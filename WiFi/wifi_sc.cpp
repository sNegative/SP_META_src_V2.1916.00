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
 *   wifi_sc.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi script source
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

#ifndef  _WIFI_SC_H_
#include "wifi_sc.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif


// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

// WiFi
#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif

#define INVALID_TAG  -1

const AnsiString KEY_WORD[]=
{
    "#define",
    "EEPROMR",
    "EEPROMW",
    "MCRR",
    "MCRW",
    "MCR16R",
    "MCR16W",
    "BBR",
    "BBW",
    "B",
    "W",
    "D",
    "DELAY",
    "CALL",
    "RET",
    "EXIT",
    "LABEL",
    "LOOP",
    "LOAD",
    "MADDB",
    "MADDW",
    "MADDD",
    "MSUBB",
    "MSUBW",
    "MSUBD",
    "MCMPB",
    "MCMPD",
    "MANDB",
    "MANDW",
    "MANDD",
    "MORB",
    "MORW",
    "MORD",
    "MXORB",
    "MXORW",
    "MXORD",
    "MSHLB",
    "MSHLW",
    "MSHLD",
    "MSHRB",
    "MSHRW",
    "MSHRD",
    "JNE",
    "JNB",
    "JNA",
    "JE",
    "JB",
    "JA",
    "JMP",
    "MPRB",
    "MPRW",
    "MPRD",
    "MPWB",
    "MPWW",
    "MPWD",
    "PRINT",
    "MPRN2FILE",
    "RAND",
    "SET_START",
    "SET_STOP",
    "SET_CONT_TX",
    "SET_LOCAL_FREQ",
    "SET_CARRIER_SUPP",
    "SET_PKT_TX",
    "SET_PWR_MGT"
    "SET_PKT_RX",
    "SET_REG_DOMAIN",
    "SET_DBM_TO_DAC",
    "SET_END"
};



//==============================================================================
static CWIFISC*  gs_wifi_sc_ptr;
static bool g_bIsRunning;

//==============================================================================
static  void  REQ_Read_From_File( void )
{
    gs_wifi_sc_ptr->REQ_Read_From_File();
}

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_sc_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_sc_ptr->REQ_Finish();
}

//===========================================================================
CWIFISC::CWIFISC( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_pvDefine = NULL;
    m_pvBVar   = NULL;
    m_pvWVar   = NULL;
    m_pvDVar   = NULL;
    m_pvLabel  = NULL;
    m_pvCall   = NULL;
    m_iConfirmState = 0;
    memset(&m_WiFiSc,0,sizeof(m_WiFiSc));
    m_pifs = NULL;
    m_pFBuf = NULL;

}

