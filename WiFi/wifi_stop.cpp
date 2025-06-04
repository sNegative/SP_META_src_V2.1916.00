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
 *   wifi_stop.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WIFI stop source
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
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _WIFI_STOP_H_
#include "wifi_stop.h"
#endif


#include "man_active.h"
#include "man_fdm.h"
//===========================================================================
static CWIFISTOP*  gs_wifi_stop_ptr;
static bool g_bIsRunning;

//===========================================================================
//static void __stdcall CNF_RFStop(const unsigned char cnf, const short token, void *usrData)
//{
//     gs_wifi_stop_ptr->CNF_RFStop( cnf, token, usrData );
//}

//---------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_stop_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_stop_ptr->REQ_Finish();
}

//===========================================================================
CWIFISTOP::CWIFISTOP( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
}

//---------------------------------------------------------------------------
CWIFISTOP::~CWIFISTOP( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFISTOP::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;


    Confirm( STATE_STOP_OK );

}

//---------------------------------------------------------------------------
/*void  CWIFISTOP::REQ_Stop( void )
{
   if(!g_bIsRunning)  return;



   Confirm( STATE_STOP_STOP );

}  */

//---------------------------------------------------------------------------
void  CWIFISTOP::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;


    Confirm( STATE_STOP_TIMEOUT );

}

//---------------------------------------------------------------------------
void  CWIFISTOP::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    g_bIsRunning = false;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFISTOP::REQ_Start( void )
{
    gs_wifi_stop_ptr = this;
    g_bIsRunning = true;

    SP_META_CancelAllBlockingCall_r( m_META_HANDLE_Obj.Get_MainHandle() );

    META_RESULT  MetaResult = SP_META_WiFi_Stop_r( m_META_HANDLE_Obj.Get_MainHandle(), 500 );

    if(MetaResult!=META_SUCCESS)
    {
        Confirm( STATE_STOP_FAIL );
        return;
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}



//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
int CWIFISTOP::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}
