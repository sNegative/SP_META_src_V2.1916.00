//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "form_5GHz_TX_Power_Profile.h"
#include "METAAPP_common.h"
#include "form_main.h"
#include "misc.h"
#include "man_fdm.h"

#include "math.h"

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

#ifndef form_WmWifimt6620H
#include "form_WmWifimt6620.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm5GHz_TX_Power_Profile *frm5GHz_TX_Power_Profile;

#define _5GH_TX_POWER_COMPENSATION_VALUE 17
#define _5GH_TX_POWER_COMPENSATION_VALUE_6630 33
char g_lv5GH_TX_Power_Compensation_value[_5GH_TX_POWER_COMPENSATION_VALUE][10] =
{
    "-4",
    "-3.5",
    "-3",
    "-2.5",
    "-2",
    "-1.5",
    "-1",
    "-0.5",
    "0",
    "0.5",
    "1",
    "1.5",
    "2",
    "2.5",
    "3",
    "3.5",
    "4"
};

#define _5GH_TX_POWER_COMPENSATION_VALUE_EX 9    //For MT6625 5G Tx power compensation over Channel
char g_lv5GH_TX_Power_Compensation_value_Ex[_5GH_TX_POWER_COMPENSATION_VALUE_EX][10] =
{
    "-2",
    "-1.5",
    "-1",
    "-0.5",
    "0",
    "0.5",
    "1",
    "1.5",
    "2",
};

#define _5GH_TX_POWER_COMPENSATION_CHANNEL 8
char g_lv5GH_TX_Power_Compensation_Channel[_5GH_TX_POWER_COMPENSATION_CHANNEL][30] =
{
    "11a 4915~4980",
    "11a 5040~5100",
    "11a 5180~5320",
    "11a 5500~5540",
    "11a 5560~5620",
    "11a 5640~5660",
    "11a 5680~5785",
    "11a 5805~5825",
};

char g_lv5GH_TX_Power_Compensation_Channel_Ex[_5GH_TX_POWER_COMPENSATION_CHANNEL][30] =
{
    "4915~5035",
    "5180~5240",
    "5260~5320",
    "5340~5480",
    "5500~5560",
    "5580~5640",
    "5660~5720",
    "5745~5905",
};

char g_lv5GH_TX_Power_Compensation_Channel_6630[_5GH_TX_POWER_COMPENSATION_CHANNEL][30] =
{
    "4850~5080",
    "5170~5250",
    "5260~5320",
    "5340~5480",
    "5500~5560",
    "5580~5640",
    "5660~5720",
    "5745~5950",
};

char g_lv5GH_TX_Power_Compensation_value_map[_5GH_TX_POWER_COMPENSATION_VALUE_EX][10] =
{
    "-128",
    "-108",
    "-72",
    "-36",
    "0",
    "36",
    "72",
    "108",
    "127"
};

//20140526 add
char g_lv5GH_TX_Power_Compensation_value_6630[_5GH_TX_POWER_COMPENSATION_VALUE_6630][10] =
{
    "-4",
    "-3.75",
    "-3.5",
    "-3.25",
    "-3",
    "-2.75",
    "-2.5",
    "-2.25",
    "-2",
    "-1.75",
    "-1.5",
    "-1.25",
    "-1",
    "-0.75",
    "-0.5",
    "-0.25",
    "0",
    "0.25",
    "0.5",
    "0.75",
    "1",
    "1.25",
    "1.5",
    "1.75",
    "2",
    "2.25",
    "2.5",
    "2.75",
    "3",
    "3.25",
    "3.5",
    "3.75",
    "3.97",
};

char g_lv5GH_TX_Power_Compensation_value_map_6630[_5GH_TX_POWER_COMPENSATION_VALUE_6630][10] =
{
    "-128",
    "-120",
    "-112",
    "-104",
    "-96",
    "-88",
    "-80",
    "-72",
    "-64",
    "-56",
    "-48",
    "-40",
    "-32",
    "-24",
    "-16",
    "-8",
    "0",
    "8",
    "16",
    "24",
    "32",
    "40",
    "48",
    "56",
    "64",
    "72",
    "80",
    "88",
    "96",
    "104",
    "112",
    "120",
    "127",
};

