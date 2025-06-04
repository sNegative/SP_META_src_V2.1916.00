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
 *   bt_hci.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command test header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_HCI_H_
#define  _BT_HCI_H_

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
#define  BT_HCI_VALUE_SIZE    20
#define  HCI_DEFAULT_TIMEOUT_MS  1000

//----------------------------------------------------------------------------
typedef struct
{
    HANDLE hPostMsgDestHandle;
    AnsiString filename;
    TStringList *log;
    BT_HCI_COMMAND s_hci_cmd;
    unsigned char  uc_last_event;
    unsigned int   ui_ms_timeout;
} S_BT_HCI;



typedef struct
{
    unsigned char uc_value[BT_HCI_VALUE_SIZE];
    unsigned char  uc_nz_byte;
} S_BT_HCI_VALUE;

typedef struct
{
    AnsiString as_name;
    unsigned int ui_bytes; // bytes
    S_BT_HCI_VALUE s_value;
    bool b_rangecheck;
    bool b_show;
    S_BT_HCI_VALUE s_max_value;
    S_BT_HCI_VALUE s_min_value;
} S_BT_HCI_PARAMETER;

typedef struct
{
    //AnsiString as_group_tag;
    AnsiString as_cmd_name;
    AnsiString as_cmd_tag;
    unsigned short us_opcode;
    unsigned char  uc_last_event;
    unsigned int ui_send_num; // send parameter number
    vector<S_BT_HCI_PARAMETER>  v_send_par;
    unsigned int ui_receive_num; // receive parameter number
    vector<S_BT_HCI_PARAMETER>  v_receive_par;
    unsigned int   ui_ms_timeout;
} S_BT_HCI_COMMAND;

typedef struct
{
    AnsiString as_group_name;
    AnsiString as_group_tag;
    vector<S_BT_HCI_COMMAND>  v_cmd;
} S_BT_HCI_GROUP;



typedef struct
{
    AnsiString as_category_name;
    AnsiString as_category_tag;
    vector<S_BT_HCI_COMMAND>  v_cmd;
} S_BT_HCI_CATEGORY;



typedef enum
{
    BT_HCI_GROUP_TAG = 0,
    BT_HCI_COMMAND_TAG,
    BT_HCI_DEFINE_TAG,
    BT_HCI_CATEGORY_TAG,
    BT_HCI_UNKNOW
} E_BT_HCI_TAG;

typedef struct
{
    unsigned short  us_opcode;
    unsigned char   uc_total_par_size;
    unsigned char   ui_par_num; // send, recieve parameter number
    vector<S_BT_HCI_PARAMETER>  v_par;
} S_HCI_TX_CMD;

typedef struct
{
    unsigned char uc_cmd[256];
} S_HCI_TX_CMD_FORMAT;

typedef struct
{
    //unsigned char   uc_event_code;
    unsigned char   uc_cmd_num;
    unsigned short  us_opcode;
    // unsigned char   uc_packet_num;
    unsigned char   uc_total_par_size;
    // unsigned char   uc_par_num; // recieve parameter number
    vector<S_BT_HCI_PARAMETER>  v_par;
} S_HCI_RX_EVENT;

typedef struct
{
    unsigned char uc_event[256];
} S_HCI_RX_EVENT_FORMAT;
/*---------------------------------------------------------------------------*/

class  CBTHCI
{
private:
    // common
    META_RESULT m_eConfirmState;
    bool m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    // AnsiString m_asFileName;
    S_BT_HCI  m_sBTHCI;
    // ifstream *m_pifs;
    // filebuf* m_pFBuf;
    FILE *m_fp;
    E_BT_HCI_TAG m_eHCISec;
    int m_iHCICategory;
    vector<S_BT_HCI_GROUP> *m_pvHCIGroup;
    vector<S_BT_HCI_CATEGORY> *m_pvHCICategory;
    vector<S_BT_HCI_CATEGORY>:: iterator m_vLastCateogryIter;
    bool m_bFirstCategoryBody;
    BT_HCI_EVENT  m_sHCIEvent;
    // S_HCI_TX_CMD  m_sTxCmd;
    // S_HCI_RX_EVENT  m_sRxEvent;
    // S_HCI_TX_CMD_FORMAT m_sTxCmdFmt;
    // S_HCI_RX_EVENT_FORMAT m_sRxEventFmt;
    // vector<S_BT_HCI_COMMAND> *m_pvHCICmd;

protected:
    void  Confirm(META_RESULT confirm_state);

public:
    CBTHCI(void);
    ~CBTHCI();

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Public member
    void  (*ConfirmCallback)(void);
    void  REQ_Start(S_BT_HCI &bt_hci);
    void  REQ_Send_HCI_Command(void);
    void __stdcall CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  REQ_Stop(  );

    // memory
    void  AllocateVector( void );
    void  DeAllocateVector( void );
    void  EraseVector( void );

    // script file
    bool  REQ_Read_Last_HCI_File_Start( S_BT_HCI  &bt_hci );
    void  REQ_Read_From_File_Start( S_BT_HCI &bt_hci );
    void  REQ_Read_From_File( void );
    bool  OpenFile( void );
    void  CloseFile( void );
    bool  ParseFile( void );
    bool  ParseCommandLine( AnsiString as_cmd );
    bool  ParseHCIGroup( AnsiString as_cmd );
    bool  ParseHCICategory( AnsiString as_cmd );
    bool  ParseHCICommand( AnsiString as_cmd );
    bool  ParseHCICmdDefine( AnsiString as_cmd );

    // compose/decompose HCI command
    //void  Compose_HCI_TX_Command( BT_HCI_COMMAND &hci_cmd );
    //void  DeCompose_HCI_RX_Event( void );

    // log
    void  AddParseLogToStringList(AnsiString as_log);
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event);

    // export information
    META_RESULT Get_ConfirmState( void );
    vector<S_BT_HCI_CATEGORY>*  Get_HciCategoryVector( void );
    vector<S_BT_HCI_GROUP>*  Get_HciGroupVector( void );
    BT_HCI_EVENT  Get_HCIEvent( void );

};

/*---------------------------------------------------------------------------*/
#endif