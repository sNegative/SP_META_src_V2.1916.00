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
 *   form_WiFiMCR.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi MAC control register form header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_WIFIMCR_H_
#define _FORM_WIFIMCR_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>

#ifndef  _WIFI_MAC_H_
#include "wifi_mac.h"
#endif

//---------------------------------------------------------------------------
class TfrmWiFiMCR : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TPanel *pnlSC;
    TPanel *Panel2;
    TPanel *Panel3;
    TLabel *lblSC0;
    TLabel *lblSC1;
    TLabel *lblSC2;
    TLabel *lblSC3;
    TEdit *edtSC0;
    TEdit *edtSC1;
    TEdit *edtSC2;
    TEdit *edtSC3;
    TPanel *pnlMDP;
    TPanel *Panel5;
    TLabel *lblMDP00;
    TLabel *lblMDP01;
    TLabel *lblMDP02;
    TLabel *lblMDP03;
    TEdit *edtMDP00;
    TEdit *edtMDP01;
    TEdit *edtMDP02;
    TEdit *edtMDP03;
    TLabel *lblMDP04;
    TEdit *edtMDP04;
    TLabel *lblMDP05;
    TEdit *edtMDP05;
    TLabel *lblMDP06;
    TEdit *edtMDP06;
    TLabel *lblMDP07;
    TEdit *edtMDP07;
    TLabel *lblMDP08;
    TEdit *edtMDP08;
    TLabel *lblMDP09;
    TEdit *edtMDP09;
    TLabel *lblMDP10;
    TEdit *edtMDP10;
    TLabel *lblMDP11;
    TEdit *edtMDP11;
    TLabel *lblMDP12;
    TEdit *edtMDP12;
    TLabel *lblMDP13;
    TEdit *edtMDP13;
    TPanel *pnlPLCI;
    TPanel *Panel7;
    TPanel *Panel8;
    TLabel *lblPLCI00;
    TEdit *edtPLCI00;
    TLabel *lblPLCI01;
    TEdit *edtPLCI01;
    TLabel *lblPLCI02;
    TEdit *edtPLCI02;
    TLabel *lblPLCI03;
    TEdit *edtPLCI03;
    TLabel *lblPLCI04;
    TEdit *edtPLCI04;
    TLabel *lblPLCI05;
    TEdit *edtPLCI05;
    TLabel *lblPLCI06;
    TEdit *edtPLCI06;
    TLabel *lblPLCI07;
    TEdit *edtPLCI07;
    TLabel *lblPLCI08;
    TEdit *edtPLCI08;
    TLabel *lblPLCI09;
    TEdit *edtPLCI09;
    TLabel *lblPLCI10;
    TEdit *edtPLCI10;
    TLabel *lblPLCI11;
    TEdit *edtPLCI11;
    TPanel *pnlMPTC;
    TPanel *Panel10;
    TLabel *lblMPTC00;
    TEdit *edtMPTC00;
    TEdit *edtMPTC01;
    TEdit *edtMPTC02;
    TEdit *edtMPTC03;
    TEdit *edtMPTC04;
    TEdit *edtMPTC05;
    TLabel *lblMPTC01;
    TLabel *lblMPTC02;
    TLabel *lblMPTC03;
    TLabel *lblMPTC04;
    TLabel *lblMPTC05;
    TLabel *lblMPTC06;
    TLabel *lblMPTC07;
    TEdit *edtMPTC06;
    TEdit *edtMPTC07;
    TLabel *lblMPTC08;
    TShape *Shape1;
    TLabel *Label40;
    TLabel *Label41;
    TEdit *edtMPTC08;
    TEdit *edtMPTC09;
    TEdit *edtMPTC10;
    TEdit *edtMPTC11;
    TEdit *edtMPTC12;
    TLabel *lblMPTC09;
    TLabel *lblMPTC10;
    TLabel *lblMPTC11;
    TLabel *lblMPTC12;
    TLabel *lblMPTC13;
    TEdit *edtMPTC13;
    TEdit *edtMPTC14;
    TLabel *lblMPTC14;
    TLabel *lblMPTC15;
    TEdit *edtMPTC15;
    TLabel *lblMPTC16;
    TEdit *edtMPTC16;
    TEdit *edtMPTC17;
    TLabel *lblMPTC17;
    TPanel *pnlNC;
    TPanel *Panel12;
    TLabel *lblNC0;
    TLabel *lblNC1;
    TLabel *lblNC2;
    TLabel *lblNC3;
    TEdit *edtNC0;
    TEdit *edtNC1;
    TEdit *edtNC2;
    TEdit *edtNC3;
    TLabel *lblMDP14;
    TEdit *edtMDP14;
    TLabel *lblMDP15;
    TEdit *edtMDP15;
    TLabel *lblMDP16;
    TEdit *edtMDP16;
    TShape *Shape3;
    TPanel *pnlBG;
    TPanel *Panel14;
    TLabel *lblBG0;
    TLabel *lblBG1;
    TLabel *lblBG2;
    TLabel *lblBG3;
    TLabel *lblBG4;
    TLabel *lblBG5;
    TLabel *lblBG6;
    TLabel *lblBG7;
    TEdit *edtBG0;
    TEdit *edtBG1;
    TEdit *edtBG2;
    TEdit *edtBG3;
    TEdit *edtBG4;
    TEdit *edtBG5;
    TEdit *edtBG6;
    TEdit *edtBG7;
    TPanel *pnlSE;
    TPanel *Panel16;
    TLabel *lblSE00;
    TEdit *edtSE00;
    TLabel *lblSE01;
    TLabel *lblSE02;
    TLabel *lblSE03;
    TLabel *lblSE04;
    TLabel *lblSE05;
    TLabel *lblSE06;
    TLabel *lblSE07;
    TLabel *lblSE08;
    TLabel *lblSE09;
    TLabel *lblSE10;
    TEdit *edtSE01;
    TEdit *edtSE02;
    TEdit *edtSE03;
    TEdit *edtSE04;
    TEdit *edtSE05;
    TEdit *edtSE06;
    TEdit *edtSE07;
    TEdit *edtSE08;
    TEdit *edtSE09;
    TEdit *edtSE10;
    TPanel *pnlTC;
    TPanel *Panel18;
    TLabel *lblTC00;
    TLabel *lblTC01;
    TLabel *lblTC02;
    TLabel *lblTC03;
    TLabel *lblTC04;
    TLabel *lblTC05;
    TLabel *lblTC06;
    TLabel *lblTC07;
    TLabel *lblTC08;
    TLabel *lblTC09;
    TLabel *lblTC10;
    TLabel *lblTC11;
    TEdit *edtTC00;
    TEdit *edtTC01;
    TEdit *edtTC02;
    TEdit *edtTC03;
    TEdit *edtTC04;
    TEdit *edtTC05;
    TEdit *edtTC06;
    TEdit *edtTC07;
    TEdit *edtTC08;
    TEdit *edtTC09;
    TEdit *edtTC10;
    TEdit *edtTC11;
    TPanel *pnlRC;
    TPanel *Panel20;
    TLabel *lblRC00;
    TLabel *lblRC01;
    TLabel *lblRC02;
    TLabel *lblRC03;
    TLabel *lblRC04;
    TLabel *lblRC05;
    TLabel *lblRC06;
    TLabel *lblRC07;
    TLabel *lblRC08;
    TLabel *lblRC09;
    TEdit *edtRC00;
    TEdit *edtRC01;
    TEdit *edtRC02;
    TEdit *edtRC03;
    TEdit *edtRC04;
    TEdit *edtRC05;
    TEdit *edtRC06;
    TEdit *edtRC07;
    TEdit *edtRC08;
    TEdit *edtRC09;
    TEdit *edtRC10;
    TEdit *edtRC11;
    TLabel *lblRC10;
    TLabel *lblRC11;
    TLabel *lblRC12;
    TLabel *lblRC13;
    TEdit *edtRC12;
    TEdit *edtRC13;
    TEdit *edtRC14;
    TLabel *lblRC14;
    TPanel *pnlHIFHeader;
    TPanel *Panel22;
    TLabel *lblHIF0;
    TLabel *lblHIF1;
    TLabel *lblHIF2;
    TEdit *edtHIF0;
    TEdit *edtHIF1;
    TEdit *edtHIF2;
    TLabel *lblHIF3;
    TEdit *edtHIF3;
    TEdit *edtHIF4;
    TEdit *edtHIF5;
    TEdit *edtHIF6;
    TEdit *edtHIF7;
    TLabel *lblHIF4;
    TLabel *lblHIF5;
    TLabel *lblHIF6;
    TLabel *lblHIF7;
    TButton *btnReadFromRegister;
    TButton *btnWriteToRegister;
    TButton *btnLoadFromFile;
    TButton *btnSaveToFile;
    TStatusBar *sbWiFiMCR;
    TLabel *lblMDP17;
    TEdit *edtMDP17;
    TButton *btnSYSMACMCRData;
    TButton *btnTRXMACMCRData;
    TTimer *HintTimer;
    TSaveDialog *SaveDialog;
    TOpenDialog *OpenDialog;
    TStaticText *lblHint;
    TCheckBox *cbSCHeader;
    TCheckBox *cbMDPHeader;
    TCheckBox *cbSC0;
    TCheckBox *cbSC1;
    TCheckBox *cbSC2;
    TCheckBox *cbSC3;
    TCheckBox *cbMDP00;
    TCheckBox *cbMDP01;
    TCheckBox *cbMDP02;
    TCheckBox *cbMDP03;
    TCheckBox *cbMDP04;
    TCheckBox *cbMDP05;
    TCheckBox *cbMDP06;
    TCheckBox *cbMDP07;
    TCheckBox *cbMDP08;
    TCheckBox *cbMDP09;
    TCheckBox *cbMDP10;
    TCheckBox *cbMDP11;
    TCheckBox *cbMDP12;
    TCheckBox *cbMDP13;
    TCheckBox *cbMDP14;
    TCheckBox *cbMDP15;
    TCheckBox *cbMDP16;
    TCheckBox *cbMDP17;
    TCheckBox *cbPLCIHeader;
    TCheckBox *cbPLCI00;
    TCheckBox *cbPLCI01;
    TCheckBox *cbPLCI02;
    TCheckBox *cbPLCI03;
    TCheckBox *cbPLCI04;
    TCheckBox *cbPLCI05;
    TCheckBox *cbPLCI06;
    TCheckBox *cbPLCI07;
    TCheckBox *cbPLCI08;
    TCheckBox *cbPLCI09;
    TCheckBox *cbPLCI10;
    TCheckBox *cbPLCI11;
    TCheckBox *cbMPTCHeader;
    TCheckBox *cbMPTC00;
    TCheckBox *cbMPTC01;
    TCheckBox *cbMPTC02;
    TCheckBox *cbMPTC03;
    TCheckBox *CheckBox42;
    TCheckBox *CheckBox43;
    TCheckBox *cbMPTC06;
    TCheckBox *cbMPTC07;
    TCheckBox *cbMPTC08;
    TCheckBox *cbMPTC09;
    TCheckBox *cbMPTC10;
    TCheckBox *cbMPTC11;
    TCheckBox *cbNCHeader;
    TCheckBox *cbBGHeader;
    TCheckBox *cbMPTC12;
    TCheckBox *cbMPTC13;
    TCheckBox *cbMPTC14;
    TCheckBox *cbMPTC15;
    TCheckBox *cbMPTC04;
    TCheckBox *cbMPTC05;
    TCheckBox *cbNC0;
    TCheckBox *cbNC1;
    TCheckBox *cbNC2;
    TCheckBox *cbNC3;
    TCheckBox *cbBG0;
    TCheckBox *cbBG1;
    TCheckBox *cbBG2;
    TCheckBox *cbBG3;
    TCheckBox *cbBG4;
    TCheckBox *cbBG5;
    TCheckBox *cbBG6;
    TCheckBox *cbBG7;
    TCheckBox *cbSEHeader;
    TCheckBox *cbTCHeader;
    TCheckBox *cbRCHeader;
    TCheckBox *cbHIFHeader;
    TCheckBox *cbTC00;
    TCheckBox *cbTC11;
    TCheckBox *cbTC10;
    TCheckBox *cbTC09;
    TCheckBox *cbTC08;
    TCheckBox *cbTC07;
    TCheckBox *cbTC06;
    TCheckBox *cbTC05;
    TCheckBox *cbTC04;
    TCheckBox *cbTC03;
    TCheckBox *cbTC02;
    TCheckBox *cbTC01;
    TCheckBox *cbSE00;
    TCheckBox *cbSE01;
    TCheckBox *cbSE02;
    TCheckBox *cbSE03;
    TCheckBox *cbSE04;
    TCheckBox *cbSE05;
    TCheckBox *cbSE06;
    TCheckBox *cbSE07;
    TCheckBox *cbSE08;
    TCheckBox *cbSE09;
    TCheckBox *cbSE10;
    TCheckBox *cbRC00;
    TCheckBox *cbRC01;
    TCheckBox *cbRC02;
    TCheckBox *cbRC03;
    TCheckBox *cbRC04;
    TCheckBox *cbRC05;
    TCheckBox *cbRC06;
    TCheckBox *cbRC07;
    TCheckBox *cbRC08;
    TCheckBox *cbRC09;
    TCheckBox *cbRC10;
    TCheckBox *cbRC11;
    TCheckBox *cbRC12;
    TCheckBox *cbRC13;
    TCheckBox *cbRC14;
    TCheckBox *cbHIF0;
    TCheckBox *cbHIF1;
    TCheckBox *cbHIF2;
    TCheckBox *cbHIF3;
    TCheckBox *cbHIF4;
    TCheckBox *cbHIF5;
    TCheckBox *cbHIF6;
    TCheckBox *cbHIF7;
    TCheckBox *cbMPTC16;
    TCheckBox *cbMPTC17;
    TLabel *Label1;
    TLabel *Label2;
    TShape *Shape4;
    TLabel *Label3;
    void __fastcall edtSCCheck(TObject *Sender);
    void __fastcall edtMDPCheck(TObject *Sender);
    void __fastcall edtPLCICheck(TObject *Sender);
    void __fastcall edtMPTCCheck(TObject *Sender);
    void __fastcall edtNCCheck(TObject *Sender);
    void __fastcall edtBGCheck(TObject *Sender);
    void __fastcall edtSECheck(TObject *Sender);
    void __fastcall edtTCCheck(TObject *Sender);
    void __fastcall edtRCCheck(TObject *Sender);
    void __fastcall edtHIFCheck(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall cbSCHeaderClick(TObject *Sender);
    void __fastcall cbMDPHeaderClick(TObject *Sender);
    void __fastcall cbPLCIHeaderClick(TObject *Sender);
    void __fastcall cbMPTCHeaderClick(TObject *Sender);
    void __fastcall cbNCHeaderClick(TObject *Sender);
    void __fastcall cbBGHeaderClick(TObject *Sender);
    void __fastcall cbSEHeaderClick(TObject *Sender);
    void __fastcall cbTCHeaderClick(TObject *Sender);
    void __fastcall cbRCHeaderClick(TObject *Sender);
    void __fastcall cbHIFHeaderClick(TObject *Sender);
    void __fastcall btnSYSMACMCRDataClick(TObject *Sender);
    void __fastcall btnTRXMACMCRDataClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall btnWriteToRegisterClick(TObject *Sender);
    void __fastcall btnReadFromRegisterClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    // UI
    TLabel *lblSC[WIFI_SC_NUM];
    TLabel *lblMDP[WIFI_MDP_NUM];
    TLabel *lblPLCI[WIFI_PLCI_NUM];
    TLabel *lblMPTC[WIFI_MPTC_NUM];
    TLabel *lblNC[WIFI_NC_NUM];
    TLabel *lblBG[WIFI_BG_NUM];
    TLabel *lblSE[WIFI_SE_NUM];
    TLabel *lblTC[WIFI_TC_NUM];
    TLabel *lblRC[WIFI_RC_NUM];
    TLabel *lblHIF[WIFI_HIF_MAX_NUM];
    TEdit  *edtSC[WIFI_SC_NUM];
    TEdit  *edtMDP[WIFI_MDP_NUM];
    TEdit  *edtPLCI[WIFI_PLCI_NUM];
    TEdit  *edtMPTC[WIFI_MPTC_NUM];
    TEdit  *edtNC[WIFI_NC_NUM];
    TEdit  *edtBG[WIFI_BG_NUM];
    TEdit  *edtSE[WIFI_SE_NUM];
    TEdit  *edtTC[WIFI_TC_NUM];
    TEdit  *edtRC[WIFI_RC_NUM];
    TEdit  *edtHIF[WIFI_HIF_MAX_NUM];
    TCheckBox *cbSC[WIFI_SC_NUM];
    TCheckBox *cbMDP[WIFI_MDP_NUM];
    TCheckBox *cbPLCI[WIFI_PLCI_NUM];
    TCheckBox *cbMPTC[WIFI_MPTC_NUM];
    TCheckBox *cbNC[WIFI_NC_NUM];
    TCheckBox *cbBG[WIFI_BG_NUM];
    TCheckBox *cbSE[WIFI_SE_NUM];
    TCheckBox *cbTC[WIFI_TC_NUM];
    TCheckBox *cbRC[WIFI_RC_NUM];
    TCheckBox *cbHIF[WIFI_HIF_MAX_NUM];
    bool m_bInit;
    int   m_final_WiFiId;
    WiFi_ChipCapability_S m_sWiFiCap;
    S_WiFi_MCR  m_sMCR;
    S_WiFi_MCR16  m_sMCR16;
    S_WIFI_MCR_SETTING  m_sMCR_Setting[WIFI_MCR_TYPE_NUM][WIFI_MCR_MAX_NUM];
    S_WIFI_MCR16_SETTING  m_sMCR16_Setting[WIFI_MCR16_TYPE_NUM][WIFI_MCR16_MAX_NUM];
    CWIFIMAC   m_WIFI_MAC_Obj;

    // HIP
    int  m_iCount;
public:		// User declarations
    __fastcall TfrmWiFiMCR(TComponent* Owner);
    void Init( void );

    // UI
    void  ReDrawFields( int idx );
    bool  CheckFields( void );
    void  ShowHintLabel( TControl *sender, char* hint );
    void  CurrentPageLock( void );
    void  CurrentPageReset( void );
    void  DisplayHIF( void );

    // MCR read/write
    void  Compose_MCR_Parameter( void );
    void  Compose_MCR_Data( void );
    void  DeCompose_MCR_Data( void );

    // HPI read/write
    void  Compose_SDIO_Parameter( E_WIFI_HIF_SDIO hif_sdio );
    void  Compose_SDIO_Data( E_WIFI_HIF_SDIO hif_sdio );
    void  DeCompose_SDIO_Data( E_WIFI_HIF_SDIO hif_sdio );
    void  Compose_HPI_Parameter( E_WIFI_HIF_HPI hif_hpi );
    void  Compose_HPI_Data( E_WIFI_HIF_HPI hif_hpi );
    void  DeCompose_HPI_Data( E_WIFI_HIF_HPI hif_hpi );
    void  Compose_SPI_Parameter( E_WIFI_HIF_SPI hif_spi );
    void  Compose_SPI_Data( E_WIFI_HIF_SPI hif_spi );
    void  DeCompose_SPI_Data( E_WIFI_HIF_SPI hif_spi );

    // call back
    void  ConfirmCallback_ReadReg( void );
    void  ConfirmCallback_ReadHIF( void );
    void  ConfirmCallback_WriteReg( void );
    void  ConfirmCallback_WriteHIF( void );


};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFiMCR *frmWiFiMCR;
//---------------------------------------------------------------------------
#endif
