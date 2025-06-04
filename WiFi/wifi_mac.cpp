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
 *   wifi_mac.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi MAC source
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
 * Feb 23 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
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

#ifndef  _WIFI_MAC_H_
#include "wifi_mac.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

static CWIFIMAC*  gs_wifi_mac_ptr;

//===========================================================================
//static  void  Read_From_Reg( void )
//{   gs_wifi_mac_ptr->Read_From_Reg();
//}

//---------------------------------------------------------------------------
//static  void  REQ_Read_From_AllReg( void )
//{   gs_wifi_mac_ptr->REQ_Read_From_AllReg();
//}

//---------------------------------------------------------------------------
//static  void  Write_To_Reg( void )
//{   gs_wifi_mac_ptr->Write_To_Reg();
//}

//---------------------------------------------------------------------------
static  void  REQ_Read_MCR_Setting_From_Reg( void )
{
    gs_wifi_mac_ptr->REQ_Read_MCR_Setting_From_Reg();
}

//---------------------------------------------------------------------------
static  void  REQ_Write_MCR_Setting_To_Reg( void )
{
    gs_wifi_mac_ptr->REQ_Write_MCR_Setting_To_Reg();
}

//---------------------------------------------------------------------------
static  void  REQ_Read_MCR16_Setting_From_Reg( void )
{
    gs_wifi_mac_ptr->REQ_Read_MCR16_Setting_From_Reg();
}

//---------------------------------------------------------------------------
static  void  REQ_Write_MCR16_Setting_To_Reg( void )
{
    gs_wifi_mac_ptr->REQ_Write_MCR16_Setting_To_Reg();
}

//---------------------------------------------------------------------------
static  void  CNF_ReadFromNVRAM( void )
{
    gs_wifi_mac_ptr->CNF_ReadFromNVRAM();
}

//---------------------------------------------------------------------------
static  void  CNF_WriteToNVRAM(void)
{
    gs_wifi_mac_ptr->CNF_WriteToNVRAM();
}

//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    gs_wifi_mac_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    gs_wifi_mac_ptr->REQ_Finish();
}

//===========================================================================
CWIFIMAC::CWIFIMAC(void)
{
    m_bIsRunning = false;
    ConfirmCallback = NULL;
    m_pcMacAddrBuf = NULL;
    m_iMacAddrBufSize = 0;
    m_iConfirmState = 0;
    m_bHasMeasured = false;
    memset(&m_sMCR,0,sizeof(m_sMCR));
    memset(&m_sMCR16,0,sizeof(m_sMCR16));
    memset(m_sMCR_Setting,0,sizeof(S_WIFI_MCR_SETTING)*WIFI_MCR_TYPE_NUM*WIFI_MCR_MAX_NUM);
    memset(m_sMCR16_Setting,0,sizeof(S_WIFI_MCR16_SETTING)*WIFI_MCR16_TYPE_NUM*WIFI_MCR16_MAX_NUM);

}

//---------------------------------------------------------------------------
CWIFIMAC::~CWIFIMAC( )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;

    if( m_pcMacAddrBuf )
    {
        delete [] m_pcMacAddrBuf;
        m_pcMacAddrBuf = NULL;
    }
}

//---------------------------------------------------------------------------
void  CWIFIMAC::REQ_Finish( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_MAC_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIMAC::REQ_Stop( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_MAC_STOP );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIMAC::REQ_TimeOut( void )
{
    if( ! m_bIsRunning )  return;

    Confirm( STATE_MAC_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CWIFIMAC::Confirm( int confirm_state )
{
    if( ! m_bIsRunning )  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
///////////////////////////   MCR register setting   ////////////////////////
//===========================================================================
void  CWIFIMAC::REQ_Read_MCR_Setting_From_Reg_Start( S_WiFi_MCR &mcr )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning    = true;
    m_sMCR          = mcr;

    ActiveMan->SetActiveFunction( ::REQ_Read_MCR_Setting_From_Reg );
}

//------------------------------------------------------------
void  CWIFIMAC::REQ_Read_MCR_Setting_From_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_MAC_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    // for( int i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        // for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            // if( m_sMCR_Setting[i][j].checked )
            {
                // MetaResult = META_WiFi_MACRegRead( 500, m_sMCR_Setting[i][j].addr, &m_sMCR_Setting[i][j].value );
                MetaResult = SP_META_WiFi_MACReg32Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sMCR.count, m_sMCR.mac_reg32, m_sMCR.count );
            }
        }
    }
    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_MAC_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CWIFIMAC::REQ_Write_MCR_Setting_To_Reg_Start( S_WiFi_MCR &mcr )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning    = true;
    m_sMCR          = mcr;
    ActiveMan->SetActiveFunction( ::REQ_Write_MCR_Setting_To_Reg );
}

