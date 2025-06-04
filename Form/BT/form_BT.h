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
 *   form_BT.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  MediaTek BT form header
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
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

#ifndef _FORM_BT_H_
#define _FORM_BT_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>

// general
#ifndef  _T_CWT_H_
#include "t_cwt.h"
#endif

// man
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// UART
#ifndef  _UART_H_
#include "uart.h"
#endif

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_HCI_H_
#include "bt_hci.h"
#endif

#ifndef  _BT_RF_H_
#include "bt_rf.h"
#endif

#ifndef  _BT_BLE_H_
#include "bt_ble.h"
#endif

#ifndef  _BT_RXStandalone_H_
#include "btRXStandalone.h"
#endif

#ifndef  _BT_PKT_H_
#include "bt_pkt.h"
#endif

#ifndef  _BT_SCRIPT_H_
#include "bt_script.h"
#endif

#ifndef  _BT_CON_H_
#include "bt_con.h"
#endif

#ifndef  _BT_THROUGHPUT_H_
#include "bt_throughput.h"
#endif

#ifndef  _BT_STOP_H_
#include "bt_stop.h"
#endif

#ifndef _BT_MT_H_
#include "bt_mt.h"
#endif

// misc
#ifndef  _TIME_UTILS_H_
#include "time_utils.h"
#endif


#ifndef  _BT_MAN_H_
#include "bt_man.h"
#endif

//---------------------------------------------------------------------------
typedef enum
{
    DRAM_MASK_HCI_SEND=0x01,
    DRAM_MASK_HCI_RECEIVE=0x02
} E_DRAM_MASK_HCI;

typedef enum
{
    DRAM_MASK_RF_BD_ADDRESS=0x01,
    DRAM_MASK_RF_ACCESS_CODE=0x02,
    DRAM_MASK_RF_TX_OTHERS=0x04,
    DRAM_MASK_RF_RX=0x08
} E_DRAM_MASK_RF;

typedef enum
{
    CHECK_MASK_RF_TX=0,
    CHECK_MASK_RF_RX,
} E_CHECK_MASK_RF;


typedef enum
{
    DRAM_MASK_PKT_CONFIG=0x01,
    DRAM_MASK_PKT_MONITOR=0x02,
    DRAM_MASK_PKT_BD_ADDR=0x04
} E_DRAM_MASK_PKT;

typedef enum
{
    DRAM_MASK_CT_LOCAL_BDADDR    = 0x01,
    DRAM_MASK_CT_ACL_BDADDR      = 0x02,
    DRAM_MASK_CT_SCO_BDADDR      = 0x04,
    DRAM_MASK_CT_DISCOVERED_LIST = 0x08,
    DRAM_MASK_CT_CONNECT_LIST    = 0x10,
    DRAM_MASK_CT_BUTTON          = 0x20,
    DRAM_MASK_CT_ACL_STATUS      = 0x40,
    DRAM_MASK_CT_SCO_STATUS      = 0x80,
}
E_DRAM_MASK_CT;

typedef enum
{
    CHECK_MASK_PKT=0,
    CHECK_MASK_PKT_TCI,
    CHECK_MASK_PKT_MONITOR
} E_CHECK_MASK_PKT;

typedef enum
{
    PKT_STATE_RUNNING=0,
    PKT_STATE_IDLE
} E_PKT_STATE;



typedef struct
{
    E_PKT_STATE e_state[BT_PACKET_IDX_COUNT];
    bool b_finish[BT_PACKET_IDX_COUNT];
} S_PKT_STATUS;


typedef enum
{
    CHECK_MASK_TT_BD_ADDR=0,
    CHECK_MASK_TT_TX,
} E_CHECK_MASK_TT;

typedef enum
{
    DRAM_MASK_TT_ACL_STATUS = 0x01,
    DRAM_MASK_TT_BUTTON = 0x02,
} E_DRAM_MASK_TT;

typedef enum
{
    BT_STATE_OPEN=0,
    BT_STATE_CLOSE,
} E_BT_STATE;

