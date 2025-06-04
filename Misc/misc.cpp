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
 *   misc.cpp
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
 * $Revision:   1.11  $
 * $Modtime:   Oct 25 2005 12:24:26  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/misc.cpp-arc  $
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
 *    Rev 1.11   Oct 25 2005 14:15:30   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.10   Sep 04 2005 11:07:06   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.9   Apr 18 2005 15:49:24   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.8   Jan 30 2005 17:58:16   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.7   Jan 10 2005 11:14:52   mtk00490
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
#pragma hdrstop

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif


#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif




//------------------------------------------------------------------------------
extern bool isBootTarget;

//---------------------------------------------------------------------------
static const short ARFCN_RANGE[][4] =
{
    {   0, 124, 975, 1023 },  /* GSM900  */
    { 512, 885, 512,  885 },  /* DCS1800 */
    { 512, 810, 512,  810 },  /* PCS1900 */
    { 128, 251, 128,  251 },  /* GSM850  */
    { 259, 293, 259,  293 }   /* GSM450  */
};


static const int APC_LOWEST_POWER_RANGE[][2] =
{
    { 0, 36 },  /* GSM900  */
    { 0, 33 },  /* DCS1800 */
    { 0, 33 },  /* PCS1900 */
    { 0, 36 },  /* GSM850  */
    { 0, 36 }   /* GSM450  */
};

// convert
//---------------------------------------------------------------------------
bool IsValidDelay(AnsiString ansi_str, int &delay)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, delay), RANGE_ERR_DELAY);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidARFCNStep(AnsiString ansi_str, short &arfcn_step)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, arfcn_step), RANGE_ERR_ARFCN_STEP);
    RANGE_CHECK_ERROR(arfcn_step <= 0                             , RANGE_ERR_ARFCN_STEP);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidApcLowestPower(AnsiString ansi_str, int band, int &apc_lowest_power)
{
    bool invalid = true;
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, apc_lowest_power), RANGE_ERR_APC_LOWEST_POWER);
    if ((apc_lowest_power >= APC_LOWEST_POWER_RANGE[band][0]) && (apc_lowest_power<=APC_LOWEST_POWER_RANGE[band][1]))
    {
        invalid = false;
    }
    RANGE_CHECK_ERROR(invalid, RANGE_ERR_APC_LOWEST_POWER);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPMCount(AnsiString ansi_str, unsigned int &pmcount)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, pmcount, 1, 2147483647), RANGE_ERR_PM_COUNT);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAFCCount(AnsiString ansi_str, short &count)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, count, 1, 32767), RANGE_ERR_AFC_COUNT);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidGain(AnsiString ansi_str, int &gain)
{
    float f_gain;
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, f_gain), RANGE_ERR_GAIN);
    gain = (int) (f_gain*8);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPathLoss(AnsiString ansi_str, float &path_loss)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, path_loss), RANGE_ERR_PATH_LOSS);
    return true;
}

