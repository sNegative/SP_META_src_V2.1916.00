//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_RawCommand.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#ifndef  _MISC_H_
#include "misc.h"
#endif

#ifndef form_NFC_TagDetectedH
#include "form_NFC_TagDetected.h"
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

TfrmNFCRawCommand *frmNFCRawCommand;
extern char g_nfc_protocol[NFC_PROTOCOL_TYPE_NUM][20];
//---------------------------------------------------------------------------
__fastcall TfrmNFCRawCommand::TfrmNFCRawCommand(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCRawCommand::btnNFC_WriteClick(TObject *Sender)
{
    CurrentPageLock();
    char rawBuf[TAG_RAW_DATA_LEN * 2 + 1];
    int rawBufLength, rawBufLengthValid;
    NFC_TAGRAWCOMM_REQ_S nfc_tagrawcomm_req;
    NFC_TAGRAWCOMM_CNF_S nfc_tagrawcomm_cnf;

    nfc_tagrawcomm_req.action = 1;

    memset(rawBuf, 0, sizeof(rawBuf));
    rawBufLength = mmNFC_TD_RC->GetTextLen();
    if(rawBufLength > TAG_RAW_DATA_LEN * 2 + 1)
    {
        Application->MessageBox( "Execution Failure :The length of the raw data is too large!", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    rawBufLengthValid = rawBufLength;
    mmNFC_TD_RC->GetTextBuf(rawBuf, rawBufLength + 1);

    for(int i = 0; i < rawBufLengthValid + 1; i++)
    {
        if(' ' == rawBuf[i] || '\r' == rawBuf[i] || '\n' == rawBuf[i])
        {
            for(int j = i; j < rawBufLengthValid - 1; j++)
            {
                rawBuf[i] = rawBuf[i + 1];
            }
            rawBufLengthValid--;
        }
    }
    if(rawBufLengthValid < rawBufLength)
    {
        memset(rawBuf + rawBufLengthValid, 0, rawBufLength - rawBufLengthValid);
    }
    if(rawBufLengthValid % 2)
    {
        Application->MessageBox( "Execution Failure :The length of the raw data is wrong!", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    int nIndex = 1;
    for (int i = 0; i < rawBufLengthValid / 2; i++)
    {
        AnsiString strTemp = ((AnsiString)rawBuf).SubString(nIndex, 2);
        unsigned int tmpValue;
        if(!IsValidHexNFCData(strTemp,&tmpValue))
        {
            CurrentPageReset();
            return;
        }
        rawBuf[i] = (char)tmpValue;
        nIndex += 2;
    }

    memset(rawBuf + rawBufLengthValid / 2, 0, rawBufLengthValid / 2);

    nfc_tagrawcomm_req.length = rawBufLengthValid / 2;

    AnsiString cardType = frmNFCTagDetected->stNFC_TD_CardType->Caption;
    if(!strcmp(cardType.c_str(), g_nfc_protocol[2]))
    {
        nfc_tagrawcomm_req.req_data.req_data_typeA.length = nfc_tagrawcomm_req.length;
        memset(nfc_tagrawcomm_req.req_data.req_data_typeA.data, 0, sizeof(nfc_tagrawcomm_req.req_data.req_data_typeA.data));
        memcpy(nfc_tagrawcomm_req.req_data.req_data_typeA.data, rawBuf, nfc_tagrawcomm_req.length);
    }

    else if(!strcmp(cardType.c_str(), g_nfc_protocol[3]))
    {
        nfc_tagrawcomm_req.req_data.req_data_typeB.length = nfc_tagrawcomm_req.length;
        memset(nfc_tagrawcomm_req.req_data.req_data_typeB.data, 0, sizeof(nfc_tagrawcomm_req.req_data.req_data_typeB.data));
        memcpy(nfc_tagrawcomm_req.req_data.req_data_typeB.data, rawBuf, nfc_tagrawcomm_req.length);
    }

    else  if(!strcmp(cardType.c_str(), g_nfc_protocol[4]))
    {
        nfc_tagrawcomm_req.req_data.req_data_typeJewel.length = nfc_tagrawcomm_req.length;
        memset(nfc_tagrawcomm_req.req_data.req_data_typeJewel.data, 0, sizeof(nfc_tagrawcomm_req.req_data.req_data_typeJewel.data));
        memcpy(nfc_tagrawcomm_req.req_data.req_data_typeJewel.data, rawBuf, nfc_tagrawcomm_req.length);
    }
    else  if(!strcmp(cardType.c_str(), g_nfc_protocol[6]))
    {
        nfc_tagrawcomm_req.req_data.req_data_typeFelica.length = nfc_tagrawcomm_req.length;
        memset(nfc_tagrawcomm_req.req_data.req_data_typeFelica.data, 0, sizeof(nfc_tagrawcomm_req.req_data.req_data_typeFelica.data));
        memcpy(nfc_tagrawcomm_req.req_data.req_data_typeFelica.data, rawBuf, nfc_tagrawcomm_req.length);
    }

    META_RESULT MetaResult = SP_META_NFC_TagRawComm_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagrawcomm_req, &nfc_tagrawcomm_cnf);

    if( META_SUCCESS != MetaResult || nfc_tagrawcomm_cnf.status)
    {
        sbNFC_RawCommand->Panels->Items[0]->Text = (AnsiString)" NFC write raw command fail";
        Application->MessageBox( "Execution Failure :NFC write raw command", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    CurrentPageReset();
    sbNFC_RawCommand->Panels->Items[0]->Text = (AnsiString)" NFC write raw command successful";
}
//---------------------------------------------------------------------------
void TfrmNFCRawCommand::CurrentPageLock()
{
    mmNFC_TD_RC->Enabled = false;
    btnNFC_Write->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCRawCommand::CurrentPageReset()
{
    mmNFC_TD_RC->Enabled = true;
    btnNFC_Write->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCRawCommand::FormShow(TObject *Sender)
{
    LOG("NFCRawCommand form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

