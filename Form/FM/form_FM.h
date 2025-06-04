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
 *   form_FM.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  FM radio form header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_FM_H_
#define _FORM_FM_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>


#include <vector>

#ifndef  _FM_RADIO_H_
#include "fm_radio.h"
#endif

#include "fm_rds.h"

#ifndef  _FM_TX_H_
#include "fm_tx.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef CONTROLLOCKER_H_
#include "ControlLocker.h"
#endif

#include "mt6620_fm_meta_lib.h"

#include <math.h>

#define u_int8  unsigned char
#define u_int16  unsigned short
#define u_int32  unsigned int


#define FM_FREQUENCY_MAX_100KHZ   1080
#define FM_FREQUENCY_MIN_100KHZ   875
#define FM_FREQUENCY_MAX_50KHZ    10800
#define FM_FREQUENCY_MIN_50KHZ    8750


#define FM_FREQUENCY_TRACKBAR_MAX_100KHZ        1080
#define FM_FREQUENCY_TRACKBAR_MIN_100KHZ        760
#define FM_FREQUENCY_TRACKBAR_MAX_50KHZ         2160   //1080*2  convenient for frequency TTrackBar slide
#define FM_FREQUENCY_TRACKBAR_MIN_50KHZ         1520   //760*2
#define FM_FREQUENCY_TRACKBAR_POSITION_50KHZ    1750   //875*2
//---------------------------------------------------------------------------
typedef enum
{
    DRAW_FM_STATION = 0x01,
    DRAW_FM_REGISTER = 0x02,
    DRAW_FM_STATUS = 0x04,
    DRAW_FM_RDS_RDS = 0x08,
    DRAW_FM_RDS_BLOCK_COUNTER = 0x10,
    DRAW_FM_RDS_GROUP_COUNTER = 0x20,
//rongguo 2011-09-09
    DRAW_FM_STATUS_MT6620 = 0x40,
//    DRAW_FM_STATUS_MT6620 = 0x30,
} E_DRAW_FM_T;

typedef enum
{
    FM_RDS_GOOD_BLOCK_COUNTER = 0,
    FM_RDS_BAD_BLOCK_COUNTER,
    FM_RDS_GROUP_COUNTER,
    FM_RDS_BLER,
    FM_RDS_RDSLOG,
    FM_RDS_COUNTER_COUNT,
} E_FM_RDS_COUNTER_T;
// YH: need to change the order and consider the combination in old sw load
typedef enum
{
    FM_PARAMETER_DECODE_MODE = 0,
    FM_PARAMETER_STEREO_BLEND,
    FM_PARAMETER_DEEMPHASIS_LEVEL,
    FM_PARAMETER_HL_SIDE,
    FM_PARAMETER_HCC,
    FM_PARAMETER_DEMOD_BW,
    FM_PARAMETER_PAMD_THRESHOLD,
    FM_PARAMETER_DYNAMIC_LIMITER,
    FM_PARAMETER_RSSI_THRESHOLD,
    FM_PARAMETER_SOFTMUTE_RATE,
    FM_PARAMETER_SOFTMUTE_ENABLE, // new API
    FM_PARAMETER_SET_SOFTMUTE, // old API
    FM_PARAMETER_MONO_STEREO_BLEND,
    FM_PARAMETER_STEREO_BLEND_STAGE,
    FM_SETTING_PARAMETER_COUNT
} E_FM_SETTING_PARAMETER_T;
typedef enum
{
    // new in MT6616
    FM_STATUS_PARAMETER_BW = 0,
    FM_STATUS_PARAMETER_PAMD,
    FM_STATUS_PARAMETER_MR,
    // old
    FM_STATUS_PARAMETER_RSSI,
    FM_STATUS_PARAMETER_STEREO,
    FM_STATUS_PARAMETER_IF_COUNTER,
    FM_STATUS_PARAMETER_HL_SIDE,
    FM_STATUS_PARAMETER_COUNT
} E_FM_STATUS_PARAMETER_T;

//rongguo 2011-09-07
typedef enum
{
    FM_TX_MAIN_UICONTROL_POWERON = 0x01,
    FM_TX_MAIN_UICONTROL_POWEROFF = 0x02,
    FM_TX_MAIN_UICONTROL_RDSON = 0x04,
    FM_TX_MAIN_UICONTROL_RDSOFF = 0x08,
    FM_TX_MAIN_UICONTROL_FREQUENCY = 0x10,
    FM_TX_MAIN_UICONTROL_RESET = 0x20,
    FM_TX_MAIN_UICONTROL_OTHERS = 0x40,
} E_FM_TX_MAIN_UICONTROL_T;