//---------------------------------------------------------------------------
CWIFISC::~CWIFISC( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFISC::AllocateVector( void )
{
    if( NULL == m_pvDefine )
        m_pvDefine = new vector<S_DEFINE>;

    if( NULL == m_pvBVar )
        m_pvBVar   = new vector<S_B_VAR>;

    if( NULL == m_pvWVar )
        m_pvWVar   = new vector<S_W_VAR>;

    if( NULL == m_pvDVar )
        m_pvDVar   = new vector<S_D_VAR>;

    if( NULL == m_pvLabel )
        m_pvLabel  = new vector<S_LABEL>;

    if( NULL == m_pvCall )
        m_pvCall = new vector<S_CALL>;

}

//---------------------------------------------------------------------------
void CWIFISC::DeAllocateVector( void )
{
    if( NULL != m_pvDefine )
    {
        if( ! m_pvDefine->empty() )
        {
            m_pvDefine->erase( m_pvDefine->begin(), m_pvDefine->end() );
        }
        delete m_pvDefine;
        m_pvDefine = NULL;
    }

    if( NULL != m_pvBVar )
    {
        if( ! m_pvBVar->empty() )
        {
            m_pvBVar->erase( m_pvBVar->begin(), m_pvBVar->end() );
        }
        delete m_pvBVar;
        m_pvBVar = NULL;
    }

    if( NULL != m_pvWVar )
    {
        if( ! m_pvWVar->empty() )
        {
            m_pvWVar->erase( m_pvWVar->begin(), m_pvWVar->end() );
        }
        delete m_pvWVar;
        m_pvWVar = NULL;
    }

    if( NULL != m_pvDVar )
    {
        if( ! m_pvDVar->empty() )
        {
            m_pvDVar->erase( m_pvDVar->begin(), m_pvDVar->end() );
        }
        delete m_pvDVar;
        m_pvDVar = NULL;
    }

    if( NULL != m_pvLabel )
    {
        if( ! m_pvLabel->empty() )
        {
            m_pvLabel->erase( m_pvLabel->begin(), m_pvLabel->end() );
        }
        delete m_pvLabel;
        m_pvLabel = NULL;
    }

    if( NULL != m_pvCall )
    {
        if( ! m_pvCall->empty() )
        {
            m_pvCall->erase( m_pvCall->begin(), m_pvCall->end() );
        }
        delete m_pvCall;
        m_pvCall = NULL;
    }

}

//---------------------------------------------------------------------------
void  CWIFISC::REQ_Finish( void )
{
    if( ! g_bIsRunning )  return;

    Confirm( STATE_SC_OK );
}
//---------------------------------------------------------------------------
void  CWIFISC::REQ_Stop( void )
{
    if( ! g_bIsRunning )  return;


    Confirm( STATE_SC_STOP );
}
//---------------------------------------------------------------------------
void  CWIFISC::REQ_TimeOut( void )
{
    if( ! g_bIsRunning )  return;

    Confirm( STATE_SC_TIMEOUT );
}
//---------------------------------------------------------------------------
void  CWIFISC::Confirm( int confirm_state )
{
    if( ! g_bIsRunning )  return;
    g_bIsRunning = false;
    DeAllocateVector();
    CloseFile();
    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}


//============================================================================
void CWIFISC::REQ_Start( S_WIFISC  wifisc )
{
    gs_wifi_sc_ptr  = this;
    g_bIsRunning    = true;

    m_WiFiSc = wifisc;


    AllocateVector();
    ActiveMan->SetActiveFunction( ::REQ_Read_From_File );
}

//----------------------------------------------------------------------------
bool  CWIFISC::OpenFile( void )
{
    // if( m_ifs.is_open() )
    // {
    //     CloseFile();
    // }

    m_pifs = new ifstream;
    m_pifs->open( m_WiFiSc.filename.c_str() );
    //m_ifs.seekg( ios::beg );
    //m_ifs.setmode( filebuf::text ); // set to text mode
    //m_pFBuf = m_ifs.rdbuf();

    return true;
}

//---------------------------------------------------------------------------
void CWIFISC::CloseFile( void )
{
    if( m_pifs->is_open() )
    {
        m_pifs->close();
        delete m_pifs;
    }
}

//----------------------------------------------------------------------------
void  CWIFISC::REQ_Read_From_File( void )
{
    if( ! OpenFile() )
    {
        Confirm( STATE_SC_FAIL );
        return;
    }

    if( ! ParseFile() )
    {
        Confirm( STATE_SC_FAIL );
        return;
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}



//---------------------------------------------------------------------------
bool CWIFISC::ParseFile( void )
{
    const int str_size = 256;
    char str[str_size];

    while( ! m_pifs->eof() )
    {
        m_pifs->getline( str, str_size, '\n' );
        if( ! ParseCommandLine( str ) )
        {
            AnsiString as_str = str;
            AddLogToStringList( as_str + " error" );
            return false;
        }
        // streampos pos = m_ifs.tellg();
        // m_ifs.tellg();
    }
    return true;
}

//---------------------------------------------------------------------------
bool CWIFISC::ParseCommandLine( AnsiString as_cmd )
{

    as_cmd = as_cmd.UpperCase();
    if( as_cmd.AnsiCompareIC("") == 0 )  return true;  // NULL
    if( as_cmd.AnsiPos("//") != 0 )  return true; // note

    //  int iLD_space = as_cmd.AnsiPos( " " );
    //  int iLD_comma = as_cmd.AnsiPos( "," );
    //  as_operator = as_cmd.SubString( 1, iLD_space-1 );
    S_OP op;
    op.tag = (E_WIFISCRIPT_TAG) INVALID_TAG;
    AnsiString as_rem;
    AnsiString as_operator;
    int i;
    char str[256];
    bool keyword_found = false;
    int iLD_space = as_cmd.LastDelimiter( " " );
    int iLD_comma = as_cmd.AnsiPos( "," );
    if( iLD_comma != 0 )
    {
        if( iLD_comma > iLD_space )
        {
            op.op2 = as_cmd.SubString( iLD_comma+1, as_cmd.Length()-iLD_comma );
            // as_rem = as_cmd.SubString( 1, iLD_comma - 1 );
            // iLD_space = as_rem.LastDelimiter( " " );
            // op.op1 = as_rem.SubString( iLD_space+1, as_cmd.Length()-iLD_space );

        }
        else
        {
            op.op2 = as_cmd.SubString( iLD_space+1, as_cmd.Length()-iLD_space );
            //as_rem = as_cmd.SubString( 1, iLD_comma-1 );
            //iLD_space = as_rem.LastDelimiter( " " );
            //op.op1 = as_rem.SubString( iLD_space+1, as_cmd.Length()-iLD_space );
            // iLD_space = as_rem.LastDelimiter( " " );
            // as_rem = as_rem.SubString( 1, iLD_space-1 );
        }
        as_rem = as_cmd.SubString( 1, iLD_comma-1 );
        iLD_space = as_rem.LastDelimiter( " " );
        op.op1 = as_rem.SubString( iLD_space+1, as_cmd.Length()-iLD_space );
        // iLD_space = as_rem.LastDelimiter( " " );
        // as_rem = as_rem.SubString( 1, iLD_space-1 );

        // int j=0;
        // for( i=0; i<as_rem.Length(); i++ )
        // {
        //    if( as_rem.SubString( i+1, 1 ).AnsiCompareIC(" ") != 0 )
        //    {
        //        strcpy( &str[j], as_rem.SubString( i+1, 1 ).c_str() );
        //        j++;
        //    }
        // }
        // str[j] = '\0';
        // as_operator = (AnsiString) str;

    }
    else // no op2
    {
        if( as_cmd.AnsiPos("EXIT") != 0 )
        {
            op.op1 = "";
        }
        else if( as_cmd.AnsiPos("\"") == 0 ) // no " "
        {
            op.op1 = as_cmd.SubString( iLD_space+1, as_cmd.Length() - iLD_comma );
            as_rem = as_cmd;
        }
        else
        {
            int iLD_1stQuotes = as_cmd.AnsiPos("\"");
            int iLD_2ndQuotes = as_cmd.LastDelimiter("\"");
            op.op1 = as_cmd.SubString( iLD_1stQuotes+1, iLD_2ndQuotes - iLD_1stQuotes -1 );
            as_rem = as_cmd.SubString( 1, iLD_1stQuotes - 1 );
        }
        op.op2 = "";
    }

    iLD_space = as_rem.LastDelimiter( " " );
    if( iLD_space != 0 )
    {
        as_rem = as_rem.SubString( 1, iLD_space-1 );
    }
    else
    {
        as_rem = as_cmd;
    }

    int j=0;
    for( i=0; i<as_rem.Length(); i++ )
    {
        if( as_rem.SubString( i+1, 1 ).AnsiCompareIC(" ") != 0 )
        {
            strcpy( &str[j], as_rem.SubString( i+1, 1 ).c_str() );
            j++;
        }
    }
    str[j] = '\0';
    as_operator = (AnsiString) str;

    for( int i=0; i<sizeof(KEY_WORD)/sizeof(KEY_WORD[0]); i++ )
    {
        if( as_operator.AnsiCompareIC( KEY_WORD[i] ) == 0 )
        {
            op.tag = ( E_WIFISCRIPT_TAG ) i;

            keyword_found = true;
            break;
        }
    }

    if( keyword_found )
    {
        if( ! Interpret( op ) )  return false;
    }

    return keyword_found;
}

//---------------------------------------------------------------------------
bool CWIFISC::Interpret( S_OP op )
{

    switch( op.tag )
    {
    case DEFINE_TAG:                // "DEFINE",
    {
        S_DEFINE define;
        define.name  = op.op1;
        define.value = op.op2.ToInt();
        m_pvDefine->push_back( define );
    }
    break;

    case EEPROMR_TAG:                // "EEPROMR",
    {
        S_WIFI_EEPROM  eeprom;
        eeprom.eeprom[0].index = GetDefineValue(op.op1);
        eeprom.count           = 1;


        META_RESULT  MetaResult =  SP_META_WiFi_EEPROM_Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, eeprom.eeprom, eeprom.count );
        if(MetaResult!=META_SUCCESS)   return false;
        WordValueOperate( op.op2, eeprom.eeprom[0].eeprom_data16, SET_OP );
    }
    break;

    case EEPROMW_TAG:                  // "EEPROMW",
    {
        S_WIFI_EEPROM  eeprom;
        eeprom.eeprom[0].index = GetDefineValue(op.op1);
        eeprom.count           = 1;

        WordValueOperate( op.op2, eeprom.eeprom[0].eeprom_data16, GET_OP );
        META_RESULT  MetaResult = SP_META_WiFi_EEPROM_Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, eeprom.eeprom, eeprom.count );
        if(MetaResult!=META_SUCCESS)   return false;

    }
    break;

    case MCRR_TAG:                 // "MCRR",
    {
        S_WiFi_MCR mcr;
        mcr.count = 1;
        mcr.mac_reg32[0].index = GetDefineValue(op.op1);

        META_RESULT MetaResult = SP_META_WiFi_MACReg32Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, mcr.mac_reg32, mcr.count );
        if(MetaResult!=META_SUCCESS)   return false;
        DWordValueOperate( op.op2, mcr.mac_reg32[0].mcr_data32, SET_OP );
    }
    break;

    case MCRW_TAG:                 // "MCRW",
    {
        S_WiFi_MCR mcr;
        mcr.count = 1;
        mcr.mac_reg32[0].index = GetDefineValue(op.op1);
        DWordValueOperate( op.op2, mcr.mac_reg32[0].mcr_data32, GET_OP );

        META_RESULT  MetaResult = SP_META_WiFi_MACReg32Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, mcr.mac_reg32, mcr.count );
        if(MetaResult!=META_SUCCESS)   return false;
    }
    break;

    case MCR16R_TAG:               // "MCR16R",
    {
        S_WiFi_MCR16 mcr16;
        mcr16.count = 1;
        mcr16.mac_reg16[0].index = GetDefineValue(op.op1);

        META_RESULT MetaResult = SP_META_WiFi_MACReg16Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, mcr16.mac_reg16, mcr16.count );
        if(MetaResult!=META_SUCCESS)   return false;
        WordValueOperate( op.op2, mcr16.mac_reg16[0].mcr_data16, SET_OP );
    }
    break;

    case MCR16W_TAG:               // "MCR16W",
    {
        S_WiFi_MCR16 mcr16;
        mcr16.count = 1;
        mcr16.mac_reg16[0].index = GetDefineValue(op.op1);
        WordValueOperate( op.op2, mcr16.mac_reg16[0].mcr_data16, GET_OP );

        META_RESULT  MetaResult = SP_META_WiFi_MACReg16Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, mcr16.mac_reg16, mcr16.count );
        if(MetaResult!=META_SUCCESS)   return false;
    }
    break;

    case BBR_TAG:                  // "BBR",
    {
        S_WiFi_BBCR bbcr;
        bbcr.count = 1;
        bbcr.bb_reg8[0].index = (unsigned char) GetDefineValue(op.op1);

        META_RESULT  MetaResult = SP_META_WiFi_BBRegRead_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, bbcr.bb_reg8, bbcr.count );
        if(MetaResult!=META_SUCCESS)   return false;
        ByteValueOperate( op.op2, bbcr.bb_reg8[0].bbcr_data8, SET_OP );
    }
    break;

    case BBW_TAG:                  // "BBW",
    {
        S_WiFi_BBCR bbcr;
        bbcr.count = 1;
        bbcr.bb_reg8[0].index =  (unsigned char) GetDefineValue(op.op1);

        ByteValueOperate( op.op2, bbcr.bb_reg8[0].bbcr_data8, GET_OP );

        META_RESULT  MetaResult = SP_META_WiFi_BBRegWrite_r( m_META_HANDLE_Obj.Get_MainHandle(),  500, bbcr.bb_reg8, bbcr.count );
        if(MetaResult!=META_SUCCESS)   return false;
    }
    break;

    case B_TAG:                    // "B",
    {
        S_B_VAR b_var;
        b_var.name = op.op1;
        b_var.value = op.op2.ToInt();
        m_pvBVar->push_back( b_var );
    }
    break;

    case W_TAG:                    // "W",
    {
        S_W_VAR w_var;
        w_var.name = op.op1;
        w_var.value = op.op2.ToInt();
        m_pvWVar->push_back( w_var );
    }
    break;

    case D_TAG:                    // "D",
    {
        S_D_VAR d_var;
        d_var.name = op.op1;
        d_var.value = op.op2.ToInt();
        m_pvDVar->push_back( d_var );
    }
    break;

    case DELAY_TAG:                // "DELAY",
    {
        unsigned int ms;
        ms = GetDefineValue(op.op1);
        Sleep( ms );
    }
    break;

    case CALL_TAG:                 // "CALL",
    {
        S_CALL call;
        call.pos = m_pifs->tellg();
        m_pvCall->push_back( call );
        vector<S_LABEL>:: iterator iter;
        S_LABEL label;
        for( iter = m_pvLabel->begin(); iter != m_pvLabel->end(); iter++ )
        {
            label = *iter;
            if( op.op1.AnsiCompareIC(label.name) == 0 )
            {
                m_pifs->seekg( label.pos );
                // streampos pos = m_pifs->tellg();
                break;
            }
        }
    }
    break;

    case EXIT_TAG:                 // "EXIT",
    {
        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }

    case RET_TAG:                  // "RET",
    {
    }
    break;

    case LABEL_TAG:                // "LABEL",
    {
        S_LABEL label;
        label.name = op.op1;
        label.pos = m_pifs->tellg();
        m_pvLabel->push_back( label );
    }
    break;

    case LOOP_TAG:                 // "LOOP",
    {

    }
    break;

    case LOAD_TAG:                 // "LOAD",
    {
    }
    break;

    case MADDB_TAG:                // "MADDB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, ADD_OP );
    }
    break;

    case MADDW_TAG:                // "MADDW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, ADD_OP );
    }
    break;

    case MADDD_TAG:                // "MADDD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, ADD_OP );
    }
    break;

    case MSUBB_TAG:                // "MSUBB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, SUB_OP );
    }
    break;

    case MSUBW_TAG:                // "MSUBW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, SUB_OP );
    }
    break;

    case MSUBD_TAG:                // "MSUBD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, SUB_OP );
    }
    break;

    case MCMPB_TAG:                // "MCMPB",
    {
    }
    break;

    case MCMPD_TAG:                // "MCMPD",
    {
    }
    break;

    case MANDB_TAG:                // "MANDB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, AND_OP );
    }
    break;

    case MANDW_TAG:                // "MANDW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, AND_OP );
    }
    break;

    case MANDD_TAG:                // "MANDD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, AND_OP );
    }
    break;

    case MORB_TAG:                 // "MORB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, OR_OP );
    }
    break;

    case MORW_TAG:                 // "MORW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, OR_OP );
    }
    break;

    case MORD_TAG:                 // "MORD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, OR_OP );
    }
    break;

    case MXORB_TAG:                // "MXORB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, XOR_OP );
    }
    break;

    case MXORW_TAG:                // "MXORW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, XOR_OP );
    }
    break;

    case MXORD_TAG:                // "MXORD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, XOR_OP );
    }
    break;

    case MSHLB_TAG:                // "MSHLB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, SHL_OP );
    }
    break;

    case MSHLW_TAG:                // "MSHLW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, SHL_OP );
    }
    break;

    case MSHLD_TAG:                // "MSHLD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, SHL_OP );
    }
    break;

    case MSHRB_TAG:                // "MSHRB",
    {
        unsigned char value = (unsigned char) GetDefineValue( op.op2 );
        ByteValueOperate( op.op1, value, SHR_OP );
    }
    break;

    case MSHRW_TAG:                // "MSHRW",
    {
        unsigned short value = (unsigned short) GetDefineValue( op.op2 );
        WordValueOperate( op.op1, value, SHR_OP );
    }
    break;

    case MSHRD_TAG:                // "MSHRD",
    {
        unsigned int value = GetDefineValue( op.op2 );
        DWordValueOperate( op.op1, value, SHR_OP );
    }
    break;

    case PRINT_TAG:                // "PRINT",
    {
        AddLogToStringList(op.op1);
        PostMessage(
            m_WiFiSc.hPostMsgDestHandle,
            WM_ML_WIFI_PRINT_MSG,
            0,
            0
        );
    }
    break;

    case JNE_TAG:                  // "JNE",
    {
    }
    break;

    case JNB_TAG:                  // "JNB",
    {
    }
    break;

    case JNA_TAG:                  // "JNA",
    {
    }
    break;

    case JE_TAG:                   // "JE",
    {
    }
    break;

    case JB_TAG:                   // "JB",
    {
    }
    break;

    case JA_TAG:                   // "JA",
    {
    }
    break;

    case JMP_TAG:                  // "JMP",
    {
    }
    break;

    case MPRB_TAG:                 // "MPRB",
    {
    }
    break;

    case MPRW_TAG:                 // "MPRW",
    {
    }
    break;

    case MPRD_TAG:                 // "MPRD",
    {
    }
    break;

    case MPWB_TAG:                 // "MPWB",
    {
    }
    break;

    case MPWW_TAG:                 // "MPWW",
    {
    }
    break;

    case MPWD_TAG:                 // "MPWD",
    {
    }
    break;



    case MPRN2FILE_TAG:            // "MPRN2FILE",
    {
    }
    break;

    case RAND_TAG:                 // "RAND",
    {
    }
    break;

    case SET_START_TAG:            // "SET_START",
    {
    }
    break;

    case SET_STOP_TAG:             // "SET_STOP",
    {
    }
    break;

    case SET_CONT_TX_TAG:          // "SET_CONT_TX",
    {
    }
    break;

    case SET_LOCAL_FREQ_TAG:       //  "SET_LOCAL_FREQ",
    {
    }
    break;

    case SET_CARRIER_SUPP_TAG:     // "SET_CARRIER_SUPP",
    {
    }
    break;

    case SET_PKT_TX_TAG:           // "SET_PKT_TX",
    {
    }
    break;

    case SET_PWR_MGT_TAG:          // "SET_PWR_MGT"
    {
    }
    break;

    case SET_PKT_RX_TAG:           // "SET_PKT_RX",
    {
    }
    break;

    case SET_REG_DOMAIN_TAG:       // "SET_REG_DOMAIN",
    {
    }
    break;

    case SET_DBM_TO_DAC_TAG:       // "SET_DBM_TO_DAC",
    {
    }
    break;

    case SET_END_TAG:              // "SET_END"
    {
    }
    break;
    }

    return true;
}

