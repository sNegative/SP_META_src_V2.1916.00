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
 *   wifi_ps.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi power save header
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
#ifndef  _WIFI_PS_H_
#define  _WIFI_PS_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

/*---------------------------------------------------------------------------*/

#define  STATE_PS_OK          0
#define  STATE_PS_FAIL        1
#define  STATE_PS_TIMEOUT     2
#define  STATE_PS_STOP        3

/*---------------------------------------------------------------------------*/

class  CWIFIPS
{
private:
    // common
    int   m_iConfirmState;
    bool  m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    WiFi_PowerManagementMode_E m_ePwrMgt;

protected:


    void  Confirm( int confirm_state );

public:

    CWIFIPS( void );
    ~CWIFIPS();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)( void );





    void  REQ_Start( WiFi_PowerManagementMode_E pwr_mgt );
    void  REQ_Stop();
    void  REQ_PowerSave( void );




    // global information
    int   Get_ConfirmState( void );

};

/*---------------------------------------------------------------------------*/
#endif
