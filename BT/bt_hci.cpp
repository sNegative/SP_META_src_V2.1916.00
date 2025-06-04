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
 *   bt_hci.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command test source
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
//===========================================================================
#include<iostream>

#include <fstream>


#pragma hdrstop

#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

#ifndef  _BT_HCI_H_
#include "bt_hci.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif


// misc
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

const AnsiString KEY_WORD[]=
{
    "[GROUP]",
    "[COMMAND]",
    "[DEFINE]",
    "[CATEGORY]"
};

//----------------------------------------------------------------------------
static CBTHCI*  gs_bt_hci_ptr;
static bool g_bIsRunning = false;

//==============================================================================
static void REQ_Read_From_File(void)
{
    gs_bt_hci_ptr->REQ_Read_From_File();
}

//----------------------------------------------------------------------------
static void  REQ_Send_HCI_Command(void)
{
    gs_bt_hci_ptr->REQ_Send_HCI_Command();
}

//------------------------------------------------------------------------------
static void __stdcall CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_hci_ptr->CNF_HCIEvent( cnf, token, usrData );
}

//===========================================================================
CBTHCI::CBTHCI(void)
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_fp = NULL;
    AllocateVector();
    
    m_bIsRunning = false;
    m_bFirstCategoryBody = false;
    m_eHCISec = BT_HCI_GROUP_TAG;
    m_iHCICategory = 0;
    memset(&m_sBTHCI,0,sizeof(m_sBTHCI));
    
}

//---------------------------------------------------------------------------
CBTHCI::~CBTHCI(void)
{
    DeAllocateVector();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTHCI::AllocateVector(void)
{
    if (!m_pvHCIGroup)
    {
        m_pvHCIGroup = new vector<S_BT_HCI_GROUP>;
    }

    if (!m_pvHCICategory)
    {
        m_pvHCICategory  = new vector<S_BT_HCI_CATEGORY>;
    }
}

//---------------------------------------------------------------------------
void CBTHCI::DeAllocateVector(void)
{
    if (m_pvHCIGroup)
    {
        if (!m_pvHCIGroup->empty())
        {
            m_pvHCIGroup->erase(m_pvHCIGroup->begin(), m_pvHCIGroup->end());
        }
        delete m_pvHCIGroup;
        m_pvHCIGroup = NULL;
    }

    if (m_pvHCICategory)
    {
        if (!m_pvHCICategory->empty())
        {
            m_pvHCICategory->erase(m_pvHCICategory->begin(), m_pvHCICategory->end());
        }
        delete m_pvHCICategory;
        m_pvHCICategory = NULL;
    }
}

//---------------------------------------------------------------------------
void CBTHCI::EraseVector(void)
{
    if (!m_pvHCIGroup->empty())
    {
        m_pvHCIGroup->erase(m_pvHCIGroup->begin(), m_pvHCIGroup->end());
    }

    if (!m_pvHCICategory->empty())
    {
        m_pvHCICategory->erase(m_pvHCICategory->begin(), m_pvHCICategory->end());
    }
}

//---------------------------------------------------------------------------
void CBTHCI::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    Confirm(METAAPP_STOP);
}

//---------------------------------------------------------------------------
void CBTHCI::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;

//  CloseFile();
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//============================================================================
void CBTHCI::REQ_Start( S_BT_HCI  &bt_hci )
{
    gs_bt_hci_ptr  = this;
    g_bIsRunning    = true;

    m_sBTHCI = bt_hci;



    ActiveMan->SetActiveFunction( ::REQ_Send_HCI_Command );
}

//---------------------------------------------------------------------------
void CBTHCI::REQ_Send_HCI_Command(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    AddTxLogToStringList(m_sBTHCI.s_hci_cmd);
    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), m_sBTHCI.ui_ms_timeout, &m_sBTHCI.s_hci_cmd, ::CNF_HCIEvent, NULL, m_sBTHCI.uc_last_event );

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
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void __stdcall CBTHCI::CNF_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // if(!g_bIsRunning)  return;

    m_sHCIEvent = *cnf;
    AddRxLogToStringList(*cnf);

}


