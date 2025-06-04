/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   form_WiFiBBCR.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi baseband control register form source
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "form_WiFiBBCR.h"

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFiBBCR *frmWiFiBBCR;

//===========================================================================
static void  ConfirmCallback_ReadReg( void )
{
    frmWiFiBBCR->ConfirmCallback_ReadReg();
}

//---------------------------------------------------------------------------
static void  ConfirmCallback_WriteReg( void )
{
    frmWiFiBBCR->ConfirmCallback_WriteReg();
}

//---------------------------------------------------------------------------
__fastcall TfrmWiFiBBCR::TfrmWiFiBBCR(TComponent* Owner)
    : TForm(Owner)
{
    int i, j;

    // Initialization and PHY-Configuration
    cbIPC[0] = cbIPC0;
    lblIPC[0] = lblIPC0;
    lblIPCn[0] = lblIPCn0;
    edtIPC[0] = edtIPC0;
    cbIPC[1] = cbIPC1;
    lblIPC[1] = lblIPC1;
    lblIPCn[1] = lblIPCn1;
    edtIPC[1] = edtIPC1;
    cbIPC[2] = cbIPC2;
    lblIPC[2] = lblIPC2;
    lblIPCn[2] = lblIPCn2;
    edtIPC[2] = edtIPC2;
    cbIPC[3] = cbIPC3;
    lblIPC[3] = lblIPC3;
    lblIPCn[3] = lblIPCn3;
    edtIPC[3] = edtIPC3;
    cbIPC[4] = cbIPC4;
    lblIPC[4] = lblIPC4;
    lblIPCn[4] = lblIPCn4;
    edtIPC[4] = edtIPC4;

    //  TX-related
    cbTX[0] = cbTX0;
    lblTX[0] = lblTX0;
    lblTXn[0] = lblTXn0;
    edtTX[0] = edtTX0;
    cbTX[1] = cbTX1;
    lblTX[1] = lblTX1;
    lblTXn[1] = lblTXn1;
    edtTX[1] = edtTX1;
    cbTX[2] = cbTX2;
    lblTX[2] = lblTX2;
    lblTXn[2] = lblTXn2;
    edtTX[2] = edtTX2;
    cbTX[3] = cbTX3;
    lblTX[3] = lblTX3;
    lblTXn[3] = lblTXn3;
    edtTX[3] = edtTX3;
    cbTX[4] = cbTX4;
    lblTX[4] = lblTX4;
    lblTXn[4] = lblTXn4;
    edtTX[4] = edtTX4;
    cbTX[5] = cbTX5;
    lblTX[5] = lblTX5;
    lblTXn[5] = lblTXn5;
    edtTX[5] = edtTX5;
    cbTX[6] = cbTX6;
    lblTX[6] = lblTX6;
    lblTXn[6] = lblTXn6;
    edtTX[6] = edtTX6;
    cbTX[7] = cbTX7;
    lblTX[7] = lblTX7;
    lblTXn[7] = lblTXn7;
    edtTX[7] = edtTX7;
    cbTX[8] = cbTX8;
    lblTX[8] = lblTX8;
    lblTXn[8] = lblTXn8;
    edtTX[8] = edtTX8;
    cbTX[9] = cbTX9;
    lblTX[9] = lblTX9;
    lblTXn[9] = lblTXn9;
    edtTX[9] = edtTX9;

    // RX-related
    cbRX[0] = cbRX00;
    lblRX[0] = lblRX00;
    lblRX[0] = lblRXn00;
    edtRX[0] = edtRX00;
    cbRX[1] = cbRX01;
    lblRX[1] = lblRX01;
    lblRX[1] = lblRXn01;
    edtRX[1] = edtRX01;
    cbRX[2] = cbRX02;
    lblRX[2] = lblRX02;
    lblRX[2] = lblRXn02;
    edtRX[2] = edtRX02;
    cbRX[3] = cbRX03;
    lblRX[3] = lblRX03;
    lblRX[3] = lblRXn03;
    edtRX[3] = edtRX03;
    cbRX[4] = cbRX04;
    lblRX[4] = lblRX04;
    lblRX[4] = lblRXn04;
    edtRX[4] = edtRX04;
    cbRX[5] = cbRX05;
    lblRX[5] = lblRX05;
    lblRX[5] = lblRXn05;
    edtRX[5] = edtRX05;
    cbRX[6] = cbRX06;
    lblRX[6] = lblRX06;
    lblRX[6] = lblRXn06;
    edtRX[6] = edtRX06;
    cbRX[7] = cbRX07;
    lblRX[7] = lblRX07;
    lblRX[7] = lblRXn07;
    edtRX[7] = edtRX07;
    cbRX[8] = cbRX08;
    lblRX[8] = lblRX08;
    lblRX[8] = lblRXn08;
    edtRX[8] = edtRX08;
    cbRX[9] = cbRX09;
    lblRX[9] = lblRX09;
    lblRX[9] = lblRXn09;
    edtRX[9] = edtRX09;
    cbRX[10] = cbRX10;
    lblRX[10] = lblRX10;
    lblRX[10] = lblRXn10;
    edtRX[10] = edtRX10;
    cbRX[11] = cbRX11;
    lblRX[11] = lblRX11;
    lblRX[11] = lblRXn11;
    edtRX[11] = edtRX11;
    cbRX[12] = cbRX12;
    lblRX[12] = lblRX12;
    lblRX[12] = lblRXn12;
    edtRX[12] = edtRX12;
    cbRX[13] = cbRX13;
    lblRX[13] = lblRX13;
    lblRX[13] = lblRXn13;
    edtRX[13] = edtRX13;
    cbRX[14] = cbRX14;
    lblRX[14] = lblRX14;
    lblRX[14] = lblRXn14;
    edtRX[14] = edtRX14;

    // BBP Configuration
    cbBBPC[0] = cbBBPC000;
    lblBBPC[0] = lblBBPC000;
    lblBBPCn[0] = lblBBPCn000;
    edtBBPC[0] = edtBBPC000;
    cbBBPC[1] = cbBBPC001;
    lblBBPC[1] = lblBBPC001;
    lblBBPCn[1] = lblBBPCn001;
    edtBBPC[1] = edtBBPC001;
    cbBBPC[2] = cbBBPC002;
    lblBBPC[2] = lblBBPC002;
    lblBBPCn[2] = lblBBPCn002;
    edtBBPC[2] = edtBBPC002;
    cbBBPC[3] = cbBBPC003;
    lblBBPC[3] = lblBBPC003;
    lblBBPCn[3] = lblBBPCn003;
    edtBBPC[3] = edtBBPC003;
    cbBBPC[4] = cbBBPC004;
    lblBBPC[4] = lblBBPC004;
    lblBBPCn[4] = lblBBPCn004;
    edtBBPC[4] = edtBBPC004;
    cbBBPC[5] = cbBBPC005;
    lblBBPC[5] = lblBBPC005;
    lblBBPCn[5] = lblBBPCn005;
    edtBBPC[5] = edtBBPC005;
    cbBBPC[6] = cbBBPC006;
    lblBBPC[6] = lblBBPC006;
    lblBBPCn[6] = lblBBPCn006;
    edtBBPC[6] = edtBBPC006;
    cbBBPC[7] = cbBBPC007;
    lblBBPC[7] = lblBBPC007;
    lblBBPCn[7] = lblBBPCn007;
    edtBBPC[7] = edtBBPC007;
    cbBBPC[8] = cbBBPC008;
    lblBBPC[8] = lblBBPC008;
    lblBBPCn[8] = lblBBPCn008;
    edtBBPC[8] = edtBBPC008;
    cbBBPC[9] = cbBBPC009;
    lblBBPC[9] = lblBBPC009;
    lblBBPCn[9] = lblBBPCn009;
    edtBBPC[9] = edtBBPC009;
    cbBBPC[10] = cbBBPC010;
    lblBBPC[10] = lblBBPC010;
    lblBBPCn[10] = lblBBPCn010;
    edtBBPC[10] = edtBBPC010;
    cbBBPC[11] = cbBBPC011;
    lblBBPC[11] = lblBBPC011;
    lblBBPCn[11] = lblBBPCn011;
    edtBBPC[11] = edtBBPC011;
    cbBBPC[12] = cbBBPC012;
    lblBBPC[12] = lblBBPC012;
    lblBBPCn[12] = lblBBPCn012;
    edtBBPC[12] = edtBBPC012;
    cbBBPC[13] = cbBBPC013;
    lblBBPC[13] = lblBBPC013;
    lblBBPCn[13] = lblBBPCn013;
    edtBBPC[13] = edtBBPC013;
    cbBBPC[14] = cbBBPC014;
    lblBBPC[14] = lblBBPC014;
    lblBBPCn[14] = lblBBPCn014;
    edtBBPC[14] = edtBBPC014;
    cbBBPC[15] = cbBBPC015;
    lblBBPC[15] = lblBBPC015;
    lblBBPCn[15] = lblBBPCn015;
    edtBBPC[15] = edtBBPC015;
    cbBBPC[16] = cbBBPC016;
    lblBBPC[16] = lblBBPC016;
    lblBBPCn[16] = lblBBPCn016;
    edtBBPC[16] = edtBBPC016;
    cbBBPC[17] = cbBBPC017;
    lblBBPC[17] = lblBBPC017;
    lblBBPCn[17] = lblBBPCn017;
    edtBBPC[17] = edtBBPC017;
    cbBBPC[18] = cbBBPC018;
    lblBBPC[18] = lblBBPC018;
    lblBBPCn[18] = lblBBPCn018;
    edtBBPC[18] = edtBBPC018;
    cbBBPC[19] = cbBBPC019;
    lblBBPC[19] = lblBBPC019;
    lblBBPCn[19] = lblBBPCn019;
    edtBBPC[19] = edtBBPC019;
    cbBBPC[20] = cbBBPC020;
    lblBBPC[20] = lblBBPC020;
    lblBBPCn[20] = lblBBPCn020;
    edtBBPC[20] = edtBBPC020;
    cbBBPC[21] = cbBBPC021;
    lblBBPC[21] = lblBBPC021;
    lblBBPCn[21] = lblBBPCn021;
    edtBBPC[21] = edtBBPC021;
    cbBBPC[22] = cbBBPC022;
    lblBBPC[22] = lblBBPC022;
    lblBBPCn[22] = lblBBPCn022;
    edtBBPC[22] = edtBBPC022;
    cbBBPC[23] = cbBBPC023;
    lblBBPC[23] = lblBBPC023;
    lblBBPCn[23] = lblBBPCn023;
    edtBBPC[23] = edtBBPC023;
    cbBBPC[24] = cbBBPC024;
    lblBBPC[24] = lblBBPC024;
    lblBBPCn[24] = lblBBPCn024;
    edtBBPC[24] = edtBBPC024;
    cbBBPC[25] = cbBBPC025;
    lblBBPC[25] = lblBBPC025;
    lblBBPCn[25] = lblBBPCn025;
    edtBBPC[25] = edtBBPC025;
    cbBBPC[26] = cbBBPC026;
    lblBBPC[26] = lblBBPC026;
    lblBBPCn[26] = lblBBPCn026;
    edtBBPC[26] = edtBBPC026;
    cbBBPC[27] = cbBBPC027;
    lblBBPC[27] = lblBBPC027;
    lblBBPCn[27] = lblBBPCn027;
    edtBBPC[27] = edtBBPC027;
    cbBBPC[28] = cbBBPC028;
    lblBBPC[28] = lblBBPC028;
    lblBBPCn[28] = lblBBPCn028;
    edtBBPC[28] = edtBBPC028;
    cbBBPC[29] = cbBBPC029;
    lblBBPC[29] = lblBBPC029;
    lblBBPCn[29] = lblBBPCn029;
    edtBBPC[29] = edtBBPC029;
    cbBBPC[30] = cbBBPC030;
    lblBBPC[30] = lblBBPC030;
    lblBBPCn[30] = lblBBPCn030;
    edtBBPC[30] = edtBBPC030;
    cbBBPC[31] = cbBBPC031;
    lblBBPC[31] = lblBBPC031;
    lblBBPCn[31] = lblBBPCn031;
    edtBBPC[31] = edtBBPC031;
    cbBBPC[32] = cbBBPC032;
    lblBBPC[32] = lblBBPC032;
    lblBBPCn[32] = lblBBPCn032;
    edtBBPC[32] = edtBBPC032;
    cbBBPC[33] = cbBBPC033;
    lblBBPC[33] = lblBBPC033;
    lblBBPCn[33] = lblBBPCn033;
    edtBBPC[33] = edtBBPC033;
    cbBBPC[34] = cbBBPC034;
    lblBBPC[34] = lblBBPC034;
    lblBBPCn[34] = lblBBPCn034;
    edtBBPC[34] = edtBBPC034;
    cbBBPC[35] = cbBBPC035;
    lblBBPC[35] = lblBBPC035;
    lblBBPCn[35] = lblBBPCn035;
    edtBBPC[35] = edtBBPC035;
    cbBBPC[36] = cbBBPC036;
    lblBBPC[36] = lblBBPC036;
    lblBBPCn[36] = lblBBPCn036;
    edtBBPC[36] = edtBBPC036;
    cbBBPC[37] = cbBBPC037;
    lblBBPC[37] = lblBBPC037;
    lblBBPCn[37] = lblBBPCn037;
    edtBBPC[37] = edtBBPC037;
    cbBBPC[38] = cbBBPC038;
    lblBBPC[38] = lblBBPC038;
    lblBBPCn[38] = lblBBPCn038;
    edtBBPC[38] = edtBBPC038;
    cbBBPC[39] = cbBBPC039;
    lblBBPC[39] = lblBBPC039;
    lblBBPCn[39] = lblBBPCn039;
    edtBBPC[39] = edtBBPC039;
    cbBBPC[40] = cbBBPC040;
    lblBBPC[40] = lblBBPC040;
    lblBBPCn[40] = lblBBPCn040;
    edtBBPC[40] = edtBBPC040;
    cbBBPC[41] = cbBBPC041;
    lblBBPC[41] = lblBBPC041;
    lblBBPCn[41] = lblBBPCn041;
    edtBBPC[41] = edtBBPC041;
    cbBBPC[42] = cbBBPC042;
    lblBBPC[42] = lblBBPC042;
    lblBBPCn[42] = lblBBPCn042;
    edtBBPC[42] = edtBBPC042;
    cbBBPC[43] = cbBBPC043;
    lblBBPC[43] = lblBBPC043;
    lblBBPCn[43] = lblBBPCn043;
    edtBBPC[43] = edtBBPC043;
    cbBBPC[44] = cbBBPC044;
    lblBBPC[44] = lblBBPC044;
    lblBBPCn[44] = lblBBPCn044;
    edtBBPC[44] = edtBBPC044;
    cbBBPC[45] = cbBBPC045;
    lblBBPC[45] = lblBBPC045;
    lblBBPCn[45] = lblBBPCn045;
    edtBBPC[45] = edtBBPC045;
    cbBBPC[46] = cbBBPC046;
    lblBBPC[46] = lblBBPC046;
    lblBBPCn[46] = lblBBPCn046;
    edtBBPC[46] = edtBBPC046;
    cbBBPC[47] = cbBBPC047;
    lblBBPC[47] = lblBBPC047;
    lblBBPCn[47] = lblBBPCn047;
    edtBBPC[47] = edtBBPC047;
    cbBBPC[48] = cbBBPC048;
    lblBBPC[48] = lblBBPC048;
    lblBBPCn[48] = lblBBPCn048;
    edtBBPC[48] = edtBBPC048;
    cbBBPC[49] = cbBBPC049;
    lblBBPC[49] = lblBBPC049;
    lblBBPCn[49] = lblBBPCn049;
    edtBBPC[49] = edtBBPC049;
    cbBBPC[50] = cbBBPC050;
    lblBBPC[50] = lblBBPC050;
    lblBBPCn[50] = lblBBPCn050;
    edtBBPC[50] = edtBBPC050;
    cbBBPC[51] = cbBBPC051;
    lblBBPC[51] = lblBBPC051;
    lblBBPCn[51] = lblBBPCn051;
    edtBBPC[51] = edtBBPC051;
    cbBBPC[52] = cbBBPC052;
    lblBBPC[52] = lblBBPC052;
    lblBBPCn[52] = lblBBPCn052;
    edtBBPC[52] = edtBBPC052;
    cbBBPC[53] = cbBBPC053;
    lblBBPC[53] = lblBBPC053;
    lblBBPCn[53] = lblBBPCn053;
    edtBBPC[53] = edtBBPC053;
    cbBBPC[54] = cbBBPC054;
    lblBBPC[54] = lblBBPC054;
    lblBBPCn[54] = lblBBPCn054;
    edtBBPC[54] = edtBBPC054;
    cbBBPC[55] = cbBBPC055;
    lblBBPC[55] = lblBBPC055;
    lblBBPCn[55] = lblBBPCn055;
    edtBBPC[55] = edtBBPC055;
    cbBBPC[56] = cbBBPC056;
    lblBBPC[56] = lblBBPC056;
    lblBBPCn[56] = lblBBPCn056;
    edtBBPC[56] = edtBBPC056;
    cbBBPC[57] = cbBBPC057;
    lblBBPC[57] = lblBBPC057;
    lblBBPCn[57] = lblBBPCn057;
    edtBBPC[57] = edtBBPC057;
    cbBBPC[58] = cbBBPC058;
    lblBBPC[58] = lblBBPC058;
    lblBBPCn[58] = lblBBPCn058;
    edtBBPC[58] = edtBBPC058;
    cbBBPC[59] = cbBBPC059;
    lblBBPC[59] = lblBBPC059;
    lblBBPCn[59] = lblBBPCn059;
    edtBBPC[59] = edtBBPC059;
    cbBBPC[60] = cbBBPC060;
    lblBBPC[60] = lblBBPC060;
    lblBBPCn[60] = lblBBPCn060;
    edtBBPC[60] = edtBBPC060;
    cbBBPC[61] = cbBBPC061;
    lblBBPC[61] = lblBBPC061;
    lblBBPCn[61] = lblBBPCn061;
    edtBBPC[61] = edtBBPC061;
    cbBBPC[62] = cbBBPC062;
    lblBBPC[62] = lblBBPC062;
    lblBBPCn[62] = lblBBPCn062;
    edtBBPC[62] = edtBBPC062;
    cbBBPC[63] = cbBBPC063;
    lblBBPC[63] = lblBBPC063;
    lblBBPCn[63] = lblBBPCn063;
    edtBBPC[63] = edtBBPC063;
    cbBBPC[64] = cbBBPC064;
    lblBBPC[64] = lblBBPC064;
    lblBBPCn[64] = lblBBPCn064;
    edtBBPC[64] = edtBBPC064;
    cbBBPC[65] = cbBBPC065;
    lblBBPC[65] = lblBBPC065;
    lblBBPCn[65] = lblBBPCn065;
    edtBBPC[65] = edtBBPC065;
    cbBBPC[66] = cbBBPC066;
    lblBBPC[66] = lblBBPC066;
    lblBBPCn[66] = lblBBPCn066;
    edtBBPC[66] = edtBBPC066;
    cbBBPC[67] = cbBBPC067;
    lblBBPC[67] = lblBBPC067;
    lblBBPCn[67] = lblBBPCn067;
    edtBBPC[67] = edtBBPC067;
    cbBBPC[68] = cbBBPC068;
    lblBBPC[68] = lblBBPC068;
    lblBBPCn[68] = lblBBPCn068;
    edtBBPC[68] = edtBBPC068;
    cbBBPC[69] = cbBBPC069;
    lblBBPC[69] = lblBBPC069;
    lblBBPCn[69] = lblBBPCn069;
    edtBBPC[69] = edtBBPC069;
    cbBBPC[70] = cbBBPC070;
    lblBBPC[70] = lblBBPC070;
    lblBBPCn[70] = lblBBPCn070;
    edtBBPC[70] = edtBBPC070;
    cbBBPC[71] = cbBBPC071;
    lblBBPC[71] = lblBBPC071;
    lblBBPCn[71] = lblBBPCn071;
    edtBBPC[71] = edtBBPC071;
    cbBBPC[72] = cbBBPC072;
    lblBBPC[72] = lblBBPC072;
    lblBBPCn[72] = lblBBPCn072;
    edtBBPC[72] = edtBBPC072;
    cbBBPC[73] = cbBBPC073;
    lblBBPC[73] = lblBBPC073;
    lblBBPCn[73] = lblBBPCn073;
    edtBBPC[73] = edtBBPC073;

    // set name property
    // Initialization and PHY-Configuration
    m_sBBCR_Setting[WIFI_BBCR_IPC][0].name = "DEV_ID";
    m_sBBCR_Setting[WIFI_BBCR_IPC][1].name = "IO_POLAR";
    m_sBBCR_Setting[WIFI_BBCR_IPC][2].name = "TR_CFG1";
    m_sBBCR_Setting[WIFI_BBCR_IPC][3].name = "TR_CFG2";
    m_sBBCR_Setting[WIFI_BBCR_IPC][4].name = "INT_CSR";

    // TX-related
    m_sBBCR_Setting[WIFI_BBCR_TX][0].name = "TX_STAT";
    m_sBBCR_Setting[WIFI_BBCR_TX][1].name = "TX_LEN_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][2].name = "TX_LEN_L";
    m_sBBCR_Setting[WIFI_BBCR_TX][3].name = "TX_SV_O_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][4].name = "TX_SV_O_L";
    m_sBBCR_Setting[WIFI_BBCR_TX][5].name = "TX_SV_CCK";
    m_sBBCR_Setting[WIFI_BBCR_TX][6].name = "TXPWR_OFD";
    m_sBBCR_Setting[WIFI_BBCR_TX][7].name = "TXPWR_CCK";
    m_sBBCR_Setting[WIFI_BBCR_TX][8].name = "PAPWR_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][9].name = "PAPWR_L";

    // RX-related
    m_sBBCR_Setting[WIFI_BBCR_RX][0].name = "RX_STAT";
    m_sBBCR_Setting[WIFI_BBCR_RX][1].name = "RX_LEN_H";
    m_sBBCR_Setting[WIFI_BBCR_RX][2].name = "RX_LEN_L";
    m_sBBCR_Setting[WIFI_BBCR_RX][3].name = "RX_SVR_H";
    m_sBBCR_Setting[WIFI_BBCR_RX][4].name = "RX_SVR_L";
    m_sBBCR_Setting[WIFI_BBCR_RX][5].name = "RSSI";
    m_sBBCR_Setting[WIFI_BBCR_RX][6].name = "SQ_B5";
    m_sBBCR_Setting[WIFI_BBCR_RX][7].name = "SQ_B4";
    m_sBBCR_Setting[WIFI_BBCR_RX][8].name = "SQ_B3";
    m_sBBCR_Setting[WIFI_BBCR_RX][9].name = "SQ_B2";
    m_sBBCR_Setting[WIFI_BBCR_RX][10].name = "SQ_B1";
    m_sBBCR_Setting[WIFI_BBCR_RX][11].name = "SQ_B0";
    m_sBBCR_Setting[WIFI_BBCR_RX][12].name = "RADAR_PW";
    m_sBBCR_Setting[WIFI_BBCR_RX][13].name = "RADAR_PWR";
    m_sBBCR_Setting[WIFI_BBCR_RX][14].name = "CR38";

    // BBP Configuration
    m_sBBCR_Setting[WIFI_BBCR_BBPC][0].name = "ODTX_BF_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][1].name = "ODTX_BF_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][2].name = "ODTX_FT_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][3].name = "ODTX_FT_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][4].name = "CCKTX_F_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][5].name = "CCKTX_F_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][6].name = "AGC_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][7].name = "AGC_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][8].name = "OFDM_TR_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][9].name = "OFDM_TR_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][10].name = "CCK_SQ_1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][11].name = "CCK_SQ_2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][12].name = "CCK_CE_TH";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][13].name = "CCK_L_PRM";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][14].name = "CCK_S_PRM";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][15].name = "CCK_PREAMB_LEN";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][16].name = "CCK_MISC_1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][17].name = "CCK_MISC_2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][18].name = "CCK_MISC_3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][19].name = "MPDU_ANT_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][20].name = "MPDU_ANT_TMO";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][21].name = "AP_ADDRB5";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][22].name = "AP_ADDRB4";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][23].name = "AP_ADDRB3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][24].name = "AP_ADDRB2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][25].name = "AP_ADDRB1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][26].name = "AP_ADDRB0";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][27].name = "OFDM_MISC1_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][28].name = "OFDM_MISC2_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][29].name = "OFDM_ACQ_SHORT";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][30].name = "OFDM_ACQ_LONG";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][31].name = "AFEBandGAP";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][32].name = "AFEPowerDOWN";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][33].name = "AFETx_DAC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][34].name = "AFETx_DAC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][35].name = "AFETx_DAC_FD";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][36].name = "Test_MODE1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][37].name = "Test_MODE2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][38].name = "Test_MODE3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][39].name = "Test_MODE4";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][40].name = "AFE_Rx_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][41].name = "AFE_Rx_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][42].name = "AFE_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][43].name = "AFE_ALC_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][44].name = "AFE_ALC_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][45].name = "CNTR_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][46].name = "N_ED_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][47].name = "N_ED_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][48].name = "N_OSD_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][49].name = "N_OSD_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][50].name = "N_mdrdy_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][51].name = "N_mdrdy_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][52].name = "N_SQ1_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][53].name = "N_SQ1_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][54].name = "RxADCI_prob_O";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][55].name = "RxADCQ_prob_O";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][56].name = "N_CRC16_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][57].name = "N_CRC16_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][58].name = "N_CCK_SFD_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][59].name = "N_CCK_SFD_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][60].name = "N_CCK_FCS_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][61].name = "N_CCK_FCS_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][62].name = "Noise_floor_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][63].name = "Noise_floor_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][64].name = "Instant_Rx_PWR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][65].name = "CCK_CMF_ERR_RDBK";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][66].name = "PostAGC_ACCUM_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][67].name = "PostAGC_ACCUM_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][68].name = "RPI_CNT_H_BYTE";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][69].name = "RPI_CNT_L_BYTE";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][70].name = "RPI_CTL_REG";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][71].name = "RPI_TH_Addr";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][72].name = "RPI_TH_Data";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][73].name = "RDD_Counter";


    // set idx property
    // Initialization and PHY-Configuration
    m_sBBCR_Setting[WIFI_BBCR_IPC][0].idx = 0;
    m_sBBCR_Setting[WIFI_BBCR_IPC][1].idx = 1;
    m_sBBCR_Setting[WIFI_BBCR_IPC][2].idx = 2;
    m_sBBCR_Setting[WIFI_BBCR_IPC][3].idx = 3;
    m_sBBCR_Setting[WIFI_BBCR_IPC][4].idx = 4;

    // TX-related
    m_sBBCR_Setting[WIFI_BBCR_TX][0].idx =  8;
    m_sBBCR_Setting[WIFI_BBCR_TX][1].idx =  9;
    m_sBBCR_Setting[WIFI_BBCR_TX][2].idx = 10;
    m_sBBCR_Setting[WIFI_BBCR_TX][3].idx = 11;
    m_sBBCR_Setting[WIFI_BBCR_TX][4].idx = 12;
    m_sBBCR_Setting[WIFI_BBCR_TX][5].idx = 13;
    m_sBBCR_Setting[WIFI_BBCR_TX][6].idx = 14;
    m_sBBCR_Setting[WIFI_BBCR_TX][7].idx = 15;
    m_sBBCR_Setting[WIFI_BBCR_TX][8].idx = 16;
    m_sBBCR_Setting[WIFI_BBCR_TX][9].idx = 17;

    // RX-related
    m_sBBCR_Setting[WIFI_BBCR_RX][0].idx = 24;
    m_sBBCR_Setting[WIFI_BBCR_RX][1].idx = 25;
    m_sBBCR_Setting[WIFI_BBCR_RX][2].idx = 26;
    m_sBBCR_Setting[WIFI_BBCR_RX][3].idx = 27;
    m_sBBCR_Setting[WIFI_BBCR_RX][4].idx = 28;
    m_sBBCR_Setting[WIFI_BBCR_RX][5].idx = 29;
    m_sBBCR_Setting[WIFI_BBCR_RX][6].idx = 30;
    m_sBBCR_Setting[WIFI_BBCR_RX][7].idx = 31;
    m_sBBCR_Setting[WIFI_BBCR_RX][8].idx = 32;
    m_sBBCR_Setting[WIFI_BBCR_RX][9].idx = 33;
    m_sBBCR_Setting[WIFI_BBCR_RX][10].idx = 34;
    m_sBBCR_Setting[WIFI_BBCR_RX][11].idx = 35;
    m_sBBCR_Setting[WIFI_BBCR_RX][12].idx = 36;
    m_sBBCR_Setting[WIFI_BBCR_RX][13].idx = 37;
    m_sBBCR_Setting[WIFI_BBCR_RX][14].idx = 38;

    // BBP Configuration
    m_sBBCR_Setting[WIFI_BBCR_BBPC][0].idx = 39;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][1].idx = 40;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][2].idx = 41;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][3].idx = 42;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][4].idx = 43;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][5].idx = 44;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][6].idx = 45;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][7].idx = 46;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][8].idx = 47;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][9].idx = 48;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][10].idx = 49;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][11].idx = 50;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][12].idx = 56;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][13].idx = 59;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][14].idx = 60;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][15].idx = 61;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][16].idx = 62;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][17].idx = 63;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][18].idx = 64;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][19].idx = 68;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][20].idx = 69;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][21].idx = 70;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][22].idx = 71;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][23].idx = 72;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][24].idx = 73;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][25].idx = 74;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][26].idx = 75;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][27].idx = 76;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][28].idx = 77;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][29].idx = 78;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][30].idx = 79;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][31].idx = 81;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][32].idx = 82;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][33].idx = 83;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][34].idx = 84;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][35].idx = 85;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][36].idx = 88;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][37].idx = 89;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][38].idx = 90;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][39].idx = 91;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][40].idx = 92;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][41].idx = 93;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][42].idx = 94;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][43].idx = 95;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][44].idx = 96;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][45].idx = 97;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][46].idx = 98;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][47].idx = 99;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][48].idx = 100;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][49].idx = 101;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][50].idx = 102;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][51].idx = 103;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][52].idx = 104;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][53].idx = 105;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][54].idx = 106;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][55].idx = 107;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][56].idx = 108;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][57].idx = 109;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][58].idx = 110;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][59].idx = 111;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][60].idx = 112;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][61].idx = 113;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][62].idx = 114;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][63].idx = 115;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][64].idx = 116;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][65].idx = 117;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][66].idx = 118;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][67].idx = 119;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][68].idx = 120;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][69].idx = 121;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][70].idx = 122;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][71].idx = 123;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][72].idx = 124;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][73].idx = 125;

    // set addr property
    // Initialization and PHY-Configuration
    m_sBBCR_Setting[WIFI_BBCR_IPC][0].addr = 0x00;
    m_sBBCR_Setting[WIFI_BBCR_IPC][1].addr = 0x02;
    m_sBBCR_Setting[WIFI_BBCR_IPC][2].addr = 0x04;
    m_sBBCR_Setting[WIFI_BBCR_IPC][3].addr = 0x06;
    m_sBBCR_Setting[WIFI_BBCR_IPC][4].addr = 0x08;

    // TX-related
    m_sBBCR_Setting[WIFI_BBCR_TX][0].addr = 0x10;
    m_sBBCR_Setting[WIFI_BBCR_TX][1].addr = 0x12;
    m_sBBCR_Setting[WIFI_BBCR_TX][2].addr = 0x14;
    m_sBBCR_Setting[WIFI_BBCR_TX][3].addr = 0x16;
    m_sBBCR_Setting[WIFI_BBCR_TX][4].addr = 0x18;
    m_sBBCR_Setting[WIFI_BBCR_TX][5].addr = 0x1A;
    m_sBBCR_Setting[WIFI_BBCR_TX][6].addr = 0x1C;
    m_sBBCR_Setting[WIFI_BBCR_TX][7].addr = 0x1E;
    m_sBBCR_Setting[WIFI_BBCR_TX][8].addr = 0x20;
    m_sBBCR_Setting[WIFI_BBCR_TX][9].addr = 0x22;

    // RX-related
    m_sBBCR_Setting[WIFI_BBCR_RX][0].addr = 0x30;
    m_sBBCR_Setting[WIFI_BBCR_RX][1].addr = 0x32;
    m_sBBCR_Setting[WIFI_BBCR_RX][2].addr = 0x34;
    m_sBBCR_Setting[WIFI_BBCR_RX][3].addr = 0x36;
    m_sBBCR_Setting[WIFI_BBCR_RX][4].addr = 0x38;
    m_sBBCR_Setting[WIFI_BBCR_RX][5].addr = 0x3A;
    m_sBBCR_Setting[WIFI_BBCR_RX][6].addr = 0x3C;
    m_sBBCR_Setting[WIFI_BBCR_RX][7].addr = 0x3E;
    m_sBBCR_Setting[WIFI_BBCR_RX][8].addr = 0x40;
    m_sBBCR_Setting[WIFI_BBCR_RX][9].addr = 0x42;
    m_sBBCR_Setting[WIFI_BBCR_RX][10].addr = 0x44;
    m_sBBCR_Setting[WIFI_BBCR_RX][11].addr = 0x46;
    m_sBBCR_Setting[WIFI_BBCR_RX][12].addr = 0x48;
    m_sBBCR_Setting[WIFI_BBCR_RX][13].addr = 0x4A;
    m_sBBCR_Setting[WIFI_BBCR_RX][14].addr = 0x4C;

    // BBP Configuration
    m_sBBCR_Setting[WIFI_BBCR_BBPC][0].addr = 0x4E;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][1].addr = 0x50;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][2].addr = 0x52;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][3].addr = 0x54;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][4].addr = 0x56;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][5].addr = 0x58;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][6].addr = 0x5A;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][7].addr = 0x5C;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][8].addr = 0x5E;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][9].addr = 0x60;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][10].addr = 0x62;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][11].addr = 0x64;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][12].addr = 0x70;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][13].addr = 0x76;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][14].addr = 0x78;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][15].addr = 0x7A;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][16].addr = 0x7C;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][17].addr = 0x7E;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][18].addr = 0x80;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][19].addr = 0x88;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][20].addr = 0x8A;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][21].addr = 0x8C;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][22].addr = 0x8E;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][23].addr = 0x90;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][24].addr = 0x92;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][25].addr = 0x94;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][26].addr = 0x96;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][27].addr = 0x98;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][28].addr = 0x9A;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][29].addr = 0x9C;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][30].addr = 0x9E;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][31].addr = 0xA2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][32].addr = 0xA4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][33].addr = 0xA6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][34].addr = 0xA8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][35].addr = 0xAA;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][36].addr = 0xB0;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][37].addr = 0xB2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][38].addr = 0xB4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][39].addr = 0xB6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][40].addr = 0xB8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][41].addr = 0xBA;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][42].addr = 0xBC;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][43].addr = 0xBE;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][44].addr = 0xC0;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][45].addr = 0xC2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][46].addr = 0xC4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][47].addr = 0xC6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][48].addr = 0xC8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][49].addr = 0xCA;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][50].addr = 0xCC;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][51].addr = 0xCE;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][52].addr = 0xD0;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][53].addr = 0xD2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][54].addr = 0xD4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][55].addr = 0xD6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][56].addr = 0xD8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][57].addr = 0xDA;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][58].addr = 0xDC;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][59].addr = 0xDE;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][60].addr = 0xE0;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][61].addr = 0xE2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][62].addr = 0xE4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][63].addr = 0xE6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][64].addr = 0xE8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][65].addr = 0xEA;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][66].addr = 0xEC;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][67].addr = 0xEE;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][68].addr = 0xF0;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][69].addr = 0xF2;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][70].addr = 0xF4;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][71].addr = 0xF6;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][72].addr = 0xF8;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][73].addr = 0xFA;

    // set RO property
    // Initialization and PHY-Configuration
    m_sBBCR_Setting[WIFI_BBCR_IPC][0].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_IPC][1].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_IPC][2].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_IPC][3].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_IPC][4].RO = false;

    // TX-related
    m_sBBCR_Setting[WIFI_BBCR_TX][0].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][1].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][2].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][3].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][4].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][5].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][6].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][7].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_TX][8].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_TX][9].RO = true;

    // RX-related
    m_sBBCR_Setting[WIFI_BBCR_RX][0].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][1].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][2].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][3].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][4].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][5].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][6].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][7].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][8].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][9].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][10].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][11].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][12].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][13].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_RX][14].RO = true;

    // BBP Configuration
    m_sBBCR_Setting[WIFI_BBCR_BBPC][0].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][1].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][2].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][3].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][4].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][5].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][6].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][7].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][8].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][9].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][10].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][11].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][12].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][13].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][14].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][15].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][16].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][17].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][18].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][19].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][20].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][21].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][22].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][23].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][24].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][25].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][26].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][27].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][28].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][29].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][30].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][31].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][32].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][33].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][34].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][35].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][36].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][37].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][38].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][39].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][40].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][41].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][42].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][43].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][44].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][45].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][46].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][47].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][48].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][49].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][50].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][51].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][52].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][53].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][54].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][55].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][56].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][57].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][58].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][59].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][60].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][61].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][62].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][63].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][64].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][65].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][66].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][67].RO = true;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][68].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][69].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][70].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][71].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][72].RO = false;
    m_sBBCR_Setting[WIFI_BBCR_BBPC][73].RO = true;

    // set R/C property
    // Initialization and PHY-Configuration
    m_sBBCR_Setting[WIFI_BBCR_IPC][0].RC = false; // "DEV_ID";
    m_sBBCR_Setting[WIFI_BBCR_IPC][1].RC = false; // "IO_POLAR";
    m_sBBCR_Setting[WIFI_BBCR_IPC][2].RC = false; // "TR_CFG1";
    m_sBBCR_Setting[WIFI_BBCR_IPC][3].RC = false; // "TR_CFG2";
    m_sBBCR_Setting[WIFI_BBCR_IPC][4].RC = true;  // "INT_CSR";

    // TX-related
    m_sBBCR_Setting[WIFI_BBCR_TX][0].RC = false; // "TX_STAT";
    m_sBBCR_Setting[WIFI_BBCR_TX][1].RC = false; // "TX_LEN_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][2].RC = false; // "TX_LEN_L";
    m_sBBCR_Setting[WIFI_BBCR_TX][3].RC = false; // "TX_SV_O_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][4].RC = false; // "TX_SV_O_L";
    m_sBBCR_Setting[WIFI_BBCR_TX][5].RC = false; // "TX_SV_CCK";
    m_sBBCR_Setting[WIFI_BBCR_TX][6].RC = false; // "TXPWR_OFD";
    m_sBBCR_Setting[WIFI_BBCR_TX][7].RC = false; // "TXPWR_CCK";
    m_sBBCR_Setting[WIFI_BBCR_TX][8].RC = false; // "PAPWR_H";
    m_sBBCR_Setting[WIFI_BBCR_TX][9].RC = false; // "PAPWR_L";

    // RX-related
    m_sBBCR_Setting[WIFI_BBCR_RX][0].RC = false; // "RX_STAT";
    m_sBBCR_Setting[WIFI_BBCR_RX][1].RC = false; // "RX_LEN_H";
    m_sBBCR_Setting[WIFI_BBCR_RX][2].RC = false; // "RX_LEN_L";
    m_sBBCR_Setting[WIFI_BBCR_RX][3].RC = false; // "RX_SVR_H";
    m_sBBCR_Setting[WIFI_BBCR_RX][4].RC = false; // "RX_SVR_L";
    m_sBBCR_Setting[WIFI_BBCR_RX][5].RC = false; //  "RSSI";
    m_sBBCR_Setting[WIFI_BBCR_RX][6].RC = false; // "SQ_B5";
    m_sBBCR_Setting[WIFI_BBCR_RX][7].RC = false; // "SQ_B4";
    m_sBBCR_Setting[WIFI_BBCR_RX][8].RC = false; // "SQ_B3";
    m_sBBCR_Setting[WIFI_BBCR_RX][9].RC = false; // "SQ_B2";
    m_sBBCR_Setting[WIFI_BBCR_RX][10].RC = false; // "SQ_B1";
    m_sBBCR_Setting[WIFI_BBCR_RX][11].RC = false; // "SQ_B0";
    m_sBBCR_Setting[WIFI_BBCR_RX][12].RC = false; // "RADAR_PW";
    m_sBBCR_Setting[WIFI_BBCR_RX][13].RC = false; // "RADAR_PWR";
    m_sBBCR_Setting[WIFI_BBCR_RX][14].RC = false; // "CR38";

    // BBP Configuration
    m_sBBCR_Setting[WIFI_BBCR_BBPC][0].RC = false; // "ODTX_BF_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][1].RC = false; // "ODTX_BF_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][2].RC = false; // "ODTX_FT_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][3].RC = false; // "ODTX_FT_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][4].RC = false; // "CCKTX_F_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][5].RC = false; // "CCKTX_F_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][6].RC = false; // "AGC_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][7].RC = false; // "AGC_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][8].RC = false; // "OFDM_TR_ADDR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][9].RC = false; // "OFDM_TR_DATA";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][10].RC = false; // "CCK_SQ_1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][11].RC = false; // "CCK_SQ_2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][12].RC = false; // "CCK_CE_TH";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][13].RC = false; // "CCK_L_PRM";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][14].RC = false; // "CCK_S_PRM";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][15].RC = false; // "CCK_PREAMB_LEN";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][16].RC = false; // "CCK_MISC_1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][17].RC = false; // "CCK_MISC_2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][18].RC = false; // "CCK_MISC_3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][19].RC = false; // "MPDU_ANT_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][20].RC = false; // "MPDU_ANT_TMO";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][21].RC = false; // "AP_ADDRB5";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][22].RC = false; // "AP_ADDRB4";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][23].RC = false; // "AP_ADDRB3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][24].RC = false; // "AP_ADDRB2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][25].RC = false; // "AP_ADDRB1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][26].RC = false; // "AP_ADDRB0";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][27].RC = false; // "OFDM_MISC1_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][28].RC = false; // "OFDM_MISC2_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][29].RC = false; // "OFDM_ACQ_SHORT";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][30].RC = false; // "OFDM_ACQ_LONG";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][31].RC = false; // "AFEBandGAP";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][32].RC = false; // "AFEPowerDOWN";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][33].RC = false; // "AFETx_DAC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][34].RC = false; // "AFETx_DAC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][35].RC = false; // "AFETx_DAC_FD";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][36].RC = false; // "Test_MODE1";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][37].RC = false; // "Test_MODE2";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][38].RC = false; // "Test_MODE3";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][39].RC = false; // "Test_MODE4";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][40].RC = false; // "AFE_Rx_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][41].RC = false; // "AFE_Rx_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][42].RC = false; // "AFE_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][43].RC = false; // "AFE_ALC_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][44].RC = false; // "AFE_ALC_ADC";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][45].RC = false; // "CNTR_CTL";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][46].RC = false; // "N_ED_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][47].RC = false; // "N_ED_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][48].RC = false; // "N_OSD_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][49].RC = false; // "N_OSD_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][50].RC = false; // "N_mdrdy_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][51].RC = false; // "N_mdrdy_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][52].RC = false; // "N_SQ1_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][53].RC = false; // "N_SQ1_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][54].RC = false; // "RxADCI_prob_O";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][55].RC = false; // "RxADCQ_prob_O";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][56].RC = false; // "N_CRC16_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][57].RC = false; // "N_CRC16_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][58].RC = false; // "N_CCK_SFD_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][59].RC = false; // "N_CCK_SFD_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][60].RC = false; // "N_CCK_FCS_PASS_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][61].RC = false; // "N_CCK_FCS_PASS_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][62].RC = false; // "Noise_floor_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][63].RC = false; // "Noise_floor_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][64].RC = false; // "Instant_Rx_PWR";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][65].RC = false; // "CCK_CMF_ERR_RDBK";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][66].RC = false; // "PostAGC_ACCUM_H";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][67].RC = false; // "PostAGC_ACCUM_L";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][68].RC = true; // "RPI_CNT_H_BYTE";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][69].RC = true; // "RPI_CNT_L_BYTE";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][70].RC = false; // "RPI_CTL_REG";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][71].RC = false; // "RPI_TH_Addr";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][72].RC = false; // "RPI_TH_Data";
    m_sBBCR_Setting[WIFI_BBCR_BBPC][73].RC = false; // "RDD_Counter";

    // Set value
    for( i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            m_sBBCR_Setting[i][j].value = 0;
        }
    }

    // Set checked property
    for( i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for( j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            m_sBBCR_Setting[i][j].checked = false;
        }
    }
    
    for( i=0; i<WIFI_RX_NUM; i++ )
    {
        lblRXn[i] = NULL;
    }


}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::ReDrawFields( void )
{
    int i;
    char  str[256];

    // Initialization, PHY Configuration and TX/RX
    if( 0 == btnIPTRBBCRData->Tag ) // Dec
    {
        btnIPTRBBCRData->Caption = "BBCR Data (Dec)";

        // Initialization and PHY-Configuration
        for( i=0; i<WIFI_IPC_NUM; i++ )
        {
            edtIPC[i]->Text = IntToStr( m_sBBCR_Setting[WIFI_BBCR_IPC][i].value );
        }

        // TX-related
        for( i=0; i<WIFI_TX_NUM; i++ )
        {
            edtTX[i]->Text = IntToStr( m_sBBCR_Setting[WIFI_BBCR_TX][i].value );
        }

        // RX-related
        for( i=0; i<WIFI_RX_NUM; i++ )
        {
            edtRX[i]->Text = IntToStr( m_sBBCR_Setting[WIFI_BBCR_RX][i].value );
        }
    }
    else
    {
        btnIPTRBBCRData->Caption = "BBCR Data (Hex)";

        // Initialization and PHY-Configuration
        for( i=0; i<WIFI_IPC_NUM; i++ )
        {
            sprintf( str, "%X", m_sBBCR_Setting[WIFI_BBCR_IPC][i].value );
            edtIPC[i]->Text = str;
        }

        // TX-related
        for( i=0; i<WIFI_TX_NUM; i++ )
        {
            sprintf( str, "%X", m_sBBCR_Setting[WIFI_BBCR_TX][i].value );
            edtTX[i]->Text = str;
        }

        // RX-related
        for( i=0; i<WIFI_RX_NUM; i++ )
        {
            sprintf( str, "%X", m_sBBCR_Setting[WIFI_BBCR_RX][i].value );
            edtRX[i]->Text = str;
        }
    }

    // BBP Configuration
    if( 0 == btnBBPCBBCRData->Tag ) // Dec
    {
        btnBBPCBBCRData->Caption = "MCR Data (Dec)";

        // BBP Configuration
        for( i=0; i<WIFI_BBPC_NUM; i++ )
        {
            edtBBPC[i]->Text = IntToStr( m_sBBCR_Setting[WIFI_BBCR_BBPC][i].value );
        }
    }
    else
    {
        btnBBPCBBCRData->Caption = "BBCR Data (Hex)";

        // BBP Configuration
        for( i=0; i<WIFI_BBPC_NUM; i++ )
        {
            sprintf( str, "%X", m_sBBCR_Setting[WIFI_BBCR_BBPC][i].value );
            edtBBPC[i]->Text = str;
        }
    }
}

