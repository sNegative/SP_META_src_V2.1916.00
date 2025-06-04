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
 *   bb_cust_hw.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband custom hardware level setting source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.7  $
 * $Modtime:   Oct 25 2005 10:53:42  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Baseband/bb_cust_hw.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Nov 7 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.7   Oct 25 2005 14:12:44   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.6   Sep 04 2005 11:00:56   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.5   Apr 18 2005 15:46:40   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.4   Jan 30 2005 17:52:48   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.3   Jan 10 2005 11:08:14   mtk00490
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
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _BB_CUST_HW_H_
#include "bb_cust_hw.h"
#endif
//===========================================================================
static const char  Battery_Level_Name[][32] =
{
    "Shutdown voltage",
    "No MO call voltage",
    "Low battery warning voltage",
    "Level 1 votage",
    "Level 2 votage",
    "Level 3 votage"
};

static CBBCUSTHW*  bb_custhw_ptr;
static bool g_bIsRunning;

//===========================================================================
static  void  CNF_ReadFromNVRAM( void )
{
    bb_custhw_ptr->CNF_ReadFromNVRAM( );
}

//---------------------------------------------------------------------------
static  void  CNF_WriteToNVRAM(void)
{
    bb_custhw_ptr->CNF_WriteToNVRAM();
}

//---------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    bb_custhw_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    bb_custhw_ptr->REQ_Finish();
}

//===========================================================================
CBBCUSTHW::CBBCUSTHW( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
    m_pcCustHwBuf = NULL;
    m_iCustHwBufSize = 0;
    m_sBBID_CUSTHW = 0;
    memset(&m_sCustomHwLevel,0,sizeof(m_sCustomHwLevel));
}

//---------------------------------------------------------------------------
CBBCUSTHW::~CBBCUSTHW( )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    if(m_pcCustHwBuf)
    {
        delete m_pcCustHwBuf;
        m_pcCustHwBuf = NULL;
    }
}

