//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_TagDetected.h"

#ifndef form_NFC_TagAccessType1H
#include "form_NFC_TagAccessType1.h"
#endif

#ifndef form_NFC_TagAccessType2H
#include "form_NFC_TagAccessType2.h"
#endif

#ifndef form_NFC_TagAccessType3H
#include "form_NFC_TagAccessType3.h"
#endif

#ifndef form_NFC_RawCommandH
#include "form_NFC_RawCommand.h"
#endif

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
TfrmNFCTagDetected *frmNFCTagDetected;

extern char g_nfc_protocol[NFC_PROTOCOL_TYPE_NUM][20];
//---------------------------------------------------------------------------
__fastcall TfrmNFCTagDetected::TfrmNFCTagDetected(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagDetected::btnNFC_TD_RdWrClick(TObject *Sender)
{
    AnsiString cardType =  stNFC_TD_CardType->Caption;

    if(!strcmp(cardType.c_str(), g_nfc_protocol[0]))
    {
        frmNFCTagAccessType1->ShowModal();
    }
    else if(!strcmp(cardType.c_str(), g_nfc_protocol[1]))
    {
        frmNFCTagAccessType2->ShowModal();
    }
    else  if(!strcmp(cardType.c_str(), g_nfc_protocol[8]))
    {
        frmNFCTagAccessType3->ShowModal();
    }
    else
    {
        frmNFCRawCommand->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCTagDetected::btnNFC_TD_RawCommandClick(
    TObject *Sender)
{
    frmNFCRawCommand->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TfrmNFCTagDetected::btnNFC_TD_FormatToNDEFClick(
    TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGFORMAT2NDEF_REQ_S nfc_tagformat2ndef_req;
    NFC_TAGFORMAT2NDEF_CNF_S nfc_tagformat2ndef_cnf;

    nfc_tagformat2ndef_req.action =1;

    META_RESULT MetaResult = SP_META_NFC_TagFormatNDEF_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagformat2ndef_req, &nfc_tagformat2ndef_cnf);

    if( META_SUCCESS != MetaResult || nfc_tagformat2ndef_cnf.status)
    {
        sbNFC_TagDetected->Panels->Items[0]->Text = (AnsiString)" NFC Format To Be NDEF Compliant fail";
        Application->MessageBox( "Execution Failure :NFC Format To Be NDEF Compliant", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    CurrentPageReset();
    sbNFC_TagDetected->Panels->Items[0]->Text = (AnsiString)" NFC Format To Be NDEF Compliant successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagDetected::btnNFC_TD_DisconnectClick(
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
        sbNFC_TagDetected->Panels->Items[0]->Text = (AnsiString)" NFC disconnect fail";
        Application->MessageBox( "Execution Failure :NFC disconnect", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    sbNFC_TagDetected->Panels->Items[0]->Text = (AnsiString)" NFC disconnect successful";

    CurrentPageReset();
    this->Visible = false;

    frmNFC->ShowModal();
    frmNFC->pcNFC->ActivePage = frmNFC->tsNFCDiscoveryNotification;
//#endif
}
//---------------------------------------------------------------------------
void TfrmNFCTagDetected::CurrentPageLock()
{
    btnNFC_TD_RdWr->Enabled = false;
    btnNFC_TD_RawCommand->Enabled = false;
    btnNFC_TD_FormatToNDEF->Enabled = false;
    btnNFC_TD_Disconnect->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCTagDetected::CurrentPageReset()
{
    if(0 == btnNFC_TD_RdWr->Tag)
    {
        btnNFC_TD_RdWr->Enabled = true;
    }
    if(0 == btnNFC_TD_RawCommand->Tag)
    {
        btnNFC_TD_RawCommand->Enabled = true;
    }
    btnNFC_TD_FormatToNDEF->Enabled = true;
    btnNFC_TD_Disconnect->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagDetected::FormShow(TObject *Sender)
{
    LOG("NFCTagDetected form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------
