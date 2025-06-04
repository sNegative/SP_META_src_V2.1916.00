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
 *   bt_mt.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test source
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

#include <windows.h>
#include <dos.h>
#include <stdio.h>
#include <process.h>
#include <dir.h>
#include <string.h>
#include <assert.h>

#pragma hdrstop

#ifndef  _BT_HCI_FT_H_
#include "bt_hci_ft.h"
#endif

#ifndef _BT_MT_H_
#include "bt_mt.h"
#endif

#ifndef _BT_MT_PARSE_H_
#include "bt_mt_Parse.h"
#endif

//=============================================================================
#define  BT_MODULE_TEST_SRCSTR_SIZE  8192
//=============================================================================
static long  GiveDateTime(void);
//=============================================================================
int CBTMT::TimerTick(void)
{
    int ok = ERR_NONE;
    int n;

    Ticks++;
    m_cLogString[0] = 0;
    LogStrPtr = m_cLogString;
    //m_pcHci->rs232.LogString[0] = 0;
    //m_pcHci->rs232.LogStrPtr = m_pcHci->rs232.LogString;
    m_cHciUart.rs232.LogString[0] = 0;
    m_cHciUart.rs232.LogStrPtr = m_cHciUart.rs232.LogString;

    //---------------------------------
    if (WaitCounter > 0)
    {
        WaitCounter--;
        goto _process_result;
    }

    //---------------------------------
    if (TimeoutTime > 0)
    {
        TimeoutCounter++;
        if (TimeoutCounter == TimeoutTime)
        {
            ProcFailCount++;
            LogStrPtr += sprintf( LogStrPtr, "Tick Time :%ld \n", Ticks );
            LogStrPtr += sprintf( LogStrPtr, "TIMEOUT (%d ms)!! \n", (int)(TimeoutCounter*TIMERTICK_UNITE) );
            if (WaitRX != 0)
            {
                WaitRX = 0;
            }
            ok = ERR_TIMEOUT;
            goto _process_result;  // //goto _process_result;
        }
    }

    //---------------------------------
    if (WaitRX)
    {
        //if (!m_pcHci->rs232.IsRxDataReady())
        if (!m_cHciUart.rs232.IsRxDataReady())
        {
            goto _process_result;
        }
        LogStrPtr += sprintf(LogStrPtr, "Tick Time :%ld\n", Ticks );
        // LogStrPtr += sprintf(LogStrPtr, "%s", m_pcHci->rs232.LogString);
        LogStrPtr += sprintf(LogStrPtr, "%s", m_cHciUart.rs232.LogString);
        //m_pcHci->rs232.LogString[0] = 0;
        //m_pcHci->rs232.LogStrPtr = m_pcHci->rs232.LogString;
        m_cHciUart.rs232.LogString[0] = 0;
        m_cHciUart.rs232.LogStrPtr = m_cHciUart.rs232.LogString;
        //if (!m_pcHci->ReadEvent())
        if (!m_cHciUart.ReadEvent())
        {
            LogStrPtr += sprintf(LogStrPtr, "Read HCI m_ucEvent Fail");
            goto _process_result;
        }
        //LogStrPtr += sprintf(LogStrPtr, "%s", m_pcHci->rs232.LogString);
        LogStrPtr += sprintf(LogStrPtr, "%s", m_cHciUart.rs232.LogString);
        WaitRX = 0;
        //if (Parse.CompareEvent(m_pcHci->EventBuf, m_pcHci->EventLen))
        if (Parse.CompareEvent(m_iEventIdx, m_cHciUart.EventBuf, m_cHciUart.EventLen))
        {
            WaitRX = 0;
            LogStrPtr += sprintf(LogStrPtr, "PASS: Compare HCI RX data \n");
        }
        else
        {
            if (WaitRX != 2)   // not waiting for some event
            {
                WaitRX=0;
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "FAIL: Wrong HCI RX data \n");
                LogStrPtr += sprintf(LogStrPtr, "Pattern : ");
                for (n = 0; n < Parse.m_iEvtLen[m_iEventIdx]; n++)
                {
                    LogStrPtr += sprintf(LogStrPtr, "%02X ", Parse.m_ucEvent[n]);
                }
                LogStrPtr += sprintf(LogStrPtr, " \n");
            }
            LogStrPtr += sprintf(LogStrPtr, "HCI Data:");
            //for (n = 0; n < m_pcHci->EventLen; n++)
            for (n = 0; n < m_cHciUart.EventLen; n++)
            {
                //LogStrPtr += sprintf(LogStrPtr, "%02X ", m_pcHci->EventBuf[n]);
                LogStrPtr += sprintf(LogStrPtr, "%02X ", m_cHciUart.EventBuf[n]);
            }
            LogStrPtr += sprintf(LogStrPtr, "\n");
            ok = ERR_RXCOMP;
        }
        ProcessResult(ok);
    }
    //---------------------------------
    TimeoutCounter = 0;
    // LogStrPtr += sprintf( LogStrPtr, "Tick Time :%ld\n", Ticks );
    ok = ExecuteNextScript();

_process_result:
    ProcessResult( ok );
    if(LogFs!=0)
        fputs(m_cLogString, LogFs );
    return(ok);

}

