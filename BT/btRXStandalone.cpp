#include<iostream>
#include <fstream>
#pragma hdrstop
#include "metaapp_common.h"
#include "bt_hci_common.h"
#include "btRXStandalone.h"
#include "man_active.h"
#include "ft_utils.h"
#include "meta_lab_msg.h"
#include "misc.h"

static bool g_bIsRunning = false;
static CBTRXStandalone*  gs_bt_std_ptr;
static void REQ_EnterTest_HCI_command (void)
{
    gs_bt_std_ptr->REQ_EnterTest_HCI_command();
}
static void REQ_ResetTest_HCI_command(void)
{
    gs_bt_std_ptr->REQ_ResetTest_HCI_command();
}

static void REQ_ExitTest_HCI_command(void)
{
    gs_bt_std_ptr->REQ_ExitTest_HCI_command();
}



static void __stdcall CNF_ResetTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_std_ptr->CNF_ResetTestHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_EnterTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_std_ptr->CNF_EnterTestHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_ExitTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_std_ptr->CNF_ExitTestHCIEvent( cnf, token, usrData );
}

//===========================================================================
CBTRXStandalone::CBTRXStandalone( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    memset(&m_sBTStandalone,0,sizeof(m_sBTStandalone));
    memset(&m_sRXStandalone_Result,0,sizeof(m_sRXStandalone_Result));

}

//---------------------------------------------------------------------------
CBTRXStandalone::~CBTRXStandalone( void )
{

}

META_RESULT CBTRXStandalone::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}


void CBTRXStandalone::Confirm(META_RESULT confirm_state)
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

void CBTRXStandalone::REQ_EnterTest(S_BT_Standalone  bt_std)
{
    gs_bt_std_ptr  = this;
    g_bIsRunning  = true;
    m_sBTStandalone =  bt_std;
    ActiveMan->SetActiveFunction(::REQ_EnterTest_HCI_command);
}

void CBTRXStandalone::REQ_ExitTest(S_BT_Standalone  bt_std)
{
    gs_bt_std_ptr  = this;
    g_bIsRunning  = true;
    m_sBTStandalone =  bt_std;
    ActiveMan->SetActiveFunction(::REQ_ExitTest_HCI_command);
}

void CBTRXStandalone::REQ_ResetTest(S_BT_Standalone  bt_std)
{
    gs_bt_std_ptr  = this;
    g_bIsRunning  = true;
    m_sBTStandalone =  bt_std;
    ActiveMan->SetActiveFunction(::REQ_ResetTest_HCI_command);
}


void CBTRXStandalone::REQ_EnterTest_HCI_command( void )
{
    BT_HCI_COMMAND hci_cmd;
    Compose_EnterTest_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );


    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_EnterTestHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    Confirm( META_SUCCESS );
}

void CBTRXStandalone::REQ_ExitTest_HCI_command()
{
    BT_HCI_COMMAND hci_cmd;
    Compose_ExitTest_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );


    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_ExitTestHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    Confirm( META_SUCCESS );
}


void CBTRXStandalone::REQ_ResetTest_HCI_command()
{
    BT_HCI_COMMAND hci_cmd;
    //reset
    Compose_Reset_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );


    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_ResetTestHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    Confirm( META_SUCCESS );
}




void _stdcall CBTRXStandalone::CNF_ResetTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );
}


void _stdcall CBTRXStandalone::CNF_EnterTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );


}

void _stdcall CBTRXStandalone::CNF_ExitTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;


    AddRxLogToStringList( *cnf );

    m_sRXStandalone_Result.RX_Packet_Count = *((unsigned int *)&cnf->m_parms[4]);
    m_sRXStandalone_Result.RX_Error_Rate = *((unsigned int *)&cnf->m_parms[8]);
    m_sRXStandalone_Result.RX_Byte_Count = *((unsigned int *)&cnf->m_parms[12]);
    m_sRXStandalone_Result.Bit_Error_Rate = *((unsigned int *)&cnf->m_parms[16]);
}

