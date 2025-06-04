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
 *   bt_mt_parse.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test script parse source
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
#include <assert.h>

#pragma hdrstop

#ifndef _BT_MT_PARSE_H_
#include "bt_mt_parse.h"
#endif

//=============================================================================
CBTMTPARSE::CBTMTPARSE(void)
{
    Reset();
}

//-----------------------------------------------
void  CBTMTPARSE::Reset(void)
{
    int i = 0;
    int n = 0;
    for (n = 0; n < VARCOUNT; n++)
    {
        VarData[n] = 0;
    }

    for (n = 0; n < CMDSIZE; n++)
    {
        Command[n] = 0;
    }

    for (i = 0; i < MAX_EVENT_NUM; i++)
    {
        for (n = 0; n < EVTSIZE; n++)
        {
            m_ucEvent[i][n] = 0;
            m_ucEvtTag[i][n]  = 0;
            m_ucAutoEvent[i][n] = 0;
            m_ucAutoEvtTag[i][n] = 0;
        }
    }
    
    StrType = STRTYPE_NONE;
    StrValue = 0;
    StrValue2 = 0;
    StrArg1 = 0;
    StrArg2 = 0;
    StrArg3 = 0;
    StrLen = 0;
    CmdLen = 0;
    for (i = 0; i < MAX_EVENT_NUM; i++)
    {
        m_iEvtLen[i] = 0;
        m_iAutoEvtLen[i] = 0;
    }
    for (i = 0; i < STRSIZE; i++)
    {
    	  String[i] = 0;
    }
    for (i = 0; i < MAX_ACL_DATA_LEN; i++)
    {
    	  m_ucTxAclData[i] = 0;
    	  m_ucRxAclData[i] = 0;
    	  m_ucRxAclDataTag[i] = 0;
    }
    m_iTxAclDataLen = 0;
    m_iRxAclDataLen = 0;
    
}

