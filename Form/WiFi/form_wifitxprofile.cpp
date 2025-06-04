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
 *   form_WiFiTxProfile.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi TX profile form source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// form
#include "form_WiFITxProfile.h"

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

// man
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

// misc
#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

// WiFi
#ifndef  _MT5911_COMMON_H_
#include "mt5911_common.h"
#endif
//---------------------------------------------------------------------------
typedef enum
{
    WIFI_CHANNEL_2412M = 0,
    WIFI_CHANNEL_2417M,
    WIFI_CHANNEL_2422M,
    WIFI_CHANNEL_2427M,
    WIFI_CHANNEL_2432M,
    WIFI_CHANNEL_2437M,
    WIFI_CHANNEL_2442M,
    WIFI_CHANNEL_2447M,
    WIFI_CHANNEL_2452M,
    WIFI_CHANNEL_2457M,
    WIFI_CHANNEL_2462M,
    WIFI_CHANNEL_2467M,
    WIFI_CHANNEL_2472M,
    WIFI_CHANNEL_2484M,
    WIFI_CHANNEL_2400M_COUNT       /* Total count */
} E_WIFI_CHANNEL_2400M;

typedef enum
{
    WIFI_CHANNEL_5040M = 0,
    WIFI_CHANNEL_5060M,
    WIFI_CHANNEL_5080M,
    WIFI_CHANNEL_5170M,
    WIFI_CHANNEL_5180M,
    WIFI_CHANNEL_5190M,
    WIFI_CHANNEL_5200M,
    WIFI_CHANNEL_5210M,
    WIFI_CHANNEL_5220M,
    WIFI_CHANNEL_5230M,
    WIFI_CHANNEL_5240M,
    WIFI_CHANNEL_5260M,
    WIFI_CHANNEL_5280M,
    WIFI_CHANNEL_5300M,
    WIFI_CHANNEL_5320M,
    WIFI_CHANNEL_5500M,
    WIFI_CHANNEL_5520M,
    WIFI_CHANNEL_5540M,
    WIFI_CHANNEL_5560M,
    WIFI_CHANNEL_5580M,
    WIFI_CHANNEL_5600M,
    WIFI_CHANNEL_5620M,
    WIFI_CHANNEL_5640M,
    WIFI_CHANNEL_5660M,
    WIFI_CHANNEL_5680M,
    WIFI_CHANNEL_5700M,
    WIFI_CHANNEL_5745M,
    WIFI_CHANNEL_5765M,
    WIFI_CHANNEL_5785M,
    WIFI_CHANNEL_5805M,
    WIFI_CHANNEL_4920M,
    WIFI_CHANNEL_4940M,
    WIFI_CHANNEL_4960M,
    WIFI_CHANNEL_4980M,
    WIFI_CHANNEL_5000M_COUNT       /* Total count */
} E_WIFI_CHANNEL_5000M;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFiTxProfile *frmWiFiTxProfile;

