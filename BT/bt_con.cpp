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
 *   bt_con.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT connection test source
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
//===========================================================================
#include<iostream>

#include <fstream>

#pragma hdrstop

// BT
#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

#ifndef  _BT_CON_H_
#include "bt_con.h"
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
static CBTCT* gs_bt_ct_ptr;
static bool g_bIsRunning = false;

//==============================================================================
/*static void REQ_Stop(void)
{   gs_bt_ct_ptr->REQ_Stop();
}   */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_SendResetHCICommand( void )
{
    gs_bt_ct_ptr->REQ_SendResetHCICommand();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ResetHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Read_Local_BDAdrress_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Read_Local_BDAdrress_HCI_command();
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_ReadLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ReadLocalBDAddressHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Write_Local_BDAdrress_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Write_Local_BDAdrress_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_WriteLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_WriteLocalBDAddressHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Scan_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Scan_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ScanHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Send_Inquiry_Scan_Interval_HCI_command(void)
{
    gs_bt_ct_ptr->REQ_Send_Inquiry_Scan_Interval_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_InquiryScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_InquiryScanIntervalHCIEvent(cnf, token, usrData);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_Send_Page_Scan_Interval_HCI_command(void)
{
    gs_bt_ct_ptr->REQ_Send_Page_Scan_Interval_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_PageScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_PageScanIntervalHCIEvent(cnf, token, usrData);
}

static void  REQ_Send_Auto_Accept_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Auto_Accept_HCI_command();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Inquiry_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Inquiry_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_InquiryHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_InquiryHCIEvent( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void  REQ_Send_Inquiry_Cancel_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Inquiry_Cancel_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_InquiryCancelHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_InquiryCancelHCIEvent( cnf, token, usrData );
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_ConnectACL_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_ConnectACL_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ConnectACLHCIEvent( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void __stdcall CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_DisconnectACLAutoHCIEvent( cnf, token, usrData );
}
//---------------------------------------------------------------------------
static void __stdcall CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_LinkKeyNegReplyHCIEvent( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void  REQ_Send_DisconnectACL_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_DisconnectACL_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_DisconnectACLHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Change_ACL_Packet_Type_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_Change_ACL_Packet_Type_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ChangeACLPacketTypeHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_EnterPIN_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_EnterPIN_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_EnterPINHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_EnterPINHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_ConnectSCO_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_ConnectSCO_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ConnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_ConnectSCOHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_DisconnectSCO_HCI_command( void )
{
    gs_bt_ct_ptr->REQ_Send_DisconnectSCO_HCI_command();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_DisconnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ct_ptr->CNF_DisconnectSCOHCIEvent( cnf, token, usrData );
}
//===========================================================================
CBTCT::CBTCT( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    AllocateVector();
    m_bEventOk = false;
    m_bEvent2Ok = false;
    m_uiInquiryTimeout = 0;
    m_uiEventCount = 0;
    memset(&m_sBTCT,0,sizeof(m_sBTCT));
    memset(&m_sLocalBdAddr,0,sizeof(m_sLocalBdAddr));
    memset(&m_sScan,0,sizeof(m_sScan));
    memset(&m_sConnectACL,0,sizeof(m_sConnectACL));
    memset(&m_sDisconnectACL,0,sizeof(m_sDisconnectACL));
    memset(&m_sEnterPIN,0,sizeof(m_sEnterPIN));
    memset(&m_sConnectSCO,0,sizeof(m_sConnectSCO));
    memset(&m_sDisconnectSCO,0,sizeof(m_sDisconnectSCO));
    
}

//---------------------------------------------------------------------------
CBTCT::~CBTCT( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    DeAllocateVector();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::AllocateVector( void )
{
    if(!m_pvCTRes )
        m_pvCTRes = new vector<S_BT_CT_RES>;

}

//---------------------------------------------------------------------------
void CBTCT::DeAllocateVector( void )
{
    if(m_pvCTRes )
    {
        if( ! m_pvCTRes->empty() )
        {
            m_pvCTRes->erase( m_pvCTRes->begin(), m_pvCTRes->end() );
        }
        delete m_pvCTRes;
        m_pvCTRes = NULL;
    }
}

//---------------------------------------------------------------------------
void  CBTCT::EraseVector( void )
{
    if( ! m_pvCTRes->empty() )
    {
        m_pvCTRes->erase( m_pvCTRes->begin(), m_pvCTRes->end() );
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*void  CBTCT::REQ_Stop( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm( METAAPP_STOP );
}   */

//---------------------------------------------------------------------------
void  CBTCT::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
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



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTCT::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}




//==========================================================================
/*void  CBTCT::REQ_Stop_Start( void )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    SP_META_CancelAllBlockingCall_r( m_META_HANDLE_Obj.Get_MainHandle() );
    ActiveMan->SetActiveFunction( ::REQ_Stop );

}  */

//==========================================================================
void  CBTCT::REQ_Reset_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;
    EraseVector();
    ActiveMan->SetActiveFunction( ::REQ_SendResetHCICommand );

}

//---------------------------------------------------------------
void CBTCT::REQ_SendResetHCICommand( void )
{
    if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    Compose_Reset_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ResetHCIEvent, NULL, HCE_COMMAND_COMPLETE);

    if (!m_bEventOk)
    {
        Confirm( META_FAILED );
        return;
    }

    if (META_SUCCESS != MetaResult)
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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,03,0C,00
    if (!g_bIsRunning)
    {
        return;
    }

    AddRxLogToStringList(*cnf);

    if ((cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x03) ||
            (cnf->m_parms[2] != 0x0C) ||
            (cnf->m_parms[3] != 0x00)
       )
    {
        m_bEventOk = false;
    }
    else
    {
        m_bEventOk = true;
    }
}

//---------------------------------------------------------------------------
void CBTCT::Compose_Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;

}

//===========================================================================
//////////////////////////// Read local BD address //////////////////////////
//===========================================================================
void  CBTCT::REQ_ReadLocalBDAddress_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;
    ActiveMan->SetActiveFunction( ::REQ_Send_Read_Local_BDAdrress_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Read_Local_BDAdrress_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_Read_Local_BD_Addr_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ReadLocalBDAddressHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ReadLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Read_Local_BD_Addr_HCI_Event( *cnf, m_sLocalBdAddr );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Read_Local_BD_Addr_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x1009;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );

}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Read_Local_BD_Addr_HCI_Event( BT_HCI_EVENT hci_event, S_BD_ADDRS &s_bd_addrs )
{

    if(
        0x09 != hci_event.m_parms[1] ||
        0x10 != hci_event.m_parms[2] ||
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }

    S_BD_ADDR bd_addr;
    for( int i=0; i<BD_ADDRESS_LEN; i++ )
        bd_addr.uc_BD_Addr[i] = hci_event.m_parms[4+i];

    s_bd_addrs.us_NAP = (bd_addr.uc_BD_Addr[5] << 8) | bd_addr.uc_BD_Addr[4];
    s_bd_addrs.uc_UAP = bd_addr.uc_BD_Addr[3];
    s_bd_addrs.ui_LAP = (bd_addr.uc_BD_Addr[2] << 16) | (bd_addr.uc_BD_Addr[1] << 8) | bd_addr.uc_BD_Addr[0];
    return true;
}

//===========================================================================
///////////////////////////  write local BD address  ////////////////////////
//===========================================================================
void  CBTCT::REQ_WriteLocalBDAddress_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;
    ActiveMan->SetActiveFunction( ::REQ_Send_Write_Local_BDAdrress_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Write_Local_BDAdrress_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_Write_Local_BD_Addr_HCI_Command( hci_cmd, m_sLocalBdAddr );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_WriteLocalBDAddressHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_WriteLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Write_Local_BD_Addr_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Write_Local_BD_Addr_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BD_ADDRS s_bd_addrs )
{
    hci_cmd.m_opcode = 0xFC1A;
    hci_cmd.m_len    = 6;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = m_sLocalBdAddr.ui_LAP & 0x000000FF;
    hci_cmd.m_cmd[1] = (m_sLocalBdAddr.ui_LAP & 0x0000FF00) >>  8;
    hci_cmd.m_cmd[2] = (m_sLocalBdAddr.ui_LAP & 0x00FF0000) >> 16;
    hci_cmd.m_cmd[3] =  m_sLocalBdAddr.uc_UAP;
    hci_cmd.m_cmd[4] =  m_sLocalBdAddr.us_NAP & 0x00FF;
    hci_cmd.m_cmd[5] = (m_sLocalBdAddr.us_NAP & 0xFF00) >> 8;
}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Write_Local_BD_Addr_HCI_Event( BT_HCI_EVENT hci_event )
{
    if(
        0x1A != hci_event.m_parms[1] ||
        0xFC != hci_event.m_parms[2] ||
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }

    return true;
}

//===========================================================================
////////////////////////////       Scan            //////////////////////////
//===========================================================================
void  CBTCT::REQ_Scan_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;
    ActiveMan->SetActiveFunction( ::REQ_Send_Scan_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Scan_HCI_command( void )
{
    if(!g_bIsRunning)  return;

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
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Scan_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Inquiry_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
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
void  CBTCT::Compose_Page_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
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
void  CBTCT::Compose_Scan_Enable_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan )
{
    hci_cmd.m_opcode = 0x0C1A;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = (unsigned char) scan.e_scan_type;
}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Scan_HCI_Event( BT_HCI_EVENT hci_event )
{

    if(
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }


    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::REQ_Set_Inquiry_Scan_Interval_Start(S_BT_CT bt_ct)
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;
    m_sBTCT = bt_ct;

    ActiveMan->SetActiveFunction(::REQ_Send_Inquiry_Scan_Interval_HCI_command);
}

//---------------------------------------------------------------------------
void CBTCT::REQ_Send_Inquiry_Scan_Interval_HCI_command(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // interlaced inquiry scan
    Compose_Inquiry_Scan_Interval_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_InquiryScanIntervalHCIEvent, NULL, HCE_COMMAND_COMPLETE);

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
void __stdcall CBTCT::CNF_InquiryScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event)
    {
        return; // LMP
    }

    AddRxLogToStringList(*cnf);
    m_bEventOk = DeCompose_Inquiry_Scan_Interval_HCI_Event(*cnf);

}

//--------------------------------------------------------------------------
void CBTCT::Compose_Inquiry_Scan_Interval_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x0C1E;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command(hci_cmd);
    hci_cmd.m_cmd[0] = 0x64;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x11;
    hci_cmd.m_cmd[3] = 0x00;
}

