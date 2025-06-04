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
 *   form_WiFiMCR.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi MAC control register form source
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
#include <stdio.h>

#pragma hdrstop

// form
#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#ifndef _FORM_WIFIMCR_H_
#include "form_WiFiMCR.h"
#endif

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

#define  DRAW_MCR_COMMON          0x01
#define  DRAW_MCR_HIF             0x02
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFiMCR *frmWiFiMCR;
//===========================================================================
static void  ConfirmCallback_ReadReg( void )
{
    frmWiFiMCR->ConfirmCallback_ReadReg();
}

//---------------------------------------------------------------------------
static void  ConfirmCallback_ReadHIF( void )
{
    frmWiFiMCR->ConfirmCallback_ReadHIF();
}

//---------------------------------------------------------------------------
static void  ConfirmCallback_WriteReg( void )
{
    frmWiFiMCR->ConfirmCallback_WriteReg();
}

//---------------------------------------------------------------------------
static void  ConfirmCallback_WriteHIF( void )
{
    frmWiFiMCR->ConfirmCallback_WriteHIF();
}

//---------------------------------------------------------------------------
__fastcall TfrmWiFiMCR::TfrmWiFiMCR(TComponent* Owner)
    : TForm(Owner)
{
    int i, j;

    // System Control
    lblSC[0] = lblSC0;
    edtSC[0] = edtSC0;
    cbSC[0] = cbSC0;
    lblSC[1] = lblSC1;
    edtSC[1] = edtSC1;
    cbSC[1] = cbSC1;
    lblSC[2] = lblSC2;
    edtSC[2] = edtSC2;
    cbSC[2] = cbSC2;
    lblSC[3] = lblSC3;
    edtSC[3] = edtSC3;
    cbSC[3] = cbSC3;

    // Miscellaneous and Debug Port
    lblMDP[0]  = lblMDP00;
    edtMDP[0]   = edtMDP00;
    cbMDP[0]   = cbMDP00;
    lblMDP[1]  = lblMDP01;
    edtMDP[1]   = edtMDP01;
    cbMDP[1]   = cbMDP01;
    lblMDP[2]  = lblMDP02;
    edtMDP[2]   = edtMDP02;
    cbMDP[2]   = cbMDP02;
    lblMDP[3]  = lblMDP03;
    edtMDP[3]   = edtMDP03;
    cbMDP[3]   = cbMDP03;
    lblMDP[4]  = lblMDP04;
    edtMDP[4]   = edtMDP04;
    cbMDP[4]   = cbMDP04;
    lblMDP[5]  = lblMDP05;
    edtMDP[5]   = edtMDP05;
    cbMDP[5]   = cbMDP05;
    lblMDP[6]  = lblMDP06;
    edtMDP[6]   = edtMDP06;
    cbMDP[6]   = cbMDP06;
    lblMDP[7]  = lblMDP07;
    edtMDP[7]   = edtMDP07;
    cbMDP[7]   = cbMDP07;
    lblMDP[8]  = lblMDP08;
    edtMDP[8]   = edtMDP08;
    cbMDP[8]   = cbMDP08;
    lblMDP[9]  = lblMDP09;
    edtMDP[9]   = edtMDP09;
    cbMDP[9]   = cbMDP09;
    lblMDP[10] = lblMDP10;
    edtMDP[10]  = edtMDP10;
    cbMDP[10]  = cbMDP10;
    lblMDP[11] = lblMDP11;
    edtMDP[11]  = edtMDP11;
    cbMDP[11]  = cbMDP11;
    lblMDP[12] = lblMDP12;
    edtMDP[12]  = edtMDP12;
    cbMDP[12]  = cbMDP12;
    lblMDP[13] = lblMDP13;
    edtMDP[13]  = edtMDP13;
    cbMDP[13]  = cbMDP13;
    lblMDP[14] = lblMDP14;
    edtMDP[14]  = edtMDP14;
    cbMDP[14]  = cbMDP14;
    lblMDP[15] = lblMDP15;
    edtMDP[15]  = edtMDP15;
    cbMDP[15]  = cbMDP15;
    lblMDP[16] = lblMDP16;
    edtMDP[16]  = edtMDP16;
    cbMDP[16]  = cbMDP16;
    lblMDP[17] = lblMDP17;
    edtMDP[17]  = edtMDP17;
    cbMDP[17]  = cbMDP17;

    // Phyical Layer Control Interface
    lblPLCI[0]  = lblPLCI00;
    edtPLCI[0]  = edtPLCI00;
    cbPLCI[0]  = cbPLCI00;
    lblPLCI[1]  = lblPLCI01;
    edtPLCI[1]  = edtPLCI01;
    cbPLCI[1]  = cbPLCI01;
    lblPLCI[2]  = lblPLCI02;
    edtPLCI[2]  = edtPLCI02;
    cbPLCI[2]  = cbPLCI02;
    lblPLCI[3]  = lblPLCI03;
    edtPLCI[3]  = edtPLCI03;
    cbPLCI[3]  = cbPLCI03;
    lblPLCI[4]  = lblPLCI04;
    edtPLCI[4]  = edtPLCI04;
    cbPLCI[4]  = cbPLCI04;
    lblPLCI[5]  = lblPLCI05;
    edtPLCI[5]  = edtPLCI05;
    cbPLCI[5]  = cbPLCI05;
    lblPLCI[6]  = lblPLCI06;
    edtPLCI[6]  = edtPLCI06;
    cbPLCI[6]  = cbPLCI06;
    lblPLCI[7]  = lblPLCI07;
    edtPLCI[7]  = edtPLCI07;
    cbPLCI[7]  = cbPLCI07;
    lblPLCI[8]  = lblPLCI08;
    edtPLCI[8]  = edtPLCI08;
    cbPLCI[8]  = cbPLCI08;
    lblPLCI[9]  = lblPLCI09;
    edtPLCI[9]  = edtPLCI09;
    cbPLCI[9]  = cbPLCI09;
    lblPLCI[10] = lblPLCI10;
    edtPLCI[10] = edtPLCI10;
    cbPLCI[10] = cbPLCI10;
    lblPLCI[11] = lblPLCI11;
    edtPLCI[11] = edtPLCI11;
    cbPLCI[11] = cbPLCI11;

    // MAC Protocol Timing Control
    lblMPTC[0]  = lblMPTC00;
    edtMPTC[0]  = edtMPTC00;
    cbMPTC[0]  = cbMPTC00;
    lblMPTC[1]  = lblMPTC01;
    edtMPTC[1]  = edtMPTC01;
    cbMPTC[1]  = cbMPTC01;
    lblMPTC[2]  = lblMPTC02;
    edtMPTC[2]  = edtMPTC02;
    cbMPTC[2]  = cbMPTC02;
    lblMPTC[3]  = lblMPTC03;
    edtMPTC[3]  = edtMPTC03;
    cbMPTC[3]  = cbMPTC03;
    lblMPTC[4]  = lblMPTC04;
    edtMPTC[4]  = edtMPTC04;
    cbMPTC[4]  = cbMPTC04;
    lblMPTC[5]  = lblMPTC05;
    edtMPTC[5]  = edtMPTC05;
    cbMPTC[5]  = cbMPTC05;
    lblMPTC[6]  = lblMPTC06;
    edtMPTC[6]  = edtMPTC06;
    cbMPTC[6]  = cbMPTC06;
    lblMPTC[7]  = lblMPTC07;
    edtMPTC[7]  = edtMPTC07;
    cbMPTC[7]  = cbMPTC07;
    lblMPTC[8]  = lblMPTC08;
    edtMPTC[8]  = edtMPTC08;
    cbMPTC[8]  = cbMPTC08;
    lblMPTC[9]  = lblMPTC09;
    edtMPTC[9]  = edtMPTC09;
    cbMPTC[9]  = cbMPTC09;
    lblMPTC[10] = lblMPTC10;
    edtMPTC[10] = edtMPTC10;
    cbMPTC[10] = cbMPTC10;
    lblMPTC[11] = lblMPTC11;
    edtMPTC[11] = edtMPTC11;
    cbMPTC[11] = cbMPTC11;
    lblMPTC[12] = lblMPTC12;
    edtMPTC[12] = edtMPTC12;
    cbMPTC[12] = cbMPTC12;
    lblMPTC[13] = lblMPTC13;
    edtMPTC[13] = edtMPTC13;
    cbMPTC[13] = cbMPTC13;
    lblMPTC[14] = lblMPTC14;
    edtMPTC[14] = edtMPTC14;
    cbMPTC[14] = cbMPTC14;
    lblMPTC[15] = lblMPTC15;
    edtMPTC[15] = edtMPTC15;
    cbMPTC[15] = cbMPTC15;
    lblMPTC[16] = lblMPTC16;
    edtMPTC[16] = edtMPTC16;
    cbMPTC[16] = cbMPTC16;
    lblMPTC[17] = lblMPTC17;
    edtMPTC[17] = edtMPTC17;
    cbMPTC[17] = cbMPTC17;

    // NVA Control
    lblNC[0] = lblNC0;
    edtNC[0] = edtNC0;
    cbNC[0] = cbNC0;
    lblNC[1] = lblNC1;
    edtNC[1] = edtNC1;
    cbNC[1] = cbNC1;
    lblNC[2] = lblNC2;
    edtNC[2] = edtNC2;
    cbNC[2] = cbNC2;
    lblNC[3] = lblNC3;
    edtNC[3] = edtNC3;
    cbNC[3] = cbNC3;

    // Beacon Generation
    lblBG[0] = lblBG0;
    edtBG[0] = edtBG0;
    cbBG[0] = cbBG0;
    lblBG[1] = lblBG1;
    edtBG[1] = edtBG1;
    cbBG[1] = cbBG1;
    lblBG[2] = lblBG2;
    edtBG[2] = edtBG2;
    cbBG[2] = cbBG2;
    lblBG[3] = lblBG3;
    edtBG[3] = edtBG3;
    cbBG[3] = cbBG3;
    lblBG[4] = lblBG4;
    edtBG[4] = edtBG4;
    cbBG[4] = cbBG4;
    lblBG[5] = lblBG5;
    edtBG[5] = edtBG5;
    cbBG[5] = cbBG5;
    lblBG[6] = lblBG6;
    edtBG[6] = edtBG6;
    cbBG[6] = cbBG6;
    lblBG[7] = lblBG7;
    edtBG[7] = edtBG7;
    cbBG[7] = cbBG7;

    // Security Engine
    lblSE[0]  = lblSE00;
    edtSE[0]  = edtSE00;
    cbSE[0]  = cbSE00;
    lblSE[1]  = lblSE01;
    edtSE[1]  = edtSE01;
    cbSE[1]  = cbSE01;
    lblSE[2]  = lblSE02;
    edtSE[2]  = edtSE02;
    cbSE[2]  = cbSE02;
    lblSE[3]  = lblSE03;
    edtSE[3]  = edtSE03;
    cbSE[3]  = cbSE03;
    lblSE[4]  = lblSE05;
    edtSE[4]  = edtSE04;
    cbSE[4]  = cbSE04;
    lblSE[5]  = lblSE05;
    edtSE[5]  = edtSE05;
    cbSE[5]  = cbSE05;
    lblSE[6]  = lblSE06;
    edtSE[6]  = edtSE06;
    cbSE[6]  = cbSE06;
    lblSE[7]  = lblSE07;
    edtSE[7]  = edtSE07;
    cbSE[7]  = cbSE07;
    lblSE[8]  = lblSE08;
    edtSE[8]  = edtSE08;
    cbSE[8]  = cbSE08;
    lblSE[9]  = lblSE09;
    edtSE[9]  = edtSE09;
    cbSE[9]  = cbSE09;
    lblSE[10] = lblSE10;
    edtSE[10] = edtSE10;
    cbSE[10] = cbSE10;

    // Transmitter Control
    lblTC[0]  = lblTC00;
    edtTC[0]  = edtTC00;
    cbTC[0]  = cbTC00;
    lblTC[1]  = lblTC01;
    edtTC[1]  = edtTC01;
    cbTC[1]  = cbTC01;
    lblTC[2]  = lblTC02;
    edtTC[2]  = edtTC02;
    cbTC[2]  = cbTC02;
    lblTC[3]  = lblTC03;
    edtTC[3]  = edtTC03;
    cbTC[3]  = cbTC03;
    lblTC[4]  = lblTC04;
    edtTC[4]  = edtTC04;
    cbTC[4]  = cbTC04;
    lblTC[5]  = lblTC05;
    edtTC[5]  = edtTC05;
    cbTC[5]  = cbTC05;
    lblTC[6]  = lblTC06;
    edtTC[6]  = edtTC06;
    cbTC[6]  = cbTC06;
    lblTC[7]  = lblTC07;
    edtTC[7]  = edtTC07;
    cbTC[7]  = cbTC07;
    lblTC[8]  = lblTC08;
    edtTC[8]  = edtTC08;
    cbTC[8]  = cbTC08;
    lblTC[9]  = lblTC09;
    edtTC[9]  = edtTC09;
    cbTC[9]  = cbTC09;
    lblTC[10] = lblTC10;
    edtTC[10] = edtTC10;
    cbTC[10] = cbTC10;
    lblTC[11] = lblTC11;
    edtTC[11]  = edtTC11;
    cbTC[11] = cbTC11;

    // Receiver Control
    lblRC[0]  = lblRC00;
    edtRC[0]  = edtRC00;
    cbRC[0]  = cbRC00;
    lblRC[1]  = lblRC01;
    edtRC[1]  = edtRC01;
    cbRC[1]  = cbRC01;
    lblRC[2]  = lblRC02;
    edtRC[2]  = edtRC02;
    cbRC[2]  = cbRC02;
    lblRC[3]  = lblRC03;
    edtRC[3]  = edtRC03;
    cbRC[3]  = cbRC03;
    lblRC[4]  = lblRC04;
    edtRC[4]  = edtRC04;
    cbRC[4]  = cbRC04;
    lblRC[5]  = lblRC05;
    edtRC[5]  = edtRC05;
    cbRC[5]  = cbRC05;
    lblRC[6]  = lblRC06;
    edtRC[6]  = edtRC06;
    cbRC[6]  = cbRC06;
    lblRC[7]  = lblRC07;
    edtRC[7]  = edtRC07;
    cbRC[7]  = cbRC07;
    lblRC[8]  = lblRC08;
    edtRC[8]  = edtRC08;
    cbRC[8]  = cbRC08;
    lblRC[9]  = lblRC09;
    edtRC[9]  = edtRC09;
    cbRC[9]  = cbRC09;
    lblRC[10] = lblRC10;
    edtRC[10] = edtRC10;
    cbRC[10] = cbRC10;
    lblRC[11] = lblRC11;
    edtRC[11] = edtRC11;
    cbRC[11] = cbRC11;
    lblRC[12] = lblRC12;
    edtRC[12] = edtRC12;
    cbRC[12] = cbRC12;
    lblRC[13] = lblRC13;
    edtRC[13] = edtRC13;
    cbRC[13] = cbRC13;
    lblRC[14] = lblRC14;
    edtRC[14] = edtRC14;
    cbRC[14] = cbRC14;

    // HIF
    lblHIF[0] = lblHIF0;
    edtHIF[0] = edtHIF0;
    cbHIF[0] = cbHIF0;
    lblHIF[1] = lblHIF1;
    edtHIF[1] = edtHIF1;
    cbHIF[1] = cbHIF1;
    lblHIF[2] = lblHIF2;
    edtHIF[2] = edtHIF2;
    cbHIF[2] = cbHIF2;
    lblHIF[3] = lblHIF3;
    edtHIF[3] = edtHIF3;
    cbHIF[3] = cbHIF3;
    lblHIF[4] = lblHIF4;
    edtHIF[4] = edtHIF4;
    cbHIF[4] = cbHIF4;
    lblHIF[5] = lblHIF5;
    edtHIF[5] = edtHIF5;
    cbHIF[5] = cbHIF5;
    lblHIF[6] = lblHIF6;
    edtHIF[6] = edtHIF6;
    cbHIF[6] = cbHIF6;
    lblHIF[7] = lblHIF7;
    edtHIF[7] = edtHIF7;
    cbHIF[7] = cbHIF7;




    // Set MCR name
    // System Control
    m_sMCR_Setting[WIFI_MCR_SC][0].name = "SCR";
    m_sMCR_Setting[WIFI_MCR_SC][1].name = "MRBS";
    m_sMCR_Setting[WIFI_MCR_SC][2].name = "DEVID";
    m_sMCR_Setting[WIFI_MCR_SC][3].name = "GPIOCR";

    // Miscellaneous and Debug Port
    m_sMCR_Setting[WIFI_MCR_MDP][0].name = "PRBCR";
    m_sMCR_Setting[WIFI_MCR_MDP][1].name = "PRBSR";
    m_sMCR_Setting[WIFI_MCR_MDP][2].name = "PFWDR";
    m_sMCR_Setting[WIFI_MCR_MDP][3].name = "PRBDR";
    m_sMCR_Setting[WIFI_MCR_MDP][4].name = "CTPR1";
    m_sMCR_Setting[WIFI_MCR_MDP][5].name = "QCR";
    m_sMCR_Setting[WIFI_MCR_MDP][6].name = "ISAR";
    m_sMCR_Setting[WIFI_MCR_MDP][7].name = "IER";
    m_sMCR_Setting[WIFI_MCR_MDP][8].name = "DRNGR";
    m_sMCR_Setting[WIFI_MCR_MDP][9].name = "AIFSR";
    m_sMCR_Setting[WIFI_MCR_MDP][10].name = "TQCWR";
    m_sMCR_Setting[WIFI_MCR_MDP][11].name = "AC0CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][12].name = "AC1CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][13].name = "AC2CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][14].name = "AC3CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][15].name = "LNUIR0";
    m_sMCR_Setting[WIFI_MCR_MDP][16].name = "LNUIR1";
    m_sMCR_Setting[WIFI_MCR_MDP][17].name = "LNUIR2";

    // Phyical Layer Control Interface
    m_sMCR_Setting[WIFI_MCR_PLCI][0].name = "PCICR";
    m_sMCR_Setting[WIFI_MCR_PLCI][1].name = "PBAR";
    m_sMCR_Setting[WIFI_MCR_PLCI][2].name = "PPORCR0";
    m_sMCR_Setting[WIFI_MCR_PLCI][3].name = "PPORCR1";
    m_sMCR_Setting[WIFI_MCR_PLCI][4].name = "PPDRCR0";
    m_sMCR_Setting[WIFI_MCR_PLCI][5].name = "PPDRCR1";
    m_sMCR_Setting[WIFI_MCR_PLCI][6].name = "PPDRCR2";
    m_sMCR_Setting[WIFI_MCR_PLCI][7].name = "PPMCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][8].name = "PSCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][9].name = "PSPR";
    m_sMCR_Setting[WIFI_MCR_PLCI][10].name = "LCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][11].name = "ACR";

    // MAC Protocol Timing Control
    m_sMCR_Setting[WIFI_MCR_MPTC][0].name = "CWBR";
    m_sMCR_Setting[WIFI_MCR_MPTC][1].name = "MPTR";
    m_sMCR_Setting[WIFI_MCR_MPTC][2].name = "MPDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][3].name = "TNTDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][4].name = "STDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][5].name = "EPDDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][6].name = "CRFCR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][7].name = "CRFCR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][8].name = "DTR";
    m_sMCR_Setting[WIFI_MCR_MPTC][9].name = "BCWR";
    m_sMCR_Setting[WIFI_MCR_MPTC][10].name = "RFTPCR";
    m_sMCR_Setting[WIFI_MCR_MPTC][11].name = "LTTR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][12].name = "LTTR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][13].name = "TTAR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][14].name = "TTAR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][15].name = "TTAR2";
    m_sMCR_Setting[WIFI_MCR_MPTC][16].name = "TTSCS";
    m_sMCR_Setting[WIFI_MCR_MPTC][17].name = "TTTC";

    // NVA Control
    m_sMCR_Setting[WIFI_MCR_NC][0].name = "LNR";
    m_sMCR_Setting[WIFI_MCR_NC][1].name = "NRTR";
    m_sMCR_Setting[WIFI_MCR_NC][2].name = "NSUR";
    m_sMCR_Setting[WIFI_MCR_NC][3].name = "TTIC";

    // Beacon Generation
    m_sMCR_Setting[WIFI_MCR_BG][0].name = "BGCR0";
    m_sMCR_Setting[WIFI_MCR_BG][1].name = "BGCR1";
    m_sMCR_Setting[WIFI_MCR_BG][2].name = "SWBCCR";
    m_sMCR_Setting[WIFI_MCR_BG][3].name = "SWBCDR";
    m_sMCR_Setting[WIFI_MCR_BG][4].name = "ARRCR";
    m_sMCR_Setting[WIFI_MCR_BG][5].name = "AFRCR";
    m_sMCR_Setting[WIFI_MCR_BG][6].name = "ATFCR";
    m_sMCR_Setting[WIFI_MCR_BG][7].name = "ATBCR";

    // Security Engine
    m_sMCR_Setting[WIFI_MCR_SE][0].name = "SKACR";
    m_sMCR_Setting[WIFI_MCR_SE][1].name = "SKADR0";
    m_sMCR_Setting[WIFI_MCR_SE][2].name = "SKADR1";
    m_sMCR_Setting[WIFI_MCR_SE][3].name = "SKADR2";
    m_sMCR_Setting[WIFI_MCR_SE][4].name = "SKADR3";
    m_sMCR_Setting[WIFI_MCR_SE][5].name = "SKADR4";
    m_sMCR_Setting[WIFI_MCR_SE][6].name = "SKADR5";
    m_sMCR_Setting[WIFI_MCR_SE][7].name = "SCPR0";
    m_sMCR_Setting[WIFI_MCR_SE][8].name = "SCPR1";
    m_sMCR_Setting[WIFI_MCR_SE][9].name = "SKADR6";
    m_sMCR_Setting[WIFI_MCR_SE][10].name = "SKADR7";

    // Transmitter Control
    m_sMCR_Setting[WIFI_MCR_TC][0].name = "ACWLR";
    m_sMCR_Setting[WIFI_MCR_TC][1].name = "MPTCR";
    m_sMCR_Setting[WIFI_MCR_TC][2].name = "NPTCR";
    m_sMCR_Setting[WIFI_MCR_TC][3].name = "NTTCR";
    m_sMCR_Setting[WIFI_MCR_TC][4].name = "TXOPGBNTCR";
    m_sMCR_Setting[WIFI_MCR_TC][5].name = "NDTCR";
    m_sMCR_Setting[WIFI_MCR_TC][6].name = "NCSTCR";
    m_sMCR_Setting[WIFI_MCR_TC][7].name = "ACTXOPR0";
    m_sMCR_Setting[WIFI_MCR_TC][8].name = "ACTXOPR1";
    m_sMCR_Setting[WIFI_MCR_TC][9].name = "TSTGPCR";
    m_sMCR_Setting[WIFI_MCR_TC][10].name = "TSTNTCR0";
    m_sMCR_Setting[WIFI_MCR_TC][11].name = "TSTNTCR1";

    // Receiver Control
    m_sMCR_Setting[WIFI_MCR_RC][0].name = "DRCR";
    m_sMCR_Setting[WIFI_MCR_RC][1].name = "RFECR";
    m_sMCR_Setting[WIFI_MCR_RC][2].name = "RFFCR";
    m_sMCR_Setting[WIFI_MCR_RC][3].name = "RPCR";
    m_sMCR_Setting[WIFI_MCR_RC][4].name = "CICR";
    m_sMCR_Setting[WIFI_MCR_RC][5].name = "CACR";
    m_sMCR_Setting[WIFI_MCR_RC][6].name = "CATR";
    m_sMCR_Setting[WIFI_MCR_RC][7].name = "CSACR";
    m_sMCR_Setting[WIFI_MCR_RC][8].name = "RFBCR";
    m_sMCR_Setting[WIFI_MCR_RC][9].name = "OMAR0";
    m_sMCR_Setting[WIFI_MCR_RC][10].name = "OMAR1";
    m_sMCR_Setting[WIFI_MCR_RC][11].name = "CBR0";
    m_sMCR_Setting[WIFI_MCR_RC][12].name = "CBR1";
    m_sMCR_Setting[WIFI_MCR_RC][13].name = "AMAR0";
    m_sMCR_Setting[WIFI_MCR_RC][14].name = "AMAR1";

    // HIF_HPI
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][0].name = "HPI_CHIPID";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][1].name = "HPI_MAC_STS";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][2].name = "HPI_CTRL";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][3].name = "HPI_POWER_CTRL";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][4].name = "TX_DATA_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][5].name = "TX_STATUS_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][6].name = "RX_STATUS_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][7].name = "RX_DATA_PORT";

    // Set read only property
    for( i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_sMCR_Setting[i][j].RO = false;
        }
    }
    m_sMCR_Setting[WIFI_MCR_SC][2].RO = true; // DEVID
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][0].RO = true; // HPI_CHIPID

    // Set read/clear property
    for( i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_sMCR_Setting[i][j].RC = false;
        }
    }

    for( i=0; i<4; i++ )
    {
        m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].RC = false;
    }
    for( i=4; i<8; i++ )
    {
        m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].RC = true;
    }


    // Set address
    // System Control
    m_sMCR_Setting[WIFI_MCR_SC][0].addr = 0x0000; // "SCR";
    m_sMCR_Setting[WIFI_MCR_SC][1].addr = 0x0018; // "MRBS";
    m_sMCR_Setting[WIFI_MCR_SC][2].addr = 0x0020; // "DEVID";
    m_sMCR_Setting[WIFI_MCR_SC][3].addr = 0x0050; // "GPIOCR";

    // Miscellaneous and Debug Port
    m_sMCR_Setting[WIFI_MCR_MDP][0].addr = 0x0080; // "PRBCR";
    m_sMCR_Setting[WIFI_MCR_MDP][1].addr = 0x0084; // "PRBSR";
    m_sMCR_Setting[WIFI_MCR_MDP][2].addr = 0x0088; // "PFWDR";
    m_sMCR_Setting[WIFI_MCR_MDP][3].addr = 0x008C; // "PRBDR";
    m_sMCR_Setting[WIFI_MCR_MDP][4].addr = 0x0094; // "CTPR1";
    m_sMCR_Setting[WIFI_MCR_MDP][5].addr = 0x0100; // "QCR";
    m_sMCR_Setting[WIFI_MCR_MDP][6].addr = 0x0104; // "ISAR";
    m_sMCR_Setting[WIFI_MCR_MDP][7].addr = 0x0108; // "IER";
    m_sMCR_Setting[WIFI_MCR_MDP][8].addr = 0x0188; // "DRNGR";
    m_sMCR_Setting[WIFI_MCR_MDP][9].addr = 0x018C; // "AIFSR";
    m_sMCR_Setting[WIFI_MCR_MDP][10].addr = 0x0190; // "TQCWR";
    m_sMCR_Setting[WIFI_MCR_MDP][11].addr = 0x0194; // "AC0CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][12].addr = 0x0198; // "AC1CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][13].addr = 0x019C; // "AC2CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][14].addr = 0x01A0; // "AC3CWR";
    m_sMCR_Setting[WIFI_MCR_MDP][15].addr = 0x0500; // "LNUIR0";
    m_sMCR_Setting[WIFI_MCR_MDP][16].addr = 0x0504; // "LNUIR1";
    m_sMCR_Setting[WIFI_MCR_MDP][17].addr = 0x0508; // "LNUIR2";


    // Phyical Layer Control Interface
    m_sMCR_Setting[WIFI_MCR_PLCI][0].addr = 0x0240; // "PCICR";
    m_sMCR_Setting[WIFI_MCR_PLCI][1].addr = 0x0248; // "PBAR";
    m_sMCR_Setting[WIFI_MCR_PLCI][2].addr = 0x0280; // "PPORCR0";
    m_sMCR_Setting[WIFI_MCR_PLCI][3].addr = 0x0284; // "PPORCR1";
    m_sMCR_Setting[WIFI_MCR_PLCI][4].addr = 0x0288; // "PPDRCR0";
    m_sMCR_Setting[WIFI_MCR_PLCI][5].addr = 0x028C; // "PPDRCR1";
    m_sMCR_Setting[WIFI_MCR_PLCI][6].addr = 0x0290; // "PPDRCR2";
    m_sMCR_Setting[WIFI_MCR_PLCI][7].addr = 0x0294; // "PPMCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][8].addr = 0x02A0; // "PSCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][9].addr = 0x02A4; // "PSPR";
    m_sMCR_Setting[WIFI_MCR_PLCI][10].addr = 0x02A8; // "LCR";
    m_sMCR_Setting[WIFI_MCR_PLCI][11].addr = 0x02AC; // "ACR";

    // MAC Protocol Timing Control
    m_sMCR_Setting[WIFI_MCR_MPTC][0].addr = 0x03F8; // "CWBR";
    m_sMCR_Setting[WIFI_MCR_MPTC][1].addr = 0x03FC; // "MPTR";
    m_sMCR_Setting[WIFI_MCR_MPTC][2].addr = 0x0400; // "MPDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][3].addr = 0x0404; // "TNTDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][4].addr = 0x0408; // "STDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][5].addr = 0x040C; // "EPDDR";
    m_sMCR_Setting[WIFI_MCR_MPTC][6].addr = 0x0410; // "CRFCR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][7].addr = 0x0414; // "CRFCR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][8].addr = 0x0418; // "DTR";
    m_sMCR_Setting[WIFI_MCR_MPTC][9].addr = 0x041C; // "BCWR";
    m_sMCR_Setting[WIFI_MCR_MPTC][10].addr = 0x0420; // "RFTPCR";
    m_sMCR_Setting[WIFI_MCR_MPTC][11].addr = 0x0440; // "LTTR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][12].addr = 0x0444; // "LTTR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][13].addr = 0x0448; // "TTAR0";
    m_sMCR_Setting[WIFI_MCR_MPTC][14].addr = 0x044C; // "TTAR1";
    m_sMCR_Setting[WIFI_MCR_MPTC][15].addr = 0x0450; // "TTAR2";
    m_sMCR_Setting[WIFI_MCR_MPTC][16].addr = 0x0454; // "TTSCS";
    m_sMCR_Setting[WIFI_MCR_MPTC][17].addr = 0x0458; // "TTTC";

    // NVA Control
    m_sMCR_Setting[WIFI_MCR_NC][0].addr = 0x0470; // "LNR";
    m_sMCR_Setting[WIFI_MCR_NC][1].addr = 0x0474; // "NRTR";
    m_sMCR_Setting[WIFI_MCR_NC][2].addr = 0x0478; // "NSUR";
    m_sMCR_Setting[WIFI_MCR_NC][3].addr = 0x047C; // "TTIC";

    // Beacon Generation
    m_sMCR_Setting[WIFI_MCR_BG][0].addr = 0x0480; // "BGCR0";
    m_sMCR_Setting[WIFI_MCR_BG][1].addr = 0x0484; // "BGCR1";
    m_sMCR_Setting[WIFI_MCR_BG][2].addr = 0x0488; // "SWBCCR";
    m_sMCR_Setting[WIFI_MCR_BG][3].addr = 0x048C; // "SWBCDR";
    m_sMCR_Setting[WIFI_MCR_BG][4].addr = 0x0490; // "ARRCR";
    m_sMCR_Setting[WIFI_MCR_BG][5].addr = 0x0494; // "AFRCR";
    m_sMCR_Setting[WIFI_MCR_BG][6].addr = 0x0498; // "ATFCR";
    m_sMCR_Setting[WIFI_MCR_BG][7].addr = 0x049C; // "ATBCR";

    // Security Engine
    m_sMCR_Setting[WIFI_MCR_SE][0].addr = 0x0200; // "SKACR";
    m_sMCR_Setting[WIFI_MCR_SE][1].addr = 0x0204; // "SKADR0";
    m_sMCR_Setting[WIFI_MCR_SE][2].addr = 0x0208; // "SKADR1";
    m_sMCR_Setting[WIFI_MCR_SE][3].addr = 0x020C; // "SKADR2";
    m_sMCR_Setting[WIFI_MCR_SE][4].addr = 0x0210; // "SKADR3";
    m_sMCR_Setting[WIFI_MCR_SE][5].addr = 0x0214; // "SKADR4";
    m_sMCR_Setting[WIFI_MCR_SE][6].addr = 0x0218; // "SKADR5";
    m_sMCR_Setting[WIFI_MCR_SE][7].addr = 0x021C; // "SCPR0";
    m_sMCR_Setting[WIFI_MCR_SE][8].addr = 0x0220; // "SCPR1";
    m_sMCR_Setting[WIFI_MCR_SE][9].addr = 0x0224; // "SKADR6";
    m_sMCR_Setting[WIFI_MCR_SE][10].addr = 0x0228; // "SKADR7";

    // Transmitter Control
    m_sMCR_Setting[WIFI_MCR_TC][0].addr = 0x0300; // "ACWLR";
    m_sMCR_Setting[WIFI_MCR_TC][1].addr = 0x0304; // "MPTCR";
    m_sMCR_Setting[WIFI_MCR_TC][2].addr = 0x0308; // "NPTCR";
    m_sMCR_Setting[WIFI_MCR_TC][3].addr = 0x030C; // "NTTCR";
    m_sMCR_Setting[WIFI_MCR_TC][4].addr = 0x0310; // "TXOPGBNTCR";
    m_sMCR_Setting[WIFI_MCR_TC][5].addr = 0x0314; // "NDTCR";
    m_sMCR_Setting[WIFI_MCR_TC][6].addr = 0x0318; // "NCSTCR";
    m_sMCR_Setting[WIFI_MCR_TC][7].addr = 0x031C; // "ACTXOPR0";
    m_sMCR_Setting[WIFI_MCR_TC][8].addr = 0x0320; // "ACTXOPR1";
    m_sMCR_Setting[WIFI_MCR_TC][9].addr = 0x0324; // "TSTGPCR";
    m_sMCR_Setting[WIFI_MCR_TC][10].addr = 0x0328; // "TSTNTCR0";
    m_sMCR_Setting[WIFI_MCR_TC][11].addr = 0x032C; // "TSTNTCR1";

    // Receiver Control
    m_sMCR_Setting[WIFI_MCR_RC][0].addr = 0x0360; // "DRCR";
    m_sMCR_Setting[WIFI_MCR_RC][1].addr = 0x0364; // "RFECR";
    m_sMCR_Setting[WIFI_MCR_RC][2].addr = 0x0368; // "RFFCR";
    m_sMCR_Setting[WIFI_MCR_RC][3].addr = 0x036C; // "RPCR";
    m_sMCR_Setting[WIFI_MCR_RC][4].addr = 0x0370; // "CICR";
    m_sMCR_Setting[WIFI_MCR_RC][5].addr = 0x0374; // "CACR";
    m_sMCR_Setting[WIFI_MCR_RC][6].addr = 0x0378; // "CATR";
    m_sMCR_Setting[WIFI_MCR_RC][7].addr = 0x037C; // "CSACR";
    m_sMCR_Setting[WIFI_MCR_RC][8].addr = 0x0380; // "RFBCR";
    m_sMCR_Setting[WIFI_MCR_RC][9].addr = 0x03A0; // "OMAR0";
    m_sMCR_Setting[WIFI_MCR_RC][10].addr = 0x03A4; // "OMAR1";
    m_sMCR_Setting[WIFI_MCR_RC][11].addr = 0x03A8; // "CBR0";
    m_sMCR_Setting[WIFI_MCR_RC][12].addr = 0x03AC; // "CBR1";
    m_sMCR_Setting[WIFI_MCR_RC][13].addr = 0x03B0; // "AMAR0";
    m_sMCR_Setting[WIFI_MCR_RC][14].addr = 0x03B4; // "AMAR1";

    // HIF_HPI
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][0].addr = 0x780; // "HPI_CHIPID";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][1].addr = 0x78C; // "HPI_MAC_STS";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][2].addr = 0x7FC; // "HPI_CTRL";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][3].addr = 0x7FE; // "HPI_POWER_CTRL";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][4].addr = 0x600; // "TX_DATA_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][5].addr = 0x640; // "TX_STATUS_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][6].addr = 0x680; // "RX_STATUS_PORT";
    m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][7].addr = 0x6c0; // "RX_DATA_PORT";

    // Set value
    for( i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_sMCR_Setting[i][j].value = 0;
        }
    }

    // Set checked property
    for( i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_sMCR_Setting[i][j].checked = false;
        }
    }

    Init();
    
    m_final_WiFiId = 0;
    m_iCount = 0;
}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::Init( void )
{
    m_bInit          = true;
}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::ReDrawFields( int idx )
{
    int i;
    char  str[256];

    if( idx & DRAW_MCR_COMMON )
    {
        // system control register
        if( 0 == btnSYSMACMCRData->Tag ) // Dec
        {
            btnSYSMACMCRData->Caption = "MCR Data (Dec)";

            // System Control
            for( i=0; i<WIFI_SC_NUM; i++ )
            {
                edtSC[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_SC][i].value );
            }

            // Miscellaneous and Debug Port
            for( i=0; i<WIFI_MDP_NUM; i++ )
            {
                edtMDP[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_MDP][i].value );
            }

            // Phyical Layer Control Interface
            for( i=0; i<WIFI_PLCI_NUM; i++ )
            {
                edtPLCI[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_PLCI][i].value );
            }

            // MAC Protocol Timing Control
            for( i=0; i<WIFI_MPTC_NUM; i++ )
            {
                edtMPTC[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_MPTC][i].value );
            }

            // NVA Control
            for( i=0; i<WIFI_NC_NUM; i++ )
            {
                edtNC[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_NC][i].value );
            }

            // Beacon Generation
            for( i=0; i<WIFI_BG_NUM; i++ )
            {
                edtBG[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_BG][i].value );
            }
        }
        else
        {
            btnSYSMACMCRData->Caption = "MCR Data (Hex)";

            // System Control
            for( i=0; i<WIFI_SC_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_SC][i].value );
                edtSC[i]->Text = str;
            }

            // Miscellaneous and Debug Port
            for( i=0; i<WIFI_MDP_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_MDP][i].value );
                edtMDP[i]->Text = str;
            }

            // Phyical Layer Control Interface
            for( i=0; i<WIFI_PLCI_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_PLCI][i].value );
                edtPLCI[i]->Text = str;
            }

            // MAC Protocol Timing Control
            for( i=0; i<WIFI_MPTC_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_MPTC][i].value );
                edtMPTC[i]->Text = str;
            }

            // NVA Control
            for( i=0; i<WIFI_NC_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_NC][i].value );
                edtNC[i]->Text = str;
            }

            // Beacon Generation
            for( i=0; i<WIFI_BG_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_BG][i].value );
                edtBG[i]->Text = str;
            }
        }
    }

    // TX/RX Releated register
    if( 0 == btnTRXMACMCRData->Tag ) // Dec
    {
        btnTRXMACMCRData->Caption = "MCR Data (Dec)";

        if( idx & DRAW_MCR_COMMON )
        {
            // Security Engine
            for( i=0; i<WIFI_SE_NUM; i++ )
            {
                edtSE[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_SE][i].value );
            }

            // Transmitter Control
            for( i=0; i<WIFI_TC_NUM; i++ )
            {
                edtTC[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_TC][i].value );
            }

            // Receiver Control
            for( i=0; i<WIFI_RC_NUM; i++ )
            {
                edtRC[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_RC][i].value );
            }
        }

        if( idx & DRAW_MCR_HIF )
        {
            // HIF
            switch( m_sWiFiCap.host_interface )
            {
            case WNDRV_HOST_INTERFACE_SDIO:
            {
                for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
                {
                    edtHIF[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].value );
                }
            }
            break;

            case WNDRV_HOST_INTERFACE_HPI:
            {
                for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
                {
                    edtHIF[i]->Text = IntToStr( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].value );
                }
            }
            break;

            case WNDRV_HOST_INTERFACE_SPI:
            {
                for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
                {
                    edtHIF[i]->Text = IntToStr( m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].value );
                }
            }
            break;
            }
        }
    }
    else
    {
        btnTRXMACMCRData->Caption = "MCR Data (Hex)";

        if( idx & DRAW_MCR_COMMON )
        {
            // Security Engine
            for( i=0; i<WIFI_SE_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_SE][i].value );
                edtSE[i]->Text = str;
            }

            // Transmitter Control
            for( i=0; i<WIFI_TC_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_TC][i].value );
                edtTC[i]->Text = str;
            }

            // Receiver Control
            for( i=0; i<WIFI_RC_NUM; i++ )
            {
                sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_RC][i].value );
                edtRC[i]->Text = str;
            }
        }

        if( idx & DRAW_MCR_HIF )
        {
            // HIF
            switch( m_sWiFiCap.host_interface )
            {
            case WNDRV_HOST_INTERFACE_SDIO:
            {
                for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
                {
                    sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].value );
                    edtHIF[i]->Text = str;
                }
            }
            break;

            case WNDRV_HOST_INTERFACE_HPI:
            {
                for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
                {
                    sprintf( str, "%X", m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].value );
                    edtHIF[i]->Text = str;
                }
            }
            break;

            case WNDRV_HOST_INTERFACE_SPI:
            {
                for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
                {
                    sprintf( str, "%X", m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].value );
                    edtHIF[i]->Text = str;
                }
            }
            break;
            }
        }

    }
}