//===========================================================================
void CBTHCI::REQ_Read_From_File_Start( S_BT_HCI  &bt_hci )
{
    gs_bt_hci_ptr  = this;
    g_bIsRunning    = true;

    m_sBTHCI = bt_hci;
    //m_asFileName = filename;

    EraseVector();
    ActiveMan->SetActiveFunction( ::REQ_Read_From_File );
}

//----------------------------------------------------------------------------
bool CBTHCI::REQ_Read_Last_HCI_File_Start( S_BT_HCI  &bt_hci )
{
    m_sBTHCI = bt_hci;

    EraseVector();

    if( ! OpenFile() )
    {

        return false;
    }

    if( ! ParseFile() )
    {

        return false;
    }

    CloseFile();

    return true;
}

//----------------------------------------------------------------------------
void  CBTHCI::REQ_Read_From_File( void )
{
    if( ! g_bIsRunning )  return;

    if( ! OpenFile() )
    {
        CloseFile();
        Confirm( META_FAILED );
        return;
    }

    if( ! ParseFile() )
    {
        CloseFile();
        Confirm(META_FAILED);
        return;
    }

    CloseFile();
    Confirm(META_SUCCESS);
}

//----------------------------------------------------------------------------
bool  CBTHCI::OpenFile( void )
{
    // if( m_ifs.is_open() )
    // {
    //     CloseFile();
    // }
    if( ! CheckFileExist(m_sBTHCI.filename) )
    {
        return false;
    }
#if 0
    m_pifs = new ifstream;
    m_pifs->open( m_sBTHCI.filename.c_str(), ios::in );

    if( 0 == m_pifs->is_open() )
        return false;
#endif
    m_fp = fopen(m_sBTHCI.filename.c_str(), "r");

    if( NULL == m_fp )
        return false;
    //m_ifs.seekg( ios::beg );
    // m_pifs->setmode( filebuf::text ); // set to text mode
    //m_pFBuf = m_ifs.rdbuf();

    return true;
}

//---------------------------------------------------------------------------
void CBTHCI::CloseFile( void )
{
#if 0
    if( m_pifs->is_open() )
    {
        m_pifs->close();
        delete m_pifs;
    }
#endif
    if( NULL != m_fp )
    {
        fclose(m_fp);
        m_fp = NULL;
    }
}


