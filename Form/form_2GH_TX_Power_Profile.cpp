//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "form_2GH_TX_Power_Profile.h"
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

Tfrm2GH_TX_Power_Profile *frm2GH_TX_Power_Profile;

typedef struct
{
    char * register_Name;
    char * data_Rate;
    char register_value;
    unsigned char nvram_address;
} _2GH_TX_POWER_PROFILE_REGISTER;

/*
typedef struct _2GH_TX_POWER_PROFILE_COMPENSATION
{
    char * channels;
    short register_value;
} _2GH_TX_POWER_PROFILE_COMPENSATION;

typedef struct _2GH_TX_POWER_PROFILE_FCC
{
    char * max_power;
    char register_value;
    unsigned char nvram_address;
} _2GH_TX_POWER_PROFILE_FCC;

_2GH_TX_POWER_PROFILE_REGISTER g_2ghz_tx_power_profile_register[18] =
{
    {"cTxPwr2G4Cck"	        ,"CCK 1M, 2M,5.5M, 11M" 	,0x28	,0x0c},
    {"cTXPwr2G4OFDM_BPSK"	,"OFDM 6M, 9M"	            ,0x24	,0x10},
    {"cTXPwr2G4OFDM_QPSK"	,"OFDM 12M, 18M"	        ,0x24	,0x11},
    {"cTXPwr2G4OFDM_16QAM"	,"OFDM 24M, 36M"	        ,0x24	,0x12},
    {"cTXPwr2G4OFDM_48M"	,"OFDM 48M"	                ,0x24	,0x14},
    {"cTXPwr2G4OFDM_54M"	,"OFDM 54M"	                ,0x24	,0x15},
    {"cTXPwr2G4HT20_BPSK"	,"HT20 MC0"	                ,0x24	,0x16},
    {"cTXPwr2G4HT20_QPSK"	,"HT20 MCS1, MCS2"	        ,0x24	,0x17},
    {"cTXPwr2G4HT20_16QAM"	,"HT20 MCS3, MCS4"	        ,0x24	,0x18},
    {"cTXPwr2G4HT20_MCS5"	,"HT20 MCS5"	            ,0x24	,0x19},
    {"cTXPwr2G4HT20_MCS6"	,"HT20 MCS6"	            ,0x24	,0x1a},
    {"cTXPwr2G4HT20_MCS7"	,"HT20 MCS7"	            ,0x24	,0x1b},
    {"cTXPwr2G4HT40_BPSK"	,"HT40 MC0"	                ,0x20	,0x1c},
    {"cTXPwr2G4HT40_QPSK"	,"HT40 MCS1, MCS2"	        ,0x20	,0x1d},
    {"cTXPwr2G4HT40_16QAM"	,"HT40 MCS3, MCS4"	        ,0x20	,0x1e},
    {"cTXPwr2G4HT40_MCS5"	,"HT40 MCS5"	            ,0x20	,0x1f},
    {"cTXPwr2G4HT40_MCS6"	,"HT40 MCS6"	            ,0x20	,0x20},
    {"cTXPwr2G4HT40_MCS7"	,"HT40 MCS7"	            ,0x20	,0x21}
};*/
_2GH_TX_POWER_PROFILE_REGISTER g_2ghz_tx_power_register_mt6632[9] =
{
    {"c11AcTxPwr2G_BPSK"	,"MCS0" 	,0	,0x90},
    {"c11AcTxPwr2G_QPSK"	,"MCS1,2"	,0	,0x91},
    {"c11AcTxPwr2G_16QAM"	,"MCS3,4"	,0	,0x92},
    {"c11AcTxPwr2G_MCS5_MCS6"	,"MCS5,6"	,0	,0x93},
    {"c11AcTxPwr2G_MCS7"	,"MCS7"	        ,0	,0x94},
    {"c11AcTxPwr2G_MCS8"	,"MCS8"	        ,0	,0x95},
    {"c11AcTxPwr2G_MCS9"	,"MCS9"	        ,0	,0x96},
    {"c11AcTxPwr2G_Reserved"	,"Reserved"     ,0	,0x97},
    {"c11AcTxPwrVht402G_OFFSET"	,"VHT40 offset with VHT20"	,0	,0x98}
};
#define _2GH_TX_POWER_COMPENSATION_VALUE 17
#define _2GH_TX_POWER_COMPENSATION_VALUE_5931 17
#define _2GH_TX_POWER_COMPENSATION_VALUE_6632 15
//#define _2GH_TX_POWER_LISTVIEW_ITEM_COUNT 25
#define _2GH_TX_POWER_LISTVIEW_ITEM_COUNT 100
#define _2GH_TX_POWER_COMPENSATION_VALUE_6628 9
#define _2GH_TX_POWER_COMPENSATION_VALUE_6630 33
#define _2GH_TX_POWER_COMPENSATION_VALUE_6625 15
#define _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628 17
char g_lv2GH_TX_Power_Compensation_value_6632[_2GH_TX_POWER_COMPENSATION_VALUE_6632][10] =
{
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
    "3.5"
};

char g_lv2GH_TX_Power_Compensation_value[_2GH_TX_POWER_COMPENSATION_VALUE][10] =
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

char g_lv2GH_TX_Power_Compensation_value_5931[_2GH_TX_POWER_COMPENSATION_VALUE_5931][10] =
{
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
    "2"
};

char g_lv2GH_TX_Power_Compensation_value_map_5931[_2GH_TX_POWER_COMPENSATION_VALUE_5931][10] =
{
    "-128",
    "-114",
    "-98",
    "-81",
    "-65",
    "-49",
    "-33",
    "-16",
    "0",
    "16",
    "33",
    "49",
    "65",
    "81",
    "98",
    "114",
    "127"
};

//20120605 qinqin add
char g_lv2GH_TX_Power_Compensation_value_6628[_2GH_TX_POWER_COMPENSATION_VALUE_6628][10] =
{
    "-2",
    "-1.5",
    "-1",
    "-0.5",
    "0",
    "0.5",
    "1",
    "1.5",
    "2"
};

char g_lv2GH_TX_Power_Compensation_value_map_6628[_2GH_TX_POWER_COMPENSATION_VALUE_6628][10] =
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
char g_lv2GH_TX_Power_Compensation_value_6630[_2GH_TX_POWER_COMPENSATION_VALUE_6630][10] =
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

