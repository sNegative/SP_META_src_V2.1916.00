/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bt_pkt_common.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT packet test common header
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_PKT_COMMON_H_
#define  _BT_PKT_COMMON_H_


#include <vcl.h>

// common

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif


/*---------------------------------------------------------------------------*/
typedef enum
{
    BT_PACKET_IDX_DM1=0,
    BT_PACKET_IDX_DH1,
    BT_PACKET_IDX_DM3,
    BT_PACKET_IDX_DH3,
    BT_PACKET_IDX_DM5,
    BT_PACKET_IDX_DH5,
    BT_PACKET_IDX_HV1,
    BT_PACKET_IDX_HV2,
    BT_PACKET_IDX_HV3,
    BT_PACKET_IDX_EV3,
    BT_PACKET_IDX_EV4,
    BT_PACKET_IDX_EV5,
    BT_PACKET_IDX_NONEDR_COUNT,
    // BT 2.0
    BT_PACKET_IDX_2DH1 = BT_PACKET_IDX_NONEDR_COUNT,
    BT_PACKET_IDX_2EV3,
    BT_PACKET_IDX_2DH3,
    BT_PACKET_IDX_2EV5,
    BT_PACKET_IDX_2DH5,
    BT_PACKET_IDX_3EV3,
    BT_PACKET_IDX_3DH1,
    BT_PACKET_IDX_3DH3,
    BT_PACKET_IDX_3EV5,
    BT_PACKET_IDX_3DH5,
    BT_PACKET_IDX_COUNT
} E_BT_PACKET_IDX;

//typedef enum
//{
//    BT_ACL_P1_DM1=0x00,
//    BT_ACL_P1_DH1=0x00,
//    BT_ACL_P1_DM3=0x04,
//    BT_ACL_P1_DH3=0x08,
//    BT_ACL_P1_DM5=0x40,
//    BT_ACL_P1_DH5=0x80,
//    BT_ACL_P1_HV1=0x00,
//    BT_ACL_P1_HV2=0x00,
//    BT_ACL_P1_HV3=0x00,
//    BT_ACL_P1_EV3=0x01,
//    BT_ACL_P1_EV4=0x10,
//    BT_ACL_P1_EV5=0x20
//}E_BT_ACL_P1;

//typedef enum
//{
//    BT_ACL_P2_DM1=0x08,
//    BT_ACL_P2_DH1=0x10,
//    BT_ACL_P2_DM3=0x00,
//    BT_ACL_P2_DH3=0x00,
//    BT_ACL_P2_DM5=0x00,
//    BT_ACL_P2_DH5=0x00,
//    BT_ACL_P2_HV1=0x20,
//    BT_ACL_P2_HV2=0x04,
//    BT_ACL_P2_HV3=0x80,
//    BT_ACL_P2_EV3=0x80,
//    BT_ACL_P2_EV4=0x00,
//    BT_ACL_P2_EV5=0x00
//}E_BT_ACL_P2;

//typedef enum
//{
//    BT_SCO_HV1=0x01,
//    BT_SCO_HV2=0x02,
//    BT_SCO_HV3=0x04,
//    BT_SCO_EV3=0x08,
//    BT_SCO_EV4=0x10,
//    BT_SCO_EV5=0x20,
//    BT_SCO_UNKNOWN
//}E_BT_SCO;

typedef struct
{
    E_BT_PACKET_IDX e_idx;
    unsigned int   ui_packet_count;
    unsigned char uc_poll_period;
    unsigned short us_packet_length;
} S_BT_PKT_TCI;

typedef struct
{
    unsigned int ui_rx_pkt_count[BT_PACKET_IDX_COUNT];
    unsigned int ui_tx_pkt_count[BT_PACKET_IDX_COUNT];
} S_BT_PKT_MONITOR_TXRX_CNF;

typedef struct
{
    S_BT_PKT_MONITOR_TXRX_CNF s_tester_monitor;
    S_BT_PKT_MONITOR_TXRX_CNF s_dut_monitor;
} S_BT_PKT_MONITOR_CNF;





#endif
