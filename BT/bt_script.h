/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bt_script.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command script test header
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_SCRIPT_H_
#define  _BT_SCRIPT_H_

#include <fstream.h>
#include <vcl.h>
#include <vector.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

/*---------------------------------------------------------------------------*/
typedef struct
{
    HANDLE hPostMsgDestHandle;
    AnsiString filename;
    TStringList *log;
    AnsiString as_script_name;
} S_BT_SCT;


typedef struct
{
    unsigned short	us_opcode;
    unsigned char	uc_len;
    AnsiString	as_cmd;
} S_BT_HCI_CMD;

typedef struct
{
    unsigned char   uc_event;
    char         	c_status;
    unsigned short  us_handle;
    unsigned char	uc_len;
    AnsiString	as_parms;
} S_BT_HCI_EVENT;

typedef struct
{
    AnsiString   as_hci_cmd;
    unsigned char   uc_last_event;
    unsigned int    ui_ms_timeout;
    vector<AnsiString> v_hci_event;
} S_BT_SCT_CMD;

typedef struct
{
    AnsiString as_script_name;
    AnsiString as_script_tag;
    vector<S_BT_SCT_CMD>  v_cmd;
} S_BT_SCT_SCRIPT;


typedef struct
{
    AnsiString as_name;
    unsigned char uc_value;
    bool b_valid;
} S_BT_B_VAR;

typedef struct
{
    AnsiString as_name;
    unsigned short us_value;
    bool b_valid;
} S_BT_W_VAR;

typedef struct
{
    AnsiString as_name;
    unsigned int ui_value;
    bool b_valid;
} S_BT_D_VAR;




typedef enum
{
    BT_SCT_B1_TAG = 0,
    BT_SCT_B2_TAG,
    BT_SCT_B3_TAG,
    BT_SCT_B4_TAG,
    BT_SCT_B5_TAG,
    BT_SCT_B6_TAG,
    BT_SCT_B7_TAG,
    BT_SCT_B8_TAG,
    BT_SCT_B9_TAG,
    BT_SCT_B10_TAG,
    BT_SCT_B11_TAG,
    BT_SCT_B12_TAG,
    BT_SCT_B13_TAG,
    BT_SCT_B14_TAG,
    BT_SCT_B15_TAG,
    BT_SCT_B16_TAG,
    BT_SCT_B17_TAG,
    BT_SCT_B18_TAG,
    BT_SCT_B19_TAG,
    BT_SCT_B20_TAG,
    BT_SCT_B21_TAG,
    BT_SCT_B22_TAG,
    BT_SCT_B23_TAG,
    BT_SCT_B24_TAG,
    BT_SCT_B25_TAG,
    BT_SCT_B26_TAG,
    BT_SCT_B27_TAG,
    BT_SCT_B28_TAG,
    BT_SCT_B29_TAG,
    BT_SCT_B30_TAG,
    BT_SCT_B31_TAG,
    BT_SCT_B32_TAG,
    BT_SCT_B33_TAG,
    BT_SCT_B34_TAG,
    BT_SCT_B35_TAG,
    BT_SCT_B36_TAG,
    BT_SCT_B37_TAG,
    BT_SCT_B38_TAG,
    BT_SCT_B39_TAG,
    BT_SCT_B40_TAG,
    BT_SCT_B41_TAG,
    BT_SCT_B42_TAG,
    BT_SCT_B43_TAG,
    BT_SCT_B44_TAG,
    BT_SCT_B45_TAG,
    BT_SCT_B46_TAG,
    BT_SCT_B47_TAG,
    BT_SCT_B48_TAG,
    BT_SCT_B49_TAG,
    BT_SCT_B_TAG,
    BT_SCT_W_TAG,
    BT_SCT_D_TAG,
    BT_SCT_UNKNOW
} E_BT_SCT_TAG;

typedef struct
{
    E_BT_SCT_TAG e_tag;
    AnsiString as_op1;
    AnsiString as_op2;
} S_BT_SCT_OP;

/*---------------------------------------------------------------------------*/
class CBTSCT
{
private:
    // common
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_BT_SCT  m_sBTSCT;
    ifstream *m_pifs;
    filebuf* m_pFBuf;
    E_BT_SCT_TAG m_eSCTSec;
    BT_HCI_EVENT  m_sHCIEvent;
    S_BT_SCT_CMD  m_sSCTCmd;
    vector<S_BT_SCT_SCRIPT> *m_pvScript;
    vector<S_BT_SCT_SCRIPT>:: iterator m_IterScript;
    vector<S_BT_SCT_CMD>:: iterator m_IterCmd;
    vector<AnsiString>:: iterator m_IterEvent;
    vector<S_BT_B_VAR> *m_pvBVar;
    vector<S_BT_W_VAR> *m_pvWVar;
    vector<S_BT_D_VAR> *m_pvDVar;
protected:
    void Confirm(META_RESULT confirm_state);
    AnsiString Get_ScriptTagString(E_BT_SCT_TAG eTag);

public:
    CBTSCT(void);
    ~CBTSCT();

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Public member
    void  (*ConfirmCallback)(void);
    void  REQ_Start(S_BT_SCT &bt_sct);
    void  REQ_Test_Script(void);
    void  REQ_Send_HCI_Command(BT_HCI_COMMAND hci_cmd, unsigned int  ms_timeout, unsigned last_event);
    void __stdcall CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  REQ_Stop();

    // memory
    void  AllocateVector(void);
    void  DeAllocateVector(void);
    void  EraseVector(void);
    void  ResetBVarData(void);

    // script file
    bool  REQ_Read_Last_SCT_File_Start(S_BT_SCT &bt_sct);
    void  REQ_Read_From_File_Start(S_BT_SCT &bt_sct);
    void  REQ_Read_From_File(void);
    bool  OpenFile(void);
    void  CloseFile(void);
    bool  ParseFile(void);
    bool  ParseCommandLine(AnsiString as_cmd);
    bool  ParseSCTHeader(AnsiString as_cmd);
    bool  ParseSCTBody(AnsiString as_cmd);
    bool  InterpretCommand(AnsiString as_cmd, BT_HCI_COMMAND &hci_cmd);
    bool  InterpretEvent(BT_HCI_EVENT hci_event, AnsiString as_event);
    unsigned short Get_OpCode(AnsiString as_cmd);
    unsigned char Get_CommandParameterLen(AnsiString as_cmd);
    unsigned char Get_LastEvent(AnsiString as_event);
    unsigned char Get_EventParameterLen(AnsiString as_event);
    int Get_VariableIndex(AnsiString as, AnsiString as_var, unsigned char len);

    // log
    void  AddParseLogToStringList(AnsiString as_log);
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event);

    // export information
    META_RESULT Get_ConfirmState(void);
    BT_HCI_EVENT  Get_HCIEvent(void);
    vector<S_BT_SCT_SCRIPT>*  Get_ScriptVector(void);
};

/*---------------------------------------------------------------------------*/
#endif