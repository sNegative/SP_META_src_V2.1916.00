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
 *   bt_con.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT connection test header
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
#ifndef  _BT_CON_H_
#define  _BT_CON_H_


#include <vcl.h>
#include <vector.h>

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

#define  STATUS_BT_CT_OK         1
#define  STATUS_BT_CT_FAIL       0

#define  STR_BT_CT_SCO_SUCCESS         ((AnsiString)       "Success")
#define  STR_BT_CT_SCO_FAIL            ((AnsiString)       "Fail")

/*---------------------------------------------------------------------------*/
typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    TStrings    *list;
} S_BT_CT;





// inquiry/connect
//typedef enum
//{
//    CT_STATUS_CONNECT = 0,
//    CT_STATUS_DISCONNECT,
//}E_CT_STATUS;

typedef enum
{
    ACL_PKT_MASK_DM1 = 0x0008,
    ACL_PKT_MASK_DH1 = 0x0010,
    ACL_PKT_MASK_DM3 = 0x0400,
    ACL_PKT_MASK_DH3 = 0x0800,
    ACL_PKT_MASK_DM5 = 0x4000,
    ACL_PKT_MASK_DH5 = 0x8000,
    // BT 2.0
    ACL_PKT_MASK_2DH1 = 0x0002,
    ACL_PKT_MASK_3DH1 = 0x0004,
    ACL_PKT_MASK_2DH3 = 0x0100,
    ACL_PKT_MASK_3DH3 = 0x0200,
    ACL_PKT_MASK_2DH5 = 0x1000,
    ACL_PKT_MASK_3DH5 = 0x2000,
} E_ACL_PKT_MASK;

typedef enum
{
    SCO_PKT_IDX_HV1 = 0,
    SCO_PKT_IDX_HV2,
    SCO_PKT_IDX_HV3,
    SCO_PKT_IDX_EV3,
    SCO_PKT_IDX_EV4,
    SCO_PKT_IDX_EV5,
    SCO_PKT_NONEDR_IDX_COUNT,
    SCO_PKT_IDX_2EV3 = SCO_PKT_NONEDR_IDX_COUNT,
    SCO_PKT_IDX_3EV3,
    SCO_PKT_IDX_2EV5,
    SCO_PKT_IDX_3EV5,
    SCO_PKT_IDX_COUNT
} E_SCO_PKT_IDX;

typedef enum
{
    SCO_PKT_MASK_HV1  = 0x0001,
    SCO_PKT_MASK_HV2  = 0x0002,
    SCO_PKT_MASK_HV3  = 0x0004,
    SCO_PKT_MASK_EV3  = 0x0008,
    SCO_PKT_MASK_EV4  = 0x0010,
    SCO_PKT_MASK_EV5  = 0x0020,
    // BT 2.0
    SCO_PKT_MASK_2EV3 = 0x0380,
    SCO_PKT_MASK_3EV3 = 0x0340,
    SCO_PKT_MASK_2EV5 = 0x02C0,
    SCO_PKT_MASK_3EV5 = 0x01C0,

} E_SCO_PKT_MASK;


typedef struct
{
    S_BD_ADDR s_bd_addr;
    E_SCO_PKT_MASK e_pkt_type;
} S_BT_CT_CONNECT_SCO;

typedef struct
{
    S_BD_ADDR s_bd_addr;
} S_BT_CT_DISCONNECT_SCO;



typedef enum
{
    BT_CT_SCO_STATUS_SUCCESS=0x00,
    BT_CT_SCO_STATUS_FAIL=0xFE,
    BT_CT_SCO_STATUS_NONE=0xFF,
} E_BT_CT_SCO_STATUS;

typedef struct
{
    S_BD_ADDR s_bd_addr;
    S_BT_PIN  s_bt_pin;
} S_BT_ENTER_PIN;

typedef struct
{
    E_BT_ACL_STATUS e_acl_status;
    E_BT_CT_SCO_STATUS e_sco_status;
    unsigned char uc_h1_acl;
    unsigned char uc_h2_acl;
    unsigned char uc_h1_sco;
    unsigned char uc_h2_sco;
    S_BD_ADDR s_bd_addr;
} S_BT_CT_RES;


