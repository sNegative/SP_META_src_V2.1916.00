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
 *   wifi_cptx.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi continuous packet TX source
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
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
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

#ifndef  _METAAPP_COMMON_H_
#include "METAAPP_common.h"
#endif

#ifndef  _WIFI_CPTX_H_
#include "wifi_cptx.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

//===========================================================================
static bool  g_bIsRunning = false;
static CWIFICPT*  gs_wifi_cptx_ptr;

//===========================================================================
//---------------------------------------------------------------------------
static void REQ_SetRegDomain(void)
{
    gs_wifi_cptx_ptr->REQ_SetRegDomain();
}

//---------------------------------------------------------------------------
static void REQ_ContinuousPktTx(void)
{
    gs_wifi_cptx_ptr->REQ_ContinuousPktTx();
}

//---------------------------------------------------------------------------
static void REQ_Query_TxStatus(void)
{
    gs_wifi_cptx_ptr->REQ_Query_TxStatus();
}

//---------------------------------------------------------------------------
static void REQ_SetDbmToDac(void)
{
    gs_wifi_cptx_ptr->REQ_SetDbmToDac();
}

//---------------------------------------------------------------------------
static void REQ_Query_DbmToDac(void)
{
    gs_wifi_cptx_ptr->REQ_Query_DbmToDac();
}

//------------------------------------------------------------------------------
static void REQ_TimeOut(void)
{
    gs_wifi_cptx_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish(void)
{
    gs_wifi_cptx_ptr->REQ_Finish();
}

//===========================================================================
CWIFICPT::CWIFICPT(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_pcTxPowerBuf = NULL;
    m_iTxPowerBufSize = 0;
    m_iConfirmState = 0;
    m_idBm = 0;
    memset(&m_sWiFiCPT,0,sizeof(m_sWiFiCPT));
}

//---------------------------------------------------------------------------
CWIFICPT::~CWIFICPT()
{
    g_bIsRunning = false;
    ConfirmCallback = 0;

    if (m_pcTxPowerBuf)
    {
        delete [] m_pcTxPowerBuf;
        m_pcTxPowerBuf = NULL;
    }
}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_Finish(void)
{
    if(! g_bIsRunning)  return;

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(METAAPP_STOP);

}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_TimeOut(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm( META_TIMEOUT );;
}

//---------------------------------------------------------------------------
void  CWIFICPT::Confirm( int confirm_state )
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }

    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
