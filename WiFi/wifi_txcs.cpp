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
 *   wifi_txcs.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi TX carrier suppression source
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

#ifndef  _WIFI_TXCS_H_
#include "wifi_txcs.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

static CWIFITXCS*  gs_wifi_txcs_ptr;

//===========================================================================
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_txcs_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_txcs_ptr->REQ_Finish();
}

//------------------------------------------------------------------------------
static void  REQ_SetRegDomain( void )
{
    gs_wifi_txcs_ptr->REQ_SetRegDomain();
}

//------------------------------------------------------------------------------
//static void  REQ_SetChannel( void )
//{   gs_wifi_txcs_ptr->REQ_SetChannel();
//}

//------------------------------------------------------------------------------
static void  REQ_CarrierSuppressionMeasure( void )
{
    gs_wifi_txcs_ptr->REQ_CarrierSuppressionMeasure();
}

//===========================================================================
CWIFITXCS::CWIFITXCS( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    // m_pcTxPowerBuf = 0;
    // m_iTxPowerBufSize = 0;
    m_iConfirmState = 0;
    memset(&m_sWiFiTXCS,0,sizeof(m_sWiFiTXCS));
}

//---------------------------------------------------------------------------
CWIFITXCS::~CWIFITXCS( )
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
void  CWIFITXCS::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;


    Confirm( STATE_TXCS_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFITXCS::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;


    // META_Cancel_r( RFID_TX );
    Confirm( STATE_TXCS_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFITXCS::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;


    Confirm( STATE_TXCS_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFITXCS::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFITXCS::REQ_Start( S_WIFITXCS wifitxcs )
{
    gs_wifi_txcs_ptr  = this;
    m_bIsRunning      = true;
    m_sWiFiTXCS       = wifitxcs;
    m_sTx.ch_freq     = wifitxcs.channel_freq;
    m_sTx.tx_rate     = wifitxcs.tx_rate;
    m_sTx.tx_gain_dac = wifitxcs.tx_pwr_dac;


    ActiveMan->SetActiveFunction( ::REQ_SetRegDomain );
}

//---------------------------------------------------------------------------
void CWIFITXCS::REQ_SetRegDomain( void )
{

    META_RESULT MetaResult = SP_META_WiFi_SetRegDomain_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sWiFiTXCS.reg_domain);
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_TXCS_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_TXCS_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_CarrierSuppressionMeasure );

}

#if 0
//---------------------------------------------------------------------------
void CWIFITXCS::REQ_SetChannel( void )
{

    META_RESULT MetaResult = META_WiFi_SetChannel_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, m_iChannelFreq);

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_TXCS_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_TXCS_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_SetOutputPower );


}

#endif
//---------------------------------------------------------------------------
void CWIFITXCS::REQ_CarrierSuppressionMeasure( void )
{

    META_RESULT MetaResult = SP_META_WiFi_CarrierSuppressionMeasure_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sTx );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_TXCS_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_TXCS_TIMEOUT );
            return;
        }
    }

    // if( IPN2128 == m_iWiFiID )
    // {
    //     META_RESULT MetaResult = META_WiFi_CarrierSuppressionMeasure500_r( 500, 0 );
    //     if(MetaResult!=META_SUCCESS)
    //     {
    //         if( MetaResult!=META_TIMEOUT )
    //         {   Confirm( STATE_TXCS_FAIL );  return;  }
    //         else
    //         {   Confirm( STATE_TXCS_TIMEOUT );  return;  }
    //     }
    // }
    ActiveMan->SetActiveFunction( ::REQ_Finish );


}

//===========================================================================
////////////////////////////          Query          ////////////////////////
//===========================================================================


//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
//---------------------------------------------------------------------------
int   CWIFITXCS::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}


