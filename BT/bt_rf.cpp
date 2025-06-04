#include<iostream>
#include <fstream>
#pragma hdrstop
#include "metaapp_common.h"
#include "bt_hci_common.h"
#include "bt_rf.h"
#include "man_active.h"
#include "ft_utils.h"
#include "meta_lab_msg.h"

#define INVALID_TAG  -1

static CBTRF*  gs_bt_rf_ptr;
static bool g_bIsRunning = false;

static void  REQ_TimeOut( void )
{
    gs_bt_rf_ptr->REQ_TimeOut();
}

static void  REQ_Stop( void )
{
    gs_bt_rf_ptr->REQ_Stop();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_bt_rf_ptr->REQ_Finish();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Enter_Test_Mode1( void )
{
    gs_bt_rf_ptr->REQ_Enter_Test_Mode1();
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_EnterTestMode1HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_EnterTestMode1HCIEvent( cnf, token, usrData );
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_EnterTestMode2HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_EnterTestMode2HCIEvent( cnf, token, usrData );
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_EnterTestMode3HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_EnterTestMode3HCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Enter_Test_Mode2( void )
{
    gs_bt_rf_ptr->REQ_Enter_Test_Mode2();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Enter_Test_Mode3( void )
{
    gs_bt_rf_ptr->REQ_Enter_Test_Mode3();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Whiten_HCI_command( void )
{
    gs_bt_rf_ptr->REQ_Send_Whiten_HCI_command();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_SendWhitenHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendWhitenHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//static void  REQ_Send_Modulation_HCI_command( void )
//{   gs_bt_rf_ptr->REQ_Send_Modulation_HCI_command();
//}

//------------------------------------------------------------------------------
//static void __stdcall CNF_SendModulationHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
//{   gs_bt_rf_ptr->CNF_SendModulationHCIEvent( cnf, token, usrData );
//}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_AccessCode_HCI_command( void )
{
    gs_bt_rf_ptr->REQ_Send_AccessCode_HCI_command();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_SendAccessCodeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendAccessCodeHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_TxParameter_HCI_command( void )
{
    gs_bt_rf_ptr->REQ_Send_TxParameter_HCI_command();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendTxParameterHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_RxParameter_HCI_command( void )
{
    gs_bt_rf_ptr->REQ_Send_RxParameter_HCI_command();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendRxParameterHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_SendResetHCICommand( void )
{
    gs_bt_rf_ptr->REQ_SendResetHCICommand();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_ResetHCIEvent( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_Send_Read_BDAdrress_HCI_command( void )
{
    gs_bt_rf_ptr->REQ_Send_Read_BDAdrress_HCI_command();
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_SendReadBDAddressHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendReadBDAddressHCIEvent1( cnf, token, usrData );
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_SendReadBDAddressHCIEvent2(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_SendReadBDAddressHCIEvent2( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void REQ_ChangePCL( void )
{
    gs_bt_rf_ptr->REQ_ChangePCL();
}

//-----------------------------------------------------------------------------
static void __stdcall CNF_ChangePCLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_rf_ptr->CNF_ChangePCLHCIEvent( cnf, token, usrData );
}

//===========================================================================
CBTRF::CBTRF( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
    m_bEventOk = false;
    memset(&m_sBtRf,0,sizeof(m_sBtRf));
    memset(&m_sBdAddr,0,sizeof(m_sBdAddr));
}

//---------------------------------------------------------------------------
CBTRF::~CBTRF( void )
{

}



//---------------------------------------------------------------------------
void CBTRF::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    Confirm(META_SUCCESS);

}

//---------------------------------------------------------------------------
void CBTRF::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(METAAPP_STOP);
}

//---------------------------------------------------------------------------
void CBTRF::REQ_TimeOut(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm( META_TIMEOUT );

}

//---------------------------------------------------------------------------
void CBTRF::Confirm(META_RESULT confirm_state)
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


//============================================================================
void CBTRF::REQ_Enter_Test_Mode_Start( S_BT_RF  bt_rf )
{
    gs_bt_rf_ptr  = this;
    g_bIsRunning  = true;
    m_sBtRf = bt_rf;
    ActiveMan->SetActiveFunction( ::REQ_Enter_Test_Mode1 );
}

//---------------------------------------------------------------------------
void CBTRF::REQ_Enter_Test_Mode1( void )
{

    BT_HCI_COMMAND hci_cmd;
    Compose_Enter_Test_Mode1_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 7500, &hci_cmd, ::CNF_EnterTestMode1HCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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

    ActiveMan->SetActiveFunction( ::REQ_Enter_Test_Mode2 );
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_EnterTestMode1HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,03,18,00
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );

    if( (cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x03) ||
            (cnf->m_parms[2] != 0x18) ||
            (cnf->m_parms[3] != 0x00)
      )
    {
        Confirm( META_FAILED );
        return;
    }
}


//---------------------------------------------------------------------------
void CBTRF::REQ_Enter_Test_Mode2( void )
{

    BT_HCI_COMMAND hci_cmd;
    Compose_Enter_Test_Mode2_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 7500, &hci_cmd, ::CNF_EnterTestMode2HCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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

    ActiveMan->SetActiveFunction( ::REQ_Enter_Test_Mode3 );
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_EnterTestMode2HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,1A,0C,00
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );

    if( (cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x1A) ||
            (cnf->m_parms[2] != 0x0C) ||
            (cnf->m_parms[3] != 0x00)
      )
    {
        Confirm( META_FAILED );
        return;
    }
}

//---------------------------------------------------------------------------
void CBTRF::REQ_Enter_Test_Mode3( void )
{

    BT_HCI_COMMAND hci_cmd;
    Compose_Enter_Test_Mode3_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 7500, &hci_cmd, ::CNF_EnterTestMode3HCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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
void __stdcall CBTRF::CNF_EnterTestMode3HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,05,0C,00
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );

    if( (cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x05) ||
            (cnf->m_parms[2] != 0x0C) ||
            (cnf->m_parms[3] != 0x00)
      )
    {
        Confirm( META_FAILED );
        return;
    }
}

//============================================================================
void CBTRF::REQ_Start( S_BT_RF  bt_rf, bool reset )
{
    gs_bt_rf_ptr  = this;
    g_bIsRunning  = true;

    m_sBtRf = bt_rf;

    // sent TX reset command.
    if(true == reset)
    {
        BT_HCI_COMMAND hci_cmd;

        Compose_Reset_HCI_Command( hci_cmd );

        AddTxLogToStringList( hci_cmd );
        META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );
        if( META_SUCCESS != MetaResult )
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
    }

    ActiveMan->SetActiveFunction( ::REQ_Send_Whiten_HCI_command );
}
//---------------------------------------------------------------------------
void CBTRF::REQ_Send_Whiten_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    if(BT_RF_PACKET_NON_MODULED == m_sBtRf.e_packet_type)
    {
        E_TX_WHITEN tmpValue = (E_TX_WHITEN)0;
        Compose_Whiten_HCI_Command( &tmpValue, &hci_cmd );
    }
    else
    {
        Compose_Whiten_HCI_Command( &(m_sBtRf.e_whiten), &hci_cmd );
    }

    // unsigned char        str[256];
    // Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    // AnsiString as_cmd( (const char*)str, (unsigned int)hci_cmd.m_len );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendWhitenHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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

    // ActiveMan->SetActiveFunction( ::REQ_Send_Modulation_HCI_command );
    if( BT_TX == m_sBtRf.e_test_type )
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_TxParameter_HCI_command );
    }
    else
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_RxParameter_HCI_command );
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_SendWhitenHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//void CBTRF::REQ_Send_Modulation_HCI_command( void )
//{
//    // sent TX access code
//    BT_HCI_COMMAND hci_cmd;
//    Compose_Modulation_HCI_Command( m_sBtRf.e_modulation, hci_cmd );
//
//   // unsigned char        str[256];
//   // Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
//  //  AnsiString as_cmd( (const char*)str, (unsigned int)hci_cmd.m_len );
//    AddTxLogToStringList( hci_cmd );
//
//    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendWhitenHCIEvent, NULL, HCE_COMMAND_COMPLETE );
//
//    if( META_SUCCESS != MetaResult )
//    {
//        Confirm( META_FAILED );
//        return;
//    }
//
//    if( BT_TX == m_sBtRf.e_test_type )
//    {
//        ActiveMan->SetActiveFunction( ::REQ_Send_TxParameter_HCI_command );
//    }
//    else
//    {   ActiveMan->SetActiveFunction( ::REQ_Send_RxParameter_HCI_command );
//    }
//
//}
//
//---------------------------------------------------------------------------
//void __stdcall CBTRF::CNF_SendModulationHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
//{
//    if(!g_bIsRunning)  return;
//
//    AddRxLogToStringList( *cnf );
//}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTRF::REQ_Send_TxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    if(BT_RF_PACKET_NON_MODULED == m_sBtRf.e_packet_type)
    {
        Compose_Tx_Nonmoduled_HCI_command( m_sBtRf, hci_cmd );
    }
    else
    {
        Compose_TxParameter_HCI_command( m_sBtRf, hci_cmd );
    }

    // unsigned char        str[256];
    // Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    // AnsiString as_cmd( (const char*)str, (unsigned int)hci_cmd.m_len );
    AddTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendTxParameterHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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
    if(BT_RF_PACKET_NON_MODULED == m_sBtRf.e_packet_type || false == m_sBtRf.b_enable_access_code)
    {
        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }
    else
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_AccessCode_HCI_command );
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    AddRxLogToStringList( *cnf );

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTRF::REQ_Send_RxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_RxParameter_HCI_command( m_sBtRf, hci_cmd );

    // unsigned char        str[256];
    // Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    // AnsiString as_cmd( (const char*)str, (unsigned int)hci_cmd.m_len );
    AddTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendRxParameterHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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

//    ActiveMan->SetActiveFunction( ::REQ_Send_AccessCode_HCI_command );
    if(false == m_sBtRf.b_enable_access_code)
    {
        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }
    else
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_AccessCode_HCI_command );
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTRF::REQ_Send_AccessCode_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_AccessCode_HCI_Command( m_sBtRf.s_access_code, hci_cmd );

    // unsigned char        str[256];
    // Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    //  AnsiString as_cmd( (const char*)str, (unsigned int)hci_cmd.m_len );
    AddTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendWhitenHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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
void __stdcall CBTRF::CNF_SendAccessCodeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    AddRxLogToStringList( *cnf );

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTRF::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

//---------------------------------------------------------------------------
void  CBTRF::Compose_Enter_Test_Mode1_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x1803;
    hci_cmd.m_len    = 0;

}

