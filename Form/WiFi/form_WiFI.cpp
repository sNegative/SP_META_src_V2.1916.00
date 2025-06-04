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
 *   form_WiFi.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi form source
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
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
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
//--------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// form
#ifndef _FORM_WiFI_H_
#include "form_WiFI.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#ifndef  _FORM_WIFITXPROFILE_H_
#include "form_wifitxprofile.h"
#endif

#ifndef _FORM_WIFIALC2400M_H_
#include "form_WiFiALC2400M.h"
#endif

#ifndef _FORM_WIFIBBCR_H_
#include "form_wifibbcr.h"
#endif

#ifndef _FORM_WIFIMCR_H_
#include "form_wifimcr.h"
#endif

#ifndef _FORM_WIFIEEPROM_H_
#include "form_WiFiEEPROM.h"
#endif

// WiFi
#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _MT5911_COMMON_H_
#include "mt5911_common.h"
#endif

// man
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif



// Misc.
#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#define WIFI_DBM_MAX    0
#define WIFI_DBM_0      1
#define WIFI_DBM_5      2
#define WIFI_DBM_10     3

// bit pattern
#define WIFI_IDX_ALL_0      0
#define WIFI_IDX_ALL_1      1
#define WIFI_IDX_ALTERNATE  2
#define WIFI_IDX_RANDOM     3

enum
{
    PAGEIDX_TXALL=0,
    PAGEIDX_CPRX,
    PAGEIDX_PS,
    PAGEIDX_BB,
    PAGEIDX_MAC,
    PAGEIDX_EE,
    PAGEIDX_SC,
    PAGEIDX_NONE

};

enum
{
    TYPEIDX_CPTX=0,
    TYPEIDX_TXOP,
    TYPEIDX_TXCS,
    TYPEIDX_LF
};

enum
{
    IDX_TX_FILTER_NORTH_AMERICA=0,
    IDX_TX_FILTER_JAPAN
};





















































//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFi *frmWiFi;
extern bool g_bHideEnable;
//===========================================================================
void ConfirmCallback_QueryChannelList( void )
{
    frmWiFi->ConfirmCallback_QueryChannelList();
}

