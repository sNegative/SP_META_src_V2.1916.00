#include<iostream>
#include <fstream>
#pragma hdrstop
#include "metaapp_common.h"
#include "bt_hci_common.h"
#include "bt_ble.h"
#include "man_active.h"
#include "ft_utils.h"
#include "meta_lab_msg.h"
#include "misc.h"

#define INVALID_TAG  -1

static CBTBLE*  gs_bt_ble_ptr;

static bool g_bIsRunning = false;

static void  REQ_TimeOut( void )
{
    gs_bt_ble_ptr->REQ_TimeOut();
}
static void REQ_BLE_START_HCI_command (void)
{
    gs_bt_ble_ptr->REQ_BLE_START_HCI_command();
}
static void REQ_BLE_STARTSTOP_HCI_command (void)
{
    gs_bt_ble_ptr->REQ_BLE_STARTSTOP_HCI_command();
}
/*static void  REQ_Stop( void )
{
    gs_bt_ble_ptr->REQ_Stop();
}  */
static void REQ_BLE_RESET_HCI_command(void)
{
    gs_bt_ble_ptr->REQ_BLE_RESET_HCI_command();
}

static void REQ_BLE_ClearWhiteList_HCI_command(void)
{
    gs_bt_ble_ptr->REQ_BLE_ClearWhiteList_HCI_command();
}

static void  REQ_Finish( void )
{
    gs_bt_ble_ptr->REQ_Finish();
}

static void  REQ_Send_TxParameter_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_Send_TxParameter_HCI_command();
}

static void  REQ_Send_RxParameter_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_Send_RxParameter_HCI_command();
}
static void REQ_BLE_AddDeviceToWhiteList_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_BLE_AddDeviceToWhiteList_HCI_command();
}
static void REQ_BLE_RemoveDeviceToWhiteList_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_BLE_RemoveDeviceToWhiteList_HCI_command();
}
static void  REQ_BLE_SetAdvertiseData_HCI_command(void)
{
    gs_bt_ble_ptr->REQ_BLE_SetAdvertiseData_HCI_command();
}
static void REQ_BLE_AdvertiseStart_HCI_command(void)
{
    gs_bt_ble_ptr->REQ_BLE_AdvertiseStart_HCI_command();
}
static void REQ_BLE_AdvertiseEnable_HCI_command(void)
{
    gs_bt_ble_ptr->REQ_BLE_AdvertiseEnable_HCI_command();
}
static void REQ_BLE_AdvertiseStop_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_AdvertiseStop_HCI_command();
}
static void REQ_BLE_SetScanResponseData_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_SetScanResponseData_HCI_command();
}
static void REQ_BLE_ScanStart_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_ScanStart_HCI_command();
}
static void REQ_BLE_ScanStop_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_ScanStop_HCI_command();
}
static void REQ_BLE_InitiateStart_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_InitiateStart_HCI_command();
}
static void REQ_BLE_InitiateStop_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_InitiateStop_HCI_command();
}
static void REQ_BLE_ScanEnable_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_ScanEnable_HCI_command();
}
static void REQ_BLE_EnhancedStart_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_EnhancedStart_HCI_command();
}
static void REQ_BLE_EnhancedStop_HCI_command()
{
    gs_bt_ble_ptr->REQ_BLE_EnhancedStop_HCI_command();
}
static void  REQ_Send_EnhancedTxParameter_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_Send_EnhancedTxParameter_HCI_command();
}

static void  REQ_Send_EnhancedRxParameter_HCI_command( void )
{
    gs_bt_ble_ptr->REQ_Send_EnhancedRxParameter_HCI_command();
}


static void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_ResetHCIEvent( cnf, token, usrData );
}
static void __stdcall CNF_StopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_StopHCIEvent( cnf, token, usrData );
}
static void __stdcall CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_SendTxParameterHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_SendRxParameterHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_SendEnhancedTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_SendEnhancedTxParameterHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_SendEnhancedRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_SendEnhancedRxParameterHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_EnhancedStopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_EnhancedStopHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_CommonHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_CommonHCIEvent( cnf, token, usrData );
}

