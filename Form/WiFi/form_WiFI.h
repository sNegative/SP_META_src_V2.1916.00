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
 *   form_WiFi.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi form header
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

//---------------------------------------------------------------------------
#ifndef _FORM_WiFI_H_
#define _FORM_WiFI_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>

#ifndef  _WIFI_GNRL_H_
#include "wifi_gnrl.h"
#endif

#ifndef  _WIFI_CPTX_H_
#include "wifi_cptx.h"
#endif

#ifndef  _WIFI_CPRX_H_
#include "wifi_cprx.h"
#endif

#ifndef  _WIFI_TXOP_H_
#include "wifi_txop.h"
#endif

#ifndef  _WIFI_TXCS_H_
#include "wifi_txcs.h"
#endif

#ifndef  _WIFI_LF_H_
#include "wifi_lf.h"
#endif

#ifndef  _WIFI_TXDC_H_
#include "wifi_txdc.h"
#endif

#ifndef  _WIFI_PS_H_
#include "wifi_ps.h"
#endif

#ifndef  _WIFI_BB_H_
#include "wifi_bb.h"
#endif

#ifndef  _WIFI_MAC_H_
#include "wifi_mac.h"
#endif

#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif

#ifndef  _WIFI_APC_2400M_H_
#include "wifi_apc_2400m.h"
#endif

#ifndef  _WIFI_ALC_H_
#include "wifi_alc.h"
#endif

#ifndef  _WIFI_SC_H_
#include "wifi_sc.h"
#endif

#ifndef  _WIFI_STOP_H_
#include "wifi_stop.h"
#endif

//---------------------------------------------------------------------------
typedef enum
{
    ACCESS_SINGLE = 0,
    ACCESS_DUMP,
    ACCESS_TX_POWER,
    ACCESS_TX_DC_OFFSET
} E_ACCESS_TYPE;


typedef enum
{
    OP_READ = 0,
    OP_WRITE
} E_OPERATION_TYPE;