//--------------------------------------------------------------------------
bool CBTCT::DeCompose_Inquiry_Scan_Interval_HCI_Event(BT_HCI_EVENT hci_event)
{

    if(
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }


    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::REQ_Set_Page_Scan_Interval_Start(S_BT_CT bt_ct)
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;
    m_sBTCT = bt_ct;

    ActiveMan->SetActiveFunction(::REQ_Send_Page_Scan_Interval_HCI_command);
}

//---------------------------------------------------------------------------
void CBTCT::REQ_Send_Page_Scan_Interval_HCI_command(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // interlaced inquiry scan
    Compose_Page_Scan_Interval_HCI_Command(hci_cmd);
    AddTxLogToStringList(hci_cmd);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_PageScanIntervalHCIEvent, NULL, HCE_COMMAND_COMPLETE);

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
void __stdcall CBTCT::CNF_PageScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event)
    {
        return; // LMP
    }

    AddRxLogToStringList(*cnf);
    m_bEventOk = DeCompose_Page_Scan_Interval_HCI_Event(*cnf);

}

//--------------------------------------------------------------------------
void CBTCT::Compose_Page_Scan_Interval_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x0C1C;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command(hci_cmd);
    hci_cmd.m_cmd[0] = 0x64;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x11;
    hci_cmd.m_cmd[3] = 0x00;
}