char g_lv2GH_TX_Power_Compensation_value_map_6630[_2GH_TX_POWER_COMPENSATION_VALUE_6630][10] =
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

char g_lv2GH_TX_Power_Compensation_value_6625[_2GH_TX_POWER_COMPENSATION_VALUE_6625][10] =
{
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
};

char g_lv2GH_TX_Power_Compensation_value_map_6625[_2GH_TX_POWER_COMPENSATION_VALUE_6625][10] =
{
    "-126",
    "-108",
    "-90",
    "-72",
    "-54",
    "-36",
    "-18",
    "0",
    "18",
    "36",
    "54",
    "72",
    "90",
    "108",
    "126",
};

char g_lv2GH_TX_Power_Compensation_AllChannel_value_6628[_2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628][10] =
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

char g_lv2GH_TX_Power_Compensation_AllChannel_value_map_6628[_2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628][10] =
{
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "7"
};


bool redValueFlag_2G[_2GH_TX_POWER_LISTVIEW_ITEM_COUNT];


//---------------------------------------------------------------------------
__fastcall Tfrm2GH_TX_Power_Profile::Tfrm2GH_TX_Power_Profile(TComponent* Owner)
    : TForm(Owner)
{
//    m_clickListView = NULL;
//    m_subItemIndex = 0;
    memset(redValueFlag_2G, 1, sizeof(redValueFlag_2G));
    m_wifiChipVersion = 0;
    flag_6632 = 0;
    m_bDisplayTXPowerBackOff = false;
}

//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_RegisterClick(TObject *Sender)
{
    if (m_lv2GH_TX_Power_Register->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Register-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Register-> Handle, 1);
    int width2 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Register-> Handle, 2);

//    TRect rect = m_lv2GH_TX_Power_Register->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_Register->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 + width1 && Pos.x < width0 + width1 + width2)
    {
        m_edt2GH_TX_Power_Register->Left = m_lv2GH_TX_Power_Register->Left + width0 + width1 + 8;
        m_edt2GH_TX_Power_Register->Top = m_lv2GH_TX_Power_Register->Top + m_lv2GH_TX_Power_Register->Selected->Top;
//        m_edt2GH_TX_Power_Register->Height = rect.Height();
//        m_edt2GH_TX_Power_Register->Width = width2;
        m_edt2GH_TX_Power_Register->Text = m_lv2GH_TX_Power_Register->Selected->SubItems->Strings[1];
        m_edt2GH_TX_Power_Register->Visible = True;
        m_edt2GH_TX_Power_Register->SetFocus();
    }
//    m_clickListView = m_lv2GH_TX_Power_Register;
//    m_subItemIndex = 1;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_lvTXPowerComClick(
      TObject *Sender)
{
    if (m_lvTXPowerCom->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lvTXPowerCom-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lvTXPowerCom-> Handle, 1);

    TPoint Pos;
    Pos = m_lvTXPowerCom->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cb_2GHTXPowerCompEdit->Left = m_lvTXPowerCom->Left + width0 + 8;
        m_cb_2GHTXPowerCompEdit->Top = m_lvTXPowerCom->Top + m_lvTXPowerCom->Selected->Top;
        m_cb_2GHTXPowerCompEdit->Text = m_lvTXPowerCom->Selected->SubItems->Strings[0];
        m_cb_2GHTXPowerCompEdit->Visible = True;
        m_cb_2GHTXPowerCompEdit->SetFocus();
    }

    int width2 = ListView_GetColumnWidth(m_lvTXPowerCom-> Handle, 2);

    TPoint Pos2;
    Pos2 = m_lvTXPowerCom->ScreenToClient(Mouse->CursorPos);
    if(Pos2.x > width0 + width1 && Pos2.x < width0 + width1+width2)
    {
        m_cb_2GH_EnableEdit->Left = m_lvTXPowerCom->Left + width0 + width1 + 8;
        m_cb_2GH_EnableEdit->Top = m_lvTXPowerCom->Top + m_lvTXPowerCom->Selected->Top;
        m_cb_2GH_EnableEdit->Text = m_lvTXPowerCom->Selected->SubItems->Strings[1];
        m_cb_2GH_EnableEdit->Visible = True;
        m_cb_2GH_EnableEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_CompensationClick(
    TObject *Sender)
{
    if (m_lv2GH_TX_Power_Compensation->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Compensation-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Compensation-> Handle, 1);

//    TRect rect = m_lv2GH_TX_Power_Compensation->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_Compensation->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cb2GH_TX_Power_Compensation_Edit->Left = m_lv2GH_TX_Power_Compensation->Left + width0 + 8;
        m_cb2GH_TX_Power_Compensation_Edit->Top = m_lv2GH_TX_Power_Compensation->Top + m_lv2GH_TX_Power_Compensation->Selected->Top;
//        m_cb2GH_TX_Power_Compensation_Edit->Height = rect.Height();
//        m_cb2GH_TX_Power_Compensation_Edit->Width = width2;
        m_cb2GH_TX_Power_Compensation_Edit->Text = m_lv2GH_TX_Power_Compensation->Selected->SubItems->Strings[0];
        m_cb2GH_TX_Power_Compensation_Edit->Visible = True;
        m_cb2GH_TX_Power_Compensation_Edit->SetFocus();
    }
//    m_clickListView =  m_lv2GH_TX_Power_Compensation;
//    m_subItemIndex = 0;
}


void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_Compensation_AllChannel_Click(
    TObject *Sender)
{
    if (m_lv2GH_TX_Power_CompensationAllChannel->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_CompensationAllChannel-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_CompensationAllChannel-> Handle, 1);

//    TRect rect = m_lv2GH_TX_Power_Compensation->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_CompensationAllChannel->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Left = m_lv2GH_TX_Power_CompensationAllChannel->Left + width0 + 8;
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Top = m_lv2GH_TX_Power_CompensationAllChannel->Top + m_lv2GH_TX_Power_CompensationAllChannel->Selected->Top;
//        m_cb2GH_TX_Power_Compensation_Edit->Height = rect.Height();
//        m_cb2GH_TX_Power_Compensation_Edit->Width = width2;
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Text = m_lv2GH_TX_Power_CompensationAllChannel->Selected->SubItems->Strings[0];
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Visible = True;
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->SetFocus();
    }
