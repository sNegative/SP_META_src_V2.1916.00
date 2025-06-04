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
 *   bt_script.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command script test source
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
 * Jun 19 2008 mtk00490
 * [STP100001739] [META] META ver 5.0820.0
 *
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
//===========================================================================


#pragma hdrstop

#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_SCRIPT_H_
#include "bt_script.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif


// misc
#ifndef  _STR_UTILS_H_
#include "str_utils.h"
#endif

#ifndef  _FILE_UTILS_H_
#include "file_utils.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _MISC_BT_H_
#include "misc_bt.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#define INVALID_TAG  -1

const AnsiString HEADER_WORD[]=
{
    "B1:",
    "B2:",
    "B3:",
    "B4:",
    "B5:",
    "B6:",
    "B7:",
    "B8:",
    "B9:",
    "B10",
    "B11:",
    "B12:",
    "B13:",
    "B14:",
    "B15:",
    "B16:",
    "B17:",
    "B18:",
    "B19:",
    "B20",
    "B21:",
    "B22:",
    "B23:",
    "B24:",
    "B25:",
    "B26:",
    "B27:",
    "B28:",
    "B29:",
    "B30",
    "B31:",
    "B32:",
    "B33:",
    "B34:",
    "B35:",
    "B36:",
    "B37:",
    "B38:",
    "B39:",
    "B40",
    "B41:",
    "B42:",
    "B43:",
    "B44:",
    "B45:",
    "B46:",
    "B47:",
    "B48:",
    "B49:",
    "BYTE",
    "WORD",
    "DWORD",

};

//----------------------------------------------------------------------------





static CBTSCT*  gs_bt_sct_ptr;
static bool g_bIsRunning = false;
//==============================================================================
static void  REQ_Read_From_File( void )
{
    gs_bt_sct_ptr->REQ_Read_From_File();
}

//----------------------------------------------------------------------------
static void  REQ_Test_Script( void )
{
    gs_bt_sct_ptr->REQ_Test_Script();
}

//----------------------------------------------------------------------------
//static void  REQ_Send_HCI_Command( void )
//{   gs_bt_sct_ptr->REQ_Send_HCI_Command();
//}

//------------------------------------------------------------------------------
static void __stdcall CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_sct_ptr->CNF_HCIEvent( cnf, token, usrData );
}

//===========================================================================
CBTSCT::CBTSCT(void)
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    AllocateVector();   
    m_pifs = NULL;
    m_pFBuf = NULL;
    m_eSCTSec = BT_SCT_B1_TAG;
    memset(&m_sBTSCT,0,sizeof(m_sBTSCT));
    memset(&m_sSCTCmd,0,sizeof(m_sSCTCmd));
}

