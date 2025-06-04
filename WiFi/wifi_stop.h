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
 *   wifi_stop.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WIFI stop header
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
#ifndef  _WIFI_STOP_H_
#define  _WIFI_STOP_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
/*---------------------------------------------------------------------------*/

#define  STATE_STOP_OK          0
#define  STATE_STOP_FAIL        1
#define  STATE_STOP_TIMEOUT     2
#define  STATE_STOP_STOP        3

/*---------------------------------------------------------------------------*/


class  CWIFISTOP
{
private:
    // common
    int   m_iConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
protected:


    void  Confirm( int confirm_state );

public:

    CWIFISTOP( void );
    ~CWIFISTOP( void );

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );

    // short RFID_STOP;
    // META_RF_STOP_CNF  RFCnf_STOP;

    // void __stdcall CNF_RFStop(const unsigned char cnf, const short token, void *usrData);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member

    void  (*ConfirmCallback)( void );

    // Public interface
    void  REQ_Start( void );
    void  REQ_Stop( void );

    // global information
    int   Get_ConfirmState( void );
};

/*---------------------------------------------------------------------------*/
#endif