//---------------------------------------------------------------------------
class TfrmWiFi : public TForm
{
__published:	// IDE-managed Components
    TPageControl *pctlToolSel;
    TTabSheet *tsTX;
    TTabSheet *tsCPR;
    TGroupBox *gbCPTInput;
    TBitBtn *btnTXStart;
    TBitBtn *btnTXStop;
    TStatusBar *sbTX;
    TGroupBox *gbCPRInput;
    TLabel *lblCPRChannelID;
    TComboBox *cbCPRChannelID;
    TGroupBox *gbCPRRxPacketStatistics;
    TGroupBox *gbCPRRxCounter;
    TLabel *lblCPRED;
    TStaticText *stCPRED;
    TLabel *lblCPROSD;
    TStaticText *stCPROSD;
    TLabel *lblCPRSQ1;
    TStaticText *stCPRSQ1;
    TLabel *lblCPRSFD;
    TStaticText *stCPRSFD;
    TLabel *lblCPRCRC16;
    TStaticText *stCPRCRC16;
    TStatusBar *sbCPR;
    TButton *btnCPRReset;
    TBitBtn *btnCPRStop;
    TBitBtn *btnCPRStart;
    TTabSheet *tsPS;
    TGroupBox *gbPSInput;
    TTabSheet *tsBB;
    TStatusBar *sbPS;
    TStatusBar *sbBB;
    TTabSheet *tsMAC;
    TStatusBar *sbMAC;
    TStaticText *lbl;
    TTimer *HintTimer;
    TButton *btnTXUploadFromFlash;
    TButton *btnTXDownloadToFlash;
    TButton *btnTXLoadFromFile;
    TButton *btnTXSaveToFile;
    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    TTimer *TimerWiFi;
    TRichEdit *memBBResult;
    TTabSheet *tsEE;
    TStatusBar *sbEE;
    TButton *btnTXTxChannelPower;
    TRichEdit *memMACResult;
    TRichEdit *memEEResult;
    TLabel *Label1;
    TComboBox *cbPSPowerMode;
    TBitBtn *btnPSStart;
    TBitBtn *btnPSStop;
    TButton *btnCPRQueryRxCounter;
    TPanel *Panel1;
    TGroupBox *gbBBInput;
    TLabel *lblBBCRIndex;
    TLabel *lblBBCRData0X;
    TEdit *edtBBCRIndex;
    TEdit *edtBBCRData;
    TButton *btnBBRead;
    TButton *btnBBWrite;
    TButton *btnBBCRData;
    TButton *btnBBDumpBBReg;
    TPanel *Panel2;
    TGroupBox *gbMACInput;
    TLabel *lblMACMCRAddress;
    TLabel *lblMACMCRAddress0X;
    TLabel *lblMACMCRData0X;
    TEdit *edtMACMCRAddress;
    TEdit *edtMACMCRData;
    TButton *btnMACRead;
    TButton *btnMACWrite;
    TButton *btnMACMCRData;
    TButton *btnMACDumpAllMacReg;
    TPanel *Panel3;
    TGroupBox *GroupBox5;
    TLabel *lblEEIndex;
    TLabel *lblEEIndex0X;
    TLabel *lblEEData0X;
    TEdit *edtEEIndex;
    TButton *btnEEData;
    TEdit *edtEEData;
    TButton *btnEERead;
    TButton *btnEEWrite;
    TButton *btnEE;
    TPopupMenu *pmWiFi;
    TMenuItem *miCopy;
    TButton *btnBBStop;
    TButton *btnEEStop;
    TLabel *lblCPRRxAntenna;
    TComboBox *cbCPRRxAntenna;
    TGroupBox *gbTXType;
    TRadioButton *rbCPT;
    TRadioButton *rbTXOP;
    TRadioButton *rbTXCS;
    TRadioButton *rbTXLF;
    TPanel *Panel4;
    TLabel *lblCPRRxRate;
    TLabel *lblCPRSum;
    TLabel *lblCPRGood;
    TLabel *lblCPRBad;
    TLabel *lblCPRFerRate;
    TStaticText *stCPR1MSum;
    TStaticText *stCPR1MGood;
    TStaticText *stCPR1MBad;
    TStaticText *stCPR1MFer;
    TStaticText *stCPR2MSum;
    TStaticText *stCPR2MGood;
    TStaticText *stCPR2MBad;
    TStaticText *stCPR2MFer;
    TStaticText *stCPR5_5MSum;
    TStaticText *stCPR5_5MGood;
    TStaticText *stCPR5_5MBad;
    TStaticText *stCPR5_5MFer;
    TStaticText *stCPR11MSum;
    TStaticText *stCPR11MGood;
    TStaticText *stCPR11MBad;
    TStaticText *stCPR11MFer;
    TStaticText *stCPR6MSum;
    TStaticText *stCPR6MGood;
    TStaticText *stCPR6MBad;
    TStaticText *stCPR6MFer;
    TStaticText *stCPR9MSum;
    TStaticText *stCPR9MGood;
    TStaticText *stCPR9MBad;
    TStaticText *stCPR9MFer;
    TStaticText *stCPR12MSum;
    TStaticText *stCPR12MGood;
    TStaticText *stCPR12MBad;
    TStaticText *stCPR12MFer;
    TStaticText *stCPR18MSum;
    TStaticText *stCPR18MGood;
    TStaticText *stCPR18MBad;
    TStaticText *stCPR18MFer;
    TStaticText *stCPR24MSum;
    TStaticText *stCPR24MGood;
    TStaticText *stCPR24MBad;
    TStaticText *stCPR24MFer;
    TStaticText *stCPR36MSum;
    TStaticText *stCPR36MGood;
    TStaticText *stCPR36MBad;
    TStaticText *stCPR36MFer;
    TStaticText *stCPR48MSum;
    TStaticText *stCPR48MGood;
    TStaticText *stCPR48MBad;
    TStaticText *stCPR48MFer;
    TStaticText *stCPR54MSum;
    TStaticText *stCPR54MGood;
    TStaticText *stCPR54MBad;
    TStaticText *stCPR54MFer;
    TPanel *Panel5;
    TLabel *lblCPRTotal;
    TStaticText *stCPRTotal;
    TLabel *lblCPRSuccess;
    TStaticText *stCPRSuccess;
    TLabel *lblCPRFER;
    TStaticText *stCPRFER;
    TLabel *lblCPRCRCErr;
    TStaticText *stCPRCRCErr;
    TLabel *lblCPRint_rx_ok_num;
    TStaticText *stCPRint_rx_ok_num;
    TLabel *lblCPRint_crc_err_num;
    TStaticText *stCPRint_crc_err_num;
    TLabel *lblCPRpau_rx_ok_count;
    TStaticText *stCPRpau_rx_ok_count;
    TLabel *lblCPRpau_crc_err_count;
    TStaticText *stCPRpau_crc_err_count;
    TLabel *lblCPRpau_cca_count;
    TStaticText *stCPRpau_cca_count;
    TStaticText *stCPR1M;
    TStaticText *stCPR2M;
    TStaticText *stCPR5_5M;
    TStaticText *stCPR11M;
    TStaticText *stCPR6M;
    TStaticText *stCPR9M;
    TStaticText *stCPR12M;
    TStaticText *stCPR18M;
    TStaticText *stCPR24M;
    TStaticText *stCPR36M;
    TStaticText *stCPR48M;
    TStaticText *stCPR54M;
    TPanel *Panel6;
    TLabel *lblCPRMin;
    TLabel *lblCPRMax;
    TLabel *lblCPRMean;
    TLabel *lblCPRVariance;
    TStaticText *stCPRMin;
    TStaticText *stCPRMax;
    TStaticText *stCPRMean;
    TStaticText *stCPRVariance;
    TStaticText *stCPRRssi;
    TPanel *Panel7;
    TStaticText *stCPRPreamble;
    TLabel *lblCPRLong;
    TStaticText *stCPRLong;
    TLabel *lblCPRShort;
    TStaticText *stCPRShort;
    TPanel *pnlCPT;
    TLabel *lblTXPacketLength;
    TEdit *edtTXPacketLength;
    TLabel *lblTXPacketCount;
    TLabel *lblTXPacketInterval;
    TEdit *edtTXPacketInterval;
    TLabel *lblTXBitPattern;
    TComboBox *cbTXBitPattern;
    TLabel *lblTXPreamble;
    TComboBox *cbTXPreamble;
    TLabel *lblTXPacketSent;
    TStaticText *stTXPacketSent;
    TLabel *lblTXAckCount;
    TStaticText *stTXAckCount;
    TStaticText *StaticText1;
    TPanel *Panel8;
    TStaticText *StaticText2;
    TButton *btnTXCalTxDC;
    TEdit *edtTXIDC;
    TEdit *edtTXQDC;
    TPanel *Panel9;
    TLabel *lblTXChannelID;
    TComboBox *cbTXChannelID;
    TLabel *lblTXTxFilter;
    TComboBox *cbTXTxFilter;
    TLabel *lblTXTxRate;
    TComboBox *cbTXTxRate;
    TButton *btnTXTxPowerDac;
    TEdit *edtTXTxPowerDAC;
    TLabel *lblTXTxPowerDac0X;
    TStaticText *StaticText3;
    TPanel *Panel10;
    TLabel *lblTXFrameCtrl0x;
    TStaticText *StaticText4;
    TEdit *edtTXFramCtrl1;
    TEdit *edtTXFramCtrl0;
    TEdit *edtTXAddress13;
    TLabel *lblTXFrameCtrl;
    TEdit *edtTXAddress15;
    TEdit *edtTXAddress14;
    TEdit *edtTXAddress12;
    TEdit *edtTXAddress11;
    TEdit *edtTXAddress10;
    TLabel *lblTXAddress1;
    TEdit *edtTXAddress25;
    TEdit *edtTXAddress24;
    TEdit *edtTXAddress23;
    TEdit *edtTXAddress22;
    TEdit *edtTXAddress21;
    TEdit *edtTXAddress20;
    TLabel *lblTXAddress2;
    TLabel *lblTXAddress3;
    TEdit *edtTXAddress35;
    TEdit *edtTXAddress34;
    TEdit *edtTXAddress33;
    TEdit *edtTXAddress32;
    TEdit *edtTXAddress31;
    TEdit *edtTXAddress30;
    TLabel *lblTXSeqCtrl;
    TEdit *edtTXSeqCtrl1;
    TEdit *edtTXSeqCtrl0;
    TLabel *lblTXDuration;
    TEdit *edtTXDuration1;
    TEdit *edtTXDuration0;
    TLabel *lblTXIDC0x;
    TLabel *lblTXQDC0x;
    TButton *btnTXIDC;
    TButton *btnTXQDC;
    TButton *btnMACRegSetting;
    TButton *btnBBRegSetting;
    TTabSheet *tsSC;
    TGroupBox *GroupBox1;
    TBitBtn *btnSCScriptFile;
    TStaticText *stSCScriptFile;
    TBitBtn *btnSCStart;
    TBitBtn *btnSCStop;
    TMemo *memSCResult;
    TStatusBar *stSC;
    TOpenDialog *dlgOpenScriptFile;
    TStaticText *stCPRpau_rx_fifo_full_count;
    TLabel *lblCPRpau_rx_fifo_full_count;
    TEdit *edtTXPacketCount;
    TButton *btnTXChangeDB;
    TButton *btnEEPROMSetting;
    TLabel *Label2;
    TEdit *edtMACBeginMCRAddr;
    TLabel *Label3;
    TLabel *lblMACEndMCRAddr;
    TEdit *edtMACEndMCRAddr;
    TLabel *Label5;
    TLabel *Label4;
    TEdit *edtBBBeginCRIndex;
    TEdit *edtBBEndCRIndex;
    TLabel *Label7;
    TLabel *Label9;
    TEdit *edtEEBeginIndex;
    TLabel *Label10;
    TEdit *edtEEEndIndex;
    TLabel *Label11;
    TLabel *Label12;
    TStaticText *lblHint;
    TGroupBox *GroupBox3;
    TRadioButton *rbEEByte;
    TRadioButton *rbEEWord;
    TButton *btnLoadTxPowerFromEE;
    TActionList *actList;
    TAction *ToggleHide;
    TButton *m_btnTxAlc;
    TCheckBox *m_cbTXTargetGain;
    TCheckBox *m_cbTXAlcTracking;
    TCheckBox *m_cbTargetAlc;
    TLabel *m_lblAverageALC;
    TStaticText *m_stAverageALC;
    TStaticText *m_stTXCCKGainControl;
    TLabel *m_lblTXCCKGainControl;
    TStaticText *m_stTXOFDMGainControl;
    TLabel *m_lblTXOFDMGainControl;
    TEdit *m_edtTXTargetAlc;
    TLabel *m_lblTXTargetAlc;
    TGroupBox *GroupBox2;
    TRadioButton *rbMAC16bits;
    TRadioButton *rbMAC32bits;
    TButton *btnMACStop;
    void __fastcall btnTXStartClick(TObject *Sender);
    // void __fastcall pctlToolSelChange(TObject *Sender);
    void __fastcall edtCPTPacketCountCheck(TObject *Sender);
    void __fastcall edtCPTPacketLengthCheck(TObject *Sender);
    void __fastcall cbTXTxFilterChange(TObject *Sender);
    void __fastcall cbTXTxRateChange(TObject *Sender);
    void __fastcall edtCPTTxPowerDACCheck(TObject *Sender);
    void __fastcall cbCPTRxAntennaChange(TObject *Sender);
    void __fastcall cbTXChannelIDChange(TObject *Sender);
    void __fastcall btnTXStopClick(TObject *Sender);
    void __fastcall cbCPRChannelIDChange(TObject *Sender);
    void __fastcall cbCPRRxAntennaChange(TObject *Sender);
    void __fastcall btnCPRResetClick(TObject *Sender);
    void __fastcall btnCPRStartClick(TObject *Sender);
    void __fastcall btnCPRStopClick(TObject *Sender);
    void __fastcall cbTXOPChannelIDChange(TObject *Sender);
    void __fastcall cbTXOPTXFilterChange(TObject *Sender);
    void __fastcall cbTXOPTXRateChange(TObject *Sender);
    void __fastcall btnTXOPStopClick(TObject *Sender);
    void __fastcall cbTXCSChannelIDChange(TObject *Sender);
    void __fastcall cbTXCSTXFilterChange(TObject *Sender);
    void __fastcall btnTXCSStopClick(TObject *Sender);
    void __fastcall cbLFChannelIDChange(TObject *Sender);
    void __fastcall cbLFTXFilterChange(TObject *Sender);
    void __fastcall btnLFStopClick(TObject *Sender);
    void __fastcall btnPSStandbyClick(TObject *Sender);
    void __fastcall btnPSSleepClick(TObject *Sender);
    void __fastcall edtBBCRIndexCheck(TObject *Sender);
    void __fastcall edtBBCRDataCheck(TObject *Sender);
    void __fastcall btnBBReadClick(TObject *Sender);
    void __fastcall edtMACMCRAddressCheck(TObject *Sender);
    void __fastcall edtMACMCRDataCheck(TObject *Sender);
    void __fastcall btnMACReadClick(TObject *Sender);
    void __fastcall btnMACWriteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall pctlToolSelChange(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall edtCPTPacketIntervalCheck(TObject *Sender);
    void __fastcall btnTXUploadFromFlashClick(TObject *Sender);
    void __fastcall btnTXDownloadToFlashClick(TObject *Sender);
    void __fastcall btnTXChangeDBClick(TObject *Sender);
    void __fastcall btnTXLoadFromFileClick(TObject *Sender);
    void __fastcall btnTXSaveToFileClick(TObject *Sender);
    void __fastcall TimerWiFiTimer(TObject *Sender);
    void __fastcall btnBBWriteClick(TObject *Sender);
    void __fastcall btnBBDumpBBRegClick(TObject *Sender);
    void __fastcall btnBBCRDataClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnMACMCRDataClick(TObject *Sender);
    void __fastcall btnEEDataClick(TObject *Sender);
    void __fastcall btnEEReadClick(TObject *Sender);
    void __fastcall btnEEWriteClick(TObject *Sender);
    void __fastcall edtEEIndexCheck(TObject *Sender);
    void __fastcall edtEEDataCheck(TObject *Sender);
    void __fastcall btnTXTxChannelPowerClick(TObject *Sender);
    void __fastcall btnTXOPUploadFromFlashClick(TObject *Sender);
    void __fastcall btnTXOPDownloadToFlashClick(TObject *Sender);
    void __fastcall btnTXOPChangeDBClick(TObject *Sender);
    void __fastcall btnTXOPLoadFromFileClick(TObject *Sender);
    void __fastcall btnTXOPSaveToFileClick(TObject *Sender);
    void __fastcall rbTXOPMaxClick(TObject *Sender);
    void __fastcall rbTXOP0dBmClick(TObject *Sender);
    void __fastcall rbTXOP5dBmClick(TObject *Sender);
    void __fastcall rbTXOP10dBmClick(TObject *Sender);
    void __fastcall btnMACDumpAllMacRegClick(TObject *Sender);
    void __fastcall btnEEClick(TObject *Sender);
    void __fastcall btnPSStartClick(TObject *Sender);
    void __fastcall btnPSStopClick(TObject *Sender);
    void __fastcall btnCPRQueryRxCounterClick(TObject *Sender);
    void __fastcall btnTXTxPowerDacClick(TObject *Sender);
    void __fastcall btnTXOPTxPowerDacClick(TObject *Sender);
    void __fastcall btnTXCSTxPowerDacClick(TObject *Sender);
    void __fastcall btnLFTxPowerDacClick(TObject *Sender);
    void __fastcall edtTXOPTxPowerDACCheck(TObject *Sender);
    void __fastcall edtTXCSTxPowerDACCheck(TObject *Sender);
    void __fastcall edtLFTxPowerDACCheck(TObject *Sender);
    void __fastcall miCopyClick(TObject *Sender);
    void __fastcall btnBBStopClick(TObject *Sender);
    void __fastcall btnMACStopClick(TObject *Sender);
    void __fastcall btnEEStopClick(TObject *Sender);
    void __fastcall rbTXOPClick(TObject *Sender);
    void __fastcall rbTXCSClick(TObject *Sender);
    void __fastcall rbTXLFClick(TObject *Sender);
    void __fastcall rbCPTClick(TObject *Sender);
    void __fastcall btnTXCalTxDCClick(TObject *Sender);
    void __fastcall edtTXFramCtrlCheck(TObject *Sender);
    void __fastcall edtTXAddress1Check(TObject *Sender);
    void __fastcall edtTXAddress2Check(TObject *Sender);
    void __fastcall edtTXAddress3Check(TObject *Sender);
    void __fastcall edtTXSeqCtrlCheck(TObject *Sender);
    void __fastcall edtTXIDcOffsetCheck(TObject *Sender);
    void __fastcall edtTXQDCOffsetCheck(TObject *Sender);
    void __fastcall edtTXDurationCheck(TObject *Sender);
    void __fastcall btnTXIDCClick(TObject *Sender);
    void __fastcall btnTXQDCClick(TObject *Sender);
    void __fastcall btnTXDCUploadFromFlashClick(TObject *Sender);
    void __fastcall btnTXDCDownloadToFlashClick(TObject *Sender);
    void __fastcall btnBBRegSettingClick(TObject *Sender);
    void __fastcall btnMACRegSettingClick(TObject *Sender);
    void __fastcall btnSCStartClick(TObject *Sender);
    void __fastcall btnSCScriptFileClick(TObject *Sender);
    void __fastcall btnSCStopClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall btnEEPROMSettingClick(TObject *Sender);
    void __fastcall edtBBBeginCRIndexCheck(TObject *Sender);
    void __fastcall edtBBEndCRIndexCheck(TObject *Sender);
    void __fastcall edtMACBeginMCRAddrCheck(TObject *Sender);
    void __fastcall edtMACEndMCRAddrCheck(TObject *Sender);
    void __fastcall edtBeginEEIndexCheck(TObject *Sender);
    void __fastcall edtEndEEIndexCheck(TObject *Sender);
    void __fastcall rbMAC32bitsClick(TObject *Sender);
    void __fastcall rbMAC16bitsClick(TObject *Sender);
    void __fastcall btnLoadTxPowerFromEEClick(TObject *Sender);
    void __fastcall btnTXLoadTxDcOffsetFromEEClick(TObject *Sender);
    void __fastcall rbEEByteClick(TObject *Sender);
    void __fastcall rbEEWordClick(TObject *Sender);
    void __fastcall ToggleHideExecute(TObject *Sender);
    void __fastcall m_btnTxAlcClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
    // common
    bool  m_bInit;
    int   m_final_WiFiId;
    WiFi_ChipCapability_S m_sWiFiCap;
    WiFi_ChannelList_S  m_sChannelList;
    int   m_iTestPageIndex;
    int   m_iLastPageIndex;


    // WiFi Object
    CWIFIGNRL  m_WIFI_GNRL_Obj;
    CWIFICPT   m_WIFI_CPT_Obj;
    CWIFIALC   m_cWIFI_ALC_Obj;
    CWIFICPRX  m_WIFI_CPRX_Obj;
    CWIFITXOP  m_WIFI_TXOP_Obj;
    CWIFITXCS  m_WIFI_TXCS_Obj;
    CWIFILF    m_WIFI_LF_Obj;
    CWIFITXDC  m_WIFI_TXDC_Obj;
    CWIFIPS    m_WIFI_PS_Obj;
    CWIFIBB    m_WIFI_BB_Obj;
    CWIFIMAC   m_WIFI_MAC_Obj;
    CWIFIEE   m_WIFI_EE_Obj;
    CWIFIAPC   m_WIFI_APC_Obj;
    CWIFISC    m_WIFI_SC_Obj;
    CWIFISTOP  m_WIFI_STOP_Obj;


    // first form show flag
    //bool       m_bInit;
    bool       m_bFirstCPTXShow;
    bool       m_bFirstCPRXShow;
    bool       m_bFirstTXOPShow;
    bool       m_bFirstTXCSShow;
    bool       m_bFirstLFShow;
    bool       m_bFirstCSShow;
    bool       m_bFirstBBShow;
    bool       m_bFirstMACShow;

    // CPTX
    S_WIFICPT  m_sWiFiCPT;
    WiFi_TxPower_2400M_S  m_sTxPwr2400M;
    WiFi_TxPower_5000M_S  m_sTxPwr5000M;
    WiFi_DAC_DC_Offset_S  m_sTxDcOffset;

    TEdit *edtTXFramCtrl[WIFI_MAC_HEAD_FRAME_CTRL_LEN];
    TEdit *edtTXDuration[WIFI_MAC_HEAD_DURATION_LEN];
    TEdit *edtTXAddress1[WIFI_MAC_HEAD_ADDRESS_LEN];
    TEdit *edtTXAddress2[WIFI_MAC_HEAD_ADDRESS_LEN];
    TEdit *edtTXAddress3[WIFI_MAC_HEAD_ADDRESS_LEN];
    TEdit *edtTXSeqCtrl[WIFI_MAC_HEAD_SEQ_CTRL_LEN];


    // CPRX
    WiFi_RxStatus_S  m_sOriRxStatus;
    TStaticText *stCPRSum[WIFI_TEST_RATE_COUNT];
    TStaticText *stCPRGood[WIFI_TEST_RATE_COUNT];
    TStaticText *stCPRBad[WIFI_TEST_RATE_COUNT];
    TStaticText *stCPRFer[WIFI_TEST_RATE_COUNT];

    // TXOP
    //WiFi_RegDomain_S sRegDomain;

    // BB
    unsigned int    m_uiBBCount;
    unsigned int    m_uiBBIdx;
    unsigned char   m_ucBBValue;
    unsigned int    m_uiBBBeginIdx;
    unsigned int    m_uiBBEndIdx;
    S_WiFi_BBCR     m_sBBCR;
    vector<WiFi_BBReg8_S> *m_pvBBCRDisp;

    // MAC
    unsigned int    m_uiMACCount;
    unsigned int    m_uiMacAddr;
    unsigned int    m_uiMacBeginAddr;
    unsigned int    m_uiMacEndAddr;
    unsigned int    m_uiMacData;
    unsigned short  m_usMac16Data;
    S_WiFi_MCR      m_sMCR;
    S_WiFi_MCR16    m_sMCR16;
    vector<WiFi_MACReg16_S> *m_pvMCR16Disp;
    vector<WiFi_MACReg32_S> *m_pvMCRDisp;

    // eeprom
    unsigned int    m_uiEEPROMCount;
    unsigned int	m_uiEEPROMIdx;
    unsigned int	m_uiEEPROMBeginIdx;
    unsigned int	m_uiEEPROMEndIdx;
    unsigned short	m_usEEPROMData;
    S_WIFI_EEPROM   m_sEE;
    vector<WiFi_EEPROM_S> *m_pvEEDisp;
    //unsigned int    m_uiDispEEPROMCount;
    // script test
    TStringList *m_pSCLog;

    // ALC
    bool m_bAlcSupport;

public:		// User declarations
    __fastcall TfrmWiFi(TComponent* Owner);

    // common
    void Init( void );
    void ApplyHideProperty( void );
    void _fastcall SubClassWndProc( Messages::TMessage &Message);

    // format transform
    unsigned int  ChannelID_To_ChannelFreq( unsigned int channel_id );
    unsigned int  ChannelFreq_To_ChannelID( unsigned int channel_freq );

    // UI
    void  CPTExecute( void );
    void  TXOPExecute( void );
    void  TXCSExecute( void );
    void  LFExecute( void );
    void  ReDrawFields( int page_idx );
    void  ReDrawTXFields( void );
    void  ReDrawTXOPFields( void );
    void  ReDrawBBFields( void );
    void  ReDrawMACFields( void );
    void  ReDrawEEFields( void );
    bool  CheckFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type );
    bool  CheckTXOPFields( void );
    bool  CheckBBFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type );
    bool  CheckMACFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type );
    bool  CheckEEFields( E_ACCESS_TYPE access_type, E_OPERATION_TYPE op_type);
    void  ShowHintLabel( TControl *sender, char* hint );
    void  EnableCPTUIComponent( void );
    void  DisableCPTUIComponent( void );
    void  CurrentPageReset( void );
    void  CurrentPageLock( void );
    void  DisplayWiFiChannel( void );
    void  DisplayWiFiTxRate( void );
    void  Display_CPTXTxPower( void );
    void  Force_WiFi_Stop( void );
    void  FillBBResult( bool  is_title );
    void  FillMACResult( bool  is_title );
    void  FillEEResult( bool  is_title );
    void  REQ_TXOP_SetDbmToDac( int dbm );

    // TX
    void  WiFiTxPowerEEToNVRAM( void );
    void  WiFiTxDcOffsetEEToNVRAM( void );
    void  ConfirmCallback_ReadTxPowerFromEE( void );
    void  ConfirmCallback_ReadTxDcOffsetFromEE( void );

    // BBCR read/write
    void  Compose_BBCR_Parameter( E_ACCESS_TYPE type );
    void  Compose_BBCR_Data( E_ACCESS_TYPE type );
    void  DeCompose_BBCR_Data( E_ACCESS_TYPE type );
    void  AllocateBBCRVector( void );
    void  EraseBBCRVector( void );
    void  DeAllocateBBCRVector( void );

    // MCR read/write
    void  Compose_MCR_Parameter( E_ACCESS_TYPE type );
    void  Compose_MCR_Data( E_ACCESS_TYPE type );
    void  DeCompose_MCR_Data( E_ACCESS_TYPE type );
    void  Compose_MCR16_Parameter( E_ACCESS_TYPE type );
    void  Compose_MCR16_Data( E_ACCESS_TYPE type );
    void  DeCompose_MCR16_Data( E_ACCESS_TYPE type );
    void  AllocateMCRVector( void );
    void  EraseMCRVector( void );
    void  DeAllocateMCRVector( void );
    void  AllocateMCR16Vector( void );
    void  EraseMCR16Vector( void );
    void  DeAllocateMCR16Vector( void );

    // EEPROM read/write
    void Compose_EEPROM_Parameter( E_ACCESS_TYPE type );
    void Compose_EEPROM_Data( E_ACCESS_TYPE type );
    void DeCompose_EEPROM_Data( E_ACCESS_TYPE type );
    void DeAllocateEEPROMVector( void );
    void EraseEEPROMVector( void );
    void AllocateEEPROMVector( void );

    // script
    void  FillSCResult( void );

    // call back
    void  ConfirmCallback_QueryChannelList( void );
    void  ConfirmCallback_CPT( void );
    void  ConfirmCallback_QueryTxStatus( void );
    void  CPTX_UploadTxPower2400MFromFlashDone( void );
    void  CPTX_UploadTxPower5000MFromFlashDone( void );
    void  CPTX_DownloadTxPower2400MToFlashDone( void );
    void  CPTX_DownloadTxPower5000MToFlashDone( void );
    void  TXOP_UploadTxPower2400MFromFlashDone( void );
    void  TXOP_UploadTxPower5000MFromFlashDone( void );
    void  TXOP_DownloadTxPower2400MToFlashDone( void );
    void  TXOP_DownloadTxPower5000MToFlashDone( void );
    void  UploadTxDCFromFlashDone( void );
    void  DownloadTxDCToFlashDone( void );
    void  ConfirmCallback_TxDcOffsetCal( void );
    void  ConfirmCallback_CPRX( void );
    void  ConfirmCallback_QueryRxStatus( void );
    void  ConfirmCallback_QueryOriRxStatus( void );
    void  ConfirmCallback_QueryRxCounter( void );
    void  ConfirmCallback_TXOP( void );
    void  ConfirmCallback_TXCS( void );
    void  ConfirmCallback_LF( void );
    void  ConfirmCallback_PS(void);
    void  ConfirmCallback_ReadBBReg( void );
    void  ConfirmCallback_ReadAllBBReg( void );
    void  ConfirmCallback_WriteBBReg( void );
    void  ConfirmCallback_ReadMACReg( void );
    void  ConfirmCallback_ReadAllMACReg( void );
    void  ConfirmCallback_WriteMACReg( void );
    void  ConfirmCallback_ReadEE( void );
    void  ConfirmCallback_ReadAllEE( void );
    void  ConfirmCallback_WriteEE( void );
    void  ConfirmCallback_SC( void );
    void  CNF_TXOP_SetDbmToDac( void );
    void  CNF_TXOP_QueryDbmToDac( void );

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFi *frmWiFi;
//---------------------------------------------------------------------------
#endif
