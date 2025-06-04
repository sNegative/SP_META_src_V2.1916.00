//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_GPSCWAutoTest.h"

#ifndef  _MISC_GPS_H_
#include "misc_GPS.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGPSAutoTest *frmGPSAutoTest;
extern TfrmGPS *frmGPS;
//---------------------------------------------------------------------------
__fastcall TfrmGPSAutoTest::TfrmGPSAutoTest(TComponent* Owner)
    : TForm(Owner)
{
    m_nCWAutoTestNum = 0;
    memset(m_strAutoTestFilePath,0,GPS_CW_TEST_FILE_PATH_LEN);
}
//---------------------------------------------------------------------------



void __fastcall TfrmGPSAutoTest::BtnCWLogPathClick(TObject *Sender)
{
    if(!(SaveDialogCWLog->Execute()))
    {
        Application->MessageBox("Please set log file location before auto test","FAILURE",MB_OK);
        return;
    }
    if( SaveDialogCWLog->FileName.Length() > GPS_CW_TEST_FILE_PATH_LEN )
    {
        Application->MessageBox("The log file location length is longer than 2048, please reset it","FAILURE",MB_OK);
        return;
    }
    memset(m_strAutoTestFilePath,0,GPS_CW_TEST_FILE_PATH_LEN);   // fix for filename abnormal
    memcpy(m_strAutoTestFilePath,SaveDialogCWLog->FileName.c_str(),SaveDialogCWLog->FileName.Length());
    stAutoTestFilePath ->Caption = m_strAutoTestFilePath;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPSAutoTest::BtnOkClick(TObject *Sender)
{
    if(m_nCWAutoTestNum <= 0 )
    {
        Application->MessageBox("Please set the test number before auto test","FAILURE",MB_OK);
        return;
    }
    if(strlen(m_strAutoTestFilePath) == 0 )
    {
        Application->MessageBox("Please set log file location before auto test","FAILURE",MB_OK);
        return;
    }
    frmGPS->GetCWAutoTestParam(m_nCWAutoTestNum,m_strAutoTestFilePath);
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPSAutoTest::BtnCancelClick(TObject *Sender)
{
    int nCWAutoTestNum = 0;
    frmGPS->GetCWAutoTestParam(nCWAutoTestNum,m_strAutoTestFilePath);
    this->Close();
}
//---------------------------------------------------------------------------
void  TfrmGPSAutoTest::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}
void __fastcall TfrmGPSAutoTest::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPSAutoTest::EDAutoTestNumExit(TObject *Sender)
{
    unsigned int n_data = 0;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 1~1000 "
    };

    text = edit->Text;
    if( !IsValidGPSAutoTestNum( text, n_data ) )
    {
        edit->Text = 100;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    m_nCWAutoTestNum = n_data;
}
//---------------------------------------------------------------------------