/*
typedef struct _CODE_MAPPING_T {
    int          u4TxpowerOffset;
    unsigned int u4RegisterValue;
} CODE_MAPPING_T, *P_CODE_MAPPING_T;

const CODE_MAPPING_T arCodeTable[] = {
                {-2,0x80},
                {-1.5,0x94},
                {-1,0xB8},
                {-0.5,0xDC},
                {0,0x0},
                {0.5,0x24},
                {1,0x48},
                {1.5,0x6c},
                {2,0x7F},
};
#define u2TableSize (arCodeTable/sizeof(CODE_MAPPING_T))

unsigned int wlanTranslate2CodeWord(int au4Input)
{
    int i = 0;
    for (i = 0; i < sizeof(arCodeTable) / sizeof(CODE_MAPPING_T); i++)
    {
        if (arCodeTable[i].u4TxpowerOffset == au4Input)
        {
            return arCodeTable[i].u4RegisterValue;
        }
    }
}

int wlanTranslate2Power(int au4Input)
{
    int i = 0;
    for (i = 0; i < sizeof(arCodeTable) / sizeof(CODE_MAPPING_T); i++)
    {
        if (arCodeTable[i].u4RegisterValue == au4Input)
        {
            return arCodeTable[i].u4TxpowerOffset;
        }
    }
}
*/
//////////////////////////////////////////////////////////////////////////////////////
bool redValueFlag_5G[50];
//---------------------------------------------------------------------------
__fastcall Tfrm5GHz_TX_Power_Profile::Tfrm5GHz_TX_Power_Profile(TComponent* Owner)
    : TForm(Owner)
{
//  m_clickListView = NULL;
//  m_subItemIndex = 0;
    memset(redValueFlag_5G, 1, sizeof(redValueFlag_5G));
    m_clickListView = NULL;
    m_subItemIndex = 0;
    m_wifiChipVersion = 0;
    m_bDisplayTXPowerBackOff = false;
}
//---------------------------------------------------------------------------


void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GHz_TX_Power_RegisterClick(
    TObject *Sender)
{
    if (m_lv5GHz_TX_Power_Register->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GHz_TX_Power_Register-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GHz_TX_Power_Register-> Handle, 1);
    int width2 = ListView_GetColumnWidth(m_lv5GHz_TX_Power_Register-> Handle, 2);

//  TRect rect = m_lv5GHz_TX_Power_Register->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv5GHz_TX_Power_Register->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 + width1 && Pos.x < width0 + width1 + width2)
    {
        m_edt5GHz_TX_Power_Register->Left = m_lv5GHz_TX_Power_Register->Left + width0 + width1 + 8;
        m_edt5GHz_TX_Power_Register->Top = m_lv5GHz_TX_Power_Register->Top + m_lv5GHz_TX_Power_Register->Selected->Top;
//      m_edt5GHz_TX_Power_Register->Height = rect.Height();
//      m_edt5GHz_TX_Power_Register->Width = width2;
        m_edt5GHz_TX_Power_Register->Text = m_lv5GHz_TX_Power_Register->Selected->SubItems->Strings[1];
        m_edt5GHz_TX_Power_Register->Visible = True;
        m_edt5GHz_TX_Power_Register->SetFocus();
    }
//  m_clickListView = m_lv5GHz_TX_Power_Register;
//  m_subItemIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GHz_TX_Power_CompensationClick(
    TObject *Sender)
{
    if (m_lv5GHz_TX_Power_Compensation->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GHz_TX_Power_Compensation-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GHz_TX_Power_Compensation-> Handle, 1);

//    TRect rect = m_lv5GHz_TX_Power_Compensation->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv5GHz_TX_Power_Compensation->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cb5GH_TX_Power_Compensation_Edit->Left = m_lv5GHz_TX_Power_Compensation->Left + width0 + 8;
        m_cb5GH_TX_Power_Compensation_Edit->Top = m_lv5GHz_TX_Power_Compensation->Top + m_lv5GHz_TX_Power_Compensation->Selected->Top;
//        m_cb5GH_TX_Power_Compensation_Edit->Height = rect.Height();
//        m_cb5GH_TX_Power_Compensation_Edit->Width = width2;
        m_cb5GH_TX_Power_Compensation_Edit->Text = m_lv5GHz_TX_Power_Compensation->Selected->SubItems->Strings[0];
        m_cb5GH_TX_Power_Compensation_Edit->Visible = True;
        m_cb5GH_TX_Power_Compensation_Edit->SetFocus();
    }
