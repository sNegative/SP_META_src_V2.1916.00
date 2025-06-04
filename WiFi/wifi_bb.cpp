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
 *   wifi_bb.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi baseband source
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
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _WIFI_BB_H_
#include "wifi_bb.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif


// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

static CWIFIBB*  gs_wifi_bb_ptr;

//===========================================================================
//static  void  Read_From_Reg( void )
//{   gs_wifi_bb_ptr->Read_From_Reg();
//}

//------------------------------------------------------------------------------
//static  void  REQ_Read_From_AllReg( void )
//{   gs_wifi_bb_ptr->REQ_Read_From_AllReg();
//}

//------------------------------------------------------------------------------
//static  void  Write_To_Reg( void )
//{   gs_wifi_bb_ptr->Write_To_Reg();
//}

//---------------------------------------------------------------------------
static  void  REQ_Read_BBCR_Setting_From_Reg( void )
{
    gs_wifi_bb_ptr->REQ_Read_BBCR_Setting_From_Reg();
}

//---------------------------------------------------------------------------
static  void  REQ_Write_BBCR_Setting_To_Reg( void )
{
    gs_wifi_bb_ptr->REQ_Write_BBCR_Setting_To_Reg();
}

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_bb_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_bb_ptr->REQ_Finish();
}

//===========================================================================
CWIFIBB::CWIFIBB( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
    m_bHasMeasured = false;
    memset(&m_sBBCR,0,sizeof(m_sBBCR));
    memset(m_sBBCR_Setting,0,sizeof(S_WIFI_BBCR_SETTING)*WIFI_BBCR_TYPE_NUM*WIFI_BBCR_MAX_NUM);
}

//---------------------------------------------------------------------------
CWIFIBB::~CWIFIBB( )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;

}

//---------------------------------------------------------------------------
void  CWIFIBB::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_BB_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIBB::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_BB_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIBB::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_BB_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIBB::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}



//===========================================================================
void  CWIFIBB::REQ_Read_BBCR_Setting_From_Reg_Start( S_WiFi_BBCR &bbcr )
{
    gs_wifi_bb_ptr = this;
    m_bIsRunning   = true;
    m_sBBCR        = bbcr;

    ActiveMan->SetActiveFunction( ::REQ_Read_BBCR_Setting_From_Reg );
}

//------------------------------------------------------------
void  CWIFIBB::REQ_Read_BBCR_Setting_From_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_BB_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    // for( int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        // for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            // if( m_sBBCR_Setting[i][j].checked )
            {
                // MetaResult = META_WiFi_BBRegRead_r( 500, m_sBBCR_Setting[i][j].addr, &m_sBBCR_Setting[i][j].value );
                MetaResult = SP_META_WiFi_BBRegRead_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sBBCR.count, m_sBBCR.bb_reg8, m_sBBCR.count );
            }
        }
    }

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_BB_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_BB_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}


//===========================================================================
void  CWIFIBB::REQ_Write_BBCR_Setting_To_Reg_Start( S_WiFi_BBCR &bbcr )
{
    gs_wifi_bb_ptr = this;
    m_bIsRunning   = true;
    m_sBBCR        = bbcr;
    ActiveMan->SetActiveFunction( ::REQ_Write_BBCR_Setting_To_Reg );
}

//------------------------------------------------------------
void  CWIFIBB::REQ_Write_BBCR_Setting_To_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_BB_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    //for( int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        //for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            // if( m_sBBCR_Setting[i][j].checked && (false == m_sBBCR_Setting[i][j].RO) )
            {
                //MetaResult = META_WiFi_BBRegWrite_r( 500, m_sBBCR_Setting[i][j].addr, m_sBBCR_Setting[i][j].value );
                MetaResult = SP_META_WiFi_BBRegWrite_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sBBCR.count, m_sBBCR.bb_reg8, m_sBBCR.count );
            }
        }
    }

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_BB_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_BB_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//============================================================================
/////////////////////////////  File read/write   /////////////////////////////
//============================================================================
static const AnsiString SECTION_NAME = "WiFi MT5911 baseband register";
static const AnsiString KEY_NAME[] =
{
    "initialization and PHY-configuration register",
    "TX-related register",
    "RX-related register",
    "BBP configuration register",

};

