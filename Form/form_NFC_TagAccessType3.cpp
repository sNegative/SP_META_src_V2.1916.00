//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_TagAccessType3.h"

#ifndef  _MISC_H_
#include "misc.h"
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
TfrmNFCTagAccessType3 *frmNFCTagAccessType3;
char g_nfc_ndef_type[9][20] =
{
    "DEFAULT",
    "URI",
    "TEXT",
    "SMART_POSTER",
    "VCARD",
    "MEDIA",
    "AbsoluteURI",
    "ForumExternal",
    "OTHERS"
}
;
/*nfc_ndef_DEFAULT   = 0,
    nfc_ndef_URI       = 1,
    nfc_ndef_TEXT      = 2,
    nfc_ndef_SMART_POSTER = 3,
    nfc_ndef_VCARD     = 4,
    nfc_ndef_MEDIA     = 5,
    nfc_ndef_AbsoluteURI = 6,
    nfc_ndef_ForumExternal = 7,
    nfc_ndef_OTHERS    = 8 */

//---------------------------------------------------------------------------
__fastcall TfrmNFCTagAccessType3::TfrmNFCTagAccessType3(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType3::btnNFC_WriteClick(TObject *Sender)
{
    CurrentPageLock();
    char rawBuf[NDEF_DATA_LEN * 2 + 1];
    int rawBufLength, rawBufLengthValid;

    NFC_TAGWRITE_REQ_S nfc_tagwrite_req;
    NFC_TAGWRITE_CNF_S nfc_tagwrite_cnf;

    memset(&nfc_tagwrite_req, 0, sizeof(nfc_tagwrite_req));

    nfc_tagwrite_req.write_type = 3;
    for(int i=0; i < 9; i++)
    {
        AnsiString strTemp = stNFC_TD_RdTag_TagType->Caption;
        if(!strcmp(strTemp.c_str(), g_nfc_ndef_type[i]))
        {
            nfc_tagwrite_req.nfc_write_data.nfc_ndef_data.ndef_type = i;
            break;
        }
    }
    memset(rawBuf, 0, sizeof(rawBuf));
    rawBufLength = mmNFC_TD_WrTag->GetTextLen();
    if(rawBufLength > NDEF_DATA_LEN * 2 + 1)
    {
        Application->MessageBox( "Execution Failure :The length of the raw data is too large!", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }
    rawBufLengthValid = rawBufLength;
    mmNFC_TD_WrTag->GetTextBuf(rawBuf, rawBufLength + 1);

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
    nfc_tagwrite_req.nfc_write_data.nfc_ndef_data.length = rawBufLengthValid / 2;
    memcpy(nfc_tagwrite_req.nfc_write_data.nfc_ndef_data.data, rawBuf, nfc_tagwrite_req.nfc_write_data.nfc_ndef_data.length);

    META_RESULT MetaResult = SP_META_NFC_TagWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagwrite_req, &nfc_tagwrite_cnf);

    if( META_SUCCESS != MetaResult || nfc_tagwrite_cnf.status)
    {
        sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC write tag fail";
        Application->MessageBox( "Execution Failure :NFC write tag", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    CurrentPageReset();
    sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC write tag successful";
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType3::CurrentPageLock()
{
    mmNFC_TD_WrTag->Enabled = false;
    btnNFC_Write->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType3::CurrentPageReset()
{
    mmNFC_TD_WrTag->Enabled = true;
    btnNFC_Write->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType3::FormShow(TObject *Sender)
{
    LOG("NFCTagAccessType3 form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