//--------------------------------------------------------------------------
bool CBTCT::DeCompose_Page_Scan_Interval_HCI_Event(BT_HCI_EVENT hci_event)
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
void  CBTCT::REQ_Auto_Accept_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;
    ActiveMan->SetActiveFunction( ::REQ_Send_Auto_Accept_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Auto_Accept_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // interlaced inquiry scan
    Compose_Auto_Accept_HCI_Command( hci_cmd );
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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_AutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Scan_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Auto_Accept_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C05;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x02;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x02;
}


//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Auto_Accept_HCI_Event( BT_HCI_EVENT hci_event )
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
///////////////////////////        Inquiry           ////////////////////////
//===========================================================================
void  CBTCT::REQ_Inquiry_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;

    //  EraseVector();
    ActiveMan->SetActiveFunction( ::REQ_Send_Inquiry_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Inquiry_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    m_uiEventCount = 0;
    Compose_Inquiry_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), m_uiInquiryTimeout, &hci_cmd, ::CNF_InquiryHCIEvent, NULL, 0x01 );

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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_InquiryHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_Inquiry_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Inquiry_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0401;
    hci_cmd.m_len    = 5;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x33;
    hci_cmd.m_cmd[1] = 0x8B;
    hci_cmd.m_cmd[2] = 0x9E;
    hci_cmd.m_cmd[3] = 0x30;
    hci_cmd.m_cmd[4] = 0x0A;

}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Inquiry_HCI_Event( BT_HCI_EVENT hci_event )
{
    if( 0x02 == hci_event.m_event )
    {
        int num_of_response = hci_event.m_parms[0];
        for( int i=0; i<num_of_response; i++ )
        {
            S_BT_CT_RES res;
            res.e_acl_status = BT_ACL_STATUS_NONE;
            for( int j=0; j<BD_ADDRESS_LEN; j++ )
            {
                res.s_bd_addr.uc_BD_Addr[j] = hci_event.m_parms[i*14+j+1];
            }

            vector<S_BT_CT_RES>:: iterator iter;
            bool match = false;
            for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
            {
                match = true;
                for( int i=0; i<BD_ADDRESS_LEN; i++ )
                {
                    if( iter->s_bd_addr.uc_BD_Addr[i] != res.s_bd_addr.uc_BD_Addr[i] )
                    {
                        match = false;
                        break;
                    }
                }

                if( match )
                    break;
            }

            if( ! match )
            {
                res.e_acl_status = BT_ACL_STATUS_NONE;
                res.e_sco_status = BT_CT_SCO_STATUS_NONE;
                res.uc_h1_acl    = 0xFF;
                res.uc_h2_acl    = 0xFF;
                res.uc_h1_sco    = 0xFF;
                res.uc_h2_sco    = 0xFF;
                m_pvCTRes->push_back( res );

                char str[3];
                AnsiString as_bd_addr;
                for( int j=BD_ADDRESS_LEN-1; j>=0; j-- )
                {
                    if( res.s_bd_addr.uc_BD_Addr[j] <= 0x0F )
                        sprintf( str, "0%X", res.s_bd_addr.uc_BD_Addr[j] );
                    else
                        sprintf( str, "%X", res.s_bd_addr.uc_BD_Addr[j] );

                    AnsiString as_str(str);
                    if( j!=0 ) as_str+= ":";
                    as_bd_addr+= as_str;
                }
                AddBDAddressToDiscovedList( as_bd_addr );
            }
        }
    }

    return true;
}