//    m_clickListView =  m_lv2GH_TX_Power_Compensation;
//    m_subItemIndex = 0;
}

//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_FCCClick(
    TObject *Sender)
{
    if (m_lv2GH_TX_Power_FCC->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_FCC-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_FCC-> Handle, 1);

//    TRect rect = m_lv2GH_TX_Power_FCC->Selected->DisplayRect(drBounds);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_FCC->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt2GH_TX_Power_FCC->Left = m_lv2GH_TX_Power_FCC->Left + width0 + 8;
        m_edt2GH_TX_Power_FCC->Top = m_lv2GH_TX_Power_FCC->Top + m_lv2GH_TX_Power_FCC->Selected->Top;
//        m_edt2GH_TX_Power_Register->Height = rect.Height();
//        m_edt2GH_TX_Power_Register->Width = width2;
        m_edt2GH_TX_Power_FCC->Text = m_lv2GH_TX_Power_FCC->Selected->SubItems->Strings[0];
        m_edt2GH_TX_Power_FCC->Visible = True;
        m_edt2GH_TX_Power_FCC->SetFocus();
    }
//    m_clickListView = m_lv2GH_TX_Power_FCC;
//    m_subItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_edt2GH_TX_Power_RegisterExit(TObject *Sender)
{
//    m_clickListView->Selected->SubItems->Strings[m_subItemIndex] = m_edt2GH_TX_Power_Register->Text;
    m_lv2GH_TX_Power_Register->Selected->SubItems->Strings[1] = m_edt2GH_TX_Power_Register->Text;
    m_edt2GH_TX_Power_Register->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_cb2GH_TX_Power_Compensation_EditChange(
    TObject *Sender)
{
    m_lv2GH_TX_Power_Compensation->Selected->SubItems->Strings[0] = m_cb2GH_TX_Power_Compensation_Edit->Text;
    m_cb2GH_TX_Power_Compensation_Edit->Visible = false;
}

void __fastcall Tfrm2GH_TX_Power_Profile::m_cb2GH_TX_Power_Compensation_AllChannel_EditChange(
    TObject *Sender)
{
    m_lv2GH_TX_Power_CompensationAllChannel->Selected->SubItems->Strings[0] = m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Text;
    m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Visible = false;
}

void __fastcall Tfrm2GH_TX_Power_Profile::m_cb_2GHTXPowerCompEditChange(
      TObject *Sender)
{
    m_lvTXPowerCom->Selected->SubItems->Strings[0] = m_cb_2GHTXPowerCompEdit->Text;
    m_cb_2GHTXPowerCompEdit->Visible = false;
}
void __fastcall Tfrm2GH_TX_Power_Profile::m_cb_2GH_EnableEditChange(
      TObject *Sender)
{
    m_lvTXPowerCom->Selected->SubItems->Strings[1] = m_cb_2GH_EnableEdit->Text;
    m_cb_2GH_EnableEdit->Visible = false;
}





//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_edt2GH_TX_Power_FCCExit(
    TObject *Sender)
{
    m_lv2GH_TX_Power_FCC->Selected->SubItems->Strings[0] = m_edt2GH_TX_Power_FCC->Text;
    m_edt2GH_TX_Power_FCC->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::Update_TX_Power_Register()
{
    int i, j;
    int idx = 0;
    char  pszBufferRaw[512]={0};


    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x0c;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    m_lv2GH_TX_Power_Register->Items->Item[idx++]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[0] / 2.0);

//for 5931
//start
    if((0x5931 == m_wifiChipVersion) || (0x6628 == m_wifiChipVersion)|| (0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))    //modified 20120525 qinqin
    {
        wifi_nvram.dataLen = 1;
        wifi_nvram.dataOffset = 0x0d;
        META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        m_lv2GH_TX_Power_Register->Items->Item[idx++]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[0] / 2.0);
    }
//end

    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x10;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 3; i++, idx++)
    {
        m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i] / 2.0);
    }

    wifi_nvram.dataLen = 6;
    wifi_nvram.dataOffset = 0x14;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 6; i++, idx++)
    {
        m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i] / 2.0);
    }

    wifi_nvram.dataLen = 8;
    wifi_nvram.dataOffset = 0x1a;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 8; i++, idx++)
    {
        m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i] / 2.0);
    }

    if((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        wifi_nvram.dataLen = 9;
        wifi_nvram.dataOffset = 0x90;
        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        for(i = 0; i < 9; i++, idx++)
        {
            AnsiString temp = FloatToStr(pszBufferRaw[i] / 2.0);
            m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1] = FloatToStr(pszBufferRaw[i] / 2.0);
        }
    }

}