//----------------------------------------------------------------------------
bool IsValidRegBit(AnsiString ansi_str, unsigned char &bit)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, bit, 0, 1), RANGE_ERR_REG_BIT);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidMeasurementCount(AnsiString ansi_str, unsigned int &measuremnt_count)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, measuremnt_count, 1, 4294967295), RANGE_ERR_MEASUREMENT_COUNT);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPeriod(AnsiString ansi_str, unsigned int &period)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, period, 1000, 4294967295), RANGE_ERR_PERIOD);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidRefDetSlopeSkew(AnsiString ansi_str, char &skew)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, skew, -4, 7), RANGE_ERR_REFDET_SLOPE_SKEW);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAmFbDac(AnsiString ansi_str, char &dac)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, dac, -7, 7), RANGE_ERR_AM_FB_DAC);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPCL(AnsiString ansi_str, int band, int &pcl)
{
    static const int PCL_RANGE[][2] =
    {
        {4,  31},  /* GSM900  */
        {0,  28},  /* DCS1800 */
        {0,  15},  /* PCS1900 */
        {4,  31}  /* GSM850 */
    };

    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, pcl), RANGE_ERR_PCL);
    if (pcl != -1)
    {
        RANGE_CHECK_ERROR((pcl<PCL_RANGE[band][0])||(pcl>PCL_RANGE[band][1]) , RANGE_ERR_PCL );
    }

    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGPCL(AnsiString ansi_str, int band, int &pcl)
{
    static const int PCL_RANGE[][2] =
    {
        {4, 31},  /* GSM400 */
        {4, 31},  /* GSM850 */
        {4, 31},  /* GSM900  */
        {0, 28},  /* DCS1800 */
        {0, 15},  /* PCS1900 */
    };

    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, pcl)                , RANGE_ERR_CFG_PCL);
    RANGE_CHECK_ERROR((pcl<PCL_RANGE[band][0]) || (pcl>PCL_RANGE[band][1]) , RANGE_ERR_CFG_PCL);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGMAX_P(AnsiString ansi_str, double &d_max_p)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_max_p), RANGE_ERR_CFG_MAX_P);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGWANTED_P(AnsiString ansi_str, double &d_wanted_p)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_wanted_p), RANGE_ERR_CFG_WANTED_P);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGMIN_P(AnsiString ansi_str, double &d_min_p)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_min_p), RANGE_ERR_CFG_MIN_P);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGC(AnsiString ansi_str, double &d_c)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_c), RANGE_ERR_CFG_C);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGCORRECTION(AnsiString ansi_str, double &d_correction)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_correction), RANGE_ERR_CFG_CORRECTION);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGRecursiveTimes(AnsiString ansi_str, int &i_RecursiveTimes)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_RecursiveTimes), RANGE_ERR_RECURSIVE_TIMES);
    RANGE_CHECK_ERROR(i_RecursiveTimes<=-1                              , RANGE_ERR_RECURSIVE_TIMES);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGTSC(AnsiString ansi_str, char &c_TSC)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, c_TSC, 0, 7), RANGE_ERR_CFG_TSC);
    RANGE_CHECK_ERROR(c_TSC<=-1                                 , RANGE_ERR_CFG_TSC);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGAPCDelta(AnsiString ansi_str, double &d_APCDelta)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_APCDelta), RANGE_ERR_CFG_APC_DELTA);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPCLDac(AnsiString ansi_str, unsigned short &pcl_dac)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, pcl_dac, 0, 1023) , RANGE_ERR_PCL_DAC);
    return true;
}


//---------------------------------------------------------------------------
bool IsValidAFC(AnsiString ansi_str, short &afc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, afc, -1, 8191) , RANGE_ERR_AFC);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidFreqErr(AnsiString ansi_str, int &freq_err)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, freq_err, -30000, 30000), RANGE_ERR_FREQERR);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBand(AnsiString &band)
{
    AnsiString BAND_NAME[] =
    {
        "GSM",
        "DCS",
        "PCS",
        "GSM850"
    };

    for (int i=0; i<sizeof(BAND_NAME)/sizeof(BAND_NAME[0]); i++)
    {
        if (BAND_NAME[i].AnsiCompareIC(band) == 0)
        {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
bool IsValidCAPID63(AnsiString ansi_str, int &cap_id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, cap_id, 0, 63) , RANGE_ERR_CAPID);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCAPID127(AnsiString ansi_str, int &cap_id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, cap_id, 0, 127), RANGE_ERR_CAPID);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCAPID511(AnsiString ansi_str, int &cap_id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, cap_id, 0, 511), RANGE_ERR_CAPID);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidTA(AnsiString ansi_str, int &ta)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, ta, 0, 63), RANGE_ERR_TA);
    return true;
}

//---------------------------------------------------------------------------
//////////////////////////////      IP2      ////////////////////////////////
//---------------------------------------------------------------------------
bool IsValidSky74045Icorrection(AnsiString ansi_str, signed char &i_corr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, i_corr, -127, 127), RANGE_ERR_ICORRECTION);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidSky74045Qcorrection(AnsiString ansi_str, signed char &q_corr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, q_corr, -127, 127), RANGE_ERR_QCORRECTION);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidSky74117Icorrection(AnsiString ansi_str, signed char &i_corr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, i_corr, -63, 63), RANGE_ERR_ICORRECTION);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidSky74117Qcorrection(AnsiString ansi_str, signed char &q_corr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, q_corr, -63, 63), RANGE_ERR_QCORRECTION);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAcode(AnsiString ansi_str, unsigned char &acode)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, acode, 0, 63), RANGE_ERR_ACODE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAmcode(AnsiString ansi_str, unsigned char &amcode)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, amcode, 0, 255), RANGE_ERR_AMCODE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAmcode127(AnsiString ansi_str, unsigned char &amcode)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, amcode, 0, 127), RANGE_ERR_AMCODE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBcode(AnsiString ansi_str, unsigned char &bcode)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, bcode, 0, 127), RANGE_ERR_BCODE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCcode(AnsiString ansi_str, unsigned char &ccode)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, ccode, 0, 127), RANGE_ERR_CCODE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidMultiSlotTxPattern(AnsiString ansi_str, unsigned short &pattern)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedBinary(ansi_str, pattern, 0, 65535), RANGE_ERR_MUTLISLOT_TX_PATTERN);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCTPattern(AnsiString ansi_str, unsigned short &pattern)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedBinary(ansi_str, pattern, 0, 65535), RANGE_ERR_CT_PATTERN);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3TA(AnsiString ansi_str, unsigned char &ta)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, ta, 0, 7), RANGE_ERR_C3TA);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3TB(AnsiString ansi_str, unsigned char &tb)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, tb, 0, 3), RANGE_ERR_C3TB);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3TC(AnsiString ansi_str, unsigned char &tc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, tc, 0, 3), RANGE_ERR_C3TC);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3TN(AnsiString ansi_str, unsigned char &tn)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, tn, 0, 63), RANGE_ERR_C3TN);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3TO(AnsiString ansi_str, unsigned char &to)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, to, 0, 15), RANGE_ERR_C3TO);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidC3PM(AnsiString ansi_str, unsigned char &pm)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, pm, 0, 15), RANGE_ERR_C3PM);
    return true;
}

