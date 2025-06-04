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
 *   wifi_txdc.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi TX DC offset header
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
#ifndef  _WIFI_TXDC_H_
#define  _WIFI_TXDC_H_
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

/*---------------------------------------------------------------------------*/
class  CWIFITXDC
{
private:

    // common
    META_RESULT   m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    bool  m_bDownloadTrigger;
    WiFi_DAC_DC_Offset_S m_sTxDcOffset;
    unsigned int m_uiTxDcOffsetBufSize;
    char *m_cpTxDcOffsetBuf;

protected:
public:

    void  Confirm(META_RESULT confirm_state);


    CWIFITXDC(void);
    ~CWIFITXDC();

    void  REQ_Finish(void);
    void  REQ_TimeOut(void);
    void  REQ_Stop(void);
    void  (*ConfirmCallback)(void);

    // NVRAM
    void  REQ_ReadFromNVRAM(void);
    void  CNF_ReadFromNVRAM(void);
    void  REQ_WriteToNVRAM(void);
    void  CNF_WriteToNVRAM(void);


    //------------------------------------------------------------------
    // Public interface


    // TX DC offset calibration
    void  REQ_TxDcOffsetCal_Start(void);
    void  REQ_TxDcOffsetCal(void);

    // NVRAM
    void  REQ_Read_From_NVRAM_Start(void);
    void  REQ_Write_To_NVRAM_Start(void);

    // ini
    bool  WiFiTxDcOffsetSectionExist(char *filename);
    bool  REQ_Read_From_File(char *filename);
    bool  REQ_Write_To_File(char *filename);




    // Global information
    META_RESULT Get_ConfirmState(void);
    WiFi_DAC_DC_Offset_S Get_TxDcOffset(void);
    void Set_TxDcOffset(WiFi_DAC_DC_Offset_S tx_dc_offset);

};

/*---------------------------------------------------------------------------*/
#endif
