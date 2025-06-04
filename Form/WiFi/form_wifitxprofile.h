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
 *   form_WiFiTxProfile.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi TX profile form header
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


#ifndef  _FORM_WIFITXPROFILE_H_
#define  _FORM_WIFITXPROFILE_H_

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

// WiFi
#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_APC_2400M_H_
#include "wifi_apc_2400m.h"
#endif

#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TfrmWiFiTxProfile : public TForm
{
__published:	// IDE-managed Components
    TPanel *pnlPCL;
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
    TButton *btnUploadFromFlash;
    TButton *btnDownloadToFlash;
    TButton *btnChangeDB;
    TButton *btnLoadFromFile;
    TButton *btnSaveToFile;
    TStatusBar *sbWiFiTXP;
    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    TStaticText *lblHint;
    TTimer *HintTimer;
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
    TLabel *Label27;
    TEdit *edtOFDMCHDAC00;
    TButton *btnTxPowerDac;
    TLabel *Label28;
    TEdit *edtCCKCHDAC0C;
    TEdit *edtCCKCHDAC0D;
    TLabel *Label1;
    TEdit *edtOFDMCHDAC0C;
    TEdit *edtOFDMCHDAC0D;
    TLabel *Label2;
    TButton *btnLoadFromEEPROM;
    void __fastcall btnUploadFromFlashClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall edtCCKCHDACCheck(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall btnChangeDBClick(TObject *Sender);
    void __fastcall btnDownloadToFlashClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnTxPowerDacClick(TObject *Sender);
    void __fastcall edtOFDMCHDACCheck(TObject *Sender);
    void __fastcall btnLoadFromEEPROMClick(TObject *Sender);


private:	// User declarations


    // common
    bool    m_bInit;
    WiFi_ChipCapability_S m_sWiFiCap;
    CWIFIAPC  m_WIFI_TXP_Obj;
    WiFi_TxPower_2400M_S  m_sTxPwr2400M;
    WiFi_TxPower_5000M_S  m_sTxPwr5000M;
    S_WIFI_EEPROM   m_sEE;

    // UI
    TEdit   *edtCCKCHDAC[NUM_TX_POWER_2400M_CH];
    TEdit   *edtOFDMCHDAC[NUM_TX_POWER_2400M_CH];

    // EEPROM
    CWIFIEE   m_WIFI_EE_Obj;

public:		// User declarations
    __fastcall TfrmWiFiTxProfile(TComponent* Owner);
    void Init( void );

    // UI
    void  ReDrawFields( void );
    bool  CheckFields( void );
    void  CurrentPageReset( void );
    void  CurrentPageLock( void );
    void  ShowHintLabel( TControl *sender, char* hint );

    // EEPROM
    void  Compose_EEPROM_Parameter( void );
    void  ConfirmCallback_ReadEE( void );
    void  WiFiTxPowerEEToNVRAM( void );

    // NVRAM
    void  UploadTxPower2400MFromFlashDone( void );
    void  UploadTxPower5000MFromFlashDone( void );
    void  DownloadTxPower2400MToFlashDone( void );
    void  DownloadTxPower5000MToFlashDone( void );

    // global information
    void  WIFI_APC_Obj( CWIFIAPC  *wifi_apc_obj );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFiTxProfile *frmWiFiTxProfile;
//---------------------------------------------------------------------------
#endif
