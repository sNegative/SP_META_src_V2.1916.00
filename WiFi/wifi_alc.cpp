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
 *   wifi_alc.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi ALC source
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#pragma hdrstop



#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_ALC_H_
#include "wifi_alc.h"
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
static CWIFIALC*  g_wifi_alc_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static void REQ_ReadAlcPowerFromNVRAM(void)
{
    g_wifi_alc_ptr->REQ_ReadAlcPowerFromNVRAM();
}

//---------------------------------------------------------------------------
static void CNF_ReadAlcPowerFromNVRAM(void)
{
    g_wifi_alc_ptr->CNF_ReadAlcPowerFromNVRAM();
}

//---------------------------------------------------------------------------
static void REQ_WriteAlcPowerToNVRAM(void)
{
    g_wifi_alc_ptr->REQ_WriteAlcPowerToNVRAM();
}

//---------------------------------------------------------------------------
static void CNF_WriteAlcPowerToNVRAM(void)
{
    g_wifi_alc_ptr->CNF_WriteAlcPowerToNVRAM();
}

//---------------------------------------------------------------------------
static void REQ_ReadAlcSlopeFromNVRAM(void)
{
    g_wifi_alc_ptr->REQ_ReadAlcSlopeFromNVRAM();
}

//---------------------------------------------------------------------------
static void CNF_ReadAlcSlopeFromNVRAM(void)
{
    g_wifi_alc_ptr->CNF_ReadAlcSlopeFromNVRAM();
}

//---------------------------------------------------------------------------
static void REQ_WriteAlcSlopeToNVRAM(void)
{
    g_wifi_alc_ptr->REQ_WriteAlcSlopeToNVRAM();
}

//---------------------------------------------------------------------------
static void CNF_WriteAlcSlopeToNVRAM(void)
{
    g_wifi_alc_ptr->CNF_WriteAlcSlopeToNVRAM();
}

//---------------------------------------------------------------------------
static void REQ_TimeOut(void)
{
    g_wifi_alc_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void REQ_Finish(void)
{
    g_wifi_alc_ptr->REQ_Finish();
}

//===========================================================================
CWIFIALC::CWIFIALC(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    m_uiAlcPowerBufSize2400M = 0;
    m_cAlcPowerBuf2400M = NULL;

    m_uiAlcSlopeBufSize2400M = 0;
    m_cAlcSlopeBuf2400M = NULL;
}

//---------------------------------------------------------------------------
CWIFIALC::~CWIFIALC()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    if (m_cAlcPowerBuf2400M)
    {
        delete [] m_cAlcPowerBuf2400M;
        m_cAlcPowerBuf2400M = NULL;
    }

    if (m_cAlcSlopeBuf2400M)
    {
        delete [] m_cAlcSlopeBuf2400M;
        m_cAlcSlopeBuf2400M = NULL;
    }
}

//---------------------------------------------------------------------------
void CWIFIALC::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm(META_SUCCESS);

}

//---------------------------------------------------------------------------
/*void CWIFIALC::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }


    NVRAMMan->REQ_Stop();
    Confirm(METAAPP_STOP);
} */

//---------------------------------------------------------------------------
void CWIFIALC::REQ_TimeOut(void)
{
    if (!g_bIsRunning)
    {
        return;
    }



    NVRAMMan->REQ_Stop();
    Confirm(META_TIMEOUT);
}

//---------------------------------------------------------------------------
void CWIFIALC::Confirm(META_RESULT confirm_state)
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
void CWIFIALC::REQ_Read_From_NVRAM_Start(void)
{
    g_wifi_alc_ptr = this;
    g_bIsRunning = true;

    REQ_ReadAlcPowerFromNVRAM();
}

//-------------------------------------
void CWIFIALC::REQ_ReadAlcPowerFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cAlcPowerBuf2400M)
    {
        META_RESULT MetaResult;
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_ALC_POWER_LID", (int *) &m_uiAlcPowerBufSize2400M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED );
            return;
        }
        m_cAlcPowerBuf2400M = new char[m_uiAlcPowerBufSize2400M];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadAlcPowerFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_WNDRV_TX_ALC_POWER_LID",
                                  1,
                                  m_uiAlcPowerBufSize2400M,
                                  m_cAlcPowerBuf2400M);
}

//-------------------------------------
void CWIFIALC::CNF_ReadAlcPowerFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT  state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        META_RESULT  MetaResult;
        MetaResult = SP_META_NVRAM_WiFi_Decompose_ALC_2400M(&m_sAlcPower2400M, m_cAlcPowerBuf2400M, m_uiAlcPowerBufSize2400M);

        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        REQ_ReadAlcSlopeFromNVRAM();
    }
    break;

    default:
    {
        Confirm(state);
    }
    break;
    }
}