//---------------------------------------------------------------------------
bool TfrmWiFiMCR::CheckFields( void )
{
    int i;
    unsigned int         uidata[WIFI_MCR_MAX_NUM];
    AnsiString text;

    // system control register
    if( 0 == btnSYSMACMCRData->Tag ) // Dec
    {
        // System Control
        for( i=0; i<WIFI_SC_NUM; i++ )
        {
            text = edtSC[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtSCCheck(edtSC[i]);
                return false;
            }
        }

        // Miscellaneous and Debug Port
        for( i=0; i<WIFI_MDP_NUM; i++ )
        {
            text = edtMDP[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtMDPCheck(edtMDP[i]);
                return false;
            }
        }

        // Phyical Layer Control Interface
        for( i=0; i<WIFI_PLCI_NUM; i++ )
        {
            text = edtPLCI[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtPLCICheck(edtPLCI[i]);
                return false;
            }
        }

        // MAC Protocol Timing Control
        for( i=0; i<WIFI_MPTC_NUM; i++ )
        {
            text = edtMPTC[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtMPTCCheck(edtMPTC[i]);
                return false;
            }
        }

        // NVA Control
        for( i=0; i<WIFI_NC_NUM; i++ )
        {
            text = edtNC[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtMPTCCheck(edtNC[i]);
                return false;
            }
        }

        // Beacon Generation
        for( i=0; i<WIFI_BG_NUM; i++ )
        {
            text = edtBG[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtMPTCCheck(edtBG[i]);
                return false;
            }
        }
    }
    else // Hex
    {
        // System Control
        for( i=0; i<WIFI_SC_NUM; i++ )
        {
            text = edtSC[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtSCCheck(edtSC[i]);
                return false;
            }
        }

        // Miscellaneous and Debug Port
        for( i=0; i<WIFI_MDP_NUM; i++ )
        {
            text = edtMDP[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtMDPCheck(edtMDP[i]);
                return false;
            }
        }

        // Phyical Layer Control Interface
        for( i=0; i<WIFI_PLCI_NUM; i++ )
        {
            text = edtPLCI[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtPLCICheck(edtPLCI[i]);
                return false;
            }
        }

        // MAC Protocol Timing Control
        for( i=0; i<WIFI_MPTC_NUM; i++ )
        {
            text = edtMPTC[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtMPTCCheck(edtMPTC[i]);
                return false;
            }
        }

        // NVA Control
        for( i=0; i<WIFI_NC_NUM; i++ )
        {
            text = edtNC[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtMPTCCheck(edtNC[i]);
                return false;
            }
        }

        // Beacon Generation
        for( i=0; i<WIFI_BG_NUM; i++ )
        {
            text = edtBG[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtMPTCCheck(edtBG[i]);
                return false;
            }
        }
    }

    // TX/RX related register
    if( 0 == btnTRXMACMCRData->Tag ) // Dec
    {
        // Security Engine
        for( i=0; i<WIFI_SE_NUM; i++ )
        {
            text = edtSE[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtSCCheck(edtSE[i]);
                return false;
            }
        }

        // Transmitter Control
        for( i=0; i<WIFI_TC_NUM; i++ )
        {
            text = edtTC[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtSCCheck(edtTC[i]);
                return false;
            }
        }

        // Receiver Control
        for( i=0; i<WIFI_RC_NUM; i++ )
        {
            text = edtRC[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtSCCheck(edtRC[i]);
                return false;
            }
        }

        // HIF_HPI
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            text = edtHIF[i]->Text;
            if( !IsValidDecWiFiMacRegValue( text, uidata[i] ) )
            {
                edtHIFCheck(edtHIF[i]);
                return false;
            }
        }

    }
    else
    {
        // Security Engine
        for( i=0; i<WIFI_SE_NUM; i++ )
        {
            text = edtSE[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtSCCheck(edtSE[i]);
                return false;
            }
        }

        // Transmitter Control
        for( i=0; i<WIFI_TC_NUM; i++ )
        {
            text = edtTC[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtSCCheck(edtTC[i]);
                return false;
            }
        }

        // Receiver Control
        for( i=0; i<WIFI_RC_NUM; i++ )
        {
            text = edtRC[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtSCCheck(edtRC[i]);
                return false;
            }
        }

        // HIF_HPI
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            text = edtHIF[i]->Text;
            if( !IsValidHexWiFiMacRegValue( text, &uidata[i] ) )
            {
                edtHIFCheck(edtHIF[i]);
                return false;
            }
        }
    }
    return true;
}

