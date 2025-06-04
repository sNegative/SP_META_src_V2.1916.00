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
 *   bt_common.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT common header
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
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
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
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_COMMON_H_
#define  _BT_COMMON_H_

#define  BD_ADDRESS_LEN               6

#define  HCI_CMD_PARM_LEN  256
#define  MAX_ACL_DATA_LEN 1021
#define  MAX_SCO_DATA_LEN  540

#define  BT_STATUS_SUCCESS 0
#define  BT_STATUS_FAIL    1

#define  BD_ADDRESS_NAP_LEN     4
#define  BD_ADDRESS_UAP_LEN     2
#define  BD_ADDRESS_LAP_LEN     6

#define  BT_PIN_LEN            16

// CAP ID
#define BT_CAP_ID_MIN   0
#define BT_CAP_ID_MAX 127
/*---------------------------------------------------------------------------*/

typedef enum
{
    PAGEIDX_BT_HCI=0,
    PAGEIDX_BT_RF,
    PAGEIDX_BT_PKT,
    PAGEIDX_BT_SCT,
    PAGEIDX_BT_MT,
    PAGEIDX_BT_TT,
    PAGEIDX_BT_CT,
    PAGEIDX_BT_BLE,  //7
    PAGEIDX_BT_BLE_NOR,
    PAGEIDX_BT_RXSTD,
    PAGEIDX_BT_BLE_ENHANCED,//10
//need check this
    PAGEIDX_BT_BLE_Normal_Advertise,
    PAGEIDX_BT_BLE_Normal_Scan,
    PAGEIDX_BT_BLE_Normal_Initiate,
} E_BT_PAGEIDX;

typedef struct
{
    unsigned short us_NAP;
    unsigned char  uc_UAP;
    unsigned int   ui_LAP;
} S_BD_ADDRS;

typedef struct
{
    unsigned char uc_BD_Addr[BD_ADDRESS_LEN];
} S_BD_ADDR;

typedef struct
{
    unsigned char uc_PIN[BT_PIN_LEN];
    unsigned char uc_pin_len;
} S_BT_PIN;

// scan
typedef enum
{
    SCAN_DISABLE = 0,
    SCAN_ENABLE_INQUIRY_ONLY,
    SCAN_ENABLE_PAGE_ONLY,
    SCAN_ENABLE_BOTH,
} E_BT_SCAN_TYPE;

typedef struct
{
    E_BT_SCAN_TYPE e_scan_type;
    bool b_interlaced_inquiry_scan;
    bool b_interlaced_page_scan;
} S_BT_SCAN;

typedef struct
{
    S_BD_ADDR s_bd_addr;
    unsigned short us_acl_pkt_type;
} S_BT_CONNECT_ACL;

typedef struct
{
    S_BD_ADDR s_bd_addr;
} S_BT_DISCONNECT_ACL;

typedef enum
{
    BT_ACL_STATUS_SUCCESS=0x00,
    BT_ACL_STATUS_PAGE_TIMEOUT=0x04,
    BT_ACL_STATUS_FAIL=0xFE,
    BT_ACL_STATUS_NONE=0xFF,
} E_BT_ACL_STATUS;

#define  STR_BT_ACL_SUCCESS         ((AnsiString)       "Success")
#define  STR_BT_ACL_FAIL            ((AnsiString)       "Fail")
#define  STR_BT_ACL_PAGE_TIMEOUT    ((AnsiString)       "Page Timeout")

#endif