//---------------------------------------------------------------------------
bool TfrmWiFiBBCR::CheckFields( void )
{
    int i;
    unsigned char         ucdata[WIFI_BBCR_MAX_NUM];
    AnsiString text;

    // Initialization, PHY Configuration and TX/RX
    if( 0 == btnIPTRBBCRData->Tag ) // Dec
    {
        // Initialization and PHY-Configuration
        for( i=0; i<WIFI_IPC_NUM; i++ )
        {
            text = edtIPC[i]->Text;
            if( !IsValidDecWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtIPCCheck(edtIPC[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_IPC][i].value = ucdata[i];
        }

        // TX-related
        for( i=0; i<WIFI_TX_NUM; i++ )
        {
            text = edtTX[i]->Text;
            if( !IsValidDecWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtTXCheck(edtTX[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_TX][i].value = ucdata[i];
        }

        // RX-related
        for( i=0; i<WIFI_RX_NUM; i++ )
        {
            text = edtRX[i]->Text;
            if( !IsValidDecWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtRXCheck(edtRX[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_RX][i].value = ucdata[i];
        }
    }
    else // Hex
    {
        // Initialization and PHY-Configuration
        for( i=0; i<WIFI_IPC_NUM; i++ )
        {
            text = edtIPC[i]->Text;
            if( !IsValidHexWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtIPCCheck(edtIPC[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_IPC][i].value = ucdata[i];
        }

        // TX-related
        for( i=0; i<WIFI_TX_NUM; i++ )
        {
            text = edtTX[i]->Text;
            if( !IsValidHexWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtTXCheck(edtTX[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_TX][i].value = ucdata[i];
        }

        // RX-related
        for( i=0; i<WIFI_RX_NUM; i++ )
        {
            text = edtRX[i]->Text;
            if( !IsValidHexWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtRXCheck(edtRX[i]);
                return false;
            }
            m_sBBCR_Setting[WIFI_BBCR_RX][i].value = ucdata[i];
        }
    }

    // BBP Configuration
    if( 0 == btnBBPCBBCRData->Tag ) // Dec
    {
        for( i=0; i<WIFI_BBPC_NUM; i++ )
        {
            text = edtBBPC[i]->Text;
            if( !IsValidDecWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtBBPCCheck(edtBBPC[i]);
                return false;
            }
        }

    }
    else
    {
        for( i=0; i<WIFI_BBPC_NUM; i++ )
        {
            text = edtBBPC[i]->Text;
            if( !IsValidHexWiFiBBRegValue( text, ucdata[i] ) )
            {
                edtBBPCCheck(edtBBPC[i]);
                return false;
            }
        }
    }
    return true;
}
//---------------------------------------------------------------------------
void  TfrmWiFiBBCR::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TfrmWiFiBBCR::CurrentPageLock( void )
{
}

//---------------------------------------------------------------------------
void  TfrmWiFiBBCR::CurrentPageReset( void )
{
}










void __fastcall TfrmWiFiBBCR::cbIPCHeaderClick(TObject *Sender)
{

    for( int i=0; i<WIFI_IPC_NUM; i++ )
    {
        cbIPC[i]->Checked = cbIPCHeader->Checked;
        m_sBBCR_Setting[WIFI_BBCR_IPC][i].checked = cbIPCHeader->Checked;
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbTXHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_TX_NUM; i++ )
    {
        cbTX[i]->Checked = cbTXHeader->Checked;
        m_sBBCR_Setting[WIFI_BBCR_TX][i].checked = cbTXHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbRXHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_RX_NUM; i++ )
    {
        cbRX[i]->Checked = cbRXHeader->Checked;
        m_sBBCR_Setting[WIFI_BBCR_RX][i].checked = cbRXHeader->Checked;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbBBPCHeaderClick(TObject *Sender)
{
    for( int i=0; i<WIFI_BBPC_NUM; i++ )
    {
        cbBBPC[i]->Checked = cbBBPCHeader->Checked;
        m_sBBCR_Setting[WIFI_BBCR_BBPC][i].checked = cbBBPCHeader->Checked;;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::edtBBPCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnBBPCBBCRData->Tag )  // Dec
    {
        if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sBBCR_Setting[WIFI_BBCR_BBPC][edit->Tag].value = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::edtIPCCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnIPTRBBCRData->Tag )  // Dec
    {
        if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sBBCR_Setting[WIFI_BBCR_IPC][edit->Tag].value = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::edtTXCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnIPTRBBCRData->Tag )  // Dec
    {
        if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sBBCR_Setting[WIFI_BBCR_TX][edit->Tag].value = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::edtRXCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  ucdata;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;
    if( 0 == btnIPTRBBCRData->Tag )  // Dec
    {
        if( !IsValidDecWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if( !IsValidHexWiFiBBRegValue( text, ucdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    m_sBBCR_Setting[WIFI_BBCR_RX][edit->Tag].value = ucdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbIPCClick(TObject *Sender)
{
    TCheckBox *cb = (TCheckBox*)Sender;

    m_sBBCR_Setting[WIFI_BBCR_IPC][cb->Tag].checked = cb->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbTXClick(TObject *Sender)
{
    TCheckBox *cb = (TCheckBox*)Sender;

    m_sBBCR_Setting[WIFI_BBCR_TX][cb->Tag].checked = cb->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::cbRXClick(TObject *Sender)
{
    TCheckBox *cb = (TCheckBox*)Sender;

    m_sBBCR_Setting[WIFI_BBCR_RX][cb->Tag].checked = cb->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TfrmWiFiBBCR::cbBBPCClick(TObject *Sender)
{
    TCheckBox *cb = (TCheckBox*)Sender;

    m_sBBCR_Setting[WIFI_BBCR_BBPC][cb->Tag].checked = cb->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = CheckFields();
    if(!ok)
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Save baseband control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save baseband control register setting to file", "FAILURE", MB_OK );
        return;
    }
    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Save baseband control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save baseband control register setting to file", "FAILURE", MB_OK );
        return;
    }


    strcpy( str, SaveDialog->FileName.c_str() );
    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            m_WIFI_BB_Obj.Set_BBCR_Setting( i, j, m_sBBCR_Setting[i][j] );
        }
    }

    ok = m_WIFI_BB_Obj.REQ_Write_To_File( str );
    if( !ok )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Save baseband control register setting to file fail";
        Application->MessageBox( "Execution Failure : Save baseband control register setting to file", "FAILURE", MB_OK );
        return;
    }

    sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Save baseband control register setting to file successfully";
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Load baseband control register setting from file fail";
        Application->MessageBox( "Execution Failure : Load baseband control register setting from file", "FAILURE", MB_OK );
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );

    ok = m_WIFI_BB_Obj.REQ_Read_From_File( str );

    if( !ok )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Load baseband control register setting from file fail";
        Application->MessageBox( "Execution Failure : Load baseband control register setting from file", "FAILURE", MB_OK );
        return;
    }

    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            m_sBBCR_Setting[i][j].value = m_WIFI_BB_Obj.Get_BBCR_Setting_Value( i, j );
        }
    }

    ReDrawFields();
    sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Load baseband control register setting from file successfully";

}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::btnIPTRBBCRDataClick(TObject *Sender)
{
    if( 0 == btnIPTRBBCRData->Tag )  // Dec-->Hex
    {
        btnIPTRBBCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnIPTRBBCRData->Tag = 0;
    }
    ReDrawFields();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::btnBBPCBBCRDataClick(TObject *Sender)
{
    if( 0 == btnBBPCBBCRData->Tag )  // Dec-->Hex
    {
        btnBBPCBBCRData->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnBBPCBBCRData->Tag = 0;
    }
    ReDrawFields();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiBBCR::btnWriteToRegisterClick(TObject *Sender)
{
    if( ! CheckFields() )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString) "  Write baseband register fail";
        Application->MessageBox( "Execution Failure : Write baseband register", "FAILURE", MB_OK );
        return;
    }

    CurrentPageLock();
    Compose_BBCR_Parameter();
    Compose_BBCR_Data();
    if( 0 == m_sBBCR.count )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Please select at least one baseband register ";
        Application->MessageBox( "Execution Fail : Please select at least one baseband register", "FAIL", MB_OK );
        return;
    }
    m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_WriteReg;
    m_WIFI_BB_Obj.REQ_Write_BBCR_Setting_To_Reg_Start( m_sBBCR );

    sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Write baseband register progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::ConfirmCallback_WriteReg( void )
{
    int state = m_WIFI_BB_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_BB_OK:
    {

        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Write baseband register successfully";
    }
    break;

    case STATE_BB_FAIL:
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Write baseband register fail";
        Application->MessageBox( "Execution Timeout : Write baseband register", "FAIL", MB_OK );
    }
    break;

    case STATE_BB_TIMEOUT:
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Write baseband register timeout";
        Application->MessageBox( "Execution Timeout : Write baseband register", "TIMEOUT", MB_OK );
    }
    break;

    case STATE_BB_STOP:
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Write baseband register stop";
        break;
    }
    CurrentPageReset();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmWiFiBBCR::btnReadFromRegisterClick(TObject *Sender)
{
    CurrentPageLock();
    Compose_BBCR_Parameter();
    if( 0 == m_sBBCR.count )
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Please select at least one baseband register ";
        Application->MessageBox( "Execution Fail : Please select at least one baseband register", "FAIL", MB_OK );
        return;
    }
    m_WIFI_BB_Obj.ConfirmCallback  = ::ConfirmCallback_ReadReg;
    m_WIFI_BB_Obj.REQ_Read_BBCR_Setting_From_Reg_Start( m_sBBCR );
    sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Read baseband register progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::ConfirmCallback_ReadReg( void )
{
    int state = m_WIFI_BB_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_BB_OK:
    {
        // for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
        // {
        //     for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        //     {
        //         m_sBBCR_Setting[i][j].value = m_WIFI_BB_Obj.Get_WiFiBBCRValue( i, j );
        //     }
        // }
        m_sBBCR = m_WIFI_BB_Obj.Get_BBCR();
        DeCompose_BBCR_Data();
        ReDrawFields();
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Read baseband register successfully";
    }
    break;

    case STATE_BB_FAIL:
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Read baseband register fail";
        Application->MessageBox( "Execution Fail : Read baseband register", "FAIL", MB_OK );
    }
    break;

    case STATE_BB_TIMEOUT:
    {
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Read baseband register timeout";
        Application->MessageBox( "Execution Timeout : Read baseband register", "TIMEOUT", MB_OK );
    }
    break;

    case STATE_BB_STOP:
        sbWiFiBBCR->Panels->Items[0]->Text = (AnsiString)"  Read baseband register stop";
        break;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiBBCR::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::Compose_BBCR_Parameter( void )
{

    m_sBBCR.count = 0;

    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            if( m_sBBCR_Setting[i][j].checked )
            {
                m_sBBCR.bb_reg8[m_sBBCR.count].index = m_sBBCR_Setting[i][j].idx;
                m_sBBCR.count++;
            }
        }
    }
#if 0
    // m_sBBCR.number = m_sBBCR_Setting[WIFI_BBCR_BBPC][WIFI_BBPC_NUM-1].idx+1;
    m_sBBCR.index = m_sBBCR_Setting[WIFI_BBCR_IPC][0].idx; // 0x00
    for( i=0; i<m_sBBCR.number; i++ )
        m_sBBCR.flag[i] = false;

    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            if( m_sBBCR_Setting[i][j].checked )
            {
                m_sBBCR.flag[m_sBBCR_Setting[i][j].idx] = true;
            }
        }
    }
#endif
}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::Compose_BBCR_Data( void )
{
    int count=0;
    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            if( m_sBBCR_Setting[i][j].checked )
            {
                m_sBBCR.bb_reg8[count].bbcr_data8 = m_sBBCR_Setting[i][j].value;
                count++;
            }
        }
    }

}

//---------------------------------------------------------------------------
void TfrmWiFiBBCR::DeCompose_BBCR_Data( void )
{
    int count=0;
    for(int i=0; i<WIFI_BBCR_TYPE_NUM; i++ )
    {
        for(int j=0; j<WIFI_BBCR_MAX_NUM; j++ )
        {
            if( m_sBBCR_Setting[i][j].checked )
            {
                m_sBBCR_Setting[i][j].value = m_sBBCR.bb_reg8[count].bbcr_data8;
                count++;
            }
        }
    }

}