//---------------------------------------------------------------------------
void  CBTCT::AddBDAddressToDiscovedList( AnsiString as_bd_addr )
{
    m_sBTCT.list->Add( as_bd_addr );
}

//===========================================================================
///////////////////////////        Inquiry Cancel          //////////////////
//===========================================================================
void  CBTCT::REQ_Inquiry_Cancel_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    //ActiveMan->SetActiveFunction2( ::REQ_Send_Inquiry_Cancel_HCI_command );
    ActiveMan->SetActiveFunction(::REQ_Send_Inquiry_Cancel_HCI_command);
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Inquiry_Cancel_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_Inquiry_Cancel_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_InquiryCancelHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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

    //ActiveMan->SetActiveFunction2( ::REQ_Finish );
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_InquiryCancelHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_Inquiry_Cancel_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Inquiry_Cancel_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0402;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );


}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Inquiry_Cancel_HCI_Event( BT_HCI_EVENT hci_event )
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
void  CBTCT::REQ_ConnectACL_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    ActiveMan->SetActiveFunction( ::REQ_Send_ConnectACL_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_ConnectACL_HCI_command( void )
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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_ConnectACL_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void __stdcall CBTCT::CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    AddRxLogToStringList( *cnf );

    if( (0x05 == cnf->m_event) && (0x00 == cnf->m_parms[0]) )
    {
        vector<S_BT_CT_RES>:: iterator iter;
        bool match;
        for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
        {
            match = true;
            if( iter->uc_h1_acl != cnf->m_parms[1] ||
                    iter->uc_h2_acl != cnf->m_parms[2]
              )
            {
                //   match = false;
                break;
            }

            if( match )
            {
                iter->e_acl_status = BT_ACL_STATUS_NONE;
                break;
            }
        }
    }

    if (NULL != m_sBTCT.log)
    {
        PostMessage(m_sBTCT.hPostMsgDestHandle,
                    WM_ML_BT_DISCONNECT_MSG,
                    PAGEIDX_BT_CT,
                    0
                   );
    }
}

