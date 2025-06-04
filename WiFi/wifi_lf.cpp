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
 *   wifi_lf.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi local frequency source
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

#ifndef  _WIFI_LF_H_
#include "wifi_lf.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

static CWIFILF*  gs_wifi_lf_ptr;

//===========================================================================
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_lf_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_lf_ptr->REQ_Finish();
}

//------------------------------------------------------------------------------
static void  REQ_SetRegDomain( void )
{
    gs_wifi_lf_ptr->REQ_SetRegDomain();
}

//------------------------------------------------------------------------------
//static void  REQ_SetChannel( void )
//{   gs_wifi_lf_ptr->REQ_SetChannel();
//}

//------------------------------------------------------------------------------
static void  REQ_LocalFrequecyMeasure( void )
{
    gs_wifi_lf_ptr->REQ_LocalFrequecyMeasure();
}

//===========================================================================
CWIFILF::CWIFILF( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    // m_pcTxPowerBuf = 0;
    // m_iTxPowerBufSize = 0;
    m_iConfirmState = 0;
    memset(&m_sWiFiLF,0,sizeof(m_sWiFiLF));
}

//---------------------------------------------------------------------------
CWIFILF::~CWIFILF( )
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
void  CWIFILF::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_LF_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFILF::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_LF_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFILF::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_LF_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFILF::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFILF::REQ_Start( S_WIFILF wifilf )
{
    gs_wifi_lf_ptr    = this;
    m_bIsRunning      = true;
    m_sWiFiLF         = wifilf;
    m_sTx.ch_freq     = wifilf.channel_freq;
    m_sTx.tx_rate     = wifilf.tx_rate;
    m_sTx.tx_gain_dac = wifilf.tx_pwr_dac;

    ActiveMan->SetActiveFunction( ::REQ_SetRegDomain );
}

//---------------------------------------------------------------------------
void CWIFILF::REQ_SetRegDomain( void )
{

    META_RESULT MetaResult = SP_META_WiFi_SetRegDomain_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sWiFiLF.reg_domain );
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_LF_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_LF_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_LocalFrequecyMeasure );

}

#if 0
//---------------------------------------------------------------------------
void CWIFILF::REQ_SetChannel( void )
{

    META_RESULT MetaResult = SP_META_WiFi_SetChannel_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, m_iChannelFreq);

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_LF_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_LF_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_LocalFrequecyMeasure );

}
#endif

//---------------------------------------------------------------------------
void CWIFILF::REQ_LocalFrequecyMeasure( void )
{

    META_RESULT MetaResult = SP_META_WiFi_LocalFrequencyMeasure_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sTx );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_LF_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_LF_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );


}

//===========================================================================
////////////////////////////          Query          ////////////////////////
//===========================================================================


//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
//---------------------------------------------------------------------------
int   CWIFILF::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}