void __fastcall Tfrm2GH_TX_Power_Profile::Update_TX_Power_Compensation_MT6632()
{
    int i, j;
    unsigned char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    META_RESULT mr;
    int temp;

    wifi_nvram.dataLen = 14;
    int WF = m_tc2GH_TX_Power_Compensation->TabIndex;
    if(WF==0)
    {
        wifi_nvram.dataOffset = 0x42;
    }else
    {
        wifi_nvram.dataOffset = 0x176;
    }
    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    for(i = 0; i < 14; i++)
    {
        LOG("Update_2GTX_Power_Compensation_MT6632  pszBufferRaw[%d] = %x", i,pszBufferRaw[i]);
        m_lvTXPowerCom->Items->Item[i]->SubItems->Strings[1] = (pszBufferRaw[i] & 0x80)>>7 ;  //BIT[7]: 0: Disable, 1: Enable
        temp = (pszBufferRaw[i] & 0x40) ? 1 : -1 ;  //BIT[6]: 0: Negative, 1: Positive
        m_lvTXPowerCom->Items->Item[i]->SubItems->Strings[0] = FloatToStr((pszBufferRaw[i] & 0x7) / 2.0 *temp);
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x53;
    memset(&pszBufferRaw,0,sizeof(pszBufferRaw));



    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    
    if(WF==0)
    {
        m_cbEnable->ItemIndex = !(pszBufferRaw[0]&0x01);
    }
    else
    {
        m_cbEnable->ItemIndex = !(pszBufferRaw[0]&0x02);
    }
}
void __fastcall Tfrm2GH_TX_Power_Profile::Update_TX_Power_Compensation()
{
    int i, j;
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    META_RESULT mr;

    if(0x5931 == m_wifiChipVersion)
    {
        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

        m_cb2GH_TX_Power_Compensation->ItemIndex = !(pszBufferRaw[3] & 0x01);
        for(i = 0; i < 3; i++)
        {
            /*			if(0x80 == pszBufferRaw[i])
            			{
            				m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = IntToStr(-2);
            			}
            			else if(0x7f == pszBufferRaw[i])
            			{
            				m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = IntToStr(2);
            			}
            			else
            			{
            				m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
            			}                                */
            for(j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_5931; j++)
            {
                if(StrToInt(g_lv2GH_TX_Power_Compensation_value_map_5931[j]) == pszBufferRaw[i])
                {
                    m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv2GH_TX_Power_Compensation_value_5931[j];
                    break;
                }
            }
            if(_2GH_TX_POWER_COMPENSATION_VALUE_5931 == j)
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
            }
        }
    }
    else if(0x6625 == m_wifiChipVersion)
    {
        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

        m_cb2GH_TX_Power_Compensation->ItemIndex = !(pszBufferRaw[3] & 0x01);
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6625; j++)
            {
                if(StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6625[j]) == pszBufferRaw[i])
                {
                    m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv2GH_TX_Power_Compensation_value_6625[j];
                    break;
                }
            }
            if(_2GH_TX_POWER_COMPENSATION_VALUE_6625 == j)
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
            }
        }
    }
    else if(0x6628 == m_wifiChipVersion)
    {
        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

        m_cb2GH_TX_Power_Compensation->ItemIndex = !(pszBufferRaw[3] & 0x01);
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6628; j++)
            {
                if(StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6628[j]) == pszBufferRaw[i])
                {
                    m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv2GH_TX_Power_Compensation_value_6628[j];
                    break;
                }
            }
            if(_2GH_TX_POWER_COMPENSATION_VALUE_6628 == j)
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
            }
        }
    }
    else if(0x6630 == m_wifiChipVersion)
    {
        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

        m_cb2GH_TX_Power_Compensation->ItemIndex = !(pszBufferRaw[3] & 0x01);
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6630; j++)
            {
                if(StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6630[j]) == pszBufferRaw[i])
                {
                    m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lv2GH_TX_Power_Compensation_value_6630[j];
                    break;
                }
            }
            if(_2GH_TX_POWER_COMPENSATION_VALUE_6630 == j)
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
            }
        }
    }
    else
    {
        wifi_nvram.dataLen = 4;
        //rongguo 2011-06-21
        //    wifi_nvram.dataOffset = 0x72;
        wifi_nvram.dataOffset = 0x7c;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        short value[4];
        value[0] = (short)(pszBufferRaw[3] >> 3 & 0x01);
        value[1] = (short)(((short)(unsigned char)pszBufferRaw[1] & 0x0001) << 8) + (short)(unsigned char)pszBufferRaw[0];
        value[2] = (short)(((short)(unsigned char)pszBufferRaw[2] & 0x0003) << 7) + (short)((short)(unsigned char)pszBufferRaw[1] >> 1 & 0x007f);
        value[3] = (short)(((short)(unsigned char)pszBufferRaw[3] & 0x0007) << 6) + (short)((short)(unsigned char)pszBufferRaw[2] >> 2 & 0x003f);
        //add sign
        for(i = 0; i < 3; i++)
        {
            if(value[i + 1] >> 8 & 0x0001)
            {
                value[i + 1] |= 0xff00;
            }
            else
            {
                value[i + 1] &= 0x00ff;
            }
        }
        m_cb2GH_TX_Power_Compensation->ItemIndex = !value[0];
        for(i = 0; i < 3; i++)
        {
            if(-256 == value[i + 1])
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = IntToStr(-4);
            }
            else if(255 == value[i + 1])
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = IntToStr(4);
            }
            else
            {
                m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(value[i + 1] / 72.0);
            }
        }
    }
}
void __fastcall Tfrm2GH_TX_Power_Profile::Update_TX_Power_Compensation_AllChannels()
{
    int i, j;
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    META_RESULT mr;
    
    if(0x6628 == m_wifiChipVersion)
    {
        wifi_nvram.dataLen = 1;
        wifi_nvram.dataOffset = 0x54;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

        m_cb2GH_TX_Power_Compensation_AllChannel->ItemIndex = !((pszBufferRaw[0] >> 7) & 0x01);
        for(j = 0; j < _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628; j++)
        {

            if((StrToInt(g_lv2GH_TX_Power_Compensation_AllChannel_value_map_6628[j])) == (pszBufferRaw[0] & 0x0f))
            {
                m_lv2GH_TX_Power_CompensationAllChannel->Items->Item[0]->SubItems->Strings[0] = g_lv2GH_TX_Power_Compensation_AllChannel_value_6628[j];
                break;
            }
        }

    }

}
void __fastcall Tfrm2GH_TX_Power_Profile::Update_TX_Power_FCC()
{
    int i, j;
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    META_RESULT mr;

    if (m_bDisplayTXPowerBackOff)
    {
        //m_lv2GH_TX_Power_BackOff
        wifi_nvram.dataLen = 2;
        wifi_nvram.dataOffset = 0xfc; //0xca;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        m_cb2GH_TX_Power_BackOff->ItemIndex = !pszBufferRaw[0];
        for(i = 0; i < 1; i++)
        {
            m_lv2GH_TX_Power_BackOff->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i + 1] / 2.0);
        }
        //m_lv2GH_TX_Power_BackOff end

        //m_lv2GH_TX_Power_Offset
        wifi_nvram.dataLen = 200;  //40*5
        wifi_nvram.dataOffset = 0x10c;

        mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
            Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        for(i = 0; i < 40; i++)
        {
            for(j = 0; j < 5; j++)
            {
                 if( j == 0)
                 {
                     m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j] = FloatToStr(pszBufferRaw[i*5 + j]);
                 }
                 else
                 {
                     m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j] = FloatToStr(pszBufferRaw[i*5 + j] / 2.0);
                     //LOG("read NVRAM i:%d,j:%d,m_lv2GH_TX_Power_Offset:%s",i,j,m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j]);
                 }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_btnReadFromNVRAMClick(
    TObject *Sender)
{
//m_lv2GH_TX_Power_Register
    Update_TX_Power_Register();

//m_lv2GH_TX_Power_Compensation
    if((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        Update_TX_Power_Compensation_MT6632();
    }
    else
    {
        Update_TX_Power_Compensation();
    }

//for 6628 m_lv2GH_TX_Power_Compensation_AllChannels
    Update_TX_Power_Compensation_AllChannels();

//m_lv2GH_TX_Power_FCC
    Update_TX_Power_FCC();

    m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM succeed!";

    CurrentPageReset();
}

void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_Register()
{
    char  pszBufferRaw[512]={0};
    int idx = 0;
    pszBufferRaw[0] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx++]->SubItems->Strings[1]);

    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x0c;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    if((0x5931 == m_wifiChipVersion) || (0x6628 == m_wifiChipVersion)|| (0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        pszBufferRaw[0] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx++]->SubItems->Strings[1]);

        wifi_nvram.dataLen = 1;
        wifi_nvram.dataOffset = 0x0d;

        META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
    }

    for(int i = 0; i < 3; i++, idx++)
    {
        pszBufferRaw[i] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x10;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(int i = 0; i < 6; i++, idx++)
    {
        pszBufferRaw[i] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 6;
    wifi_nvram.dataOffset = 0x14;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(int i = 0; i < 8; i++, idx++)
    {
        pszBufferRaw[i] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1]);
    }

    wifi_nvram.dataLen = 8;
    wifi_nvram.dataOffset = 0x1a;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    if((0x6632 == m_wifiChipVersion) || (0x0035 == m_wifiChipVersion))
    {
        for(int i = 0; i < 9; i++, idx++)
        {
                pszBufferRaw[i] =  2 * StrToFloat(m_lv2GH_TX_Power_Register->Items->Item[idx]->SubItems->Strings[1]);
        }
        wifi_nvram.dataLen = 9;
        wifi_nvram.dataOffset = 0x90;
    
        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
                m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
                Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
                CurrentPageReset();
                return;
        }
    }

}

