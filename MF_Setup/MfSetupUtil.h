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
 *   MfSetupUtil.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MF_Setup.txt file handler header
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
 * $Modtime:   Oct 25 2005 12:21:42  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/MF_Setup/MfSetupUtil.h-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
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
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 * May 17 2006 mtk00490
 * [STP100000868] [META] META ver 3.7.05
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:24   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:07:00   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:20   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:58:10   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:14:44   mtk00490
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
#ifndef  _MFSETUPUTIL_H_
#define  _MFSETUPUTIL_H_

#include <vcl.h>
#include <inifiles.hpp>

#include "meta_utils.h"

/*---------------------------------------------------------------------------*/
AnsiString read_field(AnsiString asSetupFile,AnsiString asExeName, AnsiString asSecName, AnsiString asFieldName, AnsiString asDefStr);
void write_field(AnsiString asSetupFile, AnsiString asExeName, AnsiString asSecName, AnsiString asFieldName, AnsiString asStr);


AnsiString read_DELAY_TIME_BEFORE_ACCESS_NVRAM( AnsiString asSetupFile, AnsiString asExeName);
/*---------------------------------------------------------------------------*/
// main menu
extern AnsiString read_Menu_selection( AnsiString asSetupFile, AnsiString asExeName );
extern void write_Menu_selection( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_MenuSel );
extern AnsiString read_LogPath(AnsiString asSetupFile,AnsiString asExeName);
/*---------------------------------------------------------------------------*/
//AnsiString read_GSM850_support(AnsiString asSetupFile,AnsiString asExeName);
//void write_GSM850_support( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_GSM850_support );
/*---------------------------------------------------------------------------*/
AnsiString read_COM_PORT_SETTING( AnsiString asSetupFile, AnsiString asExeName );
void write_COM_PORT_SETTING( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Com );
/*---------------------------------------------------------------------------*/
AnsiString read_Baseband_chip(AnsiString asSetupFile,AnsiString asExeName);
void write_Baseband_chip(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Baseband_chip);
/*---------------------------------------------------------------------------*/
//AnsiString read_Clock_rate(AnsiString asSetupFile,AnsiString asExeName);
//void write_Clock_rate(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Clock_rate);
/*---------------------------------------------------------------------------*/
//AnsiString read_Flow_control(AnsiString asSetupFile,AnsiString asExeName);
//void write_Flow_control(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Flow_control);
/*---------------------------------------------------------------------------*/
//extern AnsiString read_TstMessageFormat(AnsiString asSetupFile,AnsiString asExeName);
//extern void write_TstMessageFormat(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TstMessageFormat);
/*---------------------------------------------------------------------------*/
AnsiString read_Sync_with_target_support(AnsiString asSetupFile,AnsiString asExeName);
void write_Sync_with_target_support(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Syn_with_target);
/*---------------------------------------------------------------------------*/
AnsiString read_Auto_control_power_supply(AnsiString asSetupFile,AnsiString asExeName);
//void write_Auto_control_power_supply(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Auto_control_power_supply);
/*---------------------------------------------------------------------------*/
AnsiString read_Baudrate(AnsiString asSetupFile,AnsiString asExeName);
void write_Baudrate(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Baudrate);
/*---------------------------------------------------------------------------*/
AnsiString read_Disable_HW_flow_control(AnsiString asSetupFile,AnsiString asExeName);
void write_Disable_HW_flow_control(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Disable_HW_flow_control);
/*---------------------------------------------------------------------------*/
AnsiString read_Boot_timeout(AnsiString asSetupFile,AnsiString asExeName);
void write_Boot_timeout(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Boot_timeout);
/*---------------------------------------------------------------------------*/
extern AnsiString read_META_Connect_timeout(AnsiString asSetupFile,AnsiString asExeName);
extern void write_META_Connect_timeout(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_METAConnectTimeout);
/*---------------------------------------------------------------------------*/
extern AnsiString read_PowerSupplyOnCount(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_PowerSupplyOffCount(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_PowerSupplyTriggerTime(AnsiString asSetupFile,AnsiString asExeName);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AuthenticationFile(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AuthenticationFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AuthenticationFile);
/*---------------------------------------------------------------------------*/
extern AnsiString read_Com_Port_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_GUID(AnsiString asSetupFile,AnsiString asExeName);

/*---------------------------------------------------------------------------*/
extern AnsiString read_CertificateFile(AnsiString asSetupFile,AnsiString asExeName);
extern void write_CertificateFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CertificateFile);
extern AnsiString read_BROM_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Preloader_Single_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Kernel_Single_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Kernel_Composite_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_FirstStage_Timeout(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_SecondStage_Timeout(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_SecondStage_Delay(AnsiString asSetupFile,AnsiString asExeName);


//Qin Qin 20120711
extern AnsiString read_Preloader_Composite_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_DeviceType(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Kernel_Filter_Count(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Kernel_Filter_Type(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Kernel_Filter_PIDVID(AnsiString asSetupFile,AnsiString asExeName);
//
//20150421
extern AnsiString read_Query_WCNDriver_Ready(AnsiString asSetupFile,AnsiString asExeName);

//====================================================================================
// Audio
extern AnsiString read_AcousticFirDirection(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AcousticFirDirection(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AcousticFirDirection);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AcousticFirBoundary(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AcousticFirBoundary(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AcousticFirBoundary);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AcousticFirEquipment(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AcousticFirEquipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AcousticFirEquipment);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AcousticFirFileFormat(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AcousticFirFileFormat(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AcousticFirFileFormat);
/*---------------------------------------------------------------------------*/

extern AnsiString read_AcousticFirBoundaryFile(AnsiString asSetupFile,AnsiString asExeName);
extern void write_AcousticFirBoundaryFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
// AEC
extern AnsiString read_AECNvramDB(AnsiString asSetupFile, AnsiString asExeName);
extern void write_AECNvramDB(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AECInitialSettingFile(AnsiString asSetupFile, AnsiString asExeName);
extern void write_AECInitialSettingFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AECAudcoffDefaultH(AnsiString asSetupFile, AnsiString asExeName);
extern void write_AECAudcoffDefaultH(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AECOutputSpeechFirFile(AnsiString asSetupFile, AnsiString asExeName);
extern void write_AECOutputSpeechFirFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
/*---------------------------------------------------------------------------*/
extern AnsiString read_AECVolumeGainFile(AnsiString asSetupFile, AnsiString asExeName);
extern void write_AECVolumeGainFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);

//==============================================================================
// META factory
// setup files
/*---------------------------------------------------------------------------*/
extern  AnsiString read_NVRAM_DATABASE_FILE(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_NVRAM_DATABASE_FILE(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_NVRAM_DATABASE_FILE);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_ConfigurationFile(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_ConfigurationFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ConfigurationFile);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_LoggingFile(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_LoggingFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_LogFile);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_ResultFile(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_ResultFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResFile);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_InitialFile(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_InitialFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResFile);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_ResultPath(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_ResultPath(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResPath);


/*---------------------------------------------------------------------------*/
extern  AnsiString read_Initial_value_from(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Initial_value_from(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Initial_value_from);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_RF_calibration(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_RF_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RF_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_AFC_Type(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_AFC_Type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AFC_Type);
/*---------------------------------------------------------------------------*/
extern AnsiString read_Crystal_CAP_ID(AnsiString asSetupFile,AnsiString asExeName);
extern void write_Crystal_CAP_ID(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Crystal_CAP_ID);
/*---------------------------------------------------------------------------*/
extern AnsiString read_CapIdCal(AnsiString asSetupFile,AnsiString asExeName);
extern void write_CapIdCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CapIdCal);
/*---------------------------------------------------------------------------*/
extern AnsiString read_TxAfcOffsetCal(AnsiString asSetupFile,AnsiString asExeName);
extern void write_TxAfcOffsetCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxFrequencyError);
/*---------------------------------------------------------------------------*/
extern AnsiString read_ResetRfTester(AnsiString asSetupFile,AnsiString asExeName);
extern void write_ResetRfTester(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxAfcOffsetCal);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_AFC(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_AFC(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AFC);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_RxPathLoss(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_RxPathLoss(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RxPathLoss);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxIqCal(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxIqCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxIqCal);
extern  AnsiString read_IP2(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IP2(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IP2);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxDcOffset(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxDcOffset(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxDcOffset);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxFbDac(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxFbDac(AnsiString asSetupFile, AnsiString asExeName, AnsiString as);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxPcl(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxPcl(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxPcl);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxSlowSkewCal(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxSlowSkewCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TxPhaseErr(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TxPhaseErr(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxPhaseErr);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_ADC_calibration(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_ADC_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ADC_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_CV_calibration(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_CV_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CV_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_WiFiTxDcOffset_calibration(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_WiFiTxDcOffset_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_WiFiTxDcOffset_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_WiFiTxPower_calibration(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_WiFiTxPower_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_WiFiTxPower_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_BTCrystalCAPID_calibration(AnsiString asSetupFile, AnsiString asExeName);
extern  void write_BTCrystalCAPID_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_BTCrystalCAPID_calibration);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_GMSK_TX_PCL_type(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_GMSK_TX_PCL_type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TX_PCL_type);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_EPSK_TX_PCL_type(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_EPSK_TX_PCL_type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TX_PCL_type);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_PAType(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_PAType(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_PAType);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_PABiasType(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_PABiasType(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_PABiasType);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_APC_GMSK_Modulation(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_APC_GMSK_Modulation(AnsiString asSetupFile,AnsiString asExeName, AnsiString as_APC_GMSK_Mod);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_APC_EPSK_Modulation(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_APC_EPSK_Modulation(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_APC_EPSK_Mod);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Sky77328_APC_DC_Offset_cal(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Sky77328_APC_DC_Offset_cal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Sky77328_APC_DC_Offset_cal);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_RF_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_RF_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RF_calibration_equipment);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_WiFi_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_WiFi_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_equipment);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_BT_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_BT_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_equipment);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_661x_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName );
extern  void write_661x_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_663x2_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName );
extern  void write_663x2_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_E3631A_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName );
extern  void write_E3631A_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Keithley2306_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName );
extern  void write_Keithley2306_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Power_Supply_Type(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Power_Supply_Type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_Type);
/*---------------------------------------------------------------------------*/
// enter
extern  AnsiString read_Read_barcode_from_enter(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Read_barcode_from_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Read_barcode_from_enter);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Barcode_increasement_enter(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Barcode_increasement_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_enter);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Auto_start_calibration_enter(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Auto_start_calibration_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Auto_start_calibration_enter);
/*---------------------------------------------------------------------------*/
// exit
extern  AnsiString read_Save_barcode_to_NVRAM_exit(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_NVRAM_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_NVRAM_exit);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Save_barcode_to_file_exit(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_file_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_file_exit);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Barcode_increasement_exit(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Barcode_increasement_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_exit);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Terminate_META_exit(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Terminate_META_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Terminate_META_exit);
/*---------------------------------------------------------------------------*/

// calibration success
extern  AnsiString read_Save_barcode_to_NVRAM_success(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_NVRAM_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_NVRAM_success);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Save_barcode_to_file_success(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_file_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_file_success);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Barcode_increasement_success(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Barcode_increasement_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_whensuccess);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TurnOffPowerSupplySuccess(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TurnOffPowerSupplySuccess(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TurnOffPowerSupplySuccess);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TerminateMETASuccess(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TerminateMETASuccess(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TerminateMETASuccess);
/*---------------------------------------------------------------------------*/
// calibration fail
extern  AnsiString read_Save_barcode_to_NVRAM_fail(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_NVRAM_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_NVRAM_fail);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Save_barcode_to_file_fail(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Save_barcode_to_file_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_save_Barcode_to_file_fail);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_Barcode_increasement_fail(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_Barcode_increasement_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_fail);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TurnOffPowerSupplyFail(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TurnOffPowerSupplyFail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TurnOffPowerSupplyFail);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_TerminateMETAFail(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_TerminateMETAFail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TerminateMETAFail);
/*---------------------------------------------------------------------------*/
// IMEI
extern  AnsiString read_IMEI_read_from(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IMEI_read_from(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_read_from);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_IMEI_save_to(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IMEI_save_to(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_save_to);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_IMEI_increasement(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IMEI_increasement(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_increasement);
/*---------------------------------------------------------------------------*/
extern  void write_Barcode(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode);
extern  AnsiString read_Barcode(AnsiString asSetupFile,AnsiString asExeName);
/*---------------------------------------------------------------------------*/
extern  AnsiString read_IMEI(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IMEI(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_without_CheckSum);
/*---------------------------------------------------------------------------*/


//=================================================================================
// power table
//extern  int read_NORMAL_VOLTAGE( AnsiString asSetupFile, AnsiString asExeName );
//extern  int read_CURRENT_LIMIT( AnsiString asSetupFile, AnsiString asExeName );
//extern  int read_OFF_VOLTAGE( AnsiString asSetupFile, AnsiString asExeName );

//===========================================================================================
// IMEI download
extern  AnsiString read_IMEI_NVRAM_DATABASE_FILE(AnsiString asSetupFile,AnsiString asExeName);
extern  void write_IMEI_NVRAM_DATABASE_FILE(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_NVRAM_DATABASE_FILE);

//==============================================================================
// BT tool
extern AnsiString read_HCI_File( AnsiString asSetupFile,AnsiString asExeName);
extern void write_HCI_File(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_HCI_file );


//Console Mode
extern AnsiString read_Console_ConnectType(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_ComFindType(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_PreloaderComPort(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_KernelComPort(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_NvramDBPath(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_ModifyCount(AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_ModifyLID(int id,AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_ModifyVariable(int id,AnsiString asSetupFile,AnsiString asExeName);
extern AnsiString read_Console_ModifyValue(int id,AnsiString asSetupFile,AnsiString asExeName);


//NVRAN backup restore timeout
extern AnsiString read_NVRAMBackupRestoreTimeout(AnsiString asSetupFile,AnsiString asExeName);
#endif
