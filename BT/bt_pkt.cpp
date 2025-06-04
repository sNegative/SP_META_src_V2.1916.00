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
 *   bt_rf.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT packet test source
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
//===========================================================================
#include <stdio.h>

#pragma hdrstop

// BT
#ifndef  _BT_PKT_H_
#include "bt_pkt.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

// man
//#ifndef  _MAN_TIMER_H_
//#include "man_timer.h"
//#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif


// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

//==============================================================================
static CBTPKT*  gs_bt_pkt_ptr;
static bool g_bIsRunning = false;

//==============================================================================
static void REQ_Pkt_Test(void)
{
    gs_bt_pkt_ptr->REQ_Pkt_Test();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_ResetBDHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_ResetBDHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_ReadBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_ReadBDAddressHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_DUTEnterTestModeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_DUTEnterTestModeHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_DUTScanEnableHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_DUTScanEnableHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_DUTAutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_DUTAutoAcceptHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_TesterCreateConnectionHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_TesterCreateConnectionHCIEvent(cnf, token, usrData);
}

//------------------------------------------------------------------------------
static void __stdcall CNF_TesterTCIActivateRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_TesterTCIActivateRemoteDUTHCIEvent(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Tester_TCI_Control_Remote_DUT(void)
{
    gs_bt_pkt_ptr->REQ_Tester_TCI_Control_Remote_DUT();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_TesterTCIControlRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_TesterTCIControlRemoteDUTHCIEvent(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Read_TX_RX_Count(void)
{
    gs_bt_pkt_ptr->REQ_Read_TX_RX_Count();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_ReadDeviceTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_ReadDeviceTxRxCountHCIEvent(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Read_EDR_TX_RX_Count(void)
{
    gs_bt_pkt_ptr->REQ_Read_EDR_TX_RX_Count();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_ReadDeviceEDRTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_pkt_ptr->CNF_ReadDeviceEDRTxRxCountHCIEvent(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Stop(void)
{
    gs_bt_pkt_ptr->REQ_Stop();
}

//===========================================================================
CBTPKT::CBTPKT(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_bTeserAct = false;
    m_sPktDevice = BT_PACKET_TESTER;
    m_iEventCount = 0;
    m_bEventOk = false;
    m_bStop = false;
    memset(&m_sBTPKT,0,sizeof(m_sBTPKT)); 
    memset(&m_sBTTCI,0,sizeof(m_sBTTCI));
    memset(&m_sBTMonCnf,0,sizeof(m_sBTMonCnf));
}
//---------------------------------------------------------------------------
CBTPKT::~CBTPKT(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
void  CBTPKT::Confirm(META_RESULT confirm_state)
{
    if (! g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}


//============================================================================
void CBTPKT::REQ_Start(S_BT_PKT &bt_pkt)
{
    gs_bt_pkt_ptr  = this;
    g_bIsRunning  = true;
    m_bStop = false;
    m_sBTPKT = bt_pkt;
    ActiveMan->SetActiveFunction(::REQ_Pkt_Test);
    //ActiveMan->SetActiveFunction(::REQ_DUT_Send_Read_BDAdrress_HCI_command);
}

//--------------------------------------------------------------------------
void CBTPKT::REQ_Pkt_Test(void)
{
    META_RESULT METAAPP_Result;

    // step1: (DUT) reset
    METAAPP_Result = REQ_ResetBD(BT_PACKET_DUT);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    // (tester) reset
    METAAPP_Result = REQ_ResetBD(BT_PACKET_TESTER);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    // step 2: (DUT) read BD address
    METAAPP_Result = REQ_Read_BDAdrress(BT_PACKET_DUT);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    // (tester) read BD address
    METAAPP_Result = REQ_Read_BDAdrress(BT_PACKET_TESTER);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    // step 3: (DUT) Enter Test Mode/Enable Scan/Auto accept
    METAAPP_Result = REQ_DUT_Enter_Test_mode();
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    METAAPP_Result = REQ_DUT_Scan_Enable();
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    METAAPP_Result = REQ_DUT_Auto_Accept();
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    // step 4: (tester) create connection
    METAAPP_Result = REQ_Tester_Create_Connection();
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    // step 5: (tester) activate remote DUT
    METAAPP_Result = REQ_Tester_TCI_Activate_Remote_DUT();
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    Confirm(META_SUCCESS);
}

// step 1: reset BD
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_ResetBD(E_BT_PACKET_DEVICE_T device)
{
    //if (!g_bIsRunning)
    //{
    //    return METAAPP_UNEXPECTED_FAIL;
    //}
    m_sPktDevice = device;
    //m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Reset_HCI_Command(hci_cmd);

    AddTxLogToStringList(hci_cmd, device);
    META_RESULT MetaResult;
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 750, &hci_cmd, ::CNF_ResetBDHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }
    else
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 750, &hci_cmd, ::CNF_ResetBDHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }

    return META_SUCCESS;
}

//-----------------------------------------------------
void __stdcall CBTPKT::CNF_ResetBDHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }
    AddRxLogToStringList(*cnf, m_sPktDevice);
    m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Reset_HCI_Event(*cnf);
}

// Step 2: Read BD Addr (X6:X5:X4:X3:X2:X1):
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_Read_BDAdrress(E_BT_PACKET_DEVICE_T device)
{
    m_sPktDevice = device;
    // m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Read_BD_Addr_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, m_sPktDevice);
    META_RESULT MetaResult;
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ReadBDAddressHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }
    else
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_ReadBDAddressHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }
    return META_SUCCESS;
}


//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_ReadBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }
    AddRxLogToStringList(*cnf, BT_PACKET_DUT);
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_BD_Addr_HCI_Event(*cnf, m_sBTPKT.s_tester_bd_addr);
    }
    else
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_BD_Addr_HCI_Event(*cnf, m_sBTPKT.s_dut_bd_addr);
    }
    PostMessage(m_sBTPKT.hPostMsgDestHandle,
                WM_ML_BT_BD_ADDRESS_MSG,
                (WPARAM) m_sPktDevice,
                0
               );
}