void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_Compensation()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;

    if(0x5931 == m_wifiChipVersion)
    {
        for(int i = 0; i < 3; i++)
        {
            /*		if(0.000001 > fabs(-2 - StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])))
            		{
            		pszBufferRaw[i] = 0x80;
            		}
            		else if(0.000001 > fabs(2 - StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])))
            		{
            		pszBufferRaw[i] = 0x7f;
            		}
            		else
            		{
            		pszBufferRaw[i] = (short)(65 * StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0]));
            		} */
            for(int j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_5931; j++)
            {
                if((AnsiString)g_lv2GH_TX_Power_Compensation_value_5931[j] == m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                {
                    pszBufferRaw[i] = StrToInt(g_lv2GH_TX_Power_Compensation_value_map_5931[j]);
                    break;
                }
            }
        }
        pszBufferRaw[3] = !(m_cb2GH_TX_Power_Compensation->ItemIndex);

        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;
    }
    else if(0x6625 == m_wifiChipVersion)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6625; j++)
            {
                if((AnsiString)g_lv2GH_TX_Power_Compensation_value_6625[j] == m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                {
                    pszBufferRaw[i] = StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6625[j]);
                    break;
                }
            }
        }
        pszBufferRaw[3] = !(m_cb2GH_TX_Power_Compensation->ItemIndex);

        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;
    }
    else if(0x6628 == m_wifiChipVersion)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6628; j++)
            {
                if((AnsiString)g_lv2GH_TX_Power_Compensation_value_6628[j] == m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                {
                    pszBufferRaw[i] = StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6628[j]);
                    break;
                }
            }
        }
        pszBufferRaw[3] = !(m_cb2GH_TX_Power_Compensation->ItemIndex);

        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;
    }
    else if(0x6630 == m_wifiChipVersion)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < _2GH_TX_POWER_COMPENSATION_VALUE_6630; j++)
            {
                if((AnsiString)g_lv2GH_TX_Power_Compensation_value_6630[j] == m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])
                {
                    pszBufferRaw[i] = StrToInt(g_lv2GH_TX_Power_Compensation_value_map_6630[j]);
                    break;
                }
            }
        }
        pszBufferRaw[3] = !(m_cb2GH_TX_Power_Compensation->ItemIndex);

        wifi_nvram.dataLen = 4;
        wifi_nvram.dataOffset = 0x50;
    }
    else
    {
        short value[4];
        value[0] = !(m_cb2GH_TX_Power_Compensation->ItemIndex);
        for(int i = 0; i < 3; i++)
        {
            if(0.000001 > fabs(-4 - StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])))
            {
                value[i + 1] = -256;
            }
            else if(0.000001 > fabs(4 - StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0])))
            {
                value[i + 1] = 255;
            }
            else
            {
                value[i + 1] = (short)(72 * StrToFloat(m_lv2GH_TX_Power_Compensation->Items->Item[i]->SubItems->Strings[0]));
            }
        }

        pszBufferRaw[0] = (char)(value[1] & 0x00ff);                                             //0x72
        pszBufferRaw[1] = (char)((value[1] >> 8) & 0x0001) + (char)((value[2]& 0x007f) << 1);    //0x73
        pszBufferRaw[2] = (char)((value[2] >> 7) & 0x0003) + (char)((value[3]& 0x003f) << 2);    //0x74
        pszBufferRaw[3] = (char)((value[3] >> 6) & 0x0007) + (char)((value[0]& 0x0001) << 3);    //0x75

        wifi_nvram.dataLen = 4;
        //rongguo 2011-06-21
        //        wifi_nvram.dataOffset = 0x72;
        wifi_nvram.dataOffset = 0x7c;
    }

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
}
void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_Compensation_AllChannels()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
     //for 6628 m_lv2GH_TX_Power_Compensation_AllChannels
    if(0x6628 == m_wifiChipVersion)
    {

        for(int j = 0; j < _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628; j++)
        {
            if((AnsiString)g_lv2GH_TX_Power_Compensation_AllChannel_value_6628[j] == m_lv2GH_TX_Power_CompensationAllChannel->Items->Item[0]->SubItems->Strings[0])
            {
                pszBufferRaw[0] = StrToInt(g_lv2GH_TX_Power_Compensation_AllChannel_value_map_6628[j]);
                break;
            }
        }
        pszBufferRaw[0] |= 0x80;
        pszBufferRaw[0] &= (((!(m_cb2GH_TX_Power_Compensation_AllChannel->ItemIndex)) << 7) | 0x7f);
        wifi_nvram.dataLen = 1;
        wifi_nvram.dataOffset = 0x54;

        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }

    }
}

