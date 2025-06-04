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
 *   wifi_cptx.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi continuous packet TX header
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
#ifndef  _WIFI_CPTX_H_
#define  _WIFI_CPTX_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

/*---------------------------------------------------------------------------*/
// WiFi MAC header
#define  WIFI_MAC_HEAD_FRAME_CTRL_LEN 2
#define  WIFI_MAC_HEAD_DURATION_LEN   2
#define  WIFI_MAC_HEAD_ADDRESS_LEN    6
#define  WIFI_MAC_HEAD_SEQ_CTRL_LEN   2
#define  WIFI_MAC_HEAD_LEN           24

#define  WIFI_TX_FLAG_ENABLE_ALC_TRACK   0x01
#define  WIFI_TX_FLAG_TARGET_ALC_PROVIDE 0x02
#define  WIFI_TX_FLAG_NO_TXGAIN          0x04
/*---------------------------------------------------------------------------*/
typedef struct
{
    unsigned char frame_ctrl[WIFI_MAC_HEAD_FRAME_CTRL_LEN];
    unsigned char duration[WIFI_MAC_HEAD_DURATION_LEN];
    unsigned char address1[WIFI_MAC_HEAD_ADDRESS_LEN];
    unsigned char address2[WIFI_MAC_HEAD_ADDRESS_LEN];
    unsigned char address3[WIFI_MAC_HEAD_ADDRESS_LEN];
    unsigned char seq_ctrl[WIFI_MAC_HEAD_SEQ_CTRL_LEN];

} S_WiFiMacHead;

typedef struct
{
    bool bAlcSupport;
    int wifi_id;
    WiFi_RegDomain_S reg_domain;
    unsigned int channel_freq;
    WiFi_TestRate_E tx_rate;
    unsigned int pkt_length;
    unsigned int pkt_count;
    unsigned int pkt_interval;
    unsigned char tx_pwr_dac;
    WiFi_TestPktTxPattern_E pattern;
    unsigned char is_short_preamble;
    S_WiFiMacHead     s_mac_header;
    // ALC
    unsigned int ui_txFlags;
    unsigned int ui_targetAlc;
} S_WIFICPT;


/*---------------------------------------------------------------------------*/

class  CWIFICPT
{
private:
    int   m_iConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_WIFICPT  m_sWiFiCPT;
    WiFi_TestPktTx_Ex_S  m_sPktTx;
    WiFi_TxPower_2400M_S  m_sTxPwr2400M;
    WiFi_TxPower_5000M_S  m_sTxPwr5000M;
    WiFi_DBM2DAC_Set_S    m_sSetDbm2Dac;
    WiFi_DBM2DAC_Query_S  m_sQueryDbm2Dac;
    char             *m_pcTxPowerBuf;
    int               m_iTxPowerBufSize;
    int m_idBm;

    // query
    WiFi_TxStatus_Ex_S  m_WiFiTxStatus;

protected:


    void  Confirm(int confirm_state);

public:

    CWIFICPT(void);
    ~CWIFICPT();

    void  REQ_Finish(void);
    void  REQ_TimeOut(void);


    // query
    void REQ_Query_TxStatus(void);
    void REQ_Query_DbmToDac(void);



    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

public:  // Public member


    void  (*ConfirmCallback)(void);





    void  REQ_Start(S_WIFICPT wificpt);
    void  REQ_Stop(void);
    void  REQ_SetRegDomain(void);
    void  REQ_ContinuousPktTx(void);
    void  REQ_SetDbmToDac_Start(unsigned int channel_freq, WiFi_TestRate_E tx_rate, int dBm);
    void  REQ_SetDbmToDac(void);

    // MAC header
    void  Compose_MacHeader(S_WiFiMacHead s_mac_head, char *p_mac_header);
    void  DeCompose_MacHeader(char *p_mac_header, S_WiFiMacHead &s_mac_head);


    // query
    bool REQ_Query_ChannelList(unsigned int *channel_num, unsigned char *channel_id);
    void REQ_Query_TxStatus_Start(bool alc_support);
    void REQ_Query_DbmToDac_Start(void);


    // global information
    int   Get_ConfirmState(void);
    WiFi_TxPower_2400M_S  Get_TxPwr2400M(void);
    void  Set_TxPwr2400M(WiFi_TxPower_2400M_S *p_tx_pwr_2400m);
    WiFi_TxPower_5000M_S  Get_TxPwr5000M(void);
    void  Set_TxPwr5000M(WiFi_TxPower_5000M_S *p_tx_pwr_5000m);
    WiFi_TxStatus_Ex_S  Get_TxStatus(void);


};

/*---------------------------------------------------------------------------*/
#endif
