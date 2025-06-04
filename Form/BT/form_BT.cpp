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
 *   form_BT.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  MediaTek BT form source
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
 * Jul 17 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
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
//--------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// BT
#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

#ifndef  _BT_POWER_H_
#include "bt_power.h"
#endif

// form
#ifndef _FORM_BT_H_
#include "form_BT.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

// misc
#ifndef  _MISC_H_
#include "misc.h"
#endif

#ifndef  _MISC_BT_H_
#include "misc_bt.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _FILE_UTILS_H_
#include "file_utils.h"
#endif

#ifndef  _TIME_UTILS_H_
#include "time_utils.h"
#endif

// MF_Setup
#ifndef  _MFSETUPUTIL_H_
#include "mfsetuputil.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

// security
#ifndef _SLA_CHALLENGE_H_
#include "sla_challenge.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif
//---------------------------------------------------------------------------
#define DRAW_MASK_HCI_CATEGORY  0x01
#define DRAW_MASK_HCI_GROUP     0x02
#define DRAW_MASK_HCI_COMMAND   0x04
#define DRAW_MASK_HCI_PARAMETER 0x08

#define HCI_NAME_COL_IDX       0
#define HCI_BYTE_COL_IDX       1
#define HCI_VALUE_COL_IDX      2

/*
 * Sync word: BCH(64,30) Generator, degree 34, g(x) = Octal 260534236651
 */
#define SYNC_BCHgenHi 026053423665L     /* Right align in 64 bit register  */
#define SYNC_BCHgenLo (1L << 29)        /* Octal as specified              */

/*
 * Sync word: Pseudo-random noise generator sequence generation
 */
#define SYNC_PNseqHi  0x83848D96L
#define SYNC_PNseqLo  0xBBCC54FCL

#define BIT0  0x0001
#define BIT1  0x0002
#define BIT2  0x0004
#define BIT3  0x0008
#define BIT4  0x0010
#define BIT5  0x0020
#define BIT6  0x0040
#define BIT7  0x0080
#define BIT8  0x0100
#define BIT9  0x0200
#define BIT10 0x0400
#define BIT11 0x0800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000