void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_FCC()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    pszBufferRaw[0] = !(m_cb2GH_TX_Power_FCC->ItemIndex);
    for(int i = 0; i < 3; i++)
    {
        pszBufferRaw[i + 1] = 2 * StrToFloat(m_lv2GH_TX_Power_FCC->Items->Item[i]->SubItems->Strings[0]);
    }

    wifi_nvram.dataLen = 4;
    wifi_nvram.dataOffset = 0xc6;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
}

void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_BackOff()
{
    char  pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    if (m_bDisplayTXPowerBackOff)
    {
        //m_lv2GH_TX_Power_BackOff
        pszBufferRaw[0] = !(m_cb2GH_TX_Power_BackOff->ItemIndex);
        for(int i = 0; i < 1; i++)
        {
            pszBufferRaw[i + 1] = 2 * StrToFloat(m_lv2GH_TX_Power_BackOff->Items->Item[i]->SubItems->Strings[0]);
        }

        wifi_nvram.dataLen = 2;
        wifi_nvram.dataOffset = 0xfc; //0xca;

        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        //m_lv2GH_TX_Power_BackOff end
        for(int i = 0; i < 40; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if( j == 0)
                {
                    pszBufferRaw[i*5 + j] = StrToFloat(m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j]);
                }
                else
                {
                    pszBufferRaw[i*5 + j] = 2 * StrToFloat(m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j]);
                    //LOG("write NVRAM i:%d,j:%d,m_lv2GH_TX_Power_Offset:%s",i,j,m_lv2GH_TX_Power_Offset->Items->Item[i]->SubItems->Strings[j]);
                }
            }
        }
        wifi_nvram.dataLen = 200;  //40*5
        wifi_nvram.dataOffset = 0x10c;

        mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
            Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        //m_lv2GH_TX_Power_Offset end
    }

}

void __fastcall Tfrm2GH_TX_Power_Profile::Download_TX_Power_Compensation_MT6632()
{
    unsigned char pszBufferRaw[512]={0};
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();
    META_RESULT mr;
    int WF = m_tc2GH_TX_Power_Compensation->TabIndex;

    for(int i = 0; i < 14; i++)
    {
        pszBufferRaw[i] = StrToInt(m_lvTXPowerCom->Items->Item[i]->SubItems->Strings[1]) ? 0x80 : 0;
        float temp = StrToFloat(m_lvTXPowerCom->Items->Item[i]->SubItems->Strings[0]);
        if(temp > 0)
        {
            pszBufferRaw[i] |= 0x40;
        }
        pszBufferRaw[i] = pszBufferRaw[i] | ((unsigned char)(fabs(temp) *2.0));
        LOG("Download_TX_Power_Compensation_MT6632 pszBufferRaw[%d] = %x",i,pszBufferRaw[i]);
    }
    wifi_nvram.dataLen = 14;

    if(WF == 0)
    {
        wifi_nvram.dataOffset = 0x42;
    }else
    {
        wifi_nvram.dataOffset = 0x176;
    }

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x53;
    memset(&pszBufferRaw,0,sizeof(pszBufferRaw));

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    char a = pszBufferRaw[0] & 0x01;
    char b = (pszBufferRaw[0] & 0x02)>>1;
    if(WF == 0)
    {
        a = !m_cbEnable->ItemIndex;
        b = b<<1;
        pszBufferRaw[0] = (b + a);

    }
    else
    {
        b = !m_cbEnable->ItemIndex;
        b = b<<1;
        pszBufferRaw[0] = (b + a);
    }

    LOG("Download_TX_Power_Compensation_MT6632 Enable = %x",pszBufferRaw[0]);

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();

}

//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_btnWriteToNVRAMClick(
    TObject *Sender)
{

    bool flag = true;
    for(int i = 0; i < _2GH_TX_POWER_LISTVIEW_ITEM_COUNT; i++)
    {
        if(!redValueFlag_2G[i])
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

    //m_lv2GH_TX_Power_Register
    Download_TX_Power_Register();

    //m_lv2GH_TX_Power_Compensation
    Download_TX_Power_Compensation();

    Download_TX_Power_Compensation_AllChannels();

    //m_lv2GH_TX_Power_FCC
    Download_TX_Power_FCC();

    //m_lv2GH_TX_Power_BackOff
    Download_TX_Power_BackOff();


    m_sb2GH->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_RegisterAdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(2 == SubItem)
    {
        float registerValue = 0.0;
        if(IsValidWiFiRegisterValue(Item->SubItems->Strings[SubItem - 1], registerValue)
                && (int)ceil(2 * registerValue) == (int)floor(2 * registerValue))
        {
            /*           char * str = Item->SubItems->Strings[SubItem - 1].c_str();
                       if(NULL != strchr(str, '.'))
                       {
                            char * pt = strchr(str, '.');
                            if('5' != *(pt + 1) && '\0' != *(pt + 1))
                            {
                               Sender->Canvas->Brush->Color = clRed;
                               int index = Item->Index;
                               redValueFlag_2G[index] = false;
                            }
                            else
                            {
                               Sender->Canvas->Brush->Color = clWindow;
                               int index = Item->Index;
                               redValueFlag_2G[index] = true;
                            }
                       }
                       else */
            {
                Sender->Canvas->Brush->Color = clWindow;
                int index = Item->Index;
                redValueFlag_2G[index] = true;
            }
        }
        else
        {
            Sender->Canvas->Brush->Color = clRed;
            int index = Item->Index;
            redValueFlag_2G[index] = false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_CompensationAdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i;
        int index;
        int temp;
        if(0x5931 == m_wifiChipVersion)
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE_5931;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_5931; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value_5931[i]))
                {
                    break;
                }
            }
        }
        else if(0x6625 == m_wifiChipVersion)
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE_6625;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6625; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value_6625[i]))
                {
                    break;
                }
            }
        }
        else if(0x6628 == m_wifiChipVersion)
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE_6628;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6628; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value_6628[i]))
                {
                    break;
                }
            }
        }
        else if(0x6630 == m_wifiChipVersion)
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE_6630;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6630; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value_6630[i]))
                {
                    break;
                }
            }
        }
        else
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value[i]))
                {
                    break;
                }
            }
        }

        if(temp == i)
        {
            Sender->Canvas->Brush->Color = clRed;
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count;
            redValueFlag_2G[index] = false;
        }
        else
        {
            Sender->Canvas->Brush->Color = clWindow;
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count;
            redValueFlag_2G[index] = true;
        }
    }
}