//--------------------------------------------------------------------------
void  CBTCT::Compose_ConnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
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
bool  CBTCT::DeCompose_ConnectACL_HCI_Event( BT_HCI_EVENT hci_event )
{

    if( 0x03 == hci_event.m_event )
    {
        S_BT_CT_RES ct_res;
        // status
        ct_res.e_acl_status = (E_BT_ACL_STATUS) hci_event.m_parms[0];
        if( (ct_res.e_acl_status != BT_ACL_STATUS_SUCCESS) &&
                (ct_res.e_acl_status != BT_ACL_STATUS_PAGE_TIMEOUT)
          )
        {
            ct_res.e_acl_status = BT_ACL_STATUS_FAIL;
        }

        // connection handle
        ct_res.uc_h1_acl = hci_event.m_parms[1];
        ct_res.uc_h2_acl = hci_event.m_parms[2];

        // bd address
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            ct_res.s_bd_addr.uc_BD_Addr[i] = hci_event.m_parms[3+i];
        }

        vector<S_BT_CT_RES>:: iterator iter;

        for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
        {
            bool match = true;
            for( int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] != ct_res.s_bd_addr.uc_BD_Addr[i] )
                {
                    match = false;
                    break;
                }
            }

            if( match )
            {
                *iter = ct_res;
                break;
            }
        }
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
        if (NULL != m_sBTCT.log)
        {
            PostMessage(m_sBTCT.hPostMsgDestHandle,
                        WM_ML_BT_PIN_MSG,
                        PAGEIDX_BT_CT,
                        0
                       );
        }
    }

    return true;
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEvent2Ok = DeCompose_Link_Key_Negative_Reply_HCI_Event( *cnf, m_sConnectACL );
}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Link_Key_Negative_Reply_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x040C;
    hci_cmd.m_len    = 6;
    Reset_HCI_Command( hci_cmd );
    for(int i=0; i<BD_ADDRESS_LEN; i++ )
        hci_cmd.m_cmd[i] = connect.s_bd_addr.uc_BD_Addr[i];

}