//------------------------------------------------------------
void  CWIFIMAC::REQ_Write_MCR_Setting_To_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_MAC_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    //  for( int i=0; i<WIFI_MCR_TYPE_NUM; i++ )
    {
        //  for(int j=0; j<WIFI_MCR_MAX_NUM; j++ )
        {
            // if( m_sMCR_Setting[i][j].checked && (false == m_sMCR_Setting[i][j].RO) )
            {
                // MetaResult = META_WiFi_MACRegWrite_r(500, m_sMCR_Setting[i][j].addr, m_sMCR_Setting[i][j].value);
                MetaResult = SP_META_WiFi_MACReg32Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sMCR.count, m_sMCR.mac_reg32, m_sMCR.count );
            }

            if(MetaResult!=META_SUCCESS)
            {
                if( MetaResult!=META_TIMEOUT )
                {
                    Confirm( STATE_MAC_FAIL );
                    return;
                }
                else
                {
                    Confirm( STATE_MAC_TIMEOUT );
                    return;
                }
            }
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//==========================================================================
void  CWIFIMAC::REQ_Read_MCR16_Setting_From_Reg_Start( S_WiFi_MCR16 &mcr16 )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning    = true;
    m_sMCR16        = mcr16;
    ActiveMan->SetActiveFunction( ::REQ_Read_MCR16_Setting_From_Reg );
}

//------------------------------------------------------------
void  CWIFIMAC::REQ_Read_MCR16_Setting_From_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_MAC_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_WiFi_MACReg16Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 50*m_sMCR16.count, m_sMCR16.mac_reg16, m_sMCR16.count );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_MAC_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CWIFIMAC::REQ_Write_MCR16_Setting_To_Reg_Start( S_WiFi_MCR16 &mcr16 )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning    = true;
    m_sMCR16        = mcr16;

    ActiveMan->SetActiveFunction( ::REQ_Write_MCR16_Setting_To_Reg );
}

//------------------------------------------------------------
void  CWIFIMAC::REQ_Write_MCR16_Setting_To_Reg( void )
{
    if( ! m_bIsRunning )
    {
        Confirm( STATE_MAC_FAIL );
        return;
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_WiFi_MACReg16Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sMCR16.count, m_sMCR16.mac_reg16, m_sMCR16.count );


    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_MAC_TIMEOUT );
            return;
        }
    }


    ActiveMan->SetActiveFunction( ::REQ_Finish );
}


//===========================================================================
void  CWIFIMAC::REQ_Read_From_NVRAM( void )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning = true;
    META_RESULT  MetaResult;

    if( 0 == m_pcMacAddrBuf )
    {
        MetaResult = SP_META_NVRAM_GetRecLen( "NVRAM_EF_WIFI_MAC_ADDRESS_LID",
                                              &m_iMacAddrBufSize );

        if(MetaResult!=META_SUCCESS)
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }
        m_pcMacAddrBuf = new  char[m_iMacAddrBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start( "NVRAM_EF_WIFI_MAC_ADDRESS_LID",
                                   1, // only one record
                                   m_iMacAddrBufSize,
                                   m_pcMacAddrBuf );
}