//    m_clickListView = m_lv5GHz_TX_Power_Compensation;
//    m_subItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_edt5GHz_TX_Power_RegisterExit(
    TObject *Sender)
{
    m_lv5GHz_TX_Power_Register->Selected->SubItems->Strings[1] = m_edt5GHz_TX_Power_Register->Text;
    m_edt5GHz_TX_Power_Register->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_cb5GH_TX_Power_Compensation_EditChange(
    TObject *Sender)
{
    m_lv5GHz_TX_Power_Compensation->Selected->SubItems->Strings[0] = m_cb5GH_TX_Power_Compensation_Edit->Text;
    m_cb5GH_TX_Power_Compensation_Edit->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::Update_5GTX_Power_Compensation_MT6632()
{
    int i, j;
    unsigned char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    META_RESULT mr;
    int temp;

    wifi_nvram.dataLen = 16;
    int WF = m_tc5GH_TX_Power_Compensation->TabIndex;
    if(WF==0)
    {
        wifi_nvram.dataOffset = 0x58;
    }else
    {
        wifi_nvram.dataOffset = 0xF0;
    }
    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 16; i++)
    {
        LOG("Update_5GTX_Power_Compensation_MT6632  pszBufferRaw[%d] = %x", i,pszBufferRaw[i]);
        m_lv5GTXPowerCom->Items->Item[i]->SubItems->Strings[1] = (pszBufferRaw[i] & 0x80)>>7 ;  //BIT[7]: 0: Disable, 1: Enable
        temp = (pszBufferRaw[i] & 0x40) ? 1 : -1 ;  //BIT[6]: 0: Negative, 1: Positive
        m_lv5GTXPowerCom->Items->Item[i]->SubItems->Strings[0] = FloatToStr((pszBufferRaw[i] & 0x7) / 2.0 *temp);
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x68;
    memset(&pszBufferRaw,0,sizeof(pszBufferRaw));

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    if(WF==0)
    {
        m_cb5GEnable->ItemIndex = !(pszBufferRaw[0]&0x01);
    }
    else
    {
        m_cb5GEnable->ItemIndex = !(pszBufferRaw[0]&0x02);
    }

}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::Update_5GTX_Power_Register()
{
    int i = 0;
    //m_lv5GH_TX_Power_Register
    char  pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x22;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 3; i++)
    {
        m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i] / 2.0);
    }

    wifi_nvram.dataLen = 4;
    wifi_nvram.dataOffset = 0x26;

    CurrentPageLock();

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 3; i < 7; i++)
    {
        m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i - 3] / 2.0);
    }

    wifi_nvram.dataLen = 10;
    wifi_nvram.dataOffset = 0x2a;

    CurrentPageLock();

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 7; i < 17; i++)
    {
        m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i - 7] / 2.0);
    }

    //add 20131219
    wifi_nvram.dataLen = 7;
    wifi_nvram.dataOffset = 0x70;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 17; i < 24; i++)
    {
        m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i-17] / 2.0);
    }

    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x78;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 24; i < 27; i++)
    {
        m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i-24] / 2.0);
    }

}

void __fastcall Tfrm5GHz_TX_Power_Profile::Update_5GTX_Power_Compensation()
{
    int i = 0,j=0;
    //m_lv5GH_TX_Power_Compensation
    char  pszBufferRaw[512] = {0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;

    //m_lv5GH_TX_Power_Compensation
    if (0x6620 == m_wifiChipVersion) //MT6620
    {
        wifi_nvram.dataLen = 8;
        wifi_nvram.dataOffset = 0x54;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        char value[9];

        value[0] = (char)(pszBufferRaw[7] >> 6 & 0x01);
        value[1] = (char)(pszBufferRaw[0] & 0x7f);
        value[2] = (char)(pszBufferRaw[0] >> 7 & 0x01) + (char)((pszBufferRaw[1] & 0x3f) << 1);
        value[3] = (char)(pszBufferRaw[1] >> 6 & 0x03) + (char)((pszBufferRaw[2] & 0x1f) << 2);
        value[4] = (char)(pszBufferRaw[2] >> 5 & 0x07) + (char)((pszBufferRaw[3] & 0x0f) << 3);
        value[5] = (char)(pszBufferRaw[4] & 0x7f);
        value[6] = (char)(pszBufferRaw[4] >> 7 & 0x01) + (char)((pszBufferRaw[5] & 0x3f) << 1);
        value[7] = (char)(pszBufferRaw[5] >> 6 & 0x03) + (char)((pszBufferRaw[6] & 0x1f) << 2);
        value[8] = (char)(pszBufferRaw[6] >> 5 & 0x07) + (char)((pszBufferRaw[7] & 0x0f) << 3);
        //add sign
        for(i = 0; i < 8; i++)
        {
            if(value[i + 1] >> 6 & 0x0001)
            {
               value[i + 1] |= 0x80;
            }
            else
            {
                value[i + 1] &= 0x7f;
            }
       }

       m_cb5GHz_TX_Power_Compensation->ItemIndex = !value[0];
       for(i = 0; i < 8; i++)
       {
            m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] =  FloatToStr(value[i + 1] / 2.0);
       }
    }
    else
    {
        if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
        {
            wifi_nvram.dataLen = 9;
            wifi_nvram.dataOffset = 0x60;
            mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
            if(META_SUCCESS != mr)
            {
                m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
                Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
                CurrentPageReset();
                return;
            }
            //char value[8] = {0};
            m_cb5GHz_TX_Power_Compensation->ItemIndex = !(pszBufferRaw[8]);
           /* for(i = 0; i < 8; i++)
            {
                 value[i] = wlanTranslate2Power(pszBufferRaw[i]);
                 m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr();
            } */
            //
            if ( 0x6630 == m_wifiChipVersion )
            {
                for(i = 0; i < 8; i++)
                {
                    for(j = 0; j < _5GH_TX_POWER_COMPENSATION_VALUE_6630; j++)
                    {
                        if(StrToInt(g_lv5GH_TX_Power_Compensation_value_map_6630[j]) == pszBufferRaw[i])
                        {
                            m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv5GH_TX_Power_Compensation_value_6630[j];
                            break;
                        }
                    }
                    if(_5GH_TX_POWER_COMPENSATION_VALUE_6630 == j)
                    {
                        m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = "0";
                    }
                }
            }
            else
            {
                for(i = 0; i < 8; i++)
                {
                    for(j = 0; j < _5GH_TX_POWER_COMPENSATION_VALUE_EX; j++)
                    {
                        if(StrToInt(g_lv5GH_TX_Power_Compensation_value_map[j]) == pszBufferRaw[i])
                        {
                            m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv5GH_TX_Power_Compensation_value_Ex[j];
                            break;
                        }
                    }
                    if(_5GH_TX_POWER_COMPENSATION_VALUE_EX == j)
                    {
                        m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = "0";
                    }
                }
            }


        }
    }
}

