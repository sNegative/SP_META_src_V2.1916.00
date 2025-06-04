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
 *   form_WiFiALC2400M.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi ALC 2.4G form header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#ifndef _FORM_WIFIALC2400M_H_
#define _FORM_WIFIALC2400M_H_

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

#ifndef  _WIFI_ALC_H_
#include "wifi_alc.h"
#endif

#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif
//---------------------------------------------------------------------------
typedef enum
{
    DRAW_MASK_WIFI_ALC2400M_CCK_ALC     = 0x01,
    DRAW_MASK_WIFI_ALC2400M_CCK_POWER   = 0x02,
    DRAW_MASK_WIFI_ALC2400M_OFDM_OFFSET = 0x04,
    DRAW_MASK_WIFI_ALC2400M_OFDM_ALC    = 0x08,
    DRAW_MASK_WIFI_ALC2400M_OFDM_POWER  = 0x10,
    DRAW_MASK_WIFI_ALC2400M_SLOPE       = 0x20
} E_DRAW_MASK_WIFI_ALC2400M;

typedef enum
{
    CHECK_MASK_WIFI_ALC2400M_CCK_ALC    = 0x01,
    CHECK_MASK_WIFI_ALC2400M_CCK_POWER  = 0x02,
    CHECK_MASK_WIFI_ALC2400M_OFDM_ALC   = 0x04,
    CHECK_MASK_WIFI_ALC2400M_OFDM_POWER = 0x08,
    CHECK_MASK_WIFI_ALC2400M_SLOPE      = 0x10
} E_CHECK_MASK_WIFI_ALC2400M;

typedef enum
{
    WIFI_EE_ALC_TYPE_2_4_G_CCK = 0,
    WIFI_EE_ALC_TYPE_2_4_G_OFDM,
    WIFI_EE_ALC_TYPE_SLOPE
} E_WIFI_EE_ALC_TYPE_T;

