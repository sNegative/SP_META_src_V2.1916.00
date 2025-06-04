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
 *   misc_barcode.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Barcode Misc. function source
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
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
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

//------------------------------------------------------------------------------
bool IsValidDecimalChar( char decimalChar )
{
    if('0' <= decimalChar && decimalChar<= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}


//------------------------------------------------------------------------------
bool getIntPartFromAnsiString( AnsiString as_Str, int* p_IntPart, int* length_IntPart )
{
    char output[100];
//     int  output_[100];
    AnsiString as_Output_Str;
    int i;
    //int output_Str_Length;

    *length_IntPart = 0;
    for( i=0; i<100; i++)
    {
        output[i] = 0;
    }
    for( i=0; i<as_Str.Length(); i++ )
    {
        output[i] = *((as_Str.SubString(as_Str.Length()-i, 1)).c_str());
    }
    for( i=0; i<as_Str.Length(); i++ )
    {
        if( IsValidDecimalChar( output[i] ) )
        {
            *(p_IntPart + i) = output[i] - '0';
            (*length_IntPart)++;
        }
        else
        {
            break;
        }
    }

    return true;
}
//------------------------------------------------------------------------------
AnsiString AnsiStringAdd( AnsiString as_Str, int increasement )
{
    //int output[100];
    int IntPart[100], len_IntPart;
    AnsiString as_nonInt_Part, as_Int_Part, as_Output_Str;
    int i;
    //int output_Str_Length;

    for( i=0; i<100; i++ )
    {
        IntPart[i]=0;
    }
    as_Int_Part = (AnsiString) "";
    getIntPartFromAnsiString( as_Str, IntPart, &len_IntPart);
    as_nonInt_Part = as_Str.SubString( 1, as_Str.Length() - len_IntPart );



    IntPart[0] = IntPart[0] + increasement;
    for( i=0; i<len_IntPart; i++ )
    {
        IntPart[i+1]= IntPart[i+1]+ IntPart[i]/10;
        IntPart[i] = IntPart[i] % 10;
    }
    if( IntPart[len_IntPart] !=0 )
    {
        len_IntPart++;
    }
    for( i=len_IntPart-1; i>=0; i--)
    {
        as_Int_Part = as_Int_Part + IntToStr( IntPart[i] );
    }
    as_Output_Str = as_nonInt_Part + as_Int_Part;

    return as_Output_Str;
}






























//---------------------------------------------------------------------------
/*bool  IsValidBarcode( AnsiString &barcode_str)
{
   if(barcode_str.Length() <= MAX_BARCODE_LEN)
      return true;
   else
      return false;
}
*/