void  CBTRXStandalone::Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}

void  CBTRXStandalone::Compose_ExitTest_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0xFC0D;
    hci_cmd.m_len    = 0x17;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]= 0x00;
    hci_cmd.m_cmd[1]= 0x09;
    hci_cmd.m_cmd[2]= 0xFF;
    hci_cmd.m_cmd[3]= 0x00;
    hci_cmd.m_cmd[4]= 0x00;
    hci_cmd.m_cmd[5]= 0x05;
    hci_cmd.m_cmd[6]= 0x00;
    hci_cmd.m_cmd[7]= 0x01;
    hci_cmd.m_cmd[8]= 0x03;
    hci_cmd.m_cmd[9] = 0x00;
    hci_cmd.m_cmd[10]= 0x00;
    hci_cmd.m_cmd[11]= 0x02;
    hci_cmd.m_cmd[12]= 0x00;
    hci_cmd.m_cmd[13]= 0x01;
    hci_cmd.m_cmd[14]= 0x00;
    hci_cmd.m_cmd[15]= 0x00;
    hci_cmd.m_cmd[16]= 0x00;
    hci_cmd.m_cmd[17]= 0x00;
    hci_cmd.m_cmd[18]= 0x00;
    hci_cmd.m_cmd[19]= 0x00;
    hci_cmd.m_cmd[20]= 0x00;
    hci_cmd.m_cmd[21]= 0x00;
    hci_cmd.m_cmd[22]= 0x00;
}

void CBTRXStandalone::Compose_EnterTest_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    unsigned int tmpValue;
    hci_cmd.m_opcode = 0xFC0D;
    hci_cmd.m_len    = 0x17;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x00;
    hci_cmd.m_cmd[1] = m_sBTStandalone.pattern;
    hci_cmd.m_cmd[2] = 0x0B;
    hci_cmd.m_cmd[3] = 0x00;
    hci_cmd.m_cmd[4] = 0x00;
    IsValidHexBTAddr(m_sBTStandalone.RXFrequency.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[5] =  tmpValue;
    hci_cmd.m_cmd[6] = 0x00;
    hci_cmd.m_cmd[7] = 0x01;
    hci_cmd.m_cmd[8] = m_sBTStandalone.PXPackettype;
    hci_cmd.m_cmd[9] = 0x00;
    hci_cmd.m_cmd[10]= 0x00;
    hci_cmd.m_cmd[11]= 0x02;
    hci_cmd.m_cmd[12]= 0x00;
    hci_cmd.m_cmd[13]= 0x01;
    hci_cmd.m_cmd[14]= 0x00;
    hci_cmd.m_cmd[15]= 0x00;
    hci_cmd.m_cmd[16]= 0x00;
//   hci_cmd.m_cmd[17]= 0x00;
    IsValidHexBTAddr(m_sBTStandalone.TesterAddress.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[17]= tmpValue;
    IsValidHexBTAddr(m_sBTStandalone.TesterAddress.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[18]= tmpValue;
    IsValidHexBTAddr(m_sBTStandalone.TesterAddress.SubString(5,2),&tmpValue);
    hci_cmd.m_cmd[19]= tmpValue;
    IsValidHexBTAddr(m_sBTStandalone.TesterAddress.SubString(7,2),&tmpValue);
    hci_cmd.m_cmd[20]= tmpValue;
    hci_cmd.m_cmd[21]= 0x00;
    hci_cmd.m_cmd[22]= 0x00;
}

void  CBTRXStandalone::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

void CBTRXStandalone::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBTStandalone.log)
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

    m_sBTStandalone.log->Add( as_log );

    PostMessage(
        m_sBTStandalone.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_RXSTD,
        0
    );
}

//--------------------------------------------------------------------------
void CBTRXStandalone::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL == m_sBTStandalone.log)
    {
        return;
    }

    unsigned char        str[1024]= {0};
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
    m_sBTStandalone.log->Add(as_log);

    PostMessage(
        m_sBTStandalone.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_RXSTD,
        0
    );
}