//---------------------------------------------------------------------------
CBTSCT::~CBTSCT(void)
{
    DeAllocateVector();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTSCT::AllocateVector(void)
{
    if (!m_pvScript)
    {
        m_pvScript = new vector<S_BT_SCT_SCRIPT>;
    }

    if (!m_pvBVar)
    {
        m_pvBVar = new vector<S_BT_B_VAR>;
    }

    if (!m_pvWVar)
    {
        m_pvWVar = new vector<S_BT_W_VAR>;
    }

    if (!m_pvDVar)
    {
        m_pvDVar = new vector<S_BT_D_VAR>;
    }
}

//---------------------------------------------------------------------------
void CBTSCT::DeAllocateVector(void)
{
    if (m_pvScript)
    {
        if (!m_pvScript->empty())
        {
            m_pvScript->erase(m_pvScript->begin(), m_pvScript->end());
        }
        delete m_pvScript;
        m_pvScript = NULL;
    }

    if (m_pvBVar)
    {
        if (!m_pvBVar->empty())
        {
            m_pvBVar->erase(m_pvBVar->begin(), m_pvBVar->end());
        }
        delete m_pvBVar;
        m_pvBVar = NULL;
    }

    if (m_pvWVar)
    {
        if (!m_pvWVar->empty())
        {
            m_pvWVar->erase(m_pvWVar->begin(), m_pvWVar->end());
        }
        delete m_pvWVar;
        m_pvWVar = NULL;
    }

    if (m_pvDVar)
    {
        if (!m_pvDVar->empty())
        {
            m_pvDVar->erase(m_pvDVar->begin(), m_pvDVar->end());
        }

        delete m_pvDVar;
        m_pvDVar = NULL;
    }
}

//---------------------------------------------------------------------------
void  CBTSCT::EraseVector(void)
{
    if (!m_pvScript->empty())
    {
        m_pvScript->erase(m_pvScript->begin(), m_pvScript->end());
    }

    if (NULL != m_pvBVar)
    {
        if (!m_pvBVar->empty())
        {
            m_pvBVar->erase(m_pvBVar->begin(), m_pvBVar->end());
        }
    }

    if (NULL != m_pvWVar)
    {
        if (!m_pvWVar->empty())
        {
            m_pvWVar->erase(m_pvWVar->begin(), m_pvWVar->end());
        }
    }

    if (NULL != m_pvDVar)
    {
        if (!m_pvDVar->empty())
        {
            m_pvDVar->erase(m_pvDVar->begin(), m_pvDVar->end());
        }
    }
}

//---------------------------------------------------------------------------
void CBTSCT::ResetBVarData(void)
{
    if (NULL != m_pvBVar)
    {
        if (!m_pvBVar->empty())
        {
            vector<S_BT_B_VAR>:: iterator iter_b_var;
            for (iter_b_var = m_pvBVar->begin(); iter_b_var != m_pvBVar->end(); iter_b_var++)
            {
                iter_b_var->b_valid = false;
            }
        }
    }
}

//---------------------------------------------------------------------------
/*void CBTSCT::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    Confirm(METAAPP_STOP);
}*/


//---------------------------------------------------------------------------
void CBTSCT::Confirm(META_RESULT confirm_state )
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;

    // CloseFile();
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}


//============================================================================
void CBTSCT::REQ_Start(S_BT_SCT &bt_sct)
{
    gs_bt_sct_ptr  = this;
    g_bIsRunning    = true;

    m_sBTSCT = bt_sct;

    ResetBVarData();

    for (m_IterScript = m_pvScript->begin(); m_IterScript != m_pvScript->end(); m_IterScript++)
    {
        if (m_IterScript->as_script_name.AnsiCompareIC(m_sBTSCT.as_script_name) == 0)
        {
            break;
        }
    }

    m_IterCmd = m_IterScript->v_cmd.begin();
    ActiveMan->SetActiveFunction(::REQ_Test_Script);
}

//---------------------------------------------------------------------------
void CBTSCT::REQ_Test_Script(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (m_IterCmd != m_IterScript->v_cmd.end())
    {
        m_IterEvent = m_IterCmd->v_hci_event.begin();
        BT_HCI_COMMAND hci_cmd;

        InterpretCommand(m_IterCmd->as_hci_cmd, hci_cmd);
        REQ_Send_HCI_Command(hci_cmd, m_IterCmd->ui_ms_timeout, m_IterCmd->uc_last_event);
        m_IterCmd++;
    }
    else
    {
        Confirm(META_SUCCESS);
    }
}