//---------------------------------------------------------------------------
void  TfrmWiFiMCR::CurrentPageLock( void )
{
}

//---------------------------------------------------------------------------
void  TfrmWiFiMCR::CurrentPageReset( void )
{
}

//---------------------------------------------------------------------------
void  TfrmWiFiMCR::ShowHintLabel( TControl *sender, char* hint )
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
void __fastcall TfrmWiFiMCR::edtSCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_SC][edit->Tag].value = uidata;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtMDPCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_MDP][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtPLCICheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_PLCI][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtMPTCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_MPTC][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtNCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_NC][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtBGCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnSYSMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_BG][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtSECheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnTRXMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_SE][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtTCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnTRXMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_TC][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtRCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnTRXMACMCRData->Tag )  // Dec
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
    m_sMCR_Setting[WIFI_MCR_RC][edit->Tag].value = uidata;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::edtHIFCheck(TObject *Sender)
{
    AnsiString  text;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;

    if( WNDRV_HOST_INTERFACE_HPI == m_sWiFiCap.host_interface )
    {
        unsigned short  usdata;
        if( 0 == btnTRXMACMCRData->Tag )  // Dec
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
        m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][edit->Tag].value = usdata;
    }
    else
    {
        unsigned int  uidata;
        if( 0 == btnTRXMACMCRData->Tag )  // Dec
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

        if( WNDRV_HOST_INTERFACE_SDIO == m_sWiFiCap.host_interface )
        {
            m_sMCR_Setting[WIFI_MCR_HIF_SDIO][edit->Tag].value = uidata;
        }
        else // SPI
        {
            m_sMCR_Setting[WIFI_MCR_HIF_SPI][edit->Tag].value = uidata;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = CheckFields();
    if(!ok)
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Save MAC control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save MAC control register setting to file", "FAILURE", MB_OK );
        return;
    }
    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Save MAC control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save MAC control register setting to file", "FAILURE", MB_OK );
        return;
    }


    strcpy( str, SaveDialog->FileName.c_str() );
    for(int i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_WIFI_MAC_Obj.Set_MCR_Setting( i, j, m_sMCR_Setting[i][j] );
        }
    }

    for(int i=0; i<WIFI_MCR16_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_MCR16_MAX_NUM; j++ )
        {
            m_WIFI_MAC_Obj.Set_MCR16_Setting( i, j, m_sMCR16_Setting[i][j] );
        }
    }

    ok = m_WIFI_MAC_Obj.REQ_Write_To_File( str, m_sWiFiCap.host_interface );
    if( !ok )
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Save MAC control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save MAC control register setting to file", "FAILURE", MB_OK );
        return;
    }

    sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Save MAC control register setting to file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbSCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_SC_NUM; i++ )
    {
        cbSC[i]->Checked = cbSCHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_SC][i].checked = cbSCHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbMDPHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_MDP_NUM; i++ )
    {
        cbMDP[i]->Checked = cbMDPHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_MDP][i].checked = cbMDPHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbPLCIHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_PLCI_NUM; i++ )
    {
        cbPLCI[i]->Checked = cbPLCIHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_PLCI][i].checked = cbPLCIHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbMPTCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_MPTC_NUM; i++ )
    {
        cbMPTC[i]->Checked = cbMPTCHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_MPTC][i].checked = cbMPTCHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbNCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_NC_NUM; i++ )
    {
        cbNC[i]->Checked = cbNCHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_NC][i].checked = cbNCHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbBGHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_BG_NUM; i++ )
    {
        cbBG[i]->Checked = cbBGHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_BG][i].checked = cbBGHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbSEHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_SE_NUM; i++ )
    {
        cbSE[i]->Checked = cbSEHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_SE][i].checked = cbSEHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbTCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_TC_NUM; i++ )
    {
        cbTC[i]->Checked = cbTCHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_TC][i].checked = cbTCHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbRCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_RC_NUM; i++ )
    {
        cbRC[i]->Checked = cbRCHeader->Checked;
        m_sMCR_Setting[WIFI_MCR_RC][i].checked = cbRCHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::cbHIFHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_HIF_HPI_NUM; i++ )
    {
        cbHIF[i]->Checked = cbHIFHeader->Checked;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][i].checked = cbHIFHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::btnSYSMACMCRDataClick(TObject *Sender)
{
    if( 0 == btnSYSMACMCRData->Tag )  // Dec-->Hex
    {
        btnSYSMACMCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnSYSMACMCRData->Tag = 0;
    }
    ReDrawFields( DRAW_MCR_COMMON | DRAW_MCR_HIF );
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiMCR::btnTRXMACMCRDataClick(TObject *Sender)
{
    if( 0 == btnTRXMACMCRData->Tag )  // Dec-->Hex
    {
        btnTRXMACMCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTRXMACMCRData->Tag = 0;
    }
    ReDrawFields( DRAW_MCR_COMMON | DRAW_MCR_HIF );
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Load MAC control register setting from file fail";
        Application->MessageBox( "Execution Failure : Load MAC control register setting from file", "FAILURE", MB_OK );
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );

    ok = m_WIFI_MAC_Obj.REQ_Read_From_File( str, m_sWiFiCap.host_interface );

    if( !ok )
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Load MAC control register setting from file fail";
        Application->MessageBox( "Execution Failure : Load MAC control register setting from file", "FAILURE", MB_OK );
        return;
    }

    for(int i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            m_sMCR_Setting[i][j].value = m_WIFI_MAC_Obj.Get_MCR_Setting_Value( i, j );
        }
    }

    if( WNDRV_HOST_INTERFACE_HPI == m_sWiFiCap.host_interface )
    {
        for(int i=0; i<WIFI_MCR16_TYPE_NUM; i++ )
        {
            for(int j=0; j<WIFI_MCR16_MAX_NUM; j++ )
            {
                m_sMCR16_Setting[i][j].value = m_WIFI_MAC_Obj.Get_MCR16_Setting_Value( i, j );
            }
        }
    }

    ReDrawFields( DRAW_MCR_COMMON | DRAW_MCR_HIF );
    sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Load MAC control register setting from file successfully";

}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::btnWriteToRegisterClick(TObject *Sender)
{
    if( ! CheckFields() )
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString) "  Write MAC register fail";
        Application->MessageBox( "Execution Failure : Write MAC register", "FAILURE", MB_OK );
        return;
    }

    Compose_MCR_Parameter();
    Compose_MCR_Data();
    CurrentPageLock();
    m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteReg;
    m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
    sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::ConfirmCallback_WriteReg( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        m_iCount = 0;
        switch( m_sWiFiCap.host_interface )
        {
        case WNDRV_HOST_INTERFACE_SDIO:
        {
            Compose_SDIO_Parameter( WIFI_HIF_SDIO_SPECIFIC );
            Compose_SDIO_Data( WIFI_HIF_SDIO_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
            m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
        }
        break;

        case WNDRV_HOST_INTERFACE_HPI:
        {
            Compose_HPI_Parameter( WIFI_HIF_HPI_SPECIFIC );
            Compose_HPI_Data( WIFI_HIF_HPI_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
            m_WIFI_MAC_Obj.REQ_Write_MCR16_Setting_To_Reg_Start( m_sMCR16 );
        }
        break;

        case WNDRV_HOST_INTERFACE_SPI:
        {
            Compose_SPI_Parameter( WIFI_HIF_SPI_SPECIFIC );
            Compose_SPI_Data( WIFI_HIF_SPI_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
            m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
        }
        break;

        default:
            sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register successfully";
            break;
        }

    }
    break;

    case STATE_MAC_FAIL:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register fail";
        Application->MessageBox( "Execution Timeout : Write MAC register", "FAIL", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register timeout";
        Application->MessageBox( "Execution Timeout : Write MAC register", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_STOP:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register stop";
        CurrentPageReset();
    }
    break;
    }

}


//---------------------------------------------------------------------------
void TfrmWiFiMCR::ConfirmCallback_WriteHIF( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        m_iCount++;

        switch( m_sWiFiCap.host_interface )
        {
        case WNDRV_HOST_INTERFACE_SDIO:
        {
            if( WIFI_HIF_SDIO_PORT4 >= m_iCount )
            {
                Compose_SDIO_Parameter( (E_WIFI_HIF_SDIO) m_iCount );
                Compose_SDIO_Data( (E_WIFI_HIF_SDIO) m_iCount );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
            }
            else
            {
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register successfully";
            }
        }
        break;

        case WNDRV_HOST_INTERFACE_HPI:
        {
            if( WIFI_HIF_HPI_PORT == m_iCount )
            {
                Compose_HPI_Parameter( WIFI_HIF_HPI_PORT );
                Compose_HPI_Data( WIFI_HIF_HPI_PORT );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR16_Setting_To_Reg_Start( m_sMCR16 );
            }
            else
            {
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register successfully";
                CurrentPageReset();
            }
        }
        break;

        case WNDRV_HOST_INTERFACE_SPI:
        {
            if( WIFI_HIF_SPI_PORT3 >= m_iCount )
            {
                Compose_SPI_Parameter( (E_WIFI_HIF_SPI) m_iCount );
                Compose_SPI_Data( (E_WIFI_HIF_SPI) m_iCount );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
            }
            else
            {
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register successfully";
            }
        }
        break;
        }
    }
    break;

    case STATE_MAC_FAIL:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register fail";
        Application->MessageBox( "Execution Timeout : Write MAC register", "FAIL", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register timeout";
        Application->MessageBox( "Execution Timeout : Write MAC register", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_STOP:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Write MAC register stop";
        CurrentPageReset();
    }
    break;
    }

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmWiFiMCR::btnReadFromRegisterClick(TObject *Sender)
{
    CurrentPageLock();
    Compose_MCR_Parameter();
    Compose_MCR_Data();
    m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadReg;
    m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
    sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::ConfirmCallback_ReadReg( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        m_sMCR = m_WIFI_MAC_Obj.Get_MCR();
        DeCompose_MCR_Data();
        ReDrawFields( DRAW_MCR_COMMON );

        switch( m_sWiFiCap.host_interface )
        {
        case WNDRV_HOST_INTERFACE_SDIO:
        {
            Compose_SDIO_Parameter( WIFI_HIF_SDIO_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadHIF;
            m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
        }
        break;

        case WNDRV_HOST_INTERFACE_HPI:
        {
            Compose_HPI_Parameter( WIFI_HIF_HPI_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadHIF;
            m_WIFI_MAC_Obj.REQ_Read_MCR16_Setting_From_Reg_Start( m_sMCR16 );
        }
        break;

        case WNDRV_HOST_INTERFACE_SPI:
        {
            Compose_SPI_Parameter( WIFI_HIF_SPI_SPECIFIC );
            m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_ReadHIF;
            m_WIFI_MAC_Obj.REQ_Read_MCR_Setting_From_Reg_Start( m_sMCR );
        }
        break;

        default:
            sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
            break;
        }

    }
    break;

    case STATE_MAC_FAIL:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register fail";
        Application->MessageBox( "Execution Timeout : Read MAC register", "FAIL", MB_OK );
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register timeout";
        Application->MessageBox( "Execution Timeout : Read MAC register", "TIMEOUT", MB_OK );
    }
    break;

    case STATE_MAC_STOP:
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register stop";
        break;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::ConfirmCallback_ReadHIF( void )
{
    int state = m_WIFI_MAC_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_MAC_OK:
    {
        m_iCount++;

        switch( m_sWiFiCap.host_interface )
        {
        case WNDRV_HOST_INTERFACE_SDIO:
        {
            if( WIFI_HIF_SDIO_PORT4 >= m_iCount )
            {
                Compose_SDIO_Parameter( (E_WIFI_HIF_SDIO) m_iCount );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
            }
            else
            {
                ReDrawFields( DRAW_MCR_HIF );
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
                CurrentPageReset();
            }
        }
        break;

        case WNDRV_HOST_INTERFACE_HPI:
        {
            if( WIFI_HIF_HPI_PORT == m_iCount )
            {
                Compose_HPI_Parameter( WIFI_HIF_HPI_PORT );
                Compose_HPI_Data( WIFI_HIF_HPI_PORT );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR16_Setting_To_Reg_Start( m_sMCR16 );
            }
            else
            {
                ReDrawFields( DRAW_MCR_HIF );
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
                CurrentPageReset();
            }
        }
        break;

        case WNDRV_HOST_INTERFACE_SPI:
        {
            if( WIFI_HIF_SPI_PORT3 >= m_iCount )
            {
                Compose_SPI_Parameter( (E_WIFI_HIF_SPI) m_iCount );
                Compose_SPI_Data( (E_WIFI_HIF_SPI) m_iCount );
                m_WIFI_MAC_Obj.ConfirmCallback  = ::ConfirmCallback_WriteHIF;
                m_WIFI_MAC_Obj.REQ_Write_MCR_Setting_To_Reg_Start( m_sMCR );
            }
            else
            {
                ReDrawFields( DRAW_MCR_HIF );
                sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register successfully";
                CurrentPageReset();
            }
        }
        break;
        }
    }
    break;

    case STATE_MAC_FAIL:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register fail";
        Application->MessageBox( "Execution Timeout : Read MAC register", "FAIL", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_TIMEOUT:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register timeout";
        Application->MessageBox( "Execution Timeout : Read MAC register", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case STATE_MAC_STOP:
    {
        sbWiFiMCR->Panels->Items[0]->Text = (AnsiString)"  Read MAC register stop";
        CurrentPageReset();
    }
    break;
    }

}

//----------------------------------------------------------------------------
void __fastcall TfrmWiFiMCR::FormShow(TObject *Sender)
{
    if( m_bInit )
    {
        m_bInit = false;
        m_sWiFiCap = frmMainSel->Get_FinalWiFiCap();
        DisplayHIF();
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::DisplayHIF( void )
{
    int i;
    switch( m_sWiFiCap.host_interface )
    {
    case WNDRV_HOST_INTERFACE_SDIO:
    {
        pnlHIFHeader->Caption = "HIF_SDIO";
        for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
        {
            cbHIF[i]->Visible = true;
            lblHIF[i]->Visible = true;
            edtHIF[i]->Visible = true;
        }
        for( i; i<WIFI_HIF_MAX_NUM; i++ )
        {
            cbHIF[i]->Visible = false;
            lblHIF[i]->Visible = false;
            edtHIF[i]->Visible = false;
        }

        lblHIF[0]->Caption = "SSTS";
        lblHIF[1]->Caption = "PSCTL";
        lblHIF[2]->Caption = "SDRDR";
        lblHIF[3]->Caption = "TX_DATA_PORT";
        lblHIF[4]->Caption = "TX_STATUS_PORT";
        lblHIF[5]->Caption = "RX_STATUS_PORT";
        lblHIF[6]->Caption = "RX_DATA_PORT";

        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][0].name = "SSTS";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][1].name = "PSCTL";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][2].name = "SDRDR";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][3].name = "TX_DATA_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][4].name = "TX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][5].name = "RX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][6].name = "RX_DATA_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][7].name = "";

        for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
        {
            lblHIF[i]->Font->Color = clBlack;
            lblHIF[i]->Font->Style = TFontStyles();
            edtHIF[i]->ReadOnly = false;
            m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].RO = false;
            m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].RC = false;
        }

        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][0].addr = 0x010C;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][1].addr = 0x012C;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][2].addr = 0x0110;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][3].addr = 0x3000;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][4].addr = 0x4000;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][5].addr = 0x5000;
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][6].addr = 0x6000;
    }
    break;

    case WNDRV_HOST_INTERFACE_HPI:
    {
        pnlHIFHeader->Caption = "HIF_HPI";
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            cbHIF[i]->Visible = true;
            lblHIF[i]->Visible = true;
            edtHIF[i]->Visible = true;
        }

        lblHIF[0]->Caption = "HPI_CHIPID";
        lblHIF[1]->Caption = "HPI_MAC_STS";
        lblHIF[2]->Caption = "HPI_CTRL";
        lblHIF[3]->Caption = "HPI_POWER_CTRL";
        lblHIF[4]->Caption = "TX_DATA_PORT";
        lblHIF[5]->Caption = "TX_STATUS_PORT";
        lblHIF[6]->Caption = "RX_STATUS_PORT";
        lblHIF[7]->Caption = "RX_DATA_PORT";

        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][0].name = "HPI_CHIPID";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][1].name = "HPI_MAC_STS";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][2].name = "HPI_CTRL";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][3].name = "HPI_POWER_CTRL";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][4].name = "TX_DATA_PORT";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][5].name = "TX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][6].name = "RX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][7].name = "RX_DATA_PORT";
        // font style
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            lblHIF[i]->Font->Style = TFontStyles() << fsUnderline;
        }
        // font color
        lblHIF[0]->Font->Color = clMaroon;
        for( i=1; i<4; i++ )
        {
            lblHIF[i]->Font->Color = clWindowText;
        }
        for( i=4; i<WIFI_HIF_HPI_NUM; i++ )
        {
            lblHIF[i]->Font->Color = clGreen;
        }
        // read only
        edtHIF[0]->ReadOnly = true;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][0].RO = true;
        for( i=1; i<WIFI_HIF_HPI_NUM; i++ )
        {
            edtHIF[i]->ReadOnly = false;
            m_sMCR_Setting[WIFI_MCR16_HIF_HPI][i].RO = false;
        }

        // read/clear
        for( i=0; i<4; i++ )
        {
            m_sMCR_Setting[WIFI_MCR16_HIF_HPI][i].RC = false;
        }
        for( i=4; i<WIFI_HIF_HPI_NUM; i++ )
        {
            m_sMCR_Setting[WIFI_MCR16_HIF_HPI][i].RC = true;
        }

        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][0].addr = 0x0780;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][1].addr = 0x078C;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][2].addr = 0x07FC;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][3].addr = 0x07FE;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][4].addr = 0x0600;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][5].addr = 0x0640;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][6].addr = 0x0680;
        m_sMCR_Setting[WIFI_MCR16_HIF_HPI][7].addr = 0x06c0;
    }
    break;

    case WNDRV_HOST_INTERFACE_SPI:
    {
        pnlHIFHeader->Caption = "HIF_SPI";
        for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
        {
            cbHIF[i]->Visible = true;
            lblHIF[i]->Visible = true;
            edtHIF[i]->Visible = true;
        }

        for( i; i<WIFI_HIF_MAX_NUM; i++ )
        {
            cbHIF[i]->Visible = false;
            lblHIF[i]->Visible = false;
            edtHIF[i]->Visible = false;
        }

        lblHIF[0]->Caption = "SSTS";
        lblHIF[1]->Caption = "PSCTL";
        lblHIF[2]->Caption = "TX_DATA_PORT";
        lblHIF[3]->Caption = "TX_STATUS_PORT";
        lblHIF[4]->Caption = "RX_STATUS_PORT";
        lblHIF[5]->Caption = "RX_DATA_PORT";


        m_sMCR_Setting[WIFI_MCR_HIF_SPI][0].name = "SSTS";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][1].name = "PSCTL";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][2].name = "TX_DATA_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][3].name = "TX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][4].name = "RX_STATUS_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][5].name = "RX_DATA_PORT";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][6].name = "";
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][7].name = "";


        for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
        {
            lblHIF[i]->Font->Color = clBlack;
            lblHIF[i]->Font->Style = TFontStyles();
            edtHIF[i]->ReadOnly = false;
            m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].RO = false;
            m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].RC = false;
        }

        m_sMCR_Setting[WIFI_MCR_HIF_SPI][0].addr = 0x010C;
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][1].addr = 0x012C;
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][2].addr = 0x3000;
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][3].addr = 0x4000;
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][4].addr = 0x5000;
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][5].addr = 0x6000;
    }
    break;
    }
}