//-------------------------------------
void  CWIFIMAC::CNF_ReadFromNVRAM( void )
{
    if( ! m_bIsRunning )  return;

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    if(state==META_SUCCESS)
    {
        if( !Decompose_MacAddress() )
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }

        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }
    else if(state==META_TIMEOUT)
    {
        Confirm( STATE_MAC_TIMEOUT );
    }
    else if(state==METAAPP_STOP)
    {
        Confirm( STATE_MAC_STOP );
    }
    else
    {
        Confirm( STATE_MAC_FAIL );
    }
}

//--------------------------------------------------------------------------
bool  CWIFIMAC::Decompose_MacAddress( void )
{

    if( SP_META_NVRAM_WiFi_Decompose_MacAddress (&m_mac_addr, m_pcMacAddrBuf, m_iMacAddrBufSize)!= META_SUCCESS )
    {
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------
bool  CWIFIMAC::Compose_MacAddress( void )
{

    if( SP_META_NVRAM_WiFi_Compose_MacAddress (&m_mac_addr, m_pcMacAddrBuf, m_iMacAddrBufSize)!= META_SUCCESS )
    {
        return false;
    }

    return true;
}
//===========================================================================
void  CWIFIMAC::REQ_Write_To_NVRAM( void )
{
    gs_wifi_mac_ptr = this;
    m_bIsRunning = true;

    if( 0 == m_pcMacAddrBuf )
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen( "NVRAM_EF_WIFI_MAC_ADDRESS_LID",
                                 &m_iMacAddrBufSize );

        if(MetaResult!=META_SUCCESS)
        {
            Confirm( STATE_MAC_FAIL );
            return;
        }
        m_pcMacAddrBuf = new  char[m_iMacAddrBufSize];
    }

    if( !Compose_MacAddress() )
    {
        Confirm( STATE_MAC_FAIL );
        return;
    }


    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start( "NVRAM_EF_WIFI_MAC_ADDRESS_LID",
                                    1,
                                    m_iMacAddrBufSize,
                                    m_pcMacAddrBuf );
}

//-------------------------------------
void  CWIFIMAC::CNF_WriteToNVRAM( void )
{
    if( ! m_bIsRunning )  return;

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    if(state==META_SUCCESS)
    {
        ActiveMan->SetActiveFunction( ::REQ_Finish );
    }
    else if(state==META_TIMEOUT)
    {
        Confirm( STATE_MAC_TIMEOUT );
    }
    else if(state==METAAPP_STOP)
    {
        Confirm( STATE_MAC_STOP );
    }
    else
    {
        Confirm( STATE_MAC_FAIL );
    }
}

//============================================================================
/////////////////////////////  File read/write   /////////////////////////////
//============================================================================
static const AnsiString SECTION_NAME = "WiFi MT5911 MAC register";
static const AnsiString KEY_NAME_MT5911_MCR[] =
{
    "system control register",
    "miscellaneous and debug port register",
    "phyical layer control interface register",
    "MAC protocol timing control register",
    "NVA control register",
    "beacon generation register",
    "security engine register",
    "transmitter control register",
    "receiver control register",
    "HIF_SDIO register",
    "HIF_SPI register"
};

static const AnsiString KEY_NAME_MT5911_MCR16[] =
{
    "HIF_HPI register"
};

//----------------------------------------------------------------------------
bool  CWIFIMAC::REQ_Read_From_File( char *filename, WiFi_HostInterface_E host_inf )
{
    TIniFile   *ini_file;
    AnsiString  as_data;
    char        str[2048];
    unsigned int      uidata[WIFI_MCR_MAX_NUM];
    unsigned short    usdata[WIFI_MCR16_MAX_NUM];
    int         i;


    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    // System Control
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_SC],
                                    "0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_SC_NUM );
    for( i=0; i<WIFI_SC_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_SC][i].value = uidata[i];
    }

    // Miscellaneous and Debug Port
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_MDP],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_MDP_NUM );
    for( i=0; i<WIFI_MDP_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_MDP][i].value = uidata[i];
    }

    // Phyical Layer Control Interface
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_PLCI],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_PLCI_NUM );
    for( i=0; i<WIFI_PLCI_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_PLCI][i].value = uidata[i];
    }

    // MAC Protocol Timing Control
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_MPTC],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_MPTC_NUM );
    for( i=0; i<WIFI_MPTC_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_MPTC][i].value = uidata[i];
    }

    // NVA Control
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_NC],
                                    "0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_NC_NUM );
    for( i=0; i<WIFI_NC_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_NC][i].value = uidata[i];
    }

    // Beacon Generation
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_BG],
                                    "0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_BG_NUM );
    for( i=0; i<WIFI_BG_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_BG][i].value = uidata[i];
    }

    // Security Engine
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_SE],
                                    "0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_SE_NUM );
    for( i=0; i<WIFI_SE_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_SE][i].value = uidata[i];
    }

    // Transmitter Control
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_TC],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_TC_NUM );
    for( i=0; i<WIFI_TC_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_TC][i].value = uidata[i];
    }

    // Receiver Control
    as_data = ini_file->ReadString( SECTION_NAME,
                                    KEY_NAME_MT5911_MCR[WIFI_MCR_RC],
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedInteger( str, uidata, WIFI_RC_NUM );
    for( i=0; i<WIFI_RC_NUM; i++ )
    {
        m_sMCR_Setting[WIFI_MCR_RC][i].value = uidata[i];
    }

    switch( host_inf )
    {
        // HIF_HPI
    case WNDRV_HOST_INTERFACE_SDIO:
    {
        as_data = ini_file->ReadString( SECTION_NAME,
                                        KEY_NAME_MT5911_MCR[WIFI_MCR_HIF_SDIO],
                                        "0,0,0,0,0,0,0,");
        strcpy( str, as_data.c_str() );
        String_To_Array_UnsignedInteger( str, uidata, WIFI_HIF_SDIO_NUM );
        for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
        {
            m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].value = uidata[i];
        }
    }
    break;

    case WNDRV_HOST_INTERFACE_HPI:
    {
        as_data = ini_file->ReadString( SECTION_NAME,
                                        KEY_NAME_MT5911_MCR16[WIFI_MCR16_HIF_HPI],
                                        "0,0,0,0,0,0,0,0,");
        strcpy( str, as_data.c_str() );
        String_To_Array_UnsignedShort( str, usdata, WIFI_HIF_HPI_NUM );
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].value = usdata[i];
        }
    }
    break;

    case WNDRV_HOST_INTERFACE_SPI:
    {
        as_data = ini_file->ReadString( SECTION_NAME,
                                        KEY_NAME_MT5911_MCR[WIFI_MCR_HIF_SPI],
                                        "0,0,0,0,0,0,");
        strcpy( str, as_data.c_str() );
        String_To_Array_UnsignedInteger( str, uidata, WIFI_HIF_SPI_NUM );
        for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
        {
            m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].value = uidata[i];
        }
    }
    break;
    }




    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFIMAC::REQ_Write_To_File( char *filename, WiFi_HostInterface_E host_inf )
{
    TIniFile   *ini_file;
    char        str[2048];
    unsigned int         uidata[WIFI_MCR_MAX_NUM];
    unsigned short       usdata[WIFI_MCR16_MAX_NUM];
    int         i;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    // System Control
    for( i=0; i<WIFI_SC_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_SC][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_SC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_SC],
                           str );

    // Miscellaneous and Debug Port
    for( i=0; i<WIFI_MDP_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_MDP][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_MDP_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_MDP],
                           str );

    // Phyical Layer Control Interface
    for( i=0; i<WIFI_PLCI_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_PLCI][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_PLCI_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_PLCI],
                           str );

    // MAC Protocol Timing Control
    for( i=0; i<WIFI_MPTC_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_MPTC][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_MPTC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_MPTC],
                           str );

    // NVA Control
    for( i=0; i<WIFI_NC_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_NC][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_NC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_NC],
                           str );

    // Beacon Generation
    for( i=0; i<WIFI_BG_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_BG][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_BG_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_BG],
                           str );

    // Security Engine
    for( i=0; i<WIFI_SE_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_SE][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_SE_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_SE],
                           str );

    // Transmitter Control
    for( i=0; i<WIFI_TC_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_TC][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_TC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_TC],
                           str );

    // Receiver Control
    for( i=0; i<WIFI_RC_NUM; i++ )
    {
        uidata[i] = m_sMCR_Setting[WIFI_MCR_RC][i].value;
    }
    Array_To_String_UnsignedInteger( str, uidata, WIFI_RC_NUM, ',' );
    ini_file->WriteString( SECTION_NAME,
                           KEY_NAME_MT5911_MCR[WIFI_MCR_RC],
                           str );

    switch( host_inf )
    {
        // HIF_HPI
    case WNDRV_HOST_INTERFACE_SDIO:
    {
        for( i=0; i<WIFI_HIF_SDIO_NUM; i++ )
        {
            uidata[i] = m_sMCR_Setting[WIFI_MCR_HIF_SDIO][i].value;
        }
        Array_To_String_UnsignedInteger( str, uidata, WIFI_HIF_SDIO_NUM, ',' );
        ini_file->WriteString( SECTION_NAME,
                               KEY_NAME_MT5911_MCR[WIFI_MCR_HIF_SDIO],
                               str );
    }
    break;

    case WNDRV_HOST_INTERFACE_HPI:
    {
        for( i=0; i<WIFI_HIF_HPI_NUM; i++ )
        {
            usdata[i] = m_sMCR16_Setting[WIFI_MCR16_HIF_HPI][i].value;
        }
        Array_To_String_UnsignedShort( str, usdata, WIFI_HIF_HPI_NUM, ',' );
        ini_file->WriteString( SECTION_NAME,
                               KEY_NAME_MT5911_MCR16[WIFI_MCR16_HIF_HPI],
                               str );
    }
    break;

    case WNDRV_HOST_INTERFACE_SPI:
    {
        for( i=0; i<WIFI_HIF_SPI_NUM; i++ )
        {
            uidata[i] = m_sMCR_Setting[WIFI_MCR_HIF_SPI][i].value;
        }
        Array_To_String_UnsignedInteger( str, uidata, WIFI_HIF_SPI_NUM, ',' );
        ini_file->WriteString( SECTION_NAME,
                               KEY_NAME_MT5911_MCR[WIFI_MCR_HIF_SPI],
                               str );
    }
    break;
    }


    delete  ini_file;

    return  true;
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
//---------------------------------------------------------------------------
int   CWIFIMAC::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int  CWIFIMAC::Get_MCR_Setting_Value( int type, int idx )
{
    return  m_sMCR_Setting[type][idx].value;
}