//---------------------------------------------------------------------------
void CBTSCT::REQ_Send_HCI_Command( BT_HCI_COMMAND hci_cmd, unsigned int  ms_timeout, unsigned last_event )
{
    if (!g_bIsRunning)
    {
        return;
    }
    AddTxLogToStringList(hci_cmd);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, &hci_cmd, ::CNF_HCIEvent, NULL, last_event);

    if (META_SUCCESS != MetaResult)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
            return;
        }
        else if (META_CANCEL == MetaResult)
        {
            Confirm(META_CANCEL);
            return;
        }
        else
        {
            Confirm(META_FAILED);
            return;
        }
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTSCT::CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // if(!g_bIsRunning)  return;
    // m_IterEvent
    m_sHCIEvent = *cnf;
    AddRxLogToStringList(*cnf);
    if (!InterpretEvent(m_sHCIEvent, *m_IterEvent))
    {
        AddParseLogToStringList("Receive unexpected event");
        Confirm(META_FAILED);
        return;
    }

    if (m_IterEvent != m_IterCmd->v_hci_event.end())
    {
        m_IterEvent++;
    }
    ActiveMan->SetActiveFunction(::REQ_Test_Script);
}


//===========================================================================
void CBTSCT::REQ_Read_From_File_Start(S_BT_SCT &bt_sct)
{
    gs_bt_sct_ptr  = this;
    g_bIsRunning    = true;

    m_sBTSCT = bt_sct;


    EraseVector();
    ActiveMan->SetActiveFunction(::REQ_Read_From_File);
}

//----------------------------------------------------------------------------
bool CBTSCT::REQ_Read_Last_SCT_File_Start(S_BT_SCT &bt_sct)
{
    m_sBTSCT = bt_sct;

    EraseVector();

    if (!OpenFile())
    {
        CloseFile();
        return false;
    }

    if (!ParseFile())
    {
        CloseFile();
        return false;
    }

    CloseFile();
    return true;
}

//----------------------------------------------------------------------------
void CBTSCT::REQ_Read_From_File(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    if (!OpenFile())
    {
        CloseFile();
        Confirm( META_FAILED );
        return;
    }

    if (!ParseFile())
    {
        CloseFile();
        Confirm(META_FAILED);
        return;
    }

    CloseFile();
    Confirm(META_SUCCESS);
}

//----------------------------------------------------------------------------
bool  CBTSCT::OpenFile(void)
{
    // if( m_ifs.is_open() )
    // {
    //     CloseFile();
    // }
    if (!CheckFileExist(m_sBTSCT.filename))
    {
        return false;
    }

    if(!m_pifs)
    {
        m_pifs = new ifstream;
    }
    m_pifs->open(m_sBTSCT.filename.c_str());
    //m_ifs.seekg( ios::beg );
    //m_ifs.setmode( filebuf::text ); // set to text mode
    //m_pFBuf = m_ifs.rdbuf();

    return true;
}

//---------------------------------------------------------------------------
void CBTSCT::CloseFile(void)
{
    if (m_pifs->is_open())
    {
        m_pifs->close();
        delete m_pifs;
    }
}

//---------------------------------------------------------------------------
bool CBTSCT::ParseFile(void)
{
    const int str_size = 256;
    char str[str_size];
    m_eSCTSec = BT_SCT_UNKNOW;
    while (!m_pifs->eof())
    {
        m_pifs->getline(str, str_size, '\n');
        if (!ParseCommandLine(str))
        {
            AnsiString as_str = str;
            AddParseLogToStringList(as_str + " error");
            return false;
        }
        // streampos pos = m_ifs.tellg();
        // m_ifs.tellg();
    }
    return true;
}

//---------------------------------------------------------------------------
bool CBTSCT::ParseCommandLine(AnsiString as_cmd)
{
    bool ok;
    as_cmd = as_cmd.UpperCase();
    as_cmd = as_cmd.Trim();
    if (as_cmd.AnsiCompareIC("") == 0)
    {
        return true;  // NULL
    }
    if (as_cmd.AnsiPos("//") != 0)
    {
        return true; // note
    }
    for (int i=0; i<sizeof(HEADER_WORD)/sizeof(HEADER_WORD[0]); i++)
    {
        if (as_cmd.AnsiPos(HEADER_WORD[i] ) != 0)
        {
            m_eSCTSec = (E_BT_SCT_TAG) i;
            bool ok = ParseSCTHeader(as_cmd);
            {
                return ok;
            }
        }
    }

    ok = ParseSCTBody(as_cmd);
    return ok;
}