//---------------------------------------------------------------------------
bool CBTHCI::ParseFile( void )
{
    const int str_size = 256;
    char str[str_size];
    m_eHCISec = BT_HCI_UNKNOW;
    // while( ! m_pifs->eof() )
    while( !feof(m_fp) )
    {
        // m_pifs->getline( str, str_size, '\n' );
        fgets( str, str_size, m_fp );
        if( ! ParseCommandLine( str ) )
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
bool CBTHCI::ParseCommandLine( AnsiString as_cmd )
{
    as_cmd = as_cmd.UpperCase();
    if( as_cmd.AnsiCompareIC("") == 0 )  return true;  // NULL
    if( as_cmd.AnsiPos("//") != 0 )  return true; // note

    for( int i=0; i<sizeof(KEY_WORD)/sizeof(KEY_WORD[0]); i++ )
    {
        if( as_cmd.AnsiPos( KEY_WORD[i] ) != 0 )
        {
            m_eHCISec = (E_BT_HCI_TAG) i;
            return true;
        }
    }

    switch( m_eHCISec )
    {
    case BT_HCI_GROUP_TAG:
    {
        if( ! ParseHCIGroup( as_cmd ) )
            return false;
    }
    break;

    case BT_HCI_COMMAND_TAG:
    {
        if( ! ParseHCICommand( as_cmd ) )
            return false;
    }
    break;

    case BT_HCI_DEFINE_TAG:
    {
        if( ! ParseHCICmdDefine( as_cmd ) )
            return false;
    }
    break;

    case BT_HCI_CATEGORY_TAG:
    {
        if( ! ParseHCICategory( as_cmd ) )
            return false;
    }
    break;
    }
    return true;
}

//---------------------------------------------------------------------------
bool CBTHCI::ParseHCIGroup( AnsiString as_cmd )
{
    AnsiString as_group_tag;
    AnsiString as_group_name;
    int iLD_r, iLD_l;

    iLD_l = as_cmd.LastDelimiter("[");
    iLD_r = as_cmd.LastDelimiter("]");
    as_group_tag  = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1);
    as_group_name = as_cmd.SubString( iLD_r+2, as_cmd.Length() );
    S_BT_HCI_GROUP group;
    group.as_group_name = as_group_name;
    group.as_group_tag  = as_group_tag;
    m_pvHCIGroup->push_back( group );

    return true;
}

//---------------------------------------------------------------------------
bool CBTHCI::ParseHCICategory( AnsiString as_cmd )
{
    AnsiString as_category_tag;
    AnsiString as_category_name;
    int iLD_r, iLD_l;

    // category header
    if( as_cmd.AnsiPos("[S") != 0 || as_cmd.AnsiPos("[s") != 0 )
    {
        m_bFirstCategoryBody = true;
        iLD_l = as_cmd.LastDelimiter("[");
        iLD_r = as_cmd.LastDelimiter("]");
        as_category_tag  = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1);
        as_category_name = as_cmd.SubString( iLD_r+2, as_cmd.Length() );
        S_BT_HCI_CATEGORY category;
        category.as_category_name = as_category_name;
        category.as_category_tag  = as_category_tag;
        m_pvHCICategory->push_back( category );
//        m_iHCICategory =
    }
    else  // category body
    {

        AnsiString as_cmd_tag;
        AnsiString as_cmd_name;
        //int iLD_r, iLD_l;


        iLD_l = as_cmd.LastDelimiter("[");
        iLD_r = as_cmd.LastDelimiter("]");
        as_cmd_tag   = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1);
        as_cmd_name  = as_cmd.SubString( iLD_r+2, as_cmd.Length() );
        // iLD_l = as_cmd_tag.LastDelimiter("C");
        //  as_category_tag = as_cmd_tag.SubString( 1, iLD_l-1 );


        vector<S_BT_HCI_CATEGORY>:: iterator iter_category;
        vector<S_BT_HCI_GROUP>:: iterator iter_group;
        vector<S_BT_HCI_COMMAND>:: iterator iter_cmd;
        if( m_bFirstCategoryBody )
        {
            m_bFirstCategoryBody = false;
            for( iter_category = m_pvHCICategory->begin(); iter_category != m_pvHCICategory->end(); iter_category++ )
            {
                m_vLastCateogryIter = iter_category;
            }
        }

        S_BT_HCI_COMMAND command;
        // command.as_cmd_name = as_cmd_name;
        command.as_cmd_tag  = as_cmd_tag;

        bool found = false;
        for( iter_group = m_pvHCIGroup->begin(); (false==found) && (iter_group != m_pvHCIGroup->end()); iter_group++ )
        {
            for( iter_cmd = iter_group->v_cmd.begin(); iter_cmd != iter_group->v_cmd.end(); iter_cmd++ )
            {
                if( iter_cmd->as_cmd_tag.AnsiCompareIC(as_cmd_tag) == 0 )
                {
                    command = *iter_cmd;
                    found = true;
                    break;
                }
            }
        }
        m_vLastCateogryIter->v_cmd.push_back( command );


    }


    return true;
}

//---------------------------------------------------------------------------
bool CBTHCI::ParseHCICommand( AnsiString as_cmd )
{
    AnsiString as_group_tag;
    AnsiString as_cmd_tag;
    AnsiString as_cmd_name;
    int iLD_r, iLD_l;

    iLD_l = as_cmd.LastDelimiter("[");
    iLD_r = as_cmd.LastDelimiter("]");
    as_cmd_tag   = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1);
    as_cmd_name  = as_cmd.SubString( iLD_r+2, as_cmd.Length() );
    iLD_l = as_cmd_tag.LastDelimiter("C");
    as_group_tag = as_cmd_tag.SubString( 1, iLD_l-1 );


    vector<S_BT_HCI_GROUP>:: iterator iter;
    for( iter = m_pvHCIGroup->begin(); iter != m_pvHCIGroup->end(); iter++ )
    {
        S_BT_HCI_GROUP group;
        group = *iter;
        if( group.as_group_tag.AnsiCompareIC( as_group_tag ) == 0 )
        {
            S_BT_HCI_COMMAND command;
            command.as_cmd_name = as_cmd_name;
            command.as_cmd_tag  = as_cmd_tag;
            iter->v_cmd.push_back( command );
            break;
        }
    }

    return true;
}

