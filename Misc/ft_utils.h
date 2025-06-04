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
 *   ft_utils.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Format transformation function header
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
 * $Modtime:   Oct 25 2005 12:22:56  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/ft_utils.h-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
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
 *    Rev 1.1   Oct 25 2005 14:15:28   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.0   Sep 04 2005 11:24:28   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _FT_UTILS_H_
#define  _FT_UTILS_H_

#include <vcl.h>


/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
// transform
//extern bool  AnsiString_To_Integer( AnsiString &ansi_str, int &out_value, int range_min, int range_max );
extern AnsiString Double_To_AnsiString(double d, int presition=5);
extern bool  AnsiString_To_Short(AnsiString ansi_str, short &out_value, short range_min=0, short range_max=-1 );
extern bool  AnsiString_To_UnsignedShort(AnsiString ansi_str, unsigned short &out_value, unsigned short range_min, unsigned short range_max );
extern bool  AnsiString_To_Integer(AnsiString ansi_str, int &out_value, int range_min=0, int range_max=-1 );
extern bool  AnsiString_To_UnsignedInteger(AnsiString ansi_str, unsigned int &out_value, unsigned int range_min=0, unsigned int range_max=-1 );
extern bool  AnsiString_To_char(AnsiString ansi_str, char &out_value, int range_min, int range_max);
extern bool  AnsiString_To_signedchar(AnsiString ansi_str, signed char &out_value, int range_min, int range_max );
extern bool  AnsiString_To_UnsignedChar(AnsiString ansi_str, unsigned char &out_value, int range_min, int range_max );
extern bool  AnsiString_To_msbsignchar(AnsiString ansi_str, signed char &out_value, int range_min, int range_max );
extern bool  AnsiString_To_msbUnsignedChar(AnsiString ansi_str, unsigned char &out_value, int range_min, int range_max );
extern bool  AnsiString_To_UnsignedBinary(AnsiString ansi_str, unsigned short &out_value, int range_min, int range_max );
//extern bool  AnsiString_To_Float( AnsiString &ansi_str, float &out_value, float range_min, float range_max );
extern bool  AnsiString_To_Float(AnsiString ansi_str, float &out_value, float range_min=0.0, float range_max=-1.0 );
//extern bool  AnsiString_To_Double( AnsiString &ansi_str, double &out_value, double range_min, double range_max );
extern bool  AnsiString_To_Double(AnsiString ansi_str, double &out_value, double range_min=0.0, double range_max=-1.0 );
extern bool  AnsiString_Hex_To_UnsignedChar(AnsiString ansi_str, unsigned char &out_value ,int range_min=0, int range_max=-1 );
extern bool  AnsiString_Hex_To_UnsignedShort(AnsiString ansi_str, unsigned short &out_value );
extern bool  AnsiString_Hex_To_Int(AnsiString ansi_str, int &out_value );
extern bool  AnsiString_Hex_To_UnsignedInt(AnsiString ansi_str, unsigned  int *out_value );
extern bool  AnsiString_Hex_To_Long(AnsiString ansi_str, unsigned long &out_value );
extern bool  AnsiString_Hex_To_UnsignedLong(AnsiString ansi_str, unsigned long &out_value );
extern bool  AnsiString_To_Short(AnsiString *ansi_str, short *out_value, short range_min_short, short range_max_short );
extern bool  AnsiString_To_UnsignedShort( AnsiString *ansi_str, unsigned short *out_value, unsigned short range_min_short, unsigned short range_max_short );
extern bool  double_To_Array_ASCII_char( double d, char* array  );
extern bool  ASCII_char_To_Array_double( char* array, double &d  );
extern int   String_To_Array_Char( char *src, char* array, int max_count );
extern int   String_To_Array_UnsignedChar( char *src, unsigned char* array, int max_count );
extern int   AnsiString_Hex_To_Array_UnsignedChar( AnsiString as_str, unsigned char* array, int max_count, char c_sep );
extern int   AnsiString_Hex_To_Array_UnsignedInteger( AnsiString as_str, unsigned int* array, int max_count, char c_sep );
extern int   String_To_Array_UnsignedShort( char *src, unsigned short* array, int max_count );
extern int   String_To_Array_short( char *str, short* array, int max_count );
extern int   String_To_Array_int(   char *str, int*   array, int max_count );
extern int   String_To_Array_UnsignedInteger( char *src, unsigned int* array, int max_count );
extern int   String_To_Array_long(  char *str, long*  array, int max_count );
extern int   String_To_Array_float( char *str, float* array, int max_count );
extern int   String_To_Array_double( char *src, double* array, int max_count );
extern int   Array_To_String_Char( char *str, char* array, int count, char separate_char );
extern int   Array_To_String_UnsignedChar( char *str, unsigned char* array, int count, char separate_char );
extern int   Array_To_String_UnsignedShort( char *str, unsigned short* array, int count, char separate_char );
extern int   Array_To_String_short( char *str, short* array, int count, char separate_char );
extern int   Array_To_String_int(   char *str, int*   array, int count, char separate_char );
extern int   Array_To_String_UnsignedInteger( char *str, unsigned int* array, int count, char separate_char );
extern int   Array_To_String_long(  char *str, long*  array, int count, char separate_char );
extern int   Array_To_String_float(char *str, float* array, int count, char separate_char);
extern int   Array_To_String_double(char *str, double* array, int count, char separate_char);
extern int   Array_To_Hex_String_UnsignedChar( char *str, unsigned char* array, int count, char separate_char );
extern int   Array_To_Hex_String_UnsignedInteger( char *str, unsigned int* array, int count, char separate_char );
extern int  PCL2POWER( int band, int pcl );
extern int  POWER2PCL( int band, int power );


#endif