//----------------------------------------------------------------------------
void CWIFIMAC::Set_MCR_Setting_Value( int type, int idx, unsigned int value )
{
    m_sMCR_Setting[type][idx].value = value;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short  CWIFIMAC::Get_MCR16_Setting_Value( int type, int idx )
{
    return  m_sMCR16_Setting[type][idx].value;
}

//----------------------------------------------------------------------------
void CWIFIMAC::Set_MCR16_Setting_Value( int type, int idx, unsigned short value )
{
    m_sMCR16_Setting[type][idx].value = value;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIMAC::Set_MCR_Setting( int type, int idx, S_WIFI_MCR_SETTING mcr )
{
    m_sMCR_Setting[type][idx] = mcr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIMAC::Set_MCR16_Setting( int type, int idx, S_WIFI_MCR16_SETTING mcr16 )
{
    m_sMCR16_Setting[type][idx] = mcr16;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_WiFi_MCR CWIFIMAC::Get_MCR( void )
{
    return  m_sMCR;
}

//----------------------------------------------------------------------------
void CWIFIMAC::Set_MCR( S_WiFi_MCR &mcr )
{
    m_sMCR = mcr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_WiFi_MCR16 CWIFIMAC::Get_MCR16( void )
{
    return  m_sMCR16;
}

//----------------------------------------------------------------------------
void CWIFIMAC::Set_MCR16( S_WiFi_MCR16 &mcr16 )
{
    m_sMCR16 = mcr16;
}