//---------------------------------------------------------------------------
bool IsValid2GAFCSlope(AnsiString ansi_str, double &slope)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, slope), RANGE_ERR_AFC_SLOPE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGAFCSlope(AnsiString ansi_str, double &slope)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, slope), RANGE_ERR_CFG_AFC_SLOPE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGFrequencyErrorPPM(AnsiString ansi_str, double &ppm)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, ppm), RANGE_ERR_CFG_FREQUENCY_ERROR_PPM);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCFGFrequencyError(AnsiString ansi_str, double &freq_err)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, freq_err), RANGE_ERR_CFG_FREQUENCY_ERROR);
    return true;
}

//==============================================================================
//////////////////////////////  BB TX Parameters  //////////////////////////////
//==============================================================================
//---------------------------------------------------------------------------
bool IsValidTrimIQ(AnsiString ansi_str, signed char &trim_iq)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, trim_iq, -8, 7) , RANGE_ERR_TRIM_IQ);
    return true;
}

//---------------------------------------------------------------------------
bool  IsValidTrimIQStep(AnsiString ansi_str, char &trim_iq_step)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, trim_iq_step, 1, 15) , RANGE_ERR_TRIM_IQ_STEP);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBBTXCalibratedFlag(AnsiString ansi_str, unsigned char &cal_flag)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, cal_flag, 0, 255), RANGE_ERR_BB_TX_CAL_FLAG );
    return true;
}

//---------------------------------------------------------------------------
bool IsValidOffsetIQStep(AnsiString ansi_str, char &off_iq_step)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, off_iq_step, 1, 63), RANGE_ERR_OFFSET_IQ_STEP);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidTxIQSwap(AnsiString ansi_str, char &iq_swap)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, iq_swap, 0, 1), RANGE_ERR_TX_IQSWAP);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBBTXCommonModeVoltage(AnsiString ansi_str, signed char &voltage)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, voltage, -4, 3), RANGE_ERR_BB_TX_COMMON_MODE_VOLTAGE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidBBTXGain(AnsiString ansi_str, signed char &gain)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, gain, -4, 3), RANGE_ERR_BB_TX_GAIN);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidBBTXCalrcsel(AnsiString ansi_str, signed char &Calrcsel)
{
    RANGE_CHECK_ERROR(!AnsiString_To_signedchar(ansi_str, Calrcsel, -4, 3), RANGE_ERR_CALRCSEL);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidBBTXPhaseselStep(AnsiString ansi_str, char &Phasesel_step)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, Phasesel_step, 1, 11), RANGE_ERR_PHASESEL_STEP);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidAPCBatLowVoltage(AnsiString ansi_str, double &voltage)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, voltage, 0, 10.0), RANGE_ERR_APC_BAT_LOW_VOLTAGE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidAPCBatHighVoltage(AnsiString ansi_str, double &voltage)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, voltage, 0, 10.0), RANGE_ERR_APC_BAT_HIGH_VOLTAGE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidAPCBatLowTemperature(AnsiString ansi_str, double &temperature)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, temperature, -50.0, 100.0), RANGE_ERR_APC_BAT_LOW_TEMPERATURE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidAPCBatHighTemperature(AnsiString ansi_str, double &temperature)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, temperature, -50.0, 100.0), RANGE_ERR_APC_BAT_HIGH_TEMPERATURE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidRamp(AnsiString ansi_str, unsigned char &ramp)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, ramp, 0, 255), RANGE_ERR_RAMP);
    return true;
}

