//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#pragma hdrstop

#include "form_WmWifi.h"

#include "METAAPP_common.h"
#include "form_main.h"
#include "misc.h"
#include "man_fdm.h"





//#define TEST

typedef enum
{
    AGC_RX_ANT_SEL,
    MPDU_RX_ANT_SEL,
    FIXED_0,
    FIXED_1
} RX_ANT_SEL;



#define BIT(n)                          ((unsigned long) 1 << (n))

/* bits range: for example BITS(16,23) = 0xFF0000
 *   ==>  (BIT(m)-1)   = 0x0000FFFF     ~(BIT(m)-1)   => 0xFFFF0000
 *   ==>  (BIT(n+1)-1) = 0x00FFFFFF
 */
#define BITS(m,n)                       (~(BIT(m)-1) & ((BIT(n) - 1) | BIT(n)))

#define CH_1     0x0
#define CH_2     0x1
#define CH_3     0x2
#define CH_4     0x3
#define CH_5     0x4
#define CH_6     0x5
#define CH_7     0x6
#define CH_8     0x7
#define CH_9     0x8
#define CH_10    0x9
#define CH_11    0xa
#define CH_12    0xb
#define CH_13    0xc
#define CH_14    0xd
#define CH_36    35
#define CH_40    39
#define CH_44    43
#define CH_48    47
#define CH_52    51
#define CH_56    55
#define CH_60    59
#define CH_64    63
#define CH_100   99
#define CH_104   103
#define CH_108   107
#define CH_112   111
#define CH_116   115
#define CH_120   119
#define CH_124   123
#define CH_128   127
#define CH_132   131
#define CH_136   135
#define CH_140   139
#define CH_149   148
#define CH_153   152
#define CH_157   156
#define CH_161   160
#define CH_165   164


#define MT5921 0x00005921


#define EEPROM_RATE_GROUP_CCK           0x0
#define EEPROM_RATE_GROUP_OFDM_6_9M     0x1
#define EEPROM_RATE_GROUP_OFDM_12_18M   0x2
#define EEPROM_RATE_GROUP_OFDM_24_36M   0x3
#define EEPROM_RATE_GROUP_OFDM_48_54M   0x4

#define TIMER_EVENT_THERMO              253

typedef struct _RF_CHANNEL_PROG_ENTRY
{
    unsigned long      chnlNum;
    unsigned long      chnlFreq;
} RF_CHANNEL_PROG_ENTRY, *PRF_CHANNEL_PROG_ENTRY;

typedef struct _DATA_RATE_SETTING
{
    char* pszRate;
    long i4RateCfg;
    unsigned char ucRateGruopEep;
} DATA_RATE_SETTING, *P_DATA_RATE_SETTING;

typedef enum _PARAM_DEVICE_POWER_STATE
{
    ParamDeviceStateUnspecified = 0,
    ParamDeviceStateD0,
    ParamDeviceStateD1,
    ParamDeviceStateD2,
    ParamDeviceStateD3,
    ParamDeviceStateMaximum
} PARAM_DEVICE_POWER_STATE, *PPARAM_DEVICE_POWER_STATE;

const RF_CHANNEL_PROG_ENTRY chnlList[] =
{
    { CH_1,    2412000},
    { CH_2,    2417000},
    { CH_3,    2422000},
    { CH_4,    2427000},
    { CH_5,    2432000},
    { CH_6,    2437000},
    { CH_7,    2442000},
    { CH_8,    2447000},
    { CH_9,    2452000},
    { CH_10,   2457000},
    { CH_11,   2462000},
    { CH_12,   2467000},
    { CH_13,   2472000},
    { CH_14,   2484000}
};

DATA_RATE_SETTING rateSetting[] =
{
    {"1M",		2,    EEPROM_RATE_GROUP_CCK},
    {"2M",		4,    EEPROM_RATE_GROUP_CCK},
    {"5.5M",	11,   EEPROM_RATE_GROUP_CCK},
    {"11M",		22,   EEPROM_RATE_GROUP_CCK},
    {"6M",		12,   EEPROM_RATE_GROUP_OFDM_6_9M},
    {"9M",		18,   EEPROM_RATE_GROUP_OFDM_6_9M},
    {"12M",		24,   EEPROM_RATE_GROUP_OFDM_12_18M},
    {"18M",		36,   EEPROM_RATE_GROUP_OFDM_12_18M},
    {"24M",		48,   EEPROM_RATE_GROUP_OFDM_24_36M},
    {"36M",		72,   EEPROM_RATE_GROUP_OFDM_24_36M},
    {"48M",		96,   EEPROM_RATE_GROUP_OFDM_48_54M},
    {"54M",		108,  EEPROM_RATE_GROUP_OFDM_48_54M}

};

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWmWifi *frmWmWifi;

extern E_WIFI_STATE g_eWiFiState;

static void CNF_WIFI_READ_EEPROM(void)
{
    frmWmWifi->CNF_WIFI_READ_EEPROM();
}

static void CNF_WIFI_READALL_EEPROM(void)
{
    frmWmWifi->CNF_WIFI_READALL_EEPROM();
}

