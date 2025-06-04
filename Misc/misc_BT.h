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
 *   misc_BT.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  BT Misc. function header
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
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _MISC_BT_H_
#define  _MISC_BT_H_
/*---------------------------------------------------------------------------*/
#include <vcl.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _BT_HCI_H_
#include "bt_hci.h"
#endif

/*---------------------------------------------------------------------------*/
// format transform
extern bool  BTHCIValue_To_AnsiString( S_BT_HCI_VALUE hci_value, AnsiString &ansi_str );
extern bool  BTHCIValue_To_Hex_AnsiString( S_BT_HCI_VALUE hci_value, AnsiString &ansi_str );
extern bool  BDAddress_To_Hex_AnsiString( S_BD_ADDR bd_addr, AnsiString &ansi_str );
extern bool  BDAddress_To_Hex_Colon_AnsiString( S_BD_ADDR bd_addr, AnsiString &ansi_str );
extern bool  AnsiString_To_Hex_BDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr );
extern bool  Colon_AnsiString_To_Hex_BDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr );
extern bool  AnsiString_To_BTHCIValue( AnsiString ansi_str, S_BT_HCI_VALUE &out_value );
extern bool  AnsiString_Hex_To_BTHCIValue( AnsiString ansi_str, S_BT_HCI_VALUE &out_value );
extern bool  AnsiString_Hex_To_BTPIN( AnsiString ansi_str, S_BT_PIN &pt_pin );
// range check
extern bool  IsValidHexBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &hci_value, S_BT_HCI_VALUE &min_hci_value, S_BT_HCI_VALUE &max_hci_value );
extern bool  IsValidHexBDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr );
extern bool  IsValidHexBTPIN( AnsiString ansi_str, S_BT_PIN &pin );
extern bool  IsValidDecBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &hci_value, S_BT_HCI_VALUE &min_hci_value, S_BT_HCI_VALUE &max_hci_value );
extern bool  IsValidHexBTHCIOpcode( AnsiString ansi_str, unsigned short &opcode );
extern bool  IsValidHexBTHCIEventIndex( AnsiString ansi_str, unsigned char &event_idx );
extern bool  IsValidBTFreq( AnsiString ansi_str, unsigned char &freq );
extern bool  IsValidBTTxDataLength( AnsiString ansi_str, unsigned short &len, unsigned short range_min, unsigned short range_max );
extern bool  IsValidBTTxPollPeriod( AnsiString ansi_str, unsigned char &period );
extern bool  IsValidBTTxPacketCount( AnsiString ansi_str, unsigned int &count );
extern bool  IsValidBTTxPcl( AnsiString ansi_str, unsigned char &pcl );
extern bool  IsValidBTBLEChannel( AnsiString ansi_str, unsigned char &pcl );
extern bool  IsValidHexBTLAP( AnsiString ansi_str, unsigned int &lap );
extern bool  IsValidHexBTTxAccessCode( AnsiString ansi_str, unsigned char &code );
extern bool  IsValidHexBDAddress( AnsiString ansi_str, unsigned char &address );
extern bool  IsValidDecBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &value );
extern bool  IsValidHexBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &value );
extern bool  IsValidBTTimeout( AnsiString ansi_str, unsigned int &timeout );

// ESCO
extern bool IsValidTxBandwidth( AnsiString ansi_str, unsigned int *ui_bandwidth );
extern bool IsValidRxBandwidth( AnsiString ansi_str, unsigned int *ui_bandwidth );
extern bool IsValidMaxLatency( AnsiString ansi_str, unsigned short &us_latency );
extern bool IsValidRetransmissionEffort( AnsiString ansi_str, unsigned char &uc_effort );
#endif