void __fastcall Tfrm5GHz_TX_Power_Profile::Update_5GTX_Power_FCC()
{
    int i = 0;
    //m_lv5GH_TX_Power_FCC
    char  pszBufferRaw[512] = {0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;

     //m_lv5GH_TX_Power_FCC
    if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
    {
       wifi_nvram.dataLen = 4;
       wifi_nvram.dataOffset = 0x3E;

       mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
       if(META_SUCCESS != mr)
       {
           m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
           Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
           CurrentPageReset();
           return;
       }
       m_cb5GH_TX_Power_FCC->ItemIndex = !pszBufferRaw[0];
       for(i = 0; i < 3; i++)
       {
           m_lv5GH_TX_Power_FCC->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i + 1] / 2.0);
       }
    }
}

void __fastcall Tfrm5GHz_TX_Power_Profile::Update_5GTX_Power_BackOff()
{
     //m_lv5GH_TX_Power_BackOff
    int i = 0;
    META_RESULT mr;
    char  pszBufferRaw[512] = {0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    if (m_bDisplayTXPowerBackOff)
    {
        wifi_nvram.dataLen = 2;
        wifi_nvram.dataOffset = 0xfe; //0xcc;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
           m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
           Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
           CurrentPageReset();
           return;
        }
        m_cb5GH_TX_Power_BackOff->ItemIndex = !pszBufferRaw[0];
        for(i = 0; i < 1; i++)
        {
           m_lv5GH_TX_Power_BackOff->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i + 1] / 2.0);
        }
    }
//m_lv5GH_TX_Power_BackOff end
}

