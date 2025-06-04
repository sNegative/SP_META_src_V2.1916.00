//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_WiFi6632RSSICOMP.h"

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "meta.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm6632RSSICOMP *frm6632RSSICOMP;

#define RSSI_COMPENSATION_VALUE_6632 31

char g_lvRSSI_Compensation_value_6632[RSSI_COMPENSATION_VALUE_6632][10] =
{
    "-7.5",
    "-7",
    "-6.5",
    "-6",
    "-5.5",
    "-5",
    "-4.5",
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
    "4",
    "4.5",
    "5",
    "5.5",
    "6",
    "6.5",
    "7",
    "7.5"
};

/*char g_lvRSSI_Compensation_value_map_6632[RSSI_COMPENSATION_VALUE_6632][10] =
{
    "0x0F",
    "0x0E",
    "0x0D",
    "0x0C",
    "0x0B",
    "0x0A",
    "0x09",
    "0x0",
    "0x01",
    "0x02",
    "0x03",
    "0x04",
    "0x05",
    "0x06",
    "0x07"
};
*/
/*
-7.5    ==>        11111
-7.0    ==>        11110
-6.5    ==>        11101
-6.0    ==>        11100
-5.5    ==>        11011
-5.0    ==>        11010
-4.5    ==>        11001
-4.0    ==>        11000
-3.5    ==>        10111
-3.0    ==>        10110
-2.5    ==>        10101
-2.0    ==>        10100
-1.5    ==>        10011
-1.0    ==>        10010
-0.5    ==>        10001
+0.0    ==>       00000
+0.5    ==>       00001
+1.0    ==>       00010 
+1.5    ==>       00011 
+2.0    ==>       00100 
+2.5    ==>       00101 
+3.0    ==>       00110 
+3.5    ==>       00111
+4.0    ==>       01000
+4.5    ==>       01001
+5.0    ==>       01010
+5.5    ==>       01011
+6.0    ==>       01100
+6.5    ==>       01101
+7.0    ==>       01110
+7.5    ==>       01111
*/
char g_lvRSSI_Compensation_value_map_6632[RSSI_COMPENSATION_VALUE_6632][10] =
{
    "0x1F",      //-7.5    ==>        11111
    "0x1E",      //-7.0    ==>        11110
    "0x1D",      //-6.5    ==>        11101
    "0x1C",      //-6.0    ==>        11100
    "0x1B",      //-5.5    ==>        11011
    "0x1A",      //-5.0    ==>        11010
    "0x19",     //-4.5    ==>        11001
    "0x18",     //-4.0    ==>        11000
    "0x17",     //-3.5    ==>        10111
    "0x16",     //-3.0    ==>        10110
    "0x15",     //-2.5    ==>        10101
    "0x14",     //-2.0    ==>        10100
    "0x13",     //-1.5    ==>        10011
    "0x12",     //-1.0    ==>        10010
    "0x11",     //-0.5    ==>        10001
    "0x0",
    "0x01",
    "0x02",
    "0x03",
    "0x04",
    "0x05",
    "0x06",
    "0x07",   // +3.5    ==>       00111
    "0x08",   // +4.0    ==>       01000
    "0x09",   // +4.5    ==>       01001
    "0x0A",   // +5.0    ==>       01010
    "0x0B",   // +5.5    ==>       01011
    "0x0C",   // +6.0    ==>       01100
    "0x0D",   // +6.5    ==>       01101
    "0x0E",   // +7.0    ==>       01110
    "0x0F"    // +7.5    ==>       01111
};

