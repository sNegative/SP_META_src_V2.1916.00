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
 *   wifi_gnrl.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi general function source
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
 * Feb 23 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
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

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _WIFI_GNRL_H_
#include "wifi_gnrl.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

//===========================================================================
static CWIFIGNRL*  wifi_gnrl_ptr;
static bool g_bIsRunning;

//===========================================================================
static void  REQ_Query_ChannelList( void )
{
    wifi_gnrl_ptr->REQ_Query_ChannelList();
}

//---------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    wifi_gnrl_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    wifi_gnrl_ptr->REQ_Finish();
}

//===========================================================================
CWIFIGNRL::CWIFIGNRL( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    // RFReq_ID = NULL;
    m_iConfirmState = 0;
    m_pWiFiChipCap = NULL;
    m_psChannelList = NULL;
    m_pbWiFiSupport = NULL;
}

//---------------------------------------------------------------------------
CWIFIGNRL::~CWIFIGNRL()
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
void  CWIFIGNRL::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;
    Confirm( STATE_WIFIGNRL_OK );

}

//---------------------------------------------------------------------------
/*void  CWIFIGNRL::REQ_Stop( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_WIFIGNRL_STOP );

}*/

//---------------------------------------------------------------------------
void  CWIFIGNRL::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;
    Confirm( STATE_WIFIGNRL_TIMEOUT );

}

//---------------------------------------------------------------------------
void  CWIFIGNRL::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    g_bIsRunning = false;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CWIFIGNRL::Query_WiFi_Support_Start( bool  &wifi_support )
{
    wifi_gnrl_ptr = this;
    g_bIsRunning = true;
    m_pbWiFiSupport = &wifi_support;
    // ActiveMan->SetActiveFunction( ::Query_WiFi_Capability );
    Query_WiFi_Support();
}

//---------------------------------------------------------------------------
void  CWIFIGNRL::Query_WiFi_Support( void )
{
    if(!g_bIsRunning)
    {
        return;
    }


    META_RESULT   MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r( m_META_HANDLE_Obj.Get_MainHandle(), 300, "SP_META_WiFi_QueryChipCapability");
    if( META_SUCCESS != MetaResult )
    {
        *m_pbWiFiSupport = false;
    }
    else
    {
        *m_pbWiFiSupport = true;
    }



    // ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//===========================================================================
bool CWIFIGNRL::Query_WiFi_Capability_Start(WiFi_ChipCapability_S &wifi_cap)
{
    wifi_gnrl_ptr = this;
    g_bIsRunning = true;
    m_pWiFiChipCap = &wifi_cap;
    if (!Query_WiFi_Capability())
    {
        return false;
    }
    return true;
}

//---------------------------------------------------------------------------
bool CWIFIGNRL::Query_WiFi_Capability(void)
{
    if (!g_bIsRunning)
    {
        return false;
    }

    META_RESULT  MetaResult = SP_META_WiFi_QueryChipCapability_r(m_META_HANDLE_Obj.Get_MainHandle(), 300, m_pWiFiChipCap);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIGNRL::REQ_Query_ChannelList_Start( WiFi_ChannelList_S *p_channel_list )
{
    wifi_gnrl_ptr = this;
    g_bIsRunning = true;

    m_psChannelList = p_channel_list;

    ActiveMan->SetActiveFunction( ::REQ_Query_ChannelList );
}

//----------------------------------------------------------------------
void CWIFIGNRL::REQ_Query_ChannelList( void )
{

    META_RESULT MetaResult = SP_META_WiFi_QueryChannelList_r (m_META_HANDLE_Obj.Get_MainHandle(), 3000, m_psChannelList);
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_WIFIGNRL_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_WIFIGNRL_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );

}

//===========================================================================
int  CWIFIGNRL::Get_ConfirmState( void )
{
    return m_iConfirmState;
}
