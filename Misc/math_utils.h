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
 *   math_utils.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Math utility header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.9  $
 * $Modtime:   Oct 25 2005 12:24:00  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/math_utils.h-arc  $
 *
 * Jul 16 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.9   Oct 25 2005 14:15:30   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.8   Sep 04 2005 11:07:06   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.7   Apr 18 2005 15:49:24   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.6   Jan 30 2005 17:58:16   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef  _MATH_UTILS_H_
#define  _MATH_UTILS_H_
/*---------------------------------------------------------------------------*/
extern  double  Round_double( double d_in );
extern  double  Abs_double( double d_in );
extern  bool    AbsOfComplexArray( double *d_A, double *d_B, int size, double *d_ABS );
extern  bool    MaxOfDoubleArray( double *d_A, int size, double *d_max );
extern  double  SumOfDoubleArray( double *d_A, int size );
// algorithm
extern int SortByIncreasing( const void *v1, const void *v2 );
extern void LinearRegression(int i_n, double* p_dx, double* p_dy, double &d_a, double& d_b);
#endif
