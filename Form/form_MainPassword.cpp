//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "form_MainPassword.h"

//version
#ifndef  _GET_VERSION_H_
#include "get_version.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

CGETVERSION    GET_VERSION_Object;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMainPassword *frmMainPassword;
//---------------------------------------------------------------------------
__fastcall TfrmMainPassword::TfrmMainPassword(TComponent* Owner)
    : TForm(Owner)
{
    m_InputStr = "";
    m_Success = false;
    m_OkPressed = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPassword::FormShow(TObject *Sender)
{
    LOG("MainPassword form center the form.");
    FormPositionSetting::CenterForm(this);
    m_InputStr = "";
    m_Success = false;
    m_OkPressed = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPassword::btnVerifyOKClick(TObject *Sender)
{
    /*    CRYPTFS_VERITIF_REQ cryptfs_Veritif_Req;
        CRYPTFS_VERITIF_CNF cryptfs_Veritif_Cnf;
        bool isCryptfsVeritif = GET_VERSION_Object.GetEncryptVeritif(&cryptfs_Veritif_Req, &cryptfs_Veritif_Cnf);
        if(isCryptfsVeritif && cryptfs_Veritif_Cnf.match_result)
        {

        }     */
    m_InputStr = edtPassword->Text;
    if(m_InputStr.IsEmpty())
    {
        Application->MessageBox( " Password can not be empty " , "Warning", MB_OK );
        return;
    }
    else if(m_InputStr.Length() > 32)
    {
        Application->MessageBox( " Password can not be longer than 32 bytes " , "Warning", MB_OK );
        return;
    }

    CRYPTFS_VERITIF_REQ cryptfs_Veritif_Req;
    CRYPTFS_VERITIF_CNF cryptfs_Veritif_Cnf;
    memset(&cryptfs_Veritif_Req, 0,sizeof(CRYPTFS_VERITIF_REQ));
    memset(&cryptfs_Veritif_Cnf, 0,sizeof(CRYPTFS_VERITIF_CNF));
    strcpy(cryptfs_Veritif_Req.pwd, m_InputStr.c_str());
    cryptfs_Veritif_Req.length = m_InputStr.Length();

    bool isCryptfsVeritif = GET_VERSION_Object.GetEncryptVeritif(&cryptfs_Veritif_Req, &cryptfs_Veritif_Cnf);
    LOG("isCryptfsVeritif is: %d", isCryptfsVeritif);
    LOG("cryptfs_Veritif_Cnf.match_result is: %d", cryptfs_Veritif_Cnf.match_result);
    if(!isCryptfsVeritif || (cryptfs_Veritif_Cnf.match_result != 1))
    {
        Application->MessageBox( " Password is wrong, please try again" , "Error", MB_OK );
        return;
    }
    else
    {
        m_OkPressed = true;
        m_Success = true;
        Application->MessageBox(" Password is correct, and this form will be closed", "SUCCESS", MB_OK);
        this->Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPassword::btnVerifyCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
AnsiString * TfrmMainPassword::GetPassword(void)
{
    return &m_InputStr;
}
//---------------------------------------------------------------------------
bool TfrmMainPassword::GetPasswordResult(void)
{
    return m_Success;
}
//---------------------------------------------------------------------------
bool TfrmMainPassword::GetOkPressed(void)
{
    return m_OkPressed;
}
//---------------------------------------------------------------------------