//-----------------------------------------------
int CBTMT::ExecuteNextScript(void)
{
    int ok;
    long fpos;
    char str[BT_MODULE_TEST_SRCSTR_SIZE];
    //char *p;

    if (RUN_Time < 0)
    {
        RUN_Time = GiveDateTime();
    }
    if (CS_feof(ScrFs))
    {
        CountProcResult();
        CloseScript();
        return(ERR_FILEEND);
    }
    CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
    LogStrPtr += sprintf(LogStrPtr, "\n=> %s", str);
    Parse.PreParseString(m_iEventIdx, str);
    if (IsForceEnd)
    {
        Parse.StrType = STRTYPE_END;
    }

    switch (Parse.StrType)
    {
    case STRTYPE_HCI:
    {
        if ((BT_RS232 == m_eBtTrans[1]) && (2 == Parse.StrValue2))
        {
            //ok = HciUart[Parse.StrValue2-1].SetTransport(Parse.StrValue, 115200L, 0 );
            ok = m_cHciUart.SetTransport(m_iComPort, 115200L, 0);
            if (!ok)
            {
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "Open COM%d Fail! \n", m_iComPort);
                return(ERR_HCIOPEN);
            }
            // m_pcHci = &(HciUart[Parse.StrValue2-1]);
            LogStrPtr += sprintf(LogStrPtr, "Open COM%d OK \n", m_iComPort);
        }
    }
    break;

    case STRTYPE_LOGPATH:
    {
        strcpy(LogPath, Parse.String);
        mkdir(LogPath);
    }
    break;

    case STRTYPE_TITLE:
    {
    }
    break;

    case STRTYPE_PROCNAME:
    {
        CountProcResult();
    }
    break;

    case STRTYPE_WAITPROCNAME:
    {
        CountProcResult();
        IsWaitProc = 1;
        WaitProcPos = CS_ftell( ScrFs );
    }
    break;

    case STRTYPE_TIMEOUT:
    {
        TimeoutCounter = TimeoutTime = (int)(Parse.StrValue/TIMERTICK_UNITE);
        LogStrPtr += sprintf( LogStrPtr, "Setting TIMEOUT value (%d ms) \n", (int)(TimeoutTime*TIMERTICK_UNITE));
    }
    break;

    case STRTYPE_WAIT:
    {
        WaitCounter = WaitTime = (int)(Parse.StrValue/TIMERTICK_UNITE);
        LogStrPtr += sprintf( LogStrPtr, "Waiting %d ms \n", (int)(WaitTime*TIMERTICK_UNITE));
    }
    break;

    case STRTYPE_VAR:
    {
        Parse.VarData[Parse.StrValue2] = Parse.StrValue;
        LogStrPtr += sprintf(LogStrPtr, "Set Var[%d] value = %d \n", Parse.StrValue2, (int)Parse.VarData[Parse.StrValue2]);
    }
    break;

    case STRTYPE_TX_HCI_CMD:
    {
        E_BT_DEVICE_T bt_device_tx = (E_BT_DEVICE_T) Parse.StrValue2-1;
        m_iEventIdx = 0;
        m_iEventNum = 0;
        m_iAutoEventIdx = 0;
        m_iAutoEventNum = 0;
        BT_META_HCI_T cmd;
        cmd.e_bt_device = (E_BT_DEVICE_T) Parse.StrValue2-1;
        cmd.e_bt_trans[0] = m_eBtTrans[0];
        cmd.e_bt_trans[1] = m_eBtTrans[1];
        // m_pcHci = &(HciUart[Parse.StrValue2-1]);
        if (BT_RS232 == m_eBtTrans[Parse.StrValue2-1])
        {
            ok = m_cHciMETA.RegAutoCallBack0();
            if (!ok)
            {
                return(ERR_META);
            }
            Parse.String2Command();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                Parse.PreParseStringType(str);
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2Command();
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            //ok = m_pcHci->SendCommand(Parse.Command, Parse.CmdLen );
            ok = m_cHciUart.SendCommand(Parse.Command, Parse.CmdLen);
            //LogStrPtr += sprintf(LogStrPtr, "%s", m_pcHci->rs232.LogString);
            LogStrPtr += sprintf(LogStrPtr, "%s", m_cHciUart.rs232.LogString);
            //m_pcHci->rs232.LogString[0] = 0;
            m_cHciUart.rs232.LogString[0] = 0;
            if (ok)
            {
                LogStrPtr += sprintf(LogStrPtr, "Send HCI Command OK! \n");
                return(ERR_NONE);
            }
            else
            {
                LogStrPtr += sprintf(LogStrPtr, "Send HCI Command FAIL!! \n");
                ProcFailCount++;
                return(ERR_TX);
            }
        }
        else
        {
            Parse.String2Command();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                //int i = 1;
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                Parse.PreParseStringType(str);
                Parse.PreParseString(m_iEventIdx, str);
                if (STRTYPE_RX_HCI_EVENT == Parse.StrType)
                {
                    if (bt_device_tx == (E_BT_DEVICE_T) Parse.StrValue2-1)
                    {
                        Parse.String2Event(m_iEventIdx);
                        m_iEventIdx++;
                        m_iEventNum = m_iEventIdx;
                    }
                    else
                    {
                        Parse.String2AutoEvent(m_iAutoEventIdx);
                        m_iAutoEventIdx++;
                        m_iAutoEventNum = m_iAutoEventIdx;
                    }
                }
                else if ((STRTYPE_TX_HCI_CMD == Parse.StrType)  ||
                         (STRTYPE_TX_ACL_DATA == Parse.StrType) ||
                         (STRTYPE_TX_SCO_DATA == Parse.StrType) ||
                         (STRTYPE_PROCNAME == Parse.StrType)
                        )
                {
                    CS_fseek(ScrFs, fpos, SEEK_SET);
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
            }
            while(1);

            CBTHCIFT BT_HCI_FT_Obj;
            BT_HCI_FT_Obj.Reset_HCI_Command(cmd.s_hci_cmd);
            cmd.s_hci_cmd.m_opcode = (Parse.Command[2] << 8) | Parse.Command[1];
            cmd.s_hci_cmd.m_len    = Parse.Command[3];
            for (int i = 0; i < cmd.s_hci_cmd.m_len; i++)
            {
                cmd.s_hci_cmd.m_cmd[i] = Parse.Command[4 + i];
            }
            cmd.i_event_num = m_iEventNum;
            for (int event_idx = 0; event_idx < cmd.i_event_num; event_idx++)
            {
                cmd.s_hci_event[event_idx].m_event = Parse.m_ucEvent[event_idx][1];
                cmd.s_hci_event[event_idx].m_len   = Parse.m_ucEvent[event_idx][2];
                for (int i = 0; i < cmd.s_hci_event[event_idx].m_len; i++)
                {
                    cmd.s_hci_event[event_idx].m_parms[i] = Parse.m_ucEvent[event_idx][3 + i];
                }
            }
            cmd.i_auto_event_num = m_iAutoEventNum;
            for (int event_idx = 0; event_idx < cmd.i_auto_event_num; event_idx++)
            {
                cmd.s_hci_auto_event[event_idx].m_event = Parse.m_ucAutoEvent[event_idx][1];
                cmd.s_hci_auto_event[event_idx].m_len   = Parse.m_ucAutoEvent[event_idx][2];
                for (int i = 0; i < cmd.s_hci_auto_event[event_idx].m_len; i++)
                {
                    cmd.s_hci_auto_event[event_idx].m_parms[i] = Parse.m_ucAutoEvent[event_idx][3 + i];
                }
            }
            ok = m_cHciMETA.SendCommand(cmd);
            if (!ok)
            {
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "Send HCI command Fail! \n");
                return(ERR_TX);
            }
        }
    }
    break;

    case STRTYPE_TX_ACL_DATA:
    {
        m_iEventIdx = 0;
        m_iEventNum = 0;
        E_BT_DEVICE_T bt_device_tx = (E_BT_DEVICE_T) Parse.StrValue2-1;
        BT_META_ACL_DATA_T acl_data;
        acl_data.e_bt_device = (E_BT_DEVICE_T) Parse.StrValue2-1;
        acl_data.e_bt_trans[0] = m_eBtTrans[0];
        acl_data.e_bt_trans[1] = m_eBtTrans[1];
        // m_pcHci = &(HciUart[Parse.StrValue2-1]);
        if (BT_RS232 == m_eBtTrans[Parse.StrValue2-1])
        {
            ok = m_cHciMETA.RegAclRxData0();
            if (!ok)
            {
                return(ERR_META);
            }
            Parse.String2TxAclData();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                Parse.PreParseStringType(str);
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2TxAclData();
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            //ok = m_pcHci->SendCommand(Parse.Command, Parse.CmdLen );
            ok = m_cHciUart.SendCommand(Parse.Command, Parse.CmdLen);
            //LogStrPtr += sprintf(LogStrPtr, "%s", m_pcHci->rs232.LogString);
            LogStrPtr += sprintf(LogStrPtr, "%s", m_cHciUart.rs232.LogString);
            //m_pcHci->rs232.LogString[0] = 0;
            m_cHciUart.rs232.LogString[0] = 0;
            if (ok)
            {
                LogStrPtr += sprintf(LogStrPtr, "Send HCI Command OK! \n");
                return(ERR_NONE);
            }
            else
            {
                LogStrPtr += sprintf(LogStrPtr, "Send HCI Command FAIL!! \n");
                ProcFailCount++;
                return(ERR_TX);
            }
        }
        else
        {
            Parse.String2TxAclData();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                //int i = 1;
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                Parse.PreParseStringType(str);
                Parse.PreParseString(m_iEventIdx, str);
                if (STRTYPE_RX_HCI_EVENT == Parse.StrType)
                {
                    if (bt_device_tx == (E_BT_DEVICE_T) Parse.StrValue2-1)
                    {
                        Parse.String2Event(m_iEventIdx);
                        m_iEventIdx++;
                        m_iEventNum = m_iEventIdx;
                    }
                    else
                    {
                        Parse.String2RxAclData();
                    }
                }
                else if ((STRTYPE_TX_HCI_CMD == Parse.StrType)  ||
                         (STRTYPE_TX_ACL_DATA == Parse.StrType) ||
                         (STRTYPE_TX_SCO_DATA == Parse.StrType) ||
                         (STRTYPE_PROCNAME == Parse.StrType))
                {
                    CS_fseek(ScrFs, fpos, SEEK_SET);
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
            }
            while(1);

            //CBTHCIFT BT_HCI_FT_Obj;
            //BT_HCI_FT_Obj.Reset_HCI_Command(acl_data.s_tx_acl_data);
            acl_data.s_tx_acl_data.m_con_hdl = (Parse.m_ucTxAclData[2] << 8) | Parse.m_ucTxAclData[1];
            acl_data.s_tx_acl_data.m_len    = Parse.m_ucTxAclData[3] | (Parse.m_ucTxAclData[4] << 8);
            for (int i = 0; i < acl_data.s_tx_acl_data.m_len; i++)
            {
                acl_data.s_tx_acl_data.m_buffer[i] = Parse.m_ucTxAclData[5 + i];
            }
            acl_data.i_event_num = m_iEventNum;
            for (int event_idx = 0; event_idx < acl_data.i_event_num; event_idx++)
            {
                acl_data.s_hci_event[event_idx].m_event = Parse.m_ucEvent[event_idx][1];
                acl_data.s_hci_event[event_idx].m_len   = Parse.m_ucEvent[event_idx][2];
                for (int i = 0; i < acl_data.s_hci_event[event_idx].m_len; i++)
                {
                    acl_data.s_hci_event[event_idx].m_parms[i] = Parse.m_ucEvent[event_idx][3 + i];
                }
            }

            ok = m_cHciMETA.SendAclData(acl_data);
            if (!ok)
            {
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "Send HCI command Fail! \n");
                return(ERR_TX);
            }
        }
    }
    break;

    case STRTYPE_RX_HCI_EVENT:
    {
        if (BT_RS232 == m_eBtTrans[Parse.StrValue2-1])
        {
            // m_pcHci = &(HciUart[Parse.StrValue2-1]);
            Parse.String2Event(m_iEventIdx);
            m_iEventIdx++;
            m_iAutoEventNum = m_iEventIdx;
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                ok = Parse.PreParseStringType(str);
                if (!ok)
                {
                    return(ERR_PARSESTR);
                }
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2Event(m_iEventIdx);
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            LogStrPtr += sprintf(LogStrPtr, "Waiting for HCI Data...... \n");
            WaitRX = 1;
        }
        else
        {
            Parse.String2AutoEvent(m_iAutoEventIdx);
            BT_META_HCI_T cmd;
            cmd.i_auto_event_num = m_iAutoEventNum;
            cmd.s_hci_auto_event[m_iAutoEventIdx].m_event = Parse.m_ucAutoEvent[m_iAutoEventIdx][1];
            cmd.s_hci_auto_event[m_iAutoEventIdx].m_len = Parse.m_ucAutoEvent[m_iAutoEventIdx][2];
            for (int i = 0; i < cmd.s_hci_auto_event[m_iAutoEventIdx].m_len; i++)
            {
                cmd.s_hci_auto_event[m_iAutoEventIdx].m_parms[i] = Parse.m_ucAutoEvent[m_iAutoEventIdx][3 + i];
            }
            m_cHciMETA.Set_HciCmd(cmd);
            m_iAutoEventIdx++;
            m_iAutoEventNum = m_iAutoEventIdx;
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                ok = Parse.PreParseStringType(str);
                if (!ok)
                {
                    return(ERR_PARSESTR);
                }
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2Event(m_iEventIdx);
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            LogStrPtr += sprintf(LogStrPtr, "Waiting for HCI Data...... \n");
            WaitRX = 1;
            while (!m_cHciMETA.Get_CallAutoCallback(Parse.StrValue2-1))
            {
                Sleep(100);
            }
            ok = m_cHciMETA.Get_EventOk();
            if (!ok)
            {
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "Receive HCI event Fail! \n");
                return(ERR_RXCOMP);
            }
            WaitRX = 0;
        }
    }
    break;

    case STRTYPE_RX_ACL_DATA:
    {
        if (BT_RS232 == m_eBtTrans[Parse.StrValue2-1])
        {
            Parse.String2RxAclData();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                ok = Parse.PreParseStringType(str);
                if (!ok)
                {
                    return(ERR_PARSESTR);
                }
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2RxAclData();
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            LogStrPtr += sprintf(LogStrPtr, "Waiting for HCI Data...... \n");
            WaitRX = 1;
        }
        else
        {
            Parse.String2RxAclData();
            do
            {
                fpos = CS_ftell(ScrFs);
                if (CS_feof(ScrFs))
                {
                    break;
                }
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                ok = Parse.PreParseStringType(str);
                if (!ok)
                {
                    return(ERR_PARSESTR);
                }
                if (Parse.StrType != STRTYPE_CONTI)
                {
                    break;
                }
                LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
                Parse.PreParseString(m_iEventIdx, str);
                Parse.String2RxAclData();
            }
            while(1);
            CS_fseek(ScrFs, fpos, SEEK_SET);
            LogStrPtr += sprintf(LogStrPtr, "Waiting for HCI Data...... \n");
#if 0
            WaitRX = 1;
            while (!m_cHciMETA.Get_CallAutoCallback(Parse.StrValue2-1))
            {
                Sleep(100);
            }
            ok = m_cHciMETA.Get_EventOk();
            if (!ok)
            {
                ProcFailCount++;
                LogStrPtr += sprintf(LogStrPtr, "Receive HCI event Fail! \n");
                return(ERR_RXCOMP);
            }
            WaitRX = 0;
#endif
        }
    }
    break;

    case STRTYPE_WAITRX:
    {
        // m_pcHci = &(HciUart[Parse.StrValue2-1]);
        Parse.String2Event(m_iEventIdx);
        do
        {
            fpos = CS_ftell(ScrFs);
            if (CS_feof(ScrFs))
            {
                break;
            }
            CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
            ok = Parse.PreParseStringType(str);
            if (!ok)
            {
                return(ERR_PARSESTR);
            }
            if (Parse.StrType != STRTYPE_CONTI)
            {
                break;
            }
            LogStrPtr += sprintf(LogStrPtr, "\n=> %s", str);
            Parse.PreParseString(m_iEventIdx, str);
            Parse.String2Event(m_iEventIdx);
        }
        while(1);
        CS_fseek(ScrFs, fpos, SEEK_SET);
        LogStrPtr += sprintf(LogStrPtr, "Waiting for HCI Data......\n");
        WaitRX = 2;
    }
    break;

    case STRTYPE_SIMRX:
    {
        //m_pcHci = &(HciUart[Parse.StrValue2-1]);
        Parse.String2Event(m_iEventIdx);
        do
        {
            fpos = CS_ftell(ScrFs);
            if (CS_feof(ScrFs))
            {
                break;
            }
            CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
            ok = Parse.PreParseStringType(str);
            if (!ok)
            {
                return ERR_PARSESTR;
            }
            if (Parse.StrType != STRTYPE_CONTI)
            {
                CS_fseek(ScrFs, fpos, SEEK_SET);
                break;
            }
            LogStrPtr += sprintf(LogStrPtr, "=> %s", str);
            Parse.PreParseString(m_iEventIdx, str);
            Parse.String2Event(m_iEventIdx);
        }
        while(1);
        //m_pcHci->rs232.PutData2Buf(Parse.m_ucEvent, Parse.m_iEvtLen);
        m_cHciUart.rs232.PutData2Buf(Parse.m_ucEvent, Parse.m_iEvtLen[m_iEventIdx]);
        LogStrPtr += sprintf( LogStrPtr, "Put debug data to UART RX buffer. \n");
        CS_fseek(ScrFs, fpos, SEEK_SET);
    }
    break;

    case STRTYPE_PATCH:
    {
        // m_pcHci = &(HciUart[Parse.StrValue2-1]);
        ok = GeneratePatchScript( Parse.StrValue2, Parse.String );
        if (ok)
        {
            SelSource = SRC_TMPFILE;
            if (TmpFs != 0)
            {
                fclose(TmpFs);
            }
            TmpFs = fopen("~tmpfile.txt", "rt");
        }
    }
    break;

    case STRTYPE_BAUDRATE:
    {
        //m_pcHci = &(HciUart[Parse.StrValue2-1]);
        ok = GenerateChangeBaudrateScript(Parse.StrValue2, Parse.StrValue);
        if (ok)
        {
            SelSource = SRC_TMPFILE;
            if (TmpFs != 0)
            {
                fclose(TmpFs);
            }
            TmpFs = fopen("~tmpfile.txt", "rt");
        }
    }
    break;

    case STRTYPE_FAILPROC:
    {
        FILE *fs = fopen("~failprc.txt", "w+t");
        if (fs != 0)
        {
            HasFailProc = true;
            while (!feof(ScrFs))
            {
                CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
                Parse.PreParseStringType(str);
                if (Parse.StrType == STRTYPE_FAILEND)
                {
                    fputs("END", fs);
                    fclose(fs);
                    break;
                }
                else
                {
                    fputs(str, fs);
                }
            }
        }
    }
    break;

    case STRTYPE_GOTONEXTPROC:
    {
        bool has_fail_proc = HasFailProc;
        HasFailProc = false;
        while (!feof(ScrFs))
        {
            CS_fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
            Parse.PreParseStringType(str);
            if (Parse.StrType == STRTYPE_PROCNAME)
            {
                CountProcResult();
                break;
            }
            else if (Parse.StrType == STRTYPE_END)
            {
                if (SelSource == SRC_ORGFILE)
                {
                    CountProcResult();
                    return ERR_FILEEND;
                }
                else if (SelSource == SRC_TMPFILE)
                {
                    if (TmpFs != 0)
                    {
                        fclose(TmpFs);
                    }
                    TmpFs = 0;
                    SelSource = SRC_ORGFILE;
                }
            }
        }
        HasFailProc = has_fail_proc;
    }
    break;

    case STRTYPE_FORCEEND:
    {
        IsForceEnd = true;
    }
    break;

    case STRTYPE_SHOWMSG:
    {
        ::MessageBox(NULL, Parse.String, "Message", MB_OK);
    }
    break;

    case STRTYPE_KYLE:
    {
        ok = GenerateKyleScript(Parse.StrArg1, Parse.StrArg2, Parse.StrArg3);
        if (ok)
        {
            SelSource = SRC_TMPFILE;
            if (TmpFs!=0)
            {
                fclose(TmpFs);
            }
            TmpFs = fopen("~tmpfile.txt", "rt");
        }
    }
    break;

    case STRTYPE_END:
    {
        if (SelSource == SRC_ORGFILE)
        {
            CountProcResult();
            return ERR_FILEEND;
        }
        else if (SelSource == SRC_TMPFILE)
        {
            if (TmpFs != 0)
            {
                fclose(TmpFs);
            }
            TmpFs = 0;
            SelSource = SRC_ORGFILE;
        }
    }
    break;
    } // switch ()

    return ERR_NONE;
}

