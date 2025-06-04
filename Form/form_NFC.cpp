//---------------------------------------------------------------------------

#include <vcl.h>

#include <stdio.h>

#pragma hdrstop

#include "form_NFC.h"

#ifndef  _MISC_NFC_H_
#include "misc_NFC.h"
#endif

#ifndef form_NFC_TagDetectedH
#include "form_NFC_TagDetected.h"
#endif

#ifndef form_NFC_PeerToPeerH
#include "form_NFC_PeerToPeer.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmNFC *frmNFC;

char g_nfc_protocol[NFC_PROTOCOL_TYPE_NUM][20] =
{
    "Mifare_1K",
    "Mifare_4K",
    "ISO1443A",
    "ISO1443B",
    "JEWEL",
    "NFC",
    "FeLICA",
    "ISO1596",
    "NDEF"
};

E_NFC_SUPPORT_PROTOCOL g_nfc_protocol_value[NFC_PROTOCOL_TYPE_NUM - 1] =
{
    NFC_MIFAREUL,
    NFC_MIFARESTD,
    NFC_ISO1443_4A,
    NFC_ISO1443_4B,
    NFC_JEWEL,
    NFC_NFC,
    NFC_FELICA,
    NFC_ISO15693
};

E_NFC_EVENT_DETECTED g_nfc_event_value[NFC_EVENT_DETECTED_NUM] =
{
    NFC_EVENT_START,
    NFC_EVENT_END,
    NFC_EVENT_TRANSACTION,
    NFC_EVENT_RFON,
    NFC_EVENT_RFOFF,
    NFC_EVENT_CONNECTIVITY
};

