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
 *   wifi_apc.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi channel power source
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
 * Jul 16 2008 mtk00490
 * [STP100001752] [META] META ver 5.0828.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Dec 17 2006 mtk00490
 * [STP100001255] [META] META ver 5.3.4.1
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


#pragma hdrstop

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_APC_H_
#include "wifi_apc.h"
#endif

// man
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif


//===========================================================================

static CWIFIAPC*  wifi_apc_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static  void  REQ_ReadFromNVRAM_TxPower2400M( void )
{
    wifi_apc_ptr->REQ_ReadFromNVRAM_TxPower2400M( );
}

//---------------------------------------------------------------------------
static void  CNF_ReadFromNVRAM_TxPower2400M( void )
{
    wifi_apc_ptr->CNF_ReadFromNVRAM_TxPower2400M();
}

//---------------------------------------------------------------------------
static  void  REQ_WriteToNVRAM_TxPower2400M( void )
{
    wifi_apc_ptr->REQ_WriteToNVRAM_TxPower2400M( );
}

//---------------------------------------------------------------------------
static  void  CNF_WriteToNVRAM_TxPower2400M( void )
{
    wifi_apc_ptr->CNF_WriteToNVRAM_TxPower2400M( );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static  void  REQ_ReadFromNVRAM_TxPower5000M( void )
{
    wifi_apc_ptr->REQ_ReadFromNVRAM_TxPower5000M( );
}

//---------------------------------------------------------------------------
static void  CNF_ReadFromNVRAM_TxPower5000M( void )
{
    wifi_apc_ptr->CNF_ReadFromNVRAM_TxPower5000M();
}

//---------------------------------------------------------------------------
static  void  REQ_WriteToNVRAM_TxPower5000M( void )
{
    wifi_apc_ptr->REQ_WriteToNVRAM_TxPower5000M( );
}

//---------------------------------------------------------------------------
static  void  CNF_WriteToNVRAM_TxPower5000M( void )
{
    wifi_apc_ptr->CNF_WriteToNVRAM_TxPower5000M( );
}

//---------------------------------------------------------------------------
static void REQ_TimeOut(void)
{
    wifi_apc_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void REQ_Finish(void)
{
    wifi_apc_ptr->REQ_Finish();
}

//---------------------------------------------------------------------------
static void REQ_SetDbmToDac(void)
{
    wifi_apc_ptr->REQ_SetDbmToDac();
}

//---------------------------------------------------------------------------
static void REQ_QueryDbmToDac(void)
{
    wifi_apc_ptr->REQ_QueryDbmToDac();
}

//===========================================================================
CWIFIAPC::CWIFIAPC(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    m_uiApcBufSize2400M = 0;
    m_cApcBuf2400M = NULL;
    m_uiApcBufSize5000M = 0;
    m_cApcBuf5000M = NULL;
    m_bDownloadTrigger = false;
}

//---------------------------------------------------------------------------
CWIFIAPC::~CWIFIAPC()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    if (m_cApcBuf2400M)
    {
        delete [] m_cApcBuf2400M;
        m_cApcBuf2400M = NULL;
    }

    if (m_cApcBuf5000M)
    {
        delete [] m_cApcBuf5000M;
        m_cApcBuf5000M = NULL;
    }
}

//---------------------------------------------------------------------------
void CWIFIAPC::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
/*void CWIFIAPC::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    NVRAMMan->REQ_Stop();
    Confirm( METAAPP_STOP );
} */

//---------------------------------------------------------------------------
void CWIFIAPC::REQ_TimeOut(void)
{
    if( ! g_bIsRunning )  return;

    NVRAMMan->REQ_Stop();
    Confirm( META_TIMEOUT );
}

//---------------------------------------------------------------------------
void CWIFIAPC::Confirm(META_RESULT confirm_state)
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
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
void CWIFIAPC::REQ_Read_TxPower2400M_From_NVRAM_Start(void)
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;
    REQ_ReadFromNVRAM_TxPower2400M();
}

//-------------------------------------
void CWIFIAPC::REQ_ReadFromNVRAM_TxPower2400M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cApcBuf2400M)
    {
        META_RESULT  MetaResult;
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_POWER_2400M_LID", (int *) &m_uiApcBufSize2400M);
        if(MetaResult!=META_SUCCESS)
        {
            Confirm( META_FAILED );
            return;
        }
        m_cApcBuf2400M = new  char[m_uiApcBufSize2400M];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM_TxPower2400M;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_WNDRV_TX_POWER_2400M_LID",
                                  1,
                                  m_uiApcBufSize2400M,
                                  m_cApcBuf2400M );
}