//--------------------------------------------------------------------------
void CWIFIALC::REQ_ReadAlcSlopeFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cAlcSlopeBuf2400M)
    {
        META_RESULT MetaResult;
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_ALC_SLOPE_LID", (int *) &m_uiAlcSlopeBufSize2400M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED );
            return;
        }
        m_cAlcSlopeBuf2400M = new char[m_uiAlcSlopeBufSize2400M];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadAlcSlopeFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_WNDRV_ALC_SLOPE_LID",
                                  1,
                                  m_uiAlcSlopeBufSize2400M,
                                  m_cAlcSlopeBuf2400M);
}

//-------------------------------------
void CWIFIALC::CNF_ReadAlcSlopeFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT  state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        META_RESULT  MetaResult;
        MetaResult = SP_META_NVRAM_WiFi_Decompose_TxALC2400M(&m_sAlcSlope2400M, m_cAlcSlopeBuf2400M, m_uiAlcSlopeBufSize2400M);

        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CWIFIALC::REQ_Write_To_NVRAM_Start(void)
{
    g_wifi_alc_ptr = this;
    g_bIsRunning = true;

    REQ_WriteAlcPowerToNVRAM();
}

//---------------------------------------------------------------------------
void CWIFIALC::REQ_WriteAlcPowerToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cAlcPowerBuf2400M)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_TX_ALC_POWER_LID", (int *) &m_uiAlcPowerBufSize2400M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cAlcPowerBuf2400M = new char[m_uiAlcPowerBufSize2400M];
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_NVRAM_WiFi_Compose_ALC_2400M(&m_sAlcPower2400M,
                 m_cAlcPowerBuf2400M,
                 m_uiAlcPowerBufSize2400M);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteAlcPowerToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_WNDRV_TX_ALC_POWER_LID",
                                   1,
                                   m_uiAlcPowerBufSize2400M,
                                   m_cAlcPowerBuf2400M
                                  );

}

//-------------------------------------
void CWIFIALC::CNF_WriteAlcPowerToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    if (state != META_SUCCESS)
    {
        Confirm(state);
        return;
    }
    REQ_WriteAlcSlopeToNVRAM();
}

//--------------------------------------------------------------------------
void CWIFIALC::REQ_WriteAlcSlopeToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cAlcSlopeBuf2400M)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_WNDRV_ALC_SLOPE_LID", (int *) &m_uiAlcSlopeBufSize2400M);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cAlcSlopeBuf2400M = new char[m_uiAlcSlopeBufSize2400M];
    }

    META_RESULT  MetaResult;
    MetaResult = SP_META_NVRAM_WiFi_Compose_TxALC2400M(&m_sAlcSlope2400M,
                 m_cAlcSlopeBuf2400M,
                 m_uiAlcSlopeBufSize2400M);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteAlcSlopeToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_WNDRV_ALC_SLOPE_LID",
                                   1,
                                   m_uiAlcSlopeBufSize2400M,
                                   m_cAlcSlopeBuf2400M
                                  );

}

//-------------------------------------
void CWIFIALC::CNF_WriteAlcSlopeToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    Confirm(state);

}


//===========================================================================
#define  TX_ALC_CCK_IDX              0
#define  TX_OUTPUT_POWER_DB_CCK_IDX  1
#define  TX_ALC_OFDM_IDX             2
#define  TX_OUTPUT_POWER_DB_OFDM_IDX 3

#define  ALC_SLOPE1_DIVIDER_IDX      0
#define  ALC_SLOPE1_DIVIDEND_IDX     1
#define  ALC_SLOPE2_DIVIDER_IDX      2
#define  ALC_SLOPE2_DIVIDEND_IDX     3

static const AnsiString asSECTION_NAME_2400M = "WiFi ALC 2.4G";

static const AnsiString asKEY_NAME_POWER_2400M[] =
{
    "TX ALC CCK",
    "TX output power DB CCK",
    "TX ALC OFDM",
    "TX output power DB OFDM"
};

static const AnsiString asKEY_NAME_SLOPE_2400M[] =
{
    "ALC Slop1 Divider",
    "ALC Slop1 Dividend",
    "ALC Slop2 Divider",
    "ALC Slop2 Dividend"
};

//----------------------------------------------------------------------------
bool CWIFIALC::WiFiAlc2400MSectionExist(char *filename)
{

    TIniFile   *ini_file;

    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return false;
    }

    if (ini_file->SectionExists(asSECTION_NAME_2400M))
    {
        return true;
    }

    return false;

}

