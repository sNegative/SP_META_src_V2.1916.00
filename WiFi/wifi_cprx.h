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
 *   wifi_cprx.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi continuous packet RX header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _WIFI_CPRX_H_
#define  _WIFI_CPRX_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

/*---------------------------------------------------------------------------*/

#define  STATE_CPRX_OK          0
#define  STATE_CPRX_FAIL        1
#define  STATE_CPRX_TIMEOUT     2
#define  STATE_CPRX_STOP        3

/*---------------------------------------------------------------------------*/

class  CWIFICPRX
{
private:
    // common
    int   m_iConfirmState;
    bool  m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    WiFi_TestPktRx_S m_sPktRx;
    WiFi_RxStatus_S  m_sRxStatus;
    WiFi_RxCounter_S m_sRxCounter;

protected:


    void  Confirm( int confirm_state );

public:

    CWIFICPRX( void );
    ~CWIFICPRX();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)( void );





    void  REQ_Start( unsigned int channel_freq, WiFi_RxAntSel_E rx_ant );
    void  REQ_Stop( void );


    void  REQ_SetChannel( void );
    void  REQ_SetContinuousRx( void );

    // query
    void  REQ_QueryRxStatus_Start( void );
    void  REQ_QueryRxStatus( void );

    void  REQ_QueryRxCounter_Start( void );
    void  REQ_QueryRxCounter( void );



    // global information
    int   Get_ConfirmState( void );
    WiFi_RxStatus_S  Get_RxStatus( void );
    WiFi_RxCounter_S Get_RxCounter( void );

};

/*---------------------------------------------------------------------------*/
#endif
