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
 *   misc_GPS.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *  GPS Misc. function source
 *

 ****************************************************************************/
#include <vcl.h>
#include <math.h>

#pragma hdrstop

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif



//==============================================================================
//////////////////////////////    range check      /////////////////////////////
//==============================================================================
//---------------------------------------------------------------------------
bool  IsValidGPSAutoTestNum( AnsiString ansi_str, unsigned int &testnum )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedInteger( ansi_str, testnum, 1, 1000 ) , RANGE_ERR_GPS_AUTOTEST_NUM );

    return true;
}

bool  IsValidGPSSvid( AnsiString ansi_str, unsigned int &Svid )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedInteger( ansi_str, Svid, 1, 32 ) , RANGE_ERR_GPS_SVID );

    return true;
}




