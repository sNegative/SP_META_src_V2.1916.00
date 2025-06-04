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
 *   wifi_ee.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi EEPROM source
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
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

#ifndef  _WIFI_EE_H_
#include "wifi_ee.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif

static CWIFIEE*  gs_wifi_ee_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static  void  Read_From_EE( void )
{
    gs_wifi_ee_ptr->Read_From_EE();
}

//---------------------------------------------------------------------------
static  void  Write_To_EE( void )
{
    gs_wifi_ee_ptr->Write_To_EE();
}

//===========================================================================
CWIFIEE::CWIFIEE( void )
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_bHasMeasured = false;
    memset(&m_sEE,0,sizeof(m_sEE));
    memset(&m_sEEGeneral,0,sizeof(m_sEEGeneral));
}

//---------------------------------------------------------------------------
CWIFIEE::~CWIFIEE( )
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
void CWIFIEE::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(METAAPP_STOP);
}

//---------------------------------------------------------------------------
void CWIFIEE::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }

    if (confirm_state != META_SUCCESS)
    {
        SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    }

    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
void  CWIFIEE::REQ_Read_From_EE_Start(S_WIFI_EEPROM eeprom)
{
    gs_wifi_ee_ptr = this;
    g_bIsRunning   = true;
    m_sEE          = eeprom;

    ActiveMan->SetActiveFunction(::Read_From_EE);
}

//------------------------------------------------------------
void CWIFIEE::Read_From_EE(void)
{
    if (!g_bIsRunning)
    {
        Confirm( META_FAILED );
        return;
    }

    META_RESULT  MetaResult = SP_META_WiFi_EEPROM_Read_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sEE.count, m_sEE.eeprom, m_sEE.count );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( META_FAILED );
            return;
        }
        else
        {
            Confirm( META_TIMEOUT );
            return;
        }
    }

    Confirm(META_SUCCESS);
}


//===========================================================================
void  CWIFIEE::REQ_Write_To_EE_Start(S_WIFI_EEPROM eeprom)
{
    gs_wifi_ee_ptr = this;
    g_bIsRunning   = true;
    m_sEE          = eeprom;

    ActiveMan->SetActiveFunction( ::Write_To_EE );
}

//------------------------------------------------------------
void  CWIFIEE::Write_To_EE( void )
{
    if( ! g_bIsRunning )
    {
        Confirm( META_FAILED );
        return;
    }

    META_RESULT  MetaResult = SP_META_WiFi_EEPROM_Write_r( m_META_HANDLE_Obj.Get_MainHandle(), 100*m_sEE.count, m_sEE.eeprom, m_sEE.count );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( META_FAILED );
            return;
        }
        else
        {
            Confirm( META_TIMEOUT );
            return;
        }
    }

    Confirm(META_SUCCESS);
}

//===========================================================================
static AnsiString SECTION_NAME_GENERAL = "WiFi General Information";

static AnsiString KEY_NAME_GENERAL[] =
{
    "WiFi BB chip ID",
    "WiFi RF chip ID",
    "WiFi serial number",
    "WiFi MAC address",
    "WiFi checksum"
};

