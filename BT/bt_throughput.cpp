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
 *   bt_throughput.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT throughput test source
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
 * Jun 19 2008 mtk00490
 * [STP100001739] [META] META ver 5.0820.0
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
#include <stdlib.h>

#pragma hdrstop

// BT
#ifndef  _BT_THROUGHPUT_H_
#include "bt_throughput.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

// man
#ifndef  _MAN_TIMER_H_
#include "man_timer.h"
#endif

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
static CBTTT*  gs_bt_tt_ptr;
static bool g_bIsRunning = false;
static bool g_bTxStop = false;
static bool g_bRxStop = false;
//static S_BT_TT_MONITOR_RX_CNF g_sBTRxCnf;
//==============================================================================
static void  REQ_TimeOut( void )
{
    gs_bt_tt_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Stop( void )
{
    gs_bt_tt_ptr->REQ_Stop();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_bt_tt_ptr->REQ_Finish();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Scan_HCI_command( void )
{
    gs_bt_tt_ptr->REQ_Send_Scan_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_ScanHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Auto_Accept_HCI_command( void )
{
    gs_bt_tt_ptr->REQ_Send_Auto_Accept_HCI_command();
}

//---------------------------------------------------------------------------
void __stdcall CNF_ConnectACLAutoHCIEvent(const BT_HCI_EVENT *hci_event, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_ConnectACLAutoHCIEvent( hci_event, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_ConnectACL_HCI_command( void )
{
    gs_bt_tt_ptr->REQ_Send_ConnectACL_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_ConnectACLHCIEvent( cnf, token, usrData );
}


//---------------------------------------------------------------------------
static void __stdcall CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_DisconnectACLAutoHCIEvent( cnf, token, usrData );
}
//---------------------------------------------------------------------------
static void __stdcall CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_LinkKeyNegReplyHCIEvent( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void  REQ_Send_DisconnectACL_HCI_command( void )
{
    gs_bt_tt_ptr->REQ_Send_DisconnectACL_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_DisconnectACLHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Change_ACL_Packet_Type_HCI_command( void )
{
    gs_bt_tt_ptr->REQ_Send_Change_ACL_Packet_Type_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_ChangeACLPacketTypeHCIEvent( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void  REQ_TX_Data( void )
{
    gs_bt_tt_ptr->REQ_TX_Data();
}

//---------------------------------------------------------------------------
void __stdcall CNF_TX_Data_V0(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_TX_Data_V0( cnf, token, usrData );
}

//---------------------------------------------------------------------------
void __stdcall CNF_TX_Data_V1(const BT_HCI_TX_PURE_TEST_STAT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_TX_Data_V1( cnf, token, usrData );
}

//---------------------------------------------------------------------------
void __stdcall CNF_TX_Data_V2(const BT_HCI_TX_PURE_TEST_STAT_V2 *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_TX_Data_V2(cnf, token, usrData);
}

//---------------------------------------------------------------------------
void  REQ_RX_Data( void )
{
    gs_bt_tt_ptr->REQ_RX_Data();
}

//---------------------------------------------------------------------------
void __stdcall CNF_RX_Data_V0(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_RX_Data_V0( cnf, token, usrData );
}

//---------------------------------------------------------------------------
void __stdcall CNF_RX_Data_V2(const BT_HCI_RX_PURE_TEST_STAT *cnf, const short token, void *usrData)
{
    gs_bt_tt_ptr->CNF_RX_Data_V2( cnf, token, usrData );
}

//---------------------------------------------------------------------------
void  REQ_Stop_RX_Data(void)
{
    gs_bt_tt_ptr->REQ_Stop_RX_Data();
}

//===========================================================================
CBTTT::CBTTT( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iEventCount = 0;
    m_bEventOk = false;
    m_bEvent2Ok = false;
    m_eTtVer = BT_TT_VER_0;
    memset(&m_sScan,0,sizeof(m_sScan));
    memset(&m_sConnectACL,0,sizeof(m_sConnectACL));
    memset(&m_sDisconnectACL,0,sizeof(m_sDisconnectACL));
    memset(&m_sBTTT,0,sizeof(m_sBTTT));
    memset(&m_sBTTxPar,0,sizeof(m_sBTTxPar));
    memset(&m_sBTTTRes,0,sizeof(m_sBTTTRes));
    memset(&m_sBTRxCnf,0,sizeof(m_sBTRxCnf));
    memset(&m_sBTTxCnf,0,sizeof(m_sBTTxCnf));
}

//---------------------------------------------------------------------------
CBTTT::~CBTTT( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_Finish( void )
{
    if( ! g_bIsRunning )  return;

    Confirm(META_SUCCESS);
    g_bIsRunning = false;
}
//==========================================================================
void  CBTTT::REQ_Stop_Start(void)
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;
    g_bTxStop = true;
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    REQ_Stop();
}
//---------------------------------------------------------------------------
void  CBTTT::REQ_Stop( void )
{
    if( ! g_bIsRunning )  return;

    Confirm(METAAPP_STOP);
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_TimeOut( void )
{
    if( ! g_bIsRunning )  return;

    Confirm( META_TIMEOUT );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void CBTTT::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if(ConfirmCallback==0)  return;
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
////////////////////////////       Scan            //////////////////////////
//===========================================================================
void  CBTTT::REQ_Scan_Start( S_BT_TT bt_tt )
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;
    ActiveMan->SetActiveFunction( ::REQ_Send_Scan_HCI_command );
}

//---------------------------------------------------------------------------
void CBTTT::REQ_Send_Scan_HCI_command(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // interlaced inquiry scan
    Compose_Inquiry_Scan_Type_HCI_Command( hci_cmd, m_sScan );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ScanHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {

        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    // interlaced page scan
    Compose_Page_Scan_Type_HCI_Command( hci_cmd, m_sScan );
    AddTxLogToStringList( hci_cmd );
    MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ScanHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {

        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    //  scan type
    Compose_Scan_Enable_HCI_Command( hci_cmd, m_sScan );
    AddTxLogToStringList( hci_cmd );
    MetaResult = SP_META_BT_RegisterAutoCallback_r( m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_ConnectACLAutoHCIEvent );
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ScanHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {

        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Scan_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTTT::Compose_Inquiry_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
{
    hci_cmd.m_opcode = 0x0C43;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    if( scan.b_interlaced_inquiry_scan )
        hci_cmd.m_cmd[0] = 1;
    else
        hci_cmd.m_cmd[0] = 0;
}

//--------------------------------------------------------------------------
void  CBTTT::Compose_Page_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
{
    hci_cmd.m_opcode = 0x0C47;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    if( scan.b_interlaced_page_scan )
        hci_cmd.m_cmd[0] = 1;
    else
        hci_cmd.m_cmd[0] = 0;
}

//--------------------------------------------------------------------------
void  CBTTT::Compose_Scan_Enable_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
{
    hci_cmd.m_opcode = 0x0C1A;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = (unsigned char) scan.e_scan_type;
}

//--------------------------------------------------------------------------
bool  CBTTT::DeCompose_Scan_HCI_Event( BT_HCI_EVENT hci_event )
{

    if(
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }


    return true;
}

//===========================================================================
////////////////////////////       auto accept     //////////////////////////
//===========================================================================
void  CBTTT::REQ_Auto_Accept_Start( S_BT_TT bt_tt )
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;
    ActiveMan->SetActiveFunction( ::REQ_Send_Auto_Accept_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_Send_Auto_Accept_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // interlaced inquiry scan
    Compose_Auto_Accept_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_RegisterAutoCallback_r( m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_ConnectACLAutoHCIEvent );
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ScanHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {

        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_AutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Scan_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void __stdcall CBTTT::CNF_ConnectACLAutoHCIEvent(const BT_HCI_EVENT *hci_event, const short token, void *usrData)
{
    AddRxLogToStringList( *hci_event );

    if( 0x03 == hci_event->m_event )
    {
        if( 0x00 == hci_event->m_parms[0] ) // success
        {
            m_sBTTTRes.e_acl_status = BT_ACL_STATUS_SUCCESS;
            m_sBTTTRes.uc_h1_acl    = hci_event->m_parms[1];
            m_sBTTTRes.uc_h2_acl    = hci_event->m_parms[2];

            for( int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                m_sBTTTRes.s_bd_addr.uc_BD_Addr[i] = hci_event->m_parms[3+i];
            }
        }
        else if( 0x04 == hci_event->m_parms[0] ) // page timeout
        {
            m_sBTTTRes.e_acl_status = BT_ACL_STATUS_PAGE_TIMEOUT;
        }
        else // fail
        {
            m_sBTTTRes.e_acl_status = BT_ACL_STATUS_FAIL;
        }

        PostMessage(
            m_sBTTT.hPostMsgDestHandle,
            MW_ML_BT_CONNECT_MSG,
            PAGEIDX_BT_TT,
            0
        );
    }


}
//--------------------------------------------------------------------------
void  CBTTT::Compose_Auto_Accept_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C05;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x02;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x02;
}


//--------------------------------------------------------------------------
bool  CBTTT::DeCompose_Auto_Accept_HCI_Event( BT_HCI_EVENT hci_event )
{

    if(
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }


    return true;
}

//===========================================================================
///////////////////////////        Connect           ////////////////////////
//===========================================================================
void  CBTTT::REQ_ConnectACL_Start( S_BT_TT bt_tt )
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;


    ActiveMan->SetActiveFunction( ::REQ_Send_ConnectACL_HCI_command );
}

//---------------------------------------------------------------------------
void CBTTT::REQ_Send_ConnectACL_HCI_command(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_ConnectACL_HCI_Command( hci_cmd, m_sConnectACL );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_RegisterAutoCallback_r( m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_DisconnectACLAutoHCIEvent );
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 40000, &hci_cmd, ::CNF_ConnectACLHCIEvent, NULL, 0x1D );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_ConnectACL_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void __stdcall CBTTT::CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *hci_event, const short token, void *usrData)
{
    AddRxLogToStringList( *hci_event );

    if( (0x05 == hci_event->m_event) && (0x00 == hci_event->m_parms[0]) ) // receive disconnect event
    {
        m_sBTTTRes.e_acl_status = BT_ACL_STATUS_NONE;
    }


}

//--------------------------------------------------------------------------
void  CBTTT::Compose_ConnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0405;
    hci_cmd.m_len    = 13;
    Reset_HCI_Command( hci_cmd );
    for(int i=0; i<BD_ADDRESS_LEN; i++ )
        hci_cmd.m_cmd[i] = connect.s_bd_addr.uc_BD_Addr[i];
    hci_cmd.m_cmd[6] = connect.us_acl_pkt_type & 0x00FF;
    hci_cmd.m_cmd[7] = (connect.us_acl_pkt_type & 0xFF00) >> 8;
    hci_cmd.m_cmd[8] = 0x01;
    hci_cmd.m_cmd[9] = 0x00;
    hci_cmd.m_cmd[10]= 0x00;
    hci_cmd.m_cmd[11]= 0x00;
    hci_cmd.m_cmd[12]= 0x01;
}

//--------------------------------------------------------------------------
bool  CBTTT::DeCompose_ConnectACL_HCI_Event( BT_HCI_EVENT hci_event )
{

    if( 0x03 == hci_event.m_event )
    {
        S_BT_TT_RES tt_res;
        // status
        tt_res.e_acl_status = (E_BT_ACL_STATUS) hci_event.m_parms[0];
        if( (tt_res.e_acl_status != BT_ACL_STATUS_SUCCESS) &&
                (tt_res.e_acl_status != BT_ACL_STATUS_PAGE_TIMEOUT)
          )
        {
            tt_res.e_acl_status = BT_ACL_STATUS_FAIL;
        }

        // connection handle
        tt_res.uc_h1_acl = hci_event.m_parms[1];
        tt_res.uc_h2_acl = hci_event.m_parms[2];

        // bd address
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            tt_res.s_bd_addr.uc_BD_Addr[i] = hci_event.m_parms[3+i];
        }
        m_sBTTTRes = tt_res;

    }
    else if( 0x17 == hci_event.m_event )
    {
#if 0
        BT_HCI_COMMAND hci_cmd;
        Compose_Link_Key_Negative_Reply_HCI_Command( hci_cmd, m_sConnectACL );
        AddTxLogToStringList( hci_cmd );
        m_bEvent2Ok = false;
        META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_LinkKeyNegReplyHCIEvent, NULL, HCE_COMMAND_COMPLETE );

        if( (META_SUCCESS != MetaResult) || (!m_bEvent2Ok) )
        {
            if( META_TIMEOUT == MetaResult )
            {
                Confirm( META_TIMEOUT );
                return false;
            }
            else if( META_CANCEL == MetaResult )
            {
                Confirm( META_CANCEL );
                return false;
            }
            else
            {
                Confirm( META_FAILED );
                return false;
            }
        }
#endif

    }
    else if( 0x16 == hci_event.m_event )
    {
        PostMessage(
            m_sBTTT.hPostMsgDestHandle,
            WM_ML_BT_PIN_MSG,
            PAGEIDX_BT_TT,
            0
        );
    }

    return true;
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEvent2Ok = DeCompose_Link_Key_Negative_Reply_HCI_Event( *cnf, m_sConnectACL );
}

//--------------------------------------------------------------------------
void  CBTTT::Compose_Link_Key_Negative_Reply_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x040C;
    hci_cmd.m_len    = 6;
    Reset_HCI_Command( hci_cmd );
    for(int i=0; i<BD_ADDRESS_LEN; i++ )
        hci_cmd.m_cmd[i] = connect.s_bd_addr.uc_BD_Addr[i];

}

//---------------------------------------------------------------------------
bool CBTTT::DeCompose_Link_Key_Negative_Reply_HCI_Event( BT_HCI_EVENT hci_event, S_BT_CONNECT_ACL connect )
{
    if( 0x00 != hci_event.m_parms[3] )
    {
        return false;
    }

    for( int i=0; i<BD_ADDRESS_LEN; i++ )
    {
        if( connect.s_bd_addr.uc_BD_Addr[i] != hci_event.m_parms[4+i] )
            return false;
    }

    return true;
}

//===========================================================================
///////////////////////////  Change ACL packet type  ////////////////////////
//===========================================================================
void  CBTTT::REQ_Change_ACL_Packet_Type_Start( S_BT_TT bt_tt )
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;


    ActiveMan->SetActiveFunction( ::REQ_Send_Change_ACL_Packet_Type_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_Send_Change_ACL_Packet_Type_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_Change_ACL_Packet_Type_HCI_Command( hci_cmd, m_sConnectACL );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_ChangeACLPacketTypeHCIEvent, NULL, 0x1D );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_Change_ACL_Packet_Type_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTTT::Compose_Change_ACL_Packet_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
{
    hci_cmd.m_opcode = 0x040F;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command( hci_cmd );


    hci_cmd.m_cmd[0] = m_sBTTTRes.uc_h1_acl;
    hci_cmd.m_cmd[1] = m_sBTTTRes.uc_h2_acl;
    hci_cmd.m_cmd[2] = connect.us_acl_pkt_type & 0x00FF;
    hci_cmd.m_cmd[3] = (connect.us_acl_pkt_type & 0xFF00) >> 8;
}

//--------------------------------------------------------------------------
bool  CBTTT::DeCompose_Change_ACL_Packet_Type_HCI_Event( BT_HCI_EVENT hci_event )
{




    return true;
}


//===========================================================================
///////////////////////////      Disonnect  ACL      ////////////////////////
//===========================================================================
void  CBTTT::REQ_DisconnectACL_Start( S_BT_TT bt_tt )
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;


    ActiveMan->SetActiveFunction( ::REQ_Send_DisconnectACL_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_Send_DisconnectACL_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_DisconnectACL_HCI_Command( hci_cmd, m_sDisconnectACL );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_DisconnectACLHCIEvent, NULL, 0x05 );

    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_DisconnectACL_HCI_Event( *cnf, m_sDisconnectACL );

}

//--------------------------------------------------------------------------
void  CBTTT::Compose_DisconnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_DISCONNECT_ACL disconnect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0406;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );

    hci_cmd.m_cmd[0] = m_sBTTTRes.uc_h1_acl;
    hci_cmd.m_cmd[1] = m_sBTTTRes.uc_h2_acl;
    hci_cmd.m_cmd[2] = 0x13;

}

//--------------------------------------------------------------------------
bool  CBTTT::DeCompose_DisconnectACL_HCI_Event( BT_HCI_EVENT hci_event, S_BT_DISCONNECT_ACL disconnect )
{
    if( (0x05 == hci_event.m_event) && (0x00 == hci_event.m_parms[0]) )
    {
        m_sBTTTRes.e_acl_status = BT_ACL_STATUS_NONE;
    }

    return true;
}

//===========================================================================
///////////////////////////         TX data          ////////////////////////
//===========================================================================
void  CBTTT::REQ_TX_Data_Start(E_BT_TT_VER_T ver, S_BT_TT bt_tt)
{
    gs_bt_tt_ptr  = this;
    //g_bIsRunning  = true;
    m_eTtVer = ver;
    m_sBTTT = bt_tt;
    m_sBTTxCnf.ui_tx_pkt_length = 0;
    m_sBTTxCnf.ui_used_time     = 0;
    g_bTxStop = false;
    ActiveMan->SetActiveFunction(::REQ_TX_Data);
}

//---------------------------------------------------------------------------
void CBTTT::REQ_TX_Data(void)
{
    if (g_bTxStop)
    {
        return;
    }

    META_RESULT MetaResult;
    if (BT_TT_VER_0 == m_eTtVer)
    {
        BT_HCI_BUFFER buffer;
        buffer.m_con_hdl = (m_sBTTTRes.uc_h2_acl<<8) | m_sBTTTRes.uc_h1_acl;
        buffer.m_len     = m_sBTTxPar.us_data_len;
        MetaResult = SP_META_BT_SendHCIData_r(m_META_HANDLE_Obj.Get_MainHandle(), 30000, &buffer, ::CNF_TX_Data_V0, NULL);
    }
    else
    {
        BT_HCI_TX_PURE_TEST tx_pure_req;
        tx_pure_req.m_con_hdl   = (m_sBTTTRes.uc_h2_acl<<8) | m_sBTTTRes.uc_h1_acl;
        tx_pure_req.m_len       = m_sBTTxPar.us_data_len;
        tx_pure_req.m_total_pks = m_sBTTxPar.us_packet_count;
        unsigned int timeout;
        if (30000 < (tx_pure_req.m_len * tx_pure_req.m_total_pks / 10))
        {
            timeout = tx_pure_req.m_len * tx_pure_req.m_total_pks / 10;
        }
        else
        {
            timeout = 30000;
        }
        if (BT_TT_VER_1 == m_eTtVer)
        {
            MetaResult = SP_META_BT_TxPureTest_r(m_META_HANDLE_Obj.Get_MainHandle(), timeout, &tx_pure_req, ::CNF_TX_Data_V1, NULL);
        }
        else
        {
            MetaResult = SP_META_BT_TxPureTest_V2_r(m_META_HANDLE_Obj.Get_MainHandle(), timeout, &tx_pure_req, ::CNF_TX_Data_V2, NULL);
        }
    }

    if (META_SUCCESS != MetaResult)
    {
        g_bTxStop = true;
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else if (META_CANCEL == MetaResult)
        {
            Confirm(META_CANCEL);
        }
        else
        {
            Confirm(META_FAILED );
        }
        return;
    }

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_TX_Data_V0(const BT_HCI_PACKET *cnf, const short token, void *usrData)
{
    if (g_bTxStop)
    {
        return;
    }

    //m_sBTTxCnf.ui_tx_pkt_count++;
    m_sBTTxCnf.ui_tx_pkt_length += cnf->m_len;
    // PostMessage(
    //                      m_sBTTT.hPostMsgDestHandle,
    //                      WM_ML_BT_TT_TX_STATUS,
    //                      m_sBTTxCnf.ui_tx_pkt_count,
    //                      0
    //                     );

    PostMessage(m_sBTTT.hPostMsgDestHandle,
                WM_ML_BT_TT_TX_STATUS,
                m_sBTTxCnf.ui_tx_pkt_length,
                0
               );

    if (m_sBTTxCnf.ui_tx_pkt_length >= (unsigned int) (m_sBTTxPar.us_packet_count*m_sBTTxPar.us_data_len))
    {
        g_bTxStop = true;
    }
    else
    {
        ActiveMan->SetActiveFunction(::REQ_TX_Data );
        return;
    }
}

//---------------------------------------------------------------------------
//void __stdcall CBTTT::CNF_TX_Data(const BT_HCI_PACKET *cnf, const short token, void *usrData)
void __stdcall CBTTT::CNF_TX_Data_V1(const BT_HCI_TX_PURE_TEST_STAT *cnf, const short token, void *usrData)
{
    if (g_bTxStop)
    {
        return;
    }
    // if (cnf->status != 0)
    // {
    //     Confirm(META_FAILED);
    //     return;
    // }
    m_sBTTxCnf.ui_tx_pkt_length += cnf->m_len;
    m_sBTTxCnf.ui_used_time     += cnf->m_used_time;

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_TT_TX_STATUS,
        m_sBTTxCnf.ui_tx_pkt_length,
        m_sBTTxCnf.ui_used_time
    );

    // if( (m_sBTTxCnf.us_tx_pkt_count < m_sBTTxPar.us_packet_count) && (! g_bTxStop) )
    // {
    //     ActiveMan->SetActiveFunction( ::REQ_TX_Data );
    //     return;
    // }
    if (m_sBTTxCnf.ui_tx_pkt_length >= (unsigned int) (m_sBTTxPar.us_packet_count*m_sBTTxPar.us_data_len))
    {
        g_bTxStop = true;
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTTT::CNF_TX_Data_V2(const BT_HCI_TX_PURE_TEST_STAT_V2 *cnf, const short token, void *usrData)
{
    if (g_bTxStop)
    {
        return;
    }

    m_sBTTxCnf.ui_tx_pkt_length = cnf->m_u2PktSentNum * m_sBTTxPar.us_data_len;
    m_sBTTxCnf.ui_used_time     = cnf->m_u4UsedTime;

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_TT_TX_STATUS,
        m_sBTTxCnf.ui_tx_pkt_length,
        m_sBTTxCnf.ui_used_time
    );

    if (m_sBTTxCnf.ui_tx_pkt_length >= (unsigned int) (m_sBTTxPar.us_packet_count*m_sBTTxPar.us_data_len))
    {
        g_bTxStop = true;
    }
}

//===========================================================================
///////////////////////////         RX data          ////////////////////////
//===========================================================================
void CBTTT::REQ_RX_Data_Start(E_BT_TT_VER_T ver, S_BT_TT bt_tt)
{
    gs_bt_tt_ptr  = this;
//    g_bIsRunning  = true;
    m_eTtVer = ver;
    m_sBTTT = bt_tt;
    m_sBTRxCnf.ui_rx_pkt_length = 0;
    m_sBTRxCnf.ui_used_time     = 0;
    g_bRxStop = false;
    ActiveMan->SetActiveFunction(::REQ_RX_Data);
}

//---------------------------------------------------------------------------
void CBTTT::REQ_RX_Data(void)
{
    if (g_bRxStop)
    {
        return;
    }
    BT_HCI_BUFFER buffer;
    buffer.m_con_hdl = (m_sBTTTRes.uc_h2_acl << 8) | m_sBTTTRes.uc_h1_acl;
    buffer.m_len     = m_sBTTxPar.us_data_len;
    META_RESULT MetaResult;
    switch (m_eTtVer)
    {
    case BT_TT_VER_0:
    {
        MetaResult = SP_META_BT_ReceiveHCIData_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_RX_Data_V0);
    }
    break;

    case BT_TT_VER_1:
    {
        MetaResult = SP_META_BT_RxTestStart_r(m_META_HANDLE_Obj.Get_MainHandle(), 4294967295, ::CNF_RX_Data_V2);
    }
    break;

    case BT_TT_VER_2:
    {
        MetaResult = SP_META_BT_RxTestStart_V2_r(m_META_HANDLE_Obj.Get_MainHandle(), 4294967295, ::CNF_RX_Data_V2);
    }
    break;
    }

    if (META_SUCCESS != MetaResult)
    {
        g_bRxStop = true;
        if (META_TIMEOUT == MetaResult)
        {
            Confirm( META_TIMEOUT );
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
void __stdcall CBTTT::CNF_RX_Data_V0(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
{
    // if(!g_bIsRunning)  return;
    if (g_bRxStop)
    {
        return;
    }
    //g_sBTRxCnf.ui_rx_pkt_count += (cnf->m_len);
    m_sBTRxCnf.ui_rx_pkt_length += cnf->m_len;

    // PostMessage(
    //                      m_sBTTT.hPostMsgDestHandle,
    //                      WM_ML_BT_TT_RX_STATUS,
    //                      g_sBTRxCnf.ui_rx_pkt_count,
    //                      0
    //                     );

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_TT_RX_STATUS,
        m_sBTRxCnf.ui_rx_pkt_length,
        0
    );

}

//---------------------------------------------------------------------------
//void __stdcall CBTTT::CNF_RX_Data(const BT_HCI_BUFFER *cnf, const short token, void *usrData)
void __stdcall CBTTT::CNF_RX_Data_V2(const BT_HCI_RX_PURE_TEST_STAT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning || g_bRxStop)  return;

    //  if (cnf->status != 0)
    //  {
    //      Confirm(META_FAILED);
    //      return;
    //  }

    m_sBTRxCnf.ui_rx_pkt_length += cnf->m_len;
    m_sBTRxCnf.ui_used_time     += cnf->m_used_time;

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_TT_RX_STATUS,
        m_sBTRxCnf.ui_rx_pkt_length,
        m_sBTRxCnf.ui_used_time
    );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTTT::REQ_Stop_RX_Data_Start(S_BT_TT bt_tt)
{
    gs_bt_tt_ptr  = this;
    g_bIsRunning  = true;

    m_sBTTT = bt_tt;
    m_sBTRxCnf.ui_rx_pkt_length = 0;
    m_sBTRxCnf.ui_used_time     = 0;
    g_bRxStop = true;
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    ActiveMan->SetActiveFunction(::REQ_Stop_RX_Data);
}

//---------------------------------------------------------------------------
void  CBTTT::REQ_Stop_RX_Data(void)
{
    if(!g_bIsRunning)  return;

    META_RESULT MetaResult = SP_META_BT_RxTestEnd_r(m_META_HANDLE_Obj.Get_MainHandle(), 500);

    if (META_SUCCESS != MetaResult)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm( META_TIMEOUT );
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
}

//---------------------------------------------------------------------------
void  CBTTT::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

//===========================================================================
////////////////////////////        Query          //////////////////////////
//===========================================================================
E_BT_TT_VER_T CBTTT::Query_TtTestVersion(void)
{
    META_RESULT MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, "SP_META_BT_TxPureTest_V2_r");
    if (META_SUCCESS != MetaResult)
    {
        return BT_TT_VER_0;
    }

    return BT_TT_VER_2;
}
//===========================================================================
////////////////////////////   Log  information   ///////////////////////////
//===========================================================================
void  CBTTT::AddTxLogToStringList( BT_HCI_COMMAND hci_cmd  )
{
    char        str[1024];
    AnsiString as_log;
    sprintf( str, "%X,", hci_cmd.m_opcode & 0x00FF );
    AnsiString as_opcode_low(str);
    sprintf( str, "%X,", (hci_cmd.m_opcode & 0xFF00)>>8 );
    AnsiString as_opcode_high(str);
    Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    AnsiString as_cmd( (const char*)str );
    if( 0 == hci_cmd.m_len )
        as_cmd = "";
    sprintf( str, "%X,", hci_cmd.m_len );
    AnsiString as_length(str);

    as_log = "[" + TimeToStr(Time()) + "] TX: " + as_opcode_low + as_opcode_high + as_length  + as_cmd;


    m_sBTTT.log->Add( as_log );

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_TT,
        0
    );
}

//--------------------------------------------------------------------------
void  CBTTT::AddRxLogToStringList( BT_HCI_EVENT hci_event )
{
    unsigned char        str[1024];
    AnsiString as_log;
    sprintf( str, "%X,", hci_event.m_event );
    AnsiString as_event( (const char*) str );
    sprintf( str, "%X,", hci_event.m_len );
    AnsiString as_length( (const char*) str );
    Array_To_Hex_String_UnsignedChar( str, hci_event.m_parms, hci_event.m_len, ',' );
    AnsiString as_param( (const char*) str );
    if(  0 == hci_event.m_len )
        as_param = "";

    as_log = "[" + TimeToStr(Time()) + "] RX: " + as_event + as_length + as_param;

    m_sBTTT.log->Add( as_log );

    PostMessage(
        m_sBTTT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_TT,
        0
    );
}


//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CBTTT::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTTT::Set_ScanParameter( S_BT_SCAN scan )
{
    m_sScan = scan;
}

//--------------------------------------------------------------------------
void CBTTT::Set_ConnectACLParameter( S_BT_CONNECT_ACL connect )
{
    m_sConnectACL = connect;
}

//---------------------------------------------------------------------------
void CBTTT::Set_DisconnectACLParameter( S_BT_DISCONNECT_ACL disconnect )
{
    m_sDisconnectACL = disconnect;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTTT::Set_TxParameter( S_BT_TT_TX_PARAMETER  par)
{
    m_sBTTxPar = par;
}

//---------------------------------------------------------------------------
S_BT_TT_RES CBTTT::Get_TTResult( void )
{
    return  m_sBTTTRes;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
E_BT_TT_VER_T CBTTT::Get_TtTestVer(void)
{
    return m_eTtVer;
}








