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
 *   misc_specialtest.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *  SpecialTest Misc. function header
******************************************************************************/


#ifndef  _MISC_SPECIALTEST_H_
#define  _MISC_SPECIALTEST_H_
/*---------------------------------------------------------------------------*/
#include <vcl.h>



// range check
extern bool  IsValidHugeDataTestNum( AnsiString ansi_str, unsigned int &testnum );

//parse raw data
extern int ByteHexStr2Int(char *p);


#endif