typedef enum
{
    WIFI_BB_CHIP_ID_IDX=0,
    WIFI_RF_CHIP_ID_IDX,
    WIFI_SN_IDX,
    WIFI_MAC_ADDR_IDX,
    WIFI_CHECKSUM_IDX
} E_WIFI_EE_GENERAL;
//---------------------------------------------------------------------------
bool  CWIFIEE::REQ_Read_General_Info_From_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;


    m_sEEGeneral.usBBChipID = ini_file->ReadInteger( SECTION_NAME_GENERAL,
                              KEY_NAME_GENERAL[WIFI_BB_CHIP_ID_IDX],
                              0);


    m_sEEGeneral.usRFChipID = ini_file->ReadInteger( SECTION_NAME_GENERAL,
                              KEY_NAME_GENERAL[WIFI_RF_CHIP_ID_IDX],
                              0);

    m_sEEGeneral.uiSN = ini_file->ReadInteger( SECTION_NAME_GENERAL,
                        KEY_NAME_GENERAL[WIFI_SN_IDX],
                        0);

    AnsiString as_mac_addr;
    as_mac_addr = ini_file->ReadString( SECTION_NAME_GENERAL,
                                        KEY_NAME_GENERAL[WIFI_MAC_ADDR_IDX],
                                        0);
    if( ! Str_To_MACAddress( as_mac_addr, m_sEEGeneral.sMACAddr ) )
    {
        delete  ini_file;
        return false;
    }
    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFIEE::REQ_Write_General_Info_To_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( NULL == ini_file )  return  false;

    ini_file->WriteInteger( SECTION_NAME_GENERAL,
                            KEY_NAME_GENERAL[WIFI_BB_CHIP_ID_IDX],
                            m_sEEGeneral.usBBChipID  );

    ini_file->WriteInteger( SECTION_NAME_GENERAL,
                            KEY_NAME_GENERAL[WIFI_RF_CHIP_ID_IDX],
                            m_sEEGeneral.usRFChipID  );

    ini_file->WriteInteger( SECTION_NAME_GENERAL,
                            KEY_NAME_GENERAL[WIFI_SN_IDX],
                            m_sEEGeneral.uiSN  );

    AnsiString as_mac_addr;
    if( ! MACAddress_To_Str( m_sEEGeneral.sMACAddr , as_mac_addr )  )
    {
        delete  ini_file;
        return false;
    }
    ini_file->WriteString( SECTION_NAME_GENERAL,
                           KEY_NAME_GENERAL[WIFI_MAC_ADDR_IDX],
                           as_mac_addr  );


    ini_file->WriteInteger( SECTION_NAME_GENERAL,
                            KEY_NAME_GENERAL[WIFI_CHECKSUM_IDX],
                            m_sEEGeneral.ucChecksum  );

    delete  ini_file;
    return  true;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static AnsiString SECTION_NAME_TXDC = "WiFi TX DC Offset";
static AnsiString KEY_NAME_TXDC[] =
{
    "I_DC",
    "Q_DC"
};

//---------------------------------------------------------------------------
bool  CWIFIEE::REQ_Read_TX_DC_Offset_From_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    m_sEEGeneral.sTxDcOffset.i_ch_offset = ini_file->ReadInteger( SECTION_NAME_TXDC,
                                           KEY_NAME_TXDC[WIFI_IDX_IDC],
                                           0);


    m_sEEGeneral.sTxDcOffset.q_ch_offset = ini_file->ReadInteger( SECTION_NAME_TXDC,
                                           KEY_NAME_TXDC[WIFI_IDX_QDC],
                                           0);


    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFIEE::REQ_Write_TX_DC_Offset_To_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( NULL == ini_file )  return  false;

    ini_file->WriteInteger( SECTION_NAME_TXDC,
                            KEY_NAME_TXDC[WIFI_IDX_IDC],
                            m_sEEGeneral.sTxDcOffset.i_ch_offset  );

    ini_file->WriteInteger( SECTION_NAME_TXDC,
                            KEY_NAME_TXDC[WIFI_IDX_QDC],
                            m_sEEGeneral.sTxDcOffset.q_ch_offset  );

    delete  ini_file;

    return  true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static const AnsiString SECTION_NAME_2400M = "WiFi TX power 2.4G";
static const AnsiString SECTION_NAME_5000M = "WiFi TX power 5G";

static const AnsiString KEY_NAME_2400M[] =
{
    "TX power CCK",
    "TX power OFDM"
};

static const AnsiString KEY_NAME_5000M = "TX power";

