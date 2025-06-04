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
 *   bt_rf.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT RF test header
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
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
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
#ifndef  _BT_RF_H_
#define  _BT_RF_H_

#include <vcl.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

/*---------------------------------------------------------------------------*/
typedef enum
{
    BT_TX=0,
    BT_RX
} BT_RF_TEST_TYPE;

typedef enum
{
    BT_TX_ALL_ZEROS=0x01,
    BT_TX_ALL_ONES,
    BT_TX_ALTER_BITS,
    BT_TX_PSEUDO_RANDOM,
    BT_TX_LOOPBACK_ACL_WITH_WHITENING,
    BT_TX_LOOPBACK_SCO_WITH_WHITENING,
    BT_RX_TEST,
    // BT_TX_LOOPBACK_ACL_WITHOUT_WHITENING,
    BT_TX_LOOPBACK_SCO_WITHOUT_WHITENING,
    BT_TX_ONES_ZEROS,
} E_BT_TX_PATTERN;

typedef enum
{
    BT_FREQ_SINGLE=0,
    BT_FREQ_HOPPING
} E_BT_FREQ_TYPE;

typedef enum
{
    BT_RF_TX_NULL_IDX = 0,
    BT_RF_TX_POLL_IDX,
    BT_RF_TX_FHS_IDX,
    BT_RF_TX_DM1_IDX,
    BT_RF_TX_DH1_IDX,
    BT_RF_TX_HV1_IDX,
    BT_RF_TX_HV2_IDX,
    BT_RF_TX_HV3_IDX,
    BT_RF_TX_DV_IDX,
    BT_RF_TX_AUX_IDX,
    BT_RF_TX_DM3_IDX,
    BT_RF_TX_DH3_IDX,
    BT_RF_TX_DM5_IDX,
    BT_RF_TX_DH5_IDX,
    BT_RF_TX_EV3_IDX,
    BT_RF_TX_EV4_IDX,
    BT_RF_TX_EV5_IDX,
    BT_RF_TX_NONEDR_IDX_COUNT,

    // BT 2.0
    BT_RF_TX_2DH1_IDX = BT_RF_TX_NONEDR_IDX_COUNT,
    BT_RF_TX_2EV3_IDX,
    BT_RF_TX_2DH3_IDX,
    BT_RF_TX_2EV5_IDX,
    BT_RF_TX_2DH5_IDX,
    BT_RF_TX_3EV3_IDX,
    BT_RF_TX_3DH1_IDX,
    BT_RF_TX_3DH3_IDX,
    BT_RF_TX_3EV5_IDX,
    BT_RF_TX_3DH5_IDX,
    BT_RF_TX_NON_MODULED_IDX,
    BT_RF_TX_IDX_COUNT
} E_BT_RF_TX_IDX_T;

typedef enum
{
    BT_RF_PACKET_NULL=0x00,
    BT_RF_PACKET_POLL=0x01,
    BT_RF_PACKET_FHS=0x02,
    BT_RF_PACKET_DM1=0x03,
    BT_RF_PACKET_DH1=0x04,
    BT_RF_PACKET_HV1=0x05,
    BT_RF_PACKET_HV2=0x06,
    BT_RF_PACKET_HV3=0x07,
    BT_RF_PACKET_DV=0x08,
    BT_RF_PACKET_AUX=0x09,
    BT_RF_PACKET_DM3=0x0A,
    BT_RF_PACKET_DH3=0x0B,
    BT_RF_PACKET_DM5=0x0E,
    BT_RF_PACKET_DH5=0x0F,
    BT_RF_PACKET_EV3=0x17,
    BT_RF_PACKET_EV4=0x1C,
    BT_RF_PACKET_EV5=0x1D,
    BT_RF_PACKET_BURST_RX=0x20,
    BT_RF_PACKET_CONT_RX=0x21,
    // BT 2.0
    BT_RF_PACKET_2DH1=0x24,
    BT_RF_PACKET_2EV3=0x36,
    BT_RF_PACKET_2DH3=0x2A,
    BT_RF_PACKET_2EV5=0x3C,
    BT_RF_PACKET_2DH5=0x2E,
    BT_RF_PACKET_3EV3=0x37,
    BT_RF_PACKET_3DH1=0x28,
    BT_RF_PACKET_3DH3=0x2B,
    BT_RF_PACKET_3EV5=0x3D,
    BT_RF_PACKET_3DH5=0x2F,
//rongguo 2011-11-01
    BT_RF_PACKET_NON_MODULED
} E_BT_TX_PACKET_TYPE;

typedef enum
{
    BT_TX_WHITEN_OFF=0,
    BT_TX_WHITEN_ON
} E_TX_WHITEN;

typedef enum
{
    BT_TX_MODULATION_OFF=0,
    BT_TX_MODULATION_ON
} E_TX_MODULATION;

typedef enum
{
    BT_TX_POWER_CTRL_ON=0,
    BT_TX_POWER_CTRL_OFF
} E_BT_TX_POWER_CTRL;

