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
 *   wifi_txdc.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi TX DC offset source
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

#ifndef  _WIFI_TXDC_H_
#include "wifi_txdc.h"
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

static CWIFITXDC*  wifi_txdc_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static  void  REQ_TxDcOffsetCal( void )
{
    wifi_txdc_ptr->REQ_TxDcOffsetCal();
}

//---------------------------------------------------------------------------
static  void  REQ_ReadFromNVRAM( void )
{
    wifi_txdc_ptr->REQ_ReadFromNVRAM( );
}

//---------------------------------------------------------------------------
static void  CNF_ReadFromNVRAM( void )
{
    wifi_txdc_ptr->CNF_ReadFromNVRAM();
}

//---------------------------------------------------------------------------
static  void  REQ_WriteToNVRAM( void )
{
    wifi_txdc_ptr->REQ_WriteToNVRAM( );
}

//---------------------------------------------------------------------------
static  void  CNF_WriteToNVRAM( void )
{
    wifi_txdc_ptr->CNF_WriteToNVRAM( );
}

//---------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    wifi_txdc_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    wifi_txdc_ptr->REQ_Finish();
}

//===========================================================================
CWIFITXDC::CWIFITXDC( void )
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    m_uiTxDcOffsetBufSize = 0;
    m_cpTxDcOffsetBuf = NULL;
    m_bDownloadTrigger = false;

}

//---------------------------------------------------------------------------
CWIFITXDC::~CWIFITXDC()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    if (m_cpTxDcOffsetBuf)
    {
        delete [] m_cpTxDcOffsetBuf;
        m_cpTxDcOffsetBuf = NULL;
    }

}

//---------------------------------------------------------------------------
void CWIFITXDC::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
/*void CWIFITXDC::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }


    NVRAMMan->REQ_Stop();
    Confirm(METAAPP_STOP);
} */

//---------------------------------------------------------------------------
void CWIFITXDC::REQ_TimeOut(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    NVRAMMan->REQ_Stop();
    Confirm(META_TIMEOUT);
}

//---------------------------------------------------------------------------
void CWIFITXDC::Confirm(META_RESULT confirm_state)
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
void  CWIFITXDC::REQ_TxDcOffsetCal_Start( void )
{
    wifi_txdc_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_TxDcOffsetCal);
}

//--------------------------------------------------------------------------
void CWIFITXDC::REQ_TxDcOffsetCal(void)
{
    META_RESULT MetaResult = SP_META_WiFi_DacDcOffsetAutoCalibration_r(m_META_HANDLE_Obj.Get_MainHandle(),  5000, &m_sTxDcOffset);
    if (MetaResult != META_SUCCESS)
    {
        if (MetaResult != META_TIMEOUT)
        {
            Confirm(META_FAILED);
            return;
        }
        else
        {
            Confirm(META_TIMEOUT);
            return;
        }
    }
    ActiveMan->SetActiveFunction(::REQ_Finish);
}

//===========================================================================
void  CWIFITXDC::REQ_Read_From_NVRAM_Start( void )
{
    wifi_txdc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;
    REQ_ReadFromNVRAM();
}

//-------------------------------------
void CWIFITXDC::REQ_ReadFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cpTxDcOffsetBuf)
    {
        META_RESULT  MetaResult;
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID", (int *) &m_uiTxDcOffsetBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cpTxDcOffsetBuf = new char[m_uiTxDcOffsetBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID",
                                  1,
                                  m_uiTxDcOffsetBufSize,
                                  m_cpTxDcOffsetBuf );
}

//-------------------------------------
void  CWIFITXDC::CNF_ReadFromNVRAM( void )
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
            REQ_WriteToNVRAM();
        }
        else
        {
            META_RESULT  MetaResult;
            MetaResult = SP_META_NVRAM_WiFi_Decompose_DacDcOffset(&m_sTxDcOffset, m_cpTxDcOffsetBuf, m_uiTxDcOffsetBufSize);

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
void CWIFITXDC::REQ_Write_To_NVRAM_Start(void)
{
    wifi_txdc_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = true;
    REQ_WriteToNVRAM();
}

//-------------------------------------
void CWIFITXDC::REQ_WriteToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT  MetaResult;

    if (NULL == m_cpTxDcOffsetBuf)
    {
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID", (int *) &m_uiTxDcOffsetBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cpTxDcOffsetBuf = new char[m_uiTxDcOffsetBufSize];
    }

    MetaResult = SP_META_NVRAM_WiFi_Compose_DacDcOffset(&m_sTxDcOffset,
                 m_cpTxDcOffsetBuf,
                 m_uiTxDcOffsetBufSize );

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID",
                                   1,
                                   m_uiTxDcOffsetBufSize,
                                   m_cpTxDcOffsetBuf);

}

//-------------------------------------
void CWIFITXDC::CNF_WriteToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    Confirm(state);
}


//===========================================================================


static AnsiString SECTION_NAME = "WiFi TX DC Offset";
static AnsiString KEY_NAME[] =
{
    "I_DC",
    "Q_DC"
};

//----------------------------------------------------------------------------
bool  CWIFITXDC::WiFiTxDcOffsetSectionExist( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL ) return false;

    if( ini_file->SectionExists( SECTION_NAME ) )
    {
        return true;
    }

    return false;
}

//---------------------------------------------------------------------------
bool  CWIFITXDC::REQ_Read_From_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    m_sTxDcOffset.i_ch_offset = ini_file->ReadInteger( SECTION_NAME,
                                KEY_NAME[WIFI_IDX_IDC],
                                0);


    m_sTxDcOffset.q_ch_offset = ini_file->ReadInteger( SECTION_NAME,
                                KEY_NAME[WIFI_IDX_QDC],
                                0);


    delete  ini_file;

    return true;
}

//-----------------------------------------------------------------------------
bool  CWIFITXDC::REQ_Write_To_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( NULL == ini_file )  return  false;

    ini_file->WriteInteger( SECTION_NAME,
                            KEY_NAME[WIFI_IDX_IDC],
                            m_sTxDcOffset.i_ch_offset  );

    ini_file->WriteInteger( SECTION_NAME,
                            KEY_NAME[WIFI_IDX_QDC],
                            m_sTxDcOffset.q_ch_offset  );

    delete  ini_file;

    return  true;
}

//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CWIFITXDC::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_DAC_DC_Offset_S CWIFITXDC::Get_TxDcOffset(void)
{
    return  m_sTxDcOffset;
}

//--------------------------------------------------------------------------
void CWIFITXDC::Set_TxDcOffset(WiFi_DAC_DC_Offset_S tx_dc_offset)
{
    m_sTxDcOffset = tx_dc_offset;
}



