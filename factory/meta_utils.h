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
 *   META_utils.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  META utility header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.12  $
 * $Modtime:   Oct 25 2005 11:20:14  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/factory/meta_utils.h-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.12   Oct 25 2005 14:13:36   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.11   Sep 04 2005 11:02:10   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.10   Apr 18 2005 15:47:34   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.9   Jan 30 2005 17:54:34   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.8   Jan 10 2005 11:10:36   mtk00490
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

#ifndef  _META_UTILS_H_
#define  _META_UTILS_H_

#include <vcl.h>
#include <stdio.h>
#include "meta.h"

//-----------------------------------------------------------------------------
// format transform
extern  int Convert_PCL_to_dBm( FrequencyBand band, int txPower );    /* Power */
extern  int Convert_dBm_to_PCL( FrequencyBand band, int power );    /* PCL */
//-----------------------------------------------------------------------------
// extract from AnsiString
extern  bool getAnsiStrSubItem( const AnsiString as_Src, const int index,
                                const char cSep, AnsiString &as_SubStr);
extern  bool getPathFromStr( AnsiString asStr, AnsiString &asPath );
extern  bool getDriveFromStr( AnsiString asStr, AnsiString &asDrive );
extern  bool getDriveLetterFromStr( AnsiString asStr, AnsiString &asDriveLetter );
extern  bool getFilenameFromStr( AnsiString asStr, AnsiString &asFileName );
extern  bool getIntegrityFromStr( AnsiString asStr, AnsiString &asIntegrity );
extern  bool getEpskIntegrityFromStr( AnsiString asStr, AnsiString &asIntegrity );
extern  bool getTxPowerFromStr( AnsiString asStr, AnsiString &asTxPower );
extern  bool getEpskTxPowerFromStr( AnsiString asStr, AnsiString &asTxPower );
extern  bool getBaseFromStr( AnsiString asStr, AnsiString &asBase );
extern  bool getEpskBaseFromStr( AnsiString asStr, AnsiString &asBase );
extern  bool getExponentFromStr( AnsiString asStr, AnsiString &asExponent );
extern  bool getEpskExponentFromStr( AnsiString asStr, AnsiString &asExponent );
extern  bool getTaModelFromStr( AnsiString asStr, AnsiString &asTaModel );
extern  bool getBand_Range_from_AnsiStr(AnsiString as,
                                        AnsiString &as_Band,
                                        AnsiString &as_Range,
                                        AnsiString &as_up_down);
//-----------------------------------------------------------------------------
extern  bool withPath( AnsiString asPath );
extern  long filesize(FILE *stream);
extern  bool change_file_name(AnsiString &as_FileName);
extern  bool IsFreqBankSupported( AnsiString &asFreqBank, FrequencyBand fb);

extern  bool getCOMIndex( AnsiString asStr, int *COMIndex );
#endif