typedef struct
{
    E_FM_SETTING_PARAMETER_T first;
    AnsiString second;
} parameter_pair;
typedef struct
{
    E_FM_STATUS_PARAMETER_T first;
    AnsiString second;
} status_pair;
//---------------------------------------------------------------------------
class TfrmFM : public TForm
{
__published:	// IDE-managed Components
    TStaticText *lblHint;
    TTimer *HintTimer;
    TPageControl *m_pgcFMRadio;
    TTabSheet *m_tsOldFMUI;
    TPanel *Panel9;
    TPanel *Panel8;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label15;
    TLabel *Label16;
    TButton *m_btnGet;
    TStaticText *m_stRssi;
    TStaticText *m_stIfCounter;
    TStaticText *m_stHLSide;
    TStaticText *m_stStereoMono;
    TPanel *Panel7;
    TPanel *Panel6;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label17;
    TEdit *m_edtAddr;
    TEdit *m_edtWord1;
    TButton *m_btnRead;
    TButton *m_btnWrite;
    TEdit *m_edtWord0;
    TPanel *Panel5;
    TPanel *Panel4;
    TLabel *Label6;
    TLabel *Label4;
    TCheckBox *m_cbSoftMute;
    TCheckBox *m_cbStereoBlend;
    TComboBox *m_cbStereoBlendLevel;
    TComboBox *m_cbMode;
    TButton *m_btnSetAudio;
    TPanel *Panel3;
    TPanel *Panel2;
    TPanel *Panel12;
    TButton *m_btnReset;
    TPanel *Panel11;
    TPanel *Panel10;
    TLabel *Label12;
    TLabel *Label1;
    TLabel *Label13;
    TLabel *Label14;
    TButton *m_btnSearchNextStation;
    TButton *m_btnSearchPreStation;
    TEdit *m_edtStation;
    TComboBox *m_cbRssiThreshold;
    TComboBox *m_cbIfCounterDelta;
    TPanel *Panel1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *m_edtFreq;
    TButton *m_btnSetFreq;
    TStatusBar *m_sbFM;
    TTabSheet *m_tsFMReceiver;
    TTabSheet *m_tsFMRDS;
    //TTabSheet *m_tsFMTransmitter;
    TStatusBar *m_sbFMReceiver;
    TStatusBar *m_sbFMRDS;
    //TStatusBar *m_sbFMTransmitter;
    TGroupBox *m_gbFMReceiver_RegisterRW;
    TEdit *m_edtFMRegister_Address;
    TEdit *m_edtFMReceiver_Word;
    TButton *m_btnFMRXRegisterWrite;
    TButton *m_btnFMRXRegisterRead;
    TLabel *m_lblFMReceiver_Address;
    TLabel *m_lblFMReceiver_Word;
    TTrackBar *m_tbFMReceiver_Frequency;
    TTrackBar *m_tbFMReceiver_Volume;
    TButton *m_btnFMRXPowerOn;
    TButton *m_btnFMRXPowerOff;
    TButton *m_btnFMRXSeekLeft;
    TButton *m_btnFMRXSeekRight;
    TGroupBox *m_gbFMReceiver_ChannelList;
    TGroupBox *m_gbFMReceiver_RDSData;
    TGroupBox *m_gbFMReceiver_Status;
    TGroupBox *m_gbFMReceiver_Settings;
    TGroupBox *m_gbFMRDS_RDS;
    TGroupBox *m_gbRDSData_BlockCounter_Accepted;
    TGroupBox *m_gbFMRDS_GroupCounter;
    TButton *m_btnFMRDS_RDSOn;
    TButton *m_btnFMRDS_RDSOff;
    TButton *m_btnFMRDS_BlockCounterReset;
    TButton *m_btnFMRDS_GroupCounterReset;
    TLabel *m_lblFMReceiver_Frequency_LowerLimit;
    TLabel *m_lblFMReceiver_Frequency_UpperLimit;
    TLabel *m_lblFMReceiver_Tune;
    TLabel *m_lblFMReceiver_Seek;
    TEdit *m_edtFMReceiver_CurrentFrequency;
    TLabel *m_lblFMReceiver_CurrentFrequency;
    TLabel *m_lblFMReceiver_Volume;
    TButton *m_btnFMRXRDSOn;
    TButton *m_btnFMRXRDSOff;
    TButton *m_btnFMRXAutoScan;
    TButton *m_btnFMRXStatusUpdate;
    TButton *m_btnFMRXSet;
    TComboBox *m_cbFMReceiver_ChannelList;
    TEdit *m_edtFMReceiver_ChannelSelect;
    TLabel *m_lblFMReceiver_ChannelNo;
    TButton *m_btnFMRXGoChannel;
    TLabel *m_lblFMReceiver_RDSData_;
    TLabel *m_lblFMReceiver_RDSData_RT;
    TStaticText *m_stFMReceiver_RDSData_PS;
    TStaticText *m_stFMReceiver_RDSData_RT;
    TStaticText *m_stFMReceiver_Status_RSSI;
    TStaticText *m_stFMReceiver_Status_BW;
    TStaticText *m_stFMReceiver_Status_PAMD;
    TStaticText *m_stFMReceiver_Status_MR;
    TStaticText *m_stFMReceiver_Status_Stereo_Mono;
    TLabel *m_lblFMReceiver_Status_RSSI;
    TLabel *m_lblFMReceiver_Status_BW;
    TLabel *m_lblFMReceiver_Status_PAMD;
    TLabel *m_lblFMReceiver_Status_MR;
    TLabel *m_lblFMReceiver_Status_Stereo_Mono;
    TComboBox *m_cbFMReceiver_Setting_DecodeMode;
    TComboBox *m_cbFMReceiver_Setting_De_emphasisLevel;
    TComboBox *m_cbFMReceiver_Setting_StereoBlend;
    TComboBox *m_cbFMReceiver_Setting_HLSide;
    TComboBox *m_cbFMReceiver_Setting_HCC;
    TComboBox *m_cbFMReceiver_Setting_DemodBandwidth;
    TComboBox *m_cbFMReceiver_Setting_DynamicLimiter;
    TEdit *m_edtFMReceiver_Setting_PAMDThreshold;
    TEdit *m_edtFMReceiver_Setting_RSSIThreshold;
    TEdit *m_edtFMReceiver_Setting_SoftMuteRate;
    TComboBox *m_cbFMReceiver_Setting_SoftMute;
    TLabel *m_lblFMReceiver_Setting_DecodeMode;
    TLabel *m_lblFMReceiver_Setting_StereoBlend;
    TLabel *m_lblFMReceiver_Setting_HCC;
    TLabel *m_lblFMReceiver_Setting_PAMDThreshold;
    TLabel *m_lblFMReceiver_Setting_RSSIThreshold;
    TLabel *m_lblFMReceiver_Setting_SoftMute;
    TLabel *m_lblFMReceiver_Setting_HLSide;
    TLabel *m_lblFMReceiver_Setting_De_emphasisLevel;
    TLabel *m_lblFMReceiver_Setting_SoftMuteRate;
    TLabel *m_lblFMReceiver_Setting_DynamicLimiter;
    TLabel *m_lblFMReceiver_Setting_DemodBandwidth;
    TStaticText *m_stRDSData_RDS_PS;
    TStaticText *m_stRDSData_RDS_PTY;
    TStaticText *m_stRDSData_RDS_PI;
    TStaticText *m_stRDSData_RDS_RT;
    TStaticText *m_stRDSData_RDS_CT;
    TStaticText *m_stRDSData_RDS_RDSSYNC;
    TStaticText *m_stRDSData_RDS_RTDISPLAY;
    TStaticText *m_stRDSData_RDS_PSDISPLAY;
    TStaticText *stFMTxVaractorValue;
    TLabel *m_lblRDSData_RDS_PS;
    TLabel *m_lblRDSData_RDS_RT;
    TLabel *m_lblRDSData_RDS_CT;
    TLabel *m_lblRDSData_RDS_PTY;
    TLabel *m_lblRDSData_RDS_PI;
    TLabel *m_lblRDSData_RDS_RDSSYNC;
    TLabel *m_lblRDSData_RDS_RTDISPLAY;
    TLabel *m_lblRDSData_RDS_PSDISPLAY;
    TStaticText *m_stRDSData_BlockCounter_TotalRecv;
    TStaticText *m_stRDSData_BlockCounter_Errors;
    TStaticText *m_stRDSData_BlockCounter_Accepted;
    TLabel *m_lblRDSData_BlockCounter_TotalRecv;
    TLabel *m_lblRDSData_BlockCounter_Errors;
    TLabel *m_lblRDSData_BlockCounter_Accepted;
    TLabel *m_lblRDSData_GroupCounter_0A;
    TLabel *m_lblRDSData_GroupCounter_0B;
    TLabel *m_lblRDSData_GroupCounter_1A;
    TLabel *m_lblRDSData_GroupCounter_1B;
    TLabel *m_lblRDSData_GroupCounter_2A;
    TLabel *m_lblRDSData_GroupCounter_2B;
    TLabel *m_lblRDSData_GroupCounter_3A;
    TLabel *m_lblRDSData_GroupCounter_3B;
    TLabel *m_lblRDSData_GroupCounter_4A;
    TLabel *m_lblRDSData_GroupCounter_4B;
    TLabel *m_lblRDSData_GroupCounter_5A;
    TLabel *m_lblRDSData_GroupCounter_5B;
    TLabel *m_lblRDSData_GroupCounter_6A;
    TLabel *m_lblRDSData_GroupCounter_6B;
    TLabel *m_lblRDSData_GroupCounter_7A;
    TLabel *m_lblRDSData_GroupCounter_7B;
    TLabel *m_lblRDSData_GroupCounter_8A;
    TLabel *m_lblRDSData_GroupCounter_8B;
    TLabel *m_lblRDSData_GroupCounter_9A;
    TLabel *m_lblRDSData_GroupCounter_9B;
    TLabel *m_lblRDSData_GroupCounter_10A;
    TLabel *m_lblRDSData_GroupCounter_10B;
    TLabel *m_lblRDSData_GroupCounter_11A;
    TLabel *m_lblRDSData_GroupCounter_11B;
    TLabel *m_lblRDSData_GroupCounter_12A;
    TLabel *m_lblRDSData_GroupCounter_12B;
    TLabel *m_lblRDSData_GroupCounter_13A;
    TLabel *m_lblRDSData_GroupCounter_13B;
    TLabel *m_lblRDSData_GroupCounter_14A;
    TLabel *m_lblRDSData_GroupCounter_14B;
    TLabel *m_lblRDSData_GroupCounter_15A;
    TLabel *m_lblRDSData_GroupCounter_15B;
    TLabel *m_lblRDSData_GroupCounter_Total;
    TStaticText *m_stRDSData_GroupCounter_0A;
    TStaticText *m_stRDSData_GroupCounter_0B;
    TStaticText *m_stRDSData_GroupCounter_1A;
    TStaticText *m_stRDSData_GroupCounter_1B;
    TStaticText *m_stRDSData_GroupCounter_2A;
    TStaticText *m_stRDSData_GroupCounter_2B;
    TStaticText *m_stRDSData_GroupCounter_3A;
    TStaticText *m_stRDSData_GroupCounter_3B;
    TStaticText *m_stRDSData_GroupCounter_4A;
    TStaticText *m_stRDSData_GroupCounter_4B;
    TStaticText *m_stRDSData_GroupCounter_5A;
    TStaticText *m_stRDSData_GroupCounter_5B;
    TStaticText *m_stRDSData_GroupCounter_6A;
    TStaticText *m_stRDSData_GroupCounter_6B;
    TStaticText *m_stRDSData_GroupCounter_7A;
    TStaticText *m_stRDSData_GroupCounter_7B;
    TStaticText *m_stRDSData_GroupCounter_8A;
    TStaticText *m_stRDSData_GroupCounter_8B;
    TStaticText *m_stRDSData_GroupCounter_9A;
    TStaticText *m_stRDSData_GroupCounter_9B;
    TStaticText *m_stRDSData_GroupCounter_10A;
    TStaticText *m_stRDSData_GroupCounter_10B;
    TStaticText *m_stRDSData_GroupCounter_11A;
    TStaticText *m_stRDSData_GroupCounter_11B;
    TStaticText *m_stRDSData_GroupCounter_12A;
    TStaticText *m_stRDSData_GroupCounter_12B;
    TStaticText *m_stRDSData_GroupCounter_13A;
    TStaticText *m_stRDSData_GroupCounter_13B;
    TStaticText *m_stRDSData_GroupCounter_14A;
    TStaticText *m_stRDSData_GroupCounter_14B;
    TStaticText *m_stRDSData_GroupCounter_15A;
    TStaticText *m_stRDSData_GroupCounter_15B;
    TStaticText *m_stRDSData_GroupCounter_Total;
    TStaticText *m_stFMReceiver_Status_IFCounter;
    TLabel *m_lblFMReceiver_Status_IFCounter;
    TStaticText *stFMRSSIoffH;
    TLabel *m_lblFMReceiver_Status_HLSide;
    TButton *m_btnFMRXSetFrequency;
    TTimer *CounterTimer;
    TComboBox *m_cbFMReceiver_Setting_StereoBlendLevel;
    TLabel *m_lblFMReceiver_Setting_StereoBlendLevel;
    TButton *m_btnFMRXSetVolume;
    TLabel *m_lblRDSData_RDS_TP;
    TStaticText *m_stRDSData_RDS_TP;
    TLabel *m_lblRDSData_BlockCounter_Ratio;
    TStaticText *m_stRDSData_BlockCounter_BLER;
    TLabel *Label7;
    TEdit *m_edtRDSQueryTimer;
    TGroupBox *m_gbFMRDS_RDSLogData;
    TRichEdit *m_richedtRDSLog;
    TTabSheet *tsFMTx;
    TStatusBar *m_sbFMTX;
    TButton *btnFMTxPowerOnOff;
    TEdit *edtFMTxRFFreq;
    TUpDown *udFMTxRFFreq;
    TEdit *edtFMTxRFlevel;
    TUpDown *udFMTxRFlevel;
    TEdit *edtFMTxAudioDeviation;
    TUpDown *udFMTxAudioDeviation;
    TEdit *edtFMTxPilotDeviation;
    TUpDown *udFMTxPilotDeviation;
    TEdit *edtFMTxRDSDeviation;
    TUpDown *udFMTxRDSDeviation;
    TEdit *edtFMTxPilotFreq;
    TUpDown *udFMTxPilotFreq;
    TLabel *Label18;
    TStaticText *stFMRSSIhex;
    TStaticText *stFMRSSIdbm;
    TStaticText *stFMPAMDhex;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TStaticText *stFMPAMDdb;
    TLabel *Label22;
    TStaticText *stFMRSSIH;
    TStaticText *stFMPAMDH;
    TStaticText *stFMRSSIoffB;
    TStaticText *stFMPAMDoffB;
    TStaticText *m_stFMReceiver_Status_HLSide;
    TStaticText *stFMPAMDoffH;
    TStaticText *stFMHCCFilter;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *Label25;
    TLabel *Label26;
    TLabel *Label27;
    TLabel *Label28;
    TStaticText *stFMSoftmuteStep;
    TLabel *Label29;
    TLabel *Label30;
    TLabel *Label31;
    TStaticText *stFMBlendGain;
    TStaticText *stFMBFN;
    TLabel *Label32;
    TLabel *Label33;
    TStaticText *stFMDynamicGain;
    TStaticText *stFMPLF;
    TLabel *Label34;
    TStaticText *stFMSSF;
    TLabel *Label35;
    TStaticText *StaticText18;
    TLabel *Label36;
    TLabel *Label37;
    TLabel *Label39;
    TLabel *Label40;
    TLabel *Label41;
    TLabel *Label43;
    TStaticText *stFMLNAGain2;
    TStaticText *stFMLNAGainIdx2;
    TStaticText *stFMPGAGain2;
    TStaticText *stFMPGAGainIdx2;
    TStaticText *stFMGainCounter2;
    TStaticText *stFMRfTotalGain2;
    TLabel *Label42;
    TStaticText *stFMChipID;
    TLabel *Label44;
    TStaticText *stFMPulseRatio;
    TLabel *Label45;
    TStaticText *stFMFastPAMD;
    TLabel *Label46;
    TStaticText *stFMPowerDetector;
    TLabel *Label47;
    TEdit *edtFMCapArray;
    TLabel *Label48;
    TComboBox *cbFMDemodType;
    TLabel *Label60;
    TLabel *Label61;
    TComboBox *ComboBox2;
    TGroupBox *GroupBox2;
    TGroupBox *GroupBox3;
    TButton *m_btnSetAntennaType;
    TGroupBox *gbFMTxRFandModu;
    TGroupBox *gbFMTxAudioControl;
    TGroupBox *GroupBox43;
    TCheckBox *chkFMTxDRCOn;
    TButton *btnFMTxADRCSET;
    TComboBox *cbFMTxStereoMonoEnable;
    TComboBox *cbFMTxModulationOn;
    TTabSheet *tsRDSTx;
    TGroupBox *gbRDSTxGeneral;
    TLabel *Label238;
    TLabel *Label239;
    TLabel *Label253;
    TCheckBox *chkRDSTxDynamic;
    TEdit *edtRDSTxPI;
    TRadioGroup *rgpRDSTxType;
    TComboBox *cbRDSTxPTY;
    TGroupBox *gbRDSTxPS;
    TEdit *edtRDSTxPS;
    TCheckBox *chkRDSTxAF;
    TCheckBox *chkRDSTxAH;
    TCheckBox *chkRDSTxStereo;
    TCheckBox *chkRDSTxTP;
    TCheckBox *chkRDSTxTA;
    TCheckBox *chkRDSTxSpeech;
    TCheckBox *chkRDSTxAudioCompress;
    TEdit *edtRDSTxAF;
    TUpDown *udRDSTxAF;
    TButton *btnRDSTxSend;
    TComboBox *cbFMTxPreEmphasis;
    TLabel *Label38;
    TLabel *Label62;
    TStaticText *stFMSoftmuteGms;
    TStaticText *stFMSoftmuteGfs;
    TRadioButton *rbEarPhone;
    TRadioButton *rbShortAnt;
    TButton *readVaractor;
    TComboBox *cbFMTxPilotOn;
    TComboBox *cbFMTxRDSOn;
    TStaticText *stFMTxTotalDeviation;
    TLabel *lbTime;
    TTimer *tmScan;
    TCheckBox *chkFMTxEL;
    TGroupBox *GroupBox34;
    TButton *btnFMTxLimiter;
    TLabel *Label49;
    TGroupBox *GroupBox4;
    TComboBox *cboFrequency;
    TButton *btnFMSetType;
    TRadioButton *cbI2S;
    TRadioButton *cbAnalog;
    TStaticText *stCapArray;
    TLabel *Label50;
    TStatusBar *m_sbRDSTX;
    TActionList *ActionList1;
    TAction *ToggleHide;
    TButton *m_btnFMRXTune_Increase;
    TButton *m_btnFMRXTune_Decrease;
    TLabel *Label5;
    TComboBox *m_cbxAFList;
    TLabel *m_lblRDSData_RDS_TA;
    TStaticText *m_stRDSData_RDS_TA;
    TLabel *Label52;
    TLabel *Label53;
    TLabel *Label54;
    TLabel *Label51;
    TGroupBox *gbAudioTest;
    TButton *btnAudioTest;
    TStaticText *stAudioTest;
    TLabel *Label55;
    TStaticText *stCapRegValue;