//==============================================================================
bool IsValidGPIBAddr(AnsiString ansi_str, int &GPIB_addr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, GPIB_addr) , RANGE_ERR_GPIB_ADDR);
    RANGE_CHECK_ERROR(GPIB_addr<=-1                               , RANGE_ERR_GPIB_ADDR);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidTimeout(AnsiString ansi_str, int &timeout )
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, timeout), RANGE_ERR_TIMEOUT);
    RANGE_CHECK_ERROR(timeout<=-1                              , RANGE_ERR_TIMEOUT);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidCableLoss(AnsiString ansi_str, double &cable_loss)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, cable_loss), RANGE_ERR_CABLE_LOSS);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidPower(AnsiString ansi_str, double &power)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, power), RANGE_ERR_POWER);
    return true;
}

//==============================================================================
////////////////////////////// RX path loss CFG  ///////////////////////////////
//==============================================================================
bool IsValidCFGPMCount(AnsiString ansi_str, char m_pm, short &n_pm)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, n_pm), RANGE_ERR_CFG_PMCOUNT);
    if (n_pm * m_pm > 2000)
    {
        return false;
    }
    return true;
}

//==============================================================================
//////////////////////////// phase error CFG  //////////////////////////////////
//==============================================================================
bool IsValidPhaseError(AnsiString ansi_str, double &d_ph_err)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_ph_err), RANGE_ERR_PHASE_ERROR);
    return true;
}



//===========================================================================
static const int  pcl2power_table[][32] =
{
    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1
    {  39,39,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11, 9, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5  },  // GSM900
    {  30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,36,34,32  },  // DCS1800
    {  30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0,33,33,33,33,33,33,33,33,33,32  },  // PCS1900
    {  39,39,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11, 9, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5  },  // GSM850

};

//---------------------------------------------------------------------------
static const int  power2pcl_table[][32] =
{
    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8
    {  19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 2  },  // GSM900
    {  15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,31,30,29  },  // DCS1800
    {  15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,31,30,29  },  // PCS1900
    {  19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 2  },  // GSM850
};

//==============================================================================
bool IsValidRepeats(AnsiString ansi_str, int &repeats)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, repeats, 0, 255), RANGE_ERR_REPEATS);
    return true;
}

//==============================================================================
bool IsValidSpeakerVolume(AnsiString ansi_str, int &SpeakerVolume)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, SpeakerVolume, 0, 6), RANGE_ERR_SPEAKERVOLUME);
    return true;
}

//==============================================================================
bool IsValidBuzzerVolume(AnsiString ansi_str, int &BuzzerVolume)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, BuzzerVolume, 0, 7), RANGE_ERR_BUZZERVOLUME);
    return true;
}

//==============================================================================
bool IsValidVolume(AnsiString ansi_str, int &Volume)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, Volume, 0, 6), RANGE_ERR_VOLUME);
    return true;
}

//==============================================================================
bool IsValidInstrument(AnsiString ansi_str, int &Instrument)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, Instrument, 1, 128), RANGE_ERR_INSTRUMENT);
    return true;
}

//==============================================================================
bool getGPIBAddrNumFromStr(AnsiString as_str, int &i_gpib_addr_num)
{
    AnsiString as_gpib_addr_2;
    int iLD = as_str.AnsiPos("::");
    if (iLD <= 0)
        return false;

    as_gpib_addr_2 = as_str.SubString( iLD+2, as_str.Length() );
    iLD = as_gpib_addr_2.LastDelimiter("::");
    as_gpib_addr_2 =  as_gpib_addr_2.SubString( 1, iLD-2 );
    i_gpib_addr_num = as_gpib_addr_2.ToInt();
    return true;
}

//------------------------------------------------------------------------------
bool IsValidTxAfcOffset(AnsiString ansi_str, short &tx_afc_offset)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, tx_afc_offset, -65536, 65535), RANGE_ERR_TX_AFC_OFFSET);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidInterslotLowestDAC(AnsiString ansi_str, unsigned char &dac)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, dac, 0, 255), RANGE_ERR_INTERSLOT_LOWEST_DAC);
    return true;
}