// Step 3: (DUT) Enter Test Mode/Enable Scan/Auto accept
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_DUT_Enter_Test_mode(void)
{
    //if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Enter_Test_Mode_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_DUT);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_DUTEnterTestModeHCIEvent, NULL, HCE_COMMAND_COMPLETE);

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }

    return META_SUCCESS;
    //ActiveMan->SetActiveFunction( ::REQ_DUT_Send_Scan_Enable_HCI_command );
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_DUTEnterTestModeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, BT_PACKET_DUT);
    m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Enter_Test_Mode_HCI_Event(*cnf);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_DUT_Scan_Enable(void)
{
    // if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Scan_Enable_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_DUT);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_DUTScanEnableHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }

    return META_SUCCESS;
//    ActiveMan->SetActiveFunction( ::REQ_DUT_Send_Auto_Accept_HCI_command );
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_DUTScanEnableHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, BT_PACKET_DUT);
    m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Scan_Enable_HCI_Event(*cnf);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_DUT_Auto_Accept(void)
{
    //if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Auto_Accept_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_DUT);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_DUTAutoAcceptHCIEvent, NULL, HCE_COMMAND_COMPLETE);

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }

    return META_SUCCESS;
    //ActiveMan->SetActiveFunction( ::REQ_Tester_Send_Create_Connection_HCI_command );
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_DUTAutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, BT_PACKET_DUT);
    m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Auto_Accept_HCI_Event(*cnf);
}

