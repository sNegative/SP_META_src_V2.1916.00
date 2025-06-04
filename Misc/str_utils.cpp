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
 *  str_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  string utility function source
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
#include <stdio.h>



#pragma hdrstop

//============================================================================
bool RemoveLastSpaceFromStr( AnsiString &as_str )
{
    int i;
    for( i=as_str.Length(); i>=1; i-- )
    {
        if( as_str.SubString(i, 1).AnsiCompareIC(" ") != 0 )
            break;
    }
    as_str = as_str.SubString(1, i);

    return true;
}

//----------------------------------------------------------------------------
int Get_CharAppearCount( AnsiString as_str, char c )
{
    int count=0;
    int length = as_str.Length();
    char str[1024];
    strcpy( str, as_str.c_str() );

    for(int i=0; i<length; i++ )
    {
        if( str[i] == c )
            count++;
    }
    return count;
}

//----------------------------------------------------------------------------
int Get_CharAppearPosition( AnsiString as_str, char c, int times )
{
    int count=0;
    int length = as_str.Length();
    char str[1024];
    strcpy( str, as_str.c_str() );
    for(int i=0; i<length; i++ )
    {
        if( str[i] == c )
        {
            count++;
            if( count == times )
            {
                return i+1;
            }
        }
    }

    return -1;
}

//---------------------------------------------------------------------------
int Get_CharAppearPosition( AnsiString as_str, char pre_c, char target_c, int times )
{
    bool b_pre_c_found = false;
    int count=0;
    int pre_c_pos = -1;

    int length = as_str.Length();
    char str[1024];
    strcpy( str, as_str.c_str() );
    for(int i=0; i<length; i++ )
    {
        if( str[i] == pre_c )
        {
            count++;
            if( count == times )
            {
                pre_c_pos = i;
                b_pre_c_found = true;
                break;
            }
        }
    }

    if( ! b_pre_c_found )  return false;
    for(int i= pre_c_pos+1; i<length; i++ )
    {
        if( str[i] == target_c )
        {
            return i+1;
        }
    }
    return -1;
}