//---------------------------------------------------------------------------
class TfrmBT : public TForm
{
__published:	// IDE-managed Components
    TPageControl *m_pctlToolSel;
    TTabSheet *tsHCI;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TGroupBox *GroupBox1;
    TStaticText *stHCIFile;
    TButton *btnHCIFile;
    TLabel *lblHCIGroup;
    TComboBox *cbHCIGroup;
    TLabel *lblHCICommand;
    TComboBox *cbHCICommand;
    TStringGrid *sgSendHCI;
    TRichEdit *memHCIResult;
    TSaveDialog *SaveDialog;
    TTimer *HintTimer;
    TOpenDialog *OpenDialog;
    TOpenDialog *dlgOpenHCIFile;
    TStatusBar *sbHCI;
    TStatusBar *sbRF;
    TStatusBar *sbPKT;
    TStringGrid *sgReceiveHCI;
    TLabel *Label1;
    TStaticText *stHCIOpcode;
    TLabel *Label2;
    TGroupBox *GroupBox2;
    TLabel *Label3;
    TComboBox *cbRFTxPattern;
    TPanel *Panel1;
    TRadioButton *rbRFTxSingleFreq;
    TRadioButton *rbRFTxFreqHop;
    TEdit *edtRFTxSignleFreq;
    TPanel *Panel2;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TComboBox *cbRFTxType;
    TEdit *edtRFTxDataLen;
    TEdit *edtRFTxPollPeriod;
    TPanel *Panel3;
    TLabel *Label9;
    TEdit *edtRFTxAccessCode7;
    TLabel *Label10;
    TPanel *Panel4;
    TCheckBox *cbRFTxPowerCtrl;
    TLabel *Label11;
    TEdit *edtRFTxLevel;
    TGroupBox *GroupBox4;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TCheckBox *cbPKTDM1;
    TEdit *edtPKTDM1DataLen;
    TEdit *edtPKTDM1PollPeriod;
    TEdit *edtPKTDM1PktCount;
    TCheckBox *cbPKTDH1;
    TEdit *edtPKTDH1DataLen;
    TEdit *edtPKTDH1PollPeriod;
    TEdit *edtPKTDM3PktCount;
    TCheckBox *cbPKTDM3;
    TEdit *edtPKTDM3DataLen;
    TEdit *edtPKTDM3PollPeriod;
    TEdit *edtPKTDH3PktCount;
    TCheckBox *cbPKTDH3;
    TEdit *edtPKTDH3DataLen;
    TEdit *edtPKTDH3PollPeriod;
    TEdit *edtPKTDM5PktCount;
    TCheckBox *cbPKTDM5;
    TEdit *edtPKTDM5DataLen;
    TEdit *edtPKTDM5PollPeriod;
    TEdit *edtPKTDH5PktCount;
    TCheckBox *cbPKTDH5;
    TEdit *edtPKTDH5DataLen;
    TEdit *edtPKTDH5PollPeriod;
    TCheckBox *cbPKTHV1;
    TCheckBox *cbPKTHV2;
    TCheckBox *cbPKTHV3;
    TCheckBox *cbPKTEV3;
    TCheckBox *cbPKTEV4;
    TCheckBox *cbPKTEV5;
    TEdit *edtPKTHV1PktCount;
    TEdit *edtPKTHV1PollPeriod;
    TEdit *edtPKTHV2PktCount;
    TEdit *edtPKTHV2PollPeriod;
    TEdit *edtPKTHV3PktCount;
    TEdit *edtPKTHV3PollPeriod;
    TEdit *edtPKTEV3PktCount;
    TEdit *edtPKTEV3PollPeriod;
    TEdit *edtPKTEV4PktCount;
    TEdit *edtPKTEV4PollPeriod;
    TEdit *edtPKTEV5PollPeriod;
    TEdit *edtPKTDH1PktCount;
    TEdit *edtPKTEV5PktCount;
    TGroupBox *GroupBox5;
    TLabel *Label18;
    TLabel *Label19;
    TEdit *edtPKTTesterDM1TXCount;
    TEdit *edtPKTTesterDM1RXCount;
    TEdit *edtPKTTesterDH1TXCount;
    TEdit *edtPKTTesterDH1RXCount;
    TEdit *edtPKTTesterDM3TXCount;
    TEdit *edtPKTTesterDM3RXCount;
    TEdit *edtPKTTesterDH3TXCount;
    TEdit *edtPKTTesterDH3RXCount;
    TEdit *edtPKTTesterDM5TXCount;
    TEdit *edtPKTTesterDM5RXCount;
    TEdit *edtPKTTesterDH5TXCount;
    TEdit *edtPKTTesterDH5RXCount;
    TEdit *edtPKTTesterHV1TXCount;
    TEdit *edtPKTTesterHV1RXCount;
    TEdit *edtPKTTesterHV2TXCount;
    TEdit *edtPKTTesterHV2RXCount;
    TEdit *edtPKTTesterHV3TXCount;
    TEdit *edtPKTTesterHV3RXCount;
    TEdit *edtPKTTesterEV3TXCount;
    TEdit *edtPKTTesterEV3RXCount;
    TEdit *edtPKTTesterEV4TXCount;
    TEdit *edtPKTTesterEV4RXCount;
    TEdit *edtPKTTesterEV5TXCount;
    TEdit *edtPKTTesterEV5RXCount;
    TEdit *edtRFTxAccessCode6;
    TEdit *edtRFTxAccessCode5;
    TEdit *edtRFTxAccessCode4;
    TEdit *edtRFTxAccessCode3;
    TEdit *edtRFTxAccessCode2;
    TEdit *edtRFTxAccessCode1;
    TEdit *edtRFTxAccessCode0;
    TStaticText *lblHint;
    TCheckBox *cbRFTxWhiten;
    TLabel *Label12;
    TStaticText *stPKTTesterBDAddr;
    TStaticText *stPKTDUTBDAddr;
    TLabel *Label21;
    TGroupBox *GroupBox6;
    TLabel *Label17;
    TLabel *Label22;
    TEdit *edtPKTDUTDM1TXCount;
    TEdit *edtPKTDUTDH1TXCount;
    TEdit *edtPKTDUTDM3TXCount;
    TEdit *edtPKTDUTDH3TXCount;
    TEdit *edtPKTDUTDM5TXCount;
    TEdit *edtPKTDUTDH5TXCount;
    TEdit *edtPKTDUTHV1TXCount;
    TEdit *edtPKTDUTHV2TXCount;
    TEdit *edtPKTDUTHV3TXCount;
    TEdit *edtPKTDUTEV3TXCount;
    TEdit *edtPKTDUTEV4TXCount;
    TEdit *edtPKTDUTEV5TXCount;
    TEdit *edtPKTDUTDM1RXCount;
    TEdit *edtPKTDUTDH1RXCount;
    TEdit *edtPKTDUTDM3RXCount;
    TEdit *edtPKTDUTDH3RXCount;
    TEdit *edtPKTDUTDH5RXCount;
    TEdit *edtPKTDUTHV1RXCount;
    TEdit *edtPKTDUTHV2RXCount;
    TEdit *edtPKTDUTHV3RXCount;
    TEdit *edtPKTDUTEV3RXCount;
    TEdit *edtPKTDUTEV4RXCount;
    TEdit *edtPKTDUTEV5RXCount;
    TEdit *edtPKTDUTDM5RXCount;
    TLabel *Label23;
    TComboBox *cbHCICategory;
    TGroupBox *GroupBox7;
    TRadioButton *rbHCICategory;
    TRadioButton *rbHCIGroup;
    TLabel *Label24;
    TLabel *Label25;
    TStaticText *stHCILastEvent;
    TRichEdit *memRFResult;
    TTimer *glbTimer;
    TGroupBox *GroupBox8;
    TLabel *Label26;
    TComboBox *cbPKTCOM;
    TComboBox *cbPKTBaudRate;
    TLabel *Label20;
    TShape *shpPKTConnect;
    TButton *btnPKTConnectDUT;
    TBitBtn *btnPKTStart;
    TBitBtn *btnPKTStop;
    TGroupBox *GroupBox9;
    TRadioButton *rbHCIDec;
    TRadioButton *rbHCIHex;
    TRichEdit *memPKTResult;
    TLabel *Label27;
    TLabel *Label28;
    TEdit *edtHCITimeout;
    TTimer *MonitorTimer;
    TLabel *Label29;
    TLabel *Label30;
    TTabSheet *tsSCT;
    TRichEdit *memSCTResult;
    TStatusBar *sbSCT;
    TOpenDialog *dlgOpenSCTFile;
    TStaticText *stSCTFile;
    TButton *btnSCTFile;
    TBitBtn *btnRFTxStart;
    TBitBtn *btnRFTxStop;
    TBitBtn *btnHCIStart;
    TBitBtn *btnHCIStop;
    TBitBtn *btnSCTStop;
    TBitBtn *btnSCTStart;
    TListBox *lbSCT;
    TButton *btnSCTClearLog;
    TTabSheet *tsTT;
    TButton *btnHCIClearLog;
    TButton *btnRFClearLog;
    TButton *btnPKTClearLog;
    TRichEdit *memTTResult;
    TStatusBar *sbTT;
    TButton *btnTHClearLog;
    TButton *btnRFEnterTestMode;
    TButton *btnRFQueryBdAddr;
    TButton *btnRFChangeLevel;
    TGroupBox *GroupBox3;
    TRadioButton *rbRFTx;
    TRadioButton *rbRFRx;
    TActionList *actList;
    TAction *ToggleHide;
    TTabSheet *tsCT;
    TRichEdit *memCTResult;
    TStatusBar *sbCT;
    TGroupBox *GroupBox14;
    TButton *btCTClearLog;
    TGroupBox *GroupBox15;
    TButton *btnCTLDIRead;
    TButton *btnCTLDIWrite;
    TLabel *Label47;
    TLabel *Label48;
    TEdit *edtCTLDINAP3;
    TEdit *edtCTLDINAP2;
    TEdit *edtCTLDINAP1;
    TEdit *edtCTLDINAP0;
    TEdit *edtCTLDIUAP1;
    TEdit *edtCTLDIUAP0;
    TLabel *Label49;
    TLabel *Label50;
    TEdit *edtCTLDILAP5;
    TEdit *edtCTLDILAP4;
    TEdit *edtCTLDILAP3;
    TEdit *edtCTLDILAP2;
    TEdit *edtCTLDILAP1;
    TEdit *edtCTLDILAP0;
    TGroupBox *GroupBox16;
    TLabel *Label51;
    TButton *btnCTEnterPIN;
    TEdit *edtCTPIN;
    TButton *btnCTConnectSCO;
    TLabel *Label52;
    TComboBox *cbCTSCOPktType;
    TGroupBox *GroupBox17;
    TLabel *Label53;
    TComboBox *cbCTScanType;
    TGroupBox *GroupBox18;
    TBitBtn *btnCTInquiryStart;
    TBitBtn *btnCTInquiryStop;
    TLabel *Label54;
    TEdit *edtCTInquiryTimeout;
    TLabel *Label55;
    TGroupBox *GroupBox19;
    TGroupBox *GroupBox20;
    TGroupBox *GroupBox21;
    TLabel *Label56;
    TLabel *Label57;
    TButton *btnCTConnectACL;
    TButton *btnCTDisconnectACL;
    TButton *btnCTChangeAclPktType;
    TListBox *lbCTDisDevices;
    TListBox *lbCTConDevices;
    TButton *btnCTResetLD;
    TStaticText *stCTACLStatus;
    TCheckBox *cbCTInterlacedInquiryScan;
    TCheckBox *cbInterlacedPageScan;
    TCheckBox *cbCTDM1;
    TCheckBox *cbCTDM3;
    TCheckBox *cbCTDH1;
    TCheckBox *cbCTDH3;
    TCheckBox *cbCTDH5;
    TCheckBox *cbCTDM5;
    TGroupBox *GroupBox22;
    TButton *btnCTAutoAccept;
    TButton *btnCTScan;
    TStaticText *stCTSCOStatus;
    TLabel *Label58;
    TLabel *Label59;
    TLabel *Label60;
    TLabel *Label63;
    TButton *btnCTDisconnectSCO;
    TStaticText *m_stCTACLBDAddr;
    TStaticText *m_stCTSCOBDAddr;
    TGroupBox *GroupBox10;
    TPanel *Panel5;
    TLabel *Label43;
    TStaticText *stTTACLStatus;
    TLabel *Label32;
    TLabel *Label31;
    TCheckBox *cbTTDM1;
    TCheckBox *cbTTDM3;
    TCheckBox *cbTTDM5;
    TCheckBox *cbTTDH1;
    TCheckBox *cbTTDH3;
    TCheckBox *cbTTDH5;
    TButton *btnTTConnect;
    TButton *btnTTChangeACLPacketType;
    TButton *btnTTDisconnect;
    TGroupBox *GroupBox11;
    TPanel *Panel9;
    TLabel *Label40;
    TStaticText *stTTRxBytes;
    TLabel *Label42;
    TStaticText *stTTRxThroughput;
    TLabel *Label7;
    TEdit *edtRFBDAddress;
    TLabel *Label8;
    TEdit *edtTTBDAddr;
    TBitBtn *btnTTRxStart;
    TBitBtn *btnTTRxStop;
    TGroupBox *GroupBox12;
    TLabel *Label35;
    TComboBox *m_cbTTScanType;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TButton *btnTTScan;
    TGroupBox *GroupBox13;
    TButton *btnTTAutoAccept;
    TGroupBox *GroupBox23;
    TPanel *Panel6;
    TLabel *Label38;
    TLabel *Label37;
    TBitBtn *btnTTTxStart;
    TBitBtn *btnTTTxStop;
    TEdit *edtTTPacketCount;
    TEdit *edtTTDataLen;
    TPanel *Panel7;
    TLabel *Label33;
    TLabel *Label34;
    TStaticText *stTTTxCount;
    TStaticText *stTTTxThroughput;
    TCheckBox *cbCT2DH1;
    TCheckBox *cbCT3DH1;
    TCheckBox *cbCT2DH3;
    TCheckBox *cbCT3DH3;
    TCheckBox *cbCT2DH5;
    TCheckBox *cbCT3DH5;
    TLabel *Label36;
    TEdit *edtCTTxBandwidth;
    TLabel *Label39;
    TLabel *Label41;
    TEdit *edtCTRxBandwidth;
    TLabel *Label44;
    TLabel *Label45;
    TEdit *edtCTMaxLatency;
    TLabel *Label46;
    TLabel *Label61;
    TEdit *edtCTRetransmitEffort;
    TLabel *Label62;
    TCheckBox *cbPK2DH1;
    TEdit *edtPKT2DH1PollPeriod;
    TEdit *edtPKT2EV3PollPeriod;
    TEdit *edtPKT2DH3PollPeriod;
    TEdit *edtPKT2EV5PollPeriod;
    TEdit *edtPKT2DH5PollPeriod;
    TEdit *edtPKT3EV3PollPeriod;
    TEdit *edtPKT3DH1PollPeriod;
    TEdit *edtPKT3DH3PollPeriod;
    TEdit *edtPKT3EV5PollPeriod;
    TEdit *edtPKT3DH5PollPeriod;
    TEdit *edtPKT2DH1PktCount;
    TEdit *edtPKT2EV3PktCount;
    TEdit *edtPKT2DH3PktCount;
    TEdit *edtPKT2EV5PktCount;
    TEdit *edtPKT2DH5PktCount;
    TEdit *edtPKT3EV3PktCount;
    TEdit *edtPKT3DH1PktCount;
    TEdit *edtPKT3DH3PktCount;
    TEdit *edtPKT3EV5PktCount;
    TEdit *edtPKT3DH5PktCount;
    TCheckBox *cbPK2EV3;
    TCheckBox *cbPK2DH3;
    TCheckBox *cbPK2EV5;
    TCheckBox *cbPK2DH5;
    TCheckBox *cbPK3EV3;
    TCheckBox *cbPK3DH1;
    TCheckBox *cbPK3DH3;
    TCheckBox *cbPK3EV5;
    TCheckBox *cbPK3DH5;
    TEdit *edtPKTTester2DH1TXCount;
    TEdit *edtPKTTester2EV3TXCount;
    TEdit *edtPKTTester2DH3TXCount;
    TEdit *edtPKTTester2EV5TXCount;
    TEdit *edtPKTTester2DH5TXCount;
    TEdit *edtPKTTester3EV3TXCount;
    TEdit *edtPKTTester3DH1TXCount;
    TEdit *edtPKTTester3DH3TXCount;
    TEdit *edtPKTTester3EV5TXCount;
    TEdit *edtPKTTester3DH5TXCount;
    TEdit *edtPKTTester2DH1RXCount;
    TEdit *edtPKTTester2EV3RXCount;
    TEdit *edtPKTTester2DH3RXCount;
    TEdit *edtPKTTester2EV5RXCount;
    TEdit *edtPKTTester2DH5RXCount;
    TEdit *edtPKTTester3EV3RXCount;
    TEdit *edtPKTTester3DH1RXCount;
    TEdit *edtPKTTester3DH3RXCount;
    TEdit *edtPKTTester3EV5RXCount;
    TEdit *edtPKTTester3DH5RXCount;
    TEdit *edtPKTDUT2DH1TXCount;
    TEdit *edtPKTDUT2EV3TXCount;
    TEdit *edtPKTDUT2DH3TXCount;
    TEdit *edtPKTDUT2EV5TXCount;
    TEdit *edtPKTDUT2DH5TXCount;
    TEdit *edtPKTDUT3EV3TXCount;
    TEdit *edtPKTDUT3DH1TXCount;
    TEdit *edtPKTDUT3DH3TXCount;
    TEdit *edtPKTDUT3EV5TXCount;
    TEdit *edtPKTDUT3DH5TXCount;
    TEdit *edtPKTDUT2DH1RXCount;
    TEdit *edtPKTDUT2EV3RXCount;
    TEdit *edtPKTDUT2DH3RXCount;
    TEdit *edtPKTDUT2EV5RXCount;
    TEdit *edtPKTDUT2DH5RXCount;
    TEdit *edtPKTDUT3EV3RXCount;
    TEdit *edtPKTDUT3DH1RXCount;
    TEdit *edtPKTDUT3DH3RXCount;
    TEdit *edtPKTDUT3EV5RXCount;
    TEdit *edtPKTDUT3DH5RXCount;
    TCheckBox *m_cbTT2DH1;
    TCheckBox *m_cbTT2DH3;
    TCheckBox *m_cbTT2DH5;
    TCheckBox *m_cbTT3DH1;
    TCheckBox *m_cbTT3DH3;
    TCheckBox *m_cbTT3DH5;
    TTabSheet *m_tsMT;
    TGroupBox *grpTestItemList;
    TStaticText *lblItem1;
    TStaticText *lblItem2;
    TStaticText *lblItem3;
    TStaticText *lblItem9;
    TStaticText *lblItem8;
    TStaticText *lblItem10;
    TStaticText *lblItem11;
    TStaticText *lblItem13;
    TStaticText *lblItem12;
    TStaticText *lblItem14;
    TStaticText *lblItem15;
    TStaticText *lblItem16;
    TStaticText *lblItem4;
    TStaticText *lblItem5;
    TStaticText *lblItem6;
    TStaticText *lblItem7;
    TScrollBar *scrTestItemList;
    TStaticText *lblItem17;
    TStaticText *lblItem18;
    TStaticText *lblItem19;
    TStaticText *lblItem20;
    TStaticText *lblItem21;
    TStaticText *lblItem22;
    TStatusBar *m_sbMT;
    TStaticText *m_lblMTStatus;
    TLabel *Label64;
    TEdit *m_edtMTRepeat;
    TGroupBox *GroupBox24;
    TRadioButton *m_rbMTTestItem0;
    TRadioButton *m_rbMTTestItem1;
    TRadioButton *m_rbMTTestItem2;
    TRadioButton *m_rbMTTestItem3;
    TRadioButton *m_rbMTTestItem4;
    TSpeedButton *m_btnMTRun;
    TRichEdit *m_edtMTLog;
    TTimer *m_tmMT;
    TGroupBox *GroupBox26;
    TShape *m_shpMTConnect;
    TLabel *Label66;
    TComboBox *m_cbMTBT2COM;
    TLabel *Label68;
    TComboBox *m_cbMTBT2Baud;
    TButton *m_btnMTConnect;
    TCheckBox *m_cbMETAMode;
    TButton *m_btnMTReload;
    TTabSheet *tsBLETest;
    TGroupBox *gbBLE;
    TGroupBox *gbTxorRx;
    TRadioButton *rbTxTest;
    TRadioButton *rbRxTest;
    TGroupBox *gbSingleorHopping;
    TRadioButton *rbSingleChannel;
    TRadioButton *rbHopping;
    TLabel *lbChannel;
    TEdit *etChannel;
    TLabel *lbPattern;
    TComboBox *cbPattern;
    TLabel *lbTxLevel;
    TComboBox *cbTxLevel;
    TCheckBox *cbContinuousTx;
    TLabel *lbPacketCount;
    TEdit *edPacketCount;
    TButton *btnStart;
    TGroupBox *GroupBox25;
    TEdit *Edit1;
    TButton *Button1;
    TRichEdit *reBLEResult;
    TButton *btClear;
    TStatusBar *sbBLE;
    TTabSheet *tsBLENormal;
    TPageControl *pcBleNormalMode;
    TTabSheet *tsAdvertise;
    TGroupBox *GroupBox27;
    TLabel *Label65;
    TLabel *Label67;
    TLabel *Label69;
    TLabel *Label70;
    TLabel *Label71;
    TLabel *Label72;
    TLabel *Label73;
    TLabel *Label74;
    TLabel *Label75;
    TEdit *edAdvertisingIntervalMin;
    TEdit *edAdvertisingIntervalMax;
    TComboBox *cbAdvertisingType;
    TCheckBox *cbChannel37;
    TCheckBox *cbChannel38;
    TCheckBox *cbChannel39;
    TComboBox *cbAdvertiseFilterPolicy;
    TComboBox *cbOwnAddressType;
    TComboBox *cbDirectAddressType;
    TEdit *edDirectAddress;
    TRichEdit *reBLEAdvertiseResult;
    TGroupBox *GroupBox28;
    TRichEdit *reAdvertiseData;
    TButton *btSetAdvertiseData;
    TButton *btAdvertiseStar;
    TGroupBox *GroupBox29;
    TEdit *edWhiteList;
    TComboBox *cbDeviceAddress;
    TButton *btAddDeviceToWhiteList;
    TButton *btRemoveDeviceToWhiteList;
    TButton *btBLEClearWhiteList;
    TButton *btAdvertiseClear;
    TTabSheet *tsScan;
    TGroupBox *GroupBox30;
    TLabel *Label76;
    TLabel *Label77;
    TLabel *Label78;
    TLabel *Label79;
    TLabel *Label80;
    TLabel *Label81;
    TLabel *Label82;
    TLabel *Label83;
    TComboBox *cbScanType;
    TEdit *edLEScanInterval;
    TEdit *edLEScanWindow;
    TComboBox *cbOwmAddressType;
    TComboBox *cbScanFilterPolicy;
    TComboBox *cbFilterDuplicate;
    TRichEdit *reBLEScanResult;
    TGroupBox *GroupBox31;
    TRichEdit *reScanResponseData;
    TButton *btSetScanResponseData;
    TButton *btScanStart;
    TButton *btHCIResetScan;
    TButton *btScanClear;
    TTabSheet *tsInitiate;
    TGroupBox *GroupBox32;
    TLabel *Label84;
    TLabel *Label85;
    TLabel *Label86;
    TLabel *Label87;
    TLabel *Label88;
    TLabel *Label89;
    TLabel *Label90;
    TLabel *Label91;
    TLabel *Label92;
    TLabel *Label93;
    TLabel *Label94;
    TLabel *Label95;
    TLabel *Label96;
    TLabel *Label97;
    TLabel *Label98;
    TLabel *Label99;
    TLabel *Label100;
    TLabel *Label101;
    TLabel *Label102;
    TEdit *edLEScanIntervalIn;
    TEdit *edLEScanWindowIn;
    TComboBox *cbInitiateFilterPolicy;
    TComboBox *cbPeerAddressType;
    TComboBox *cbOwnAddressTypeIn;
    TEdit *edPeerAddress;
    TEdit *edConnectionIntervalMax;
    TEdit *edConnectionLatency;
    TEdit *edSupervisionTimeout;
    TEdit *edMinimumCELength;
    TEdit *edMaximumCELength;
    TRichEdit *reBLEInitiateResult;
    TButton *btInitiateStart;
    TButton *btHCIResetInitiate;
    TButton *btInitiateClear;
    TButton *btHCIReset;
    TStatusBar *sbBLENormalMode;
    TEdit *edConnectionIntervalMin;
    TButton *btChangeMintoHex;
    TButton *btChangeMaxtoHex;
    TButton *btChangeLeScanInterval;
    TButton *btChangeLEScanWindow;
    TTabSheet *tsStandalone;
    TGroupBox *GroupBox34;
    TLabel *Label106;
    TLabel *Label107;
    TLabel *Label103;
    TLabel *Label104;
    TComboBox *cbRXPattern;
    TEdit *edRXFre;
    TEdit *edTesterAddress;
    TButton *btnEnterTest;
    TButton *btnExitTest;
    TGroupBox *GroupBox33;
    TLabel *Label105;
    TLabel *Label108;
    TLabel *Label109;
    TLabel *Label110;
    TEdit *edPXPacketCount;
    TEdit *edRXErroRate;
    TEdit *edRXByteCount;
    TEdit *edBitErrorRate;
    TRichEdit *reRXSTD;
    TButton *btnSTDClear;
    TComboBox *cbRXPacketTypeSub;
    TButton *btnLEScanInterval;
    TButton *btnLEScanWindow;
    TStatusBar *sbRXSTD;
    TEdit *edUserInput;
    TLabel *lbUserInput;
    TButton *btnResetTest;
    TCheckBox *cbRFTxAccessCode;
    TStaticText *StaticText1;
        TTabSheet *TabSheet1;
        TGroupBox *GroupBox35;
        TRadioButton *rbEnTxTest;
        TRadioButton *rbEnRxTest;
        TLabel *Label111;
        TLabel *Label112;
        TComboBox *cbEnPHY;
        TLabel *lbEnPayloadLength;
        TLabel *lbEnPattern;
        TComboBox *cbEnChannel;
        TComboBox *cbEnPattern;
        TButton *btnEnStart;
        TLabel *Label115;
        TEdit *edEnPacketCount;
        TRichEdit *reBLEEnhancedResult;
        TButton *Button3;
        TStatusBar *sbBLEEN;
        TEdit *edEnPayloadLength;
    void __fastcall btnHCIFileClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall cbHCIGroupChange(TObject *Sender);
    void __fastcall cbHCICommandChange(TObject *Sender);
    void __fastcall btnHCISendClick(TObject *Sender);
    void __fastcall edtRFTxSignleFreqCheck(TObject *Sender);
    void __fastcall edtRFTxDataLenCheck(TObject *Sender);
    void __fastcall edtRFTxPollPeriodCheck(TObject *Sender);
    void __fastcall edtRFTxLevelCheck(TObject *Sender);
    void __fastcall edtRFTxAccessCodeCheck(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall btnRFTxStartClick(TObject *Sender);
    // void __fastcall edtRFTxLapCheck(TObject *Sender);
    void __fastcall btnRFRxStartClick(TObject *Sender);
    void __fastcall rbHCICategoryClick(TObject *Sender);
    void __fastcall rbHCIGroupClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall glbTimerTimer(TObject *Sender);
    void __fastcall btnPKTConnectDUTClick(TObject *Sender);
    void __fastcall btnPKTStartClick(TObject *Sender);
    void __fastcall rbHCIDecClick(TObject *Sender);
    void __fastcall rbHCIHexClick(TObject *Sender);
    void __fastcall sgSendHCICheck(TObject *Sender);
    void __fastcall edtHCITimeoutCheck(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall cbRFTxTypeChange(TObject *Sender);
    void __fastcall edtRFRxSignleFreqCheck(TObject *Sender);
    void __fastcall MonitorTimerTimer(TObject *Sender);
    void __fastcall edtPKTDataLenCheck(TObject *Sender);
    void __fastcall edtPKTPollPeriodCheck(TObject *Sender);
    void __fastcall edtPKTCountCheck(TObject *Sender);
    void __fastcall btnSCTFileClick(TObject *Sender);
    void __fastcall btnSCTTestClick(TObject *Sender);
    void __fastcall btnPKTStopClick(TObject *Sender);
    void __fastcall btnRFTxStopClick(TObject *Sender);
    void __fastcall cbHCICategoryChange(TObject *Sender);
    void __fastcall btnHCIStartClick(TObject *Sender);
    void __fastcall btnHCIStopClick(TObject *Sender);
    // void __fastcall btnRFRxStopClick(TObject *Sender);
    void __fastcall btnSCTStopClick(TObject *Sender);
    void __fastcall btnSCTStartClick(TObject *Sender);
    void __fastcall btnSCTClearLogClick(TObject *Sender);
    void __fastcall btnHCIClearLogClick(TObject *Sender);
    void __fastcall btnRFClearLogClick(TObject *Sender);
    void __fastcall btnPKTClearLogClick(TObject *Sender);
    void __fastcall btnTHClearLogClick(TObject *Sender);
    void __fastcall btnTHConnectDUTClick(TObject *Sender);
    void __fastcall cbTHCOMChange(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall btnRFEnterTestModeClick(TObject *Sender);
    void __fastcall btnRFQueryBdAddrClick(TObject *Sender);
    void __fastcall cbRFTxPowerCtrlClick(TObject *Sender);
    void __fastcall btnRFChangeLevelClick(TObject *Sender);
    void __fastcall ToggleHideExecute(TObject *Sender);
    void __fastcall edtRFNAPCheck(TObject *Sender);
    void __fastcall edtRFUAPCheck(TObject *Sender);
    void __fastcall edtRFLAPCheck(TObject *Sender);
    void __fastcall btnCTLDIReadClick(TObject *Sender);
    void __fastcall btnCTResetLDClick(TObject *Sender);
    void __fastcall btnCTLDIWriteClick(TObject *Sender);
    void __fastcall edtCTLDINAPCheck(TObject *Sender);
    void __fastcall edtCTLDIUAPCheck(TObject *Sender);
    void __fastcall edtCTLDILAPCheck(TObject *Sender);
    void __fastcall btnCTInquiryStartClick(TObject *Sender);
    void __fastcall edtCTInquiryTimeoutCheck(TObject *Sender);
    void __fastcall btCTClearLogClick(TObject *Sender);
    // void __fastcall btnCTScanStartClick(TObject *Sender);
    void __fastcall lbCTDisDevicesClick(TObject *Sender);
    void __fastcall btnCTConnectACLClick(TObject *Sender);
    void __fastcall btnCTInquiryStopClick(TObject *Sender);
    void __fastcall btnCTScanClick(TObject *Sender);
    void __fastcall btnCTAutoAcceptClick(TObject *Sender);
    void __fastcall btnCTDisconnectACLClick(TObject *Sender);
    void __fastcall lbCTConDevicesClick(TObject *Sender);
    void __fastcall btnCTChangeAclPktTypeClick(TObject *Sender);
    void __fastcall btnCTConnectSCOClick(TObject *Sender);
    void __fastcall edtCTPINCheck(TObject *Sender);
    void __fastcall btnCTEnterPINClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall btnTTConnectClick(TObject *Sender);
    void __fastcall btnTTDisconnectClick(TObject *Sender);
    void __fastcall edtTTDataLenCheck(TObject *Sender);
    void __fastcall edtTTPacketCountCheck(TObject *Sender);
    void __fastcall btnTTTxStartClick(TObject *Sender);
    void __fastcall btnTTChangeACLPacketTypeClick(TObject *Sender);
    void __fastcall edtRFBDAddressCheck(TObject *Sender);
    void __fastcall edtTTBdAddrCheck(TObject *Sender);
    void __fastcall btnTTRxStartClick(TObject *Sender);
    void __fastcall btnTTScanClick(TObject *Sender);
    void __fastcall btnTTAutoAcceptClick(TObject *Sender);
    void __fastcall btnTTTxStopClick(TObject *Sender);
    void __fastcall edtCTTxBandwidthCheck(TObject *Sender);
    void __fastcall edtCTRxBandwidthCheck(TObject *Sender);
    void __fastcall edtCTMaxLatencyCheck(TObject *Sender);
    void __fastcall edtCTRetransmitEffortCheck(TObject *Sender);
    void __fastcall btnTTRxStopClick(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall cbPKTCOMChange(TObject *Sender);
    void __fastcall cbPKTBaudRateChange(TObject *Sender);
    void __fastcall btnCTDisconnectSCOClick(TObject *Sender);
    void __fastcall m_tmMTTimer(TObject *Sender);
    void __fastcall m_btnMTReloadClick(TObject *Sender);
    void __fastcall m_btnMTRunClick(TObject *Sender);
    void __fastcall m_btnMTConnectClick(TObject *Sender);
    void __fastcall m_cbMETAModeClick(TObject *Sender);
    void __fastcall scrTestItemListChange(TObject *Sender);
    void __fastcall rbRxTestClick(TObject *Sender);
    void __fastcall rbTxTestClick(TObject *Sender);
    void __fastcall rbSingleChannelClick(TObject *Sender);
    void __fastcall rbHoppingClick(TObject *Sender);
    void __fastcall cbContinuousTxClick(TObject *Sender);
    void __fastcall btnStartClick(TObject *Sender);
    void __fastcall cbPatternSelect(TObject *Sender);
    void __fastcall etChannelExit(TObject *Sender);
    void __fastcall btClearClick(TObject *Sender);
    void __fastcall btHCIResetClick(TObject *Sender);
    void __fastcall btAdvertiseClearClick(TObject *Sender);
    void __fastcall btScanClearClick(TObject *Sender);
    void __fastcall btInitiateClearClick(TObject *Sender);
    void __fastcall tsAdvertiseShow(TObject *Sender);
    void __fastcall tsScanShow(TObject *Sender);
    void __fastcall tsInitiateShow(TObject *Sender);
    void __fastcall btBLEClearWhiteListClick(TObject *Sender);
    void __fastcall btAddDeviceToWhiteListClick(TObject *Sender);
    void __fastcall cbDeviceAddressChange(TObject *Sender);
    void __fastcall btRemoveDeviceToWhiteListClick(TObject *Sender);
    void __fastcall btSetAdvertiseDataClick(TObject *Sender);
    void __fastcall btAdvertiseStarClick(TObject *Sender);
    void __fastcall btSetScanResponseDataClick(TObject *Sender);
    void __fastcall btScanStartClick(TObject *Sender);
    void __fastcall btInitiateStartClick(TObject *Sender);
    void __fastcall btChangeMintoHexClick(TObject *Sender);
    void __fastcall btChangeMaxtoHexClick(TObject *Sender);
    void __fastcall btChangeLeScanIntervalClick(TObject *Sender);
    void __fastcall btChangeLEScanWindowClick(TObject *Sender);
    void __fastcall btnLEScanIntervalClick(TObject *Sender);
    void __fastcall btnLEScanWindowClick(TObject *Sender);
    void __fastcall btnEnterTestClick(TObject *Sender);
    void __fastcall btnSTDClearClick(TObject *Sender);
    void __fastcall btnExitTestClick(TObject *Sender);
    void __fastcall cbRXPacketTypeSubChange(TObject *Sender);
    void __fastcall btnResetTestClick(TObject *Sender);
        void __fastcall rbEnRxTestClick(TObject *Sender);
        void __fastcall btnEnStartClick(TObject *Sender);
        void __fastcall rbEnTxTestClick(TObject *Sender);



private:	// User declarations
    // common
    bool  m_bInit;
    bool m_bFirstFormShow;
    CMETAHANDLE m_META_HANDLE_Obj;
    unsigned char m_cBtId;
    bool ble_start_or_stop;
    bool ble_enhanced;
    bool ble_Advertise_start_or_stop;
    bool ble_Scan_start_or_stop;
    bool ble_Initiate_start_or_stop;


    //----------------------------- UI ------------------------------
    // RF test
    TEdit *m_edtRFTxAccessCode[8];

    //BLE
    CBTBLE    m_BT_BLE_Obj;
    S_BT_BLE m_sBtBle;
    S_BT_BLE_Normal m_sBleNormal;
    S_BT_BLE_ENHANCED m_sBleEnhanced;

    TStringList *m_pBLELog;
    
    AnsiString m_stab;

    //standalone
    TStringList *m_pSTDLog;
    S_BT_Standalone m_sRXStandalone;
    CBTRXStandalone m_BT_RXStandalone_Obj;


    // HCI
    S_BT_HCI  m_sBTHCI;
    CBTHCI    m_BT_HCI_Obj;
    TStringList *m_pHCILog;
    vector<S_BT_HCI_GROUP> *m_pvHCIGroup;
    vector<S_BT_HCI_CATEGORY> *m_pvHCICategory;
    BT_HCI_EVENT  m_sHCIEventFmt;
    S_HCI_TX_CMD  m_sTxCmd;
    // S_HCI_RX_EVENT  m_sRxEvent;
    vector<S_BT_HCI_PARAMETER> *m_pvSendHCIPar;
    vector<S_BT_HCI_PARAMETER> *m_pvReceiveHCIPar;

    // RF test
    // S_BT_RF  m_sBtRfTx;
    S_BT_RF  m_sBtRf;

    S_BD_ADDR m_sRFBdAddr;
    CBTRF       m_BT_RF_Obj;

    TStringList *m_pRFLog;

    TEdit     *m_edtRFNAP[BD_ADDRESS_NAP_LEN];
    TEdit     *m_edtRFUAP[BD_ADDRESS_UAP_LEN];
    TEdit     *m_edtRFLAP[BD_ADDRESS_LAP_LEN];

    // packet test
    bool m_bConnectTargetok;
    bool m_bConnectingTarget;
    TCheckBox *m_cbPKTType[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTDataLen[6];
    TEdit     *m_edtPKTPollPeriod[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTPktCount[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTTesterTXCount[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTTesterTXRate[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTTesterRXCount[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTTesterRXRate[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTDUTTXCount[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTDUTTXRate[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTDUTRXCount[BT_PACKET_IDX_COUNT];
    TEdit     *m_edtPKTDUTRXRate[BT_PACKET_IDX_COUNT];
    unsigned short m_usComPortArray[MAX_SUPPORT_COM_NUM];
    S_CWT  m_sCWT;
    AnsiString m_asBaudrate;
    T_META_ConnectWithTarget *m_pT_CWT;
    TStringList *m_pPKTLog;
    S_BT_PKT  m_sBTPKT;
    S_BT_PKT_TCI m_sBTTCI;
    // S_BT_PKT_MONITOR_REQ m_sBTMonReq;
    S_BT_PKT_MONITOR_CNF m_sBTMonCnf;
    CBTPKT  m_BT_PKT_Obj;
    S_PKT_STATUS m_sPKTStatus;
    unsigned int m_uiPKTLastTesterTx;
    unsigned int m_uiPKTLastTesterRx;
    unsigned int m_uiPKTLastDutTx;
    unsigned int m_uiPKTLastDutRx;
    unsigned int m_uiPKTCount;

    // script test
    // TButton *m_btnSCTTest[MAX_SCRIPT_NUM];
    S_BT_SCT  m_sBTSCT;
    CBTSCT  m_BT_SCT_Obj;
    TStringList *m_pSCTLog;
    vector<S_BT_SCT_SCRIPT> *m_pvScript;

    // module test
    CBTMT* Script[BT_MT_TESTCASE_NUM];
    TRadioButton* m_rbTestItem[BT_MT_TESTCASE_NUM];
    TStaticText*    lblItem[BT_MT_MAX_PROC_NUM];
    int ActIdx;
    int LoopCount;

    // throughput test
    E_BT_TT_VER_T m_eTtVer;
    S_BD_ADDR m_sTTACLBdAddr;
    CBTTT    m_cBT_TT_Obj;
    S_BT_TT  m_sBTTT;
    S_BT_TT_RES  m_sBTTTRes;
    TStringList *m_pTTLog;
    S_TIME  m_sTTTxStartTime;
    S_TIME  m_sTTRxStartTime;

    // connection test
    CBTCT    m_cBT_CT_Obj;
    S_BT_CT  m_sBTCT;
    TStringList *m_pCTLog;
    S_BD_ADDRS m_sLocalBdAddr;
    S_BD_ADDR  m_sCTACLBdAddr;
    S_BD_ADDR  m_sSCOBdAddr;
    unsigned int m_uiInquiryTimeout;
    S_BT_PIN   m_sBTPIN;
    unsigned int m_uiTxBandwidth;
    unsigned int m_uiRxBandwidth;
    unsigned short m_usMaxLatency;
    unsigned char m_ucRetransmissionEffort;

    // stop
    CBTSTOP  m_cBT_STOP_Obj;

    unsigned int m_nBTChipVersion;
    E_BT_STATE m_eBTState;
    CBTMan m_BT_Man_Obj;
    void OpenBT(void);
    void CloseBT(void);
    bool GetCurrentCOMPort(int &nComPortCount);
//

public:		// User declarations
    __fastcall TfrmBT(TComponent* Owner);

    // ------------------------ common ---------------------------
    void Init( void );
    void _fastcall SubClassWndProc( Messages::TMessage &Message);

    // memory
    void  AllocateVector( void );
    void  DeAllocateVector( void );

    // ------------------------   UI  ----------------------------
    // common

    void  CurrentPageReset( void );
    void  CurrentPageLock( void );
    // bool  CheckFields( void );
    bool  CheckHCIFields( void );
    bool  CheckRFFields( E_CHECK_MASK_RF check_mask );
    void  ShowHintLabel( TControl *sender, char* hint );
    void  ApplyHideProperty( void );


    // HCI
    bool  CheckSendHCIValue( void );
    void  DisplayHCIFile( void );
    void  SaveHCIFile( void );
    void  ReadHCIFile( AnsiString asFileName );
    void  DisplayHCIUI( int draw_mask, int group_idx, int cmd_idx );

    void  FillHCIResult( void );
    // void  AddReceiveParameterVector( void );
    void  ReDrawHCIFields( E_DRAM_MASK_HCI draw_mask );
    bool  ComposeHCICommand( S_BT_HCI &hci );
    bool  DeComposeHCIEvent( BT_HCI_EVENT &event );

    //BLE
    void  FillBLEHCIResult( void );
    void  FillBLEEnhancedHCIResult( void );
    void  FillBLENormalAdvertiseHCIResult(void);
    void  FillBLENormalScanHCIResult(void);
    void  FillBLENormalInitiateHCIResult(void);
    void CNF_BLE_Comman();
    void CNF_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb);
    AnsiString  deleteSpace(AnsiString input);


    void CNF_RXST_Enter();
    void CNF_RXST_Exit();
    void CNF_RXST_Reset();
    void FillRXSTDHCIResult(void);

    // RF
    void DisplayBtRfTestUi(void);
    void DisplayRFDefaultDataLen(void);
    unsigned short Get_RFTxDataDefaultLen(int index);
    unsigned short Get_RFTxDataMinLen(int index);
    unsigned short Get_RFTxDataMaxLen(int index);
    void  FillRFResult(void);
    void  ReDrawRFFields(E_DRAM_MASK_RF draw_mask);
    void  SyncLAPAndAccessCode( void );
    void  Build_Sync_Word(const unsigned int a_lap, unsigned int* pSyncHi, unsigned int* pSyncLo);

    // pakcet test
    void DisplayBtPktTestUi(void);
    void  DisplayPKTBDAddress( E_BT_PACKET_DEVICE_T obj );
    void  ReDrawPKTFields( E_DRAM_MASK_PKT draw_mask );
    bool  IsPKTTestFinish( E_BT_PACKET_IDX idx );
    bool  IsAllPKTTestFinish( void );
    bool  SetPKTFinish( E_BT_PACKET_IDX idx );
    bool  IsPKTTestRunning( E_BT_PACKET_IDX idx );
    bool  IsNewTciRequired( void );
    bool  CheckPKTFields( E_CHECK_MASK_PKT mark );
    unsigned short Get_PKTTxDataDefaultLen( E_BT_PACKET_IDX index );
    unsigned short Get_PKTTxDataMinLen( E_BT_PACKET_IDX index );
    unsigned short Get_PKTTxDataMaxLen(E_BT_PACKET_IDX index);
    void  FillPKTResult(void);
    void  SetMetaConnectReq(META_Connect_Req &META_connect_req);
    void  AbortConnectWithTarget(void);

    // script test
    void  DisplaySCTUI(void);
    void  FillSCTResult(void);

    // module test
    int  UpdateProcessGroup(void);
    int  ReloadScriptFiles(void);

    // throughput test
    void DisplayBtThroughputTestUi(void);
    bool  CheckTTFields( E_CHECK_MASK_TT mask );
    void  FillTTResult( void );
    unsigned short Get_TTAclPacketType( void );
    void  DisplayTHBDAddress( E_BT_PACKET_DEVICE_T obj );
    void  SetTHMetaConnectReq( META_Connect_Req &META_connect_req );
    void  ReDrawTTFields( E_DRAM_MASK_TT draw_mask );

    // connection test
    void DisplayBtConnectionTestUi(void);
    void  FillCTResult( void );
    void  ReDrawCTFields( E_DRAM_MASK_CT draw_mask );
    void  DisplayInquiryBDList( void );
    void  DisplayConnectBDList( void );
    S_BD_ADDR Get_BDAddrFromString( AnsiString as_str );
    unsigned short Get_CTAclPacketType( void );
    E_SCO_PKT_MASK Get_ScoPacketType( void );

    bool GetBTChipVersion(unsigned int* nBTChipID);
    void ShowBTPageControl();
//

    // stop
    void  Force_BT_Stop(bool reset);
    void  Force_BT_Stop_BLE(void);
    // callback
    void  ConfirmCallback_BLETX(void);
    void  ConfirmCallback_BLERX(void);
    void  ConfirmCallback_BLETXStop(void);
    void  ConfirmCallback_BLERXStop(void);
    void  ConfirmCallback_HCI(void);
    void  ConfirmCallback_SetupHCIFile(void);
    void  ConfirmCallback_RFTX(void);
    void  ConfirmCallback_RFRX(void);
    void  ConfirmCallback_RFEnterTestMode(void);

    void  ConfirmCallback_BLEENTX(void);
    void  ConfirmCallback_BLEENRX(void);
    void  ConfirmCallback_BLEEnTXStop(void);
    void  ConfirmCallback_BLEEnRXStop(void);


    void  CNF_PKT(void);
    void  CNF_PKT_Stop(void);
    void  CNF_PKT_TCI(void);
    void  CNF_PKT_Read_TxRxCount(void);
    void  CNF_PKT_Read_EDRTxRxCount(void);
    void  ConfirmCallback_SetupSCTFile(void);
    void  ConfirmCallback_SCT(void);
    void  ConfirmCallback_QueryBDAddress(void);
    void  ConfirmCallback_ChangePCL(void);
    void __fastcall on_PKTConnectWithTarget_Success(TObject *Sender);
    void __fastcall on_PKTConnectWithTarget_Fail(TObject *Sender);
    void __fastcall on_PKTConnectWithTarget_ByUser(TObject *Sender);
    void __fastcall on_THConnectWithTarget_Success(TObject *Sender);
    void __fastcall on_THConnectWithTarget_Fail(TObject *Sender);
    void __fastcall on_THConnectWithTarget_ByUser(TObject *Sender);
    void  CNF_CT_ReadLocalBDAddr(void);
    void  CNF_CT_WriteLocalBDAddr(void);
    void  CNF_CT_Reset(void);
    void  CNF_CT_Scan(void);
    void  CNF_CT_AutoAccept(void);
    void  CNF_CT_Inquiry(void);
    void  CNF_CT_InquiryCancel(void);
    void  CNF_CT_ConnectACL(void);
    void  CNF_CT_DisconnectACL(void);
    void  CNF_CT_ChangeACLPacketType(void);
    void  CNF_CT_ConnectSCO(void);
    void  CNF_CT_DisconnectSCO(void);
    void  CNF_CT_EnterPIN(void);
    void  CNF_TT_Scan(void);
    void  CNF_TT_AutoAccept(void);
    void  CNF_TT_ConnectACL(void);
    void  CNF_TT_DisconnectACL(void);
    void  CNF_TT_ChangeACLPacketType(void);
    void  CNF_TT_TxData(void);
    void  CNF_TT_RxData(void);
    void  CNF_TT_Stop_RxData(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBT *frmBT;
//---------------------------------------------------------------------------
#endif
