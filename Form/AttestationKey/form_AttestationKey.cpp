//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "form_AttestationKey.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAttestationKeyInstall *frmAttestationKeyInstall;
//---------------------------------------------------------------------------
__fastcall TfrmAttestationKeyInstall::TfrmAttestationKeyInstall(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

static void CNF_AttestationKeyInstall(void)
{
    frmAttestationKeyInstall->CNF_AttestationKeyInstall();
}


void __fastcall TfrmAttestationKeyInstall::BtnLoadKeyFileClick(
      TObject *Sender)
{
    bool bOk = false;
    bOk = dlg_OpenKeyFile->Execute();
    if ( !bOk )
    {
        SetStatusBarString("Open Key Block file fail");
        return;

    }
    strKeyFile->Caption = dlg_OpenKeyFile->FileName.c_str();
    m_file_name = dlg_OpenKeyFile->FileName;
    if ( m_file_name.IsEmpty() )
    {
        Application->MessageBox( "Execution Failure: Please help to make sure the file path is valid", "ERROR", MB_OK );
        return;
    }
}

void TfrmAttestationKeyInstall::SetStatusBarString(char *strInfo)
{
    strStatusInfo->Caption = (AnsiString) strInfo;
}

//---------------------------------------------------------------------------

void __fastcall TfrmAttestationKeyInstall::BtnInstallClick(TObject *Sender)
{
    if ( m_file_name.IsEmpty() )
    {
        Application->MessageBox( "Execution Failure : Please select the KeyBlock file!", "FAILURE", MB_OK );
        return;
    }
    CurrentPageLock();
    m_AttestationKey_Obj.ConfirmCallback = ::CNF_AttestationKeyInstall;
    m_AttestationKey_Obj.REQ_AttestationKeyInstall_Start(m_file_name.c_str());

}

void TfrmAttestationKeyInstall::CNF_AttestationKeyInstall(void)
{
    META_RESULT state = m_AttestationKey_Obj.Get_ConfirmState();
    if(state == META_SUCCESS)
    {
        SetStatusBarString("AttestationKey install OK");
    }
    else if(state == META_TIMEOUT)
    {
        SetStatusBarString("AttestationKey install timeout");
    }
    else
    {
        SetStatusBarString("AttestationKey install fail");
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void TfrmAttestationKeyInstall::CurrentPageLock(void)
{
    BtnLoadKeyFile->Enabled = false;
    BtnInstall->Enabled = false;
}

void TfrmAttestationKeyInstall::CurrentPageReset(void)
{
    BtnLoadKeyFile->Enabled = true;
    BtnInstall->Enabled = true;
}

void __fastcall TfrmAttestationKeyInstall::FormShow(TObject *Sender)
{
    LOG("Attestation Key Install Tool form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

