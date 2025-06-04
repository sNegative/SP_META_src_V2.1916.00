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
 *   wifi_common.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi common header
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
#ifndef  _WIFI_COMMON_H_
#define  _WIFI_COMMON_H_

/*---------------------------------------------------------------------------*/
typedef enum
{
    WIFI_802_11A_IDX = 0,
    WIFI_802_11B_IDX,
    WIFI_802_11G_IDX
} E_WIFI_GENERATION;

typedef enum
{
    WIFI_MOD_CCK = 0,
    WIFI_MOD_OFDM
} E_WIFI_MOD;

#define   NUM_TX_POWER_2400M_CH   14
#define   NUM_TX_POWER_5000M_CH   34

#define   WIFI_CCK_TX_RATE_NUM     4
#define   WIFI_OFDM_TX_RATE_NUM   12

// ALC
#define   WIFI_ALC_2400M_TX_RATE_NUM  8
#define   WIFI_ALC_2400M_CH_NUM   14

#define   BB_ADDR_MIN           0
#define   BB_ADDR_MAX         127
#define   BB_ADDR_STEP          1

#define   MAC_ADDR_MIN           0
#define   MAC_ADDR_MAX      0x04FC
#define   MAC_ADDR_STEP          4

#define   EE_ADDR_MIN           0
#define   EE_ADDR_MAX_IPN2128   0x007F
#define   EE_ADDR_MAX_MT5911    0x00FF
#define   EE_ADDR_STEP          1

// TX DC offset
#define WIFI_IDX_IDC  0
#define WIFI_IDX_QDC  1

// read/wrtie
#define WIFI_MAX_COUNT  200



typedef struct
{
    unsigned int ch_freq_MHz[NUM_TX_POWER_5000M_CH];
    int ch_num;
} S_WIFI_CH_FREQ_MHZ;
/*---------------------------------------------------------------------------*/
#endif