//----------------------------------------------------------------------------
bool  CWIFIBB::REQ_Read_From_File( char *filename )
{
    TIniFile   *ini_file;
    AnsiString  as_data;
    char        str[2048];
    unsigned char      ucdata[WIFI_BBCR_MAX_NUM];
    int         i;


    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    // Initialization and PHY-Configuration
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME[WIFI_BBCR_IPC],
                                    "0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedChar( str, ucdata, WIFI_IPC_NUM );
    for( i=0; i<WIFI_IPC_NUM; i++ )
    {
        m_sBBCR_Setting[WIFI_BBCR_IPC][i].value = ucdata[i];
    }

    // TX-related
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME[WIFI_BBCR_TX],
                                    "0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedChar( str, ucdata, WIFI_TX_NUM );
    for( i=0; i<WIFI_TX_NUM; i++ )
    {
        m_sBBCR_Setting[WIFI_BBCR_TX][i].value = ucdata[i];
    }


    // RX-related
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME[WIFI_BBCR_RX],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedChar( str, ucdata, WIFI_RX_NUM );
    for( i=0; i<WIFI_RX_NUM; i++ )
    {
        m_sBBCR_Setting[WIFI_BBCR_RX][i].value = ucdata[i];
    }

    // BBP Configuration
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME[WIFI_BBCR_RX],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedChar( str, ucdata, WIFI_BBPC_NUM );
    for( i=0; i<WIFI_BBPC_NUM; i++ )
    {
        m_sBBCR_Setting[WIFI_BBCR_BBPC][i].value = ucdata[i];
    }

    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFIBB::REQ_Write_To_File( char *filename )
{
    TIniFile   *ini_file;
    char        str[2048];
    unsigned char         ucdata[WIFI_BBCR_MAX_NUM];
    int         i;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    // Initialization and PHY-Configuration
    for( i=0; i<WIFI_IPC_NUM; i++ )
    {
        ucdata[i] = m_sBBCR_Setting[WIFI_BBCR_IPC][i].value;
    }
    Array_To_String_UnsignedChar( str, ucdata, WIFI_IPC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME[WIFI_BBCR_IPC],
                           str );

    // TX-related
    for( i=0; i<WIFI_TX_NUM; i++ )
    {
        ucdata[i] = m_sBBCR_Setting[WIFI_BBCR_TX][i].value;
    }
    Array_To_String_UnsignedChar( str, ucdata, WIFI_TX_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME[WIFI_BBCR_TX],
                           str );

    // RX-related
    for( i=0; i<WIFI_RX_NUM; i++ )
    {
        ucdata[i] = m_sBBCR_Setting[WIFI_BBCR_RX][i].value;
    }
    Array_To_String_UnsignedChar( str, ucdata, WIFI_RX_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME[WIFI_BBCR_RX],
                           str );

    // BBP Configuration
    for( i=0; i<WIFI_BBPC_NUM; i++ )
    {
        ucdata[i] = m_sBBCR_Setting[WIFI_BBCR_BBPC][i].value;
    }
    Array_To_String_UnsignedChar( str, ucdata, WIFI_BBPC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME[WIFI_BBCR_BBPC],
                           str );

    delete  ini_file;

    return  true;
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
int   CWIFIBB::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

//---------------------------------------------------------------------------
S_WiFi_BBCR   CWIFIBB::Get_BBCR( void )
{
    return  m_sBBCR;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int  CWIFIBB::Get_BBCR_Setting_Value( int type, int idx )
{
    return  m_sBBCR_Setting[type][idx].value;
}

//----------------------------------------------------------------------------
void CWIFIBB::Set_BBCR_Setting_Value( int type, int idx, unsigned int value )
{
    m_sBBCR_Setting[type][idx].value = value;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIBB::Set_BBCR_Setting( int type, int idx, S_WIFI_BBCR_SETTING bbcr )
{
    m_sBBCR_Setting[type][idx] = bbcr;
}
