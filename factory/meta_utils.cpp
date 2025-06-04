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
 *   META_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  META utility source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.12  $
 * $Modtime:   Oct 25 2005 11:19:54  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/factory/meta_utils.cpp-arc  $
 *
 * Jul 16 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
 *
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.12   Oct 25 2005 14:13:34   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.11   Sep 04 2005 11:02:08   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.10   Apr 18 2005 15:47:34   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.9   Jan 30 2005 17:54:34   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.8   Jan 10 2005 11:10:34   mtk00490
 * 1. Automatic BB chip and external clock rate detection
 * 2. Support baud rate 57600 (for FPGA test)
 * 3. RF tool
 * a.Trim IQ, offset IQ sweep (get phase error, original offset, IQ imbalance information from equipment)
 * 4. Audio
 * a.Acoustic FIR tuning and melody FIR tuning integrate with AFTDLL.dll (provide freqz and firls function, user does not to install MATLAB for FIR tuning)
 * 5. Update parameter
 * a.add barcode and IMEI read/write
 * 6. Factory
 * a.support DCS, PCS, GSM850 AFC calibration
 * b.phase error calibration
 * c.user configurable current limit
 * d.add APC DAC to result file
 * e.add AFC_BAND, AFC_ARFCN to TCVCXO AFC CFG editor
 * f.add CURRENT_LIMIT to ADC CFG editor
 * g.add phase error CFG editor
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//---------------------------------------------------------------------------
#include <system.hpp>
#include <dstring.h>
//#include <assert.h>
#include <stdio.h>


#pragma hdrstop


#ifndef  _META_UTILS_H_
#include "meta_utils.h"
#endif

#ifndef _META_MSG_H_
#include "meta_msg.h"
#endif
//------------------------------------------------------------------------------
#define MAX_FILE_NAME_LENGTH 255

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
bool getAnsiStrSubItem( const AnsiString as_Src, const int index,
                        const char cSep, AnsiString &as_SubStr)
{
    // index start from 1
    AnsiString as_tmp=as_Src;
    AnsiString as_tmp2=as_Src;
    AnsiString as_Result;

    int i_begin;
    int i_end;
    int count=0;

    if ( as_Src.AnsiCompare("") == 0 )
    {
        as_SubStr = "";
        return false;
    }
    i_begin = as_tmp.AnsiPos( AnsiString( cSep ));

    if ( i_begin == 0)
    {
        as_SubStr = "";
        return false;
    }

    if ( index == 1 )
    {
        as_SubStr = as_tmp.SubString(1, i_begin-1 );
        return true;
    }

    if ( count == index-1 )
    {
        i_begin = 0;
    }

    for( int i=1; i<= as_Src.Length(); i++)
    {
        if ( as_Src[i] == cSep)
        {
            count ++;
            if ( count == index-1 )
            {
                i_begin = i;
            }
            if ( count == index )
            {
                i_end = i;
            }
        }
    }

    as_SubStr = as_tmp.SubString(i_begin+1, i_end-i_begin-1 );
    if( as_SubStr.AnsiCompare("") == 0 )
    {
        return  false;
    }
    return true;

    /*
        as_tmp2 = as_tmp.SubString( i_begin,

        as_tmp = as_tmp.SubString( i_begin,
    */

}



//-----------------------------------------------------------------------------

