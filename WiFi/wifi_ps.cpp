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
 *   wifi_ps.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi power save source
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
#include "wifi_ps.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

static CWIFIPS*  gs_wifi_ps_ptr;

//===========================================================================
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_ps_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_ps_ptr->REQ_Finish();
}

//------------------------------------------------------------------------------
static void  REQ_PowerSave( void )
{
    gs_wifi_ps_ptr->REQ_PowerSave();
}

//===========================================================================
CWIFIPS::CWIFIPS( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    // m_pcTxPowerBuf = 0;
    // m_iTxPowerBufSize = 0;
    m_iConfirmState = 0;
}

//---------------------------------------------------------------------------
CWIFIPS::~CWIFIPS( )
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
void  CWIFIPS::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_PS_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIPS::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_PS_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIPS::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_PS_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIPS::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFIPS::REQ_Start( WiFi_PowerManagementMode_E pwr_mgt )
{
    gs_wifi_ps_ptr = this;
    m_bIsRunning     = true;
    m_ePwrMgt        = pwr_mgt;


    ActiveMan->SetActiveFunction( ::REQ_PowerSave );
}

//---------------------------------------------------------------------------
void CWIFIPS::REQ_PowerSave( void )
{

    META_RESULT MetaResult = SP_META_WiFi_SetPowerManagementMode_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, m_ePwrMgt);
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_PS_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_PS_TIMEOUT );
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
int   CWIFIPS::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}