static void __stdcall CNF_TestResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_ble_ptr->CNF_TestResetHCIEvent( cnf, token, usrData );
}







//===========================================================================
CBTBLE::CBTBLE( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    memset(&m_sBtBle,0,sizeof(m_sBtBle));
    memset(&m_sBleNormal,0,sizeof(m_sBleNormal));
    eBTPage = PAGEIDX_BT_HCI;

}

//---------------------------------------------------------------------------
CBTBLE::~CBTBLE( void )
{

}


//---------------------------------------------------------------------------
void CBTBLE::REQ_TimeOut(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm( META_TIMEOUT );

}
//---------------------------------------------------------------------------
void CBTBLE::Confirm(META_RESULT confirm_state)
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
//---------------------------------------------------------------------------
void CBTBLE::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    Confirm(META_SUCCESS);

}

//---------------------------------------------------------------------------
/*void CBTBLE::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(METAAPP_STOP);
}   */
//-------------------------------------------------------------------------------
void CBTBLE::REQ_StartStop( S_BT_BLE  bt_ble )
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBtBle = bt_ble;

    ActiveMan->SetActiveFunction( ::REQ_BLE_STARTSTOP_HCI_command );
}

//-------------------------------------------------------------------------------
void CBTBLE::REQ_Start( S_BT_BLE  bt_ble )
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBtBle = bt_ble;

    ActiveMan->SetActiveFunction( ::REQ_BLE_START_HCI_command );
}

void  CBTBLE::REQ_BLEAdvertiseStart(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_AdvertiseStart_HCI_command);
}

void CBTBLE::REQ_BLEScanStart(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_ScanStart_HCI_command);
}

void CBTBLE::REQ_BLEClearWhiteList(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_ClearWhiteList_HCI_command);

}

void CBTBLE::REQ_BLEInitiateStart(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_InitiateStart_HCI_command);
}

void CBTBLE::REQ_BLEEnhancedStart(S_BT_BLE_ENHANCED  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleEnhanced =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_EnhancedStart_HCI_command);
}


void CBTBLE::REQ_BLESetScanResponseData(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_SetScanResponseData_HCI_command);

}


void CBTBLE::REQ_BLEScanStop(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_ScanStop_HCI_command);
}

void CBTBLE::REQ_BLEAddDeviceToWhiteList(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_AddDeviceToWhiteList_HCI_command);

}
void  CBTBLE::REQ_BLERemoveDeviceToWhiteList(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_RemoveDeviceToWhiteList_HCI_command);
}
void CBTBLE::REQ_BLESetAdvertiseData(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_SetAdvertiseData_HCI_command);
}
void CBTBLE::REQ_BLEAdvertiseStop(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;
    ActiveMan->SetActiveFunction(::REQ_BLE_AdvertiseStop_HCI_command);
}
void CBTBLE::REQ_BLEResetHCI(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_RESET_HCI_command);

}
void CBTBLE::REQ_BLEInitiateStop(S_BT_BLE_Normal  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleNormal =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_InitiateStop_HCI_command);
}

void CBTBLE::REQ_BLEEnhancedStop(S_BT_BLE_ENHANCED  bt_ble)
{
    gs_bt_ble_ptr  = this;
    g_bIsRunning  = true;

    m_sBleEnhanced =  bt_ble;

    ActiveMan->SetActiveFunction(::REQ_BLE_EnhancedStop_HCI_command);
}

//==============================================================================
void CBTBLE::REQ_BLE_InitiateStop_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_InitiateStop_HCI_Command( hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );



    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}
void CBTBLE::REQ_BLE_InitiateStart_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_InitiateStart_HCI_Command( m_sBleNormal ,hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_STATUS );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}
void CBTBLE::REQ_BLE_AdvertiseStop_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_AdvertiseStop_HCI_Command( hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}
void CBTBLE::REQ_BLE_AdvertiseStart_HCI_command(void)
{

    BT_HCI_COMMAND hci_cmd;

    Compose_AdvertiseStart_HCI_Command( m_sBleNormal ,hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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


    ActiveMan->SetActiveFunction( ::REQ_BLE_AdvertiseEnable_HCI_command );

}

void CBTBLE::REQ_BLE_EnhancedStart_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    //reset
    Compose_Reset_HCI_Command( hci_cmd );

    AddEnhancedTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_TestResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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

    if( BT_TX_Test == m_sBleEnhanced.ble_test_type ) //tx
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_EnhancedTxParameter_HCI_command );
    }
    else //rx
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_EnhancedRxParameter_HCI_command );
    }


}