void  CWIFICPT::REQ_Start(S_WIFICPT wificpt)
{
    gs_wifi_cptx_ptr           = this;
    g_bIsRunning               = true;
    m_sWiFiCPT                 = wificpt;

    m_sPktTx.ch_freq           = wificpt.channel_freq;
    m_sPktTx.tx_rate           = wificpt.tx_rate;
    m_sPktTx.tx_gain_dac       = wificpt.tx_pwr_dac;
    m_sPktTx.pktCount          = wificpt.pkt_count;
    m_sPktTx.pktInterval       = wificpt.pkt_interval;
    m_sPktTx.pktLength         = wificpt.pkt_length;
    m_sPktTx.pattern           = wificpt.pattern;
    m_sPktTx.txAnt             = 0;
    m_sPktTx.is_short_preamble = wificpt.is_short_preamble;
    m_sPktTx.txFlags           = wificpt.ui_txFlags;
    m_sPktTx.targetAlc         = wificpt.ui_targetAlc;

    ActiveMan->SetActiveFunction(::REQ_SetRegDomain);
}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_SetRegDomain(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_WiFi_SetRegDomain_r(m_META_HANDLE_Obj.Get_MainHandle(),  500, &m_sWiFiCPT.reg_domain);

    if (MetaResult != META_SUCCESS)
    {
        if (MetaResult != META_TIMEOUT)
        {
            Confirm(META_FAILED);
            return;
        }
        else
        {
            Confirm(META_TIMEOUT);
            return;
        }
    }
    ActiveMan->SetActiveFunction(::REQ_ContinuousPktTx);

}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_ContinuousPktTx( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult;
    Compose_MacHeader(m_sWiFiCPT.s_mac_header, m_sPktTx.mac_header);

    if (m_sWiFiCPT.bAlcSupport)
    {
        MetaResult = SP_META_WiFi_ContPktTx_Ex_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sPktTx);
    }
    else
    {
        WiFi_TestPktTx_S pkt_tx;
        pkt_tx.ch_freq           = m_sPktTx.ch_freq;
        pkt_tx.tx_rate           = m_sPktTx.tx_rate;
        pkt_tx.tx_gain_dac       = m_sPktTx.tx_gain_dac;
        pkt_tx.pktCount          = m_sPktTx.pktCount;
        pkt_tx.pktInterval       = m_sPktTx.pktInterval;
        pkt_tx.pktLength         = m_sPktTx.pktLength;
        pkt_tx.pattern           = m_sPktTx.pattern;
        pkt_tx.txAnt             = m_sPktTx.txAnt;
        pkt_tx.is_short_preamble = m_sPktTx.is_short_preamble;
        for (int i=0; i<WIFI_MAC_HEAD_LEN; i++)
        {
            pkt_tx.mac_header[i] = m_sPktTx.mac_header[i];
        }
        MetaResult = SP_META_WiFi_ContPktTx_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, &pkt_tx);
    }

    if (MetaResult != META_SUCCESS)
    {
        if (MetaResult != META_TIMEOUT )
        {
            Confirm(META_FAILED );
            return;
        }
    }
    ActiveMan->SetActiveFunction(::REQ_Query_TxStatus);


}


//---------------------------------------------------------------------------
void CWIFICPT::REQ_SetDbmToDac_Start( unsigned int channel_freq, WiFi_TestRate_E tx_rate, int dBm )
{
    gs_wifi_cptx_ptr = this;
    g_bIsRunning = true;

    m_sSetDbm2Dac.ch_freq = channel_freq;
    m_sSetDbm2Dac.tx_rate = tx_rate;
    m_sSetDbm2Dac.dbm     = dBm;

    ActiveMan->SetActiveFunction( ::REQ_SetDbmToDac );


}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_SetDbmToDac( void )
{
#if 0
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT  MetaResult = META_WiFi_SetDbmToDac_r(m_META_HANDLE_Obj.Get_MainHandle(), 900, m_iChannelFreq, m_eTxRate, m_idBm);

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( META_FAILED );
            return;
        }
        else
        {
            Confirm( META_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );
#endif
}

//===========================================================================
////////////////////////////          Query          ////////////////////////
//===========================================================================
void CWIFICPT::REQ_Query_TxStatus_Start(bool alc_support)
{
    gs_wifi_cptx_ptr = this;
    g_bIsRunning = true;
    m_sWiFiCPT.bAlcSupport = alc_support;
    ActiveMan->SetActiveFunction(::REQ_Query_TxStatus);
}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_Query_TxStatus( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult;
    if (m_sWiFiCPT.bAlcSupport)
    {
        MetaResult = SP_META_WiFi_QueryTxStatus_Ex_r(m_META_HANDLE_Obj.Get_MainHandle(), 900, &m_WiFiTxStatus);
    }
    else
    {
        WiFi_TxStatus_S tx_status;
        MetaResult = SP_META_WiFi_QueryTxStatus_r (m_META_HANDLE_Obj.Get_MainHandle(), 900, &tx_status);
        m_WiFiTxStatus.pkt_sent_count = tx_status.pkt_sent_count;
        m_WiFiTxStatus.pkt_sent_acked = tx_status.pkt_sent_acked;
    }

    if (MetaResult != META_SUCCESS)
    {
        if (MetaResult != META_TIMEOUT)
        {
            Confirm(META_FAILED);
            return;
        }
    }
    ActiveMan->SetActiveFunction(::REQ_Finish);


}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFICPT::REQ_Query_DbmToDac_Start( void )
{
    gs_wifi_cptx_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction( ::REQ_Query_DbmToDac );
}