//---------------------------------------------------------------------------
__fastcall Tfrm6632RSSICOMP::Tfrm6632RSSICOMP(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_btnReadFromNVRAMClick(TObject *Sender)
{
    int j = 0;
    char pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    memset(&wifi_nvram, 0, sizeof(NVRAM_ACCESS_STRUCT));
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x10a;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    m_cb2GWF0RSSI->ItemIndex = !(pszBufferRaw[0] & 0x01);
    m_cb2GWF1RSSI->ItemIndex = !(pszBufferRaw[0] & 0x02);
    m_cb5GWF0RSSI->ItemIndex = !(pszBufferRaw[0] & 0x04);
    m_cb5GWF1RSSI->ItemIndex = !(pszBufferRaw[0] & 0x08);

    //2.4G WF1
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x85;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if(StrToInt(g_lvRSSI_Compensation_value_map_6632[j]) == pszBufferRaw[0])
        {
            m_lv2GWF1RSSI->Items->Item[0]->SubItems->Strings[0] = g_lvRSSI_Compensation_value_6632[j];
            break;
        }
    }

    //5G WF1
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x86;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if(StrToInt(g_lvRSSI_Compensation_value_map_6632[j]) == pszBufferRaw[0])
        {
            m_lv5GWF1RSSI->Items->Item[0]->SubItems->Strings[0] = g_lvRSSI_Compensation_value_6632[j];
            break;
        }
    }

    //2.4G WF0
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x108;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if(StrToInt(g_lvRSSI_Compensation_value_map_6632[j]) == pszBufferRaw[0])
        {
            m_lv2GWF0RSSI->Items->Item[0]->SubItems->Strings[0] = g_lvRSSI_Compensation_value_6632[j];
            break;
        }
    }

    //5G WF0
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x109;

    mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if(StrToInt(g_lvRSSI_Compensation_value_map_6632[j]) == pszBufferRaw[0])
        {
            m_lv5GWF0RSSI->Items->Item[0]->SubItems->Strings[0] = g_lvRSSI_Compensation_value_6632[j];
            break;
        }
    }
    
    m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall Tfrm6632RSSICOMP::m_btnWriteToNVRAMClick(TObject *Sender)
{
    int j = 0;
    char pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    memset(&wifi_nvram, 0, sizeof(NVRAM_ACCESS_STRUCT));
    CurrentPageLock();

    pszBufferRaw[0] = (!(m_cb2GWF0RSSI->ItemIndex) & 0x01) + (((!(m_cb2GWF1RSSI->ItemIndex)) & 0x01)<< 1) + (((!(m_cb5GWF0RSSI->ItemIndex)) & 0x01)<< 2) + (((!(m_cb5GWF1RSSI->ItemIndex)) & 0x01)<< 3);

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x10a;
    wifi_nvram.data = pszBufferRaw;


    META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    //2.4G WF1
    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if((AnsiString)g_lvRSSI_Compensation_value_6632[j] == m_lv2GWF1RSSI->Items->Item[0]->SubItems->Strings[0])
        {
            pszBufferRaw[0] = StrToInt(g_lvRSSI_Compensation_value_map_6632[j]);
            break;
        }
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x85;
    wifi_nvram.data = pszBufferRaw;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    //5G WF1
    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if((AnsiString)g_lvRSSI_Compensation_value_6632[j] == m_lv5GWF1RSSI->Items->Item[0]->SubItems->Strings[0])
        {
            pszBufferRaw[0] = StrToInt(g_lvRSSI_Compensation_value_map_6632[j]);
            break;
        }
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x86;
    wifi_nvram.data = pszBufferRaw;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    //2.4G WF0
    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if((AnsiString)g_lvRSSI_Compensation_value_6632[j] == m_lv2GWF0RSSI->Items->Item[0]->SubItems->Strings[0])
        {
            pszBufferRaw[0] = StrToInt(g_lvRSSI_Compensation_value_map_6632[j]);
            break;
        }
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x108;
    wifi_nvram.data = pszBufferRaw;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }


    //5G WF0
    for(j = 0; j < RSSI_COMPENSATION_VALUE_6632; j++)
    {
        if((AnsiString)g_lvRSSI_Compensation_value_6632[j] == m_lv5GWF0RSSI->Items->Item[0]->SubItems->Strings[0])
        {
            pszBufferRaw[0] = StrToInt(g_lvRSSI_Compensation_value_map_6632[j]);
            break;
        }
    }

    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x109;
    wifi_nvram.data = pszBufferRaw;

    mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    m_sb6632RSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Tfrm6632RSSICOMP::CurrentPageLock()
{
    GroupBox6632RSSIComp->Enabled = false;
    m_btnReadFromNVRAM->Enabled = false;
    m_btnWriteToNVRAM->Enabled = false;
}
//---------------------------------------------------------------------------
void Tfrm6632RSSICOMP::CurrentPageReset()
{
    GroupBox6632RSSIComp->Enabled = true;
    m_btnReadFromNVRAM->Enabled = true;
    m_btnWriteToNVRAM->Enabled = true;
}
void __fastcall Tfrm6632RSSICOMP::FormShow(TObject *Sender)
{
    FormPositionSetting::CenterForm(this);
    m_edt2GWF0RSSI->Items->Clear();
    m_edt5GWF0RSSI->Items->Clear();
    m_edt2GWF1RSSI->Items->Clear();
    m_edt5GWF1RSSI->Items->Clear();
    for(int i = 0; i < RSSI_COMPENSATION_VALUE_6632; i++)
    {
        m_edt2GWF0RSSI->Items->Add(g_lvRSSI_Compensation_value_6632[i]);
        m_edt5GWF0RSSI->Items->Add(g_lvRSSI_Compensation_value_6632[i]);
        m_edt2GWF1RSSI->Items->Add(g_lvRSSI_Compensation_value_6632[i]);
        m_edt5GWF1RSSI->Items->Add(g_lvRSSI_Compensation_value_6632[i]);
    }

    m_btnReadFromNVRAMClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_edt2GWF0RSSIExit(TObject *Sender)
{
    m_lv2GWF0RSSI->Selected->SubItems->Strings[0] = m_edt2GWF0RSSI->Text;
    m_edt2GWF0RSSI->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_edt5GWF0RSSIExit(TObject *Sender)
{
    m_lv5GWF0RSSI->Selected->SubItems->Strings[0] = m_edt5GWF0RSSI->Text;
    m_edt5GWF0RSSI->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_edt2GWF1RSSIExit(TObject *Sender)
{
    m_lv2GWF1RSSI->Selected->SubItems->Strings[0] = m_edt2GWF1RSSI->Text;
    m_edt2GWF1RSSI->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_edt5GWF1RSSIExit(TObject *Sender)
{
    m_lv5GWF1RSSI->Selected->SubItems->Strings[0] = m_edt5GWF1RSSI->Text;
    m_edt5GWF1RSSI->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm6632RSSICOMP::m_lv2GWF0RSSIAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        for(i = 0; i < RSSI_COMPENSATION_VALUE_6632; i++)
        {
            if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lvRSSI_Compensation_value_6632[i]))
            {
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv5GWF0RSSIAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        for(i = 0; i < RSSI_COMPENSATION_VALUE_6632; i++)
        {
            if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lvRSSI_Compensation_value_6632[i]))
            {
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv2GWF1RSSIAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        for(i = 0; i < RSSI_COMPENSATION_VALUE_6632; i++)
        {
            if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lvRSSI_Compensation_value_6632[i]))
            {
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv5GWF1RSSIAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        for(i = 0; i < RSSI_COMPENSATION_VALUE_6632; i++)
        {
            if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lvRSSI_Compensation_value_6632[i]))
            {
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv2GWF0RSSIClick(TObject *Sender)
{
    if (m_lv2GWF0RSSI->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GWF0RSSI-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GWF0RSSI-> Handle, 1);

    TPoint Pos;
    Pos = m_lv2GWF0RSSI->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt2GWF0RSSI->Left = m_lv2GWF0RSSI->Left + width0 + 8;
        m_edt2GWF0RSSI->Top = m_lv2GWF0RSSI->Top + m_lv2GWF0RSSI->Selected->Top;
        m_edt2GWF0RSSI->Text = m_lv2GWF0RSSI->Selected->SubItems->Strings[0];
        m_edt2GWF0RSSI->Visible = True;
        m_edt2GWF0RSSI->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv5GWF0RSSIClick(TObject *Sender)
{
    if (m_lv5GWF0RSSI->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GWF0RSSI-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GWF0RSSI-> Handle, 1);

    TPoint Pos;
    Pos = m_lv5GWF0RSSI->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt5GWF0RSSI->Left = m_lv5GWF0RSSI->Left + width0 + 8;
        m_edt5GWF0RSSI->Top = m_lv5GWF0RSSI->Top + m_lv5GWF0RSSI->Selected->Top;
        m_edt5GWF0RSSI->Text = m_lv5GWF0RSSI->Selected->SubItems->Strings[0];
        m_edt5GWF0RSSI->Visible = True;
        m_edt5GWF0RSSI->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv2GWF1RSSIClick(TObject *Sender)
{
    if (m_lv2GWF1RSSI->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv2GWF1RSSI-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv2GWF1RSSI-> Handle, 1);

    TPoint Pos;
    Pos = m_lv2GWF1RSSI->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt2GWF1RSSI->Left = m_lv2GWF1RSSI->Left + width0 + 8;
        m_edt2GWF1RSSI->Top = m_lv2GWF1RSSI->Top + m_lv2GWF1RSSI->Selected->Top;
        m_edt2GWF1RSSI->Text = m_lv2GWF1RSSI->Selected->SubItems->Strings[0];
        m_edt2GWF1RSSI->Visible = True;
        m_edt2GWF1RSSI->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm6632RSSICOMP::m_lv5GWF1RSSIClick(TObject *Sender)
{
    if (m_lv5GWF1RSSI->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lv5GWF1RSSI-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lv5GWF1RSSI-> Handle, 1);

    TPoint Pos;
    Pos = m_lv5GWF1RSSI->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edt5GWF1RSSI->Left = m_lv5GWF1RSSI->Left + width0 + 8;
        m_edt5GWF1RSSI->Top = m_lv5GWF1RSSI->Top + m_lv5GWF1RSSI->Selected->Top;
        m_edt5GWF1RSSI->Text = m_lv5GWF1RSSI->Selected->SubItems->Strings[0];
        m_edt5GWF1RSSI->Visible = True;
        m_edt5GWF1RSSI->SetFocus();
    }
}
//---------------------------------------------------------------------------