/*---------------------------------------------------------------------------*/
class CBTCT
{
private:
    META_RESULT m_eConfirmState;
    bool  m_bEventOk;
    bool  m_bEvent2Ok;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_BT_CT  m_sBTCT;
    S_BD_ADDRS m_sLocalBdAddr;
    unsigned int m_uiInquiryTimeout;
    unsigned int m_uiEventCount;
    S_BT_SCAN m_sScan;
    S_BT_CONNECT_ACL m_sConnectACL;
    S_BT_DISCONNECT_ACL m_sDisconnectACL;
    S_BT_ENTER_PIN   m_sEnterPIN;
    S_BT_CT_CONNECT_SCO m_sConnectSCO;
    S_BT_CT_DISCONNECT_SCO m_sDisconnectSCO;
    vector<S_BT_CT_RES> *m_pvCTRes;

protected:
    void  Confirm(META_RESULT confirm_state);

public:

    CBTCT(void);
    ~CBTCT();
    // memory
    void  AllocateVector(void);
    void  DeAllocateVector(void);
    void  EraseVector(void);

//   void  REQ_Stop_Start(void);
//   void  REQ_Stop(void);


    void  (*ConfirmCallback)(void);








    // reset
    void  REQ_Reset_Start(S_BT_CT bt_ct);
    void  REQ_SendResetHCICommand(void);
    void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);

    // read local BD address
    void  REQ_ReadLocalBDAddress_Start(S_BT_CT bt_ct);
    void  REQ_Send_Read_Local_BDAdrress_HCI_command(void);
    void  Compose_Read_Local_BD_Addr_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_Local_BD_Addr_HCI_Event(BT_HCI_EVENT hci_event, S_BD_ADDRS &bd_addr);
    void __stdcall CNF_ReadLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);

    // write local BD address
    void  REQ_WriteLocalBDAddress_Start(S_BT_CT bt_ct);
    void  REQ_Send_Write_Local_BDAdrress_HCI_command(void);
    void  __stdcall CNF_WriteLocalBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Write_Local_BD_Addr_HCI_Command(BT_HCI_COMMAND &hci_cmd, S_BD_ADDRS s_bd_addrs);
    bool  DeCompose_Write_Local_BD_Addr_HCI_Event(BT_HCI_EVENT hci_event);

    // auto accept
    void  REQ_Auto_Accept_Start( S_BT_CT bt_ct );
    void  REQ_Send_Auto_Accept_HCI_command( void );
    void __stdcall CNF_AutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Auto_Accept_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Auto_Accept_HCI_Event( BT_HCI_EVENT hci_event );


    // scan
    void  REQ_Scan_Start( S_BT_CT bt_ct );
    void  REQ_Send_Scan_HCI_command( void );
    void __stdcall CNF_ScanHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Inquiry_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan );
    void  Compose_Page_Scan_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan );
    void Compose_Scan_Enable_HCI_Command(BT_HCI_COMMAND &hci_cmd, S_BT_SCAN scan);
    bool DeCompose_Scan_HCI_Event(BT_HCI_EVENT hci_event);
    void REQ_Set_Inquiry_Scan_Interval_Start(S_BT_CT bt_ct);
    void REQ_Send_Inquiry_Scan_Interval_HCI_command(void);
    void __stdcall CNF_InquiryScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void Compose_Inquiry_Scan_Interval_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool DeCompose_Inquiry_Scan_Interval_HCI_Event(BT_HCI_EVENT hci_event);
    void REQ_Set_Page_Scan_Interval_Start(S_BT_CT bt_ct);
    void REQ_Send_Page_Scan_Interval_HCI_command(void);
    void __stdcall CNF_PageScanIntervalHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void Compose_Page_Scan_Interval_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool DeCompose_Page_Scan_Interval_HCI_Event(BT_HCI_EVENT hci_event);

    // inquiry
    void  REQ_Inquiry_Start( S_BT_CT bt_ct );
    void  REQ_Send_Inquiry_HCI_command( void );
    void   __stdcall CNF_InquiryHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Inquiry_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Inquiry_HCI_Event( BT_HCI_EVENT hci_event );
    void  AddBDAddressToDiscovedList( AnsiString as_bd_addr );

    // inquiry cancel
    void  REQ_Inquiry_Cancel_Start( S_BT_CT bt_ct );
    void  REQ_Send_Inquiry_Cancel_HCI_command( void );
    void   __stdcall CNF_InquiryCancelHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Inquiry_Cancel_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Inquiry_Cancel_HCI_Event( BT_HCI_EVENT hci_event );

    // connect
    void  REQ_ConnectACL_Start( S_BT_CT bt_ct );
    void  REQ_Send_ConnectACL_HCI_command( void );
    void __stdcall CNF_ConnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DisconnectACLAutoHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_ConnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_ConnectACL_HCI_Event( BT_HCI_EVENT hci_event );
    void  Compose_Link_Key_Negative_Reply_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_Link_Key_Negative_Reply_HCI_Event( BT_HCI_EVENT hci_event, S_BT_CONNECT_ACL connect );

    // change ACL packet type
    void  REQ_Change_ACL_Packet_Type_Start( S_BT_CT bt_ct );
    void  REQ_Send_Change_ACL_Packet_Type_HCI_command( void );
    void __stdcall CNF_ChangeACLPacketTypeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_Change_ACL_Packet_Type_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CONNECT_ACL connect );
    bool  DeCompose_Change_ACL_Packet_Type_HCI_Event( BT_HCI_EVENT hci_event );
    void __stdcall CNF_LinkKeyNegReplyHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);

    // enter PIN
    bool  REQ_EnterPIN_Start( S_BT_CT bt_ct );
    bool  REQ_Send_EnterPIN_HCI_command( void );
    void __stdcall CNF_EnterPINHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_EnterPIN_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_ENTER_PIN enter_pin );
    bool  DeCompose_EnterPIN_HCI_Event( BT_HCI_EVENT hci_event );

    // disconnect ACL
    void  REQ_DisconnectACL_Start( S_BT_CT bt_ct );
    void  REQ_Send_DisconnectACL_HCI_command( void );
    void __stdcall CNF_DisconnectACLHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_DisconnectACL_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_DISCONNECT_ACL disconnect );
    bool  DeCompose_DisconnectACL_HCI_Event( BT_HCI_EVENT hci_event, S_BT_DISCONNECT_ACL disconnect );

    // connect SCO
    void  REQ_ConnectSCO_Start( S_BT_CT bt_ct );
    void  REQ_Send_ConnectSCO_HCI_command( void );
    void __stdcall CNF_ConnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_ConnectSCO_HCI_Command( BT_HCI_COMMAND &hci_cmd, S_BT_CT_CONNECT_SCO connect );
    bool  DeCompose_ConnectSCO_HCI_Event( BT_HCI_EVENT hci_event, S_BT_CT_CONNECT_SCO connect );

    // disconnect SCO
    void  REQ_DisconnectSCO_Start(S_BT_CT bt_ct);
    void  REQ_Send_DisconnectSCO_HCI_command(void);
    void __stdcall CNF_DisconnectSCOHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_DisconnectSCO_HCI_Command(BT_HCI_COMMAND &hci_cmd, S_BT_CT_DISCONNECT_SCO disconnect);
    bool  DeCompose_DisconnectSCO_HCI_Event(BT_HCI_EVENT hci_event, S_BT_CT_DISCONNECT_SCO disconnect);
    // compose
    void  Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);

    // log
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event);

    // global information
    META_RESULT Get_ConfirmState(void);
    S_BD_ADDRS Get_LocalBdAddr(void);
    void Set_LocalBdAddr(S_BD_ADDRS bd_addr);
    void Set_InquiryTimeout(unsigned int timout);
    void Set_ScanParameter(S_BT_SCAN scan);
    void Set_EnterPINParameter(S_BT_ENTER_PIN enter_pin);
    void Set_ConnectACLParameter(S_BT_CONNECT_ACL connect);
    void Set_DisconnectACLParameter(S_BT_DISCONNECT_ACL disconnect);
    void Set_ConnectSCOParameter(S_BT_CT_CONNECT_SCO connect);
    void Set_DisconnectSCOParameter(S_BT_CT_DISCONNECT_SCO disconnect);
    vector<S_BT_CT_RES>*  Get_CtResVector(void);
};

/*---------------------------------------------------------------------------*/
#endif