//---------------------------------------------------------------------------
////////////////////////////     BV        //////////////////////////////////
//---------------------------------------------------------------------------
bool IsValidBVAP(AnsiString ansi_str, int &i_ap)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_ap, 0, 7), RANGE_ERR_BV_AP);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVAS(AnsiString ansi_str, int &i_as)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_as, 0, 7), RANGE_ERR_BV_AS);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVAO(AnsiString ansi_str, int &i_ao)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_ao, 0, 63), RANGE_ERR_BV_AO);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVBD(AnsiString ansi_str, int &i_bd)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_bd, 0, 31), RANGE_ERR_BV_BD);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVKAG(AnsiString ansi_str, int &i_kag)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_kag, 0, 31), RANGE_ERR_BV_KAG);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVKSG(AnsiString ansi_str, int &i_ksg)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_ksg, 0, 15), RANGE_ERR_BV_KSG);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVKAD(AnsiString ansi_str, int &i_kad)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_kad, 0, 31), RANGE_ERR_BV_KAD);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVKSD(AnsiString ansi_str, int &i_ksd)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_ksd, 0, 15), RANGE_ERR_BV_KSD);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVVRE(AnsiString ansi_str, int &i_vre)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_vre, 0, 1), RANGE_ERR_BV_VRE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVVOF(AnsiString ansi_str, int &i_vof)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_vof, 0, 127), RANGE_ERR_BV_VOF);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVARE(AnsiString ansi_str, int &i_are)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_are, 0, 1), RANGE_ERR_BV_ARE);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidBVAOF(AnsiString ansi_str, int &i_aof)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, i_aof, 0, 127), RANGE_ERR_BV_AOF);
    return true;
}


//==============================================================================
//////////////////////////////////   CTS   /////////////////////////////////////
//==============================================================================
//------------------------------------------------------------------------------
bool IsValidCTSTemperature(AnsiString ansi_str, float &temperature)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, temperature, -20.0, 70.0), RANGE_ERR_CTS_TEMPERATURE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidCTSTemperatureStep(AnsiString ansi_str, float &temperature_step)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, temperature_step, 0.1, 90.0), RANGE_ERR_CTS_TEMPERATURE_STEP);
    return true;
}

//==============================================================================
///////////////////////////////   register   ///////////////////////////////////
//==============================================================================
bool IsValidHexBsiAddr(AnsiString ansi_str, unsigned int *bsi_addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, bsi_addr), RANGE_ERR_REG_ADDR);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidDecBsiAddr(AnsiString ansi_str, unsigned int &bsi_addr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, bsi_addr, 1, 4294967295), RANGE_ERR_REG_ADDR);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidHexBsiData(AnsiString ansi_str, unsigned int *bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, bsi_data), RANGE_ERR_REG_VALUE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidDecBsiData(AnsiString ansi_str, unsigned int &bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, bsi_data, 1, 4294967295), RANGE_ERR_REG_VALUE);
    return true;
}
//GSensor
bool IsValidDecGSensorData(AnsiString ansi_str, int &bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, bsi_data), RANGE_ERR_REG_VALUE);
    return true;
}

bool IsValidDecGYROSensorData(AnsiString ansi_str, int &bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, bsi_data), RANGE_ERR_REG_VALUE);
    return true;
}

//for dvb
bool IsValidDecDVBData(AnsiString ansi_str, unsigned int &bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, bsi_data, 0, 4294967295), 0);
    return true;
}

bool IsValidHexDVBData(AnsiString ansi_str, unsigned int *bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, bsi_data), 0);
    return true;
}

//for wifi
bool IsValidDecWIFIData(AnsiString ansi_str, unsigned int &bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, bsi_data, 0, 4294967295), 0);
    return true;
}

bool IsValidHexWIFIData(AnsiString ansi_str, unsigned int *bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, bsi_data), 0);
    return true;
}

bool IsValidIntWIFIData(AnsiString ansi_str, int &slope)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, slope), RANGE_ERR_ADC_SLOPE);
    return true;
}


bool IsValidDoubleWIFIData(AnsiString ansi_str, double &slope)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, slope), RANGE_ERR_WIFI_TX_POWER_DAC);
    return true;
}

//for uuid
bool IsValidUUID(AnsiString ansi_str,unsigned char &uuid_data)
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar( ansi_str, uuid_data, 0, 15  ) , RANGE_ERR_UUID_VALUE );

    return true;
}

extern bool IsValidHexBTAddr(AnsiString ansi_str, unsigned int *addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, addr), RANGE_ERR_REG_ADDR);
    return true;

}

bool IsValidHexNFCData(AnsiString ansi_str, unsigned int *bsi_data)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, bsi_data), 0);
    return true;
}

bool IsValidGUIDUnsignedLong(AnsiString ansi_str, unsigned long *value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedLong(ansi_str, *value), 0);
    return true;
}

bool IsValidGUIDUnsignedShort(AnsiString ansi_str, unsigned short &value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedShort(ansi_str, value), 0);
    return true;
}

bool IsValidGUIDUnsignedChar(AnsiString ansi_str, unsigned char &value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, value), 0);
    return true;
}