// Step 4: (TESTER) Create Connection with DUT
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_Tester_Create_Connection(void)
{
    //if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_ACL_Connect_HCI_Command(m_sBTPKT.s_dut_bd_addr, hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_TESTER);
    m_iEventCount = 1;
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_TesterCreateConnectionHCIEvent, NULL, HCE_CONNECT_COMPLETE );

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }
    return META_SUCCESS;

    // ActiveMan->SetActiveFunction( ::REQ_Tester_Send_TCI_Activate_Remote_DUT_HCI_command );


}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_TesterCreateConnectionHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }
    AddRxLogToStringList(*cnf, BT_PACKET_TESTER);

    switch (m_iEventCount)
    {
    case 1:
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_ACL_Connect_HCI_Event1(*cnf);
    }
    break;

    case 2:
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_ACL_Connect_HCI_Event2(*cnf, m_sBTPKT.s_dut_bd_addr, m_sBTPKT.uc_h1, m_sBTPKT.uc_h2);
    }
    break;

    case 3:
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_ACL_Connect_HCI_Event3(*cnf, m_sBTPKT.uc_h1, m_sBTPKT.uc_h2);
    }
    break;

    case 4:
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_ACL_Connect_HCI_Event4(*cnf, m_sBTPKT.uc_h1, m_sBTPKT.uc_h2);
    }
    break;
    }
    m_iEventCount++;
}

// Step 5: (TESTER) TCI_Activate_Remote_DUT
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_Tester_TCI_Activate_Remote_DUT(void)
{
    //if (!g_bIsRunning)
    // {
    //     return;
    // }
    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_TCI_Activate_Remote_DUT_HCI_Command(m_sBTPKT.uc_h1, m_sBTPKT.uc_h2, hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_TESTER);
    m_iEventCount = 1;
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_TesterTCIActivateRemoteDUTHCIEvent, NULL, HCE_COMMAND_COMPLETE);

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }

    return META_SUCCESS;
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_TesterTCIActivateRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, BT_PACKET_TESTER);

    if (0x0F == cnf->m_event)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_TCI_Activate_Remote_DUT_HCI_Event1(*cnf);
    }
    else if (0x0E == cnf->m_event)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_TCI_Activate_Remote_DUT_HCI_Event2(*cnf);
    }
    m_iEventCount++;
}

//===========================================================================
//////////// (TESTER) TCI_Control_Remote_DUT DM1 packet no whiten  //////////
//===========================================================================
void CBTPKT::REQ_TCI_Control_Remote_DUT_Start(S_BT_PKT_TCI tci)
{
    gs_bt_pkt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTCI = tci;
    ActiveMan->SetActiveFunction(::REQ_Tester_TCI_Control_Remote_DUT);
}

//---------------------------------------------------------------------------
void CBTPKT::REQ_Tester_TCI_Control_Remote_DUT(void)
{
    //if (!g_bIsRunning)
    //{
    //    return;
    //}

    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_TCI_Control_Remote_DUT_HCI_Command(m_sBTPKT.uc_h1, m_sBTPKT.uc_h2, m_sBTTCI, hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_TESTER);
    m_iEventCount = 1;
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_TesterTCIControlRemoteDUTHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
            return;
        }
        else if (META_CANCEL == MetaResult)
        {
            Confirm(META_CANCEL);
            return;
        }
        else
        {
            Confirm(META_FAILED);
            return;
        }
    }
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_TesterTCIControlRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, BT_PACKET_TESTER);
    if (1 == m_iEventCount)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_TCI_Control_Remote_DUT_HCI_Event1(*cnf);
    }
    else
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_TCI_Control_Remote_DUT_HCI_Event2(*cnf);
    }
}