//===========================================================================
/////////////////////////////     Define handling     ///////////////////////
//===========================================================================
unsigned int CWIFISC::GetDefineValue( AnsiString str )
{
    unsigned int value;
    unsigned int pos_mouse = str.AnsiPos("@");
    if( 0 == pos_mouse ) // const
    {
        value = str.ToInt();
    }
    else  // alias
    {
        str = str.SubString( pos_mouse+1, str.Length() - pos_mouse );

        vector<S_DEFINE>:: iterator iter;
        S_DEFINE define;
        for( iter = m_pvDefine->begin(); iter != m_pvDefine->end(); iter++ )
        {
            define = *iter;
            if( define.name.AnsiCompareIC( str ) == 0 )
            {
                value = iter->value;
                break;
            }
        }
    }
    return value;
}

//---------------------------------------------------------------------------

//===========================================================================
////////////////////////////      BBCR read/wrtie     ///////////////////////
//===========================================================================
void CWIFISC::ByteValueOperate( AnsiString str, unsigned char &value, E_OPERATION op )
{
    vector<S_B_VAR>:: iterator iter;
    S_B_VAR old_ub_var;
    int iLD_AND = str.LastDelimiter( "&" );
    if( 0 == iLD_AND && GET_OP == op ) // const
    {
        value = str.ToInt();
        return;
    }

    // alias
    str = str.SubString( iLD_AND+1, str.Length() - iLD_AND );

    for( iter=m_pvBVar->begin(); iter!= m_pvBVar->end(); iter++ )
    {
        old_ub_var = *iter;
        if( old_ub_var.name.AnsiCompareIC(str) == 0 )
        {
            switch( op )
            {
            case GET_OP:
                value = iter->value;
                break;

            case SET_OP:
                iter->value = value;
                break;

            case ADD_OP:
                iter->value += value;
                break;

            case SUB_OP:
                iter->value -= value;
                break;

            case CMP_OP:

                break;

            case AND_OP:
                iter->value &= value;
                break;

            case OR_OP:
                iter->value |= value;
                break;

            case XOR_OP:
                iter->value ^= value;
                break;

            case SHL_OP:
                iter->value <<= value;
                break;

            case SHR_OP:
                iter->value >>= value;
                break;


            }
            break;
        }
    }
}

