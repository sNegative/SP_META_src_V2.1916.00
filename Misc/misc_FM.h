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
 *   misc_FM.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  FM radio Misc. function header
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _MISC_FM_H_
#define  _MISC_FM_H_
/*---------------------------------------------------------------------------*/
#include <vcl.h>




/*---------------------------------------------------------------------------*/
// format transform
extern bool AnsiString_To_FM_Freq(AnsiString ansi_str, short& freq);
extern bool AnsiString_To_FM_Freq_50KHz(AnsiString ansi_str, short& freq);

// range check
extern bool IsValidFMFreq(AnsiString ansi_str, short& freq);
extern bool IsValidFMFreqFor50KHz(AnsiString ansi_str, short& freq);
extern bool IsValidFMRssiThreshold(AnsiString ansi_str, unsigned int& threshold);
extern bool IsValidFMIfCounterDelta(AnsiString ansi_str, unsigned int& delta);
extern bool IsValidFMChannel(AnsiString ansi_str, short& channel);

#endif