//---------------------------------------------------------------------------
void  CBBCUSTHW::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_CUST_HW_OK );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CBBCUSTHW::REQ_Stop( void )
{
    if(!g_bIsRunning)  return;

    SP_META_Cancel_r( m_META_HANDLE_Obj.Get_MainHandle(), m_sBBID_CUSTHW );
    Confirm( STATE_CUST_HW_STOP );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CBBCUSTHW::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;

    SP_META_Cancel_r( m_META_HANDLE_Obj.Get_MainHandle(), m_sBBID_CUSTHW );
    Confirm( STATE_CUST_HW_TIMEOUT );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CBBCUSTHW::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
bool  CBBCUSTHW::Decompose_CustHwLevel( void )
{
    int  i, j;
    AnsiString as_str;
    META_RESULT MetaResult;

    // PWM1
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str+ "PWM1" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &m_sCustomHwLevel.PWM1[i][j],
                         sizeof(m_sCustomHwLevel.PWM1[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // PWM2
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str + "PWM2" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &m_sCustomHwLevel.PWM2[i][j],
                         sizeof(m_sCustomHwLevel.PWM2[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // PWM3
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str + "PWM3" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &m_sCustomHwLevel.PWM3[i][j],
                         sizeof(m_sCustomHwLevel.PWM3[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // Main LCD contrast
    for( i=0; i<LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Contrast" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Contrast[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Contrast[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD bias
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Bias" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Bias[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Bias[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD linerate
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Linerate" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Linerate[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Linerate[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD temperature
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Temp" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Temp[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Temp[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD contrast
    for( i=0; i<LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Contrast" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Contrast[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Contrast[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD bias
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Bias" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Bias[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Bias[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD linerate
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Linerate" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Linerate[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Linerate[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD temperature
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Temp" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Temp[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Temp[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Battery level
    for( i=0; i<BATTERY_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "BatteryLevel" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_GetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.BatteryLevel[i],
                     sizeof(m_sCustomHwLevel.BatteryLevel[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }
    return(true);

}

//---------------------------------------------------------------------------
bool  CBBCUSTHW::Compose_CustHwLevel( void )
{
    int  i, j;
    AnsiString as_str;
    META_RESULT MetaResult;

    // PWM1
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str+ "PWM1" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &m_sCustomHwLevel.PWM1[i][j],
                         sizeof(m_sCustomHwLevel.PWM1[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // PWM2
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str + "PWM2" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult =SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                        as_str.c_str(),
                        m_pcCustHwBuf,
                        m_iCustHwBufSize,
                        &m_sCustomHwLevel.PWM2[i][j],
                        sizeof(m_sCustomHwLevel.PWM2[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // PWM3
    for( i=0; i<PWM_MAX_LEVEL; i++ )
    {
        for( j=0; j<2; j++ )
        {
            as_str = "";
            as_str = as_str + "PWM3" + "[" + IntToStr(i) + "]" + "[" + IntToStr(j) + "]";
            MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &m_sCustomHwLevel.PWM3[i][j],
                         sizeof(m_sCustomHwLevel.PWM3[i][j]) );

            if(MetaResult!=META_SUCCESS)  return(false);
        }
    }

    // Main LCD contrast
    for( i=0; i<LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Contrast" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Contrast[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Contrast[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD bias
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Bias" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Bias[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Bias[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD linerate
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Linerate" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Linerate[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Linerate[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Main LCD temperature
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "MainLCD_Temp" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.MainLCD_Temp[i],
                     sizeof(m_sCustomHwLevel.MainLCD_Temp[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD contrast
    for( i=0; i<LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Contrast" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Contrast[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Contrast[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD bias
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Bias" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Bias[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Bias[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD linerate
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Linerate" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Linerate[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Linerate[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Sub LCD temperature
    for( i=0; i<LCD_PARAM_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "SubLCD_Temp" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.SubLCD_Temp[i],
                     sizeof(m_sCustomHwLevel.SubLCD_Temp[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }

    // Battery level
    for( i=0; i<BATTERY_MAX_LEVEL; i++ )
    {
        as_str = "";
        as_str = as_str + "BatteryLevel" + "[" + IntToStr(i) + "]";
        MetaResult = SP_META_NVRAM_SetRecFieldValue( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                     as_str.c_str(),
                     m_pcCustHwBuf,
                     m_iCustHwBufSize,
                     &m_sCustomHwLevel.BatteryLevel[i],
                     sizeof(m_sCustomHwLevel.BatteryLevel[i]) );

        if(MetaResult!=META_SUCCESS)  return(false);
    }
    return(true);

}

//===========================================================================
void  CBBCUSTHW::REQ_Read_From_NVRAM( void )
{
    bb_custhw_ptr = this;
    g_bIsRunning = true;

    if(!m_pcCustHwBuf )
    {
        if(META_SUCCESS != SP_META_NVRAM_GetRecLen( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID", &m_iCustHwBufSize))
        {
            Confirm( STATE_CUST_HW_FAIL );
            return;
        }
        if(0 > m_iCustHwBufSize)
        {
            // todo output dll bug
            return;
        }
        m_pcCustHwBuf = new  char[m_iCustHwBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",  1, m_iCustHwBufSize,  m_pcCustHwBuf );
}

//-------------------------------------
void  CBBCUSTHW::CNF_ReadFromNVRAM( void )
{
    if(!g_bIsRunning)
        return;

    switch( NVRAMMan->Get_ConfirmState())
    {
    case META_SUCCESS:
        if( !Decompose_CustHwLevel())
        {
            Confirm( STATE_CUST_HW_FAIL );
            return;
        }
        ActiveMan->SetActiveFunction( ::REQ_Finish );
        break;
    case META_TIMEOUT:
        Confirm( STATE_CUST_HW_TIMEOUT );
        break;
    case METAAPP_STOP:
        Confirm( STATE_CUST_HW_STOP );
        break;
    case STATE_CUST_HW_FAIL:
        Confirm( STATE_CUST_HW_FAIL );
        break;
    }
}
//------------------------------------------------------------------------------
void  CBBCUSTHW::REQ_Write_To_NVRAM( void )
{
    bb_custhw_ptr = this;
    g_bIsRunning = true;
    META_RESULT MetaResult;

    if( NULL == m_pcCustHwBuf )
    {
        MetaResult = SP_META_NVRAM_GetRecLen( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                                              &m_iCustHwBufSize );

        if(MetaResult!=META_SUCCESS)
        {
            Confirm( STATE_CUST_HW_FAIL );
            return;
        }
        m_pcCustHwBuf = new  char[m_iCustHwBufSize];
    }

    if( !Compose_CustHwLevel() )
    {
        Confirm( STATE_CUST_HW_FAIL );
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start( "NVRAM_EF_CUST_HW_LEVEL_TBL_LID",
                                    1, // temp set to 1
                                    m_iCustHwBufSize,
                                    m_pcCustHwBuf );
}

//-------------------------------------
void  CBBCUSTHW::CNF_WriteToNVRAM( void )
{
    if(!g_bIsRunning)  return;

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }
    break;

    case META_TIMEOUT:
    {
        Confirm( STATE_CUST_HW_TIMEOUT );
    }
    break;

    case METAAPP_STOP:
    {
        Confirm( STATE_CUST_HW_STOP );
    }
    break;

    case META_FAILED:
    {
        Confirm( STATE_CUST_HW_FAIL );
    }
    break;
    }
}

//===========================================================================
bool  CBBCUSTHW::REQ_Read_From_File( char *filename )
{
    TIniFile   *ini_file;
    int         i;
    AnsiString  as_str;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    for( i=0; i<VISIBLE_BATTERY_LEVEL_NUM; i++ )
    {
        as_str = ini_file->ReadString( "Battery level",
                                       Battery_Level_Name[i],
                                       "0" );
        m_sCustomHwLevel.BatteryLevel[i] = as_str.ToInt();
    }

    delete  ini_file;

    return  true;

}

//------------------------------------------------------------------------
bool   CBBCUSTHW::REQ_Write_To_File( char *filename )
{
    TIniFile   *ini_file;
    int         i;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    for( i=0; i<VISIBLE_BATTERY_LEVEL_NUM; i++ )
    {
        ini_file->WriteString( "Battery level",
                               Battery_Level_Name[i],
                               IntToStr( m_sCustomHwLevel.BatteryLevel[i] ) );
    }

    delete  ini_file;
    return  true;
}

//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
int  CBBCUSTHW::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

//--------------------------------------------------------------------------
S_CUSTOM_HW_LEVEL  CBBCUSTHW::Get_CustomHwLevel( void )
{
    return  m_sCustomHwLevel;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int CBBCUSTHW::Get_BatteryLevel( int idx )
{
    return m_sCustomHwLevel.BatteryLevel[idx];
}

//--------------------------------------------------------------------------
void CBBCUSTHW::Set_BatteryLevel( int idx, unsigned int level )
{
    m_sCustomHwLevel.BatteryLevel[idx] = level;
}
