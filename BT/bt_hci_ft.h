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
 *   bt_hci_ft.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command compose/event decompose header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_HCI_FT_H_
#define  _BT_HCI_FT_H_


#include <vcl.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_PKT_COMMON_H_
#include "bt_pkt_common.h"
#endif
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
class CBTHCIFT
{
private:
    // common


protected:


public:

    CBTHCIFT(void);
    ~CBTHCIFT();

    // reset
    void  Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    void  Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Reset_HCI_Event(BT_HCI_EVENT hci_event);

    // read BD address
    void  Compose_Read_BD_Addr_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_BD_Addr_HCI_Event(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr);

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

    void  Compose_TCI_Activate_Remote_DUT_HCI_Command(unsigned char h1, unsigned char h2, BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_TCI_Activate_Remote_DUT_HCI_Event1(BT_HCI_EVENT hci_event);
    bool  DeCompose_TCI_Activate_Remote_DUT_HCI_Event2(BT_HCI_EVENT hci_event);
    void  Compose_TCI_Control_Remote_DUT_HCI_Command(unsigned char h1,
            unsigned char h2,
            S_BT_PKT_TCI req,
            BT_HCI_COMMAND &hci_cmd );
    bool  DeCompose_TCI_Control_Remote_DUT_HCI_Event1(BT_HCI_EVENT hci_event);
    bool  DeCompose_TCI_Control_Remote_DUT_HCI_Event2(BT_HCI_EVENT hci_event);

    void  Compose_Read_TX_RX_Count_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor);
    void  Compose_Read_EDR_TX_RX_Count_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_Read_EDR_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor);



};

/*---------------------------------------------------------------------------*/
#endif
