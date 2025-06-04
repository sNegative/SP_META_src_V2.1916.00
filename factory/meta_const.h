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
 *   meta_const.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  META constant header
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
 * $Modtime:   Oct 25 2005 11:13:04  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/factory/meta_const.h-arc  $
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Mar 22 2006 mtk00490
 * [STP100000700] [META] META ver 3.7.03
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.10   Oct 25 2005 14:13:22   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:01:44   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:47:18   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:54:04   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:09:46   mtk00490
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


#ifndef _META_CONST_H_
#define _META_CONST_H_

// GSM400 (GSM450)
const short GSM400_MIN_ARFCN = 259;
const short GSM400_MAX_ARFCN = 293;

const short GSM850_MIN_ARFCN = 128;
const short GSM850_MAX_ARFCN = 251;

// E-GSM900
const short GSM900_MIN_ARFCN = 0;
const short GSM900_MAX_ARFCN = 1023;

const short DCS1800_MIN_ARFCN = 512;
const short DCS1800_MAX_ARFCN = 885;

const short PCS1900_MIN_ARFCN = 512;
const short PCS1900_MAX_ARFCN = 810;

const int RF_RX_LOSS_END_OF_TABLE = -1;



const float TARGET_TO_PC_DEVIDE = 8.0;
const float PC_TO_TARGET_MULTIPLY = 8.0;

const float AVG_POWER_PC_SIDE_MULTIPLY = PC_TO_TARGET_MULTIPLY;
const AVG_POWER_DIGITS = 4;

const float DEVIATION_PC_SIDE_MULTIPLY = PC_TO_TARGET_MULTIPLY;
const float GAIN_REQUEST_PC_SIDE_MULTIPLY = PC_TO_TARGET_MULTIPLY;

const float GAIN_OFFSET_PC_DEVIDE = TARGET_TO_PC_DEVIDE;
const float GAIN_OFFSET_PC_MULTIPLY = PC_TO_TARGET_MULTIPLY;

const DEVIATION_DIGITS = 4;
const GAIN_DIGITS = 4;

const RF_AFC_SLOPE_DENOMINATOR = 4096;      //denominator


// TX_Level

const RF_RAMP_TABLE_TX_LEVEL_COUNT=16;

const RF_RAMP_TABLE_RAMP_COUNT=16;
const RF_RAMP_RANGE_COUNT =4;
const RF_RAMP_UP_INDEX = 0;
const RF_RAMP_DOWN_INDEX = 1;
const RF_RAMP_GSM_LOWEST_POWER = 5;
const RF_RAMP_DCS_PCS_LOWEST_POWER = 0;




const RF_PM_MAX_TEST_SAMPLES = 2000;

const MIDI_BUF_SIZE= 2100;

const MAX_GROUP_NUM_IN_FDM = 20;  // MAX group num in FDM
const MAX_ELEMENT_NUM_IN_GROUP = 60; // MAX element num in a group

const MEAT_MAX_GROUP_NAME_LEN = 100;
const META_MAX_ELEMENT_NAME_LEN = 200;
const META_MAX_REC_NAME_LEN = 200;

const char CH_SEP = '\0';

const META_FIR_COEFF_INPUT_ELEMENT_COUNT = 30;
const META_FIR_COEFF_OUTPUT_ELEMENT_COUNT = 30;
const META_FIR_COEFF_ELEMENT_COUNT = META_FIR_COEFF_INPUT_ELEMENT_COUNT +
                                     META_FIR_COEFF_OUTPUT_ELEMENT_COUNT ;

const FDM_DATA_VALID    = 0;
const FDM_DATA_INVALID  = 1;
const FDM_WRITE_SUCCESS = 0;
const FDM_WRITE_FAIL    = 1;
const FDM_READ_SUCCESS = 0; // added by Andy Ueng
const FDM_READ_FAIL    = 1; // added by Andy Ueng
const FDM_RESET_SUCCESS = 0;
const FDM_RESET_FAIL = 0;

const  RAW_DATA_START_COL = 1;
const  RAW_DATA_START_ROW = 1;
const  RAW_DATA_COL_COUNTS = 8;  // 8 col raw data in a row.
const  RAW_DATA_BUF_LEN = 2000;

const MAX_GROUP_NAME_LEN = 250;
const MAX_ELEMENT_NAME_LEN = 250;
const MAX_STRUCT_NAME_LEN = 250;
const MAX_FDM_REC_LEN = 1024*32;
const MAX_ELEMENT_IN_FDM = 300;


// META factory constant

// const int BAND_COUNT = 5;
const char DEFAULT_SEP_CHAR = ',';

const int MF_RF_LAST_ELEMENT = RF_RX_LOSS_END_OF_TABLE;
// const int MF_RF_GAIN_TO_BE_SUB = -40;
const int MF_RF_GAIN_TO_BE_SUB = -35;
// const int MF_RF_PATH_LOSS_COUNT = 12;






#endif