//----------------------------------------------------------------------------
bool CWIFIALC::REQ_Read_From_File(char *filename)
{

    TIniFile   *ini_file;
    AnsiString  as_data;
    char        str[2048];
    unsigned char      ucdata[WIFI_ALC_2400M_CH_NUM];

    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return false;
    }


    // TX ALC CCK
    as_data = ini_file->ReadString(asSECTION_NAME_2400M,
                                   asKEY_NAME_POWER_2400M[TX_ALC_CCK_IDX],
                                   "0,0,0,0,0,0,0,0,0,0,0,0,0,0");
    strcpy(str, as_data.c_str());
    String_To_Array_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM);
    for(int j=0; j<WIFI_ALC_2400M_CH_NUM; j++ )
    {
        m_sAlcPower2400M.txAlcCCK[j] = ucdata[j];
    }

    // TX output power DB CCK
    as_data = ini_file->ReadString(asSECTION_NAME_2400M,
                                   asKEY_NAME_POWER_2400M[TX_OUTPUT_POWER_DB_CCK_IDX],
                                   "0,0,0,0,0,0,0,0,0,0,0,0,0,0");
    strcpy(str, as_data.c_str());
    String_To_Array_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM);
    for (int j=0; j<WIFI_ALC_2400M_CH_NUM; j++ )
    {
        m_sAlcPower2400M.txOutputPowerDBCCK[j] = ucdata[j];
    }

    // TX ALC OFDM
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        AnsiString as = asKEY_NAME_POWER_2400M[TX_ALC_OFDM_IDX] + IntToStr(i);
        as_data = ini_file->ReadString(asSECTION_NAME_2400M,
                                       as,
                                       "0,0,0,0,0,0,0,0,0,0,0,0,0,0");
        strcpy(str, as_data.c_str());
        String_To_Array_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM);
        for(int j=0; j<WIFI_ALC_2400M_CH_NUM; j++ )
        {
            m_sAlcPower2400M.txAlcOFDM[i][j] = ucdata[j];
        }
    }

    // TX output power DB OFDM
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        AnsiString as = asKEY_NAME_POWER_2400M[TX_OUTPUT_POWER_DB_OFDM_IDX] + IntToStr(i);
        as_data = ini_file->ReadString(asSECTION_NAME_2400M,
                                       as,
                                       "0,0,0,0,0,0,0,0,0,0,0,0,0,0");
        strcpy(str, as_data.c_str());
        String_To_Array_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM);
        for(int j=0; j<WIFI_ALC_2400M_CH_NUM; j++ )
        {
            m_sAlcPower2400M.txOutputPowerDBOFDM[i][j] = ucdata[j];
        }
    }

    // ALC slope
    m_sAlcSlope2400M.alcSlop1Divider = ini_file->ReadInteger(asSECTION_NAME_2400M,
                                       asKEY_NAME_SLOPE_2400M[ALC_SLOPE1_DIVIDER_IDX],
                                       10);

    m_sAlcSlope2400M.alcSlop1Dividend = ini_file->ReadInteger(asSECTION_NAME_2400M,
                                        asKEY_NAME_SLOPE_2400M[ALC_SLOPE1_DIVIDEND_IDX],
                                        1);

    m_sAlcSlope2400M.alcSlop2Divider = ini_file->ReadInteger(asSECTION_NAME_2400M,
                                       asKEY_NAME_SLOPE_2400M[ALC_SLOPE2_DIVIDER_IDX],
                                       15);

    m_sAlcSlope2400M.alcSlop2Dividend = ini_file->ReadInteger(asSECTION_NAME_2400M,
                                        asKEY_NAME_SLOPE_2400M[ALC_SLOPE2_DIVIDEND_IDX],
                                        10);

    delete  ini_file;
    return true;
}

