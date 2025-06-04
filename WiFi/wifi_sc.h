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
 *   wifi_sc.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi script header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _WIFI_SC_H_
#define  _WIFI_SC_H_

#include <fstream.h>
#include <vcl.h>
#include <vector.h>

#include "meta.h"

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_BB_H_
#include "wifi_bb.h"
#endif

#ifndef  _WIFI_MAC_H_
#include "wifi_mac.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

/*---------------------------------------------------------------------------*/

#define  STATE_SC_OK          0
#define  STATE_SC_FAIL        1
#define  STATE_SC_TIMEOUT     2
#define  STATE_SC_STOP        3
#define  STATE_SC_SECTION_OK  4

typedef struct
{
    AnsiString name;
    unsigned int value;
} S_DEFINE;

typedef struct
{
    AnsiString name;
    unsigned char value;
} S_B_VAR;

typedef struct
{
    AnsiString name;
    unsigned short value;
} S_W_VAR;

typedef struct
{
    AnsiString name;
    unsigned int value;
} S_D_VAR;

typedef struct
{
    AnsiString name;
    streampos pos;
} S_LABEL;

typedef struct
{
    streampos pos;
} S_CALL;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    AnsiString filename;
    TStringList *log;
} S_WIFISC;

typedef enum
{
    DEFINE_TAG=0,                // "DEFINE",
    EEPROMR_TAG,                // "EEPROMR",
    EEPROMW_TAG,                  // "EEPROMW",
    MCRR_TAG,                 // "MCRR",
    MCRW_TAG,                 // "MCRW",
    MCR16R_TAG,               // "MCR16R",
    MCR16W_TAG,               // "MCR16W",
    BBR_TAG,                  // "BBR",
    BBW_TAG,                  // "BBW",
    B_TAG,                    // "B",
    W_TAG,                    // "W",
    D_TAG,                    // "D",
    DELAY_TAG,                // "DELAY",
    CALL_TAG,                 // "CALL",
    RET_TAG,                  // "RET",
    EXIT_TAG,                 // "EXIT",
    LABEL_TAG,                // "LABEL",
    LOOP_TAG,                 // "LOOP",
    LOAD_TAG,                 // "LOAD",
    MADDB_TAG,                // "MADDB",
    MADDW_TAG,                // "MADDW",
    MADDD_TAG,                // "MADDD",
    MSUBB_TAG,                // "MSUBB",
    MSUBW_TAG,                // "MSUBW",
    MSUBD_TAG,                // "MSUBD",
    MCMPB_TAG,                // "MCMPB",
    MCMPD_TAG,                // "MCMPD",
    MANDB_TAG,                // "MANDB",
    MANDW_TAG,                // "MANDW",
    MANDD_TAG,                // "MANDD",
    MORB_TAG,                 // "MORB",
    MORW_TAG,                 // "MORW",
    MORD_TAG,                 // "MORD",
    MXORB_TAG,                // "MXORB",
    MXORW_TAG,                // "MXORW",
    MXORD_TAG,                // "MXORD",
    MSHLB_TAG,                // "MSHLB",
    MSHLW_TAG,                // "MSHLW",
    MSHLD_TAG,                // "MSHLD",
    MSHRB_TAG,                // "MSHRB",
    MSHRW_TAG,                // "MSHRW",
    MSHRD_TAG,                // "MSHRD",
    JNE_TAG,                  // "JNE",
    JNB_TAG,                  // "JNB",
    JNA_TAG,                  // "JNA",
    JE_TAG,                   // "JE",
    JB_TAG,                   // "JB",
    JA_TAG,                   // "JA",
    JMP_TAG,                  // "JMP",
    MPRB_TAG,                 // "MPRB",
    MPRW_TAG,                 // "MPRW",
    MPRD_TAG,                 // "MPRD",
    MPWB_TAG,                 // "MPWB",
    MPWW_TAG,                 // "MPWW",
    MPWD_TAG,                 // "MPWD",
    PRINT_TAG,                // "PRINT",
    MPRN2FILE_TAG,            // "MPRN2FILE",
    RAND_TAG,                 // "RAND",
    SET_START_TAG,            // "SET_START",
    SET_STOP_TAG,             // "SET_STOP",
    SET_CONT_TX_TAG,          // "SET_CONT_TX",
    SET_LOCAL_FREQ_TAG,       //  "SET_LOCAL_FREQ",
    SET_CARRIER_SUPP_TAG,     // "SET_CARRIER_SUPP",
    SET_PKT_TX_TAG,           // "SET_PKT_TX",
    SET_PWR_MGT_TAG,          // "SET_PWR_MGT"
    SET_PKT_RX_TAG,           // "SET_PKT_RX",
    SET_REG_DOMAIN_TAG,       // "SET_REG_DOMAIN",
    SET_DBM_TO_DAC_TAG,       // "SET_DBM_TO_DAC",
    SET_END_TAG,              // "SET_END"
} E_WIFISCRIPT_TAG;

typedef enum
{
    SET_OP=0,
    GET_OP,
    ADD_OP,
    SUB_OP,
    CMP_OP,
    AND_OP,
    OR_OP,
    XOR_OP,
    SHL_OP,
    SHR_OP,
} E_OPERATION;

typedef struct
{
    E_WIFISCRIPT_TAG tag;
    AnsiString op1;
    AnsiString op2;
}
S_OP;

/*---------------------------------------------------------------------------*/

class  CWIFISC
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    int   m_iConfirmState;
    S_WIFISC  m_WiFiSc;
    ifstream *m_pifs;
    filebuf* m_pFBuf;
    vector<S_DEFINE> *m_pvDefine;
    vector<S_B_VAR> *m_pvBVar;
    vector<S_W_VAR> *m_pvWVar;
    vector<S_D_VAR> *m_pvDVar;
    vector<S_LABEL>  *m_pvLabel;
    vector<S_CALL>  *m_pvCall;
//     CWIFIBB    m_WIFI_BB_Obj;
//     CWIFIMAC   m_WIFI_MAC_Obj;




protected:


    void  Confirm( int confirm_state );

public:

    CWIFISC( void );
    ~CWIFISC();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Public member


    void  (*ConfirmCallback)( void );





    void  REQ_Start( S_WIFISC  wifisc );
    void  REQ_Stop(  );

    // memory
    void  AllocateVector( void );
    void  DeAllocateVector( void );

    // script file
    void  REQ_Read_From_File( void );
    bool  OpenFile( void );
    void  CloseFile( void );
    bool  ParseFile( void );
    bool  ParseCommandLine( AnsiString as_cmd );
    bool  Interpret( S_OP op );
    unsigned int GetDefineValue( AnsiString str );
    void  ByteValueOperate( AnsiString byte_name, unsigned char &value, E_OPERATION op );
    void  DWordValueOperate( AnsiString dword_name, unsigned int &value, E_OPERATION op );
    void  WordValueOperate( AnsiString word_name, unsigned short &value, E_OPERATION op );

    // log
    void  AddLogToStringList( AnsiString as_log );
    // void  Clear_Log( void );

    // global information
    int   Get_ConfirmState( void );
    // void  Get_Log( TStringList *log );

};

/*---------------------------------------------------------------------------*/
#endif