//---------------------------------------------------------------------------
bool CBTHCI::ParseHCICmdDefine( AnsiString as_cmd )
{

    // static AnsiString as_last_cmd_tag=""; // last parsing command tag
    static AnsiString as_cur_cmd;
    static AnsiString as_cmd_tag=""; // currently parsing command tag
    AnsiString as_group_tag;
    // static unsigned int send_par_num=0;
    // static unsigned int receive_par_num=0;
    // static vector<S_BT_HCI_GROUP>:: iterator last_iter;
    static vector<S_BT_HCI_GROUP>:: iterator iter_group;
    static vector<S_BT_HCI_COMMAND>:: iterator iter_cmd;
    int iLD_r, iLD_l, iLD_c;


    iLD_l = as_cmd.AnsiPos("(G");
    iLD_r = as_cmd.LastDelimiter(")");
    if( (0 != iLD_l) && (0 != iLD_r) ) // command define header
    {
        as_cur_cmd = as_cmd;
        //as_last_cmd_tag = as_cur_cmd_tag;
        as_cmd_tag  = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1);
        iLD_c           = as_cmd_tag.AnsiPos("C");
        as_group_tag    = as_cmd_tag.SubString( 1, iLD_c-1 );

        S_BT_HCI_GROUP group;
        S_BT_HCI_COMMAND command;
        for( iter_group = m_pvHCIGroup->begin(); iter_group != m_pvHCIGroup->end(); iter_group++ )
        {
            group = *iter_group;
            if( group.as_group_tag.AnsiCompareIC( as_group_tag ) == 0 )
            {
                for( iter_cmd = iter_group->v_cmd.begin(); iter_cmd != iter_group->v_cmd.end(); iter_cmd++ )
                {
                    command = *iter_cmd;
                    if( command.as_cmd_tag.AnsiCompareIC( as_cmd_tag ) == 0 )
                    {
                        iter_cmd->ui_send_num = 0;
                        iter_cmd->ui_receive_num = 0;
                        break;
                    }
                }
                // last_iter    = curr_iter;
                // curr_iter    = iter;

            }
        }

        // if( as_last_cmd_tag.AnsiCompareIC("") != 0 ) // not first command define header
        // {
        //    // curr_iter->ui_send_num    = send_par_num;
        //    // curr_iter->ui_receive_num = receive_par_num;
        // }

        // vector<S_BT_HCI_COMMAND>:: iterator iter;
        // S_BT_HCI_COMMAND command;
        //  for( iter = m_pvHCICmd->begin(); iter != m_pvHCICmd->end(); iter++ )
        // {
        //     command = *iter;
        //     if( command.as_cmd_tag.AnsiCompareIC( as_cur_cmd_tag ) == 0 )
        //     {
        ////         last_iter    = curr_iter;
        //        // curr_iter    = iter;
        //        // break;
        //     }
        // }
        //
        // send_par_num     = 0;
        // receive_par_num  = 0;
    }
    else // command define parameter
    {

        if( (iLD_l=as_cmd.AnsiPos("#")) != 0 ) // opcode
        {
            iLD_r = as_cmd.AnsiPos(" ");

            if( 0 == iLD_r )
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    iter_cmd->us_opcode = as_cmd.SubString( iLD_l+1, as_cmd.Length() ).ToInt();
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedShort( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), iter_cmd->us_opcode );
                }
            }
            else
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    iter_cmd->us_opcode = as_cmd.SubString( iLD_r+1, as_cmd.Length() ).ToInt();
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedShort( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), iter_cmd->us_opcode );
                }
            }
        }
        else if( (iLD_l=as_cmd.AnsiPos("$")) != 0 ) // last event
        {
            iLD_r = as_cmd.AnsiPos(" ");

            if( 0 == iLD_r )
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    iter_cmd->uc_last_event = as_cmd.SubString( iLD_l+1, as_cmd.Length() ).ToInt();
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedChar( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), iter_cmd->uc_last_event );
                }
            }
            else
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    iter_cmd->uc_last_event = as_cmd.SubString( iLD_r+1, as_cmd.Length() ).ToInt();
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedChar( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), iter_cmd->uc_last_event );
                }
            }
        }
        else if( (iLD_l=as_cmd.AnsiPos("@")) != 0 )   // send parameter
        {
            iLD_r = as_cmd.AnsiPos(" ");
            S_BT_HCI_PARAMETER par;
            if( 0 != iLD_r )
            {
                par.ui_bytes  = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 ).ToInt();
                if( 0 == as_cmd.AnsiPos("(") )
                {
                    par.as_name = as_cmd.SubString( iLD_r+1, as_cmd.Length() );
                }
                else
                {
                    par.as_name = as_cmd.SubString( iLD_r+1, as_cmd.AnsiPos("(")-iLD_r-2 );
                }
            }
            else
            {
                AnsiString as_log = "parsing " +  as_cur_cmd + " command " + as_cmd + " parameter fail";
                AddParseLogToStringList( as_log );

                return false;
            }
            // default value, range
            iLD_l = as_cmd.AnsiPos("(");
            if( 0 == iLD_l ) // default value & range not exist
            {
                par.b_rangecheck = false;
                par.s_value.uc_nz_byte     = 0;
                par.s_min_value.uc_nz_byte = 0;
                par.s_max_value.uc_nz_byte = 0;
                for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
                {
                    par.s_value.uc_value[i]     = 0;
                    par.s_min_value.uc_value[i] = 0;
                    par.s_max_value.uc_value[i] = 0;
                }
            }
            else // default value or range exist
            {
                iLD_r = as_cmd.AnsiPos(",");
                if( iLD_r != 0 ) // default value & range exist
                {
                    if( as_cmd.AnsiPos("0X") ) // Hex
                    {
                        iLD_l = as_cmd.AnsiPos("0X");
                        AnsiString_Hex_To_BTHCIValue( as_cmd.SubString(iLD_l+2, iLD_r-iLD_l-2), par.s_value );
                    }
                    else // Dec
                    {
                        AnsiString_To_BTHCIValue( as_cmd.SubString(iLD_l+1, iLD_r-iLD_l-1), par.s_value );
                    }
                    iLD_l = iLD_r;
                    iLD_r = as_cmd.AnsiPos(")");
                    AnsiString as_range = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 );
                    iLD_r = as_range.AnsiPos("-");
                    if( iLD_r != 0 )
                    {
                        par.b_rangecheck = true;
                        // min range
                        AnsiString as_min_range = as_range.SubString( 1, iLD_r-1 );
                        if( as_min_range.AnsiPos("0X") ) // Hex
                        {
                            iLD_l = as_min_range.AnsiPos("0X");
                            AnsiString_Hex_To_BTHCIValue( as_min_range.SubString(iLD_l+2, as_min_range.Length()), par.s_min_value );
                        }
                        else // Dec
                        {
                            AnsiString_To_BTHCIValue( as_min_range.SubString(1, as_min_range.Length()), par.s_min_value );
                        }
                        // max range
                        AnsiString as_max_range = as_range.SubString( iLD_r+1, as_range.Length()-iLD_r );
                        if( as_max_range.AnsiPos("0X") ) // Hex
                        {
                            iLD_l = as_max_range.AnsiPos("0X");
                            AnsiString_Hex_To_BTHCIValue( as_max_range.SubString(iLD_l+2, as_max_range.Length()), par.s_max_value );
                        }
                        else // Dec
                        {
                            AnsiString_To_BTHCIValue( as_max_range.SubString(1, as_max_range.Length()), par.s_max_value );
                        }
                    }
                    else // no range check
                    {
                        par.b_rangecheck = false;
                    }
                }
                else // default value or range exist
                {
                    if( as_cmd.AnsiPos("-") != 0 ) // default value not exist, range exist
                    {
                        par.b_rangecheck = true;
                        par.s_value.uc_nz_byte     = 0;
                        for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
                        {
                            par.s_value.uc_value[i]     = 0;
                        }
                        iLD_l = as_cmd.AnsiPos("(");
                        iLD_r = as_cmd.AnsiPos(")");
                        AnsiString as_range = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 );


                        // min range
                        iLD_r = as_range.AnsiPos("-");
                        AnsiString as_min_range = as_range.SubString( 1, iLD_r-1 );
                        if( as_min_range.AnsiPos("0X") ) // Hex
                        {
                            iLD_l = as_min_range.AnsiPos("0X");
                            AnsiString_Hex_To_BTHCIValue( as_min_range.SubString(iLD_l+2, as_min_range.Length()), par.s_min_value );
                        }
                        else // Dec
                        {
                            AnsiString_To_BTHCIValue( as_min_range.SubString(1, as_min_range.Length()), par.s_min_value );
                        }
                        // max range
                        AnsiString as_max_range = as_range.SubString( iLD_r+1, as_range.Length()-iLD_r );
                        if( as_max_range.AnsiPos("0X") ) // Hex
                        {
                            iLD_l = as_max_range.AnsiPos("0X");
                            AnsiString_Hex_To_BTHCIValue( as_max_range.SubString(iLD_l+2, as_max_range.Length()), par.s_max_value );
                        }
                        else // Dec
                        {
                            AnsiString_To_BTHCIValue( as_max_range.SubString(1, as_max_range.Length()), par.s_max_value );
                        }
                    }
                    else // default value exist, range not exist
                    {
                        par.b_rangecheck = false;
                        par.s_min_value.uc_nz_byte = 0;
                        par.s_max_value.uc_nz_byte = 0;
                        for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
                        {
                            par.s_min_value.uc_value[i] = 0;
                            par.s_max_value.uc_value[i] = 0;
                        }
                        iLD_l = as_cmd.AnsiPos("(");
                        iLD_r = as_cmd.AnsiPos(")");
                        AnsiString as_default = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 );
                        if( as_default.AnsiPos("0X") ) // Hex
                        {
                            iLD_l = as_default.AnsiPos("0X");
                            AnsiString_Hex_To_BTHCIValue( as_default.SubString(iLD_l+2, as_default.Length()), par.s_value );
                        }
                        else // Dec
                        {
                            AnsiString_To_BTHCIValue( as_default.SubString(1, as_default.Length()), par.s_value );
                        }

                    }
                }
            }

            iter_cmd->v_send_par.push_back( par );
            iter_cmd->ui_send_num++;
        }
        else if( (iLD_l=as_cmd.AnsiPos("~")) != 0 )   // receive parameter
        {
            S_BT_HCI_PARAMETER par;
            iLD_r = as_cmd.AnsiPos("*");
            if( 0 == iLD_r )
            {
                iLD_r = as_cmd.AnsiPos(" ");

                if( 0 != iLD_r )
                {
                    par.b_show   = true;
                    par.ui_bytes = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 ).ToInt();
                    par.as_name  = as_cmd.SubString( iLD_r+1, as_cmd.Length() ).Trim();
                }
                else
                {
                    AnsiString as_log = "parsing " +  as_cur_cmd + " command " + as_cmd + " parameter fail";
                    AddParseLogToStringList( as_log );

                    return false;
                }
            }
            else
            {
                iLD_l = as_cmd.AnsiPos("*");
                iLD_r = as_cmd.AnsiPos(" ");

                if( 0 != iLD_r )
                {
                    par.b_show   = false;
                    par.ui_bytes = as_cmd.SubString( iLD_l+1, iLD_r-iLD_l-1 ).ToInt();
                    par.as_name  = as_cmd.SubString( iLD_r+1, as_cmd.Length() ).Trim();
                }
                else
                {
                    AnsiString as_log = "parsing " +  as_cur_cmd + " command " + as_cmd + " parameter fail";
                    AddParseLogToStringList( as_log );
                    return false;
                }
            }
            iter_cmd->v_receive_par.push_back( par );
            iter_cmd->ui_receive_num++;
        }

        if( (iLD_l=as_cmd.AnsiPos("&")) != 0 )   // timeout
        {
            iLD_r = as_cmd.AnsiPos(" ");

            if( 0 == iLD_r )
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    iter_cmd->ui_ms_timeout = as_cmd.SubString( iLD_l+1, as_cmd.Length() ).Trim().ToInt()*1000;
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedInt( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), &(iter_cmd->ui_ms_timeout) );
                    iter_cmd->ui_ms_timeout *= 1000;
                }
            }
            else
            {
                if( as_cmd.AnsiPos("0X") == 0 )
                {
                    AnsiString as_timeout = as_cmd.SubString( iLD_r+1, as_cmd.Length()-iLD_r ).Trim();
                    iter_cmd->ui_ms_timeout = as_timeout.ToInt()*1000;
                }
                else
                {
                    iLD_r = as_cmd.AnsiPos("0X");
                    AnsiString_Hex_To_UnsignedInt( as_cmd.SubString( iLD_r+2, as_cmd.Length()-iLD_r-2 ), &(iter_cmd->ui_ms_timeout) );
                    iter_cmd->ui_ms_timeout *= 1000;
                }
            }
        }
        else
        {
            iter_cmd->ui_ms_timeout = HCI_DEFAULT_TIMEOUT_MS;
        }
    }

    return true;
}

