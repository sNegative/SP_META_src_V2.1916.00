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
 *   com_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  COM port utility source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.10  $
 * $Modtime:   Oct 25 2005 11:11:58  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/factory/com_utils.cpp-arc  $
 *
 *    Rev 1.10   Oct 25 2005 14:13:16   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:01:32   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:47:08   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:53:40   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:08:58   mtk00490
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



#include <windows.h>
#include <stdio.h>

#pragma hdrstop

DCB dcb;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool open_com_port( HANDLE &hCOM_HANDLE, int i_com_port, int i_baud_rate)
{
    if ( hCOM_HANDLE != NULL && hCOM_HANDLE != INVALID_HANDLE_VALUE )
    {
        PurgeComm( hCOM_HANDLE, PURGE_TXABORT);
        PurgeComm( hCOM_HANDLE, PURGE_RXABORT);
        PurgeComm( hCOM_HANDLE, PURGE_TXCLEAR);
        PurgeComm( hCOM_HANDLE, PURGE_RXCLEAR);
        CloseHandle( hCOM_HANDLE);
        hCOM_HANDLE = NULL;
    }

    char c_com[50];
    ::sprintf(c_com, "\\\\.\\COM%d", i_com_port);

    hCOM_HANDLE = ::CreateFile( c_com,
                                GENERIC_READ|GENERIC_WRITE,
                                0,
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if( hCOM_HANDLE==INVALID_HANDLE_VALUE )
    {
//            ShowMessage(" COM" + IntToStr( i_com_port) + " is used by other program.");
        hCOM_HANDLE = NULL;
        return false;
    }

    if( ::SetupComm(hCOM_HANDLE, 8192, 8192)==FALSE )
        return false;

    if( ::PurgeComm(hCOM_HANDLE, PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR)==FALSE )
        return false;

    COMMTIMEOUTS TimeOut;
    TimeOut.ReadIntervalTimeout = 0;
    TimeOut.ReadTotalTimeoutMultiplier = 1;
    TimeOut.ReadTotalTimeoutConstant = 700;
    TimeOut.WriteTotalTimeoutMultiplier = 1;
    TimeOut.WriteTotalTimeoutConstant = 700;

    SetCommTimeouts(hCOM_HANDLE, &TimeOut);

    char c_dcb[50];
    ::sprintf( c_dcb, "%d,n,8,1", i_baud_rate);

    BuildCommDCB( c_dcb, &dcb );

    SetCommState( hCOM_HANDLE, &dcb );
    return true;
}
//------------------------------------------------------------------------------

bool set_com_port( HANDLE &hCOM_HANDLE, int i_baud_rate)
{
    if( hCOM_HANDLE==INVALID_HANDLE_VALUE )
    {
        hCOM_HANDLE = NULL;
        return false;
    }

    if( hCOM_HANDLE==NULL )
    {
        return false;
    }

    if ( PurgeComm( hCOM_HANDLE, PURGE_TXABORT)==0 || PurgeComm( hCOM_HANDLE, PURGE_RXABORT)==0 ||
            PurgeComm( hCOM_HANDLE, PURGE_TXCLEAR)==0 || PurgeComm( hCOM_HANDLE, PURGE_RXCLEAR)==0 )
    {
        return false;
    }

    if( ::SetupComm(hCOM_HANDLE, 8192, 8192)==FALSE )
        return false;

    if( ::PurgeComm(hCOM_HANDLE, PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR)==FALSE )
        return false;

    COMMTIMEOUTS TimeOut;
    TimeOut.ReadIntervalTimeout = 0;
    TimeOut.ReadTotalTimeoutMultiplier = 1;
    TimeOut.ReadTotalTimeoutConstant = 700;
    TimeOut.WriteTotalTimeoutMultiplier = 1;
    TimeOut.WriteTotalTimeoutConstant = 700;

    SetCommTimeouts( hCOM_HANDLE, &TimeOut);

    char c_dcb[50];
    ::sprintf( c_dcb, "%d,n,8,1", i_baud_rate);

    BuildCommDCB( c_dcb, &dcb );

    SetCommState( hCOM_HANDLE, &dcb );
    return true;
}


//------------------------------------------------------------------------------
void close_com_port( HANDLE &hCOM_HANDLE  )
{
    if ( hCOM_HANDLE != NULL && hCOM_HANDLE != INVALID_HANDLE_VALUE )
    {
        PurgeComm( hCOM_HANDLE, PURGE_TXABORT);
        PurgeComm( hCOM_HANDLE, PURGE_RXABORT);
        PurgeComm( hCOM_HANDLE, PURGE_TXCLEAR);
        PurgeComm( hCOM_HANDLE, PURGE_RXCLEAR);
        CloseHandle( hCOM_HANDLE);
        hCOM_HANDLE = NULL;
    }
    if ( hCOM_HANDLE == INVALID_HANDLE_VALUE )
    {
        hCOM_HANDLE = NULL;
    }
}

//------------------------------------------------------------------------------