//---------------------------------------------------------------------------
bool CBTCT::DeCompose_Link_Key_Negative_Reply_HCI_Event( BT_HCI_EVENT hci_event, S_BT_CONNECT_ACL connect )
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
void  CBTCT::REQ_Change_ACL_Packet_Type_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    ActiveMan->SetActiveFunction( ::REQ_Send_Change_ACL_Packet_Type_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_Change_ACL_Packet_Type_HCI_command( void )
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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_Change_ACL_Packet_Type_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_Change_ACL_Packet_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect )
{
    hci_cmd.m_opcode = 0x040F;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command( hci_cmd );

    vector<S_BT_CT_RES>:: iterator iter;
    for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
    {
        bool match = true;
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            if( iter->s_bd_addr.uc_BD_Addr[i] != connect.s_bd_addr.uc_BD_Addr[i] )
            {
                match = false;
                break;
            }
        }

        if( match )
        {
            break;
        }
    }
    hci_cmd.m_cmd[0] = iter->uc_h1_acl;
    hci_cmd.m_cmd[1] = iter->uc_h2_acl;
    hci_cmd.m_cmd[2] = connect.us_acl_pkt_type & 0x00FF;
    hci_cmd.m_cmd[3] = (connect.us_acl_pkt_type & 0xFF00) >> 8;
}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_Change_ACL_Packet_Type_HCI_Event( BT_HCI_EVENT hci_event )
{




    return true;
}

//===========================================================================
///////////////////////////  Enter PIN  ////////////////////////
//===========================================================================
bool  CBTCT::REQ_EnterPIN_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    if( REQ_Send_EnterPIN_HCI_command() ) return false;

    return true;
}

//---------------------------------------------------------------------------
bool  CBTCT::REQ_Send_EnterPIN_HCI_command( void )
{
    if(!g_bIsRunning)  return false;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_EnterPIN_HCI_Command( hci_cmd, m_sEnterPIN );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_EnterPINHCIEvent, NULL, HCE_COMMAND_COMPLETE );
    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_EnterPINHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_EnterPIN_HCI_Event( *cnf );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_EnterPIN_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_ENTER_PIN enter_pin )
{
    hci_cmd.m_opcode = 0x040D;
    hci_cmd.m_len    = 23;
    Reset_HCI_Command( hci_cmd );

    for( int i=0; i<BD_ADDRESS_LEN; i++ )
    {
        hci_cmd.m_cmd[i] = enter_pin.s_bd_addr.uc_BD_Addr[i];
    }

    hci_cmd.m_cmd[6] = enter_pin.s_bt_pin.uc_pin_len;
    for( int i=0; i<BD_ADDRESS_LEN; i++ )
    {
        hci_cmd.m_cmd[7+i] = enter_pin.s_bt_pin.uc_PIN[i];
    }

}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_EnterPIN_HCI_Event( BT_HCI_EVENT hci_event )
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
///////////////////////////      Disonnect  ACL      ////////////////////////
//===========================================================================
void  CBTCT::REQ_DisconnectACL_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    ActiveMan->SetActiveFunction( ::REQ_Send_DisconnectACL_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_DisconnectACL_HCI_command( void )
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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_DisconnectACL_HCI_Event( *cnf, m_sDisconnectACL );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_DisconnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_DISCONNECT_ACL disconnect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0406;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );

    vector<S_BT_CT_RES>:: iterator iter;
    for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
    {
        bool match = true;
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            if( iter->s_bd_addr.uc_BD_Addr[i] != disconnect.s_bd_addr.uc_BD_Addr[i] )
            {
                match = false;
                break;
            }
        }

        if( match )
        {
            break;
        }
    }

    hci_cmd.m_cmd[0] = iter->uc_h1_acl;
    hci_cmd.m_cmd[1] = iter->uc_h2_acl;
    hci_cmd.m_cmd[2] = 0x13;

}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_DisconnectACL_HCI_Event( BT_HCI_EVENT hci_event, S_BT_DISCONNECT_ACL disconnect )
{
    if( (0x05 == hci_event.m_event) && (0x00 == hci_event.m_parms[0]) )
    {
        vector<S_BT_CT_RES>:: iterator iter;
        for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
        {
            bool match = true;
            for( int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] != disconnect.s_bd_addr.uc_BD_Addr[i] )
                {
                    match = false;
                    break;
                }
            }

            if( match )
            {
                iter->e_acl_status = BT_ACL_STATUS_NONE;
                break;
            }
        }
    }

    return true;
}