//---------------------------------------------------------------------------
void  CBTRF::Compose_Enter_Test_Mode2_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C1A;
    hci_cmd.m_len    = 0x01;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x03;

}

//---------------------------------------------------------------------------
void  CBTRF::Compose_Enter_Test_Mode3_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C05;
    hci_cmd.m_len    = 0x03;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x02;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x02;
}

//---------------------------------------------------------------------------
void  CBTRF::Compose_Whiten_HCI_Command( E_TX_WHITEN *whiten, BT_HCI_COMMAND *hci_cmd )
{
    (*hci_cmd).m_opcode = 0xFC15;
    (*hci_cmd).m_len    = 1;
    Reset_HCI_Command( (*hci_cmd) );
    (*hci_cmd).m_cmd[0] = (unsigned char) whiten;

}

//---------------------------------------------------------------------------
void  CBTRF::DeCompose_Whiten_HCI_Event( BT_HCI_COMMAND &hci_cmd, E_TX_WHITEN &whiten )
{
    // whiten = (E_TX_WHITEN) hci_cmd.m_cmd[3];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTRF::Compose_Modulation_HCI_Command( E_TX_MODULATION &modulation, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0xFC32;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = (unsigned char) modulation;

}

//----------------------------------------------------------------------------
void  CBTRF::DeCompose_Modulation_HCI_Event( BT_HCI_COMMAND &hci_cmd, E_TX_MODULATION &modulation )
{
    // modulation = (E_TX_MODULATION) hci_cmd.m_cmd[3];
}