//---------------------------------------------------------------------------
static void  CNF_ReadTxPower2400MFromNVRAM( void )
{
    frmWiFiTxProfile->UploadTxPower2400MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_WriteTxPower2400MToNVRAM( void )
{
    frmWiFiTxProfile->DownloadTxPower2400MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_ReadTxPower5000MFromNVRAM( void )
{
    frmWiFiTxProfile->UploadTxPower5000MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_WriteTxPower5000MToNVRAM( void )
{
    frmWiFiTxProfile->DownloadTxPower5000MToFlashDone();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadAEE( void )
{
    frmWiFiTxProfile->ConfirmCallback_ReadEE();
}

//============================================================================
__fastcall TfrmWiFiTxProfile::TfrmWiFiTxProfile(TComponent* Owner)
    : TForm(Owner)
{
	  m_bInit =  false;
	  for(int i=0; i<NUM_TX_POWER_2400M_CH; i++)
	  {
	  	  edtCCKCHDAC[i] = NULL; 
	  	  edtOFDMCHDAC[i] = NULL; 
	  }
	  
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiTxProfile::FormCreate(TObject *Sender)
{
    edtCCKCHDAC[ 0] = edtCCKCHDAC00;
    edtCCKCHDAC[ 1] = edtCCKCHDAC01;
    edtCCKCHDAC[ 2] = edtCCKCHDAC02;
    edtCCKCHDAC[ 3] = edtCCKCHDAC03;
    edtCCKCHDAC[ 4] = edtCCKCHDAC04;
    edtCCKCHDAC[ 5] = edtCCKCHDAC05;
    edtCCKCHDAC[ 6] = edtCCKCHDAC06;
    edtCCKCHDAC[ 7] = edtCCKCHDAC07;
    edtCCKCHDAC[ 8] = edtCCKCHDAC08;
    edtCCKCHDAC[ 9] = edtCCKCHDAC09;
    edtCCKCHDAC[10] = edtCCKCHDAC0A;
    edtCCKCHDAC[11] = edtCCKCHDAC0B;
    edtCCKCHDAC[12] = edtCCKCHDAC0C;
    edtCCKCHDAC[13] = edtCCKCHDAC0D;

    edtOFDMCHDAC[ 0] = edtOFDMCHDAC00;
    edtOFDMCHDAC[ 1] = edtOFDMCHDAC01;
    edtOFDMCHDAC[ 2] = edtOFDMCHDAC02;
    edtOFDMCHDAC[ 3] = edtOFDMCHDAC03;
    edtOFDMCHDAC[ 4] = edtOFDMCHDAC04;
    edtOFDMCHDAC[ 5] = edtOFDMCHDAC05;
    edtOFDMCHDAC[ 6] = edtOFDMCHDAC06;
    edtOFDMCHDAC[ 7] = edtOFDMCHDAC07;
    edtOFDMCHDAC[ 8] = edtOFDMCHDAC08;
    edtOFDMCHDAC[ 9] = edtOFDMCHDAC09;
    edtOFDMCHDAC[10] = edtOFDMCHDAC0A;
    edtOFDMCHDAC[11] = edtOFDMCHDAC0B;
    edtOFDMCHDAC[12] = edtOFDMCHDAC0C;
    edtOFDMCHDAC[13] = edtOFDMCHDAC0D;

    Init();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//---------------------------------------------------------------------------
void TfrmWiFiTxProfile::Init( void )
{
    m_bInit          = true;
}

//------------------------------------------------------------------------------
void  TfrmWiFiTxProfile::ReDrawFields( void )
{
    int  i;
    char str[256];


    if( 0 == btnTxPowerDac->Tag ) // Dec
    {
        btnTxPowerDac->Caption = "TX Power DAC (Dec)";

        for(i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            edtCCKCHDAC[i]->Text  = IntToStr( m_sTxPwr2400M.CCKTxPWR[i] );
            edtOFDMCHDAC[i]->Text = IntToStr( m_sTxPwr2400M.OFDMTxPWR[i] );
        }
    }
    else
    {
        btnTxPowerDac->Caption = "TX Power DAC (Hex)";

        for(i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            sprintf( str, "%X", m_sTxPwr2400M.CCKTxPWR[i] );
            edtCCKCHDAC[i]->Text = str;
            sprintf( str, "%X", m_sTxPwr2400M.OFDMTxPWR[i] );
            edtOFDMCHDAC[i]->Text = str;
        }
    }
}

//---------------------------------------------------------------------------
bool  TfrmWiFiTxProfile::CheckFields( void )
{
    int  i;
    //unsigned short  usdata[NUM_TX_POWER_2400M_CH];

    AnsiString  text;

    for(i=0; i<NUM_TX_POWER_2400M_CH; i++)
    {
        // text = edtCHDAC[i]->Text;  if( !IsValidWiFiTxPowerDac( text, usdata[i] ) )         {  edtCHDACCheck(edtCHDAC[i]);   return(false);   }
    }

    return true;
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::CurrentPageReset( void )
{
    btnUploadFromFlash->Enabled = true;
    btnDownloadToFlash->Enabled = true;
    btnChangeDB->Enabled = true;
    btnLoadFromFile->Enabled = true;
    btnSaveToFile->Enabled = true;
    btnLoadFromEEPROM->Enabled = true;
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::CurrentPageLock( void )
{
    btnUploadFromFlash->Enabled = false;
    btnDownloadToFlash->Enabled = false;
    btnChangeDB->Enabled = false;
    btnLoadFromFile->Enabled = false;
    btnSaveToFile->Enabled = false;
    btnLoadFromEEPROM->Enabled = false;
}

//--------------------------------------------------------------------------
void  TfrmWiFiTxProfile::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiTxProfile::btnUploadFromFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
        if( ! NVRAMMan->Get_IsInit() )
        {
            sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
            Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
            return;
        }
        //stNVRAMDB->Caption = frmMainSel->Get_NVRAMDBFileName();
    }

    m_WIFI_TXP_Obj.ConfirmCallback = ::CNF_ReadTxPower2400MFromNVRAM;
    m_WIFI_TXP_Obj.REQ_Read_TxPower2400M_From_NVRAM_Start( );

    CurrentPageLock();
    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash progressing";
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::UploadTxPower2400MFromFlashDone( void )
{
    META_RESULT state = m_WIFI_TXP_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr2400M = m_WIFI_TXP_Obj.Get_TxChannelDac2400M();

        ReDrawFields();
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash successfully";
    }
    break;

    case META_FAILED:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload WiFi TX power from flash, please check 1. GSM850 support. 2. The version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash timeout";
        Application->MessageBox( "Execution Timeout : Upload WiFi TX power flash", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash stop";
        Application->MessageBox( "Execution Timeout : Upload WiFi TX power from flash", "STOP", MB_OK );
    }
    break;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::UploadTxPower5000MFromFlashDone( void )
{
    META_RESULT state = m_WIFI_TXP_Obj.Get_ConfirmState();
    //char  str[20];
    //float  fdata;



    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr5000M = m_WIFI_TXP_Obj.Get_TxChannelDac5000M();
        ReDrawFields();
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash successful";
    }
    break;

    case META_FAILED:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload WiFi TX power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload WiFi TX power setting", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting stop";
        CurrentPageReset();
    }
    break;
    }

}


//---------------------------------------------------------------------------
void __fastcall TfrmWiFiTxProfile::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::WIFI_APC_Obj( CWIFIAPC  *wifi_apc_obj )
{
    //m_pWIFI_APC_2400M_Obj = wifi_apc_2400m_obj;
}

void __fastcall TfrmWiFiTxProfile::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
        return;
    }

    strcpy( str, SaveDialog->FileName.c_str() );

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_TXP_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        ok = m_WIFI_TXP_Obj.REQ_Write_TxPower2400M_To_File( str );
        if( !ok )
        {
            sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
            Application->MessageBox( "Execution Failure : Save WiFi TX setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    // if( m_sWiFiCap.support_802_11a )
    // {
    //     m_WIFI_TXP_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
    //     ok = m_WIFI_TXP_Obj.REQ_Write_TxPower5000M_To_File( str );
    //     if( !ok )
    //     {
    //         sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
    //         Application->MessageBox( "Execution Failure : Save WiFi TX setting to file", "FAILURE", MB_OK );
    //         return;
    //     }
    // }

    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiTxProfile::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;
    //float  fdata;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );
    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        ok = m_WIFI_TXP_Obj.REQ_Read_TxPower2400M_From_File( str );
        if( ok )
        {
            m_sTxPwr2400M = m_WIFI_TXP_Obj.Get_TxChannelDac2400M();
        }
        else
        {
            sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
            Application->MessageBox( "Execution Failure : Load WiFi TX setting from file", "FAILURE", MB_OK );
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        ok = m_WIFI_TXP_Obj.REQ_Read_TxPower5000M_From_File( str );
        if( ok )
        {
            m_sTxPwr5000M = m_WIFI_TXP_Obj.Get_TxChannelDac5000M();
        }
        else
        {
            sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
            Application->MessageBox( "Execution Failure : Load WiFi TX setting from file", "FAILURE", MB_OK );
        }
    }


    ReDrawFields();
    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiTxProfile::btnChangeDBClick(TObject *Sender)
{
    frmMainSel->mnuFDMDatabaseClick(Sender);
    if( ! NVRAMMan->Get_IsInit() )
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
        return;
    }
    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Change NVRAM database file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiTxProfile::btnDownloadToFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_TXP_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        m_WIFI_TXP_Obj.ConfirmCallback = ::CNF_WriteTxPower2400MToNVRAM;
        m_WIFI_TXP_Obj.REQ_Write_TxPower2400M_To_NVRAM_Start();
    }
    //  else if( m_sWiFiCap.support_802_11a )
    //  {
    //      m_WIFI_TXP_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
    //      m_WIFI_TXP_Obj.ConfirmCallback = ::CNF_WriteTxPower5000MToNVRAM;
    //      m_WIFI_TXP_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
    //  }

    CurrentPageLock();
    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download WiFi TX power setting to flash progressing";
}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::DownloadTxPower2400MToFlashDone( void )
{
    META_RESULT state = m_WIFI_TXP_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        // if( m_sWiFiCap.support_802_11a )
        // {
        //     m_WIFI_TXP_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
        //     m_WIFI_TXP_Obj.ConfirmCallback = ::CNF_WriteTxPower5000MToNVRAM;
        //     m_WIFI_TXP_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
        // }
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download WiFi TX power setting to flash successfully";
        CurrentPageReset();
    }
    break;

    case META_FAILED:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download WiFi TX power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download WiFi TX power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download WiFi TX power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download WiFi TX power setting to flash", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download WiFi TX power setting to flash stop";
        CurrentPageReset();
    }
    break;
    }


}

