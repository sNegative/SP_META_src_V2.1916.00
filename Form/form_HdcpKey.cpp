/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   form_Hdcpkey.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   HDCP Key Tool main form source file.
 *
 * Author:
 * -------
 *  Rongguo Zhang (mtk80761)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 16 2012 11:45:30  $
 * $Log:    $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

//Man
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_Main.h"
#endif

#ifndef _FORM_HDCP_H_
#include "form_HdcpKey.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHdcpKey *frmHdcpKey;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
static void CNF_ReadFromNVRAM_HDCP( void )
{
    frmHdcpKey->UploadFromFlashDone_HDCP();
}
//---------------------------------------------------------------------------
static void CNF_WriteToNVRAM_HDCP( void )
{
    frmHdcpKey->DownloadToFlashDone_HDCP();
}
//---------------------------------------------------------------------------
__fastcall TfrmHdcpKey::TfrmHdcpKey(TComponent* Owner)
    : TForm(Owner)
{
    memset(&m_sHDCPNvramStruct,       0, sizeof(m_sHDCPNvramStruct));
    memset(&m_sHDCPNvramStruct_NVRAM, 0, sizeof(m_sHDCPNvramStruct_NVRAM));
    memset(&m_sHDCPNvramStruct_File,  0, sizeof(m_sHDCPNvramStruct_File));
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::FormShow(TObject *Sender)
{
    LOG("HDCP Key Tool form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::btnHDCPSetChangeDBClick(TObject *Sender)
{
    bool ok;
    ok = m_dlgOpenDB->Execute();
    if( !ok )
    {
        return;
    }
    
    frmMainSel->OpenDatabaseCommon(m_dlgOpenDB->FileName.c_str());

    if (!NVRAMMan->Get_IsInit())
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization failed";
        return;
    }

    btnUploadHDCPFromFlash->Enabled = true;
    m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Change NVRAM database successfully";
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::btnUploadHDCPFromFlashClick(TObject *Sender)
{
    if (!NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if (!NVRAMMan->Get_IsInit())
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
        return;
    }

    m_HDCP_Nvram_Object.ConfirmCallback = ::CNF_ReadFromNVRAM_HDCP;
    m_HDCP_Nvram_Object.REQ_Read_From_NVRAM();

    m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Upload HDCP NVRAM value from flash progressing";
}
//---------------------------------------------------------------------------
void TfrmHdcpKey::UploadFromFlashDone_HDCP(void)
{
    int state = m_HDCP_Nvram_Object.Get_ConfirmState();

    if( state == META_SUCCESS )
    {
        m_HDCP_Nvram_Object.Get_HDCPValue(&m_sHDCPNvramStruct);
        memcpy(&m_sHDCPNvramStruct_NVRAM, &m_sHDCPNvramStruct, sizeof(m_sHDCPNvramStruct));
        ReDrawHDCPFields();

        btnDownloadHDCPToFlash->Enabled = true;
        btnLoadHDCPFromFile->Enabled = true;
//        btnHDCPVerify->Enabled = true;
        
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Upload HDCP NVRAM value from flash successfully";
    }
    else if( state==META_FAILED )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Upload HDCP NVRAM value from flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload HDCP NVRAM value form flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    else  if( state==META_TIMEOUT )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Upload HDCP NVRAM value from flash timeout";
        Application->MessageBox( "Execution Timeout : Upload HDCP NVRAM value form flash", "TIMEOUT", MB_OK );
    }
    else  if( state==METAAPP_STOP )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Upload HDCP NVRAM value from flash stop";
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::btnDownloadHDCPToFlashClick(TObject *Sender)
{
    if (!NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(NULL);
    }

    if (!NVRAMMan->Get_IsInit())
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization failed";
        Application->MessageBox("Execution Failure : NVRAM database file initialize", "FAILURE", MB_OK);
        return;
    }

    m_HDCP_Nvram_Object.Set_HDCPValue(m_sHDCPNvramStruct);

    m_HDCP_Nvram_Object.ConfirmCallback = ::CNF_WriteToNVRAM_HDCP;
    m_HDCP_Nvram_Object.REQ_Write_To_NVRAM();

    m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Download HDCP NVRAM value to flash progressing";
}
//---------------------------------------------------------------------------
void TfrmHdcpKey::DownloadToFlashDone_HDCP(void)
{
    int state = m_HDCP_Nvram_Object.Get_ConfirmState();

    if( state == META_SUCCESS )
    {
        memcpy(&m_sHDCPNvramStruct_NVRAM, &m_sHDCPNvramStruct, sizeof(m_sHDCPNvramStruct));
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Download HDCP NVRAM value to flash successfully";
    }
    else  if( state == META_FAILED )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Download HDCP NVRAM value to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download HDCP NVRAM value to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    else  if( state == META_TIMEOUT )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Download HDCP NVRAM value to flash timeout";
        Application->MessageBox( "Execution Timeout : Download HDCP NVRAM value to flash", "TIMEOUT", MB_OK );
    }
    else  if( state == METAAPP_STOP )
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Download HDCP NVRAM value to flash stop";
    }
}
//---------------------------------------------------------------------------
void TfrmHdcpKey::ReDrawHDCPFields(void)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::btnLoadHDCPFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = m_dlgOpenHDCPKeyFile->Execute();
    if (!ok)
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Load HDCP Key value from file fail";
        Application->MessageBox( "Execution Failure : Load HDCP Key value from file", "FAILURE", MB_OK );
        return;
    }

    strcpy(str, m_dlgOpenHDCPKeyFile->FileName.c_str());
    ok = m_HDCP_Nvram_Object.REQ_Read_HDCP_Key_File(str);
    if (ok)
    {
        m_HDCP_Nvram_Object.Get_HDCPValue(&m_sHDCPNvramStruct);
        memcpy(&m_sHDCPNvramStruct_File, &m_sHDCPNvramStruct, sizeof(m_sHDCPNvramStruct));
        btnHDCPVerify->Enabled = true;
        ReDrawHDCPFields();
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Load HDCP Key value from file successfully";
    }
    else
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Load HDCP Key value from file fail";
        Application->MessageBox( "Execution Failure : Load HDCP Key value from file", "FAILURE", MB_OK );
    }

    DialogInitialDir::SetInitialDir(m_dlgOpenHDCPKeyFile->FileName, m_dlgOpenHDCPKeyFile, DIALOG_TYPE_OPEN);    
}
//---------------------------------------------------------------------------
void __fastcall TfrmHdcpKey::btnHDCPVerifyClick(TObject *Sender)
{
    if(0 == memcmp(&m_sHDCPNvramStruct_File, &m_sHDCPNvramStruct_NVRAM, sizeof(m_sHDCPNvramStruct)))
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Verify success";
        Application->MessageBox( "Verify success", "NOTICE", MB_OK );
    }
    else
    {
        m_sbHDCPMain->Panels->Items[0]->Text = (AnsiString) "  Verify fail";
        Application->MessageBox( "Verify fail", "FAILURE", MB_OK );
    }
}
//---------------------------------------------------------------------------