void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_Compensation_AllChannel_AdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i;
        int index;
        int temp;
        if(0x6628 == m_wifiChipVersion)
        {
            temp = _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_AllChannel_value_6628[i]))
                {
                    break;
                }
            }
        }
        else
        {
            temp = _2GH_TX_POWER_COMPENSATION_VALUE;
            for(i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE; i++)
            {
                if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lv2GH_TX_Power_Compensation_value[i]))
                {
                    break;
                }
            }
        }

        if(temp == i)
        {
            Sender->Canvas->Brush->Color = clRed;
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count + m_lv2GH_TX_Power_Compensation->Items->Count;
            redValueFlag_2G[index] = false;
        }
        else
        {
            Sender->Canvas->Brush->Color = clWindow;
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count + m_lv2GH_TX_Power_Compensation->Items->Count;
            redValueFlag_2G[index] = true;
        }
    }
}


//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_FCCAdvancedCustomDrawSubItem(
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
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count +
                     m_lv2GH_TX_Power_Compensation->Items->Count + m_lv2GH_TX_Power_CompensationAllChannel->Items->Count;
            redValueFlag_2G[index] = true;
        }
        else
        {
            Sender->Canvas->Brush->Color = clRed;
            index =  Item->Index + m_lv2GH_TX_Power_Register->Items->Count +
                     m_lv2GH_TX_Power_Compensation->Items->Count + m_lv2GH_TX_Power_CompensationAllChannel->Items->Count;
            redValueFlag_2G[index] = false;
        }
    }
}