//-----------------------------------------------
int CBTMT::GeneratePatchScript(int hci_no, char* patchfile)
{
    FILE *pfs, *fs;
    char str[BT_MODULE_TEST_SRCSTR_SIZE], *p;
    unsigned char buf[240];
    long len;
    int n;

    pfs = fopen( patchfile, "rb" );
    if (pfs == 0)
    {
        return 0;
    }
    fs = fopen("~tmpfile.txt", "w+t");
    if (fs == 0)
    {
        fclose(pfs);
        return(0);
    }
    // Generate 1'st segement of patch
    len = fread(buf, 1, 240, pfs);
    p=str;
    p += sprintf(p, "TX%d : 01 C4 FC F5 00 F0 00 00 00 ", hci_no);
    for (n=0; n<len; n++)
    {
        p+=sprintf(p, "%02X ", (int)buf[n]);
    }
    fputs(str, fs);
    sprintf(str, "\nRX%d : 04 0E 04 01 C4 FC 00\n", hci_no);
    fputs(str, fs);

    // Generate middle segements of patch
    len = fread(buf, 1, 240, pfs);
    while (len >= 240)
    {
        p = str;
        p += sprintf(p, "TX%d : 01 C4 FC F5 01 F0 00 00 00 ", hci_no);
        for (n=0; n<len; n++)
        {
            p+=sprintf(p, "%02X ", (int)buf[n]);
        }
        fputs(str, fs);
        sprintf(str, "\nRX%d : 04 0E 04 01 C4 FC 00\n", hci_no);
        fputs(str, fs);
        len = fread(buf, 1, 240, pfs);
    }

    // Generate last segement of patch
    p = str;
    p += sprintf(p, "TX%d : 01 C4 FC %02X 02 %02X 00 00 00 ", hci_no, (int)(5+len), (int)len);
    for (n=0; n<len; n++)
    {
        p += sprintf(p, "%02X ", (int)buf[n]);
    }
    fputs(str, fs);
    sprintf(str, "\nRX%d : 04 0E 04 01 C4 FC 00\n", hci_no);
    fputs(str, fs);

    sprintf(str, "END");
    fputs(str, fs);
    fclose(fs);
    fclose(pfs);
    return 1;
}

