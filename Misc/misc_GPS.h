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
 *   misc_GPS.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *  GPS Misc. function header
******************************************************************************/


#ifndef  _MISC_GPS_H_
#define  _MISC_GPS_H_
/*---------------------------------------------------------------------------*/
#include <vcl.h>



// range check
extern bool  IsValidGPSAutoTestNum( AnsiString ansi_str, unsigned int &testnum );
extern bool  IsValidGPSSvid( AnsiString ansi_str, unsigned int &Svid );


#endif
