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
 *   uart.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   UART handling header
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
 * $Modtime:   Oct 25 2005 10:55:18  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Comm/UART/uart.h-arc  $
 *
 *    Rev 1.2   Oct 25 2005 14:12:48   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.1   Sep 04 2005 11:01:06   mtk00490
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
#ifndef  _UART_H_
#define  _UART_H_
/*---------------------------------------------------------------------------*/
#include "meta.h"
/*---------------------------------------------------------------------------*/

#define  STATE_UART_OK          0
#define  STATE_UART_FAIL        1
#define  STATE_UART_TIMEOUT     2
#define  STATE_UART_STOP        3

#define  MAX_SUPPORT_COM_NUM   255
#define  MAX_COM_BUF_LEN      1024
/*---------------------------------------------------------------------------*/
typedef struct
{
    int com_port;
    DWORD baud_rate;
    int byte_size;
    int parity;
    int stop_bits;
}
sUART;
/*---------------------------------------------------------------------------*/

class  CUART
{
private:

    int     ConfirmState;
    DCB  original_dcb;

protected:

    bool  IsRunning;
    void  Confirm( int confirm_state );

public:

    CUART( void );
    ~CUART();

    void  (*ConfirmCallback)( void );
    void  REQ_Stop( void );
    void  REQ_Finish( void );
    void  REQ_TimeOut( void );

    bool  UART_Open( HANDLE &hCOM, sUART uart );
    bool  UART_GetCommTimeouts( HANDLE hCOM, COMMTIMEOUTS &timeout);
    bool  UART_SetCommTimeouts( HANDLE hCOM, COMMTIMEOUTS timeout);
    bool  UART_GetCommMask( HANDLE hCOM, DWORD &dwEvtMask );
    bool  UART_SetCommMask( HANDLE hCOM, DWORD dwEvtMask );
    bool  UART_EscapeCommFunction( HANDLE hCOM, DWORD dwFunc );
    bool  UART_SendData( HANDLE hCOM, char* p_data );
    bool  UART_ReceiveData( HANDLE hCOM, char* p_data, DWORD  &dw_byte_read );
    bool  UART_Close( HANDLE hCOM );
    // global information
    int   Get_ConfirmState( void );
    DCB   Get_OriginalDCB( void );
    bool  Set_OriginalDCB( DCB &dcb );

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/





};

/*---------------------------------------------------------------------------*/
#endif