    void __fastcall FormActivate(TObject *Sender);
    void __fastcall edtFreqCheck(TObject *Sender);
    void __fastcall m_btnSetFreqClick(TObject *Sender);
    void __fastcall edtRssiThresholdCheck(TObject *Sender);
    void __fastcall edtIFCounterDeltaCheck(TObject *Sender);
    void __fastcall m_btnSearchNextStationClick(TObject *Sender);
    void __fastcall m_btnSearchPreStationClick(TObject *Sender);
    void __fastcall m_btnSetAudioClick(TObject *Sender);
    void __fastcall m_btnReadClick(TObject *Sender);
    void __fastcall m_btnWriteClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall m_btnGetClick(TObject *Sender);
    void __fastcall m_btnResetClick(TObject *Sender);
    void __fastcall m_cbModeChange(TObject *Sender);
    void __fastcall m_tbFMReceiver_FrequencyChange(TObject *Sender);
    void __fastcall m_btnFMRDS_BlockCounterResetClick(TObject *Sender);
    void __fastcall m_btnFMRDS_GroupCounterResetClick(TObject *Sender);
    void __fastcall m_btnFMRDS_RDSOffClick(TObject *Sender);
    void __fastcall m_btnFMRDS_RDSOnClick(TObject *Sender);
    void __fastcall m_btnFMRXAutoScanClick(TObject *Sender);
    void __fastcall m_btnFMRXStatusUpdateClick(TObject *Sender);
    void __fastcall m_btnFMRXRegisterReadClick(TObject *Sender);
    void __fastcall m_btnFMRXRegisterWriteClick(
        TObject *Sender);
    void __fastcall btnFMRXPowerOnClick(TObject *Sender);
    void __fastcall btnFMRXPowerOffClick(TObject *Sender);
    void __fastcall m_btnFMRXSeekLeftClick(TObject *Sender);
    void __fastcall m_btnFMRXSeekRightClick(TObject *Sender);
    void __fastcall m_btnFMRXSetFrequencyClick(TObject *Sender);
    void __fastcall m_btnFMRXSetClick(TObject *Sender);
    void __fastcall CounterTimerTimer(TObject *Sender);
    void __fastcall m_cbFMReceiver_ChannelListChange(TObject *Sender);
    void __fastcall m_edtFMReceiver_ChannelSelectExit(TObject *Sender);
    void __fastcall m_btnFMRXSetVolumeClick(TObject *Sender);
    void __fastcall m_btnFMRXGoChannelClick(TObject *Sender);
    void __fastcall m_tbFMReceiver_FrequencyKeyDown(TObject *Sender,
            WORD &Key, TShiftState Shift);
    void __fastcall m_edtFMRegister_AddressExit(TObject *Sender);
    void __fastcall m_edtFMReceiver_WordExit(TObject *Sender);
    void __fastcall m_tbFMReceiver_VolumeKeyDown(TObject *Sender,
            WORD &Key, TShiftState Shift);
    void __fastcall m_edtFMReceiver_CurrentFrequencyKeyDown(
        TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall m_edtRDSQueryTimerExit(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall ToggleHideExecute(TObject *Sender);
    void __fastcall btnFMTxPowerOnOffClick(TObject *Sender);
    void __fastcall edtFMTxRFFreqKeyPress(TObject *Sender, char &Key);
    void __fastcall udFMTxRFFreqChanging(TObject *Sender,
                                         bool &AllowChange);
    void __fastcall udFMTxRFlevelChanging(TObject *Sender,
                                          bool &AllowChange);
    void __fastcall edtFMTxRFlevelKeyPress(TObject *Sender, char &Key);
    void __fastcall edtFMTxAudioDeviationKeyPress(TObject *Sender,
            char &Key);
    void __fastcall udFMTxAudioDeviationChanging(TObject *Sender,
            bool &AllowChange);
    void __fastcall udFMTxPilotDeviationChanging(TObject *Sender,
            bool &AllowChange);
    void __fastcall udFMTxRDSDeviationChanging(TObject *Sender,
            bool &AllowChange);
    void __fastcall udFMTxPilotFreqChanging(TObject *Sender,
                                            bool &AllowChange);
    void __fastcall edtFMTxPilotDeviationKeyPress(TObject *Sender,
            char &Key);
    void __fastcall edtFMTxRDSDeviationKeyPress(TObject *Sender,
            char &Key);
    void __fastcall cbFMTxStereoMonoEnableKeyPress(TObject *Sender,
            char &Key);
    void __fastcall cbFMTxModulationOnKeyPress(TObject *Sender,
            char &Key);
    void __fastcall cbFMTxPreEmphasisKeyPress(TObject *Sender,
            char &Key);
    void __fastcall btnFMTxADRCSETClick(TObject *Sender);

    void __fastcall btnFM(TObject *Sender);
    void __fastcall edtFMTxPilotFreqKeyPress(TObject *Sender,
            char &Key);
    void __fastcall rgpRDSTxTypeClick(TObject *Sender);
    void __fastcall chkRDSTxAFClick(TObject *Sender);
    void __fastcall edtRDSTxAFKeyPress(TObject *Sender, char &Key);
    void __fastcall udRDSTxAFChanging(TObject *Sender,
                                      bool &AllowChange);
    void __fastcall btnRDSTxSendClick(TObject *Sender);
    void __fastcall m_btnSetAntennaTypeClick(TObject *Sender);
    void __fastcall readVaractorClick(TObject *Sender);
    void __fastcall cbFMTxPilotOnKeyPress(TObject *Sender, char &Key);
    void __fastcall cbFMTxRDSOnKeyPress(TObject *Sender, char &Key);
    void __fastcall btnFMSetTypeClick(TObject *Sender);
    void __fastcall edtFMTxRFFreqChange(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall edtFMTxExit(TObject *Sender);
    void __fastcall m_btnFMRXTune_IncreaseClick(TObject *Sender);
    void __fastcall m_btnFMRXTune_DecreaseClick(TObject *Sender);
    void __fastcall btnAudioTestClick(TObject *Sender);

private:	// User declarations
    CFMRADIO m_cFM_RADIO_Obj;
    CFMRDS m_cFM_RDS_Obj;
    CFMTX   m_cFM_TX_Obj;
    bool m_bInit;
    FM_VAILD_FREQ_CNF_T m_sValidFreq;
    unsigned char m_ucAddr;
    unsigned short m_usData;
    unsigned int m_u4Data;
    S_FM_STATUS_T m_sStatus;
    FM_RDS_Good_Block_Counter_CNF_T m_sRDSGoodBlockCounter;
    FM_RDS_Bad_Block_Counter_CNF_T m_sRDSBadBlockCounter;
//rongguo 2011-06-24
//        FM_RDS_Group_Counter_CNF_T m_sRDSGroupCounter;
    FM_RDS_GROUPCOUNTER_T m_sRDSGroupCounter;

    FM_RDS_Info_CNF_T m_sRDSInfo;
    FM_RDS_Status_CNF_T m_sRDSStatus;
    FM_AutoScan_CNF_T m_sAutoScan;
    FM_HWSeek_CNF_T m_sHWSeek;
//rongguo 2011-06-24
//        FM_RDS_Block_CNF_T m_sRDSLogData;
    FM_RDS_LOGDATA_T m_sRDSLogData;

    std::vector<parameter_pair> m_vParameter;
    std::vector<parameter_pair>::iterator m_iterParameter;
    std::vector<status_pair> m_vStatus;
    std::vector<status_pair>::iterator m_iterStatus;
    //E_FM_SETTING_PARAMETER_T m_ePar;
    //E_FM_STATUS_PARAMETER_T m_eSPar;
    E_FM_RDS_COUNTER_T m_eRdsCounter;
    FM_CHIP_ID_CNF_T m_sFMChipId;
    bool m_bAction;
    int version;
    unsigned short m_u2BLER;
    CMETAHANDLE m_META_HANDLE_Obj;

    void CNF_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb);
    void Output_FM_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb);

    FM_Status_CNF_T cnf;
    DWORD   dwStart;
    AnsiString left;
    AnsiString right;
    bool bFMRXPowerOn;
    bool bFMTXPowerOn;
    short m_RXCurrentFrequency;

    FM_STEP_MODE_CNF_T m_sFMStepMode;
    ControlLocker m_FMOldUILocker;
    ControlLocker m_FMReceiverLocker;
    ControlLocker m_FMRDSLocker;
    ControlLocker m_FMTxLocker;
    void ResetFMTxUI(bool bEnable);
    void DealCounterUpdate(void);
    bool m_bFMSupport;
    FM_CHIP_ID_CNF_T m_FMChipId;
    FM_STEP_MODE_CNF_T m_FMStepMode;
//
public:		// User declarations
    __fastcall TfrmFM(TComponent* Owner);
    void Init(void);
    void _fastcall SubClassWndProc( Messages::TMessage &Message);
    void QueryFMInfo(void);
    FM_CHIP_ID_CNF_T Get_FMChipID();
    FM_STEP_MODE_CNF_T Get_FMStepMode();
    // UI
    void ShowHintLabel(TControl *sender, char* hint);
    void ReDrawFields(E_DRAW_FM_T draw);
    void ReDrawRDSFields(RdsEvent e);

    // call back
    void CNF_FM_WriteAddr(META_RESULT state ,AnsiString text);
    void CNF_FM_TxRFlevel(void);
    void CNF_FM_TxPowerOn(void);
    void CNF_FM_TxPowerOff(void);
    void CNF_FM_PowerOn(void);
    void CNF_FM_PowerReset(void);
    void CNF_FM_PowerOff(void);
    void CNF_FM_SetFreq(void);
    void CNF_FM_SearchNextStation(void);
    void CNF_FM_SearchPreStation(void);
    void CNF_FM_SetAudio(void);
    void CNF_FM_ReadData(void);
    void CNF_FM_WriteData(void);
    void CNF_FM_GetStatus(void);
    // for MT6616 new API
    void CNF_FM_ResetBlockCounter(void);
    void CNF_FM_ResetGroupCounter(void);
    void CNF_FM_RDSOn(void);
    void CNF_FM_RDSOff(void);
    void CNF_FM_AutoScan(void);
    void CNF_FM_SeekStation(void);
    void CNF_FM_Set_Volume(void);
    void CNF_FM_AudioSource(META_RESULT state ,AnsiString text);

    // parameter settings
    void ParameterSetting(void);
    void ParameterSettingMT6620(AnsiString xmlFile);
    void ParameterSettingDone(void);
    // status update
    void StatusUpdate(void);
    void CNF_StatusUpdate(void);
    void CounterUpdate(void);
    void CNF_CounterUpdate(void);
    void ClearRDSUIData(void);
    void ApplyHideProperty(void);
    inline double HandleFloat(double dInput);


    void FMStatusUpdate(AnsiString xmlFileName);
    void CNF_StatusUpdateMT6620(void);
    void CNF_ParameterSettingMT6620(void);
    void ResetFMTransmitter();
    int ReadRegister(unsigned char addr,unsigned short page,int sb,int eb);
    void TxMainUIControl(E_FM_TX_MAIN_UICONTROL_T control);
    void DisconnectClean(int cleanFlag);
    void CleanFMStatus(void);
    void CNF_FM_AudioTest(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFM *frmFM;
//---------------------------------------------------------------------------
#endif