E_NFC_DISCOVERY_SETTING g_nfc_discovery_value[NFC_DISCOVERY_PROTOCOL_NUM] =
{
    NFC_DISCOVERY_ISO14443A,
    NFC_DISCOVERY_ISO14443B,
    NFC_DISCOVERY_FELICA212,
    NFC_DISCOVERY_FELICA424,
    NFC_DISCOVERY_ISO15693,
    NFC_DISCOVERY_NFC_ACTIVE,
    NFC_DISCOVERY_DISCARD_CARD_EMULATION,
    NFC_DISCOVERY_DISABLE_P2P_IP_TARGET
};
//---------------------------------------------------------------------------
__fastcall TfrmNFC::TfrmNFC(TComponent* Owner)
    : TForm(Owner)
{
    frmNFC->Width = 828;
    frmNFC->Height = 546;
    for(int i=0; i<NFC_PROTOCOL_TYPE_NUM; i++)
    {
        rbNFC_Test[i] = NULL;
    }
    
    for(int i=0; i<NFC_REGISTER_PROTOCOL_NUM; i++)
    {
        cbNFC_RN[i] = NULL;
    }
    
    for(int i=0; i<NFC_DISCOVERY_PROTOCOL_NUM; i++)
    {
        cbNFC_DS[i] = NULL;
    }
    
    
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::FormCreate(TObject *Sender)
{
    this->Height = 611;
    this->Width = 783;

    rbNFC_Test[0] = rbNFC_Test_WithASK;
    rbNFC_Test[1] = rbNFC_Test_WithoutASK;
    rbNFC_Test[2] = rbNFC_Test_Emulation;
    rbNFC_Test[3] = rbNFC_Test_Reader;
    rbNFC_Test[4] = rbNFC_Test_Peer;
    rbNFC_Test[5] = rbNFC_Test_SWP;
    rbNFC_Test[6] = rbNFC_Test_Antenna;
    rbNFC_Test[7] = rbNFC_Test_UidRD;
    rbNFC_Test[8] = rbNFC_Test_CardMode;

    cbNFC_RN[0] = cbNFC_RN_MifareUL;
    cbNFC_RN[1] = cbNFC_RN_MifareStd;
    cbNFC_RN[2] = cbNFC_RN_ISO144434A;
    cbNFC_RN[3] = cbNFC_RN_ISO144434B;
    cbNFC_RN[4] = cbNFC_RN_Jewel;
    cbNFC_RN[5] = cbNFC_RN_NFC;
    cbNFC_RN[6] = cbNFC_RN_Felica;
    cbNFC_RN[7] = cbNFC_RN_ISO15693;

    cbNFC_DS[0] = cbNFC_DS_ISO14443A;
    cbNFC_DS[1] = cbNFC_DS_ISO14443B;
    cbNFC_DS[2] = cbNFC_DS_Felica212;
    cbNFC_DS[3] = cbNFC_DS_Felica424;
    cbNFC_DS[4] = cbNFC_DS_ISO15693;
    cbNFC_DS[5] = cbNFC_DS_NFCActive;
    cbNFC_DS[6] = cbNFC_DS_DisCardEmu;
    cbNFC_DS[7] = cbNFC_DS_DisP2PIpTar;

    TabVisible(NFC_TAB_SETTING);
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::backdoorExecute(TObject *Sender)
{
    /*
        if(!btnSoftwareStack->Enabled && !btnRawData->Enabled)
        {
            btnSoftwareStack->Enabled = true;
            btnRawData->Enabled = false;
        }
        else if(btnSoftwareStack->Enabled && !btnRawData->Enabled)
        {
            btnSoftwareStack->Enabled = false;
            btnRawData->Enabled = true;
        }
        else
        {
            btnSoftwareStack->Enabled = false;
            btnRawData->Enabled = false;
        }
        if(btnNFC_RN_DiscoveryNotification->Enabled)
        {
            btnNFC_RN_DiscoveryNotification->Enabled = false;
        }
        else
        {
            btnNFC_RN_DiscoveryNotification->Enabled = true;
        }

        if(gbNFCSecureElements->Visible)
        {
            gbNFCSecureElements->Visible = false;
            gbNFCSecureElementSetMode->Visible = false;
            gbNFCSecureElementEventsDetected->Visible = false;
        }
        else
        {
            gbNFCSecureElements->Visible = true;
            gbNFCSecureElementSetMode->Visible = true;
            gbNFCSecureElementEventsDetected->Visible = true;
        }
    */
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::Action1Execute(TObject *Sender)
{
    //frmNFCSwStack->tsNFCTagDetected->TabVisible = true;
    //frmNFCSwStack->tsNFCP2P->TabVisible = false;
    //frmNFCSwStack->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::Action2Execute(TObject *Sender)
{
    //frmNFCSwStack->tsNFCTagDetected->TabVisible = false;
    //frmNFCSwStack->tsNFCP2P->TabVisible = true;
    //frmNFCSwStack->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::Action3Execute(TObject *Sender)
{
    //frmNFCTagDetected->tsNFCReadNDEFTag->TabVisible = true;
    //frmNFCTagDetected->tsNFCWriteNDEFTag->TabVisible = false;
    //frmNFCTagDetected->tsNFCRawCommand->TabVisible = false;
    //frmNFCTagDetected->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFC::Action4Execute(TObject *Sender)
{
    //frmNFCTagDetected->tsNFCReadNDEFTag->TabVisible = false;
    //frmNFCTagDetected->tsNFCWriteNDEFTag->TabVisible = true;
    //frmNFCTagDetected->tsNFCRawCommand->TabVisible = false;
    //frmNFCTagDetected->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFC::Action5Execute(TObject *Sender)
{
    ///frmNFCTagDetected->tsNFCReadNDEFTag->TabVisible = false;
    //frmNFCTagDetected->tsNFCWriteNDEFTag->TabVisible = false;
    //frmNFCTagDetected->tsNFCRawCommand->TabVisible = true;
    //frmNFCTagDetected->Show();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rbNFCClick(TObject *Sender)
{

    if(rbNFCOn->Checked)
    {
        rbNFCOn->Font->Color = clRed;
        rbNFCOff->Font->Color = clBlack;
    }
    else
    {
        rbNFCOn->Font->Color = clBlack;
        rbNFCOff->Font->Color = clRed;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rbNFCDebugClick(TObject *Sender)
{

    if(rbNFCDebugOn->Checked)
    {
        rbNFCDebugOn->Font->Color = clRed;
        rbNFCDebugOff->Font->Color = clBlack;
    }
    else
    {
        rbNFCDebugOn->Font->Color = clBlack;
        rbNFCDebugOff->Font->Color = clRed;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rsNFCSWProtocolSwitchClick(TObject *Sender)
{

    if(rbNFCSoftwareStack->Checked)
    {
        rbNFCSoftwareStack->Font->Color = clRed;
        rbNFCRawData->Font->Color = clBlack;

    }
    else
    {
        rbNFCSoftwareStack->Font->Color = clBlack;
        rbNFCRawData->Font->Color = clRed;

    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnSoftwareStackClick(TObject *Sender)
{
    tsNFCSetting->TabVisible = false;
    tsNFCRegisterNotification->TabVisible = true;
    tsRawData->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnNFCRawDataClick(TObject *Sender)
{
    tsNFCSetting->TabVisible = false;
    tsNFCRegisterNotification->TabVisible = false;
    tsRawData->TabVisible = true;
}
//---------------------------------------------------------------------------
// Regisetr Notification
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnNFC_RN_NFCSettingClick(TObject *Sender)
{
    tsNFCSetting->TabVisible = true;
    tsNFCRegisterNotification->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnNFC_RN_DiscoveryNotificationClick(
    TObject *Sender)
{
    tsNFCRegisterNotification->TabVisible = false;
    tsNFCDiscoveryNotification->TabVisible = true;
}
//---------------------------------------------------------------------------
// Discovery Notification
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnNFC_DN_regNotificationClick(TObject *Sender)
{
    tsNFCRegisterNotification->TabVisible = false;
    tsNFCDiscoveryNotification->TabVisible = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCSettingSetClick(TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_SETTING);
    NFC_SETTING_REQ_S nfc_setting_req;
    NFC_SETTING_CNF_S nfc_setting_cnf;
    if(rbNFCOn->Checked)
    {
        nfc_setting_req.nfc_enable = 1;
    }
    else
    {
        nfc_setting_req.nfc_enable = 0;
    }

    if(rbNFCDebugOn->Checked)
    {
        nfc_setting_req.debug_enable = 1;
    }
    else
    {
        nfc_setting_req.debug_enable = 0;
    }

    if(rbNFCSoftwareStack->Checked)
    {
        nfc_setting_req.sw_protocol = 0;
    }
    else
    {
        nfc_setting_req.sw_protocol = 1;
    }

    nfc_setting_req.get_capabilities = 1;

    META_RESULT MetaResult = SP_META_NFC_Setting_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000, &nfc_setting_req, &nfc_setting_cnf);
    if( META_SUCCESS != MetaResult || nfc_setting_cnf.status)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" Set NFC Setting fail";
        Application->MessageBox( "Execution Failure :Set NFC Setting", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_SETTING);
        sbNFCSettingNext->Enabled = false;
        return;
    }

    if(nfc_setting_cnf.get_capabilities)
    {
//update capabilities
        stNFCFwVersion->Caption = "0x" + IntToHex((int)nfc_setting_cnf.fw_ver, 1);
        stNFCSwVersion->Caption = "0x" + IntToHex((int)nfc_setting_cnf.sw_ver, 1);
        stNFCHwVersion->Caption = "0x" + IntToHex((int)nfc_setting_cnf.hw_ver, 1);
//reader mode support protocol
        for(int i = 0; i < NFC_PROTOCOL_TYPE_NUM - 1; i++)
        {
            if(nfc_setting_cnf.reader_mode & g_nfc_protocol_value[i])
            {
                clbNFC_Support_Prococol_Rm->Checked[i] = true;
            }
            else
            {
                clbNFC_Support_Prococol_Rm->Checked[i] = false;
            }
        }
//card mode support protocol
        for(int i = 0; i < NFC_PROTOCOL_TYPE_NUM - 1; i++)
        {
            if(nfc_setting_cnf.card_mode & g_nfc_protocol_value[i])
            {
                clbNFC_Support_Prococol_Cm->Checked[i] = true;
            }
            else
            {
                clbNFC_Support_Prococol_Cm->Checked[i] = false;
            }
        }
    }
    CurrentPageReset(NFC_TAB_SETTING);

    if(rbNFCSoftwareStack->Checked)
    {
        TabVisible(NFC_TAB_REGISTER_NOTIFICATION);
    }
    else
    {
        TabVisible(NFC_TAB_RAW_DATA);
    }

    sbNFCSettingNext->Enabled = true;
    sbNFC->Panels->Items[0]->Text = (AnsiString)" Set NFC Setting successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRegisterNofificationSetClick(TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_REGISTER_NOTIFICATION);
    gbNFCSecureElements->Visible = false;
    gbNFCSecureElement1->Enabled = false;
    gbNFCSecureElement2->Enabled = false;

    NFC_REGNOTIFY_REQ_S nfc_regnotify_req;
    NFC_REGNOTIFY_CNF_S nfc_regnotify_cnf;

    memset(&nfc_regnotify_req, 0, sizeof(nfc_regnotify_req));

    for(int i = 0; i < NFC_REGISTER_PROTOCOL_NUM; i++)
    {
        if(cbNFC_RN[i]->Checked)
        {
            nfc_regnotify_req.reg_type |= g_nfc_protocol_value[i];
        }
    }

    META_RESULT MetaResult = SP_META_NFC_RegNotify_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000, &nfc_regnotify_req, &nfc_regnotify_cnf);
    if( META_SUCCESS != MetaResult || nfc_regnotify_cnf.status)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Register Notification fail";
        Application->MessageBox( "Execution Failure :Set Register Notification", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_REGISTER_NOTIFICATION);
        sbNFCRegisterNofificationNext->Enabled = false;
        return;
    }

    if(nfc_regnotify_cnf.se)
    {
        gbNFCSecureElements->Visible = true;
    }
//secure elements
    if(1 == nfc_regnotify_cnf.se)
    {
        gbNFCSecureElement1->Enabled = true;
        if(0 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement1Off->Checked = true;
        }
        else if(1 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement1Virtual->Checked = true;
        }
        else if(2 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement1Wired->Checked = true;
        }
    }
    else if(2 == nfc_regnotify_cnf.se)
    {
        gbNFCSecureElement2->Enabled = true;
        if(0 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement2Off->Checked = true;
        }
        else if(1 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement1Virtual->Checked = true;
        }
        else if(2 == nfc_regnotify_cnf.se_status)
        {
            cbNFCSecureElement1Wired->Checked = true;
        }
    }
//event detected
    for(int i = 0; i < NFC_EVENT_DETECTED_NUM; i++)
    {
        if(nfc_regnotify_cnf.se_type & g_nfc_event_value[i])
        {
            clbNFC_Secure_Event_Detected->Checked[i] = true;
        }
    }

    CurrentPageReset(NFC_TAB_REGISTER_NOTIFICATION);

    if(!nfc_regnotify_cnf.se)
    {
        TabVisible(NFC_TAB_DISCOVERY_NOTIFICATION);
        sbNFCRegisterNofificationNext->Enabled = true;
    }

    sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Register Notification successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCSecureElementsSetClick(TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_REGISTER_NOTIFICATION);
    NFC_SECURE_REQ_S nfc_secure_req;
    NFC_SECURE_CNF_S nfc_secure_cnf;

    if(gbNFCSecureElement1->Enabled)
    {
        if(cbNFCSecureElement1Off->Checked)
        {
            nfc_secure_req.set_SEtype = 0;
        }
        else if(cbNFCSecureElement1Virtual->Checked)
        {
            nfc_secure_req.set_SEtype = 1;
        }
        else if(cbNFCSecureElement1Wired->Checked)
        {
            nfc_secure_req.set_SEtype = 2;
        }
    }

    else if(gbNFCSecureElement2->Enabled)
    {
        if(cbNFCSecureElement2Off->Checked)
        {
            nfc_secure_req.set_SEtype = 0;
        }
        else if(cbNFCSecureElement2Virtual->Checked)
        {
            nfc_secure_req.set_SEtype = 1;
        }
        else if(cbNFCSecureElement2Wired->Checked)
        {
            nfc_secure_req.set_SEtype = 2;
        }
    }

    META_RESULT MetaResult = SP_META_NFC_SecureElement_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000, &nfc_secure_req, &nfc_secure_cnf);
    if( META_SUCCESS != MetaResult || nfc_secure_cnf.status)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Secure Elements fail";
        Application->MessageBox( "Execution Failure :Set Secure Elements", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_REGISTER_NOTIFICATION);
        sbNFCRegisterNofificationNext->Enabled = false;
        return;
    }
    CurrentPageReset(NFC_TAB_REGISTER_NOTIFICATION);
    sbNFCRegisterNofificationNext->Enabled = true;

    TabVisible(NFC_TAB_DISCOVERY_NOTIFICATION);
    sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Secure Elements successful";

//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCDiscoveryNotificationSetClick(
    TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_DISCOVERY_NOTIFICATION);
    NFC_DISCOVERY_REQ_S nfc_discovery_req;
    NFC_DISCOVERY_CNF_S nfc_discovery_cnf;

    //short * token;
    //void * usrData;

    memset(&nfc_discovery_req, 0, sizeof(nfc_discovery_req));

    for(int i = 0; i < NFC_DISCOVERY_PROTOCOL_NUM; i++)
    {
        if(cbNFC_DS[i]->Checked)
        {
            nfc_discovery_req.dis_type |= g_nfc_discovery_value[i];
        }
    }

    AnsiString text = edtNFC_DN_Duration->Text;
    if( !IsValidDuration( text) )
    {
//        ShowHintLabel( edit, hint );
//        edit->SetFocus();
        CurrentPageReset(NFC_TAB_DISCOVERY_NOTIFICATION);
        return;
    }

    nfc_discovery_req.duration = StrToInt(edtNFC_DN_Duration->Text);

    META_RESULT MetaResult = SP_META_NFC_Discovery_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_discovery_req, &nfc_discovery_cnf);
    if( META_SUCCESS != MetaResult || nfc_discovery_cnf.status)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Discovery Notification fail";
        Application->MessageBox( "Execution Failure :Set Discovery Notification", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_DISCOVERY_NOTIFICATION);
        return;
    }

    if(1 == nfc_discovery_cnf.type)
    {
        switch(nfc_discovery_cnf.nfc_device_info.nfc_tag_info.tag_type)
        {
        case 1:
            frmNFCTagDetected->stNFC_TD_TagType->Caption = "Tag";
            break;
        case 2:
            frmNFCTagDetected->stNFC_TD_TagType->Caption = "NDEF";
            break;
        default:
            break;
        }

        int cardType = nfc_discovery_cnf.nfc_device_info.nfc_tag_info.card_type;
        if(1 > cardType || 9 < cardType)
        {
            sbNFC->Panels->Items[0]->Text = (AnsiString)" Confirm card type is wrong";
            Application->MessageBox( "Execution Failure :Confirm card type is wrong", "FAILURE", MB_OK );
            CurrentPageReset(NFC_TAB_DISCOVERY_NOTIFICATION);
            return;
        }
        frmNFCTagDetected->stNFC_TD_CardType->Caption = g_nfc_protocol[cardType - 1];

        switch(nfc_discovery_cnf.nfc_device_info.nfc_tag_info.card_type)
        {
        case 1:
        case 2:
        case 9:
            frmNFCTagDetected->btnNFC_TD_RdWr->Enabled = true;
            frmNFCTagDetected->btnNFC_TD_RawCommand->Enabled = false;

            frmNFCTagDetected->btnNFC_TD_RdWr->Tag = 0;
            frmNFCTagDetected->btnNFC_TD_RawCommand->Tag = 1;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            frmNFCTagDetected->btnNFC_TD_RdWr->Enabled = false;
            frmNFCTagDetected->btnNFC_TD_RawCommand->Enabled = true;

            frmNFCTagDetected->btnNFC_TD_RdWr->Tag = 1;
            frmNFCTagDetected->btnNFC_TD_RawCommand->Tag = 0;
            break;
        default:
            return;
        }

        frmNFCTagDetected->stNFC_TD_Uid->Caption = "0x" + IntToHex((int)nfc_discovery_cnf.nfc_device_info.nfc_tag_info.uid, 2);
        frmNFCTagDetected->stNFC_TD_Sak->Caption = "0x" + IntToHex((int)nfc_discovery_cnf.nfc_device_info.nfc_tag_info.sak, 2);
        frmNFCTagDetected->stNFC_TD_AtqA->Caption = "0x" + IntToHex((int)nfc_discovery_cnf.nfc_device_info.nfc_tag_info.atag, 2);
        frmNFCTagDetected->stNFC_TD_AppData->Caption = "0x" + IntToHex((int)nfc_discovery_cnf.nfc_device_info.nfc_tag_info.appdata, 2);
        frmNFCTagDetected->stNFC_TD_MaxDataRate->Caption = "0x" + IntToHex((int)nfc_discovery_cnf.nfc_device_info.nfc_tag_info.maxdatarate, 2);

        if(!frmNFCTagDetected->Visible)
        {
            frmNFCTagDetected->ShowModal();
        }
    }
    else if(2 == nfc_discovery_cnf.type)
    {
        if(!frmNFCPeerToPeer->Visible)
        {
            frmNFCPeerToPeer->ShowModal();
        }
    }

    CurrentPageReset(NFC_TAB_DISCOVERY_NOTIFICATION);
    sbNFC->Panels->Items[0]->Text = (AnsiString)" Set Discovery Notification successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRawDataTestStartClick(TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_RAW_DATA);
    NFC_SCRIPT_REQ_S nfc_script_req;
    NFC_SCRIPT_CNF_S nfc_script_cnf;
    META_RESULT MetaResult;

    nfc_script_req.type = 1;
    nfc_script_req.action = 1;
    nfc_script_cnf.result = 0;

    if(rbNFC_Test_WithASK->Checked)
    {
        NFC_TXALWAYS_REQ_S nfc_txalways_req;
        nfc_txalways_req.type = 1;
        nfc_txalways_req.action = 1;
        nfc_txalways_req.modulation_type = cbNFC_Raw_Modulation_Type->ItemIndex;
        nfc_txalways_req.bitrate = cbNFC_Raw_BitRate->ItemIndex;
        MetaResult = SP_META_NFC_TxAlwaysOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                              &nfc_txalways_req, &nfc_script_cnf);

    }
    else if(rbNFC_Test_WithoutASK->Checked)
    {
        NFC_TXALWAYS_REQ_S nfc_txalways_req;
        nfc_txalways_req.type = 1;
        nfc_txalways_req.action = 1;
        nfc_txalways_req.modulation_type = cbNFC_Raw_Modulation_Type->ItemIndex;
        nfc_txalways_req.bitrate = cbNFC_Raw_BitRate->ItemIndex;
        MetaResult = SP_META_NFC_TxAlwaysOnWOACK_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_txalways_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Emulation->Checked)
    {
        NFC_CARDEMULATION_REQ_S nfc_cardemulation_req;
        nfc_cardemulation_req.type = 1;
        nfc_cardemulation_req.action = 1;
        nfc_cardemulation_req.technology = cbNFC_Raw_Type->ItemIndex;
        nfc_cardemulation_req.protocols = cbNFC_Raw_Protocol->ItemIndex;
//        MetaResult = SP_META_NFC_CardEmulationMode_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
//                     &nfc_cardemulation_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Reader->Checked)
    {
        MetaResult = SP_META_NFC_ReaderModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Peer->Checked)
    {
        MetaResult = SP_META_NFC_P2PModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                               &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_SWP->Checked)
    {
        MetaResult = SP_META_NFC_SWPSelfTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                               &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Antenna->Checked)
    {
        MetaResult = SP_META_NFC_AntennaSelfTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_UidRD->Checked)
    {
        NFC_SCRIPTUID_REQ_S nfc_scriptuid_req;
        NFC_SCRIPTUID_CNF_S nfc_scriptuid_cnf;
        nfc_scriptuid_req.type = 1;
        nfc_scriptuid_req.action = 1;
        nfc_scriptuid_req.uid_type = 0;
        memset(nfc_scriptuid_req.data, 0, sizeof(nfc_scriptuid_req.data));

        MetaResult = SP_META_NFC_TagUidRW_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                            &nfc_scriptuid_req, &nfc_scriptuid_cnf);
        if(nfc_scriptuid_cnf.result)
        {
            sbNFC->Panels->Items[0]->Text = (AnsiString)" NFC test start fail";
            Application->MessageBox( "Execution Failure :NFC test start", "FAILURE", MB_OK );
            CurrentPageReset(NFC_TAB_RAW_DATA);
            return;
        }
    }

    else if(rbNFC_Test_CardMode->Checked)
    {
        NFC_CARDMODETEST_REQ_S nfc_cardmodetest_req;
        nfc_cardmodetest_req.type = 1;
        nfc_cardmodetest_req.action = 1;
        nfc_cardmodetest_req.technology = cbNFC_Raw_Type->ItemIndex;
        nfc_cardmodetest_req.protocols = cbNFC_Raw_Protocol->ItemIndex;
        MetaResult = SP_META_NFC_CardModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                                &nfc_cardmodetest_req, &nfc_script_cnf);
    }

    if( META_SUCCESS != MetaResult || nfc_script_cnf.result)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" NFC test start fail";
        Application->MessageBox( "Execution Failure :NFC test start", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        return;
    }

    CurrentPageReset(NFC_TAB_RAW_DATA);

    for(int i = 0; i < 9; i++)
    {
        rbNFC_Test[i]->Enabled = false;
    }

    if(cbNFC_Raw_Modulation_Type->Enabled)
    {
        cbNFC_Raw_Modulation_Type->Enabled = false;
        cbNFC_Raw_Modulation_Type->Tag = 1;
    }
    if(cbNFC_Raw_BitRate->Enabled)
    {
        cbNFC_Raw_BitRate->Enabled = false;
        cbNFC_Raw_BitRate->Tag = 1;
    }
    if(cbNFC_Raw_Type->Enabled)
    {
        cbNFC_Raw_Type->Enabled = false;
        cbNFC_Raw_Type->Tag = 1;
    }
    if(cbNFC_Raw_Protocol->Enabled)
    {
        cbNFC_Raw_Protocol->Enabled = false;
        cbNFC_Raw_Protocol->Tag = 1;
    }

    gbNFCRawData->Enabled = false;
    sbNFCRawDataBack->Enabled = false;

    sbNFCRawDataTestStart->Enabled = false;
    sbNFCRawDataTestStop->Enabled = true;
    sbNFC->Panels->Items[0]->Text = (AnsiString)" NFC test start successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRawDataTestStopClick(TObject *Sender)
{
//#if 0
    CurrentPageLock(NFC_TAB_RAW_DATA);
    NFC_SCRIPT_REQ_S nfc_script_req;
    NFC_SCRIPT_CNF_S nfc_script_cnf;
    META_RESULT MetaResult;

    nfc_script_req.type = 1;
    nfc_script_req.action = 0;

    if(rbNFC_Test_WithASK->Checked)
    {
        NFC_TXALWAYS_REQ_S nfc_txalways_req;
        nfc_txalways_req.type = 1;
        nfc_txalways_req.action = 0;
        nfc_txalways_req.modulation_type = cbNFC_Raw_Modulation_Type->ItemIndex;
        nfc_txalways_req.bitrate = cbNFC_Raw_BitRate->ItemIndex;
        MetaResult = SP_META_NFC_TxAlwaysOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                              &nfc_txalways_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_WithoutASK->Checked)
    {
        NFC_TXALWAYS_REQ_S nfc_txalways_req;
        nfc_txalways_req.type = 1;
        nfc_txalways_req.action = 0;
        nfc_txalways_req.modulation_type = cbNFC_Raw_Modulation_Type->ItemIndex;
        MetaResult = SP_META_NFC_TxAlwaysOnWOACK_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_txalways_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Emulation->Checked)
    {
        NFC_CARDEMULATION_REQ_S nfc_cardemulation_req;
        nfc_cardemulation_req.type = 1;
        nfc_cardemulation_req.action = 0;
        nfc_cardemulation_req.technology = cbNFC_Raw_Type->ItemIndex;
        nfc_cardemulation_req.protocols = cbNFC_Raw_Protocol->ItemIndex;
//        MetaResult = SP_META_NFC_CardEmulationMode_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
//                     &nfc_cardemulation_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Reader->Checked)
    {
        MetaResult = SP_META_NFC_ReaderModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Peer->Checked)
    {
        MetaResult = SP_META_NFC_P2PModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                               &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_SWP->Checked)
    {
        MetaResult = SP_META_NFC_SWPSelfTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                               &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_Antenna->Checked)
    {
        MetaResult = SP_META_NFC_AntennaSelfTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                     &nfc_script_req, &nfc_script_cnf);
    }
    else if(rbNFC_Test_UidRD->Checked)
    {
        NFC_SCRIPTUID_REQ_S nfc_scriptuid_req;
        NFC_SCRIPTUID_CNF_S nfc_scriptuid_cnf;
        nfc_scriptuid_req.type = 1;
        nfc_scriptuid_req.action = 0;
        nfc_scriptuid_req.uid_type = 1;
        memset(nfc_scriptuid_req.data, 0, sizeof(nfc_scriptuid_req.data));
        MetaResult = SP_META_NFC_TagUidRW_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                            &nfc_scriptuid_req, &nfc_scriptuid_cnf);
    }

    else if(rbNFC_Test_CardMode->Checked)
    {
        NFC_CARDMODETEST_REQ_S nfc_cardmodetest_req;
        nfc_cardmodetest_req.type = 1;
        nfc_cardmodetest_req.action = 0;
        nfc_cardmodetest_req.technology = cbNFC_Raw_Type->ItemIndex;
        nfc_cardmodetest_req.protocols = cbNFC_Raw_Protocol->ItemIndex;
        MetaResult = SP_META_NFC_CardModeTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                                                &nfc_cardmodetest_req, &nfc_script_cnf);
    }

    if( META_SUCCESS != MetaResult)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString)" NFC test stop fail";
        Application->MessageBox( "Execution Failure :NFC test stop", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        return;
    }

    CurrentPageReset(NFC_TAB_RAW_DATA);

    for(int i = 0; i < 9; i++)
    {
        rbNFC_Test[i]->Enabled = true;
    }

    if(1 == cbNFC_Raw_Modulation_Type->Tag)
    {
        cbNFC_Raw_Modulation_Type->Enabled = true;
        cbNFC_Raw_Modulation_Type->Tag = 0;
    }
    if(1 == cbNFC_Raw_BitRate->Tag)
    {
        cbNFC_Raw_BitRate->Enabled = true;
        cbNFC_Raw_BitRate->Tag = 0;
    }
    if(1 == cbNFC_Raw_Type->Tag)
    {
        cbNFC_Raw_Type->Enabled = true;
        cbNFC_Raw_Type->Tag = 0;
    }
    if(1 == cbNFC_Raw_Protocol->Tag)
    {
        cbNFC_Raw_Protocol->Enabled = false;
        cbNFC_Raw_Protocol->Tag = 0;
    }

    gbNFCRawData->Enabled = true;
    sbNFCRawDataBack->Enabled = true;

    sbNFCRawDataTestStart->Enabled = true;
    sbNFCRawDataTestStop->Enabled = false;
    sbNFC->Panels->Items[0]->Text = (AnsiString)" NFC test stop successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rbNFC_Test_WithASKClick(TObject *Sender)
{
    cbNFC_Raw_Modulation_Type->Enabled = true;
    cbNFC_Raw_BitRate->Enabled = true;
    cbNFC_Raw_Type->Enabled = false;
    cbNFC_Raw_Protocol->Enabled = false;

    NFCTestItemSelect();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rbNFC_Test_EmulationClick(TObject *Sender)
{
    cbNFC_Raw_Modulation_Type->Enabled = false;
    cbNFC_Raw_BitRate->Enabled = false;
    cbNFC_Raw_Type->Enabled = true;
    cbNFC_Raw_Protocol->Enabled = true;

    NFCTestItemSelect();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::rbNFC_Test_ReaderClick(TObject *Sender)
{
    cbNFC_Raw_Modulation_Type->Enabled = false;
    cbNFC_Raw_BitRate->Enabled = false;
    cbNFC_Raw_Type->Enabled = false;
    cbNFC_Raw_Protocol->Enabled = false;

    NFCTestItemSelect();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::btnNFC_RD_OpenScriptClick(TObject *Sender)
{
    CurrentPageLock(NFC_TAB_RAW_DATA);
    char str[512];
    bool ok;

    FILE *fp;
    //bool IsEof;

    char buffer[1000];

    ok = dlgOpenNFCScipt->Execute();
    if (!ok)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString) "  Open NFC script fail";
        Application->MessageBox( "Execution Failure : Open NFC script", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        return;
    }

    strcpy(str, dlgOpenNFCScipt->FileName.c_str());

    fp = fopen(str, "r");
    if (NULL == fp)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString) "  Open NFC script file fail";
        Application->MessageBox( "Execution Failure : Open NFC script file", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        return;
    }

    if(fseek(fp, 0, SEEK_END))
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString) "  Operate NFC script file fail";
        Application->MessageBox( "Execution Failure : Operate NFC script file", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        fclose(fp);
        return;
    }

    int fileLength = ftell(fp);

    if(0 >= fileLength)
    {
        sbNFC->Panels->Items[0]->Text = (AnsiString) "  Operate NFC script file fail";
        Application->MessageBox( "Execution Failure : Operate NFC script file", "FAILURE", MB_OK );
        CurrentPageReset(NFC_TAB_RAW_DATA);
        fclose(fp);
        return;
    }

    fread(buffer, 1, fileLength, fp);

    fclose(fp);
    CurrentPageReset(NFC_TAB_RAW_DATA);

    btnNFC_RD_OpenScript->Enabled = true;
    sbNFCRawDataScriptStart->Enabled = true;
    sbNFCRawDataScriptStop->Enabled = false;

    sbNFC->Panels->Items[0]->Text = (AnsiString) "  Open NFC script successful";
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRawDataScriptStartClick(TObject *Sender)
{
    btnNFC_RD_OpenScript->Enabled = false;
    sbNFCRawDataScriptStart->Enabled = false;
    sbNFCRawDataScriptStop->Enabled = true;

    gbNFCTestMode->Enabled = false;
    sbNFCRawDataBack->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRawDataScriptStopClick(TObject *Sender)
{
    btnNFC_RD_OpenScript->Enabled = true;
    sbNFCRawDataScriptStart->Enabled = true;
    sbNFCRawDataScriptStop->Enabled = false;

    gbNFCTestMode->Enabled = true;
    sbNFCRawDataBack->Enabled = true;
}
//---------------------------------------------------------------------------
void TfrmNFC::NFCTestItemSelect(void)
{
    int item;
    for(item = 0; item < 9; item++)
    {
        if(rbNFC_Test[item]->Checked)
        {
            rbNFC_Test[item]->Font->Color = clRed;
        }
        else
        {
            rbNFC_Test[item]->Font->Color = clBlack;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCSettingNextClick(TObject *Sender)
{
    if(rbNFCSoftwareStack->Checked)
    {
        TabVisible(NFC_TAB_REGISTER_NOTIFICATION);
    }
    else
    {
        TabVisible(NFC_TAB_RAW_DATA);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRegisterNofificationBackClick(TObject *Sender)
{
    TabVisible(NFC_TAB_SETTING);
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRegisterNofificationNextClick(
    TObject *Sender)
{
    TabVisible(NFC_TAB_DISCOVERY_NOTIFICATION);
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCDiscoveryNotificationBackClick(TObject *Sender)
{
    TabVisible(NFC_TAB_REGISTER_NOTIFICATION);
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::sbNFCRawDataBackClick(TObject *Sender)
{
    TabVisible(NFC_TAB_SETTING);
}
//---------------------------------------------------------------------------
void TfrmNFC::TabVisible(E_NFC_TAB tab)
{
    if(tab & NFC_TAB_SETTING)
    {
        tsNFCSetting->TabVisible = true;
    }
    else
    {
        tsNFCSetting->TabVisible = false;
    }

    if(tab & NFC_TAB_REGISTER_NOTIFICATION)
    {
        tsNFCRegisterNotification->TabVisible = true;
    }
    else
    {
        tsNFCRegisterNotification->TabVisible = false;
    }

    if(tab & NFC_TAB_DISCOVERY_NOTIFICATION)
    {
        tsNFCDiscoveryNotification->TabVisible = true;
    }
    else
    {
        tsNFCDiscoveryNotification->TabVisible = false;
    }

    if(tab & NFC_TAB_RAW_DATA)
    {
        tsRawData->TabVisible = true;
    }
    else
    {
        tsRawData->TabVisible = false;
    }
}
//---------------------------------------------------------------------------
void TfrmNFC::CurrentPageLock(E_NFC_TAB nfc_tab)
{
    if(nfc_tab & NFC_TAB_SETTING)
    {
        gbNFCFeature->Enabled = false;
        gbNFCDebug->Enabled = false;
        gbNFCMode->Enabled = false;
        sbNFCSettingSet->Enabled = false;
        sbNFCSettingNext->Enabled = false;
    }
    else if(nfc_tab & NFC_TAB_REGISTER_NOTIFICATION)
    {
        gbNFCNofificationSetting->Enabled = false;
        gbNFCSecureElementSetMode->Enabled = false;
        sbNFCRegisterNofificationBack->Enabled = false;
        sbNFCRegisterNofificationNext->Enabled = false;

    }
    else if(nfc_tab & NFC_TAB_DISCOVERY_NOTIFICATION)
    {
        gbNFCDiscoveryNotification->Enabled = false;
        sbNFCDiscoveryNotificationBack->Enabled = false;
    }
    else if(nfc_tab & NFC_TAB_RAW_DATA)
    {
        gbNFCTestMode->Enabled = false;
        gbNFCRawData->Enabled = false;
        sbNFCRawDataBack->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void TfrmNFC::CurrentPageReset(E_NFC_TAB nfc_tab)
{
    if(nfc_tab & NFC_TAB_SETTING)
    {
        gbNFCFeature->Enabled = true;
        gbNFCDebug->Enabled = true;
        gbNFCMode->Enabled = true;
        sbNFCSettingSet->Enabled = true;
        sbNFCSettingNext->Enabled = true;
    }
    else if(nfc_tab & NFC_TAB_REGISTER_NOTIFICATION)
    {
        gbNFCNofificationSetting->Enabled = true;
        gbNFCSecureElementSetMode->Enabled = true;
        sbNFCRegisterNofificationBack->Enabled = true;
        sbNFCRegisterNofificationNext->Enabled = true;

    }
    else if(nfc_tab & NFC_TAB_DISCOVERY_NOTIFICATION)
    {
        gbNFCDiscoveryNotification->Enabled = true;
        sbNFCDiscoveryNotificationBack->Enabled = true;
    }
    else if(nfc_tab & NFC_TAB_RAW_DATA)
    {
        gbNFCTestMode->Enabled = true;
        gbNFCRawData->Enabled = true;
        sbNFCRawDataBack->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFC::FormShow(TObject *Sender)
{
    LOG("NFC form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