void CBTBLE::REQ_BLE_ScanStart_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_ScanStart_HCI_Command( m_sBleNormal ,hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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

    ActiveMan->SetActiveFunction( ::REQ_BLE_ScanEnable_HCI_command );
}
void CBTBLE::REQ_BLE_AdvertiseEnable_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;
    Compose_AdvertiseEnable_HCI_Command( hci_cmd );
    AddNormalTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }
}
void CBTBLE::REQ_BLE_ScanEnable_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;
    Compose_ScanEnable_HCI_Command( m_sBleNormal , hci_cmd );
    AddNormalTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }
}
void CBTBLE::REQ_BLE_ScanStop_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;
    Compose_ScanStop_HCI_Command(m_sBleNormal , hci_cmd );
    AddNormalTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }
}


void CBTBLE::REQ_BLE_ClearWhiteList_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;
    Compose_Clear_White_List_HCI_Command( hci_cmd );
    AddNormalTxLogToStringList( hci_cmd );
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }


}
//---------------------------------------------------------------------------
void CBTBLE::REQ_BLE_STARTSTOP_HCI_command( void )
{

    BT_HCI_COMMAND hci_cmd;

    Compose_Stop_HCI_Command( hci_cmd );
    AddTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_StopHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }


}

//---------------------------------------------------------------------------
void CBTBLE::REQ_BLE_EnhancedStop_HCI_command( void )
{

    BT_HCI_COMMAND hci_cmd;

    Compose_EnhancedStop_HCI_Command( hci_cmd );
    AddEnhancedTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_EnhancedStopHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }


}

void CBTBLE::REQ_BLE_RESET_HCI_command(void)
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;

    //reset
    Compose_Reset_HCI_Command( hci_cmd );

    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_ResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }
}
void CBTBLE::REQ_BLE_AddDeviceToWhiteList_HCI_command( void )
{
    BT_HCI_COMMAND hci_cmd;

    Compose_AddDeviceToWhiteList_HCI_Command(m_sBleNormal , hci_cmd);
    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }

}
void CBTBLE::REQ_BLE_SetAdvertiseData_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_SetAdvertiseData_HCI_Command(m_sBleNormal , hci_cmd);
    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}

void CBTBLE::REQ_BLE_RemoveDeviceToWhiteList_HCI_command( void )
{
    BT_HCI_COMMAND hci_cmd;

    Compose_RemoveDeviceToWhiteList_HCI_Command(m_sBleNormal , hci_cmd);
    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}
void CBTBLE::REQ_BLE_SetScanResponseData_HCI_command(void)
{
    BT_HCI_COMMAND hci_cmd;

    Compose_SetScanResponseData_HCI_Command(m_sBleNormal , hci_cmd);
    AddNormalTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_CommonHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm( META_SUCCESS );
    }
}
void CBTBLE::REQ_BLE_START_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;

    //reset
    Compose_Reset_HCI_Command( hci_cmd );

    AddTxLogToStringList( hci_cmd );



    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 8000, &hci_cmd, ::CNF_TestResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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


    if( BT_TX_Test == m_sBtBle.ble_test_type ) //tx
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_TxParameter_HCI_command );
    }
    else //rx
    {
        ActiveMan->SetActiveFunction( ::REQ_Send_RxParameter_HCI_command );
    }

}