#define BIT16 0x00010000
#define BIT17 0x00020000
#define BIT18 0x00040000
#define BIT19 0x00080000
#define BIT20 0x00100000
#define BIT21 0x00200000
#define BIT22 0x00400000
#define BIT23 0x00800000L
#define BIT24 0x01000000L
#define BIT25 0x02000000L
#define BIT26 0x04000000L
#define BIT27 0x08000000L
#define BIT28 0x10000000L
#define BIT29 0x20000000L
#define BIT30 0x40000000L
#define BIT31 0x80000000UL
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBT *frmBT;
extern bool g_bHideEnable;
extern bool ConnectTargetok; //add 20120610
//---------------------------------------------------------------------------
static void ConfirmCallback_HCI(void)
{
    frmBT->ConfirmCallback_HCI();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_SetupHCIFile(void)
{
    frmBT->ConfirmCallback_SetupHCIFile();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_RFTX(void)
{
    frmBT->ConfirmCallback_RFTX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_RFRX(void)
{
    frmBT->ConfirmCallback_RFRX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLETX(void)
{
    frmBT->ConfirmCallback_BLETX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLERX(void)
{
    frmBT->ConfirmCallback_BLERX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLETXStop(void)
{
    frmBT->ConfirmCallback_BLETXStop();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLERXStop(void)
{
    frmBT->ConfirmCallback_BLERXStop();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_BLEEnTXStop(void)
{
    frmBT->ConfirmCallback_BLEEnTXStop();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLEEnRXStop(void)
{
    frmBT->ConfirmCallback_BLEEnRXStop();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_RFEnterTestMode(void)
{
    frmBT->ConfirmCallback_RFEnterTestMode();
}
//---------------------------------------------------------------------------
static void CNF_PKT(void)
{
    frmBT->CNF_PKT();
}
//---------------------------------------------------------------------------
static void CNF_PKT_Stop(void)
{
    frmBT->CNF_PKT_Stop();
}
//---------------------------------------------------------------------------
static void CNF_PKT_TCI(void)
{
    frmBT->CNF_PKT_TCI();
}
//---------------------------------------------------------------------------
static void CNF_PKT_Read_TxRxCount( void )
{
    frmBT->CNF_PKT_Read_TxRxCount();
}
//---------------------------------------------------------------------------
static void CNF_PKT_Read_EDRTxRxCount(void)
{
    frmBT->CNF_PKT_Read_EDRTxRxCount();
}

//---------------------------------------------------------------------------
static void ConfirmCallback_BLEENTX(void)
{
    frmBT->ConfirmCallback_BLEENTX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_BLEENRX(void)
{
    frmBT->ConfirmCallback_BLEENRX();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_SetupSCTFile( void )
{
    frmBT->ConfirmCallback_SetupSCTFile();
}
//---------------------------------------------------------------------------
static void ConfirmCallback_SCT( void )
{
    frmBT->ConfirmCallback_SCT();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  ConfirmCallback_QueryBDAddress( void )
{
    frmBT->ConfirmCallback_QueryBDAddress();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void ConfirmCallback_ChangePCL( void )
{
    frmBT->ConfirmCallback_ChangePCL();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void CNF_CT_ReadLocalBDAddr( void )
{
    frmBT->CNF_CT_ReadLocalBDAddr();
}
//---------------------------------------------------------------------------
static void CNF_CT_WriteLocalBDAddr( void )
{
    frmBT->CNF_CT_WriteLocalBDAddr();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_Reset( void )
{
    frmBT->CNF_CT_Reset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_Scan( void )
{
    frmBT->CNF_CT_Scan();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void CNF_CT_AutoAccept( void )
{
    frmBT->CNF_CT_AutoAccept();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_Inquiry( void )
{
    frmBT->CNF_CT_Inquiry();
}
//---------------------------------------------------------------------------
static void  CNF_CT_InquiryCancel( void )
{
    frmBT->CNF_CT_InquiryCancel();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_EnterPIN( void )
{
    frmBT->CNF_CT_EnterPIN();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_ConnectACL( void )
{
    frmBT->CNF_CT_ConnectACL();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void CNF_CT_DisconnectACL( void )
{
    frmBT->CNF_CT_DisconnectACL();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_ChangeACLPacketType( void )
{
    frmBT->CNF_CT_ChangeACLPacketType();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_CT_ConnectSCO(void)
{
    frmBT->CNF_CT_ConnectSCO();
}
//---------------------------------------------------------------------------
static void CNF_CT_DisconnectSCO(void)
{
    frmBT->CNF_CT_DisconnectSCO();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  CNF_TT_Scan(void)
{
    frmBT->CNF_TT_Scan();
}
//---------------------------------------------------------------------------
static void  CNF_TT_AutoAccept( void )
{
    frmBT->CNF_TT_AutoAccept();
}
//---------------------------------------------------------------------------
static void  CNF_TT_ConnectACL( void )
{
    frmBT->CNF_TT_ConnectACL();
}
//---------------------------------------------------------------------------
static void  CNF_TT_DisconnectACL( void )
{
    frmBT->CNF_TT_DisconnectACL();
}
//---------------------------------------------------------------------------
static void  CNF_TT_ChangeACLPacketType( void )
{
    frmBT->CNF_TT_ChangeACLPacketType();
}
//---------------------------------------------------------------------------
static void  CNF_TT_TxData( void )
{
    frmBT->CNF_TT_TxData();
}
//--------------------------------------------------------------------------
static void  CNF_TT_RxData(void)
{
    frmBT->CNF_TT_RxData();
}
//---------------------------------------------------------------------------
static void  CNF_TT_Stop_RxData(void)
{
    frmBT->CNF_TT_Stop_RxData();
}
//---------------------------------------------------------------------------
static void CNF_BLE_Comman()
{
    frmBT->CNF_BLE_Comman();
}
//---------------------------------------------------------------------------
static void CNF_RXST_Enter()
{
    frmBT->CNF_RXST_Enter();
}
//---------------------------------------------------------------------------
static void CNF_RXST_Exit()
{
    frmBT->CNF_RXST_Exit();
}
//---------------------------------------------------------------------------
static void CNF_RXST_Reset()
{
    frmBT->CNF_RXST_Reset();
}
//---------------------------------------------------------------------------
__fastcall TfrmBT::TfrmBT(TComponent* Owner)
    : TForm(Owner)
{
    // RF test
    m_edtRFTxAccessCode[0] = edtRFTxAccessCode0;
    m_edtRFTxAccessCode[1] = edtRFTxAccessCode1;
    m_edtRFTxAccessCode[2] = edtRFTxAccessCode2;
    m_edtRFTxAccessCode[3] = edtRFTxAccessCode3;
    m_edtRFTxAccessCode[4] = edtRFTxAccessCode4;
    m_edtRFTxAccessCode[5] = edtRFTxAccessCode5;
    m_edtRFTxAccessCode[6] = edtRFTxAccessCode6;
    m_edtRFTxAccessCode[7] = edtRFTxAccessCode7;

    // m_edtRFNAP[0] = edtRFNAP0;
    // m_edtRFNAP[1] = edtRFNAP1;
    // m_edtRFNAP[2] = edtRFNAP2;
    // m_edtRFNAP[3] = edtRFNAP3;

    // m_edtRFUAP[0] = edtRFUAP0;
    // m_edtRFUAP[1] = edtRFUAP1;

    // m_edtRFLAP[0] = edtRFLAP0;
    // m_edtRFLAP[1] = edtRFLAP1;
    // m_edtRFLAP[2] = edtRFLAP2;
    // m_edtRFLAP[3] = edtRFLAP3;
    // m_edtRFLAP[4] = edtRFLAP4;
    // m_edtRFLAP[5] = edtRFLAP5;

    // Packet test
    m_cbPKTType[0]  = cbPKTDM1;
    m_cbPKTType[1]  = cbPKTDH1;
    m_cbPKTType[2]  = cbPKTDM3;
    m_cbPKTType[3]  = cbPKTDH3;
    m_cbPKTType[4]  = cbPKTDM5;
    m_cbPKTType[5]  = cbPKTDH5;
    m_cbPKTType[6]  = cbPKTHV1;
    m_cbPKTType[7]  = cbPKTHV2;
    m_cbPKTType[8]  = cbPKTHV3;
    m_cbPKTType[9] = cbPKTEV3;
    m_cbPKTType[10] = cbPKTEV4;
    m_cbPKTType[11] = cbPKTEV5;
    m_cbPKTType[12] = cbPK2DH1;
    m_cbPKTType[13] = cbPK2EV3;
    m_cbPKTType[14] = cbPK2DH3;
    m_cbPKTType[15] = cbPK2EV5;
    m_cbPKTType[16] = cbPK2DH5;
    m_cbPKTType[17] = cbPK3EV3;
    m_cbPKTType[18] = cbPK3DH1;
    m_cbPKTType[19] = cbPK3DH3;
    m_cbPKTType[20] = cbPK3EV5;
    m_cbPKTType[21] = cbPK3DH5;

    m_edtPKTDataLen[0]  = edtPKTDM1DataLen;
    m_edtPKTDataLen[1]  = edtPKTDH1DataLen;
    m_edtPKTDataLen[2]  = edtPKTDM3DataLen;
    m_edtPKTDataLen[3]  = edtPKTDH3DataLen;
    m_edtPKTDataLen[4]  = edtPKTDM5DataLen;
    m_edtPKTDataLen[5]  = edtPKTDH5DataLen;



    m_edtPKTPollPeriod[0]  = edtPKTDM1PollPeriod;
    m_edtPKTPollPeriod[1]  = edtPKTDH1PollPeriod;
    m_edtPKTPollPeriod[2]  = edtPKTDM3PollPeriod;
    m_edtPKTPollPeriod[3]  = edtPKTDH3PollPeriod;
    m_edtPKTPollPeriod[4]  = edtPKTDM5PollPeriod;
    m_edtPKTPollPeriod[5]  = edtPKTDH5PollPeriod;
    m_edtPKTPollPeriod[6]  = edtPKTHV1PollPeriod;
    m_edtPKTPollPeriod[7]  = edtPKTHV2PollPeriod;
    m_edtPKTPollPeriod[8]  = edtPKTHV3PollPeriod;
    m_edtPKTPollPeriod[9] = edtPKTEV3PollPeriod;
    m_edtPKTPollPeriod[10] = edtPKTEV4PollPeriod;
    m_edtPKTPollPeriod[11] = edtPKTEV5PollPeriod;
    m_edtPKTPollPeriod[12] = edtPKT2DH1PollPeriod;
    m_edtPKTPollPeriod[13] = edtPKT2EV3PollPeriod;
    m_edtPKTPollPeriod[14] = edtPKT2DH3PollPeriod;
    m_edtPKTPollPeriod[15] = edtPKT2EV5PollPeriod;
    m_edtPKTPollPeriod[16] = edtPKT2DH5PollPeriod;
    m_edtPKTPollPeriod[17] = edtPKT3EV3PollPeriod;
    m_edtPKTPollPeriod[18] = edtPKT3DH1PollPeriod;
    m_edtPKTPollPeriod[19] = edtPKT3DH3PollPeriod;
    m_edtPKTPollPeriod[20] = edtPKT3EV5PollPeriod;
    m_edtPKTPollPeriod[21] = edtPKT3DH5PollPeriod;

    m_edtPKTPktCount[0]  = edtPKTDM1PktCount;
    m_edtPKTPktCount[1]  = edtPKTDH1PktCount;
    m_edtPKTPktCount[2]  = edtPKTDM3PktCount;
    m_edtPKTPktCount[3]  = edtPKTDH3PktCount;
    m_edtPKTPktCount[4]  = edtPKTDM5PktCount;
    m_edtPKTPktCount[5]  = edtPKTDH5PktCount;
    m_edtPKTPktCount[6]  = edtPKTHV1PktCount;
    m_edtPKTPktCount[7]  = edtPKTHV2PktCount;
    m_edtPKTPktCount[8]  = edtPKTHV3PktCount;
    m_edtPKTPktCount[9] = edtPKTEV3PktCount;
    m_edtPKTPktCount[10] = edtPKTEV4PktCount;
    m_edtPKTPktCount[11] = edtPKTEV5PktCount;
    m_edtPKTPktCount[12] = edtPKT2DH1PktCount;
    m_edtPKTPktCount[13] = edtPKT2EV3PktCount;
    m_edtPKTPktCount[14] = edtPKT2DH3PktCount;
    m_edtPKTPktCount[15] = edtPKT2EV5PktCount;
    m_edtPKTPktCount[16] = edtPKT2DH5PktCount;
    m_edtPKTPktCount[17] = edtPKT3EV3PktCount;
    m_edtPKTPktCount[18] = edtPKT3DH1PktCount;
    m_edtPKTPktCount[19] = edtPKT3DH3PktCount;
    m_edtPKTPktCount[20] = edtPKT3EV5PktCount;
    m_edtPKTPktCount[21] = edtPKT3DH5PktCount;


    m_edtPKTTesterTXCount[0]  = edtPKTTesterDM1TXCount;
    m_edtPKTTesterTXCount[1]  = edtPKTTesterDH1TXCount;
    m_edtPKTTesterTXCount[2]  = edtPKTTesterDM3TXCount;
    m_edtPKTTesterTXCount[3]  = edtPKTTesterDH3TXCount;
    m_edtPKTTesterTXCount[4]  = edtPKTTesterDM5TXCount;
    m_edtPKTTesterTXCount[5]  = edtPKTTesterDH5TXCount;
    m_edtPKTTesterTXCount[6]  = edtPKTTesterHV1TXCount;
    m_edtPKTTesterTXCount[7]  = edtPKTTesterHV2TXCount;
    m_edtPKTTesterTXCount[8]  = edtPKTTesterHV3TXCount;
    m_edtPKTTesterTXCount[9]  = edtPKTTesterEV3TXCount;
    m_edtPKTTesterTXCount[10] = edtPKTTesterEV4TXCount;
    m_edtPKTTesterTXCount[11] = edtPKTTesterEV5TXCount;
    m_edtPKTTesterTXCount[12] = edtPKTTester2DH1TXCount;
    m_edtPKTTesterTXCount[13] = edtPKTTester2EV3TXCount;
    m_edtPKTTesterTXCount[14] = edtPKTTester2DH3TXCount;
    m_edtPKTTesterTXCount[15] = edtPKTTester2EV5TXCount;
    m_edtPKTTesterTXCount[16] = edtPKTTester2DH5TXCount;
    m_edtPKTTesterTXCount[17] = edtPKTTester3EV3TXCount;
    m_edtPKTTesterTXCount[18] = edtPKTTester3DH1TXCount;
    m_edtPKTTesterTXCount[19] = edtPKTTester3DH3TXCount;
    m_edtPKTTesterTXCount[20] = edtPKTTester3EV5TXCount;
    m_edtPKTTesterTXCount[21] = edtPKTTester3DH5TXCount;

    m_edtPKTTesterRXCount[0]  = edtPKTTesterDM1RXCount;
    m_edtPKTTesterRXCount[1]  = edtPKTTesterDH1RXCount;
    m_edtPKTTesterRXCount[2]  = edtPKTTesterDM3RXCount;
    m_edtPKTTesterRXCount[3]  = edtPKTTesterDH3RXCount;
    m_edtPKTTesterRXCount[4]  = edtPKTTesterDM5RXCount;
    m_edtPKTTesterRXCount[5]  = edtPKTTesterDH5RXCount;
    m_edtPKTTesterRXCount[6]  = edtPKTTesterHV1RXCount;
    m_edtPKTTesterRXCount[7]  = edtPKTTesterHV2RXCount;
    m_edtPKTTesterRXCount[8]  = edtPKTTesterHV3RXCount;
    m_edtPKTTesterRXCount[9]  = edtPKTTesterEV3RXCount;
    m_edtPKTTesterRXCount[10] = edtPKTTesterEV4RXCount;
    m_edtPKTTesterRXCount[11] = edtPKTTesterEV5RXCount;
    m_edtPKTTesterRXCount[12] = edtPKTTester2DH1RXCount;
    m_edtPKTTesterRXCount[13] = edtPKTTester2EV3RXCount;
    m_edtPKTTesterRXCount[14] = edtPKTTester2DH3RXCount;
    m_edtPKTTesterRXCount[15] = edtPKTTester2EV5RXCount;
    m_edtPKTTesterRXCount[16] = edtPKTTester2DH5RXCount;
    m_edtPKTTesterRXCount[17] = edtPKTTester3EV3RXCount;
    m_edtPKTTesterRXCount[18] = edtPKTTester3DH1RXCount;
    m_edtPKTTesterRXCount[19] = edtPKTTester3DH3RXCount;
    m_edtPKTTesterRXCount[20] = edtPKTTester3EV5RXCount;
    m_edtPKTTesterRXCount[21] = edtPKTTester3DH5RXCount;

    m_edtPKTDUTTXCount[0]  = edtPKTDUTDM1TXCount;
    m_edtPKTDUTTXCount[1]  = edtPKTDUTDH1TXCount;
    m_edtPKTDUTTXCount[2]  = edtPKTDUTDM3TXCount;
    m_edtPKTDUTTXCount[3]  = edtPKTDUTDH3TXCount;
    m_edtPKTDUTTXCount[4]  = edtPKTDUTDM5TXCount;
    m_edtPKTDUTTXCount[5]  = edtPKTDUTDH5TXCount;
    m_edtPKTDUTTXCount[6]  = edtPKTDUTHV1TXCount;
    m_edtPKTDUTTXCount[7]  = edtPKTDUTHV2TXCount;
    m_edtPKTDUTTXCount[8]  = edtPKTDUTHV3TXCount;
    m_edtPKTDUTTXCount[9]  = edtPKTDUTEV3TXCount;
    m_edtPKTDUTTXCount[10] = edtPKTDUTEV4TXCount;
    m_edtPKTDUTTXCount[11] = edtPKTDUTEV5TXCount;
    m_edtPKTDUTTXCount[12] = edtPKTDUT2DH1TXCount;
    m_edtPKTDUTTXCount[13] = edtPKTDUT2EV3TXCount;
    m_edtPKTDUTTXCount[14] = edtPKTDUT2DH3TXCount;
    m_edtPKTDUTTXCount[15] = edtPKTDUT2EV5TXCount;
    m_edtPKTDUTTXCount[16] = edtPKTDUT2DH5TXCount;
    m_edtPKTDUTTXCount[17] = edtPKTDUT3EV3TXCount;
    m_edtPKTDUTTXCount[18] = edtPKTDUT3DH1TXCount;
    m_edtPKTDUTTXCount[19] = edtPKTDUT3DH3TXCount;
    m_edtPKTDUTTXCount[20] = edtPKTDUT3EV5TXCount;
    m_edtPKTDUTTXCount[21] = edtPKTDUT3DH5TXCount;

    m_edtPKTDUTRXCount[0]  = edtPKTDUTDM1RXCount;
    m_edtPKTDUTRXCount[1]  = edtPKTDUTDH1RXCount;
    m_edtPKTDUTRXCount[2]  = edtPKTDUTDM3RXCount;
    m_edtPKTDUTRXCount[3]  = edtPKTDUTDH3RXCount;
    m_edtPKTDUTRXCount[4]  = edtPKTDUTDM5RXCount;
    m_edtPKTDUTRXCount[5]  = edtPKTDUTDH5RXCount;
    m_edtPKTDUTRXCount[6]  = edtPKTDUTHV1RXCount;
    m_edtPKTDUTRXCount[7]  = edtPKTDUTHV2RXCount;
    m_edtPKTDUTRXCount[8]  = edtPKTDUTHV3RXCount;
    m_edtPKTDUTRXCount[9]  = edtPKTDUTEV3RXCount;
    m_edtPKTDUTRXCount[10] = edtPKTDUTEV4RXCount;
    m_edtPKTDUTRXCount[11] = edtPKTDUTEV5RXCount;
    m_edtPKTDUTRXCount[12] = edtPKTDUT2DH1RXCount;
    m_edtPKTDUTRXCount[13] = edtPKTDUT2EV3RXCount;
    m_edtPKTDUTRXCount[14] = edtPKTDUT2DH3RXCount;
    m_edtPKTDUTRXCount[15] = edtPKTDUT2EV5RXCount;
    m_edtPKTDUTRXCount[16] = edtPKTDUT2DH5RXCount;
    m_edtPKTDUTRXCount[17] = edtPKTDUT3EV3RXCount;
    m_edtPKTDUTRXCount[18] = edtPKTDUT3DH1RXCount;
    m_edtPKTDUTRXCount[19] = edtPKTDUT3DH3RXCount;
    m_edtPKTDUTRXCount[20] = edtPKTDUT3EV5RXCount;
    m_edtPKTDUTRXCount[21] = edtPKTDUT3DH5RXCount;

    m_pT_CWT = NULL;

    m_sBtBle.ble_tx_patten = PRBS9;

    // module test
    lblItem[ 0] = lblItem1;
    lblItem[10] = lblItem11;
    lblItem[20] = lblItem21;
    lblItem[ 1] = lblItem2;
    lblItem[11] = lblItem12;
    lblItem[21] = lblItem22;
    lblItem[ 2] = lblItem3;
    lblItem[12] = lblItem13;
    lblItem[ 3] = lblItem4;
    lblItem[13] = lblItem14;
    m_rbTestItem[0] = m_rbMTTestItem0;
    lblItem[ 4] = lblItem5;
    lblItem[14] = lblItem15;
    m_rbTestItem[1] = m_rbMTTestItem1;
    lblItem[ 5] = lblItem6;
    lblItem[15] = lblItem16;
    m_rbTestItem[2] = m_rbMTTestItem2;
    lblItem[ 6] = lblItem7;
    lblItem[16] = lblItem17;
    m_rbTestItem[3] = m_rbMTTestItem3;
    lblItem[ 7] = lblItem8;
    lblItem[17] = lblItem18;
    m_rbTestItem[4] = m_rbMTTestItem4;
    lblItem[ 8] = lblItem9;
    lblItem[18] = lblItem19;
    lblItem[ 9] = lblItem10;
    lblItem[19] = lblItem20;
    for (int n = 0; n < BT_MT_TESTCASE_NUM; n++)
    {
        Script[n] = 0;
    }
    ActIdx = -1;

    m_pvSendHCIPar = NULL;
    m_pvReceiveHCIPar = NULL;
    
    m_bFirstFormShow = false;
    m_cBtId = 0;
    ble_start_or_stop = false;
    ble_Advertise_start_or_stop = false;
    ble_Scan_start_or_stop = false;
    ble_Initiate_start_or_stop = false;
    m_pBLELog = NULL; 
    m_pSTDLog = NULL;
    m_pHCILog = NULL;
    m_pvHCIGroup = NULL;
    m_pvHCICategory = NULL;
    m_pRFLog = NULL;
    
    
    m_pPKTLog = NULL;
    memset(&m_sPKTStatus,0,sizeof(m_sPKTStatus));
    m_uiPKTLastTesterTx = 0;
    m_uiPKTLastTesterRx = 0;
    m_uiPKTLastDutTx = 0;
    m_uiPKTLastDutRx = 0;
    m_uiPKTCount = 0;
    m_pSCTLog = NULL;
    m_pvScript = NULL;
    LoopCount = 0;
    m_pTTLog = NULL;
    m_pCTLog = NULL;
    m_uiInquiryTimeout = 0;
    m_uiTxBandwidth = 0;
    m_uiRxBandwidth = 0;
    m_usMaxLatency = 0;
    m_ucRetransmissionEffort = 0;
    m_eBTState = BT_STATE_CLOSE;
    
    int i = 0;
    for(i=0; i<BD_ADDRESS_NAP_LEN; i++)
    {
        m_edtRFNAP[i] = NULL;
        m_edtRFUAP[i] = NULL;
        m_edtRFLAP[i] = NULL;
    }
    
    for(i=0; i<BT_PACKET_IDX_COUNT; i++)
    {
        m_edtPKTTesterTXRate[i] = NULL;
        m_edtPKTTesterRXRate[i] = NULL;
        m_edtPKTDUTTXRate[i] = NULL;
        m_edtPKTDUTRXRate[i] = NULL;
    }  
    
    for(i=0; i<MAX_SUPPORT_COM_NUM; i++)
    {
        m_usComPortArray[i] = 0;
    }
    
    Init();

    WindowProc = SubClassWndProc;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmBT::AllocateVector( void )
{
    if( NULL == m_pvSendHCIPar )
        m_pvSendHCIPar    = new vector<S_BT_HCI_PARAMETER>;

    if( NULL == m_pvReceiveHCIPar )
        m_pvReceiveHCIPar = new vector<S_BT_HCI_PARAMETER>;
}
//---------------------------------------------------------------------------
void TfrmBT::DeAllocateVector( void )
{
    if( m_pvSendHCIPar != NULL )
    {
        if( ! m_pvSendHCIPar->empty() )
        {
            m_pvSendHCIPar->erase( m_pvSendHCIPar->begin(), m_pvSendHCIPar->end() );
        }

        delete m_pvSendHCIPar;
        m_pvSendHCIPar = NULL;
    }

    if( m_pvReceiveHCIPar != NULL )
    {
        if( ! m_pvReceiveHCIPar->empty() )
        {
            m_pvReceiveHCIPar->erase( m_pvReceiveHCIPar->begin(), m_pvReceiveHCIPar->end() );
        }
        delete m_pvReceiveHCIPar;
        m_pvReceiveHCIPar = NULL;
    }

}
//---------------------------------------------------------------------------
void TfrmBT::Init(void)
{
    m_bInit             = true;
    btnHCIStart->Enabled = true;
    btnPKTStart->Enabled = true;
    btnPKTConnectDUT->Enabled = true;
    m_btnMTConnect->Enabled = m_cbMETAMode->Checked;
    shpPKTConnect->Brush->Color = clRed;
    m_shpMTConnect->Brush->Color = clRed;
    m_bConnectTargetok = false;
    m_bConnectingTarget = false;
    m_nBTChipVersion = 0;
    btnRFChangeLevel->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::FormHide(TObject *Sender)
{
    m_sCWT.iBootStop = SP_BOOT_STOP;
    AbortConnectWithTarget();
    CloseBT();
}
//==============================================================================
void _fastcall TfrmBT::SubClassWndProc( Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
    case WM_ML_BT_BD_ADDRESS_MSG:
    {
        DisplayPKTBDAddress( (E_BT_PACKET_DEVICE_T) Message.WParam );
    }
    break;

    case WM_ML_BT_START_MONITOR_MSG:
    {
        MonitorTimer->Enabled = true;
    }
    break;

    case WM_ML_BT_PRINT_MSG:
    {
        switch( (E_BT_PAGEIDX) Message.WParam )
        {
        case PAGEIDX_BT_BLE:
        {
            FillBLEHCIResult();
        }
        break;

        case PAGEIDX_BT_BLE_ENHANCED:
        {
            FillBLEEnhancedHCIResult();
        }
        break;

        case PAGEIDX_BT_BLE_Normal_Advertise:
        {
            FillBLENormalAdvertiseHCIResult();
        }
        break;

        case PAGEIDX_BT_BLE_Normal_Scan:
        {
            FillBLENormalScanHCIResult();
        }
        break;

        case PAGEIDX_BT_BLE_Normal_Initiate:
        {
            FillBLENormalInitiateHCIResult();
        }
        break;

        case PAGEIDX_BT_RXSTD:
        {
            FillRXSTDHCIResult();
        }
        break;

        case PAGEIDX_BT_HCI:
        {
            FillHCIResult();
        }
        break;

        case PAGEIDX_BT_RF:
        {
            FillRFResult();
        }
        break;

        case PAGEIDX_BT_PKT:
        {
            FillPKTResult();
        }
        break;

        case PAGEIDX_BT_SCT:
        {
            FillSCTResult();
        }
        break;

        case PAGEIDX_BT_TT:
        {
            FillTTResult();
        }
        break;

        case PAGEIDX_BT_CT:
        {
            FillCTResult();
        }
        break;
        }
    }
    break;

    case WM_ML_BT_PIN_MSG:
    {
        btnCTEnterPIN->Enabled = true;
        ShowHintLabel( edtCTPIN, "Please enter PIN code" );
    }
    break;

    case MW_ML_BT_CONNECT_MSG:
    {
        switch( (E_BT_PAGEIDX) Message.WParam )
        {
        case PAGEIDX_BT_CT:
        {
            ReDrawCTFields( DRAM_MASK_CT_DISCOVERED_LIST |
                            DRAM_MASK_CT_CONNECT_LIST    |
                            DRAM_MASK_CT_ACL_STATUS      |
                            DRAM_MASK_CT_BUTTON );

            sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect from remote BT device";
        }
        break;

        case PAGEIDX_BT_TT:
        {
            m_sBTTTRes = m_cBT_TT_Obj.Get_TTResult();
            ReDrawTTFields( DRAM_MASK_TT_ACL_STATUS      |
                            DRAM_MASK_TT_BUTTON );

            sbTT->Panels->Items[0]->Text = (AnsiString)"  Connect from remote BT device";
        }
        break;
        }

    }
    break;

    case WM_ML_BT_DISCONNECT_MSG:
    {
        switch( (E_BT_PAGEIDX) Message.WParam )
        {
        case PAGEIDX_BT_CT:
        {
            ReDrawCTFields( DRAM_MASK_CT_DISCOVERED_LIST |
                            DRAM_MASK_CT_CONNECT_LIST    |
                            DRAM_MASK_CT_ACL_STATUS      |
                            DRAM_MASK_CT_BUTTON );

            sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect from remote BT device";
        }
        break;

        case PAGEIDX_BT_TT:
        {
            m_sBTTTRes = m_cBT_TT_Obj.Get_TTResult();
            ReDrawTTFields( DRAM_MASK_TT_ACL_STATUS      |
                            DRAM_MASK_TT_BUTTON );

            sbTT->Panels->Items[0]->Text = (AnsiString)"  Disconnect from remote BT device";
        }
        break;
        }

    }
    break;

    case WM_ML_BT_TT_TX_STATUS:
    {
        unsigned int ui_pkt_length = (unsigned int) Message.WParam;
        unsigned int ui_used_time;
        if (BT_TT_VER_0 == m_eTtVer)
        {
            S_TIME time;
            time = ::Get_CurrentTime();
            int msec = DifferenceMiniSec(&m_sTTTxStartTime, &time);
            ui_used_time = (unsigned int) msec;
        }
        else
        {
            ui_used_time = (unsigned int) Message.LParam;
        }

        if (0 == ui_used_time)
        {
            return;
        }
        int data_len = edtTTDataLen->Text.ToInt();
        float tx_throughput = 1000.0 * ui_pkt_length / ui_used_time;
        int count = ui_pkt_length/data_len;
        char str[64];
        sprintf(str, "%.3f", tx_throughput);
        stTTTxCount->Caption = IntToStr(count);
        stTTTxThroughput->Caption = (AnsiString) str;

        if (count >= edtTTPacketCount->Text.ToInt())
        {
            CurrentPageReset();
        }
    }
    break;

    case WM_ML_BT_TT_RX_STATUS:
    {
        unsigned int ui_pkt_length = (unsigned int) Message.WParam;
        unsigned int ui_used_time;
        if (BT_TT_VER_0 == m_eTtVer)
        {
            S_TIME time;
            time = ::Get_CurrentTime();
            int msec = DifferenceMiniSec(&m_sTTRxStartTime, &time);
            ui_used_time = (unsigned int) msec;
        }
        else
        {
            ui_used_time = (unsigned int) Message.LParam;
        }

        if (0 == ui_used_time)
        {
            return;
        }
        // int data_len = edtTTDataLen->Text.ToInt();
        float rx_throughput = 1000.0 * ui_pkt_length / ui_used_time;
        char str[64];
        sprintf(str, "%.3f", rx_throughput);
        stTTRxBytes->Caption = IntToStr(ui_pkt_length);
        stTTRxThroughput->Caption = (AnsiString) str;
    }
    break;

    default:
        this->WndProc( Message );
        break;
    }
}
//===========================================================================
////////////////////////////  Form event handler   //////////////////////////
//===========================================================================
void __fastcall TfrmBT::FormCreate(TObject *Sender)
{
    m_bFirstFormShow = true;

    // allocate memory
    m_pHCILog = new TStringList;
    m_pRFLog  = new TStringList;
    m_pPKTLog = new TStringList;
    m_pSCTLog = new TStringList;
    m_pCTLog  = new TStringList;
    m_pTTLog  = new TStringList;
    m_pBLELog = new TStringList;
    m_pSTDLog = new TStringList;

    AllocateVector();

    if( rbHCICategory->Checked )
    {
        cbHCICategory->Enabled = true;
        cbHCIGroup->Enabled    = false;
    }
    else
    {
        cbHCICategory->Enabled = false;
        cbHCIGroup->Enabled    = true;
    }

    // RF test
    cbRFTxPattern->ItemIndex = 0;

    // packet test
    cbPKTBaudRate->ItemIndex = 0;

    // throughput test
    m_cbTTScanType->ItemIndex = 3;

    // connection test
    cbCTScanType->ItemIndex = 3;
    
    m_uiInquiryTimeout = edtCTInquiryTimeout->Text.ToInt() * 1.28 * 1000;
    m_sBTPIN.uc_pin_len = 4;
    for( int i=0; i<m_sBTPIN.uc_pin_len; i++ )
        m_sBTPIN.uc_PIN[i] = '0';
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::FormActivate(TObject *Sender)
{
    OpenBT();
    if (m_bInit)
    {
        if( ConnectTargetok )
        {
            m_bInit = false;
        }
        ApplyHideProperty();
        BT_ModuleID_S* p_bt_module_id = frmMainSel->Get_BTMoudleID();
        m_cBtId = p_bt_module_id->id;

        DisplayBtRfTestUi();
        DisplayBtPktTestUi();
        DisplayBtThroughputTestUi();
        DisplayBtConnectionTestUi();
        CBTPOWER BT_POWER_Obj;
        BT_POWER_Obj.REQ_Power_On_Main_BT_Start();
        m_eTtVer = m_cBT_TT_Obj.Query_TtTestVersion();
        unsigned int nBTChipID = 0;
        if(GetBTChipVersion(&nBTChipID))
        {
            m_nBTChipVersion = nBTChipID;
            LOG("20120113 m_nBTChipVersion:%d",m_nBTChipVersion);
        }
    }
    ShowBTPageControl();
//
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::FormClose(TObject *Sender, TCloseAction &Action)
{
    // HCI file
    SaveHCIFile();
    AbortConnectWithTarget();
    CloseBT();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::FormDestroy(TObject *Sender)
{
    // free memory
    if( m_pHCILog != NULL )
    {
        delete  m_pHCILog;
        m_pHCILog = NULL;
    }

    if( m_pRFLog != NULL)
    {
        delete  m_pRFLog;
        m_pRFLog = NULL;
    }

    if( m_pPKTLog != NULL )
    {
        delete  m_pPKTLog;
        m_pPKTLog = NULL;
    }

    if( m_pSCTLog != NULL )
    {
        delete  m_pSCTLog;
        m_pSCTLog = NULL;
    }

    if(  m_pTTLog != NULL )
    {
        delete  m_pTTLog;
        m_pTTLog = NULL;
    }

    if( m_pCTLog != NULL)
    {
        delete  m_pCTLog;
        m_pCTLog = NULL;
    }

    if (m_pBLELog != NULL )
    {
        delete m_pBLELog;
        m_pBLELog = NULL;
    }

    if (m_pSTDLog != NULL)
    {
        delete m_pSTDLog;
        m_pSTDLog = NULL;
    }

    DeAllocateVector();

    for (int n=0; n < BT_MT_TESTCASE_NUM; n++)
    {
        if (Script[n] != NULL)
        {
            delete Script[n];
            Script[n] = NULL;
        }
    }

    if( m_bConnectTargetok )
    {
        SP_META_ShutDownTarget_r( m_META_HANDLE_Obj.Get_SecondHandle() );
        SP_META_DisconnectWithTarget_r( m_META_HANDLE_Obj.Get_SecondHandle() );
        m_bConnectTargetok = false;
    }

    if( NULL == m_pT_CWT )
        m_sCWT.iBootStop = SP_BOOT_STOP;
    WaitForSingleObject( m_sCWT.METADLL_Connect_Event, 5000 );

    // release handle
    m_META_HANDLE_Obj.REQ_ReleaseSecondHandle_Start();
}
//===========================================================================
void TfrmBT::DisplayBtRfTestUi(void)
{
    cbRFTxType->Clear();
    AnsiString as_nonedr_pkt_name[] =
    {
        "NULL",
        "POLL",
        "FHS",
        "DM1",
        "DH1",
        "HV1",
        "HV2",
        "HV3",
        "DV",
        "AUX",
        "DM3",
        "DH3",
        "DM5",
        "DH5",
        "EV3",
        "EV4",
        "EV5",
    };

    for (int i=0; i<BT_RF_TX_NONEDR_IDX_COUNT; i++)
    {
        cbRFTxType->Items->Add(as_nonedr_pkt_name[i]);
    }

    AnsiString as_edr_pkt_name[] =
    {
        "2-DH1",
        "2-EV3",
        "2-DH3",
        "2-EV5",
        "2-DH5",
        "3-EV3",
        "3-DH1",
        "3-DH3",
        "3-EV5",
        "3-DH5",
        "non-modulated"
    };

    for (int i = 0; i < BT_RF_TX_IDX_COUNT - BT_RF_TX_NONEDR_IDX_COUNT; i++)
    {
        cbRFTxType->Items->Add(as_edr_pkt_name[i]);
    }

    cbRFTxType->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayBtPktTestUi(void)
{
    bool b_visible = true;

    for (int i=BT_PACKET_IDX_2DH1; i<BT_PACKET_IDX_COUNT; i++)
    {
        m_cbPKTType[i]->Visible = b_visible;
        m_edtPKTPollPeriod[i]->Visible = b_visible;
        m_edtPKTPktCount[i]->Visible = b_visible;
        m_edtPKTTesterTXCount[i]->Visible = b_visible;
        m_edtPKTTesterRXCount[i]->Visible = b_visible;
        m_edtPKTDUTTXCount[i]->Visible = b_visible;
        m_edtPKTDUTRXCount[i]->Visible = b_visible;
    }
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayBtThroughputTestUi(void)
{
    bool b_eco_support = (BTMODULE_MT6611 == m_cBtId);
    m_cbTT2DH1->Visible = b_eco_support;
    m_cbTT2DH3->Visible = b_eco_support;
    m_cbTT2DH5->Visible = b_eco_support;
    m_cbTT3DH1->Visible = b_eco_support;
    m_cbTT3DH3->Visible = b_eco_support;
    m_cbTT3DH5->Visible = b_eco_support;

    if (b_eco_support)
    {
        edtTTDataLen->Text = "1021";
    }
    else
    {
        edtTTDataLen->Text = "339";
    }
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayBtConnectionTestUi(void)
{
    bool b_edr_support = true;
    cbCT2DH1->Visible = b_edr_support;
    cbCT2DH3->Visible = b_edr_support;
    cbCT2DH5->Visible = b_edr_support;
    cbCT3DH1->Visible = b_edr_support;
    cbCT3DH3->Visible = b_edr_support;
    cbCT3DH5->Visible = b_edr_support;

    AnsiString as_SCO_NONEDR_PKT[] =
    {
        "HV1",
        "HV2",
        "HV3",
        "EV3",
        "EV4",
        "EV5"
    };

    cbCTSCOPktType->Clear();
    for (int i=0; i<SCO_PKT_NONEDR_IDX_COUNT; i++)
    {
        cbCTSCOPktType->Items->Add(as_SCO_NONEDR_PKT[i]);
    }

    if (b_edr_support)
    {
        AnsiString as_SCO_EDR_PKT[] =
        {
            "2-EV3",
            "3-EV3",
            "2-EV5",
            "3-EV5"
        };

        for (int i=0; i<SCO_PKT_IDX_COUNT-SCO_PKT_IDX_2EV3; i++)
        {
            cbCTSCOPktType->Items->Add(as_SCO_EDR_PKT[i]);
        }
    }
    cbCTSCOPktType->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void  TfrmBT::CurrentPageReset( void )
{
    switch (m_pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_BT_BLE:
    {
        gbTxorRx->Enabled = true;
        gbSingleorHopping->Enabled = true;
        etChannel->Enabled = true;
        cbPattern->Enabled = true;
        cbTxLevel->Enabled = true;
        cbContinuousTx->Enabled = true;
        edPacketCount->Enabled = true;
        GroupBox25->Enabled = true;
        btnStart->Tag = 0;
    }
    case PAGEIDX_BT_HCI:
    {
        btnHCIStart->Enabled = true;
        btnHCIStart->Tag = 0;
    }
    break;

    case PAGEIDX_BT_RF:
    {
        // btnRFTxStart->Enabled = true;
        // btnRFTxStart->Tag = 0;
        // btnRFRxStart->Enabled = true;
        // btnRFRxStart->Tag = 0;
        btnRFEnterTestMode->Enabled = true;
        btnRFQueryBdAddr->Enabled = true;
        //btnRFChangeLevel->Enabled = false;
    }
    break;

    case PAGEIDX_BT_PKT:
    {
        cbPKTDM1->Enabled = true;
        cbPKTDH1->Enabled = true;
        cbPKTDM3->Enabled = true;
        cbPKTDH3->Enabled = true;
        cbPKTDM5->Enabled = true;

        btnPKTConnectDUT->Enabled = true;
        btnPKTStart->Enabled = true;
        btnPKTStart->Tag = 0;
    }
    break;

    case PAGEIDX_BT_SCT:
    {
        btnSCTStart->Enabled = true;
        btnSCTStart->Tag = 0;
    }
    break;

    case PAGEIDX_BT_TT:
    {
        ReDrawTTFields( DRAM_MASK_TT_BUTTON );

    }
    break;

    case PAGEIDX_BT_CT:
    {
        btnCTLDIRead->Enabled = true;
        btnCTLDIWrite->Enabled = true;
        btnCTEnterPIN->Enabled = true;
        // btnCTConnectSCO->Enabled = true;
        //  btnCTScanStart->Enabled = true;
        //  btnCTScanStart->Tag = 0;
        btnCTInquiryStart->Enabled = true;
        btnCTInquiryStart->Tag = 0;
        // btnCTConnect->Enabled = true;
        // btnCTDisconnect->Enabled = true;
        // btnCTChangeAclPktType->Enabled = true;
        btnCTResetLD->Enabled = true;
        ReDrawCTFields( DRAM_MASK_CT_BUTTON );
    }
    break;
    case PAGEIDX_BT_RXSTD:
    {
        btnEnterTest->Enabled = true;
        btnExitTest->Enabled = true;
        btnResetTest->Enabled = true;
    }
    break;
    case PAGEIDX_BT_BLE_ENHANCED:
    {

    }
    break;
    }
}
//---------------------------------------------------------------------------
void  TfrmBT::CurrentPageLock( void )
{
    switch(m_pctlToolSel->ActivePageIndex)
    {
    case PAGEIDX_BT_BLE:
    {
        gbTxorRx->Enabled = false;
        gbSingleorHopping->Enabled = false;
        etChannel->Enabled = false;
        cbPattern->Enabled = false;
        cbTxLevel->Enabled = false;
        cbContinuousTx->Enabled = false;
        edPacketCount->Enabled = false;
        GroupBox25->Enabled = false;
        btnStart->Tag = 1;
    }
    break;
    case PAGEIDX_BT_HCI:
    {
        btnHCIStart->Enabled = false;
        btnHCIStart->Tag = 1;
    }
    break;

    case PAGEIDX_BT_PKT:
    {
        btnPKTConnectDUT->Enabled = false;
        btnPKTStart->Enabled = false;
        btnPKTStart->Tag = 1;
    }
    break;

    case PAGEIDX_BT_SCT:
    {
        btnSCTStart->Enabled = false;
        btnSCTStart->Tag = 1;
    }
    break;

    case PAGEIDX_BT_TT:
    {
        btnTTScan->Enabled = false;
        btnTTAutoAccept->Enabled = false;
        btnTTConnect->Enabled = false;
        btnTTDisconnect->Enabled = false;
        btnTTChangeACLPacketType->Enabled = false;
        btnTTTxStart->Enabled = false;
        btnTTTxStart->Tag = 1;
        btnTTRxStart->Enabled = false;
        btnTTRxStart->Tag = 1;

    }
    break;

    case PAGEIDX_BT_CT:
    {
        btnCTLDIRead->Enabled = false;
        btnCTLDIWrite->Enabled = false;
        btnCTScan->Enabled = false;
        btnCTAutoAccept->Enabled = false;
        btnCTEnterPIN->Enabled = false;
        btnCTConnectSCO->Enabled = false;
        btnCTDisconnectSCO->Enabled = false;
        // btnCTScanStart->Enabled = false;
        // btnCTScanStart->Tag = 1;
        btnCTInquiryStart->Enabled = false;
        btnCTInquiryStart->Tag = 1;
        btnCTInquiryStart->Enabled = false;
        btnCTConnectACL->Enabled = false;
        btnCTDisconnectACL->Enabled = false;
        btnCTChangeAclPktType->Enabled = false;
        btnCTResetLD->Enabled = false;
    }
    break;
    case PAGEIDX_BT_RXSTD:
    {
        btnEnterTest->Enabled = false;
        btnExitTest->Enabled = false;
        btnResetTest->Enabled = false;
    }
    break;
    case PAGEIDX_BT_BLE_ENHANCED:
    {

    }
    break;
    }
}
//---------------------------------------------------------------------------
bool  TfrmBT::CheckHCIFields( void )
{

    return true;
}
//---------------------------------------------------------------------------
bool  TfrmBT::CheckRFFields( E_CHECK_MASK_RF check_mask )
{
    AnsiString text;

    if( CHECK_MASK_RF_TX == check_mask )
    {
        // pattern
        if( cbRFTxPattern->Text.AnsiCompareIC("0000") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_ALL_ZEROS;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("1111") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_ALL_ONES;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("1010") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_ALTER_BITS;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("11110000") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_ONES_ZEROS;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("pseudo random bit sequence") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_PSEUDO_RANDOM;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("loopback ACL with whitening") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_LOOPBACK_ACL_WITH_WHITENING;
        }
        else if( cbRFTxPattern->Text.AnsiCompareIC("loopback SCO with whitening") == 0 )
        {
            m_sBtRf.e_pattern = BT_TX_LOOPBACK_SCO_WITH_WHITENING;
        }
        // else if( cbRFTxPattern->Text.AnsiCompareIC("loopback ACL without whitening") == 0 )
        // {   m_sBtRf.e_pattern = BT_TX_LOOPBACK_ACL_WITHOUT_WHITENING;
        // }
        else
        {
            m_sBtRf.e_pattern = BT_TX_LOOPBACK_SCO_WITHOUT_WHITENING;
        }
    }
    else
    {
        m_sBtRf.e_pattern = BT_RX_TEST;
    }

    // whiten
    if( cbRFTxWhiten->Checked )
    {
        m_sBtRf.e_whiten = BT_TX_WHITEN_ON;
    }
    else
    {
        m_sBtRf.e_whiten = BT_TX_WHITEN_OFF;
    }

    // freuency type
    if( rbRFTxSingleFreq->Checked )
    {
        m_sBtRf.e_freq_type = BT_FREQ_SINGLE;
    }
    else
    {
        m_sBtRf.e_freq_type = BT_FREQ_HOPPING;
    }

    // packet
    if( cbRFTxType->Text.AnsiCompareIC("NULL") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_NULL;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("POLL") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_POLL;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("FHS") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_FHS;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DM1") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DM1;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DH1") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DH1;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("HV1") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_HV1;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("HV2") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_HV2;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("HV3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_HV3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DV") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DV;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("AUX") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_AUX;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DM3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DM3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DH3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DH3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DM5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DM5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("DH5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_DH5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("EV3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_EV3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("EV4") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_EV4;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("EV5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_EV5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("2-DH1") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_2DH1;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("2-EV3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_2EV3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("2-DH3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_2DH3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("2-EV5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_2EV5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("2-DH5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_2DH5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("3-EV3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_3EV3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("3-DH1") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_3DH1;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("3-DH3") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_3DH3;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("3-EV5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_3EV5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("3-DH5") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_3DH5;
    }
    else if( cbRFTxType->Text.AnsiCompareIC("non-modulated") == 0 )
    {
        m_sBtRf.e_packet_type = BT_RF_PACKET_NON_MODULED;
    }
    // power control
#if 0
}
else // RX
{
    // freuency type
    if( rbRFRxSingleFreq->Checked )
    {
        m_sBtRf.e_freq_type = BT_FREQ_SINGLE;
    }
    else
    {
        m_sBtRf.e_freq_type = BT_FREQ_HOPPING;
    }

    // packet
    if( rbRFRxContRx->Checked )
    {
        m_sBtRf.e_packet_type = BT_TX_PACKET_CONT_RX;
    }
    else
    {
        m_sBtRf.e_packet_type = BT_TX_PACKET_BURST_RX;
    }
}
#endif
text = edtRFTxSignleFreq->Text;
if( !IsValidBTFreq( text, m_sBtRf.uc_freq ) )
{
    edtRFTxSignleFreqCheck(edtRFTxSignleFreq);
    return false;
}
//    text = edtRFTxSignleFreq->Text;      if( !IsValidBTFreq( text, m_sBtRf.uc_rx_freq ) )         {  edtRFRxSignleFreqCheck(edtRFTxSignleFreq);        return false;   }

text = edtRFTxDataLen->Text;
if( !IsValidBTTxDataLength( text, m_sBtRf.us_data_len, Get_RFTxDataMinLen(cbRFTxType->ItemIndex), Get_RFTxDataMaxLen(cbRFTxType->ItemIndex) ) )
{
    edtRFTxDataLenCheck(edtRFTxDataLen);
    return false;
}
text = edtRFTxPollPeriod->Text;
if( !IsValidBTTxPollPeriod( text, m_sBtRf.uc_poll_period ) )
{
    edtRFTxPollPeriodCheck(edtRFTxPollPeriod);
    return false;
}

// power control
if( cbRFTxPowerCtrl->Checked )
{
    m_sBtRf.e_power_ctrl = BT_TX_POWER_CTRL_ON;
}
else
{
    m_sBtRf.e_power_ctrl = BT_TX_POWER_CTRL_OFF;
}
m_sBtRf.b_enable_access_code = cbRFTxAccessCode->Checked;
if(true == m_sBtRf.b_enable_access_code)
{
    for( int i=0; i<(sizeof(m_sBtRf.s_access_code.uc_access_code)/sizeof(m_sBtRf.s_access_code.uc_access_code[0])); i++ )
    {
        text = m_edtRFTxAccessCode[i]->Text;
        if( !IsValidHexBTTxAccessCode( text, m_sBtRf.s_access_code.uc_access_code[i] ) )
        {
            edtRFTxAccessCodeCheck(m_edtRFTxAccessCode[i]);
            return false;
        }
    }
}
return true;
}
//---------------------------------------------------------------------------
void  TfrmBT::ShowHintLabel( TControl *sender, char* hint )
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
void __fastcall TfrmBT::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnHCIFileClick(TObject *Sender)
{
    //char str[512];
    bool ok;

    ok = dlgOpenHCIFile->Execute();
    if (!::CheckFileExist(dlgOpenHCIFile->FileName))
    {
        ok = false;
    }

    if( !ok )
    {
        sbHCI->Panels->Items[0]->Text = (AnsiString) "  Load HCI file fail";
        return;
    }


    m_sBTHCI.hPostMsgDestHandle = this->Handle;
    m_sBTHCI.filename           = dlgOpenHCIFile->FileName;
    m_sBTHCI.log                = m_pHCILog;

    m_BT_HCI_Obj.ConfirmCallback = ::ConfirmCallback_SetupHCIFile;
    m_BT_HCI_Obj.REQ_Read_From_File_Start( m_sBTHCI );

    sbHCI->Panels->Items[0]->Text = (AnsiString) "  Setup HCI file progressing";
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_SetupHCIFile(void)
{
    META_RESULT state = m_BT_HCI_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        stHCIFile->Caption = m_sBTHCI.filename;
        if( rbHCICategory->Checked )
        {
            m_pvHCICategory = m_BT_HCI_Obj.Get_HciCategoryVector();
            DisplayHCIUI( DRAW_MASK_HCI_CATEGORY | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
        }
        else
        {
            m_pvHCIGroup = m_BT_HCI_Obj.Get_HciGroupVector();
            DisplayHCIUI( DRAW_MASK_HCI_GROUP | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
        }
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Setup HCI file successfully";
    }
    break;

    case META_FAILED:
    {
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Setup HCI file fail";
        Application->MessageBox( "Execution Fail : Setup HCI file", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Setup HCI file timeout";
        Application->MessageBox("Execution Timeout : Setup HCI file", "TIMEOUT", MB_OK);
    }
    break;

    case METAAPP_STOP:
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Setup HCI file stop";
        break;
    }

    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayHCIUI( int draw_mask, int category_group_idx, int cmd_idx )
{
    static vector<S_BT_HCI_CATEGORY>:: iterator iter_category;
    static vector<S_BT_HCI_GROUP>:: iterator iter_group;
    vector<S_BT_HCI_COMMAND>:: iterator iter_cmd;
    vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
    S_BT_HCI_CATEGORY category;
    S_BT_HCI_GROUP group;
    S_BT_HCI_COMMAND command;
    S_BT_HCI_PARAMETER parameter;

    if( rbHCICategory->Checked )
    {
        if( draw_mask & DRAW_MASK_HCI_CATEGORY )
        {
            cbHCICategory->Clear();
            // display category
            for( iter_category = m_pvHCICategory->begin(); iter_category != m_pvHCICategory->end(); iter_category++ )
            {
                category = *iter_category;
                cbHCICategory->Items->Add( category.as_category_name );
            }
            iter_category = m_pvHCICategory->begin();
            cbHCICategory->ItemIndex = category_group_idx;
        }

        // display command
        if( draw_mask & DRAW_MASK_HCI_COMMAND )
        {
            for( iter_category = m_pvHCICategory->begin(); iter_category != m_pvHCICategory->end(); iter_category++ )
            {
                category = *iter_category;
                if( category.as_category_name.AnsiCompareIC(cbHCICategory->Text) == 0 )
                {
                    break;
                }
            }

            cbHCICommand->Clear();
            for( iter_cmd = iter_category->v_cmd.begin(); iter_cmd != iter_category->v_cmd.end(); iter_cmd++ )
            {
                command = *iter_cmd;
                cbHCICommand->Items->Add( command.as_cmd_name );
            }
            cbHCICommand->ItemIndex = cmd_idx;
        }

        // display parameter
        if( draw_mask & DRAW_MASK_HCI_PARAMETER )
        {
            // sgSendHCI->EditorMode = true;
            for( iter_cmd = iter_category->v_cmd.begin(); iter_cmd != iter_category->v_cmd.end(); iter_cmd++ )
            {
                command = *iter_cmd;
                if( command.as_cmd_name.AnsiCompareIC(cbHCICommand->Text) == 0 )
                {
                    if( ! m_pvSendHCIPar->empty() )
                    {
                        m_pvSendHCIPar->erase( m_pvSendHCIPar->begin(), m_pvSendHCIPar->end() );
                    }

                    if( ! m_pvReceiveHCIPar->empty() )
                    {
                        m_pvReceiveHCIPar->erase( m_pvReceiveHCIPar->begin(), m_pvReceiveHCIPar->end() );
                    }

                    char str[20];
                    sprintf( str, "%X", iter_cmd->us_opcode );
                    stHCIOpcode->Caption = str;

                    sprintf( str, "%X", iter_cmd->uc_last_event );
                    stHCILastEvent->Caption = str;

                    edtHCITimeout->Text = iter_cmd->ui_ms_timeout;

                    // send parameter
                    if( 0 == iter_cmd->ui_send_num )
                    {
                        sgSendHCI->FixedCols = 3;
                        sgSendHCI->FixedRows = 1;
                        sgSendHCI->ColCount = 4;
                        sgSendHCI->RowCount = 2;
                        sgSendHCI->Cells[HCI_NAME_COL_IDX][1] = "";
                        sgSendHCI->Cells[HCI_BYTE_COL_IDX][1] = "";
                        sgSendHCI->Cells[HCI_VALUE_COL_IDX][1] = "";
                    }
                    else
                    {
                        sgSendHCI->FixedCols = 2;
                        sgSendHCI->FixedRows = 1;
                        sgSendHCI->ColCount = 4;
                        sgSendHCI->RowCount = iter_cmd->ui_send_num+1;
                        for (unsigned int i=0; i<iter_cmd->ui_send_num; i++ )
                        {
                            iter_par = iter_cmd->v_send_par.begin() + i;
                            parameter = *iter_par;
                            sgSendHCI->Cells[HCI_NAME_COL_IDX][i+1] = iter_par->as_name;
                            sgSendHCI->Cells[HCI_BYTE_COL_IDX][i+1] = IntToStr( iter_par->ui_bytes );
                            AnsiString as_value;
                            if( rbHCIDec->Checked )
                            {
                                BTHCIValue_To_AnsiString( iter_par->s_value, as_value );
                                sgSendHCI->Cells[HCI_VALUE_COL_IDX][i+1] = as_value;
                            }
                            else
                            {

                                BTHCIValue_To_Hex_AnsiString( iter_par->s_value, as_value );
                                sgSendHCI->Cells[HCI_VALUE_COL_IDX][i+1] = as_value;
                            }

                            S_BT_HCI_PARAMETER hci_par;
                            // for( int j=0; j<BT_HCI_VALUE_SIZE; j++ )
                            //  {
                            //      parameter.s_value.uc_value[j] = 0;
                            //  }
                            // parameter.s_value.uc_nz_byte = 0;
                            m_pvSendHCIPar->push_back( parameter );
                        }
                    }

                    // receive parameter
                    if( 0 == iter_cmd->ui_receive_num )
                    {
                        sgReceiveHCI->FixedCols = 3;
                        sgReceiveHCI->FixedRows = 1;
                        sgReceiveHCI->ColCount = 4;
                        sgReceiveHCI->RowCount = 2;
                        sgReceiveHCI->Cells[HCI_NAME_COL_IDX][1] = "";
                        sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][1] = "";
                        sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][1] = "";
                    }
                    else
                    {
                        sgReceiveHCI->FixedCols = 2;
                        sgReceiveHCI->FixedRows = 1;
                        sgReceiveHCI->ColCount = 4;
                        // sgReceiveHCI->RowCount = iter_cmd->ui_receive_num+1;
                        int count = 0;
                        for (unsigned int i=0; i<iter_cmd->ui_receive_num; i++)
                        {
                            iter_par = iter_cmd->v_receive_par.begin() + i;
                            parameter = *iter_par;
                            if( iter_par->b_show )
                            {
                                sgReceiveHCI->Cells[HCI_NAME_COL_IDX][count+1] = iter_par->as_name;
                                sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][count+1] = IntToStr( iter_par->ui_bytes );
                                sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][count+1] = IntToStr( 0 );
                                count++;
                            }
                            for( int j=0; j<BT_HCI_VALUE_SIZE; j++ )
                            {
                                parameter.s_value.uc_value[j] = 0;
                            }
                            parameter.s_value.uc_nz_byte = 0;
                            m_pvReceiveHCIPar->push_back( parameter );
                        }
                        sgReceiveHCI->RowCount = count+1;
                    }

                    break;
                }
            }
        }
    }
    else // group
    {
        if( draw_mask & DRAW_MASK_HCI_GROUP )
        {
            // display group
            cbHCIGroup->Clear();
            for( iter_group = m_pvHCIGroup->begin(); iter_group != m_pvHCIGroup->end(); iter_group++ )
            {
                group = *iter_group;
                cbHCIGroup->Items->Add( group.as_group_name );
            }
            iter_group = m_pvHCIGroup->begin();
            cbHCIGroup->ItemIndex = category_group_idx;
        }

        // display command
        if( draw_mask & DRAW_MASK_HCI_COMMAND )
        {
            for( iter_group = m_pvHCIGroup->begin(); iter_group != m_pvHCIGroup->end(); iter_group++ )
            {
                group = *iter_group;
                if( group.as_group_name.AnsiCompareIC(cbHCIGroup->Text) == 0 )
                {
                    break;
                }
            }

            cbHCICommand->Clear();
            for( iter_cmd = iter_group->v_cmd.begin(); iter_cmd != iter_group->v_cmd.end(); iter_cmd++ )
            {
                command = *iter_cmd;
                cbHCICommand->Items->Add( command.as_cmd_name );
            }
            cbHCICommand->ItemIndex = cmd_idx;
        }

        // display parameter
        if( draw_mask & DRAW_MASK_HCI_PARAMETER )
        {
            // sgSendHCI->EditorMode = true;
            for( iter_cmd = iter_group->v_cmd.begin(); iter_cmd != iter_group->v_cmd.end(); iter_cmd++ )
            {
                command = *iter_cmd;
                if( command.as_cmd_name.AnsiCompareIC(cbHCICommand->Text) == 0 )
                {
                    if( ! m_pvSendHCIPar->empty() )
                    {
                        m_pvSendHCIPar->erase( m_pvSendHCIPar->begin(), m_pvSendHCIPar->end() );
                    }

                    if( ! m_pvReceiveHCIPar->empty() )
                    {
                        m_pvReceiveHCIPar->erase( m_pvReceiveHCIPar->begin(), m_pvReceiveHCIPar->end() );
                    }
                    char str[20];
                    sprintf( str, "%X", iter_cmd->us_opcode );
                    stHCIOpcode->Caption = str;

                    sprintf( str, "%X", iter_cmd->uc_last_event );
                    stHCILastEvent->Caption = str;

                    edtHCITimeout->Text = iter_cmd->ui_ms_timeout;

                    // send parameter
                    if( 0 == iter_cmd->ui_send_num )
                    {
                        sgSendHCI->FixedCols = 3;
                        sgSendHCI->FixedRows = 1;
                        sgSendHCI->ColCount  = 4;
                        sgSendHCI->RowCount  = 2;
                        sgSendHCI->Cells[HCI_NAME_COL_IDX][1] = "";
                        sgSendHCI->Cells[HCI_BYTE_COL_IDX][1] = "";
                        sgSendHCI->Cells[2][1] = "";
                    }
                    else
                    {
                        sgSendHCI->FixedCols = 2;
                        sgSendHCI->FixedRows = 1;
                        sgSendHCI->ColCount = 4;
                        sgSendHCI->RowCount = iter_cmd->ui_send_num+1;
                        for (unsigned int i=0; i<iter_cmd->ui_send_num; i++)
                        {
                            iter_par = iter_cmd->v_send_par.begin() + i;
                            parameter = *iter_par;
                            sgSendHCI->Cells[HCI_NAME_COL_IDX][i+1] = iter_par->as_name;
                            sgSendHCI->Cells[HCI_BYTE_COL_IDX][i+1] = IntToStr( iter_par->ui_bytes );
                            AnsiString as_value;
                            if( rbHCIDec->Checked )
                            {
                                BTHCIValue_To_AnsiString( iter_par->s_value, as_value );
                                sgSendHCI->Cells[HCI_VALUE_COL_IDX][i+1] = as_value;
                            }
                            else
                            {
                                BTHCIValue_To_Hex_AnsiString( iter_par->s_value, as_value );
                                sgSendHCI->Cells[HCI_VALUE_COL_IDX][i+1] = as_value;
                            }
                            // for( int j=0; j<BT_HCI_VALUE_SIZE; j++ )
                            // {
                            ////     parameter.s_value.uc_value[j] = 0;
                            // }
                            // parameter.s_value.uc_nz_byte = 0;
                            m_pvSendHCIPar->push_back( parameter );
                        }
                    }

                    // receive parameter
                    if( 0 == iter_cmd->ui_receive_num )
                    {
                        sgReceiveHCI->FixedCols = 3;
                        sgReceiveHCI->FixedRows = 1;
                        sgReceiveHCI->ColCount = 4;
                        sgReceiveHCI->RowCount = 2;
                        sgReceiveHCI->Cells[HCI_NAME_COL_IDX][1] = "";
                        sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][1] = "";
                        sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][1] = "";
                    }
                    else
                    {
                        sgReceiveHCI->FixedCols = 2;
                        sgReceiveHCI->FixedRows = 1;
                        sgReceiveHCI->ColCount = 4;
                        // sgReceiveHCI->RowCount = iter_cmd->ui_receive_num+1;
                        int count = 0;
                        for (unsigned int i=0; i<iter_cmd->ui_receive_num; i++)
                        {
                            iter_par = iter_cmd->v_receive_par.begin() + i;
                            parameter = *iter_par;
                            if( iter_par->b_show )
                            {
                                sgReceiveHCI->Cells[HCI_NAME_COL_IDX][count+1] = iter_par->as_name;
                                sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][count+1] = IntToStr( iter_par->ui_bytes );
                                sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][count+1] = IntToStr( 0 );
                                count++;
                            }

                            for( int j=0; j<BT_HCI_VALUE_SIZE; j++ )
                            {
                                parameter.s_value.uc_value[j] = 0;
                            }
                            parameter.s_value.uc_nz_byte = 0;
                            m_pvReceiveHCIPar->push_back( parameter );
                        }
                        sgReceiveHCI->RowCount = count+1;
                    }

                    break;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void  TfrmBT::DisplayHCIFile( void )
{
    AnsiString as_HCI_file = read_HCI_File("MF_setup.txt", Application->ExeName);
    ReadHCIFile( as_HCI_file );
}
//---------------------------------------------------------------------------
void  TfrmBT::SaveHCIFile( void )
{
    if( stHCIFile->Caption.AnsiCompareIC("") != 0 )
    {
        write_HCI_File( "MF_setup.txt", Application->ExeName, stHCIFile->Caption );
    }
}
//---------------------------------------------------------------------------
void TfrmBT::ReadHCIFile( AnsiString asFileName )
{
    if( ! CheckFileExist(asFileName) )
    {
        return;
    }

    m_sBTHCI.hPostMsgDestHandle = this->Handle;
    m_sBTHCI.filename           = asFileName;
    m_sBTHCI.log                = m_pHCILog;
    // m_BT_HCI_Obj.ConfirmCallback = ::ConfirmCallback_SetupHCIFile;
    // m_BT_HCI_Obj.REQ_Read_From_File_Start( m_sBTHCI );
    bool ok = m_BT_HCI_Obj.REQ_Read_Last_HCI_File_Start( m_sBTHCI );
    if( ok )
    {
        stHCIFile->Caption = m_sBTHCI.filename;
        if( rbHCICategory->Checked )
        {
            m_pvHCICategory = m_BT_HCI_Obj.Get_HciCategoryVector();
            DisplayHCIUI( DRAW_MASK_HCI_CATEGORY | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
        }
        else
        {
            m_pvHCIGroup = m_BT_HCI_Obj.Get_HciGroupVector();
            DisplayHCIUI( DRAW_MASK_HCI_GROUP | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
        }
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Setup HCI file successfully";
    }

}
//--------------------------------------------------------------------------
bool TfrmBT::ComposeHCICommand( S_BT_HCI &hci )
{
    S_BT_HCI_VALUE s_value;
    //unsigned char parameter_len=0;
    int row, byte_idx;
    //int str_idx;
    //int value;
    //  char value_str[256];
    int byte_num;
    int hci_cmd_max_len;
    hci_cmd_max_len = sizeof(hci.s_hci_cmd.m_cmd)/sizeof(hci.s_hci_cmd.m_cmd[0]);
    for( int i=0; i<hci_cmd_max_len; i++ )
        hci.s_hci_cmd.m_cmd[i] = '\0';

    // opcode
    if( ! IsValidHexBTHCIOpcode( stHCIOpcode->Caption, hci.s_hci_cmd.m_opcode ) )
        return false;

    // last event index
    if( ! IsValidHexBTHCIEventIndex( stHCILastEvent->Caption, hci.uc_last_event ) )
        return false;

    // hci.s_hci_cmd.m_cmd[0] = hci.s_hci_cmd.m_opcode & 0x00FF ;
    // hci.s_hci_cmd.m_cmd[1] = (hci.s_hci_cmd.m_opcode & 0xFF00)>>8 ;

    // parameter length
    // for( row=1; row<sgSendHCI->RowCount; row++ )
    // {
    //     parameter_len += sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt();
    // }
    // hci.s_hci_cmd.m_cmd[2] = parameter_len;

    // parameter
    hci.s_hci_cmd.m_len = 0;
    for( row=1; row<sgSendHCI->RowCount; row++ )
    {
        if( sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].AnsiCompareIC("") == 0 )
            return true;
        byte_num = sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt();
        if( rbHCIHex->Checked )
        {
            AnsiString_Hex_To_BTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], s_value );
            //itoa( value, value_str, 10 );
        }
        else
        {
            AnsiString_To_BTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], s_value );
        }
        // for( str_idx=0; str_idx<hci_cmd_max_len; str_idx++ )
        // {
        //     if(  0 == value_str[str_idx] )
        //     {
        //        value_str_len = str_idx;
        //        break;
        //     }
        // }

        for( byte_idx=0; byte_idx<byte_num; byte_idx++ )
        {
            if( byte_idx < s_value.uc_nz_byte )
            {
                hci.s_hci_cmd.m_cmd[hci.s_hci_cmd.m_len] = s_value.uc_value[byte_idx];
            }
            else
            {
                hci.s_hci_cmd.m_cmd[hci.s_hci_cmd.m_len] = 0;
            }
            hci.s_hci_cmd.m_len++;
        }
    }

    return true;
}
//--------------------------------------------------------------------------
bool  TfrmBT::DeComposeHCIEvent( BT_HCI_EVENT &event )
{
    if( sgReceiveHCI->Cells[HCI_NAME_COL_IDX][1].AnsiCompareIC("") == 0 )  // no event parameter
        return true;

    static vector<S_BT_HCI_CATEGORY>:: iterator iter_category;
    static vector<S_BT_HCI_GROUP>:: iterator iter_group;
    vector<S_BT_HCI_COMMAND>:: iterator iter_cmd;
    vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
    S_BT_HCI_PARAMETER sParameter;
    // int row;
//     vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
    int idx = 0;


    if( ! m_pvReceiveHCIPar->empty() )
    {
        m_pvReceiveHCIPar->erase(m_pvReceiveHCIPar->begin(), m_pvReceiveHCIPar->end() );
    }


    // S_BT_HCI_CATEGORY category;
    // S_BT_HCI_GROUP group;
    // S_BT_HCI_COMMAND command;
    // S_BT_HCI_PARAMETER parameter;

    if( rbHCICategory->Checked )
    {
        for( iter_category = m_pvHCICategory->begin(); iter_category != m_pvHCICategory->end(); iter_category++ )
        {
            AnsiString as_category_name = iter_category->as_category_name.Trim();
            AnsiString as_text = cbHCICategory->Text.Trim();
            if( as_category_name.AnsiCompareIC(as_text) == 0 )
                break;
        }

        for( iter_cmd = iter_category->v_cmd.begin(); iter_cmd != iter_category->v_cmd.end(); iter_cmd++ )
        {
            AnsiString as_cmd_name = iter_cmd->as_cmd_name.Trim();
            AnsiString as_text = cbHCICommand->Text.Trim();
            if( as_cmd_name.AnsiCompareIC(as_text) == 0 )
                break;

        }

        for (unsigned int i=0; i<iter_cmd->ui_receive_num; i++ )
        {
            iter_par = iter_cmd->v_receive_par.begin() + i;
            sParameter = *iter_par;
            for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
            {
                sParameter.s_value.uc_value[i] = 0;
            }
            sParameter.s_value.uc_nz_byte = 0;
            for (unsigned int i=0; i<sParameter.ui_bytes; i++)
            {
                sParameter.s_value.uc_value[i] = (char) event.m_parms[idx];
                idx++;
                if( sParameter.s_value.uc_value[i] != 0 )
                    sParameter.s_value.uc_nz_byte++;
            }
            m_pvReceiveHCIPar->push_back( sParameter );
        }
    }
    else
    {
        for( iter_group = m_pvHCIGroup->begin(); iter_group != m_pvHCIGroup->end(); iter_group++ )
        {
            AnsiString as_group_name = iter_group->as_group_name.Trim();
            AnsiString as_text = cbHCIGroup->Text.Trim();
            if( as_group_name.AnsiCompareIC(as_text) == 0 )
                break;
        }

        for( iter_cmd = iter_group->v_cmd.begin(); iter_cmd != iter_group->v_cmd.end(); iter_cmd++ )
        {
            AnsiString as_cmd_name = iter_cmd->as_cmd_name.Trim();
            AnsiString as_text = cbHCICommand->Text.Trim();
            if( as_cmd_name.AnsiCompareIC(as_text) == 0 )
                break;

        }

        for (unsigned int i=0; i<iter_cmd->ui_receive_num; i++ )
        {
            iter_par = iter_cmd->v_receive_par.begin() + i;
            sParameter = *iter_par;
            for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
            {
                sParameter.s_value.uc_value[i] = 0;
            }
            sParameter.s_value.uc_nz_byte = 0;
            for (unsigned int i=0; i<sParameter.ui_bytes; i++ )
            {
                sParameter.s_value.uc_value[i] = (char) event.m_parms[idx];
                idx++;
                if( sParameter.s_value.uc_value[i] != 0 )
                    sParameter.s_value.uc_nz_byte++;
            }
            m_pvReceiveHCIPar->push_back( sParameter );
        }
    }
#if 0
    for( row=1; row<sgReceiveHCI->RowCount; row++ )
    {
        sParameter.as_name  = sgReceiveHCI->Cells[HCI_NAME_COL_IDX][row];
        sParameter.ui_bytes = sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt();
        for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
        {
            sParameter.s_value.uc_value[i] = 0;
        }
        sParameter.s_value.uc_nz_byte = 0;
        for( int i=0; i<sParameter.ui_bytes; i++ )
        {
            sParameter.s_value.uc_value[i] = (char) event.m_parms[HCI_EVENT_PARAMETER_START_IDX+idx];
            idx++;
            if( sParameter.s_value.uc_value[i] != 0 )
                sParameter.s_value.uc_nz_byte++;
        }

        m_pvReceiveHCIPar->push_back( sParameter );
    }
#endif
    return true;
}
//--------------------------------------------------------------------------
void  TfrmBT::ReDrawHCIFields( E_DRAM_MASK_HCI draw_mask )
{
    vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
    if( draw_mask & DRAM_MASK_HCI_SEND )
    {
        for( int row=1; row<sgSendHCI->RowCount; row++ )
        {
            for( iter_par = m_pvSendHCIPar->begin(); iter_par != m_pvSendHCIPar->end(); iter_par++ )
            {
                AnsiString as_name = sgSendHCI->Cells[HCI_NAME_COL_IDX][row];
                if( iter_par->as_name.AnsiCompareIC( as_name ) == 0 )
                {
                    AnsiString as_hci_value;
                    if( rbHCIDec->Checked )
                    {
                        BTHCIValue_To_AnsiString( iter_par->s_value, as_hci_value );
                    }
                    else
                    {
                        BTHCIValue_To_Hex_AnsiString( iter_par->s_value, as_hci_value );
                    }
                    sgSendHCI->Cells[HCI_VALUE_COL_IDX][row] = as_hci_value;
                    break;
                }
            }
        }
    }

    if( draw_mask & DRAM_MASK_HCI_RECEIVE )
    {


        AnsiString ansi_str;
//        iter_par = m_sRxEvent.v_par.begin();

        for(int row=1; row<sgReceiveHCI->RowCount; row++ )
        {
            for( iter_par = m_pvReceiveHCIPar->begin(); iter_par != m_pvReceiveHCIPar->end(); iter_par++ )
            {
                AnsiString as_name = sgReceiveHCI->Cells[HCI_NAME_COL_IDX][row];
                if( iter_par->as_name.AnsiCompareIC( as_name ) == 0 )
                {
                    AnsiString as_hci_value;
                    if( rbHCIDec->Checked )
                    {
                        BTHCIValue_To_AnsiString( iter_par->s_value, as_hci_value );
                    }
                    else
                    {
                        BTHCIValue_To_Hex_AnsiString( iter_par->s_value, as_hci_value );
                    }
                    sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][row] = as_hci_value;
                    break;
                }
            }
            // BTHCIValue_To_AnsiString( iter_par->s_value, ansi_str );
            // sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][row] = ansi_str;
            // iter_par++;
        }

    }

}
//--------------------------------------------------------------------------
void TfrmBT::FillHCIResult( void )
{

    for(int i=0; i<m_pHCILog->Count; i++ )
    {
        AnsiString as = m_pHCILog->Strings[i];
        memHCIResult->Lines->Add( as );
    }
    m_pHCILog->Clear();

}
//---------------------------------------------------------------------------
void TfrmBT::FillBLEHCIResult( void )
{

    for(int i=0; i<m_pBLELog->Count; i++ )
    {
        AnsiString as = m_pBLELog->Strings[i];
        reBLEResult->Lines->Add( as );
    }
    m_pBLELog->Clear();

}

//---------------------------------------------------------------------------
void TfrmBT::FillBLEEnhancedHCIResult( void )
{

    for(int i=0; i<m_pBLELog->Count; i++ )
    {
        AnsiString as = m_pBLELog->Strings[i];
        reBLEEnhancedResult->Lines->Add( as );
    }
    m_pBLELog->Clear();

}
//---------------------------------------------------------------------------
void TfrmBT::FillBLENormalAdvertiseHCIResult(void)
{
    for(int i=0; i<m_pBLELog->Count; i++ )
    {
        AnsiString as = m_pBLELog->Strings[i];
        reBLEAdvertiseResult->Lines->Add( as );
    }
    m_pBLELog->Clear();
}
//---------------------------------------------------------------------------
void TfrmBT::FillBLENormalScanHCIResult(void)
{
    for(int i=0; i<m_pBLELog->Count; i++ )
    {
        AnsiString as = m_pBLELog->Strings[i];
        reBLEScanResult->Lines->Add( as );
    }
    m_pBLELog->Clear();
}
//---------------------------------------------------------------------------
void TfrmBT::FillBLENormalInitiateHCIResult(void)
{
    for(int i=0; i<m_pBLELog->Count; i++ )
    {
        AnsiString as = m_pBLELog->Strings[i];
        reBLEInitiateResult->Lines->Add( as );
    }
    m_pBLELog->Clear();
}
//---------------------------------------------------------------------------
void TfrmBT::FillRXSTDHCIResult(void)
{
    for(int i=0; i<m_pSTDLog->Count; i++ )
    {
        AnsiString as = m_pSTDLog->Strings[i];
        reRXSTD->Lines->Add( as );
    }
    m_pSTDLog->Clear();
}
//--------------------------------------------------------------------------
void TfrmBT::FillRFResult( void )
{

    for(int i=0; i<m_pRFLog->Count; i++ )
    {
        AnsiString as = m_pRFLog->Strings[i];
        memRFResult->Lines->Add( as );
    }
    m_pRFLog->Clear();

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmBT::DisplayPKTBDAddress( E_BT_PACKET_DEVICE_T obj )
{
    AnsiString as_bd_addr;

    if( BT_PACKET_TESTER == obj )
    {

        BDAddress_To_Hex_AnsiString( m_BT_PKT_Obj.Get_TesterBDAddress(), as_bd_addr );
        stPKTTesterBDAddr->Caption = as_bd_addr;
    }
    else
    {
        BDAddress_To_Hex_AnsiString( m_BT_PKT_Obj.Get_DUTBDAddress(), as_bd_addr );
        stPKTDUTBDAddr->Caption = as_bd_addr;
    }
}
//--------------------------------------------------------------------------
void TfrmBT::FillPKTResult( void )
{

    for(int i=0; i<m_pPKTLog->Count; i++ )
    {
        AnsiString as = m_pPKTLog->Strings[i];
        memPKTResult->Lines->Add( as );
    }
    m_pPKTLog->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbHCIGroupChange(TObject *Sender)
{
    DisplayHCIUI( DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, cbHCIGroup->ItemIndex, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbHCICommandChange(TObject *Sender)
{
    DisplayHCIUI( DRAW_MASK_HCI_PARAMETER, cbHCIGroup->ItemIndex, cbHCICommand->ItemIndex );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnHCISendClick(TObject *Sender)
{
    if( ! CheckSendHCIValue() )
    {
        return;
    }

    m_sBTHCI.hPostMsgDestHandle = this->Handle;
    m_sBTHCI.filename           = stHCIFile->Caption;
    m_sBTHCI.log                = m_pHCILog;
    m_sBTHCI.ui_ms_timeout      = edtHCITimeout->Text.ToInt();
    ComposeHCICommand( m_sBTHCI );

    CurrentPageLock();
    sbHCI->Panels->Items[0]->Text = (AnsiString) "  Send HCI command progressing";
    m_BT_HCI_Obj.ConfirmCallback  = ::ConfirmCallback_HCI;
    m_BT_HCI_Obj.REQ_Start( m_sBTHCI );
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_HCI(void)
{
    META_RESULT state = m_BT_HCI_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sHCIEventFmt = m_BT_HCI_Obj.Get_HCIEvent();
        DeComposeHCIEvent(m_sHCIEventFmt);
        ReDrawHCIFields(DRAM_MASK_HCI_RECEIVE);
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Send HCI command successfully";
    }
    break;

    case META_FAILED:
    {
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Send HCI command fail";
        Application->MessageBox( "Execution Fail : Send HCI command", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop(false);
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Send HCI command timeout";
        Application->MessageBox( "Execution Timeout : Send HCI command", "TIMEOUT", MB_OK );
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Send HCI command stop";
    }
    break;
    }

    CurrentPageReset();
}
//===========================================================================
/////////////////////////////////  RF test  /////////////////////////////////
//===========================================================================
void TfrmBT::ReDrawRFFields( E_DRAM_MASK_RF draw_mask )
{
    if( draw_mask & DRAM_MASK_RF_BD_ADDRESS )
    {
        AnsiString as_bd_addr;
        BDAddress_To_Hex_Colon_AnsiString( m_sRFBdAddr, as_bd_addr );
        edtRFBDAddress->Text = as_bd_addr;
    }


    if( draw_mask & DRAM_MASK_RF_ACCESS_CODE )
    {
        char str[20];

        // access code
        for( int i=0; i<(sizeof(m_sBtRf.s_access_code.uc_access_code)/sizeof(m_sBtRf.s_access_code.uc_access_code[0])); i++ )
        {
            sprintf( str, "%X", m_sBtRf.s_access_code.uc_access_code[i] );
            m_edtRFTxAccessCode[i]->Text = str;
        }
    }

    if( draw_mask & DRAM_MASK_RF_TX_OTHERS )
    {
        edtRFTxSignleFreq->Text = IntToStr( m_sBtRf.uc_freq );
        edtRFTxDataLen->Text    = IntToStr( m_sBtRf.us_data_len );
        edtRFTxPollPeriod->Text = IntToStr( m_sBtRf.uc_poll_period );
        edtRFTxLevel->Text      = IntToStr( m_sBtRf.uc_pcl );
    }

    // if( draw_mask & DRAM_MASK_RF_RX )
    // {
    //     edtRFRxSignleFreq->Text = IntToStr( m_sBtRf.uc_freq );
    // }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFTxSignleFreqCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~255 "
    };

    text = edit->Text;
    if( !IsValidBTFreq( text, uc_data ) )
    {
        edit->Text = 78;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBtRf.uc_freq = uc_data;
}
//-------------------------------------------------------------------------
unsigned short TfrmBT::Get_RFTxDataDefaultLen(int index)
{
    unsigned short us_default_len[] =
    {
        0,// NULL
        0,// POLL
        0,// FHS
        17,// DM1
        27,// DH1
        10,// HV1
        20,// HV2
        30,// HV3
        19,// DV
        10,// AUX
        121,// DM3
        183,// DH3
        224,// DM5
        339,// DH5
        30,// EV3
        120,// EV4
        180,//EV5
        54,// 2-DH1
        60,// 2-EV3
        367,// 2-DH3
        360,// 2-EV5
        679,// 2-DH5
        90,// 3-EV3
        83,// 3-DH1
        552,// 3-DH3
        540,// 3-EV5
        1021, // 3-DH5
        0  //non-modulated
    };

    return us_default_len[index];
}
//--------------------------------------------------------------------------
unsigned short TfrmBT::Get_RFTxDataMinLen( int index )
{
    unsigned short us_min_len[] =
    {
        0,// NULL
        0,// POLL
        0,// FHS
        0,// DM1
        0,// DH1
        10,// HV1
        20,// HV2
        30,// HV3
        10,// DV
        0,// AUX
        0,// DM3
        0,// DH3
        0,// DM5
        0,// DH5
        1,// EV3
        1,// EV4
        1,//EV5
        0,// 2-DH1
        1,// 2-EV3
        0,// 2-DH3
        1,// 2-EV5
        0,// 2-DH5
        1,// 3-EV3
        0,// 3-DH1
        0,// 3-DH3
        1,// 3-EV5
        0,// 3-DH5
        0  //non-modulated
    };

    return us_min_len[index];
}
//--------------------------------------------------------------------------
unsigned short TfrmBT::Get_RFTxDataMaxLen( int index )
{
    unsigned short us_max_len[] =
    {
        0,// NULL
        0,// POLL
        0,// FHS
        17,// DM1
        27,// DH1
        10,// HV1
        20,// HV2
        30,// HV3
        19,// DV
        255,// AUX
        121,// DM3
        183,// DH3
        224,// DM5
        339,// DH5
        30,// EV3
        120,// EV4
        180,//EV5
        54,// 2-DH1
        60,// 2-EV3
        367,// 2-DH3
        360,// 2-EV5
        679,// 2-DH5
        90,// 3-EV3
        83,// 3-DH1
        552,// 3-DH3
        540,// 3-EV5
        1021, // 3-DH5
        0  //non-modulated
    };

    return us_max_len[index];
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayRFDefaultDataLen( void )
{
    unsigned short len = Get_RFTxDataDefaultLen(cbRFTxType->ItemIndex);
    edtRFTxDataLen->Text = IntToStr( len );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFTxDataLenCheck(TObject *Sender)
{
    unsigned short  us_min_len = Get_RFTxDataMinLen(cbRFTxType->ItemIndex);
    unsigned short  us_max_len = Get_RFTxDataMaxLen(cbRFTxType->ItemIndex);
    unsigned short  us_data;
    AnsiString  text;
    AnsiString  as_hint;
    TEdit *edit = (TEdit*)Sender;
    if( us_min_len != us_max_len )
    {
        as_hint = " value should be " + IntToStr( us_min_len ) +"~" + IntToStr( us_max_len );
    }
    else
    {
        as_hint = " value should be " + IntToStr( us_min_len );
    }

    text = edit->Text;
    if( !IsValidBTTxDataLength( text, us_data, Get_RFTxDataMinLen(cbRFTxType->ItemIndex), Get_RFTxDataMaxLen(cbRFTxType->ItemIndex) ) )
    {
        edit->Text = Get_RFTxDataDefaultLen(cbRFTxType->ItemIndex);
        ShowHintLabel( edit, as_hint.c_str() );
        edit->SetFocus();
        return;
    }

    m_sBtRf.us_data_len = us_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFTxPollPeriodCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~255 "
    };

    text = edit->Text;
    if( !IsValidBTTxPollPeriod( text, uc_data ) )
    {
        edit->Text = 0;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBtRf.uc_poll_period = uc_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFTxLevelCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~7 "
    };

    text = edit->Text;
    if( !IsValidBTTxPcl( text, uc_data ) )
    {
        edit->Text = 6;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBtRf.uc_pcl = uc_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFTxAccessCodeCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~255 "
    };

    text = edit->Text;
    if( !IsValidHexBTTxAccessCode( text, uc_data ) )
    {
        edit->Text = 0;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBtRf.s_access_code.uc_access_code[edit->Tag] = uc_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFTxStartClick(TObject *Sender)
{
    if( rbRFTx->Checked )
    {
        if( ! CheckRFFields( CHECK_MASK_RF_TX ) )
        {
            sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF TX fail";
            Application->MessageBox( "Execution Failure : BT RF TX", "FAILURE", MB_OK );
            return;
        }
    }
    else
    {
        if( ! CheckRFFields( CHECK_MASK_RF_RX ) )
        {
            sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF RX fail";
            Application->MessageBox( "Execution Failure : BT RF RX", "FAILURE", MB_OK );
            return;
        }
    }

    m_sBtRf.hPostMsgDestHandle = this->Handle;
    m_sBtRf.log                = m_pRFLog;
    m_sBtRf.e_test_type        = BT_TX;

    CurrentPageLock();

    if( rbRFTx->Checked )
    {
        sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF TX progressing";
        m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_RFTX;
    }
    else
    {
        sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF RX progressing";
        m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_RFRX;
    }

    if( rbRFTx->Checked &&
            (BT_RF_TX_NON_MODULED_IDX == cbRFTxType->ItemIndex && 1 == btnRFTxStart->Tag) ||
            (BT_RF_TX_NON_MODULED_IDX != cbRFTxType->ItemIndex && 2 == btnRFTxStart->Tag))
    {
        m_BT_RF_Obj.REQ_Start( m_sBtRf, true );
    }

    else
    {
        m_BT_RF_Obj.REQ_Start( m_sBtRf, false );
    }

    if(BT_RF_TX_NON_MODULED_IDX == cbRFTxType->ItemIndex)
    {
        btnRFTxStart->Tag = 2;
    }
    else
    {
        btnRFTxStart->Tag = 1;
    }
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_RFTX(void)
{
    META_RESULT state = m_BT_RF_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF TX progressing";
        btnRFChangeLevel->Enabled = true;
    }
    break;

    case META_FAILED:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF TX fail";
        Application->MessageBox( "Execution Failure : BT RF TX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( true );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF TX timeout";
        Application->MessageBox( "Execution Timeout : BT RF TX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF TX stop";
        CurrentPageReset();
    }
    break;
    }
}
//--------------------------------------------------------------------------
void TfrmBT::SyncLAPAndAccessCode( void )
{
    unsigned int syncHi;
    unsigned int syncLo;
    unsigned int a_lap = 0;
    //char lap_string[9];
    //unsigned char hex_string[3];
    char sync_string[128];

    // transform LAP string to 32bit value
    //GetDlgItemText(IDC_LAP, lap_string, 9);
    // AnsiString as_lap;
    // for( int i=BD_ADDRESS_LAP_LEN-1; i>=0; i-- )
    // {   as_lap += m_edtRFLAP[i]->Text;
    // }
    //  AnsiString_Hex_To_UnsignedInt( as_lap, a_lap );
    // for(int i = 0; i < 6; i++)
    //    lap_string[i] = lap_string[i+2];
    // ascii_hex_string_2_hex_string((unsigned char *)lap_string, hex_string, 6);
    // a_lap = hex_string[0] << 16;
    /// a_lap |= hex_string[1] << 8;
    //a_lap |= hex_string[2];

    // 32 bit LAP --> 64 bit Access Word

    unsigned int a_lap1 = m_sRFBdAddr.uc_BD_Addr[0] ;
    unsigned int a_lap2 = m_sRFBdAddr.uc_BD_Addr[1]  ;
    unsigned int a_lap3 = m_sRFBdAddr.uc_BD_Addr[2] ;

    a_lap =  (a_lap1&0xFF)|((a_lap2&0xFF)<<8)|((a_lap3&0xFF)<<16);

    Build_Sync_Word(a_lap, &syncHi, &syncLo);

    // print 64 bit Access Word
    sprintf(sync_string, "%08X%08X", syncHi, syncLo);

    // SetDlgItemText(IDC_SYNC, sync_string);
    m_sBtRf.s_access_code.uc_access_code[7] = (syncHi>>24) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[6] = (syncHi>>16) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[5] = (syncHi>>8 ) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[4] = (syncHi    ) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[3] = (syncLo>>24) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[2] = (syncLo>>16) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[1] = (syncLo>>8 ) & 0x000000FF;
    m_sBtRf.s_access_code.uc_access_code[0] = (syncLo    ) & 0x000000FF;
}
//--------------------------------------------------------------------------
// 32 bit LAP --> 64 bit Access Word
void TfrmBT::Build_Sync_Word(const unsigned int a_lap, unsigned int* pSyncHi, unsigned int* pSyncLo)
{
#if 0
    unsigned int BCHgeneratorHi = 026053423665L;
    unsigned int BCHgeneratorLo = (1L << 29);
    const unsigned int p_PNsequenceHi = 0x83848D96L;
    const unsigned int p_PNsequenceLo = 0xBBCC54FCL;
    const unsigned int B_BitsA23_0 = 0x2C000000U;
    const unsigned int B_BitsA23_1 = 0x13000000U;

    unsigned int x_infoBits;
    unsigned int x_encodeBits;
    unsigned int regHi, regLo;
    unsigned int count;

#define BIT23 0x00800000L
#define BIT31 0x80000000UL

    /* V0.8 p126                                                                */
    /* Step 1   Format the 30 information bits to encode  LAP + Barker Sequence */
    /*          x(D) = a(D) +D^24 B_A23(D)                                      */

    if (a_lap&BIT23)                       /* Toggle bits 5:0                */
        x_infoBits = a_lap | B_BitsA23_1;
    else
        x_infoBits = a_lap | B_BitsA23_0;

    /* Step 2   Add (Exor) the information covering part of the PN sequence     */
    /*          x~(D) = x(D) + p34 + p35D + ... + p63D^29                       */

    x_encodeBits =  (x_infoBits ^ (p_PNsequenceHi>>2)) << 2;

    /* Step 3   Generate parity bits of BCH(64,30)                              */
    /*          c~(D) = D^34 x~(D) mod g(D)                                     */

    /* Initialise                                                               */
    regHi = x_encodeBits;
    regLo = 0;

    /* Generate remainder      64 bit dividend, 35 bit divisor                  */
    count = 0;
    while (++count <= 64 - 35 + 1)      /* Reduce/Shift the remaining 30 bits*/
    {
        if (regHi&BIT31)                 /* Reduce                            */
        {
            regHi ^= BCHgeneratorHi;
            regLo ^= BCHgeneratorLo;
        }
        regHi = (regHi<<1) + (regLo>>31);/*Shift full register                */
        regLo <<= 1;
    }

    /* Step 4   Create the BCH codeword                                         */
    /*          s~(D) = D^34 x~(D) + c~(D)    Note: Exor Addition               */
    /* Step 5   Add the PN Sequence                                             */
    /*          s(D) = s(D) + p(D)            Note: Exor Addition               */

    *pSyncLo = ((regHi<<2)  ^ (regLo>>30))    ^ p_PNsequenceLo;
    *pSyncHi = ((regHi>>30) ^ (x_encodeBits)) ^ p_PNsequenceHi;

    /* Hardware ? */
    /* Step 6   Prepend and append the (DC-free preamble and trailer            */
    /*          y(D = F_c0(D) + D^4 s(D) + D^68 F_a23(D)                        */

#endif

    unsigned int  g_BCHgeneratorHi = ((unsigned int) SYNC_BCHgenHi), /*Faster if in register     */
                  g_BCHgeneratorLo = ((unsigned int) SYNC_BCHgenLo);
    const unsigned int p_PNsequenceHi = ((unsigned int) SYNC_PNseqHi),
                       p_PNsequenceLo = ((unsigned int) SYNC_PNseqLo);
    const unsigned int B_BitsA23_0 = 0x2C000000U, B_BitsA23_1 = 0x13000000U;
    unsigned int x_infoBits;
    unsigned int x_encodeBits;
    unsigned int regHi, regLo;
    unsigned int count;

    /* V0.8 p126                                                                */
    /* Step 1   Format the 30 information bits to encode  LAP + Barker Sequence */
    /*          x(D) = a(D) +D^24 B_A23(D)                                      */

    if (a_lap&BIT23)                       /* Toggle bits 5:0                */
        x_infoBits = a_lap | B_BitsA23_1;
    else
        x_infoBits = a_lap | B_BitsA23_0;

    /* Step 2   Add (Exor) the information covering part of the PN sequence     */
    /*          x~(D) = x(D) + p34 + p35D + ... + p63D^29                       */

    x_encodeBits =  (x_infoBits ^ (p_PNsequenceHi>>2)) << 2;

    /* Step 3   Generate parity bits of BCH(64,30)                              */
    /*          c~(D) = D^34 x~(D) mod g(D)                                     */

    /* Initialise                                                               */
    regHi = x_encodeBits;
    regLo = 0;

    /* Generate remainder      64 bit dividend, 35 bit divisor                  */
    count = 0;
    while (++count <= 64 - 35 + 1)      /* Reduce/Shift the remaining 30 bits*/
    {
        if (regHi&BIT31)                 /* Reduce                            */
        {
            regHi ^= g_BCHgeneratorHi;
            regLo ^= g_BCHgeneratorLo;
        }
        regHi = (regHi<<1) + (regLo>>31);/*Shift full register                */
        regLo <<= 1;
    }

    /* Step 4   Create the BCH codeword                                         */
    /*          s~(D) = D^34 x~(D) + c~(D)    Note: Exor Addition               */
    /* Step 5   Add the PN Sequence                                             */
    /*          s(D) = s(D) + p(D)            Note: Exor Addition               */

    *pSyncLo = ((regHi<<2)  ^ (regLo>>30))    ^ p_PNsequenceLo;
    *pSyncHi = ((regHi>>30) ^ (x_encodeBits)) ^ p_PNsequenceHi;

    /* Hardware ? */
    /* Step 6   Prepend and append the (DC-free preamble and trailer            */
    /*          y(D = F_c0(D) + D^4 s(D) + D^68 F_a23(D)                        */


}
//---------------------------------------------------------------------------
//void __fastcall TfrmBT::edtRFTxLapCheck(TObject *Sender)
//{
//    unsigned int  ui_data;
//    AnsiString  text;
//    TEdit *edit = (TEdit*)Sender;
//    char  hint[] =
//    {   " value should be 0~4294967296 "
//    };
//
//    text = edit->Text;
//    if( !IsValidHexBTLAP( text, ui_data ) )
//    {
//        edit->Text = 0;
//        ShowHintLabel( edit, hint );
//        edit->SetFocus();
//        return;
//    }
//
//    m_sBtRf.ui_lap = ui_data;
//    SyncLAPAndAccessCode();
//    ReDrawRFFields( DRAM_MASK_RF_ACCESS_CODE );
//}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFRxStartClick(TObject *Sender)
{
    if( ! CheckRFFields( CHECK_MASK_RF_RX ) )
    {
        sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF RX fail";
        Application->MessageBox( "Execution Failure : BT RF RX", "FAILURE", MB_OK );
        return;
    }

    m_sBtRf.hPostMsgDestHandle = this->Handle;
    m_sBtRf.log                = m_pRFLog;
    m_sBtRf.e_test_type        = BT_RX;

    CurrentPageLock();
    sbRF->Panels->Items[0]->Text = (AnsiString) "  BT RF RX progressing";
    m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_RFRX;
    m_BT_RF_Obj.REQ_Start( m_sBtRf );
}
//---------------------------------------------------------------------------
void  TfrmBT::ConfirmCallback_RFRX(void)
{
    META_RESULT state = m_BT_RF_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF RX progressing";
    }
    break;

    case META_FAILED:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF RX fail";
        Application->MessageBox( "Execution Failure : BT RF RX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( true );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF RX timeout";
        Application->MessageBox( "Execution Timeout : BT RF RX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  BT RF RX stop";
        CurrentPageReset();
    }
    break;
    }

}
//--------------------------------------------------------------------------
void __fastcall TfrmBT::rbHCICategoryClick(TObject *Sender)
{
    cbHCICategory->Enabled = true;
    cbHCIGroup->Enabled    = false;
    m_pvHCICategory = m_BT_HCI_Obj.Get_HciCategoryVector();
    DisplayHCIUI( DRAW_MASK_HCI_CATEGORY | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::rbHCIGroupClick(TObject *Sender)
{
    cbHCICategory->Enabled = false;
    cbHCIGroup->Enabled    = true;
    m_pvHCIGroup = m_BT_HCI_Obj.Get_HciGroupVector();
    DisplayHCIUI( DRAW_MASK_HCI_GROUP | DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, 0, 0 );
}
//---------------------------------------------------------------------------
bool TfrmBT::GetCurrentCOMPort(int &nComPortCount)
{
    int nRet = SP_S_DONE;
    SP_COM_FILTER_LIST_S ComFilter;
    nComPortCount = MAX_SUPPORT_COM_NUM;
    char* ppFilter[2] = {0};

    memset(&ComFilter,0,sizeof(ComFilter));
    ComFilter.m_eType = SP_WHITE_LIST;
    ComFilter.m_uCount = 0;
    ComFilter.m_ppFilterID = ppFilter;

    SP_COM_PROPERTY_S * pCOMPorperty = new SP_COM_PROPERTY_S[nComPortCount];
    if (pCOMPorperty == NULL)
    {
        return false;
    }
    if (nRet != SP_GetCurrentCOMPortInfoWithFilter(&ComFilter, NULL, false, pCOMPorperty, &nComPortCount))
    {
        delete[] pCOMPorperty;
        pCOMPorperty = NULL;
        return false;
    }

    for(int i = 0; i < nComPortCount; i++)
    {
        m_usComPortArray[i] = pCOMPorperty[i].m_uNumber;
    }
    delete[] pCOMPorperty;
    pCOMPorperty = NULL;
    return true;

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::FormShow(TObject *Sender)
{
    if (m_bFirstFormShow)
    {
        m_bFirstFormShow = false;
        m_META_HANDLE_Obj.REQ_AllocateSecondHandle_Start();

        int nComPortCount = 0;
        if (!GetCurrentCOMPort(nComPortCount))
        {
            Application->MessageBox("Enumerate COM port failed", "FAIL", MB_OK);
            return;
        }
        for (int i=0; i<nComPortCount; i++)
        {
            cbPKTCOM->Items->Add((AnsiString) "COM" + IntToStr( m_usComPortArray[i]));
            m_cbMTBT2COM->Items->Add((AnsiString) "COM" + IntToStr( m_usComPortArray[i]));
        }
        cbPKTCOM->ItemIndex = 0;
        m_cbMTBT2COM->ItemIndex = 0;

        // string grid
        sgSendHCI->Cells[HCI_NAME_COL_IDX][0] = "Send Parameter";
        sgSendHCI->Cells[HCI_BYTE_COL_IDX][0] = "Bytes";
        if( rbHCIDec->Checked )
        {
            sgSendHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value";
        }
        else
        {
            sgSendHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value (Hex)";
        }

        sgReceiveHCI->Cells[HCI_NAME_COL_IDX][0] = "Receive Parameter";
        sgReceiveHCI->Cells[HCI_BYTE_COL_IDX][0] = "Bytes";
        if( rbHCIDec->Checked )
        {
            sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value";
        }
        else
        {
            sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value (Hex)";
        }

        // HCI file

        DisplayHCIFile();

        // RF
        DisplayRFDefaultDataLen();

        // module test
        ReloadScriptFiles();
        UpdateProcessGroup();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::glbTimerTimer(TObject *Sender)
{
    glbTimer->Enabled = false;
    glbTimer->Interval = 1000;
    glbTimer->Enabled = true;


}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnPKTConnectDUTClick(TObject *Sender)
{
#if 0
    shpPKTConnect->Brush->Color = clRed;
    m_sCWT.i_meta_handle = m_META_HANDLE_Obj.Get_SecondHandle();
    SetMetaConnectReq(m_sCWT.META_connect_req);
    m_sCWT.neSuccess = on_PKTConnectWithTarget_Success;
    m_sCWT.neByUser  = on_PKTConnectWithTarget_ByUser;

    AbortConnectWithTarget();

    m_pT_CWT = new T_META_ConnectWithTarget(true, &m_sCWT);
    if (NULL != m_pT_CWT)
    {
        m_pT_CWT->FreeOnTerminate = true;
        m_pT_CWT->OnTerminate = on_PKTConnectWithTarget_Fail;
        m_pT_CWT->Priority = tpHighest;
    }
    else
    {
        m_pPKTLog->Add( DateToStr(Date()) +  " " + TimeToStr(Time()) +
                        " FAIL: connect with target"
                      );
        PostMessage(
            this->Handle,
            WM_ML_BT_PRINT_MSG,
            0,
            0
        );


        return;
    }

    if( NULL != m_pT_CWT )
    {
        m_pT_CWT->Resume();
    }
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_PKTConnectWithTarget_Success(TObject *Sender)
{
    if (PAGEIDX_BT_PKT == m_pctlToolSel->ActivePageIndex)
    {
        shpPKTConnect->Brush->Color = clYellow;
    }
    else
    {
        m_shpMTConnect->Brush->Color = clYellow;
    }

    m_bConnectTargetok = true;
    CBTPOWER BT_POWER_Obj;
    BT_POWER_Obj.REQ_Power_On_Second_BT_Start();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_PKTConnectWithTarget_Fail(TObject *Sender)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_PKTConnectWithTarget_ByUser(TObject *Sender)
{

}
//---------------------------------------------------------------------------
void TfrmBT::SetMetaConnectReq(META_Connect_Req &META_connect_req)
{
#if 0
    AnsiString  as_BootTimeout, as_METAConnectTimeout;
    int com_index;
    int baudrate_index;

    if (PAGEIDX_BT_PKT == m_pctlToolSel->ActivePageIndex)
    {
        com_index = cbPKTCOM->ItemIndex;
        baudrate_index = cbPKTBaudRate->ItemIndex;
    }
    else
    {
        com_index = m_cbMTBT2COM->ItemIndex;
        baudrate_index = m_cbMTBT2Baud->ItemIndex;
    }

    as_BootTimeout = read_Boot_timeout("MF_setup.txt", Application->ExeName);
    if (as_BootTimeout.AnsiCompareIC("infinite") == 0)
    {
        META_connect_req.boot_meta_arg.m_ms_boot_timeout = BOOT_INFINITE;
    }
    else
    {
        META_connect_req.boot_meta_arg.m_ms_boot_timeout = as_BootTimeout.ToInt();
    }

    META_connect_req.com_port = m_usComPortArray[com_index];
    META_connect_req.boot_meta_arg.m_bbchip_type = frmMainSel->Get_CurBBChipType();
    META_connect_req.boot_meta_arg.m_ext_clock = frmMainSel->Get_CurExternalClockType();

    switch ((E_BAUD_RATE_INDEX) baudrate_index)
    {
    case BAUD_RATE_AUTO_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD57600;
        META_connect_req.baudrate[1] = META_BAUD115200;
        META_connect_req.baudrate[2] = META_BAUD230400;
        META_connect_req.baudrate[3] = META_BAUD460800;
        META_connect_req.baudrate[4] = META_BAUD921600;
        META_connect_req.baudrate[5] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_57600_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD57600;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_115200_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD115200;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_230400_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD230400;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_460800_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD460800;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_921600_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD921600;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    default: // set baud rate = AUTO
    {
        META_connect_req.baudrate[0] = META_BAUD115200;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;
    }

    META_connect_req.flowctrl = META_SW_FLOWCTRL;
    as_METAConnectTimeout = read_META_Connect_timeout("MF_setup.txt", Application->ExeName);
    META_connect_req.ms_connect_timeout = as_METAConnectTimeout.ToInt();
    META_connect_req.boot_meta_arg.m_cb_in_brom_stage = NULL;
    META_connect_req.boot_meta_arg.m_cb_in_brom_stage_arg = NULL;

    // security
    META_connect_req.boot_meta_arg.m_speedup_brom_baudrate = _TRUE; //115200
    META_connect_req.boot_meta_arg.m_ready_power_on_wnd_handle = NULL;
    META_connect_req.boot_meta_arg.m_ready_power_on_wparam = NULL;
    META_connect_req.boot_meta_arg.m_ready_power_on_lparam = NULL;
    META_connect_req.boot_meta_arg.m_auth_handle = frmMainSel->Get_SLA_Object()->Get_AuthHandle();
    META_connect_req.boot_meta_arg.m_cb_sla_challenge = SLA_Challenge;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_arg = NULL;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_end = SLA_Challenge_END;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_end_arg = NULL;

    // EDGE PC card
    // META_connect_req.boot_meta_arg.m_cb_com_init_stage = ::cb_PowerOnOxford;
    //  META_connect_req.boot_meta_arg.m_cb_com_init_stage_arg = NULL;
#endif

}
//---------------------------------------------------------------------------
void TfrmBT::ReDrawPKTFields(E_DRAM_MASK_PKT draw_mask)
{
    if (draw_mask & DRAM_MASK_PKT_MONITOR)
    {
        int count;
        if (BTMODULE_MT6611 != m_cBtId)
        {
            count = BT_PACKET_IDX_NONEDR_COUNT;
        }
        else
        {
            count = BT_PACKET_IDX_COUNT;
        }

        for (int i=0; i<count; i++)
        {
            if (m_cbPKTType[i]->Checked)
            {
                m_edtPKTTesterTXCount[i]->Text = IntToStr( m_sBTMonCnf.s_tester_monitor.ui_tx_pkt_count[i] );
                m_edtPKTTesterRXCount[i]->Text = IntToStr( m_sBTMonCnf.s_tester_monitor.ui_rx_pkt_count[i] );
                m_edtPKTDUTTXCount[i]->Text    = IntToStr( m_sBTMonCnf.s_dut_monitor.ui_tx_pkt_count[i] );
                m_edtPKTDUTRXCount[i]->Text    = IntToStr( m_sBTMonCnf.s_dut_monitor.ui_rx_pkt_count[i] );
            }
        }
    }
}
//---------------------------------------------------------------------------
bool TfrmBT::IsPKTTestFinish( E_BT_PACKET_IDX idx )
{
    return m_sPKTStatus.b_finish[idx];
}
//---------------------------------------------------------------------------
bool TfrmBT::IsAllPKTTestFinish( void )
{
    for( int i=0; i<BT_PACKET_IDX_COUNT; i++ )
    {
        if( m_cbPKTType[i]->Checked )
        {
            if(  ! m_sPKTStatus.b_finish[i] )
                return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
bool TfrmBT::SetPKTFinish(E_BT_PACKET_IDX idx)
{
    if (idx >= BT_PACKET_IDX_COUNT)
    {
        return false;
    }
    unsigned int ui_tester_tx = m_edtPKTTesterTXCount[idx]->Text.ToInt();
    unsigned int ui_tester_rx = m_edtPKTTesterRXCount[idx]->Text.ToInt();
    unsigned int ui_dut_tx    = m_edtPKTDUTTXCount[idx]->Text.ToInt();
    unsigned int ui_dut_rx    = m_edtPKTDUTRXCount[idx]->Text.ToInt();
    unsigned int ui_pkt_count = m_edtPKTPktCount[idx]->Text.ToInt();

    if( (ui_tester_tx == m_uiPKTLastTesterTx) ||
            (ui_tester_rx == m_uiPKTLastTesterRx) ||
            (ui_dut_tx    == m_uiPKTLastDutTx)    ||
            (ui_dut_rx    == m_uiPKTLastDutRx)
      )
    {
        m_uiPKTCount++;
    }
    else
    {
        m_uiPKTCount = 0;
    }

    if( (ui_tester_tx >= ui_pkt_count ) &&
            ( ui_tester_rx >= ui_pkt_count ) &&
            ( ui_dut_tx    >= ui_pkt_count ) &&
            ( ui_dut_rx    >= ui_pkt_count ) ||
            ( m_uiPKTCount > 3             )
      )
    {
        m_sPKTStatus.b_finish[idx] = true;
        m_uiPKTLastTesterTx = 0;
        m_uiPKTLastTesterRx = 0;
        m_uiPKTLastDutTx    = 0;
        m_uiPKTLastDutRx    = 0;
        m_uiPKTCount        = 0;
    }
    else
    {
        m_sPKTStatus.b_finish[idx] = false;
        m_uiPKTLastTesterTx = ui_tester_tx;
        m_uiPKTLastTesterRx = ui_tester_rx;
        m_uiPKTLastDutTx    = ui_dut_tx;
        m_uiPKTLastDutRx    = ui_dut_rx;
    }

    return true;
}
//---------------------------------------------------------------------------
bool TfrmBT::IsPKTTestRunning( E_BT_PACKET_IDX idx )
{
    if( PKT_STATE_IDLE == m_sPKTStatus.e_state[idx] )
        return false;
    else
        return true;
}
//---------------------------------------------------------------------------
bool TfrmBT::CheckPKTFields( E_CHECK_MASK_PKT mark )
{
#if 0
    AnsiString_To_Hex_BDAddress( stTesterBDAddr->Caption, m_sBTPKT.s_tester_bd_addr );
    AnsiString_To_Hex_BDAddress( stDUTBDAddr->Caption, m_sBTPKT.s_dut_bd_addr );

    if( cbPKTDM1->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DM1) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DM1;
        //m_sBTPKT.e_p2  = BT_ACL_P2_DM1;
        //m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        //m_sBTPKT.e_idx = BT_PACKET_IDX_DM1;
    }
    else if( cbPKTDH1->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DH1) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DH1;
        // m_sBTPKT.e_p2  = BT_ACL_P2_DH1;
        // m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        m_sBTPKT.e_idx = BT_PACKET_IDX_DH1;
    }
    else if( cbPKTDM3->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DM3) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DM3;
        //m_sBTPKT.e_p2  = BT_ACL_P2_DM3;
        //m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        m_sBTPKT.e_idx = BT_PACKET_IDX_DM3;
    }
    else if( cbPKTDH3->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DH3) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DH3;
        //m_sBTPKT.e_p2  = BT_ACL_P2_DH3;
        //m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        m_sBTPKT.e_idx = BT_PACKET_IDX_DH3;
    }
    else if( cbPKTDM5->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DM5) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DM5;
        // m_sBTPKT.e_p2  = BT_ACL_P2_DM5;
        // m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        m_sBTPKT.e_idx = BT_PACKET_IDX_DM5;
    }
    else if( cbPKTDH5->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_DH5) )  )
    {
        //m_sBTPKT.e_p1  = BT_ACL_P1_DH5;
        //m_sBTPKT.e_p2  = BT_ACL_P2_DH5;
        //m_sBTPKT.e_sco = BT_SCO_UNKNOWN;
        m_sBTPKT.e_idx = BT_PACKET_IDX_DH5;
    }
    else if( cbPKTHV1->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_HV1) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_HV1;
        m_sBTPKT.e_p2  = BT_ACL_P2_HV1;
        m_sBTPKT.e_sco = BT_SCO_HV1;
        m_sBTPKT.e_idx = BT_PACKET_IDX_HV1;
    }
    else if( cbPKTHV2->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_HV2) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_HV2;
        m_sBTPKT.e_p2  = BT_ACL_P2_HV2;
        m_sBTPKT.e_sco = BT_SCO_HV2;
        m_sBTPKT.e_idx = BT_PACKET_IDX_HV2;
    }
    else if( cbPKTHV3->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_HV3) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_HV3;
        m_sBTPKT.e_p2  = BT_ACL_P2_HV3;
        m_sBTPKT.e_sco = BT_SCO_HV3;
        m_sBTPKT.e_idx = BT_PACKET_IDX_HV3;
    }
    else if( cbPKTEV3->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_EV3) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_EV3;
        m_sBTPKT.e_p2  = BT_ACL_P2_EV3;
        m_sBTPKT.e_sco = BT_SCO_EV3;
        m_sBTPKT.e_idx = BT_PACKET_IDX_EV3;
    }
    else if( cbPKTEV4->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_EV4) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_EV4;
        m_sBTPKT.e_p2  = BT_ACL_P2_EV4;
        m_sBTPKT.e_sco = BT_SCO_EV4;
        m_sBTPKT.e_idx = BT_PACKET_IDX_EV4;
    }
    else if( cbPKTEV5->Checked && (! IsPKTTestFinish(BT_PACKET_IDX_EV5) )  )
    {
        m_sBTPKT.e_p1  = BT_ACL_P1_EV5;
        m_sBTPKT.e_p2  = BT_ACL_P2_EV5;
        m_sBTPKT.e_sco = BT_SCO_EV5;
        m_sBTPKT.e_idx = BT_PACKET_IDX_EV5;
    }

    AnsiString text;
    if( BT_PACKET_IDX_DH5 >= m_sBTPKT.e_idx )
    {
        text = m_edtPKTDataLen[m_sBTPKT.e_idx]->Text;
        if( !IsValidBTTxDataLength( text, m_sBTPKT.us_packet_length, 0, 65535 ) )
        {
            edtPKTDataLenCheck(m_edtPKTDataLen[m_sBTPKT.e_idx]);
            return false;
        }
    }
    text = m_edtPKTPollPeriod[m_sBTPKT.e_idx]->Text;
    if( !IsValidBTTxPollPeriod( text, m_sBTPKT.uc_poll_period ) )
    {
        edtPKTDataLenCheck(m_edtPKTPollPeriod[m_sBTPKT.e_idx]);
        return false;
    }
    text = m_edtPKTPktCount[m_sBTPKT.e_idx]->Text;
    if( !IsValidBTTxPacketCount( text, m_sBTPKT.ui_packet_count ) )
    {
        edtPKTCountCheck(m_edtPKTPktCount[m_sBTPKT.e_idx]);
        return false;
    }
#endif

    if( CHECK_MASK_PKT_TCI == mark )
    {
        AnsiString text;
        text = m_edtPKTPollPeriod[m_sBTTCI.e_idx]->Text;
        if( !IsValidBTTxPollPeriod( text, m_sBTTCI.uc_poll_period ) )
        {
            edtPKTDataLenCheck(m_edtPKTPollPeriod[m_sBTTCI.e_idx]);
            return false;
        }
        text = m_edtPKTPktCount[m_sBTTCI.e_idx]->Text;
        if( !IsValidBTTxPacketCount( text, m_sBTTCI.ui_packet_count ) )
        {
            edtPKTCountCheck(m_edtPKTPktCount[m_sBTTCI.e_idx]);
            return false;
        }
        if( BT_PACKET_IDX_DH5 >= m_sBTTCI.e_idx )
        {
            text = m_edtPKTDataLen[m_sBTTCI.e_idx]->Text;
            if( !IsValidBTTxDataLength( text, m_sBTTCI.us_packet_length, 0, 65535 ) )
            {
                edtPKTDataLenCheck(m_edtPKTDataLen[m_sBTTCI.e_idx]);
                return false;
            }
        }
        else
        {
            switch( m_sBTTCI.e_idx )
            {
            case BT_PACKET_IDX_HV1:
                m_sBTTCI.us_packet_length = 10;
                break;

            case BT_PACKET_IDX_HV2:
                m_sBTTCI.us_packet_length = 20;
                break;

            case BT_PACKET_IDX_HV3:
                m_sBTTCI.us_packet_length = 30;
                break;

            case BT_PACKET_IDX_EV3:
                m_sBTTCI.us_packet_length = 30;
                break;

            case BT_PACKET_IDX_EV4:
                m_sBTTCI.us_packet_length = 120;
                break;

            case BT_PACKET_IDX_EV5:
                m_sBTTCI.us_packet_length = 180;
                break;
            }
        }

    }

    return true;
}
//-------------------------------------------------------------------------
unsigned short TfrmBT::Get_PKTTxDataDefaultLen( E_BT_PACKET_IDX index )
{
    unsigned short us_default_len[] =
    {
        17, // DM1
        27, // DH1,
        10, // HV1,
        20, // HV2,
        30, // HV3,
        121, // DM3,
        183, // DH3,
        224, // DM5,
        339, // DH5,
        30, // EV3,
        120, // EV4,
        180, //EV5,
        // BT 2.0
        54, // 2-DH1,
        60, // 2-EV3,
        367, // 2-DH3,
        360, // 2-EV5,
        679, // 2-DH5,
        90, // 3-EV3,
        83, // 3-DH1,
        552, // 3-DH3,
        540, // 3-EV5,
        1021, // 3-DH5,
    };

    return us_default_len[index];
}
//--------------------------------------------------------------------------
unsigned short TfrmBT::Get_PKTTxDataMinLen( E_BT_PACKET_IDX index )
{
    unsigned short us_min_len[] =
    {
        0, // DM1
        0, // DH1,
        10, // HV1,
        20, // HV2,
        30, // HV3,
        0, // DM3,
        0, // DH3,
        0, // DM5,
        0, // DH5,
        1, // EV3,
        1, // EV4,
        1, //EV5,
        // BT 2.0
        0, // 2-DH1,
        1, // 2-EV3,
        0, // 2-DH3,
        1, // 2-EV5,
        0, // 2-DH5,
        1, // 3-EV3,
        0, // 3-DH1,
        0, // 3-DH3,
        1, // 3-EV5,
        0, // 3-DH5,
    };

    return us_min_len[index];
}
//--------------------------------------------------------------------------
unsigned short TfrmBT::Get_PKTTxDataMaxLen( E_BT_PACKET_IDX index )
{
    unsigned char us_max_len[] =
    {
        17, // DM1
        27, // DH1,
        10, // HV1,
        20, // HV2,
        30, // HV3,
        121, // DM3,
        183, // DH3,
        224, // DM5,
        339, // DH5,
        30, // EV3,
        120, // EV4,
        180, //EV5,
        // BT 2.0
        54, // 2-DH1,
        60, // 2-EV3,
        367, // 2-DH3,
        360, // 2-EV5,
        679, // 2-DH5,
        90, // 3-EV3,
        83, // 3-DH1,
        552, // 3-DH3,
        540, // 3-EV5,
        1021, // 3-DH5,
    };

    return us_max_len[index];
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnPKTStartClick(TObject *Sender)
{
    if( ! CheckPKTFields( CHECK_MASK_PKT ) )
    {
        sbPKT->Panels->Items[0]->Text = (AnsiString) "  BT packet test fail";
        Application->MessageBox( "Execution Failure : BT packet test", "FAILURE", MB_OK );
        return;
    }

    for( int i=0; i<BT_PACKET_IDX_COUNT; i++ )
    {
        m_sPKTStatus.b_finish[i] = false;
        m_sPKTStatus.e_state[i]  = PKT_STATE_IDLE;
    }

    m_sBTPKT.hPostMsgDestHandle = this->Handle;
    m_sBTPKT.log                = m_pPKTLog;

    CurrentPageLock();
    sbPKT->Panels->Items[0]->Text = (AnsiString) "  BT packet test progressing";
    MonitorTimer->Enabled = false;

    m_uiPKTLastTesterTx = 0;
    m_uiPKTLastTesterRx = 0;
    m_uiPKTLastDutTx    = 0;
    m_uiPKTLastDutRx    = 0;
    m_uiPKTCount        = 0;

    m_BT_PKT_Obj.ConfirmCallback = ::CNF_PKT;
    m_BT_PKT_Obj.REQ_Start( m_sBTPKT );
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_PKT(void)
{
    META_RESULT state = m_BT_PKT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        MonitorTimer->Enabled = true;
        // m_sHCIEventFmt = m_BT_HCI_Obj.Get_HCIEvent();
        // DeComposeHCIEvent( m_sHCIEventFmt );
        // ReDrawHCIFields( DRAM_MASK_HCI_RECEIVE );
        // sbPKT->Panels->Items[0]->Text = (AnsiString)"  BT packet test successfully";
    }
    break;

    case META_FAILED:
    {
        CurrentPageReset();
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  BT packet test fail";
        Application->MessageBox( "Execution Fail : BT packet test", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        CurrentPageReset();
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  BT packet test timeout";
        Application->MessageBox( "Execution Timeout : BT packet test", "TIMEOUT", MB_OK );
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        CurrentPageReset();
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  BT packet test stop";
    }
    break;
    }


}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::rbHCIDecClick(TObject *Sender)
{
    sgSendHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value";
    sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value";

    ReDrawHCIFields( DRAM_MASK_HCI_SEND | DRAM_MASK_HCI_RECEIVE );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::rbHCIHexClick(TObject *Sender)
{
    sgSendHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value (Hex)";
    sgReceiveHCI->Cells[HCI_VALUE_COL_IDX][0] = "Value (Hex)";

    ReDrawHCIFields( DRAM_MASK_HCI_SEND | DRAM_MASK_HCI_RECEIVE );
}
//---------------------------------------------------------------------------
bool  TfrmBT::CheckSendHCIValue( void )
{
    S_BT_HCI_VALUE hci_value;
    vector<S_BT_HCI_PARAMETER>:: iterator iter;
    bool ok;

    for( int row=1; row<sgSendHCI->RowCount; row++ )
    {
        AnsiString as_name = sgSendHCI->Cells[HCI_NAME_COL_IDX][row];
        if( rbHCIDec->Checked )
        {
            if( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row].AnsiCompareIC("") == 0 )
            {
                return true;
            }

            for( iter = m_pvSendHCIPar->begin(); iter != m_pvSendHCIPar->end(); iter++ )
            {
                if( iter->as_name.AnsiCompareIC( as_name ) == 0 )
                {
                    // iter->ui_bytes = sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt();
                    // iter->s_value = hci_value;
                    break;
                }
            }

            if( iter->b_rangecheck )
            {
                ok = IsValidDecBTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], (unsigned char)sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt(), hci_value, iter->s_min_value, iter->s_max_value ) ;
                if( ! ok )
                {
                    AnsiString as_min_range, as_max_range;
                    BTHCIValue_To_AnsiString( iter->s_min_value, as_min_range );
                    BTHCIValue_To_AnsiString( iter->s_max_value, as_max_range );
                    AnsiString as_msg = "Execution Fail : value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect, range : " + as_min_range + "~" + as_max_range;
                    sbHCI->Panels->Items[0]->Text = (AnsiString)"  value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    Application->MessageBox( as_msg.c_str(), "FAIL", MB_OK );
                    return false;
                }
            }
            else
            {
                ok = IsValidDecBTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], (unsigned char)sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt(), hci_value ) ;
                if( ! ok )
                {
                    AnsiString as_msg = "Execution Fail : value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    sbHCI->Panels->Items[0]->Text = (AnsiString)"  value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    Application->MessageBox( as_msg.c_str(), "FAIL", MB_OK );
                    return false;
                }
            }

        }
        else
        {
            if( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row].AnsiCompareIC("") == 0 )
            {
                return true;
            }

            for( iter = m_pvSendHCIPar->begin(); iter != m_pvSendHCIPar->end(); iter++ )
            {
                if( iter->as_name.AnsiCompareIC( as_name ) == 0 )
                {
                    // iter->ui_bytes = sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt();
                    // iter->s_value = hci_value;
                    break;
                }
            }

            if( iter->b_rangecheck )
            {
                ok = IsValidHexBTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], (unsigned char)sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt(), hci_value, iter->s_min_value, iter->s_max_value ) ;
                if( ! ok )
                {
                    AnsiString as_min_range, as_max_range;
                    BTHCIValue_To_Hex_AnsiString( iter->s_min_value, as_min_range );
                    BTHCIValue_To_Hex_AnsiString( iter->s_max_value, as_max_range );
                    AnsiString as_msg = "Execution Fail : value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect, range : 0x" + as_min_range + "~0x" + as_max_range;
                    sbHCI->Panels->Items[0]->Text = (AnsiString)"  value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    Application->MessageBox( as_msg.c_str(), "FAIL", MB_OK );
                    return false;
                }
            }
            else
            {
                ok = IsValidHexBTHCIValue( sgSendHCI->Cells[HCI_VALUE_COL_IDX][row], (unsigned char)sgSendHCI->Cells[HCI_BYTE_COL_IDX][row].ToInt(), hci_value ) ;
                if( ! ok )
                {
                    AnsiString as_msg = "Execution Fail : value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    sbHCI->Panels->Items[0]->Text = (AnsiString)"  value of parameter " + sgSendHCI->Cells[HCI_NAME_COL_IDX][row] + " incorrect";
                    Application->MessageBox( as_msg.c_str(), "FAIL", MB_OK );
                    return false;
                }
            }

        }


    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::sgSendHCICheck(TObject *Sender)
{
    CheckSendHCIValue();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtHCITimeoutCheck(TObject *Sender)
{
    int data;
    AnsiString text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " Timeout is not valid ";

    text = edit->Text;
    if (!IsValidTimeout(text, data))
    {
        ShowHintLabel(edit, hint);
        edit->Text = IntToStr( HCI_DEFAULT_TIMEOUT_MS );
        edit->SetFocus();
        return;
    }

    m_sBTHCI.ui_ms_timeout = (unsigned int) data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbRFTxTypeChange(TObject *Sender)
{
    if(BT_RF_TX_NON_MODULED_IDX == cbRFTxType->ItemIndex)
    {
        edtRFTxDataLen->Enabled = false;
    }
    else
    {
        edtRFTxDataLen->Enabled = true;
    }
    DisplayRFDefaultDataLen();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFRxSignleFreqCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~255 "
    };

    text = edit->Text;
    if( !IsValidBTFreq( text, uc_data ) )
    {
        edit->Text = 78;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBtRf.uc_freq = uc_data;
}
//===========================================================================
/////////////////////////////  Packet test   ////////////////////////////////
//===========================================================================
void TfrmBT::AbortConnectWithTarget(void)
{
    m_sCWT.iBootStop = SP_BOOT_STOP;
    if (m_bConnectTargetok)
    {
        SP_META_ShutDownTarget_r(m_META_HANDLE_Obj.Get_SecondHandle());
        SP_META_DisconnectWithTarget_r(m_META_HANDLE_Obj.Get_SecondHandle());
        m_bConnectTargetok = false;
    }

    if (NULL != m_pT_CWT)
    {
        WaitForSingleObject(m_sCWT.METADLL_Connect_Event, 5000);
    }
}
//---------------------------------------------------------------------------
bool TfrmBT::IsNewTciRequired(void)
{
    TCheckBox *cbPkt20[] =
    {
        cbPKTDM1,
        cbPKTDH1,
        cbPKTDM3,
        cbPKTDH3,
        cbPKTDM5,
        cbPKTDH5,
        cbPKTHV1,
        cbPKTHV2,
        cbPKTHV3,
        cbPKTEV3,
        cbPKTEV4,
        cbPKTEV5,
        cbPK2DH1,
        cbPK2EV3,
        cbPK2DH3,
        cbPK2EV5,
        cbPK2DH5,
        cbPK3EV3,
        cbPK3DH1,
        cbPK3DH3,
        cbPK3EV5,
        cbPK3DH5
    };

    int total_num;
    if (BTMODULE_MT6611 != m_cBtId)
    {
        total_num = BT_PACKET_IDX_NONEDR_COUNT;
    }
    else
    {
        total_num = BT_PACKET_IDX_COUNT;
    }

    for (int i=0; i<total_num; i++)
    {
        if (cbPkt20[i]->Checked &&
                (!IsPKTTestFinish((E_BT_PACKET_IDX) i))
           )
        {
            if (IsPKTTestRunning((E_BT_PACKET_IDX) i))
            {
                return false;
            }
            else
            {
                m_sBTTCI.e_idx = (E_BT_PACKET_IDX) i;
                return true;
            }
        }
    }

    return false;
#if 0
    if (cbPKTDM1->Checked                       &&
            (!IsPKTTestFinish(BT_PACKET_IDX_DM1))
       )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DM1))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DM1;
            return true;
        }
    }
    else if (cbPKTDH1->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_DH1))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DH1))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DH1;
            return true;
        }
    }
    else if (cbPKTDM3->Checked                      &&
             (!IsPKTTestFinish(BT_PACKET_IDX_DM3))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DM3))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DM3;
            return true;
        }
    }
    else if (cbPKTDH3->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_DH3))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DH3))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DH3;
            return true;
        }
    }
    else if (cbPKTDM5->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_DM5))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DM5))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DM5;
            return true;
        }
    }
    else if (cbPKTDH5->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_DH5))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_DH5))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_DH5;
            return true;
        }
    }
    else if (cbPKTHV1->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_HV1))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_HV1))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_HV1;
            return true;
        }
    }
    else if (cbPKTHV2->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_HV2))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_HV2))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_HV2;
            return true;
        }
    }
    else if (cbPKTHV3->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_HV3))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_HV3))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_HV3;
            return true;
        }
    }
    else if (cbPKTEV3->Checked                      &&
             (!IsPKTTestFinish(BT_PACKET_IDX_EV3))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_EV3))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_EV3;
            return true;
        }
    }
    else if (cbPKTEV4->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_EV4))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_EV4))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_EV4;
            return true;
        }
    }
    else if (cbPKTEV5->Checked                       &&
             (!IsPKTTestFinish(BT_PACKET_IDX_EV5))
            )
    {
        if (IsPKTTestRunning(BT_PACKET_IDX_EV5))
        {
            return false;
        }
        else
        {
            m_sBTTCI.e_idx = BT_PACKET_IDX_EV5;
            return true;
        }
    }

    if (BTMODULE_MT6611 == m_cBtId)
    {
        E_BT_PACKET_IDX ePkt20[] =
        {
            BT_PACKET_IDX_2DH1,
            BT_PACKET_IDX_2EV3,
            BT_PACKET_IDX_2DH3,
            BT_PACKET_IDX_2EV5,
            BT_PACKET_IDX_2DH5,
            BT_PACKET_IDX_3EV3,
            BT_PACKET_IDX_3DH1,
            BT_PACKET_IDX_3DH3,
            BT_PACKET_IDX_3EV5,
            BT_PACKET_IDX_3DH5,
        };


    }

    return false;
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::MonitorTimerTimer(TObject *Sender)
{
    if (IsAllPKTTestFinish())
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  BT packet test finish";
        CurrentPageReset();
    }

    if (IsNewTciRequired())
    {
        if( ! CheckPKTFields( CHECK_MASK_PKT_TCI ) )
        {
            MonitorTimer->Enabled = false;
            sbPKT->Panels->Items[0]->Text = (AnsiString) "  BT packet test fail";
            Application->MessageBox( "Execution Failure : BT packet test", "FAILURE", MB_OK );
            return;
        }
        m_sPKTStatus.e_state[m_sBTTCI.e_idx] = PKT_STATE_RUNNING;
        m_BT_PKT_Obj.ConfirmCallback = ::CNF_PKT_TCI;
        m_BT_PKT_Obj.REQ_TCI_Control_Remote_DUT_Start(m_sBTTCI);
    }
    else
    {
        m_BT_PKT_Obj.ConfirmCallback = ::CNF_PKT_Read_TxRxCount;
        m_BT_PKT_Obj.REQ_Read_TX_RX_Count_Start();
    }
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_PKT_TCI( void )
{
    META_RESULT state = m_BT_PKT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {

        // sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count successfully";
    }
    break;

    case META_FAILED:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)" Read packet TX/RX count fail";
        Application->MessageBox("Execution Fail : Read packet TX/RX count", "FAIL", MB_OK);
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count timeout";
        Application->MessageBox("Execution Timeout : Read packet TX/RX count", "TIMEOUT", MB_OK);
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count stop";
        CurrentPageReset();
    }
    break;
    }
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_PKT_Read_TxRxCount(void)
{
    META_RESULT state = m_BT_PKT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        if (BTMODULE_MT6611 != m_cBtId)
        {
            SetPKTFinish(m_sBTTCI.e_idx);
            m_sBTMonCnf = m_BT_PKT_Obj.Get_MonitorResult();
            ReDrawPKTFields(DRAM_MASK_PKT_MONITOR);
        }
        else
        {
            m_BT_PKT_Obj.ConfirmCallback = ::CNF_PKT_Read_EDRTxRxCount;
            m_BT_PKT_Obj.REQ_Read_EDR_TX_RX_Count_Start();
        }
        // sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count successfully";
    }
    break;

    case META_FAILED:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)" Read packet TX/RX count fail";
        Application->MessageBox("Execution Fail : Read packet TX/RX count", "FAIL", MB_OK);
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count timeout";
        Application->MessageBox("Execution Timeout : Read packet TX/RX count", "TIMEOUT", MB_OK);
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count stop";
        CurrentPageReset();
    }
    break;
    }
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_PKT_Read_EDRTxRxCount(void)
{
    META_RESULT state = m_BT_PKT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        SetPKTFinish(m_sBTTCI.e_idx);
        m_sBTMonCnf = m_BT_PKT_Obj.Get_MonitorResult();
        ReDrawPKTFields(DRAM_MASK_PKT_MONITOR);
        // sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read packet TX/RX count successfully";
    }
    break;

    case META_FAILED:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)" Read EDR packet TX/RX count fail";
        Application->MessageBox("Execution Fail : Read EDR packet TX/RX count", "FAIL", MB_OK);
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read EDR packet TX/RX count timeout";
        Application->MessageBox("Execution Timeout : Read EDR packet TX/RX count", "TIMEOUT", MB_OK);
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        MonitorTimer->Enabled = false;
        sbPKT->Panels->Items[0]->Text = (AnsiString)"  Read EDR packet TX/RX count stop";
        CurrentPageReset();
    }
    break;
    }
}
//--------------------------------------------------------------------------
void __fastcall TfrmBT::edtPKTDataLenCheck(TObject *Sender)
{
    AnsiString  text;
    AnsiString  as_hint;
    TEdit *edit = (TEdit*)Sender;
    unsigned short  us_min_len = Get_PKTTxDataMinLen((E_BT_PACKET_IDX) edit->Tag);
    unsigned short  us_max_len = Get_PKTTxDataMaxLen((E_BT_PACKET_IDX) edit->Tag);
    unsigned short  us_data;

    if( us_min_len != us_max_len )
    {
        as_hint = " value should be " + IntToStr( us_min_len ) +"~" + IntToStr( us_max_len );
    }
    else
    {
        as_hint = " value should be " + IntToStr( us_min_len );
    }

    text = edit->Text;
    if( !IsValidBTTxDataLength( text, us_data, us_min_len, us_max_len ) )
    {
        edit->Text = Get_PKTTxDataDefaultLen((E_BT_PACKET_IDX) edit->Tag);
        ShowHintLabel( edit, as_hint.c_str() );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtPKTPollPeriodCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~255 "
    };

    text = edit->Text;
    if( !IsValidBTTxPollPeriod( text, uc_data ) )
    {
        edit->Text = 0;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtPKTCountCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~4294967295 "
    };

    text = edit->Text;
    if( !IsValidBTTxPacketCount( text, ui_data ) )
    {
        edit->Text = 1000;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnSCTFileClick(TObject *Sender)
{
    //char str[512];
    bool ok;

    ok = dlgOpenSCTFile->Execute();
    if( ! ::CheckFileExist(dlgOpenSCTFile->FileName))
        ok = false;

    if( !ok )
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString) "  Load script file fail";
        return;
    }


    m_sBTSCT.hPostMsgDestHandle = this->Handle;
    m_sBTSCT.filename           = dlgOpenSCTFile->FileName;
    m_sBTSCT.log                = m_pSCTLog;

    m_BT_SCT_Obj.ConfirmCallback = ::ConfirmCallback_SetupSCTFile;
    m_BT_SCT_Obj.REQ_Read_From_File_Start( m_sBTSCT );

    sbSCT->Panels->Items[0]->Text = (AnsiString) "  Setup script file progressing";
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_SetupSCTFile(void)
{
    META_RESULT state = m_BT_SCT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        stSCTFile->Caption = m_sBTSCT.filename;
        m_pvScript = m_BT_SCT_Obj.Get_ScriptVector();
        DisplaySCTUI();
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Setup script file successfully";
    }
    break;

    case META_FAILED:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Setup script file fail";
        Application->MessageBox( "Execution Fail : Setup script file", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Setup script file timeout";
        Application->MessageBox( "Execution Timeout : Setup script file", "TIMEOUT", MB_OK );
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Setup script file stop";
    }
    break;
    }

    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmBT::DisplaySCTUI( void )
{
    vector<S_BT_SCT_SCRIPT>:: iterator iter_script;
    // S_BT_SCT_SCRIPT script;
    // int i;

    // for( i=0; i<MAX_SCRIPT_NUM; i++ )
    // {  // m_btnSCTTest[i]->Visible = false;
    //     m_btnSCTTest[i]->Enabled = false;
    // }

    lbSCT->Clear();
    for( iter_script = m_pvScript->begin(); iter_script != m_pvScript->end(); iter_script++ )
    {
        lbSCT->Items->Add( iter_script->as_script_name );
        // script = *iter_script;
        // for( int i=1; i<=MAX_SCRIPT_NUM; i++ )
        // {
        //     if( script.as_script_tag.AnsiPos(IntToStr(i)) != 0 )
        //     {
        //         m_btnSCTTest[i-1]->Enabled = true;
        //        // m_btnSCTTest[i-1]->Visible = true;
        //         m_btnSCTTest[i-1]->Caption = script.as_script_name;
        //         break;
        //     }
        // }
    }


}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnSCTTestClick(TObject *Sender)
{
    TButton *btn = (TButton *)Sender;

    m_sBTSCT.hPostMsgDestHandle = this->Handle;
    m_sBTSCT.filename           = stSCTFile->Caption;
    m_sBTSCT.log                = m_pSCTLog;
    m_sBTSCT.as_script_name     = btn->Caption;

    CurrentPageLock();
    sbSCT->Panels->Items[0]->Text = (AnsiString) "  Script test progressing";
    m_BT_SCT_Obj.ConfirmCallback  = ::ConfirmCallback_SCT;
    m_BT_SCT_Obj.REQ_Start( m_sBTSCT );
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_SCT(void)
{
    META_RESULT state = m_BT_SCT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Script test successfully";
    }
    break;

    case META_FAILED:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Script test fail";
        Application->MessageBox( "Execution Fail : Script test", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop(true);
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Script test timeout";
        Application->MessageBox( "Execution Timeout : Script test", "TIMEOUT", MB_OK );
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbSCT->Panels->Items[0]->Text = (AnsiString)"  Send HCI command stop";
    }
    break;
    }

    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnPKTStopClick(TObject *Sender)
{
    if( btnPKTStart->Tag==1 )
    {
        MonitorTimer->Enabled = false;
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Stop packet test successfully";
        m_BT_PKT_Obj.ConfirmCallback = ::CNF_PKT_Stop;
        m_BT_PKT_Obj.REQ_Stop_Start();
    }

}
//--------------------------------------------------------------------------
void TfrmBT::CNF_PKT_Stop(void)
{
    CurrentPageReset();
}
//--------------------------------------------------------------------------
void TfrmBT::FillSCTResult( void )
{

    for(int i=0; i<m_pSCTLog->Count; i++ )
    {
        AnsiString as = m_pSCTLog->Strings[i];
        memSCTResult->Lines->Add( as );
    }
    m_pSCTLog->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFTxStopClick(TObject *Sender)
{
    if(1 == btnRFTxStart->Tag || 2 == btnRFTxStart->Tag)
    {
        Force_BT_Stop( true );
        m_BT_RF_Obj.REQ_Stop_Start();
        CurrentPageReset();
        if( rbRFTx->Checked )
        {
            btnRFChangeLevel->Enabled = false;
        }
//
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Stop RF TX test successfully";
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbHCICategoryChange(TObject *Sender)
{
    DisplayHCIUI( DRAW_MASK_HCI_COMMAND | DRAW_MASK_HCI_PARAMETER, cbHCICategory->ItemIndex, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnHCIStartClick(TObject *Sender)
{
    if( ! CheckSendHCIValue() )
    {
        return;
    }

    m_sBTHCI.hPostMsgDestHandle = this->Handle;
    m_sBTHCI.filename           = stHCIFile->Caption;
    m_sBTHCI.log                = m_pHCILog;
    m_sBTHCI.ui_ms_timeout      = edtHCITimeout->Text.ToInt();
    ComposeHCICommand( m_sBTHCI );

    CurrentPageLock();
    sbHCI->Panels->Items[0]->Text = (AnsiString) "  Start HCI commander test progressing";
    m_BT_HCI_Obj.ConfirmCallback  = ::ConfirmCallback_HCI;
    m_BT_HCI_Obj.REQ_Start( m_sBTHCI );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnHCIStopClick(TObject *Sender)
{
    if( btnHCIStart->Tag==1 )
    {
        Force_BT_Stop( false );
        m_BT_HCI_Obj.REQ_Stop();
        CurrentPageReset();
        sbHCI->Panels->Items[0]->Text = (AnsiString)"  Stop HCI commander test successfully";
        return;
    }
}
//---------------------------------------------------------------------------
void  TfrmBT::Force_BT_Stop(bool reset)
{
    m_cBT_STOP_Obj.REQ_Start( reset );
}

void TfrmBT::Force_BT_Stop_BLE(void)
{
    m_cBT_STOP_Obj.REQ_Stop();
}
//--------------------------------------------------------------------------
//void __fastcall TfrmBT::btnRFRxStopClick(TObject *Sender)
//{
//    if( btnRFRxStart->Tag==1 )
//    {
//        Force_BT_Stop();
//        m_BT_RF_Obj.REQ_Stop_Start();
//        CurrentPageReset();
//        sbRF->Panels->Items[0]->Text = (AnsiString)"  Stop RF RX test successfully";
//        return;
//    }
//}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnSCTStopClick(TObject *Sender)
{
    Force_BT_Stop( true );
    CurrentPageReset();
    sbSCT->Panels->Items[0]->Text = (AnsiString)"  Stop script test successfully";

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnSCTStartClick(TObject *Sender)
{
    //TButton *btn = (TButton *)Sender;

    m_sBTSCT.hPostMsgDestHandle = this->Handle;
    m_sBTSCT.filename           = stSCTFile->Caption;
    m_sBTSCT.log                = m_pSCTLog;
    m_sBTSCT.as_script_name     = lbSCT->Items->Strings[lbSCT->ItemIndex];

    CurrentPageLock();
    sbSCT->Panels->Items[0]->Text = (AnsiString) "  Script test progressing";
    m_BT_SCT_Obj.ConfirmCallback  = ::ConfirmCallback_SCT;
    m_BT_SCT_Obj.REQ_Start( m_sBTSCT );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnSCTClearLogClick(TObject *Sender)
{
    memSCTResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnHCIClearLogClick(TObject *Sender)
{
    memHCIResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFClearLogClick(TObject *Sender)
{
    memRFResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnPKTClearLogClick(TObject *Sender)
{
    memPKTResult->Clear();
}
//===========================================================================
//////////////////////////////  Throughput test   ///////////////////////////
//===========================================================================
void __fastcall TfrmBT::btnTHClearLogClick(TObject *Sender)
{
    memTTResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTHConnectDUTClick(TObject *Sender)
{
#if 0
    shpTHConnect->Brush->Color = clRed;
    if( m_bConnectingTarget )
    {
        m_sCWT.iBootStop = BOOT_STOP;
        if( NULL != m_pT_CWT )
        {
            WaitForSingleObject( m_sCWT.METADLL_Connect_Event, 5000 );
        }
        m_sCWT.iBootStop = 0;
    }
    else
    {
        m_sCWT.iBootStop = 0;
    }
    m_sCWT.i_meta_handle             = m_META_HANDLE_Obj.Get_SecondHandle();
    SetTHMetaConnectReq( m_sCWT.META_connect_req );
    m_sCWT.neSuccess = on_THConnectWithTarget_Success;
    m_sCWT.neByUser  = on_THConnectWithTarget_ByUser;


    if( m_bConnectTargetok )
    {
        WM_META_ShutDownTarget_r( m_META_HANDLE_Obj.Get_SecondHandle() );
        WM_META_DisconnectWithTarget_r( m_META_HANDLE_Obj.Get_SecondHandle() );
        m_bConnectTargetok = false;
    }

    if( NULL != m_pT_CWT )
    {
        WaitForSingleObject( m_sCWT.METADLL_Connect_Event, 5000 );
    }

    m_pT_CWT = new T_META_ConnectWithTarget(
        true,
        &m_sCWT
    );
    if( NULL != m_pT_CWT )
    {
        m_pT_CWT->FreeOnTerminate = true;
        m_pT_CWT->OnTerminate = on_THConnectWithTarget_Fail;
        m_pT_CWT->Priority = tpHighest;
    }
    else
    {
        m_pTHLog->Add( DateToStr(Date()) +  " " + TimeToStr(Time()) +
                       " FAIL: connect with target"
                     );
        PostMessage(
            this->Handle,
            WM_ML_BT_PRINT_MSG,
            0,
            0
        );


        return;
    }

    if( NULL != m_pT_CWT )
    {
        m_bConnectingTarget = true;
        m_pT_CWT->Resume();
    }
#endif
}
//---------------------------------------------------------------------------
void TfrmBT::SetTHMetaConnectReq( META_Connect_Req &META_connect_req )
{
#if 0
    AnsiString  as_BootTimeout, as_METAConnectTimeout;

    as_BootTimeout = read_Boot_timeout("MF_setup.txt", Application->ExeName);
    if( as_BootTimeout.AnsiCompareIC( "infinite" ) == 0 )
    {
        META_connect_req.boot_meta_arg.m_ms_boot_timeout = BOOT_INFINITE;
    }
    else
    {
        META_connect_req.boot_meta_arg.m_ms_boot_timeout = as_BootTimeout.ToInt();
    }

    META_connect_req.com_port = m_usComPortArray[cbTHCOM->ItemIndex];
    META_connect_req.boot_meta_arg.m_bbchip_type = frmMainSel->Get_CurBBChipType();
    META_connect_req.boot_meta_arg.m_ext_clock = frmMainSel->Get_CurExternalClockType();

    switch ( (E_BAUD_RATE_INDEX) cbPKTBaudRate->ItemIndex )
    {
    case BAUD_RATE_AUTO_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD57600;
        META_connect_req.baudrate[1] = META_BAUD115200;
        META_connect_req.baudrate[2] = META_BAUD230400;
        META_connect_req.baudrate[3] = META_BAUD460800;
        META_connect_req.baudrate[4] = META_BAUD921600;
        META_connect_req.baudrate[5] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_57600_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD57600;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_115200_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD115200;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_230400_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD230400;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_460800_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD460800;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    case BAUD_RATE_921600_INDEX:
    {
        META_connect_req.baudrate[0] = META_BAUD921600;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;

    default: // set baud rate = AUTO
    {
        META_connect_req.baudrate[0] = META_BAUD115200;
        META_connect_req.baudrate[1] = META_BAUD_END;
    }
    break;
    }

    META_connect_req.flowctrl = META_SW_FLOWCTRL;
    as_METAConnectTimeout = read_META_Connect_timeout("MF_setup.txt", Application->ExeName);
    META_connect_req.ms_connect_timeout = as_METAConnectTimeout.ToInt();
    META_connect_req.boot_meta_arg.m_cb_in_brom_stage = NULL;
    META_connect_req.boot_meta_arg.m_cb_in_brom_stage_arg = NULL;

    // security
    META_connect_req.boot_meta_arg.m_speedup_brom_baudrate = _TRUE; //115200
    META_connect_req.boot_meta_arg.m_ready_power_on_wnd_handle = NULL;
    META_connect_req.boot_meta_arg.m_ready_power_on_wparam = NULL;
    META_connect_req.boot_meta_arg.m_ready_power_on_lparam = NULL;
    META_connect_req.boot_meta_arg.m_auth_handle = frmMainSel->Get_SLA_Object()->Get_AuthHandle();
    META_connect_req.boot_meta_arg.m_cb_sla_challenge = SLA_Challenge;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_arg = NULL;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_end = SLA_Challenge_END;
    META_connect_req.boot_meta_arg.m_cb_sla_challenge_end_arg = NULL;

    // EDGE PC card
    META_connect_req.boot_meta_arg.m_cb_com_init_stage = ::cb_PowerOnOxford;
    META_connect_req.boot_meta_arg.m_cb_com_init_stage_arg = NULL;

#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_THConnectWithTarget_Success(TObject *Sender)
{
#if 0
    shpTHConnect->Brush->Color = clYellow;
    m_bConnectTargetok = true;
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_THConnectWithTarget_Fail(TObject *Sender)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::on_THConnectWithTarget_ByUser(TObject *Sender)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbTHCOMChange(TObject *Sender)
{
    //m_sCWT.iBootStop = BOOT_STOP;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::ComboBox1Change(TObject *Sender)
{
    //m_sCWT.iBootStop = BOOT_STOP;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFEnterTestModeClick(TObject *Sender)
{

    m_sBtRf.hPostMsgDestHandle = this->Handle;
    m_sBtRf.log                = m_pRFLog;


    CurrentPageLock();
    sbRF->Panels->Items[0]->Text = (AnsiString) "  Enter BT test mode progressing";
    m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_RFEnterTestMode;
    m_BT_RF_Obj.REQ_Enter_Test_Mode_Start( m_sBtRf );
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_RFEnterTestMode(void)
{
    META_RESULT state = m_BT_RF_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Enter BT test mode finish";
        btnRFChangeLevel->Enabled = true;
    }
    break;

    case META_FAILED:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Enter BT test mode fail";
        Application->MessageBox( "Execution Failure : Enter BT test mode", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( true );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Enter BT test mode timeout";
        Application->MessageBox( "Execution Timeout : Enter BT test mode", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Enter BT test mode stop";
        btnRFChangeLevel->Enabled = false;
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();
}
//--------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFBDAddressCheck(TObject *Sender)
{
    S_BD_ADDR  bd_addr;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " BD address is not valid "
    };

    text = edit->Text;
    if( !IsValidHexBDAddress( text, bd_addr ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sRFBdAddr = bd_addr;
    SyncLAPAndAccessCode();
    ReDrawRFFields( DRAM_MASK_RF_ACCESS_CODE );
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFQueryBdAddrClick(TObject *Sender)
{
    m_sBtRf.hPostMsgDestHandle = this->Handle;
    m_sBtRf.log                = m_pRFLog;

    CurrentPageLock();
    sbRF->Panels->Items[0]->Text = (AnsiString) "  Query BD address progressing";
    m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_QueryBDAddress;
    m_BT_RF_Obj.REQ_QueryBDAddress_Start( m_sBtRf );
}//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_QueryBDAddress(void)
{
    META_RESULT state = m_BT_RF_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sRFBdAddr = m_BT_RF_Obj.Get_BdAddress();
        ReDrawRFFields( DRAM_MASK_RF_BD_ADDRESS );
        SyncLAPAndAccessCode();
        ReDrawRFFields( DRAM_MASK_RF_ACCESS_CODE );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Query BD address finish";
    }
    break;

    case META_FAILED:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Query BD address fail";
        Application->MessageBox( "Execution Failure : Query BD address ", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( true );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Query BD address timeout";
        Application->MessageBox( "Execution Timeout : Query BD address ", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Query BD address stop";
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbRFTxPowerCtrlClick(TObject *Sender)
{
    if( (cbRFTxPowerCtrl->Checked) && (! btnRFTxStart->Enabled) )
        btnRFChangeLevel->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnRFChangeLevelClick(TObject *Sender)
{
    AnsiString text = edtRFTxLevel->Text;
    if( !IsValidBTTxPcl( text, m_sBtRf.uc_pcl ) )
    {
        edtRFTxLevelCheck(edtRFTxLevel);
        return;
    }

    m_sBtRf.hPostMsgDestHandle = this->Handle;
    m_sBtRf.log                = m_pRFLog;

    CurrentPageLock();
    sbRF->Panels->Items[0]->Text = (AnsiString) "  Change power control level progressing";
    m_BT_RF_Obj.ConfirmCallback  = ::ConfirmCallback_ChangePCL;
    m_BT_RF_Obj.REQ_ChangePCL_Start( m_sBtRf );
}
//--------------------------------------------------
void TfrmBT::ConfirmCallback_ChangePCL(void)
{
    META_RESULT state = m_BT_RF_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Change power control level finish";
    }
    break;

    case META_FAILED:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Change power control level fail";
        Application->MessageBox( "Execution Failure : Change power control level", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( true );
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Change power control level timeout";
        Application->MessageBox( "Execution Timeout : Change power control level", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbRF->Panels->Items[0]->Text = (AnsiString)"  Change power control level stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::ToggleHideExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;

    ApplyHideProperty();
}
//---------------------------------------------------------------------------
void TfrmBT::ApplyHideProperty(void)
{
//    bool visible = g_bHideEnable ? false : true;
    /*   tsHCI->Visible = visible;
       tsHCI->TabVisible = visible;
       tsSCT->Visible = visible;
       tsSCT->TabVisible = visible;
       m_tsMT->Visible = visible;
       m_tsMT->TabVisible = visible;*/
}
//--------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFNAPCheck(TObject *Sender)
{
#if 0
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 3 == edit->Tag % 4 )
    {
        m_sBtRf.s_BDAddr.us_NAP = (m_sBtRf.s_BDAddr.us_NAP & 0x0FFF) | ((ucdata &0xF)<<12);
    }
    else if( 2 == edit->Tag % 4 )
    {
        m_sBtRf.s_BDAddr.us_NAP = (m_sBtRf.s_BDAddr.us_NAP & 0xF0FF) | ((ucdata &0xF)<<8);
    }
    else if( 1 == edit->Tag % 4 )
    {
        m_sBtRf.s_BDAddr.us_NAP = (m_sBtRf.s_BDAddr.us_NAP & 0xFF0F) | ((ucdata &0xF)<<4);
    }
    else
    {
        m_sBtRf.s_BDAddr.us_NAP = (m_sBtRf.s_BDAddr.us_NAP & 0xFFF0) | (ucdata &0xF);
    }
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFUAPCheck(TObject *Sender)
{
#if 0
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 1 == edit->Tag % 2 )
    {
        m_sBtRf.s_BDAddr.uc_UAP = (m_sBtRf.s_BDAddr.uc_UAP & 0x0F) | ((ucdata & 0xF)<<4);
    }
    else
    {
        m_sBtRf.s_BDAddr.uc_UAP = (m_sBtRf.s_BDAddr.uc_UAP & 0xF0) | (ucdata & 0xF);
    }
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtRFLAPCheck(TObject *Sender)
{
#if 0
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 5 == edit->Tag % 6 )
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0x0FFFFF) | ((ucdata & 0xF)<<20);
    }
    else if( 4 == edit->Tag % 6 )
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0xF0FFFF) | ((ucdata & 0xF)<<16);
    }
    else if( 3 == edit->Tag % 6 )
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0xFF0FFF) | ((ucdata & 0xF)<<12);
    }
    else if( 2 == edit->Tag % 6 )
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0xFFF0FF) | ((ucdata & 0xF)<<8);
    }
    else if( 1 == edit->Tag % 6 )
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0xFFFF0F) | ((ucdata & 0xF)<<4);
    }
    else
    {
        m_sBtRf.s_BDAddr.ui_LAP = (m_sBtRf.s_BDAddr.ui_LAP & 0xFFFFF0) | (ucdata & 0xF);
    }
#endif
}
//============================================================================
//////////////////////////  Connection test  /////////////////////////////////
//============================================================================
void  TfrmBT::ReDrawCTFields( E_DRAM_MASK_CT draw_mask )
{
    if( draw_mask & DRAM_MASK_CT_LOCAL_BDADDR )
    {
        char str[20];

        // NAP
        sprintf( str, "%X", (m_sLocalBdAddr.us_NAP & 0xF000) >> 12 );
        edtCTLDINAP3->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.us_NAP & 0x0F00) >>  8 );
        edtCTLDINAP2->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.us_NAP & 0x00F0) >>  4 );
        edtCTLDINAP1->Text = (AnsiString) str;
        sprintf( str, "%X", m_sLocalBdAddr.us_NAP & 0x000F );
        edtCTLDINAP0->Text = (AnsiString) str;

        // UAP
        sprintf( str, "%X", (m_sLocalBdAddr.uc_UAP & 0xF0) >> 4 );
        edtCTLDIUAP1->Text = (AnsiString) str;
        sprintf( str, "%X", m_sLocalBdAddr.uc_UAP & 0x0F );
        edtCTLDIUAP0->Text = (AnsiString) str;

        // LAP
        sprintf( str, "%X", (m_sLocalBdAddr.ui_LAP & 0x00F00000) >> 20 );
        edtCTLDILAP5->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.ui_LAP & 0x000F0000) >> 16 );
        edtCTLDILAP4->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.ui_LAP & 0x0000F000) >> 12 );
        edtCTLDILAP3->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.ui_LAP & 0x00000F00) >>  8 );
        edtCTLDILAP2->Text = (AnsiString) str;
        sprintf( str, "%X", (m_sLocalBdAddr.ui_LAP & 0x000000F0) >>  4 );
        edtCTLDILAP1->Text = (AnsiString) str;
        sprintf( str, "%X", m_sLocalBdAddr.ui_LAP & 0x0000000F );
        edtCTLDILAP0->Text = (AnsiString) str;
    }

    // ACL BD address
    if( draw_mask & DRAM_MASK_CT_ACL_BDADDR )
    {
        AnsiString as_bd_addr;
        char str[3];
        for( int i=BD_ADDRESS_LEN-1; i>=0; i-- )
        {
            if( m_sCTACLBdAddr.uc_BD_Addr[i] <= 0x0F )
                sprintf( str, "0%X", m_sCTACLBdAddr.uc_BD_Addr[i] );
            else
                sprintf( str, "%X", m_sCTACLBdAddr.uc_BD_Addr[i] );
            AnsiString as_str(str);
            if( i != 0 )  as_str += ":";
            as_bd_addr+= as_str;
        }
        m_stCTACLBDAddr->Caption = as_bd_addr;
    }

    // SCO BD address
    if( draw_mask & DRAM_MASK_CT_SCO_BDADDR )
    {
        AnsiString as_bd_addr;
        char str[3];
        for( int i=BD_ADDRESS_LEN-1; i>=0; i-- )
        {
            if( m_sSCOBdAddr.uc_BD_Addr[i] <= 0x0F )
                sprintf( str, "0%X", m_sSCOBdAddr.uc_BD_Addr[i] );
            else
                sprintf( str, "%X", m_sSCOBdAddr.uc_BD_Addr[i] );
            AnsiString as_str(str);
            if( i != 0 )  as_str += ":";
            as_bd_addr+= as_str;
        }
        m_stCTSCOBDAddr->Caption = as_bd_addr;
    }

    // discovered list
    if( draw_mask & DRAM_MASK_CT_DISCOVERED_LIST )
    {
        DisplayInquiryBDList();
    }

    // connect list
    if( draw_mask & DRAM_MASK_CT_CONNECT_LIST )
    {
        DisplayConnectBDList();
    }

    // ACL connect status
    if( draw_mask & DRAM_MASK_CT_ACL_STATUS )
    {
        vector<S_BT_CT_RES>:: iterator iter;
        vector<S_BT_CT_RES> *pvCTRes = m_cBT_CT_Obj.Get_CtResVector();
        bool match = false;
        for( iter = pvCTRes->begin(); iter != pvCTRes->end(); iter++ )
        {
            match = true;
            for(int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] != m_sCTACLBdAddr.uc_BD_Addr[i] )
                {
                    match = false;
                    break;
                }
            }

            if( match )
                break;
        }

        if (match)
        {
            switch (iter->e_acl_status)
            {
            case BT_ACL_STATUS_SUCCESS:
            {
                stCTACLStatus->Caption = (AnsiString) STR_BT_ACL_SUCCESS;
            }
            break;

            case BT_ACL_STATUS_PAGE_TIMEOUT:
            {
                stCTACLStatus->Caption = (AnsiString) STR_BT_ACL_PAGE_TIMEOUT;
            }
            break;

            case BT_ACL_STATUS_FAIL:
            {
                stCTACLStatus->Caption = (AnsiString) STR_BT_ACL_FAIL;
            }
            break;

            case BT_ACL_STATUS_NONE:
            default:
            {
                stCTACLStatus->Caption = (AnsiString) "";
            }
            break;
            }
        }
    }

    // SCO connect status
    if (draw_mask & DRAM_MASK_CT_SCO_STATUS)
    {
        vector<S_BT_CT_RES>:: iterator iter;
        vector<S_BT_CT_RES> *pvCTRes = m_cBT_CT_Obj.Get_CtResVector();
        bool match;
        for (iter = pvCTRes->begin(); iter != pvCTRes->end(); iter++)
        {
            match = true;
            for(int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if (iter->s_bd_addr.uc_BD_Addr[i] != m_sSCOBdAddr.uc_BD_Addr[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                break;
            }
        }

        if (match && iter != NULL)
        {
            switch (iter->e_sco_status)
            {
            case BT_CT_SCO_STATUS_SUCCESS:
            {
                stCTSCOStatus->Caption = (AnsiString) STR_BT_CT_SCO_SUCCESS;
            }
            break;

            case BT_CT_SCO_STATUS_FAIL:
            {
                stCTSCOStatus->Caption = (AnsiString) STR_BT_CT_SCO_FAIL;
            }
            break;

            default:
            case BT_CT_SCO_STATUS_NONE:
            {
                stCTSCOStatus->Caption = (AnsiString) "";
            }
            break;
            }
        }
    }

    // button
    if (draw_mask & DRAM_MASK_CT_BUTTON)
    {
        if (1 == btnCTInquiryStart->Tag)
        {
            btnCTScan->Enabled = false;
            btnCTAutoAccept->Enabled = false;
            btnCTEnterPIN->Enabled = false;
            btnCTConnectSCO->Enabled = false;
            btnCTDisconnectSCO->Enabled = false;
            btnCTConnectACL->Enabled = false;
            btnCTDisconnectACL->Enabled = false;
            btnCTChangeAclPktType->Enabled = false;
        }
        else
        {
            int acl_result = stCTACLStatus->Caption.AnsiCompareIC(STR_BT_ACL_SUCCESS);
            int sco_result = stCTSCOStatus->Caption.AnsiCompareIC(STR_BT_CT_SCO_SUCCESS);
            btnCTScan->Enabled = true;
            btnCTAutoAccept->Enabled = true;
            btnCTEnterPIN->Enabled = false;
            if (1 == acl_result)
            {
                btnCTConnectSCO->Enabled = false;
                btnCTDisconnectSCO->Enabled = false;
            }
            else
            {
                btnCTConnectSCO->Enabled = sco_result;
                btnCTDisconnectSCO->Enabled = !sco_result;
            }
            btnCTConnectACL->Enabled = acl_result;
            btnCTDisconnectACL->Enabled = !acl_result;
            if ((0 == acl_result) && (0 != sco_result))
            {
                btnCTChangeAclPktType->Enabled = true;
            }
            else
            {
                btnCTChangeAclPktType->Enabled = false;
            }
        }
    }


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTLDIReadClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Read local BD address progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_ReadLocalBDAddr;
    m_cBT_CT_Obj.REQ_ReadLocalBDAddress_Start( m_sBTCT );
}
//---------------------------------------------
void  TfrmBT::CNF_CT_ReadLocalBDAddr( void )
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sLocalBdAddr = m_cBT_CT_Obj.Get_LocalBdAddr();
        ReDrawCTFields(DRAM_MASK_CT_LOCAL_BDADDR);
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address fail";
        Application->MessageBox( "Execution Failure : Read local BD address", "FAILURE", MB_OK );
        Application->BringToFront();

    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address timeout";
        Application->MessageBox( "Execution Timeout : Read local BD address", "TIMEOUT", MB_OK );
        Application->BringToFront();

    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address stop";

    }
    break;
    }
    CurrentPageReset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTResetLDClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Reset local device progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_Reset;
    m_cBT_CT_Obj.REQ_Reset_Start( m_sBTCT );
}
//---------------------------------------------
void  TfrmBT::CNF_CT_Reset( void )
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();
    CurrentPageReset();
    switch( state )
    {
    case META_SUCCESS:
    {
        ReDrawCTFields( DRAM_MASK_CT_DISCOVERED_LIST |
                        DRAM_MASK_CT_CONNECT_LIST    |
                        DRAM_MASK_CT_BUTTON          |
                        DRAM_MASK_CT_ACL_STATUS      |
                        DRAM_MASK_CT_SCO_STATUS
                      );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Reset local device successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Reset local device fail";
        Application->MessageBox( "Execution Failure : Reset local device", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Reset local device timeout";
        Application->MessageBox( "Execution Timeout : Reset local device", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Reset local device stop";

    }
    break;
    }

}
//--------------------------------------------------------------------------
void TfrmBT::FillCTResult( void )
{

    for(int i=0; i<m_pCTLog->Count; i++ )
    {
        AnsiString as = m_pCTLog->Strings[i];
        memCTResult->Lines->Add( as );
    }
    m_pCTLog->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTLDIWriteClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;
    m_cBT_CT_Obj.Set_LocalBdAddr( m_sLocalBdAddr );
    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Write local BD address progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_WriteLocalBDAddr;
    m_cBT_CT_Obj.REQ_WriteLocalBDAddress_Start( m_sBTCT );
}
//---------------------------------------------
void  TfrmBT::CNF_CT_WriteLocalBDAddr(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Write local BD address successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address fail";
        Application->MessageBox( "Execution Failure : Read local BD address", "FAILURE", MB_OK );
        Application->BringToFront();

    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address timeout";
        Application->MessageBox( "Execution Timeout : Read local BD address", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Read local BD address stop";
    }
    break;
    }
    CurrentPageReset();
}
//------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTLDINAPCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 3 == edit->Tag )
    {
        m_sLocalBdAddr.us_NAP = (m_sLocalBdAddr.us_NAP & 0x0FFF) | ((ucdata &0xF)<<12);
    }
    else if( 2 == edit->Tag )
    {
        m_sLocalBdAddr.us_NAP = (m_sLocalBdAddr.us_NAP & 0xF0FF) | ((ucdata &0xF)<<8);
    }
    else if( 1 == edit->Tag )
    {
        m_sLocalBdAddr.us_NAP = (m_sLocalBdAddr.us_NAP & 0xFF0F) | ((ucdata &0xF)<<4);
    }
    else
    {
        m_sLocalBdAddr.us_NAP = (m_sLocalBdAddr.us_NAP & 0xFFF0) | (ucdata &0xF);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTLDIUAPCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 1 == edit->Tag )
    {
        m_sLocalBdAddr.uc_UAP = (m_sLocalBdAddr.uc_UAP & 0x0F) | ((ucdata & 0xF)<<4);
    }
    else
    {
        m_sLocalBdAddr.uc_UAP = (m_sLocalBdAddr.uc_UAP & 0xF0) | (ucdata & 0xF);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTLDILAPCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~F ";

    text = edit->Text;
    if( !IsValidHexBDAddress( text, ucdata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    if( 5 == edit->Tag )
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0x0FFFFF) | ((ucdata & 0xF)<<20);
    }
    else if( 4 == edit->Tag )
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0xF0FFFF) | ((ucdata & 0xF)<<16);
    }
    else if( 3 == edit->Tag )
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0xFF0FFF) | ((ucdata & 0xF)<<12);
    }
    else if( 2 == edit->Tag )
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0xFFF0FF) | ((ucdata & 0xF)<<8);
    }
    else if( 1 == edit->Tag )
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0xFFFF0F) | ((ucdata & 0xF)<<4);
    }
    else
    {
        m_sLocalBdAddr.ui_LAP = (m_sLocalBdAddr.ui_LAP & 0xFFFFF0) | (ucdata & 0xF);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTInquiryStartClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;
    m_sBTCT.list               = lbCTDisDevices->Items;
    m_cBT_CT_Obj.Set_InquiryTimeout( m_uiInquiryTimeout );
    //  lbCTDisDevices->Clear();
    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Inquiry progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_Inquiry;
    m_cBT_CT_Obj.REQ_Inquiry_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_Inquiry(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Inquiry successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Inquiry fail";
        Application->MessageBox( "Execution Failure : Inquiry", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop(false);
        m_sBTCT.hPostMsgDestHandle = this->Handle;
        m_sBTCT.log                = m_pCTLog;
        m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_InquiryCancel;
        m_cBT_CT_Obj.REQ_Inquiry_Cancel_Start(m_sBTCT);
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Inquiry timeout";
        Application->MessageBox( "Execution Timeout : Inquiry", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Inquiry stop";

    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayInquiryBDList( void )
{
    vector<S_BT_CT_RES> *pvCTRes = m_cBT_CT_Obj.Get_CtResVector();
    vector<S_BT_CT_RES>:: iterator iter;
    lbCTDisDevices->Clear();
    for( iter = pvCTRes->begin(); iter != pvCTRes->end(); iter++ )
    {
        if( iter->e_acl_status != BT_ACL_STATUS_SUCCESS )
        {
            AnsiString as_bd_addr;
            char str[3];
            for( int i=BD_ADDRESS_LEN-1; i>=0; i-- )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] <= 0x0F )
                    sprintf( str, "0%X", iter->s_bd_addr.uc_BD_Addr[i] );
                else
                    sprintf( str, "%X", iter->s_bd_addr.uc_BD_Addr[i] );
                AnsiString as_str(str);
                if( i != 0 )
                    as_bd_addr+= as_str + ":";
                else
                    as_bd_addr+= as_str;
            }
            lbCTDisDevices->Items->Add( as_bd_addr );
        }
    }
}
//---------------------------------------------------------------------------
void TfrmBT::DisplayConnectBDList( void )
{
    vector<S_BT_CT_RES> *pvCTRes = m_cBT_CT_Obj.Get_CtResVector();
    vector<S_BT_CT_RES>:: iterator iter;
    lbCTConDevices->Clear();
    for( iter = pvCTRes->begin(); iter != pvCTRes->end(); iter++ )
    {
        if(  BT_ACL_STATUS_SUCCESS == iter->e_acl_status )
        {
            AnsiString as_bd_addr;
            char str[3];
            for( int i=BD_ADDRESS_LEN-1; i>=0; i-- )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] <= 0x0F )
                    sprintf( str, "0%X", iter->s_bd_addr.uc_BD_Addr[i] );
                else
                    sprintf( str, "%X", iter->s_bd_addr.uc_BD_Addr[i] );
                AnsiString as_str(str);
                if( i != 0 )
                    as_bd_addr+= as_str + ":";
                else
                    as_bd_addr+= as_str;
            }
            lbCTConDevices->Items->Add( as_bd_addr );
        }
    }
}
//--------------------------------------------------------------------------
S_BD_ADDR TfrmBT::Get_BDAddrFromString( AnsiString as_str )
{
    //int iLD;
    // AnsiString as_bd_addr;
    S_BD_ADDR bd_addr;
    unsigned char str[BD_ADDRESS_LEN];

    AnsiString_Hex_To_Array_UnsignedChar( as_str, str, BD_ADDRESS_LEN, ':' );
    for( int i=0; i<BD_ADDRESS_LEN; i++ )
    {
        bd_addr.uc_BD_Addr[i] = str[BD_ADDRESS_LEN-i-1];
    }
    return  bd_addr;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::edtCTInquiryTimeoutCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~10000000 ";

    text = edit->Text;
    if( !IsValidBTTimeout( text, uidata ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiInquiryTimeout = uidata * 1.28 * 1000;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btCTClearLogClick(TObject *Sender)
{
    memCTResult->Clear();
}
//-------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTScanClick(TObject *Sender)
{
    S_BT_SCAN scan;
    scan.e_scan_type = (E_BT_SCAN_TYPE) cbCTScanType->ItemIndex;
    scan.b_interlaced_inquiry_scan = cbCTInterlacedInquiryScan->Checked;
    scan.b_interlaced_page_scan = cbInterlacedPageScan->Checked;
    m_cBT_CT_Obj.Set_ScanParameter( scan );

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Set scan parameter progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_Scan;
    m_cBT_CT_Obj.REQ_Scan_Start( m_sBTCT );
}
//---------------------------------------------
void TfrmBT::CNF_CT_Scan(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter fail";
        Application->MessageBox( "Execution Failure : Set scan parameter", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter timeout";
        Application->MessageBox( "Execution Timeout : Set scan parameter", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::lbCTDisDevicesClick(TObject *Sender)
{
    m_sCTACLBdAddr = Get_BDAddrFromString( lbCTDisDevices->Items->Strings[lbCTDisDevices->ItemIndex] );
    m_sSCOBdAddr = m_sCTACLBdAddr;
    ReDrawCTFields( DRAM_MASK_CT_ACL_BDADDR |
                    DRAM_MASK_CT_SCO_BDADDR |
                    DRAM_MASK_CT_ACL_STATUS |
                    DRAM_MASK_CT_SCO_STATUS |
                    DRAM_MASK_CT_BUTTON);
}
//---------------------------------------------------------------------------
unsigned short TfrmBT::Get_CTAclPacketType( void )
{
    unsigned short pkt_type=0;
    if( cbCTDM1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM1;
    }

    if( cbCTDH1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH1;
    }

    if( cbCTDM3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM3;
    }

    if( cbCTDH3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH3;
    }

    if( cbCTDM5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM5;
    }

    if( cbCTDH5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH5;
    }

    // BT 2.0
    if( ! cbCT2DH1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_2DH1;
    }

    if( ! cbCT3DH1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_3DH1;
    }

    if( ! cbCT2DH3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_2DH3;
    }

    if( ! cbCT3DH3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_3DH3;
    }

    if( ! cbCT2DH5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_2DH5;
    }

    if( ! cbCT3DH5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_3DH5;
    }

    return pkt_type;
}
//---------------------------------------------------------------------------
E_SCO_PKT_MASK TfrmBT::Get_ScoPacketType( void )
{
    return (E_SCO_PKT_MASK) cbCTSCOPktType->ItemIndex;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTConnectACLClick(TObject *Sender)
{
    if ((!cbCTDM1->Checked) &&
            (!cbCTDH1->Checked) &&
            (!cbCTDM3->Checked) &&
            (!cbCTDH3->Checked) &&
            (!cbCTDM5->Checked) &&
            (!cbCTDH5->Checked) &&
            (!cbCT2DH1->Checked) &&
            (!cbCT2DH3->Checked) &&
            (!cbCT2DH5->Checked) &&
            (!cbCT3DH1->Checked) &&
            (!cbCT3DH3->Checked) &&
            (!cbCT3DH5->Checked)
       )
    {
        Application->MessageBox("Please select at least one ACL packet type", "WARRNING", MB_OK);
        Application->BringToFront();
        return;
    }

    if (m_stCTACLBDAddr->Caption.AnsiCompareIC("") == 0)
    {
        Application->MessageBox("BD address is incorrect", "WARRNING", MB_OK);
        Application->BringToFront();
        return;
    }

    S_BT_CONNECT_ACL connect;

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    connect.us_acl_pkt_type = Get_CTAclPacketType();
    connect.s_bd_addr       = m_sCTACLBdAddr;
    m_cBT_CT_Obj.Set_ConnectACLParameter(connect);

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Connect ACL link progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_ConnectACL;
    m_cBT_CT_Obj.REQ_ConnectACL_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_ConnectACL(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();
    CurrentPageReset();
    switch( state )
    {
    case META_SUCCESS:
    {
        ReDrawCTFields( DRAM_MASK_CT_DISCOVERED_LIST |
                        DRAM_MASK_CT_CONNECT_LIST    |
                        DRAM_MASK_CT_ACL_STATUS      |
                        DRAM_MASK_CT_BUTTON );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link fail";
        Application->MessageBox( "Execution Failure : Connect ACL link", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link timeout";
        Application->MessageBox( "Execution Timeout : Connect ACL link", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link stop";
    }
    break;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTInquiryStopClick(TObject *Sender)
{
    Force_BT_Stop( false );

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Cancel inquiry progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_InquiryCancel;
    m_cBT_CT_Obj.REQ_Inquiry_Cancel_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_InquiryCancel(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Cancel inquiry successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Cancel inquiry fail";
        Application->MessageBox( "Execution Failure : Cancel inquiry", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        DisplayInquiryBDList();
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Cancel inquiry timeout";
        Application->MessageBox( "Execution Timeout : Cancel inquiry", "TIMEOUT", MB_OK );
        Application->BringToFront();

    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        DisplayInquiryBDList();
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Cancel inquiry stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTAutoAcceptClick(TObject *Sender)
{

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Auto accept progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_AutoAccept;
    m_cBT_CT_Obj.REQ_Auto_Accept_Start( m_sBTCT );
}
//---------------------------------------------
void TfrmBT::CNF_CT_AutoAccept(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Auto accept successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Auto accept fail";
        Application->MessageBox( "Execution Failure : Auto accept", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Auto accept timeout";
        Application->MessageBox( "Execution Timeout : Auto accept", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Auto accept stop";
    }
    break;
    }
    CurrentPageReset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTDisconnectACLClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    S_BT_DISCONNECT_ACL disconnect;
    disconnect.s_bd_addr       = m_sCTACLBdAddr;
    m_cBT_CT_Obj.Set_DisconnectACLParameter( disconnect );

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Disconnect progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_DisconnectACL;
    m_cBT_CT_Obj.REQ_DisconnectACL_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_DisconnectACL(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        ReDrawCTFields( DRAM_MASK_CT_DISCOVERED_LIST |
                        DRAM_MASK_CT_CONNECT_LIST    |
                        DRAM_MASK_CT_ACL_STATUS      |
                        DRAM_MASK_CT_BUTTON);
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect fail";
        Application->MessageBox( "Execution Failure : Disconnect", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect timeout";
        Application->MessageBox( "Execution Timeout : Disconnect", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::lbCTConDevicesClick(TObject *Sender)
{
    m_sCTACLBdAddr = Get_BDAddrFromString( lbCTConDevices->Items->Strings[lbCTConDevices->ItemIndex] );
    m_sSCOBdAddr = m_sCTACLBdAddr;
    ReDrawCTFields( DRAM_MASK_CT_ACL_BDADDR |
                    DRAM_MASK_CT_SCO_BDADDR |
                    DRAM_MASK_CT_ACL_STATUS |
                    DRAM_MASK_CT_SCO_STATUS |
                    DRAM_MASK_CT_BUTTON);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTChangeAclPktTypeClick(TObject *Sender)
{
    if( (! cbCTDM1->Checked) &&
            (! cbCTDH1->Checked) &&
            (! cbCTDM3->Checked) &&
            (! cbCTDH3->Checked) &&
            (! cbCTDM5->Checked) &&
            (! cbCTDH5->Checked)
      )
    {
        Application->MessageBox( "Please select at least one ACL packet type", "WARRNING", MB_OK );
        Application->BringToFront();
        return;
    }

    S_BT_CONNECT_ACL connect;

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    connect.us_acl_pkt_type = Get_CTAclPacketType();
    connect.s_bd_addr       = m_sCTACLBdAddr;
    m_cBT_CT_Obj.Set_ConnectACLParameter( connect );

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Change ACL packet type progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_ChangeACLPacketType;
    m_cBT_CT_Obj.REQ_Change_ACL_Packet_Type_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_ChangeACLPacketType(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type fail";
        Application->MessageBox( "Execution Failure : Change ACL packet type", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type timeout";
        Application->MessageBox( "Execution Timeout : Change ACL packet type", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type stop";
    }
    break;
    }
    CurrentPageReset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTConnectSCOClick(TObject *Sender)
{
    if (m_stCTSCOBDAddr->Caption.AnsiCompareIC("") == 0)
    {
        Application->MessageBox("BD address is incorrect", "WARRNING", MB_OK);
        Application->BringToFront();
        return;
    }

    CurrentPageLock();
    sbCT->Panels->Items[0]->Text = (AnsiString) "  Connect SCO link progressing";

    S_BT_CT_CONNECT_SCO connect;
    connect.s_bd_addr  = m_sSCOBdAddr;
    connect.e_pkt_type = Get_ScoPacketType();
    m_cBT_CT_Obj.Set_ConnectSCOParameter(connect);

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_ConnectSCO;
    m_cBT_CT_Obj.REQ_ConnectSCO_Start( m_sBTCT );
}
//-----------------------------------------
void TfrmBT::CNF_CT_ConnectSCO(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        ReDrawCTFields( DRAM_MASK_CT_SCO_STATUS | DRAM_MASK_CT_BUTTON );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect SCO link successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect SCO link fail";
        Application->MessageBox( "Execution Failure : Connect SCO link ", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect SCO link timeout";
        Application->MessageBox( "Execution Timeout : Connect SCO link ", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Connect SCO link stop";
    }
    break;
    }
    CurrentPageReset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnCTDisconnectSCOClick(TObject *Sender)
{
    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    S_BT_CT_DISCONNECT_SCO disconnect;
    disconnect.s_bd_addr  = m_sSCOBdAddr;
    m_cBT_CT_Obj.Set_DisconnectSCOParameter(disconnect);

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Disconnect SCO link progressing";
    m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_DisconnectSCO;
    m_cBT_CT_Obj.REQ_DisconnectSCO_Start(m_sBTCT);
}
//-----------------------------------------
void TfrmBT::CNF_CT_DisconnectSCO(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        ReDrawCTFields(DRAM_MASK_CT_SCO_STATUS | DRAM_MASK_CT_BUTTON);
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect SCO link successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect SCO link fail";
        Application->MessageBox("Execution Failure : Disconnect SCO link ", "FAILURE", MB_OK);
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop(false);
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect SCO link timeout";
        Application->MessageBox("Execution Timeout : Disconnect SCO link ", "TIMEOUT", MB_OK);
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Disconnect SCO link stop";
    }
    break;
    }
    CurrentPageReset();
}
//-------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTPINCheck(TObject *Sender)
{
    AnsiString  text;
    S_BT_PIN  pin;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x0~0xFFFFFFFFFFFFFFFF ";

    text = edit->Text;
    if( !IsValidHexBTPIN( text, pin ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sBTPIN = pin;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnCTEnterPINClick(TObject *Sender)
{
    S_BT_ENTER_PIN enter_pin;

    m_sBTCT.hPostMsgDestHandle = this->Handle;
    m_sBTCT.log                = m_pCTLog;

    enter_pin.s_bd_addr  = m_sSCOBdAddr;
    enter_pin.s_bt_pin   = m_sBTPIN;
    m_cBT_CT_Obj.Set_EnterPINParameter( enter_pin );

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Enter PIN progressing";
    // m_cBT_CT_Obj.ConfirmCallback  = ::CNF_CT_EnterPIN;
    if( ! m_cBT_CT_Obj.REQ_EnterPIN_Start( m_sBTCT ) )
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN successfully";
        return;
    }

    sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN fail";
}
//-----------------------------------------
void TfrmBT::CNF_CT_EnterPIN(void)
{
    META_RESULT state = m_cBT_CT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN successfully";
    }
    break;

    case META_FAILED:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN fail";
        Application->MessageBox( "Execution Failure : Enter PIN ", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN timeout";
        Application->MessageBox( "Execution Timeout : Enter PIN ", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Enter PIN stop";
    }
    break;
    }
    CurrentPageReset();
}
//============================================================================
///////////////////////////  Throughput test  ////////////////////////////////
//============================================================================
void  TfrmBT::ReDrawTTFields( E_DRAM_MASK_TT draw_mask )
{
    if( draw_mask & DRAM_MASK_TT_ACL_STATUS )
    {
        switch( m_sBTTTRes.e_acl_status )
        {
        case BT_ACL_STATUS_SUCCESS:
            stTTACLStatus->Caption = (AnsiString ) STR_BT_ACL_SUCCESS;
            break;

        case BT_ACL_STATUS_PAGE_TIMEOUT:
            stTTACLStatus->Caption = (AnsiString ) STR_BT_ACL_PAGE_TIMEOUT;
            break;

        case BT_ACL_STATUS_FAIL:
            stTTACLStatus->Caption = (AnsiString ) STR_BT_ACL_FAIL;
            break;

        default:
        case BT_ACL_STATUS_NONE:
            stTTACLStatus->Caption = (AnsiString ) "";
            break;
        }
    }

    if( draw_mask & DRAM_MASK_TT_BUTTON )
    {
        int acl_result = stTTACLStatus->Caption.AnsiCompareIC(STR_BT_ACL_SUCCESS);
        btnTTScan->Enabled                = true;
        btnTTAutoAccept->Enabled          = true;
        btnTTConnect->Enabled             = (bool) acl_result;
        btnTTDisconnect->Enabled          = ! (bool) acl_result;
        btnTTChangeACLPacketType->Enabled = ! (bool) acl_result;
        btnTTTxStart->Enabled             = ! (bool) acl_result;
        btnTTTxStart->Tag                 = 0;
        btnTTRxStart->Enabled             = ! (bool) acl_result;
        btnTTRxStart->Tag                 = 0;
    }
}
//----------------------------------------------------------------------------
bool  TfrmBT::CheckTTFields( E_CHECK_MASK_TT mask )
{
    if( CHECK_MASK_TT_BD_ADDR == mask )
    {
        AnsiString text;
        text = edtTTBDAddr->Text;
        if( !IsValidHexBDAddress( text, m_sTTACLBdAddr ) )
        {
            edtTTBdAddrCheck(edtTTBDAddr);
            return false;
        }
    }
    else if( CHECK_MASK_TT_TX == mask )
    {
    }

    return true;
}
//----------------------------------------------------------------------------
void  TfrmBT::FillTTResult( void )
{
    for(int i=0; i<m_pTTLog->Count; i++ )
    {
        AnsiString as = m_pTTLog->Strings[i];
        memTTResult->Lines->Add( as );
    }
    m_pTTLog->Clear();
}
//----------------------------------------------------------------------------
unsigned short TfrmBT::Get_TTAclPacketType( void )
{
    unsigned short pkt_type=0;
    if( cbTTDM1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM1;
    }

    if( cbTTDH1->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH1;
    }

    if( cbTTDM3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM3;
    }

    if( cbTTDH3->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH3;
    }

    if( cbTTDM5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DM5;
    }

    if( cbTTDH5->Checked )
    {
        pkt_type |= ACL_PKT_MASK_DH5;
    }

    return pkt_type;
}
//--------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTConnectClick(TObject *Sender)
{
    if ((!cbTTDM1->Checked) &&
            (!cbTTDH1->Checked) &&
            (!cbTTDM3->Checked) &&
            (!cbTTDH3->Checked) &&
            (!cbTTDM5->Checked) &&
            (!cbTTDH5->Checked) &&
            (!m_cbTT2DH1->Checked) &&
            (!m_cbTT2DH3->Checked) &&
            (!m_cbTT2DH5->Checked) &&
            (!m_cbTT3DH1->Checked) &&
            (!m_cbTT3DH3->Checked) &&
            (!m_cbTT3DH5->Checked)
       )
    {
        Application->MessageBox( "Please select at least one ACL packet type", "WARRNING", MB_OK );
        Application->BringToFront();
        return;
    }

    if( ! CheckTTFields( CHECK_MASK_TT_BD_ADDR ) )
    {
        return;
    }

    S_BT_CONNECT_ACL connect;

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;

    connect.us_acl_pkt_type = Get_TTAclPacketType();
    connect.s_bd_addr       = m_sTTACLBdAddr;
    m_cBT_TT_Obj.Set_ConnectACLParameter( connect );

    CurrentPageLock();

    sbCT->Panels->Items[0]->Text = (AnsiString) "  Connect ACL link progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_ConnectACL;
    m_cBT_TT_Obj.REQ_ConnectACL_Start( m_sBTTT );
}
//-----------------------------------------
void TfrmBT::CNF_TT_ConnectACL(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();
    CurrentPageReset();
    switch (state)
    {
    case META_SUCCESS:
    {
        m_sBTTTRes = m_cBT_TT_Obj.Get_TTResult();
        ReDrawTTFields( DRAM_MASK_TT_ACL_STATUS |
                        DRAM_MASK_TT_BUTTON );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link fail";
        Application->MessageBox( "Execution Failure : Connect ACL link", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link timeout";
        Application->MessageBox( "Execution Timeout : Connect ACL link", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Connect ACL link stop";
    }
    break;
    }

}
//----------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTDisconnectClick(TObject *Sender)
{
    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;

    S_BT_DISCONNECT_ACL disconnect;
    disconnect.s_bd_addr       = m_sTTACLBdAddr;
    m_cBT_TT_Obj.Set_DisconnectACLParameter( disconnect );

    CurrentPageLock();

    sbTT->Panels->Items[0]->Text = (AnsiString) "  Disconnect progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_DisconnectACL;
    m_cBT_TT_Obj.REQ_DisconnectACL_Start( m_sBTTT );
}
//-----------------------------------------
void TfrmBT::CNF_TT_DisconnectACL(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_sBTTTRes = m_cBT_TT_Obj.Get_TTResult();
        ReDrawTTFields(
            DRAM_MASK_TT_ACL_STATUS      |
            DRAM_MASK_TT_BUTTON);
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Disconnect successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Disconnect fail";
        Application->MessageBox( "Execution Failure : Disconnect", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Disconnect timeout";
        Application->MessageBox( "Execution Timeout : Disconnect", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Disconnect stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtTTDataLenCheck(TObject *Sender)
{
    bool ok;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    unsigned short  us_data;

    AnsiString as_hint[] = {" value should be 1~339 ", " value should be 1~1021 "};


    text = edit->Text;
    if (BTMODULE_MT6611 != m_cBtId)
    {
        ok = IsValidBTTxDataLength(text, us_data, 1, 339);
    }
    else
    {
        ok = IsValidBTTxDataLength(text, us_data, 1, 1021);
    }

    if (!ok)
    {
        if (BTMODULE_MT6611 != m_cBtId)
        {
            edit->Text = IntToStr(339);
            ShowHintLabel( edit, as_hint[0].c_str());
        }
        else
        {
            edit->Text = IntToStr(1021);
            ShowHintLabel( edit, as_hint[1].c_str());
        }
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtTTPacketCountCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~4294967295 "
    };

    text = edit->Text;
    if( !IsValidBTTxPacketCount( text, ui_data ) )
    {
        edit->Text = 1000;
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTChangeACLPacketTypeClick(TObject *Sender)
{
    if( (! cbTTDM1->Checked) &&
            (! cbTTDH1->Checked) &&
            (! cbTTDM3->Checked) &&
            (! cbTTDH3->Checked) &&
            (! cbTTDM5->Checked) &&
            (! cbTTDH5->Checked)
      )
    {
        Application->MessageBox( "Please select at least one ACL packet type", "WARRNING", MB_OK );
        Application->BringToFront();
        return;
    }

    S_BT_CONNECT_ACL connect;

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;

    connect.us_acl_pkt_type = Get_TTAclPacketType();
    connect.s_bd_addr       = m_sTTACLBdAddr;
    m_cBT_TT_Obj.Set_ConnectACLParameter( connect );

    CurrentPageLock();

    sbTT->Panels->Items[0]->Text = (AnsiString) "  Change ACL packet type progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_ChangeACLPacketType;
    m_cBT_TT_Obj.REQ_Change_ACL_Packet_Type_Start( m_sBTTT );
}
//-----------------------------------------
void TfrmBT::CNF_TT_ChangeACLPacketType(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type fail";
        Application->MessageBox( "Execution Failure : Change ACL packet type", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type timeout";
        Application->MessageBox( "Execution Timeout : Change ACL packet type", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Change ACL packet type stop";
    }
    break;
    }
    CurrentPageReset();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBT::btnTTTxStartClick(TObject *Sender)
{
    CurrentPageLock();

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;
    stTTTxCount->Caption = "0";
    stTTTxThroughput->Caption = "0";

    S_BT_TT_TX_PARAMETER tx_par;
    tx_par.us_data_len     = edtTTDataLen->Text.ToInt();
    tx_par.us_packet_count = edtTTPacketCount->Text.ToInt();
    m_cBT_TT_Obj.Set_TxParameter( tx_par );

    m_sTTTxStartTime = ::Get_CurrentTime();
    sbTT->Panels->Items[0]->Text = (AnsiString) "  Transmit BT data progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_TxData;
    m_cBT_TT_Obj.REQ_TX_Data_Start(m_eTtVer, m_sBTTT);
}
//----------------------------------
void TfrmBT::CNF_TT_TxData(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Transmit BT data successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Transmit BT data fail";
        Application->MessageBox( "Execution Failure : Transmit BT data", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Transmit BT data timeout";
        Application->MessageBox( "Execution Timeout : Transmit BT data", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Transmit BT data stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtTTBdAddrCheck(TObject *Sender)
{
    S_BD_ADDR  bd_addr;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " BD address is not valid "
    };

    text = edit->Text;
    if( !IsValidHexBDAddress( text, bd_addr ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_sTTACLBdAddr = bd_addr;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTRxStartClick(TObject *Sender)
{
    CurrentPageLock();

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;
    stTTRxBytes->Caption = "0";
    stTTRxThroughput->Caption = "0";
    m_sTTRxStartTime = ::Get_CurrentTime();
    sbTT->Panels->Items[0]->Text = (AnsiString) "  Receive BT data progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_RxData;
    m_cBT_TT_Obj.REQ_RX_Data_Start(m_eTtVer, m_sBTTT);
}
//----------------------------------
void TfrmBT::CNF_TT_RxData(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Receive BT data successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Receive BT data fail";
        Application->MessageBox( "Execution Failure : Receive BT data", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Receive BT data timeout";
        Application->MessageBox( "Execution Timeout : Receive BT data", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Receive BT data stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTScanClick(TObject *Sender)
{
    S_BT_SCAN scan;
    scan.e_scan_type = (E_BT_SCAN_TYPE) cbCTScanType->ItemIndex;
    scan.b_interlaced_inquiry_scan = cbCTInterlacedInquiryScan->Checked;
    scan.b_interlaced_page_scan = cbInterlacedPageScan->Checked;
    m_cBT_TT_Obj.Set_ScanParameter( scan );

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;

    CurrentPageLock();

    sbTT->Panels->Items[0]->Text = (AnsiString) "  Set scan parameter progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_CT_Scan;
    m_cBT_TT_Obj.REQ_Scan_Start( m_sBTTT );
}
//---------------------------------------------
void TfrmBT::CNF_TT_Scan(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter fail";
        Application->MessageBox( "Execution Failure : Set scan parameter", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter timeout";
        Application->MessageBox( "Execution Timeout : Set scan parameter", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Set scan parameter stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTAutoAcceptClick(TObject *Sender)
{
    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;

    CurrentPageLock();

    sbTT->Panels->Items[0]->Text = (AnsiString) "  Auto accept progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_AutoAccept;
    m_cBT_TT_Obj.REQ_Auto_Accept_Start( m_sBTTT );
}
//---------------------------------------------
void TfrmBT::CNF_TT_AutoAccept(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Auto accept successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Auto accept fail";
        Application->MessageBox( "Execution Failure : Auto accept", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbCT->Panels->Items[0]->Text = (AnsiString)"  Auto accept timeout";
        Application->MessageBox( "Execution Timeout : Auto accept", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Auto accept stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTTxStopClick(TObject *Sender)
{
    m_cBT_TT_Obj.REQ_Stop_Start();
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTTxBandwidthCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  ui_data;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x0~0xFFFFFFFF ";

    text = edit->Text;
    if( !IsValidTxBandwidth( text, &ui_data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiTxBandwidth = ui_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTRxBandwidthCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  ui_data;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x0~0xFFFFFFFF ";

    text = edit->Text;
    if( !IsValidRxBandwidth( text, &ui_data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_uiRxBandwidth = ui_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTMaxLatencyCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned short  us_data;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x0~0xFFFF ";

    text = edit->Text;
    if( !IsValidMaxLatency( text, us_data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }

    m_usMaxLatency = us_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::edtCTRetransmitEffortCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char uc_data;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x0~0xFF ";

    text = edit->Text;
    if (!IsValidRetransmissionEffort(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_ucRetransmissionEffort = uc_data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnTTRxStopClick(TObject *Sender)
{
    CurrentPageLock();

    m_sBTTT.hPostMsgDestHandle = this->Handle;
    m_sBTTT.log                = m_pTTLog;


    sbTT->Panels->Items[0]->Text = (AnsiString) "  Stop Receiving BT data progressing";
    m_cBT_TT_Obj.ConfirmCallback  = ::CNF_TT_Stop_RxData;
    m_cBT_TT_Obj.REQ_Stop_RX_Data_Start(m_sBTTT);
}
//----------------------------------
void TfrmBT::CNF_TT_Stop_RxData(void)
{
    META_RESULT state = m_cBT_TT_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Stop Receiving BT data successfully";
    }
    break;

    case META_FAILED:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Stop Receiving BT data fail";
        Application->MessageBox( "Execution Failure : Stop Receiving BT data", "FAILURE", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop( false );
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Stop Receiving BT data timeout";
        Application->MessageBox( "Execution Timeout : Stop Receiving BT data", "TIMEOUT", MB_OK );
        Application->BringToFront();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbTT->Panels->Items[0]->Text = (AnsiString)"  Stop Receiving BT data stop";
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbPKTCOMChange(TObject *Sender)
{
    AbortConnectWithTarget();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbPKTBaudRateChange(TObject *Sender)
{
    AbortConnectWithTarget();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::m_tmMTTimer(TObject *Sender)
{
    m_tmMT->Enabled = false;
    // Add Logging String
    Script[ActIdx]->TimerTick();
    //int len = strlen(Script[ActIdx]->LogString);
    int len = Script[ActIdx]->Get_LogStringLen();
    if (len >= 2)
    {
        // if (Script[ActIdx]->LogString[len-2] == '\n')
        if (Script[ActIdx]->Get_LogString(len-2) == '\n')
        {
            //Script[ActIdx]->LogString[len-2] = 0;
            Script[ActIdx]->Set_LogString(len-2, 0);
        }
        //m_edtMTLog->Lines->Add(Script[ActIdx]->LogString);
        m_edtMTLog->Lines->Add(Script[ActIdx]->Get_LogString());
    }

    // Update progress group
    //if (Script[ActIdx]->LastProc!=Script[ActIdx]->CurProc)
    if (Script[ActIdx]->Get_LastProc() != Script[ActIdx]->Get_CurProc())
    {
        UpdateProcessGroup();
        //Script[ActIdx]->LastProc = Script[ActIdx]->CurProc;
        Script[ActIdx]->Set_LastProc(Script[ActIdx]->Get_CurProc());
        m_edtMTLog->Lines->Clear();
    }

    // Exit Timer
    //if (Script[ActIdx]->ErrorCode != ERR_FILEEND)
    if (Script[ActIdx]->Get_ErrorCode() != ERR_FILEEND)
    {
        m_tmMT->Enabled = true;
    }
    else   // End of this testing
    {
        m_tmMT->Enabled = false;
        m_btnMTRunClick(0);
        // if (Script[ActIdx]->FailCount != 0)
        if (Script[ActIdx]->Get_FailCount() != 0)
        {
            m_lblMTStatus->Font->Color = clRed;
            m_lblMTStatus->Caption = "FAIL";
            //m_edtMTLog->Lines->Add(Script[ActIdx]->LogString);
            m_edtMTLog->Lines->Add(Script[ActIdx]->Get_LogString());
        }
        else
        {
            m_lblMTStatus->Font->Color = clBlue;
            m_lblMTStatus->Caption = "PASS";
        }
        if ((LoopCount > 0) && (LoopCount != 99999))
        {
            LoopCount--;
        }
        if (LoopCount != 0)
        {
            m_edtMTRepeat->Text = LoopCount;
            scrTestItemList->Position = scrTestItemList->Min;
            m_btnMTRunClick(0);
        }
    }
}
//---------------------------------------------------------------------------
int  TfrmBT::UpdateProcessGroup(void)
{
#if 0
    int n, base;
    char str[256];
    int cidx = ActIdx;
    CBTMT *scr = Script[cidx];

    //grpTestItemList->Caption = scr->Title;
    grpTestItemList->Caption = scr->Get_Title();
    scrTestItemList->Min = 0;
    //n = scr->ProcCount - BT_MT_MAX_PROC_NUM;
    n = scr->Get_ProcCount() - BT_MT_MAX_PROC_NUM;
    scrTestItemList->Max = (n>0) ? n : 0;

    if (m_btnMTRun->Tag) //Running
    {
        //base = (scr->CurProc < BT_MT_MAX_PROC_NUM) ? 0 : (scr->CurProc-BT_MT_MAX_PROC_NUM+1);
        base = (scr->Get_CurProc() < BT_MT_MAX_PROC_NUM) ? 0 : (scr->Get_CurProc() - BT_MT_MAX_PROC_NUM + 1);
    }
    else
    {
        base = scrTestItemList->Position;
    }

    for (n=0; n<BT_MT_MAX_PROC_NUM; n++)
    {
        //if (base + n >= scr->CurProc)
        if (base + n >= scr->Get_CurProc())
        {
            break;
        }

        //if (scr->ProcFail[base+n] != 0)
        if (scr->Get_ProcFail(base+n) != 0)
        {
            lblItem[n]->Font->Color = clRed;
            lblItem[n]->Font->Style = TFontStyles()<< fsBold ;
            //sprintf(str, "%s (Fail)", scr->ProcName[base+n]);
            sprintf(str, "%s (Fail)", scr->Get_ProcName(base+n));
            lblItem[n]->Caption = str;
            lblItem[n]->Visible = true;
        }
        else
        {
            lblItem[n]->Font->Color = clBlue;
            lblItem[n]->Font->Style = TFontStyles()<< fsBold ;
            //sprintf(str, "%s (Pass)", scr->ProcName[base+n]);
            sprintf(str, "%s (Pass)", scr->Get_ProcName(base+n));
            lblItem[n]->Caption = str;
            lblItem[n]->Visible = true;
        }
    }
    if (n < BT_MT_MAX_PROC_NUM)
    {
        //if (base+n == scr->CurProc)
        if (base+n == scr->Get_CurProc())
        {
            lblItem[n]->Font->Color = clBlack;
            lblItem[n]->Font->Style = TFontStyles()<< fsBold ;
            //sprintf(str, "%s", scr->ProcName[base+n]);
            sprintf(str, "%s", scr->Get_ProcName(base+n));
            lblItem[n]->Caption = str;
            lblItem[n]->Visible = true;
            n++;
        }
    }
    for (; n<BT_MT_MAX_PROC_NUM; n++)
    {
        //if (base+n < scr->ProcCount)
        if (base+n < scr->Get_ProcCount())
        {
            lblItem[n]->Font->Color = clBlack;
            lblItem[n]->Font->Style = TFontStyles();
            //sprintf(str, "%s", scr->ProcName[base+n]);
            sprintf(str, "%s", scr->Get_ProcName(base+n));
            lblItem[n]->Caption = str;
            lblItem[n]->Visible = true;
        }
        else
        {
            lblItem[n]->Visible = false;
        }
    }
#endif
    return(1);
}
//---------------------------------------------------------------------------
int TfrmBT::ReloadScriptFiles(void)
{
#if 0
    int ok;
    char str[256];
    FILE *fs ;

    scrTestItemList->LargeChange = BT_MT_MAX_PROC_NUM;
    for (int n=0; n < BT_MT_TESTCASE_NUM; n++)
    {
        sprintf(str, "Item%d.txt", n+1);
        fs = fopen(str, "r");
        if (NULL == fs)
        {
            if (Script[n] != NULL)
            {
                delete Script[n];
            }
            Script[n] = 0;
            m_rbTestItem[n]->Caption = "TBD";
            m_rbTestItem[n]->Enabled = false;
            continue;
        }
        fclose(fs);
        if (Script[n] != NULL)
        {
            delete Script[n];
        }
        Script[n] = new CBTMT;
        ok = Script[n]->OpenScript(str);
        if (!ok)
        {
            if(Script[n]!=NULL)
                delete Script[n];
            Script[n] = 0;
            m_rbTestItem[n]->Caption = "TBD";
            m_rbTestItem[n]->Enabled = false;
            continue;
        }
        //m_rbTestItem[n]->Caption = Script[n]->Title;
        m_rbTestItem[n]->Caption = Script[n]->Get_Title();
        m_rbTestItem[n]->Enabled = true;
        if(ActIdx<0)  ActIdx = n;
    }
    m_rbTestItem[ActIdx]->Checked = true;
    // btnCheckCOMClick(this);

#endif
    return(1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::m_btnMTReloadClick(TObject *Sender)
{
    ReloadScriptFiles();
    UpdateProcessGroup();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::m_btnMTRunClick(TObject *Sender)
{
    TSpeedButton* btn;
    btn = (Sender!=0) ? (TSpeedButton*)Sender : m_btnMTRun;
    if (0 == btn->Tag)
    {
        btn->Tag = 1;
        btn->Caption = "Stop";
        for (int n = 0; n < BT_MT_TESTCASE_NUM; n++)
        {
            m_rbTestItem[n]->Enabled = false;
        }
        Script[ActIdx]->Set_BTTrans(0, BT_META);
        if (m_cbMETAMode->Checked)
        {
            Script[ActIdx]->Set_BTTrans(1, BT_META);
        }
        else
        {
            Script[ActIdx]->Set_ComPort(m_usComPortArray[m_cbMTBT2COM->ItemIndex]);
            Script[ActIdx]->Set_BTTrans(1, BT_RS232);
        }
        m_lblMTStatus->Font->Color = clBlue;
        m_lblMTStatus->Caption = "RUNNING";
        Script[ActIdx]->Reset();
        m_edtMTLog->Lines->Clear();
        m_tmMT->Enabled =true;
    }
    else
    {
        btn->Tag = 0;
        m_tmMT->Enabled =false;
        btn->Caption = "Run";


        for (int n=0; n<BT_MT_TESTCASE_NUM; n++)
        {
            m_rbTestItem[n]->Enabled = (Script[n]!=0);
        }
        m_lblMTStatus->Font->Color = clBlack;
        m_lblMTStatus->Caption = "STOP";
        Script[ActIdx]->CloseScript();
        UpdateProcessGroup();
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmBT::m_btnMTConnectClick(TObject *Sender)
{
#if 0
    m_shpMTConnect->Brush->Color = clRed;
    m_sCWT.i_meta_handle = m_META_HANDLE_Obj.Get_SecondHandle();
    SetMetaConnectReq(m_sCWT.META_connect_req);
    m_sCWT.neSuccess = on_PKTConnectWithTarget_Success;
    m_sCWT.neByUser  = on_PKTConnectWithTarget_ByUser;

    AbortConnectWithTarget();

    m_pT_CWT = new T_META_ConnectWithTarget(true, &m_sCWT);
    if (NULL != m_pT_CWT)
    {
        m_pT_CWT->FreeOnTerminate = true;
        m_pT_CWT->OnTerminate = on_PKTConnectWithTarget_Fail;
        m_pT_CWT->Priority = tpHighest;
    }
    else
    {
        m_pPKTLog->Add( DateToStr(Date()) +  " " + TimeToStr(Time()) +
                        " FAIL: connect with target"
                      );
        PostMessage(
            this->Handle,
            WM_ML_BT_PRINT_MSG,
            0,
            0
        );


        return;
    }

    if( NULL != m_pT_CWT )
    {
        m_pT_CWT->Resume();
    }
#endif
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::m_cbMETAModeClick(TObject *Sender)
{
    m_btnMTConnect->Enabled = m_cbMETAMode->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::scrTestItemListChange(TObject *Sender)
{
    UpdateProcessGroup();
}

//---------------------------------------------------------------------------
void __fastcall TfrmBT::rbRxTestClick(TObject *Sender)
{
    cbTxLevel->Enabled = false;
    cbContinuousTx->Enabled =  false;
    cbPattern->Enabled = false;
    m_sBtBle.ble_test_type        = BT_RX_Test;
}
//---------------------------------------------------------------------------

void __fastcall TfrmBT::rbTxTestClick(TObject *Sender)
{
    cbTxLevel->Enabled = true;
    cbContinuousTx->Enabled =  true;
    cbPattern->Enabled = true;
    m_sBtBle.ble_test_type        = BT_TX_Test;
}
//---------------------------------------------------------------------------

void __fastcall TfrmBT::rbSingleChannelClick(TObject *Sender)
{
//rongguo 2011-06-27
//        etChannel->Enabled = true;
    m_sBtBle.ble_channel_type = BT_SINGLE;
}
//---------------------------------------------------------------------------

void __fastcall TfrmBT::rbHoppingClick(TObject *Sender)
{
//rongguo 2011-06-27
//        etChannel->Text = "";
//        etChannel->Enabled = false;
    m_sBtBle.ble_channel_type = BT_HOPPING;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbContinuousTxClick(TObject *Sender)
{
    if(cbContinuousTx->Checked == false)
    {
        edPacketCount->Enabled = true;
    }
    else
    {
        edPacketCount->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btAddDeviceToWhiteListClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;
    m_sBleNormal.ble_strWhiteList   = deleteSpace(edWhiteList->Text);

    if(m_sBleNormal.ble_strWhiteList.Length()!=12)
    {
        Application->MessageBox( "The content of White List is invalid", "", MB_OK );
        return;
    }

    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE Add Device To White List progressing";
    m_stab = " BT BLE Add Device To White List";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLEAddDeviceToWhiteList(m_sBleNormal);
}

//---------------------------------------------------------------------------
void __fastcall TfrmBT::btRemoveDeviceToWhiteListClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;
    m_sBleNormal.ble_strWhiteList   = deleteSpace(edWhiteList->Text);

    if(m_sBleNormal.ble_strWhiteList.Length()!=12)
    {
        Application->MessageBox( "The content of White List is invalid", "", MB_OK );
        return;
    }

    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE Remove Device To White List progressing";
    m_stab = " BT BLE Remove Device To White List";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLERemoveDeviceToWhiteList(m_sBleNormal);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btSetAdvertiseDataClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;
    m_sBleNormal.ble_strAdvertiseData = deleteSpace(reAdvertiseData->Text);

    if(m_sBleNormal.ble_strAdvertiseData.Length()>31)
    {
        Application->MessageBox( "The content of Advertise Data is invalid", "", MB_OK );
        return;
    }

    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE Set Advertise Data progressing";
    m_stab = " BT BLE Set Advertise Data";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLESetAdvertiseData(m_sBleNormal);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btBLEClearWhiteListClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;

    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE  White List progressing";
    m_stab = " BT BLE Clear White List";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLEClearWhiteList(m_sBleNormal);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btSetScanResponseDataClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;

    m_sBleNormal.ble_strSetScanResponseData = deleteSpace(reScanResponseData->Text);
    if(m_sBleNormal.ble_strSetScanResponseData.Length()>31)
    {
        Application->MessageBox( "The content of Scan Response Data is invalid", "", MB_OK );
        return;
    }
    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE Set Scan Response Data progressing";
    m_stab = " BT BLE Set Scan Response Data";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLESetScanResponseData(m_sBleNormal);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btHCIResetClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;

    sbBLENormalMode->Panels->Items[0]->Text = (AnsiString) "  BT BLE HCI Reset progressing";
    m_stab = " BT BLE HCI Reset";
    m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
    CurrentPageLock();
    m_BT_BLE_Obj.REQ_BLEResetHCI(m_sBleNormal);

    ble_Advertise_start_or_stop = 0;
    ble_Scan_start_or_stop = 0;
    ble_Initiate_start_or_stop = 0;

    btAdvertiseStar->Caption = "Start";
    btScanStart->Caption = "Start";
    btInitiateStart->Caption = "Start";
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnStartClick(TObject *Sender)
{
    m_sBtBle.hPostMsgDestHandle = this->Handle;
    m_sBtBle.log                = m_pBLELog;

    if(ble_start_or_stop==0)   //start
    {
        if(rbSingleChannel->Checked == true) // SingleChannel
        {
            if(etChannel->Text == "")
            {
                sbRF->Panels->Items[0]->Text = (AnsiString) "Valid value of Channel is 0~39";
                Application->MessageBox( "Valid value of Channel is 0~39", "FAILURE", MB_OK );
                return;
            }
        }
        if(rbTxTest->Checked == true)  //Tx Test
        {
            sbBLE->Panels->Items[0]->Text = (AnsiString) "  BT BLE TX Test progressing";

            if(etChannel->Text == "")
            {
                sbRF->Panels->Items[0]->Text = (AnsiString) "Valid value of Channel is 0~39";
                Application->MessageBox( "Valid value of Channel is 0~39", "FAILURE", MB_OK );
                return;
            }

            m_sBtBle.Channel = StrToInt(etChannel->Text);
            m_sBtBle.ble_tx_patten = (BT_BLE_TX_PATTERN)cbPattern->ItemIndex;
            m_sBtBle.ble_test_type = (BT_BLE_TEST_TYPE)0;
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLETX;
        }
        else//Rx Test
        {
            sbBLE->Panels->Items[0]->Text = (AnsiString) "  BT BLE RX Test progressing";
            m_sBtBle.Channel = StrToInt(etChannel->Text);
            m_sBtBle.ble_test_type = (BT_BLE_TEST_TYPE)1;
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLERX;
        }
        CurrentPageLock();
        btnStart->Caption = "Stop";
        ble_start_or_stop = 1;
        m_BT_BLE_Obj.REQ_Start( m_sBtBle );
    }
    else
    {
        Force_BT_Stop_BLE();
        if(rbTxTest->Checked == true)  //Tx Test
        {
            sbBLE->Panels->Items[0]->Text = (AnsiString) "  Stop BT BLE TX Test progressing";
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLETXStop;
        }
        else//Rx Test
        {
            sbBLE->Panels->Items[0]->Text = (AnsiString) "  Stop BT BLE RX Test progressing";
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLERXStop;

        }
        CurrentPageLock();
        btnStart->Caption = "Start";
        ble_start_or_stop = 0;
        m_BT_BLE_Obj.REQ_StartStop( m_sBtBle );

    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmBT::btnEnStartClick(TObject *Sender)
{
    m_sBleEnhanced.hPostMsgDestHandle = this->Handle;
    m_sBleEnhanced.log                = m_pBLELog;

    if(ble_enhanced==0)   //start
    {
        if(rbEnTxTest->Checked == true)  //tx
        {
            sbBLEEN->Panels->Items[0]->Text = (AnsiString) "  BT BLE Enhanced TX Test progressing";
            m_sBleEnhanced.Channel = StrToInt(cbEnChannel->Text);
            m_sBleEnhanced.PayloadLength =  StrToInt(edEnPayloadLength->Text);
            m_sBleEnhanced.ble_tx_patten = (BT_BLE_ENHANCED_TX_PATTERN)cbEnPattern->ItemIndex;
            m_sBleEnhanced.ble_test_type = (BT_BLE_TEST_TYPE)0;
            m_sBleEnhanced.ble_tx_phy = (BT_BLE_ENHANCED_TX_PHY)(cbEnPHY->ItemIndex+1);
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLEENTX;
        }
        else  //rx
        {
            sbBLEEN->Panels->Items[0]->Text = (AnsiString) "  BT BLE Enhanced RX Test progressing";
            m_sBleEnhanced.Channel = StrToInt(cbEnChannel->Text);
            m_sBleEnhanced.ble_test_type = (BT_BLE_TEST_TYPE)1;
            m_sBleEnhanced.ble_rx_phy = (BT_BLE_ENHANCED_RX_PHY)(cbEnPHY->ItemIndex+1);
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLEENRX;
        }
        CurrentPageLock();
        btnEnStart->Caption = "Stop";
        ble_enhanced = 1;
        m_BT_BLE_Obj.REQ_BLEEnhancedStart( m_sBleEnhanced );

    }
    else   //stop
    {
        Force_BT_Stop_BLE();
        if(rbEnTxTest->Checked == true)  //tx
        {
            sbBLEEN->Panels->Items[0]->Text = (AnsiString) "  Stop BT BLE Enhanced TX Test progressing";
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLEEnTXStop;
        }
        else           //rx
        {
            sbBLEEN->Panels->Items[0]->Text = (AnsiString) "  Stop BT BLE Enhanced RX Test progressing";
            m_BT_BLE_Obj.ConfirmCallback  = ::ConfirmCallback_BLEEnRXStop;
        }
        CurrentPageLock();
        btnEnStart->Caption = "Start";
        ble_enhanced = 0;
        m_BT_BLE_Obj.REQ_BLEEnhancedStop( m_sBleEnhanced );
    }
                 
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btAdvertiseStarClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;

    if(ble_Advertise_start_or_stop == 0)
    {
        m_sBleNormal.ble_strAdvertisingIntervalMin = deleteSpace(edAdvertisingIntervalMin->Text);
        m_sBleNormal.ble_strAdvertisingIntervalMax = deleteSpace(edAdvertisingIntervalMax->Text);
        if(m_sBleNormal.ble_strAdvertisingIntervalMin.Length()>4)
        {
            Application->MessageBox( "The content of Advertising Interval Min is invalid", "", MB_OK );
            return;
        }
        if(m_sBleNormal.ble_strAdvertisingIntervalMax.Length()>4)
        {
            Application->MessageBox( "The content of Advertising Interval Max is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.ble_advertising_type = (E_BT_Advertising_Type)cbAdvertisingType->ItemIndex;
        m_sBleNormal.ble_own_address_type = (E_BT_Device_Address)cbOwnAddressType->ItemIndex;
        m_sBleNormal.ble_direct_address_type =  (E_BT_Device_Address)cbDirectAddressType->ItemIndex;
        m_sBleNormal.ble_strDirectAddress = deleteSpace(edDirectAddress->Text);

        if(m_sBleNormal.ble_strDirectAddress.Length()!=12)
        {
            Application->MessageBox( "The content of Direct Address is invalid", "", MB_OK );
            return;
        }

        if(cbChannel37->Checked == false && cbChannel38->Checked == false && cbChannel39->Checked ==false)
        {
            Application->MessageBox( "At least one channel should be selected", "", MB_OK );
        }
        m_sBleNormal.channel = 0;
        if(cbChannel37->Checked == true)
        {
            m_sBleNormal.channel += 1;
        }

        if(cbChannel38->Checked == true)
        {
            m_sBleNormal.channel += 2;
        }

        if(cbChannel38->Checked == true)
        {
            m_sBleNormal.channel += 4;
        }

        m_sBleNormal.ble_advertise_filter_policy = (E_BT_Advertise_Filter_Policy)cbAdvertiseFilterPolicy->ItemIndex;
        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Adevertise Start";
        CurrentPageLock();
        btAdvertiseStar->Caption = "Stop";
        ble_Advertise_start_or_stop = 1;
        m_BT_BLE_Obj.REQ_BLEAdvertiseStart(m_sBleNormal);
    }
    else
    {
        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Adevertise Stop";
        CurrentPageLock();
        btAdvertiseStar->Caption = "Start";
        ble_Advertise_start_or_stop = 0;
        m_BT_BLE_Obj.REQ_BLEAdvertiseStop(m_sBleNormal);
    }


}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btInitiateStartClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;
    if(ble_Initiate_start_or_stop == 0)
    {
        m_sBleNormal.ble_strLEScanIntervalIn =  deleteSpace(edLEScanIntervalIn->Text);
        if(m_sBleNormal.ble_strLEScanIntervalIn.Length()>4)
        {
            Application->MessageBox( "The content of LE Scan Interval is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.ble_strLEScanWindowIn =  deleteSpace(edLEScanWindowIn->Text);
        if(m_sBleNormal.ble_strLEScanWindowIn.Length()>4)
        {
            Application->MessageBox( "The content of LE Scan Window is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.ble_initiate_filter_policy = (E_BT_Initiate_Filter_Policy)cbInitiateFilterPolicy->ItemIndex;
        m_sBleNormal.ble_PeerAddressType = (E_BT_Device_Address)cbPeerAddressType->ItemIndex;
        m_sBleNormal.ble_OwnAddressTypeIn = (E_BT_Device_Address)cbOwnAddressTypeIn->ItemIndex;
        m_sBleNormal.strPeerAddress = deleteSpace(edPeerAddress->Text);
        if(m_sBleNormal.strPeerAddress.Length()!= 12)
        {
            Application->MessageBox( "The content of Peer Address is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strConnectionIntervalMin = deleteSpace(edConnectionIntervalMin->Text);
        if(m_sBleNormal.strConnectionIntervalMin.Length()> 4)
        {
            Application->MessageBox( "The content of Peer Address is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strConnectionIntervalMax = deleteSpace(edConnectionIntervalMax->Text);
        if(m_sBleNormal.strConnectionIntervalMax.Length() > 4)
        {
            Application->MessageBox( "The content of Peer Address is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strConnectionLatency = deleteSpace(edConnectionLatency->Text);
        if(m_sBleNormal.strConnectionLatency.Length() > 4)
        {
            Application->MessageBox( "The content of Connection Latency is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strSupervisionTimeout = deleteSpace(edSupervisionTimeout->Text);
        if(m_sBleNormal.strSupervisionTimeout.Length() > 4)
        {
            Application->MessageBox( "The content of Supervision Timeout is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strMinimumCELength =  deleteSpace(edMinimumCELength->Text);
        if(m_sBleNormal.strMinimumCELength.Length() > 4)
        {
            Application->MessageBox( "The content of Minimum CE Length is invalid", "", MB_OK );
            return;
        }
        m_sBleNormal.strMaximumCELength = deleteSpace(edMaximumCELength->Text);
        if(m_sBleNormal.strMaximumCELength.Length() > 4)
        {
            Application->MessageBox( "The content of Maximum CE Length is invalid", "", MB_OK );
            return;
        }
        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Initiate Start";
        CurrentPageLock();
        btInitiateStart->Caption = "Stop";
        ble_Initiate_start_or_stop = 1;
        m_BT_BLE_Obj.REQ_BLEInitiateStart(m_sBleNormal);
    }
    else
    {
        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Initiate Stop";
        CurrentPageLock();
        btInitiateStart->Caption = "Start";
        ble_Initiate_start_or_stop = 0;
        m_BT_BLE_Obj.REQ_BLEInitiateStop(m_sBleNormal);


    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btScanStartClick(TObject *Sender)
{
    m_sBleNormal.hPostMsgDestHandle = this->Handle;
    m_sBleNormal.log                = m_pBLELog;
    if(ble_Scan_start_or_stop == 0)
    {
        m_sBleNormal.ble_scan_type = (E_BT_Scan_Type)cbScanType->ItemIndex;
        m_sBleNormal.ble_strLEScanInterval =  deleteSpace(edLEScanInterval->Text);
        m_sBleNormal.ble_strLEScanWindow = deleteSpace(edLEScanWindow->Text);

        if(m_sBleNormal.ble_strAdvertisingIntervalMax.Length()>4)
        {
            Application->MessageBox( "The content of LE Scan Interval is invalid", "", MB_OK );
            return;
        }
        if(m_sBleNormal.ble_strAdvertisingIntervalMax.Length()>4)
        {
            Application->MessageBox( "The content of LE Scan Interval is invalid", "", MB_OK );
            return;
        }

        m_sBleNormal.ble_scan_own_address_type = (E_BT_Device_Address)cbOwmAddressType->ItemIndex;
        m_sBleNormal.ble_scan_filter_policy = (E_BT_Scan_Filter_Policy)cbScanFilterPolicy->ItemIndex;
        m_sBleNormal.ble_scan_filter_duplicate = (E_BT_Scan_Filter_Duplicate)cbFilterDuplicate->ItemIndex;

        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Scan Start";
        CurrentPageLock();
        btScanStart->Caption = "Stop";
        ble_Scan_start_or_stop = 1;
        m_BT_BLE_Obj.REQ_BLEScanStart(m_sBleNormal);
    }
    else
    {
        m_BT_BLE_Obj.ConfirmCallback  = ::CNF_BLE_Comman;
        m_stab = " BT BLE Scan Stop";
        CurrentPageLock();
        btScanStart->Caption = "Start";
        ble_Scan_start_or_stop = 0;
        m_BT_BLE_Obj.REQ_BLEScanStop(m_sBleNormal);
    }
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLERXStop(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();



    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"Stop BT BLE RX successfully";
        edPacketCount->Text = m_BT_BLE_Obj.GetBLEResult();
    }
    break;

    case META_FAILED:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE RX fail";
        Application->MessageBox( "Execution Failure :Stop BT BLE RX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE RX timeout";
        Application->MessageBox( "Execution Timeout :Stop BT BLE RX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"Stop BT BLE RX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLETXStop(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE TX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE TX fail";
        Application->MessageBox( "Execution Failure :Stop BT BLE TX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE TX timeout";
        Application->MessageBox( "Execution Timeout :Stop BT BLE TX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE TX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}

//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLEEnTXStop(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced TX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced TX fail";
        Application->MessageBox( "Execution Failure :Stop BT BLE Enhanced TX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced TX timeout";
        Application->MessageBox( "Execution Timeout :Stop BT BLE Enhanced TX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced TX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}

//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLEEnRXStop(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"Stop BT BLE Enhanced RX successfully";
        edEnPacketCount->Text = m_BT_BLE_Obj.GetBLEResult();
    }
    break;

    case META_FAILED:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced RX fail";
        Application->MessageBox( "Execution Failure :Stop BT BLE Enhanced RX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)" Stop BT BLE Enhanced RX timeout";
        Application->MessageBox( "Execution Timeout :Stop BT BLE Enhanced RX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"Stop BT BLE Enhanced RX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLERX(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE RX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE RX fail";
        Application->MessageBox( "Execution Failure : BT BLE RX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE RX timeout";
        Application->MessageBox( "Execution Timeout : BT BLE RX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE RX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLETX(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE TX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE TX fail";
        Application->MessageBox( "Execution Failure : BT BLE TX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE TX timeout";
        Application->MessageBox( "Execution Timeout : BT BLE TX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLE->Panels->Items[0]->Text = (AnsiString)"  BT BLE TX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLEENRX(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced RX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced RX fail";
        Application->MessageBox( "Execution Failure : BT BLE Enhanced RX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced RX timeout";
        Application->MessageBox( "Execution Timeout : BT BLE Enhanced RX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced RX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void TfrmBT::ConfirmCallback_BLEENTX(void)
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced TX successfully";
    }
    break;

    case META_FAILED:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced TX fail";
        Application->MessageBox( "Execution Failure : BT BLE Enhanced TX", "FAILURE", MB_OK );
        Application->BringToFront();
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        Force_BT_Stop_BLE();
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced TX timeout";
        Application->MessageBox( "Execution Timeout : BT BLE Enhanced TX", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case META_CANCEL:
    case METAAPP_STOP:
    {
        sbBLEEN->Panels->Items[0]->Text = (AnsiString)"  BT BLE Enhanced TX stop";
        CurrentPageReset();
    }
    break;
    }
    CurrentPageReset();

}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbPatternSelect(TObject *Sender)
{
    if(cbPattern->ItemIndex == 1)
    {
        m_sBtBle.ble_tx_patten  = P11110000;
    }

    if(cbPattern->ItemIndex == 2)
    {
        m_sBtBle.ble_tx_patten  = P10101010;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmBT::etChannelExit(TObject *Sender)
{
//rongguo 2011-06-27
//    if(rbSingleChannel->Checked == true)
//    {
    unsigned char  channel;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] =
    {
        " value should be 0~39 "
    };

    text = edit->Text;
    if( !IsValidBTBLEChannel( text, channel ) )
    {
        ShowHintLabel( edit, hint );
        //edit->SetFocus();
        return;
    }

    m_sBtBle.Channel = channel;
//    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btClearClick(TObject *Sender)
{
    reBLEEnhancedResult->Clear();
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_BLE_Comman()
{
    META_RESULT state = m_BT_BLE_Obj.Get_ConfirmState();
    AnsiString text = m_stab;
    switch (state)
    {
    case META_SUCCESS:
    {
        sbBLENormalMode->Panels->Items[0]->Text =text + (AnsiString)" successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler(text, state, sbBLENormalMode);
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb)
{
    switch (state)
    {
    case META_FAILED:
    {
        // new
        sb->Panels->Items[0]->Text = message + " failed";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        // new
        sb->Panels->Items[0]->Text = message+ " timeout";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        // new
        sb->Panels->Items[0]->Text = message + " stop";
    }
    break;

    default:
    {
    }
    break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btAdvertiseClearClick(TObject *Sender)
{
    reBLEAdvertiseResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btScanClearClick(TObject *Sender)
{
    reBLEScanResult->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btInitiateClearClick(TObject *Sender)
{
    reBLEInitiateResult->Clear();
}
//---------------------------------------------------------------------------
AnsiString TfrmBT::deleteSpace(AnsiString input)
{
    AnsiString output;


    //output =StringReplace(input," ","",TReplaceFlags()<<rfReplaceAll);

    // output =StringReplace(output,":","",TReplaceFlags()<<rfReplaceAll);

    AnsiString tempStr;
    int temp = input.Length();
    int i;
    int j=1;
    char tempASCII[256]= {0};

    for(i=1; i<=temp; i++)
    {
        tempStr=input.SubString(j,1);
        strncpy(tempASCII,tempStr.c_str(),1);

        if(tempASCII[0]<0x30 || (tempASCII[0]>0x39 && tempASCII[0]<0x41)|| (tempASCII[0]>0x46 && tempASCII[0]<0x61) || tempASCII[0]>0x69)
        {
            input =StringReplace(input,tempStr,"",TReplaceFlags()<<rfReplaceAll);
        }
        else
        {
            j++;
        }
    }

    return input;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::tsAdvertiseShow(TObject *Sender)
{
    m_BT_BLE_Obj.eBTPage = PAGEIDX_BT_BLE_Normal_Advertise;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::tsScanShow(TObject *Sender)
{
    m_BT_BLE_Obj.eBTPage = PAGEIDX_BT_BLE_Normal_Scan;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::tsInitiateShow(TObject *Sender)
{
    m_BT_BLE_Obj.eBTPage = PAGEIDX_BT_BLE_Normal_Initiate;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbDeviceAddressChange(TObject *Sender)
{
    if(cbDeviceAddress->ItemIndex == 0)
    {
        m_sBleNormal.ble_device_address = Public_Device_Address;
    }
    else
    {
        m_sBleNormal.ble_device_address = Random_Device_Address;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btChangeMintoHexClick(TObject *Sender)
{
    edAdvertisingIntervalMin->Text = IntToHex(edAdvertisingIntervalMin->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btChangeMaxtoHexClick(TObject *Sender)
{
    edAdvertisingIntervalMax->Text = IntToHex(edAdvertisingIntervalMax->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btChangeLeScanIntervalClick(TObject *Sender)
{
    edLEScanInterval->Text =  IntToHex(edLEScanInterval->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btChangeLEScanWindowClick(TObject *Sender)
{
    edLEScanWindow->Text = IntToHex(edLEScanWindow->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnLEScanIntervalClick(TObject *Sender)
{
    edLEScanIntervalIn->Text = IntToHex(edLEScanIntervalIn->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnLEScanWindowClick(TObject *Sender)
{
    edLEScanWindowIn->Text = IntToHex(edLEScanWindowIn->Text.ToInt(),4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnEnterTestClick(TObject *Sender)
{
    m_sRXStandalone.hPostMsgDestHandle = this->Handle;
    m_sRXStandalone.log                = m_pSTDLog;
    unsigned int tmpValue;
    if(cbRXPattern->ItemIndex < 4)
    {
        m_sRXStandalone.pattern = (RXPattern)cbRXPattern->ItemIndex+1;
    }
    else if(cbRXPattern->ItemIndex == 4)
    {
        m_sRXStandalone.pattern = p11110000;
    }
    if(0 > edRXFre->Text.ToInt() || 78 < edRXFre->Text.ToInt())
    {
        Application->MessageBox( "The content of Tester Frequency must be 0~78", "", MB_OK );
        return;
    }
    m_sRXStandalone.RXFrequency = IntToHex(edRXFre->Text.ToInt(),2);

    switch(cbRXPacketTypeSub->ItemIndex)
    {
    case 0:
        m_sRXStandalone.PXPackettype = 0x03;
        break;
    case 1:
        m_sRXStandalone.PXPackettype = 0x04;
        break;
    case 2:
        m_sRXStandalone.PXPackettype = 0x09;
        break;
    case 3:
        m_sRXStandalone.PXPackettype = 0x0A;
        break;
    case 4:
        m_sRXStandalone.PXPackettype = 0x0B;
        break;
    case 5:
        m_sRXStandalone.PXPackettype = 0x0E;
        break;
    case 6:
        m_sRXStandalone.PXPackettype = 0x0F;
        break;
    case 7:
        m_sRXStandalone.PXPackettype = 0x24;
        break;
    case 8:
        m_sRXStandalone.PXPackettype = 0x28;
        break;
    case 9:
        m_sRXStandalone.PXPackettype = 0x2A;
        break;
    case 10:
        m_sRXStandalone.PXPackettype = 0x2B;
        break;
    case 11:
        m_sRXStandalone.PXPackettype = 0x2E;
        break;
    case 12:
        m_sRXStandalone.PXPackettype = 0x2F;
        break;
    case 13:
        IsValidHexBTAddr(edUserInput->Text.SubString(1,2),&tmpValue);
        m_sRXStandalone.PXPackettype = tmpValue;
        break;
    }

    if(edTesterAddress->Text.Length()<8)
    {
        if(edTesterAddress->Text.IsEmpty() || 0 != edTesterAddress->Text.ToInt())
        {
            Application->MessageBox( "The content of Tester Address is invalid", "", MB_OK );
            return;
        }
        else
        {
            m_sRXStandalone.TesterAddress = "00000000";
        }
    }
    else
    {
        m_sRXStandalone.TesterAddress = edTesterAddress->Text.SubString(edTesterAddress->Text.Length()-7, 8);
    }
    CurrentPageLock();
    m_BT_RXStandalone_Obj.ConfirmCallback  = ::CNF_RXST_Enter;
    m_BT_RXStandalone_Obj.REQ_EnterTest(m_sRXStandalone);

}
//---------------------------------------------------------------------------
void TfrmBT::CNF_RXST_Enter()
{
    META_RESULT state = m_BT_RXStandalone_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
    {
        sbRXSTD->Panels->Items[0]->Text ="Enter Test successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Enter Test", state, sbRXSTD);
    }
    break;
    }
    CurrentPageReset();
}
void __fastcall TfrmBT::btnSTDClearClick(TObject *Sender)
{
    reRXSTD->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnExitTestClick(TObject *Sender)
{
    m_sRXStandalone.hPostMsgDestHandle = this->Handle;
    m_sRXStandalone.log                = m_pSTDLog;
    CurrentPageLock();
    m_BT_RXStandalone_Obj.ConfirmCallback  = ::CNF_RXST_Exit;
    m_BT_RXStandalone_Obj.REQ_ExitTest(m_sRXStandalone);
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_RXST_Exit()
{
    META_RESULT state = m_BT_RXStandalone_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
    {
        sbRXSTD->Panels->Items[0]->Text ="Exit Test successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Exit Test", state, sbRXSTD);
    }
    break;
    }

    char text[20];
//    sprintf(text, "%d", m_BT_RXStandalone_Obj.m_sRXStandalone_Result.RX_Packet_Count);
    edPXPacketCount->Text = m_BT_RXStandalone_Obj.m_sRXStandalone_Result.RX_Packet_Count;

    sprintf(text, "%f%%", m_BT_RXStandalone_Obj.m_sRXStandalone_Result.RX_Error_Rate / (float)1000000);
    edRXErroRate->Text = text;

//    sprintf(text, "%d", m_BT_RXStandalone_Obj.m_sRXStandalone_Result.RX_Byte_Count);
    edRXByteCount->Text = m_BT_RXStandalone_Obj.m_sRXStandalone_Result.RX_Byte_Count;

    sprintf(text, "%f%%", m_BT_RXStandalone_Obj.m_sRXStandalone_Result.Bit_Error_Rate / (float)1000000);
    edBitErrorRate->Text = text;
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::cbRXPacketTypeSubChange(TObject *Sender)
{
    if(cbRXPacketTypeSub->ItemIndex == 13)
    {
        edUserInput->Visible = true;
        lbUserInput->Visible = true;
    }
    else
    {
        edUserInput->Visible = false;
        lbUserInput->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBT::btnResetTestClick(TObject *Sender)
{
    m_sRXStandalone.hPostMsgDestHandle = this->Handle;
    m_sRXStandalone.log                = m_pSTDLog;
    CurrentPageLock();
    m_BT_RXStandalone_Obj.ConfirmCallback  = ::CNF_RXST_Reset;
    m_BT_RXStandalone_Obj.REQ_ResetTest(m_sRXStandalone);
}
//---------------------------------------------------------------------------
void TfrmBT::CNF_RXST_Reset()
{
    META_RESULT state = m_BT_RXStandalone_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
    {
        sbRXSTD->Panels->Items[0]->Text ="Reset Test successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Reset Test", state, sbRXSTD);
    }
    break;
    }
    CurrentPageReset();
}
bool TfrmBT::GetBTChipVersion(unsigned int* nBTChipID)
{
    //META_RESULT mr = SP_META_BT_GetChipID_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, nBTChipID);
    META_RESULT mr = m_BT_Man_Obj.BT_GetChipID(5000, nBTChipID);
    LOG("20120113 SP_META_BT_GetChipID_r mr:%d",mr);
    if( mr != META_SUCCESS)
    {
        return false;
    }
    return true;
}

void TfrmBT::ShowBTPageControl()
{
    LOG("20120113 m_nBTChipVersion:%d",m_nBTChipVersion);
    if( m_nBTChipVersion == BT_CHIP_ID_MT6622)
    {
        tsBLETest->TabVisible = false;
        tsBLENormal->TabVisible = false;
        rbRFRx->Visible = false;
        tsStandalone->TabVisible = false;
    }
    if( m_nBTChipVersion == BT_CHIP_ID_MT6626)
    {
        tsBLETest->TabVisible = false;
        tsBLENormal->TabVisible = false;
        rbRFRx->Visible = false;
    }
}
//

void TfrmBT::OpenBT(void)
{
    if( m_eBTState == BT_STATE_CLOSE )
    {
        m_BT_Man_Obj.BT_Open(5000);
        m_eBTState = BT_STATE_OPEN;
    }

}

void TfrmBT::CloseBT(void)
{
    if( m_eBTState == BT_STATE_OPEN )
    {
       m_BT_Man_Obj.BT_Close(5000);
       m_eBTState = BT_STATE_CLOSE;
    }
}


void __fastcall TfrmBT::rbEnRxTestClick(TObject *Sender)
{
        lbEnPayloadLength->Visible = false;
        edEnPayloadLength->Visible = false;
        lbEnPattern->Visible = false;
        cbEnPattern->Visible = false;
        cbEnPHY->Clear();
        cbEnPHY->AddItem("1M PHY", NULL);
        cbEnPHY->AddItem("2M PHY", NULL);
        cbEnPHY->AddItem("Coded PHY", NULL);
}

//---------------------------------------------------------------------------

void __fastcall TfrmBT::rbEnTxTestClick(TObject *Sender)
{
        lbEnPayloadLength->Visible = true;
        edEnPayloadLength->Visible = true;
        lbEnPattern->Visible = true;
        cbEnPattern->Visible = true;
        cbEnPHY->Clear();
        cbEnPHY->AddItem("1M PHY", NULL);
        cbEnPHY->AddItem("2M PHY", NULL);
        cbEnPHY->AddItem("Coded PHY, S=8", NULL);
        cbEnPHY->AddItem("Coded PHY, S=2", NULL);
}
//---------------------------------------------------------------------------