//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_btnReadFromNVRAMClick(
    TObject *Sender)
{
    //m_lv5GH_TX_Power_Register
    Update_5GTX_Power_Register();
    //m_lv5GH_TX_Power_Compensation
    if((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
    {
        Update_5GTX_Power_Compensation_MT6632();
    }else
    {
        Update_5GTX_Power_Compensation();
    }
    //m_lv5GH_TX_Power_FCC
    Update_5GTX_Power_FCC();
    //m_lv5GH_TX_Power_BackOff
    Update_5GTX_Power_BackOff();

    m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM succeed!";
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::Download_5GTX_Power_Register()
{
    char  pszBufferRaw[512] = {0};
    int i = 0;

    for(i = 0; i < 3; i++)
    {
        pszBufferRaw[i] =  2 * StrToFloat(m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1]);
    }

    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x22;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(i = 3; i < 7; i++)
    {
        pszBufferRaw[i - 3] =  2 * StrToFloat(m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 4;
    wifi_nvram.dataOffset = 0x26;

    CurrentPageLock();

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(i = 7; i < 17; i++)
    {
        pszBufferRaw[i - 7] =  2 * StrToFloat(m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 10;
    wifi_nvram.dataOffset = 0x2a;

    CurrentPageLock();

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset() ;
        return;
    }

    //add 20131219
    for(i = 17; i < 24; i++)
    {
        pszBufferRaw[i - 17] =  2 * StrToFloat(m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 7;
    wifi_nvram.dataOffset = 0x70;

    CurrentPageLock();

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(i = 24; i < 27; i++)
    {
        pszBufferRaw[i - 24] =  2 * StrToFloat(m_lv5GHz_TX_Power_Register->Items->Item[i]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x78;

    CurrentPageLock();

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    //add end
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::Download_5GTX_Power_Compensation_MT6632()
{
    unsigned char pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    int WF = m_tc5GH_TX_Power_Compensation->TabIndex;

    for(int i = 0; i < 16; i++)
    {
        pszBufferRaw[i] = StrToInt(m_lv5GTXPowerCom->Items->Item[i]->SubItems->Strings[1]) ? 0x80 : 0;
        float temp = StrToFloat(m_lv5GTXPowerCom->Items->Item[i]->SubItems->Strings[0]);
        if(temp > 0)
        {
            pszBufferRaw[i] |= 0x40;
        }
        pszBufferRaw[i] = pszBufferRaw[i] | ((unsigned char)(fabs(temp) *2.0));
        LOG("Download_5GTX_Power_Compensation_MT6632 pszBufferRaw[%d] = %x",i,pszBufferRaw[i]);
    }
    wifi_nvram.dataLen = 16;

    if(WF == 0)
    {
        wifi_nvram.dataOffset = 0x58;
    }else
    {
        wifi_nvram.dataOffset = 0xF0;
    }

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x68;
    memset(&pszBufferRaw,0,sizeof(pszBufferRaw));

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    char a = pszBufferRaw[0] & 0x01;
    char b = (pszBufferRaw[0] & 0x02)>>1;
    if(WF == 0)
    {
        a = !m_cb5GEnable->ItemIndex;
        b = b<<1;
        pszBufferRaw[0] = (b + a);

    }
    else
    {
        b = !m_cb5GEnable->ItemIndex;
        b = b<<1;
        pszBufferRaw[0] = (b + a);
    }

    LOG("Download_5GTX_Power_Compensation_MT6632 Enable = %x",pszBufferRaw[0]);

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::Download_5GTX_Power_Compensation()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    int i = 0;
    int j = 0;

    char value[9] = {0};
    if (0x6620 == m_wifiChipVersion) //MT6620
    {
        value[0] = !(m_cb5GHz_TX_Power_Compensation->ItemIndex);
        for(i = 0; i < 8; i++)
        {
            value[i + 1] = (char)(2 * StrToFloat(m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0]));
        }

        pszBufferRaw[0] = (char)((unsigned char)(value[1] & 0x7f)       + (unsigned char)((value[2] & 0x01) << 7));    //0x54
        pszBufferRaw[1] = (char)((unsigned char)(value[2] >> 1 & 0x3f)  + (unsigned char)((value[3] & 0x03) << 6));    //0x55
        pszBufferRaw[2] = (char)((unsigned char)(value[3] >> 2 & 0x1f)  + (unsigned char)((value[4] & 0x07) << 5));    //0x56
        pszBufferRaw[3] = (char)((unsigned char)(value[4] >> 3 & 0x0f));                                               //0x57
        pszBufferRaw[4] = (char)((unsigned char)(value[5] & 0x7f)       + (unsigned char)((value[6] & 0x01) << 7));    //0x58
        pszBufferRaw[5] = (char)((unsigned char)(value[6] >> 1 & 0x3f)  + (unsigned char)((value[7] & 0x03) << 6));    //0x59
        pszBufferRaw[6] = (char)((unsigned char)(value[7] >> 2 & 0x1f)  + (unsigned char)((value[8] & 0x07) << 5));    //0x5a
        pszBufferRaw[7] = (char)((unsigned char)(value[8] >> 3 & 0x0f)  + (unsigned char)((value[0] & 0x01) << 6));    //0x5b

        wifi_nvram.dataLen = 8;
        wifi_nvram.dataOffset = 0x54;
    }
    else
    {
        if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
        {
            pszBufferRaw[8] = !(m_cb5GHz_TX_Power_Compensation->ItemIndex);

            if ( 0x6630 == m_wifiChipVersion )
            {
                for(i = 0; i < 8; i++)
                {
                   for(int j = 0; j < _5GH_TX_POWER_COMPENSATION_VALUE_6630; j++)
                    {
                        if((AnsiString)g_lv5GH_TX_Power_Compensation_value_6630[j] == m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                        {
                            pszBufferRaw[i] = StrToInt(g_lv5GH_TX_Power_Compensation_value_map_6630[j]);
                            break;
                        }
                    }
                }
            }
            else
            {
                for(i = 0; i < 8; i++)
                {
                    for(int j = 0; j < _5GH_TX_POWER_COMPENSATION_VALUE_EX; j++)
                    {
                        if((AnsiString)g_lv5GH_TX_Power_Compensation_value_Ex[j] == m_lv5GHz_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                        {
                            pszBufferRaw[i] = StrToInt(g_lv5GH_TX_Power_Compensation_value_map[j]);
                            break;
                        }
                    }
                }
            }
            wifi_nvram.dataLen = 9;
            wifi_nvram.dataOffset = 0x60;
        }
    }

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
         m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
         Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
         CurrentPageReset();
         return;
    }
}
void __fastcall Tfrm5GHz_TX_Power_Profile::Download_5GTX_Power_FCC()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    int i = 0;

    if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
    {
        pszBufferRaw[0] = !(m_cb5GH_TX_Power_FCC->ItemIndex);
        for(i = 0; i < 3; i++)
        {
           pszBufferRaw[i + 1] = 2 * StrToFloat(m_lv5GH_TX_Power_FCC->Items->Item[i]->SubItems->Strings[0]);
        }

        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x3E;

        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
    }
}

void __fastcall Tfrm5GHz_TX_Power_Profile::Download_5GTX_Power_BackOff()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    int i = 0;

    if (m_bDisplayTXPowerBackOff)
    {
        pszBufferRaw[0] = !(m_cb5GH_TX_Power_BackOff->ItemIndex);
        for(i = 0; i < 1; i++)
        {
           pszBufferRaw[i + 1] = 2 * StrToFloat(m_lv5GH_TX_Power_BackOff->Items->Item[i]->SubItems->Strings[0]);
        }

        wifi_nvram.dataLen = 2;
        wifi_nvram.dataOffset = 0xfe; //0xcc;

        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_btnWriteToNVRAMClick(
    TObject *Sender)
{
   int i = 0;
    bool flag = true;
    for(i = 0; i < 50; i++)
    {
        if(!redValueFlag_5G[i])
        {
            flag = false;
            break;
        }
    }
    if(!flag)
    {
        Application->MessageBox( "Execution Failure: There are invalid values", "FAILURE", MB_OK );
        return;
    }
    
    //m_lv5GHz_TX_Power_Register
    Download_5GTX_Power_Register();

    //m_lv5GH_TX_Power_Compensation
    Download_5GTX_Power_Compensation();

    //m_lv5GH_TX_Power_FCC
    Download_5GTX_Power_FCC();

    //m_lv5GH_TX_Power_BackOff
    Download_5GTX_Power_BackOff();

    m_sb5GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GHz_TX_Power_RegisterAdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(2 == SubItem)
    {
        float registerValue;
        if(IsValidWiFiRegisterValue(Item->SubItems->Strings[SubItem - 1], registerValue)
                && (int)ceil(2 * registerValue) == (int)floor(2 * registerValue))
        {
            Sender->Canvas->Brush->Color = clWindow;
            int index = Item->Index;
            redValueFlag_5G[index] = true;
        }
        else
        {
            Sender->Canvas->Brush->Color = clRed;
            int index =  Item->Index;
            redValueFlag_5G[index] = false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GHz_TX_Power_CompensationAdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        if (0x6620 == m_wifiChipVersion)
        {
            for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv5GH_TX_Power_Compensation_value[i]))
                {
                    break;
                }
            }
            if(_5GH_TX_POWER_COMPENSATION_VALUE == i)
            {
               Sender->Canvas->Brush->Color = clRed;
               int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
               redValueFlag_5G[index] = false;
            }
            else
            {
                Sender->Canvas->Brush->Color = clWindow;
                int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
                redValueFlag_5G[index] = true;
            }
        }
        else if(0x6630 == m_wifiChipVersion)
        {
            for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE_6630; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv5GH_TX_Power_Compensation_value_6630[i]))
                {
                    break;
                }
            }
            if(_5GH_TX_POWER_COMPENSATION_VALUE_6630 == i)
            {
                Sender->Canvas->Brush->Color = clRed;
                int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
                redValueFlag_5G[index] = false;
            }
            else
            {
                Sender->Canvas->Brush->Color = clWindow;
                int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
                redValueFlag_5G[index] = true;
            }
        }
        else
        {
            if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
            {
                for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE_EX; i++)
                {
                    if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv5GH_TX_Power_Compensation_value_Ex[i]))
                    {
                        break;
                    }
                }
                if(_5GH_TX_POWER_COMPENSATION_VALUE_EX == i)
                {
                    Sender->Canvas->Brush->Color = clRed;
                    int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
                    redValueFlag_5G[index] = false;
                }
                else
                {
                    Sender->Canvas->Brush->Color = clWindow;
                    int index = Item->Index + m_lv5GHz_TX_Power_Register->Items->Count;
                    redValueFlag_5G[index] = true;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm5GHz_TX_Power_Profile::FormShow(TObject *Sender)
{
    LOG("frm5GHz_TX_Power_Profile form center the form.");
    FormPositionSetting::CenterForm(this);
    Init();
    m_btnReadFromNVRAMClick(Sender);
}
//---------------------------------------------------------------------------
void Tfrm5GHz_TX_Power_Profile::CurrentPageLock()
{
    m_lv5GHz_TX_Power_Register->Enabled = false;
    GroupBox1->Enabled = false;
    m_btnReadFromNVRAM->Enabled = false;
    m_btnWriteToNVRAM->Enabled = false;
}
//---------------------------------------------------------------------------
void Tfrm5GHz_TX_Power_Profile::CurrentPageReset()
{
    m_lv5GHz_TX_Power_Register->Enabled = true;
    GroupBox1->Enabled = true;
    m_btnReadFromNVRAM->Enabled = true;
    m_btnWriteToNVRAM->Enabled = true;
}
//---------------------------------------------------------------------------

void Tfrm5GHz_TX_Power_Profile::Init(void)
{
    int i = 0;
    m_wifiChipVersion = frmWmWifiMT6620->GetWifiChipVersion();

    if (0x6620 == m_wifiChipVersion) //MT6620
    {
        for(i = 0; i < _5GH_TX_POWER_COMPENSATION_CHANNEL; i++)
        {
            m_lv5GHz_TX_Power_Compensation->Items->Item[i]->Caption = g_lv5GH_TX_Power_Compensation_Channel[i];
        }
        m_lv5GHz_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-4~+4dB, step 0.5)";
        m_cb5GH_TX_Power_Compensation_Edit->Items->Clear();
        for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE; i++)
        {
            m_cb5GH_TX_Power_Compensation_Edit->Items->Add(g_lv5GH_TX_Power_Compensation_value[i]);
        }
        GroupBox5GHzBandEdgeLimit->Visible = false;
    }
    else if((0x6632 == m_wifiChipVersion) || (0x0035 == m_wifiChipVersion) )
    {
        m_cb5GHz_TX_Power_Compensation->Visible = false;
        m_lv5GHz_TX_Power_Compensation->Visible = false;

        m_tc5GH_TX_Power_Compensation->Visible = true;
        m_cb5GEnable->Visible = true;
        m_lv5GTXPowerCom->Visible = true;
        m_btn5GWriteToNvram_MT6632->Visible = true;
        GroupBox5GHzBandEdgeLimit->Visible = false;
    }
    else
    {
        if ((0x6628 != m_wifiChipVersion) && (0x5931 != m_wifiChipVersion))
        {
            if (0x6630 == m_wifiChipVersion)
            {
                for(i = 0; i < _5GH_TX_POWER_COMPENSATION_CHANNEL; i++)
                {
                    m_lv5GHz_TX_Power_Compensation->Items->Item[i]->Caption = g_lv5GH_TX_Power_Compensation_Channel_6630[i];
                }

                m_lv5GHz_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-4~+4dB, step 0.25)";
                m_cb5GH_TX_Power_Compensation_Edit->Items->Clear();
                for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE_6630; i++)
                {
                    m_cb5GH_TX_Power_Compensation_Edit->Items->Add(g_lv5GH_TX_Power_Compensation_value_6630[i]);
                }
            }
            else
            {
                for(i = 0; i < _5GH_TX_POWER_COMPENSATION_CHANNEL; i++)
                {
                    m_lv5GHz_TX_Power_Compensation->Items->Item[i]->Caption = g_lv5GH_TX_Power_Compensation_Channel_Ex[i];
                }

                m_lv5GHz_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-2~+2dB, step 0.5)";
                m_cb5GH_TX_Power_Compensation_Edit->Items->Clear();
                for(i = 0; i < _5GH_TX_POWER_COMPENSATION_VALUE_EX; i++)
                {
                    m_cb5GH_TX_Power_Compensation_Edit->Items->Add(g_lv5GH_TX_Power_Compensation_value_Ex[i]);
                }
            }
            GroupBox5GHzBandEdgeLimit->Visible = true;
        }
    }

    CheckDisplayTXPowerBackOff();
    if (m_bDisplayTXPowerBackOff)
    {
        GroupBox2->Visible = true;
    }
    else
    {
        GroupBox2->Visible = false;
    }

}
void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GH_TX_Power_FCCClick(
      TObject *Sender)
{
    if (m_lv5GH_TX_Power_FCC->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GH_TX_Power_FCC-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GH_TX_Power_FCC-> Handle, 1);


    TPoint Pos;
    Pos = m_lv5GH_TX_Power_FCC->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt5GH_TX_Power_FCC->Left = m_lv5GH_TX_Power_FCC->Left + width0 + 8;
        m_edt5GH_TX_Power_FCC->Top = m_lv5GH_TX_Power_FCC->Top + m_lv5GH_TX_Power_FCC->Selected->Top;
        m_edt5GH_TX_Power_FCC->Text = m_lv5GH_TX_Power_FCC->Selected->SubItems->Strings[0];
        m_edt5GH_TX_Power_FCC->Visible = True;
        m_edt5GH_TX_Power_FCC->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GH_TX_Power_FCCAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int index;
        float FCCValue;
        if(IsValidWiFiRegisterValue(Item->SubItems->Strings[SubItem - 1], FCCValue)
                && (int)ceil(2 * FCCValue) == (int)floor(2 * FCCValue))
        {
            Sender->Canvas->Brush->Color = clWindow;
            index =  Item->Index + m_lv5GHz_TX_Power_Register->Items->Count +
                     m_lv5GHz_TX_Power_Compensation->Items->Count;
            redValueFlag_5G[index] = true;
        }
        else
        {
            Sender->Canvas->Brush->Color = clRed;
            index =  Item->Index + m_lv5GHz_TX_Power_Register->Items->Count +
                     m_lv5GHz_TX_Power_Compensation->Items->Count;
            redValueFlag_5G[index] = false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm5GHz_TX_Power_Profile::m_edt5GH_TX_Power_FCCExit(
      TObject *Sender)
{
    m_lv5GH_TX_Power_FCC->Selected->SubItems->Strings[0] = m_edt5GH_TX_Power_FCC->Text;
    m_edt5GH_TX_Power_FCC->Visible = false;
}
//---------------------------------------------------------------------------



void __fastcall Tfrm5GHz_TX_Power_Profile::m_edt5GH_TX_Power_BackOffExit(
      TObject *Sender)
{
    m_lv5GH_TX_Power_BackOff->Selected->SubItems->Strings[0] = m_edt5GH_TX_Power_BackOff->Text;
    m_edt5GH_TX_Power_BackOff->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GH_TX_Power_BackOffClick(
      TObject *Sender)
{
    if (m_lv5GH_TX_Power_BackOff->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GH_TX_Power_BackOff-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GH_TX_Power_BackOff-> Handle, 1);

    TPoint Pos;
    Pos = m_lv5GH_TX_Power_BackOff->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt5GH_TX_Power_BackOff->Left = m_lv5GH_TX_Power_BackOff->Left + width0 + 8;
        m_edt5GH_TX_Power_BackOff->Top = m_lv5GH_TX_Power_BackOff->Top + m_lv5GH_TX_Power_BackOff->Selected->Top;
        m_edt5GH_TX_Power_BackOff->Text = m_lv5GH_TX_Power_BackOff->Selected->SubItems->Strings[0];
        m_edt5GH_TX_Power_BackOff->Visible = True;
        m_edt5GH_TX_Power_BackOff->SetFocus();
    }
}
//---------------------------------------------------------------------------

void Tfrm5GHz_TX_Power_Profile::CheckDisplayTXPowerBackOff()
{
    char  pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x1d4;
    wifi_nvram.data = pszBufferRaw;

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_bDisplayTXPowerBackOff = false;
        return;
    }
    if(pszBufferRaw[0] == 0x01)
    {
        m_bDisplayTXPowerBackOff = true;
    }
    else
    {
        m_bDisplayTXPowerBackOff = false;
    }
}
void __fastcall Tfrm5GHz_TX_Power_Profile::m_lv5GTXPowerComClick(
      TObject *Sender)
{
   if (m_lv5GTXPowerCom->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GTXPowerCom-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GTXPowerCom-> Handle, 1);

    TPoint Pos;
    Pos = m_lv5GTXPowerCom->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cb_5GHTXPowerCompEdit->Left = m_lv5GTXPowerCom->Left + width0 + 8;
        m_cb_5GHTXPowerCompEdit->Top = m_lv5GTXPowerCom->Top + m_lv5GTXPowerCom->Selected->Top;
        m_cb_5GHTXPowerCompEdit->Text = m_lv5GTXPowerCom->Selected->SubItems->Strings[0];
        m_cb_5GHTXPowerCompEdit->Visible = True;
        m_cb_5GHTXPowerCompEdit->SetFocus();
    }

    int width2 = ListView_GetColumnWidth(m_lv5GTXPowerCom-> Handle, 2);

    TPoint Pos2;
    Pos2 = m_lv5GTXPowerCom->ScreenToClient(Mouse->CursorPos);
    if(Pos2.x > width0 + width1 && Pos2.x < width0 + width1+width2)
    {
        m_cb_5GH_EnableEdit->Left = m_lv5GTXPowerCom->Left + width0 + width1 + 8;
        m_cb_5GH_EnableEdit->Top = m_lv5GTXPowerCom->Top + m_lv5GTXPowerCom->Selected->Top;
        m_cb_5GH_EnableEdit->Text = m_lv5GTXPowerCom->Selected->SubItems->Strings[1];
        m_cb_5GH_EnableEdit->Visible = True;
        m_cb_5GH_EnableEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------


void __fastcall Tfrm5GHz_TX_Power_Profile::m_cb_5GHTXPowerCompEditExit(
      TObject *Sender)
{
    m_lv5GTXPowerCom->Selected->SubItems->Strings[0] = m_cb_5GHTXPowerCompEdit->Text;
    m_cb_5GHTXPowerCompEdit->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm5GHz_TX_Power_Profile::m_cb_5GH_EnableEditExit(
      TObject *Sender)
{
    m_lv5GTXPowerCom->Selected->SubItems->Strings[1] = m_cb_5GH_EnableEdit->Text;
    m_cb_5GH_EnableEdit->Visible = false;
}
//---------------------------------------------------------------------------





void __fastcall Tfrm5GHz_TX_Power_Profile::m_tc5GH_TX_Power_CompensationChange(
      TObject *Sender)
{
    Update_5GTX_Power_Compensation_MT6632();
}
//---------------------------------------------------------------------------


void __fastcall Tfrm5GHz_TX_Power_Profile::m_btn5GWriteToNvram_MT6632Click(
      TObject *Sender)
{
    Download_5GTX_Power_Compensation_MT6632();        
}
//---------------------------------------------------------------------------

