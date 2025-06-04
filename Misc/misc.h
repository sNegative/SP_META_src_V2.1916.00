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
 *   misc.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Misc. function source
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
 * $Modtime:   Oct 25 2005 12:24:40  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/misc.h-arc  $
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
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
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:32   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:07:08   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:24   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:58:18   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MISC_H_
#define  _MISC_H_
/*---------------------------------------------------------------------------*/

//#include "visatype.h"
/*---------------------------------------------------------------------------*/
// GPIB
extern  bool getGPIBAddrNumFromStr(AnsiString as_str, int &i_gpib_addr_num);
/*---------------------------------------------------------------------------*/
// check
// convert
extern bool  IsValidDelay(AnsiString ansi_str, int &delay);

// IP2
extern bool  IsValidSky74045Icorrection(AnsiString ansi_str, signed char &i_corr);
extern bool  IsValidSky74045Qcorrection(AnsiString ansi_str, signed char &q_corr);
extern bool  IsValidSky74117Icorrection(AnsiString ansi_str, signed char &i_corr);
extern bool  IsValidSky74117Qcorrection(AnsiString ansi_str, signed char &q_corr);
extern bool  IsValidAcode(AnsiString ansi_str, unsigned char &acode);
extern bool  IsValidAmcode(AnsiString ansi_str, unsigned char &amcode);
extern bool  IsValidAmcode127(AnsiString ansi_str, unsigned char &amcode);
extern bool  IsValidBcode(AnsiString ansi_str, unsigned char &bcode);
extern bool  IsValidCcode(AnsiString ansi_str, unsigned char &ccode);
// Multi slot TX
extern bool  IsValidMultiSlotTxPattern(AnsiString ansi_str, unsigned short &pattern);

// CT
extern bool  IsValidCTPattern(AnsiString ansi_str, unsigned short &pattern);
// Renesas C3 register
extern bool  IsValidC3TA(AnsiString ansi_str, unsigned char &ta);
extern bool  IsValidC3TB(AnsiString ansi_str, unsigned char &tb);
extern bool  IsValidC3TC(AnsiString ansi_str, unsigned char &tc);
extern bool  IsValidC3TN(AnsiString ansi_str, unsigned char &tn);
extern bool  IsValidC3TO(AnsiString ansi_str, unsigned char &to);
extern bool  IsValidC3PM(AnsiString ansi_str, unsigned char &pm);
// ramp profile
extern bool  IsValidRamp(AnsiString ansi_str, unsigned char &ramp);

// BB TX parameters
extern bool  IsValidTrimIQ(AnsiString ansi_str, signed char &trim_iq);
extern bool  IsValidTrimIQStep(AnsiString ansi_str, char &trim_iq_step);
extern bool  IsValidBBTXCalibratedFlag(AnsiString ansi_str, unsigned char &cal_flag);
extern bool  IsValidOffsetIQStep(AnsiString ansi_str, char &off_iq_step);
extern bool  IsValidTxIQSwap(AnsiString ansi_str, char &iq_swap);
extern bool  IsValidBBTXCommonModeVoltage(AnsiString ansi_str, signed char &voltage);
extern bool  IsValidBBTXGain(AnsiString ansi_str, signed char &gain);
extern bool  IsValidBBTXCalrcsel(AnsiString ansi_str, signed char &Calrcsel);
extern bool  IsValidBBTXPhaseselStep(AnsiString ansi_str, char &Phasesel_step);
extern bool  IsValidAPCBatLowVoltage(AnsiString ansi_str, double &voltage);
extern bool  IsValidAPCBatHighVoltage(AnsiString ansi_str, double  &voltage);
extern bool  IsValidAPCBatLowTemperature(AnsiString ansi_str, double  &temperature);
extern bool  IsValidAPCBatHighTemperature(AnsiString ansi_str, double &temperature);

// common CFG
extern bool  IsValidGPIBAddr(AnsiString ansi_str, int &GPIB_addr);
extern bool  IsValidTimeout(AnsiString ansi_str, int &timeout);
extern bool  IsValidCableLoss(AnsiString ansi_str, double &cable_loss);
extern bool  IsValidPower(AnsiString ansi_str, double &power);

