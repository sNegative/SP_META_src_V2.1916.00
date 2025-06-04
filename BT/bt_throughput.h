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
 *   bt_throughput.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT throughput test header
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
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
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
#ifndef  _BT_THROUGHPUT_H_
#define  _BT_THROUGHPUT_H_


#include <vcl.h>

// common
#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

/*---------------------------------------------------------------------------*/
typedef enum
{
    BT_TT_VER_0,
    BT_TT_VER_1,
    BT_TT_VER_2,
} E_BT_TT_VER_T;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
} S_BT_TT;

typedef struct
{
    E_BT_ACL_STATUS e_acl_status;
    unsigned char uc_h1_acl;
    unsigned char uc_h2_acl;
    S_BD_ADDR s_bd_addr;
} S_BT_TT_RES;

typedef struct
{
    unsigned short us_data_len;
    unsigned short us_packet_count;
} S_BT_TT_TX_PARAMETER;


typedef struct
{
    unsigned int ui_tx_pkt_length;
    unsigned int ui_used_time;
} S_BT_TT_MONITOR_TX_CNF;

typedef struct
{
    unsigned int ui_rx_pkt_length;
    unsigned int ui_used_time;
} S_BT_TT_MONITOR_RX_CNF;




/*---------------------------------------------------------------------------*/

class  CBTTT
{
private:
    // common
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_BT_SCAN m_sScan;
    S_BT_CONNECT_ACL m_sConnectACL;
    S_BT_DISCONNECT_ACL m_sDisconnectACL;
    int  m_iEventCount;
    bool  m_bEventOk;
    bool  m_bEvent2Ok;
    S_BT_TT  m_sBTTT;
    S_BT_TT_TX_PARAMETER  m_sBTTxPar;
    S_BT_TT_RES  m_sBTTTRes;
    S_BT_TT_MONITOR_RX_CNF m_sBTRxCnf;
    S_BT_TT_MONITOR_TX_CNF m_sBTTxCnf;
    E_BT_TT_VER_T m_eTtVer;

protected:
    void  Confirm(META_RESULT confirm_state );

public:

    CBTTT( void );
    ~CBTTT();
    void  (*ConfirmCallback)( void );
    void  REQ_Stop_Start( void );
    void  REQ_Stop( void );
    void  REQ_Finish( void );
    void  REQ_TimeOut( void );

    // auto accept
    void  REQ_Auto_Accept_Start( S_BT_TT bt_tt );
    void  REQ_Send_Auto_Accept_HCI_command( void );
    void __stdcall CNF_ConnectACLAutoHCIEvent(const BT_HCI_EVENT *hci_event, const short token, void *usrData);
    void __stdcall CNF_AutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Auto_Accept_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Auto_Accept_HCI_Event( BT_HCI_EVENT hci_event );


    // scan
    void  REQ_Scan_Start( S_BT_TT bt_tt );
    void  REQ_Send_Scan_HCI_command( void );
    void __stdcall CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Inquiry_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan );
    void  Compose_Page_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan );
    void  Compose_Scan_Enable_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan );
    bool  DeCompose_Scan_HCI_Event( BT_HCI_EVENT hci_event );


    // connect
    void  REQ_ConnectACL_Start( S_BT_TT bt_tt );
    void  REQ_Send_ConnectACL_HCI_command( void );
    void __stdcall CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_ConnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_ConnectACL_HCI_Event( BT_HCI_EVENT hci_event );
    void  Compose_Link_Key_Negative_Reply_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_Link_Key_Negative_Reply_HCI_Event( BT_HCI_EVENT hci_event, S_BT_CONNECT_ACL connect );

    // change ACL packet type
    void  REQ_Change_ACL_Packet_Type_Start( S_BT_TT bt_tt );
    void  REQ_Send_Change_ACL_Packet_Type_HCI_command( void );
    void __stdcall CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Change_ACL_Packet_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_Change_ACL_Packet_Type_HCI_Event( BT_HCI_EVENT hci_event );
    void __stdcall CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);

    // disconnect ACL
    void  REQ_DisconnectACL_Start( S_BT_TT bt_tt );
    void  REQ_Send_DisconnectACL_HCI_command( void );
    void __stdcall CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_DisconnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_DISCONNECT_ACL disconnect );
    bool  DeCompose_DisconnectACL_HCI_Event( BT_HCI_EVENT hci_event, S_BT_DISCONNECT_ACL disconnect );

    // TX data
    void  REQ_TX_Data_Start(E_BT_TT_VER_T ver, S_BT_TT bt_tt);
    void  REQ_TX_Data(void);
    void __stdcall CNF_TX_Data_V0(const BT_HCI_PACKET *cnf, const short token, void *usrData);
    void __stdcall CNF_TX_Data_V1(const BT_HCI_TX_PURE_TEST_STAT *cnf, const short token, void *usrData);
    void __stdcall CNF_TX_Data_V2(const BT_HCI_TX_PURE_TEST_STAT_V2 *cnf, const short token, void *usrData);

    // RX data
    void  REQ_RX_Data_Start(E_BT_TT_VER_T ver, S_BT_TT bt_tt);
    void  REQ_RX_Data(void);
    void __stdcall CNF_RX_Data_V0(const BT_HCI_BUFFER *cnf, const short token, void *usrData);
    void __stdcall CNF_RX_Data_V2(const BT_HCI_RX_PURE_TEST_STAT *cnf, const short token, void *usrData);
    void  REQ_Stop_RX_Data_Start(S_BT_TT bt_tt);
    void  REQ_Stop_RX_Data(void);

    // compose
    void  Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );

    // log
    void  AddTxLogToStringList( BT_HCI_COMMAND hci_cmd  );
    void  AddRxLogToStringList( BT_HCI_EVENT hci_event );

    // query
    E_BT_TT_VER_T Query_TtTestVersion(void);

    // export information
    META_RESULT Get_ConfirmState(void);
    void  Set_ScanParameter( S_BT_SCAN scan );
    void  Set_ConnectACLParameter( S_BT_CONNECT_ACL connect );
    void  Set_DisconnectACLParameter( S_BT_DISCONNECT_ACL disconnect );
    void  Set_TxParameter( S_BT_TT_TX_PARAMETER  par);
    S_BT_TT_RES Get_TTResult( void );
    E_BT_TT_VER_T  Get_TtTestVer(void);


};

/*---------------------------------------------------------------------------*/
#endif