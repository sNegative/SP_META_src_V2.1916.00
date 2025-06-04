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
 *   bt_mt_parse.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test script parse header
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
 * Feb 25 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef _BT_MT_PARSE_H_
#define _BT_MT_PARSE_H_

#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef _BT_MT_COMMON_H_
#include "bt_mt_common.h"
#endif

//=============================================================================
// prefix
#define PREFIX_HCI_COMMMAND    0x01
#define PREFIX_ACL_DATA        0x02
#define PREFIX_SCO_DATA        0x03
#define PREFIX_HCI_EVENT       0x04

// script type
#define STRTYPE_NONE           0
#define STRTYPE_HCI            1 // "HCI1 : COM7"
#define STRTYPE_LOGPATH        2 // "LOGPATH : .\MT6611_LOTA"
#define STRTYPE_TITLE          3 // "TITLE : Module Test"
#define STRTYPE_PROCNAME       4 // "PROC : Inquiry"
#define STRTYPE_WAITPROCNAME   5 // "WAITPROC : Inquiry"
#define STRTYPE_TIMEOUT        6 // "TIMEOUT : 100"
#define STRTYPE_WAIT           7 // "WAIT : 100"
#define STRTYPE_VAR            8 // "x1 : 30"
#define STRTYPE_TX_HCI_CMD     9 // "TX1 : 00 11 ....."
#define STRTYPE_RX_HCI_EVENT  10 // "RX2 : 00 3A ....."
#define STRTYPE_WAITRX        11 // "WAITRX1 : ?? 3A ....."
#define STRTYPE_CONTI         12 // "      44 78 A7 ..."
#define STRTYPE_SIMRX         13 // "SIMRX1 : 00 3A 46...."
#define STRTYPE_PATCH         14 // "PATCH1 : D:\patch.bin"
#define STRTYPE_BAUDRATE      15 // "HCIRATE1 : 921K" //115K, 230K, 460K, 921K, 3M // 1 2 4 9 3
#define STRTYPE_FAILPROC      16 // "PROCFAIL"
#define STRTYPE_FAILEND       17 // "FAILEND"
#define STRTYPE_GOTONEXTPROC  18 // "GOTONEXTPROC"
#define STRTYPE_FORCEEND      19 // "FORCEEND"
#define STRTYPE_SHOWMSG       20 // "SHOWMSG"
#define STRTYPE_KYLE          21 // "KYLE : 3 4 5"
#define STRTYPE_TX_ACL_DATA   22 // "TX1 : 02 32 20 11 00 0D 00 40 00 00 00 00 00 55 56 57 58 59 5A 5B 5C 45"
#define STRTYPE_RX_ACL_DATA   23 // "RX2 : 02 32 20 11 00 0D 00 40 00 00 00 00 00 55 56 57 58 59 5A 5B 5C 45"
#define STRTYPE_TX_SCO_DATA   24 // "TX2 : 03 00 0E 0A 00 00 00 00 55 56 57 58 59 55"
#define STRTYPE_RX_SCO_DATA   25 // "RX1 : 03 00 0E 0A 00 00 00 00 55 56 57 58 59 55"
#define STRTYPE_END           99 // "END"
//-----------------------------------------------
#define VARCOUNT                30
#define STRSIZE               8192
#define CMDSIZE                256

//-----------------------------------------------

class  CBTMTPARSE
{
protected:
    char *GotoDataFiled( char *p, int mode  );
    void  GetStringData( char *p );
    void  GetDecimalData( char *p );
    int   ByteHexStr2Int( char *p );
    int   GetDecimalArg( char *p );

public:

    int   VarData[VARCOUNT];   // var of x0~x9(0~9), y0~9(10~19), z0~9(20~29)

    // After the PreParseString, you can get information from these variable
    int   StrType;
    int   StrValue;      // value after "term : n"
    int   StrValue2;     // HCIn, xn, yn, zn, TXn, RXn
    int   StrArg1, StrArg2, StrArg3;
    char  String[ STRSIZE ];
    int   StrLen;

    // raw data ready to be sent
    unsigned char Command[CMDSIZE];
    int           CmdLen;

    // raw data used to be compared
    unsigned char m_ucEvent[MAX_EVENT_NUM][EVTSIZE];
    unsigned char m_ucEvtTag[MAX_EVENT_NUM][EVTSIZE];
    //int m_iEvtNum;
    int m_iEvtLen[MAX_EVENT_NUM];
    unsigned char m_ucAutoEvent[MAX_EVENT_NUM][EVTSIZE];
    unsigned char m_ucAutoEvtTag[MAX_EVENT_NUM][EVTSIZE];
    //int m_iAutoEvtNum;
    int m_iAutoEvtLen[MAX_EVENT_NUM];
    unsigned char m_ucTxAclData[MAX_ACL_DATA_LEN];
    unsigned char m_ucRxAclData[MAX_ACL_DATA_LEN];
    unsigned char m_ucRxAclDataTag[MAX_ACL_DATA_LEN];
    int m_iTxAclDataLen;
    int m_iRxAclDataLen;

public:
    CBTMTPARSE(void);

    void Reset(void);
    int  PreParseStringType( char *str );
    int  PreParseString(int i_event_idx, char *str);
    bool String2Command(void);
    bool String2TxAclData(void);
    bool String2RxAclData(void);
    bool String2Event(int i_event_idx);
    bool String2AutoEvent(int i_event_idx);
    bool CompareEvent(int i_event_idx, unsigned char *event, int len);
};

//=============================================================================

#endif
