//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_WiFiRSSICOMP.h"

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include "METAAPP_common.h"
#include "form_main.h"
#include "misc.h"
#include "man_fdm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRSSICOMP *frmRSSICOMP;

#define RSSI_COMPENSATION_VALUE 16

char g_lvRSSI_Compensation_value[RSSI_COMPENSATION_VALUE][10] =
{
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

char g_lvRSSI_Compensation_value_map[RSSI_COMPENSATION_VALUE][10] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15"
};
//---------------------------------------------------------------------------
__fastcall TfrmRSSICOMP::TfrmRSSICOMP(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmRSSICOMP::m_btnReadFromNVRAMClick(TObject *Sender)
{
    int i = 0;
    int j = 0;
    char pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    memset(&wifi_nvram, 0, sizeof(NVRAM_ACCESS_STRUCT));
    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x108;
    wifi_nvram.data = pszBufferRaw;
    CurrentPageLock();

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sbRSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    m_cbRSSI_Compensation->ItemIndex = !(pszBufferRaw[2] & 0x01);
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < RSSI_COMPENSATION_VALUE; j++)
        {
             if(StrToInt(g_lvRSSI_Compensation_value_map[j]) == pszBufferRaw[i])
             {
                 m_lvRSSI_Compensation->Items->Item[i]->SubItems->Strings[0] = g_lvRSSI_Compensation_value[j];
                 break;
             }
        }
        if(RSSI_COMPENSATION_VALUE == j)
        {
             m_lvRSSI_Compensation->Items->Item[i]->SubItems->Strings[0] = FloatToStr(pszBufferRaw[i] / 65.0);
        }
    }
    
    m_sbRSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmRSSICOMP::FormShow(TObject *Sender)
{
    FormPositionSetting::CenterForm(this);
    m_cbRSSI_Compensation_Edit->Items->Clear();
    for(int i = 0; i < RSSI_COMPENSATION_VALUE; i++)
    {
        m_cbRSSI_Compensation_Edit->Items->Add(g_lvRSSI_Compensation_value[i]);
    }

    m_btnReadFromNVRAMClick(Sender);
}
//---------------------------------------------------------------------------
void TfrmRSSICOMP::CurrentPageLock()
{
    GroupBoxRSSIComp->Enabled = false;
    m_btnReadFromNVRAM->Enabled = false;
    m_btnWriteToNVRAM->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmRSSICOMP::CurrentPageReset()
{
    GroupBoxRSSIComp->Enabled = true;
    m_btnReadFromNVRAM->Enabled = true;
    m_btnWriteToNVRAM->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRSSICOMP::m_btnWriteToNVRAMClick(TObject *Sender)
{
    int i = 0;
    int j = 0;
    char pszBufferRaw[512] = {0};

    NVRAM_ACCESS_STRUCT wifi_nvram;
    memset(&wifi_nvram, 0, sizeof(NVRAM_ACCESS_STRUCT));
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < RSSI_COMPENSATION_VALUE; j++)
        {
            if((AnsiString)g_lvRSSI_Compensation_value[j] == m_lvRSSI_Compensation->Items->Item[i]->SubItems->Strings[0])
            {
                pszBufferRaw[i] = StrToInt(g_lvRSSI_Compensation_value_map[j]);
                break;
            }
        }
    }
    pszBufferRaw[2] = !(m_cbRSSI_Compensation->ItemIndex);

    wifi_nvram.dataLen = 3;
    wifi_nvram.dataOffset = 0x108;
    wifi_nvram.data = pszBufferRaw;

    CurrentPageLock();
    META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sbRSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    m_sbRSSICOMP->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmRSSICOMP::m_lvRSSI_CompensationAdvancedCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int i = 0;
        for(i = 0; i < RSSI_COMPENSATION_VALUE; i++)
        {
            if(!strcmp(Item->SubItems->Strings[SubItem - 1].c_str(), g_lvRSSI_Compensation_value[i]))
            {
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRSSICOMP::m_lvRSSI_CompensationClick(TObject *Sender)
{
   if (m_lvRSSI_Compensation->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lvRSSI_Compensation-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lvRSSI_Compensation-> Handle, 1);

    TPoint Pos;
    Pos = m_lvRSSI_Compensation->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_cbRSSI_Compensation_Edit->Left = m_lvRSSI_Compensation->Left + width0 + 8;
        m_cbRSSI_Compensation_Edit->Top = m_lvRSSI_Compensation->Top + m_lvRSSI_Compensation->Selected->Top;
        m_cbRSSI_Compensation_Edit->Text = m_lvRSSI_Compensation->Selected->SubItems->Strings[0];
        m_cbRSSI_Compensation_Edit->Visible = True;
        m_cbRSSI_Compensation_Edit->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRSSICOMP::m_cbRSSI_Compensation_EditExit(
      TObject *Sender)
{
    m_lvRSSI_Compensation->Selected->SubItems->Strings[0] = m_cbRSSI_Compensation_Edit->Text;
    m_cbRSSI_Compensation_Edit->Visible = false;
}
//---------------------------------------------------------------------------

