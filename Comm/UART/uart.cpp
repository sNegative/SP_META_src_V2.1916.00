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
 *   uart.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   UART handling source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.2  $
 * $Modtime:   Oct 25 2005 10:55:04  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Comm/UART/uart.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 *    Rev 1.2   Oct 25 2005 14:12:48   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.1   Sep 04 2005 11:01:04   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.0   Apr 18 2005 15:57:50   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stdio.h>
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif

#include "uart.h"

//===========================================================================

static CUART*  uart_ptr;

//===========================================================================

//---------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    uart_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    uart_ptr->REQ_Finish();
}

//===========================================================================
CUART::CUART( void )
{
    IsRunning = false;
    ConfirmCallback = 0;
    // RFReq_ID = NULL;
    ConfirmState = 0;
}

//---------------------------------------------------------------------------
CUART::~CUART()
{
    IsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
void  CUART::REQ_Finish( void )
{
    if(!IsRunning)  return;

    Confirm( STATE_UART_OK );
    IsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CUART::REQ_Stop( void )
{
    if(!IsRunning)  return;

    Confirm( STATE_UART_STOP );
    IsRunning = false;
}      */

//---------------------------------------------------------------------------
void  CUART::REQ_TimeOut( void )
{
    if(!IsRunning)  return;

    Confirm( STATE_UART_TIMEOUT );
    IsRunning = false;
}

//---------------------------------------------------------------------------
void  CUART::Confirm( int confirm_state )
{
    if(!IsRunning)  return;

    if(ConfirmCallback==0)  return;
    ConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
bool  CUART::UART_Open( HANDLE  &hCOM, sUART uart )
{
    char  str[20];

    sprintf( str, "\\\\.\\COM%d", uart.com_port );
    hCOM = ::CreateFile( str,
                         GENERIC_READ|GENERIC_WRITE,
                         0,
                         NULL,
                         OPEN_EXISTING,
                         0,
                         NULL
                       );

    if( hCOM==INVALID_HANDLE_VALUE || hCOM == 0)
    {
        //MSG_CHECK_ERROR( MSG_ERR_OPEN_COM_FAIL );
        hCOM = NULL;
        return false;
    }

    DCB dcb;
    if(! ::GetCommState( hCOM, &dcb ) )
    {
        hCOM = NULL;
        return false;
    }
    original_dcb = dcb;
    dcb.fBinary           = true;
    dcb.fParity           = true;
    dcb.fOutxCtsFlow      = false;
    dcb.fOutxDsrFlow      = false;
    dcb.fDtrControl       = DTR_CONTROL_DISABLE;
    dcb.fDsrSensitivity   = false;
    dcb.fTXContinueOnXoff = false;
    dcb.fOutX             = false;
    dcb.fInX              = false;
    dcb.fErrorChar        = false;
    dcb.fNull             = false;
    dcb.fRtsControl       = RTS_CONTROL_DISABLE;
    dcb.wReserved         = 0;

    dcb.fAbortOnError     = false;
    dcb.BaudRate        = uart.baud_rate;
    dcb.ByteSize        = uart.byte_size;
    dcb.Parity          = uart.parity;
    dcb.StopBits        = uart.stop_bits;
    if(! ::SetCommState( hCOM, &dcb ) )
    {
        hCOM = NULL;
        return false;
    }
    return  true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CUART::UART_GetCommTimeouts( HANDLE hCOM, COMMTIMEOUTS &timeout)
{
    if( ! ::GetCommTimeouts( hCOM, &timeout ) )   return false;

    return true;
}

//------------------------------------------------------------------------
bool  CUART::UART_SetCommTimeouts( HANDLE hCOM, COMMTIMEOUTS timeout)
{
    if( ! ::SetCommTimeouts( hCOM, &timeout ) )   return false;

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CUART::UART_GetCommMask( HANDLE hCOM, DWORD &dwEvtMask )
{
    if( ! ::GetCommMask( hCOM, &dwEvtMask) )   return false;

    return true;
}

//--------------------------------------------------------------------------
bool  CUART::UART_SetCommMask( HANDLE hCOM, DWORD dwEvtMask )
{
    if( ! ::SetCommMask(hCOM, dwEvtMask) )   return false;

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CUART::UART_EscapeCommFunction( HANDLE hCOM, DWORD dwFunc )
{
    if( ! ::EscapeCommFunction(hCOM, dwFunc) )   return false;

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CUART::UART_SendData( HANDLE hCOM, char* p_data )
{
    if( hCOM == INVALID_HANDLE_VALUE || hCOM == NULL)   return false;

    int len = 0;
    unsigned long rlen;
    for(int i=0; i<MAX_COM_BUF_LEN; i++)
    {
        if( *(p_data+i) == '\0' )
        {
            len = i;
            break;
        }
    }

    if( ! ::WriteFile( hCOM, p_data, len, &rlen, NULL ) ) return false;

    return true;
}

//------------------------------------------------------------------------
bool  CUART::UART_ReceiveData( HANDLE hCOM, char* p_data, DWORD  &dw_byte_read )
{
    char buf[MAX_COM_BUF_LEN];
    DWORD  dw_err;
    COMSTAT com_stat;

    if( hCOM == INVALID_HANDLE_VALUE || hCOM == NULL)     return false;

    if( ! ::ClearCommError( hCOM, &dw_err, &com_stat ) )  return false;

    if( com_stat.cbInQue > sizeof(buf) )
    {
        PurgeComm( hCOM, PURGE_RXCLEAR );
        return false;
    }

    if( ! ::ReadFile( hCOM, p_data, com_stat.cbInQue, &dw_byte_read, NULL ) )  return false;

    return true;
}

//------------------------------------------------------------------------
bool  CUART::UART_Close( HANDLE hCOM )
{
    if( hCOM == INVALID_HANDLE_VALUE || hCOM == 0)   return false;
    if(! ::SetCommState(hCOM, &original_dcb) )       return false;
    if(! ::CloseHandle( hCOM ) )                     return false;
    return true;
}

//===========================================================================
////////////////////////////    Global information   ////////////////////////
//===========================================================================
int  CUART::Get_ConfirmState( void )
{
    return ConfirmState;
}

//---------------------------------------------------------------------------
DCB CUART::Get_OriginalDCB( void )
{
    return  original_dcb;

}

//---------------------------------------------------------------------------
bool CUART::Set_OriginalDCB( DCB &dcb )
{
    original_dcb = dcb;
    return true;
}
