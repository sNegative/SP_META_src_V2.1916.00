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
 *   wifi_cprx.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi continuous packet RX source
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
//===========================================================================
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _WIFI_CPRX_H_
#include "wifi_cprx.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

static CWIFICPRX*  gs_wifi_cprx_ptr;

//===========================================================================
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_cprx_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_cprx_ptr->REQ_Finish();
}

//------------------------------------------------------------------------------
static void  REQ_SetContinuousRx( void )
{
    gs_wifi_cprx_ptr->REQ_SetContinuousRx();
}

//---------------------------------------------------------------------------
static void REQ_QueryRxStatus( void )
{
    gs_wifi_cprx_ptr->REQ_QueryRxStatus();
}

//---------------------------------------------------------------------------
static void REQ_QueryRxCounter( void )
{
    gs_wifi_cprx_ptr->REQ_QueryRxCounter();
}

//===========================================================================
CWIFICPRX::CWIFICPRX( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    // m_pcTxPowerBuf = 0;
    // m_iTxPowerBufSize = 0;
    m_iConfirmState = 0;
}

//---------------------------------------------------------------------------
CWIFICPRX::~CWIFICPRX( )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;

    // if( m_pcTxPowerBuf )
//  {
    //     delete [] m_pcTxPowerBuf;
    //     m_pcTxPowerBuf = NULL;
    // }
}

//---------------------------------------------------------------------------
void  CWIFICPRX::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_CPRX_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFICPRX::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_CPRX_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFICPRX::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_CPRX_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFICPRX::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFICPRX::REQ_Start( unsigned int channel_freq, WiFi_RxAntSel_E rx_ant )
{
    gs_wifi_cprx_ptr = this;
    m_bIsRunning = true;

    m_sPktRx.ch_freq = channel_freq;
    m_sPktRx.mode    = WIFI_RF_RX_TEST_MODE;
    m_sPktRx.rxAnt   = rx_ant;

    ActiveMan->SetActiveFunction( ::REQ_SetContinuousRx );
}


//---------------------------------------------------------------------------
void CWIFICPRX::REQ_SetContinuousRx( void )
{

    META_RESULT MetaResult = SP_META_WiFi_ContPktRx_r( m_META_HANDLE_Obj.Get_MainHandle(), 900, &m_sPktRx );
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_CPRX_FAIL );
            return;
        }
        // else
        // {   Confirm( STATE_CPRX_TIMEOUT );  return;  }
    }
    // ActiveMan->SetActiveFunction( ::REQ_QueryRxStatus );
    ActiveMan->SetActiveFunction( ::REQ_Finish );

}

//===========================================================================
////////////////////////////          Query          ////////////////////////
//===========================================================================
void CWIFICPRX::REQ_QueryRxStatus_Start( void )
{
    gs_wifi_cprx_ptr = this;
    m_bIsRunning = true;
    ActiveMan->SetActiveFunction( ::REQ_QueryRxStatus );
}

//---------------------------------------------------------------------------
void CWIFICPRX::REQ_QueryRxStatus( void )
{

    META_RESULT MetaResult = SP_META_WiFi_QueryRxStatus_r ( m_META_HANDLE_Obj.Get_MainHandle(), 900, &m_sRxStatus);

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_CPRX_FAIL );
            return;
        }
        //else
        //{   Confirm( STATE_CPRX_TIMEOUT );  return;  }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );


}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFICPRX::REQ_QueryRxCounter_Start( void )
{
    gs_wifi_cprx_ptr = this;
    m_bIsRunning = true;
    ActiveMan->SetActiveFunction( ::REQ_QueryRxCounter );
}

//---------------------------------------------------------------------------
void CWIFICPRX::REQ_QueryRxCounter( void )
{

    META_RESULT MetaResult = SP_META_WiFi_QueryRxCounter_r ( m_META_HANDLE_Obj.Get_MainHandle(), 900, &m_sRxCounter);

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_CPRX_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_CPRX_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );


}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
//---------------------------------------------------------------------------
int   CWIFICPRX::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

//---------------------------------------------------------------------------
WiFi_RxStatus_S CWIFICPRX::Get_RxStatus( void )
{
    return m_sRxStatus;
}

//---------------------------------------------------------------------------
WiFi_RxCounter_S CWIFICPRX::Get_RxCounter( void )
{
    return m_sRxCounter;
}
