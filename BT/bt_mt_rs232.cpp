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
 *   bt_mt_rs232.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test through RS232 source
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
 * Feb 25 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef _BT_MT_RS232_H_
#include "bt_mt_rs232.h"
#endif

//=============================================================================
CBTMTRS232::CBTMTRS232(void)
{
    EventLen  = 0;
    EventType = EVTTYPE_NONE;
    memset(EventBuf,0,sizeof(unsigned char)*HCIEVENTBUFSIZE);
}

//-----------------------------------------------
bool CBTMTRS232::SetTransport(int port_no, long baudrate, int ena_flowctrl)
{
    bool ok;
    ok = rs232.Open(port_no, baudrate, 8, 0, 0, 0, ena_flowctrl, 0);
    return ok;
}

//-----------------------------------------------
int CBTMTRS232::SendCommand(unsigned char *command, int len)
{
    int ok;
    ok = rs232.SendData(command, len);
    return ok;
}

//-----------------------------------------------
int CBTMTRS232::ReadEvent(void)
{
    int len, len2;
    unsigned char *p, ch;
    long  last_read_pos;
    int  ok;

    last_read_pos = rs232.pos_read;
    len = rs232.ReadData( &ch, 1 ) ;
    if (len==0)
    {
        return 0;
    }
    ok = 0;
    EventLen = len;
    p = EventBuf;
    *p++ = ch;
    if (ch==0x04)      // HCI_event
    {
        EventType = EVTTYPE_EVENT;
        len = rs232.ReadData( p, 2 ) ;
        EventLen += len;
        if (len==2)
        {
            len = p[1];
            p = &(p[2]);
            ok = 1;
        }
    }
    else if (ch==0x03)  // SCO Data
    {
        EventType = EVTTYPE_SCO;
        len = rs232.ReadData( p, 3 ) ;
        EventLen += len;
        if (len==3)
        {
            len = p[2];
            p = &(p[3]);
            ok = 1;
        }
    }
    else if (ch==0x02)  // ACL Data
    {
        EventType = EVTTYPE_ACL;
        len = rs232.ReadData( p, 4 ) ;
        EventLen += len;
        if (len==4)
        {
            len = (p[3]<<8)+p[2];
            p = &(p[4]);
            ok = 1;
        }
    }
    else
    {
    }
    if (ok)
    {
        len2 = rs232.ReadData( p, len) ;
        EventLen += len2;
        if (len!=len2)
        {
            ok = 0;
        }
    }
    if (!ok)
    {
        EventType = EVTTYPE_NONE;
        rs232.pos_read = last_read_pos;
        ConsumeErrorEvent();
        rs232.LogRXQposition();
        return 0;
    }
    rs232.LogRXQposition();
    return 1;
}

//-----------------------------------------------
void  CBTMTRS232::ConsumeErrorEvent(void )
{
}
//=============================================================================