//===========================================================================
///////////////////////////        Connect  SCO      ////////////////////////
//===========================================================================
void  CBTCT::REQ_ConnectSCO_Start( S_BT_CT bt_ct )
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    ActiveMan->SetActiveFunction( ::REQ_Send_ConnectSCO_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_ConnectSCO_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_ConnectSCO_HCI_Command( hci_cmd, m_sConnectSCO );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 10000, &hci_cmd, ::CNF_ConnectSCOHCIEvent, NULL, 0x2C );

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

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_ConnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_ConnectSCO_HCI_Event( *cnf, m_sConnectSCO );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_ConnectSCO_HCI_Command(BT_HCI_COMMAND &hci_cmd, S_BT_CT_CONNECT_SCO connect)
{
    hci_cmd.m_opcode = 0x0428;
    hci_cmd.m_len    = 17;
    Reset_HCI_Command( hci_cmd );

    vector<S_BT_CT_RES>:: iterator iter;
    for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
    {
        bool match = true;
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            if( iter->s_bd_addr.uc_BD_Addr[i] != connect.s_bd_addr.uc_BD_Addr[i] )
            {
                match = false;
                break;
            }
        }

        if( match )
        {
            break;
        }
    }
    hci_cmd.m_cmd[0] = iter->uc_h1_acl;
    hci_cmd.m_cmd[1] = iter->uc_h2_acl;
    hci_cmd.m_cmd[2] = 0x40; // @4 Transmit_Bandwidth
    hci_cmd.m_cmd[3] = 0x1F;
    hci_cmd.m_cmd[4] = 0x00;
    hci_cmd.m_cmd[5] = 0x00;
    hci_cmd.m_cmd[6] = 0x40; // @4 Receive_Bandwidth
    hci_cmd.m_cmd[7] = 0x1F;
    hci_cmd.m_cmd[8] = 0x00;
    hci_cmd.m_cmd[9] = 0x00;
    hci_cmd.m_cmd[10]= 0x05; // @2 Max_Latency
    hci_cmd.m_cmd[11]= 0x00;
    hci_cmd.m_cmd[12]= 0xAC; // @2 Voice_Setting
    hci_cmd.m_cmd[13]= 0x00;
    hci_cmd.m_cmd[14]= 0x00; // @1 Retransmission_Effort
    hci_cmd.m_cmd[15]=  connect.e_pkt_type & 0x00FF; // @2 Packet_Type
    hci_cmd.m_cmd[16]= (connect.e_pkt_type & 0xFF00) >> 8;
}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_ConnectSCO_HCI_Event(BT_HCI_EVENT hci_event, S_BT_CT_CONNECT_SCO connect)
{
    if( 0x2C == hci_event.m_event )
    {
        vector<S_BT_CT_RES>:: iterator iter;
        for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
        {
            bool match = true;
            for( int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] != connect.s_bd_addr.uc_BD_Addr[i] )
                {
                    match = false;
                    break;
                }
            }

            if( match )
            {
                break;
            }
        }

        if( hci_event.m_parms[0] != 0   )
        {
            iter->e_sco_status = BT_CT_SCO_STATUS_FAIL;
            return false;
        }

        iter->e_sco_status = BT_CT_SCO_STATUS_SUCCESS;
        iter->uc_h1_sco    = hci_event.m_parms[1];
        iter->uc_h2_sco    = hci_event.m_parms[2];
    }
    return true;
}

//===========================================================================
///////////////////////////      Disonnect  SCO      ////////////////////////
//===========================================================================
void  CBTCT::REQ_DisconnectSCO_Start(S_BT_CT bt_ct)
{
    gs_bt_ct_ptr  = this;
    g_bIsRunning  = true;

    m_sBTCT = bt_ct;


    ActiveMan->SetActiveFunction(::REQ_Send_DisconnectSCO_HCI_command);
}

//---------------------------------------------------------------------------
void  CBTCT::REQ_Send_DisconnectSCO_HCI_command(void)
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;
    //m_uiEventCount = 0;
    Compose_DisconnectSCO_HCI_Command(hci_cmd, m_sDisconnectSCO);
    AddTxLogToStringList(hci_cmd);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_DisconnectSCOHCIEvent, NULL, 0x05 );

    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
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
            Confirm(META_FAILED);
        }
        return;
    }

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTCT::CNF_DisconnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event) // LMP
    {
        return;
    }
    // m_uiEventCount++;

    AddRxLogToStringList( *cnf );

    m_bEventOk = DeCompose_DisconnectSCO_HCI_Event( *cnf, m_sDisconnectSCO );

}

