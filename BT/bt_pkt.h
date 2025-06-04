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
 *   bt_pkt.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT packet test header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_PKT_H_
#define  _BT_PKT_H_


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

#ifndef  _BT_PKT_COMMON_H_
#include "bt_pkt_common.h"
#endif

#ifndef  _BT_HCI_FT_H_
#include "bt_hci_ft.h"
#endif

/*---------------------------------------------------------------------------*/
typedef enum
{
    BT_PACKET_TESTER=0,
    BT_PACKET_DUT
} E_BT_PACKET_DEVICE_T;


typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    S_BD_ADDR s_tester_bd_addr;
    S_BD_ADDR s_dut_bd_addr;

    // E_BT_ACL_P1 e_p1;
    // E_BT_ACL_P1 e_p2;
    // E_BT_SCO    e_sco;
    unsigned char uc_h1;
    unsigned char uc_h2;

} S_BT_PKT;

/*---------------------------------------------------------------------------*/
class  CBTPKT
{
private:
    // common
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    CBTHCIFT m_cBT_HCI_FT_Obj;
    E_BT_PACKET_DEVICE_T m_sPktDevice;
    int  m_iEventCount;
    bool  m_bEventOk;
    bool  m_bTeserAct;
    bool  m_bStop;
    S_BT_PKT  m_sBTPKT;
    S_BT_PKT_TCI m_sBTTCI;
    // S_BT_PKT_MONITOR_REQ m_sBTMonReq;
    S_BT_PKT_MONITOR_CNF m_sBTMonCnf;
    // BT_HCI_COMMAND  m_sHciCmd;

protected:
    void  Confirm(META_RESULT confirm_state);

    META_RESULT REQ_ResetBD(E_BT_PACKET_DEVICE_T device);
    META_RESULT REQ_Read_BDAdrress(E_BT_PACKET_DEVICE_T device);
    META_RESULT REQ_DUT_Enter_Test_mode(void);
    META_RESULT REQ_DUT_Scan_Enable(void);
    META_RESULT REQ_DUT_Auto_Accept(void);
    META_RESULT REQ_Tester_Create_Connection(void);
    META_RESULT REQ_Tester_TCI_Activate_Remote_DUT(void);
    META_RESULT REQ_Read_Device_TX_RX_Count(E_BT_PACKET_DEVICE_T device);
    META_RESULT REQ_Read_Device_EDR_TX_RX_Count(E_BT_PACKET_DEVICE_T device);


public:

    CBTPKT(void);
    ~CBTPKT();
    void (*ConfirmCallback)(void);
    void REQ_Pkt_Test(void);
    void REQ_Tester_TCI_Control_Remote_DUT(void);
    void REQ_Read_TX_RX_Count(void);
    void REQ_Read_EDR_TX_RX_Count(void);
    void REQ_Stop(void);

    // public interface
    void REQ_Start(S_BT_PKT &bt_pkt);
    void REQ_TCI_Control_Remote_DUT_Start(S_BT_PKT_TCI tci);
    void REQ_Read_TX_RX_Count_Start(void);
    void REQ_Read_EDR_TX_RX_Count_Start(void);
    void REQ_Stop_Start(void);




// callback
    void __stdcall CNF_ResetBDHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ReadBDAddressHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DUTEnterTestModeHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DUTScanEnableHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_DUTAutoAcceptHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_TesterCreateConnectionHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_TesterTCIActivateRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_TesterTCIControlRemoteDUTHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ReadDeviceTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ReadDeviceEDRTxRxCountHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);


#if 0
    // ----------------------   HCI command    -----------------------------
    void  Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    // read BD address
    void  Compose_Read_BD_Addr_HCI_Command1(BT_HCI_COMMAND &hci_cmd);
    void  Compose_Read_BD_Addr_HCI_Command2(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_BD_Addr_HCI_Event2(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr);
    // enter test mode
    void  Compose_Enter_Test_Mode_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Enter_Test_Mode_HCI_Event(BT_HCI_EVENT hci_event);
    // scan enable
    void  Compose_Scan_Enable_HCI_Command(BT_HCI_COMMAND &hci_cmd);
//   void  Compose_Scan_Enable_HCI_Command2( BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_Scan_Enable_HCI_Event(BT_HCI_EVENT hci_event);
    void  Compose_Auto_Accept_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Auto_Accept_HCI_Event(BT_HCI_EVENT hci_event);
//   bool  DeCompose_Scan_Enable_HCI_Event2( BT_HCI_EVENT &hci_event );
    // ACL connect
    void  Compose_ACL_Connect_HCI_Command(S_BD_ADDR &bd_addr, BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_ACL_Connect_HCI_Event1(BT_HCI_EVENT hci_event);
    bool  DeCompose_ACL_Connect_HCI_Event2(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr, unsigned char &h1, unsigned char &h2 );
    bool  DeCompose_ACL_Connect_HCI_Event3(BT_HCI_EVENT hci_event, unsigned char &h1, unsigned char &h2 );
    bool  DeCompose_ACL_Connect_HCI_Event4(BT_HCI_EVENT hci_event, unsigned char &h1, unsigned char &h2 );
    // enable SCO connect
    // void  Compose_Enable_SCO_Connect_HCI_Command1( BT_HCI_COMMAND &hci_cmd );
    // bool  DeCompose_Enable_SCO_Connect_HCI_Event1( BT_HCI_EVENT &hci_event );
    // void  Compose_Enable_SCO_Connect_HCI_Command2( S_BD_ADDR &bd_addr, E_BT_SCO sco, BT_HCI_COMMAND &hci_cmd );
    // create SCO connect
    // void  Compose_Create_SCO_Connect_HCI_Command( E_BT_ACL_P1 p1, E_BT_ACL_P1 p2, E_BT_SCO sco, BT_HCI_COMMAND &hci_cmd );
    // TCI
    void  Compose_TCI_Activate_Remote_DUT_HCI_Command( unsigned char &h1, unsigned char &h2, BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_TCI_Activate_Remote_DUT_HCI_Event1( BT_HCI_EVENT &hci_event );
    bool  DeCompose_TCI_Activate_Remote_DUT_HCI_Event2( BT_HCI_EVENT &hci_event );
    void  Compose_TCI_Control_Remote_DUT_HCI_Command( unsigned char h1,
            unsigned char h2,
            S_BT_PKT_TCI req,
            BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_TCI_Control_Remote_DUT_HCI_Event1(BT_HCI_EVENT hci_event);
    bool  DeCompose_TCI_Control_Remote_DUT_HCI_Event2(BT_HCI_EVENT hci_event);
    // start TX packet
//   void  Compose_Start_TX_Packet_HCI_Command( E_BT_ACL_P1 p1, E_BT_ACL_P1 p2, unsigned char poll_period,
//                                                   unsigned short packet_length, BT_HCI_COMMAND &hci_cmd );
//   bool  DeCompose_Start_TX_Packet_HCI_Event( BT_HCI_EVENT &hci_event );

    // Get Packet TX/RX count
    void  Compose_Read_TX_RX_Count_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor);
    void  Compose_Read_EDR_TX_RX_Count_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_EDR_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor);

    // reset
    void  Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);
#endif
    // log
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd, E_BT_PACKET_DEVICE_T obj);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event, E_BT_PACKET_DEVICE_T obj);

    // global information
    META_RESULT Get_ConfirmState(void);
    S_BD_ADDR Get_TesterBDAddress(void);
    S_BD_ADDR Get_DUTBDAddress(void);
    S_BT_PKT_MONITOR_CNF Get_MonitorResult(void);
};

/*---------------------------------------------------------------------------*/
#endif