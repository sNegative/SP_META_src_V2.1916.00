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
 *   RS232 handling for BT module test source
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
#include <process.h>    /* _beginthread, _endthread */
#include <assert.h>
#include "string.h"
#include "stdio.h"
#include  "rs232.h"

//=============================================================================
#define RXQUEUESIZE     4096
#define TXQUEUESIZE     4096
//=============================================================================
CRS232::CRS232(void)
{
    m_bConnected = false;
    pos_write = 0;
    pos_read  = 0;
    pos_wrap  = UART_WRAPPOS;
    LogEnable = true;
//   LogEnable = false;
    LogString[0]=0;
    m_PortNo = 0;

    memset(&m_osWrite, 0, sizeof(OVERLAPPED));
    memset(&m_osRead, 0, sizeof(OVERLAPPED));
    m_osRead.hEvent  = CreateEvent(NULL,  TRUE, FALSE, NULL);
    m_osWrite.hEvent = CreateEvent(NULL,  TRUE, FALSE, NULL);
    /* for thread handle :
       memset( ThreadBuffer, 0, sizeof(ThreadBuffer));
       m_hThread        =  CreateEvent( NULL, FALSE, FALSE, NULL  );
    */
    m_hPort = NULL;
    LogStrPtr = NULL;
}

//-----------------------------------------------
CRS232::~CRS232(void)
{
    if (m_bConnected)
    {
        Close();
    }
    CloseHandle(m_osRead.hEvent);
    CloseHandle(m_osWrite.hEvent);
    /* for thread handle :
       CloseHandle(  m_hThread   );
    */
}

//-----------------------------------------------
/*
   CreatFile --> SetCommState --> SetCommMask --> SetupComm --> SetCommTimeouts --> _beginthread
*/
bool CRS232::Open(int port_no, long baudrate, int data_bit, int stop_bit, int parity,int ena_dts_rts, int ena_rts_cts, int ena_xon_xoff)
{
    char szComPort[] = "\\\\.\\COM99";
    DWORD dwBaudRate = (DWORD)baudrate;
    BYTE cByteSize   = (BYTE)data_bit;
    BYTE cStopBits   = (BYTE)stop_bit;
    BYTE cParity     = (BYTE)parity;
    bool bDTR_DSR    = (bool)(ena_dts_rts!=0);
    bool bRTS_CTS    = (bool)(ena_rts_cts!=0);
    bool bXON_XOFF   = (bool)(ena_xon_xoff!=0);
    int ok;

    if (m_bConnected )
        return  FALSE;

    if(port_no<10)
    {
        szComPort[7] = '0'+port_no;
        szComPort[8] = 0;
    }
    else
    {
        szComPort[7] = '0'+port_no/10;
        szComPort[8] = '0'+port_no%10;
        szComPort[9] = 0;
    }
    m_PortNo = port_no;
    SetEvent(m_osWrite.hEvent);
    m_hPort  =  CreateFile( szComPort, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0/*FILE_FLAG_OVERLAPPED*/,  NULL );
    if( m_hPort==INVALID_HANDLE_VALUE )
        return  FALSE;

    DCB  dcb;
    dcb.DCBlength    =  sizeof(DCB);
    GetCommState( m_hPort,&dcb );
    dcb.BaudRate     = dwBaudRate;
    dcb.ByteSize     = cByteSize;
    dcb.Parity       = cParity;
    dcb.StopBits     = cStopBits;
    dcb.fOutxDsrFlow = (bDTR_DSR!=0);
    dcb.fDtrControl  = (bDTR_DSR) ? DTR_CONTROL_HANDSHAKE : DTR_CONTROL_ENABLE;
    dcb.fOutxCtsFlow = (bRTS_CTS!=0);
    dcb.fRtsControl  = (bRTS_CTS)  ? RTS_CONTROL_HANDSHAKE : RTS_CONTROL_ENABLE;
    dcb.fInX         = (bXON_XOFF!=0);
    dcb.fOutX        = (bXON_XOFF!=0);
    dcb.fBinary      = TRUE  ;
    dcb.fParity      = TRUE  ;
    ok = SetCommState(m_hPort,&dcb);
    if(!ok)
    {
        m_bConnected =  FALSE  ;
        CloseHandle( m_hPort )  ;
        return  FALSE;
    }

    SetCommMask( m_hPort, EV_RXCHAR|EV_TXEMPTY );
    SetupComm(m_hPort, RXQUEUESIZE /*InQueue size*/ , TXQUEUESIZE /*OutQueue size*/);

    COMMTIMEOUTS CommTimeOuts  ;
    CommTimeOuts.ReadIntervalTimeout         =  MAXDWORD;
    CommTimeOuts.ReadTotalTimeoutMultiplier  =  0;
    CommTimeOuts.ReadTotalTimeoutConstant    =  0;
    CommTimeOuts.WriteTotalTimeoutMultiplier =  0;
    CommTimeOuts.WriteTotalTimeoutConstant   =  0;
    SetCommTimeouts(  m_hPort,  &CommTimeOuts  );
    pos_read = 0;
    pos_write = 0;
    pos_wrap = UART_WRAPPOS;

    m_bConnected  =  TRUE  ;
    /* for thread handle :
       m_hThreadOrg = (HANDLE)_beginthread( CommThreadProc, 4096, (void*)this );
    */
    return  TRUE;
}
//-----------------------------------------------

bool CRS232::Close( void )
{
    if( !m_bConnected )
        return FALSE;
    m_bConnected = FALSE;
    m_PortNo = 0;
    /* for thread handle :
       SetEvent(m_hThread);
    */
    SetCommMask( m_hPort, 0 );
    EscapeCommFunction( m_hPort, CLRDTR );
    CloseHandle(m_hPort);
    return TRUE;
}
//-----------------------------------------------

