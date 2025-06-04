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
 *   bt_mt_meta.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test through META_DLL header
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
#ifndef _BT_MT_META_H_
#define _BT_MT_META_H_

//=============================================================================
// common
#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

// BT
#ifndef _BT_MT_COMMON_H_
#include "bt_mt_common.h"
#endif

typedef struct
{
    E_BT_DEVICE_T e_bt_device;
    E_BT_TRANS_T e_bt_trans[2];
    BT_HCI_COMMAND s_hci_cmd;
    int i_event_num;
    BT_HCI_EVENT s_hci_event[MAX_EVENT_NUM];
    int i_auto_event_num;
    BT_HCI_EVENT s_hci_auto_event[MAX_EVENT_NUM];
} BT_META_HCI_T;

typedef struct
{
    E_BT_DEVICE_T e_bt_device;
    E_BT_TRANS_T e_bt_trans[2];
    //BT_HCI_COMMAND s_hci_cmd;
    BT_HCI_BUFFER s_tx_acl_data;
    BT_HCI_BUFFER s_rx_acl_data;
    int i_event_num;
    BT_HCI_EVENT s_hci_event[MAX_EVENT_NUM];
} BT_META_ACL_DATA_T;

//-----------------------------------------------
class CBTMTMETA
{
private:
    bool m_bEventOk;
    bool m_bAclDataOk;
    CMETAHANDLE m_META_HANDLE_Obj;
    //unsigned char m_ucEventBuf[HCIEVENTBUFSIZE];      // binary format
    //int m_iEventLen;
    //int m_iEventType;
    int m_iEventIdx;
    int m_iAutoEventIdx;
    BT_META_HCI_T m_sHciCmd;
    bool m_bRegAutoCallback[2];
    bool m_bCallAutoCallback[2];
    BT_META_ACL_DATA_T m_sTxAclData;
    BT_META_ACL_DATA_T m_sRxAclData;
    bool m_bRegAclRxCallback[2];
    bool m_bCallAclRxCallback[2];


protected:
    void ConsumeErrorEvent(void);

//public:



public:
    CBTMTMETA(void);
    CBTMTMETA(int port_no, int ena_flowctrl);
    bool RegAutoCallBack0(void);
    bool SendCommand(BT_META_HCI_T cmd);
    bool RegAclRxData0(void);
    bool SendAclData(BT_META_ACL_DATA_T acl_data);

    // call back
    void __stdcall CNF_AutoHCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_AutoHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_HCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_HCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_RxAclCallback0(const BT_HCI_BUFFER *cnf, const short token, void *usrData);
    void __stdcall CNF_RxAclCallback1(const BT_HCI_BUFFER *cnf, const short token, void *usrData);
    void __stdcall CNF_TxAclCallback0(const BT_HCI_PACKET *cnf, const short token, void *usrData);
    void __stdcall CNF_TxAclCallback1(const BT_HCI_PACKET *cnf, const short token, void *usrData);

    // export information
    bool Get_EventOk(void);
    bool Get_CallAutoCallback(int idx);
    void Set_HciCmd(BT_META_HCI_T cmd);
};

//=============================================================================
#endif
