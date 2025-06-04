//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_MultiSIM.h"

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMultiSIM *frmMultiSIM;
//---------------------------------------------------------------------------
__fastcall TfrmMultiSIM::TfrmMultiSIM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmMultiSIM::Init( void )
{
    META_RESULT  mr = META_FAILED;
    bool bSupport = m_MSIM_Man_Obj.Query_MSIM_Support();
    if (!bSupport)
    {
        Application->MessageBox("The target side does not support Multi-SIM setting", "Notice", MB_OK);
        radioBtnSs->Visible = false;
        radioBtnDsds->Visible = false;
        return;
    }
    radioBtnSs->Visible = true;
    radioBtnDsds->Visible = true;
    MSIM_GETVALUE_CNF getValueCnf;
    memset(&getValueCnf, 0, sizeof(MSIM_GETVALUE_CNF));
    mr = m_MSIM_Man_Obj.MSIM_GetValue(5000, &getValueCnf);
    if (mr != META_SUCCESS)
    {
        m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Get Multi-SIM value fail.";
        return;
    }

    m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Get Multi-SIM value success.";


    if( stricmp(getValueCnf.msim_value, "ss") == 0 )
    {
        radioBtnSs->Checked = true;
    }
    else if( stricmp(getValueCnf.msim_value, "dsds") == 0 )
    {
        radioBtnDsds->Checked = true;
    }
    else
    {
        m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Multi-SIM value invalid.";
    }
}
void __fastcall TfrmMultiSIM::FormShow(TObject *Sender)
{
    FormPositionSetting::CenterForm(this);
    Init();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMultiSIM::btnMSIMUpdateClick(TObject *Sender)
{
    MSIM_SETVALUE_REQ setValueReq;
    MSIM_SETVALUE_CNF setValueCnf;
    memset(&setValueReq, 0, sizeof(MSIM_SETVALUE_REQ));
    memset(&setValueCnf, 0, sizeof(MSIM_SETVALUE_CNF));
    if (radioBtnSs->Checked)
    {
        memcpy(setValueReq.msim_value, "ss", strlen("ss"));
    }
    else if (radioBtnDsds->Checked)
    {
        memcpy(setValueReq.msim_value, "dsds", strlen("dsds"));
    }
    else
    {
        Application->MessageBox("Execution Failure: The Multi-SIM setting is invalid, update fail", "FAILURE", MB_OK);
        return;
    }
    META_RESULT mr = m_MSIM_Man_Obj.MSIM_SetValue(5000, &setValueReq, &setValueCnf);
    if (mr != META_SUCCESS)
    {
        m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Set Multi-SIM value fail.";
        return;
    }
    else
    {
        if(setValueCnf.set_result == 0)
        {
            m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Set Multi-SIM value fail.";
            return;
        }
        else if(setValueCnf.set_result == 1)
        {
            Application->MessageBox("Set new Multi-SIM value success, and we will do factory reset and reboot the target", "Notice", MB_OK);
            EMMC_CLEAR_CNF_S factoryResetCnf;
            memset(&factoryResetCnf, 0, sizeof(EMMC_CLEAR_CNF_S));
            m_MSIM_Man_Obj.MSIM_FactoryReset(180000, &factoryResetCnf);
            return;
        }
        else if(setValueCnf.set_result == 2)
        {
            m_sbMultiSIMStatus->Panels->Items[0]->Text = (AnsiString)"  Set Multi-SIM value success, no need do factory reset.";
            return;
        }
    }
}
//---------------------------------------------------------------------------

