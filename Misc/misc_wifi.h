/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   misc_wifi.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi Misc. function header
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
 * Jan 1 2007 mtk00490
 * [STP100001274] [META] META ver 5.3.4.2
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
#ifndef  _MISC_WIFI_H_
#define  _MISC_WIFI_H_
/*---------------------------------------------------------------------------*/
#include <vcl.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

// WiFi
#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif
/*---------------------------------------------------------------------------*/
// WiFi
extern bool IsValidDecWiFiBBChipID(AnsiString ansi_str, unsigned short &chip_id);
extern bool IsValidHexWiFiBBChipID(AnsiString ansi_str, unsigned short &chip_id);
extern bool IsValidDecWiFiRFChipID(AnsiString ansi_str, unsigned short &chip_id);
extern bool IsValidHexWiFiRFChipID(AnsiString ansi_str, unsigned short &chip_id);
extern bool IsValidDecWiFiSN(AnsiString ansi_str, unsigned int &sn);
extern bool IsValidHexWiFiSN(AnsiString ansi_str, unsigned int *sn);
extern bool IsValidDecWiFiMACAddress(AnsiString ansi_str, unsigned char &mac_addr_char);
extern bool IsValidHexWiFiMACAddress(AnsiString ansi_str, unsigned char &mac_addr_char);
extern bool IsValidDecWiFiBBRegAddr(AnsiString ansi_str, unsigned int &addr);
extern bool IsValidHexWiFiBBRegAddr(AnsiString ansi_str, unsigned char &addr);
extern bool IsValidDecWiFiBBRegValue(AnsiString ansi_str, unsigned char &value);
extern bool IsValidHexWiFiBBRegValue(AnsiString ansi_str, unsigned char &value);
extern bool IsValidHexWiFiMacRegAddr(AnsiString ansi_str, unsigned int *addr);
extern bool IsValidDecWiFiMacRegValue(AnsiString ansi_str, unsigned int &value);
extern bool IsValidDecWiFiMacReg16Value(AnsiString ansi_str, unsigned short &value);
extern bool IsValidHexWiFiMacReg16Value(AnsiString ansi_str, unsigned short &value);
extern bool IsValidHexWiFiMacRegValue(AnsiString ansi_str, unsigned int *value);
extern bool IsValidHexWiFiEERegAddr(AnsiString ansi_str, unsigned int *addr);
extern bool IsValidDecWiFiEERegValue(AnsiString ansi_str, unsigned short &value);
extern bool IsValidHexWiFiEERegValue(AnsiString ansi_str, unsigned short &value);
extern bool IsValidWiFiPacketLength(AnsiString ansi_str, unsigned int &pkt_length);
extern bool IsValidWiFiPacketCount(AnsiString ansi_str, unsigned int &pkt_count);
extern bool IsValidWiFiPacketInterval(AnsiString ansi_str, unsigned int &pkt_interval);
extern bool IsValidDecWiFiTxPowerDac(AnsiString ansi_str, unsigned char &dac);
extern bool IsValidHexWiFiTxPowerDac(AnsiString ansi_str, unsigned char &dac);
extern bool IsValidDecWiFiTxDcOffset(AnsiString ansi_str, unsigned char &txdc);
extern bool IsValidHexWiFiTxDcOffset(AnsiString ansi_str, unsigned char &txdc);
extern bool IsValidHexWiFiMacHeaderFrameCtrl(AnsiString ansi_str, unsigned char &frame_ctrl);
extern bool IsValidHexWiFiMacHeaderDuration(AnsiString ansi_str, unsigned char &duration);
extern bool IsValidHexWiFiMacHeaderAddress(AnsiString ansi_str, unsigned char &addr);
extern bool IsValidHexWiFiMacHeaderSeqCtrl(AnsiString ansi_str, unsigned char &seq_ctrl);
extern bool IsValidWiFiTxRate(E_WIFI_GENERATION wifi_gen, double d_tx_rate);
extern bool IsWiFiSupported( AnsiString as_802_11, E_WIFI_GENERATION e_802_11_idx);
//rongguo 2011-06-23
extern bool IsValidWiFiRegisterValue(AnsiString ansi_str, float &registerValue);
//rongguo 2011-10-23
extern bool IsValidWiFiCrystalValue(AnsiString ansi_str, int &registerValue);

// ALC
extern bool IsValidWiFiTxAlcCCK(AnsiString ansi_str, unsigned char &tx_alc);
extern bool IsValidWiFiTxOutputPowerDbCCK(AnsiString ansi_str, unsigned char &output_power);
extern bool IsValidWiFiTxAlcOFDM(AnsiString ansi_str, unsigned char &tx_alc);
extern bool IsValidWiFiTxOutputPowerDbOFDM(AnsiString ansi_str, unsigned char &output_power);
extern bool IsValidWiFiAlcOffset(AnsiString ansi_str, char &offset);
extern bool IsValidWiFiTargetALC(AnsiString ansi_str, unsigned int &alc);
extern bool IsValidWiFiAlcSlopeDivider(AnsiString ansi_str, unsigned char &alc_slope_divider);
extern bool IsValidWiFiAlcSlopeDividend(AnsiString ansi_str, unsigned char &alc_slope_dividend);

// format transform
extern bool   MACAddress_To_Str(WiFi_MacAddress_S mac_addr, AnsiString &as_str);
extern bool Str_To_MACAddress(AnsiString as_str, WiFi_MacAddress_S &mac_addr);
extern unsigned int GetWiFiChannelFreqFromStr(AnsiString as_str);
extern unsigned int GetWiFiChannelFrequency(int _802_11_type, int idx);
extern unsigned int GetWiFiTxRateFromStr(AnsiString as_str);
extern bool GetWiFiChannelIndexFromStr(AnsiString as_channel, AnsiString as_txrate, E_WIFI_GENERATION &wifi_802_11_idx, unsigned int &chan_idx);
extern bool GetWiFiTxRate(double d_tx_rate, WiFi_TestRate_E &e_tx_rate);
extern int GetWiFiRemainChannels(E_WIFI_GENERATION wifi_gen, S_WIFI_CH_FREQ_MHZ org_ch_freq_mhz, S_WIFI_CH_FREQ_MHZ &remain_ch_freq_mhz);
extern int GetWiFiNVRAMChannelIndex(E_WIFI_GENERATION wifi_gen, unsigned int ch_freq_mhz);
extern bool GetWiFiTwoClosetNVRAMChannelIndex(E_WIFI_GENERATION wifi_gen, unsigned int ch_freq_MHz, S_WIFI_CH_FREQ_MHZ s_ch_freq_MHz, int &first_ch_index, int &second_ch_index);
//

#endif