//---------------------------------------------------------------------------
void CBTBLE::Compose_InitiateStart_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200D;
    hci_cmd.m_len    = 0x19;
    Reset_HCI_Command( hci_cmd );

    unsigned int tmpValue;
    int len = bt_ble_normal.ble_strLEScanIntervalIn.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strLEScanIntervalIn = "0" +  bt_ble_normal.ble_strLEScanIntervalIn;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanIntervalIn.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[0] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanIntervalIn.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[1] =  tmpValue;

    len = bt_ble_normal.ble_strLEScanWindowIn.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strLEScanWindowIn = "0" +  bt_ble_normal.ble_strLEScanWindowIn;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanWindowIn.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[2] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanWindowIn.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[3] =  tmpValue;

    hci_cmd.m_cmd[4] = bt_ble_normal.ble_initiate_filter_policy;
    hci_cmd.m_cmd[5] = bt_ble_normal.ble_PeerAddressType;

    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(11,2),&tmpValue);
    hci_cmd.m_cmd[6] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(9,2),&tmpValue);
    hci_cmd.m_cmd[7] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(7,2),&tmpValue);
    hci_cmd.m_cmd[8] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(5,2),&tmpValue);
    hci_cmd.m_cmd[9] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[10] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strPeerAddress.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[11] =  tmpValue;

    hci_cmd.m_cmd[12] = bt_ble_normal.ble_OwnAddressTypeIn;

    len = bt_ble_normal.strConnectionIntervalMin.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strConnectionIntervalMin = "0" +  bt_ble_normal.strConnectionIntervalMin;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strConnectionIntervalMin.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[13] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strConnectionIntervalMin.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[14] =  tmpValue;

    len = bt_ble_normal.strConnectionIntervalMax.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strConnectionIntervalMax = "0" +  bt_ble_normal.strConnectionIntervalMax;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strConnectionIntervalMax.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[15] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strConnectionIntervalMax.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[16] =  tmpValue;

    len = bt_ble_normal.strConnectionLatency.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strConnectionLatency = "0" +  bt_ble_normal.strConnectionLatency;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strConnectionLatency.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[17] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strConnectionLatency.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[18] =  tmpValue;

    len = bt_ble_normal.strSupervisionTimeout.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strSupervisionTimeout = "0" +  bt_ble_normal.strSupervisionTimeout;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strSupervisionTimeout.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[19] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strSupervisionTimeout.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[20] =  tmpValue;

    len = bt_ble_normal.strMinimumCELength.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strMinimumCELength = "0" +  bt_ble_normal.strMinimumCELength;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strMinimumCELength.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[21] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strMinimumCELength.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[22] =  tmpValue;

    len = bt_ble_normal.strMinimumCELength.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.strMaximumCELength = "0" +  bt_ble_normal.strMaximumCELength;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.strMaximumCELength.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[23] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.strMaximumCELength.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[24] =  tmpValue;
}
void CBTBLE::Compose_InitiateStop_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200E;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}
void CBTBLE::Compose_ScanStop_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200C;
    hci_cmd.m_len    = 0x02;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x00;
    hci_cmd.m_cmd[1]  = bt_ble_normal.ble_scan_filter_duplicate;
}

void  CBTBLE::Compose_ScanEnable_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200C;
    hci_cmd.m_len    = 0x02;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x01;
    hci_cmd.m_cmd[1]  = bt_ble_normal.ble_scan_filter_duplicate;
}
void  CBTBLE::Compose_AdvertiseStop_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200A;
    hci_cmd.m_len    = 0x01;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x00;
}

