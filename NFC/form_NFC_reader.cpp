//---------------------------------------------------------------------------

#include <vcl.h>    
#include <stdio.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include "form_NFC_reader.h"

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_AIRM_Reader *form_AIRM_Reader;
//---------------------------------------------------------------------------
__fastcall Tform_AIRM_Reader::Tform_AIRM_Reader(TComponent* Owner)
        : TForm(Owner)
{
        m_module_status = 0;
}
//---------------------------------------------------------------------------
void Tform_AIRM_Reader::displayReadModule(bool isVisible)
{
        tb_AIRM_NTF_Read->Visible = isVisible;
        gb_AIRM_Reader_read->Visible = isVisible;
}

void Tform_AIRM_Reader::displayWriteModule(bool isVisible)
{
        tb_AIRM_NTF_Write->Visible = isVisible;
        gb_AIRM_Reader_write->Visible = isVisible;
}

void Tform_AIRM_Reader::displayFormatToNDEF(bool isVisible)
{
        gb_AIRM_Reader_format->Visible = isVisible;
}

void __fastcall Tform_AIRM_Reader::tb_AIRM_NTF_WriteClick(TObject *Sender)
{
        LOG("entry tb_AIRM_NTF_WriteClick\n");
        memset(&m_readm_opt_req, 0, sizeof(m_readm_opt_req));
        memset(&m_readm_opt_cnf, 0, sizeof(m_readm_opt_cnf));
        m_readm_opt_req.action = NFC_EM_OPT_ACT_WRITE;
        if(true == rb_AIRM_NTF_Write_tagType_URI->Checked)
        {       
                LOG("entry rb_AIRM_NTF_Write_tagType_URI\n");
                AnsiString URI = te_AIRM_NTF_Write_tagType_Text->Text;
                m_readm_opt_req.ndef_write.ndef_type = nfc_ndef_type_uri;
                m_readm_opt_req.ndef_write.ndef_data.URL_Data.URLLength = URI.Length();
                memcpy(m_readm_opt_req.ndef_write.ndef_data.URL_Data.URLData, URI.c_str(), URI.Length());
        }
        else if(true == rb_AIRM_NTF_Write_tagType_Text->Checked)
        {     
                LOG("entry rb_AIRM_NTF_Write_tagType_Text\n");
                AnsiString Text = te_AIRM_NTF_Write_tagType_Text->Text;
                m_readm_opt_req.ndef_write.ndef_type = nfc_ndef_type_text;
                m_readm_opt_req.ndef_write.ndef_data.TX_Data.DataLength = Text.Length();
                memcpy(m_readm_opt_req.ndef_write.ndef_data.TX_Data.data, Text.c_str(), Text.Length());
        }
        LOG("before SP_META_NFC_EM_Als_Reader_Mode_OPT_r\n");
        META_RESULT MetaResult = SP_META_NFC_Em_Als_Reader_Mode_OPT_r(m_META_HANDLE_Obj.Get_MainHandle(),
                10000, &m_readm_opt_req, &m_readm_opt_cnf); 
        LOG("After SP_META_NFC_EM_Als_Reader_Mode_OPT_r\n");
        if ( (META_SUCCESS == MetaResult) && (m_readm_opt_cnf.result == 0) )
        {
                Application->MessageBoxA("Write OK!", "Message", MB_OK);
        }
        else
        {
                Application->MessageBoxA("Write Fail!", "Error", MB_OK);
        }
        te_AIRM_NTF_Write_tagType_Text->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall Tform_AIRM_Reader::tb_AIRM_NTF_ReadClick(TObject *Sender)
{
        memset(&m_readm_opt_req, 0, sizeof(m_readm_opt_req));
        memset(&m_readm_opt_cnf, 0, sizeof(m_readm_opt_cnf));
        m_readm_opt_req.action = NFC_EM_OPT_ACT_READ;
        resetUI();
        META_RESULT MetaResult = SP_META_NFC_Em_Als_Reader_Mode_OPT_r(m_META_HANDLE_Obj.Get_MainHandle(),
                10000, &m_readm_opt_req, &m_readm_opt_cnf);
        if ( META_SUCCESS == MetaResult )
        {
                if(0 == m_readm_opt_cnf.result)
                {
                        char temp[512] = {0};
                        sprintf(temp, "%02x", m_readm_opt_cnf.ndef_read.recordFlags);
                        te_AIRM_Reader_recordFlag->Text = temp;
                        for(int i = 0, j = 0; i < 3; i++)
                        {
                                LOG("m_readm_opt_cnf.ndef_read.lang[%d]:%02x\n", i, m_readm_opt_cnf.ndef_read.lang[i]);
                                sprintf(temp+j, "%02x", m_readm_opt_cnf.ndef_read.lang[i]);
                                j += 2;
                        }
                        te_AIRM_Reader_lang->Text = temp;
                        for(int i = 0, j = 0; i < 32; i++)
                        {
                                LOG("m_readm_opt_cnf.ndef_read.recordId[%d]=%02x\n", i, m_readm_opt_cnf.ndef_read.recordId[i]);
                                sprintf(temp+j, "%02x", m_readm_opt_cnf.ndef_read.recordId[i]);
                                j += 2;
                        }
                        te_AIRM_Reader_recordID->Text = temp;
                        LOG("m_readm_opt_cnf.ndef_read.recordTnf=%02x", m_readm_opt_cnf.ndef_read.recordTnf);
                        sprintf(temp, "%02x", m_readm_opt_cnf.ndef_read.recordTnf);
                        te_AIRM_Reader_recordInfo->Text = temp;
                        te_AIRM_Reader_payloadLength->Text = IntToStr(m_readm_opt_cnf.ndef_read.length);
                        for(int i = 0; i < m_readm_opt_cnf.ndef_read.length; i++)
                        {
                                LOG("m_readm_opt_cnf.ndef_read.data[%d]=%c\n", i, m_readm_opt_cnf.ndef_read.data[i]);
                                sprintf(temp+i, "%c", m_readm_opt_cnf.ndef_read.data[i]);
                        }
                        te_AIRM_Reader_payloadASCII->Text = temp;
                        String b;
                        for(int i = 0; i < m_readm_opt_cnf.ndef_read.length; i++)
                        {
                                LOG("te_AIRM_Reader_payloadASCII->Text=%s\n", b);
                                b += IntToHex(m_readm_opt_cnf.ndef_read.data[i], 2)+" ";
                        }
                        te_AIRM_Reader_payloadHEX->Text = b;
                        
                        if(nfc_ndef_type_uri == m_readm_opt_cnf.ndef_read.ndef_type)
                        {
                                cb_AIRM_Reader_tagType_URI->Checked = true;
                        }
                        else if(nfc_ndef_type_text == m_readm_opt_cnf.ndef_read.ndef_type)
                        {
                                cb_AIRM_Reader_tagType_Text->Checked = true;
                        }
                        else
                        {
                                cb_AIRM_Reader_tagType_SmartPoster->Checked = true;
                        }
                        
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall Tform_AIRM_Reader::rb_AIRM_NTF_Write_tagType_TextClick(
      TObject *Sender)
{
        Label17->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tform_AIRM_Reader::rb_AIRM_NTF_Write_tagType_URIClick(
      TObject *Sender)
{
        Label17->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall Tform_AIRM_Reader::tb_AIRM_Reader_formatToNDEFClick(
      TObject *Sender)
{
        memset(&m_readm_opt_req, 0, sizeof(m_readm_opt_req));
        memset(&m_readm_opt_cnf, 0, sizeof(m_readm_opt_cnf));
        m_readm_opt_req.action = NFC_EM_OPT_ACT_FORMAT;
        META_RESULT MetaResult = SP_META_NFC_Em_Als_Reader_Mode_OPT_r(m_META_HANDLE_Obj.Get_MainHandle(),
                10000, &m_readm_opt_req, &m_readm_opt_cnf);
        if ( META_SUCCESS == MetaResult )
        {
                Application->MessageBoxA("Format OK!", "Message", MB_OK);
        }
        else
        {
                Application->MessageBoxA("Format Fail!", "Error", MB_OK);
        }  
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void Tform_AIRM_Reader::resetUI()
{

       te_AIRM_Reader_recordFlag->Text = "";
       te_AIRM_Reader_recordID->Text = "";
       te_AIRM_Reader_recordInfo->Text = "";
       te_AIRM_Reader_payloadLength->Text = "";
       cb_AIRM_Reader_tagType_URI->Checked = false; 
       cb_AIRM_Reader_tagType_Text->Checked = false;
       cb_AIRM_Reader_tagType_SmartPoster->Checked = false;
       te_AIRM_Reader_lang->Text = "";
       te_AIRM_Reader_payloadHEX->Text = ""; 
       te_AIRM_Reader_payloadASCII->Text = "";
       te_AIRM_NTF_Write_tagType_Text->Text = "";
}

//---------------------------------------------------------------------------