//===========================================================================
//////////////////////////   Send/receive HCI command   /////////////////////
//===========================================================================
//void  CBTHCI::Compose_HCI_TX_Command( BT_HCI_COMMAND &hci_cmd )
//{
//    vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
//    int idx;
//
//    hci_cmd.m_cmd[0] = 0x01; // fixed pattern
//    hci_cmd.m_cmd[1] = m_sTxCmd.us_opcode & 0x00FF;   // low byte of opcode
//    hci_cmd.m_cmd[2] = (m_sTxCmd.us_opcode & 0xFF00) >> 16; // high byte of opcode
//    hci_cmd.m_cmd[3] = m_sTxCmd.uc_total_par_size; // total parameter size
//    idx = 4;
//    for( iter_par = m_sTxCmd.v_par.begin(); iter_par != m_sTxCmd.v_par.end(); iter_par++ )
//    {
//        for(int i=0; i<iter_par->ui_bytes; i++ )
//        {
//            hci_cmd.m_cmd[idx] = iter_par->s_value.uc_value[i];
//            idx++;
//        }
//    }
//    hci_cmd.m_len = idx + 1;
//}

//---------------------------------------------------------------------------
//void  CBTHCI::DeCompose_HCI_RX_Event( void )
//{
//    vector<S_BT_HCI_PARAMETER>:: iterator iter_par;
//    int idx = 5;
//
//    m_sRxEvent.uc_event_code     = m_sRxEventFmt.uc_event[0];
//    m_sRxEvent.uc_total_par_size = m_sRxEventFmt.uc_event[1];
//    m_sRxEvent.uc_packet_num     = m_sRxEventFmt.uc_event[2];
//    m_sRxEvent.us_opcode         = m_sRxEventFmt.uc_event[4];
//    m_sRxEvent.us_opcode         = (m_sRxEvent.us_opcode << 8) | m_sRxEventFmt.uc_event[3];
//
//    for( iter_par = m_sRxEvent.v_par.begin(); iter_par != m_sRxEvent.v_par.end(); iter_par++ )
//    {
//        for(int i=0; i<iter_par->ui_bytes; i++ )
//        {
//            iter_par->s_value.uc_value[i] =  m_sRxEventFmt.uc_event[idx];
//            idx++;
//        }
//    }
//}

