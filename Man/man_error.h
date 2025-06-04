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
 *   man_error.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Error handling header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.10  $
 * $Modtime:   Oct 25 2005 12:18:12  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_error.h-arc  $
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * Jun 16 2007 mtk00490
 * [STP100001440] [META] META ver 5.3.9
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
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:16   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:06:44   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:10   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:57:50   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:14:22   mtk00490
 * 1. Automatic BB chip and external clock rate detection
 * 2. Support baud rate 57600 (for FPGA test)
 * 3. RF tool
 * a.Trim IQ, offset IQ sweep (get phase error, original offset, IQ imbalance information from equipment)
 * 4. Audio
 * a.Acoustic FIR tuning and melody FIR tuning integrate with AFTDLL.dll (provide freqz and firls function, user does not to install MATLAB for FIR tuning)
 * 5. Update parameter
 * a.add barcode and IMEI read/write
 * 6. Factory
 * a.support DCS, PCS, GSM850 AFC calibration
 * b.phase error calibration
 * c.user configurable current limit
 * d.add APC DAC to result file
 * e.add AFC_BAND, AFC_ARFCN to TCVCXO AFC CFG editor
 * f.add CURRENT_LIMIT to ADC CFG editor
 * g.add phase error CFG editor
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _MAN_ERROR_H_
#define  _MAN_ERROR_H_
/*---------------------------------------------------------------------------*/

#define  MSG_ERR_OPEN_COM_FAIL                    1
#define  MSG_ERR_SET_COM_RATE_FAIL                2


enum
{
    // RF
    RANGE_ERR_ARFCN,
    RANGE_ERR_ARFCN2,
    RANGE_ERR_ARFCN_STEP,
    RANGE_ERR_APC_LOWEST_POWER,
    RANGE_ERR_PM_COUNT,
    RANGE_ERR_AFC_COUNT,
    RANGE_ERR_GAIN,
    RANGE_ERR_PATH_LOSS,
    RANGE_ERR_PCL,
    RANGE_ERR_PCL_DAC,
    RANGE_ERR_VBIAS,
    RANGE_ERR_AFC,
    RANGE_ERR_FREQERR,
    RANGE_ERR_INIT_AFC_DAC,
    RANGE_ERR_AFC_SLOPE,
    RANGE_ERR_CFG_AFC_SLOPE,
    RANGE_ERR_CFG_FREQUENCY_ERROR_PPM,
    RANGE_ERR_CFG_FREQUENCY_ERROR,
    RANGE_ERR_RAMP,
    RANGE_ERR_WEIGHT,
    RANGE_ERR_REG_BIT,
    RANGE_ERR_MEASUREMENT_COUNT,
    RANGE_ERR_PERIOD,
    RANGE_ERR_REFDET_SLOPE_SKEW,
    RANGE_ERR_AM_FB_DAC,

    // ADC
    RANGE_ERR_ADC_SLOPE,
    RANGE_ERR_ADC_OFFSET,
    RANGE_ERR_ADC_INPUT,
    RANGE_ERR_ADC_VOLTAGE,
    RANGE_ERR_CURRENT_LIMIT,
    RANGE_ERR_ADC_CHANNEL,
    RANGE_ERR_ADC_RESISTANCE,
    RANGE_ERR_ADC_MAX_VOLTAGE_DIFFERENCE,
    RANGE_ERR_ADC_MAX_CURRENT_DIFFERENCE,
    RANGE_ERR_ADC_MEASUREMENT_COUNT,

    // common CFG
    RANGE_ERR_GPIB_ADDR,
    RANGE_ERR_TIMEOUT,
    RANGE_ERR_CABLE_LOSS,
    RANGE_ERR_POWER,

    // RX path loss CFG
    RANGE_ERR_CFG_PMCOUNT,

    // TX PCL CFG
    RANGE_ERR_CFG_PCL,
    RANGE_ERR_CFG_MAX_P,
    RANGE_ERR_CFG_WANTED_P,
    RANGE_ERR_CFG_MIN_P,
    RANGE_ERR_CFG_C,
    RANGE_ERR_CFG_CORRECTION,
    RANGE_ERR_RECURSIVE_TIMES,
    RANGE_ERR_CFG_APC_DELTA,
    RANGE_ERR_CFG_TSC,

    // phase error CFG
    RANGE_ERR_PHASE_ERROR,


    // FM
    RANGE_ERR_FM_FREQ,
    RANGE_ERR_FM_RSSI_THRESHOLD,
    RANGE_ERR_FM_IF_COUNTER_DELTA,
    RANGE_ERR_FM_CHANNEL,