//-----------------------------------------------
int CBTMT::GenerateChangeBaudrateScript(int hci_no, int baudrate)
{
    FILE *fs;
    char str[BT_MODULE_TEST_SRCSTR_SIZE];
    int baudchar;

    if (1 == baudrate)
    {
        baudchar = 0x08; // 115K
    }
    else if (baudrate==2)
    {
        baudchar = 0x09; // 230K
    }
    else if (baudrate==4)
    {
        baudchar = 0x0A; // 460K
    }
    else if (baudrate==9)
    {
        baudchar = 0x0B; // 921K
    }
    else if (baudrate==3)
    {
        baudchar = 0x0C; // 3M
    }
    else
    {
        return(0);
    }
    fs = fopen("~tmpfile.txt", "w+t" );
    if (fs==0)
    {
        return(0);
    }

    // Generate 1'st segement of patch
    sprintf(str, "TX%d : 01 77 FC 02 %02X 00\n", hci_no, baudchar);
    fputs(str, fs);
    sprintf(str, "RX%d : 04 0F 04 00 01 77 FC\n", hci_no);
    fputs(str, fs);
    //sprintf(str, "TX%d : FF\n", hci_no, baudchar);
    sprintf(str, "TX%d : FF\n", hci_no);
    fputs(str, fs);
    sprintf(str, "RX%d : 04 0E 04 00 01 C0 FC\n", hci_no);
    fputs(str, fs);
    sprintf(str, "RX%d : 04 0E 04 00 01 C0 FC\n", hci_no);
    fputs(str, fs);
    sprintf(str, "END");
    fputs(str, fs);
    fclose(fs);
    return 1;
}

