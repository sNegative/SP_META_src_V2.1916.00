//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_NFC_TagAccessType2.h"
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

TfrmNFCTagAccessType2 *frmNFCTagAccessType2;
//---------------------------------------------------------------------------
__fastcall TfrmNFCTagAccessType2::TfrmNFCTagAccessType2(TComponent* Owner)
    : TForm(Owner)
{
//#if 0
    edtNFC_Byte[0] = edtNFC_Byte0;
    edtNFC_Byte[1] = edtNFC_Byte1;
    edtNFC_Byte[2] = edtNFC_Byte2;
    edtNFC_Byte[3] = edtNFC_Byte3;
    edtNFC_Byte[4] = edtNFC_Byte4;
    edtNFC_Byte[5] = edtNFC_Byte5;
    edtNFC_Byte[6] = edtNFC_Byte6;
    edtNFC_Byte[7] = edtNFC_Byte7;
    edtNFC_Byte[8] = edtNFC_Byte8;
    edtNFC_Byte[9] = edtNFC_Byte9;
    edtNFC_Byte[10] = edtNFC_Byte10;
    edtNFC_Byte[11] = edtNFC_Byte11;
    edtNFC_Byte[12] = edtNFC_Byte12;
    edtNFC_Byte[13] = edtNFC_Byte13;
    edtNFC_Byte[14] = edtNFC_Byte14;
    edtNFC_Byte[15] = edtNFC_Byte15;
//#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType2::btnNFC_ReadClick(TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGREAD_REQ_S nfc_tagread_req;
    NFC_TAGREAD_CNF_S nfc_tagread_cnf;

    memset(&nfc_tagread_req, 0, sizeof(nfc_tagread_req));

    nfc_tagread_req.read_type = 2;
    nfc_tagread_req.sector = cbNFC_Sector->ItemIndex;
    nfc_tagread_req.block = cbNFC_Block->ItemIndex;
    if(rbNFC_AuthKey_A->Checked)
    {
        nfc_tagread_req.AuthentificationKey = 0;
    }
    else
    {
        nfc_tagread_req.AuthentificationKey = 1;
    }

    META_RESULT MetaResult = SP_META_NFC_TagRead_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000,
                             &nfc_tagread_req, &nfc_tagread_cnf);
    if( META_SUCCESS != MetaResult || nfc_tagread_cnf.status)
    {
        sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag read fail";
        Application->MessageBox( "Execution Failure :NFC tag read", "FAILURE", MB_OK );
        CurrentPageReset();
        return;
    }

    for(int i = 0; i < MIFARE4K_LEN; i++)
    {
        edtNFC_Byte[i]->Text = IntToHex((int)nfc_tagread_cnf.nfc_read_data.nfc_Mifare4K_data.data[i], 2);
    }
    CurrentPageReset();
    sbNFC_TagAccess->Panels->Items[0]->Text = (AnsiString)" NFC tag read successful";
//#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCTagAccessType2::btnNFC_WriteClick(TObject *Sender)
{
//#if 0
    CurrentPageLock();
    NFC_TAGWRITE_REQ_S nfc_tagwrite_req;
    NFC_TAGWRITE_CNF_S nfc_tagwrite_cnf;

    memset(&nfc_tagwrite_req, 0, sizeof(nfc_tagwrite_req));

    nfc_tagwrite_req.write_type = 2;
    nfc_tagwrite_req.nfc_write_data.nfc_Mifare4K_data.sector = cbNFC_Sector->ItemIndex;
    nfc_tagwrite_req.nfc_write_data.nfc_Mifare4K_data.block = cbNFC_Block->ItemIndex;

    memset(nfc_tagwrite_req.nfc_write_data.nfc_Mifare4K_data.data, 0, sizeof(nfc_tagwrite_req.nfc_write_data.nfc_Mifare4K_data.data));
    for(int i = 0; i < MIFARE4K_LEN; i++)
    {
        AnsiString strTemp = edtNFC_Byte[i]->Text;
        unsigned int tmpValue;
        if(strTemp.IsEmpty() || strTemp.Length() > 2)
        {
            AnsiString str;
            str.sprintf("Execution Failure :The %d byte is wrong!", i);
            Application->MessageBox( str.c_str(), "FAILURE", MB_OK );
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
void __fastcall TfrmNFCTagAccessType2::rbNFC_AuthKey_AClick(
    TObject *Sender)
{
    rbNFC_AuthKey_A->Font->Color = clRed;
    rbNFC_AuthKey_B->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCTagAccessType2::rbNFC_AuthKey_BClick(
    TObject *Sender)
{
    rbNFC_AuthKey_A->Font->Color = clBlack;
    rbNFC_AuthKey_B->Font->Color = clRed;
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType2::CurrentPageLock()
{
    cbNFC_Sector->Enabled = false;
    cbNFC_Block->Enabled = false;
    rbNFC_AuthKey_A->Enabled = false;
    rbNFC_AuthKey_B->Enabled = false;
    for(int i = 0; i < MIFARE4K_LEN; i++)
    {
        edtNFC_Byte[i]->Enabled = false;
    }
    btnNFC_Read->Enabled = false;
    btnNFC_Write->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmNFCTagAccessType2::CurrentPageReset()
{
    cbNFC_Sector->Enabled = true;
    cbNFC_Block->Enabled = true;
    rbNFC_AuthKey_A->Enabled = true;
    rbNFC_AuthKey_B->Enabled = true;
    for(int i = 0; i < MIFARE4K_LEN; i++)
    {
        edtNFC_Byte[i]->Enabled = true;
    }
    btnNFC_Read->Enabled = true;
    btnNFC_Write->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNFCTagAccessType2::FormShow(TObject *Sender)
{
    LOG("NFCTagAccessType2 form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

