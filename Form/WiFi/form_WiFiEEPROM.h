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
 *   form_WiFiEEPROM.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi EEPROM form header
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

#ifndef _FORM_WIFIEEPROM_H_
#define _FORM_WIFIEEPROM_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif
//---------------------------------------------------------------------------
class TfrmWiFiEEPROM : public TForm
{
__published:	// IDE-managed Components
    TPanel *pnlPCL;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *Label25;
    TLabel *Label26;
    TLabel *Label28;
    TEdit *edtCCKCHDAC00;
    TEdit *edtCCKCHDAC01;
    TEdit *edtCCKCHDAC02;
    TEdit *edtCCKCHDAC03;
    TEdit *edtCCKCHDAC04;
    TEdit *edtCCKCHDAC05;
    TEdit *edtCCKCHDAC06;
    TEdit *edtCCKCHDAC07;
    TEdit *edtCCKCHDAC08;
    TEdit *edtCCKCHDAC09;
    TEdit *edtCCKCHDAC0A;
    TEdit *edtCCKCHDAC0B;
    TEdit *edtOFDMCHDAC01;
    TEdit *edtOFDMCHDAC02;
    TEdit *edtOFDMCHDAC03;
    TEdit *edtOFDMCHDAC04;
    TEdit *edtOFDMCHDAC05;
    TEdit *edtOFDMCHDAC06;
    TEdit *edtOFDMCHDAC07;
    TEdit *edtOFDMCHDAC08;
    TEdit *edtOFDMCHDAC09;
    TEdit *edtOFDMCHDAC0A;
    TEdit *edtOFDMCHDAC0B;
    TEdit *edtOFDMCHDAC00;
    TPanel *pnl2400MTXP;
    TPanel *Panel2;
    TPanel *pnlWGI;
    TLabel *lblBBChipID;
    TEdit *edtBBChipID;
    TLabel *lblRFChipID;
    TEdit *edtRFChipID;
    TLabel *lblSN;
    TEdit *edtSN;
    TLabel *lblMACAddr;
    TEdit *edtMACAddr5;
    TPanel *pnlTXDC;
    TPanel *Panel3;
    TLabel *lblTXIDC0x;
    TEdit *edtTXIDC;
    TEdit *edtTXQDC;
    TLabel *lblTXQDC0x;
    TLabel *Label29;
    TLabel *Label30;
    TButton *btnWGI;
    TButton *btnTXDC;
    TButton *btn2400MTXP;
    TLabel *lblBBChipID0x;
    TLabel *lblRFChipID0x;
    TLabel *lblSN0x;
    TLabel *lblMACAddr0x;
    TShape *Shape1;
    TLabel *Label40;
    TButton *btnUploadFromEEPROM;
    TButton *btnDownloadToEEPROM;
    TStatusBar *sbWiFiEEPROM;
    TButton *btnSaveToFile;
    TButton *btnLoadFromFile;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TSaveDialog *SaveDialog;
    TOpenDialog *OpenDialog;
    TEdit *edtMACAddr4;
    TEdit *edtMACAddr3;
    TEdit *edtMACAddr2;
    TEdit *edtMACAddr1;
    TEdit *edtMACAddr0;
    TPanel *Panel1;
    TPanel *Panel4;
    TLabel *lblChecksum;
    TEdit *edtChecksum;
    TLabel *lblChecksum0x;
    TEdit *edtCCKCHDAC0C;
    TEdit *edtCCKCHDAC0D;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *edtOFDMCHDAC0C;
    TEdit *edtOFDMCHDAC0D;
    void __fastcall btnWGIClick(TObject *Sender);
    void __fastcall btnTXDCClick(TObject *Sender);
    void __fastcall btn2400MTXPClick(TObject *Sender);
    void __fastcall edtRFChipIDCheck(TObject *Sender);
    void __fastcall edtSNCheck(TObject *Sender);
    void __fastcall edtBBChipIDCheck(TObject *Sender);
    void __fastcall edtMACAddrCheck(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall btnUploadFromEEPROMClick(TObject *Sender);
    void __fastcall btnDownloadToEEPROMClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
private:	// User declarations
    // common
    bool    m_bInit;
    WiFi_ChipCapability_S m_sWiFiCap;
    CWIFIEE   m_WIFI_EE_Obj;
    S_WIFI_EEPROM  m_sEE;
    S_WIFI_EE_GENERAL    m_sEEGeneral;
    WiFi_TxPower_2400M_S  m_sTxPwr2400M;
    WiFi_TxPower_5000M_S  m_sTxPwr5000M;
    unsigned short        m_usReserved3;
    // WiFi_DAC_DC_Offset_S  m_sTxDcOffset;
    // unsigned short m_usChecksum;

    // UI
    TEdit   *edtMACAddr[6];
    TEdit   *edtCCKCHDAC[NUM_TX_POWER_2400M_CH];
    TEdit   *edtOFDMCHDAC[NUM_TX_POWER_2400M_CH];


public:		// User declarations
    __fastcall TfrmWiFiEEPROM(TComponent* Owner);
    void Init( void );

    // UI
    void  ReDrawFields( int idx );
    bool  CheckFields( void );
    void  CurrentPageReset( void );
    void  CurrentPageLock( void );
    void  ShowHintLabel( TControl *sender, char* hint );

    // EEPROM read/write

    void Compose_EEPROM_Data( void );
    void DeCompose_EEPROM_Data( void );

    // callback
    void  ConfirmCallback_ReadEE( void );
    void  ConfirmCallback_WriteEE( void );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFiEEPROM *frmWiFiEEPROM;
//---------------------------------------------------------------------------
#endif
