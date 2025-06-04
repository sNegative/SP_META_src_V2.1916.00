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
 *   ft_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Format transformation function source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.1  $
 * $Modtime:   Oct 25 2005 12:22:44  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/ft_utils.cpp-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
 *
 *
 * Mar 14 2007 mtk00490
 * [STP100001335] [META] META ver 5.3.6.1
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.1   Oct 25 2005 14:15:26   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.0   Sep 04 2005 11:24:28   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <vcl.h>
#include <math.h>
#include <stdio.h>

#pragma hdrstop

#include "man_error.h"

#ifndef  _META_UTILS_H_
#include "meta_utils.h"
#endif

#ifndef  _STR_UTILS_H_
#include "str_utils.h"
#endif

//------------------------------------------------------------------------------
AnsiString Double_To_AnsiString(double d, int presition=5)
{
    char str[1024];
    AnsiString as_format;
    as_format = AnsiString("%." + IntToStr(presition) + "f");
    sprintf(str, as_format.c_str(), d);
    AnsiString ansi_str(str);
    return ansi_str;
}

//------------------------------------------------------------------------------
bool  AnsiString_To_Short(AnsiString ansi_str, short &out_value, short range_min=0, short range_max=-1 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0 || str_len >6)  return(false);

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(short)*8-1) )  return false;

    out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_UnsignedShort(AnsiString ansi_str, unsigned short &out_value, unsigned short range_min, unsigned short range_max )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0 || str_len >6)  return(false);

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(unsigned short)*8) )  return false;
    out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_Integer(AnsiString ansi_str, int &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();
        if(str_len==0)  return(false);
        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(int)*8-1) )  return false;

    out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_UnsignedInteger(AnsiString ansi_str, unsigned int &out_value, unsigned int range_min, unsigned int range_max )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();
        if(str_len==0)  return(false);
        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(unsigned int)*8-1) )  return false;
    out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_char(AnsiString ansi_str, char &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0 || str_len >5)  return(false); // 2^8 = 256

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(char)*8-1) )  return false;

    int int_out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }
    out_value = (char) int_out_value & 0xFF;
    return( true );
}


//---------------------------------------------------------------------------
bool  AnsiString_To_signedchar(AnsiString ansi_str, signed char &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0 || str_len >5)  return(false); // 2^8 = 256

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(signed char)*8-1) )  return false;
    int int_out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }
    out_value = (signed char) int_out_value & 0xFF;
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_UnsignedChar(AnsiString ansi_str, unsigned char &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0 || str_len >10)
            return(false); // 2^8 = 256

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, sizeof(unsigned char)*8) )  return false;

    int int_out_value = ansi_str.ToInt();

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }
    out_value = (unsigned char) int_out_value & 0xFF;
    return( true );
}