//============================================================================
//////////////////////////   read TX/RX count   //////////////////////////////
//============================================================================
void CBTPKT::REQ_Read_TX_RX_Count_Start(void)
{
    gs_bt_pkt_ptr  = this;
    g_bIsRunning  = true;
    ActiveMan->SetActiveFunction(::REQ_Read_TX_RX_Count);
    //ActiveMan->SetActiveFunction( ::REQ_Tester_Send_Read_TX_RX_Count_HCI_command );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTPKT::REQ_Read_TX_RX_Count(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT METAAPP_Result;
    METAAPP_Result = REQ_Read_Device_TX_RX_Count(BT_PACKET_TESTER);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    METAAPP_Result = REQ_Read_Device_TX_RX_Count(BT_PACKET_DUT);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    Confirm(META_SUCCESS);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_Read_Device_TX_RX_Count(E_BT_PACKET_DEVICE_T device)
{
    //if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    m_sPktDevice = device;
    m_cBT_HCI_FT_Obj.Compose_Read_TX_RX_Count_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_TESTER);
    META_RESULT MetaResult;
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ReadDeviceTxRxCountHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }
    else
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_ReadDeviceTxRxCountHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }
    }
    return META_SUCCESS;
    //ActiveMan->SetActiveFunction( ::REQ_DUT_Send_Read_TX_RX_Count_HCI_command );
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_ReadDeviceTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }

    AddRxLogToStringList(*cnf, m_sPktDevice);
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_TX_RX_Count_HCI_Event(*cnf, m_sBTMonCnf.s_tester_monitor);
    }
    else
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_TX_RX_Count_HCI_Event(*cnf, m_sBTMonCnf.s_dut_monitor);
    }
}


//============================================================================
//////////////////////////   read EDR TX/RX count   //////////////////////////
//============================================================================
void CBTPKT::REQ_Read_EDR_TX_RX_Count_Start(void)
{
    gs_bt_pkt_ptr  = this;
    g_bIsRunning  = true;

    ActiveMan->SetActiveFunction(::REQ_Read_EDR_TX_RX_Count);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTPKT::REQ_Read_EDR_TX_RX_Count(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT METAAPP_Result;
    METAAPP_Result = REQ_Read_Device_EDR_TX_RX_Count(BT_PACKET_TESTER);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    if (m_bStop)
    {
        return;
    }

    METAAPP_Result = REQ_Read_Device_EDR_TX_RX_Count(BT_PACKET_DUT);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    Confirm(META_SUCCESS);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
META_RESULT CBTPKT::REQ_Read_Device_EDR_TX_RX_Count(E_BT_PACKET_DEVICE_T device)
{
    //if (!g_bIsRunning)
    //{
    //    return;
    //}

    m_sPktDevice = device;
    BT_HCI_COMMAND hci_cmd;
    m_cBT_HCI_FT_Obj.Compose_Read_EDR_TX_RX_Count_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd, BT_PACKET_TESTER);
    META_RESULT MetaResult;
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ReadDeviceEDRTxRxCountHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }
    else
    {
        MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000, &hci_cmd, ::CNF_ReadDeviceEDRTxRxCountHCIEvent, NULL, HCE_COMMAND_COMPLETE);
    }
    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            return META_TIMEOUT;
        }
        else if (META_CANCEL == MetaResult)
        {
            return META_CANCEL;
        }
        else
        {
            return META_FAILED;
        }

    }
    return META_SUCCESS;
    //ActiveMan->SetActiveFunction(::REQ_DUT_Send_Read_EDR_TX_RX_Count_HCI_command);
}

//---------------------------------------------------------------------------
void __stdcall CBTPKT::CNF_ReadDeviceEDRTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event)  // LMP
    {
        return;
    }
    AddRxLogToStringList(*cnf, m_sPktDevice);
    if (BT_PACKET_TESTER == m_sPktDevice)
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_EDR_TX_RX_Count_HCI_Event(*cnf, m_sBTMonCnf.s_tester_monitor);
    }
    else
    {
        m_bEventOk = m_cBT_HCI_FT_Obj.DeCompose_Read_EDR_TX_RX_Count_HCI_Event(*cnf, m_sBTMonCnf.s_dut_monitor);
    }
}