//---------------------------------------------------------------------------
void CBTRF::Compose_AccessCode_HCI_Command( S_BT_TX_ACCESS_CODE &access_code, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0xFC12;
    hci_cmd.m_len    = 8;
    Reset_HCI_Command( hci_cmd );
    for( int i=0; i<(sizeof(access_code.uc_access_code)/sizeof(access_code.uc_access_code[0])); i++ )
    {
        hci_cmd.m_cmd[i] = access_code.uc_access_code[i];
    }

}

//---------------------------------------------------------------------------
void CBTRF::DeCompose_AccessCode_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_TX_ACCESS_CODE &access_code )
{
    // for( int i=0; i<(sizeof(access_code.uc_access_code)/access_code.uc_access_code[0]); i++ )
    // {
    //     access_code.uc_access_code[i] = hci_cmd.m_cmd[3+i];
    // }
}

//---------------------------------------------------------------------------
void CBTRF::Compose_TxParameter_HCI_command( S_BT_RF bt_rf_tx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0xFC0D;
    hci_cmd.m_len     = 23;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x00;
    hci_cmd.m_cmd[1]  = 0x00;
    hci_cmd.m_cmd[2]  = bt_rf_tx.e_pattern;
    hci_cmd.m_cmd[3]  = bt_rf_tx.e_freq_type;
    hci_cmd.m_cmd[4]  = bt_rf_tx.uc_freq;
    hci_cmd.m_cmd[5]  = bt_rf_tx.uc_freq;
    hci_cmd.m_cmd[6]  = bt_rf_tx.e_power_ctrl;
    hci_cmd.m_cmd[7] = bt_rf_tx.uc_poll_period;
    hci_cmd.m_cmd[8] = bt_rf_tx.e_packet_type;
    hci_cmd.m_cmd[9] = bt_rf_tx.us_data_len & 0x00FF;
    hci_cmd.m_cmd[10] = ( bt_rf_tx.us_data_len & 0xFF00 ) >> 8;
    hci_cmd.m_cmd[11] = 0x02;
    hci_cmd.m_cmd[12] = 0x00;
    hci_cmd.m_cmd[13] = 0x01;
    for( int i=14; i<23; i++ )
    {
        hci_cmd.m_cmd[i] = 0x00;
    }
}