//---------------------------------------------------------------------------
AnsiString CBTSCT::Get_ScriptTagString(E_BT_SCT_TAG eTag)
{
    AnsiString as_tag;
    if ((eTag >= BT_SCT_B1_TAG) && (eTag <= BT_SCT_B49_TAG))
    {
        as_tag = "B" + IntToStr(eTag + 1);
    }
    return as_tag;
}

//---------------------------------------------------------------------------
bool CBTSCT::ParseSCTHeader(AnsiString as_cmd)
{
    S_BT_SCT_SCRIPT script;
    int iLD_l = as_cmd.AnsiPos(": ");
    if (iLD_l != 0)
    {
        script.as_script_name = as_cmd.SubString(iLD_l+2, as_cmd.Length()-iLD_l-1);
        RemoveLastSpaceFromStr(script.as_script_name);
        if ((m_eSCTSec >= BT_SCT_B1_TAG) && (m_eSCTSec <= BT_SCT_B49_TAG))
        {
            script.as_script_tag = Get_ScriptTagString(m_eSCTSec);
        }
        m_pvScript->push_back(script);
    }
    else
    {
        S_BT_SCT_OP op;
        AnsiString as_rem;
        int iLD_space = as_cmd.LastDelimiter( " " );
        int iLD_comma = as_cmd.AnsiPos( "," );
        if( iLD_comma != 0 )
        {
            if( iLD_comma > iLD_space )
            {
                op.as_op2 = as_cmd.SubString( iLD_comma+1, as_cmd.Length()-iLD_comma );

            }
            else
            {
                op.as_op2 = as_cmd.SubString( iLD_space+1, as_cmd.Length()-iLD_space );
            }
            as_rem = as_cmd.SubString( 1, iLD_comma-1 );
            iLD_space = as_rem.LastDelimiter( " " );
            op.as_op1 = as_rem.SubString( iLD_space+1, as_cmd.Length()-iLD_space );
        }
        else // no op2
        {
            if( as_cmd.AnsiPos("\"") == 0 ) // no " "
            {
                op.as_op1 = as_cmd.SubString( iLD_space+1, as_cmd.Length() - iLD_comma );
                as_rem = as_cmd;
            }
            else
            {
                int iLD_1stQuotes = as_cmd.AnsiPos("\"");
                int iLD_2ndQuotes = as_cmd.LastDelimiter("\"");
                op.as_op1 = as_cmd.SubString( iLD_1stQuotes+1, iLD_2ndQuotes - iLD_1stQuotes -1 );
                as_rem = as_cmd.SubString( 1, iLD_1stQuotes - 1 );
            }
            op.as_op2 = "";
        }

        switch( m_eSCTSec )
        {
        case BT_SCT_B_TAG:                    // "B",
        {
            S_BT_B_VAR b_var;
            b_var.as_name = op.as_op1;
            if( op.as_op2.AnsiCompareIC("") == 0 )
            {
                //  b_var.uc_value = 0;
                b_var.b_valid  = false;
            }
            else
            {
                AnsiString_Hex_To_UnsignedChar( op.as_op2, b_var.uc_value );
                b_var.b_valid   = true;
            }
            m_pvBVar->push_back( b_var );
        }
        break;

        case BT_SCT_W_TAG:                    // "W",
        {
            S_BT_W_VAR w_var;
            w_var.as_name = op.as_op1;
            if( op.as_op2.AnsiCompareIC("") == 0 )
            {
                w_var.us_value = 0;
            }
            else
            {
                AnsiString_Hex_To_UnsignedShort( op.as_op2, w_var.us_value );
            }
            m_pvWVar->push_back( w_var );
        }
        break;

        case BT_SCT_D_TAG:                    // "D",
        {
            S_BT_D_VAR d_var;
            d_var.as_name = op.as_op1;
            if( op.as_op2.AnsiCompareIC("") == 0 )
            {
                d_var.ui_value = 0;
            }
            else
            {
                AnsiString_Hex_To_UnsignedInt( op.as_op2, &(d_var.ui_value) );
            }
            m_pvDVar->push_back( d_var );
        }
        break;
        } // switch()
    } // else

    return true;
}