int  CRS232::PutData2Buf( void *data, int len)
{
    UINT16 w = pos_write;
    UINT16 r = pos_read;
    UINT8 *p = (UINT8*)data;;
    int n = 0;
    //int x;

    if(LogEnable)
    {
        LogStrPtr = LogString;
        LogStrPtr += sprintf( LogStrPtr, "COM%d RX (%d) : ", (int)m_PortNo, (int)len);
        for(n=0; n<len; n++)
        {
            LogStrPtr += sprintf( LogStrPtr, "%02X ", (int)p[n]);
        }
        LogStrPtr += sprintf( LogStrPtr, " \n" );
    }
    for(n=0; n<len; n++)
    {
        RXBuf[w++]=*p++;
        if(w==r)  break;
    }
    if(w>=UART_WRAPPOS)
    {
        pos_wrap = w;
        w = 0;
    }
    pos_write = w;
    LogRXQposition();
    return(n);
}
//-----------------------------------------------

int  CRS232::ReadUartData( void )
{
    COMSTAT  com_stat;
    DWORD    err_flags;
    DWORD    read_len = 0;
    DWORD    rxlen = UART_BUFSIZE-UART_WRAPPOS;
    UINT16   w = pos_write;
    UINT16   r = pos_read;
    int  ok;

    ClearCommError( m_hPort, &err_flags, &com_stat);
    // decide receive count shall be min( cbInQue, UartBuff spare space)
    if( rxlen>com_stat.cbInQue )
        rxlen = com_stat.cbInQue;
    if(r>w)
        if(rxlen>(DWORD)(r-w))
            rxlen = r-w;
    ok = ReadFile( m_hPort, (void*)(&RXBuf[w]), rxlen , &read_len , &m_osRead);
    if(!ok)
    {
        if(GetLastError()==ERROR_IO_PENDING)
            if( !GetOverlappedResult(m_hPort, &m_osRead, &rxlen, TRUE) )
                ClearCommError(  m_hPort,  &err_flags,  &com_stat  );
        return(0);
    }
    else if(read_len>0)
    {
        if(LogEnable)
        {
            LogStrPtr = LogString;
            LogStrPtr += sprintf( LogStrPtr, "COM%d RX (%d) : ",(int)m_PortNo, (int)read_len);
            for(DWORD n=0; n<read_len; n++)
            {
                LogStrPtr += sprintf( LogStrPtr, "%02X ", (int)(RXBuf[w+n]));
            }
            LogStrPtr += sprintf( LogStrPtr, " \n" );
        }
        w += read_len;
        if(w>UART_WRAPPOS)
        {
            pos_wrap = w;
            w = 0;
        }
        pos_write = w;
        LogRXQposition();
    }

    return(read_len);
}
//-----------------------------------------------

int  CRS232::ReadData( void *buf, int maxlen )
{
    UINT16 w = pos_write;
    UINT16 r = pos_read;
    UINT8 *p = (UINT8*)buf;
    int n;

    ReadUartData();
    for(n=0; (n<maxlen)&&(r!=w); n++)
    {
        p[n] = RXBuf[r++];
        if(r>=pos_wrap)  r = 0;
    }
    pos_read = r;
    return(n);
}


//-----------------------------------------------

int CRS232::SendData( void *buf, int len )
{
    DWORD  write_size = 0;
    DWORD  err_flags;
    COMSTAT  com_stat;
    int ok;

    if( !m_bConnected )
        return(0);
    if( WaitForSingleObject( m_osWrite.hEvent,0 )!=WAIT_OBJECT_0 )
        return(0);
    ResetEvent(m_osWrite.hEvent);
    ok = WriteFile( m_hPort, buf, len, &write_size, &m_osWrite);
    if(!ok)
    {
        if( GetLastError()==ERROR_IO_PENDING  )
            return(0);
        ClearCommError( m_hPort, &err_flags, &com_stat ) ;
        return(0);
    }
    if(LogEnable)
    {
        UINT8 *cbuf = (UINT8*)buf;
        LogStrPtr = LogString;
        LogStrPtr += sprintf( LogStrPtr, "COM%d TX (%d): ", (int)m_PortNo, (int)write_size);
        for(unsigned n=0; n<write_size; n++)
        {
            LogStrPtr += sprintf( LogStrPtr, "%02X ", (int)(cbuf[n]));
        }
        LogStrPtr += sprintf( LogStrPtr, " \n");
    }
    return(write_size);
}
//-----------------------------------------------

bool  CRS232::IsConnected( void )
{
    return  m_bConnected;
}
//-----------------------------------------------

bool  CRS232::IsRxDataReady( void )
{
    ReadUartData();
    return (pos_read!=pos_write);
}
//-----------------------------------------------

void  CRS232::LogRXQposition(void)
{
    int x;
    if(LogEnable)
    {
        if(pos_write>=pos_read)
            x = (int)(pos_write-pos_read);
        else
            x = (int)(pos_wrap-pos_read+pos_write);
        LogStrPtr += sprintf( LogStrPtr, "(r,w,cnt)=(%d,%d,%d) ", (int)pos_read, (int)pos_write, x);
        if(x!=0)
        {
            x = pos_read;
            LogStrPtr += sprintf( LogStrPtr, "Data: %02X %02X %02X %02X %02X %02X %02X %02X  ",
                                  (int)RXBuf[x+0], (int)RXBuf[x+1], (int)RXBuf[x+2], (int)RXBuf[x+3],
                                  (int)RXBuf[x+5], (int)RXBuf[x+6], (int)RXBuf[x+7], (int)RXBuf[x+8] );
        }
        LogStrPtr += sprintf( LogStrPtr, "\n");
    }
}


