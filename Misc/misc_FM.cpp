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
 *   misc_FM.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  FM radio Misc. function source
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
 * Dec 31 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <vcl.h>
#include <math.h>

#pragma hdrstop

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// FM
#ifndef  _FM_COMMON_H_
#include "fm_common.h"
#endif

//==============================================================================
//////////////////////////////   Format transform  /////////////////////////////
//==============================================================================
bool AnsiString_To_FM_Freq(AnsiString ansi_str, short& freq) // unit of freq: 0.1Mhz
{
    float freq_Mhz;
    float f_freq;
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, freq_Mhz), RANGE_ERR_FM_FREQ);
    f_freq = freq_Mhz * FM_FREQ_SCALE_100KHZ;
    freq = (short) f_freq;
    return true;
}

bool AnsiString_To_FM_Freq_50KHz(AnsiString ansi_str, short& freq) // unit of freq: 0.05Mhz
{
    float freq_Mhz;
    float f_freq;
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, freq_Mhz), RANGE_ERR_FM_FREQ);
    f_freq = freq_Mhz * FM_FREQ_SCALE_50KHZ;
    freq = (short) f_freq;
    return true;
}


//==============================================================================
//////////////////////////////      Range check    /////////////////////////////
//==============================================================================
bool IsValidFMFreq(AnsiString ansi_str, short& freq)
{
    double freq_Mhz;
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, freq_Mhz, FM_MIN_FREQ, FM_MAX_FREQ), RANGE_ERR_FM_FREQ);
    freq = (float)freq_Mhz * FM_FREQ_SCALE_100KHZ;

    return true;
}

bool IsValidFMFreqFor50KHz(AnsiString ansi_str, short& freq)
{
    double freq_Mhz;
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, freq_Mhz, FM_MIN_FREQ, FM_MAX_FREQ), RANGE_ERR_FM_FREQ);
    freq = (float)freq_Mhz * FM_FREQ_SCALE_50KHZ;

    return true;
}

//------------------------------------------------------------------------------
bool IsValidFMRssiThreshold(AnsiString ansi_str, unsigned int& threshold)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, threshold, FM_MIN_RSSI_THRESHOLD, FM_MAX_RSSI_THRESHOLD), RANGE_ERR_FM_RSSI_THRESHOLD);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidFMIfCounterDelta(AnsiString ansi_str, unsigned int& delta)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, delta, FM_MIN_IF_COUNTER_DELTA, FM_MAX_IF_COUNTER_DELTA), RANGE_ERR_FM_IF_COUNTER_DELTA);
    if (delta % FM_IF_COUNTER_DELTA_STEP)
    {
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
bool IsValidFMChannel(AnsiString ansi_str, short& channel)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, channel, 0, 1000), RANGE_ERR_FM_CHANNEL);
    return true;
}