//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void  CBTHCI::AddParseLogToStringList(AnsiString as_log)
{
    m_sBTHCI.log->Add(as_log);
    PostMessage(
        m_sBTHCI.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_HCI,
        0
    );
}

//----------------------------------------------------------------------------
void  CBTHCI::AddTxLogToStringList(BT_HCI_COMMAND hci_cmd)
{
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

    m_sBTHCI.log->Add( as_log );

    PostMessage(
        m_sBTHCI.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_HCI,
        0
    );
}

//--------------------------------------------------------------------------
void  CBTHCI::AddRxLogToStringList(BT_HCI_EVENT hci_event)
{
    unsigned char str[1024];
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

    m_sBTHCI.log->Add( as_log );

    PostMessage(
        m_sBTHCI.hPostMsgDestHandle,
        WM_ML_BT_PRINT_MSG,
        PAGEIDX_BT_HCI,
        0
    );
}

//===========================================================================
////////////////////////////   Export  information   ////////////////////////
//===========================================================================
META_RESULT CBTHCI::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//---------------------------------------------------------------------------
vector<S_BT_HCI_CATEGORY>*  CBTHCI::Get_HciCategoryVector( void )
{
    return m_pvHCICategory;
}

//---------------------------------------------------------------------------
vector<S_BT_HCI_GROUP>*  CBTHCI::Get_HciGroupVector( void )
{
    return m_pvHCIGroup;
}

//---------------------------------------------------------------------------
BT_HCI_EVENT  CBTHCI::Get_HCIEvent( void )
{
    return m_sHCIEvent;
}