//---------------------------------------------------------------------------
bool CBTSCT::ParseSCTBody( AnsiString as_cmd )
{
    vector<S_BT_SCT_SCRIPT>:: iterator iter_script = m_pvScript->end()-1;
    vector<S_BT_SCT_CMD>:: iterator iter_cmd = iter_script->v_cmd.end()-1;
    S_BT_SCT_CMD cmd;
    //int i;
    //unsigned char array[HCI_CMD_MAX_LEN];
    // for( i=0; i<HCI_CMD_MAX_LEN; i++ )
    //     cmd.s_hci_cmd.m_cmd[i] = 0;

    if( as_cmd.AnsiPos("TX:") != 0 )
    {
        int iLD_l = as_cmd.AnsiPos("TX:");
        AnsiString as_TX_cmd = as_cmd.SubString( iLD_l+4, as_cmd.Length() );
        // if( ! InterpretCommand( as_TX_cmd ) )
        //     return false;
        // int count = String_Hex_To_Array_UnsignedChar( as_TX_cmd.c_str(), array, HCI_CMD_MAX_LEN );
        // cmd.s_hci_cmd.m_opcode = (array[HCI_CMD_OPCODE_HIGH_IDX] << 8) | array[HCI_CMD_OPCODE_LOW_IDX];
        // cmd.s_hci_cmd.m_len    =  array[HCI_CMD_LEN_IDX];
        // for( i=HCI_CMD_PARAMETER_START_IDX; i<count; i++ )
        // {   cmd.s_hci_cmd.m_cmd[i-HCI_CMD_PARAMETER_START_IDX] = array[i];
        // }
        // cmd.s_hci_cmd.m_opcode = Get_OpCode( as_TX_cmd );
        // cmd.s_hci_cmd.m_len    = Get_CommandParameterLen( as_TX_cmd );
        cmd.as_hci_cmd = as_TX_cmd;
        iter_script->v_cmd.push_back( cmd );
    }
    else if( as_cmd.AnsiPos("RX:") != 0 )
    {
        //BT_HCI_EVENT event;
        int iLD_l = as_cmd.AnsiPos("RX:");
        AnsiString as_RX_event = as_cmd.SubString( iLD_l+4, as_cmd.Length() ).Trim();
        // if( ! InterpretCommand( as_RX_event ) )
        //     return false;
        // int count = String_Hex_To_Array_UnsignedChar( as_RX_event.c_str(), array, HCI_CMD_MAX_LEN );
        // event.m_event = array[HCI_EVENT_ID_IDX];
        // event.m_len   = array[HCI_EVENT_LEN_IDX];
        // for( i=HCI_EVENT_PARAMETER_START_IDX; i<count; i++ )
        // {   event.m_parms[i-HCI_EVENT_PARAMETER_START_IDX] = array[i];
        // }
        //vector<BT_HCI_EVENT>:: iterator iter_event = iter_cmd->v_hci_event.end()-1;
        //event.m_event = Get_LastEvent( as_RX_event );
        //event.m_len   = Get_EventParameterLen( as_RX_event );
        iter_cmd->uc_last_event = Get_LastEvent( as_RX_event );
        iter_cmd->ui_ms_timeout = 20000;
        iter_cmd->v_hci_event.push_back( as_RX_event );
    }

    return true;
}