//-----------------------------------------------------------------------------
bool CWIFIALC::REQ_Write_To_File(char *filename)
{
    TIniFile   *ini_file;
    char        str[2048];
    unsigned char         ucdata[WIFI_ALC_2400M_CH_NUM];

    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return  false;
    }

    // TX ALC CCK
    for (int j=0; j<NUM_TX_POWER_2400M_CH; j++)
    {
        ucdata[j] = m_sAlcPower2400M.txAlcCCK[j];
    }

    Array_To_String_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM, ',');
    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_POWER_2400M[TX_ALC_CCK_IDX],
                          str);

    // TX output power DB CCK
    for (int j=0; j<NUM_TX_POWER_2400M_CH; j++)
    {
        ucdata[j] = m_sAlcPower2400M.txOutputPowerDBCCK[j];
    }

    Array_To_String_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM, ',');
    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_POWER_2400M[TX_OUTPUT_POWER_DB_CCK_IDX],
                          str);

    // TX ALC OFDM
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        for (int j=0; j<NUM_TX_POWER_2400M_CH; j++)
        {
            ucdata[j] = m_sAlcPower2400M.txAlcOFDM[i][j];
        }

        AnsiString as = asKEY_NAME_POWER_2400M[TX_ALC_OFDM_IDX] + IntToStr(i);
        Array_To_String_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM, ',');
        ini_file->WriteString(asSECTION_NAME_2400M,
                              as,
                              str);
    }

    // TX output power DB OFDM
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        for (int j=0; j<NUM_TX_POWER_2400M_CH; j++)
        {
            ucdata[j] = m_sAlcPower2400M.txOutputPowerDBOFDM[i][j];
        }

        AnsiString as = asKEY_NAME_POWER_2400M[TX_OUTPUT_POWER_DB_OFDM_IDX] + IntToStr(i);
        Array_To_String_UnsignedChar(str, ucdata, WIFI_ALC_2400M_CH_NUM, ',');
        ini_file->WriteString(asSECTION_NAME_2400M,
                              as,
                              str);
    }

    // ALC slope
    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_SLOPE_2400M[ALC_SLOPE1_DIVIDER_IDX],
                          IntToStr(m_sAlcSlope2400M.alcSlop1Divider)
                         );

    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_SLOPE_2400M[ALC_SLOPE1_DIVIDEND_IDX],
                          IntToStr(m_sAlcSlope2400M.alcSlop1Dividend)
                         );

    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_SLOPE_2400M[ALC_SLOPE2_DIVIDER_IDX],
                          IntToStr(m_sAlcSlope2400M.alcSlop2Divider)
                         );

    ini_file->WriteString(asSECTION_NAME_2400M,
                          asKEY_NAME_SLOPE_2400M[ALC_SLOPE2_DIVIDEND_IDX],
                          IntToStr(m_sAlcSlope2400M.alcSlop2Dividend)
                         );

    delete  ini_file;
    return  true;

}

//==========================================================================
//////////////////////////////    Query    /////////////////////////////////
//===========================================================================
bool CWIFIALC::REQ_Query_ALC_Suppport_Start(void)
{

    if (SP_META_QueryIfTargetSupportWifiALC_r(m_META_HANDLE_Obj.Get_MainHandle(), 300) != META_SUCCESS)
    {
        return false;
    }

    return true;
}

//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CWIFIALC::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_ALC_2400M_S* CWIFIALC::Get_AlcPower2400M(void)
{
    return &m_sAlcPower2400M;
}

//---------------------------------------------------------------------------
void CWIFIALC::Set_AlcPower2400M(WiFi_ALC_2400M_S alc)
{
    m_sAlcPower2400M = alc;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIALC::Get_AlcPower2400MAlc(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate)
{
    unsigned char alc;
    if (WIFI_MOD_CCK == mod)
    {
        alc = m_sAlcPower2400M.txAlcCCK[ch_idx];
    }
    else
    {
        alc = m_sAlcPower2400M.txAlcOFDM[rate][ch_idx];
    }

    return alc;
}

//---------------------------------------------------------------------------
void CWIFIALC::Set_AlcPower2400MAlc(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate, unsigned char alc)
{
    if (WIFI_MOD_CCK == mod)
    {
        m_sAlcPower2400M.txAlcCCK[ch_idx] = alc;
    }
    else
    {
        m_sAlcPower2400M.txAlcOFDM[rate][ch_idx] = alc;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CWIFIALC::Get_AlcPower2400MPowerDB(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate)
{
    unsigned char db;
    if (WIFI_MOD_CCK == mod)
    {
        db = m_sAlcPower2400M.txOutputPowerDBCCK[ch_idx];
    }
    else
    {
        db = m_sAlcPower2400M.txOutputPowerDBOFDM[rate][ch_idx];
    }

    return db;
}

//---------------------------------------------------------------------------
void CWIFIALC::Set_AlcPower2400MPowerDB(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate, unsigned char db)
{
    if (WIFI_MOD_CCK == mod)
    {
        m_sAlcPower2400M.txOutputPowerDBCCK[ch_idx] = db;
    }
    else
    {
        m_sAlcPower2400M.txOutputPowerDBOFDM[rate][ch_idx] = db;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WiFi_TxALC_2400M_S* CWIFIALC::Get_AlcSlope2400M(void)
{
    return &m_sAlcSlope2400M;
}

//---------------------------------------------------------------------------
void CWIFIALC::Set_AlcSlope2400M(WiFi_TxALC_2400M_S alc)
{
    m_sAlcSlope2400M = alc;
}