//===========================================================================
////////////////////////////      MCR32 read/wrtie     ////////////////////////
//===========================================================================
void CWIFISC::DWordValueOperate( AnsiString str, unsigned int &value, E_OPERATION op )
{
    vector<S_D_VAR>:: iterator iter;
    S_D_VAR old_d_var;
    int iLD_AND = str.LastDelimiter( "&" );
    if( 0 == iLD_AND && GET_OP == op ) // const
    {
        value = str.ToInt();
        return;
    }

    // alias
    str = str.SubString( iLD_AND+1, str.Length() - iLD_AND );

    for( iter=m_pvDVar->begin(); iter!= m_pvDVar->end(); iter++ )
    {
        old_d_var = *iter;
        if( old_d_var.name.AnsiCompareIC(str) == 0 )
        {
            switch( op )
            {
            case GET_OP:
                value = iter->value;
                break;

            case SET_OP:
                iter->value = value;
                break;

            case ADD_OP:
                iter->value += value;
                break;

            case SUB_OP:
                iter->value -= value;
                break;

            case CMP_OP:

                break;

            case AND_OP:
                iter->value &= value;
                break;

            case OR_OP:
                iter->value |= value;
                break;

            case XOR_OP:
                iter->value ^= value;
                break;

            case SHL_OP:
                iter->value <<= value;
                break;

            case SHR_OP:
                iter->value >>= value;
                break;


            }
            break;
        }
    }
}


