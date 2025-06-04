//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_DRMKey.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDRMKeyInstall *frmDRMKeyInstall;

static void CNF_DRMKeyInstall(void)
{
    frmDRMKeyInstall->CNF_DRMKeyInstall();
}


static void CNF_DRMKeyQuery(void)
{
    frmDRMKeyInstall->CNF_DRMKeyQuery();
}

//---------------------------------------------------------------------------
__fastcall TfrmDRMKeyInstall::TfrmDRMKeyInstall(TComponent* Owner)
        : TForm(Owner)
{
    DRMLog->Lines->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TfrmDRMKeyInstall::BtnLoadKeyBlockFileClick(
      TObject *Sender)
{
    bool bOk = false;
    bOk = dlg_OpenKeyBlockFile->Execute();
    if ( !bOk )
    {
        //m_bOpenKeyBlockFile = false;
        SetStatusBarString("Open Key Block file fail");
        return;

    }
    stKeyBlockFile->Caption = dlg_OpenKeyBlockFile->FileName.c_str();
    m_file_name = dlg_OpenKeyBlockFile->FileName;
    if ( m_file_name.IsEmpty() )
    {
        Application->MessageBox( "Execution Failure: Please help to make sure the file path is valid", "ERROR", MB_OK );
        return;
    }
}
//---------------------------------------------------------------------------


void TfrmDRMKeyInstall::SetStatusBarString(char *strInfo)
{
    stDRMInfo->Caption = (AnsiString) strInfo;
}

void __fastcall TfrmDRMKeyInstall::BtnInstallClick(TObject *Sender)
{
    if ( m_file_name.IsEmpty() )
    {
        Application->MessageBox( "Execution Failure : Please select the KeyBlock file!", "FAILURE", MB_OK );
        return;
    }
    CurrentPageLock();
    m_cDRMKey_Obj.ConfirmCallback = ::CNF_DRMKeyInstall;
    m_cDRMKey_Obj.REQ_DRMKeyInstall_Start(m_file_name.c_str());

}
//---------------------------------------------------------------------------
void TfrmDRMKeyInstall::CNF_DRMKeyInstall(void)
{
    META_RESULT state = m_cDRMKey_Obj.Get_ConfirmState();
    if(state == META_SUCCESS)
    {
        SetStatusBarString("DRMKey install OK");
    }
    else if(state == META_TIMEOUT)
    {
        SetStatusBarString("DRMKey install timeout");
    }
    else
    {
        SetStatusBarString("DRMKey install fail");
    }
    CurrentPageReset();
}
void __fastcall TfrmDRMKeyInstall::BtnQueryVerifyClick(TObject *Sender)
{
    CurrentPageLock();
    m_cDRMKey_Obj.ConfirmCallback = ::CNF_DRMKeyQuery;
    m_cDRMKey_Obj.REQ_DRMKeyQuery_Start();
}
//---------------------------------------------------------------------------

void TfrmDRMKeyInstall::CNF_DRMKeyQuery(void)
{
    META_RESULT state = m_cDRMKey_Obj.Get_ConfirmState();
    if(state == META_SUCCESS)
    {
        char strQueryResult[4096*2]={0};
        bool bRet = m_cDRMKey_Obj.GetDRMKeyQueryResult(strQueryResult);
        if( bRet )
        {
            OutputLog(strQueryResult);
        }
        SetStatusBarString("DRMKey query OK");
    }
    else if( state == META_TIMEOUT )
    {
        SetStatusBarString("DRMKey query timeout");
    }
    else
    {
        SetStatusBarString("DRMKey query fail");
    }
    CurrentPageReset();
}

void TfrmDRMKeyInstall::OutputLog(char *strInfo)
{
    DRMLog->Lines->Add(strInfo);
    PostMessage(DRMLog->Handle,EM_SCROLLCARET, 0, 0);
}

void __fastcall TfrmDRMKeyInstall::BtnClearLogClick(TObject *Sender)
{
    DRMLog->Lines->Clear();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TfrmDRMKeyInstall::CurrentPageLock(void)
{
    BtnLoadKeyBlockFile->Enabled = false;
    BtnInstall->Enabled = false;
    BtnQueryVerify->Enabled = false;
    BtnClearLog->Enabled = false;
}

void TfrmDRMKeyInstall::CurrentPageReset(void)
{
    BtnLoadKeyBlockFile->Enabled = true;
    BtnInstall->Enabled = true;
    BtnQueryVerify->Enabled = true;
    BtnClearLog->Enabled = true;
}
