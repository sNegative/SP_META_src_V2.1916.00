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
 *   form_GetVersion.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Get version form source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 25 2005 11:54:04  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Form/form_GetVersion.cpp-arc  $
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.11   Oct 25 2005 14:14:24   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.10   Sep 04 2005 11:05:20   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.9   Apr 18 2005 15:48:18   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.8   Jan 30 2005 17:56:04   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.7   Jan 10 2005 11:12:12   mtk00490
 * 1. Automatic BB chip and external clock rate detection
 * 2. Support baud rate 57600 (for FPGA test)
 * 3. RF tool
 * a.Trim IQ, offset IQ sweep (get phase error, original offset, IQ imbalance information from equipment)
 * 4. Audio
 * a.Acoustic FIR tuning and melody FIR tuning integrate with AFTDLL.dll (provide freqz and firls function, user does not to install MATLAB for FIR tuning)
 * 5. Update parameter
 * a.add barcode and IMEI read/write
 * 6. Factory
 * a.support DCS, PCS, GSM850 AFC calibration
 * b.phase error calibration
 * c.user configurable current limit
 * d.add APC DAC to result file
 * e.add AFC_BAND, AFC_ARFCN to TCVCXO AFC CFG editor
 * f.add CURRENT_LIMIT to ADC CFG editor
 * g.add phase error CFG editor
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#include "form_GetVersion.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGetVersion *frmGetVersion;
static void CNF_GetTargetVersion( void )
{
    frmGetVersion->CNF_GetTargetVersion();
}
static void CNF_ReadUUID(void)
{
    frmGetVersion->CNF_ReadUUID();
}
static void CNF_WriteUUID(void)
{
    frmGetVersion->CNF_WriteUUID();
}
//---------------------------------------------------------------------------
__fastcall TfrmGetVersion::TfrmGetVersion(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TfrmGetVersion::btnGetTargetVersionClick(TObject *Sender)
{
    GET_VERSION_Object.ConfirmCallback = ::CNF_GetTargetVersion;
    GET_VERSION_Object.GetTargetVersion();
}

//---------------------------------------------------------------------------
void TfrmGetVersion::CNF_GetTargetVersion(void)
{
    int state = GET_VERSION_Object.Get_ConfirmState();

    if( state==STATE_GET_VERSION_OK )
    {
        GET_VERSION_Object.Get_VerInfo( VerInfo );
        ReDrawFields();
    }
    else  if( state==STATE_GET_VERSION_FAIL )
    {
        Application->MessageBox( "Execution Failure : Get target version", "FAILURE", MB_OK );
    }
    else  if( state==STATE_GET_VERSION_TIMEOUT )
    {
        Application->MessageBox( "Execution Timeout : Get target version", "TIMEOUT", MB_OK );
    }
    else  if( state==STATE_GET_VERSION_STOP )
    {
    }

}

//=========================================================================
void __fastcall TfrmGetVersion::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;
    //float  fdata;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Load version information from file fail";
        Application->MessageBox( "Execution Failure : Load version information from file", "FAILURE", MB_OK );
        return;
    }

    strcpy( str, OpenDialog->FileName.c_str() );
    ok = GET_VERSION_Object.REQ_Read_From_File( str );
    if( ok )
    {
        GET_VERSION_Object.Get_VerInfo( VerInfo );
        ReDrawFields();
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Load version information from file successful";
    }
    else
    {
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Load version information from file fail";
        Application->MessageBox( "Execution Failure : Load version information from file", "FAILURE", MB_OK );
    }

}

//---------------------------------------------------------------------------
void __fastcall TfrmGetVersion::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Save TXIQ setting to file fail";
        Application->MessageBox( "Execution Failure : Save TXIQ setting to file", "FAILURE", MB_OK );
        return;
    }

    strcpy( str, SaveDialog->FileName.c_str() );
    GetFields();
    GET_VERSION_Object.Set_VerInfo( VerInfo );
    ok = GET_VERSION_Object.REQ_Write_To_File( str );
    if( !ok )
    {
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Save TXIQ setting to file fail";
        Application->MessageBox( "Execution Failure : Save TXIQ setting to file", "FAILURE", MB_OK );
    }
    else
    {
        sbVersion->Panels->Items[0]->Text = (AnsiString) "  Save TXIQ setting to file successfully";
    }
}