//--------------------------------------------------------------------------
void  CBTCT::Compose_DisconnectSCO_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CT_DISCONNECT_SCO disconnect )
{
    // 33 8B 9E 30 0A

    hci_cmd.m_opcode = 0x0406;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );

    vector<S_BT_CT_RES>:: iterator iter;
    for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
    {
        bool match = true;
        for( int i=0; i<BD_ADDRESS_LEN; i++ )
        {
            if( iter->s_bd_addr.uc_BD_Addr[i] != disconnect.s_bd_addr.uc_BD_Addr[i] )
            {
                match = false;
                break;
            }
        }

        if( match )
        {
            iter->e_sco_status = BT_CT_SCO_STATUS_NONE;
            break;
        }
    }

    hci_cmd.m_cmd[0] = iter->uc_h1_sco;
    hci_cmd.m_cmd[1] = iter->uc_h2_sco;
    hci_cmd.m_cmd[2] = 0x13;

}

//--------------------------------------------------------------------------
bool  CBTCT::DeCompose_DisconnectSCO_HCI_Event(BT_HCI_EVENT hci_event, S_BT_CT_DISCONNECT_SCO disconnect)
{
    // if( (0x05 == hci_event.m_event) && (0x00 == hci_event.m_parms[0]) )
    {
        vector<S_BT_CT_RES>:: iterator iter;
        for( iter = m_pvCTRes->begin(); iter != m_pvCTRes->end(); iter++ )
        {
            bool match = true;
            for( int i=0; i<BD_ADDRESS_LEN; i++ )
            {
                if( iter->s_bd_addr.uc_BD_Addr[i] != disconnect.s_bd_addr.uc_BD_Addr[i] )
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                iter->e_sco_status = BT_CT_SCO_STATUS_NONE;
                break;
            }
        }
    }

    return true;
}

//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void  CBTCT::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBTCT.log)
    {
        return;
    }

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

    m_sBTCT.log->Add( as_log );

    PostMessage(
        m_sBTCT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_CT,
        0
    );
}

//--------------------------------------------------------------------------
void  CBTCT::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL == m_sBTCT.log)
    {
        return;
    }

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
    m_sBTCT.log->Add( as_log );

    PostMessage(
        m_sBTCT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_CT,
        0
    );
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CBTCT::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_BD_ADDRS CBTCT::Get_LocalBdAddr( void )
{
    return m_sLocalBdAddr;
}

//---------------------------------------------------------------------------
void CBTCT::Set_LocalBdAddr( S_BD_ADDRS bd_addr )
{
    m_sLocalBdAddr = bd_addr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::Set_ScanParameter( S_BT_SCAN scan )
{
    m_sScan = scan;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::Set_InquiryTimeout( unsigned int timeout )
{
    m_uiInquiryTimeout = timeout;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
vector<S_BT_CT_RES>*  CBTCT::Get_CtResVector( void )
{
    return m_pvCTRes;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::Set_EnterPINParameter( S_BT_ENTER_PIN enter_pin )
{
    m_sEnterPIN = enter_pin;
}

//--------------------------------------------------------------------------
void CBTCT::Set_ConnectACLParameter( S_BT_CONNECT_ACL connect )
{
    m_sConnectACL = connect;
}

//---------------------------------------------------------------------------
void CBTCT::Set_DisconnectACLParameter( S_BT_DISCONNECT_ACL disconnect )
{
    m_sDisconnectACL = disconnect;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTCT::Set_ConnectSCOParameter( S_BT_CT_CONNECT_SCO connect )
{
    m_sConnectSCO = connect;
}

//---------------------------------------------------------------------------
void CBTCT::Set_DisconnectSCOParameter( S_BT_CT_DISCONNECT_SCO disconnect )
{
    m_sDisconnectSCO = disconnect;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