void  CBTBLE::Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}
void CBTBLE::Compose_AdvertiseEnable_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200A;
    hci_cmd.m_len    = 0x01;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = 0x01;
}
void CBTBLE::Compose_SetScanResponseData_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x2009;
    hci_cmd.m_len = bt_ble_normal.ble_strSetScanResponseData.Length()/2+1;

    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = bt_ble_normal.ble_strSetScanResponseData.Length()/2;


    unsigned int tmpValue;
    int i=1;
    int j=1;

    while(j <= bt_ble_normal.ble_strSetScanResponseData.Length()/2)
    {
        IsValidHexBTAddr(bt_ble_normal.ble_strSetScanResponseData.SubString(i,2),&tmpValue);
        hci_cmd.m_cmd[j] =  tmpValue;
        i+=2;
        j+=1;

    }
}
void CBTBLE::Compose_AddDeviceToWhiteList_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x2011;
    hci_cmd.m_len    = 0x07;
    Reset_HCI_Command( hci_cmd );

    if( bt_ble_normal.ble_device_address == Public_Device_Address)
    {
        hci_cmd.m_cmd[0]  = 0x00;
    }
    else
    {
        hci_cmd.m_cmd[0]  = 0x01;
    }
    unsigned int tmpValue;


    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(11,2),&tmpValue);
    hci_cmd.m_cmd[1] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(9,2),&tmpValue);
    hci_cmd.m_cmd[2] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(7,2),&tmpValue);
    hci_cmd.m_cmd[3] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(5,2),&tmpValue);
    hci_cmd.m_cmd[4] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[5] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[6] =  tmpValue;

}
void CBTBLE::Compose_RemoveDeviceToWhiteList_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x2012;
    hci_cmd.m_len    = 0x07;
    Reset_HCI_Command( hci_cmd );

    if( bt_ble_normal.ble_device_address == Public_Device_Address)
    {
        hci_cmd.m_cmd[0]  = 0x00;
    }
    else
    {
        hci_cmd.m_cmd[0]  = 0x01;
    }
    unsigned int tmpValue;


    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(11,2),&tmpValue);
    hci_cmd.m_cmd[1] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(9,2),&tmpValue);
    hci_cmd.m_cmd[2] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(7,2),&tmpValue);
    hci_cmd.m_cmd[3] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(5,2),&tmpValue);
    hci_cmd.m_cmd[4] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[5] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strWhiteList.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[6] =  tmpValue;
}
void CBTBLE::Compose_ScanStart_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x200B;
    hci_cmd.m_len    = 0x07;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = bt_ble_normal.ble_scan_type;



    unsigned int tmpValue;
    int len = bt_ble_normal.ble_strLEScanInterval.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strLEScanInterval = "0" +  bt_ble_normal.ble_strLEScanInterval;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanInterval.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[1] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanInterval.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[2] =  tmpValue;

    len = bt_ble_normal.ble_strLEScanWindow.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strLEScanWindow = "0" +  bt_ble_normal.ble_strLEScanWindow;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanWindow.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[3] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strLEScanWindow.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[4] =  tmpValue;

    hci_cmd.m_cmd[5] =  bt_ble_normal.ble_scan_own_address_type;
    hci_cmd.m_cmd[6] =  bt_ble_normal.ble_scan_filter_policy;


}
void CBTBLE::Compose_AdvertiseStart_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x2006;
    hci_cmd.m_len    = 0x0F;
    Reset_HCI_Command( hci_cmd );

    unsigned int tmpValue;
    int len = bt_ble_normal.ble_strAdvertisingIntervalMin.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strAdvertisingIntervalMin = "0" +  bt_ble_normal.ble_strAdvertisingIntervalMin;
        }
    }

    IsValidHexBTAddr(bt_ble_normal.ble_strAdvertisingIntervalMin.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[0] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strAdvertisingIntervalMin.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[1] =  tmpValue;

    len = bt_ble_normal.ble_strAdvertisingIntervalMax.Length();
    if(len<4)
    {
        for(int i=0; i<4-len; i++)
        {
            bt_ble_normal.ble_strAdvertisingIntervalMax = "0" +  bt_ble_normal.ble_strAdvertisingIntervalMax;
        }
    }
    IsValidHexBTAddr(bt_ble_normal.ble_strAdvertisingIntervalMax.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[2] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strAdvertisingIntervalMax.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[3] =  tmpValue;

    hci_cmd.m_cmd[4] =  bt_ble_normal.ble_advertising_type;
    hci_cmd.m_cmd[5] =  bt_ble_normal.ble_own_address_type;
    hci_cmd.m_cmd[6] =  bt_ble_normal.ble_direct_address_type;

    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(11,2),&tmpValue);
    hci_cmd.m_cmd[7] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(9,2),&tmpValue);
    hci_cmd.m_cmd[8] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(7,2),&tmpValue);
    hci_cmd.m_cmd[9] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(5,2),&tmpValue);
    hci_cmd.m_cmd[10] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(3,2),&tmpValue);
    hci_cmd.m_cmd[11] =  tmpValue;
    IsValidHexBTAddr(bt_ble_normal.ble_strDirectAddress.SubString(1,2),&tmpValue);
    hci_cmd.m_cmd[12] =  tmpValue;

    hci_cmd.m_cmd[13] =  bt_ble_normal.channel;

    hci_cmd.m_cmd[14] =  bt_ble_normal.ble_advertise_filter_policy;

}