/* Power */ int Convert_PCL_to_dBm( FrequencyBand band, int txPower )
{
    static const char powerLevelTodBm[3][32] =
    {
        /* GSM 400, GSM 850, GSM 900 */
        { 39,39,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11, 9, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
        /* DCS 1800 */
        { 30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,36,34,32 },
        /* PCS 1900 */
        { 30,28,26,24,22,20,18,16,14,12,10, 8, 6, 4, 2, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,32 }
    };
    static const bandToTableIndex[FrequencyBandCount] =
    {
        0, /* FrequencyBand400 */
        0, /* FrequencyBand850 */
        0, /* FrequencyBand900 */
        1, /* FrequencyBand1800 */
        2  /* FrequencyBand1900 */
    };
    return powerLevelTodBm[ bandToTableIndex[band] ][ txPower ];
}
//---------------------------------------------------------------------------

/* PCL */ int Convert_dBm_to_PCL( FrequencyBand band, int power )
{
    power = ( power + 1 ) / 2;
    if ( band <= FrequencyBand900 ) return (22 - power);
    if ( power >= 16 ) return (47 - power);
    return (15 - power);
}

//---------------------------------------------------------------------------
bool getPathFromStr( AnsiString asStr, AnsiString &asPath )
{
    int iLD = asStr.LastDelimiter(":\\");
    if (iLD <= 0)
        return false;

    asPath = asStr.SubString( 1, iLD );
    return true;
}

//---------------------------------------------------------------------------
bool getDriveFromStr( AnsiString asStr, AnsiString &asDrive )
{
    int iLD = asStr.LastDelimiter(":\\");
    if (iLD <= 0)
        return false;

    asDrive = asStr.SubString( 1, iLD );
    return true;
}

//---------------------------------------------------------------------------
bool getDriveLetterFromStr( AnsiString asStr, AnsiString &asDriveLetter )
{
    asDriveLetter = asStr.SubString( 1, 1 );
    return true;
}

//---------------------------------------------------------------------------
bool getFilenameFromStr( AnsiString asStr, AnsiString &asFileName )
{
    int iLD = asStr.LastDelimiter("\\");
    if (iLD <= 0)
        return false;

    asFileName = asStr.SubString( iLD+1, MAX_FILE_NAME_LENGTH );
    return true;
}

//---------------------------------------------------------------------------
bool getIntegrityFromStr( AnsiString asStr, AnsiString &asIntegrity )
{
    int iLD = asStr.LastDelimiter(",");
    if (iLD <= 0)
        return false;

    asIntegrity = asStr.SubString( 1, iLD-1 );
    return true;
}

//---------------------------------------------------------------------------
bool getEpskIntegrityFromStr( AnsiString asStr, AnsiString &asIntegrity )
{
    int iLD = asStr.LastDelimiter(",");
    if (iLD <= 0)
        return false;

    asStr = asStr.SubString( 1, iLD-1 );
    iLD = asStr.LastDelimiter(",");
    asIntegrity = asStr.SubString( 1, iLD-1 );
    return true;
}
//---------------------------------------------------------------------------
bool getTxPowerFromStr( AnsiString asStr, AnsiString &asTxPower )
{
    int iLD = asStr.LastDelimiter(",");
    if (iLD <= 0)
        return false;

    asTxPower = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}

//---------------------------------------------------------------------------
bool getEpskTxPowerFromStr( AnsiString asStr, AnsiString &asTxPower )
{
    int iLD = asStr.LastDelimiter(",");
    if (iLD <= 0)
        return false;

    asTxPower = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}

//---------------------------------------------------------------------------
bool getBaseFromStr( AnsiString asStr, AnsiString &asBase )
{
    int iLD = asStr.LastDelimiter("E");
    if (iLD <= 0)
        return false;

    asBase = asStr.SubString( 1, iLD-1 );
    return true;
}

//---------------------------------------------------------------------------
bool getEpskBaseFromStr( AnsiString asStr, AnsiString &asBase )
{
    int iLD = asStr.LastDelimiter("E");
    if (iLD <= 0)
        return false;

    asBase = asStr.SubString( 1, iLD-1 );
    return true;
}

//---------------------------------------------------------------------------
bool getExponentFromStr( AnsiString asStr, AnsiString &asExponent )
{
    int iLD = asStr.LastDelimiter("E");
    if (iLD <= 0)
        return false;

    asExponent = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}

//---------------------------------------------------------------------------
bool getEpskExponentFromStr( AnsiString asStr, AnsiString &asExponent )
{
    int iLD = asStr.LastDelimiter("E");
    if (iLD <= 0)
        return false;

    asExponent = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}

//---------------------------------------------------------------------------
bool getTaModelFromStr( AnsiString asStr, AnsiString &asTaModel )
{
    int iLD = asStr.LastDelimiter("\"");
    if (iLD <= 0)
        return false;

    asTaModel = asStr.SubString( 2, iLD-2 );
    return true;
}

//-----------------------------------------------------------------------------
bool withPath( AnsiString asPath )
{
    if ( asPath.LastDelimiter(":\\") > 0 )
        return true;
    else
        return false;
}
//-----------------------------------------------------------------------------
bool getStrAFromStrAB( AnsiString StrAB, char c_SEP, AnsiString &StrA  )
{
    int iLD = StrAB.LastDelimiter(c_SEP);
    if ( iLD > 0 )
    {
        StrA = StrAB.SubString( 0,  iLD-1);
        return true;
    }
    else
        return false;
}
//-----------------------------------------------------------------------------
long filesize(FILE *stream)
{
    long curpos, length;

    curpos = ftell(stream);
    fseek(stream, 0L, SEEK_END);
    length = ftell(stream);
    fseek(stream, curpos, SEEK_SET);
    return length;
}
//-----------------------------------------------------------------------------
bool change_file_name(AnsiString &as_FileName)
{
    AnsiString as;
    int i_dot = as_FileName.LastDelimiter(".");
    int i_slash =  as_FileName.LastDelimiter(":\\");
    char c;
    int pos;

    if (
        ((i_dot > i_slash) && (i_dot > 1)) ||
        ( i_dot == 0 )  // only main file name
    )
    {
        if ((i_dot > i_slash) && (i_dot > 1))
            pos = i_dot-1;
        else
            pos = as_FileName.Length();

        as = as_FileName.LowerCase();
        c = as[pos];

        switch ( c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            as_FileName[pos] = (char)(c+1);
            return true;

        case '9':
            as_FileName[pos] = 'a';
            return true;

        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
            as_FileName[pos] = (char)(c+1);
            return true;

        case 'z':
        default :
            as_FileName[pos] = '0';
            return true;

        } // switch
    }

    return false;

}

//------------------------------------------------------------------------------

bool IsFreqBankSupported( AnsiString &asFreqBank, FrequencyBand fb)
{
    int i = asFreqBank.ToInt();
    switch ( fb)
    {
    case FrequencyBand850:
        if (i & 0x02)
            return true;
        else
            return false;
    case FrequencyBand900:
        if (i & 0x04)
            return true;
        else
            return false;
    case FrequencyBand1800:
        if (i & 0x08)
            return true;
        else
            return false;
    case FrequencyBand1900:
        if (i & 0x10)
            return true;
        else
            return false;
    default:
        return false;
    } // switch
}

//------------------------------------------------------------------------------
bool getBand_Range_from_AnsiStr( AnsiString as,
                                 AnsiString &as_Band,
                                 AnsiString &as_Range,
                                 AnsiString &as_up_down )
{
    if ( as.Pos("GSM400") != 0 )
        as_Band = "GSM400";
    else if ( as.Pos("GSM850") != 0 )
        as_Band = "GSM850";
    else if ( as.Pos("GSM900") != 0 )
        as_Band = "GSM900";
    else if ( as.Pos("DCS1800") != 0 )
        as_Band = "DCS1800";
    else if ( as.Pos("PCS1900") != 0 )
        as_Band = "PCS1900";
    else
        return false;

    if ( as.Pos("Range0") != 0 )
        as_Range = "Range0";
    else if ( as.Pos("Range1") != 0 )
        as_Range = "Range1";
    else if ( as.Pos("Range2") != 0 )
        as_Range = "Range2";
    else if ( as.Pos("Range3") != 0 )
        as_Range = "Range3";
    else
        return false;


    if ( as.Pos("up") != 0 )
    {
        as_up_down = "up";
        return true;
    }
    else if ( as.Pos("down") != 0 )
    {
        as_up_down = "down";
        return true;
    }
    else
        return false;

}


//------------------------------------------------------------------------------
bool getCOMIndex( AnsiString asStr, int *COMIndex )
{
    int iLD;

    asStr = asStr.LowerCase();
    iLD = asStr.LastDelimiter("com");
    if (iLD <= 0)
        return false;

    *COMIndex = (asStr.SubString( iLD+1, 1 )).ToInt();
    return true;
}

// EOF
