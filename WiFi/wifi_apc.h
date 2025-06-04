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
 *   wifi_apc.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi channel power header
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
#ifndef  _WIFI_APC_H_
#define  _WIFI_APC_H_
#include <vcl.h>
#include <IniFiles.hpp>
// common
#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// WiFi
#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif
/*---------------------------------------------------------------------------*/



#define  WIFI_MAX_APC_VALUE        63



class  CWIFIAPC
{
private:

    // common
    META_RESULT   m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    bool  m_bDownloadTrigger;
    unsigned int m_uiApcBufSize2400M;
    char        *m_cApcBuf2400M;
    unsigned int m_uiApcBufSize5000M;
    char        *m_cApcBuf5000M;
    WiFi_TxPower_2400M_S m_sTxChannelDac2400M;
    WiFi_TxPower_5000M_S m_sTxChannelDac5000M;
    WiFi_DBM2DAC_Set_S m_sDbm2DacSet;
    WiFi_DBM2DAC_Query_S m_sDbm2DacQuery;

protected:
public:


    void  Confirm(META_RESULT confirm_state );


    CWIFIAPC( void );
    ~CWIFIAPC();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );





    void  REQ_ReadFromNVRAM_TxPower2400M( void );
    void  CNF_ReadFromNVRAM_TxPower2400M( void );
    void  REQ_WriteToNVRAM_TxPower2400M( void );
    void  CNF_WriteToNVRAM_TxPower2400M( void );
    void  REQ_ReadFromNVRAM_TxPower5000M( void );
    void  CNF_ReadFromNVRAM_TxPower5000M( void );
    void  REQ_WriteToNVRAM_TxPower5000M( void );
    void  CNF_WriteToNVRAM_TxPower5000M( void );

    void  (*ConfirmCallback)( void );




    // Public interface

    void  REQ_Stop( void );
    void  REQ_Read_TxPower2400M_From_NVRAM_Start( void );
    void  REQ_Write_TxPower2400M_To_NVRAM_Start( void );
    void  REQ_Read_TxPower5000M_From_NVRAM_Start( void );
    void  REQ_Write_TxPower5000M_To_NVRAM_Start( void );
    void  REQ_SetDbmToDac_Start( WiFi_DBM2DAC_Set_S dbm2dac_set );
    void  REQ_SetDbmToDac( void );
    // ini

    bool  WiFiTxPower2400MSectionExist( char *filename );
    bool  REQ_Read_TxPower2400M_From_File( char *filename );
    bool  REQ_Write_TxPower2400M_To_File( char *filename );
    bool  REQ_Read_TxPower5000M_From_File( char *filename );
    bool  REQ_Write_TxPower5000M_To_File( char *filename );

    // query
    void  REQ_QueryDbmToDac_Start( void );
    void  REQ_QueryDbmToDac( void );

    // Global information
    META_RESULT  Get_ConfirmState(void);
    unsigned char Get_TxPowerDac(E_WIFI_GENERATION e_802_11_idx, E_WIFI_MOD mod, unsigned int ch_idx );
    void          Set_TxPowerDac(E_WIFI_GENERATION e_802_11_idx, E_WIFI_MOD mod, unsigned int ch_idx, unsigned char dac );
    WiFi_TxPower_2400M_S Get_TxChannelDac2400M( void );
    void                 Set_TxChannelDac2400M( WiFi_TxPower_2400M_S &txpwr );
    WiFi_TxPower_5000M_S Get_TxChannelDac5000M( void );
    void                 Set_TxChannelDac5000M( WiFi_TxPower_5000M_S &txpwr );
    WiFi_DBM2DAC_Query_S  Get_DbmToDac( void );
    unsigned char         Get_TxPowerDac2400M( E_WIFI_MOD mod, unsigned int ch_idx );
    void                  Set_TxPowerDac2400M( E_WIFI_MOD mod, unsigned int ch_idx, unsigned char dac );
    unsigned char         Get_TxPowerDac5000M( unsigned int ch_idx );
    void                  Set_TxPowerDac5000M( unsigned int ch_idx, unsigned char dac );
};

/*---------------------------------------------------------------------------*/
#endif
