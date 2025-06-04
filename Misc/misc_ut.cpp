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
 *   misc_ut.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Unit Test Misc. function source
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
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
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


//==============================================================================
//////////////////////////////        Unit test        //////////////////////////////
//==============================================================================

//----------------------------------------------------------------------------
bool  IsValidTestCaseID(AnsiString ansi_str, unsigned int &id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, id, 0, 4294967295) , RANGE_ERR_UNIT_TEST_ID);
    return true;
}