//---------------------------------------------------------------------------
bool  AnsiString_To_msbsignchar(AnsiString ansi_str, signed char &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    int   i;
    unsigned char  ch;
    char  str[256];
    int int_out_value;
    int   str_len = ansi_str.Length();

    if(str_len==0 || str_len >5)  return(false); // 2^8 = 256

    strcpy( str, ansi_str.c_str() );

    for( i=0; i<str_len; i++ )
    {
        ch = str[i];
        if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
        break;
    }
    if( i!=str_len )
        return(false);


    /* convert string to integer */
    if( str[0] == '-' )
    {
        int_out_value = ansi_str.SubString(2, ansi_str.Length()).ToInt();
    }
    else
    {
        int_out_value = ansi_str.ToInt();
    }

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }

    if( str[0] == '-' )
    {
        out_value = (signed char) int_out_value | 0x80;
    }
    else
    {
        out_value = (signed char) int_out_value;
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_msbUnsignedChar(AnsiString ansi_str, unsigned char &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    int   i;
    unsigned char  ch;
    unsigned char  str[256];
    int int_out_value;
    int   str_len = ansi_str.Length();

    if(str_len==0 || str_len >5)  return(false); // 2^8 = 256

    strcpy( str, ansi_str.c_str() );

    for( i=0; i<str_len; i++ )
    {
        ch = str[i];
        if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
        break;
    }
    if( i!=str_len )
        return(false);

    /* convert string to integer */
    if( str[0] == '-' )
    {
        int_out_value = ansi_str.SubString(2, ansi_str.Length()).ToInt();
    }
    else
    {
        int_out_value = ansi_str.ToInt();
    }

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }

    if( str[0] == '-' )
    {
        out_value = (unsigned char) int_out_value | 0x80;
    }
    else
    {
        out_value = (unsigned char) int_out_value;
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_To_UnsignedBinary(AnsiString ansi_str, unsigned short &out_value, int range_min=0, int range_max=-1 )
{
    /* check if each char is valid */
    int   i;
    char  ch;
    char  str[256];
    int   str_len = ansi_str.Length();

    if(str_len==0 || str_len >16)  return(false); // 2^8 = 256

    strcpy( str, ansi_str.c_str() );

    for( i=0; i<str_len; i++ )
    {
        ch = str[i];
        if( ((ch>='0')&&(ch<='1')) )   continue;
        break;
    }
    if( i!=str_len )
        return(false);

    /* convert string to integer */
    int int_out_value=0;
    int i_str;
    for( i=0; i<str_len; i++ )
    {
        i_str = (int) str[i]-'0';
        int_out_value += i_str*pow(2,str_len-i-1);
    }

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (int_out_value<range_min)||(int_out_value>range_max) )
            return(false);
    }
    out_value = (unsigned short) int_out_value & 0xFFFF;
    return( true );
}