//==========================================================================
void TfrmGetVersion::ReDrawFields(void)
{
    stBBChipVersion->Caption      = VerInfo.BB_CHIP;
    stECOVersion->Caption         = VerInfo.ECO_VER;
    stDSPFirmwareVersion->Caption = VerInfo.DSP_FW;
    stDSPPatchVersion->Caption    = VerInfo.DSP_PATCH;
    stSWVersion->Caption          = VerInfo.SW_VER;
    stHWVersion->Caption          = VerInfo.HW_VER;
    stMelodyVersion->Caption      = VerInfo.MELODY_VER;
}

//---------------------------------------------------------------------------
void TfrmGetVersion::GetFields(void)
{
    stBBChipVersion->Caption      = (AnsiString) VerInfo.BB_CHIP;
    stECOVersion->Caption         = (AnsiString) VerInfo.ECO_VER;
    stDSPFirmwareVersion->Caption = (AnsiString) VerInfo.DSP_FW;
    stDSPPatchVersion->Caption    = (AnsiString) VerInfo.DSP_PATCH;
    stSWVersion->Caption          = (AnsiString) VerInfo.SW_VER;
    stHWVersion->Caption          = (AnsiString) VerInfo.HW_VER;
    stMelodyVersion->Caption      = (AnsiString) VerInfo.MELODY_VER;
}
/*//---------------------------------------------------------------------------
void TfrmGetVersion::ResetFields(void)
{
    stBBChipVersion->Caption      = "";
    stECOVersion->Caption         = "";
    stDSPFirmwareVersion->Caption = "";
    stDSPPatchVersion->Caption    = "";
    stSWVersion->Caption          = "";
    stHWVersion->Caption          = "";
    stMelodyVersion->Caption      = "";
}                */

void TfrmGetVersion::ShowHintLabel(TControl *sender, char* hint)
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x-30);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

void __fastcall TfrmGetVersion::edtUUIDCheck(TObject *Sender)
{
    unsigned char  data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char hint[] = "value shall be 0x0~0xF";

    text = edit->Text;
    if( !IsValidUUID( text, data ) )
    {
        ShowHintLabel( edit, hint );
        //edit->Clear();
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGetVersion::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGetVersion::bnUUIDReadClick(TObject *Sender)
{
    CurrentPageLock();
    UUID_Op_Object.ConfirmCallback = ::CNF_ReadUUID;
    UUID_Op_Object.ReadUUID();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGetVersion::bnUUIDWriteClick(TObject *Sender)
{
    CurrentPageLock();
    UUID_Op_Object.ConfirmCallback = ::CNF_WriteUUID;
    unsigned int high = GetUUIDHigh();
    unsigned int low = GetUUIDLow();
    UUID_Op_Object.WriteUUID(high,low);
}
//---------------------------------------------------------------------------
void TfrmGetVersion::CNF_ReadUUID(void)
{
    CurrentPageReset();
    int state = UUID_Op_Object.Get_ConfirmState();

    if( state==STATE_READ_UUID_OK )
    {
        ShowUUID(UUID_Op_Object.GetUUIDHigh(),UUID_Op_Object.GetUUIDLow());
        Application->MessageBox( "Execution Success : Read UUID Succeed", "SUCCESS", MB_OK );
    }
    else  if( state==STATE_READ_UUID_TIMEOUT )
    {
        Application->MessageBox( "Execution Timeout : Read UUID Timeout", "TIMEOUT", MB_OK );
    }
    else  if( state==STATE_READ_UUID_STOP )
    {
        Application->MessageBox( "Execution Stop : Read UUID Stop", "STOP", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution Failure : Read UUID Failed", "FAILURE", MB_OK );
    }
}
//------------------------------------------------------------------------------
void TfrmGetVersion::CNF_WriteUUID(void)
{
    CurrentPageReset();
    int state = UUID_Op_Object.Get_ConfirmState();

    if( state==STATE_WRITE_UUID_OK )
    {
        /*UINT high = UUID_Op_Object.GetUUIDHigh();
        UINT low = UUID_Op_Object.GetUUIDLow();
        ShowUUID(high,low);*/
        Application->MessageBox( "Execution Success : Write UUID Succeed", "SUCCESS", MB_OK );
    }
    else  if( state==STATE_READ_UUID_TIMEOUT )
    {
        Application->MessageBox( "Execution Timeout : Write UUID Timeout", "TIMEOUT", MB_OK );
    }
    else  if( state==STATE_READ_UUID_STOP )
    {
        Application->MessageBox( "Execution Stop : Write UUID Stop", "STOP", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution Failure : Write UUID Failed", "FAILURE", MB_OK );
    }
}

//------------------------------------------------------------------------------
unsigned int TfrmGetVersion::GetUUIDHigh(void)
{
    unsigned int high = 0;
    unsigned char  data;

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh1->Text,data,0,15);
    high = (high & 0x0FFF) | ((data & 0xF)<<28);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh2->Text,data,0,15);
    high = (high & 0xF0FF) | ((data & 0xF)<<24);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh3->Text,data,0,15);
    high = (high & 0xFF0F) | ((data & 0xF)<<20);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh4->Text,data,0,15);
    high = (high & 0xFFF0) | ((data & 0xF)<<16);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh5->Text,data,0,15);
    high = (high & 0x0FFF) | ((data & 0xF)<<12);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh6->Text,data,0,15);
    high = (high & 0xF0FF) | ((data & 0xF)<<8);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh7->Text,data,0,15);
    high = (high & 0xFF0F) | ((data & 0xF)<<4);

    AnsiString_Hex_To_UnsignedChar(edUUIDHigh8->Text,data,0,15);
    high = (high & 0xFFF0) | (data & 0xF);

    return high;
}