//-----------------------------------------------
CBTMT::CBTMT(void)
{
    ScrFs = 0;
    TmpFs = 0;
    LogFs = 0;
    strcpy(m_cTitle, "Test Process");
    m_asProcName[0] = "Test1";
    int n = 0;
    for (n=1; n<PROCCOUNT; n++)
    {
        m_asProcName[n] = "";
    }
    m_iProcCount = 0;
    m_iEventIdx = 0;
    m_iAutoEventIdx = 0;
//   Reset();
    for(n=0; n<2; n++)
    {
    	  m_eBtTrans[n] = BT_RS232;
    } 
    m_iComPort = 0;
    m_iCurProc = 0;
    m_iLastProc = 0;

    ProcFailCount = 0;
    m_iFailCount = 0;
    IsWaitProc = 0;
    WaitProcPos = 0;
    IsForceEnd = false;
    HasFailProc = false;
    Ticks = 0;
    WaitRX  = 0;
    WaitTime = 0;
    WaitCounter = 0;
    TimeoutTime = 0;
    TimeoutCounter = 0;
    RUN_Time = 0;
    SelSource = 0;
    memset(ScriptFilename,0,sizeof(char)*PATHSTRSIZE);
    memset(LogPath,0,sizeof(char)*PATHSTRSIZE);
    memset(m_cLogString,0,sizeof(char)*LOGSTRSIZE);
    memset(m_cProcFail,0,sizeof(char)*(PROCCOUNT+1)); 
    LogStrPtr = NULL;
    LogEnable = false;
    m_iErrorCode = 0;
    m_iEventNum = 0;
    m_iAutoEventNum = 0;
    
}