//--------------------------------------------------------------------------
static void ConfirmCallback_CPT( void )
{
    frmWiFi->ConfirmCallback_CPT();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_QueryTxStatus( void )
{
    frmWiFi->ConfirmCallback_QueryTxStatus();
}

//---------------------------------------------------------------------------
static void CNF_CPTX_ReadTxPower2400MFromNVRAM( void )
{
    frmWiFi->CPTX_UploadTxPower2400MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_CPTX_WriteTxPower2400MToNVRAM( void )
{
    frmWiFi->CPTX_DownloadTxPower2400MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_CPTX_ReadTxPower5000MFromNVRAM( void )
{
    frmWiFi->CPTX_UploadTxPower5000MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_ReadTxDCFromNVRAM( void )
{
    frmWiFi->UploadTxDCFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_CPTX_WriteTxPower5000MToNVRAM( void )
{
    frmWiFi->CPTX_DownloadTxPower5000MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_TXOP_ReadTxPower2400MFromNVRAM( void )
{
    frmWiFi->TXOP_UploadTxPower2400MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_TXOP_WriteTxPower2400MToNVRAM( void )
{
    frmWiFi->TXOP_DownloadTxPower2400MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_TXOP_ReadTxPower5000MFromNVRAM( void )
{
    frmWiFi->TXOP_UploadTxPower5000MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_TXOP_WriteTxPower5000MToNVRAM( void )
{
    frmWiFi->TXOP_DownloadTxPower5000MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_WriteTxDCToNVRAM( void )
{
    frmWiFi->DownloadTxDCToFlashDone();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_CPRX( void )
{
    frmWiFi->ConfirmCallback_CPRX();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_QueryOriRxStatus( void )
{
    frmWiFi->ConfirmCallback_QueryOriRxStatus();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_QueryRxStatus( void )
{
    frmWiFi->ConfirmCallback_QueryRxStatus();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_QueryRxCounter( void )
{
    frmWiFi->ConfirmCallback_QueryRxCounter();
}

//---------------------------------------------------------------------------
static void  ConfirmCallback_TxDcOffsetCal( void )
{
    frmWiFi->ConfirmCallback_TxDcOffsetCal();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_TXOP( void )
{
    frmWiFi->ConfirmCallback_TXOP();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_TXCS( void )
{
    frmWiFi->ConfirmCallback_TXCS();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_LF( void )
{
    frmWiFi->ConfirmCallback_LF();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_PS( void )
{
    frmWiFi->ConfirmCallback_PS();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadBBReg( void )
{
    frmWiFi->ConfirmCallback_ReadBBReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadAllBBReg( void )
{
    frmWiFi->ConfirmCallback_ReadAllBBReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_WriteBBReg( void )
{
    frmWiFi->ConfirmCallback_WriteBBReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadMACReg( void )
{
    frmWiFi->ConfirmCallback_ReadMACReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadAllMACReg( void )
{
    frmWiFi->ConfirmCallback_ReadAllMACReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_WriteMACReg( void )
{
    frmWiFi->ConfirmCallback_WriteMACReg();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadEE( void )
{
    frmWiFi->ConfirmCallback_ReadEE();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadAllEE( void )
{
    frmWiFi->ConfirmCallback_ReadAllEE();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_WriteEE( void )
{
    frmWiFi->ConfirmCallback_WriteEE();
}

//---------------------------------------------------------------------------
static void CNF_TXOP_SetDbmToDac( void )
{
    frmWiFi->CNF_TXOP_SetDbmToDac();
}

//---------------------------------------------------------------------------
static void  CNF_TXOP_QueryDbmToDac( void )
{
    frmWiFi->CNF_TXOP_QueryDbmToDac();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_SC( void )
{
    frmWiFi->ConfirmCallback_SC();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadTxPowerFromEE( void )
{
    frmWiFi->ConfirmCallback_ReadTxPowerFromEE();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_ReadTxDcOffsetFromEE( void )
{
    frmWiFi->ConfirmCallback_ReadTxDcOffsetFromEE();
}
//===========================================================================
__fastcall TfrmWiFi::TfrmWiFi(TComponent* Owner)
    : TForm(Owner)
{
    Init();
    m_bFirstCPTXShow = true;
    m_bFirstCPRXShow = true;
    m_bFirstTXOPShow = true;
    m_bFirstTXCSShow = true;
    m_bFirstLFShow   = true;
    m_bFirstCSShow   = true;
    m_bFirstBBShow   = true;
    m_bFirstMACShow  = true;

    // TX
    edtTXFramCtrl[0] = edtTXFramCtrl0;
    edtTXDuration[0] = edtTXDuration0;
    edtTXSeqCtrl[0] = edtTXSeqCtrl0;
    edtTXFramCtrl[1] = edtTXFramCtrl1;
    edtTXDuration[1] = edtTXDuration1;
    edtTXSeqCtrl[1] = edtTXSeqCtrl1;



    edtTXAddress1[0] = edtTXAddress10;
    edtTXAddress2[0] = edtTXAddress20;
    edtTXAddress3[0] = edtTXAddress30;
    edtTXAddress1[1] = edtTXAddress11;
    edtTXAddress2[1] = edtTXAddress21;
    edtTXAddress3[1] = edtTXAddress31;
    edtTXAddress1[2] = edtTXAddress12;
    edtTXAddress2[2] = edtTXAddress22;
    edtTXAddress3[2] = edtTXAddress32;
    edtTXAddress1[3] = edtTXAddress13;
    edtTXAddress2[3] = edtTXAddress23;
    edtTXAddress3[3] = edtTXAddress33;
    edtTXAddress1[4] = edtTXAddress14;
    edtTXAddress2[4] = edtTXAddress24;
    edtTXAddress3[4] = edtTXAddress34;
    edtTXAddress1[5] = edtTXAddress15;
    edtTXAddress2[5] = edtTXAddress25;
    edtTXAddress3[5] = edtTXAddress35;

    // Continuous packet RX
    stCPRSum[0]  = stCPR1MSum;
    stCPRGood[0]  = stCPR1MGood;
    stCPRBad[0]  = stCPR1MBad;
    stCPRFer[0]  = stCPR1MFer;
    stCPRSum[1]  = stCPR2MSum;
    stCPRGood[1]  = stCPR2MGood;
    stCPRBad[1]  = stCPR2MBad;
    stCPRFer[1]  = stCPR2MFer;
    stCPRSum[2]  = stCPR5_5MSum;
    stCPRGood[2]  = stCPR5_5MGood;
    stCPRBad[2]  = stCPR5_5MBad;
    stCPRFer[2]  = stCPR5_5MFer;
    stCPRSum[3]  = stCPR11MSum;
    stCPRGood[3]  = stCPR11MGood;
    stCPRBad[3]  = stCPR11MBad;
    stCPRFer[3]  = stCPR11MFer;
    stCPRSum[4]  = stCPR6MSum;
    stCPRGood[4]  = stCPR6MGood;
    stCPRBad[4]  = stCPR6MBad;
    stCPRFer[4]  = stCPR6MFer;
    stCPRSum[5]  = stCPR9MSum;
    stCPRGood[5]  = stCPR9MGood;
    stCPRBad[5]  = stCPR9MBad;
    stCPRFer[5]  = stCPR9MFer;
    stCPRSum[6]  = stCPR12MSum;
    stCPRGood[6]  = stCPR12MGood;
    stCPRBad[6]  = stCPR12MBad;
    stCPRFer[6]  = stCPR12MFer;
    stCPRSum[7]  = stCPR18MSum;
    stCPRGood[7]  = stCPR18MGood;
    stCPRBad[7]  = stCPR18MBad;
    stCPRFer[7]  = stCPR18MFer;
    stCPRSum[8]  = stCPR24MSum;
    stCPRGood[8]  = stCPR24MGood;
    stCPRBad[8]  = stCPR24MBad;
    stCPRFer[8]  = stCPR24MFer;
    stCPRSum[9]  = stCPR36MSum;
    stCPRGood[9]  = stCPR36MGood;
    stCPRBad[9]  = stCPR36MBad;
    stCPRFer[9]  = stCPR36MFer;
    stCPRSum[10] = stCPR48MSum;
    stCPRGood[10] = stCPR48MGood;
    stCPRBad[10] = stCPR48MBad;
    stCPRFer[10] = stCPR48MFer;
    stCPRSum[11] = stCPR54MSum;
    stCPRGood[11] = stCPR54MGood;
    stCPRBad[11] = stCPR54MBad;
    stCPRFer[11] = stCPR54MFer;

    m_pvBBCRDisp  = NULL;
    m_pvMCRDisp   = NULL;
    m_pvMCR16Disp = NULL;
    m_pvEEDisp    = NULL;
    
    m_final_WiFiId = 0;
    m_iTestPageIndex = 0;
    m_iLastPageIndex = 0;
    m_uiBBCount = 0;
    m_uiBBIdx = 0;
    m_ucBBValue = 0;
    m_uiBBBeginIdx = 0;
    m_uiBBEndIdx = 0;
    m_uiMACCount = 0;
    m_uiMacAddr = 0;
    m_uiMacBeginAddr = 0;
    m_uiMacEndAddr = 0;
    m_uiMacData = 0;
    m_usMac16Data = 0;
    m_uiEEPROMCount = 0;
    m_uiEEPROMIdx = 0;
    m_uiEEPROMBeginIdx = 0;
    m_uiEEPROMEndIdx = 0;
    m_usEEPROMData = 0;
    m_pSCLog = NULL;
    m_bAlcSupport = false;


    WindowProc = SubClassWndProc;
}

//---------------------------------------------------------------------------
void TfrmWiFi::Init( void )
{
    m_bInit          = true;
}

//==============================================================================
void _fastcall TfrmWiFi::SubClassWndProc( Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
    case WM_ML_WIFI_PRINT_MSG:
    {
        FillSCResult();
    }
    break;

    default:
        this->WndProc( Message );
        break;
    }
}

//==========================================================================
////////////////////////////   Form event handler   ////////////////////////
//==========================================================================
void __fastcall TfrmWiFi::FormCreate(TObject *Sender)
{
    // Initialize
    m_uiBBIdx = 0;
    m_ucBBValue = 0;
    m_uiBBBeginIdx = 0;
    m_uiBBEndIdx = 0;

    m_uiMacAddr = 0;
    m_uiMacBeginAddr = 0;
    m_uiMacEndAddr = 0;
    m_uiMacData = 0;
    m_usMac16Data = 0;

    // eeprom
    m_uiEEPROMIdx = 0;
    m_uiEEPROMBeginIdx = 0;
    m_uiEEPROMEndIdx = 0;
    m_usEEPROMData = 0;

    m_iTestPageIndex = PAGEIDX_NONE;
    m_iLastPageIndex = pctlToolSel->ActivePageIndex;

    // dynamic allocate
    m_pSCLog = new TStringList;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::FormDestroy(TObject *Sender)
{
    delete m_pSCLog;

    DeAllocateBBCRVector();
    DeAllocateMCRVector();
    DeAllocateMCR16Vector();
    DeAllocateEEPROMVector();

}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::FormShow(TObject *Sender)
{
    ApplyHideProperty();
    frmWiFiTxProfile->WIFI_APC_Obj(&m_WIFI_APC_Obj);
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::ToggleHideExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;

    ApplyHideProperty();
}

//---------------------------------------------------------------------------
void TfrmWiFi::ApplyHideProperty( void )
{
    bool visible = g_bHideEnable ? false : true;
    btnBBRegSetting->Visible = visible;
    btnMACRegSetting->Visible = visible;
    btnEEPROMSetting->Visible = visible;
    tsSC->Visible = visible;
    tsSC->TabVisible = visible;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::pctlToolSelChange(TObject *Sender)
{
    if( PAGEIDX_NONE != m_iTestPageIndex )
    {
        if(m_iTestPageIndex != pctlToolSel->ActivePageIndex &&
                PAGEIDX_BB       != pctlToolSel->ActivePageIndex &&
                PAGEIDX_MAC      != pctlToolSel->ActivePageIndex &&
                PAGEIDX_EE       != pctlToolSel->ActivePageIndex
          )
        {
            pctlToolSel->ActivePageIndex = m_iLastPageIndex;
            Application->MessageBox( "Cannot change page because test is progressing", "Notice", MB_OK );
            return;
        }
    }

    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_TXALL:
    {
        // if( ! m_bFirstCPTXShow )
        // {
        //     m_bFirstCPTXShow = false;
        //    Display_CPTXChannelId();
        // }
    }
    break;

    case PAGEIDX_CPRX:

        break;


    case PAGEIDX_PS:
        break;


    case PAGEIDX_BB:
        break;


    case PAGEIDX_MAC:
        break;

    case PAGEIDX_EE:
        break;
    }

    m_iLastPageIndex = pctlToolSel->ActivePageIndex;
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ReDrawFields( int page_idx )
{
    switch( page_idx )
    {
    case PAGEIDX_TXALL:
        ReDrawTXFields();
        break;

    case PAGEIDX_CPRX:

        break;

    case PAGEIDX_PS:
        break;


    case PAGEIDX_BB:
        ReDrawBBFields();
        break;


    case PAGEIDX_MAC:
        ReDrawMACFields();
        break;

    case PAGEIDX_EE:
        ReDrawEEFields();
        break;

    case PAGEIDX_SC:
        break;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::ReDrawTXFields(void)
{
    char  str[256];
    E_WIFI_GENERATION wifi_802_11_idx;
    unsigned int chan_idx;

    if(! GetWiFiChannelIndexFromStr( cbTXChannelID->Text, cbTXTxRate->Text, wifi_802_11_idx, chan_idx ) )
    {
        return;
    }

    if( 0 == btnTXTxPowerDac->Tag )  // Dec
    {
        btnTXTxPowerDac->Caption = "TX power DAC (Dec)";
        lblTXTxPowerDac0X->Visible = false;
        if( WIFI_802_11A_IDX == wifi_802_11_idx )
        {
            edtTXTxPowerDAC->Text = IntToStr( m_sTxPwr5000M.TxPWR[chan_idx] );
        }
        else if( WIFI_802_11B_IDX == wifi_802_11_idx )
        {
            edtTXTxPowerDAC->Text = IntToStr( m_sTxPwr2400M.CCKTxPWR[chan_idx] );
        }
        else  // 802.11G
        {
            edtTXTxPowerDAC->Text = IntToStr( m_sTxPwr2400M.OFDMTxPWR[chan_idx] );
        }
    }
    else  // Hex
    {
        btnTXTxPowerDac->Caption = "TX power DAC (Hex)";
        lblTXTxPowerDac0X->Visible = true;
        if( WIFI_802_11A_IDX == wifi_802_11_idx )
        {
            sprintf( str, "%X", (int)m_sTxPwr5000M.TxPWR[chan_idx] );
        }
        else if( WIFI_802_11B_IDX == wifi_802_11_idx )
        {
            sprintf( str, "%X", (int)m_sTxPwr2400M.CCKTxPWR[chan_idx] );
        }
        else // 802.11G
        {
            sprintf( str, "%X", (int)m_sTxPwr2400M.OFDMTxPWR[chan_idx] );
        }
        edtTXTxPowerDAC->Text = str;
    }

    // TX DC offset
    if( 0 == btnTXIDC->Tag )  // Dec
    {
        btnTXIDC->Caption = "I_DC (Dec)";
        lblTXIDC0x->Visible = false;
        edtTXIDC->Text = IntToStr( m_sTxDcOffset.i_ch_offset );
    }
    else  // Hex
    {
        btnTXIDC->Caption = "I_DC (Hex)";
        lblTXIDC0x->Visible = true;
        sprintf( str, "%X", (int)m_sTxDcOffset.i_ch_offset );
        edtTXIDC->Text = str;
    }

    if( 0 == btnTXQDC->Tag )  // Dec
    {
        btnTXQDC->Caption = "Q_DC (Dec)";
        lblTXQDC0x->Visible = false;
        edtTXQDC->Text = IntToStr( m_sTxDcOffset.q_ch_offset );
    }
    else  // Hex
    {
        btnTXQDC->Caption = "Q_DC (Hex)";
        lblTXQDC0x->Visible = true;
        sprintf( str, "%X", (int)m_sTxDcOffset.q_ch_offset );
        edtTXQDC->Text = str;
    }

}

//---------------------------------------------------------------------------
void  TfrmWiFi::ReDrawTXOPFields( void )
{
#if 0
    char  str[256];
    E_WIFI_GENERATION wifi_802_11_idx;
    unsigned int chan_idx;

    if(! GetWiFiChannelIndexFromStr( cbTXOPChannelID->Text, cbTXOPTXRate->Text, wifi_802_11_idx, chan_idx ) )
    {
        return;
    }

    if( 0 == btnTXOPTxPowerDac->Tag )  // Dec
    {
        btnTXOPTxPowerDac->Caption = "TX power DAC (Dec)";
        lblTXOPTxPowerDac0X->Visible = false;
        if( WIFI_802_11A_IDX == wifi_802_11_idx )
        {
            edtTXOPTxPowerDAC->Text = m_sTxPwr5000M.TxPWR[chan_idx];
        }
        else if( WIFI_802_11B_IDX == wifi_802_11_idx )
        {
            edtTXOPTxPowerDAC->Text = m_sTxPwr2400M.CCKTxPWR[chan_idx];
        }
        else
        {
            edtTXOPTxPowerDAC->Text = m_sTxPwr2400M.OFDMTxPWR[chan_idx];
        }
    }
    else  // Hex
    {
        btnTXOPTxPowerDac->Caption = "TX power DAC (Hex)";
        lblTXOPTxPowerDac0X->Visible = true;
        if( WIFI_802_11A_IDX == wifi_802_11_idx )
        {
            sprintf( str, "%X", (int)m_sTxPwr5000M.TxPWR[chan_idx] );
        }
        else if( WIFI_802_11B_IDX == wifi_802_11_idx )
        {
            sprintf( str, "%X", (int)m_sTxPwr2400M.CCKTxPWR[chan_idx] );
        }
        else  // 802.11g
        {
            sprintf( str, "%X", (int)m_sTxPwr2400M.OFDMTxPWR[chan_idx] );
        }
        edtTXOPTxPowerDAC->Text = str;
    }
#endif
}
//---------------------------------------------------------------------------
void  TfrmWiFi::ReDrawBBFields( void )
{
    char  str[256];

    //sprintf(str, "%08lx", m_ucBBAddr);
    //sprintf(str, "%04lx", m_ucBBAddr);
    //edtBBCRIndex->Text = str;
    edtBBCRIndex->Text = m_uiBBIdx;
    if( 0 == btnBBCRData->Tag )  // Dec
    {
        btnBBCRData->Caption = "CR Data (Dec)";
        lblBBCRData0X->Visible = false;
        edtBBCRData->Text = m_ucBBValue;
    }
    else  // Hex
    {
        btnBBCRData->Caption = "CR Data (Hex)";
        lblBBCRData0X->Visible = true;
        sprintf( str, "%X", (int)m_ucBBValue );
        edtBBCRData->Text = str;
    }
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ReDrawMACFields( void )
{
    char  str[256];

    //sprintf(str, "%08lx", m_ucBBAddr);
    sprintf(str, "%04lx", m_uiMacAddr);
    edtMACMCRAddress->Text = str;
    if( btnMACMCRData->Tag==0 )  // Dec
    {
        btnMACMCRData->Caption = "CR Data (Dec)";
        lblMACMCRData0X->Visible = false;
        if( rbMAC16bits->Checked )
        {
            edtMACMCRData->Text = m_usMac16Data;
        }
        else
        {
            edtMACMCRData->Text = m_uiMacData;
        }
    }
    else  // Hex
    {
        btnMACMCRData->Caption = "CR Data (Hex)";
        lblMACMCRData0X->Visible = true;
        if( rbMAC16bits->Checked )
        {
            sprintf( str, "%X", m_usMac16Data );
        }
        else
        {
            sprintf( str, "%X", m_uiMacData );
        }
        edtMACMCRData->Text = str;
    }
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ReDrawEEFields( void )
{
    char  str[256];

    sprintf(str, "%04lx", m_uiEEPROMIdx);
    // sprintf(str, "%04lx", m_sEE.eeprom[0].index);
    edtEEIndex->Text = str;
    if( 0 == btnEEData->Tag )  // Dec
    {
        btnEEData->Caption = "EEPRom data (Dec)";
        lblEEData0X->Visible = false;
        edtEEData->Text = IntToStr( m_sEE.eeprom[0].eeprom_data16 );
    }
    else  // Hex
    {
        btnEEData->Caption = "EEPRom data (Hex)";
        lblEEData0X->Visible = true;
        sprintf( str, "%X", m_sEE.eeprom[0].eeprom_data16 );
        edtEEData->Text = str;
    }
}

//----------------------------------------------------------------------------
void  TfrmWiFi::FillBBResult( bool  is_title )
{

    char  str[256];

    if( is_title )
    {
        memBBResult->Lines->Clear();
        sprintf( str, " BB          BB                                        " );
        memBBResult->Lines->Add(str);
        sprintf( str, " index       data                                      " );
        memBBResult->Lines->Add(str);
        sprintf( str, "=======================================================" );
        memBBResult->Lines->Add(str);
    }
    else
    {
        AnsiString as_bbinfo;
        unsigned int    bb_addr;
        unsigned char   bb_value;
        vector<WiFi_BBReg8_S>:: iterator iter;
        WiFi_BBReg8_S bbcr_first = *m_pvBBCRDisp->begin();
        for( iter = m_pvBBCRDisp->begin(); iter != m_pvBBCRDisp->end(); iter++ )
            // for( int i=0; i<m_sBBCR.count; i++ )
        {
            bb_addr  = iter->index;
            bb_value = iter->bbcr_data8;
            if( (bb_addr-bbcr_first.index) % 8 == 0 )
            {
                sprintf(str, "%04ld:        ", bb_addr);
                as_bbinfo = str;
            }
            sprintf(str, "%02lx ", bb_value);
            as_bbinfo += str;
            // if( bb_addr % 8 == 0 && bb_addr != 0 )
            if( (bb_addr-bbcr_first.index) % 8 == 7  )
            {
                strcpy( str, as_bbinfo.c_str() );
                memBBResult->Lines->Add(str);
            }
        }

        if( (bb_addr-bbcr_first.index) % 8 != 7  )
        {
            strcpy( str, as_bbinfo.c_str() );
            memBBResult->Lines->Add(str);
        }
    }

}

//----------------------------------------------------------------------------
void  TfrmWiFi::FillMACResult( bool  is_title )
{
    char  str[256];

    if( is_title )
    {
        memMACResult->Lines->Clear();
        sprintf( str, " MAC         MAC                                        " );
        memMACResult->Lines->Add(str);
        sprintf( str, " address     data                                      " );
        memMACResult->Lines->Add(str);
        sprintf( str, "=======================================================" );
        memMACResult->Lines->Add(str);
    }
    else
    {
        AnsiString as_macinfo;
        unsigned int   mac_addr;

        if( rbMAC16bits->Checked )
        {
            unsigned int   mac16_value;
            vector<WiFi_MACReg16_S>:: iterator iter;
            WiFi_MACReg16_S mcr16_first = *m_pvMCR16Disp->begin();
            // for( int i=0; i<m_sMCR16.count; i++ )
            for( iter = m_pvMCR16Disp->begin(); iter != m_pvMCR16Disp->end(); iter++ )
            {
                mac_addr    = iter->index;
                mac16_value = iter->mcr_data16;

                if( (mac_addr-mcr16_first.index) % 0x10 == 0 )
                {
                    sprintf(str, "%04lx:        ", mac_addr);
                    as_macinfo = str;
                }
                sprintf(str, "%04lx ", mac16_value);
                as_macinfo += str;

                if( (mac_addr-mcr16_first.index) % 0x10 == 0x0E  )
                {
                    strcpy( str, as_macinfo.c_str() );
                    memMACResult->Lines->Add(str);
                }
            }

            if( (mac_addr-mcr16_first.index) % 0x10 != 0x0E  )
            {
                strcpy( str, as_macinfo.c_str() );
                memMACResult->Lines->Add(str);
            }
        }
        else // MAC32
        {
            unsigned int   mac32_value;
            vector<WiFi_MACReg32_S>:: iterator iter;
            WiFi_MACReg32_S mcr32_first = *m_pvMCRDisp->begin();
            //for( int i=0; i<m_sMCR.count; i++ )
            for( iter = m_pvMCRDisp->begin(); iter != m_pvMCRDisp->end(); iter++ )
            {
                mac_addr    = iter->index;
                mac32_value = iter->mcr_data32;

                if( (mac_addr-mcr32_first.index) % 0x10 == 0 )
                {
                    sprintf(str, "%04lx:        ", mac_addr);
                    as_macinfo = str;
                }
                sprintf(str, "%08lx ", mac32_value);
                as_macinfo += str;

                if( (mac_addr-mcr32_first.index) % 0x10 == 0x0C  )
                {
                    strcpy( str, as_macinfo.c_str() );
                    memMACResult->Lines->Add(str);
                }
            }

            if( (mac_addr-mcr32_first.index) % 0x10 != 0x0C  )
            {
                strcpy( str, as_macinfo.c_str() );
                memMACResult->Lines->Add(str);
            }
        }
    }
}

//----------------------------------------------------------------------------
void  TfrmWiFi::FillEEResult( bool  is_title )
{
    char  str[256];

    if( is_title )
    {
        memEEResult->Lines->Clear();
        sprintf( str, " EEProm                                   EEPRom                                       " );
        memEEResult->Lines->Add(str);
        sprintf( str, " address                                  data                                         " );
        memEEResult->Lines->Add(str);
        if( rbEEWord->Checked )
            sprintf( str, "=======================================================================================" );
        else
            sprintf( str, "=====================================================================================================" );

        memEEResult->Lines->Add(str);
    }
    else
    {
        AnsiString as_eeinfo;
        unsigned int     ee_addr;
        unsigned short   ee_value;
        vector<WiFi_EEPROM_S>:: iterator iter;
        WiFi_EEPROM_S eeprom_first = *m_pvEEDisp->begin();
        if( rbEEByte->Checked )
        {
            for( iter = m_pvEEDisp->begin(); iter != m_pvEEDisp->end(); iter++ )
                //for( int i=0; i<m_sEE.count; i++ )
            {
                //WiFi_EEPROM_S eeprom;
                //eeprom = *iter;
                ee_addr  = iter->index;
                ee_value = iter->eeprom_data16;
                if( (ee_addr-eeprom_first.index) % 0x10 == 0 )
                {
                    sprintf(str, "%04lx: ", ee_addr);
                    as_eeinfo = str;
                }
                sprintf(str, "%02lx ", ee_value & 0x00FF );
                as_eeinfo += str;
                sprintf(str, "%02lx ", (ee_value & 0xFF00)>>8 );
                as_eeinfo += str;

                if( (ee_addr-eeprom_first.index) % 0x10 == 0x0F  )
                {
                    strcpy( str, as_eeinfo.c_str() );
                    memEEResult->Lines->Add(str);
                }
            }

            if( (ee_addr-eeprom_first.index) % 0x10 != 0x0F  )
            {
                strcpy( str, as_eeinfo.c_str() );
                memEEResult->Lines->Add(str);
            }
        }
        else
        {
            //for( int i=0; i<m_sEEDisp.count; i++ )
            for( iter = m_pvEEDisp->begin(); iter != m_pvEEDisp->end(); iter++ )
            {
                // WiFi_EEPROM_S eeprom;
                // eeprom = *iter;
                ee_addr  = iter->index;
                ee_value = iter->eeprom_data16;
                if( (ee_addr-eeprom_first.index) % 0x10 == 0 )
                {
                    sprintf(str, "%04lx: ", ee_addr);
                    as_eeinfo = str;
                }
                sprintf(str, "%04lx ", ee_value);
                as_eeinfo += str;

                if( (ee_addr-eeprom_first.index) % 0x10 == 0x0F  )
                {
                    strcpy( str, as_eeinfo.c_str() );
                    memEEResult->Lines->Add(str);
                }
            }

            if( (ee_addr-eeprom_first.index) % 0x10 != 0x0F  )
            {
                strcpy( str, as_eeinfo.c_str() );
                memEEResult->Lines->Add(str);
            }
        } // word
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  TfrmWiFi::CheckFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type )
{
    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_TXALL:
    {

    }
    break;

    case PAGEIDX_CPRX:

        break;

    case PAGEIDX_PS:
        break;


    case PAGEIDX_BB:
        if( ! CheckBBFields( access_type, op_type ) )  return false;
        break;


    case PAGEIDX_MAC:
        if( ! CheckMACFields( access_type, op_type ) )  return false;
        break;

    case PAGEIDX_EE:
        if( ! CheckEEFields( access_type, op_type ) )  return false;
        break;

    case PAGEIDX_SC:
        break;
    }

    return true;
}

//---------------------------------------------------------------------------
bool  TfrmWiFi::CheckBBFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type )
{
    unsigned int uidata;
    AnsiString text;

    if( ACCESS_SINGLE == access_type )
    {
        text = edtBBCRIndex->Text;
        if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
        {
            edtBBCRIndexCheck(edtBBCRIndex);
            return false;
        }
        m_uiBBIdx = uidata;

        if( op_type == OP_WRITE )
        {
            unsigned char ucdata;
            text = edtBBCRData->Text;
            if( btnBBCRData->Tag==0 )  // Dec
            {
                if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
                {
                    edtBBCRDataCheck( edtBBCRData );
                    return false;
                }
            }
            else  // Hex
            {
                if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
                {
                    edtBBCRDataCheck( edtBBCRData );
                    return false;
                }
            }
            m_ucBBValue = ucdata;
        }
    }
    else // dump
    {
        text = edtBBBeginCRIndex->Text;
        if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
        {
            edtBBBeginCRIndexCheck(edtBBBeginCRIndex);
            return false;
        }
        m_uiBBBeginIdx = uidata;

        text = edtBBEndCRIndex->Text;
        if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
        {
            edtBBEndCRIndexCheck(edtBBEndCRIndex);
            return false;
        }
        m_uiBBEndIdx = uidata;


    }

    return true;
}

//---------------------------------------------------------------------------
bool  TfrmWiFi::CheckMACFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type )
{
    unsigned int uidata;
    AnsiString text;

    if( ACCESS_SINGLE == access_type )
    {
        text = edtMACMCRAddress->Text;
        if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
        {
            edtMACMCRAddressCheck(edtMACMCRAddress);
            return false;
        }
        m_uiMacAddr = uidata;

        text = edtMACMCRData->Text;

        if( rbMAC16bits->Checked )
        {
            unsigned short usdata;
            if( btnMACMCRData->Tag==0 )  // Dec
            {
                if( !IsValidDecWiFiMacReg16Value( text, usdata ) )
                {
                    edtMACMCRDataCheck( edtMACMCRData );
                    return false;
                }
            }
            else  // Hex
            {
                if( !IsValidHexWiFiMacReg16Value( text, usdata ) )
                {
                    edtMACMCRDataCheck( edtMACMCRData );
                    return false;
                }
            }
            m_usMac16Data = usdata;
        }
        else
        {
            if( btnMACMCRData->Tag==0 )  // Dec
            {
                if( !IsValidDecWiFiMacRegValue( text, uidata ) )
                {
                    edtMACMCRDataCheck( edtMACMCRData );
                    return false;
                }
            }
            else  // Hex
            {
                if( !IsValidHexWiFiMacRegValue( text, &uidata ) )
                {
                    edtMACMCRDataCheck( edtMACMCRData );
                    return false;
                }
            }
            m_uiMacData = uidata;
        }
    }
    else // dump
    {
        if( rbMAC16bits->Checked )
        {
            text = edtMACBeginMCRAddr->Text;
            if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
            {
                edtMACBeginMCRAddrCheck(edtMACBeginMCRAddr);
                return false;
            }
            m_uiMacBeginAddr = uidata;

            text = edtMACEndMCRAddr->Text;
            if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
            {
                edtMACBeginMCRAddrCheck(edtMACEndMCRAddr);
                return false;
            }
            m_uiMacEndAddr = uidata;
        }
    }

    return true;
}

//---------------------------------------------------------------------------
bool  TfrmWiFi::CheckEEFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type )
{
    unsigned int uidata;
    unsigned short usdata;

    AnsiString text;

    if( ACCESS_SINGLE == access_type )
    {
        text = edtEEIndex->Text;
        if( !IsValidHexWiFiEERegAddr( text, &uidata ) )
        {
            edtMACMCRAddressCheck(edtMACMCRAddress);
            return false;
        }
        m_uiEEPROMIdx = uidata;

        text = edtEEData->Text;
        if( 0 == btnEEData->Tag )  // Dec
        {
            if( !IsValidDecWiFiEERegValue( text, usdata ) )
            {
                edtEEDataCheck( edtEEData );
                return false;
            }
        }
        else  // Hex
        {
            if( !IsValidHexWiFiEERegValue( text, usdata ) )
            {
                edtEEDataCheck( edtEEData );
                return false;
            }
        }
        m_usEEPROMData = usdata;
    }
    else
    {
        text = edtEEBeginIndex->Text;
        if( !IsValidHexWiFiEERegAddr( text, &uidata ) )
        {
            edtBeginEEIndexCheck(edtEEBeginIndex);
            return false;
        }
        m_uiEEPROMBeginIdx = uidata;

        text = edtEEEndIndex->Text;
        if( !IsValidHexWiFiEERegAddr( text, &uidata ) )
        {
            edtEndEEIndexCheck(edtEEEndIndex);
            return false;
        }
        m_uiEEPROMEndIdx = uidata;
    }

    return true;
}

//---------------------------------------------------------------------------
bool  TfrmWiFi::CheckTXOPFields( void )
{
    return true;
}

//---------------------------------------------------------------------------
void  TfrmWiFi::EnableCPTUIComponent( void )
{
    // ALC
    m_edtTXTargetAlc->Enabled = true;
    m_cbTXTargetGain->Enabled = true;
    m_cbTXAlcTracking->Enabled = true;
    m_cbTargetAlc->Enabled = true;

    // MAC header
    edtTXFramCtrl1->Enabled = true;
    edtTXFramCtrl0->Enabled = true;

    edtTXDuration1->Enabled = true;
    edtTXDuration0->Enabled = true;

    edtTXAddress15->Enabled = true;
    edtTXAddress14->Enabled = true;
    edtTXAddress13->Enabled = true;
    edtTXAddress12->Enabled = true;
    edtTXAddress11->Enabled = true;
    edtTXAddress10->Enabled = true;

    edtTXAddress25->Enabled = true;
    edtTXAddress24->Enabled = true;
    edtTXAddress23->Enabled = true;
    edtTXAddress22->Enabled = true;
    edtTXAddress21->Enabled = true;
    edtTXAddress20->Enabled = true;

    edtTXAddress35->Enabled = true;
    edtTXAddress34->Enabled = true;
    edtTXAddress33->Enabled = true;
    edtTXAddress32->Enabled = true;
    edtTXAddress31->Enabled = true;
    edtTXAddress30->Enabled = true;

    edtTXSeqCtrl1->Enabled = true;
    edtTXSeqCtrl0->Enabled = true;

    edtTXPacketLength->Enabled = true;
    edtTXPacketCount->Enabled = true;
    edtTXPacketInterval->Enabled = true;
    cbTXPreamble->Enabled = true;
    cbTXBitPattern->Enabled = true;
}

//---------------------------------------------------------------------------
void  TfrmWiFi::DisableCPTUIComponent(void)
{
    // ALC
    m_edtTXTargetAlc->Enabled = false;
    m_cbTXTargetGain->Enabled = false;
    m_cbTXAlcTracking->Enabled = false;
    m_cbTargetAlc->Enabled = false;

    // MAC header
    edtTXFramCtrl1->Enabled = false;
    edtTXFramCtrl0->Enabled = false;

    edtTXDuration1->Enabled = false;
    edtTXDuration0->Enabled = false;

    edtTXAddress15->Enabled = false;
    edtTXAddress14->Enabled = false;
    edtTXAddress13->Enabled = false;
    edtTXAddress12->Enabled = false;
    edtTXAddress11->Enabled = false;
    edtTXAddress10->Enabled = false;

    edtTXAddress25->Enabled = false;
    edtTXAddress24->Enabled = false;
    edtTXAddress23->Enabled = false;
    edtTXAddress22->Enabled = false;
    edtTXAddress21->Enabled = false;
    edtTXAddress20->Enabled = false;

    edtTXAddress35->Enabled = false;
    edtTXAddress34->Enabled = false;
    edtTXAddress33->Enabled = false;
    edtTXAddress32->Enabled = false;
    edtTXAddress31->Enabled = false;
    edtTXAddress30->Enabled = false;

    edtTXSeqCtrl1->Enabled = false;
    edtTXSeqCtrl0->Enabled = false;

    edtTXPacketLength->Enabled = false;
    edtTXPacketCount->Enabled = false;
    edtTXPacketInterval->Enabled = false;
    cbTXPreamble->Enabled = false;
    cbTXBitPattern->Enabled = false;
}

//---------------------------------------------------------------------------

void  TfrmWiFi::CurrentPageReset( void )
{

    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_TXALL:
    {
        m_iTestPageIndex = PAGEIDX_NONE;
        // cbTXChannelID->Enabled = true;
        // cbTXTxFilter->Enabled = true;
        // cbTXTxRate->Enabled = true;
        // btnTXTxPowerDac->Enabled = true;
        // edtTXTxPowerDAC->Enabled = true;

        rbTXOP->Enabled = true;
        rbTXCS->Enabled = true;
        rbCPT->Enabled = true;
        rbTXLF->Enabled = true;

        // TX DC offset
        //edtTXIDC->Enabled = true;
        //edtTXQDC->Enabled = true;
        btnTXCalTxDC->Enabled = true;

        btnTXUploadFromFlash->Enabled = true;
        btnTXDownloadToFlash->Enabled = true;
        btnTXChangeDB->Enabled = true;
        //btnTXLoadFromFile->Enabled = true;
        //btnTXSaveToFile->Enabled = true;
        btnLoadTxPowerFromEE->Enabled = true;
        btnTXTxChannelPower->Enabled = true;
        m_btnTxAlc->Enabled = true;

        btnTXStart->Enabled = true;
        btnTXStart->Tag = 0;

        if( rbCPT->Checked )
        {
            EnableCPTUIComponent();
        }
    }
    break;

    case PAGEIDX_CPRX:
    {
        m_iTestPageIndex = PAGEIDX_NONE;
        cbCPRChannelID->Enabled = true;
        // cbCPRRxAntenna->Enabled = true;
        cbCPRRxAntenna->Enabled = true;
        btnCPRReset->Enabled = true;
        btnCPRQueryRxCounter->Enabled = true;
        btnCPRStart->Enabled = true;
        btnCPRStart->Tag = 0;
    }
    break;



    case PAGEIDX_PS:
    {
        m_iTestPageIndex = PAGEIDX_NONE;
        cbPSPowerMode->Enabled = true;
        btnPSStart->Enabled = true;
        btnPSStart->Tag = 0;
    }
    break;


    case PAGEIDX_BB:
    {
        edtBBCRIndex->Enabled = true;
        edtBBCRData->Enabled = true;
        btnBBRead->Enabled = true;
        btnBBWrite->Enabled = true;
        btnBBCRData->Enabled = true;
        btnBBDumpBBReg->Enabled = true;
        btnBBRead->Tag = 0;
        btnBBWrite->Tag = 0;
    }
    break;


    case PAGEIDX_MAC:
    {
        edtMACMCRAddress->Enabled = true;
        edtMACMCRData->Enabled = true;
        btnMACRead->Enabled = true;
        btnMACWrite->Enabled = true;
        btnMACMCRData->Enabled = true;
        btnMACDumpAllMacReg->Enabled = true;
        btnMACRead->Tag = 0;
        btnMACWrite->Tag = 0;
    }
    break;

    case PAGEIDX_EE:
    {
        edtEEIndex->Enabled = true;
        edtEEData->Enabled = true;
        btnEERead->Enabled = true;
        btnEEWrite->Enabled = true;
        btnEEData->Enabled = true;
        btnEE->Enabled = true;
        btnEERead->Tag = 0;
        btnEEWrite->Tag = 0;
    }
    break;

    case PAGEIDX_SC:
    {
        btnSCScriptFile->Enabled = true;
        btnSCStart->Enabled = true;
        btnSCStart->Tag = 0;
    }
    break;

    }
}

//---------------------------------------------------------------------------
void  TfrmWiFi::CurrentPageLock( void )
{
    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_TXALL:
    {
        m_iTestPageIndex = PAGEIDX_TXALL;
        // cbTXChannelID->Enabled = false;
        // cbTXTxFilter->Enabled = false;
        // cbTXTxRate->Enabled = false;
        // btnTXTxPowerDac->Enabled = false;
        // edtTXTxPowerDAC->Enabled = false;
        // edtTXPacketInterval->Enabled = false;
        // edtTXPacketLength->Enabled = false;
        // edtTXPacketCount->Enabled = false;
        // cbTXBitPattern->Enabled = false;
        // DisableCPTUIComponent();
        rbTXOP->Enabled = false;
        rbTXCS->Enabled = false;
        rbCPT->Enabled = false;
        rbTXLF->Enabled = false;

        // TX DC offset
        btnTXCalTxDC->Enabled = false;


        btnTXUploadFromFlash->Enabled = false;
        btnTXDownloadToFlash->Enabled = false;
        btnTXChangeDB->Enabled = false;
        btnLoadTxPowerFromEE->Enabled = false;
        btnTXTxChannelPower->Enabled = false;
        m_btnTxAlc->Enabled = false;
        btnTXStart->Enabled = false;
        btnTXStart->Tag = 1;

    }
    break;

    case PAGEIDX_CPRX:
    {
        m_iTestPageIndex = PAGEIDX_CPRX;
        cbCPRChannelID->Enabled = false;
        cbCPRRxAntenna->Enabled = false;
        // cbCPRRxAntenna->Enabled = false;
        btnCPRReset->Enabled = false;
        btnCPRQueryRxCounter->Enabled = false;
        btnCPRStart->Enabled = false;
        btnCPRStart->Tag = 1;
    }
    break;


    case PAGEIDX_PS:
    {
        m_iTestPageIndex = PAGEIDX_PS;
        cbPSPowerMode->Enabled = false;
        btnPSStart->Enabled = false;
        btnPSStart->Tag = 1;
    }
    break;


    case PAGEIDX_BB:
    {
        // m_iTestPageIndex = PAGEIDX_BB;
        edtBBCRIndex->Enabled = false;
        edtBBCRData->Enabled = false;
        btnBBRead->Enabled = false;
        btnBBWrite->Enabled = false;
        btnBBCRData->Enabled = false;
        btnBBDumpBBReg->Enabled = false;
        btnBBRead->Tag = 1;
        btnBBWrite->Tag = 1;
    }
    break;


    case PAGEIDX_MAC:
    {
        // m_iTestPageIndex = PAGEIDX_MAC;
        edtMACMCRAddress->Enabled = false;
        edtMACMCRData->Enabled = false;
        btnMACRead->Enabled = false;
        btnMACWrite->Enabled = false;
        btnMACMCRData->Enabled = false;
        btnMACDumpAllMacReg->Enabled = false;
        btnMACRead->Tag = 1;
        btnMACWrite->Tag = 1;
    }
    break;

    case PAGEIDX_EE:
    {
        // m_iTestPageIndex = PAGEIDX_EE;
        edtEEIndex->Enabled = false;
        edtEEData->Enabled = false;
        btnEERead->Enabled = false;
        btnEEWrite->Enabled = false;
        btnEEData->Enabled = false;
        btnEE->Enabled = false;
        btnEERead->Tag = 1;
        btnEEWrite->Tag = 1;
    }
    break;

    case PAGEIDX_SC:
    {
        btnSCScriptFile->Enabled = false;
        btnSCStart->Enabled = false;
        btnSCStart->Tag = 1;
    }
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXStartClick(TObject *Sender)
{


    if( rbTXOP->Checked )
    {
        TXOPExecute();
    }
    else if( rbTXCS->Checked )
    {
        TXCSExecute();
    }
    else if( rbCPT->Checked )
    {
        CPTExecute();
    }
    else
    {
        LFExecute();
    }



}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::CPTExecute(void)
{
    int i;
    AnsiString  text;
    S_WIFICPT  m_sWiFiCPT;

    m_sWiFiCPT.bAlcSupport = m_bAlcSupport;
    m_sWiFiCPT.wifi_id = m_final_WiFiId;
    m_sWiFiCPT.channel_freq = GetWiFiChannelFreqFromStr( cbTXChannelID->Text );
    if( IDX_TX_FILTER_NORTH_AMERICA == cbTXTxFilter->ItemIndex )
    {
        m_sWiFiCPT.reg_domain.country_code[0] = 'U';
        m_sWiFiCPT.reg_domain.country_code[1] = 'S';
    }
    else
    {
        m_sWiFiCPT.reg_domain.country_code[0] = 'J';
        m_sWiFiCPT.reg_domain.country_code[1] = 'P';
    }
    m_sWiFiCPT.tx_rate = (WiFi_TestRate_E) GetWiFiTxRateFromStr( cbTXTxRate->Text );

    text = edtTXPacketLength->Text;
    if( !IsValidWiFiPacketLength( text, m_sWiFiCPT.pkt_length ) )
    {
        edtCPTPacketLengthCheck(edtTXPacketLength);
        return;
    }
    text = edtTXPacketCount->Text;
    if( !IsValidWiFiPacketCount( text, m_sWiFiCPT.pkt_count ) )
    {
        edtCPTPacketCountCheck(edtTXPacketCount);
        return;
    }
    text = edtTXPacketInterval->Text;
    if( !IsValidWiFiPacketInterval( text, m_sWiFiCPT.pkt_interval ) )
    {
        edtCPTPacketIntervalCheck(edtTXPacketInterval);
        return;
    }
    if( 0 == btnTXTxPowerDac->Tag )
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidDecWiFiTxPowerDac( text, m_sWiFiCPT.tx_pwr_dac ) )
        {
            edtCPTTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }
    else
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidHexWiFiTxPowerDac( text, m_sWiFiCPT.tx_pwr_dac ) )
        {
            edtCPTTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }

    switch (cbTXBitPattern->ItemIndex)
    {
    case WIFI_IDX_ALL_0:
    {
        m_sWiFiCPT.pattern = WIFI_TX_ALL_ZEROS;
    }
    break;

    case WIFI_IDX_ALL_1:
    {
        m_sWiFiCPT.pattern = WIFI_TX_ALL_ONES;
    }
    break;

    case WIFI_IDX_ALTERNATE:
    {
        m_sWiFiCPT.pattern = WIFI_TX_ALTERNATE_BITS;
    }
    break;

    case WIFI_IDX_RANDOM:
    {
        m_sWiFiCPT.pattern = WIFI_TX_PSEUDO_RANDOM;
    }
    break;

    default:
    {
    }
    break;
    }

    m_sWiFiCPT.is_short_preamble = cbTXPreamble->ItemIndex;

    // MAC header
    for( i=0; i<WIFI_MAC_HEAD_FRAME_CTRL_LEN; i++ )
    {
        text = edtTXFramCtrl[i]->Text;
        if( !IsValidHexWiFiMacHeaderFrameCtrl( text, m_sWiFiCPT.s_mac_header.frame_ctrl[i] ) )
        {
            edtTXFramCtrlCheck(edtTXFramCtrl[i]);
            return;
        }
    }

    for( i=0; i<WIFI_MAC_HEAD_DURATION_LEN; i++ )
    {
        text = edtTXDuration[i]->Text;
        if( !IsValidHexWiFiMacHeaderDuration( text, m_sWiFiCPT.s_mac_header.duration[i] ) )
        {
            edtTXDurationCheck(edtTXDuration[i]);
            return;
        }
    }

    for( i=0; i<WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
    {
        text = edtTXAddress1[i]->Text;
        if( !IsValidHexWiFiMacHeaderAddress( text, m_sWiFiCPT.s_mac_header.address1[i] ) )
        {
            edtTXAddress1Check(edtTXAddress1[i]);
            return;
        }
    }

    for( i=0; i<WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
    {
        text = edtTXAddress2[i]->Text;
        if( !IsValidHexWiFiMacHeaderAddress( text, m_sWiFiCPT.s_mac_header.address2[i] ) )
        {
            edtTXAddress2Check(edtTXAddress2[i]);
            return;
        }
    }

    for( i=0; i<WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
    {
        text = edtTXAddress3[i]->Text;
        if( !IsValidHexWiFiMacHeaderAddress( text, m_sWiFiCPT.s_mac_header.address3[i] ) )
        {
            edtTXAddress3Check(edtTXAddress3[i]);
            return;
        }
    }

    for( i=0; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN; i++ )
    {
        text = edtTXSeqCtrl[i]->Text;
        if( !IsValidHexWiFiMacHeaderAddress( text, m_sWiFiCPT.s_mac_header.seq_ctrl[i] ) )
        {
            edtTXSeqCtrlCheck(edtTXSeqCtrl[i]);
            return;
        }
    }

    if (m_bAlcSupport)
    {
        m_sWiFiCPT.ui_txFlags = 0;
        if (!m_cbTXTargetGain->Checked)
        {
            m_sWiFiCPT.ui_txFlags |= WIFI_TX_FLAG_NO_TXGAIN;
        }

        if (m_cbTXAlcTracking->Checked)
        {
            m_sWiFiCPT.ui_txFlags |= WIFI_TX_FLAG_ENABLE_ALC_TRACK;
        }

        if (m_cbTargetAlc->Checked)
        {
            m_sWiFiCPT.ui_txFlags |= WIFI_TX_FLAG_TARGET_ALC_PROVIDE;
        }

        m_sWiFiCPT.ui_targetAlc = m_edtTXTargetAlc->Text.ToInt();
    }

    CurrentPageLock();
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Continuos packet TX progressing";
    m_WIFI_CPT_Obj.ConfirmCallback  = ::ConfirmCallback_CPT;
    m_WIFI_CPT_Obj.REQ_Start(m_sWiFiCPT);
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ConfirmCallback_CPT(void)
{
    int state = m_WIFI_CPT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        TimerWiFi->Enabled = true;
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Continuous packet TX progressing";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Continuous packet TX fail";
        Application->MessageBox( "Execution Failure : Continuous packet TX", "FAILURE", MB_OK );
        Application->BringToFront();
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Continuous packet TX timeout";
        Application->MessageBox( "Execution Timeout : Continuous packet TX", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Continuous packet TX stop";
        CurrentPageReset();
    }
    break;
    }

}


//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXUploadFromFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) " NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    //  m_WIFI_CPT_Obj.ConfirmCallback = ::CNF_CPTX_ReadFromNVRAM;
    //  m_WIFI_CPT_Obj.REQ_Read_From_NVRAM();
    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_ReadTxPower2400MFromNVRAM;
        m_WIFI_APC_Obj.REQ_Read_TxPower2400M_From_NVRAM_Start();
    }
    else if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_ReadTxPower5000MFromNVRAM;
        m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_NVRAM_Start();
    }
    CurrentPageLock();


}

//---------------------------------------------------------------------------
void  TfrmWiFi::CPTX_UploadTxPower2400MFromFlashDone( void )
{
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();
    //char  str[20];
    //float  fdata;



    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr2400M = m_WIFI_APC_Obj.Get_TxChannelDac2400M();
        if( m_sWiFiCap.support_802_11a )
        {
            m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_ReadTxPower5000MFromNVRAM;
            m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_NVRAM_Start();
        }
        else
        {
            ReDrawFields( PAGEIDX_TXALL );
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting from flash successful";
            //CurrentPageReset();
            m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_ReadTxDCFromNVRAM;
            m_WIFI_TXDC_Obj.REQ_Read_From_NVRAM_Start();
        }
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload TX channel power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload TX channel power setting", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void  TfrmWiFi::CPTX_UploadTxPower5000MFromFlashDone( void )
{
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();
    //char  str[20];
    //float  fdata;



    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr5000M = m_WIFI_APC_Obj.Get_TxChannelDac5000M();
        ReDrawFields( PAGEIDX_TXALL );
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting from flash successful";
        m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_ReadTxDCFromNVRAM;
        m_WIFI_TXDC_Obj.REQ_Read_From_NVRAM_Start();
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload TX channel power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload TX channel power setting", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting stop";
        CurrentPageReset();
    }
    break;
    }

}

//--------------------------------------------------------------------------
void TfrmWiFi::UploadTxDCFromFlashDone( void )
{
    META_RESULT state = m_WIFI_TXDC_Obj.Get_ConfirmState();
    //char  str[20];
    //float  fdata;

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxDcOffset = m_WIFI_TXDC_Obj.Get_TxDcOffset();
        ReDrawFields( PAGEIDX_TXALL );
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX DC offset from flash successful";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload TX channel power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload TX channel power setting", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting stop";
    }
    break;
    }
    CurrentPageReset();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmWiFi::btnTXDownloadToFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_WriteTxPower2400MToNVRAM;
        m_WIFI_APC_Obj.REQ_Write_TxPower2400M_To_NVRAM_Start();
    }
    else if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_WriteTxPower5000MToNVRAM;
        m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
    }

    CurrentPageLock();
}

//---------------------------------------------------------------------------
void  TfrmWiFi::CPTX_DownloadTxPower2400MToFlashDone( void )
{
    int state = m_WIFI_CPT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        if( m_sWiFiCap.support_802_11a )
        {
            m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
            m_WIFI_APC_Obj.ConfirmCallback = ::CNF_CPTX_WriteTxPower5000MToNVRAM;
            m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash successful";
            // CurrentPageReset();
            m_WIFI_TXDC_Obj.Set_TxDcOffset( m_sTxDcOffset );
            m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_WriteTxDCToNVRAM;
            m_WIFI_TXDC_Obj.REQ_Write_To_NVRAM_Start();
        }
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX channel power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX channel power setting to flash", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash stop";
        CurrentPageReset();
    }
    break;
    }


}

//---------------------------------------------------------------------------
void  TfrmWiFi::CPTX_DownloadTxPower5000MToFlashDone( void )
{
    int state = m_WIFI_CPT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash successful";
        m_WIFI_TXDC_Obj.Set_TxDcOffset( m_sTxDcOffset );
        m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_WriteTxDCToNVRAM;
        m_WIFI_TXDC_Obj.REQ_Write_To_NVRAM_Start();
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX channel power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();

    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX channel power setting to flash", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash stop";
        CurrentPageReset();
    }
    break;
    }


}

//---------------------------------------------------------------------------
void  TfrmWiFi::DownloadTxDCToFlashDone( void )
{
    int state = m_WIFI_CPT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX DC offset to flash successful";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX DC offset to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX DC offset to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );

    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX DC offset to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX DC offset to flash", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX DC offset to flash stop";
    }
    break;
    }
    CurrentPageReset();

}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXChangeDBClick(TObject *Sender)
{
    frmMainSel->mnuFDMDatabaseClick(Sender);
    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
        return;
    }
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Change NVRAM database file successfully";
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;
    //float  fdata;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );
    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        ok = m_WIFI_APC_Obj.REQ_Read_TxPower2400M_From_File( str );
        if( ok )
        {
            m_sTxPwr2400M = m_WIFI_APC_Obj.Get_TxChannelDac2400M();
        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
            Application->MessageBox( "Execution Failure : Load WiFi TX setting from file", "FAILURE", MB_OK );
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        ok = m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_File( str );
        if( ok )
        {
            m_sTxPwr5000M = m_WIFI_APC_Obj.Get_TxChannelDac5000M();
        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
            Application->MessageBox( "Execution Failure : Load WiFi TX setting from file", "FAILURE", MB_OK );
        }
    }

    // load TX DC offset from file
    ok = m_WIFI_TXDC_Obj.REQ_Read_From_File( str );
    if( ok )
    {
        m_sTxDcOffset = m_WIFI_TXDC_Obj.Get_TxDcOffset();
    }
    else
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file fail";
        Application->MessageBox( "Execution Failure : Load WiFi TX setting from file", "FAILURE", MB_OK );
    }
    ReDrawFields( PAGEIDX_TXALL );
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file successfully";
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
        return;
    }

    strcpy( str, SaveDialog->FileName.c_str() );

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        ok = m_WIFI_APC_Obj.REQ_Write_TxPower2400M_To_File( str );
        if( !ok )
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
            Application->MessageBox( "Execution Failure : Save WiFi TX setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
        ok = m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_File( str );
        if( !ok )
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
            Application->MessageBox( "Execution Failure : Save WiFi TX setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    // save TX DC offset to file
    m_WIFI_TXDC_Obj.Set_TxDcOffset( m_sTxDcOffset );
    ok = m_WIFI_TXDC_Obj.REQ_Write_To_File( str );
    if( !ok )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file fail";
        Application->MessageBox( "Execution Failure : Save WiFi TX setting to file", "FAILURE", MB_OK );
        return;
    }

    sbTX->Panels->Items[0]->Text = (AnsiString) "  Save WiFi TX setting to file successfully";
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtCPTPacketCountCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " packet count is invalid "
    };

    text = edit->Text;
    if( !IsValidWiFiPacketCount( text, ui_data ) )
    {
        edit->Text = 1000;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtCPTPacketLengthCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " packet length shall be 24~1500 "
    };

    text = edit->Text;
    if( !IsValidWiFiPacketLength( text, ui_data ) )
    {
        edit->Text = 128;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::edtCPTPacketIntervalCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " packet interval is invalid "
    };

    text = edit->Text;
    if( !IsValidWiFiPacketLength( text, ui_data ) )
    {
        edit->Text = 100;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::edtCPTTxPowerDACCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value should be 0~63 ";


    text = edit->Text;
    if( 0 == btnTXTxPowerDac->Tag )  // Dec
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

    if( uc_data > 63 )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    E_WIFI_GENERATION wifi_802_11_idx;
    unsigned int chan_idx;
    if(! GetWiFiChannelIndexFromStr( cbTXChannelID->Text, cbTXTxRate->Text, wifi_802_11_idx, chan_idx ) )
    {
        return;
    }

    if( WIFI_802_11A_IDX == wifi_802_11_idx )
    {
        m_sTxPwr5000M.TxPWR[chan_idx] = uc_data;
    }
    else if( WIFI_802_11B_IDX == wifi_802_11_idx )
    {
        m_sTxPwr2400M.CCKTxPWR[chan_idx] = uc_data;
    }
    else  // 802.11G
    {
        m_sTxPwr2400M.OFDMTxPWR[chan_idx] = uc_data;
    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXTxFilterChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXTxRateChange(TObject *Sender)
{
    ReDrawFields( PAGEIDX_TXALL );
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbCPTRxAntennaChange(TObject *Sender)
{
    //
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::cbTXChannelIDChange(TObject *Sender)
{
    ReDrawFields( PAGEIDX_TXALL );
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ShowHintLabel( TControl *sender, char* hint )
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

void __fastcall TfrmWiFi::btnTXStopClick(TObject *Sender)
{
    if( 1 == btnTXStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Stop continuous packet TX successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbCPRChannelIDChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbCPRRxAntennaChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnCPRResetClick(TObject *Sender)
{
    // General RX
    int i;
    stCPRTotal->Caption = IntToStr( 0 );
    stCPRSuccess->Caption = IntToStr( 0 );
    stCPRFER->Caption = IntToStr( 0 );
    stCPRCRCErr->Caption = IntToStr( 0 );

    stCPRint_rx_ok_num->Caption = IntToStr( 0 );
    stCPRint_crc_err_num->Caption = IntToStr( 0 );
    stCPRpau_rx_ok_count->Caption = IntToStr( 0 );
    stCPRpau_crc_err_count->Caption = IntToStr( 0 );
    stCPRpau_cca_count->Caption = IntToStr( 0 );
    stCPRpau_rx_fifo_full_count->Caption = IntToStr( 0 );

    for( i=0; i<WIFI_TEST_RATE_COUNT; i++ )
    {
        stCPRSum[i]->Caption = IntToStr( 0 );
        stCPRGood[i]->Caption = IntToStr( 0 );
        stCPRBad[i]->Caption = IntToStr( 0 );
        stCPRFer[i]->Caption = IntToStr( 0 );
    }

    // RSSI
    stCPRMin->Caption = IntToStr( 0 );
    stCPRMax->Caption = IntToStr( 0 );
    stCPRMean->Caption = IntToStr( 0 );
    stCPRVariance->Caption = IntToStr( 0 );

    // Preamble
    stCPRLong->Caption = IntToStr( 0 );
    stCPRShort->Caption = IntToStr( 0 );



    m_WIFI_CPRX_Obj.ConfirmCallback  = ::ConfirmCallback_QueryOriRxStatus;
    m_WIFI_CPRX_Obj.REQ_QueryRxStatus_Start();
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnCPRStartClick(TObject *Sender)
{
    unsigned int channel_freq = GetWiFiChannelFreqFromStr( cbCPRChannelID->Text );
    WiFi_RxAntSel_E rx_ant = (WiFi_RxAntSel_E) cbCPRRxAntenna->ItemIndex;

    CurrentPageLock();
    m_WIFI_CPRX_Obj.ConfirmCallback  = ::ConfirmCallback_CPRX;
    m_WIFI_CPRX_Obj.REQ_Start( channel_freq, rx_ant );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_CPRX( void )
{

    int state = m_WIFI_CPRX_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_CPRX_OK:
    {
        m_WIFI_CPRX_Obj.ConfirmCallback  = ::ConfirmCallback_QueryOriRxStatus;
        m_WIFI_CPRX_Obj.REQ_QueryRxStatus_Start();
        TimerWiFi->Enabled = true;
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Continuous packet RX progressing";
    }
    break;

    case STATE_CPRX_FAIL:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Continuous packet RX fail";
        Application->MessageBox( "Execution Failure : Continuous packet RX", "FAILURE", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_TIMEOUT:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Continuous packet RX timeout";
        Application->MessageBox( "Execution Timeout : Continuous packet RX", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_STOP:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Continuous packet RX stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_QueryOriRxStatus( void )
{
    int state = m_WIFI_CPRX_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_CPRX_OK:
    {
        WiFi_RxStatus_S  rx_status;
        m_sOriRxStatus = m_WIFI_CPRX_Obj.Get_RxStatus();

        // stCPRSuccess->Caption = IntToStr( rx_status.int_rx_ok_num - m_sOriRxStatus.int_rx_ok_num );
        // stCPRCRCErr->Caption  = IntToStr( rx_status.int_crc_err_num - m_sOriRxStatus.int_crc_err_num );
        // stCPRTotal->Caption   = IntToStr( stCPRSuccess->Caption.ToInt() + stCPRCRCErr->Caption.ToInt() );
        // if( stCPRTotal->Caption.ToInt() != 0 )
        // {
        //     stCPRFER->Caption     = Double_To_AnsiString( stCPRCRCErr->Caption.ToInt() * 100.0 / stCPRTotal->Caption.ToInt() );
        // }
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status successfully";
    }
    break;

    case STATE_CPRX_FAIL:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status fail";
        Application->MessageBox( "Execution Failure : Query continuous packet RX status", "FAILURE", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_TIMEOUT:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status timeout";
        Application->MessageBox( "Execution Timeout : Query continuous packet RX status", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_STOP:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status stop";
        CurrentPageReset();
    }
    break;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnCPRStopClick(TObject *Sender)
{
    if( btnCPRStart->Tag==1 )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Stop continuous packet RX successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXOPChannelIDChange(TObject *Sender)
{
    // ReDrawFields( PAGEIDX_TXOP );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXOPTXFilterChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXOPTXRateChange(TObject *Sender)
{
    // ReDrawFields( PAGEIDX_TXOP );
}
//---------------------------------------------------------------------------
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  TfrmWiFi::TXOPExecute( void )
{
    AnsiString text;
    S_WIFITXOP  wifitxop;

    wifitxop.wifi_id = m_final_WiFiId;
    if( IDX_TX_FILTER_NORTH_AMERICA == cbTXTxFilter->ItemIndex )
    {
        wifitxop.reg_domain.country_code[0] = 'U';
        wifitxop.reg_domain.country_code[1] = 'S';
    }
    else
    {
        wifitxop.reg_domain.country_code[0] = 'J';
        wifitxop.reg_domain.country_code[1] = 'P';
    }

    wifitxop.channel_freq = GetWiFiChannelFreqFromStr( cbTXChannelID->Text );
    wifitxop.tx_rate      = (WiFi_TestRate_E) GetWiFiTxRateFromStr( cbTXTxRate->Text );
    if( 0 == btnTXTxPowerDac->Tag )
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidDecWiFiTxPowerDac( text, wifitxop.tx_pwr_dac ) )
        {
            edtTXOPTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }
    else
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidHexWiFiTxPowerDac( text, wifitxop.tx_pwr_dac ) )
        {
            edtTXOPTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }

    CurrentPageLock();
    sbTX->Panels->Items[0]->Text = (AnsiString)"  TX output power progressing";
    m_WIFI_TXOP_Obj.ConfirmCallback  = ::ConfirmCallback_TXOP;
    m_WIFI_TXOP_Obj.REQ_Start( wifitxop );
}

//---------------------------------------------------------------------------
void  TfrmWiFi::ConfirmCallback_TXOP( void )
{

    int state = m_WIFI_TXOP_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_TXOP_OK:
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX output power progressing";
        break;

    case STATE_TXOP_FAIL:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX output power fail";
        Application->MessageBox( "Execution Timeout : TX output power", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_TXOP_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX output power timeout";
        Application->MessageBox( "Execution Timeout : TX output power", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_TXOP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX output power stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXOPStopClick(TObject *Sender)
{
    if( 1 == btnTXStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Stop TX output power successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXCSChannelIDChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbTXCSTXFilterChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::TXCSExecute( void )
{
    AnsiString  text;
    S_WIFITXCS  wifitxcs;

    wifitxcs.wifi_id = m_final_WiFiId;
    wifitxcs.channel_freq = GetWiFiChannelFreqFromStr( cbTXChannelID->Text );
    if( IDX_TX_FILTER_NORTH_AMERICA == cbTXTxFilter->ItemIndex )
    {
        wifitxcs.reg_domain.country_code[0] = 'U';
        wifitxcs.reg_domain.country_code[1] = 'S';
    }
    else
    {
        wifitxcs.reg_domain.country_code[0] = 'J';
        wifitxcs.reg_domain.country_code[1] = 'P';
    }

    wifitxcs.tx_rate = (WiFi_TestRate_E) GetWiFiTxRateFromStr( cbTXTxRate->Text );

    if( 0 == btnTXTxPowerDac->Tag )
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidDecWiFiTxPowerDac( text, wifitxcs.tx_pwr_dac ) )
        {
            edtTXCSTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }
    else
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidHexWiFiTxPowerDac( text, wifitxcs.tx_pwr_dac ) )
        {
            edtTXCSTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }

    CurrentPageLock();
    sbTX->Panels->Items[0]->Text = (AnsiString) "  TX Carrier suppression progressing";
    m_WIFI_TXCS_Obj.ConfirmCallback  = ::ConfirmCallback_TXCS;
    m_WIFI_TXCS_Obj.REQ_Start( wifitxcs );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_TXCS( void )
{
    int state = m_WIFI_TXCS_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_TXCS_OK:
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX carrier suppression progressing";
        break;

    case STATE_TXCS_FAIL:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX carrier suppression fail";
        Application->MessageBox( "Execution Timeout : TX carrier suppression", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_TXCS_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX carrier suppression timeout";
        Application->MessageBox( "Execution Timeout : TX carrier suppression", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_TXCS_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX carrier suppression stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXCSStopClick(TObject *Sender)
{
    if( 1 == btnTXStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Stop TX carrier suppression successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbLFChannelIDChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::cbLFTXFilterChange(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::LFExecute( void )
{
    AnsiString  text;
    S_WIFILF wifilf;

    wifilf.wifi_id = m_final_WiFiId;
    wifilf.channel_freq = GetWiFiChannelFreqFromStr( cbTXChannelID->Text );
    if( IDX_TX_FILTER_NORTH_AMERICA == cbTXTxFilter->ItemIndex )
    {
        wifilf.reg_domain.country_code[0] = 'U';
        wifilf.reg_domain.country_code[1] = 'S';
    }
    else
    {
        wifilf.reg_domain.country_code[0] = 'J';
        wifilf.reg_domain.country_code[1] = 'P';
    }

    wifilf.tx_rate = (WiFi_TestRate_E) GetWiFiTxRateFromStr( cbTXTxRate->Text );

    if( 0 == btnTXTxPowerDac->Tag )
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidDecWiFiTxPowerDac( text, wifilf.tx_pwr_dac ) )
        {
            edtLFTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }
    else
    {
        text = edtTXTxPowerDAC->Text;
        if( !IsValidHexWiFiTxPowerDac( text, wifilf.tx_pwr_dac ) )
        {
            edtLFTxPowerDACCheck(edtTXTxPowerDAC);
            return;
        }
    }

    CurrentPageLock();
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Local frequency test progressing";
    m_WIFI_LF_Obj.ConfirmCallback  = ::ConfirmCallback_LF;
    m_WIFI_LF_Obj.REQ_Start( wifilf );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_LF( void )
{
    int state = m_WIFI_LF_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_LF_OK:
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Local frequency test progressing";
        break;

    case STATE_LF_FAIL:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Local frequency test fail";
        Application->MessageBox( "Execution Timeout : Local frequency test", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_LF_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Local frequency test timeout";
        Application->MessageBox( "Execution Timeout : Local frequency test", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_LF_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Local frequency test stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnLFStopClick(TObject *Sender)
{
    if( 1 == btnTXStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Stop local frequency test successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnPSStandbyClick(TObject *Sender)
{
    m_WIFI_PS_Obj.ConfirmCallback  = ::ConfirmCallback_PS;
    m_WIFI_PS_Obj.REQ_Start( WIFI_POWER_MODE_IDLE );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnPSSleepClick(TObject *Sender)
{
    m_WIFI_PS_Obj.ConfirmCallback  = ::ConfirmCallback_PS;
    m_WIFI_PS_Obj.REQ_Start( WIFI_POWER_MODE_SLEEP );
}


//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtBBCRIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value should be 0~127 ";

    text = edit->Text;
    if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( uidata > 127 )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiBBIdx = uidata;
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtBBCRDataCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( btnBBCRData->Tag==0 )  // Dec
    {
        if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_ucBBValue = ucdata;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnBBReadClick(TObject *Sender)
{
    AnsiString text;
    //unsigned int uidata;



    if( !CheckFields( ACCESS_SINGLE, OP_READ ) )
    {
        sbBB->Panels->Items[0]->Text = (AnsiString) "  Read baseband register fail";
        Application->MessageBox( "Execution Failure : Read baseband register", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();
    Compose_BBCR_Parameter( ACCESS_SINGLE );

    m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_ReadBBReg;
    m_WIFI_BB_Obj.REQ_Read_BBCR_Setting_From_Reg_Start( m_sBBCR );
    // m_WIFI_BB_Obj.REQ_Read_From_Reg_Start(  m_ucBBAddr );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadBBReg( void )
{

    int state = m_WIFI_BB_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_BB_OK:
    {
        m_sBBCR = m_WIFI_BB_Obj.Get_BBCR();
        DeCompose_BBCR_Data( ACCESS_SINGLE );
        ReDrawFields( PAGEIDX_BB );
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Read baseband register successfully";
    }
    break;

    case STATE_BB_FAIL:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Read baseband register fail";
        Application->MessageBox( "Execution Timeout : Read baseband register", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_BB_TIMEOUT:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Read baseband register timeout";
        Application->MessageBox( "Execution Timeout : Read baseband register", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_BB_STOP:
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Read baseband register stop";
        break;
    }
    CurrentPageReset();

}


//-----------------------------------------------------------------------
void __fastcall TfrmWiFi::btnBBWriteClick(TObject *Sender)
{
    AnsiString text;
    // unsigned char bb_reg_addr, bb_reg_data;

    // text = edtBBCRIndex->Text;        if( !IsValidHexWiFiBBRegAddr( text, bb_reg_addr ) )           {  edtBBCRIndexCheck(edtBBCRIndex);            return;   }
    // text = edtBBCRData->Text;        if( !IsValidHexWiFiBBRegValue( text, bb_reg_data ) )           {  edtBBCRDataCheck(edtBBCRData);            return;   }
    if( !CheckFields( ACCESS_SINGLE, OP_WRITE ) )
    {
        sbBB->Panels->Items[0]->Text = (AnsiString) "  Write baseband register fail";
        Application->MessageBox( "Execution Failure : Write baseband register", "FAILURE", MB_OK );
        return;
    }
    Compose_BBCR_Parameter( ACCESS_SINGLE );
    Compose_BBCR_Data( ACCESS_SINGLE );
    m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_WriteBBReg;
    m_WIFI_BB_Obj.REQ_Write_BBCR_Setting_To_Reg_Start( m_sBBCR );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_WriteBBReg( void )
{
    int state = m_WIFI_BB_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_BB_OK:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Write baseband register successfully";
    }
    break;

    case STATE_BB_FAIL:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Write baseband register fail";
        Application->MessageBox( "Execution Timeout : Write baseband register", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_BB_TIMEOUT:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Write baseband register timeout";
        Application->MessageBox( "Execution Timeout : Write baseband register", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_BB_STOP:
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Write baseband register stop";
        break;
    }
    CurrentPageReset();
}




//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::edtMACMCRAddressCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";
    char  hint16[] = " value should be multiple of 2 ";
    char  hint32[] = " value should be multiple of 4 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( rbMAC16bits->Checked )
    {
        if( 0 != uidata%2 )
        {
            ShowHintLabel( edit, hint16 );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( 0 != uidata%4 )
        {
            ShowHintLabel( edit, hint32 );
            edit->SetFocus();
            return;
        }
    }

    m_uiMacAddr = uidata;

}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtMACMCRDataCheck(TObject *Sender)
{
    AnsiString  text;

    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value is not valid ";


    text = edit->Text;
    if( rbMAC16bits->Checked )
    {
        unsigned short  usdata;
        if( btnMACMCRData->Tag==0 )  // Dec
        {
            if( !IsValidDecWiFiMacReg16Value( text, usdata ) )
            {
                ShowHintLabel( edit, hint );
                edit->SetFocus();
                return;
            }
        }
        else  // Hex
        {
            if( !IsValidHexWiFiMacReg16Value( text, usdata ) )
            {
                ShowHintLabel( edit, hint );
                edit->SetFocus();
                return;
            }
        }
        m_usMac16Data = usdata;
    }
    else
    {
        unsigned int  uidata;
        if( btnMACMCRData->Tag==0 )  // Dec
        {
            if( !IsValidDecWiFiMacRegValue( text, uidata ) )
            {
                ShowHintLabel( edit, hint );
                edit->SetFocus();
                return;
            }
        }
        else  // Hex
        {
            if( !IsValidHexWiFiMacRegValue( text, &uidata ) )
            {
                ShowHintLabel( edit, hint );
                edit->SetFocus();
                return;
            }
        }

        m_uiMacData = uidata;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnMACReadClick(TObject *Sender)
{
    AnsiString text;
    unsigned int mac_reg_addr;

    text = edtMACMCRAddress->Text;
    if( !IsValidHexWiFiMacRegAddr( text, &mac_reg_addr ) )
    {
        edtMACMCRAddressCheck(edtMACMCRAddress);
        return;
    }
    m_uiMacAddr = mac_reg_addr;

    CurrentPageLock();
    m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadMACReg;
    if( rbMAC16bits->Checked )
    {
        Compose_MCR16_Parameter( ACCESS_SINGLE );
        m_WIFI_MAC_Obj.REQ_Read_MCR16_Setting_From_Reg_Start( m_sMCR16 );
    }
    else
    {
        Compose_MCR_Parameter( ACCESS_SINGLE );
        m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
    }
    sbMAC->Panels->Items[0]->Text = (AnsiString)"  Read MAC register progressing";
    //m_WIFI_MAC_Obj.REQ_Read_From_Reg_Start( m_uiMacAddr );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadMACReg( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        // m_uiMacData = m_WIFI_MAC_Obj.Get_MacData();
        if( rbMAC16bits->Checked )
        {
            m_sMCR16 = m_WIFI_MAC_Obj.Get_MCR16();
            DeCompose_MCR16_Data( ACCESS_SINGLE );
        }
        else
        {
            m_sMCR = m_WIFI_MAC_Obj.Get_MCR();
            DeCompose_MCR_Data( ACCESS_SINGLE );
        }
        ReDrawFields( PAGEIDX_MAC );
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
    }
    break;

    case STATE_MAC_FAIL:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Read MAC register fail";
        Application->MessageBox( "Execution Timeout : Read MAC register", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Read MAC register timeout";
        Application->MessageBox( "Execution Timeout : Read MAC register", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_MAC_STOP:
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Read MAC register stop";
        break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnMACWriteClick(TObject *Sender)
{
    //AnsiString text;
    //unsigned int mac_reg_addr, mac_reg_data;

    //text = edtMACMCRAddress->Text;        if( !IsValidHexWiFiMacRegAddr( text, mac_reg_addr ) )           {  edtMACMCRAddressCheck(edtMACMCRAddress);            return;   }
    //text = edtMACMCRData->Text;        if( !IsValidHexWiFiMacRegValue( text, mac_reg_data ) )           {  edtMACMCRDataCheck(edtMACMCRData);            return;   }
    if( ! CheckFields( ACCESS_SINGLE, OP_WRITE ) )
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString) "  Write MAC register fail";
        Application->MessageBox( "Execution Failure : Write MAC register", "FAILURE", MB_OK );
        return;
    }


    CurrentPageLock();
    m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteMACReg;
    if( rbMAC16bits->Checked )
    {
        Compose_MCR16_Parameter( ACCESS_SINGLE );
        Compose_MCR16_Data( ACCESS_SINGLE );
        m_WIFI_MAC_Obj.REQ_Write_MCR16_Setting_To_Reg_Start( m_sMCR16 );
    }
    else
    {
        Compose_MCR_Parameter( ACCESS_SINGLE );
        Compose_MCR_Data( ACCESS_SINGLE );
        m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_WriteMACReg( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {

        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Write MAC register successfully";
    }
    break;

    case STATE_MAC_FAIL:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Write MAC register fail";
        Application->MessageBox( "Execution Timeout : Write MAC register", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Write MAC register timeout";
        Application->MessageBox( "Execution Timeout : Write MAC register", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_MAC_STOP:
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Write MAC register stop";
        break;
    }
    CurrentPageReset();
}

//===========================================================================
static AnsiString WIFI_802_11B_TX_RATE[] =
{
    "1",
    "2",
    "5.5",
    "11"
};


static AnsiString WIFI_802_11AG_TX_RATE[] =
{
    "6",
    "9",
    "12",
    "18",
    "24",
    "36",
    "48",
    "54"
};

//---------------------------------------------------------------------------
void  TfrmWiFi::DisplayWiFiTxRate( void )
{
    int i;
    cbTXTxRate->Items->Clear();

    if( m_sWiFiCap.support_802_11b )
    {
        for( i=0; i<sizeof(WIFI_802_11B_TX_RATE)/sizeof(WIFI_802_11B_TX_RATE[0]); i++ )
        {
            cbTXTxRate->Items->Add( WIFI_802_11B_TX_RATE[i] );
        }
    }

    if( m_sWiFiCap.support_802_11a || m_sWiFiCap.support_802_11g )
    {
        for( i=0; i<sizeof(WIFI_802_11AG_TX_RATE)/sizeof(WIFI_802_11AG_TX_RATE[0]); i++ )
        {
            cbTXTxRate->Items->Add( WIFI_802_11AG_TX_RATE[i] );
        }
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static AnsiString WIFI_802_11BG_CHANNEL[] =
{
    "1 (2412000)",
    "2 (2417000)",
    "3 (2422000)",
    "4 (2427000)",
    "5 (2432000)",
    "6 (2437000)",
    "7 (2442000)",
    "8 (2447000)",
    "9 (2452000)",
    "10 (2457000)",
    "11 (2462000)",
    "12 (2467000)",
    "13 (2472000)",
    "14 (2484000)"
};


static AnsiString WIFI_802_11A_CHANNEL[] =
{
    "8 (5040000)",
    "12 (5060000)",
    "16 (5080000)",
    "34 (5170000)",
    "36 (5180000)",
    "38 (5190000)",
    "40 (5200000)",
    "42 (5210000)",
    "44 (5220000)",
    "46 (5230000)",
    "48 (5240000)",
    "52 (5260000)",
    "56 (5280000)",
    "60 (5300000)",
    "64 (5320000)",
    "100 (5500000)",
    "104 (5520000)",
    "108 (5540000)",
    "112 (5560000)",
    "116 (5580000)",
    "120 (5600000)",
    "124 (5620000)",
    "128 (5640000)",
    "132 (5660000)",
    "136 (5680000)",
    "140 (5700000)",
    "149 (5745000)",
    "153 (5765000)",
    "157 (5785000)",
    "161 (5805000)",
    "240 (4920000)",
    "244 (4940000)",
    "248 (4960000)",
    "252 (4980000)"
};

//---------------------------------------------------------------------------
void  TfrmWiFi::DisplayWiFiChannel( void )
{
    int i;
    cbTXChannelID->Items->Clear();
    cbCPRChannelID->Items->Clear();

    if( m_sWiFiCap.support_802_11b || m_sWiFiCap.support_802_11g )
    {
        for( i=0; i<sizeof(WIFI_802_11BG_CHANNEL)/sizeof(WIFI_802_11BG_CHANNEL[0]); i++ )
        {
            cbTXChannelID->Items->Add( WIFI_802_11BG_CHANNEL[i] );
            cbCPRChannelID->Items->Add( WIFI_802_11BG_CHANNEL[i] );
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        for( i=0; i<sizeof(WIFI_802_11A_CHANNEL)/sizeof(WIFI_802_11A_CHANNEL[0]); i++ )
        {
            cbTXChannelID->Items->Add( WIFI_802_11A_CHANNEL[i] );
            cbCPRChannelID->Items->Add( WIFI_802_11A_CHANNEL[i] );
        }
    }

    // m_WIFI_GNRL_Obj.ConfirmCallback = ::ConfirmCallback_QueryChannelList;
    // m_WIFI_GNRL_Obj.REQ_Query_ChannelList_Start( &m_sChannelList );




}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_QueryChannelList( void )
{
    // channel ID
    cbTXChannelID->Items->Clear();
    cbCPRChannelID->Items->Clear();

    for (unsigned int i = 0; i <m_sChannelList.channel_num; i++)
    {
        cbTXChannelID->Items->Add(m_sChannelList.channel_list[i]);
        cbCPRChannelID->Items->Add(m_sChannelList.channel_list[i]);
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::Display_CPTXTxPower( void )
{
    //bool bCcks;
    //int nTxPwr;

    //if( cbTXTxRate->Text.ToInt() < 4)
    //{
    //    bCcks = 1;
    //}
    //else
    //{
    //    bCcks = 0;
    //}

#if 0
    macFunc.ReadTxPowerFromEeprom(m_nCardIndex, m_nChannel, bCcks, &nTxPwr, m_ndBValue, !m_b5GBand);
    m_szHexTxPwr.Format("%x", nTxPwr);
    if(m_szHexTxPwr.GetLength() > 2)
    {
        m_szHexTxPwr = "0";
    }
#endif

}




//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void  TfrmWiFi::Force_WiFi_Stop( void )
{
    TimerWiFi->Enabled = false;
    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_TXALL:
    {
        if( rbTXOP->Checked )
        {
            m_WIFI_TXOP_Obj.REQ_Stop();
        }
        else if( rbTXCS->Checked )
        {
            m_WIFI_TXCS_Obj.REQ_Stop();

        }
        else if( rbCPT->Checked )
        {
            m_WIFI_CPT_Obj.REQ_Stop();
        }
        else
        {
            m_WIFI_LF_Obj.REQ_Stop();
        }
    }
    break;

    case PAGEIDX_CPRX:
        m_WIFI_CPRX_Obj.REQ_Stop();
        break;

    case PAGEIDX_PS:
        m_WIFI_PS_Obj.REQ_Stop();
        break;


    case PAGEIDX_BB:
        m_WIFI_BB_Obj.REQ_Stop();
        break;


    case PAGEIDX_MAC:
        m_WIFI_MAC_Obj.REQ_Stop();
        break;

    case PAGEIDX_EE:
        m_WIFI_EE_Obj.REQ_Stop();
        break;

    case PAGEIDX_SC:
    {
        m_WIFI_SC_Obj.REQ_Stop();
    }
    }


    m_WIFI_STOP_Obj.REQ_Start();
}

//---------------------------------------------------------------------------
unsigned int  TfrmWiFi::ChannelID_To_ChannelFreq( unsigned int channel_id )
{
    unsigned int channel_freq[]=
    {
        2412000, //  1
        2417000, //  2
        2422000, //  3
        2427000, //  4
        2432000, //  5
        2437000, //  6
        2442000, //  7
        2447000, //  8
        2452000, //  9
        2457000, // 10
        2462000, // 11
        2467000, // 12
        2472000, // 13
        2484000  // 14
    };

    return channel_freq[channel_id-1];
}

//---------------------------------------------------------------------------
unsigned int  TfrmWiFi::ChannelFreq_To_ChannelID( unsigned int channel_freq )
{
    int channel_id = 0;
    unsigned int channel_freq_arry[]=
    {
        2412000, //  1
        2417000, //  2
        2422000, //  3
        2427000, //  4
        2432000, //  5
        2437000, //  6
        2442000, //  7
        2447000, //  8
        2452000, //  9
        2457000, // 10
        2462000, // 11
        2467000, // 12
        2472000, // 13
        2484000  // 14
    };

    for( int i=0; i<sizeof(channel_freq); i++)
    {
        if( channel_freq_arry[i] == channel_freq )
        {
            channel_id = i+1;
            break;
        }
    }

    return channel_id;
}

//==========================================================================
void __fastcall TfrmWiFi::TimerWiFiTimer(TObject *Sender)
{

    if (1 == btnTXStart->Tag)
    {
        m_WIFI_CPT_Obj.ConfirmCallback  = ::ConfirmCallback_QueryTxStatus;
        m_WIFI_CPT_Obj.REQ_Query_TxStatus_Start(m_bAlcSupport);
    }
    else if (1 == btnCPRStart->Tag)
    {
        m_WIFI_CPRX_Obj.ConfirmCallback  = ::ConfirmCallback_QueryRxStatus;
        m_WIFI_CPRX_Obj.REQ_QueryRxStatus_Start();
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_QueryTxStatus( void )
{
    int state = m_WIFI_CPT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        WiFi_TxStatus_Ex_S  tx_status;
        tx_status = m_WIFI_CPT_Obj.Get_TxStatus();
        stTXPacketSent->Caption = IntToStr(tx_status.pkt_sent_count);
        stTXAckCount->Caption = IntToStr(tx_status.pkt_sent_acked);
        if (m_bAlcSupport)
        {
            m_stAverageALC->Caption        = IntToStr(tx_status.avgAlc);
            m_stTXCCKGainControl->Caption  = IntToStr(tx_status.cckGainControl);
            m_stTXOFDMGainControl->Caption = IntToStr(tx_status.ofdmGainControl);
        }
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet TX status fail";
        Application->MessageBox( "Execution Failure : Query continuous packet TX status", "FAILURE", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet TX status timeout";
        Application->MessageBox( "Execution Timeout : Query continuous packet TX status", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet TX status stop";
        CurrentPageReset();
    }
    break;
    }

}



//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_QueryRxStatus( void )
{
    int state = m_WIFI_CPRX_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_CPRX_OK:
    {
        WiFi_RxStatus_S  rx_status;
        rx_status = m_WIFI_CPRX_Obj.Get_RxStatus();
        // if( WIFI_BB_IPN2128 == m_final_WiFiId )
        // {
        //     stCPRSuccess->Caption = IntToStr( rx_status.int_rx_ok_num - m_sOriRxStatus.int_rx_ok_num );
        // }
        // else
        {
            stCPRSuccess->Caption = IntToStr( rx_status.pau_rx_pkt_count - m_sOriRxStatus.pau_rx_pkt_count - ( rx_status.pau_crc_err_count - m_sOriRxStatus.pau_crc_err_count ) );
        }
        stCPRCRCErr->Caption  = IntToStr( rx_status.pau_crc_err_count - m_sOriRxStatus.pau_crc_err_count );
        stCPRTotal->Caption   = IntToStr( stCPRSuccess->Caption.ToInt() + stCPRCRCErr->Caption.ToInt() );
        if( stCPRTotal->Caption.ToInt() != 0 )
        {
            char str[20];
            sprintf(str, "%.2f", (float) stCPRCRCErr->Caption.ToInt() * 100.0 / stCPRTotal->Caption.ToInt() );
            stCPRFER->Caption =  (AnsiString) str;
        }
        else
        {
            stCPRFER->Caption = "0";
        }
        stCPRint_rx_ok_num->Caption = IntToStr( rx_status.int_rx_ok_num );
        stCPRint_crc_err_num->Caption = IntToStr( rx_status.int_crc_err_num );
        stCPRpau_rx_ok_count->Caption = IntToStr( rx_status.pau_rx_pkt_count );
        stCPRpau_crc_err_count->Caption = IntToStr( rx_status.pau_crc_err_count );
        stCPRpau_cca_count->Caption = IntToStr( rx_status.pau_cca_count );
        stCPRpau_rx_fifo_full_count->Caption = IntToStr( rx_status.pau_rx_fifo_full_count );

        for( int i=0; i<WIFI_TEST_RATE_COUNT; i++ )
        {
            stCPRGood[i]->Caption = IntToStr( rx_status.int_rate_ok_num[i] - m_sOriRxStatus.int_rate_ok_num[i] );
            stCPRBad[i]->Caption  = IntToStr( rx_status.int_rate_crc_err_num[i] - m_sOriRxStatus.int_rate_crc_err_num[i] );
            stCPRSum[i]->Caption   = IntToStr( stCPRGood[i]->Caption.ToInt() + stCPRBad[i]->Caption.ToInt() );
            if( stCPRSum[i]->Caption.ToInt() != 0 )
            {
                char str[20];
                sprintf(str, "%.2f", (float) stCPRBad[i]->Caption.ToInt() * 100.0 / stCPRSum[i]->Caption.ToInt() );
                stCPRFer[i]->Caption =  (AnsiString) str;
            }
            else
            {
                stCPRFer[i]->Caption = "0";
            }
        }

        // RSSI
        stCPRMin->Caption = IntToStr( rx_status.int_rssi_min );
        stCPRMax->Caption = IntToStr( rx_status.int_rssi_max );
        stCPRMean->Caption = IntToStr( rx_status.int_rssi_mean );
        stCPRVariance->Caption = IntToStr( rx_status.int_rssi_variance );

        // Preamble
        stCPRLong->Caption = IntToStr( rx_status.int_long_preamble_num );
        stCPRShort->Caption = IntToStr( rx_status.int_short_preamble_num );
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status successfully";
    }
    break;

    case STATE_CPRX_FAIL:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status fail";
        Application->MessageBox( "Execution Failure : Query continuous packet RX status", "FAILURE", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_TIMEOUT:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status timeout";
        Application->MessageBox( "Execution Timeout : Query continuous packet RX status", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_CPRX_STOP:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status stop";
        CurrentPageReset();
    }
    break;
    }

}

//===========================================================================
//////////////////////////////////     BBCR    //////////////////////////////
//===========================================================================
void TfrmWiFi::AllocateBBCRVector( void )
{
    if( NULL == m_pvBBCRDisp  )
    {
        m_pvBBCRDisp    = new vector<WiFi_BBReg8_S>;
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::EraseBBCRVector( void )
{
    if( NULL == m_pvBBCRDisp  )
    {
        if( ! m_pvBBCRDisp->empty() )
        {
            m_pvBBCRDisp->erase( m_pvBBCRDisp->begin(), m_pvBBCRDisp->end() );
        }
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::DeAllocateBBCRVector( void )
{
    if( m_pvBBCRDisp != NULL )
    {
        if( ! m_pvBBCRDisp->empty() )
        {
            m_pvBBCRDisp->erase( m_pvBBCRDisp->begin(), m_pvBBCRDisp->end() );
        }
        delete m_pvBBCRDisp;
        m_pvBBCRDisp = NULL;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnBBDumpBBRegClick(TObject *Sender)
{
    if( !CheckFields( ACCESS_DUMP, OP_READ ) )
    {
        sbBB->Panels->Items[0]->Text = (AnsiString) "  Dump baseband registers fail";
        Application->MessageBox( "Execution Failure : Dump baseband registers", "FAILURE", MB_OK );
        return;
    }

    FillBBResult(true);

    CurrentPageLock();
    m_uiBBCount=0;
    Compose_BBCR_Parameter( ACCESS_DUMP );

    AllocateBBCRVector();
    EraseBBCRVector();

    m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllBBReg;
    m_WIFI_BB_Obj.REQ_Read_BBCR_Setting_From_Reg_Start( m_sBBCR );
    sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump baseband registers progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadAllBBReg( void )
{
    int state = m_WIFI_BB_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_BB_OK:
    {
        m_sBBCR = m_WIFI_BB_Obj.Get_BBCR();
        for (unsigned int i=0; i<m_sBBCR.count; i++ )
        {
            WiFi_BBReg8_S bbcr;
            bbcr.index = m_sBBCR.bb_reg8[i].index;
            bbcr.bbcr_data8 = m_sBBCR.bb_reg8[i].bbcr_data8;
            m_pvBBCRDisp->push_back( bbcr );
        }

        if( m_sBBCR.bb_reg8[m_sBBCR.count-1].index < m_uiBBEndIdx )
        {
            Compose_BBCR_Parameter( ACCESS_DUMP );
            m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllBBReg;
            m_WIFI_BB_Obj.REQ_Read_BBCR_Setting_From_Reg_Start( m_sBBCR );
        }
        else
        {
            FillBBResult( false );
            sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump baseband registers successfully";
            CurrentPageReset();
        }
    }
    break;

    case STATE_BB_FAIL:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump baseband registers fail";
        Application->MessageBox( "Execution Timeout : Dump baseband registers", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_BB_TIMEOUT:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump baseband registers timeout";
        Application->MessageBox( "Execution Timeout : Dump baseband registers", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_BB_STOP:
    {
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump baseband registers stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnBBCRDataClick(TObject *Sender)
{
    if( btnBBCRData->Tag==0 )  // Dec-->Hex
    {
        btnBBCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnBBCRData->Tag = 0;
    }
    ReDrawFields( PAGEIDX_BB );
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnMACMCRDataClick(TObject *Sender)
{
    if( btnMACMCRData->Tag==0 )  // Dec-->Hex
    {
        btnMACMCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnMACMCRData->Tag = 0;
    }
    ReDrawFields( PAGEIDX_MAC );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnEEDataClick(TObject *Sender)
{
    if( 0 == btnEEData->Tag )  // Dec-->Hex
    {
        btnEEData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnEEData->Tag = 0;
    }
    ReDrawFields( PAGEIDX_EE );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnEEReadClick(TObject *Sender)
{
    AnsiString text;
    unsigned int ee_addr;

    text = edtEEIndex->Text;
    if( !IsValidHexWiFiEERegAddr( text, &ee_addr ) )
    {
        edtMACMCRAddressCheck(edtMACMCRAddress);
        return;
    }
    m_uiEEPROMIdx = ee_addr;
    Compose_EEPROM_Parameter( ACCESS_SINGLE );

    CurrentPageLock();
    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadEE( void )
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        DeCompose_EEPROM_Data( ACCESS_SINGLE );
        ReDrawFields( PAGEIDX_EE );
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM fail";
        Application->MessageBox( "Execution Fail : Read EEPROM", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case META_TIMEOUT:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Read EEPROM", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case METAAPP_STOP:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM stop";
    }
    break;
    }
    CurrentPageReset();
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnEEWriteClick(TObject *Sender)
{
#if 0
    if( ! CheckFields( ACCESS_SINGLE, OP_WRITE ) )
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString) "  Write EEPROM fail";
        Application->MessageBox( "Execution Failure : Write EEPROM", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();
    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_WriteEE;
    m_WIFI_EE_Obj.REQ_Write_To_EE_Start( m_sEE );
#endif

    if( !CheckFields( ACCESS_SINGLE, OP_WRITE ) )
    {
        sbEE->Panels->Items[0]->Text = (AnsiString) "  Write EEPROM fail";
        Application->MessageBox( "Execution Failure : Write EEPROM", "FAILURE", MB_OK );
        return;
    }
    Compose_EEPROM_Parameter( ACCESS_SINGLE );
    Compose_EEPROM_Data( ACCESS_SINGLE );
    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_WriteEE;
    m_WIFI_EE_Obj.REQ_Write_To_EE_Start( m_sEE );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_WriteEE( void )
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM fail";
        Application->MessageBox( "Execution Timeout : Write EEPROM", "FAIL", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case META_TIMEOUT:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Write EEPROM", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case METAAPP_STOP:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM stop";
    }
    break;
    }
    CurrentPageReset();
}

void __fastcall TfrmWiFi::edtEEIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int uidata;
    TEdit *edit = (TEdit*)Sender;
    AnsiString as_hint = " value is not valid ";

    char  hint[256];
    strcpy( hint, as_hint.c_str() );

    text = edit->Text;
    if( !IsValidHexWiFiEERegAddr( text, &uidata )  )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    // if( usdata > m_sWiFiCap.eeprom_size  )
    // {
    //     ShowHintLabel( edit, hint );
    //     edit->SetFocus();
    //     return;
    // }

    // if( 0 != uidata%2 )
    // {
    //     ShowHintLabel( edit, hint );
    //     edit->SetFocus();
    //     return;
    // }

    // if( uidata >= m_sWiFiCap.eeprom_size-1 )
    // {
    //     ShowHintLabel( edit, hint );
    //      edit->SetFocus();
    //      return;
    // }

    m_uiEEPROMIdx = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtEEDataCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned short  usdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnEEData->Tag )  // Dec
    {
        if( !IsValidDecWiFiEERegValue( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    if( 1 == btnEEData->Tag ) // Hex
    {
        if( !IsValidHexWiFiEERegValue( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sEE.eeprom[0].eeprom_data16 = usdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXTxChannelPowerClick(TObject *Sender)
{
    frmWiFiTxProfile->Top  = 152;
    frmWiFiTxProfile->Left = 152;
    frmWiFiTxProfile->Show();
}


void __fastcall TfrmWiFi::btnTXOPUploadFromFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) " NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_ReadTxPower2400MFromNVRAM;
        m_WIFI_APC_Obj.REQ_Read_TxPower2400M_From_NVRAM_Start();
    }
    else if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_ReadTxPower5000MFromNVRAM;
        m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_NVRAM_Start();
    }
}

//---------------------------------------------------------------------------
void  TfrmWiFi::TXOP_UploadTxPower2400MFromFlashDone( void )
{
#if 0
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();
    char  str[20];
    float  fdata;



    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr2400M = m_WIFI_APC_Obj.Get_TxChannelDac2400M();
        if( m_sWiFiCap.support_802_11a )
        {
            m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_ReadTxPower5000MFromNVRAM;
            m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_NVRAM_Start();
        }
        else
        {
            ReDrawFields( PAGEIDX_TXOP );
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting from flash successful";
            CurrentPageReset();
        }
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload TX channel power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload TX channel power setting", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting stop";
        CurrentPageReset();
    }
    break;
    }
#endif
}

//---------------------------------------------------------------------------
void  TfrmWiFi::TXOP_UploadTxPower5000MFromFlashDone( void )
{
#if 0
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();
    char  str[20];
    float  fdata;



    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxPwr5000M = m_WIFI_APC_Obj.Get_TxChannelDac5000M();
        ReDrawFields( PAGEIDX_TXOP );
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting from flash successful";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload TX channel power setting, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting timeout";
        Application->MessageBox( "Execution Timeout : Upload TX channel power setting", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Upload TX channel power setting stop";
    }
    break;
    }
    CurrentPageReset();
#endif
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXOPDownloadToFlashClick(TObject *Sender)
{
    // if( !CheckFields() )
    // {
    //    // sbBB->Panels->Items[0]->Text = (AnsiString) "  Write baseband register fail";
    //    // Application->MessageBox( "Execution Failure : Write baseband register", "FAILURE", MB_OK );
    //     return;
    // }

    if( ! NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_WriteTxPower2400MToNVRAM;
        m_WIFI_APC_Obj.REQ_Write_TxPower2400M_To_NVRAM_Start();
    }
    else if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_WriteTxPower5000MToNVRAM;
        m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
    }
}

//---------------------------------------------------------------------------
void  TfrmWiFi::TXOP_DownloadTxPower2400MToFlashDone( void )
{
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        if( m_sWiFiCap.support_802_11a )
        {
            m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
            m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_WriteTxPower5000MToNVRAM;
            m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_NVRAM_Start();
        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash successful";
            CurrentPageReset();
        }
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX channel power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX channel power setting to flash", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash stop";
        CurrentPageReset();
    }
    break;
    }


}

//---------------------------------------------------------------------------
void  TfrmWiFi::TXOP_DownloadTxPower5000MToFlashDone( void )
{
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash successful";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download TX channel power setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download TX channel power setting to flash", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Download TX channel power setting to flash stop";
    }
    break;
    }

    CurrentPageReset();
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXOPChangeDBClick(TObject *Sender)
{
    frmMainSel->mnuFDMDatabaseClick(Sender);
    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
        return;
    }
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Change NVRAM database file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXOPLoadFromFileClick(TObject *Sender)
{
#if 0
    char str[512];
    bool ok;
    float  fdata;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Load TX channel power setting from file fail";
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        ok = m_WIFI_APC_Obj.REQ_Read_TxPower2400M_From_File( str );
        if( ok )
        {
            m_sTxPwr2400M = m_WIFI_APC_Obj.Get_TxChannelDac2400M();

        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Load TX channel power setting from file fail";
            Application->MessageBox( "Execution Failure : Load TX channel power setting from file", "FAILURE", MB_OK );
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        ok = m_WIFI_APC_Obj.REQ_Read_TxPower5000M_From_File( str );
        if( ok )
        {
            m_sTxPwr5000M = m_WIFI_APC_Obj.Get_TxChannelDac5000M();
        }
        else
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Load TX channel power setting from file fail";
            Application->MessageBox( "Execution Failure : Load TX channel power setting from file", "FAILURE", MB_OK );
        }
    }

    ReDrawFields( PAGEIDX_TXOP );
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Load TX channel power setting from file successfully";
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXOPSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Save TX channel power setting to file fail";
        return;
    }

    strcpy( str, SaveDialog->FileName.c_str() );

    if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
        ok = m_WIFI_APC_Obj.REQ_Write_TxPower2400M_To_File( str );
        if( !ok )
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Save TX channel power setting to file fail";
            Application->MessageBox( "Execution Failure : Save TX channel power setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    if( m_sWiFiCap.support_802_11a )
    {
        m_WIFI_APC_Obj.Set_TxChannelDac5000M( m_sTxPwr5000M );
        ok = m_WIFI_APC_Obj.REQ_Write_TxPower5000M_To_File( str );
        if( !ok )
        {
            sbTX->Panels->Items[0]->Text = (AnsiString) "  Save TX channel power setting to file fail";
            Application->MessageBox( "Execution Failure : Save TX channel power setting to file", "FAILURE", MB_OK );
            return;
        }
    }
    sbTX->Panels->Items[0]->Text = (AnsiString) "  Save TX channel power setting to file successfully";
}

//---------------------------------------------------------------------------
void TfrmWiFi::REQ_TXOP_SetDbmToDac( int dbm )
{
#if 0
    WiFi_DBM2DAC_Set_S dbm2dac_set;
    dbm2dac_set.ch_freq = ChannelID_To_ChannelFreq( cbTXOPChannelID->Text.ToInt() );
    dbm2dac_set.tx_rate = (WiFi_TestRate_E) (WiFi_TestRate_E) GetWiFiTxRateFromStr( cbTXOPTXRate->Text );
    dbm2dac_set.dbm     = dbm;
    m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_SetDbmToDac;
    m_WIFI_APC_Obj.REQ_SetDbmToDac_Start( dbm2dac_set );
#endif
}

//---------------------------------------------------------------------------
void TfrmWiFi::CNF_TXOP_SetDbmToDac( void )
{
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Set dBm to DAC successful";
        m_WIFI_APC_Obj.ConfirmCallback = ::CNF_TXOP_QueryDbmToDac;
        m_WIFI_APC_Obj.REQ_QueryDbmToDac_Start( );
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Set dBm to DAC fail";
        Application->MessageBox( "Execution Failure : Set dBm to DAC", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Set dBm to DAC timeout";
        Application->MessageBox( "Execution Timeout : Set dBm to DAC", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Set dBm to DAC stop";
        CurrentPageReset();
    }
    break;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::CNF_TXOP_QueryDbmToDac( void )
{
#if 0
    META_RESULT state = m_WIFI_APC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        ReDrawFields( PAGEIDX_TXOP );
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Query dBm to DAC successful";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Query dBm to DAC fail";
        Application->MessageBox( "Execution Failure : Query dBm to DAC", "FAILURE", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Query dBm to DAC timeout";
        Application->MessageBox( "Execution Timeout : Query dBm to DAC", "TIMEOUT", MB_OK );

    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  Set dBm to DAC stop";

    }
    break;
    }
    CurrentPageReset();
#endif
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::rbTXOPMaxClick(TObject *Sender)
{
    REQ_TXOP_SetDbmToDac( WIFI_DBM_MAX );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbTXOP0dBmClick(TObject *Sender)
{
    REQ_TXOP_SetDbmToDac( WIFI_DBM_0 );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbTXOP5dBmClick(TObject *Sender)
{
    REQ_TXOP_SetDbmToDac( WIFI_DBM_5 );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbTXOP10dBmClick(TObject *Sender)
{
    REQ_TXOP_SetDbmToDac( WIFI_DBM_10 );
}

//===========================================================================
//////////////////////////////////     MCR    //////////////////////////////
//===========================================================================
void TfrmWiFi::AllocateMCRVector( void )
{
    if( NULL == m_pvMCRDisp  )
    {
        m_pvMCRDisp    = new vector<WiFi_MACReg32_S>;
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::EraseMCRVector( void )
{
    if( NULL == m_pvMCRDisp  )
    {
        if( ! m_pvMCRDisp->empty() )
        {
            m_pvMCRDisp->erase( m_pvMCRDisp->begin(), m_pvMCRDisp->end() );
        }
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::DeAllocateMCRVector( void )
{
    if( m_pvMCRDisp != NULL )
    {
        if( ! m_pvMCRDisp->empty() )
        {
            m_pvMCRDisp->erase( m_pvMCRDisp->begin(), m_pvMCRDisp->end() );
        }
        delete m_pvMCRDisp;
        m_pvMCRDisp = NULL;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::AllocateMCR16Vector( void )
{
    if( NULL == m_pvMCR16Disp  )
    {
        m_pvMCR16Disp    = new vector<WiFi_MACReg16_S>;
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::EraseMCR16Vector( void )
{
    if( NULL == m_pvMCR16Disp  )
    {
        if( ! m_pvMCR16Disp->empty() )
        {
            m_pvMCR16Disp->erase( m_pvMCR16Disp->begin(), m_pvMCR16Disp->end() );
        }
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::DeAllocateMCR16Vector( void )
{
    if( m_pvMCR16Disp != NULL )
    {
        if( ! m_pvMCR16Disp->empty() )
        {
            m_pvMCR16Disp->erase( m_pvMCR16Disp->begin(), m_pvMCR16Disp->end() );
        }
        delete m_pvMCR16Disp;
        m_pvMCR16Disp = NULL;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnMACDumpAllMacRegClick(TObject *Sender)
{
    if( !CheckFields( ACCESS_DUMP, OP_READ ) )
    {
        sbBB->Panels->Items[0]->Text = (AnsiString) "  Dump baseband registers fail";
        Application->MessageBox( "Execution Failure : Dump baseband registers", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();

    FillMACResult(true);
    m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllMACReg;
    m_uiMACCount=0;
    if( rbMAC16bits->Checked )
    {
        AllocateMCR16Vector();
        EraseMCR16Vector();
        Compose_MCR16_Parameter( ACCESS_DUMP );
        m_WIFI_MAC_Obj.REQ_Read_MCR16_Setting_From_Reg_Start( m_sMCR16 );
    }
    else
    {
        AllocateMCRVector();
        EraseMCRVector();
        Compose_MCR_Parameter( ACCESS_DUMP );
        m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
    }

    sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump all MAC register progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadAllMACReg( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        if( rbMAC16bits->Checked )
        {
            m_sMCR16 = m_WIFI_MAC_Obj.Get_MCR16();
            for (unsigned int i=0; i<m_sMCR16.count; i++ )
            {
                m_pvMCR16Disp->push_back( m_sMCR16.mac_reg16[i] );
            }
        }
        else
        {
            m_sMCR = m_WIFI_MAC_Obj.Get_MCR();
            for (unsigned int i=0; i<m_sMCR.count; i++)
            {
                m_pvMCRDisp->push_back(m_sMCR.mac_reg32[i]);
            }
        }



        m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllMACReg;

        if( rbMAC16bits->Checked )
        {
            if( m_sMCR16.mac_reg16[m_sMCR16.count-1].index < m_uiMacEndAddr )
            {
                Compose_MCR16_Parameter( ACCESS_DUMP );
                m_WIFI_MAC_Obj.REQ_Read_MCR16_Setting_From_Reg_Start( m_sMCR16 );
            }
            else
            {
                FillMACResult( false );
                sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump MAC registers successfully";
                CurrentPageReset();
            }
        }
        else
        {
            if( m_sMCR.mac_reg32[m_sMCR.count-1].index < m_uiMacEndAddr )
            {
                Compose_MCR_Parameter( ACCESS_DUMP );
                m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
            }
            else
            {
                FillMACResult( false );
                sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump MAC registers successfully";
                CurrentPageReset();
            }
        }

    }
    break;

    // case STATE_MAC_SECTION_OK:
    // {
    //     FillMACResult( false );
    //     m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllMACReg;
    //    // m_WIFI_MAC_Obj.REQ_Read_From_AllReg();
    //
    //    // sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump all baseband register successfully";
    // }
    //  break;

    case STATE_MAC_FAIL:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump MAC registers fail";
        Application->MessageBox( "Execution Timeout : Dump MAC registers", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump MAC registers timeout";
        Application->MessageBox( "Execution Timeout : Dump MAC registers", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_MAC_STOP:
    {
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Dump MAC registers stop";
        CurrentPageReset();
    }
    break;
    }

}

//============================================================================
//////////////////////////////////     EEPRM    //////////////////////////////
//============================================================================
//--------------------------------------------------------------------------
void TfrmWiFi::AllocateEEPROMVector( void )
{
    if( NULL == m_pvEEDisp  )
    {
        m_pvEEDisp    = new vector<WiFi_EEPROM_S>;
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::EraseEEPROMVector( void )
{
    if( NULL == m_pvEEDisp  )
    {
        if( ! m_pvEEDisp->empty() )
        {
            m_pvEEDisp->erase( m_pvEEDisp->begin(), m_pvEEDisp->end() );
        }
    }
}

//--------------------------------------------------------------------------
void TfrmWiFi::DeAllocateEEPROMVector( void )
{
    if( m_pvEEDisp != NULL )
    {
        if( ! m_pvEEDisp->empty() )
        {
            m_pvEEDisp->erase( m_pvEEDisp->begin(), m_pvEEDisp->end() );
        }
        delete m_pvEEDisp;
        m_pvEEDisp = NULL;
    }
}

//----------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnEEClick(TObject *Sender)
{
    if( !CheckFields( ACCESS_DUMP, OP_READ ) )
    {
        sbEE->Panels->Items[0]->Text = (AnsiString) "  Dump EEPROM fail";
        Application->MessageBox( "Execution Failure : Dump EEPROM", "FAILURE", MB_OK );
        return;
    }

    FillEEResult(true);

    CurrentPageLock();
    m_uiEEPROMCount = 0;
    Compose_EEPROM_Parameter( ACCESS_DUMP );

//    m_uiDispEEPROMCount = 0;


    AllocateEEPROMVector();
    EraseEEPROMVector();

    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );
    sbEE->Panels->Items[0]->Text = (AnsiString)"  Dump EEPROM progressing";

}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadAllEE( void )
{
    int state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        for (unsigned int i=0; i<m_sEE.count; i++ )
        {
            WiFi_EEPROM_S eeprom;
            eeprom.index = m_sEE.eeprom[i].index;
            eeprom.eeprom_data16 = m_sEE.eeprom[i].eeprom_data16;
            m_pvEEDisp->push_back( eeprom );
        }
        //  m_uiDispEEPROMCount += m_sEE.count;
        //FillEEResult( false );
        if( m_sEE.eeprom[m_sEE.count-1].index < m_uiEEPROMEndIdx )
        {

            Compose_EEPROM_Parameter( ACCESS_DUMP );
            m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllEE;
            m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );
        }
        else
        {
            FillEEResult( false );
            sbEE->Panels->Items[0]->Text = (AnsiString)"  Dump all EEPROM successfully";
            CurrentPageReset();
        }
    }
    break;

    // case STATE_EE_SECTION_OK:
    //  {
    //     FillEEResult( false );
    //     m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadAllEE;
    //     m_WIFI_EE_Obj.REQ_Read_From_AllEE();
    //
    //     sbBB->Panels->Items[0]->Text = (AnsiString)"  Dump all baseband register successfully";
    //  }
    // break;

    case META_FAILED:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Dump all EEPROM fail";
        Application->MessageBox( "Execution Timeout : Dump all EEPROM", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Dump all EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Dump all EEPROM", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Dump all EEPROM stop";
        CurrentPageReset();
    }
    break;
    }

}

//----------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnPSStartClick(TObject *Sender)
{
    CurrentPageLock();
    m_WIFI_PS_Obj.ConfirmCallback  = ::ConfirmCallback_PS;
    m_WIFI_PS_Obj.REQ_Start( (WiFi_PowerManagementMode_E) cbPSPowerMode->ItemIndex +1);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_PS( void )
{
    int state = m_WIFI_PS_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_PS_OK:
    {
        sbPS->Panels->Items[0]->Text = (AnsiString)"  Power saving test progressing";
    }
    break;

    case STATE_PS_FAIL:
    {
        sbPS->Panels->Items[0]->Text = (AnsiString)"  Power saving test fail";
        Application->MessageBox( "Execution Timeout : Power saving test ", "FAIL", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_PS_TIMEOUT:
    {
        sbPS->Panels->Items[0]->Text = (AnsiString)"  Power saving test timeout";
        Application->MessageBox( "Execution Timeout : Power saving test ", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
        CurrentPageReset();
    }
    break;

    case STATE_PS_STOP:
    {
        sbPS->Panels->Items[0]->Text = (AnsiString)"  Power saving test stop";
        CurrentPageReset();
    }
    break;
    }

}


void __fastcall TfrmWiFi::btnPSStopClick(TObject *Sender)
{
    if( 1 == btnPSStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbPS->Panels->Items[0]->Text = (AnsiString)"  Stop power saving test successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnCPRQueryRxCounterClick(TObject *Sender)
{
    CurrentPageLock();
    m_WIFI_CPRX_Obj.ConfirmCallback  = ::ConfirmCallback_QueryRxCounter;
    m_WIFI_CPRX_Obj.REQ_QueryRxCounter_Start();
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_QueryRxCounter( void )
{
    int state = m_WIFI_CPRX_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_CPRX_OK:
    {
        WiFi_RxCounter_S  rx_counter;
        rx_counter = m_WIFI_CPRX_Obj.Get_RxCounter();
        stCPRED->Caption = IntToStr( rx_counter.ED );
        stCPROSD->Caption = IntToStr( rx_counter.OSD );
        stCPRSQ1->Caption = IntToStr( rx_counter.SQ1 );
        stCPRSFD->Caption = IntToStr( rx_counter.SFD );
        stCPRCRC16->Caption = IntToStr( rx_counter.CRC16 );

        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX counter successfully";
    }
    break;

    case STATE_CPRX_FAIL:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX counter fail";
        Application->MessageBox( "Execution Failure : Query continuous packet RX counter", "FAILURE", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_CPRX_TIMEOUT:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX counter timeout";
        Application->MessageBox( "Execution Timeout : Query continuous packet RX counter", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case STATE_CPRX_STOP:
    {
        sbCPR->Panels->Items[0]->Text = (AnsiString)"  Query continuous packet RX status stop";
    }
    break;
    }
    CurrentPageReset();
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXTxPowerDacClick(TObject *Sender)
{
    if( 0 == btnTXTxPowerDac->Tag )  // Dec-->Hex
    {
        btnTXTxPowerDac->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXTxPowerDac->Tag = 0;
    }
    ReDrawFields( PAGEIDX_TXALL );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXOPTxPowerDacClick(TObject *Sender)
{
#if 0
    if( 0 == btnTXOPTxPowerDac->Tag )  // Dec-->Hex
    {
        btnTXOPTxPowerDac->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXOPTxPowerDac->Tag = 0;
    }
    ReDrawFields( PAGEIDX_TXOP );
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXCSTxPowerDacClick(TObject *Sender)
{
#if 0
    if( 0 == btnTXTxPowerDac->Tag )  // Dec-->Hex
    {
        btnTXTxPowerDac->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXTxPowerDac->Tag = 0;
    }
    ReDrawFields( PAGEIDX_TXCS );
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnLFTxPowerDacClick(TObject *Sender)
{
#if 0
    if( 0 == btnLFTxPowerDac->Tag )  // Dec-->Hex
    {
        btnLFTxPowerDac->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnLFTxPowerDac->Tag = 0;
    }
    ReDrawFields( PAGEIDX_LF );
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXOPTxPowerDACCheck(TObject *Sender)
{
#if 0
    unsigned char  us_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";


    text = edit->Text;
    if( 0 == btnTXOPTxPowerDac->Tag )  // Dec
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
    m_sTxPwr2400M.CCKTxPWR[cbTXOPChannelID->ItemIndex] = uc_data;
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXCSTxPowerDACCheck(TObject *Sender)
{
#if 0
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";


    text = edit->Text;
    if( 0 == btnTXCSTxPowerDac->Tag )  // Dec
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
    m_sTxPwr2400M.CCKTxPWR[cbTXCSChannelID->ItemIndex] = uc_data;
#endif
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtLFTxPowerDACCheck(TObject *Sender)
{
#if 0
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";


    text = edit->Text;
    if( 0 == btnTXTxPowerDac->Tag )  // Dec
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
    m_sTxPwr2400M.CCKTxPWR[cbLFChannelID->ItemIndex] = uc_data;
#endif
}
//---------------------------------------------------------------------------




void __fastcall TfrmWiFi::miCopyClick(TObject *Sender)
{
    switch(pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_BB:
    {
        memBBResult->SelectAll();
        memBBResult->CopyToClipboard();
    }
    break;

    case PAGEIDX_MAC:
    {
        memMACResult->SelectAll();
        memMACResult->CopyToClipboard();
    }
    break;

    case PAGEIDX_EE:
    {
        memEEResult->SelectAll();
        memEEResult->CopyToClipboard();
    }
    break;
    }


}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnBBStopClick(TObject *Sender)
{
    if( 1 == btnBBRead->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbBB->Panels->Items[0]->Text = (AnsiString)"  Stop baseband register read/write successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnMACStopClick(TObject *Sender)
{
    if( 1 == btnMACRead->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbMAC->Panels->Items[0]->Text = (AnsiString)"  Stop MAC register read/write successfully";
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnEEStopClick(TObject *Sender)
{
    if( 1 == btnEERead->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        sbEE->Panels->Items[0]->Text = (AnsiString)"  Stop EEPRom read/write successfully";
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmWiFi::rbTXOPClick(TObject *Sender)
{
    DisableCPTUIComponent();

}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbTXCSClick(TObject *Sender)
{
    DisableCPTUIComponent();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbTXLFClick(TObject *Sender)
{
    DisableCPTUIComponent();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbCPTClick(TObject *Sender)
{
    EnableCPTUIComponent();
}
//---------------------------------------------------------------------------



void __fastcall TfrmWiFi::btnTXCalTxDCClick(TObject *Sender)
{
    m_WIFI_TXDC_Obj.ConfirmCallback  = ::ConfirmCallback_TxDcOffsetCal;
    m_WIFI_TXDC_Obj.REQ_TxDcOffsetCal_Start();
    CurrentPageLock();
    sbTX->Panels->Items[0]->Text = (AnsiString)"  TX DC offset calibration progressing";
}

//-------------------------------------------------------
void  TfrmWiFi::ConfirmCallback_TxDcOffsetCal( void )
{
    META_RESULT state = m_WIFI_TXDC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sTxDcOffset = m_WIFI_TXDC_Obj.Get_TxDcOffset();
        ReDrawFields( PAGEIDX_TXALL );
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX DC offset calibration successfully";

    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX DC offset calibration fail";
        Application->MessageBox( "Execution Failure : TX DC offset calibration", "FAILURE", MB_OK );
        Force_WiFi_Stop();

    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX DC offset calibration timeout";
        Application->MessageBox( "Execution Timeout : TX DC offset calibration TX", "TIMEOUT", MB_OK );
        Force_WiFi_Stop();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  TX DC offset calibration stop";
    }
    break;
    }

    CurrentPageReset();
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXFramCtrlCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderFrameCtrl( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.frame_ctrl[edit->Tag] = ucdata;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::edtTXDurationCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderDuration( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.duration[edit->Tag] = ucdata;
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXAddress1Check(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.address1[edit->Tag] = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXAddress2Check(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.address2[edit->Tag] = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXAddress3Check(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.address3[edit->Tag] = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXSeqCtrlCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacHeaderSeqCtrl( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sWiFiCPT.s_mac_header.seq_ctrl[edit->Tag] = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXIDcOffsetCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;

    if( 0 == btnTXIDC->Tag ) // Dec
    {
        if( !IsValidDecWiFiTxDcOffset( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiTxDcOffset( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sTxDcOffset.i_ch_offset = ucdata;




}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtTXQDCOffsetCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;

    if( 0 == btnTXQDC->Tag ) // Dec
    {
        if( !IsValidDecWiFiTxDcOffset( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiTxDcOffset( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sTxDcOffset.q_ch_offset = ucdata;
}
//---------------------------------------------------------------------------








void __fastcall TfrmWiFi::btnTXIDCClick(TObject *Sender)
{
    if( 0 == btnTXIDC->Tag )  // Dec-->Hex
    {
        btnTXIDC->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXIDC->Tag = 0;
    }
    ReDrawFields( PAGEIDX_TXALL );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXQDCClick(TObject *Sender)
{
    if( 0 == btnTXQDC->Tag )  // Dec-->Hex
    {
        btnTXQDC->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXQDC->Tag = 0;
    }
    ReDrawFields( PAGEIDX_TXALL );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXDCUploadFromFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) " NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();
    m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_ReadTxDCFromNVRAM;
    m_WIFI_TXDC_Obj.REQ_Read_From_NVRAM_Start();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnTXDCDownloadToFlashClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if( ! NVRAMMan->Get_IsInit() )
    {
        sbTX->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();

    m_WIFI_TXDC_Obj.Set_TxDcOffset( m_sTxDcOffset );
    m_WIFI_TXDC_Obj.ConfirmCallback = ::CNF_WriteTxDCToNVRAM;
    m_WIFI_TXDC_Obj.REQ_Write_To_NVRAM_Start();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnBBRegSettingClick(TObject *Sender)
{
    frmWiFiBBCR->Top  = 1;
    frmWiFiBBCR->Left = 77;
    frmWiFiBBCR->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnMACRegSettingClick(TObject *Sender)
{
    frmWiFiMCR->Top  = 1;
    frmWiFiMCR->Left = 77;
    frmWiFiMCR->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnSCStartClick(TObject *Sender)
{
    if( stSCScriptFile->Caption.AnsiCompareIC("") == 0 )
    {
        stSC->Panels->Items[0]->Text = (AnsiString)"  Please select script file before start test";
        Application->MessageBox( "Execution Timeout : Please select script file before start test", "FAIL", MB_OK );
        return;
    }
    S_WIFISC  wifisc;
    wifisc.hPostMsgDestHandle = this->Handle;
    wifisc.filename           = stSCScriptFile->Caption;
    wifisc.log                = m_pSCLog;

    CurrentPageLock();
    m_WIFI_SC_Obj.ConfirmCallback  = ::ConfirmCallback_SC;
    m_WIFI_SC_Obj.REQ_Start( wifisc );
}

//---------------------------------------------------------------------------
void TfrmWiFi::ConfirmCallback_SC( void )
{
    int state = m_WIFI_SC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_SC_OK:
    {

        stSC->Panels->Items[0]->Text = (AnsiString)"  Script test successfully";
    }
    break;

    case STATE_SC_FAIL:
    {

        stSC->Panels->Items[0]->Text = (AnsiString)"  Script test fail";
        Application->MessageBox( "Execution Fail : Script test", "FAIL", MB_OK );
        // Force_WiFi_Stop();
    }
    break;

    case STATE_SC_TIMEOUT:
    {

        stSC->Panels->Items[0]->Text = (AnsiString)"  Script test timeout";
        Application->MessageBox( "Execution Timeout : Script test", "TIMEOUT", MB_OK );
        //Force_WiFi_Stop();
    }
    break;

    case STATE_SC_STOP:
        stSC->Panels->Items[0]->Text = (AnsiString)"  Script test stop";
        break;
    }
    FillSCResult();
    CurrentPageReset();
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::btnSCStopClick(TObject *Sender)
{
    if( 1 == btnSCStart->Tag )
    {
        Force_WiFi_Stop();
        CurrentPageReset();
        stSC->Panels->Items[0]->Text = (AnsiString)"  Stop script test successfully";
    }
}
//---------------------------------------------------------------------------

//===========================================================================
void __fastcall TfrmWiFi::btnSCScriptFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = dlgOpenScriptFile->Execute();
    if( !ok )
    {
        stSC->Panels->Items[0]->Text = (AnsiString) "  Load script file fail";
        return;
    }
    strcpy( str, dlgOpenScriptFile->FileName.c_str() );
    //ok = m_WIFI_SC_Obj.REQ_Open_File( str );

    stSCScriptFile->Caption = str;
    stSC->Panels->Items[0]->Text = (AnsiString) "  Setup script file successfully";

}

//--------------------------------------------------------------------------
void TfrmWiFi::FillSCResult( void )
{

    for(int i=0; i<m_pSCLog->Count; i++ )
    {
        memSCResult->Lines->Add(m_pSCLog->Strings[i]);
    }
    m_pSCLog->Clear();

}



//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnEEPROMSettingClick(TObject *Sender)
{
    frmWiFiEEPROM->Top  = 1;
    frmWiFiEEPROM->Left = 77;
    frmWiFiEEPROM->Show();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TfrmWiFi::Compose_BBCR_Parameter( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sBBCR.count     = 1;
        m_sBBCR.bb_reg8[0].index = m_uiBBIdx;
    }
    else
    {
        m_sBBCR.count     = m_uiBBEndIdx - m_uiBBBeginIdx - m_uiBBCount*WIFI_MAX_COUNT + 1;

        if( m_sBBCR.count > WIFI_MAX_COUNT )  m_sBBCR.count = WIFI_MAX_COUNT;

        for (unsigned int i=0; i<m_sBBCR.count; i++)
        {
            m_sBBCR.bb_reg8[i].index = m_uiBBBeginIdx + i + m_uiBBCount*WIFI_MAX_COUNT;;
        }
        m_uiBBCount++;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::Compose_BBCR_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sBBCR.bb_reg8[0].bbcr_data8 = m_ucBBValue;
    }
    else
    {
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::DeCompose_BBCR_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_ucBBValue = m_sBBCR.bb_reg8[0].bbcr_data8;
    }
    else
    {
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::Compose_MCR_Parameter( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sMCR.count                = 1;
        m_sMCR.mac_reg32[0].index   = m_uiMacAddr;
    }
    else
    {
        int data_size = sizeof(m_sMCR.mac_reg32[0].mcr_data32);
        m_sMCR.count     = (m_uiMacEndAddr - m_uiMacBeginAddr)/data_size + 1 - m_uiMACCount*WIFI_MAX_COUNT;

        if( m_sMCR.count > WIFI_MAX_COUNT )  m_sMCR.count = WIFI_MAX_COUNT;

        for (unsigned  int i=0; i<m_sMCR.count; i++)
        {
            m_sMCR.mac_reg32[i].index = m_uiMacBeginAddr + (i + m_uiMACCount*WIFI_MAX_COUNT)*data_size;
        }
        m_uiMACCount++;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::Compose_MCR_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sMCR.mac_reg32[0].mcr_data32 = m_uiMacData;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::DeCompose_MCR_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_uiMacData = m_sMCR.mac_reg32[0].mcr_data32;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::Compose_MCR16_Parameter( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sMCR16.count     = 1;
        m_sMCR16.mac_reg16[0].index  = m_uiMacAddr;
    }
    else
    {
        int data_size = sizeof(m_sMCR16.mac_reg16[0].mcr_data16);
        m_sMCR16.count     = (m_uiMacEndAddr - m_uiMacBeginAddr)/data_size + 1 - m_uiMACCount*WIFI_MAX_COUNT;

        if( m_sMCR16.count > WIFI_MAX_COUNT )  m_sMCR16.count = WIFI_MAX_COUNT;

        for (unsigned int i=0; i<m_sMCR16.count; i++)
        {
            m_sMCR16.mac_reg16[i].index = m_uiMacBeginAddr + (i + m_uiMACCount*WIFI_MAX_COUNT)*data_size;
        }
        m_uiMACCount++;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::Compose_MCR16_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sMCR16.mac_reg16[0].mcr_data16 = m_usMac16Data;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::DeCompose_MCR16_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_usMac16Data = m_sMCR16.mac_reg16[0].mcr_data16;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFi::Compose_EEPROM_Parameter( E_ACCESS_TYPE type )
{
    switch( type )
    {
    case ACCESS_SINGLE:
    {
        m_sEE.count           = 1;
        m_sEE.eeprom[0].index = m_uiEEPROMIdx;
    }
    break;

    case ACCESS_DUMP:
    {
        // int data_size = sizeof(m_sEE.eeprom[0].eeprom_data16);
        m_sEE.count     = (m_uiEEPROMEndIdx - m_uiEEPROMBeginIdx) -m_uiEEPROMCount*WIFI_MAX_COUNT + 1;

        if( m_sEE.count > WIFI_MAX_COUNT )  m_sEE.count = WIFI_MAX_COUNT;

        for (unsigned int i=0; i<m_sEE.count; i++)
        {
            m_sEE.eeprom[i].index = m_uiEEPROMBeginIdx + (i+ m_uiEEPROMCount*WIFI_MAX_COUNT);
        }
        m_uiEEPROMCount++;
    }
    break;

    case ACCESS_TX_POWER:
    {
        m_sEE.count = 14;
        for (unsigned int i=0; i<m_sEE.count; i++)
        {
            m_sEE.eeprom[i].index = ADDR_MT5911_EEPROM_2_4G_CCK_TX_POWER + i;
        }
    }
    break;

    case ACCESS_TX_DC_OFFSET:
    {
        m_sEE.count = 1;
        m_sEE.eeprom[0].index = ADDR_MT5911_EEPROM_DAC_IQ_OFFSET;
    }
    break;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFi::Compose_EEPROM_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_sEE.eeprom[0].eeprom_data16   = m_usEEPROMData;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFi::DeCompose_EEPROM_Data( E_ACCESS_TYPE type )
{
    if( ACCESS_SINGLE == type )
    {
        m_usEEPROMData  = m_sEE.eeprom[0].eeprom_data16;
    }
}

//===========================================================================
void __fastcall TfrmWiFi::edtBBBeginCRIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value should be 0~127 ";

    text = edit->Text;
    if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( uidata > 127 )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiBBBeginIdx = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtBBEndCRIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value should be 0~127 ";

    text = edit->Text;
    if( !IsValidDecWiFiBBRegAddr( text, uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( uidata > 127 )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiBBEndIdx = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtMACBeginMCRAddrCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";
    char  hint16[] = " value should be multiple of 2 ";
    char  hint32[] = " value should be multiple of 4 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( rbMAC16bits->Checked )
    {
        if( 0 != uidata%2 )
        {
            ShowHintLabel( edit, hint16 );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( 0 != uidata%4 )
        {
            ShowHintLabel( edit, hint32 );
            edit->SetFocus();
            return;
        }
    }

    m_uiMacBeginAddr = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtMACEndMCRAddrCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";
    char  hint16[] = " value should be multiple of 2 ";
    char  hint32[] = " value should be multiple of 4 ";

    text = edit->Text;
    if( !IsValidHexWiFiMacRegAddr( text, &uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( rbMAC16bits->Checked )
    {
        if( 0 != uidata%2 )
        {
            ShowHintLabel( edit, hint16 );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( 0 != uidata%4 )
        {
            ShowHintLabel( edit, hint32 );
            edit->SetFocus();
            return;
        }
    }

    m_uiMacEndAddr = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtBeginEEIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int uidata;
    TEdit *edit = (TEdit*)Sender;
    AnsiString as_hint = " value is not valid";

    char  hint[256];
    strcpy( hint, as_hint.c_str() );

    text = edit->Text;
    if( !IsValidHexWiFiEERegAddr( text, &uidata )  )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    // if( uidata >= m_sWiFiCap.eeprom_size-1 )
    // {
    //     ShowHintLabel( edit, hint );
    //     edit->SetFocus();
    //     return;
    // }


    // if( 0 != uidata%2 )
    // {
    //     ShowHintLabel( edit, hint );
    //     edit->SetFocus();
    //     return;
    // }

    m_uiEEPROMBeginIdx = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::edtEndEEIndexCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int uidata;
    TEdit *edit = (TEdit*)Sender;
    AnsiString as_hint = " value should be multiple of 2, ragne 0~" + IntToStr(m_sWiFiCap.eeprom_size-1);

    char  hint[256];
    strcpy( hint, as_hint.c_str() );

    text = edit->Text;
    if( !IsValidHexWiFiEERegAddr( text, &uidata )  )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    //  if( uidata >= m_sWiFiCap.eeprom_size-1 )
    //  {
    //      ShowHintLabel( edit, hint );
    //      edit->SetFocus();
    //      return;
    //  }

    //  if( 0 != uidata%2 )
    //  {
    //      ShowHintLabel( edit, hint );
    //      edit->SetFocus();
    //      return;
    //  }

    m_uiEEPROMEndIdx = uidata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbMAC32bitsClick(TObject *Sender)
{
    edtMACMCRAddressCheck( edtMACMCRAddress );
    edtMACBeginMCRAddrCheck( edtMACBeginMCRAddr );
    edtMACEndMCRAddrCheck( edtMACEndMCRAddr );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbMAC16bitsClick(TObject *Sender)
{
    edtMACMCRAddressCheck( edtMACMCRAddress );
    edtMACBeginMCRAddrCheck( edtMACBeginMCRAddr );
    edtMACEndMCRAddrCheck( edtMACEndMCRAddr );
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnLoadTxPowerFromEEClick(TObject *Sender)
{
    CurrentPageLock();

    Compose_EEPROM_Parameter( ACCESS_TX_POWER );

    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadTxPowerFromEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );

    sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM progressing";
}


//-------------------------------------------
void TfrmWiFi::ConfirmCallback_ReadTxPowerFromEE( void )
{
    int state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiTxPowerEEToNVRAM();
        Compose_EEPROM_Parameter( ACCESS_TX_DC_OFFSET );
        m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadTxDcOffsetFromEE;
        m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM fail";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "FAIL", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM stop";
        CurrentPageReset();
    }
    break;
    }

}

//----------------------------------------
void TfrmWiFi::ConfirmCallback_ReadTxDcOffsetFromEE(void)
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiTxDcOffsetEEToNVRAM();
        ReDrawFields( PAGEIDX_TXALL );
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM fail";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Load WiFi TX power from EEPROM", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX power from EEPROM stop";
    }
    break;
    }
    CurrentPageReset();
}

//--------------------------------------------------------------------------
void TfrmWiFi::WiFiTxPowerEEToNVRAM( void )
{
    int i;
    for(i=0; i<NUM_TX_POWER_2400M_CH/2; i++)
    {
        m_sTxPwr2400M.CCKTxPWR[2*i]   = (unsigned char) m_sEE.eeprom[i].eeprom_data16 & 0x00FF;
        m_sTxPwr2400M.CCKTxPWR[2*i+1] = (unsigned char) ( (m_sEE.eeprom[i].eeprom_data16 & 0xFF00)>>8 );
    }

    for(i=0; i<NUM_TX_POWER_2400M_CH/2; i++)
    {
        m_sTxPwr2400M.OFDMTxPWR[2*i]   = (unsigned char) m_sEE.eeprom[i+NUM_TX_POWER_2400M_CH/2].eeprom_data16 & 0x00FF;
        m_sTxPwr2400M.OFDMTxPWR[2*i+1] = (unsigned char) ((m_sEE.eeprom[i+NUM_TX_POWER_2400M_CH/2].eeprom_data16 & 0xFF00)>>8);
    }
}

//--------------------------------------------------------------------------
void  TfrmWiFi::WiFiTxDcOffsetEEToNVRAM( void )
{
    m_sTxDcOffset.i_ch_offset = (unsigned char) ((m_sEE.eeprom[0].eeprom_data16 >> 8) & 0x001F);
    m_sTxDcOffset.q_ch_offset = (unsigned char) (m_sEE.eeprom[0].eeprom_data16 & 0x001F );
}

//--------------------------------------------------------------------------
void __fastcall TfrmWiFi::btnTXLoadTxDcOffsetFromEEClick(TObject *Sender)
{
    CurrentPageLock();

    Compose_EEPROM_Parameter( ACCESS_TX_DC_OFFSET );

    m_WIFI_EE_Obj.ConfirmCallback  = ::ConfirmCallback_ReadTxDcOffsetFromEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );

    sbTX->Panels->Items[0]->Text = (AnsiString)"  Load WiFi TX DC offset from EEPROM progressing";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbEEByteClick(TObject *Sender)
{
    FillEEResult(true);
    FillEEResult(false);
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::rbEEWordClick(TObject *Sender)
{
    FillEEResult(true);
    FillEEResult(false);
}

void __fastcall TfrmWiFi::m_btnTxAlcClick(TObject *Sender)
{
    frmWiFiALC2400M->Top  = 152;
    frmWiFiALC2400M->Left = 152;
    frmWiFiALC2400M->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFi::FormActivate(TObject *Sender)
{
    if (m_bInit)
    {
        m_bInit = false;
        m_sWiFiCap = frmMainSel->Get_FinalWiFiCap();
        m_bAlcSupport = m_cWIFI_ALC_Obj.REQ_Query_ALC_Suppport_Start();
        m_btnTxAlc->Visible = m_bAlcSupport;
        m_cbTXTargetGain->Visible = m_bAlcSupport;
        m_cbTXAlcTracking->Visible = m_bAlcSupport;
        m_cbTargetAlc->Visible = m_bAlcSupport;
        m_lblTXTargetAlc->Visible = m_bAlcSupport;
        m_edtTXTargetAlc->Visible = m_bAlcSupport;
        m_lblAverageALC->Visible = m_bAlcSupport;
        m_stAverageALC->Visible = m_bAlcSupport;
        m_lblTXCCKGainControl->Visible = m_bAlcSupport;
        m_stTXCCKGainControl->Visible = m_bAlcSupport;
        m_lblTXOFDMGainControl->Visible = m_bAlcSupport;
        m_stTXOFDMGainControl->Visible = m_bAlcSupport;
        DisplayWiFiChannel();
        DisplayWiFiTxRate();
    }

}
//---------------------------------------------------------------------------