// AFC CFG
extern bool  IsValidCFGFrequencyErrorPPM(AnsiString ansi_str, double &ppm);
extern bool  IsValidCFGFrequencyError(AnsiString ansi_str, double &freq_err);

// RX path loss CFG
extern bool  IsValidCFGPMCount(AnsiString ansi_str, char m_pm, short &n_pm);

// phase error CFG
extern bool  IsValidPhaseError(AnsiString ansi_str, double &d_ph_err);

// Battery compensate
extern bool IsValidBatteryCompensate(AnsiString ansi_str, unsigned short &battery_compensate);
// BV
extern bool  IsValidBVAP(AnsiString ansi_str, int &i_ap);
extern bool  IsValidBVAS(AnsiString ansi_str, int &i_as);
extern bool  IsValidBVAO(AnsiString ansi_str, int &i_ao);
extern bool  IsValidBVBD(AnsiString ansi_str, int &i_bd);
extern bool  IsValidBVKAG(AnsiString ansi_str, int &i_kag);
extern bool  IsValidBVKSG(AnsiString ansi_str, int &i_ksg);
extern bool  IsValidBVKAD(AnsiString ansi_str, int &i_kad);
extern bool  IsValidBVKSD(AnsiString ansi_str, int &i_ksd);
extern bool  IsValidBVVRE(AnsiString ansi_str, int &i_vre);
extern bool  IsValidBVVOF(AnsiString ansi_str, int &i_vof);
extern bool  IsValidBVARE(AnsiString ansi_str, int &i_are);
extern bool  IsValidBVAOF(AnsiString ansi_str, int &i_aof);
// crystal
extern bool  IsValidTxAfcOffset(AnsiString ansi_str, short &tx_afc_offset);
extern bool  IsValidCTSTemperature(AnsiString ansi_str, float &temperature);
extern bool  IsValidCTSTemperatureStep(AnsiString ansi_str, float &temperature_step);
// inter slot
extern bool IsValidInterslotLowestDAC(AnsiString ansi_str, unsigned char &dac);
// register
extern bool  IsValidHexBsiAddr(AnsiString ansi_str, unsigned int &bsi_addr);
extern bool  IsValidDecBsiAddr(AnsiString ansi_str, unsigned int &bsi_addr);
extern bool  IsValidHexBsiData(AnsiString ansi_str, unsigned int &bsi_data);
extern bool  IsValidDecBsiData(AnsiString ansi_str, unsigned int &bsi_data);
extern bool IsValidDecGSensorData(AnsiString ansi_str, int &bsi_data);
extern bool IsValidDecGYROSensorData(AnsiString ansi_str, int &bsi_data);
//dvb
extern bool IsValidDecDVBData(AnsiString ansi_str, unsigned int &bsi_data);
extern bool IsValidHexDVBData(AnsiString ansi_str, unsigned int *bsi_data);

//wifi
extern bool IsValidDecWIFIData(AnsiString ansi_str, unsigned int &bsi_data);
extern bool IsValidHexWIFIData(AnsiString ansi_str, unsigned int *bsi_data);
extern bool IsValidIntWIFIData(AnsiString ansi_str, int &slope);
extern bool IsValidDoubleWIFIData(AnsiString ansi_str, double &slope);

//UUID
extern bool IsValidUUID(AnsiString ansi_str,unsigned char &uuid_data);

extern bool IsValidHexBTAddr(AnsiString ansi_str, unsigned int *addr);
extern bool IsValidHexNFCData(AnsiString ansi_str, unsigned int *bsi_data);
/*---------------------------------------------------------------------------*/

extern bool IsValidGUIDUnsignedLong(AnsiString ansi_str, unsigned long *value);
extern bool IsValidGUIDUnsignedShort(AnsiString ansi_str, unsigned short &value);
extern bool IsValidGUIDUnsignedChar(AnsiString ansi_str, unsigned char &value);



#endif