//---------------------------------------------------------------------------
void CBTRF::DeCompose_TxParameter_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_RF bt_rf_tx )
{

    //  bt_rf_tx.e_pattern      = hci_cmd.m_cmd[5];
    //  bt_rf_tx.e_freq_type    = hci_cmd.m_cmd[6];
    //  bt_rf_tx.uc_freq        = hci_cmd.m_cmd[7];
    //  bt_rf_tx.uc_freq        = hci_cmd.m_cmd[8];
    //  bt_rf_tx.e_power_ctrl   = hci_cmd.m_cmd[9];
    //  bt_rf_tx.uc_poll_period = hci_cmd.m_cmd[10];
    //  bt_rf_tx.e_packet_type  = hci_cmd.m_cmd[11];
    //  bt_rf_tx.uc_data_len    = hci_cmd.m_cmd[12];
}
//rongguo 2011-11-01
//---------------------------------------------------------------------------
void CBTRF::Compose_Tx_Nonmoduled_HCI_command( S_BT_RF bt_rf_tx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0xFCD5;
    hci_cmd.m_len     = 1;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = bt_rf_tx.uc_freq;
}

//---------------------------------------------------------------------------
void CBTRF::Compose_RxParameter_HCI_command( S_BT_RF bt_rf_rx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0xFC0D;
    hci_cmd.m_len     = 23;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x00;
    hci_cmd.m_cmd[1]  = 0x00;
    hci_cmd.m_cmd[2]  = bt_rf_rx.e_pattern;
    hci_cmd.m_cmd[3]  = bt_rf_rx.e_freq_type;
    hci_cmd.m_cmd[4]  = bt_rf_rx.uc_freq;
    hci_cmd.m_cmd[5]  = bt_rf_rx.uc_freq;
    hci_cmd.m_cmd[6]  = bt_rf_rx.e_power_ctrl;
    hci_cmd.m_cmd[7] = bt_rf_rx.uc_poll_period;
    hci_cmd.m_cmd[8] = bt_rf_rx.e_packet_type;
    hci_cmd.m_cmd[9] = bt_rf_rx.us_data_len;
    hci_cmd.m_cmd[10] = 0x00;
    hci_cmd.m_cmd[11] = 0x02;
    hci_cmd.m_cmd[12] = 0x00;
    hci_cmd.m_cmd[13] = 0x01;
    for( int i=14; i<23; i++ )
    {
        hci_cmd.m_cmd[i] = 0x00;
    }
}

//---------------------------------------------------------------------------
void CBTRF::DeCompose_RxParameter_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_RF bt_rf_rx )
{

}

//==========================================================================
void  CBTRF::REQ_Stop_Start( void )
{
    gs_bt_rf_ptr  = this;
    g_bIsRunning  = true;

    SP_META_CancelAllBlockingCall_r( m_META_HANDLE_Obj.Get_MainHandle() );
    //ActiveMan->SetActiveFunction( ::REQ_Stop );
    ActiveMan->SetActiveFunction( ::REQ_SendResetHCICommand );
}

