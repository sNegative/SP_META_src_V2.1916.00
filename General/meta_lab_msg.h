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
 *   META_lab_msg.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  META LAB message header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.2  $
 * $Modtime:   Oct 25 2005 12:09:44  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/General/meta_lab_msg.h-arc  $
 *
 * Jul 16 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
 *
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
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
 * Nov 7 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.2   Oct 25 2005 14:15:08   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.1   Sep 04 2005 11:06:30   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.0   Apr 18 2005 15:57:56   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//---------------------------------------------------------------------------


#ifndef _META_LAB_MSG_H_
#define _META_LAB_MSG_H_

#include <windows.h>
//------------------------------------------------------------------------------
typedef  enum
{
    WM_META_LAB_MSG_START = WM_USER+10000,

    // audio
    WM_ML_AUDIO_FIR_VER_CNF,
    WM_ML_AUDIO_AEC_RESULT_CNF,
    WM_ML_AUDIO_VOL_VER_CNF,
    WM_ML_AUDIO_QST_FIR_UPLOAD,
    WM_ML_AUDIO_QST_FIR_DOWNLOAD,
    WM_ML_AUDIO_BESLOUDNESS_V3_AFTER_UPLOAD_FROM_FLASH,
    WM_ML_AUDIO_NB_UPLOAD_FROM_FLASH_DONE,
    WM_ML_AUDIO_NB_DOWNLOAD_TO_FLASH_DONE,
    WM_ML_AUDIO_NB_READ_FROM_FILE_DONE,
    WM_ML_AUDIO_NB_WRITE_TO_FILE_DONE,
    WM_ML_AUDIO_NB_CHANGE_NVRAM_DATABASE_DONE,

    WM_ML_AUDIO_WB_UPLOAD_FROM_FLASH_DONE,
    WM_ML_AUDIO_WB_DOWNLOAD_TO_FLASH_DONE,
    WM_ML_AUDIO_DUAL_MIC_UPLOAD_FROM_FLASH_DONE,
    WM_ML_AUDIO_DUAL_MIC_READ_FROM_FILE_DONE,
    WM_ML_AUDIO_HCF_BESLOUDNESS_V3_AFTER_UPLOAD_FROM_FLASH,
    WM_ML_AUDIO_GT_UPLOAD_FROM_FLASH,
    WM_ML_AUDIO_GT_QUERY_GAIN_TABLE_INFO,
    WM_ML_AUDIO_SPEECH_MODE_TABLE_SUPPORT,
    WM_ML_AUDIO_HD_REC_DUAL_MIC_SUPPORT,
    WM_ML_AUDIO_HD_REC_SD_CARD_DETECTED,
    WM_ML_AUDIO_HD_REC_LOAD_INPUT_FINISHED,
    WM_ML_AUDIO_HD_REC_VR_LOAD_INPUT_ERROR,

    // equipment
    WM_ML_RCT_INIT_FAIL,
    WM_ML_RCT_SET_OPERATION_MODE_FAIL,
    WM_ML_RCT_SET_BAND_FAIL,
    WM_ML_RCT_SET_DOWNLINK_POWER_FAIL,
    WM_ML_RCT_SET_TCH_LEVEL_FAIL,
    WM_ML_RCT_SET_BCH_ARFCN_FAIL,
    WM_ML_RCT_SET_TCH_ARFCN_FAIL,
    WM_ML_RCT_SET_TCH_TIMESLOT_FAIL,
    WM_ML_RCT_SET_TSC_FAIL,
    WM_ML_RCT_SET_MS_TX_LEVEL_FAIL,

    WM_ML_NFC_READER_OPT_READ,
    WM_ML_NFC_P2P,
    WN_ML_NFC_POLLING_LOOP,
    WM_ML_NFC_AIRM,
    // IMEI
    WM_ML_IMEI_SECOND_CNF,

    // query
    WM_ML_QUERY_RFMSCAP_SUCCESS,
    WM_ML_QUERY_RFMSCAP_FAILED,
    WM_ML_QUERY_RFID_SUCCESS,
    WM_ML_QUERY_RFID_FAILED,
    WM_ML_QUERY_CONTSINESUPPORT_SUCCESS,
    WM_ML_QUERY_CONTSINESUPPORT_FAILED,
    WM_ML_QUERY_BBTXCFG3SUPPPORT_SUCCESS,
    WM_ML_QUERY_BBTXCFG3SUPPPORT_FAILED,
    WM_ML_QUERY_RFSETRAMPTABLE_SUCCESS,
    WM_ML_QUERY_RFSETRAMPTABLE_FAILED,
    WM_ML_QUERY_RFEPSKSETRAMPTABLE_SUCCESS,
    WM_ML_QUERY_RFEPSKSETRAMPTABLE_FAILED,

    // NVRAM
    WM_ML_NVRAM_DB_INIT_CNF,
    WM_ML_NVRAM_READ_AFC_FAIL,
    WM_ML_NVRAM_READ_GMSK_APC_CNF,
    WM_ML_NVRAM_READ_EPSK_APC_CNF,

    // RTC
    WM_ML_RTC_PRINT_MSG,
    WM_ML_RTC_CLOCK_OUT_OF_RANGE_MSG,

    // RF
    WM_ML_RF_STOP_FAIL,
    WM_ML_RF_SELECT_BAND_FAIL,
    WM_ML_RF_AFC_CONTROL_FAIL,
    WM_ML_RF_TX_LEVEL_FAIL,
    WM_ML_RF_REG_READ_CNF,
    WM_ML_RF_REG_WRITE_CNF,

    // WiFi
    WM_ML_WIFI_PRINT_MSG,

    // BT
    WM_ML_BT_PRINT_MSG,
    WM_ML_BT_BD_ADDRESS_MSG,
    WM_ML_BT_START_MONITOR_MSG,
    WM_ML_BT_CONNET_WITH_TARGET_NEW_FAIL,
    WM_ML_BT_PIN_MSG,
    MW_ML_BT_CONNECT_MSG,
    WM_ML_BT_DISCONNECT_MSG,
    WM_ML_BT_TT_TX_STATUS,
    WM_ML_BT_TT_RX_STATUS,



    //GPS
    WM_ML_GPS_PKG_PRINT_MSG,
    WM_ML_GPS_PKG_ERROR_MSG,
    WM_ML_GPS_PKG_CW_AUTO_TEST_MSG,
    //Battery
    WM_ML_BASEBAND_BATTERY_FWUPDATE_ONGOING_MSG,
    WM_ML_BASEBAND_BATTERY_FWUPDATE_FINISHED_MSG,
    WM_ML_BASEBAND_BATTERY_FWUPDATE_FAILED_MSG,
    // FM
    WM_ML_FM_RDS_INFO_UPDATE,
    WM_ML_FM_RDS_STATUS_UPDATE,
    WM_FM_DISCONNECT_CLEAN_DONE,
    WM_ML_FM_RDS_COUNTER_UPDATE,
    WM_ML_FM_RDS_COUNTER_UPDATE_MSG,
    WM_ML_FM_RDSON_SUCCESS_MSG,
    WM_ML_FM_BLOCKCOUNTER_RESET_MSG,
    WM_ML_FM_GROUPCOUNTER_RESET_MSG,
	//DFO
    WM_ML_DFO_SHOW_READ_DATA_MSG,

    // Main form
    WM_ML_MAIN_GET_CHIP_VERSION_DONE
} METALabMsg;
#endif
