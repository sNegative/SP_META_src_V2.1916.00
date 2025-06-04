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
 *   wifi_lf.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi local frequency header
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
#ifndef  _WIFI_LF_H_
#define  _WIFI_LF_H_
#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

/*---------------------------------------------------------------------------*/

#define  STATE_LF_OK          0
#define  STATE_LF_FAIL        1
#define  STATE_LF_TIMEOUT     2
#define  STATE_LF_STOP        3

typedef struct
{
    int wifi_id;
    WiFi_RegDomain_S reg_domain;
    unsigned int channel_freq;
    WiFi_TestRate_E  tx_rate;
    unsigned char tx_pwr_dac;
} S_WIFILF;
/*---------------------------------------------------------------------------*/

class  CWIFILF
{
private:
    int   m_iConfirmState;
    bool  m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    S_WIFILF m_sWiFiLF;
    WiFi_TestTx_S    m_sTx;

protected:


    void  Confirm( int confirm_state );

public:

    CWIFILF( void );
    ~CWIFILF();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)( void );





    void  REQ_Start( S_WIFILF wifilf );
    void  REQ_Stop();
    void  REQ_SetRegDomain( void );
    // void  REQ_SetChannel( void );
    void  REQ_LocalFrequecyMeasure( void );




    // global information
    int   Get_ConfirmState( void );

};

/*---------------------------------------------------------------------------*/
#endif
