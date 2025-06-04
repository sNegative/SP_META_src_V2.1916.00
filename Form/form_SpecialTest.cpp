//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>

#include "form_SpecialTest.h"

#ifndef  _MISC_SPECIALTEST_H_
#include "misc_specialtest.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSpecialTest *frmSpecialTest;
//---------------------------------------------------------------------------
__fastcall TfrmSpecialTest::TfrmSpecialTest(TComponent* Owner)
    : TForm(Owner)
{
    m_nHugeDataTestNum = 0;
    m_nChecksum = 0;
    memset(m_cRawDataBuf,0,RAW_DATA_LEN);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSpecialTest::FormShow(TObject *Sender)
{
    cbxDataSize->ItemIndex = 4;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::btnSpecialTestClick(TObject *Sender)
{
    m_nHugeDataTestNum = StrToInt(edtTestTime->Text.c_str());
    if(m_nHugeDataTestNum <= 0 )
    {
        Application->MessageBox("Please set the test number before do huge data test","FAILURE",MB_OK);
        return;
    }
    META_RESULT mr = META_FAILED;
    int data_size = 1024*50;
    int i = 0;
    if( cbxDataSize->Text == "10K" )
    {
        data_size = 1024*10;
    }
    else if( cbxDataSize->Text == "20K" )
    {
        data_size = 1024*20;
    }
    else if ( cbxDataSize->Text == "30K")
    {
        data_size = 1024*30;
    }
    else if ( cbxDataSize->Text == "40K")
    {
        data_size = 1024*40;
    }
    else if ( cbxDataSize->Text == "50K")
    {
        data_size = 1024*50;
    }
    else
    {
        Application->MessageBox("Please make sure the Data Size is correct","FAILURE",MB_OK);
        return;
    }
    for ( i=0; i<m_nHugeDataTestNum; i++ )
    {
        mr = m_SpecialTest_Man_Obj.SpecialTest_HugeData(5000, data_size);
        if( mr != META_SUCCESS )
        {
            LOG("SP_META_SpecialTest_HugeData_r mr:%d, the %d time test fail",mr,i);
            Application->MessageBox( "Execution Failure : Special test huge data test fail", "FAILURE", MB_OK );
            return;
        }
    }
    Application->MessageBox( "Execution Success : Special test pass", "SUCCESS", MB_OK );
}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::edtTestTimeExit(TObject *Sender)
{
    unsigned int n_data = 0;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 1~1000 "
    };

    text = edit->Text;
    if( !IsValidHugeDataTestNum( text, n_data ) )
    {
        edit->Text = 100;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    m_nHugeDataTestNum = n_data;
}
//---------------------------------------------------------------------------
void  TfrmSpecialTest::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}
void __fastcall TfrmSpecialTest::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmSpecialTest::btnRightDataTestClick(TObject *Sender)
{
    //case 1: the right data which to get version
    unsigned char recBuf[4096] = {0};
    int i = 0;
    META_RESULT mr = META_FAILED;
    GetRawDataTestBuf();
    for(i =0; i<m_nRawDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }
    mr = m_SpecialTest_Man_Obj.SpecialTest_RawData(5000,
       recBuf, m_cRawDataBuf, m_nRawDataSize);
    LOG("SP_META_SpecialTest_RawData_r mr:%d",mr);

}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::btnChecksumErrorClick(TObject *Sender)
{
    //case 2: the checksum is error, we see the tst log.
    unsigned char recBuf[4096] = {0};
    int i = 0;
    META_RESULT mr = META_FAILED;
    GetRawDataTestBuf();
    for(i =0; i<m_nRawDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }
    //modify the checksum as error data
    (m_cRawDataBuf[m_nRawDataSize-1])++; 
    mr = m_SpecialTest_Man_Obj.SpecialTest_RawData(5000,
       recBuf, m_cRawDataBuf, m_nRawDataSize);
    LOG("SP_META_SpecialTest_RawData_r mr:%d",mr);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::btnEscapeDataTestClick(TObject *Sender)
{
    //case 3: the token has escaping data 0x5A->0x5A 0x5A.
    unsigned char recBuf[4096] = {0};
    int i = 0;
    META_RESULT mr = META_FAILED;
    GetRawDataTestBuf();
    for(i =0; i<m_nRawDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }
    mr = m_SpecialTest_Man_Obj.SpecialTest_RawData(5000,
       recBuf, m_cRawDataBuf, m_nRawDataSize);
    LOG("SP_META_SpecialTest_RawData_r mr:%d",mr);
}
//---------------------------------------------------------------------------

/* the define of escape key */
#define   MUX_KEY_WORD		        0x5A
#define   STX_OCTET            	0x55

bool TfrmSpecialTest::ParseSendData(unsigned char *buf_ptr, unsigned int input_len)
{	
	if ( buf_ptr == NULL )
    {
        LOG("ParseSendData buf_ptr is NULL");
        return 0;
	}

    unsigned char *pTempBuf = NULL;
    unsigned char *pTempDstBuf = NULL;
    unsigned char *pMamptrBase = buf_ptr;
    unsigned char *pDestptrBase = NULL;
    int iCheckNum = 0;
    int dest_index = 0;
    int cbTxBuffer = input_len;
	
    if(pMamptrBase == NULL)
    {
		LOG("ParseSendData pMamptrBase is NULL");
        return 0;
    }
    
    pDestptrBase = new unsigned char[4096];
    if(pDestptrBase == NULL)
    {
		LOG("ParseSendData pDestptrBase malloc Fail");
        return 0;
    }
	
    pTempDstBuf = pDestptrBase;
    pTempBuf = pMamptrBase;
	
    /* if the data is 0x5A and 0x5A, escape to 0x5A
	if the data is 0x5A and 0x01, escape to 0x55
    */
    while (iCheckNum != cbTxBuffer)
    {
        iCheckNum++;	    
        if (*pTempBuf == MUX_KEY_WORD )
        {
            pTempBuf++;
            iCheckNum++;		
            if (*pTempBuf == MUX_KEY_WORD)
			{
				*pTempDstBuf = MUX_KEY_WORD;
			}
            else if (*pTempBuf == 0x01 )
            {
                *pTempDstBuf = STX_OCTET;
			}
			else
			{
				LOG("ParseSendData no escape: cnt:%d",iCheckNum);
                delete []pDestptrBase;
                pDestptrBase = NULL;
				return 0;
			}
		}
        else
        {
			*pTempDstBuf = *pTempBuf;
        }
		
        dest_index++;
        pTempDstBuf++;
        pTempBuf++;
	}

    if(dest_index < 12)    //FrameHeader(4) + Local Len(2) + Peer Len(2) + Token(2) + Req id(2)
    {
        delete []pDestptrBase;
        pDestptrBase = NULL;
        return false;
    }
/*    if ((pDestptrBase[10] != 157) || (pDestptrBase[11] != 0))  //check request id is 157
    {
        delete []pDestptrBase;
        pDestptrBase = NULL;
        return false;
    } */

    m_nChecksum = GetCheckSum(pDestptrBase,dest_index);

	delete []pDestptrBase;
    pDestptrBase = NULL;
    return true;
}

int TfrmSpecialTest::GetCheckSum(char *buf, int size)
{
	unsigned char chksum = 0;
    char result[3] = {0};
	int i = 0;
	for(i=0; i<size; i++)
	{
		chksum ^= buf[i];
	}
	sprintf(result, "%02X", chksum);
    LOG("%s",result);
    return ByteHexStr2Int(result);
}


void TfrmSpecialTest::GetRawDataTestBuf(void)
{
    AnsiString  text = edtRawData->Text;
    char cDataBuf[RAW_DATA_LEN] = {0};
    int nDataLen = 0;
    int nDataSize = 0;
    int i =0;
    nDataLen = strlen(text.c_str());
    memcpy(cDataBuf,text.c_str(),nDataLen);
    std::string temp(cDataBuf);
    nDataSize = String2Hex(temp,m_cRawDataBuf);
    for(i =0; i<nDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }

    /*bool bParse = ParseSendData(m_cRawDataBuf,nDataSize);
    if ( !bParse )
    {
        Application->MessageBox( "Execution Failure : Please make sure the request id is (0x9D) and the data length is valid", "FAILURE", MB_OK );
        return;
    }
    m_cRawDataBuf[nDataSize] = m_nChecksum;
    m_nRawDataSize = nDataSize + 1;  */

    m_nRawDataSize = nDataSize;

}


int TfrmSpecialTest::String2Hex(std::string str, char *SendOut)
{
	int hexdata,lowhexdata;
	int hexdatalen=0;
	int len = str.length();
	for(int i=0;i<len;)
	{
		char lstr,hstr=str[i];
		if(hstr==' '||hstr=='\r'||hstr=='\n')
		{
			i++;
			continue;
		}
		i++;
		if (i>=len)
			break;
		lstr=str[i];
		hexdata=ConvertHexData(hstr);
		lowhexdata=ConvertHexData(lstr);
		if((hexdata==16)||(lowhexdata==16))
			break;
		else
			hexdata=hexdata*16+lowhexdata;
		i++;
		SendOut[hexdatalen]=(char)hexdata;
		hexdatalen++;
	}
	return hexdatalen;
}

char TfrmSpecialTest::ConvertHexData(char ch)
{
	if((ch>='0')&&(ch<='9'))
		return ch-0x30;
	if((ch>='A')&&(ch<='F'))
		return ch-'A'+10;
	if((ch>='a')&&(ch<='f'))
		return ch-'a'+10;
    else return(-1);
}


void __fastcall TfrmSpecialTest::btnChecksumEscapingTestClick(TObject *Sender)
{
    edtRawData->Text = "55 00 08 66 04 00 00 00 F7 00 9D 00";
    unsigned char recBuf[4096] = {0};
    int i = 0;
    META_RESULT mr = META_FAILED;
    GetRawDataTestBuf();
    for(i =0; i<m_nRawDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }
    if (m_cRawDataBuf[m_nRawDataSize-1] == 0x55)       //escape 0x55->0x5a 0x01
    {
        m_cRawDataBuf[m_nRawDataSize-1] = 0x5A;
        m_cRawDataBuf[m_nRawDataSize] = 0x01;
        m_nRawDataSize = m_nRawDataSize + 1;
    }
    mr = m_SpecialTest_Man_Obj.SpecialTest_RawData(5000,
       recBuf, m_cRawDataBuf, m_nRawDataSize);
    LOG("SP_META_SpecialTest_RawData_r mr:%d",mr);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::edtRawDataExit(TObject *Sender)
{
    int nDataLen = 0;
    //int nDataSize = 0;
    char cDataBuf[RAW_DATA_LEN] = {0};
    //char cDataTempBuf[RAW_DATA_LEN] = {0};
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;

    text = edit->Text;
    nDataLen = strlen(text.c_str());
    memcpy(cDataBuf,text.c_str(),nDataLen);
   /* std::string temp(cDataBuf);
    nDataSize = String2Hex(temp,cDataTempBuf);
    bool bParse = ParseSendData(cDataTempBuf,nDataSize);
    if ( !bParse )
    {
        edit->Text = "";
        Application->MessageBox( "Execution Failure : Please make sure the request id is (0x9D) and the data length is valid", "FAILURE", MB_OK );
        return;
    } */
}
//---------------------------------------------------------------------------


void __fastcall TfrmSpecialTest::btnRawDataTestClick(TObject *Sender)
{
    unsigned char recBuf[4096] = {0};
    int i = 0;
    META_RESULT mr = META_FAILED;
    GetRawDataTestBuf();
    for(i =0; i<m_nRawDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }
    mr = m_SpecialTest_Man_Obj.SpecialTest_RawData(5000,
       recBuf, m_cRawDataBuf, m_nRawDataSize);
    LOG("SP_META_SpecialTest_RawData_r mr:%d",mr);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSpecialTest::btnGetChecksumClick(TObject *Sender)
{
    AnsiString  text = edtRawData->Text;
    char cDataBuf[RAW_DATA_LEN] = {0};
    int nDataLen = 0;
    int nDataSize = 0;
    int i =0;
    nDataLen = strlen(text.c_str());
    memcpy(cDataBuf,text.c_str(),nDataLen);
    std::string temp(cDataBuf);
    nDataSize = String2Hex(temp,m_cRawDataBuf);
    for(i =0; i<nDataSize; i++)
    {
        LOG("m_cRawDataBuf[%d]:%02X",i, m_cRawDataBuf[i]);
    }

    ParseSendData(m_cRawDataBuf,nDataSize);
    LOG("m_nChecksum:%02X",m_nChecksum);
}
//---------------------------------------------------------------------------