typedef struct
{
    unsigned char uc_access_code[8];
} S_BT_TX_ACCESS_CODE;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    BT_RF_TEST_TYPE     e_test_type;
    E_BT_TX_PATTERN     e_pattern;
    E_BT_FREQ_TYPE      e_freq_type;
    unsigned char       uc_freq;
    // unsigned char       uc_rx_freq;
    E_BT_TX_PACKET_TYPE e_packet_type;
    unsigned short       us_data_len;
    unsigned char       uc_poll_period;
    E_TX_WHITEN         e_whiten;
    E_TX_MODULATION     e_modulation;
    E_BT_TX_POWER_CTRL  e_power_ctrl;
    unsigned char       uc_pcl;
    // unsigned int        ui_lap;
    // S_BD_ADDRS  s_BDAddr;
    S_BT_TX_ACCESS_CODE s_access_code;
    bool b_enable_access_code;
} S_BT_RF;

typedef enum
{
    BT_RX_CONT_RX=0,
    BT_RX_BURST_RX
} E_BT_RX_TYPE;

typedef struct
{
    E_BT_FREQ_TYPE      e_freq_type;
    unsigned char       uc_freq;
    E_BT_RX_TYPE        e_rx_type;
} S_BT_RF_RX;

/*---------------------------------------------------------------------------*/

class  CBTRF
{
private:
    META_RESULT m_eConfirmState;
    int m_iConfirmState;        // just for HWT
    bool  m_bEventOk;
    CMETAHANDLE m_META_HANDLE_Obj;

    S_BT_RF  m_sBtRf;
    S_BD_ADDR m_sBdAddr;
    // BT_HCI_COMMAND  m_sHciCmd;
protected:
    void  Confirm(META_RESULT confirm_state);

public:

    CBTRF( void );
    ~CBTRF();

    void  REQ_Stop_Start( void );
    void  REQ_Finish( void );
    void  REQ_TimeOut( void );







    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Public member


    void  (*ConfirmCallback)( void );





    void  REQ_Start( S_BT_RF  bt_rf, bool reset = false );
    void  REQ_Stop( void );

    //just for HW test
    void REQ_BT_HWT(void);

    // send HCI command
    void  REQ_Enter_Test_Mode_Start( S_BT_RF  bt_rf );
    void  REQ_Enter_Test_Mode1( void );
    void  REQ_Enter_Test_Mode2( void );
    void  REQ_Enter_Test_Mode3( void );
    void  REQ_Send_Whiten_HCI_command( void );
    // void  REQ_Send_Modulation_HCI_command( void );
    void  REQ_Send_AccessCode_HCI_command( void );
    void  REQ_Send_TxParameter_HCI_command( void );
    void  REQ_Send_RxParameter_HCI_command( void );
    void  REQ_SendResetHCICommand( void );
    void  REQ_QueryBDAddress_Start( S_BT_RF  bt_rf );
    void  REQ_Send_Read_BDAdrress_HCI_command( void );
    void  REQ_ChangePCL_Start( S_BT_RF  bt_rf );
    void  REQ_ChangePCL( void );

    // compose/decompose HCI command
    void  Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Enter_Test_Mode1_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Enter_Test_Mode2_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Enter_Test_Mode3_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Whiten_HCI_Command( E_TX_WHITEN *whiten, BT_HCI_COMMAND *hci_cmd );
    void  DeCompose_Whiten_HCI_Event( BT_HCI_COMMAND &hci_cmd, E_TX_WHITEN &whiten );
    void  Compose_Modulation_HCI_Command( E_TX_MODULATION &modulation, BT_HCI_COMMAND &hci_cmd );
    void  DeCompose_Modulation_HCI_Event( BT_HCI_COMMAND &hci_cmd, E_TX_MODULATION &modulation );
    void  Compose_AccessCode_HCI_Command( S_BT_TX_ACCESS_CODE &access_code, BT_HCI_COMMAND &hci_cmd );
    void  DeCompose_AccessCode_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_TX_ACCESS_CODE &access_code );
    void  Compose_TxParameter_HCI_command( S_BT_RF bt_rf_tx, BT_HCI_COMMAND &hci_cmd );
    void  DeCompose_TxParameter_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_RF bt_rf_tx );
    void  Compose_RxParameter_HCI_command( S_BT_RF bt_rf_rx, BT_HCI_COMMAND &hci_cmd );
    void  DeCompose_RxParameter_HCI_Event( BT_HCI_COMMAND &hci_cmd, S_BT_RF bt_rf_rx );
    void  Compose_Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Read_BD_Addr_HCI_Command1( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Read_BD_Addr_HCI_Command2( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Read_BD_Addr_HCI_Event2(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr);
    void  Compose_ChangePCL_HCI_Command( BT_HCI_COMMAND &hci_cmd );
//rongguo 2011-11-01
    void  Compose_Tx_Nonmoduled_HCI_command( S_BT_RF bt_rf_tx, BT_HCI_COMMAND &hci_cmd );

    // callback
    void __stdcall CNF_EnterTestMode1HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_EnterTestMode2HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_EnterTestMode3HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendWhitenHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendModulationHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendAccessCodeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DUTSendReadBDAddressHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DUTSendReadBDAddressHCIEvent2(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendReadBDAddressHCIEvent1(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendReadBDAddressHCIEvent2(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ChangePCLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);

    // log
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event);

    // global information
    META_RESULT Get_ConfirmState(void);
    S_BD_ADDR Get_BdAddress( void );


};

/*---------------------------------------------------------------------------*/
#endif