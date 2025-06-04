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
 *   bt_mt_meta.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test through META_DLL source
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
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef _BT_MT_META_H_
#include "bt_mt_meta.h"
#endif

//=============================================================================
static CBTMTMETA* gs_bt_mt_meta_ptr;
static bool g_bIsRunning = false;

//------------------------------------------------------------------------------
static void __stdcall CNF_AutoHCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_AutoHCIEvent0(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_AutoHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_AutoHCIEvent1(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_HCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_HCIEvent0(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_HCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_HCIEvent1(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void __stdcall CNF_TxAclCallback0(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_TxAclCallback0(cnf, token, usrData);
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_TxAclCallback1(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_TxAclCallback1(cnf, token, usrData);
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_RxAclCallback0(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_RxAclCallback0(cnf, token, usrData);
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_RxAclCallback1(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    gs_bt_mt_meta_ptr->CNF_RxAclCallback1(cnf, token, usrData);
}

//=============================================================================
CBTMTMETA::CBTMTMETA(void)
{
    //m_iEventLen  = 0;
    //m_iEventType = EVTTYPE_NONE;
    g_bIsRunning = false;
    m_bRegAutoCallback[0] = false;
    m_bRegAutoCallback[1] = false;
    m_bCallAutoCallback[0] = false;
    m_bCallAutoCallback[1] = false;
    //m_bRegAclRxCallback[0] = false;
    m_bEventOk = false;
    m_bAclDataOk = false;
    m_iEventIdx = 0;
    m_iAutoEventIdx = 0;
    memset(&m_sHciCmd,0,sizeof(m_sHciCmd));
    memset(&m_sTxAclData,0,sizeof(m_sTxAclData));
    memset(&m_sRxAclData,0,sizeof(m_sRxAclData));
    for(int i =0; i<2; i++)
    {
    	  m_bRegAclRxCallback[i] = false;
    	  m_bCallAclRxCallback[i] = false;
    }
}

//=============================================================================
////////////////////////////  HCI command/event   /////////////////////////////
//=============================================================================
bool CBTMTMETA::RegAutoCallBack0(void)
{
    m_bCallAutoCallback[0] = false;
    META_RESULT MetaResult = SP_META_BT_RegisterAutoCallback_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_AutoHCIEvent0);
    if (META_SUCCESS != MetaResult)
    {
        return false;
    }
    m_bRegAutoCallback[0] = true;
    return true;
}

//-----------------------------------------------
bool CBTMTMETA::SendCommand(BT_META_HCI_T cmd)
{
    g_bIsRunning = true;
    gs_bt_mt_meta_ptr = this;
    META_RESULT MetaResult;
    m_iEventIdx = 0;
    m_iAutoEventIdx = 0;
    m_bEventOk = false;
    m_sHciCmd = cmd;
    unsigned char uc_last_event = cmd.s_hci_event[cmd.i_event_num - 1].m_event;
    if (BT1 == cmd.e_bt_device)
    {
        if (BT_META == cmd.e_bt_trans[1])
        {
            if (!m_bCallAutoCallback[1])
            {
                MetaResult = SP_META_BT_RegisterAutoCallback_r(m_META_HANDLE_Obj.Get_SecondHandle(), ::CNF_AutoHCIEvent1);
                if (META_SUCCESS != MetaResult)
                {
                    return false;
                }
                m_bRegAutoCallback[1] = true;
            }
        }

        if (m_bRegAutoCallback[0])
        {
            MetaResult = SP_META_BT_RemoveAutoCallback_r(m_META_HANDLE_Obj.Get_MainHandle());
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAutoCallback[0] = false;
        }

        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, &cmd.s_hci_cmd, ::CNF_HCIEvent0, NULL, uc_last_event);
        if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
        {
            return false;
        }
    }
    else
    {
        if (!m_bCallAutoCallback[0])
        {
            MetaResult = SP_META_BT_RegisterAutoCallback_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_AutoHCIEvent0);
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAutoCallback[0] = true;
        }

        if (m_bRegAutoCallback[1])
        {
            MetaResult = SP_META_BT_RemoveAutoCallback_r(m_META_HANDLE_Obj.Get_SecondHandle());
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAutoCallback[1] = false;
        }

        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 10000, &cmd.s_hci_cmd, ::CNF_HCIEvent1, NULL, uc_last_event);
        if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
        {
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_AutoHCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bCallAutoCallback[0] = true;
    if ((BT_STATUS_SUCCESS != cnf->m_status)                                  ||
            (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_event != cnf->m_event) ||
            (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_len  != cnf->m_len)
       )
    {
        m_bEventOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_len; i++)
    {
        if (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_parms[i] != cnf->m_parms[i])
        {
            m_bEventOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_iAutoEventIdx++;
    m_bEventOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_AutoHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bCallAutoCallback[1] = true;
    if ((BT_STATUS_SUCCESS != cnf->m_status)                                  ||
            (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_event != cnf->m_event) ||
            (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_len  != cnf->m_len)
       )
    {
        m_bEventOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_len; i++)
    {
        if (m_sHciCmd.s_hci_auto_event[m_iAutoEventIdx].m_parms[i] != cnf->m_parms[i])
        {
            m_bEventOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_iAutoEventIdx++;
    m_bEventOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_HCIEvent0(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if ((BT_STATUS_SUCCESS != cnf->m_status)                         ||
            (m_sHciCmd.s_hci_event[m_iEventIdx].m_event != cnf->m_event) ||
            (m_sHciCmd.s_hci_event[m_iEventIdx].m_len  != cnf->m_len)
       )
    {
        m_bEventOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sHciCmd.s_hci_event[m_iEventIdx].m_len; i++)
    {
        if (m_sHciCmd.s_hci_event[m_iEventIdx].m_parms[i] != cnf->m_parms[i])
        {
            m_bEventOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_iEventIdx++;
    m_bEventOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_HCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if ((BT_STATUS_SUCCESS != cnf->m_status)                         ||
            (m_sHciCmd.s_hci_event[m_iEventIdx].m_event != cnf->m_event) ||
            (m_sHciCmd.s_hci_event[m_iEventIdx].m_len  != cnf->m_len)
       )
    {
        m_bEventOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sHciCmd.s_hci_event[m_iEventIdx].m_len; i++)
    {
        if (m_sHciCmd.s_hci_event[m_iEventIdx].m_parms[i] != cnf->m_parms[i])
        {
            m_bEventOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_iEventIdx++;
    m_bEventOk = true;
}

//=============================================================================
////////////////////////////////   ACL data      //////////////////////////////
//=============================================================================
bool CBTMTMETA::RegAclRxData0(void)
{
    m_bRegAclRxCallback[0] = false;
    META_RESULT MetaResult = SP_META_BT_ReceiveHCIData_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_RxAclCallback0);
    if (META_SUCCESS != MetaResult)
    {
        return false;
    }
    m_bRegAclRxCallback[0] = true;
    return true;
}

//-----------------------------------------------------------------------------
bool CBTMTMETA::SendAclData(BT_META_ACL_DATA_T acl_data)
{
    g_bIsRunning = true;
    gs_bt_mt_meta_ptr = this;
    META_RESULT MetaResult;

    m_bAclDataOk = false;
    m_sTxAclData = acl_data;

    if (BT1 == acl_data.e_bt_device)
    {
        if (BT_META == acl_data.e_bt_trans[1])
        {
            if (!m_bCallAclRxCallback[1])
            {
                MetaResult = SP_META_BT_ReceiveHCIData_r(m_META_HANDLE_Obj.Get_SecondHandle(), ::CNF_RxAclCallback1);
                if (META_SUCCESS != MetaResult)
                {
                    return false;
                }
                m_bCallAclRxCallback[1] = true;
            }
        }

        if (m_bRegAclRxCallback[0])
        {
            MetaResult = SP_META_BT_RemoveReceiveHCIDataCallback_r(m_META_HANDLE_Obj.Get_MainHandle());
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAclRxCallback[0] = false;
        }

        MetaResult = SP_META_BT_SendHCIData_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, &acl_data.s_tx_acl_data, ::CNF_TxAclCallback0, NULL);
        if ((META_SUCCESS != MetaResult) || (!m_bAclDataOk))
        {
            return false;
        }
    }
    else
    {
        if (!m_bRegAclRxCallback[0])
        {
            MetaResult = SP_META_BT_ReceiveHCIData_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_RxAclCallback0);
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAclRxCallback[0] = true;
        }

        if (m_bRegAclRxCallback[1])
        {
            MetaResult = SP_META_BT_RemoveReceiveHCIDataCallback_r(m_META_HANDLE_Obj.Get_SecondHandle());
            if (META_SUCCESS != MetaResult)
            {
                return false;
            }
            m_bRegAclRxCallback[1] = false;
        }

        MetaResult = SP_META_BT_SendHCIData_r(m_META_HANDLE_Obj.Get_SecondHandle(), 10000, &acl_data.s_tx_acl_data, ::CNF_TxAclCallback1, NULL);
        if ((META_SUCCESS != MetaResult) || (!m_bAclDataOk))
        {
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_RxAclCallback0(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bCallAclRxCallback[0] = true;
    if ((m_sRxAclData.s_rx_acl_data.m_con_hdl != cnf->m_con_hdl) ||
            (m_sRxAclData.s_rx_acl_data.m_len != cnf->m_len)
       )
    {
        m_bAclDataOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sRxAclData.s_rx_acl_data.m_len; i++)
    {
        if (m_sRxAclData.s_rx_acl_data.m_buffer[i] != cnf->m_buffer[i])
        {
            m_bAclDataOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_bAclDataOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_RxAclCallback1(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bCallAclRxCallback[1] = true;
    if ((m_sRxAclData.s_rx_acl_data.m_con_hdl != cnf->m_con_hdl) ||
            (m_sRxAclData.s_rx_acl_data.m_len != cnf->m_len)
       )
    {
        m_bAclDataOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sRxAclData.s_rx_acl_data.m_len; i++)
    {
        if (m_sRxAclData.s_rx_acl_data.m_buffer[i] != cnf->m_buffer[i])
        {
            m_bAclDataOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_bAclDataOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_TxAclCallback0(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (m_sTxAclData.s_rx_acl_data.m_len != cnf->m_len)
    {
        m_bAclDataOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sTxAclData.s_tx_acl_data.m_len; i++)
    {
        if (m_sTxAclData.s_tx_acl_data.m_buffer[i] != cnf->m_data[i])
        {
            m_bAclDataOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_bAclDataOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTMTMETA::CNF_TxAclCallback1(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (m_sTxAclData.s_rx_acl_data.m_len != cnf->m_len)
    {
        m_bAclDataOk = false;
        g_bIsRunning = false;
        return;
    }

    for (int i = 0; i < m_sTxAclData.s_rx_acl_data.m_len; i++)
    {
        if (m_sTxAclData.s_rx_acl_data.m_buffer[i] != cnf->m_data[i])
        {
            m_bAclDataOk = false;
            g_bIsRunning = false;
            return;
        }
    }
    m_bAclDataOk = true;
}

//=============================================================================
/////////////////////////////  Export  information  ///////////////////////////
//=============================================================================
bool CBTMTMETA::Get_EventOk(void)
{
    return m_bEventOk;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CBTMTMETA::Get_CallAutoCallback(int idx)
{
    return m_bCallAutoCallback[idx];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTMTMETA::Set_HciCmd(BT_META_HCI_T cmd)
{
    m_sHciCmd = cmd;
}