//---------------------------------------------------------------------------
bool  CBTSCT::InterpretCommand( AnsiString as_cmd, BT_HCI_COMMAND &hci_cmd )
{
    bool b_find;
    vector<S_BT_B_VAR>:: iterator iter_b_var;
    unsigned char array[HCI_CMD_MAX_LEN];
    int count = ::Get_CharAppearCount( as_cmd, '&' );
    AnsiString as_var_name;
    for(int i=0; i<count; i++ )
    {
        b_find = false;
        int iLD_l = Get_CharAppearPosition( as_cmd, '&', 1 );;
        int iLD_r = Get_CharAppearPosition( as_cmd, '&', ',', 1 );
        if( iLD_r < iLD_l )
        {
            iLD_r = as_cmd.Length()+1;
        }

        as_var_name = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 );


        for( iter_b_var = m_pvBVar->begin(); iter_b_var != m_pvBVar->end(); iter_b_var++ )
        {
            if( iter_b_var->as_name.AnsiCompareIC(as_var_name) == 0 )
            {
                char str_value[HCI_CMD_MAX_LEN];
                sprintf( str_value, "%X", iter_b_var->uc_value );
                AnsiString as_value(str_value);
                as_cmd = as_cmd.SubString(1, iLD_l-1) + as_value + as_cmd.SubString(iLD_r, as_cmd.Length()-iLD_r+1);
                b_find = true;
                break;
            }
        }

        if( ! b_find )
            return false;

        // String_Hex_To_Array_UnsignedChar( as_cmd.c_str(), hci_cmd.m_cmd, HCI_CMD_MAX_LEN );

    }  // for

    hci_cmd.m_opcode = Get_OpCode( as_cmd );
    hci_cmd.m_len    = Get_CommandParameterLen( as_cmd );
    AnsiString_Hex_To_Array_UnsignedChar( as_cmd.c_str(), array, HCI_CMD_MAX_LEN, ',' );
    for( int i=0; i<hci_cmd.m_len; i++ )
    {
        hci_cmd.m_cmd[i] = array[i+HCI_CMD_PARAMETER_START_IDX];
    }

    return true;
}

//---------------------------------------------------------------------------
bool  CBTSCT::InterpretEvent( BT_HCI_EVENT hci_event, AnsiString as_event )
{
    bool b_find;
    AnsiString as_var_name;
    vector<S_BT_B_VAR>:: iterator iter_b_var;
    unsigned char str[2*HCI_CMD_MAX_LEN+1];
    int count = ::Get_CharAppearCount( as_event, '&' );
    for(int i=0; i<count; i++ )
    {
        b_find = false;
        int iLD_l = Get_CharAppearPosition( as_event, '&', 1 );;
        int iLD_r = Get_CharAppearPosition( as_event, '&', ',', 1 );
        if( iLD_r < iLD_l )
        {
            iLD_r = as_event.Length()+1;
        }

        as_var_name = as_event.SubString( iLD_l+1, iLD_r-iLD_l-1 );


        for( iter_b_var = m_pvBVar->begin(); iter_b_var != m_pvBVar->end(); iter_b_var++ )
        {
            if( iter_b_var->as_name.AnsiCompareIC(as_var_name) == 0 )
            {
                // as_event = as_event.SubString(1, iLD_l-1) + IntToStr(iter_b_var->uc_value) + as_event.SubString(iLD_r, as_event.Length()-iLD_r+1);
                int count_seq = Get_CharAppearCount( as_event, ',' );
                int index = Get_VariableIndex( as_event, as_var_name, count_seq+1  );
                if( index < 0 )
                    return false;
                if( ! iter_b_var->b_valid )
                {
                    iter_b_var->uc_value = hci_event.m_parms[index-HCI_EVENT_PARAMETER_START_IDX];
                    iter_b_var->b_valid  = true;
                }
                else
                {
                    if( iter_b_var->uc_value != hci_event.m_parms[index-HCI_EVENT_PARAMETER_START_IDX] )
                        return false;
                }
                char str_value[HCI_CMD_MAX_LEN];
                sprintf( str_value, "%X", iter_b_var->uc_value );
                AnsiString as_value(str_value);
                as_event = as_event.SubString(1, iLD_l-1) + as_value + as_event.SubString(iLD_r, as_event.Length()-iLD_r+1);
                b_find = true;
                break;
            }
        }

        if( ! b_find )
            return false;

    }  // for

    AnsiString_Hex_To_Array_UnsignedChar( as_event.c_str(), str, HCI_CMD_MAX_LEN, ','  );

    if( str[HCI_EVENT_ID_IDX] != hci_event.m_event )   return false;
    if( str[HCI_EVENT_LEN_IDX]!= hci_event.m_len )     return false;
    for( int i=0; i<hci_event.m_len; i++ )
    {
        if( str[HCI_EVENT_PARAMETER_START_IDX+i] != hci_event.m_parms[i] )
            return false;
    }
    //sprintf( str, "%X,", hci_event.m_event );
    //AnsiString as_last_event( str );
    //sprintf( str, "%X,", hci_event.m_len );
    //AnsiString as_par_len( str );
    //Array_To_Hex_String_UnsignedChar( str, hci_event.m_parms, hci_event.m_len, ',' );
    //AnsiString as_par( (const char*) str );
    //AnsiString as_receive_event = as_last_event + as_par_len + as_par;

    // if( as_receive_event.AnsiCompareIC(as_event) != 0 )
    //     return false;
    //  int count = ::Get_CharAppearCount( as_cmd, '&' );
    //  for(int i=0; i<count; i++ )
    //  {
    //  }

    return true;
}