//---------------------------------------------------------------------------
void  TfrmWiFiTxProfile::DownloadTxPower5000MToFlashDone( void )
{
    META_RESULT state = m_WIFI_TXP_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash successful";
    }
    break;

    case META_FAILED:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX channel power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();

    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX channel power setting to flash", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash stop";
        CurrentPageReset();
    }
    break;
    }


}

void __fastcall TfrmWiFiTxProfile::FormShow(TObject *Sender)
{
    if( m_bInit )
    {
        m_bInit = false;
        m_sWiFiCap = frmMainSel->Get_FinalWiFiCap();
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmWiFiTxProfile::btnTxPowerDacClick(TObject *Sender)
{
    if( 0 == btnTxPowerDac->Tag )  // Dec-->Hex
    {
        btnTxPowerDac->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTxPowerDac->Tag = 0;
    }
    ReDrawFields();
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFiTxProfile::edtCCKCHDACCheck(TObject *Sender)
{

    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~63 ";

    text = edit->Text;
    if( 0 == btnTxPowerDac->Tag )  // Dec
    {
        if( !IsValidDecWiFiTxPowerDac( text, uc_data ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiTxPowerDac( text, uc_data ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sTxPwr2400M.CCKTxPWR[edit->Tag] = uc_data;

}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFiTxProfile::edtOFDMCHDACCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~63 ";

    text = edit->Text;
    if( 0 == btnTxPowerDac->Tag )  // Dec
    {
        if( !IsValidDecWiFiTxPowerDac( text, uc_data ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiTxPowerDac( text, uc_data ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sTxPwr2400M.OFDMTxPWR[edit->Tag] = uc_data;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFiTxProfile::Compose_EEPROM_Parameter( void )
{

    m_sEE.count = 14;

    for (unsigned int i=0; i<m_sEE.count; i++)
    {
        m_sEE.eeprom[i].index = ADDR_MT5911_EEPROM_2_4G_CCK_TX_POWER + i;
    }
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFiTxProfile::btnLoadFromEEPROMClick(TObject *Sender)
{
    CurrentPageLock();

    Compose_EEPROM_Parameter();

    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );

    sbWiFiTXP->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM progressing";
}

//-----------------------------------------------
void TfrmWiFiTxProfile::ConfirmCallback_ReadEE( void )
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiTxPowerEEToNVRAM();
        ReDrawFields();
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM fail";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiTXP->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM stop";
    }
    break;
    }
    CurrentPageReset();
}

//--------------------------------------------------------------------------
void TfrmWiFiTxProfile::WiFiTxPowerEEToNVRAM( void )
{
    int i;
    for(i=0; i<NUM_TX_POWER_2400M_CH/2; i++)
    {
        m_sTxPwr2400M.CCKTxPWR[2*i]   = (unsigned char) m_sEE.eeprom[i].eeprom_data16 & 0x00FF;
        m_sTxPwr2400M.CCKTxPWR[2*i+1] = (unsigned char) ((m_sEE.eeprom[i].eeprom_data16 & 0xFF00)>>8);
    }

    for(i=0; i<NUM_TX_POWER_2400M_CH/2; i++)
    {
        m_sTxPwr2400M.OFDMTxPWR[2*i]   = (unsigned char) m_sEE.eeprom[i+NUM_TX_POWER_2400M_CH/2].eeprom_data16 & 0x00FF ;
        m_sTxPwr2400M.OFDMTxPWR[2*i+1] = (unsigned char) ((m_sEE.eeprom[i+NUM_TX_POWER_2400M_CH/2].eeprom_data16 & 0xFF00)>>8);
    }
}
