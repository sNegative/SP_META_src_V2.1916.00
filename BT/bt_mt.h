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
 *   bt_mt.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT module test header
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
#ifndef _BT_MT_H_
#define _BT_MT_H_

//=============================================================================
#include <stdio.h>
#include <vcl.h>

#ifndef _BT_MT_PARSE_H_
#include "bt_mt_parse.h"
#endif

#ifndef _BT_MT_RS232_H_
#include "bt_mt_rs232.h"
#endif

#ifndef _BT_MT_META_H_
#include "bt_mt_meta.h"
#endif

//-----------------------------------------------
#define  TIMERTICK_UNITE   10
//-----------------------------------------------
#define  ERR_NONE          0
#define  ERR_PARSESTR      1
#define  ERR_HCIOPEN       2
#define  ERR_TX            3
#define  ERR_RXCOMP        4
#define  ERR_TIMEOUT       5
#define  ERR_META          6
#define  ERR_FILEEND      -1
//-----------------------------------------------
#define  SRC_ORGFILE       0
#define  SRC_TMPFILE       1
//-----------------------------------------------
#define  PROCCOUNT         64
#define  PROCSTRSIZE       64
#define  PATHSTRSIZE       1024
#define  LOGSTRSIZE        (8192*2)
//-----------------------------------------------
// module test
#define  BT_MT_TESTCASE_NUM  5
#define  BT_MT_MAX_PROC_NUM 22

class CBTMT
{
private:
    E_BT_TRANS_T m_eBtTrans[2];
    int m_iComPort;
    CBTMTPARSE  Parse;
    CBTMTRS232  m_cHciUart;
    CBTMTMETA  m_cHciMETA;
    //CBTMTRS232  *m_pcHci;

//public:
    char  m_cTitle[PROCSTRSIZE];
    AnsiString  m_asProcName[PROCCOUNT];
    int   m_iProcCount;
    int   m_iCurProc;
    int   m_iLastProc;
    char  m_cProcFail[PROCCOUNT+1];
    int   ProcFailCount;
    int   m_iFailCount;
    int   IsWaitProc;
    long  WaitProcPos;
    bool  IsForceEnd;
    bool  HasFailProc;



//public:
    unsigned long Ticks;
    int           WaitRX;
    int           WaitTime;
    int           WaitCounter;
    long          TimeoutTime;
    long          TimeoutCounter;
    long          RUN_Time;

//public:
    int       SelSource;
    FILE     *TmpFs;



//public:
    char       ScriptFilename[ PATHSTRSIZE ];
    FILE      *ScrFs;

    char       LogPath[ PATHSTRSIZE ];
    FILE      *LogFs;

    char       m_cLogString[LOGSTRSIZE];
    char      *LogStrPtr;
    bool       LogEnable;
    int        m_iErrorCode;
    //E_BT_DEVICE_T m_eBtDevice[MAX_EVENT_NUM];
    int m_iEventNum;
    int m_iEventIdx;
    int m_iAutoEventNum;
    int m_iAutoEventIdx;

public:
    CBTMT(void);
    ~CBTMT();
    bool OpenScript(char *filename);
    int CloseScript(void);
    int   ExecuteNextScript(void);
    int   ProcessResult( int err_code );
    int   CountProcResult(void);

    int   GeneratePatchScript( int hci_no, char* patchfile );
    int   GenerateChangeBaudrateScript( int hci_no, int baudrate );  // baudrate = 1(115K), 2(230K), 4(460K), 9(921K), 3(3M)

    int   GenerateKyleScript( int arg1, int arg2, int arg3 );
    int  TimerTick( void );
    int  Reset( void );
    int       CS_feof(FILE *fs);
    char     *CS_fgets(char *s, int n, FILE *fs);
    long int  CS_ftell(FILE *fs);
    int       CS_fseek(FILE *fs, long offset, int whence);
    void Set_ComPort(int com_port);
    void Set_BTTrans(int idx, E_BT_TRANS_T bt_trans);
    int Get_LogStringLen(void);
    char Get_LogString(int idx);
    void Set_LogString(int idx, char c);
    char* Get_LogString(void);
    int Get_LastProc(void);
    void Set_LastProc(int proc);
    int Get_CurProc(void);
    void Set_CurProc(int proc);
    int Get_ErrorCode(void);
    void Set_ErrorCode(int err_code);
    int Get_FailCount(void);
    void Set_FailCount(int fail_count);
    char* Get_Title(void);
    int Get_ProcCount(void);
    void Set_ProcCount(int proc_count);
    char Get_ProcFail(int idx);
    void Set_ProcFail(int idx, char proc_fail);
    AnsiString Get_ProcName(int idx);
    void Set_ProcName(int idx, AnsiString proc_name);
};

//=============================================================================

#endif
