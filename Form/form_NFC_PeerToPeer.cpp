//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_PeerToPeer.h"

#ifndef form_NFCH
#include "form_NFC.h"
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
TfrmNFCPeerToPeer *frmNFCPeerToPeer;
//---------------------------------------------------------------------------
__fastcall TfrmNFCPeerToPeer::TfrmNFCPeerToPeer(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCPeerToPeer::btnNFC_P2P_SendClick(TObject *Sender)
{
    CurrentPageLock();
    NFC_P2PCOMM_REQ_S nfc_p2pcomm_req;
    NFC_P2PCOMM_CNF_S nfc_p2pcomm_cnf;

    memset(&nfc_p2pcomm_req, 0, sizeof(nfc_p2pcomm_req));
    nfc_p2pcomm_req.action = 1;
    AnsiString text = mmNFCP2PText->Text;
    nfc_p2pcomm_req.length = text.Length();
//    memcpy(nfc_p2pcomm_req.data, text.c_str(), nfc_p2pcomm_req.length);

    META_RESULT MetaResult = SP_META_NFC_P2PComm_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_p2pcomm_req, &nfc_p2pcomm_cnf);
    if( META_SUCCESS != MetaResult || nfc_p2pcomm_cnf.status)
    {
        sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC p2p send fail";
        Application->MessageBox( "Execution Failure :NFC p2p send", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
    sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC p2p send successful";
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCPeerToPeer::btnNFC_P2P_RecieveClick(TObject *Sender)
{
    CurrentPageLock();
    NFC_P2PCOMM_REQ_S nfc_p2pcomm_req;
    NFC_P2PCOMM_CNF_S nfc_p2pcomm_cnf;

    memset(&nfc_p2pcomm_req, 0, sizeof(nfc_p2pcomm_req));
    nfc_p2pcomm_req.action = 2;

    META_RESULT MetaResult = SP_META_NFC_P2PComm_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_p2pcomm_req, &nfc_p2pcomm_cnf);
    if( META_SUCCESS != MetaResult || nfc_p2pcomm_cnf.status)
    {
        sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC p2p recieve fail";
        Application->MessageBox( "Execution Failure :NFC p2p recieve", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
//    nfc_p2pcomm_cnf.data;
//    mmNFCP2PText->Text =
    sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC p2p recieve successful";
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCPeerToPeer::btnNFC_P2P_DisconnectClick(
    TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGDISCONNECT_REQ_S nfc_tagdisconnect_req;
    NFC_TAGDISCONNECT_CNF_S nfc_tagdisconnect_cnf;
    nfc_tagdisconnect_req.action = 1;

    META_RESULT MetaResult = SP_META_NFC_TagDisconnect_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagdisconnect_req, &nfc_tagdisconnect_cnf);
    if( META_SUCCESS != MetaResult || nfc_tagdisconnect_cnf.status)
    {
        sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC disconnect fail";
        Application->MessageBox( "Execution Failure :NFC disconnect", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
    sbNFC_PeerToPeer->Panels->Items[0]->Text = (AnsiString)" NFC disconnect successful";

    this->Visible = false;
    frmNFC->ShowModal();
    frmNFC->pcNFC->ActivePage = frmNFC->tsNFCDiscoveryNotification;
//#endif
}
//---------------------------------------------------------------------------
void TfrmNFCPeerToPeer::CurrentPageLock()
{
    mmNFCP2PText->Enabled = false;
    btnNFC_P2P_Send->Enabled = false;
    btnNFC_P2P_Recieve->Enabled = false;
    btnNFC_P2P_Disconnect->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCPeerToPeer::CurrentPageReset()
{
    mmNFCP2PText->Enabled = true;
    btnNFC_P2P_Send->Enabled = true;
    btnNFC_P2P_Recieve->Enabled = true;
    btnNFC_P2P_Disconnect->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCPeerToPeer::FormShow(TObject *Sender)
{
    LOG("NFCPeerToPeer form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

