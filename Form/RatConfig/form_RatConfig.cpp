//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "form_RatConfig.h"
#include "meta_utils.h"

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRatConfig *frmRatConfig;
//---------------------------------------------------------------------------
__fastcall TfrmRatConfig::TfrmRatConfig(TComponent* Owner)
    : TForm(Owner)
{
    m_ppRadioBtn = NULL;
    m_nRadioBtnNum = 0;
    m_nRadioBtnFreeNum = 0;
}
//---------------------------------------------------------------------------

void TfrmRatConfig::Init( void )
{
    META_RESULT  mr = META_FAILED;
    int i = 0;
    char curRatValue[128] = {0};
    bool bSupport = m_RatConfig_Man_Obj.Query_RatConfig_Support();
    if (!bSupport)
    {
        Application->MessageBox("The target side does not support Radio Access Technology", "Notice", MB_OK);
        return;
    }
    RATCONFIG_READOPTR_CNF readOptrCnf;
    memset(&readOptrCnf, 0, sizeof(RATCONFIG_READOPTR_CNF));
    mr = m_RatConfig_Man_Obj.RATConfig_ReadOptr(5000, &readOptrCnf);
    if (mr != META_SUCCESS)
    {
        m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Read optr fail.";
        return;
    }

    m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Read optr success.";

    RATCONFIG_READOPTRSEG_CNF readOptrSegCnf;
    memset(&readOptrSegCnf, 0, sizeof(RATCONFIG_READOPTRSEG_CNF));
    mr = m_RatConfig_Man_Obj.RATConfig_ReadOptrSeg(5000, &readOptrSegCnf);
    if (mr != META_SUCCESS)
    {
        m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Read optr seg fail.";
        return;
    }
    m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Read optr seg success.";

    RATCONFIG_GETCURRENTRAT_CNF getCurrentRatCnf;
    memset(&getCurrentRatCnf, 0, sizeof(RATCONFIG_GETCURRENTRAT_CNF));
    mr = m_RatConfig_Man_Obj.RATConfig_GetCurrentRat(5000, &getCurrentRatCnf);
    if (mr != META_SUCCESS)
    {
        m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Get current rat fail.";
        return;
    }

    m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Get current rat success.";

    AnsiString asPath;
    getPathFromStr(Application->ExeName, asPath);
    AnsiString asXMLPath = asPath + "rat_config.xml";
    AnsiString asConfigPath = asPath + "rat_config_option.txt";
    int nParseRet = m_RatConfig_Man_Obj.ParseXMLFile(asXMLPath.c_str(), asConfigPath.c_str(), readOptrCnf.optr, readOptrSegCnf.optrseg);
    m_nRadioBtnNum = m_RatConfig_Man_Obj.m_nRatOptionCount;
    if( (nParseRet != 0) && (m_nRadioBtnNum != m_RatConfig_Man_Obj.m_OptionList.size()))
    {
        Application->MessageBox("Execution Failure: Parse XML fail", "FAILURE", MB_OK);
        return;
    }

    if ( (m_RatConfig_Man_Obj.m_nRatValid == 1) && (m_nRadioBtnNum > 0) )
    {
        //Maybe no need to show current value label
        //sprintf(curRatValue,"Current: %s", getCurrentRatCnf.rat_value) ;
        //LabelCurRAT->Caption = (AnsiString)curRatValue;
        FreeRadioResource();
        m_ppRadioBtn = new TRadioButton* [m_nRadioBtnNum];
        m_nRadioBtnFreeNum = m_nRadioBtnNum;
        for(i = 0; i< m_nRadioBtnNum; i++)
        {
            m_ppRadioBtn[i] = new TRadioButton(this);
            m_ppRadioBtn[i]->Parent = GroupBoxRATConfig;
            m_ppRadioBtn[i]->Top = 20 + 24*(i+1);
            m_ppRadioBtn[i]->Left = 24;
            m_ppRadioBtn[i]->Height = 17;
            m_ppRadioBtn[i]->Width = 113;
            m_ppRadioBtn[i]->Caption = (AnsiString)m_RatConfig_Man_Obj.m_OptionList[i].c_str();
            if( stricmp(m_RatConfig_Man_Obj.m_OptionList[i].c_str(), getCurrentRatCnf.rat_value) == 0 )
            {
                m_ppRadioBtn[i]->Checked = true;
            }
        }
    }
}

void __fastcall TfrmRatConfig::FormShow(TObject *Sender)
{
    Init();
}
//---------------------------------------------------------------------------

void TfrmRatConfig::FreeRadioResource(void)
{
    if(m_ppRadioBtn != NULL)
    {
        for(int i = 0; i< m_nRadioBtnFreeNum; i++)
        {
            if (m_ppRadioBtn[i] != NULL)
            {
                delete m_ppRadioBtn[i];
                m_ppRadioBtn[i] = NULL;
            }
        }
        delete [] m_ppRadioBtn;
        m_ppRadioBtn = NULL;
    }

}
void __fastcall TfrmRatConfig::FormDestroy(TObject *Sender)
{
    FreeRadioResource();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRatConfig::BtnUpdateClick(TObject *Sender)
{
    if(m_ppRadioBtn != NULL)
    {
        for(int i = 0; i< m_nRadioBtnNum; i++)
        {
            if ((m_ppRadioBtn[i] != NULL) && (m_ppRadioBtn[i]->Checked))
            {
                RATCONFIG_SETNEWRAT_REQ setNewRatReq;
                RATCONFIG_SETNEWRAT_CNF setNewRatCnf;
                memset(&setNewRatReq, 0, sizeof(RATCONFIG_SETNEWRAT_REQ));
                memset(&setNewRatCnf, 0, sizeof(RATCONFIG_SETNEWRAT_CNF));
                memcpy(setNewRatReq.set_rat_value,m_ppRadioBtn[i]->Caption.c_str(), strlen(m_ppRadioBtn[i]->Caption.c_str()));
                META_RESULT mr = m_RatConfig_Man_Obj.RATConfig_SetNewRat(5000, &setNewRatReq, &setNewRatCnf);
                if (mr != META_SUCCESS)
                {
                    m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Set new rat fail.";
                    return;
                }
                else
                {
                    if(setNewRatCnf.set_result == 0)
                    {
                        m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Set new rat fail.";
                        return;
                    }
                    else if(setNewRatCnf.set_result == 1)
                    {
                        Application->MessageBox("Set new rat success, and we will do factory reset and reboot the target", "Notice", MB_OK);
                        EMMC_CLEAR_CNF_S factoryResetCnf;
	                    memset(&factoryResetCnf, 0, sizeof(EMMC_CLEAR_CNF_S));
                        m_RatConfig_Man_Obj.RATConfig_FactoryReset(180000, &factoryResetCnf);
                        return;
                    }
                    else if(setNewRatCnf.set_result == 2)
                    {
                        m_sbRATStatus->Panels->Items[0]->Text = (AnsiString)"  Set new rat success, no need do factory reset.";
                        return;
                    }
                }

            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmRatConfig::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FreeRadioResource();
}
//---------------------------------------------------------------------------


