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
 *   wifi_mac.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi MAC header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _WIFI_MAC_H_
#define  _WIFI_MAC_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

/*---------------------------------------------------------------------------*/

#define  STATE_MAC_OK          0
#define  STATE_MAC_FAIL        1
#define  STATE_MAC_TIMEOUT     2
#define  STATE_MAC_STOP        3
#define  STATE_MAC_SECTION_OK  4

// MCR
#define WIFI_SC_NUM         4   // System Control
#define WIFI_MDP_NUM       18   // Miscellaneous and Debug Port
#define WIFI_PLCI_NUM      12   // Physical Layer Control Interface
#define WIFI_MPTC_NUM      18   // MAC Protocol Timing Control
#define WIFI_NC_NUM         4   // NVA Control
#define WIFI_BG_NUM         8   // Beacon Generation
#define WIFI_SE_NUM        11   // Security Engine
#define WIFI_TC_NUM        12   // Transmitter Control
#define WIFI_RC_NUM        15   // Receiver Control
#define WIFI_HIF_SDIO_NUM   7   // HIF_SDIO
#define WIFI_HIF_SPI_NUM    6   // HIF_SPI
#define WIFI_MCR_MAX_NUM   WIFI_MPTC_NUM

#define WIFI_HIF_SDIO_SPECIFIC_NUM  2
#define WIFI_HIF_SDIO_PORT_NUM      5
#define WIFI_HIF_SPI_SPECIFIC_NUM   2
#define WIFI_HIF_SPI_PORT_NUM       4

// MCR16
#define WIFI_HIF_HPI_SPECIFIC_NUM   4
#define WIFI_HIF_HPI_PORT_NUM       4
#define WIFI_HIF_HPI_NUM            8   // HIF_HPI
#define WIFI_HIF_MAX_NUM            WIFI_HIF_HPI_NUM
#define WIFI_MCR16_MAX_NUM          WIFI_HIF_HPI_NUM


/*---------------------------------------------------------------------------*/
typedef enum
{
    WIFI_MCR_SC = 0,
    WIFI_MCR_MDP,
    WIFI_MCR_PLCI,
    WIFI_MCR_MPTC,
    WIFI_MCR_NC,
    WIFI_MCR_BG,
    WIFI_MCR_SE,
    WIFI_MCR_TC,
    WIFI_MCR_RC,
    WIFI_MCR_HIF_SDIO,
    WIFI_MCR_HIF_SPI,
    WIFI_MCR_TYPE_NUM
} E_WIFI_MCR_TYPE;

typedef enum
{
    WIFI_MCR16_HIF_HPI=0,
    WIFI_MCR16_TYPE_NUM
} E_WIFI_MCR16_TYPE;

typedef struct
{
    AnsiString name;
    bool checked;
    bool RO; // read only
    bool RC; // R/C
    unsigned int addr;
    unsigned int value;
} S_WIFI_MCR_SETTING;

typedef struct
{
    AnsiString name;
    bool checked;
    bool RO; // read only
    bool RC; // R/C
    unsigned int addr;
    unsigned short value;
} S_WIFI_MCR16_SETTING;

typedef enum
{
    WIFI_HIF_SDIO_SPECIFIC = 0,
    WIFI_HIF_SDIO_PORT0,
    WIFI_HIF_SDIO_PORT1,
    WIFI_HIF_SDIO_PORT2,
    WIFI_HIF_SDIO_PORT3,
    WIFI_HIF_SDIO_PORT4
} E_WIFI_HIF_SDIO;

typedef enum
{
    WIFI_HIF_HPI_SPECIFIC = 0,
    WIFI_HIF_HPI_PORT
} E_WIFI_HIF_HPI;

typedef enum
{
    WIFI_HIF_SPI_SPECIFIC = 0,
    WIFI_HIF_SPI_PORT0,
    WIFI_HIF_SPI_PORT1,
    WIFI_HIF_SPI_PORT2,
    WIFI_HIF_SPI_PORT3,
} E_WIFI_HIF_SPI;