//------------------------------------------------------------------------------
bool  AnsiString_To_Float(AnsiString ansi_str, float &out_value, float range_min=0.0, float range_max=-1.0 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='.') || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    out_value = (float) atof(ansi_str.c_str());

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//------------------------------------------------------------------------------
bool  AnsiString_To_Double(AnsiString ansi_str, double &out_value, double range_min=0.0, double range_max=-1.0 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='.') || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    out_value = atof(ansi_str.c_str());

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_UnsignedChar(AnsiString ansi_str, unsigned char &out_value ,int range_min=0, int range_max=-1 )
{
    char  str[256];
    unsigned  char  val;

    /* check if each char is valid */
    {
        int   i;
        unsigned char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        if('0' == (ansi_str.c_str())[0] && ('x' == (ansi_str.c_str())[1] || 'X' == (ansi_str.c_str())[1]))
        {
            ansi_str = ansi_str.SubString(3, str_len);
            str_len = ansi_str.Length();
        }
        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return(false);
    }

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (val<range_min)||(val>range_max) )
            return(false);
    }
    /* convert string to integer */
    out_value = val;

    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_Int(AnsiString ansi_str, int &out_value )
{
    char  str[256];
    int  val;

    /* check if each char is valid */
    {
        int   i;
        char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    out_value = val;

    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_UnsignedShort(AnsiString ansi_str, unsigned short &out_value )
{
    char  str[256];
    unsigned  short  val;

    /* check if each char is valid */
    {
        int   i;
        char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return false;

        if('0' == (ansi_str.c_str())[0] && ('x' == (ansi_str.c_str())[1] || 'X' == (ansi_str.c_str())[1]))
        {
            ansi_str = ansi_str.SubString(3, str_len);
            str_len = ansi_str.Length();
        }
        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return false;
    }
    /* convert string to integer */
    out_value = val;

    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_UnsignedInt(AnsiString ansi_str, unsigned  int *out_value )
{
    char  str[256];
    unsigned  int  val;

    /* check if each char is valid */
    {
        int   i;
        char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        if('0' == (ansi_str.c_str())[0] && ('x' == (ansi_str.c_str())[1] || 'X' == (ansi_str.c_str())[1]))
        {
            ansi_str = ansi_str.SubString(3, str_len);
            str_len = ansi_str.Length();
        }
        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    *out_value = val;

    return( true );
}

//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_Long(AnsiString ansi_str, unsigned long &out_value )
{
    char  str[256];
    long  val;

    /* check if each char is valid */
    {
        int   i;
        char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    out_value = val;

    return( true );
}
//---------------------------------------------------------------------------
bool  AnsiString_Hex_To_UnsignedLong(AnsiString ansi_str, unsigned long &out_value )
{
    char  str[256];
    unsigned long  val;

    /* check if each char is valid */
    {
        int   i;
        char  ch;
        int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        strcpy( str, ansi_str.c_str() );

        val = 0;
        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( (ch>='0')&&(ch<='9') )
            {
                val <<= 4;
                val += ch-'0';
            }
            else if( (ch>='A')&&(ch<='F') )
            {
                val <<= 4;
                val += ch-'A'+10;
            }
            else if( (ch>='a')&&(ch<='f') )
            {
                val <<= 4;
                val += ch-'a'+10;
            }
            else if( ch==' ' )
            {
            }
            else
            {
                break;
            }
            continue;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    out_value = val;

    return( true );
}


//==============================================================================
bool  CharArray_To_Float( Char* str, int str_len, float &out_value, float range_min=0.0, float range_max=-1.0 )
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        //char  str[256];
        //int   str_len = ansi_str.Length();

        if(str_len==0)  return(false);

        out_value = 0.0;
        //strcpy( str, ansi_str.c_str() );

        //for( i=0; i<str_len; i++ )
        // {  ch = *(str+i);
        //    if( ((ch>='0')&&(ch<='9')) || (ch=='.') || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
        //   break;
        // }
        for( i=0; i<str_len; i++ )
        {
            ch = *(str+i);
            if( ((ch>='0')&&(ch<='9')) )
            {
                out_value = (out_value*10.0) + ch;
            }
            // || (ch=='.') || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    // out_value = (float) atof(ansi_str.c_str());

    /* chack value range */
    if(range_min<=range_max)
    {
        if( (out_value<range_min)||(out_value>range_max) )
            return(false);
    }
    return( true );
}





//===========================================================================
int   _ArrayString_Parse( char *src, char* dst, short* dst_pos )
{
    char  ch = src[0];
    char  last_char_is_null = 1;
    int   dst_idx = 0;
    int   i;

    for( i=0; (ch!=0)&&(i<2047); i++ )
    {
        ch = src[i];
        if(  ((ch>='0')&&(ch<='9'))||(ch=='-')||(ch=='+')||(ch=='.')||(ch=='E') ||(ch=='e'))
        {
            if( last_char_is_null )
            {
                dst_pos[dst_idx] = i;
                dst_idx++;
            }
            dst[i] = ch;
            last_char_is_null = 0;
        }
        else
        {
            dst[i] = 0;
            last_char_is_null = 1;
        }
    }
    dst[i] = 0;
    dst_pos[dst_idx] = -1;
    return( dst_idx );
}

//---------------------------------------------------------------------------
int   Hex_ArrayString_Parse( char *src, char* dst, short* dst_pos )
{
    char  ch = src[0];
    char  last_char_is_null = 1;
    int   dst_idx = 0;
    int   i;

    for( i=0; (ch!=0)&&(i<2047); i++ )
    {
        ch = src[i];
        if( ((ch>='0')&&(ch<='9')) ||
                ((ch>='A')&&(ch<='F')) ||
                ((ch>='a')&&(ch<='f')) ||
                (ch=='-')              ||
                (ch=='+')              ||
                (ch=='.')
          )
        {
            if( last_char_is_null )
            {
                dst_pos[dst_idx] = i;
                dst_idx++;
            }
            dst[i] = ch;
            last_char_is_null = 0;
        }
        else
        {
            dst[i] = 0;
            last_char_is_null = 1;
        }
    }
    dst[i] = 0;
    dst_pos[dst_idx] = -1;
    return( dst_idx );
}

//---------------------------------------------------------------------------
bool  double_To_Array_ASCII_char( double d, char* array  )
{
    AnsiString as_d = Double_To_AnsiString( d );
    int i;

    for( i=0; i<as_d.Length(); i++)
    {
        strcpy( (array+i), as_d.SubString(i+1,1).c_str());
    }
    *(array+i) = '\0';

    return true;
}

//---------------------------------------------------------------------------
void  ASCII_char_To_Array_double( char* array, double &d  )
{
    for(int i=0; ; i++)
    {
        if( *(array+i) == '\0' )  break;
        *(array+i) &= 0x7F;
    }
    AnsiString as_d(array);

    d = atof(as_d.c_str());
}

//---------------------------------------------------------------------------
int   String_To_Array_Char( char *src, char* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = (char) atoi( &str[str_pos[i]] );
    }

    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_UnsignedChar( char *src, unsigned char* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = (unsigned char) atoi( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   AnsiString_Hex_To_Array_UnsignedChar(AnsiString as_str, unsigned char* array, int max_count, char c_sep )
{
    //char  str[2048];
    //char  ch;
    //short str_pos[512];
    int   i, count;
    //unsigned  char  val;
    // AnsiString as_str(src);
    // count = Hex_ArrayString_Parse( src, str, str_pos );
    // count = Get_CharAppearCount( as_str, ',' );
    count = Get_CharAppearCount( as_str, c_sep );
    if( count>max_count )  count = max_count;

    for(i=0; i<=count; i++)
    {
        // int iLD_l = as_str.AnsiPos(",");
        int iLD_l = as_str.AnsiPos( c_sep );
        if( iLD_l != 0 )
        {
            AnsiString_Hex_To_UnsignedChar( as_str.SubString( 1, iLD_l-1), array[i]  );
        }
        else
        {
            AnsiString_Hex_To_UnsignedChar( as_str, array[i]  );
        }
        as_str = as_str.SubString( iLD_l+1, as_str.Length() - iLD_l );

    }
    return( count );
}
//---------------------------------------------------------------------------
int   AnsiString_Hex_To_Array_UnsignedInteger(AnsiString as_str, unsigned int* array, int max_count, char c_sep )
{
    //char  str[2048];
    //char  ch;
    //short str_pos[512];
    int   i, count;
    //unsigned  char  val;
    // AnsiString as_str(src);
    // count = Hex_ArrayString_Parse( src, str, str_pos );
    // count = Get_CharAppearCount( as_str, ',' );
    count = Get_CharAppearCount( as_str, c_sep );
    if( count>max_count )  count = max_count;

    for(i=0; i<=count; i++)
    {
        // int iLD_l = as_str.AnsiPos(",");
        int iLD_l = as_str.AnsiPos( c_sep );
        if( iLD_l != 0 )
        {
            AnsiString_Hex_To_UnsignedInt( as_str.SubString( 1, iLD_l-1), array + i  );
        }
        else
        {
            AnsiString_Hex_To_UnsignedInt( as_str, array + i  );
        }
        as_str = as_str.SubString( iLD_l+1, as_str.Length() - iLD_l );

    }
    return( count );
}
//---------------------------------------------------------------------------
int   String_To_Array_UnsignedShort( char *src, unsigned short* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = (unsigned short) atoi( &str[str_pos[i]] );
    }
    return( count );
}


//---------------------------------------------------------------------------
int   String_To_Array_short( char *src, short* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = (short)atoi( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_int( char *src, int* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = atoi( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_UnsignedInteger( char *src, unsigned int* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = ( unsigned int) atoi( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_long( char *src, long* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = atol( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_float( char *src, float* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = (float)atof( &str[str_pos[i]] );
    }
    return( count );
}

//---------------------------------------------------------------------------
int   String_To_Array_double( char *src, double* array, int max_count )
{
    char  str[2048];
    short str_pos[512];
    int   i, count;

    count = _ArrayString_Parse( src, str, str_pos );
    if( count>max_count )  count = max_count;

    for(i=0; i<count; i++)
    {
        array[i] = atof( &str[str_pos[i]] );
    }
    return( count );
}

//===========================================================================
int   Array_To_String_Char( char *str, char* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", (char)array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", (char)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return i;
}

//--------------------------------------------------------------------------
int   Array_To_String_UnsignedChar( char *str, unsigned char* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", (unsigned char)array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", (unsigned char)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//--------------------------------------------------------------------------
int   Array_To_String_UnsignedShort( char *str, unsigned short* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", (unsigned short)array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", (unsigned short)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//--------------------------------------------------------------------------
int   Array_To_String_short( char *str, short* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", (int)array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", (int)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//---------------------------------------------------------------------------
int   Array_To_String_UnsignedInteger( char *str, unsigned int* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", array[i] );
    i = (unsigned int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//---------------------------------------------------------------------------
int   Array_To_String_int( char *str, int* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%d%c", array[i], separate_char );
    }
    ptr += sprintf( ptr, "%d", array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//---------------------------------------------------------------------------
int   Array_To_String_long( char *str, long* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "%l%c", array[i], separate_char );
    }
    ptr += sprintf( ptr, "%l", array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//---------------------------------------------------------------------------
int Array_To_String_float(char *str, float* array, int count, char separate_char)
{
    char *ptr = str;
    int i;

    for (i=0; i<count-1; i++)
    {
        ptr += sprintf( ptr, "%.3f%c", array[i], separate_char);
    }
    ptr += sprintf( ptr, "%.3f%c", array[i], '0' );
    i = (int)((unsigned long)ptr - (unsigned long)str);
    return i;
}

//--------------------------------------------------------------------------
int Array_To_String_double(char *str, double* array, int count, char separate_char)
{
    char *ptr = str;
    int i;

    for (i=0; i<count-1; i++)
    {
        ptr += sprintf( ptr, "%.3f%c", array[i], separate_char);
    }
    ptr += sprintf( ptr, "%.3f%c", array[i], '0' );
    i = (int)((unsigned long)ptr - (unsigned long)str);
    return i;
}

//===========================================================================
int   Array_To_Hex_String_UnsignedChar( char *str, unsigned char* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "0x%2.2X%c", (unsigned char)array[i], separate_char );
    }
    ptr += sprintf( ptr, "0x%2.2X", (unsigned char)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}
//---------------------------------------------------------------------------
int   Array_To_Hex_String_UnsignedInteger( char *str, unsigned int* array, int count, char separate_char )
{
    char  *ptr = str;
    int   i;

    for( i=0; i<count-1; i++ )
    {
        ptr += sprintf( ptr, "0x%8.8X%c", (unsigned int)array[i], separate_char );
    }
    ptr += sprintf( ptr, "0x%8.8X", (unsigned int)array[i] );
    i = (int)((unsigned long)ptr - (unsigned long)str);

    return( i );
}

//===========================================================================
static const int  pcl2power_table[][32] =
{
    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1
    {  39,39,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11, 9, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5  },  // GSM900
    {  30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,36,34,32  },  // DCS1800
    {  30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0,33,33,33,33,33,33,33,33,33,32  },  // PCS1900
    {  39,39,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11, 9, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5  },  // GSM850

};

//---------------------------------------------------------------------------
int  PCL2POWER( int band, int pcl )
{
    if(pcl<0)  pcl=0;
    if(pcl>31) pcl = 31;
    int  power=pcl2power_table[band][pcl];
    return(power);
}

//---------------------------------------------------------------------------
static const int  power2pcl_table[][32] =
{
    //  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8
    {  19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 2  },  // GSM900
    {  15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,31,30,29  },  // DCS1800
    {  15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,31,30,29  },  // PCS1900
    {  19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 2  },  // GSM850
};