//---------------------------------------------------------------------------
class TfrmWiFiALC2400M : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TEdit *m_edtTxAlcCCK00;
    TEdit *m_edtTxAlcCCK01;
    TEdit *m_edtTxAlcCCK02;
    TEdit *m_edtTxAlcCCK03;
    TEdit *m_edtTxAlcCCK04;
    TEdit *m_edtTxAlcCCK05;
    TEdit *m_edtTxAlcCCK06;
    TEdit *m_edtTxAlcCCK07;
    TEdit *m_edtTxAlcCCK08;
    TEdit *m_edtTxAlcCCK09;
    TEdit *m_edtTxAlcCCK10;
    TEdit *m_edtTxAlcCCK11;
    TEdit *m_edtTxAlcCCK12;
    TEdit *m_edtTxAlcCCK13;
    TPanel *Panel5;
    TPanel *Panel6;
    TLabel *Label29;
    TEdit *m_edtTxOutputPowerDbCCK00;
    TEdit *m_edtTxOutputPowerDbCCK01;
    TEdit *m_edtTxOutputPowerDbCCK02;
    TEdit *m_edtTxOutputPowerDbCCK03;
    TEdit *m_edtTxOutputPowerDbCCK04;
    TEdit *m_edtTxOutputPowerDbCCK05;
    TEdit *m_edtTxOutputPowerDbCCK06;
    TEdit *m_edtTxOutputPowerDbCCK07;
    TEdit *m_edtTxOutputPowerDbCCK08;
    TEdit *m_edtTxOutputPowerDbCCK09;
    TEdit *m_edtTxOutputPowerDbCCK10;
    TEdit *m_edtTxOutputPowerDbCCK11;
    TEdit *m_edtTxOutputPowerDbCCK12;
    TEdit *m_edtTxOutputPowerDbCCK13;
    TLabel *Label30;
    TButton *m_btnOFDMTxRate0;
    TLabel *Label15;
    TButton *m_btnOFDMTxRate1;
    TButton *m_btnOFDMTxRate2;
    TButton *m_btnOFDMTxRate3;
    TButton *m_btnOFDMTxRate4;
    TButton *m_btnOFDMTxRate5;
    TButton *m_btnOFDMTxRate6;
    TButton *m_btnOFDMTxRate7;
    TEdit *m_edtOFDMTxAlcOffset0;
    TEdit *m_edtOFDMTxAlcOffset1;
    TEdit *m_edtOFDMTxAlcOffset2;
    TEdit *m_edtOFDMTxAlcOffset3;
    TEdit *m_edtOFDMTxAlcOffset4;
    TEdit *m_edtOFDMTxAlcOffset5;
    TEdit *m_edtOFDMTxAlcOffset6;
    TEdit *m_edtOFDMTxAlcOffset7;
    TLabel *Label16;
    TPanel *Panel4;
    TPanel *m_pnlOFDMTxRate;
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
    TLabel *Label27;
    TLabel *Label28;
    TLabel *Label31;
    TLabel *Label32;
    TEdit *m_edtTxAlcOFDM00;
    TEdit *m_edtTxAlcOFDM01;
    TEdit *m_edtTxAlcOFDM02;
    TEdit *m_edtTxAlcOFDM03;
    TEdit *m_edtTxAlcOFDM06;
    TEdit *m_edtTxAlcOFDM07;
    TEdit *m_edtTxAlcOFDM09;
    TEdit *Edit8;
    TEdit *m_edtTxAlcOFDM04;
    TEdit *m_edtTxAlcOFDM05;
    TEdit *m_edtTxAlcOFDM08;
    TEdit *m_edtTxAlcOFDM10;
    TEdit *m_edtTxAlcOFDM11;
    TEdit *m_edtTxAlcOFDM12;
    TEdit *m_edtTxAlcOFDM13;
    TLabel *Label33;
    TEdit *m_edtTxOutputPowerDbOFDM01;
    TEdit *m_edtTxOutputPowerDbOFDM02;
    TEdit *m_edtTxOutputPowerDbOFDM03;
    TEdit *m_edtTxOutputPowerDbOFDM04;
    TEdit *m_edtTxOutputPowerDbOFDM05;
    TEdit *m_edtTxOutputPowerDbOFDM06;
    TEdit *m_edtTxOutputPowerDbOFDM07;
    TEdit *m_edtTxOutputPowerDbOFDM08;
    TEdit *m_edtTxOutputPowerDbOFDM09;
    TEdit *m_edtTxOutputPowerDbOFDM10;
    TEdit *m_edtTxOutputPowerDbOFDM11;
    TEdit *m_edtTxOutputPowerDbOFDM12;
    TEdit *m_edtTxOutputPowerDbOFDM13;
    TLabel *Label34;
    TButton *btnUploadFromFlash;
    TButton *btnDownloadToFlash;
    TButton *btnChangeDB;
    TButton *btnLoadFromFile;
    TButton *btnSaveToFile;
    TStatusBar *m_sbALC;
    TTimer *HintTimer;
    TStaticText *lblHint;
    TSaveDialog *SaveDialog;
    TOpenDialog *OpenDialog;
    TEdit *m_edtTxOutputPowerDbOFDM00;
    TButton *m_btnApply;
    TEdit *m_edtOFDMTxOutputPowerOffset0;
    TEdit *m_edtOFDMTxOutputPowerOffset1;
    TEdit *m_edtOFDMTxOutputPowerOffset2;
    TEdit *m_edtOFDMTxOutputPowerOffset3;
    TEdit *m_edtOFDMTxOutputPowerOffset4;
    TEdit *m_edtOFDMTxOutputPowerOffset5;
    TEdit *m_edtOFDMTxOutputPowerOffset6;
    TEdit *m_edtOFDMTxOutputPowerOffset7;
    TLabel *Label35;
    TPanel *Panel3;
    TPanel *Panel7;
    TLabel *Label36;
    TLabel *Label37;
    TLabel *Label39;
    TEdit *m_edtALCSlop1Divider;
    TEdit *m_edtALCSlop1Dividend;
    TEdit *m_edtALCSlop2Divider;
    TEdit *m_edtALCSlop2Dividend;
    TButton *m_btnLoadFromEEPROM;
    void __fastcall edtTxAlcCCKCheck(TObject *Sender);
    void __fastcall edtTxOutputPowerDbCCKCheck(TObject *Sender);
    void __fastcall btnOFDMTxRateClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall edtTxAlcOFDMCheck(TObject *Sender);
    void __fastcall edtTxOutputPowerDbOFDMCheck(TObject *Sender);
    void __fastcall btnUploadFromFlashClick(TObject *Sender);
    void __fastcall btnDownloadToFlashClick(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall m_btnApplyClick(TObject *Sender);
    void __fastcall edtOFDMTxAlcOffsetCheck(TObject *Sender);
    void __fastcall edtOFDMTxOutputPowerOffsetCheck(TObject *Sender);
    void __fastcall m_edtALCSlopDividerCheck(TObject *Sender);
    void __fastcall m_edtALCSlopDividendCheck(TObject *Sender);
    void __fastcall btnChangeDBClick(TObject *Sender);
    void __fastcall m_btnLoadFromEEPROMClick(TObject *Sender);
private:	// User declarations
    S_WIFI_EEPROM   m_sEE;
    CWIFIEE   m_WIFI_EE_Obj;
    WiFi_ALC_2400M_S  m_sWiFiAlcPower2400M;
    WiFi_TxALC_2400M_S m_sWiFiAlcSlope2400M;
    char m_cOFDMTxAlcOffset[WIFI_ALC_2400M_TX_RATE_NUM];
    char m_cOFDMTxOutputPowerOffset[WIFI_ALC_2400M_TX_RATE_NUM];
    CWIFIALC m_cWIFI_ALC_Obj;

    // UI
    TEdit *m_edtTxAlcCCK[WIFI_ALC_2400M_CH_NUM];
    TEdit *m_edtTxOutputPowerDbCCK[WIFI_ALC_2400M_CH_NUM];
    TButton *m_btnOFDMTxRate[WIFI_ALC_2400M_TX_RATE_NUM];
    TEdit *m_edtOFDMTxAlcOffset[WIFI_ALC_2400M_TX_RATE_NUM];
    TEdit *m_edtOFDMTxOutputPowerOffset[WIFI_ALC_2400M_TX_RATE_NUM];
    TEdit *m_edtTxAlcOFDM[WIFI_ALC_2400M_CH_NUM];
    TEdit *m_edtTxOutputPowerDbOFDM[WIFI_ALC_2400M_CH_NUM];

public:		// User declarations
    __fastcall TfrmWiFiALC2400M(TComponent* Owner);
    void  ReDrawFields(E_DRAW_MASK_WIFI_ALC2400M mask);
    bool  CheckFields(E_CHECK_MASK_WIFI_ALC2400M mask);
    void  CurrentPageReset(void);
    void  CurrentPageLock(void);
    void  ShowHintLabel(TControl *sender, char* hint);

    // NVRAM
    void UploadAlc2400MFromFlashDone(void);
    void DownloadAlc2400MToFlashDone(void);

    // EEPROM
    void Compose_EEPROM_Parameter(E_WIFI_EE_ALC_TYPE_T type);
    void WiFiAlcEEToNVRAMFormat(E_WIFI_EE_ALC_TYPE_T type);
    void CNF_ReadAlcCCKFromEE(void);
    void CNF_ReadAlcOFDMFromEE(void);
    void CNF_ReadAlcSlopeFromEE(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFiALC2400M *frmWiFiALC2400M;
//---------------------------------------------------------------------------
#endif
