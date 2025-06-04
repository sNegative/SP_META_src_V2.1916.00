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
 *   bt_hci_common.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI common header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_HCI_COMMON_H_
#define  _BT_HCI_COMMON_H_



#define HCI_CMD_MAX_LEN                    256
#define HCI_EVENT_MAX_LEN                  256

#define HCI_CMD_OPCODE_LOW_IDX               0
#define HCI_CMD_OPCODE_HIGH_IDX              1
#define HCI_CMD_LEN_IDX                      2
#define HCI_CMD_PARAMETER_START_IDX          3
#define HCI_EVENT_ID_IDX                     0
#define HCI_EVENT_LEN_IDX                    1
#define HCI_EVENT_PARAMETER_START_IDX        2




// standard
#define HCE_INQUIRY_COMPLETE               0x01
#define HCE_INQUIRY_RESULT                 0x02
#define HCE_CONNECT_COMPLETE               0x03
#define HCE_CONNECT_REQUEST                0x04
#define HCE_DISCONNECT_COMPLETE            0x05
#define HCE_AUTH_COMPLETE                  0x06
#define HCE_REMOTE_NAME_REQ_COMPLETE       0x07
#define HCE_ENCRYPT_CHNG                   0x08
#define HCE_CHNG_CONN_LINK_KEY_COMPLETE    0x09
#define HCE_MASTER_LINK_KEY_COMPLETE       0x0A
#define HCE_READ_REMOTE_FEATURES_COMPLETE  0x0B
#define HCE_READ_REMOTE_VERSION_COMPLETE   0x0C
#define HCE_QOS_SETUP_COMPLETE             0x0D
#define HCE_COMMAND_COMPLETE               0x0E
#define HCE_COMMAND_STATUS                 0x0F
#define HCE_HARDWARE_ERROR                 0x10
#define HCE_FLUSH_OCCURRED                 0x11
#define HCE_ROLE_CHANGE                    0x12
#define HCE_NUM_COMPLETED_PACKETS          0x13
#define HCE_MODE_CHNG                      0x14
#define HCE_RETURN_LINK_KEYS               0x15
#define HCE_PIN_CODE_REQ                   0x16
#define HCE_LINK_KEY_REQ                   0x17
#define HCE_LINK_KEY_NOTIFY                0x18
#define HCE_LOOPBACK_COMMAND               0x19
#define HCE_DATA_BUFFER_OVERFLOW           0x1A
#define HCE_MAX_SLOTS_CHNG                 0x1B
#define HCE_READ_CLOCK_OFFSET_COMPLETE     0x1C
#define HCE_CONN_PACKET_TYPE_CHNG          0x1D
#define HCE_QOS_VIOLATION                  0x1E
#define HCE_PAGE_SCAN_MODE_CHANGE          0x1F /* Not in 1.2 */
#define HCE_PAGE_SCAN_REPETITION_MODE      0x20
#define HCE_FLOW_SPECIFICATION_COMPLETE    0x21 /* 1.2 */
#define HCE_INQUIRY_RESULT_WITH_RSSI       0x22 /* 1.2 */
#define HCE_READ_REMOTE_EXT_FEAT_COMPLETE  0x23 /* 1.2 */
#define HCE_FIXED_ADDRESS                  0x24 /* 1.2 */
#define HCE_ALIAS_ADDRESS                  0x25 /* 1.2 */
#define HCE_GENERATE_ALIAS_REQ             0x26 /* 1.2 */
#define HCE_ACTIVE_ADDRESS                 0x27 /* 1.2 */
#define HCE_ALLOW_PRIVATE_PAIRING          0x28 /* 1.2 */
#define HCE_ALIAS_ADDRESS_REQ              0x29 /* 1.2 */
#define HCE_ALIAS_NOT_RECOGNIZED           0x2A /* 1.2 */
#define HCE_FIXED_ADDRESS_ATTEMPT          0x2B /* 1.2 */
#define HCE_SYNC_CONNECT_COMPLETE          0x2C /* 1.2 */
#define HCE_SYNC_CONN_CHANGED              0x2D /* 1.2 */
#define HCE_BLUETOOTH_LOGO                 0xFE
#define HCE_VENDOR_SPECIFIC                0xFF
/*---------------------------------------------------------------------------*/
#endif