//===========================================================================
////////////////////////////   Pseudo EEPROM, MCR16 read/write   ///////////////////
//===========================================================================
void CWIFISC::WordValueOperate( AnsiString str, unsigned short &value, E_OPERATION op )
{
    vector<S_W_VAR>:: iterator iter;
    S_W_VAR old_w_var;

    int iLD_AND = str.LastDelimiter( "&" );
    if( 0 == iLD_AND && GET_OP == op ) // const
    {
        value = str.ToInt();
        return;
    }

    // alias
    str = str.SubString( iLD_AND+1, str.Length() - iLD_AND );

    for( iter=m_pvWVar->begin(); iter!= m_pvWVar->end(); iter++ )
    {
        old_w_var = *iter;
        if( old_w_var.name.AnsiCompareIC(str) == 0 )
        {
            switch( op )
            {
            case GET_OP:
                value = iter->value;
                break;

            case SET_OP:
                iter->value = value;
                break;

            case ADD_OP:
                iter->value += value;
                break;

            case SUB_OP:
                iter->value -= value;
                break;

            case CMP_OP:

                break;

            case AND_OP:
                iter->value &= value;
                break;

            case OR_OP:
                iter->value |= value;
                break;

            case XOR_OP:
                iter->value ^= value;
                break;

            case SHL_OP:
                iter->value <<= value;
                break;

            case SHR_OP:
                iter->value >>= value;
                break;


            }
            break;
        }
    }
}

//===========================================================================
////////////////////////////   Log  information   ////////////////////////
//===========================================================================
void  CWIFISC::AddLogToStringList( AnsiString as_log )
{
    m_WiFiSc.log->Add( as_log );
}



//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
int   CWIFISC::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}