//-----------------------------------------------
CBTMT::~CBTMT(void)
{
    if (TmpFs != 0)
    {
        fclose(TmpFs);
        TmpFs = 0;
    }
    if (ScrFs != 0)
    {
        fclose(ScrFs);
        ScrFs = 0;
    }
    if (LogFs != 0)
    {
        fclose(LogFs);
        LogFs = 0;
    }
    //HciUart[0].rs232.Close();
    //HciUart[1].rs232.Close();
    m_cHciUart.rs232.Close();
}

//-----------------------------------------------
int CBTMT::Reset(void)
{
    int n;
    //HciUart[0].rs232.Close();
    //HciUart[1].rs232.Close();
    m_cHciUart.rs232.Close();
    // m_pcHci = &HciUart[0];

    m_iLastProc = m_iCurProc = -1;
    for(n=0; n<PROCCOUNT+1; n++)  m_cProcFail[n] = 0;
    ProcFailCount = 0;
    m_iFailCount = 0;
    IsWaitProc=0;
    WaitProcPos=0;
    IsForceEnd = false;
    HasFailProc = false;

    Ticks = 0;
    WaitRX = 0;
    WaitTime = 0;
    WaitCounter = 0;
    TimeoutTime = 0;
    TimeoutCounter = 0;
    RUN_Time = -1;

    SelSource = SRC_ORGFILE;
    if(TmpFs!=0)
    {
        fclose(TmpFs);
        TmpFs = 0;
    }

    if(ScrFs!=0)
    {
        fclose(ScrFs);
        ScrFs = 0;
    }
    ScrFs = fopen( ScriptFilename, "rt" );
    if(ScrFs==0)   return(0);

    if(LogFs!=0)
    {
        fclose(LogFs);
        LogFs = 0;
    }
    if(LogEnable)
        LogFs = fopen("logfile.txt", "w+t" );
    else
        LogFs = 0;

    LogPath[0] = 0;

    m_cLogString[0] = 0;
    LogStrPtr = m_cLogString;
    LogEnable = true;

    m_iErrorCode = ERR_NONE;
    return(1);
}

