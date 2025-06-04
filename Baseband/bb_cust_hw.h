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
 *   bb_cust_hw.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband custom hardware level setting header
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
 * $Modtime:   Oct 25 2005 10:54:04  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Baseband/bb_cust_hw.h-arc  $
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
 *    Rev 1.5   Apr 18 2005 15:46:42   mtk00490
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
#ifndef  _BB_CUST_HW_H_
#define  _BB_CUST_HW_H_

#include "meta.h"
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
/*---------------------------------------------------------------------------*/

#define  STATE_CUST_HW_OK          0
#define  STATE_CUST_HW_FAIL        1
#define  STATE_CUST_HW_TIMEOUT     2
#define  STATE_CUST_HW_STOP        3

#define PWM_MAX_LEVEL 5
#define LCD_CONTRAST_MAX_LEVEL 15
#define LCD_PARAM_MAX_LEVEL 5
#define BATTERY_MAX_LEVEL 10
#define  VISIBLE_BATTERY_LEVEL_NUM              6

typedef struct
{
    unsigned int   PWM1[PWM_MAX_LEVEL][2];  /* freq, duty */
    unsigned int   PWM2[PWM_MAX_LEVEL][2];  /* freq, duty */
    unsigned int   PWM3[PWM_MAX_LEVEL][2];  /* freq, duty */
    unsigned int   MainLCD_Contrast[LCD_CONTRAST_MAX_LEVEL];
    unsigned int   MainLCD_Bias[LCD_PARAM_MAX_LEVEL];
    unsigned int   MainLCD_Linerate[LCD_PARAM_MAX_LEVEL];
    unsigned int   MainLCD_Temp[LCD_PARAM_MAX_LEVEL];
    unsigned int   SubLCD_Contrast[LCD_CONTRAST_MAX_LEVEL];
    unsigned int   SubLCD_Bias[LCD_PARAM_MAX_LEVEL];
    unsigned int   SubLCD_Linerate[LCD_PARAM_MAX_LEVEL];
    unsigned int   SubLCD_Temp[LCD_PARAM_MAX_LEVEL];
    unsigned int   BatteryLevel[BATTERY_MAX_LEVEL];
} S_CUSTOM_HW_LEVEL;

/*---------------------------------------------------------------------------*/
class  CBBCUSTHW
{
private:
    int   m_iConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    char  *m_pcCustHwBuf;
    int    m_iCustHwBufSize;
    short  m_sBBID_CUSTHW;
    S_CUSTOM_HW_LEVEL  m_sCustomHwLevel;

protected:
    void  Confirm( int confirm_state );

public:

    CBBCUSTHW( void );
    ~CBBCUSTHW( );

    bool  Decompose_CustHwLevel( void );
    bool  Compose_CustHwLevel( void );

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );


    void  REQ_Read_From_NVRAM( void );
    void  REQ_Write_To_NVRAM( void );
    void  CNF_ReadFromNVRAM( void );
    void  CNF_WriteToNVRAM( void );
    bool  REQ_Read_From_File( char *filename );
    bool  REQ_Write_To_File( char *filename );

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)( void );

    // Public interface

    void  REQ_Stop( void );

    // Global information
    int  Get_ConfirmState( void );
    S_CUSTOM_HW_LEVEL  Get_CustomHwLevel( void );
    unsigned int Get_BatteryLevel( int idx );
    void         Set_BatteryLevel( int idx, unsigned int level );
};

/*---------------------------------------------------------------------------*/
#endif