void CBTBLE::Compose_SetAdvertiseData_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x2008;
    hci_cmd.m_len = bt_ble_normal.ble_strAdvertiseData.Length()/2+1;

    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = bt_ble_normal.ble_strAdvertiseData.Length()/2;


    unsigned int tmpValue;
    int i=1;
    int j=1;
//    int temp = bt_ble_normal.ble_strAdvertiseData.Length();

    while(j <= bt_ble_normal.ble_strAdvertiseData.Length()/2)
    {
        IsValidHexBTAddr(bt_ble_normal.ble_strAdvertiseData.SubString(i,2),&tmpValue);
        hci_cmd.m_cmd[j] =  tmpValue;
        i+=2;
        j+=1;

    }
}
//---------------------------------------------------------------------------
void  CBTBLE::Compose_Stop_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x201F;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}
//---------------------------------------------------------------------------
void  CBTBLE::Compose_Clear_White_List_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x2010;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}

//---------------------------------------------------------------------------
void __stdcall CBTBLE::CNF_CommonHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddNormalRxLogToStringList( *cnf );
}

void __stdcall CBTBLE::CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddNormalRxLogToStringList( *cnf );
}

void _stdcall CBTBLE::CNF_TestResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );
}

//---------------------------------------------------------------------------
void __stdcall CBTBLE::CNF_StopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );

    unsigned int tmp, tmp1, tmp2;
    tmp1 = ((unsigned int)cnf->m_parms[5]) << 8;
    tmp2 = (unsigned int)cnf->m_parms[4];
    tmp = tmp1 + tmp2;
    m_conf = tmp;
}

//---------------------------------------------------------------------------
void __stdcall CBTBLE::CNF_EnhancedStopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddEnhancedRxLogToStringList( *cnf );

    unsigned int tmp, tmp1, tmp2;
    tmp1 = ((unsigned int)cnf->m_parms[5]) << 8;
    tmp2 = (unsigned int)cnf->m_parms[4];
    tmp = tmp1 + tmp2;
    m_conf = tmp;
}

void  CBTBLE::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

AnsiString CBTBLE::GetBLEResult(void)
{
    return m_conf;
}

//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================


void CBTBLE::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBtBle.log)
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

    m_sBtBle.log->Add( as_log );


    PostMessage(
        m_sBtBle.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_BLE,
        0
    );
}

//--------------------------------------------------------------------------
void CBTBLE::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL != m_sBtBle.log || NULL != m_sBleEnhanced.log)
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

    if(m_sBtBle.log != NULL)
    {
        m_sBtBle.log->Add(as_log);
        PostMessage(
        m_sBtBle.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_BLE,
        0
        );
    }

    if(m_sBleEnhanced.log != NULL)
    {
        m_sBleEnhanced.log->Add(as_log);
        PostMessage(
        m_sBleEnhanced.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_BLE_ENHANCED,
        0
        );
    }

    }
}

void CBTBLE::AddEnhancedTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBleEnhanced.log)
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

    m_sBleEnhanced.log->Add( as_log );


    PostMessage(
        m_sBleEnhanced.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_BLE_ENHANCED,
        0
    );
}

//--------------------------------------------------------------------------
void CBTBLE::AddEnhancedRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL == m_sBleEnhanced.log)
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
    m_sBleEnhanced.log->Add(as_log);

    PostMessage(
        m_sBleEnhanced.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_BLE_ENHANCED,
        0
    );
}


void CBTBLE::AddNormalTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
    if (NULL == m_sBleNormal.log)
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

    m_sBleNormal.log->Add( as_log );


    PostMessage(
        m_sBleNormal.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        eBTPage,
        0
    );


}