//-----------------------------------------------
bool CBTMT::OpenScript(char *filename)
{
    char str[BT_MODULE_TEST_SRCSTR_SIZE];
    strcpy(ScriptFilename, filename);
    if (ScrFs != NULL)
    {
        fclose(ScrFs);
    }
    ScrFs = fopen(ScriptFilename, "rt");
    if (ScrFs==0)
    {
        return(0);
    }
    m_iProcCount = 0;
    while (!feof(ScrFs))
    {
        fgets(str, BT_MODULE_TEST_SRCSTR_SIZE, ScrFs);
        Parse.PreParseStringType(str);
        // ok = Parse.PreParseStringType( str );
        // if(!ok)  return(ERR_PARSESTR);
        if (Parse.StrType == STRTYPE_TITLE)
        {
            strcpy(m_cTitle, Parse.String);
        }
        else if ((Parse.StrType == STRTYPE_PROCNAME)    ||
                 (Parse.StrType == STRTYPE_WAITPROCNAME)
                )
        {
            if (m_iProcCount < PROCCOUNT)
            {
                //strcpy(m_cProcName[m_iProcCount], Parse.String);
                m_asProcName[m_iProcCount] = Parse.String;
                m_iProcCount++;
            }
        }
    }
    fclose(ScrFs);
    ScrFs = 0;
    Reset();
    return 1;
}

//-----------------------------------------------
int CBTMT::CloseScript(void)
{
    long cur_time = GiveDateTime();
    RUN_Time = cur_time - RUN_Time;
    LogStrPtr += sprintf( LogStrPtr, "Execution Time = %ld sec\n", (long)RUN_Time);

    if (TmpFs != 0)
    {
        fclose(TmpFs);
        TmpFs = 0;
    }

    if (ScrFs != 0)
    {
        fclose(ScrFs);
        ScrFs = 0;
    }

    if (LogFs != 0)
    {
        fclose(LogFs);
        LogFs = 0;
    }
    //HciUart[0].rs232.Close();
    //HciUart[1].rs232.Close();
    m_cHciUart.rs232.Close();

    if ((LogPath[0] != 0) && (m_iFailCount != 0))  // copy log to logpath
    {
        char str[2048];
        sprintf(str, "copy logfile.txt %s\\%08ld.txt", LogPath, (long)cur_time );
        system(str);
    }
    return 1;
}

//-----------------------------------------------
int  CBTMT::CountProcResult(void)
{
    int fail_count = ProcFailCount ;

    if(m_iProcCount<0)
        return(0);
    if(m_iCurProc<0)
    {
        m_iCurProc = 0;
        return(0);
    }
    if((IsWaitProc)&&(ProcFailCount!=0))    // do again
    {
        m_cProcFail[m_iCurProc]= 1;
        m_iLastProc = -1;
        CS_fseek(ScrFs, WaitProcPos, SEEK_SET);
    }
    else
    {
        if(ProcFailCount!=0)
        {
            m_cProcFail[m_iCurProc]= 1;
            m_iFailCount++;
            if(HasFailProc)
            {
                system( " copy ~failprc.txt ~tmpfile.txt/Y" );
                SelSource = SRC_TMPFILE;
                if(TmpFs!=0) fclose(TmpFs);
                TmpFs = fopen("~tmpfile.txt", "rt" );
            }
        }
        else
        {
            m_cProcFail[m_iCurProc] = 0;
            IsWaitProc = 0;
        }
        m_iLastProc = m_iCurProc;
        m_iCurProc += (m_iCurProc<m_iProcCount) ? 1 : 0;
    }
    ProcFailCount = 0;
    return(fail_count);
}
//-----------------------------------------------

int  CBTMT::ProcessResult( int err_code )
{
    m_iErrorCode = err_code;
    if( m_iErrorCode!=ERR_NONE )
        if(HasFailProc)
        {
            system( " copy ~failprc.txt ~tmpfile.txt/Y" );
            SelSource = SRC_TMPFILE;
            if(TmpFs!=0) fclose(TmpFs);
            TmpFs = fopen("~tmpfile.txt", "rt" );
        }
    return(1);
}
//-----------------------------------------------

