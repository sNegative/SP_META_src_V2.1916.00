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
 *   misc_audio.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Audio Misc. function source
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
 * Jun 16 2007 mtk00490
 * [STP100001440] [META] META ver 5.3.9
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Mar 14 2007 mtk00490
 * [STP100001335] [META] META ver 5.3.6.1
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
#include <vcl.h>

#pragma hdrstop


#include "man_error.h"

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _META_UTILS_H_
#include "meta_utils.h"
#endif

//---------------------------------------------------------------------------
bool IsValidFirTaps(AnsiString ansi_str, short &taps)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, taps, 1, 44) , RANGE_ERR_FIR_TAPS);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidWBFirTaps(AnsiString ansi_str, short &taps)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, taps, 1, 90) , RANGE_ERR_FIR_TAPS);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidFirCoef(AnsiString ansi_str, short &coef)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, coef, -32768, 32767), RANGE_ERR_FIR_COEF);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidTimeConst(AnsiString ansi_str, unsigned short &time_const)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, time_const, 0, 65535), RANGE_ERR_TIME_CONST);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidVolumeConst(AnsiString ansi_str, unsigned short &volume_const)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, volume_const, 0, 65535) , RANGE_ERR_VOLUME_CONST);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidMediaPlaybackMaximumSwing(AnsiString ansi_str, unsigned short &media_playback_max_swing)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, media_playback_max_swing, 0, 65535), RANGE_ERR_MEDIA_PLAYBACK_MAXIMUM_SWING);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidSpeechCommonParameter(AnsiString ansi_str, unsigned short &sc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, sc, 0, 65535), RANGE_ERR_SPEECH_COMMON_PARAMETER);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidSpeechModeDependentParameter(AnsiString ansi_str, unsigned short &smdp)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, smdp, 0, 65535), RANGE_ERR_SPEECH_MODE_DEPENDENT_PARAMETER);
    return true;
}

//---------------------------------------------------------------------------
bool IsValidAudioCompensation(AnsiString ansi_str, short &ac)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Short(ansi_str, ac, -32768, 32767), RANGE_ERR_FIR_COEF);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidFirScale(AnsiString ansi_str, float &FirScale)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, FirScale, 0.5, 1.0), RANGE_ERR_FIR_SCALE);
    return true;
}

//------------------------------------------------------------------------------
bool IsValidDigitalScale(AnsiString ansi_str, float &DigitalScale)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, DigitalScale, 0, 1.0), RANGE_ERR_DIGITAL_SCALE);
    return true;
}

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
bool getYfromStr( AnsiString asStr, double* p_Y )
{
    AnsiString asY;
    int iLD = asStr.LastDelimiter(" ");
    if (iLD <= 0)
        return false;

    asY = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}

//==============================================================================
int getMaxYBound( int max_y, int scale)
{
    int distance, min_distance = 100000, max_y_bound;

    for(int i=-100; i<100; i++)
    {
        distance = abs(i*scale - max_y);
        //if(i*scale > max_y && distance < min_distance)
        if(i*scale >= max_y && distance < min_distance)
        {
            min_distance = distance;
            max_y_bound = i*scale;
        }
    }
    return  max_y_bound;
}

//------------------------------------------------------------------------------
int  getMinYBound( int min_y, int scale)
{
    int distance, min_distance = 100000, min_y_bound;

    for(int i=-100; i<100; i++)
    {
        distance = abs(i*scale - min_y);
        if(i*scale < min_y && distance < min_distance)
        {
            min_distance = distance;
            min_y_bound = i*scale;
        }
    }
    return  min_y_bound;
}
//------------------------------------------------------------------------------
AnsiString getFullPathFileName( AnsiString as_filename )
{
    AnsiString as_path, as_full_filename;

    getPathFromStr( Application->ExeName, as_path);
    as_full_filename = as_path + as_filename;

    return  as_full_filename;
}
//---------------------------------------------------------------------------
bool getHzFromStr( AnsiString as_str, double &Hz)
{
    AnsiString as_Hz;
    int iLD = as_str.LastDelimiter(" ");
    if (iLD <= 0)
        return false;

    as_Hz = as_str.SubString( 1, iLD-1 );
    Hz = atof(as_Hz.c_str());
    return true;
}
//==============================================================================
// Audio
//==============================================================================
// customer volume setting
bool IsValidVolumeGain(AnsiString ansi_str, unsigned char &coef)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, coef, 0, 255 ), RANGE_ERR_VOLUME_GAIN);
    return true;
}
// FIR tunning
//---------------------------------------------------------------------------
bool IsValidMagdB(AnsiString ansi_str, double &d_mag_db)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_mag_db), RANGE_ERR_MAG_DB);
    return true ;
}
// tone
//----------------------------------------------------------------------------
bool IsValidToneFreq(AnsiString ansi_str, unsigned short &freq)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, freq, 0, 65535), RANGE_ERR_TONE_FREQ);
    return true;
}
//----------------------------------------------------------------------------
bool IsValidLoudSpeakerVolume(AnsiString ansi_str, unsigned char &volume)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, volume, 0, 255), RANGE_ERR_LOUD_SPEAKER_VOLUME);
    return true;
}
//============================================================================
/////////////////////////////////  AEC   /////////////////////////////////////
//============================================================================
bool IsValidSpeakerGain(AnsiString ansi_str, int &gain)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, gain, -128, 127), RANGE_ERR_SPEAKER_GAIN);
    return true;
}
//----------------------------------------------------------------------------
bool IsValidMicGain(AnsiString ansi_str, int &gain)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, gain, -128, 127), RANGE_ERR_MIC_GAIN);
    return true;
}
//----------------------------------------------------------------------------
bool IsValidACMagdB(AnsiString ansi_str, double &d_mag_db)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Double(ansi_str, d_mag_db, -15.0, 15.0), RANGE_ERR_MAG_DB);
    return true ;
}
//============================================================================
// Dual Mic. NR
//============================================================================
bool IsValidABFRecTime(AnsiString ansi_str, int &time, int type)
{
    switch(type)
    {
    case 0:
    {
        RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, time, 10, 99), RANGE_ERR_REC_TIME);
    }
    break;
    case 1:
    {
        RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, time, 20, 99), RANGE_ERR_REC_TIME);
    }
    break;
    default:
    {
        RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, time, 20, 99), RANGE_ERR_REC_TIME);
    }
    break;
    }
    return true;
}
//----------------------------------------------------------------------------
bool IsValidDigitalGain(AnsiString ansi_str, unsigned char &gain)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, gain, 0, 255), RANGE_ERR_DIGITAL_GAIN);
    return true;
}
//----------------------------------------------------------------------------
bool IsValidPureGain(AnsiString ansi_str, char &gain)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, gain, -128, 127), RANGE_ERR_PURE_GAIN);
    return true;
}
//----------------------------------------------------------------------------
bool IsValidMaxVolume(AnsiString ansi_str, unsigned char &volume)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, volume, 0, 255), RANGE_ERR_MAX_VOLUME);
    return true;
}
