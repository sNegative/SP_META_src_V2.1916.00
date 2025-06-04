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
 *  time_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  time utility source
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
 * $Modtime:   Oct 25 2005 12:24:50  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/time_utils.cpp-arc  $
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.1   Oct 25 2005 14:15:32   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.0   Sep 04 2005 11:24:28   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#pragma hdrstop

#ifndef  _TIME_UTILS_H_
#include "time_utils.h"
#endif

//----------------------------------------------------------------------------
S_TIME Get_CurrentTime( void )
{
    S_TIME  stime;
    TDateTime datetime;
    TDateTime current_time = datetime.CurrentTime();

    current_time.DecodeTime( &stime.hour, &stime.min, &stime.sec, &stime.msec );

    return stime;
}

//-------------------------------------------------------------------------------
AnsiString CurrentTimeStr( void )
{
    AnsiString as_str;
    S_TIME  stime = Get_CurrentTime();
    AnsiString as_hour;
    AnsiString as_min;
    AnsiString as_sec;
    AnsiString as_msec;

    as_hour.sprintf( "%2d", stime.hour );
    as_min.sprintf( "%2d", stime.min );
    as_sec.sprintf( "%2d", stime.sec );
    as_msec.sprintf( "%3d", stime.msec );

    as_str = as_hour + ":" + as_min + ":" + as_sec +  "." + as_msec;

    return as_str;
}

//-----------------------------------------------------------------------------
int TransferToSec( S_TIME *p_time )
{
    return (p_time->hour*60*60 + p_time->min*60 + p_time->sec);
}

//-----------------------------------------------------------------------------
int DifferenceSec(S_TIME *p_start_time, S_TIME *p_end_time)
{
    int start_time_sec = TransferToSec( p_start_time );
    int end_time_sec = TransferToSec( p_end_time );

    if( start_time_sec <= end_time_sec )
    {
        return ( end_time_sec - start_time_sec );
    }
    else
    {
        return (end_time_sec + 24*60*60 - start_time_sec);
    }
}

//-----------------------------------------------------------------------------
int TransferToMiniSec( S_TIME *p_time )
{
    return (p_time->hour*60*60*1000 + p_time->min*60*1000 + p_time->sec*1000 + p_time->msec);
}

//-----------------------------------------------------------------------------
int DifferenceMiniSec(S_TIME *p_start_time, S_TIME *p_end_time)
{
    int start_time_msec = TransferToMiniSec( p_start_time );
    int end_time_msec = TransferToMiniSec( p_end_time );

    if( start_time_msec <= end_time_msec )
    {
        return ( end_time_msec - start_time_msec );
    }
    else
    {
        return (end_time_msec + 24*60*60*1000 - start_time_msec);
    }
}


