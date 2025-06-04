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
 *   misc_specialtest.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *  SpecialTest Misc. function source
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
bool  IsValidHugeDataTestNum( AnsiString ansi_str, unsigned int &testnum )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedInteger( ansi_str, testnum, 1, 1000 ) , RANGE_ERR_SPECIALTETS_TEST_NUM );

    return true;
}


//==============================================================================
//////////////////////////////    parse raw data      //////////////////////////
//==============================================================================
//---------------------------------------------------------------------------
int ByteHexStr2Int(char *p)
{
   int n = 0;
   int v = 0;
   for(n=0; n<2; n++)
   {
      if((*p>='0')&&(*p<='9'))
      {
          v = v*16 + (*p-'0');
      }
      else if((*p>='A')&&(*p<='F'))
      {
          v = v*16 + (10+*p-'A');
      }
      else if((*p>='a')&&(*p<='f'))
      {
          v = v*16 + (10+*p-'a');
      }
      else
      {
          return(-1);
      }
      p++;
   }
   return(v);
}