//---------------------------------------------------------------------------
__fastcall TfrmWmWifi::TfrmWmWifi(TComponent* Owner)
    : TForm(Owner)
{
    m_bInited = false;
    redtLog->Lines->Clear();
    m_bTXTestFlag = false;
    m_bRXTestFlag = false;
    m_bTSTestFlag = false;
    m_bSwitchAntennaOK = false;
    
    m_i4InitRxOKCnt = 0;
    m_i4InitRxFcsErrCnt = 0;
    m_u4ThermoRunNum = 0;
    m_u4InitEdPass = 0;
    m_u4InitOfdmOsdPass = 0;
    m_u4InitCckSq = 0;
    m_u4InitCckSfdPass = 0;
    m_u4InitOfdmSig = 0;
    m_u4InitCckSig = 0;
    m_fgOriThermoEn = false;
    m_bIsNvramFlag = false;
}

void TfrmWmWifi::Init( void )
{
    META_RESULT  mr = META_FAILED;
    m_bIsNvramFlag = false;
    ENUM_CFG_SRC_TYPE_T bufType;
    mr = m_WiFi_Man_Obj.WiFi_QueryConfig(5000, &bufType);

    if(META_SUCCESS != mr)
    {
        Label4->Caption = "EEPROM access";
        btnEESaveAsFile->Caption = "EEPROM Save As File";
        btnEEBurnFromFile->Caption = "Burn EEPROM From File";
        return;
    }
    else
    {
        if(CFG_SRC_TYPE_NVRAM == bufType)
        {
            Label4->Caption = "NVRAM access";
            btnEESaveAsFile->Caption = "NVRAM Save As File";
            btnEEBurnFromFile->Caption = "Burn NVRAM From File";
            m_bIsNvramFlag = true;
        }
        else if(CFG_SRC_TYPE_BOTH == bufType)
        {
            Label4->Caption = "NVRAM access";
            btnEESaveAsFile->Caption = "NVRAM Save As File";
            btnEEBurnFromFile->Caption = "Burn NVRAM From File";
            btnEEToFlash->Visible = true;
            m_bIsNvramFlag = true;
        }
        else
        {
            Label4->Caption = "EEPROM access";
            btnEESaveAsFile->Caption = "EEPROM Save As File";
            btnEEBurnFromFile->Caption = "Burn EEPROM From File";
        }
    }
    mr = m_WiFi_Man_Obj.WiFi_setTestMode(1200);
    OutputMetaResult(" setTestMode", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_switchAntenna(5000, 0);
    OutputMetaResult(" switchAntenna", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bSwitchAntennaOK = true;
//

    long channelConfig_p = 0;
#ifdef TEST
    channelConfig_p = 2427000;
#else

    mr = m_WiFi_Man_Obj.WiFi_getChannel(1200, &channelConfig_p);
    OutputMetaResult(" Get channel", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
#endif
    for(int i = 0 ; i < sizeof(chnlList)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
    {
        if((unsigned long)channelConfig_p == chnlList[i].chnlFreq)
        {
            cbChannel->ItemIndex = i;
            break;
        }
    }
    DoChannelChange();

}

void TfrmWmWifi::OutputLog(char *strInfo)
{
    redtLog->Lines->Add(strInfo);
//    redtLog->Perform(EM_SCROLLCARET, 0, 0);
//exception for the richedit in function OutputLog in CNF_WIFI_READALL_EEPROM
    PostMessage(redtLog->Handle,EM_SCROLLCARET, 0, 0);
}

void TfrmWmWifi::OutputMetaResult(char *strOperator, META_RESULT result)
{
    char strInfo[256] = {0};
    unsigned int strLen = strlen(strOperator);
    if(strLen > 200)
    {
        redtLog->Lines->Add(" Error: size of param strOperator in OutputMetaResult() function is too long!");
        return;
    }
    memcpy(strInfo, strOperator, strLen);
    switch(result)
    {
    case META_SUCCESS:
        strcat(strInfo, " success");
        break;
    case META_FAILED:
        strcat(strInfo, " failed");
        break;
    case META_COMM_FAIL:
        strcat(strInfo, " comm fail");
        break;
    case META_TIMEOUT:
        strcat(strInfo, " time out");
        break;
    case META_INVALID_HANDLE:
        strcat(strInfo, " invalid handle");
        break;
    default:
        strcat(strInfo, " other error");
        break;
    }
    redtLog->Lines->Add(strInfo);
}



void TfrmWmWifi::CurrentPageLock(unsigned int exceptCtl)
{
    edtMCRAddr->Enabled = false;
    edtMCRValue->Enabled = false;
    btnMCRRead->Enabled = false;
    btnMCRWrite->Enabled = false;
    edtEEWordAddr->Enabled = false;
    edtEEWordValue->Enabled = false;
    btnEEWordRead->Enabled = false;
    btnEEWordWrite->Enabled = false;
    edtEEByteStringAddr->Enabled = false;
    edtEEByteStringLength->Enabled = false;
    btnEEByteStringRead->Enabled = false;
    btnEEByteStringWrite->Enabled = false;
    edtEEByteStringValue->Enabled = false;
    btnEESaveAsFile->Enabled = false;
    btnEEBurnFromFile->Enabled = false;
    btnEEReadAll->Enabled = false;
    edtTXAntenna->Enabled = false;
    edtTXGain->Enabled = false;
    cbChannel->Enabled = false;
    cbACL->Enabled = false;
    cbRate->Enabled = false;
    cbTXTestType->Enabled = false;

    btnEEToFlash->Enabled = false;

    btnTXGo->Enabled = false;
    cbJapanChannel->Enabled = false;
    cbModuationType->Enabled = false;
    edtTXPktLen->Enabled = false;
    edtTXPktCnt->Enabled = false;
    btnRXGo->Enabled = false;


    btnTemperatureGo->Enabled = false;
    btnXtalTrim->Enabled = false;
    edtXtalTrimValue->Enabled = false;

    btnTXStop->Enabled = false;
    btnRXStop->Enabled = false;
    btnTemperatureStop->Enabled = false;
    switch(exceptCtl)
    {
    case NONE_STOP:
        break;
    case TX_STOP:
        btnTXStop->Enabled = true;
        break;
    case RX_STOP:
        btnRXStop->Enabled = true;
        break;
    case TEMPERATURE_STOP:
        btnTemperatureStop->Enabled = true;
        break;
    default:
        break;
    }

}

void  TfrmWmWifi::CurrentPageReset(void)
{
    edtMCRAddr->Enabled = true;
    edtMCRValue->Enabled = true;
    btnMCRRead->Enabled = true;
    btnMCRWrite->Enabled = true;
    edtEEWordAddr->Enabled = true;
    edtEEWordValue->Enabled = true;
    btnEEWordRead->Enabled = true;
    btnEEWordWrite->Enabled = true;
    edtEEByteStringAddr->Enabled = true;
    edtEEByteStringLength->Enabled = true;
    btnEEByteStringRead->Enabled = true;
    btnEEByteStringWrite->Enabled = true;
    edtEEByteStringValue->Enabled = true;
    btnEESaveAsFile->Enabled = true;
    btnEEBurnFromFile->Enabled = true;
    btnEEReadAll->Enabled = true;
    edtTXAntenna->Enabled = true;
    edtTXGain->Enabled = true;
    cbChannel->Enabled = true;
    cbACL->Enabled = true;
    cbRate->Enabled = true;
    cbTXTestType->Enabled = true;
    btnTXStop->Enabled = true;
    btnTXGo->Enabled = true;
    cbJapanChannel->Enabled = true;
    cbModuationType->Enabled = true;
    edtTXPktLen->Enabled = true;
    edtTXPktCnt->Enabled = true;
    btnRXGo->Enabled = true;
    btnRXStop->Enabled = true;
    btnTemperatureStop->Enabled = true;
    btnTemperatureGo->Enabled = true;
    btnXtalTrim->Enabled = true;
    edtXtalTrimValue->Enabled = true;
    btnEEToFlash->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnMCRReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    if(false == IsValidHexWIFIData(edtMCRAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, u4Addr, &u4Value);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    edtMCRValue->Text = IntToHex((int)u4Value, 4);
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnMCRWriteClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Value = 0;
    if(false == IsValidHexWIFIData(edtMCRAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidHexWIFIData(edtMCRValue->Text, &u4Value))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, u4Addr, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnClearLogClick(TObject *Sender)
{
    redtLog->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEWordReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    if(false == IsValidHexWIFIData(edtEEWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readEEPRom16(1200, u4Addr, &u4Value);
    if(true == m_bIsNvramFlag)
        OutputMetaResult(" Read NVRAM WORD", mr);
    else
        OutputMetaResult(" Read EEPROM WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    edtEEWordValue->Text = IntToHex((int)u4Value, 4);
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEWordWriteClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Value = 0;
    if(false == IsValidHexWIFIData(edtEEWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidHexWIFIData(edtEEWordValue->Text, &u4Value))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeEEPRom16(1200, u4Addr, u4Value);

    if(true == m_bIsNvramFlag)
        OutputMetaResult(" Write NVRAM WORD", mr);
    else
        OutputMetaResult(" Write EEPROM WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEByteStringReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Length = 0;
    char aucSzTmp[512] = {0};

    if(false == IsValidHexWIFIData(edtEEByteStringAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidDecWIFIData(edtEEByteStringLength->Text, u4Length))
    {
        OutputLog(" Error: length is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_eepromReadByteStr(1200, u4Addr, u4Length, aucSzTmp);
    if(true == m_bIsNvramFlag)
        OutputMetaResult(" Read NVRAM byte string", mr);
    else
        OutputMetaResult(" Read EEPROM byte string", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    edtEEByteStringValue->Text = (AnsiString)aucSzTmp;
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEByteStringWriteClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Length = 0;

    if(false == IsValidHexWIFIData(edtEEByteStringAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    u4Length = strlen((edtEEByteStringValue->Text).c_str());

    if( (u4Length == 0) ||((u4Length) % 2 == 1 ))
    {
        OutputLog(" Error: length is not valid");
        CurrentPageReset();
        return;
    }

    wchar_t *lpsz = new wchar_t[u4Length + 1];
    if(!lpsz)
    {
        OutputLog(" Error: memory allocate fail");
        CurrentPageReset();
        return;
    }
    _wmemset(lpsz, 0, u4Length + 1);
    _wmemcpy(lpsz,(edtEEByteStringValue->Text).c_str(), u4Length);

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_eepromWriteByteStr(1200, u4Addr, u4Length / 2, (char*)lpsz);
    if(true == m_bIsNvramFlag)
        OutputMetaResult(" Write NVRAM byte string", mr);
    else
        OutputMetaResult(" Write EEPROM byte string", mr);
    delete[] lpsz;
    lpsz = NULL;
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnEESaveAsFileClick(TObject *Sender)
{
    CurrentPageLock();
    if(!(saveDlgEE->Execute()))
    {
        CurrentPageReset();
        return;
    }

    if(FileExists(saveDlgEE->FileName))
    {
        char szFileName[255] = {0};
        fnsplit(saveDlgEE->FileName.c_str(), 0, 0, szFileName, 0);
        strcat(szFileName, ".BAK");
        RenameFile(saveDlgEE->FileName, szFileName);
    }
    m_WiFi_Man_Obj.ConfirmCallback = ::CNF_WIFI_READ_EEPROM;
    m_WiFi_Man_Obj.REQ_WIFI_READ_EEPROM_Start();
}


void TfrmWmWifi::CNF_WIFI_READ_EEPROM(void)
{
    META_RESULT state = m_WiFi_Man_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        EESaveAsFile(saveDlgEE->FileName);
    }
    break;

    default:
    {
        if(true == m_bIsNvramFlag)
        {
            OutputLog(" Error: NVRAM save as file failed");
        }
        else
        {
            OutputLog(" Error: EEPROM save as file failed");
        }
        CurrentPageReset();
    }
    break;
    }
}

void TfrmWmWifi::EESaveAsFile(AnsiString asSaveFileName)
{
    int iFileHandle = FileCreate(asSaveFileName);
    FileWrite(iFileHandle, m_WiFi_Man_Obj.GetEEBuffer(), strlen(m_WiFi_Man_Obj.GetEEBuffer()));
    FileClose(iFileHandle);
    if(true == m_bIsNvramFlag)
    {
        OutputLog(" NVRAM save as file success");
    }
    else
    {
        OutputLog(" EEPROM save as file success");
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEReadAllClick(TObject *Sender)
{
    CurrentPageLock();
    m_WiFi_Man_Obj.ConfirmCallback = ::CNF_WIFI_READALL_EEPROM;
    m_WiFi_Man_Obj.REQ_WIFI_READALL_EEPROM_Start();
//
}

void TfrmWmWifi::CNF_WIFI_READALL_EEPROM(void)
{
    META_RESULT state = m_WiFi_Man_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        OutputLog(m_WiFi_Man_Obj.GetEEBuffer());
        OutputLog(" EEPROM read all success");
    }
    break;

    default:
    {
        OutputLog(" Error: EEPROM read all failed");
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnEEBurnFromFileClick(TObject *Sender)
{
    CurrentPageLock();
    if( !(openDlgEE->Execute()))
    {
        CurrentPageReset();
        return;
    }
    try
    {
        int iFileHandle = FileOpen(openDlgEE->FileName, fmOpenRead);
        int iFileLength = FileSeek(iFileHandle,0,2);
        FileSeek(iFileHandle,0,0);

        //modify
        char* pszBuffer = new char[iFileLength+1];
        pszBuffer[iFileLength] = '\0';
        FileRead(iFileHandle, (char*)pszBuffer, iFileLength);
        AnsiString strBuffer = pszBuffer;


        FileClose(iFileHandle);
#ifdef TEST
        char *strTemp = new char[iFileLength + 1];
        if( strTemp == NULL )
        {
            return;
        }
        memcpy(strTemp, (char*)pszBuffer, iFileLength);
        strTemp[iFileLength] = '\0';
        OutputLog(strTemp);

        delete[] strTemp;
        strTemp = NULL;
#else
        int nIndex = 1;
        for (int i = 0; i < iFileLength / 4; i++)
        {
            AnsiString strTemp = strBuffer.SubString(nIndex,4);
            unsigned int tmpValue;
            if(!IsValidHexWIFIData(strTemp,&tmpValue))
            {
                if( pszBuffer != NULL )
                {
                    delete [] pszBuffer;
                    pszBuffer = NULL;
                }
                CurrentPageReset();
                return;
            }
            nIndex += 4;
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeEEPRom16(1200, i, tmpValue);

            if(META_SUCCESS != mr)
            {
                OutputLog(" Error: NVRAM Write failed");
                if( pszBuffer != NULL )
                {
                    delete [] pszBuffer;
                    pszBuffer = NULL;
                }
                CurrentPageReset();
                return;
            }

        }
#endif
        if( pszBuffer != NULL )
        {
            delete[] pszBuffer;
            pszBuffer = NULL;
        }
    }
    catch(...)
    {
        Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
    }
    if(true == m_bIsNvramFlag)
        OutputLog(" NVRAM burn from file success");
    else
        OutputLog(" EEPROM burn from file success");
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::FormShow(TObject *Sender)
{
    if(!m_bInited)
    {
        m_bInited = true;


        //set channel
        for(int i = 0 ; i < sizeof(chnlList)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {

            cbChannel->Items->Add(IntToStr(chnlList[i].chnlNum + 1)+"  ("+IntToStr(chnlList[i].chnlFreq/1000)+"MHz)");
        }
        cbChannel->ItemIndex = 0;

        //set rate
        for(int i = 0; i < sizeof(rateSetting) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSetting[i].pszRate));
        }
        cbRate->ItemIndex = 0;

        //set moduation type
        cbModuationType->Items->Add((AnsiString)"CCK");
        cbModuationType->Items->Add((AnsiString)"OFDM");
        cbModuationType->ItemIndex = 0;

        //set test type
        cbTXTestType->Items->Add((AnsiString)"continuous pkt tx");
        cbTXTestType->Items->Add((AnsiString)"tx output power");
        cbTXTestType->Items->Add((AnsiString)"carrier suppression");
        cbTXTestType->Items->Add((AnsiString)"local frequency");
        cbTXTestType->Items->Add((AnsiString)"Fly Mode");
        cbTXTestType->ItemIndex = 0;

    }
    Init();

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnTXGoClick(TObject *Sender)
{

    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
        goTX0();
        break;
    case 1:// tx output power
        goTX1();
        break;
    case 2:// carrier suppression
        goTX2();
        break;
    case 3:// local leakage
        goTX3();
        break;
    case 4:// Enter Power OFF
        goTX4();
        break;
    default:
        //error
        break;
    }
}

void TfrmWmWifi::goTX0(void)
{
    CurrentPageLock(TX_STOP);

#if 0
    unsigned char szBuf[1024] = {0};

    /* Frame Control Field */
    szBuf[0] = 0x80;
    szBuf[1] = 0x00;
    szBuf[2] = 0x00;
    szBuf[3] = 0x00;

    /* A1 */
    szBuf[4] = 0xFF;
    szBuf[5] = 0x22;
    szBuf[6] = 0x33;
    szBuf[7] = 0x44;
    szBuf[8] = 0x55;
    szBuf[9] = 0x66;

    /* A2 */
    szBuf[10] = 0x00;
    szBuf[11] = 0x0C;
    szBuf[12] = 0xE7;
    szBuf[13] = 0x09;
    szBuf[14] = 0x00;
    szBuf[15] = 0x26;

    /* A3 */
    szBuf[16] = 0x00;
    szBuf[17] = 0x00;
    szBuf[18] = 0x00;
    szBuf[19] = 0x00;
    szBuf[20] = 0x00;
    szBuf[21] = 0x00;

    /* Sequence Number & Frag. Number */
    szBuf[22] = 0x40;
    szBuf[23] = 0x80;

    /* Data */
    szBuf[24] = 0x81;
    szBuf[25] = 0xaa;
    szBuf[26] = 0xaa;
    szBuf[27] = 0xbb;
    szBuf[28] = 0xbb;
    szBuf[29] = 0xcc;
    szBuf[30] = 0xcc;
#endif

    unsigned int u4TxPktCnt = 0;
    int i4TxPktLen = 0;
    unsigned int u4TxGain = 0;
    int i4Antenna = 0;
    if(false == IsValidDecWIFIData(edtTXPktCnt->Text, u4TxPktCnt))
    {
        OutputLog(" Error: Pkt cnt is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidHexWIFIData(edtTXGain->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidIntWIFIData(edtTXAntenna->Text, i4Antenna))
    {
        OutputLog(" Error: Antenna is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidIntWIFIData(edtTXPktLen->Text, i4TxPktLen))
    {
        OutputLog(" Error: Pkt Len is not valid");
        CurrentPageReset();
        return;
    }
    if(i4TxPktLen < 31)
    {
        OutputLog(" Error: Pkt Len is too small");
        CurrentPageReset();
        return;
    }
//rongguo 2011-06-16
    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = FALSE;
    txParam.txRate = cbRate->ItemIndex;
    txParam.pktCount =  u4TxPktCnt;
    txParam.pktInterval = 10;
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxGain;
    txParam.txAntenna = i4Antenna;
    btnTXGo->Enabled = false;

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setPacketTxEx(1200, &txParam);
    OutputMetaResult(" setPacketTxEx", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    timerTX->Enabled = true;
}

void TfrmWmWifi::goTX1(void)
{
    CurrentPageLock(TX_STOP);
//    int rate_500KHZ = rateSetting[cbRate->ItemIndex].i4RateCfg;

    unsigned int u4TxGain = 0;
    int i4Antenna = 0;

    if(false == IsValidHexWIFIData(edtTXGain->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidIntWIFIData(edtTXAntenna->Text, i4Antenna))
    {
        OutputLog(" Error: Antenna is not valid");
        CurrentPageReset();
        return;
    }
    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.txRate = cbRate->ItemIndex;
    txParam.gainControl = u4TxGain;
    txParam.txAntenna = i4Antenna;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setOutputPower(1200, &txParam);
    OutputMetaResult(" setOutputPower", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifi::goTX2(void)
{
    CurrentPageLock(TX_STOP);
    unsigned int u4TxGain = 0;
    int i4Antenna = 0;

    if(false == IsValidHexWIFIData(edtTXGain->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidIntWIFIData(edtTXAntenna->Text, i4Antenna))
    {
        OutputLog(" Error: Antenna is not valid");
        CurrentPageReset();
        return;
    }
    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.txRate = cbRate->ItemIndex;
    txParam.gainControl = u4TxGain;
    txParam.txAntenna = i4Antenna;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setCarrierSuppression(1200, &txParam);
    OutputMetaResult(" setCarrierSuppression", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifi::goTX3(void)
{
    CurrentPageLock(TX_STOP);
    unsigned int u4TxGain = 0;
    int i4Antenna = 0;

    if(false == IsValidHexWIFIData(edtTXGain->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    if(false == IsValidIntWIFIData(edtTXAntenna->Text, i4Antenna))
    {
        OutputLog(" Error: Antenna is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setLocalFrequecy(1200, u4TxGain, i4Antenna);
    OutputMetaResult(" setLocalFrequecy", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifi::goTX4(void)
{
    CurrentPageLock(TX_STOP);
    btnTXGo->Enabled = false;
    META_RESULT mr;
    mr = m_WiFi_Man_Obj.WiFi_setNormalMode(1200);
    OutputMetaResult(" setNormalMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_setOutputPin(1200, 20, 0); //IO_PIN_LCR
    OutputMetaResult(" setOutputPin", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD3);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::btnTXStopClick(TObject *Sender)
{
    m_bTXTestFlag = false;
    CurrentPageLock();
    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
        stopTX0();
        break;
    case 1:// tx output power
        stopTX1();
        break;
    case 2:// carrier suppression
        stopTX2();
        break;
    case 3:// local leakage
        stopTX3();
        break;
    case 4:// Enter Power OFF
        stopTX4();
        break;
    default:
        //error
        break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void TfrmWmWifi::stopTX0(void)
{
    META_RESULT mr;
    unsigned long u4Value = 0;
    for (int i = 0; i < 100; i++)
    {
        mr = m_WiFi_Man_Obj.WiFi_SetATParam(1200, 1, 0);
        OutputMetaResult(" SetATParam", mr);
        if(META_SUCCESS != mr)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_GetATParam(1200, 1, &u4Value);
        OutputMetaResult(" GetATParam", mr);
        if(META_SUCCESS != mr)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            return;
        }

        if (u4Value == 0)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            return;
        }
        else
        {
            Sleep(10);
        }
    }
}

void TfrmWmWifi::stopTX1(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
}

void TfrmWmWifi::stopTX2(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
}

void TfrmWmWifi::stopTX3(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
}

void TfrmWmWifi::stopTX4(void)
{
    META_RESULT mr;
    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD0);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_setTestMode(1200);
    OutputMetaResult(" setTestMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, chnlList[cbChannel->ItemIndex].chnlFreq);
    OutputMetaResult(" setChannel", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }

    if(!uiUpdateTxPower())
    {
        btnTXGo->Enabled = true;
        return;
    }
}

void __fastcall TfrmWmWifi::TimerTimerTX(TObject *Sender)
{
    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
    {
        unsigned long u4Value;
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_GetATParam(1200, 1, &u4Value);
        OutputMetaResult(" GetATParam", mr);
        if(META_SUCCESS != mr)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            CurrentPageReset();
            return;
        }

        if(u4Value == 0)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            CurrentPageReset();
            OutputLog(" TX completed");
        }
        break;
    }
    case 1:// tx output power
        break;
    case 2:// carrier suppression
        break;
    case 3:// local leakage
        break;
    case 4:// Enter Power OFF
        break;
    default:
        //error
        break;
    }
}


bool TfrmWmWifi::uiUpdateTxPower(void)
{
    long i4TxPwrGain;
    long i4OutputPower;
    long i4targetAlc;

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readTxPowerFromEEPromEx(1200,
                     chnlList[cbChannel->ItemIndex].chnlFreq,
                     rateSetting[cbRate->ItemIndex].i4RateCfg,
                     &i4TxPwrGain,
                     &i4OutputPower,
                     &i4targetAlc);
    OutputMetaResult(" readTxPowerFromEEPromEx", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return false;
    }

    unsigned char ucGain = (unsigned char)(i4TxPwrGain & BITS(0,8));
    if( ucGain== 0x00 || ucGain == 0xFF)
    {
        if(rateSetting[cbRate->ItemIndex].ucRateGruopEep <= EEPROM_RATE_GROUP_CCK)
        {
            edtTXGain->Text = (AnsiString)"20";
        }
        else
        {
            edtTXGain->Text = (AnsiString)"22";
        }
    }
    else
    {
        edtTXGain->Text = IntToHex(ucGain, 2);
    }
    return true;
}
void TfrmWmWifi::DoChannelChange(void)
{
    META_RESULT mr;
    unsigned long u4Value = 0;

    mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, chnlList[cbChannel->ItemIndex].chnlFreq);
    OutputMetaResult(" setChannel", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 65 * 4, &u4Value);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
    u4Value &= BITS(0, 15);

    if(chnlList[cbChannel->ItemIndex].chnlNum == CH_14 )
    {
        if ( cbJapanChannel->Checked )
        {
            u4Value |= BIT(6); //enable Tx Filter for Japen Channel
        }
        else
        {
            u4Value &= ~BIT(6); //disable Tx Filter for Japen Channel
        }

    }
    else
    {
        u4Value &= ~BIT(6); //disable Tx Filter for Japen Channel
    }

    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0x200 + 65 * 4, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
        return;
    uiUpdateTxPower();


}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::cbxChannelChange(TObject *Sender)
{
    DoChannelChange();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnRXGoClick(TObject *Sender)
{
    CurrentPageLock(RX_STOP);
    META_RESULT mr;
//    unsigned int u4Addr = 0;
    unsigned long u4RegisterBackup = 0;

    // record the initial value for RFB G0/ 1/ 2 setting
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0xf4, &u4RegisterBackup);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    // OR BIT(0) | BIT(1) | BIT(2) | BIT(5)
    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0xf4, u4RegisterBackup |
                                   BIT(0) | BIT(1) | BIT(2) | BIT(5));
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    // reset BB RX counters
    unsigned long u4Value = 0;

    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 82 * 4, &u4Value);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    u4Value |= BIT(7);

    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0x200 + 82 * 4, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    u4Value &= ~BIT(7);

    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0x200 + 82 * 4, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    // enable BB RX counters
    u4Value |= BIT(6);

    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0x200 + 82 * 4, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    // Clear initial RX counters
    //ED pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 91 * 4, &m_u4InitEdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //OFDM OSD pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 92 * 4, &m_u4InitOfdmOsdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //CCK_SQ
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 94 * 4, &m_u4InitCckSq);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //CCK_SFD Pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 96 * 4, &m_u4InitCckSfdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //BB_OFDM_SIG
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 93 * 4, &m_u4InitOfdmSig);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //BB_CCK_SIG
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 95 * 4, &m_u4InitCckSig);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    //MAC_FCS_ERR, MAC_RX_OK
    //BB_CCK_SIG
    WIFI_RXSTATUS_T req;
    mr = m_WiFi_Man_Obj.WiFi_getPacketRxStatus(1200, &req);
    OutputMetaResult(" getPacketRxStatus", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_i4InitRxOKCnt = req.int_rx_ok_num;
    m_i4InitRxFcsErrCnt = req.int_crc_err_num;

    mr = m_WiFi_Man_Obj.WiFi_setPacketRx(1200, cbACL->Checked, (RX_ANT_SEL)0);
    OutputMetaResult(" setPacketRx", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    int intervalTime = 0;
    if(false == IsValidIntWIFIData(edtInterval->Text, intervalTime) || intervalTime <= 0)
    {
        intervalTime = 1;
        OutputLog(" Error: interval time is not valid, which will be set to default value(1 sec)");
    }

    timerRX->Interval = intervalTime*1000;
    m_bRXTestFlag = true;
    timerRX->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::TimerTimerRX(TObject *Sender)
{
    RXQuery();
}


void TfrmWmWifi::RXQuery()
{
    //long u4RxOk = 0;
    //long u4RxErr = 0;
    WIFI_RXSTATUS_T req;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_getPacketRxStatus(1200, &req);
    OutputMetaResult(" getPacketRxStatus", mr);
    if(META_SUCCESS != mr)
    {
        timerRX->Enabled = false;
        CurrentPageReset();
        return;
    }

    long i4RxCntOK = req.int_rx_ok_num - m_i4InitRxOKCnt;
    long i4RxCntFcsErr = req.int_crc_err_num - m_i4InitRxFcsErrCnt;
    long i4RxPer = 0;
    if(i4RxCntFcsErr + i4RxCntOK)
    {
        i4RxPer = i4RxCntFcsErr * 100 / (i4RxCntFcsErr + i4RxCntOK);
    }

    stRXFCSerr->Caption = IntToStr(i4RxCntFcsErr);
    stRXOK->Caption = IntToStr(i4RxCntOK);
    stRXPER->Caption = IntToStr(i4RxPer);
    stMin->Caption = IntToStr(req.int_rssi_min);
    stMax->Caption = IntToStr(req.int_rssi_max);
    stMean->Caption = IntToStr(req.int_rssi_mean);
    stVar->Caption = IntToStr(req.int_rssi_variance);
}


//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnRXStopClick(TObject *Sender)
{
    CurrentPageLock();
    timerRX->Enabled = false;
    RXQuery();

#if 0

    mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
#else

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_SetATParam(1200, 1, 0);
    OutputMetaResult(" SetATParam", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
#endif



    // Disable BB RX counters
    unsigned long u4Value;
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 82 * 4, &u4Value);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    u4Value &= ~BIT(6);

    mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, 0x200 + 82 * 4, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }


    WIFI_RXSTATUS_T req;
    mr = m_WiFi_Man_Obj.WiFi_getPacketRxStatus(1200, &req);
    OutputMetaResult(" getPacketRxStatus", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    unsigned long u4EdPass = 0;
    unsigned long u4OfdmOsdPass = 0;
    unsigned long u4CckSq = 0;
    unsigned long u4CckSfdPass = 0;
    unsigned long u4OfdmSig = 0;
    unsigned long u4CckSig = 0;
    //ED pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 91 * 4, &u4EdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    //OFDM OSD pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 92 * 4, &u4OfdmOsdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //CCK_SQ
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 94 * 4, &u4CckSq);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //CCK_SFD Pass
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 96 * 4, &u4CckSfdPass);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //BB_OFDM_SIG
    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 93 * 4, &u4OfdmSig);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    //BB_CCK_SIG
     mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, 0x200 + 95 * 4, &u4CckSig);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bRXTestFlag = false;
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnXtalTrimClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4UiVal = 0;

    if(false == IsValidHexWIFIData(edtXtalTrimValue->Text, &u4UiVal))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setXtalTrimToCr(1200, u4UiVal);
    OutputMetaResult(" setXtalTrimToCr", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnTemperatureGoClick(TObject *Sender)
{
    CurrentPageLock(TEMPERATURE_STOP);
    META_RESULT mr;
    long i4AlcEn = 0;

    mr = m_WiFi_Man_Obj.WiFi_queryThermoInfo(1200, &i4AlcEn, NULL);
    OutputMetaResult(" queryThermoInfo", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    if (i4AlcEn == 1)
    {
        m_fgOriThermoEn = true;
    }
    else
    {
        m_fgOriThermoEn = false;

        mr = m_WiFi_Man_Obj.WiFi_setThermoEn(1200, (long)1);
        OutputMetaResult(" setThermoEn", mr);
        if(META_SUCCESS != mr)
        {
            CurrentPageReset();
            return;
        }
    }
    m_u4ThermoRunNum = 0;
    m_bTSTestFlag = true;
    timerTemperature->Enabled = true;
    btnTemperatureGo->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::TimerTimerTemperature(TObject *Sender)
{
    unsigned long u4ThermoRaw = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_queryThermoInfo(1200, NULL, &u4ThermoRaw);
    OutputMetaResult(" queryThermoInfo", mr);
    if(META_SUCCESS != mr)
    {
        timerTemperature->Enabled = false;
        CurrentPageReset();
        return;
    }

    if (u4ThermoRaw == 0xFFFFFFFF)
    {
        OutputLog(" Hareware report busy after 99 times retry");
    }
    else
    {
        char strTemp[32] = {0};
        sprintf(strTemp, "Run %d, Thermo value: %#04X", ++m_u4ThermoRunNum, u4ThermoRaw);
        OutputLog(strTemp);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::btnTemperatureStopClick(TObject *Sender)
{
    CurrentPageLock();
    timerTemperature->Enabled = false;

    if (!m_fgOriThermoEn)
    {
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_setThermoEn(1200, 0);
        OutputMetaResult(" setThermoEn", mr);
        if(META_SUCCESS != mr)
        {
            btnTemperatureGo->Enabled = true;
            CurrentPageReset();
            return;
        }
    }
    btnTemperatureGo->Enabled = true;
    m_bTSTestFlag = false;
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifi::cbRateChange(TObject *Sender)
{
    uiUpdateTxPower();
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifi::btnEEToFlashClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned short  u2EepromSz = 512;
    unsigned short  u2EepromValue = 0;
    unsigned long   u4Tmp = 0;
    char strEEbuf[2048] = {0};

    for(int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
    {
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_ReadConfigData(1200, u2Tmp, &u4Tmp,CFG_SRC_TYPE_EEPROM);
        //OutputMetaResult(" read EEPRom16", mr);
        if(META_SUCCESS != mr)
        {
            OutputLog(" Error: EEPROM load failed!");
            CurrentPageReset();
            return ;
        }
        u2EepromValue = (unsigned short) u4Tmp;

        char strBuf[10] = {0};
        sprintf(strBuf, "%04X", u2EepromValue);
        strcat(strEEbuf, strBuf);
    }
    //strEEbuf is useful.

    OutputLog(" EEPROM load success");
    AnsiString strBuffer = strEEbuf;
    int nIndex = 1;
    for (int i = 0; i < u2EepromSz/2; i++)
    {
        AnsiString strTemp = strBuffer.SubString(nIndex,4);
        unsigned int tmpValue;
        if(!IsValidHexWIFIData(strTemp,&tmpValue))
        {
            OutputLog(" Error: EEPROM load failed");
            CurrentPageReset();
            return;
        }
        nIndex += 4;
         META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeEEPRom16(1200, i, tmpValue);
        //OutputMetaResult(" Write NVRAM WORD", mr);
        if(META_SUCCESS != mr)
        {
            OutputLog(" Error: NVRAM Write failed!");
            CurrentPageReset();
            return;
        }

    }
    OutputLog(" NVRAM Write success");
    CurrentPageReset();
    return;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::FormClose(TObject *Sender,
                                      TCloseAction &Action)
{

    if(m_bTXTestFlag)
    {
        btnTXStopClick(NULL);
        m_bTXTestFlag = false;
    }
    if(m_bRXTestFlag)
    {
        btnRXStopClick(NULL);
        m_bRXTestFlag = false;
    }
    if(m_bTSTestFlag)
    {
        btnTemperatureStopClick(NULL);
        m_bTSTestFlag = false;
    }

    m_WiFi_Man_Obj.WiFi_setNormalMode(1200);
    if( m_bSwitchAntennaOK )
    {
        META_RESULT  mr = META_FAILED;
        mr = m_WiFi_Man_Obj.WiFi_switchAntenna(5000, 1);
        if(META_SUCCESS != mr)
        {
            return;
        }
        m_bSwitchAntennaOK = false;
    }

    CloseWiFi();
    return;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifi::Button1Click(TObject *Sender)
{
    unsigned char ChipID[17]= {0};
    META_RESULT mr = SP_META_GetChipID_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, ChipID);
    char strBuf[10] = {0};
    sprintf(strBuf, "%02X", ChipID);
    if(mr == META_SUCCESS)
    {
        Application->MessageBox(ChipID,MB_OK);
    }
    else
    {
        Application->MessageBox("Fail",MB_OK);
    }
}
//---------------------------------------------------------------------------
void TfrmWmWifi::CloseWiFi(void)
{
    if( g_eWiFiState == WIFI_STATE_OPEN )
    {
       m_WiFi_Man_Obj.WiFi_Close(5000);
       g_eWiFiState = WIFI_STATE_CLOSE;
    }
}
void __fastcall TfrmWmWifi::FormHide(TObject *Sender)
{
    CloseWiFi();
}
//---------------------------------------------------------------------------

