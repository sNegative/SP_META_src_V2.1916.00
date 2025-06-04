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
 *   misc_audio.h
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MISC_AUDIO_H_
#define  _MISC_AUDIO_H_
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/

extern bool getYfromStr( AnsiString asStr, double* p_Y );
/*---------------------------------------------------------------------------*/
extern int getMaxYBound( int max_y, int scale);
extern int getMinYBound( int min_y, int scale);
/*---------------------------------------------------------------------------*/
extern AnsiString getFullPathFileName( AnsiString as_filename );
// audio
extern  bool getHzFromStr( AnsiString as_str, double &Hz);
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/



// Audio
extern bool IsValidFirTaps(AnsiString ansi_str, short &taps);
extern bool IsValidWBFirTaps(AnsiString ansi_str, short &taps);
extern bool IsValidFirCoef(AnsiString ansi_str, short &coef);
extern bool IsValidTimeConst(AnsiString ansi_str, unsigned short &time_const);
extern bool IsValidVolumeConst(AnsiString ansi_str, unsigned short &volume_const);
extern bool IsValidMediaPlaybackMaximumSwing(AnsiString ansi_str, unsigned short &media_playback_max_swing);
extern bool IsValidSpeechCommonParameter(AnsiString ansi_str, unsigned short &sc);
extern bool IsValidAudioCompensation(AnsiString ansi_str, short &ac);
extern bool IsValidSpeechModeDependentParameter(AnsiString ansi_str, unsigned short &smdp);
extern bool IsValidFirScale(AnsiString ansi_str, float &FirScale);
extern bool IsValidDigitalScale(AnsiString ansi_str, float &DigitalScale);
extern bool IsValidRepeats(AnsiString ansi_str, int &repeats);
extern bool IsValidSpeakerVolume (AnsiString ansi_str, int &SpeakerVolume);
extern bool IsValidBuzzerVolume (AnsiString ansi_str, int &BuzzerVolume);
extern bool IsValidVolume (AnsiString ansi_str, int &Volume);
extern bool IsValidInstrument (AnsiString ansi_str, int &Instrument);
// audio
extern bool IsValidVolumeGain(AnsiString ansi_str, unsigned char &coef);
extern bool IsValidMagdB(AnsiString ansi_str, double &d_mag_db);
extern bool IsValidACMagdB(AnsiString ansi_str, double &d_mag_db);

//rongguo 2011-11-23
extern bool IsValidMaxVolume(AnsiString ansi_str, unsigned char &volume);

extern bool IsValidDigitalGain(AnsiString ansi_str, unsigned char &gain);
extern bool IsValidPureGain(AnsiString ansi_str, char &gain);
// tone
extern bool IsValidToneFreq(AnsiString ansi_str, unsigned short &freq);
extern bool IsValidLoudSpeakerVolume(AnsiString ansi_str, unsigned char &volume);

// AEC
extern bool IsValidSpeakerGain(AnsiString ansi_str, int &gain);
extern bool IsValidMicGain(AnsiString ansi_str, int &gain);

//Dual Mic
extern bool IsValidABFRecTime(AnsiString ansi_str, int &time, int type);

#endif