//---------------------------------------------------------------------------
void CWIFICPT::REQ_Query_DbmToDac( void )
{
#if 0
    META_RESULT MetaResult = META_WiFi_QueryDbmToDac_r ( m_META_HANDLE_Obj.Get_MainHandle(), 900, &m_usTxPwrDAC );
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm(META_FAILED);
            return;
        }
        else
        {
            Confirm( META_TIMEOUT );
            return;
        }
    }
    ActiveMan->SetActiveFunction( ::REQ_Finish );
#endif

}

//===========================================================================
////////////////////////////       MAC header        ////////////////////////
//===========================================================================
void  CWIFICPT::Compose_MacHeader( S_WiFiMacHead s_mac_head, char *p_mac_header )
{
    int i;
    for( i=0; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.seq_ctrl[i];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.address3[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+2*WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.address2[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-WIFI_MAC_HEAD_ADDRESS_LEN];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+2*WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.address1[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-2*WIFI_MAC_HEAD_ADDRESS_LEN];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN+WIFI_MAC_HEAD_DURATION_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.duration[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-3*WIFI_MAC_HEAD_ADDRESS_LEN];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN+WIFI_MAC_HEAD_DURATION_LEN; i<WIFI_MAC_HEAD_LEN; i++ )
        p_mac_header[WIFI_MAC_HEAD_LEN-i-1] = s_mac_head.frame_ctrl[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-3*WIFI_MAC_HEAD_ADDRESS_LEN-WIFI_MAC_HEAD_DURATION_LEN];
}

//----------------------------------------------------------------------------
void  CWIFICPT::DeCompose_MacHeader( char *p_mac_header, S_WiFiMacHead &s_mac_head )
{
    int i;
    for( i=0; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN; i++ )
        s_mac_head.seq_ctrl[i] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        s_mac_head.address3[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+2*WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        s_mac_head.address2[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-WIFI_MAC_HEAD_ADDRESS_LEN] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+2*WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN; i++ )
        s_mac_head.address1[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-2*WIFI_MAC_HEAD_ADDRESS_LEN] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN; i<WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN+WIFI_MAC_HEAD_DURATION_LEN; i++ )
        s_mac_head.duration[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-3*WIFI_MAC_HEAD_ADDRESS_LEN] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];

    for( i=WIFI_MAC_HEAD_SEQ_CTRL_LEN+3*WIFI_MAC_HEAD_ADDRESS_LEN+WIFI_MAC_HEAD_DURATION_LEN; i<WIFI_MAC_HEAD_LEN; i++ )
        s_mac_head.frame_ctrl[i-WIFI_MAC_HEAD_SEQ_CTRL_LEN-3*WIFI_MAC_HEAD_ADDRESS_LEN-WIFI_MAC_HEAD_DURATION_LEN] = p_mac_header[WIFI_MAC_HEAD_SEQ_CTRL_LEN-i-1];
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
int   CWIFICPT::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_2400M_S  CWIFICPT::Get_TxPwr2400M( void )
{
    return m_sTxPwr2400M;
}

//----------------------------------------------------------------------------
void  CWIFICPT::Set_TxPwr2400M( WiFi_TxPower_2400M_S *p_tx_pwr_2400m )
{
    m_sTxPwr2400M = *p_tx_pwr_2400m;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_5000M_S  CWIFICPT::Get_TxPwr5000M( void )
{
    return m_sTxPwr5000M;
}

//----------------------------------------------------------------------------
void  CWIFICPT::Set_TxPwr5000M( WiFi_TxPower_5000M_S *p_tx_pwr_5000m )
{
    m_sTxPwr5000M = *p_tx_pwr_5000m;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxStatus_Ex_S  CWIFICPT::Get_TxStatus( void )
{
    return m_WiFiTxStatus;
}


