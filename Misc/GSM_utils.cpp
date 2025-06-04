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
 *  GSM_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  GSM utility source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.6  $
 * $Modtime:   Oct 25 2005 12:23:14  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/GSM_utils.cpp-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <assert.h>

#pragma hdrstop


#ifndef  _GSM_UTILS_H_
#include "gsm_utils.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef _APCCAL_COMMON_H_
#include "apccal_common.h"
#endif

#ifndef age1960_INCLUDE
#include "age1960.h"
#endif

//---------------------------------------------------------------------------
bool getCenterFreq(FrequencyBand Band, int ARFCN, bool isDownlink, double *CenterFreq)
{
    switch (Band)
    {
    case FrequencyBand850:
    {
        if (128<=ARFCN && ARFCN<=251)
        {
            if (!isDownlink)
            {
                *CenterFreq = 824.2 + 0.2*(ARFCN-128);
            }
            else
            {
                *CenterFreq = 824.2 + 0.2*(ARFCN-128) + 45.0;
            }
        }
        else
        {
            return false;
        }
    }
    break;

    case FrequencyBand900:
    {
        if (0<=ARFCN && ARFCN<= 124) // PGSM, EGSM
        {
            if (!isDownlink)
            {
                *CenterFreq = 890.0 + 0.2*ARFCN;
            }
            else
            {
                *CenterFreq = 890.0 + 0.2*ARFCN + 45.0;
            }
        }
        else if (955<=ARFCN && ARFCN<=1023) // EGSM, RGSM
        {
            if (!isDownlink)
            {
                *CenterFreq = 890.0 + 0.2*(ARFCN-1024);
            }
            else
            {
                *CenterFreq = 890.0 + 0.2*(ARFCN-1024) + 45.0;
            }
        }
        else
        {
            return false;
        }
    }
    break;

    case FrequencyBand1800:
    {
        if (512<=ARFCN && ARFCN<=885)
        {
            if( ! isDownlink )
            {
                *CenterFreq = 1710.2 + 0.2*(ARFCN-512);
            }
            else
            {
                *CenterFreq = 1710.2 + 0.2*(ARFCN-512) + 95.0;
            }
        }
        else
        {
            return false;
        }
    }
    break;

    case FrequencyBand1900:
    {
        if (512<=ARFCN && ARFCN<=810)
        {
            if( ! isDownlink )
            {
                *CenterFreq = 1850.2 + 0.2*(ARFCN-512);
            }
            else
            {
                *CenterFreq = 1850.2 + 0.2*(ARFCN-512) + 80.0;
            }
        }
        else
        {
            return false;
        }
    }
    break;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool NominalPower_To_PCL(FrequencyBand FreqBand, int dBm, int &pcl)
{
    switch (FreqBand)
    {
    case FrequencyBand850:
    case FrequencyBand900:
    {
        if( dBm > 33 || dBm < 5)  return false;
        pcl = GSM900_FIRST_PCL - dBm/2 + 2;
    }
    break;

    case FrequencyBand1800:
    case FrequencyBand1900:
    {
        if( dBm > 30 || dBm < 0 )  return false;
        pcl = DCS1800_FIRST_PCL - dBm/2;
    }
    break;

    default:
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------
bool PCL_To_NominalPower(FrequencyBand FreqBand, int pcl, int &dBm)
{
    switch( FreqBand )
    {
    case FrequencyBand850:
    case FrequencyBand900:
    {
        if( pcl < GSM900_LAST_PCL || pcl > GSM900_FIRST_PCL )  return false;
        dBm = ( GSM900_FIRST_PCL + 2 - pcl ) * 2 + 1;
    }
    break;

    case FrequencyBand1800:
    case FrequencyBand1900:
    {
        if( pcl < DCS1800_LAST_PCL || pcl > DCS1800_FIRST_PCL )  return false;
        dBm = ( DCS1800_FIRST_PCL - pcl ) * 2;
    }
    break;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
short dBm_To_PCL(E_BANDSEL BandSel, double dBm)
{
    short pcl;
    switch (BandSel)
    {
    case BANDSEL_GSM850:
    case BANDSEL_GSM900:
    {
        if (dBm > 32)
        {
            pcl = 5;
        }
        else if ((dBm >= 6)  && (dBm <= 32))
        {
            pcl = (short) 19 - (dBm - 5) / 2;
        }
        else
        {
            pcl = 19;
        }
    }
    break;

    case BANDSEL_DCS1800:
    case BANDSEL_PCS1900:
    {
        if (dBm > 30)
        {
            pcl = 0;
        }
        else if ((dBm >= 0)  && (dBm <= 30))
        {
            pcl = (short) 15 - dBm / 2;
        }
        else
        {
            pcl = 15;
        }
    }
    break;

    default:
    {
        assert(false);
    }
    break;
    }
    return pcl;
}

//---------------------------------------------------------------------------
bool PCL_To_PCLIndex(E_BANDSEL BandSel, short pcl, short &pcl_idx)
{
    switch (BandSel)
    {
    case BANDSEL_GSM850:
    case BANDSEL_GSM900:
    {
        if ((pcl >= GSM900_LAST_PCL) && (pcl <= GSM900_FIRST_PCL))
        {
            pcl_idx = GSM900_FIRST_PCL - pcl;
        }
        else
        {
            return false;
        }
    }
    break;

    case BANDSEL_DCS1800:
    case BANDSEL_PCS1900:
    {
        if ((pcl >= DCS1800_LAST_PCL) && (pcl <= DCS1800_FIRST_PCL))
        {
            pcl_idx = DCS1800_FIRST_PCL - pcl;
        }
        else
        {
            return false;
        }
    }
    break;

    default:
    {
        return false;
    }
    }

    return true;
}

//---------------------------------------------------------------------------
bool PCLIndex_To_PCL(E_BANDSEL BandSel, short pcl_idx, short &pcl)
{
    switch (BandSel)
    {
    case BANDSEL_GSM850:
    case BANDSEL_GSM900:
    {
        if ((pcl_idx >= 0) && (pcl < TOTAL_GSM_PCL_NUM))
        {
            pcl = GSM900_LAST_PCL + pcl_idx;
        }
        else
        {
            return false;
        }
    }
    break;

    case BANDSEL_DCS1800:
    case BANDSEL_PCS1900:
    {
        if ((pcl_idx >= 0) && (pcl < TOTAL_DCS_PCL_NUM))
        {
            pcl = DCS1800_LAST_PCL + pcl_idx;
        }
        else
        {
            return false;
        }
    }
    break;

    default:
    {
        return false;
    }
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
short Get_FirstPCL(E_BANDSEL BandSel)
{
    short pcl;
    switch (BandSel)
    {
    case BANDSEL_GSM900:
    {
        pcl = GSM900_FIRST_PCL;
    }
    break;

    case BANDSEL_DCS1800:
    {
        pcl = DCS1800_FIRST_PCL;
    }
    break;

    case BANDSEL_PCS1900:
    {
        pcl = PCS1900_FIRST_PCL;
    }
    break;

    case BANDSEL_GSM850:
    {
        pcl = GSM850_FIRST_PCL;
    }
    break;

    default:
    {
        assert(false);
    }
    break;
    }
    return pcl;
}

//---------------------------------------------------------------------------
short Get_LastPCL(E_BANDSEL BandSel)
{
    short pcl;
    switch (BandSel)
    {
    case BANDSEL_GSM900:
    {
        pcl = GSM900_LAST_PCL;
    }
    break;

    case BANDSEL_DCS1800:
    {
        pcl = DCS1800_LAST_PCL;
    }
    break;

    case BANDSEL_PCS1900:
    {
        pcl = PCS1900_LAST_PCL;
    }
    break;

    case BANDSEL_GSM850:
    {
        pcl = GSM850_LAST_PCL;
    }
    break;

    default:
    {
        assert(false);
    }
    break;
    }
    return pcl;
}

//===========================================================================
//////////////////////////////  Channel   ///////////////////////////////////
//---------------------------------------------------------------------------
short Get_SeperateChannel(int vi_band, short arfcn)
{
    short sep_arfcn;
    switch( vi_band )
    {
    case age1960_GSM850_BAND:
    {
        if( arfcn != (int)age1960_GSM850_MIN_CH )
        {
            sep_arfcn = age1960_GSM850_MIN_CH;
        }
        else
        {
            sep_arfcn = age1960_GSM850_MAX_CH;
        }
    }
    break;

    case age1960_PGSM_BAND:
    {
        if( arfcn != (int)age1960_EGSM_MIN_CH_1 )
        {
            sep_arfcn = age1960_EGSM_MIN_CH_1;
        }
        else
        {
            sep_arfcn = age1960_EGSM_MAX_CH_1;
        }
    }
    break;

    case age1960_EGSM_BAND:
    {
        if( arfcn != (int)age1960_EGSM_MIN_CH_2 )
        {
            sep_arfcn = age1960_EGSM_MIN_CH_2;
        }
        else
        {
            sep_arfcn = age1960_EGSM_MAX_CH_2;
        }
    }
    break;

    case age1960_DCS1800_BAND:
    {
        if( arfcn != (int)age1960_DCS1800_MIN_CH )
        {
            sep_arfcn = age1960_DCS1800_MIN_CH;
        }
        else
        {
            sep_arfcn = age1960_DCS1800_MAX_CH;
        }
    }
    break;

    case age1960_PCS1900_BAND:
    {
        if( arfcn != (int)age1960_PCS1900_MIN_CH )
        {
            sep_arfcn = age1960_PCS1900_MIN_CH;
        }
        else
        {
            sep_arfcn = age1960_PCS1900_MAX_CH;
        }
    }
    break;

    }

    return sep_arfcn;
}