    // baseband
    RANGE_ERR_REG_ADDR,
    RANGE_ERR_REG_VALUE,
    RANGE_ERR_GPIO_PORT,
    RANGE_ERR_GPIO_VALUE,
    RANGE_ERR_LED_LIGHT_LEVEL,
    RANGE_ERR_RTC_YEAR,
    RANGE_ERR_RTC_MONTH,
    RANGE_ERR_RTC_WDAY,
    RANGE_ERR_RTC_DAY,
    RANGE_ERR_RTC_HOUR,
    RANGE_ERR_RTC_MINUTE,
    RANGE_ERR_RTC_SEC,
    // BB TX parameters
    RANGE_ERR_TRIM_IQ,
    RANGE_ERR_TRIM_IQ_STEP,
    RANGE_ERR_OFFSET_IQ,
    RANGE_ERR_OFFSET_IQ_STEP,
    RANGE_ERR_BB_TX_CAL_FLAG,
    RANGE_ERR_TX_CALBIAS,
    RANGE_ERR_TX_IQSWAP,
    RANGE_ERR_BB_TX_COMMON_MODE_VOLTAGE,
    RANGE_ERR_BB_TX_GAIN,
    RANGE_ERR_CALRCSEL,
    RANGE_ERR_PHASESEL,
    RANGE_ERR_PHASESEL_STEP,
    RANGE_ERR_APC_BAT_LOW_VOLTAGE,
    RANGE_ERR_APC_BAT_HIGH_VOLTAGE,
    RANGE_ERR_APC_BAT_LOW_TEMPERATURE,
    RANGE_ERR_APC_BAT_HIGH_TEMPERATURE,
    RANGE_ERR_BATTERY_COMPENSATE,
    // BV
    RANGE_ERR_BV_AP,
    RANGE_ERR_BV_AS,
    RANGE_ERR_BV_AO,
    RANGE_ERR_BV_BD,
    RANGE_ERR_BV_KAG,
    RANGE_ERR_BV_KSG,
    RANGE_ERR_BV_KAD,
    RANGE_ERR_BV_KSD,
    RANGE_ERR_BV_VRE,
    RANGE_ERR_BV_VOF,
    RANGE_ERR_BV_ARE,
    RANGE_ERR_BV_AOF,

    // crystal
    RANGE_ERR_CAPID,
    RANGE_ERR_TX_AFC_OFFSET,
    RANGE_ERR_INTERSLOT_LOWEST_DAC,
    RANGE_ERR_CTS_TEMPERATURE,
    RANGE_ERR_CTS_TEMPERATURE_STEP,

    // Audio
    RANGE_ERR_FIR_TAPS,
    RANGE_ERR_FIR_COEF,
    RANGE_ERR_DELAY,
    RANGE_ERR_REPEATS,
    RANGE_ERR_SPEAKERVOLUME,
    RANGE_ERR_BUZZERVOLUME,
    RANGE_ERR_FACTORY_ID,
    RANGE_ERR_TA,
    RANGE_ERR_ICORRECTION,
    RANGE_ERR_QCORRECTION,
    RANGE_ERR_ACODE,
    RANGE_ERR_AMCODE,
    RANGE_ERR_BCODE,
    RANGE_ERR_CCODE,
    RANGE_ERR_MUTLISLOT_TX_PATTERN,
    RANGE_ERR_CT_PATTERN,
    RANGE_ERR_C3TA,
    RANGE_ERR_C3TB,
    RANGE_ERR_C3TC,
    RANGE_ERR_C3TN,
    RANGE_ERR_C3TO,
    RANGE_ERR_C3PM,
    RANGE_ERR_VOLUME,
    RANGE_ERR_INSTRUMENT,
    RANGE_ERR_TIME_CONST,
    RANGE_ERR_VOLUME_CONST,
    RANGE_ERR_MEDIA_PLAYBACK_MAXIMUM_SWING,
    RANGE_ERR_SPEECH_COMMON_PARAMETER,
    RANGE_ERR_SPEECH_MODE_DEPENDENT_PARAMETER,
    RANGE_ERR_MEASURE_COUNT,
    RANGE_ERR_BATTERY_LEVEL_VOLTAGE,
    // audio
    RANGE_ERR_VOLUME_GAIN,
    RANGE_ERR_MAG_DB,
    RANGE_ERR_DIGITAL_GAIN,
    RANGE_ERR_PURE_GAIN,
    RANGE_ERR_MAX_VOLUME,
    // tone
    RANGE_ERR_TONE_FREQ,
    RANGE_ERR_LOUD_SPEAKER_VOLUME,
    // FIR tunning
    RANGE_ERR_FIR_SCALE,
    RANGE_ERR_DIGITAL_SCALE,
    // AEC
    RANGE_ERR_SPEAKER_GAIN,
    RANGE_ERR_MIC_GAIN,
    // ABF
    RANGE_ERR_REC_TIME,