//-------------------------------------
void CWIFIAPC::CNF_ReadFromNVRAM_TxPower2400M(void)
{
    if (!g_bIsRunning )
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        if (m_bDownloadTrigger)
        {
            REQ_WriteToNVRAM_TxPower2400M();
        }
        else
        {
            META_RESULT MetaResult;
            MetaResult = SP_META_NVRAM_WiFi_Decompose_TxPower2400M(&m_sTxChannelDac2400M, m_cApcBuf2400M, m_uiApcBufSize2400M);

            if (MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
                return;
            }
            ActiveMan->SetActiveFunction(::REQ_Finish);
        }
    }
    break;

    default:
    {
        Confirm(state);
    }
    break;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIAPC::REQ_Write_TxPower2400M_To_NVRAM_Start(void)
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = true;
    REQ_ReadFromNVRAM_TxPower2400M();
}

//-------------------------------------
void CWIFIAPC::REQ_WriteToNVRAM_TxPower2400M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cApcBuf2400M)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_POWER_2400M_LID", (int *) &m_uiApcBufSize2400M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cApcBuf2400M = new char[m_uiApcBufSize2400M];
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_NVRAM_WiFi_Compose_TxPower2400M(&m_sTxChannelDac2400M,
                 m_cApcBuf2400M,
                 m_uiApcBufSize2400M);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM_TxPower2400M;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_WNDRV_TX_POWER_2400M_LID",
                                   1,
                                   m_uiApcBufSize2400M,
                                   m_cApcBuf2400M);

}

//-------------------------------------
void CWIFIAPC::CNF_WriteToNVRAM_TxPower2400M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        ActiveMan->SetActiveFunction(::REQ_Finish);
    }
    break;

    default:
    {
        Confirm(state);
    }
    break;
    }
}

//===========================================================================
void CWIFIAPC::REQ_Read_TxPower5000M_From_NVRAM_Start(void)
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;
    REQ_ReadFromNVRAM_TxPower5000M();
}

//-------------------------------------
void CWIFIAPC::REQ_ReadFromNVRAM_TxPower5000M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cApcBuf5000M)
    {
        META_RESULT  MetaResult;
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_POWER_5000M_LID", (int *) &m_uiApcBufSize5000M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cApcBuf5000M = new char[m_uiApcBufSize5000M];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM_TxPower5000M;
    NVRAMMan->REQ_ReadNVRAM_Start( "NVRAM_EF_WNDRV_TX_POWER_5000M_LID",
                                   1,
                                   m_uiApcBufSize5000M,
                                   m_cApcBuf5000M );
}

//-------------------------------------
void CWIFIAPC::CNF_ReadFromNVRAM_TxPower5000M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        if (m_bDownloadTrigger)
        {
            REQ_WriteToNVRAM_TxPower5000M();
        }
        else
        {
            META_RESULT  MetaResult;
            MetaResult = SP_META_NVRAM_WiFi_Decompose_TxPower5000M(&m_sTxChannelDac5000M, m_cApcBuf5000M, m_uiApcBufSize5000M);

            if (MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
                return;
            }
            ActiveMan->SetActiveFunction(::REQ_Finish);
        }
    }
    break;

    default:
    {
        Confirm(state);
    }
    break;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIAPC::REQ_Write_TxPower5000M_To_NVRAM_Start(void)
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = true;
    REQ_ReadFromNVRAM_TxPower5000M();
}

//-------------------------------------
void CWIFIAPC::REQ_WriteToNVRAM_TxPower5000M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cApcBuf5000M)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_POWER_5000M_LID", (int *) &m_uiApcBufSize5000M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cApcBuf5000M = new char[m_uiApcBufSize5000M];
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_NVRAM_WiFi_Compose_TxPower5000M(&m_sTxChannelDac5000M,
                 m_cApcBuf5000M,
                 m_uiApcBufSize5000M);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM_TxPower5000M;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_WNDRV_TX_POWER_5000M_LID",
                                   1,
                                   m_uiApcBufSize5000M,
                                   m_cApcBuf5000M);

}

//-------------------------------------
void CWIFIAPC::CNF_WriteToNVRAM_TxPower5000M(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    Confirm(state);
}

//===========================================================================
static const AnsiString SECTION_NAME_2400M = "WiFi TX power 2.4G";
static const AnsiString SECTION_NAME_5000M = "WiFi TX power 5G";

static const AnsiString KEY_NAME_2400M[] =
{
    "TX power CCK",
    "TX power OFDM"
};

static const AnsiString KEY_NAME_5000M = "TX power";

//----------------------------------------------------------------------------
bool  CWIFIAPC::WiFiTxPower2400MSectionExist( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL ) return false;

    if( ini_file->SectionExists( "WiFi TX power 2.4G" ) )
    {
        return true;
    }

    return false;
}