//---------------------------------------------------------------
void CBTRF::REQ_SendResetHCICommand( void )
{
    if(!g_bIsRunning)  return;

    BT_HCI_COMMAND hci_cmd;
    Compose_Reset_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );

    if( META_SUCCESS != MetaResult )
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

    ActiveMan->SetActiveFunction( ::REQ_Stop );
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,03,0C,00
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );

    if( (cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x03) ||
            (cnf->m_parms[2] != 0x0C) ||
            (cnf->m_parms[3] != 0x00)
      )
    {
        Confirm( META_FAILED );
        return;
    }
}

//---------------------------------------------------------------------------
void CBTRF::Compose_Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTRF::REQ_QueryBDAddress_Start( S_BT_RF  bt_rf )
{
    gs_bt_rf_ptr  = this;
    g_bIsRunning  = true;

    m_sBtRf = bt_rf;
    ActiveMan->SetActiveFunction( ::REQ_Send_Read_BDAdrress_HCI_command );
}

//---------------------------------------------------------------------------
void  CBTRF::REQ_Send_Read_BDAdrress_HCI_command( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_Read_BD_Addr_HCI_Command2( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendReadBDAddressHCIEvent2, NULL, HCE_COMMAND_COMPLETE );

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

void CBTRF::REQ_BT_HWT(void)
{
    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_Read_BD_Addr_HCI_Command1( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, NULL, NULL, HCE_COMMAND_COMPLETE );

    if( (META_SUCCESS != MetaResult))
        m_iConfirmState = META_FAILED;
    else
        m_iConfirmState = META_SUCCESS;
    ConfirmCallback();
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_SendReadBDAddressHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = true;
}

//---------------------------------------------------------------------------
void __stdcall CBTRF::CNF_SendReadBDAddressHCIEvent2(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    if( 0xFF == cnf->m_event )  return; // LMP

    AddRxLogToStringList( *cnf );
    m_bEventOk = DeCompose_Read_BD_Addr_HCI_Event2( *cnf, m_sBdAddr );
    if (m_sBtRf.hPostMsgDestHandle != NULL)
    {
        PostMessage(
            m_sBtRf.hPostMsgDestHandle,
            WM_ML_BT_PRINT_MSG,
            PAGEIDX_BT_RF,
            0
        );
    }
}

//-----------------------------------------------------------------------
void  CBTRF::Compose_Read_BD_Addr_HCI_Command1( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );
}

//--------------------------------------------------------------------------
void  CBTRF::Compose_Read_BD_Addr_HCI_Command2( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x1009;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );
}

//--------------------------------------------------------------------------
bool  CBTRF::DeCompose_Read_BD_Addr_HCI_Event2(BT_HCI_EVENT hci_event, S_BD_ADDR &s_bd_addr)
{

    if(
        0x09 != hci_event.m_parms[1] ||
        0x10 != hci_event.m_parms[2] ||
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }

    // S_BD_ADDR bd_addr;
    for( int i=0; i<BD_ADDRESS_LEN; i++ )
        s_bd_addr.uc_BD_Addr[i] = hci_event.m_parms[4+i];

    // s_bd_addrs.us_NAP = (bd_addr.uc_BD_Addr[5] << 8) | bd_addr.uc_BD_Addr[4];
    // s_bd_addrs.uc_UAP = bd_addr.uc_BD_Addr[3];
    // s_bd_addrs.ui_LAP = (bd_addr.uc_BD_Addr[2] << 16) | (bd_addr.uc_BD_Addr[1] << 8) | bd_addr.uc_BD_Addr[0];
    return true;
}

//===========================================================================
void  CBTRF::REQ_ChangePCL_Start( S_BT_RF  bt_rf )
{
    gs_bt_rf_ptr  = this;
    g_bIsRunning  = true;

    m_sBtRf = bt_rf;
    ActiveMan->SetActiveFunction( ::REQ_ChangePCL );
}

//------------------------------------------------------
void CBTRF::REQ_ChangePCL( void )
{
    if(!g_bIsRunning)  return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    Compose_ChangePCL_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ChangePCLHCIEvent, NULL, HCE_COMMAND_COMPLETE );
//rongguo 2011-07-08
//    if( (META_SUCCESS != MetaResult) || (!m_bEventOk) )
    if(META_SUCCESS != MetaResult)
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
    Confirm( META_SUCCESS );
}