//---------------------------------------------------------------------------
unsigned short CBTSCT::Get_OpCode( AnsiString as_cmd )
{
    unsigned short opcode;
    unsigned short opcode_low, opcode_hi;
    AnsiString as_opcode_low, as_opcode_hi;
    int iLD = as_cmd.AnsiPos(",");
    as_opcode_low = as_cmd.SubString( 1, iLD-1 );
    AnsiString_Hex_To_UnsignedShort( as_opcode_low, opcode_low );
    as_cmd = as_cmd.SubString( iLD+1, as_cmd.Length() );
    iLD = as_cmd.AnsiPos(",");
    as_opcode_hi = as_cmd.SubString( 1, iLD-1 );
    AnsiString_Hex_To_UnsignedShort( as_opcode_hi, opcode_hi );
    opcode = ((opcode_hi & 0x00FF) << 8) | (opcode_low & 0x00FF);
    return opcode;
}

//---------------------------------------------------------------------------
unsigned char CBTSCT::Get_CommandParameterLen( AnsiString as_cmd )
{
    unsigned char len;
    int iLD;
    for(int i=0; i<2; i++ )
    {
        iLD = as_cmd.AnsiPos(",");
        as_cmd = as_cmd.SubString( iLD+1, as_cmd.Length() );
    }
    iLD = as_cmd.AnsiPos(",");
    AnsiString as_len = as_cmd.SubString( 1, iLD-1 );
    AnsiString_Hex_To_UnsignedChar( as_len, len );

    return len;
}

//---------------------------------------------------------------------------
unsigned char CBTSCT::Get_LastEvent( AnsiString as_event )
{
    unsigned char last_event;
    int iLD = as_event.AnsiPos(",");
    AnsiString as_last_event = as_event.SubString( 1, iLD-1 );
    AnsiString_Hex_To_UnsignedChar( as_last_event, last_event );

    return last_event;
}

//---------------------------------------------------------------------------
unsigned char CBTSCT::Get_EventParameterLen( AnsiString as_event )
{
    unsigned char len;
    int iLD = as_event.AnsiPos(",");
    as_event = as_event.SubString( iLD+1, as_event.Length() );
    iLD = as_event.AnsiPos(",");
    AnsiString as_len = as_event.SubString( 1, iLD-1 );
    AnsiString_Hex_To_UnsignedChar( as_len, len );

    return len;
}

