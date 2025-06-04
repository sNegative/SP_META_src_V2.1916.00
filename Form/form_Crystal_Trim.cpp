//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "form_Crystal_Trim.h"

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

#ifndef form_WmWifimt6620H
#include "form_WmWifimt6620.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCrystalTrim *frmCrystalTrim;
bool redValueFlag;
//---------------------------------------------------------------------------
__fastcall TfrmCrystalTrim::TfrmCrystalTrim(TComponent* Owner)
    : TForm(Owner)
{
    redValueFlag = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::m_btnCrystal_Trim_ReadClick(TObject *Sender)
{
    char  pszBufferRaw[512];

    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x6d;
    wifi_nvram.data = pszBufferRaw;

    META_RESULT mr = SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sbCrystallTrim->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM fail!";
        Application->MessageBox( "Execution Failure: Read from NVRAM", "FAILURE", MB_OK );
        return;
    }
    m_cbCrystal_Trim->ItemIndex = !((pszBufferRaw[0] >> 7) & 0x01);
    if(64 <= (char)(pszBufferRaw[0] & 0x7f))
    {
        m_lvCrystal_Trim->Items->Item[0]->SubItems->Strings[0] = (pszBufferRaw[0] & 0x7f) - 128;
    }
    else
    {
        m_lvCrystal_Trim->Items->Item[0]->SubItems->Strings[0] = (pszBufferRaw[0] & 0x7f);
    }
    m_sbCrystallTrim->Panels->Items[0]->Text = (AnsiString) "  Read from NVRAM succeed!";
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::m_btnCrystal_Trim_WriteClick(
    TObject *Sender)
{
    if(!redValueFlag)
    {
        Application->MessageBox( "Execution Failure: There is invalid value", "FAILURE", MB_OK );
        return;
    }
    char  pszBufferRaw[512];
    if(0 > StrToInt(m_lvCrystal_Trim->Items->Item[0]->SubItems->Strings[0]))
    {
        pszBufferRaw[0] =  StrToInt(m_lvCrystal_Trim->Items->Item[0]->SubItems->Strings[0]) + 128;
    }
    else
    {
        pszBufferRaw[0] =  StrToInt(m_lvCrystal_Trim->Items->Item[0]->SubItems->Strings[0]);
    }

    pszBufferRaw[0] |= 0x80;
    pszBufferRaw[0] &= (((!(m_cbCrystal_Trim->ItemIndex)) << 7) | 0x7f);
    NVRAM_ACCESS_STRUCT wifi_nvram;
    wifi_nvram.dataLen = 1;
    wifi_nvram.dataOffset = 0x6d;
    wifi_nvram.data = pszBufferRaw;

    META_RESULT mr = SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, &wifi_nvram);
    if(META_SUCCESS != mr)
    {
        m_sbCrystallTrim->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM fail!";
        Application->MessageBox( "Execution Failure: Save to NVRAM", "FAILURE", MB_OK );

        return;
    }
    m_sbCrystallTrim->Panels->Items[0]->Text = (AnsiString) "  Save to NVRAM succeed!";
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::m_lvCrystal_TrimClick(TObject *Sender)
{
    if (m_lvCrystal_Trim->SelCount < 1)
        return;

    int width0 = ListView_GetColumnWidth(m_lvCrystal_Trim-> Handle, 0);
    int width1 = ListView_GetColumnWidth(m_lvCrystal_Trim-> Handle, 1);

    TPoint Pos;
    Pos = m_lvCrystal_Trim->ScreenToClient(Mouse->CursorPos);
    if(Pos.x > width0 && Pos.x < width0 + width1)
    {
        m_edtCrystal_Trim->Left = m_lvCrystal_Trim->Left + width0 + 8;
        m_edtCrystal_Trim->Top = m_lvCrystal_Trim->Top + m_lvCrystal_Trim->Selected->Top;
        m_edtCrystal_Trim->Text = m_lvCrystal_Trim->Selected->SubItems->Strings[0];
        m_edtCrystal_Trim->Visible = True;
        m_edtCrystal_Trim->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::m_edtCrystal_TrimExit(TObject *Sender)
{
    m_lvCrystal_Trim->Selected->SubItems->Strings[0] = m_edtCrystal_Trim->Text;
    m_edtCrystal_Trim->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::m_lvCrystal_TrimAdvancedCustomDrawSubItem(
    TCustomListView *Sender, TListItem *Item, int SubItem,
    TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
    if(1 == SubItem)
    {
        int Value;
        if(IsValidWiFiCrystalValue(Item->SubItems->Strings[SubItem - 1], Value))
        {
            Sender->Canvas->Brush->Color = clWindow;
            redValueFlag = true;
        }
        else
        {
            Sender->Canvas->Brush->Color = clRed;
            redValueFlag = false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCrystalTrim::FormShow(TObject *Sender)
{
    LOG("CrystalTrim form center the form.");
    FormPositionSetting::CenterForm(this);
    m_btnCrystal_Trim_ReadClick(Sender);
}
//---------------------------------------------------------------------------