//-----------------------------------------------
int CBTMTPARSE::PreParseString(int i_event_idx, char *str)
{
    int  v, n;
    char *p = str;

    StrType = STRTYPE_NONE;
    for( n=0; *p==' '; n++ )
    {
        p++;
    }
    if( (p[0]=='H')&&(p[1]=='C')&&(p[2]=='I') )
    {
        p = GotoDataFiled( &(p[3]), 1 );
        if(p==0)  return(0);
        GetDecimalData( p );
        StrType = STRTYPE_HCI;
    }
    else if( (p[0]=='L')&&(p[1]=='O')&&(p[2]=='G')&&(p[3]=='P')&&(p[4]=='A')&&(p[5]=='T')&&(p[6]=='H') )
    {
        p = GotoDataFiled( &(p[7]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_LOGPATH;
    }
    else if( (p[0]=='T')&&(p[1]=='I')&&(p[2]=='T')&&(p[3]=='L')&&(p[4]=='E') )
    {
        p = GotoDataFiled( &(p[5]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_TITLE;
    }
    else if( (p[0]=='P')&&(p[1]=='R')&&(p[2]=='O')&&(p[3]=='C') )
    {
        p = GotoDataFiled( &(p[4]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_PROCNAME;
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T')&&(p[4]=='P')&&(p[5]=='R')&&(p[6]=='O')&&(p[7]=='C') )
    {
        p = GotoDataFiled( &(p[8]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_WAITPROCNAME;
    }
    else if( (p[0]=='T')&&(p[1]=='I')&&(p[2]=='M')&&(p[3]=='E')&&(p[4]=='O')&&(p[5]=='U')&&(p[6]=='T') )
    {
        p = GotoDataFiled( &(p[7]), 0 );
        if(p==0)  return(0);
        GetDecimalData( p );
        StrType = STRTYPE_TIMEOUT;
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T') )
    {
        p = GotoDataFiled( &(p[4]), 0 );
        if(p==0)  return(0);
        GetDecimalData( p );
        StrType = STRTYPE_WAIT;
    }
    else if( (p[0]=='x')||(p[0]=='y')||(p[0]=='z')||(p[0]=='X')||(p[0]=='Y')||(p[0]=='Z') )
    {
        if((*p=='x')||(*p=='y')||(*p=='z'))
            v = (p[0]-'x')*10+(p[1]-'0');
        if((*p=='X')||(*p=='Y')||(*p=='Z'))
            v = (p[0]-'X')*10+(p[1]-'0');
        StrValue2 = v;
        p = GotoDataFiled( &(p[2]), 0 );
        if(p==0)  return(0);
        StrValue = ByteHexStr2Int(p);
        if( StrValue<0 )  return(0);
        StrType = STRTYPE_VAR;
    }
    else if( (p[0]=='T')&&(p[1]=='X') )
    {
        p = GotoDataFiled( &(p[2]), 1 );
        if(p==0)  return(0);
        GetStringData(p);
        if (('0' == p[0]) && ('1' == p[1]))
        {
            StrType = STRTYPE_TX_HCI_CMD;
            CmdLen = 0;
        }
        else if (('0' == p[0]) && ('2' == p[1]))
        {
            StrType = STRTYPE_TX_ACL_DATA;
        }
        else if (('0' == p[0]) && ('3' == p[1]))
        {
            StrType = STRTYPE_TX_SCO_DATA;
        }
    }
    else if((p[0]=='R')&&(p[1]=='X'))
    {
        p = GotoDataFiled(&(p[2]), 1);
        if(p==0)  return(0);
        GetStringData( p );
        if (('0' == p[0]) && ('2' == p[1]))
        {
            StrType = STRTYPE_RX_ACL_DATA;
        }
        else if (('0' == p[0]) && ('3' == p[1]))
        {
            StrType = STRTYPE_RX_SCO_DATA;
        }
        else if (('0' == p[0]) && ('4' == p[1]))
        {
            StrType = STRTYPE_RX_HCI_EVENT;
            m_iEvtLen[i_event_idx] = 0;
        }
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T')&&(p[4]=='R')&&(p[5]=='X') )
    {
        p = GotoDataFiled( &(p[6]), 1 );
        if(p==0)  return(0);
        GetStringData( p );
        m_iEvtLen[i_event_idx] = 0;
        StrType = STRTYPE_WAITRX;
    }
    else if( (p[0]=='S')&&(p[1]=='I')&&(p[2]=='M')&&(p[3]=='R')&&(p[4]=='X') )
    {
        p = GotoDataFiled( &(p[5]), 1 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_SIMRX;
    }
    else if( (p[0]=='P')&&(p[1]=='A')&&(p[2]=='T')&&(p[3]=='C')&&(p[4]=='H') )
    {
        p = GotoDataFiled( &(p[5]), 1 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_PATCH;
    }
    else if( (p[0]=='B')&&(p[1]=='A')&&(p[2]=='U')&&(p[3]=='D')&&(p[4]=='R')&&(p[5]=='A')&&(p[6]=='T')&&(p[7]=='E') )
    {
        p = GotoDataFiled( &(p[8]), 1 );
        if(p==0)  return(0);
        StrValue = *p - '0';
        StrType = STRTYPE_BAUDRATE;
    }
    else if( (p[0]=='F')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='L')&&(p[4]=='P')&&(p[5]=='R')&&(p[6]=='O')&&(p[7]=='C') )
    {
        StrType = STRTYPE_FAILPROC;
    }
    else if( (p[0]=='F')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='L')&&(p[4]=='E')&&(p[5]=='N')&&(p[6]=='D') )
    {
        StrType = STRTYPE_FAILEND;
    }
    else if( (p[0]=='G')&&(p[1]=='O')&&(p[2]=='T')&&(p[3]=='O')&&(p[4]=='N')&&(p[5]=='E')&&(p[6]=='X')&&(p[7]=='T')&&(p[8]=='P')&&(p[9]=='R')&&(p[10]=='O')&&(p[11]=='C') )
    {
        StrType = STRTYPE_GOTONEXTPROC;
    }
    else if( (p[0]=='F')&&(p[1]=='O')&&(p[2]=='R')&&(p[3]=='C')&&(p[4]=='E')&&(p[5]=='E')&&(p[6]=='N')&&(p[7]=='D') )
    {
        StrType = STRTYPE_FORCEEND;
    }
    else if( (p[0]=='S')&&(p[1]=='H')&&(p[2]=='O')&&(p[3]=='W')&&(p[4]=='M')&&(p[5]=='S')&&(p[6]=='G') )
    {
        p = GotoDataFiled( &(p[7]), 1 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_SHOWMSG;
    }
    else if( (p[0]=='K')&&(p[1]=='Y')&&(p[2]=='L')&&(p[3]=='E') )
    {
        p = GotoDataFiled( &(p[8]), 0 );
        if(p==0)  return(0);
        StrArg1 = GetDecimalArg( p );
        StrArg2 = GetDecimalArg( p );
        StrArg3 = GetDecimalArg( p );
        StrType = STRTYPE_KYLE;
    }
    else if( (p[0]=='E')&&(p[1]=='N')&&(p[2]=='D') )
    {
        StrType = STRTYPE_END;
    }
    else  if( n>=3 )  // 3 space in front of this line
    {
        GetStringData( p );
        StrType = STRTYPE_CONTI;
    }
    return(1);
}

//-----------------------------------------------
int CBTMTPARSE::PreParseStringType(char *str)
{
    int  n;
    char *p = str;
    StrType = STRTYPE_NONE;
    for( n=0; *p==' '; n++ )
    {
        p++;
    }
    if( (p[0]=='H')&&(p[1]=='C')&&(p[2]=='I') )
    {
        StrType = STRTYPE_HCI;
    }
    else if( (p[0]=='L')&&(p[1]=='O')&&(p[2]=='G')&&(p[3]=='P')&&(p[4]=='A')&&(p[5]=='T')&&(p[6]=='H') )
    {
        StrType = STRTYPE_LOGPATH;
    }
    else if( (p[0]=='T')&&(p[1]=='I')&&(p[2]=='T')&&(p[3]=='L')&&(p[4]=='E') )
    {
        p = GotoDataFiled( &(p[5]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_TITLE;
        return(1);
    }
    else if( (p[0]=='P')&&(p[1]=='R')&&(p[2]=='O')&&(p[3]=='C') )
    {
        p = GotoDataFiled( &(p[4]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_PROCNAME;
        return(1);
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T')&&(p[4]=='P')&&(p[5]=='R')&&(p[6]=='O')&&(p[7]=='C') )
    {
        p = GotoDataFiled( &(p[8]), 0 );
        if(p==0)  return(0);
        GetStringData( p );
        StrType = STRTYPE_WAITPROCNAME;
        return(1);
    }
    else if( (p[0]=='T')&&(p[1]=='I')&&(p[2]=='M')&&(p[3]=='E')&&(p[4]=='O')&&(p[5]=='U')&&(p[6]=='T') )
    {
        StrType = STRTYPE_TIMEOUT;
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T') )
    {
        StrType = STRTYPE_WAIT;
    }
    else if( (p[0]=='x')||(p[0]=='y')||(p[0]=='z')||(p[0]=='X')||(p[0]=='Y')||(p[0]=='Z') )
    {
        StrType = STRTYPE_VAR;
    }
    else if((p[0]=='T')&&(p[1]=='X'))
    {
        p = GotoDataFiled(&(p[2]), 1);
        if (p==0)
        {
            return(0);
        }
        if (('0' == p[0]) && ('1' == p[1]))
        {
            StrType = STRTYPE_TX_HCI_CMD;
        }
        else if (('0' == p[0]) && ('2' == p[1]))
        {
            StrType = STRTYPE_TX_ACL_DATA;
        }
        else if (('0' == p[0]) && ('3' == p[1]))
        {
            StrType = STRTYPE_TX_SCO_DATA;
        }
    }
    else if ((p[0]=='R') && (p[1]=='X'))
    {
        p = GotoDataFiled(&(p[2]), 1);
        if(p==0)  return(0);
        if (('0' == p[0]) && ('2' == p[1]))
        {
            StrType = STRTYPE_RX_ACL_DATA;
        }
        else if (('0' == p[0]) && ('3' == p[1]))
        {
            StrType = STRTYPE_RX_SCO_DATA;
        }
        else if (('0' == p[0]) && ('4' == p[1]))
        {
            StrType = STRTYPE_RX_HCI_EVENT;
        }
    }
    else if( (p[0]=='W')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='T')&&(p[4]=='R')&&(p[5]=='X') )
    {
        StrType = STRTYPE_WAITRX;
    }
    else if( (p[0]=='S')&&(p[1]=='I')&&(p[2]=='M')&&(p[3]=='R')&&(p[4]=='X') )
    {
        StrType = STRTYPE_SIMRX;
    }
    else if( (p[0]=='P')&&(p[1]=='A')&&(p[2]=='T')&&(p[3]=='C')&&(p[4]=='H') )
    {
        StrType = STRTYPE_PATCH;
    }
    else if( (p[0]=='B')&&(p[1]=='A')&&(p[2]=='U')&&(p[3]=='D')&&(p[4]=='R')&&(p[5]=='A')&&(p[6]=='T')&&(p[7]=='E') )
    {
        StrType = STRTYPE_BAUDRATE;
    }
    else if( (p[0]=='F')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='L')&&(p[4]=='P')&&(p[5]=='R')&&(p[6]=='O')&&(p[7]=='C') )
    {
        StrType = STRTYPE_FAILPROC;
    }
    else if( (p[0]=='F')&&(p[1]=='A')&&(p[2]=='I')&&(p[3]=='L')&&(p[4]=='E')&&(p[5]=='N')&&(p[6]=='D') )
    {
        StrType = STRTYPE_FAILEND;
    }
    else if( (p[0]=='G')&&(p[1]=='O')&&(p[2]=='T')&&(p[3]=='O')&&(p[4]=='N')&&(p[5]=='E')&&(p[6]=='X')&&(p[7]=='T')&&(p[8]=='P')&&(p[9]=='R')&&(p[10]=='O')&&(p[11]=='C') )
    {
        StrType = STRTYPE_GOTONEXTPROC;
    }
    else if( (p[0]=='F')&&(p[1]=='O')&&(p[2]=='R')&&(p[3]=='C')&&(p[4]=='E')&&(p[5]=='E')&&(p[6]=='N')&&(p[7]=='D') )
    {
        StrType = STRTYPE_FORCEEND;
    }
    else if( (p[0]=='S')&&(p[1]=='H')&&(p[2]=='O')&&(p[3]=='W')&&(p[4]=='M')&&(p[5]=='S')&&(p[6]=='G') )
    {
        StrType = STRTYPE_SHOWMSG;
    }
    else if( (p[0]=='K')&&(p[1]=='Y')&&(p[2]=='L')&&(p[3]=='E') )
    {
        StrType = STRTYPE_KYLE;
    }
    else if( (p[0]=='E')&&(p[1]=='N')&&(p[2]=='D') )
    {
        StrType = STRTYPE_END;
    }
    else  if( n>=3 )  // 3 space in front of this line
    {
        StrType = STRTYPE_CONTI;
    }
    return(1);
}
//-----------------------------------------------

char *CBTMTPARSE::GotoDataFiled( char *p, int mode  )
{
    if(mode==0)
    {
        while( *p==' ' )  p++;
        if(*p++!=':')  return(0);
        while( *p==' ' )  p++;
    }
    else
    {
        if((*p>='1')&&(*p<'9'))
        {
            StrValue2 = *p - '0';
            p++;
        }
        else
        {
            StrValue2 = 0;
            p++;
        }
        while( *p==' ' )  p++;
        if(*p++!=':')  return(0);
        while( *p==' ' )  p++;
    }
    return(p);
}
//-----------------------------------------------

void CBTMTPARSE::GetStringData( char *p )
{
    int n;
    for( n=0; (*p!=0)&&(*p!='\n'); n++)
    {
        if( (p[0]=='/')&&(p[1]=='/') )   break;  // ignore comment "//"
        if( (p[0]=='\\')&&(p[1]=='\\') ) break;  // ignore comment "//"
        String[n] = *p++;
    }
    String[n] = 0;
    StrLen = n;
}
//-----------------------------------------------

void CBTMTPARSE::GetDecimalData( char *p )
{
    int v;
    for(v=0; (*p>='0')&&(*p<='9'); p++ )
    {
        v = v*10 + (*p-'0');
    }
    StrValue = v;
}
//-----------------------------------------------

int CBTMTPARSE::GetDecimalArg( char *p )
{
    int v;
    while(*p==' ') p++;
    for(v=0; (*p>='0')&&(*p<='9'); p++ )
    {
        v = v*10 + (*p-'0');
    }
    return(v);
}
//-----------------------------------------------

int CBTMTPARSE::ByteHexStr2Int( char *p )
{
    int n, v = 0;
    for(n=0; n<2; n++)
    {
        if( (*p>='0')&&(*p<='9') )  v = v*16 + (*p-'0');
        else if( (*p>='A')&&(*p<='F') )  v = v*16 + (10+*p-'A');
        else if( (*p>='a')&&(*p<='f') )  v = v*16 + (10+*p-'a');
        else return(-1);
        p++;
    }
    return(v);
}

//-----------------------------------------------
// "00 11 00 11 A5 33 DE FF x1 x2 x3"
bool CBTMTPARSE::String2Command(void)
{
    int  v;
    char *p = String;

    while ((p[0]!=0) && (p[1]!=0))
    {
        if ((*p=='x')||(*p=='y')||(*p=='z'))
        {
            v = VarData[10*(p[0]-'x')+(p[1]-'0')];
        }
        else
        {
            v = ByteHexStr2Int(p);
            if (v < 0)
            {
                return false;
            }
        }
        Command[CmdLen] = v;
        CmdLen++;
        p+=2;
        while(*p==' ')  p++; //delete space
    }
    return true;
}

//-----------------------------------------------
// "00 11 00 11 A5 33 DE FF x1 x2 x3"
bool CBTMTPARSE::String2TxAclData(void)
{
    int  v;
    char *p = String;

    while ((p[0]!=0) && (p[1]!=0))
    {
        if ((*p == 'x') || (*p == 'y') || (*p == 'z'))
        {
            v = VarData[10*(p[0]-'x')+(p[1]-'0')];
        }
        else
        {
            v = ByteHexStr2Int(p);
            if (v < 0)
            {
                return false;
            }
        }
        m_ucTxAclData[m_iTxAclDataLen] = v;
        m_iTxAclDataLen++;
        p+=2;
        while(*p==' ')  p++; //delete space
    }
    return true;
}

//-----------------------------------------------
// "00 11 00 11 ?? ?? 35 ?? 33 DE FF x1 x2 x3 AA X8 X9 Y9 *"
bool CBTMTPARSE::String2Event(int i_event_idx)
{
    int  v;
    char *p = String;
    m_iEvtLen[i_event_idx] = 0;

    while ((p[0]!=0) && (p[1]!=0))
    {
        if ((*p=='x') || (*p=='y') || (*p=='z'))
        {
            m_ucEvtTag[i_event_idx][m_iEvtLen[i_event_idx]] = 1;
            v =  10*(p[0]-'x')+(p[1]-'0');
        }
        else if ((*p=='X') || (*p=='Y') || (*p=='Z'))
        {
            m_ucEvtTag[i_event_idx][m_iEvtLen[i_event_idx]] = 2;
            v =  10*(p[0]-'X')+(p[1]-'0');
        }
        else if ((p[0] == '?') && (p[1] == '?'))
        {
            m_ucEvtTag[i_event_idx][m_iEvtLen[i_event_idx]] = 3;
            v =  0;
        }
        else if (p[0]=='*')
        {
            m_ucEvtTag[i_event_idx][m_iEvtLen[i_event_idx]] = 4;
            v =  0;
        }
        else
        {
            assert(i_event_idx < MAX_EVENT_NUM);
            assert(m_iEvtLen[i_event_idx] < EVTSIZE);
            m_ucEvtTag[i_event_idx][m_iEvtLen[i_event_idx]] = 0;
            v = ByteHexStr2Int(p);
            if (v < 0)
            {
                return false;
            }
        }
        m_ucEvent[i_event_idx][m_iEvtLen[i_event_idx]] = v;
        m_iEvtLen[i_event_idx]++;
        p += 2;
        while (*p == ' ')  p++; //delete space
    }
    return true;
}

//-----------------------------------------------
// "00 11 00 11 ?? ?? 35 ?? 33 DE FF x1 x2 x3 AA X8 X9 Y9 *"
bool CBTMTPARSE::String2AutoEvent(int i_event_idx)
{
    int  v;
    char *p = String;
    m_iAutoEvtLen[i_event_idx] = 0;
    while ((p[0]!=0) && (p[1]!=0))
    {
        if ((*p=='x') || (*p=='y') || (*p=='z'))
        {
            m_ucAutoEvtTag[i_event_idx][m_iAutoEvtLen[i_event_idx]] = 1;
            v =  10*(p[0]-'x')+(p[1]-'0');
        }
        else if ((*p=='X') || (*p=='Y') || (*p=='Z'))
        {
            m_ucAutoEvtTag[i_event_idx][m_iAutoEvtLen[i_event_idx]] = 2;
            v =  10*(p[0]-'X')+(p[1]-'0');
        }
        else if ((p[0] == '?') && (p[1] == '?'))
        {
            m_ucAutoEvtTag[i_event_idx][m_iAutoEvtLen[i_event_idx]] = 3;
            v =  0;
        }
        else if (p[0]=='*')
        {
            m_ucAutoEvtTag[i_event_idx][m_iAutoEvtLen[i_event_idx]] = 4;
            v =  0;
        }
        else
        {
            assert(i_event_idx < MAX_EVENT_NUM);
            assert(m_iAutoEvtLen[i_event_idx] < EVTSIZE);
            m_ucAutoEvtTag[i_event_idx][m_iAutoEvtLen[i_event_idx]] = 0;
            v = ByteHexStr2Int(p);
            if (v < 0)
            {
                return false;
            }
        }
        m_ucAutoEvent[i_event_idx][m_iAutoEvtLen[i_event_idx]] = v;
        m_iAutoEvtLen[i_event_idx]++;
        p += 2;
        while (*p == ' ')  p++; //delete space
    }
    return true;
}

//-----------------------------------------------
// "00 11 00 11 ?? ?? 35 ?? 33 DE FF x1 x2 x3 AA X8 X9 Y9 *"
bool CBTMTPARSE::String2RxAclData(void)
{
    int  v;
    char *p = String;
    m_iTxAclDataLen = 0;
    while ((p[0]!=0) && (p[1]!=0))
    {
        if ((*p=='x') || (*p=='y') || (*p=='z'))
        {
            m_ucRxAclDataTag[m_iRxAclDataLen] = 1;
            v =  10*(p[0]-'x')+(p[1]-'0');
        }
        else if ((*p=='X') || (*p=='Y') || (*p=='Z'))
        {
            m_ucRxAclDataTag[m_iRxAclDataLen] = 2;
            v =  10*(p[0]-'X')+(p[1]-'0');
        }
        else if ((p[0] == '?') && (p[1] == '?'))
        {
            m_ucRxAclDataTag[m_iRxAclDataLen] = 3;
            v =  0;
        }
        else if (p[0]=='*')
        {
            m_ucRxAclDataTag[m_iRxAclDataLen] = 4;
            v =  0;
        }
        else
        {
            assert(m_iRxAclDataLen < MAX_ACL_DATA_LEN);
            m_ucRxAclDataTag[m_iRxAclDataLen] = 0;
            v = ByteHexStr2Int(p);
            if (v < 0)
            {
                return false;
            }
        }
        m_ucRxAclData[m_iRxAclDataLen] = v;
        m_iRxAclDataLen++;
        p += 2;
        while (*p == ' ')  p++; //delete space
    }
    return true;
}

//-----------------------------------------------
// "00 11 00 11 ?? ?? 35 ?? 33 DE FF x1 x2 x3 AA X8 X9 Y9 *"
bool CBTMTPARSE::CompareEvent(int i_event_idx, unsigned char *event, int len)
{
    int n;
//   if(len!=m_iEvtLen)   return(0);
    for (n = 0; n < len; n++)
    {
        if (m_ucEvtTag[n] == 0)
        {
            if (m_ucEvent[i_event_idx][n] != event[n])
            {
                return false;
            }
        }
        else if (m_ucEvtTag[i_event_idx][n] == 2)  // compare variable
        {
            if (VarData[m_ucEvent[i_event_idx][n]] != event[n])
            {
                return(0);
            }
        }
        else if (m_ucEvtTag[i_event_idx][n] == 3)  // ??
        {
            // nothing to do
        }
        else if (m_ucEvtTag[i_event_idx][n] == 4)  // *
        {
            break;
        }
    }
    for (n = 0; n < len; n++)
    {
        if (m_ucEvtTag[i_event_idx][n] == 1)   // assign value to variable
        {
            VarData[m_ucEvent[i_event_idx][n]] = event[n];
        }
    }
    return true;
}

//=============================================================================