typedef struct
{
    WiFi_MACReg32_S mac_reg32[512];
    unsigned int count;
} S_WiFi_MCR;

typedef struct
{
    WiFi_MACReg16_S mac_reg16[WIFI_MAX_COUNT];
    unsigned int count;
} S_WiFi_MCR16;
/*---------------------------------------------------------------------------*/
class  CWIFIMAC
{
private:
    // common
    int   m_iConfirmState;
    bool  m_bIsRunning;
    CMETAHANDLE m_META_HANDLE_Obj;

    bool  m_bHasMeasured;
    char             *m_pcMacAddrBuf;
    int               m_iMacAddrBufSize;
    WiFi_MacAddress_S  m_mac_addr;
    S_WiFi_MCR        m_sMCR;
    S_WiFi_MCR16      m_sMCR16;
    //unsigned int m_uiMacAddr;
    //unsigned int m_uiMacAddrBegin;
    //unsigned int m_uiMacAddrEnd;
    //unsigned int m_uiMacAddrStep;
    //unsigned int m_uiMacData;
    S_WIFI_MCR_SETTING  m_sMCR_Setting[WIFI_MCR_TYPE_NUM][WIFI_MCR_MAX_NUM];
    S_WIFI_MCR16_SETTING  m_sMCR16_Setting[WIFI_MCR16_TYPE_NUM][WIFI_MCR16_MAX_NUM];

protected:
    void  Confirm( int confirm_state );

public:

    CWIFIMAC( void );
    ~CWIFIMAC();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Public member


    void  (*ConfirmCallback)( void );






    void  REQ_Stop(  );


    // NVRAM
    bool  Decompose_MacAddress( void );
    bool  Compose_MacAddress( void );
    void  REQ_Read_From_NVRAM( void );
    void  CNF_ReadFromNVRAM( void );
    void  REQ_Write_To_NVRAM( void );
    void  CNF_WriteToNVRAM( void );

    // MCR setting
    // resiger
    void  REQ_Read_MCR_Setting_From_Reg_Start( S_WiFi_MCR &mcr );
    void  REQ_Read_MCR_Setting_From_Reg( void );
    void  REQ_Write_MCR_Setting_To_Reg_Start( S_WiFi_MCR &mcr );
    void  REQ_Write_MCR_Setting_To_Reg( void );
    void  REQ_Read_MCR16_Setting_From_Reg_Start( S_WiFi_MCR16 &mcr16 );
    void  REQ_Read_MCR16_Setting_From_Reg( void );
    void  REQ_Write_MCR16_Setting_To_Reg_Start( S_WiFi_MCR16 &mcr16 );
    void  REQ_Write_MCR16_Setting_To_Reg( void );

    // INI file
    bool  REQ_Read_From_File( char *filename, WiFi_HostInterface_E host_inf );
    bool  REQ_Write_To_File( char *filename, WiFi_HostInterface_E host_inf );

    // global information
    int   Get_ConfirmState( void );
    unsigned int   Get_MCR_Setting_Value( int type, int idx );
    void           Set_MCR_Setting_Value( int type, int idx, unsigned int value );
    unsigned short Get_MCR16_Setting_Value( int type, int idx );
    void           Set_MCR16_Setting_Value( int type, int idx, unsigned short value );
    void           Set_MCR_Setting( int type, int idx, S_WIFI_MCR_SETTING mcr );
    void           Set_MCR16_Setting( int type, int idx, S_WIFI_MCR16_SETTING mcr16 );
    S_WiFi_MCR     Get_MCR( void );
    void           Set_MCR( S_WiFi_MCR &mcr );
    S_WiFi_MCR16   Get_MCR16( void );
    void           Set_MCR16( S_WiFi_MCR16 &mcr16 );

};

/*---------------------------------------------------------------------------*/
#endif