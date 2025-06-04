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
 *   wifi_alc.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi ALC header
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
#ifndef  _WIFI_ALC_H_
#define  _WIFI_ALC_H_

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

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif


/*---------------------------------------------------------------------------*/
class CWIFIALC
{
private:
    // common
    META_RESULT   m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    unsigned int m_uiAlcPowerBufSize2400M;
    char        *m_cAlcPowerBuf2400M;
    unsigned int m_uiAlcSlopeBufSize2400M;
    char        *m_cAlcSlopeBuf2400M;
    WiFi_ALC_2400M_S m_sAlcPower2400M;
    WiFi_TxALC_2400M_S m_sAlcSlope2400M;

protected:
public:
    void  Confirm(META_RESULT confirm_state);

    CWIFIALC(void);
    ~CWIFIALC();

    void  REQ_Finish(void);
    void  REQ_TimeOut(void);
    void  REQ_Stop(void);
    void  REQ_ReadAlcPowerFromNVRAM(void);
    void  CNF_ReadAlcPowerFromNVRAM(void);
    void  REQ_WriteAlcPowerToNVRAM(void);
    void  CNF_WriteAlcPowerToNVRAM(void);
    void  REQ_ReadAlcSlopeFromNVRAM(void);
    void  CNF_ReadAlcSlopeFromNVRAM(void);
    void  REQ_WriteAlcSlopeToNVRAM(void);
    void  CNF_WriteAlcSlopeToNVRAM(void);
    void  (*ConfirmCallback)(void);




    // Public interface


    void  REQ_Read_From_NVRAM_Start(void);
    void  REQ_Write_To_NVRAM_Start(void);

    // ini
    bool  WiFiAlc2400MSectionExist(char *filename);
    bool  REQ_Read_From_File(char *filename);
    bool  REQ_Write_To_File(char *filename);


    // query
    bool  REQ_Query_ALC_Suppport_Start(void);

    // Global information
    META_RESULT Get_ConfirmState(void);
    WiFi_ALC_2400M_S* Get_AlcPower2400M(void);
    void                 Set_AlcPower2400M(WiFi_ALC_2400M_S alc);
    unsigned char Get_AlcPower2400MAlc(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate);
    void Set_AlcPower2400MAlc(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate, unsigned char alc);
    unsigned char Get_AlcPower2400MPowerDB(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate);
    void Set_AlcPower2400MPowerDB(E_WIFI_MOD mod, unsigned int ch_idx, WiFi_TestRate_E rate, unsigned char db);
    WiFi_TxALC_2400M_S* Get_AlcSlope2400M(void);
    void Set_AlcSlope2400M(WiFi_TxALC_2400M_S alc_slope);
};

/*---------------------------------------------------------------------------*/
#endif