//------------------------------------------------------------------------------
unsigned int TfrmGetVersion::GetUUIDLow(void)
{
    unsigned int low = 0;
    unsigned char  data = 0;

    AnsiString_Hex_To_UnsignedChar(edUUIDLow1->Text,data,0,15);
    low = (low & 0x0FFF) | ((data & 0xF)<<28);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow2->Text,data,0,15);
    low = (low & 0xF0FF) | ((data & 0xF)<<24);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow3->Text,data,0,15);
    low = (low & 0xFF0F) | ((data & 0xF)<<20);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow4->Text,data,0,15);
    low = (low & 0xFFF0) | ((data & 0xF)<<16);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow5->Text,data,0,15);
    low = (low & 0x0FFF) | ((data & 0xF)<<12);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow6->Text,data,0,15);
    low = (low & 0xF0FF) | ((data & 0xF)<<8);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow7->Text,data,0,15);
    low = (low & 0xFF0F) | ((data & 0xF)<<4);

    AnsiString_Hex_To_UnsignedChar(edUUIDLow8->Text,data,0,15);
    low = (low & 0xFFF0) | (data & 0xF);


    return low;
}

//------------------------------------------------------------------------------
void TfrmGetVersion::ShowUUID(const unsigned int high,const unsigned int low)
{
    char str[20];

    sprintf( str, "%X", (high & 0xF000) >> 28 );
    edUUIDHigh1->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0x0F00) >>  24 );
    edUUIDHigh2->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0x00F0) >>  20 );
    edUUIDHigh3->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0x000F) >>  16);
    edUUIDHigh4->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0xF000) >> 12 );
    edUUIDHigh5->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0x0F00) >>  8 );
    edUUIDHigh6->Text = (AnsiString) str;
    sprintf( str, "%X", (high & 0x00F0) >>  4 );
    edUUIDHigh7->Text = (AnsiString) str;
    sprintf( str, "%X", high & 0x000F );
    edUUIDHigh8->Text = (AnsiString) str;

    sprintf( str, "%X", (low & 0xF000) >> 28 );
    edUUIDLow1->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0x0F00) >>  24 );
    edUUIDLow2->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0x00F0) >>  20 );
    edUUIDLow3->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0x000F) >>  16);
    edUUIDLow4->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0xF000) >> 12 );
    edUUIDLow5->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0x0F00) >>  8 );
    edUUIDLow6->Text = (AnsiString) str;
    sprintf( str, "%X", (low & 0x00F0) >>  4 );
    edUUIDLow7->Text = (AnsiString) str;
    sprintf( str, "%X", low & 0x000F );
    edUUIDLow8->Text = (AnsiString) str;

}

//------------------------------------------------------------------------------
void TfrmGetVersion::CurrentPageLock(void)
{
    bnUUIDRead->Enabled = false;
    bnUUIDWrite->Enabled = false;
}

//------------------------------------------------------------------------------
void TfrmGetVersion::CurrentPageReset(void)
{
    bnUUIDRead->Enabled = true;
    bnUUIDWrite->Enabled = true;
}
void __fastcall TfrmGetVersion::FormShow(TObject *Sender)
{
    LOG("Get Version form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------