//---------------------------------------------------------------------------
int CBTSCT::Get_VariableIndex( AnsiString as, AnsiString as_var, unsigned char len )
{
    // unsigned char str[2*HCI_CMD_MAX_LEN+1];
    // String_Hex_To_Array_UnsignedChar( as.c_str(), str, len  );
    int index = -1;
    AnsiString as_temp;
    for( int i=0; i<len; i++ )
    {
        int iLD = as.AnsiPos(",");
        if( iLD < 1 )
            iLD = as.Length()+1;
        as_temp = as.SubString( 1, iLD-1 );
        as = as.SubString(iLD+1, as.Length()-iLD);
        if( as_temp.AnsiPos("&") != 0 )
        {
            iLD = as_temp.AnsiPos("&");
            as_temp = as_temp.SubString(iLD+1, as_temp.Length()-iLD).Trim();
            if( as_temp.AnsiCompareIC(as_var) == 0 )
            {
                index = i;
                break;
            }
        }

    }

    return index;
}
//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void CBTSCT::AddParseLogToStringList(AnsiString as_log)
{
    m_sBTSCT.log->Add(as_log);
    PostMessage(
        m_sBTSCT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_SCT,
        0
    );
}

//----------------------------------------------------------------------------
void  CBTSCT::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
#if 0
    unsigned char        str[1024];
    Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    AnsiString as_cmd( (const char*)str );
    AnsiString as_log = "[" + TimeToStr(Time()) + "] TX: " + as_cmd;
#endif

    char        str[1024];
    AnsiString as_log;
    sprintf( str, "%X,", hci_cmd.m_opcode & 0x00FF );
    AnsiString as_opcode_low(str);
    sprintf( str, "%X,", (hci_cmd.m_opcode & 0xFF00)>>8 );
    AnsiString as_opcode_high(str);
    Array_To_Hex_String_UnsignedChar( str, hci_cmd.m_cmd, hci_cmd.m_len, ',' );
    AnsiString as_cmd( (const char*)str );
    if( 0 == hci_cmd.m_len )
        as_cmd = "";
    sprintf( str, "%X,", hci_cmd.m_len );
    AnsiString as_length(str);


    as_log = "[" + TimeToStr(Time()) + "] TX: " + as_opcode_low + as_opcode_high + as_length  + as_cmd;
    m_sBTSCT.log->Add( as_log );

    PostMessage(
        m_sBTSCT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_SCT,
        0
    );
}

//--------------------------------------------------------------------------
void  CBTSCT::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
#if 0
    unsigned char        str[1024];
    Array_To_Hex_String_UnsignedChar( str, hci_event.m_parms, hci_event.m_len, ',' );
    AnsiString as_event( (const char*) str );
    AnsiString as_log = "[" + TimeToStr(Time()) + "] RX: " + as_event;
#endif

    unsigned char        str[1024];
    AnsiString as_log;
    sprintf( str, "%X,", hci_event.m_event );
    AnsiString as_event( (const char*) str );
    sprintf( str, "%X,", hci_event.m_len );
    AnsiString as_length( (const char*) str );
    Array_To_Hex_String_UnsignedChar( str, hci_event.m_parms, hci_event.m_len, ',' );
    AnsiString as_param( (const char*) str );
    if(  0 == hci_event.m_len )
        as_param = "";

    as_log = "[" + TimeToStr(Time()) + "] RX: " + as_event + as_length + as_param;

    m_sBTSCT.log->Add( as_log );

    PostMessage(
        m_sBTSCT.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_SCT,
        0
    );
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CBTSCT::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//---------------------------------------------------------------------------
BT_HCI_EVENT CBTSCT::Get_HCIEvent(void)
{
    return m_sHCIEvent;
}

//---------------------------------------------------------------------------
vector<S_BT_SCT_SCRIPT>*  CBTSCT::Get_ScriptVector( void )
{
    return m_pvScript;
}






