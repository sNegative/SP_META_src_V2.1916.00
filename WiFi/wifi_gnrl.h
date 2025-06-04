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
 *   wifi_gnrl.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi general function header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _WIFI_GNRL_H_
#define  _WIFI_GNRL_H_
/*---------------------------------------------------------------------------*/
#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif
/*---------------------------------------------------------------------------*/

#define  STATE_WIFIGNRL_OK          0
#define  STATE_WIFIGNRL_FAIL        1
#define  STATE_WIFIGNRL_TIMEOUT     2
#define  STATE_WIFIGNRL_STOP        3

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/

class  CWIFIGNRL
{
private:

    int   m_iConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    WiFi_ChipCapability_S  *m_pWiFiChipCap;
    WiFi_ChannelList_S *m_psChannelList;
    bool  *m_pbWiFiSupport;

protected:

    void  Confirm( int confirm_state );

public:

    CWIFIGNRL( void );
    ~CWIFIGNRL();

    void  (*ConfirmCallback)( void );
    void  REQ_Stop( void );
    void  REQ_Finish( void );
    void  REQ_TimeOut( void );
    void  Query_WiFi_Support_Start( bool  &wifi_support );
    void  Query_WiFi_Support( void );
    bool  Query_WiFi_Capability_Start(WiFi_ChipCapability_S &wifi_cap);
    bool  Query_WiFi_Capability(void);
    void  REQ_Query_ChannelList_Start( WiFi_ChannelList_S *p_channel_list );
    void  REQ_Query_ChannelList( void );

    // Global information
    int   Get_ConfirmState( void );

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/





};

/*---------------------------------------------------------------------------*/
#endif
