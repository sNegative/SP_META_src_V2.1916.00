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
 *   math_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Math utility source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.8  $
 * $Modtime:   Oct 25 2005 12:23:48  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/math_utils.cpp-arc  $
 *
 * Jul 16 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.8   Oct 25 2005 14:15:28   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.7   Sep 04 2005 11:07:04   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.6   Apr 18 2005 15:49:24   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.5   Jan 30 2005 17:58:14   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <math.h>
#include <math.hpp>


#pragma hdrstop

#ifndef  _MATH_UTILS_H_
#include "math_utils.h"
#endif
//------------------------------------------------------------------------------
double  Round_double( double d_in )
{
    double d_diff1, d_diff2, d_out;

    d_diff1 = d_in - (double)Ceil(d_in);
    d_diff2 = d_in - (double)Floor(d_in);

    if( Abs_double(d_diff1) < Abs_double(d_diff2) )
    {
        d_out = (double) Ceil(d_in);
    }
    else
    {
        d_out = (double) Floor(d_in);
    }
    return  d_out;
}

//------------------------------------------------------------------------------
double Abs_double(double d_in)
{
    double  d_out;

    if (d_in > 0)
    {
        d_out = d_in;
    }
    else
    {
        d_out = -d_in;
    }
    return d_out;
}

//------------------------------------------------------------------------------
bool AbsOfComplexArray(double *d_A, double *d_B, int size, double *d_ABS)
{
    for (int i=0; i<size; i++)
    {
        *(d_ABS+i) = sqrt(pow(*(d_A+i), 2.0) + pow(*(d_B+i), 2.0));
    }
    return true;
}

//------------------------------------------------------------------------------
bool MaxOfDoubleArray(double *d_A, int size, double *d_max)
{
    double d_temp_max = -100000;
    for (int i=0; i<size; i++)
    {
        if (*(d_A+i) > d_temp_max)
        {
            d_temp_max =  *(d_A+i);
        }
    }
    *d_max = d_temp_max;
    return  true;
}

//------------------------------------------------------------------------------
double SumOfDoubleArray(double *d_A, int size)
{
    double d_sum = 0;

    for (int i=0; i<size; i++)
    {
        d_sum += *(d_A + i);
    }
    return d_sum;
}



//------------------------------------------------------------------------------
void LinearRegression(int i_n, double* p_dx, double* p_dy, double &d_a, double& d_b)
{
    double d1 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d1 += *(p_dx+i) * (*(p_dy+i));
    }

    double d2_x = 0;
    double d2_y = 0;
    double d2 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d2_x += *(p_dx+i);
        d2_y += *(p_dy+i);
    }
    d2 = d2_x * d2_y;

    double d3 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d3 += pow(*(p_dx+i), 2.0);
    }

    double d4 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d4 += *(p_dx+i);
    }
    d4 = pow(d4, 2.0);

    d_a = (1.0* i_n * d1 - d2) / (1.0* i_n * d3 - d4);

    double d5 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d5 += *(p_dx+i);
    }

    double d6 = 0;
    for (int i = 0; i < i_n; i++)
    {
        d6 += *(p_dy+i);
    }

    d_b = d6/i_n - d_a * d5/i_n;
}
