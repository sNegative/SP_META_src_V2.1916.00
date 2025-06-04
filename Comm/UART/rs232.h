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
 *   rs232.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   RS232 handling for BT module test header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _RS232_H_
#define _RS232_H_
//=============================================================================
#include "windows.h"
//-----------------------------------------------

#define THREAD_BUFSIZE  4096        // thread buffer size
#define UART_BUFSIZE    (4096+1024)
#define UART_WRAPPOS    (4096)

//-----------------------------------------------

class CRS232
{
public:
// for Thread management
    /*
       HANDLE      m_hThreadOrg;
       HANDLE      m_hThread;
       UINT8       ThreadBuffer[ THREAD_BUFSIZE ];
    */

public:
    bool        m_bConnected;
    int         m_PortNo;
    HANDLE      m_hPort;
    OVERLAPPED  m_osRead,m_osWrite;

// for UART RX buffer management
    UINT8   RXBuf[UART_BUFSIZE];
    UINT16  pos_read;
    UINT16  pos_write;
    UINT16  pos_wrap;

// For debug logging
    bool    LogEnable;
    char    LogString[8196];
    char   *LogStrPtr;

public:
    CRS232( void );
    ~CRS232(  );

    int  PutData2Buf( void *data, int len);  // for debug simulation
    int  ReadUartData(void);
//public:
    /*
      port_no      = 1~99 (COM1~CM99);
      baudrate     = 9600L, 57600L, 115200L, 230400L, 460800L, 921600L
      data_bit     = 4~8
      stop_bit     = 0(1bit), 1(1.5bit), 2(2bit)
      parity       = 0(no),1(odd),2(even),3(mark),4(space)
      ena_dts_rts  = 0(disable), 1(enable)
      ena_rts_cts  = 0(disable), 1(enable)
      ena_xon_xoff = 0(disable), 1(enable)
    */
    bool  Open( int port_no=1, long baudrate=115200, int data_bit=8,
                int stop_bit=0, int parity=0, int ena_dts_rts=0, int ena_rts_cts=0, int ena_xon_xoff=0);
    bool Close( void );
    int  SendData( void *buf, int len );
    int  ReadData( void *buf, int maxlen );
    bool IsConnected( void );
    bool IsRxDataReady( void );

    void LogRXQposition(void);
};

//=============================================================================
#endif
