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
 *   wifi_bb.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi baseband header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _WIFI_BB_H_
#define  _WIFI_BB_H_

#include "meta.h"

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
/*---------------------------------------------------------------------------*/

#define  STATE_BB_OK          0
#define  STATE_BB_FAIL        1
#define  STATE_BB_TIMEOUT     2
#define  STATE_BB_STOP        3
#define  STATE_BB_SECTION_OK  4

#define WIFI_IPC_NUM        5   // Initialization and PHY-Configuration
#define WIFI_TX_NUM        10   // TX-related
#define WIFI_RX_NUM        15   // RX-related
#define WIFI_BBPC_NUM      74   // BBP Configuration
#define WIFI_BBCR_MAX_NUM  WIFI_BBPC_NUM

#define WIFI_MT5911_BBCR_ADDR_STEP 0x02
/*---------------------------------------------------------------------------*/
typedef enum
{
    WIFI_BBCR_IPC = 0,
    WIFI_BBCR_TX,
    WIFI_BBCR_RX,
    WIFI_BBCR_BBPC,
    WIFI_BBCR_TYPE_NUM
} E_WIFI_BBCR_TYPE;

typedef struct
{
    AnsiString name;
    bool checked;
    bool RO; // read only
    bool RC; // R/C
    unsigned int idx;
    unsigned int addr;
    unsigned char value;
} S_WIFI_BBCR_SETTING;


typedef struct
{
    WiFi_BBReg8_S bb_reg8[WIFI_MAX_COUNT];
    unsigned int  count;
} S_WiFi_BBCR;
/*---------------------------------------------------------------------------*/

class  CWIFIBB
{
private:
    int   m_iConfirmState;
    bool  m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    bool  m_bHasMeasured;
    S_WiFi_BBCR  m_sBBCR;
    // unsigned char   m_ucBBAddr;
    // unsigned char   m_ucBBValue;
    // unsigned char   m_ucBBAddrBegin;
    // unsigned char   m_ucBBAddrEnd;
    // unsigned char   m_ucBBAddrStep;
    S_WIFI_BBCR_SETTING  m_sBBCR_Setting[WIFI_BBCR_TYPE_NUM][WIFI_BBCR_MAX_NUM];

protected:


    void  Confirm( int confirm_state );

public:

    CWIFIBB( void );
    ~CWIFIBB();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Public member


    void  (*ConfirmCallback)( void );






    void  REQ_Stop(  );

    // Register
    // void  REQ_Read_From_Reg_Start( unsigned char bb_addr );
    // void  Read_From_Reg( void );
    // void  REQ_Write_To_Reg_Start( unsigned char bb_addr, unsigned char bb_value );
    // void  Write_To_Reg( void );
    // void  REQ_Read_From_AllReg_Start( unsigned char bb_addr_begin, unsigned char bb_addr_end, unsigned char bb_addr_step );
    // void  REQ_Read_From_AllReg( void );

    // query
    bool Query_ChannelList( unsigned int *channel_num, unsigned char *channel_id );

    // BBCR setting
    // resiger
    void  REQ_Read_BBCR_Setting_From_Reg_Start( S_WiFi_BBCR &bbcr );
    void  REQ_Read_BBCR_Setting_From_Reg( void );
    void  REQ_Write_BBCR_Setting_To_Reg_Start( S_WiFi_BBCR &bbcr );
    void  REQ_Write_BBCR_Setting_To_Reg( void );
    // INI file
    bool  REQ_Read_From_File( char *filename );
    bool  REQ_Write_To_File( char *filename );

    // global information
    int   Get_ConfirmState( void );
    S_WiFi_BBCR   Get_BBCR( void );
    unsigned int  Get_BBCR_Setting_Value( int type, int idx );
    void          Set_BBCR_Setting_Value( int type, int idx, unsigned int value );
    void Set_BBCR_Setting( int type, int idx, S_WIFI_BBCR_SETTING bbcr );
};

/*---------------------------------------------------------------------------*/
#endif