//--------------------------------------------------------------------------
void CBTBLE::AddNormalRxLogToStringList(BT_HCI_EVENT hci_event)
{
    if (NULL == m_sBleNormal.log)
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
    m_sBleNormal.log->Add(as_log);


    PostMessage(
        m_sBleNormal.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        eBTPage,
        0
    );


}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTBLE::REQ_Send_TxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_TxParameter_HCI_command( m_sBtBle, hci_cmd );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }

}

void CBTBLE::REQ_Send_EnhancedTxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_EnhancedTxParameter_HCI_command( m_sBleEnhanced, hci_cmd );

    AddEnhancedTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendEnhancedTxParameterHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTBLE::CNF_SendEnhancedTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    AddEnhancedRxLogToStringList( *cnf );
}

void __stdcall CBTBLE::CNF_SendEnhancedRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddEnhancedRxLogToStringList( *cnf );
}

//---------------------------------------------------------------------------
void __stdcall CBTBLE::CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;
    AddRxLogToStringList( *cnf );
}

void __stdcall CBTBLE::CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    AddRxLogToStringList( *cnf );
}

//---------------------------------------------------------------------------
void CBTBLE::REQ_Send_RxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_RxParameter_HCI_command( m_sBtBle, hci_cmd );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }


}
//---------------------------------------------------------------------------
void CBTBLE::REQ_Send_EnhancedRxParameter_HCI_command( void )
{
    // sent TX access code
    BT_HCI_COMMAND hci_cmd;
    Compose_EnhancedRxParameter_HCI_command( m_sBleEnhanced, hci_cmd );

    AddEnhancedTxLogToStringList( hci_cmd );

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_SendEnhancedRxParameterHCIEvent, NULL, HCE_COMMAND_COMPLETE );

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
    else
    {
        Confirm(META_SUCCESS);
        return;
    }


}
//---------------------------------------------------------------------------
META_RESULT CBTBLE::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}



//---------------------------------------------------------------------------
void CBTBLE::Compose_TxParameter_HCI_command( S_BT_BLE bt_ble_tx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0x201E;
    hci_cmd.m_len     = 03;
    Reset_HCI_Command( hci_cmd );


    hci_cmd.m_cmd[0]  = bt_ble_tx.Channel;
    hci_cmd.m_cmd[1]  = 0x25;

    hci_cmd.m_cmd[2]  = bt_ble_tx.ble_tx_patten;

}
//---------------------------------------------------------------------------
void CBTBLE::Compose_RxParameter_HCI_command( S_BT_BLE bt_ble_rx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0x201D;
    hci_cmd.m_len     = 01;
    Reset_HCI_Command( hci_cmd );


    hci_cmd.m_cmd[0]  = bt_ble_rx.Channel;
}

//---------------------------------------------------------------------------
void CBTBLE::Compose_EnhancedTxParameter_HCI_command( S_BT_BLE_ENHANCED bt_ble_tx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0x2034;
    hci_cmd.m_len     = 04;
    Reset_HCI_Command( hci_cmd );

    hci_cmd.m_cmd[0]  = bt_ble_tx.Channel;
    hci_cmd.m_cmd[1]  = bt_ble_tx.PayloadLength;
    hci_cmd.m_cmd[2]  = bt_ble_tx.ble_tx_patten;
    hci_cmd.m_cmd[3]  = bt_ble_tx.ble_tx_phy;

}
//---------------------------------------------------------------------------
void CBTBLE::Compose_EnhancedRxParameter_HCI_command( S_BT_BLE_ENHANCED bt_ble_rx, BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode  = 0x2033;
    hci_cmd.m_len     = 03;
    Reset_HCI_Command( hci_cmd );

    hci_cmd.m_cmd[0]  = bt_ble_rx.Channel;
    hci_cmd.m_cmd[1]  = bt_ble_rx.ble_rx_phy;
    hci_cmd.m_cmd[2]  = 0;
}

//---------------------------------------------------------------------------
void  CBTBLE::Compose_EnhancedStop_HCI_Command(BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x201F;
    hci_cmd.m_len    = 0x00;
    Reset_HCI_Command( hci_cmd );
}