//---------------------------------------------------------------------------
void __fastcall Tfrm2GH_TX_Power_Profile::FormShow(TObject *Sender)
{
    LOG("2GH_TX_Power_Profile form center the form.");
    FormPositionSetting::CenterForm(this);
    m_wifiChipVersion = frmWmWifiMT6620->GetWifiChipVersion();

    if((0x5931 == m_wifiChipVersion) || (0x6628 == m_wifiChipVersion)|| (0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        if(m_lv2GH_TX_Power_Register->Items->Item[1]->Caption != "cTxPwr2G4Dsss")
        {
            TListItem* itemToAdd = m_lv2GH_TX_Power_Register->Items->Insert(1);
            itemToAdd->Caption = "cTxPwr2G4Dsss";
            itemToAdd->SubItems->Add("CCK 1M, 2M");
            itemToAdd->SubItems->Add("21");
            m_lv2GH_TX_Power_Register->Items->Item[0]->SubItems->Strings[0] = "CCK 5.5M, 11M";
        }

        if((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if(flag_6632 == 0)
            {
                flag_6632 = 1;
                int index = m_lv2GH_TX_Power_Register->Items->Count;

                for(int i=0; i<9; i++)
                {
                    TListItem* itemToAdd = m_lv2GH_TX_Power_Register->Items->Insert(index);
                    itemToAdd->Caption = g_2ghz_tx_power_register_mt6632[i].register_Name;
                    itemToAdd->SubItems->Add(g_2ghz_tx_power_register_mt6632[i].data_Rate);
                    itemToAdd->SubItems->Add(g_2ghz_tx_power_register_mt6632[i].register_value);
                    index++;
                }
                m_lv2GH_TX_Power_Compensation->Visible = false;
                m_cb2GH_TX_Power_Compensation->Visible = false;
                m_tc2GH_TX_Power_Compensation->Visible = true;
                m_cbEnable->Visible = true;
                m_lvTXPowerCom->Visible = true;
                m_btnWriteToNvram_MT6632->Visible = true;
                GroupBox2->Visible = false;
                index = m_lv2GH_TX_Power_Register->Items->Count;
                GroupBox3->Visible = false;
            }

        }

        if(0x5931 == m_wifiChipVersion)
        {
            m_lv2GH_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-2~+2dB, step 0.25)";
            GroupBox3->Visible = false;
        }
        else if(0x6628 == m_wifiChipVersion)
        {
            m_lv2GH_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-2~+2dB, step 0.5)";
            GroupBox3->Visible = true;
        }
        else if((0x6632 != m_wifiChipVersion)&&(0x0035 != m_wifiChipVersion))
        {
            m_lv2GH_TX_Power_Compensation->Items->Item[1]->Caption = "Ch5,6,7,8";
            m_lv2GH_TX_Power_Compensation->Items->Item[2]->Caption = "Ch9,10,11,12,13,14";
        }
    }
    else
    {
        if(0x6630 == m_wifiChipVersion)
        {
            m_lv2GH_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-4~+4dB, step 0.25)";
            m_lv2GH_TX_Power_Compensation->Items->Item[1]->Caption = "Ch5,6,7,8,9";
            m_lv2GH_TX_Power_Compensation->Items->Item[2]->Caption = "Ch10,11,12,13,14";
        }
        else if(0x6625 == m_wifiChipVersion)
        {
            m_lv2GH_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-2~+2dB, step 0.25)";
            m_lv2GH_TX_Power_Compensation->Items->Item[1]->Caption = "Ch5,6,7,8";
            m_lv2GH_TX_Power_Compensation->Items->Item[2]->Caption = "Ch9,10,11,12,13,14";
        }
        else
        {
            m_lv2GH_TX_Power_Compensation->Columns->Items[1]->Caption = "TX Power Offset (-4~+4dB, step 0.5)";
            m_lv2GH_TX_Power_Compensation->Items->Item[1]->Caption = "Ch5,6,7,8";
            m_lv2GH_TX_Power_Compensation->Items->Item[2]->Caption = "Ch9,10,11,12,13,14";
        }

        if(m_lv2GH_TX_Power_Register->Items->Item[1]->Caption == "cTxPwr2G4Dsss")
        {
            m_lv2GH_TX_Power_Register->Items->Delete(1);
            m_lv2GH_TX_Power_Register->Items->Item[0]->SubItems->Strings[0] = "CCK 1M, 2M,5.5M, 11M";
        }
        GroupBox3->Visible = false;
    }


    m_cb2GH_TX_Power_Compensation_Edit->Items->Clear();
    if(0x5931 == m_wifiChipVersion)
    {
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_5931; i++)
        {
            m_cb2GH_TX_Power_Compensation_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_value_5931[i]);
        }
    }
    else if(0x6625 == m_wifiChipVersion)
    {
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6625; i++)
        {
            m_cb2GH_TX_Power_Compensation_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_value_6625[i]);
        }
    }
    else if(0x6628 == m_wifiChipVersion)
    {
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6628; i++)
        {
            m_cb2GH_TX_Power_Compensation_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_value_6628[i]);
        }
        m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Items->Clear();
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_ALL_CHANNEL_VALUE_6628; i++)
        {
            m_cb2GH_TX_Power_Compensation_AllChannel_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_AllChannel_value_6628[i]);
        }
    }
    else if(0x6630 == m_wifiChipVersion)
    {
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE_6630; i++)
        {
            m_cb2GH_TX_Power_Compensation_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_value_6630[i]);
        }
    }
    else
    {
        for(int i = 0; i < _2GH_TX_POWER_COMPENSATION_VALUE; i++)
        {
            m_cb2GH_TX_Power_Compensation_Edit->Items->Add(g_lv2GH_TX_Power_Compensation_value[i]);
        }
    }

    CheckDisplayTXPowerBackOff();
    if (m_bDisplayTXPowerBackOff)
    {
        GroupBox4->Visible = true;
        GroupBox5->Visible = true;
    }
    else
    {
        GroupBox4->Visible = false;
        GroupBox5->Visible = false;
    }

    m_btnReadFromNVRAMClick(Sender);
}
//---------------------------------------------------------------------------
void Tfrm2GH_TX_Power_Profile::CurrentPageLock()
{
    m_lv2GH_TX_Power_Register->Enabled = false;
    GroupBox1->Enabled = false;
    GroupBox2->Enabled = false;
    m_btnReadFromNVRAM->Enabled = false;
    m_btnWriteToNVRAM->Enabled = false;
}
//---------------------------------------------------------------------------
void Tfrm2GH_TX_Power_Profile::CurrentPageReset()
{
    m_lv2GH_TX_Power_Register->Enabled = true;
    GroupBox1->Enabled = true;
    GroupBox2->Enabled = true;
    m_btnReadFromNVRAM->Enabled = true;
    m_btnWriteToNVRAM->Enabled = true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_edt2GH_TX_Power_BackOffExit(
      TObject *Sender)
{
    m_lv2GH_TX_Power_BackOff->Selected->SubItems->Strings[0] = m_edt2GH_TX_Power_BackOff->Text;
    m_edt2GH_TX_Power_BackOff->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_BackOffClick(
      TObject *Sender)
{
    if (m_lv2GH_TX_Power_BackOff->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_BackOff-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_BackOff-> Handle, 1);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_BackOff->ScreenToClient(Mouse->CursorPos);

    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt2GH_TX_Power_BackOff->Left = m_lv2GH_TX_Power_BackOff->Left + width0 + 8;
        m_edt2GH_TX_Power_BackOff->Top = m_lv2GH_TX_Power_BackOff->Top + m_lv2GH_TX_Power_BackOff->Selected->Top;
        m_edt2GH_TX_Power_BackOff->Text = m_lv2GH_TX_Power_BackOff->Selected->SubItems->Strings[0];
        m_edt2GH_TX_Power_BackOff->Visible = True;
        m_edt2GH_TX_Power_BackOff->SetFocus();
    }

}
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_lv2GH_TX_Power_OffsetClick(TObject *Sender)
{
    if (m_lv2GH_TX_Power_Offset->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Offset-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Offset-> Handle, 1);

    TPoint Pos;
    Pos = m_lv2GH_TX_Power_Offset->ScreenToClient(Mouse->CursorPos);
    for (int j = 0; j< 5; j++)
    {
        if(Pos.x > width0 && Pos.x < (width0 + width1 * (j +1)))
        {
            m_edt2GHTX_Power_Offset->Left = m_lv2GH_TX_Power_Offset->Left + width0  + width1 * j + 8;
            m_edt2GHTX_Power_Offset->Top = m_lv2GH_TX_Power_Offset->Top + m_lv2GH_TX_Power_Offset->Selected->Top;
            m_edt2GHTX_Power_Offset->Text = m_lv2GH_TX_Power_Offset->Selected->SubItems->Strings[j];
            m_edt2GHTX_Power_Offset->Visible = true;
            m_edt2GHTX_Power_Offset->SetFocus();
            break;
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_edt2GHTX_Power_OffsetExit(
      TObject *Sender)
{

    int width0 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Offset-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GH_TX_Power_Offset-> Handle, 1);

    for(int j = 0; j < 5; j++)
    {
        if(m_edt2GHTX_Power_Offset->Left == m_lv2GH_TX_Power_Offset->Left + width0  + width1 * j + 8)
        {
             m_lv2GH_TX_Power_Offset->Selected->SubItems->Strings[j] = m_edt2GHTX_Power_Offset->Text;
             m_edt2GHTX_Power_Offset->Visible = false;
             break;
        }
    }
}
//---------------------------------------------------------------------------

void Tfrm2GH_TX_Power_Profile::CheckDisplayTXPowerBackOff()
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
        LOG("m_bDisplayTXPowerBackOff = true");
    }
    else
    {
        m_bDisplayTXPowerBackOff = false;
        LOG("m_bDisplayTXPowerBackOff = false");
    }
}





//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_tc2GH_TX_Power_CompensationChange(
      TObject *Sender)
{
    Update_TX_Power_Compensation_MT6632();
}

//---------------------------------------------------------------------------

void __fastcall Tfrm2GH_TX_Power_Profile::m_btnWriteToNvram_MT6632Click(
      TObject *Sender)
{
    Download_TX_Power_Compensation_MT6632();
}
//---------------------------------------------------------------------------