    // IMEISV
    RANGE_ERR_IMEI_SVN,
    RANGE_ERR_IMEI_PAD,
    // Agilent 8960
    RANGE_ERR_AGE_MEASUREMENT_COUNT,

    // WiFi
    RANGE_ERR_WIFI_BB_CHIP_ID,
    RANGE_ERR_WIFI_RF_CHIP_ID,
    RANGE_ERR_WIFI_SN,
    RANGE_ERR_WIFI_MAC_ADDRESS,
    RANGE_ERR_WIFI_BB_REG_ADDR,
    RANGE_ERR_WIFI_BB_REG_VALUE,
    RANGE_ERR_WIFI_MAC_REG_ADDR,
    RANGE_ERR_WIFI_MAC_REG_VALUE,
    RANGE_ERR_WIFI_EE_ADDR,
    RANGE_ERR_WIFI_EE_VALUE,

    RANGE_ERR_WIFI_PACKET_LENGTH,
    RANGE_ERR_WIFI_PACKET_COUNT,
    RANGE_ERR_WIFI_PACKET_INTERVAL,
    RANGE_ERR_WIFI_TX_POWER_DAC,
    RANGE_ERR_WIFI_TX_DC_OFFSET,
    RANGE_ERR_WIFI_MAC_HEADER_FRAME_CTRL,
    RANGE_ERR_WIFI_MAC_HEADER_DURATION,
    RANGE_ERR_WIFI_MAC_HEADER_ADDRESS,
    RANGE_ERR_WIFI_MAC_HEADER_SEQ_CTRL,
//rongguo 2011-06-18
    RANGE_ERR_WIFI_REGISTER_VALUE,
//rongguo 2011-10-23
    RANGE_ERR_WIFI_CRYSTAL_VALUE,

    RANGE_ERR_WIFI_TX_ALC_CCK,
    RANGE_ERR_WIFI_TX_OUTPUT_POWER_DB_CCK,
    RANGE_ERR_WIFI_TX_ALC_OFDM,
    RANGE_ERR_WIFI_TX_OUTPUT_POWER_DB_OFDM,
    RANGE_ERR_WIFI_ALC_OFFSET,
    RANGE_ERR_WIFI_TARGET_ALC,
    RANGE_ERR_WIFI_ALC_SLOPE_DIVIDER,
    RANGE_ERR_WIFI_ALC_SLOPE_DIVIDEND,


    // BT common
    RANGE_ERR_BT_HCI_VALUE,
    RANGE_ERR_BT_HCI_OPCODE,
    RANGE_ERR_BT_HCI_EVENT_INDEX,
    RANGE_ERR_BT_FREQ,
    RANGE_ERR_BT_TX_DATA_LENGTH,
    RANGE_ERR_BT_TX_POLL_PERIOD,
    RANGE_ERR_BT_TX_PACKET_COUNT,
    RANGE_ERR_BT_TX_PCL,
    RANGE_ERR_BT_TX_LAP,
    RANGE_ERR_BT_TX_ACCESS_CODE,
    RANGE_ERR_BT_BD_ADDRESS,
    RANGE_ERR_BT_TIMEOUT,
    RANGE_ERR_BT_PIN,
    RANGE_ERR_BT_BLE_CHANNEL,


    // ESCO
    RANGE_ERR_BT_RX_BANDWIDTH,
    RANGE_ERR_BT_TX_BANDWIDTH,
    RANGE_ERR_BT_MAX_LATENCY,
    RANGE_ERR_BT_RETRANSMISSION_EFFORT,
    RANGE_ERR_BT_LEVEL,

    //UUID
    RANGE_ERR_UUID_VALUE,
    // Unit Test
    RANGE_ERR_UNIT_TEST_ID,

    RANGE_ERR_NFC_DURATION,
    RANGE_ERR_GPS_AUTOTEST_NUM,
    RANGE_ERR_GPS_SVID,
    RANGE_ERR_SPECIALTETS_TEST_NUM,
};
/*---------------------------------------------------------------------------*/

#define  MSG_CHECK_ERROR( _op_id )      \
{  ::ShowErrorMessage( _op_id );        \
}

#define  RANGE_CHECK_ERROR( _false_statement, _op_id )  \
{  if( _false_statement )                               \
   {  ::ShowRangeErrorMessage( _op_id );                \
      return(false);                                    \
   }                                                    \
}

/*---------------------------------------------------------------------------*/

extern void ShowErrorMessage( int op_id );
extern void ShowTimeoutMessage( int op_id );
extern void ShowRangeErrorMessage( int op_id );

/*---------------------------------------------------------------------------*/
#endif