//==========================================================================
void CBTPKT::REQ_Stop_Start(void)
{
    gs_bt_pkt_ptr  = this;
    g_bIsRunning  = true;
    m_bStop = true;
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_SecondHandle());

    ActiveMan->SetActiveFunction(::REQ_Stop);
}

//---------------------------------------------------------------------------
void CBTPKT::REQ_Stop(void)
{
    META_RESULT METAAPP_Result;

    // step1: (DUT) reset
    METAAPP_Result = REQ_ResetBD(BT_PACKET_DUT);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }

    // (tester) reset
    METAAPP_Result = REQ_ResetBD(BT_PACKET_TESTER);
    if (METAAPP_Result != META_SUCCESS)
    {
        Confirm(METAAPP_Result);
        return;
    }
    Confirm(META_SUCCESS);
}


//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void  CBTPKT::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd, E_BT_PACKET_DEVICE_T device)
{
    char str[1024];
    AnsiString as_log;
    sprintf(str, "%X,", hci_cmd.m_opcode & 0x00FF);
    AnsiString as_opcode_low(str);
    sprintf(str, "%X,", (hci_cmd.m_opcode & 0xFF00)>>8);
    AnsiString as_opcode_high(str);
    Array_To_Hex_String_UnsignedChar(str, hci_cmd.m_cmd, hci_cmd.m_len, ',');
    AnsiString as_cmd((const char*)str);
    if (0 == hci_cmd.m_len)
    {
        as_cmd = "";
    }
    sprintf(str, "%X,", hci_cmd.m_len);
    AnsiString as_length(str);

    if (BT_PACKET_TESTER == device)
    {
        as_log = "[" + TimeToStr(Time()) + "] Tester TX: " + as_opcode_low + as_opcode_high + as_length  + as_cmd;
    }
    else
    {
        as_log = "[" + TimeToStr(Time()) + "] DUT TX: " + as_opcode_low + as_opcode_high + as_length  + as_cmd;
    }

    m_sBTPKT.log->Add(as_log);

    PostMessage(m_sBTPKT.hPostMsgDestHandle,
                WM_ML_BT_PRINT_MSG,
                PAGEIDX_BT_PKT,
                0
               );
}

//--------------------------------------------------------------------------
void  CBTPKT::AddRxLogToStringList(BT_HCI_EVENT hci_event, E_BT_PACKET_DEVICE_T device)
{
    unsigned char str[1024];
    AnsiString as_log;
    sprintf(str, "%X,", hci_event.m_event);
    AnsiString as_event((const char*) str);
    sprintf(str, "%X,", hci_event.m_len);
    AnsiString as_length((const char*) str);
    Array_To_Hex_String_UnsignedChar(str, hci_event.m_parms, hci_event.m_len, ',');
    AnsiString as_param((const char*) str);
    if (0 == hci_event.m_len)
    {
        as_param = "";
    }

    if (BT_PACKET_TESTER == device)
    {
        as_log = "[" + TimeToStr(Time()) + "] Tester RX: " + as_event + as_length + as_param;
    }
    else
    {
        as_log = "[" + TimeToStr(Time()) + "] DUT RX: " + as_event + as_length + as_param;
    }

    m_sBTPKT.log->Add(as_log);

    PostMessage(m_sBTPKT.hPostMsgDestHandle,
                WM_ML_BT_PRINT_MSG,
                PAGEIDX_BT_PKT,
                0
               );
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CBTPKT::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//---------------------------------------------------------------------------
S_BD_ADDR CBTPKT::Get_TesterBDAddress( void )
{
    return m_sBTPKT.s_tester_bd_addr;
}

//----------------------------------------------------------------------------
S_BD_ADDR CBTPKT::Get_DUTBDAddress( void )
{
    return m_sBTPKT.s_dut_bd_addr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_BT_PKT_MONITOR_CNF CBTPKT::Get_MonitorResult( void )
{
    return m_sBTMonCnf;
}