//----------------------------------------------------------------------------
bool  CWIFIEE::REQ_Read_TxPower2400M_From_File( char *filename )
{
    TIniFile   *ini_file;
    AnsiString  as_data;
    char        str[2048];
    unsigned char      ucdata[NUM_TX_POWER_2400M_CH];
    int         i, j;


    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    for( i=0; i<2; i++ )
    {
        as_data = ini_file->ReadString( SECTION_NAME_2400M,
                                        KEY_NAME_2400M[i],
                                        "0,0,0,0,0,0,0,0,0,0,0,0,0,0");
        strcpy( str, as_data.c_str() );
        String_To_Array_UnsignedChar( str, ucdata, NUM_TX_POWER_2400M_CH );
        if( WIFI_MOD_CCK == i )
        {
            for( j=0; j<NUM_TX_POWER_2400M_CH; j++ )
            {
                m_sTxChannelDac2400M.CCKTxPWR[j] = ucdata[j];
            }
        }
        else
        {
            for( j=0; j<NUM_TX_POWER_2400M_CH; j++ )
            {
                m_sTxChannelDac2400M.OFDMTxPWR[j] = ucdata[j];
            }
        }
    }

    delete  ini_file;

    return true;
}


//-----------------------------------------------------------------------------
bool  CWIFIEE::REQ_Write_TxPower2400M_To_File( char *filename )
{
    TIniFile   *ini_file;
    char        str[2048];
    unsigned char         ucdata[NUM_TX_POWER_2400M_CH];
    int         i, j;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    for( i=0; i<2; i++ )
    {
        if( WIFI_MOD_CCK == i )
        {
            for( j=0; j<NUM_TX_POWER_2400M_CH; j++ )
            {
                ucdata[i] = m_sTxChannelDac2400M.CCKTxPWR[i];
            }
        }
        else
        {
            for( j=0; j<NUM_TX_POWER_2400M_CH; j++ )
            {
                ucdata[i] = m_sTxChannelDac2400M.OFDMTxPWR[i];
            }
        }
        Array_To_String_UnsignedChar( str, ucdata, NUM_TX_POWER_2400M_CH, ',' );
        ini_file->WriteString( SECTION_NAME_2400M,
                               KEY_NAME_2400M[i],
                               str );
    }

    delete  ini_file;

    return  true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CWIFIEE::REQ_Read_TxPower5000M_From_File( char *filename )
{
    TIniFile   *ini_file;
    AnsiString  as_data;
    char        str[2048];
    unsigned char      ucdata[NUM_TX_POWER_5000M_CH];
    int         i;


    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    as_data = ini_file->ReadString( SECTION_NAME_5000M,
                                    KEY_NAME_5000M,
                                    "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
    strcpy( str, as_data.c_str() );
    String_To_Array_UnsignedChar( str, ucdata, NUM_TX_POWER_5000M_CH );
    for( i=0; i<NUM_TX_POWER_5000M_CH; i++ )
    {
        m_sTxChannelDac5000M.TxPWR[i] = ucdata[i];
    }

    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFIEE::REQ_Write_TxPower5000M_To_File( char *filename )
{
    TIniFile   *ini_file;
    char        str[2048];
    unsigned char         ucdata[NUM_TX_POWER_5000M_CH];
    int         i;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    for( i=0; i<NUM_TX_POWER_5000M_CH; i++ )
    {
        ucdata[i] = m_sTxChannelDac5000M.TxPWR[i];
    }
    Array_To_String_UnsignedChar( str, ucdata, NUM_TX_POWER_5000M_CH, ',' );
    ini_file->WriteString( SECTION_NAME_5000M,
                           KEY_NAME_5000M,
                           str );

    delete  ini_file;

    return  true;
}

//---------------------------------------------------------------------------
unsigned char CWIFIEE::Calculate_Checksum( S_WIFI_EE_GENERAL &ee_gnrl )
{
    // m_sEEGeneral = ee_gnrl;
    unsigned char xor_sum=0;
    unsigned char checksum;

    // BB chip ID
    xor_sum ^= (ee_gnrl.usBBChipID & 0x00FF);
    xor_sum ^= ((ee_gnrl.usBBChipID & 0xFF00)>>8);

    // RF chip ID
    xor_sum ^= (ee_gnrl.usRFChipID & 0x00FF);
    xor_sum ^= ((ee_gnrl.usRFChipID & 0xFF00)>>8);

    // SN
    xor_sum ^= (ee_gnrl.usRFChipID & 0x000000FF);
    xor_sum ^= ((ee_gnrl.usRFChipID & 0x0000FF00)>>8);
    xor_sum ^= ((ee_gnrl.usRFChipID & 0x00FF0000)>>16);
    xor_sum ^= ((ee_gnrl.usRFChipID & 0xFF000000)>>24);

    // MAC address
    for( int i=0; i< sizeof(ee_gnrl.sMACAddr.mac_addr)/sizeof(ee_gnrl.sMACAddr.mac_addr[0]); i=i+2 )
    {
        xor_sum ^= ee_gnrl.sMACAddr.mac_addr[i];
    }

    // reserved 0
    xor_sum ^= (ee_gnrl.usReserved0 & 0x00FF);
    xor_sum ^= ((ee_gnrl.usReserved0 & 0xFF00)>>8);

    // TX DC offset
    xor_sum ^= (ee_gnrl.sTxDcOffset.i_ch_offset);
    xor_sum ^= (ee_gnrl.sTxDcOffset.q_ch_offset);

    // reserved 1
    xor_sum ^= (ee_gnrl.usReserved1 & 0x00FF);
    xor_sum ^= ((ee_gnrl.usReserved1 & 0xFF00)>>8);

    // reserved 2
    xor_sum ^= (ee_gnrl.ucReserved2);

    checksum = 0xFF ^ xor_sum;

    return checksum;
}

//===========================================================================
////////////////////////////   Global  information   ////////////////////////
//===========================================================================
META_RESULT CWIFIEE::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_WIFI_EEPROM   CWIFIEE::Get_EE( void )
{
    return  m_sEE;
}

//---------------------------------------------------------------------------
void   CWIFIEE::Set_EE( S_WIFI_EEPROM &eeprom )
{
    m_sEE = eeprom;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
S_WIFI_EE_GENERAL CWIFIEE::Get_EEGeneral( void )
{
    return  m_sEEGeneral;
}

//---------------------------------------------------------------------------
void CWIFIEE::Set_EEGeneral( S_WIFI_EE_GENERAL &ee_general )
{
    m_sEEGeneral = ee_general;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_DAC_DC_Offset_S CWIFIEE::Get_TxDcOffset( void )
{
    return  m_sEEGeneral.sTxDcOffset;
}

//--------------------------------------------------------------------------
void CWIFIEE::Set_TxDcOffset( WiFi_DAC_DC_Offset_S tx_dc_offset )
{
    m_sEEGeneral.sTxDcOffset = tx_dc_offset;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIEE::Get_Checksum( void )
{
    return m_sEEGeneral.ucChecksum;
}

//--------------------------------------------------------------------------
void CWIFIEE::Set_Checksum( unsigned char checksum )
{
    m_sEEGeneral.ucChecksum = checksum;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_2400M_S CWIFIEE::Get_TxChannelDac2400M( void )
{
    return m_sTxChannelDac2400M;
}

//---------------------------------------------------------------------------
void CWIFIEE::Set_TxChannelDac2400M( WiFi_TxPower_2400M_S &txpwr )
{
    m_sTxChannelDac2400M = txpwr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_5000M_S CWIFIEE::Get_TxChannelDac5000M( void )
{
    return m_sTxChannelDac5000M;
}

//---------------------------------------------------------------------------
void CWIFIEE::Set_TxChannelDac5000M( WiFi_TxPower_5000M_S &txpwr )
{
    m_sTxChannelDac5000M = txpwr;
}