//-----------------------------------------------------
void __stdcall CBTRF::CNF_ChangePCLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
//rongguo 2011-07-08
    /*    // 0E 06 01 17 FC 00 00 00
        if( ! g_bIsRunning )  return;
        if( 0xFF == cnf->m_event )  return; // LMP

        if( ( 0x06 != cnf->m_len )      ||
            ( 0x01 != cnf->m_parms[0] ) ||
            ( 0x17 != cnf->m_parms[1] ) ||
            ( 0xFC != cnf->m_parms[2] ) ||
            ( 0x00 != cnf->m_parms[3] ) ||
            ( 0x00 != cnf->m_parms[4] ) ||
            ( 0x00 != cnf->m_parms[5] )
          )
        {
            return;
        } */

    /*    if( ! g_bIsRunning )  return;
        if( 0xFF == cnf->m_event )  return; // LMP

        if( ( 0x04 != cnf->m_len )      ||
            ( 0x01 != cnf->m_parms[0] ) ||
            ( 0x79 != cnf->m_parms[1] ) ||
            ( 0xFC != cnf->m_parms[2] ) ||
            ( 0x00 != cnf->m_parms[3] )
          )
        {
            return;
        }                */

//rongguo 2011-11-21
// 04 0E 04 01 17 FC 00
    /*if( ! g_bIsRunning )  return;
        if( 0xFF == cnf->m_event )  return; // LMP

        if( ( 0x04 != cnf->m_len )      ||
            ( 0x01 != cnf->m_parms[0] ) ||
            ( 0x17 != cnf->m_parms[1] ) ||
            ( 0xFC != cnf->m_parms[2] ) ||
            ( 0x00 != cnf->m_parms[3] )
          )
        {
            return;
        }                                */
    AddRxLogToStringList( *cnf );
//rongguo 2011-07-08
//    m_bEventOk = true;
}

//----------------------------------------------
void  CBTRF::Compose_ChangePCL_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
//rongguo 2011-11-21
    // 17 FC 04 00 00 PP 00
    hci_cmd.m_opcode = 0xFC17;
    hci_cmd.m_len    = 0x04;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x00;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = m_sBtRf.uc_pcl;
    hci_cmd.m_cmd[3] = 0x00;


    /*  hci_cmd.m_opcode = 0xFC79;
        hci_cmd.m_len    = 0x06;
        Reset_HCI_Command( hci_cmd );
        hci_cmd.m_cmd[0] = m_sBtRf.uc_pcl;;
        hci_cmd.m_cmd[1] = 0x80;
        hci_cmd.m_cmd[2] = 0x00;
        hci_cmd.m_cmd[3] = 0x06;
        hci_cmd.m_cmd[4] = 0x03;
        hci_cmd.m_cmd[5] = m_sBtRf.uc_pcl; */
//

}

//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void CBTRF::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBtRf.log)
    {
        return;
    }

    char        str[1024];
    AnsiString as_log;
    sprintf( str, "%2.2X,", hci_cmd.m_opcode & 0x00FF );
    AnsiString as_opcode_low(str);
    sprintf( str, "%2.2X,", (hci_cmd.m_opcode & 0xFF00)>>8 );
    AnsiString as_opcode_high(str);
    Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    AnsiString as_cmd( (const char*)str );
    if( 0 == hci_cmd.m_len )
        as_cmd = "";
    sprintf( str, "%2.2X,", hci_cmd.m_len );
    AnsiString as_length(str);


    as_log = "[" + TimeToStr(Time()) + "] TX: " + as_opcode_low + as_opcode_high + as_length  + as_cmd;

    m_sBtRf.log->Add( as_log );
    PostMessage(
        m_sBtRf.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_RF,
        0
    );
}

//--------------------------------------------------------------------------
void CBTRF::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL == m_sBtRf.log)
    {
        return;
    }

    unsigned char        str[1024];
    AnsiString as_log;
    sprintf( str, "%2.2X,", hci_event.m_event );
    AnsiString as_event( (const char*) str );
    sprintf( str, "%2.2X,", hci_event.m_len );
    AnsiString as_length( (const char*) str );
    Array_To_Hex_String_UnsignedChar( str, hci_event.m_parms, hci_event.m_len, ',' );
    AnsiString as_param( (const char*) str );
    if(  0 == hci_event.m_len )
        as_param = "";

    as_log = "[" + TimeToStr(Time()) + "] RX: " + as_event + as_length + as_param;
    m_sBtRf.log->Add(as_log);

    PostMessage(
        m_sBtRf.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_RF,
        0
    );
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CBTRF::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_BD_ADDR CBTRF::Get_BdAddress(void)
{
    return m_sBdAddr;
}