//=========================================================================
//---------------------------------------------------------------------------
void TfrmWiFiMCR::Compose_MCR_Parameter( void )
{

    // int i, j;

    // m_sMCR.number = m_sMCR_Setting[WIFI_MCR_RC][WIFI_RC_NUM-1].addr/sizeof(m_sMCR.mcr_data[0])+1;
    // m_sMCR.mcr_addr = m_sMCR_Setting[WIFI_MCR_SC][0].addr; // 0x0000
    // for( i=0; i<m_sMCR.number; i++ )
    //     m_sMCR.flag[i] = false;

    m_sMCR.count=0;
    for(int i=0; i<=WIFI_MCR_RC; i++ )
    {
        for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            if( m_sMCR_Setting[i][j].checked )
            {
                m_sMCR.mac_reg32[m_sMCR.count].index = m_sMCR_Setting[i][j].addr;
                m_sMCR.count++;
            }
        }
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::Compose_MCR_Data( void )
{
    int count=0;
    for(int i=0; i<=WIFI_MCR_RC; i++ )
    {
        for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            if( m_sMCR_Setting[i][j].checked )
            {
                m_sMCR.mac_reg32[count].mcr_data32 = m_sMCR_Setting[i][j].value;
                count++;
            }
        }
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::DeCompose_MCR_Data( void )
{
    int count=0;
    for(int i=0; i<=WIFI_MCR_RC; i++ )
    {
        for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            if( m_sMCR_Setting[i][j].checked )
            {
                m_sMCR_Setting[i][j].value = m_sMCR.mac_reg32[count].mcr_data32;
                count++;
            }
        }
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFiMCR::Compose_SDIO_Parameter( E_WIFI_HIF_SDIO hif_sdio )
{

    //int i;
    int j;

    if( WIFI_HIF_SDIO_SPECIFIC == hif_sdio )
    {
        // m_sMCR.number = (m_sMCR_Setting[WIFI_MCR_HIF_SDIO][WIFI_HIF_SDIO_SPECIFIC_NUM-1].addr-m_sMCR_Setting[WIFI_MCR_HIF_SDIO][0].addr)/sizeof(m_sMCR.mcr_data[0])+1;
        // m_sMCR.mcr_addr = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][0].addr; // 0x10C
        // for( i=0; i<m_sMCR.number; i++ )
        //     m_sMCR.flag[i] = false;
        m_sMCR.count=0;
        for( j=0; j<WIFI_HIF_SDIO_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].checked )
            {
                m_sMCR.mac_reg32[m_sMCR.count].index = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].addr;
                m_sMCR.count++;
            }
        }
    }
    else // SDIO port
    {
        m_sMCR.count   = 1;
        m_sMCR.mac_reg32[0].index = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][WIFI_HIF_SDIO_SPECIFIC_NUM+hif_sdio-1].addr; // 0x600
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::Compose_SDIO_Data( E_WIFI_HIF_SDIO hif_sdio )
{
    int count=0;
    if( WIFI_HIF_SDIO_SPECIFIC == hif_sdio )
    {
        for( int j=0; j<WIFI_HIF_SDIO_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].checked )
            {
                m_sMCR.mac_reg32[count].mcr_data32 = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].value;
                count++;
            }
        }
    }
    else // SDIO port
    {
        m_sMCR.mac_reg32[0].mcr_data32 = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][WIFI_HIF_SDIO_SPECIFIC_NUM+hif_sdio-1].value;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::DeCompose_SDIO_Data( E_WIFI_HIF_SDIO hif_sdio )
{
    int count=0;
    if( WIFI_HIF_SDIO_SPECIFIC == hif_sdio )
    {
        for( int j=0; j<WIFI_HIF_SDIO_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].checked )
            {
                m_sMCR_Setting[WIFI_MCR_HIF_SDIO][j].value = m_sMCR.mac_reg32[count].mcr_data32;
                count++;
            }
        }
    }
    else // SDIO port
    {
        m_sMCR_Setting[WIFI_MCR_HIF_SDIO][WIFI_HIF_SDIO_SPECIFIC_NUM+hif_sdio-1].value = m_sMCR.mac_reg32[0].mcr_data32;
    }

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFiMCR::Compose_HPI_Parameter( E_WIFI_HIF_HPI hif_hpi )
{

    //int i;
    int j;

    if( WIFI_HIF_HPI_SPECIFIC == hif_hpi )
    {
//        m_sMCR16.number = (m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][3].addr-m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][0].addr)/sizeof(m_sMCR16.mcr_data[0])+1;
//        m_sMCR16.mcr_addr = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][0].addr; // 0x780
//        for( i=0; i<m_sMCR16.number; i++ )
//            m_sMCR16.flag[i] = false;
        m_sMCR16.count=0;
        for( j=0; j<WIFI_HIF_HPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16.mac_reg16[m_sMCR16.count].index = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].addr;
                m_sMCR16.count++;
            }
        }
    }
    else // HPI port
    {
        // m_sMCR16.number = (m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][WIFI_HIF_HPI_NUM-1].addr-m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][WIFI_HIF_HPI_SPECIFIC_NUM].addr)/sizeof(m_sMCR16.mcr_data[0])+1;
        // m_sMCR16.mcr_addr = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][WIFI_HIF_HPI_SPECIFIC_NUM].addr; // 0x600
        // for( i=0; i<m_sMCR16.number; i++ )
        //     m_sMCR16.flag[i] = false;
        m_sMCR16.count=0;
        for( j=WIFI_HIF_HPI_SPECIFIC_NUM; j<WIFI_MCR16_MAX_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16.mac_reg16[m_sMCR16.count].index = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].addr;
                m_sMCR16.count++;
            }
        }
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::Compose_HPI_Data( E_WIFI_HIF_HPI hif_hpi )
{

    int j;
    int count=0;
    if( WIFI_HIF_HPI_SPECIFIC == hif_hpi )
    {
        for( j=0; j<WIFI_HIF_HPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16.mac_reg16[count].mcr_data16 = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].value;
                count++;
            }
        }
    }
    else // HPI port
    {
        for( j=WIFI_HIF_HPI_SPECIFIC_NUM; j<WIFI_HIF_HPI_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16.mac_reg16[count].mcr_data16 = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].value;
                count++;
            }
        }
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::DeCompose_HPI_Data( E_WIFI_HIF_HPI hif_hpi )
{

    int j;
    int count=0;
    if( WIFI_HIF_HPI_SPECIFIC == hif_hpi )
    {
        for( j=0; j<WIFI_HIF_HPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].value = m_sMCR16.mac_reg16[count].mcr_data16;
                count++;
            }
        }
    }
    else // HIF port
    {
        for( j=WIFI_HIF_HPI_SPECIFIC_NUM; j<WIFI_HIF_HPI_NUM; j++ )
        {
            if( m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].checked )
            {
                m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][j].value = m_sMCR16.mac_reg16[count].mcr_data16;
                count++;
            }
        }
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFiMCR::Compose_SPI_Parameter( E_WIFI_HIF_SPI hif_spi )
{

    //int i;
    int j;

    if( WIFI_HIF_SPI_SPECIFIC == hif_spi )
    {
        //  m_sMCR.number = (m_sMCR_Setting[WIFI_MCR_HIF_SPI][WIFI_HIF_SPI_SPECIFIC_NUM-1].addr-m_sMCR_Setting[WIFI_MCR_HIF_SPI][0].addr)/sizeof(m_sMCR.mcr_data[0])+1;
        //  m_sMCR.mcr_addr = m_sMCR_Setting[WIFI_MCR_HIF_SPI][0].addr; // 0x10C
        //  for( i=0; i<m_sMCR.number; i++ )
        //      m_sMCR.flag[i] = false;
        m_sMCR.count=0;
        for( j=0; j<WIFI_HIF_SPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].checked )
            {
                m_sMCR.mac_reg32[m_sMCR.count].index = m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].addr;
                m_sMCR.count++;
            }
        }
    }
    else // SPI port
    {
        m_sMCR.count   = 1;
        m_sMCR.mac_reg32[0].index = m_sMCR_Setting[WIFI_MCR_HIF_SPI][WIFI_HIF_SPI_SPECIFIC_NUM+hif_spi-1].addr; // 0x600
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::Compose_SPI_Data( E_WIFI_HIF_SPI hif_spi )
{

    if( WIFI_HIF_SPI_SPECIFIC == hif_spi )
    {
        int count = 0;
        for( int j=0; j<WIFI_HIF_SPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].checked )
            {
                m_sMCR.mac_reg32[count].mcr_data32 = m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].value;
                count++;
            }
        }
    }
    else // SPI port
    {
        m_sMCR.mac_reg32[0].mcr_data32 = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][WIFI_HIF_SPI_SPECIFIC_NUM+hif_spi-1].value;
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiMCR::DeCompose_SPI_Data( E_WIFI_HIF_SPI hif_spi )
{

    if( WIFI_HIF_SPI_SPECIFIC == hif_spi )
    {
        int count=0;
        for( int j=0; j<WIFI_HIF_SPI_SPECIFIC_NUM; j++ )
        {
            if( m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].checked )
            {
                m_sMCR_Setting[WIFI_MCR_HIF_SPI][j].value = m_sMCR.mac_reg32[count].mcr_data32;
                count++;
            }
        }
    }
    else // SPI port
    {
        m_sMCR_Setting[WIFI_MCR_HIF_SPI][WIFI_HIF_SPI_SPECIFIC_NUM+hif_spi-1].value = m_sMCR.mac_reg32[0].mcr_data32;
    }

}

