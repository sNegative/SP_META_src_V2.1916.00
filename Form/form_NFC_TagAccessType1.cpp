//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_TagAccessType1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#ifndef  _MISC_H_
#include "misc.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif
TfrmNFCTagAccessType1 *frmNFCTagAccessType1;
//---------------------------------------------------------------------------
__fastcall TfrmNFCTagAccessType1::TfrmNFCTagAccessType1(TComponent* Owner)
    : TForm(Owner)
{
    edtNFC_Byte[0] = edtNFC_Byte0;
    edtNFC_Byte[1] = edtNFC_Byte1;
    edtNFC_Byte[2] = edtNFC_Byte2;
    edtNFC_Byte[3] = edtNFC_Byte3;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType1::btnNFC_ReadClick(TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGREAD_REQ_S nfc_tagread_req;
    NFC_TAGREAD_CNF_S nfc_tagread_cnf;

    memset(&nfc_tagread_req, 0, sizeof(nfc_tagread_req));

    nfc_tagread_req.read_type = 1;
    nfc_tagread_req.address = cbNFC_PageAddress->ItemIndex;

    META_RESULT MetaResult = SP_META_NFC_TagRead_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagread_req, &nfc_tagread_cnf);
    if( META_SUCCESS != MetaResult || nfc_tagread_cnf.status)
    {
        sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag read fail";
        Application->MessageBox( "Execution Failure :NFC tag read", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    CurrentPageReset();
    sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag read successful";
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType1::btnNFC_WriteClick(TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGWRITE_REQ_S nfc_tagwrite_req;
    NFC_TAGWRITE_CNF_S nfc_tagwrite_cnf;

    memset(&nfc_tagwrite_req, 0, sizeof(nfc_tagwrite_req));

    nfc_tagwrite_req.write_type = 1;
    nfc_tagwrite_req.nfc_write_data.nfc_Mifare1K_data.address = cbNFC_PageAddress->ItemIndex;

    memset(nfc_tagwrite_req.nfc_write_data.nfc_Mifare1K_data.data, 0, sizeof(nfc_tagwrite_req.nfc_write_data.nfc_Mifare1K_data.data));
    for(int i = 0; i < MIFARE1K_LEN; i++)
    {
        AnsiString strTemp = edtNFC_Byte[i]->Text;
        unsigned int tmpValue;
        if(strTemp.IsEmpty() || strTemp.Length() > 2)
        {
            Application->MessageBox( "Execution Failure :The 0 byte is wrong!", "FAILURE", MB_OK );
            CurrentPageReset();
            return;
        }
        if(!IsValidHexNFCData(strTemp, &tmpValue))
        {
            CurrentPageReset();
            return;
        }
        nfc_tagwrite_req.nfc_write_data.nfc_Mifare1K_data.data[i] = (unsigned short)tmpValue;
    }

    META_RESULT MetaResult = SP_META_NFC_TagWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagwrite_req, &nfc_tagwrite_cnf);
    if( META_SUCCESS != MetaResult || nfc_tagwrite_cnf.status)
    {
        sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag write fail";
        Application->MessageBox( "Execution Failure :NFC tag write", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    CurrentPageReset();
    sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag write successful";
//#endif
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType1::CurrentPageLock()
{
    cbNFC_PageAddress->Enabled = false;

    for(int i = 0; i < MIFARE1K_LEN; i++)
    {
        edtNFC_Byte[i]->Enabled = false;
    }
    btnNFC_Read->Enabled = false;
    btnNFC_Write->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType1::CurrentPageReset()
{
    cbNFC_PageAddress->Enabled = true;

    for(int i = 0; i < MIFARE1K_LEN; i++)
    {
        edtNFC_Byte[i]->Enabled = true;
    }
    btnNFC_Read->Enabled = true;
    btnNFC_Write->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType1::FormShow(TObject *Sender)
{
    LOG("NFCTagAccessType1 form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

