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
 *   bt_hci_ft.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT HCI command compose/event decompose source
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
//===========================================================================
#include <stdio.h>

#pragma hdrstop

// BT
#ifndef  _BT_HCI_FT_H_
#include "bt_hci_ft.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif


//==============================================================================
static CBTHCIFT*  gs_bt_ft_ptr;


//===========================================================================
CBTHCIFT::CBTHCIFT(void)
{
}

//---------------------------------------------------------------------------
CBTHCIFT::~CBTHCIFT(void)
{
}

//===========================================================================
//////////////////////////  Compose/decompose HCI command  //////////////////
//===========================================================================
void CBTHCIFT::Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

//---------------------------------------------------------------------------
void CBTHCIFT::Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Reset_HCI_Event(BT_HCI_EVENT hci_event)
{
    if ((hci_event.m_len      != 0x04) ||
            (hci_event.m_parms[0] != 0x01) ||
            (hci_event.m_parms[1] != 0x03) ||
            (hci_event.m_parms[2] != 0x0C) ||
            (hci_event.m_parms[3] != 0x00)
       )
    {
        return false;
    }

    return true;
}
//--------------------------------------------------------------------------
void  CBTHCIFT::Compose_Read_BD_Addr_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0x1009;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );

}

//--------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Read_BD_Addr_HCI_Event(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr)
{
    if ((0x09 != hci_event.m_parms[1]) ||
            (0x10 != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    for (int i=0; i<BD_ADDRESS_LEN; i++)
    {
        bd_addr.uc_BD_Addr[i] = hci_event.m_parms[4+i];
    }
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Enter_Test_Mode_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x1803;
    hci_cmd.m_len    = 0;
    Reset_HCI_Command( hci_cmd );
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Enter_Test_Mode_HCI_Event(BT_HCI_EVENT hci_event)
{
    if ((0x03 != hci_event.m_parms[1]) ||
            (0x18 != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Scan_Enable_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C1A;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x03;

}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_Scan_Enable_HCI_Event(BT_HCI_EVENT hci_event)
{
    if ((0x1A != hci_event.m_parms[1]) ||
            (0x0C != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------
void  CBTHCIFT::Compose_Auto_Accept_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C05;
    hci_cmd.m_len    = 3;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x02;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x02;

}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Auto_Accept_HCI_Event(BT_HCI_EVENT hci_event)
{
    if ((0x05 != hci_event.m_parms[1]) ||
            (0x0C != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_ACL_Connect_HCI_Command( S_BD_ADDR &bd_addr, BT_HCI_COMMAND &hci_cmd )
{
    int i;

    hci_cmd.m_opcode = 0x0405;
    hci_cmd.m_len = 13;
    Reset_HCI_Command( hci_cmd );
    for( i=0; i<BD_ADDRESS_LEN; i++ )
        hci_cmd.m_cmd[i] = bd_addr.uc_BD_Addr[i];
    hci_cmd.m_cmd[6]  = 0x18;
    hci_cmd.m_cmd[7]  = 0xCC;
    hci_cmd.m_cmd[8]  = 0x01;
    hci_cmd.m_cmd[9]  = 0x00;
    hci_cmd.m_cmd[10] = 0xA7;
    hci_cmd.m_cmd[11] = 0xFC;
    hci_cmd.m_cmd[12] = 0x00;



}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_ACL_Connect_HCI_Event1(BT_HCI_EVENT hci_event)
{
    if ((0x05 != hci_event.m_parms[2]) ||
            (0x04 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_ACL_Connect_HCI_Event2(BT_HCI_EVENT hci_event, S_BD_ADDR &bd_addr, unsigned char &h1, unsigned char &h2)
{
    // 03 0B 00 (H1 H2) 08 FF 00 22 2D AE 01 00

    if ((0x00 != hci_event.m_parms[0]) ||  // connect not successfully
            (0x00 != hci_event.m_parms[2]) ||
            (0x01 != hci_event.m_parms[9]) ||
            (0x00 != hci_event.m_parms[10])
       )
    {
        return false;
    }


    for (int i=0; i<BD_ADDRESS_LEN; i++)
    {
        if (bd_addr.uc_BD_Addr[i] != hci_event.m_parms[i+3])
        {
            return false;
        }
    }

    h1 = hci_event.m_parms[1];
    h2 = hci_event.m_parms[2];


    return true;
}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_ACL_Connect_HCI_Event3(BT_HCI_EVENT hci_event, unsigned char &h1, unsigned char &h2 )
{
    // 1B 03 (H1 H2) 05

    if ((0x1B != hci_event.m_parms[0]) ||
            (0x03 != hci_event.m_parms[1])  ||
            (0x05 != hci_event.m_parms[4])
       )
    {
        return false;
    }

    h1 = hci_event.m_parms[2];
    h2 = hci_event.m_parms[3];

    return true;
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_ACL_Connect_HCI_Event4(BT_HCI_EVENT hci_event, unsigned char &h1, unsigned char &h2 )
{
    // 1D 05 00 (H1 H2) 18 CC

    if ((0x1D != hci_event.m_parms[0]) ||
            (0x05 != hci_event.m_parms[1]) ||
            (0x00 != hci_event.m_parms[2]) ||
            (0x18 != hci_event.m_parms[5]) ||
            (0xCC != hci_event.m_parms[6])
       )
    {
        return false;
    }

    h1 = hci_event.m_parms[3];
    h2 = hci_event.m_parms[4];

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_TCI_Activate_Remote_DUT_HCI_Command( unsigned char h1, unsigned char h2, BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0xFC02;
    hci_cmd.m_len = 2;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = h1;
    hci_cmd.m_cmd[7]  = h2;

}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_TCI_Activate_Remote_DUT_HCI_Event1(BT_HCI_EVENT hci_event)
{
    if ((0x02 != hci_event.m_parms[2]) ||
            (0xFC != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_TCI_Activate_Remote_DUT_HCI_Event2(BT_HCI_EVENT hci_event)
{
    // 0E 04 01 02 FC 00
    if((0x02 != hci_event.m_parms[1]) ||
            (0xFC != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
      )
    {
        return false;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_TCI_Control_Remote_DUT_HCI_Command(unsigned char h1,
        unsigned char h2,
        S_BT_PKT_TCI req,
        BT_HCI_COMMAND &hci_cmd)
{
    // 03 FC 1B (H1 H2) 07 01 00 00 00 02 03 11 00 00 00 01 00 00 00 00 00 00 00 00 00 (N1 N2 N3 N4)
    hci_cmd.m_opcode = 0xFC03;
    hci_cmd.m_len    = 0x1B;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = h1;
    hci_cmd.m_cmd[1] = h2;
    hci_cmd.m_cmd[2] = 0x07;
    hci_cmd.m_cmd[3] = 0x01;
    hci_cmd.m_cmd[4] = 0x00;
    hci_cmd.m_cmd[5] = 0x00;
    hci_cmd.m_cmd[6] = 0x00;
    hci_cmd.m_cmd[7] = req.uc_poll_period;
    // hci_cmd.m_cmd[8] = 0x03;
    hci_cmd.m_cmd[9] = req.us_packet_length & 0x00FF;
    hci_cmd.m_cmd[10]= (req.us_packet_length & 0xFF00)>>8;
    hci_cmd.m_cmd[11]= 0x00;
    hci_cmd.m_cmd[12]= 0x00;
    hci_cmd.m_cmd[13]= 0x01;
    hci_cmd.m_cmd[14]= 0x00;
    hci_cmd.m_cmd[15]= 0x00;
    hci_cmd.m_cmd[16]= 0x00;
    hci_cmd.m_cmd[17]= 0x00;
    hci_cmd.m_cmd[18]= 0x00;
    hci_cmd.m_cmd[19]= 0x00;
    hci_cmd.m_cmd[20]= 0x00;
    hci_cmd.m_cmd[21]= 0x00;
    hci_cmd.m_cmd[22]= 0x00;
    hci_cmd.m_cmd[23]= req.ui_packet_count & 0x000000FF;
    hci_cmd.m_cmd[24]= (req.ui_packet_count & 0x0000FF00)>>8;
    hci_cmd.m_cmd[25]= (req.ui_packet_count & 0x00FF0000)>>16;
    hci_cmd.m_cmd[26]= (req.ui_packet_count & 0xFF000000)>>24;
    switch( req.e_idx )
    {
    case BT_PACKET_IDX_DM1:
    {
        hci_cmd.m_cmd[8] = 0x03; // type
    }
    break;

    case BT_PACKET_IDX_DH1:
    {
        hci_cmd.m_cmd[8] = 0x04;
    }
    break;

    case BT_PACKET_IDX_DM3:
    {
        hci_cmd.m_cmd[8] = 0x0A;
    }
    break;

    case BT_PACKET_IDX_DH3:
    {
        hci_cmd.m_cmd[8] = 0x0B;
    }
    break;

    case BT_PACKET_IDX_DM5:
    {
        hci_cmd.m_cmd[8] = 0x0E;
    }
    break;

    case BT_PACKET_IDX_DH5:
    {
        hci_cmd.m_cmd[8] = 0x0F;
    }
    break;

    case BT_PACKET_IDX_HV1:
    {
        hci_cmd.m_cmd[8] = 0x05;
    }
    break;

    case BT_PACKET_IDX_HV2:
    {
        hci_cmd.m_cmd[8] = 0x06;
    }
    break;

    case BT_PACKET_IDX_HV3:
    {
        hci_cmd.m_cmd[8] = 0x07;
    }
    break;

    case BT_PACKET_IDX_EV3:
    {
        hci_cmd.m_cmd[8] = 0x17;
    }
    break;

    case BT_PACKET_IDX_EV4:
    {
        hci_cmd.m_cmd[8] = 0x1C;
    }
    break;

    case BT_PACKET_IDX_EV5:
    {
        hci_cmd.m_cmd[8] = 0x1D;
    }
    break;

    case BT_PACKET_IDX_2DH1:
    {
        hci_cmd.m_cmd[8] = 0x24;
    }
    break;

    case BT_PACKET_IDX_2EV3:
    {
        hci_cmd.m_cmd[8] = 0x36;
    }
    break;

    case BT_PACKET_IDX_2DH3:
    {
        hci_cmd.m_cmd[8] = 0x2A;
    }
    break;

    case BT_PACKET_IDX_2EV5:
    {
        hci_cmd.m_cmd[8] = 0x3C;
    }
    break;

    case BT_PACKET_IDX_2DH5:
    {
        hci_cmd.m_cmd[8] = 0x2E;
    }
    break;

    case BT_PACKET_IDX_3EV3:
    {
        hci_cmd.m_cmd[8] = 0x37;
    }
    break;

    case BT_PACKET_IDX_3DH1:
    {
        hci_cmd.m_cmd[8] = 0x28;
    }
    break;

    case BT_PACKET_IDX_3DH3:
    {
        hci_cmd.m_cmd[8] = 0x2B;
    }
    break;

    case BT_PACKET_IDX_3EV5:
    {
        hci_cmd.m_cmd[8] = 0x3D;
    }
    break;

    case BT_PACKET_IDX_3DH5:
    {
        hci_cmd.m_cmd[8] = 0x2F;
    }
    break;
    }
}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_TCI_Control_Remote_DUT_HCI_Event1(BT_HCI_EVENT hci_event)
{
    //  0F 04 00 01 03 FC

    if ((0x03 != hci_event.m_parms[1]) ||
            (0xFC != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_TCI_Control_Remote_DUT_HCI_Event2(BT_HCI_EVENT hci_event)
{
    //  0E 04 01 03 FC 00

    if ((0x03 != hci_event.m_parms[1]) ||
            (0xFC != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    return true;
}

#if 0
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Enable_SCO_Connect_HCI_Command1( BT_HCI_COMMAND &hci_cmd )
{
    // 05,0C,01,00
    hci_cmd.m_opcode = 0x0C05;
    hci_cmd.m_len    = 1;
    Reset_HCI_Command( hci_cmd );
}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_Enable_SCO_Connect_HCI_Event1( BT_HCI_EVENT &hci_event )
{
    // 0E,04,01,05,0C,00

    if(
        0x05 != hci_event.m_parms[1]  ||
        0x0C != hci_event.m_parms[2]  ||
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------
void  CBTHCIFT::Compose_Enable_SCO_Connect_HCI_Command2( S_BD_ADDR &bd_addr, E_BT_SCO sco, BT_HCI_COMMAND &hci_cmd )
{
    // 29,04,15,Y1,Y2,Y3,Y4,Y5,Y6,40,1F,00,00,40,1F,00,00,05,00,AF,00,00,KK,00
    hci_cmd.m_opcode = 0x0429;
    hci_cmd.m_len     = 21;
    Reset_HCI_Command( hci_cmd );
    for( int i=0; i<BD_ADDRESS_LEN; i++ )
    {
        hci_cmd.m_cmd[i] = bd_addr.uc_BD_Addr[i];
    }
    hci_cmd.m_cmd[6]  = 0x40;
    hci_cmd.m_cmd[7]  = 0x1F;
    hci_cmd.m_cmd[8]  = 0x00;
    hci_cmd.m_cmd[9]  = 0x00;
    hci_cmd.m_cmd[10] = 0x40;
    hci_cmd.m_cmd[11] = 0x1F;
    hci_cmd.m_cmd[12] = 0x00;
    hci_cmd.m_cmd[13] = 0x00;
    hci_cmd.m_cmd[14] = 0x05;
    hci_cmd.m_cmd[15] = 0x00;
    hci_cmd.m_cmd[16] = 0xAF;
    hci_cmd.m_cmd[17] = 0x00;
    hci_cmd.m_cmd[18] = 0x00;
    hci_cmd.m_cmd[19] = sco;
    hci_cmd.m_cmd[20] = 0x00;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Create_SCO_Connect_HCI_Command( E_BT_ACL_P1 p1, E_BT_ACL_P1 p2, E_BT_SCO sco, BT_HCI_COMMAND &hci_cmd )
{
    // 28,04,11,H1,H2,40,1F,00,00,40,1F,00,00,05,00,AF,00,00,KK,00
    hci_cmd.m_opcode = 0x0428;
    hci_cmd.m_len     = 17;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = p1;
    hci_cmd.m_cmd[1]  = p2;
    hci_cmd.m_cmd[2]  = 0x40;
    hci_cmd.m_cmd[3]  = 0x1F;
    hci_cmd.m_cmd[4]  = 0x00;
    hci_cmd.m_cmd[5]  = 0x00;
    hci_cmd.m_cmd[6]  = 0x40;
    hci_cmd.m_cmd[7]  = 0x1F;
    hci_cmd.m_cmd[8]  = 0x00;
    hci_cmd.m_cmd[9]  = 0x00;
    hci_cmd.m_cmd[10] = 0x05;
    hci_cmd.m_cmd[11] = 0x00;
    hci_cmd.m_cmd[12] = 0xAF;
    hci_cmd.m_cmd[13] = 0x00;
    hci_cmd.m_cmd[14] = 0x00;
    hci_cmd.m_cmd[15] = sco;
    hci_cmd.m_cmd[16] = 0x00;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Start_TX_Packet_HCI_Command( E_BT_ACL_P1 p1, E_BT_ACL_P1 p2, unsigned char poll_period,
        unsigned short packet_length, BT_HCI_COMMAND &hci_cmd )
{
    // 000: 03,FC,17,
    // 003: H1,H2
    // 005: scenario (01)
    // 006: hop_mode (01)
    // 007: tx_freq  (00)
    // 008: rx_freq  (00)
    // 009: power_control_mode (00)
    // 010: poll_period
    // 011: packet_type (P2)
    // 012: packet_length
    // 014: system_test_group (01,00,01,00)
    // 018: system_test_subgroup (06,P1,00,00)
    // 022: test_number (E8,03,00,00)
    hci_cmd.m_opcode = 0xFC03;
    hci_cmd.m_len     = 23;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0]  = p1;
    hci_cmd.m_cmd[1]  = p2;
    hci_cmd.m_cmd[2]  = 0x01;
    hci_cmd.m_cmd[3]  = 0x01;
    hci_cmd.m_cmd[4]  = 0x00;
    hci_cmd.m_cmd[5]  = 0x00;
    hci_cmd.m_cmd[6]  = 0x00;
    hci_cmd.m_cmd[7]  = poll_period;
    hci_cmd.m_cmd[8]  = p2;
    hci_cmd.m_cmd[9]  = packet_length & 0x00FF;
    hci_cmd.m_cmd[10] = (packet_length & 0xFF00) >> 8;
    hci_cmd.m_cmd[11] = 0x01;
    hci_cmd.m_cmd[12] = 0x00;
    hci_cmd.m_cmd[13] = 0x01;
    hci_cmd.m_cmd[14] = 0x00;
    hci_cmd.m_cmd[15] = 0x06;
    hci_cmd.m_cmd[16] = p1;
    hci_cmd.m_cmd[17] = 0x00;
    hci_cmd.m_cmd[18] = 0x00;
    hci_cmd.m_cmd[19] = 0xE8;
    hci_cmd.m_cmd[20] = 0x03;
    hci_cmd.m_cmd[21] = 0x00;
    hci_cmd.m_cmd[22] = 0x00;

}

//---------------------------------------------------------------------------
bool  CBTHCIFT::DeCompose_Start_TX_Packet_HCI_Event( BT_HCI_EVENT &hci_event )
{
    // 0E,04,01,03,FC,00

    if(
        0x03 != hci_event.m_parms[1]  ||
        0xFC != hci_event.m_parms[2]  ||
        0x00 != hci_event.m_parms[3]
    )
    {
        return false;
    }

    return true;
}
#endif


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTHCIFT::Compose_Read_TX_RX_Count_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{

    hci_cmd.m_opcode = 0xFC3F;
    hci_cmd.m_len     = 0;
    Reset_HCI_Command( hci_cmd );
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Read_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor )
{
    // 04,0E,F8,01 3F FC 00

    if ((0x3F != hci_event.m_parms[1]) ||
            (0xFC != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    // TX
    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DM1] =  hci_event.m_parms[48]        |
            (hci_event.m_parms[49] << 8)  |
            (hci_event.m_parms[50] << 16) |
            (hci_event.m_parms[51] << 24) ;

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DH1] =  hci_event.m_parms[52]        |
            (hci_event.m_parms[53] << 8)  |
            (hci_event.m_parms[54] << 16) |
            (hci_event.m_parms[55] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_HV1] =  hci_event.m_parms[56]        |
            (hci_event.m_parms[57] << 8)  |
            (hci_event.m_parms[58] << 16) |
            (hci_event.m_parms[59] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_HV2] =  hci_event.m_parms[60]        |
            (hci_event.m_parms[61] <<  8) |
            (hci_event.m_parms[62] << 16) |
            (hci_event.m_parms[63] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_HV3] = hci_event.m_parms[64]         |
            (hci_event.m_parms[65] << 8)  |
            (hci_event.m_parms[66] << 16) |
            (hci_event.m_parms[67] << 24);

    // monitor.ui_tx_pkt_count[BT_PACKET_IDX_DV] =  hci_event.m_parms[68]  |
    //                                              (hci_event.m_parms[69] << 8) |
    //                                              (hci_event.m_parms[70] << 16) |
    //                                              ( hci_event.m_parms[71]<<24);

    // monitor.ui_tx_pkt_count[BT_PACKET_IDX_AUX] = hci_event.m_parms[72]  |
    //                                              (hci_event.m_parms[73] << 8) |
    //                                              (hci_event.m_parms[74] << 16) |
    //                                              (hci_event.m_parms[75] << 24);
    //
    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DM3] = hci_event.m_parms[76]         |
            (hci_event.m_parms[77] << 8)  |
            (hci_event.m_parms[78] << 16) |
            (hci_event.m_parms[79] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DH3] = hci_event.m_parms[80]         |
            (hci_event.m_parms[81] << 8)  |
            (hci_event.m_parms[82] << 16) |
            (hci_event.m_parms[83] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_EV4] =  hci_event.m_parms[84]        |
            (hci_event.m_parms[85] << 8)  |
            (hci_event.m_parms[86] << 16) |
            (hci_event.m_parms[87] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_EV5] =  hci_event.m_parms[88]        |
            (hci_event.m_parms[89] << 8)  |
            (hci_event.m_parms[90] << 16) |
            (hci_event.m_parms[91] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DM5] =  hci_event.m_parms[92]        |
            (hci_event.m_parms[93] << 8)  |
            (hci_event.m_parms[94] << 16) |
            (hci_event.m_parms[95] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_DH5] =  hci_event.m_parms[96]        |
            (hci_event.m_parms[97] <<  8) |
            (hci_event.m_parms[98] << 16) |
            (hci_event.m_parms[99] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_EV3] =  hci_event.m_parms[128]       |
            (hci_event.m_parms[129] <<  8)|
            (hci_event.m_parms[130] << 16)|
            (hci_event.m_parms[131] << 24);

    // RX
    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DM1] =  hci_event.m_parms[144]       |
            (hci_event.m_parms[145] << 8) |
            (hci_event.m_parms[146] << 16)|
            (hci_event.m_parms[147] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DH1] =  hci_event.m_parms[148]       |
            (hci_event.m_parms[149] << 8) |
            (hci_event.m_parms[150] << 16)|
            (hci_event.m_parms[151] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_HV1] =  hci_event.m_parms[152]       |
            (hci_event.m_parms[153] << 8) |
            (hci_event.m_parms[154] << 16)|
            (hci_event.m_parms[155] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_HV2] =  hci_event.m_parms[156]       |
            (hci_event.m_parms[157] << 8) |
            (hci_event.m_parms[158] << 16)|
            (hci_event.m_parms[159] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_HV3] =  hci_event.m_parms[160]       |
            (hci_event.m_parms[161] <<  8)|
            (hci_event.m_parms[162] << 16)|
            (hci_event.m_parms[163] << 24);

    // monitor.ui_rx_pkt_count[BT_PACKET_IDX_DV] =  hci_event.m_parms[164]  |
    //                                              (hci_event.m_parms[165] << 8) |
    //                                              (hci_event.m_parms[166] << 16) |
    //                                              (hci_event.m_parms[167] << 24);

    //  monitor.ui_rx_pkt_count[BT_PACKET_IDX_AUX] = hci_event.m_parms[168]  |
    //                                               (hci_event.m_parms[169] << 8) |
    //                                               (hci_event.m_parms[170] << 16) |
    //                                               (hci_event.m_parms[171] << 24);
    //
    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DM3] = hci_event.m_parms[172]        |
            (hci_event.m_parms[173] << 8) |
            (hci_event.m_parms[174] << 16)|
            (hci_event.m_parms[175] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DH3] = hci_event.m_parms[176]        |
            (hci_event.m_parms[177] << 8) |
            (hci_event.m_parms[178] << 16)|
            (hci_event.m_parms[179] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_EV4] = hci_event.m_parms[180]        |
            (hci_event.m_parms[181] << 8) |
            (hci_event.m_parms[182] << 16)|
            (hci_event.m_parms[183] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_EV5] = hci_event.m_parms[184]        |
            (hci_event.m_parms[185] << 8) |
            (hci_event.m_parms[186] << 16)|
            (hci_event.m_parms[187] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DM5] =  hci_event.m_parms[188]       |
            (hci_event.m_parms[189] << 8) |
            (hci_event.m_parms[190] << 16)|
            (hci_event.m_parms[191] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_DH5] =  hci_event.m_parms[192]       |
            (hci_event.m_parms[193] << 8) |
            (hci_event.m_parms[194] << 16)|
            (hci_event.m_parms[195] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_EV3] =  hci_event.m_parms[224]       |
            (hci_event.m_parms[225] << 8) |
            (hci_event.m_parms[226] << 16)|
            (hci_event.m_parms[227] << 24);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTHCIFT::Compose_Read_EDR_TX_RX_Count_HCI_Command(BT_HCI_COMMAND &hci_cmd)
{

    hci_cmd.m_opcode = 0xFCDA;
    hci_cmd.m_len     = 0;
    Reset_HCI_Command(hci_cmd);
}

//---------------------------------------------------------------------------
bool CBTHCIFT::DeCompose_Read_EDR_TX_RX_Count_HCI_Event(BT_HCI_EVENT hci_event, S_BT_PKT_MONITOR_TXRX_CNF &monitor)
{
    // 04,0E,94,01,DA,FC,00

    if ((0xDA != hci_event.m_parms[1]) ||
            (0xFC != hci_event.m_parms[2]) ||
            (0x00 != hci_event.m_parms[3])
       )
    {
        return false;
    }

    // TX
    monitor.ui_tx_pkt_count[BT_PACKET_IDX_2DH1] = hci_event.m_parms[4]        |
            (hci_event.m_parms[5] << 8)  |
            (hci_event.m_parms[6] << 16) |
            (hci_event.m_parms[7] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_2EV3] = hci_event.m_parms[8]         |
            (hci_event.m_parms[9]  << 8)  |
            (hci_event.m_parms[10] << 16) |
            (hci_event.m_parms[11] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_3EV3] = hci_event.m_parms[12]        |
            (hci_event.m_parms[13] << 8)  |
            (hci_event.m_parms[14] << 16) |
            (hci_event.m_parms[15] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_3DH1] = hci_event.m_parms[16]        |
            (hci_event.m_parms[17] <<  8) |
            (hci_event.m_parms[18] << 16) |
            (hci_event.m_parms[19] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_2DH3] = hci_event.m_parms[20]         |
            (hci_event.m_parms[21] << 8)  |
            (hci_event.m_parms[22] << 16) |
            (hci_event.m_parms[23] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_3DH3] = hci_event.m_parms[24]        |
            (hci_event.m_parms[25] << 8)  |
            (hci_event.m_parms[26] << 16) |
            (hci_event.m_parms[27] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_2EV5] = hci_event.m_parms[28]         |
            (hci_event.m_parms[29] << 8)  |
            (hci_event.m_parms[30] << 16) |
            (hci_event.m_parms[31] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_3EV5] = hci_event.m_parms[32]        |
            (hci_event.m_parms[33] << 8)  |
            (hci_event.m_parms[34] << 16) |
            (hci_event.m_parms[35] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_2DH5] = hci_event.m_parms[36]        |
            (hci_event.m_parms[37] << 8)  |
            (hci_event.m_parms[38] << 16) |
            (hci_event.m_parms[39] << 24);

    monitor.ui_tx_pkt_count[BT_PACKET_IDX_3DH5] = hci_event.m_parms[40]        |
            (hci_event.m_parms[41] << 8)  |
            (hci_event.m_parms[42] << 16) |
            (hci_event.m_parms[43] << 24);

    // RX
    monitor.ui_rx_pkt_count[BT_PACKET_IDX_2DH1] = hci_event.m_parms[64]        |
            (hci_event.m_parms[65] << 8)  |
            (hci_event.m_parms[66] << 16) |
            (hci_event.m_parms[67] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_2EV3] = hci_event.m_parms[68]         |
            (hci_event.m_parms[69]  << 8)  |
            (hci_event.m_parms[70] << 16) |
            (hci_event.m_parms[71] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_3EV3] = hci_event.m_parms[72]        |
            (hci_event.m_parms[73] << 8)  |
            (hci_event.m_parms[74] << 16) |
            (hci_event.m_parms[75] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_3DH1] = hci_event.m_parms[76]        |
            (hci_event.m_parms[77] <<  8) |
            (hci_event.m_parms[78] << 16) |
            (hci_event.m_parms[79] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_2DH3] = hci_event.m_parms[80]         |
            (hci_event.m_parms[81] << 8)  |
            (hci_event.m_parms[82] << 16) |
            (hci_event.m_parms[83] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_3DH3] = hci_event.m_parms[84]        |
            (hci_event.m_parms[85] << 8)  |
            (hci_event.m_parms[86] << 16) |
            (hci_event.m_parms[87] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_2EV5] = hci_event.m_parms[88]         |
            (hci_event.m_parms[89] << 8)  |
            (hci_event.m_parms[90] << 16) |
            (hci_event.m_parms[91] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_3EV5] = hci_event.m_parms[92]        |
            (hci_event.m_parms[93] << 8)  |
            (hci_event.m_parms[94] << 16) |
            (hci_event.m_parms[95] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_2DH5] = hci_event.m_parms[96]        |
            (hci_event.m_parms[97] << 8)  |
            (hci_event.m_parms[98] << 16) |
            (hci_event.m_parms[99] << 24);

    monitor.ui_rx_pkt_count[BT_PACKET_IDX_3DH5] = hci_event.m_parms[100]        |
            (hci_event.m_parms[101] << 8)  |
            (hci_event.m_parms[102] << 16) |
            (hci_event.m_parms[103] << 24);

    return true;
}