//----------------------------------------------------------------------------
bool  CWIFIAPC::REQ_Read_TxPower2400M_From_File( char *filename )
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
bool  CWIFIAPC::REQ_Write_TxPower2400M_To_File( char *filename )
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
                ucdata[j] = m_sTxChannelDac2400M.CCKTxPWR[j];
            }
        }
        else
        {
            for( j=0; j<NUM_TX_POWER_2400M_CH; j++ )
            {
                ucdata[j] = m_sTxChannelDac2400M.OFDMTxPWR[j];
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
bool  CWIFIAPC::REQ_Read_TxPower5000M_From_File( char *filename )
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
bool  CWIFIAPC::REQ_Write_TxPower5000M_To_File( char *filename )
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

//===========================================================================
void CWIFIAPC::REQ_SetDbmToDac_Start( WiFi_DBM2DAC_Set_S dbm2dac_set )
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;

    m_sDbm2DacSet = dbm2dac_set;
    ActiveMan->SetActiveFunction( ::REQ_SetDbmToDac );

}

//---------------------------------------------------------------------------
void CWIFIAPC::REQ_SetDbmToDac( void )
{
    META_RESULT  MetaResult = SP_META_WiFi_SetDbmToDac_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sDbm2DacSet);
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

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//===========================================================================
void CWIFIAPC::REQ_QueryDbmToDac_Start( void )
{
    wifi_apc_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction( ::REQ_QueryDbmToDac );

}

//---------------------------------------------------------------------------
void CWIFIAPC::REQ_QueryDbmToDac( void )
{
    META_RESULT  MetaResult = SP_META_WiFi_QueryDbmToDac_r( m_META_HANDLE_Obj.Get_MainHandle(), 500, &m_sDbm2DacQuery);
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

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CWIFIAPC::Get_ConfirmState( void )
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_2400M_S CWIFIAPC::Get_TxChannelDac2400M( void )
{
    return m_sTxChannelDac2400M;
}

//---------------------------------------------------------------------------
void CWIFIAPC::Set_TxChannelDac2400M( WiFi_TxPower_2400M_S &txpwr )
{
    m_sTxChannelDac2400M = txpwr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxPower_5000M_S CWIFIAPC::Get_TxChannelDac5000M( void )
{
    return m_sTxChannelDac5000M;
}

//---------------------------------------------------------------------------
void CWIFIAPC::Set_TxChannelDac5000M( WiFi_TxPower_5000M_S &txpwr )
{
    m_sTxChannelDac5000M = txpwr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_DBM2DAC_Query_S  CWIFIAPC::Get_DbmToDac( void )
{
    return m_sDbm2DacQuery;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIAPC::Get_TxPowerDac(E_WIFI_GENERATION e_802_11_idx, E_WIFI_MOD mod, unsigned int ch_idx )
{
    unsigned char dac;
    switch( e_802_11_idx )
    {
    case WIFI_802_11A_IDX:
        dac = Get_TxPowerDac5000M( ch_idx );
        break;

    case WIFI_802_11B_IDX:
    case WIFI_802_11G_IDX:
        dac = Get_TxPowerDac2400M( mod, ch_idx );
        break;

    }
    return dac;
}

//---------------------------------------------------------------------------
void CWIFIAPC::Set_TxPowerDac(E_WIFI_GENERATION e_802_11_idx, E_WIFI_MOD mod, unsigned int ch_idx, unsigned char dac )
{
    switch( e_802_11_idx )
    {
    case WIFI_802_11A_IDX:
        Set_TxPowerDac5000M( ch_idx, dac );
        break;

    case WIFI_802_11B_IDX:
    case WIFI_802_11G_IDX:
        Set_TxPowerDac2400M( mod, ch_idx, dac );
        break;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIAPC::Get_TxPowerDac2400M( E_WIFI_MOD mod, unsigned int ch_idx )
{
    unsigned char dac;
    if( WIFI_MOD_CCK == mod )
    {
        dac = m_sTxChannelDac2400M.CCKTxPWR[ch_idx];
    }
    else
    {
        dac = m_sTxChannelDac2400M.OFDMTxPWR[ch_idx];
    }

    return dac;
}

//---------------------------------------------------------------------------
void CWIFIAPC::Set_TxPowerDac2400M( E_WIFI_MOD mod, unsigned int ch_idx, unsigned char dac )
{
    if( WIFI_MOD_CCK == mod )
    {
        m_sTxChannelDac2400M.CCKTxPWR[ch_idx] = dac;
    }
    else
    {
        m_sTxChannelDac2400M.OFDMTxPWR[ch_idx] = dac;
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIAPC::Get_TxPowerDac5000M( unsigned int ch_idx )
{
    return m_sTxChannelDac5000M.TxPWR[ch_idx];
}

//---------------------------------------------------------------------------
void CWIFIAPC::Set_TxPowerDac5000M( unsigned int ch_idx, unsigned char dac )
{
    m_sTxChannelDac5000M.TxPWR[ch_idx] = dac;
}


