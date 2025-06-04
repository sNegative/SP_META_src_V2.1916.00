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
 *   wifi_ee.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   WiFi EEPROM header
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
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
#ifndef  _WIFI_EE_H_
#define  _WIFI_EE_H_

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

#ifndef  _WIFI_APC_H_
#include "wifi_apc.h"
#endif

/*---------------------------------------------------------------------------*/

// EEPROM address (word offset)
#define  WIFI_EE_ADDR_BB_CHIP_ID  0x00
#define  WIFI_EE_ADDR_RF_CHIP_ID  0x01
#define  WIFI_EE_ADDR_SN          0x02
#define  WIFI_EE_ADDR_MAC_ADDR    0x04
#define  WIFI_EE_ADDR_RESERVED0   0x07
#define  WIFI_EE_ADDR_TX_IQ       0x08
#define  WIFI_EE_ADDR_RESERVED1   0x09
#define  WIFI_EE_ADDR_RESERVED2   0x0A
#define  WIFI_EE_ADDR_CHECKSUM    0x0A
#define  WIFI_EE_ADDR_RESERVED3   0x0B
#define  WIFI_EE_ADDR_TXP_2_4_G   0x0C
#define  WIFI_EE_ADDR_TXP_5_G     0x1A

// EEPROM len (word length)
#define  WIFI_EE_LEN_BB_CHIP_ID    1
#define  WIFI_EE_LEN_RF_CHIP_ID    1
#define  WIFI_EE_LEN_SN            2
#define  WIFI_EE_LEN_MAC_ADDR      3
#define  WIFI_EE_LEN_RESERVED0     1
#define  WIFI_EE_LEN_TX_IQ         1
#define  WIFI_EE_LEN_RESERVED1     1
#define  WIFI_EE_LEN_RESERVED2     0.5
#define  WIFI_EE_LEN_CHECKSUM      0.5
#define  WIFI_EE_LEN_TXP_2_4_G    14
#define  WIFI_EE_LEN_TXP_5_G      17

typedef struct
{
    unsigned short       usBBChipID;
    unsigned short       usRFChipID;
    unsigned int         uiSN;
    WiFi_MacAddress_S    sMACAddr;
    unsigned short       usReserved0;
    WiFi_DAC_DC_Offset_S sTxDcOffset;
    unsigned short       usReserved1;
    unsigned char        ucReserved2;
    unsigned char        ucChecksum;
}  S_WIFI_EE_GENERAL;

typedef struct
{
    WiFi_EEPROM_S eeprom[WIFI_MAX_COUNT];
    unsigned int count;
} S_WIFI_EEPROM;
/*---------------------------------------------------------------------------*/

class  CWIFIEE
{
private:
    // common
    META_RESULT m_eConfirmState;
    CMETAHANDLE  m_META_HANDLE_Obj;

    bool  m_bHasMeasured;

    // EEPROM
    S_WIFI_EEPROM  m_sEE;
    S_WIFI_EE_GENERAL   m_sEEGeneral;
    WiFi_TxPower_2400M_S m_sTxChannelDac2400M;
    WiFi_TxPower_5000M_S m_sTxChannelDac5000M;

protected:
    void Confirm(META_RESULT confirm_state);

public:
    CWIFIEE(void);
    ~CWIFIEE();







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Public member
    void  (*ConfirmCallback)(void);




    void  REQ_Stop(void);

    // Register
    void  REQ_Read_From_EE_Start(S_WIFI_EEPROM eeprom);
    void  Read_From_EE(void);
    void  REQ_Write_To_EE_Start(S_WIFI_EEPROM eeprom);
    void  Write_To_EE( void );
    unsigned char Calculate_Checksum( S_WIFI_EE_GENERAL &ee_gnrl );

    // ini
    bool  REQ_Read_General_Info_From_File( char *filename );
    bool  REQ_Write_General_Info_To_File( char *filename );
    bool  REQ_Read_TX_DC_Offset_From_File( char *filename );
    bool  REQ_Write_TX_DC_Offset_To_File( char *filename );
    bool  REQ_Read_TxPower2400M_From_File( char *filename );
    bool  REQ_Write_TxPower2400M_To_File( char *filename );
    bool  REQ_Read_TxPower5000M_From_File( char *filename );
    bool  REQ_Write_TxPower5000M_To_File( char *filename );

    // global information
    META_RESULT Get_ConfirmState( void );
    S_WIFI_EEPROM   Get_EE( void );
    void            Set_EE( S_WIFI_EEPROM &eeprom );
    S_WIFI_EE_GENERAL Get_EEGeneral( void );
    void              Set_EEGeneral( S_WIFI_EE_GENERAL &ee_general );
    WiFi_DAC_DC_Offset_S Get_TxDcOffset( void );
    void                 Set_TxDcOffset( WiFi_DAC_DC_Offset_S tx_dc_offset );
    unsigned char Get_Checksum( void );
    void          Set_Checksum( unsigned char checksum );
    WiFi_TxPower_2400M_S Get_TxChannelDac2400M( void );
    void                 Set_TxChannelDac2400M( WiFi_TxPower_2400M_S &txpwr );
    WiFi_TxPower_5000M_S Get_TxChannelDac5000M( void );
    void                 Set_TxChannelDac5000M( WiFi_TxPower_5000M_S &txpwr );


};

/*---------------------------------------------------------------------------*/
#endif