int CBTMT::CS_feof(FILE *fs)
{
    if(SelSource==SRC_ORGFILE)
        return(feof(fs));
    if(SelSource==SRC_TMPFILE)
    {
        int ok = feof(TmpFs);
        if(!ok)  return(ok);
        fclose(TmpFs);
        TmpFs = 0;
        SelSource = SRC_ORGFILE;
        return(ftell(fs));
    }
    return(0);
}
//-----------------------------------------------

char *CBTMT::CS_fgets(char *s, int n, FILE *fs)
{
    if(SelSource==SRC_ORGFILE)
        return(fgets(s, n, fs));
    if(SelSource==SRC_TMPFILE)
    {
        if(TmpFs==0)
        {
            TmpFs = fopen("~tmpfile.txt", "rt" );
        }
        return(fgets(s, n, TmpFs));
    }
    return(0);
}
//-----------------------------------------------

long int CBTMT::CS_ftell(FILE *fs)
{
    if(SelSource==SRC_ORGFILE)
        return(ftell(fs));
    if(SelSource==SRC_TMPFILE)
        return(ftell(TmpFs));
    return(0);
}

//-----------------------------------------------
int CBTMT::CS_fseek(FILE *fs, long offset, int whence)
{
    if(SelSource==SRC_ORGFILE)
        return(fseek(fs, offset, whence));
    if(SelSource==SRC_TMPFILE)
        return(fseek(TmpFs, offset, whence));
    return(0);
}

//-----------------------------------------------
static long  GiveDateTime( void )
{
    struct date d;
    struct time t;
    unsigned long v = 0;
    getdate(&d);
    gettime(&t);
    v = (v*100)+d.da_mon;
    v = (v*100)+d.da_day;
    v = (v*100)+t.ti_hour;
    v = (v*100)+t.ti_min;
    v = (v*100)+t.ti_sec;

    return(v);
}
//=============================================================================

int   CBTMT::GenerateKyleScript( int arg1, int arg2, int arg3 )
{
    FILE *fs;
    //char str[BT_MODULE_TEST_SRCSTR_SIZE];

    fs = fopen("~tmpfile.txt", "w+t" );
    if(fs==0)  return(0);

    /*==== Generate Script statements =======*/
    // example:
    //
    // p=str;
    // p += sprintf( p, "TX1 : 01 C4 FC F5 %02X F0 00 00 00 ", arg1);
    // for(n=0; n<len; n++) {  p+=sprintf( p, "%02X ", (int)buf[n] ); }
    // fputs( str, fs );
    // sprintf( str, "\nRX%d : 04 0E 04 01 C4 FC 00\n", hci_no);
    // fputs( str, fs );
    // LogStrPtr += sprintf( LogStrPtr, "You can add trace string in this statement");
    //
    /*==== Generate Script statements */

    fclose(fs);
    return(1);
}

//=============================================================================
///////////////////////////  Export information   /////////////////////////////
//=============================================================================
void CBTMT::Set_ComPort(int com_port)
{
    m_iComPort = com_port;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTMT::Set_BTTrans(int idx, E_BT_TRANS_T bt_trans)
{
    assert(idx < 2);
    m_eBtTrans[idx] = bt_trans;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_LogStringLen(void)
{
    return strlen(m_cLogString);
}

//-----------------------------------------------------------------------------
char CBTMT::Get_LogString(int idx)
{
    return m_cLogString[idx];
}

//-----------------------------------------------------------------------------
void CBTMT::Set_LogString(int idx, char c)
{
    m_cLogString[idx] = c;
}

//-----------------------------------------------------------------------------
char* CBTMT::Get_LogString(void)
{
    return m_cLogString;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_LastProc(void)
{
    return m_iLastProc;
}

//-----------------------------------------------------------------------------
void CBTMT::Set_LastProc(int proc)
{
    m_iLastProc = proc;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_CurProc(void)
{
    return m_iCurProc;
}

//-----------------------------------------------------------------------------
void CBTMT::Set_CurProc(int proc)
{
    m_iCurProc = proc;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_ErrorCode(void)
{
    return m_iErrorCode;
}

//-----------------------------------------------------------------------------
void CBTMT::Set_ErrorCode(int err_code)
{
    m_iErrorCode = err_code;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_FailCount(void)
{
    return m_iFailCount;
}

//----------------------------------------------------------------------------
void CBTMT::Set_FailCount(int fail_count)
{
    m_iFailCount = fail_count;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char* CBTMT::Get_Title(void)
{
    return m_cTitle;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CBTMT::Get_ProcCount(void)
{
    return m_iProcCount;
}

//----------------------------------------------------------------------------
void CBTMT::Set_ProcCount(int proc_count)
{
    m_iProcCount = proc_count;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char CBTMT::Get_ProcFail(int idx)
{
    assert(idx <= PROCCOUNT);
    return m_cProcFail[idx];
}

//----------------------------------------------------------------------------
void CBTMT::Set_ProcFail(int idx, char proc_fail)
{
    assert(idx <= PROCCOUNT);
    m_cProcFail[idx] = proc_fail;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString CBTMT::Get_ProcName(int idx)
{
    assert(idx < PROCCOUNT);
    return m_asProcName[idx];
}

//----------------------------------------------------------------------------
void CBTMT::Set_ProcName(int idx, AnsiString proc_name)
{
    assert(idx < PROCCOUNT);
    m_asProcName[idx] = proc_name;
}


