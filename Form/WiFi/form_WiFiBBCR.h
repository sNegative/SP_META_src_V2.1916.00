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
 *   form_WiFiBBCR.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi baseband control register form header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_WIFIBBCR_H_
#define _FORM_WIFIBBCR_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#ifndef  _WIFI_BB_H_
#include "wifi_bb.h"
#endif

//---------------------------------------------------------------------------
class TfrmWiFiBBCR : public TForm
{
__published:	// IDE-managed Components
    TTimer *HintTimer;
    TSaveDialog *SaveDialog;
    TOpenDialog *OpenDialog;
    TPageControl *PageControl1;
    TTabSheet *tsIPTR;
    TTabSheet *tsBBPC;
    TPanel *pnlIPCHeader;
    TCheckBox *cbIPCHeader;
    TPanel *pnlIPC;
    TLabel *lblIPC0;
    TLabel *lblIPCn0;
    TEdit *edtIPC0;
    TLabel *lblIPC1;
    TLabel *lblIPCn1;
    TEdit *edtIPC1;
    TLabel *lblIPC2;
    TEdit *edtIPC2;
    TLabel *lblIPCn2;
    TLabel *lblIPC3;
    TLabel *lblIPCn3;
    TEdit *edtIPC3;
    TLabel *lblIPC4;
    TLabel *lblIPCn4;
    TEdit *edtIPC4;
    TCheckBox *cbIPC0;
    TCheckBox *cbIPC1;
    TCheckBox *cbIPC2;
    TCheckBox *cbIPC3;
    TCheckBox *cbIPC4;
    TPanel *Panel4;
    TPanel *pnlTX;
    TCheckBox *cbTXHeader;
    TLabel *lblTX2;
    TEdit *edtTX2;
    TLabel *lblTXn2;
    TLabel *lblTX3;
    TLabel *lblTXn3;
    TEdit *edtTX3;
    TLabel *lblTX4;
    TLabel *lblTXn4;
    TEdit *edtTX4;
    TLabel *lblTX5;
    TLabel *lblTXn5;
    TEdit *edtTX5;
    TLabel *lblTX6;
    TLabel *lblTXn6;
    TEdit *edtTX6;
    TLabel *lblTX7;
    TLabel *lblTXn7;
    TEdit *edtTX7;
    TLabel *lblTXn0;
    TEdit *edtTX0;
    TLabel *lblTX0;
    TLabel *lblTXn1;
    TEdit *edtTX1;
    TLabel *lblTX1;
    TCheckBox *cbTX0;
    TCheckBox *cbTX1;
    TCheckBox *cbTX2;
    TCheckBox *cbTX3;
    TCheckBox *cbTX4;
    TCheckBox *cbTX5;
    TCheckBox *cbTX6;
    TCheckBox *cbTX7;
    TCheckBox *cbTX8;
    TCheckBox *cbTX9;
    TLabel *lblTX8;
    TLabel *lblTX9;
    TLabel *lblTXn8;
    TLabel *lblTXn9;
    TEdit *edtTX8;
    TEdit *edtTX9;
    TPanel *pnlRXHeader;
    TPanel *pnlRX;
    TLabel *lblRX00;
    TLabel *lblRXn00;
    TEdit *edtRX00;
    TLabel *lblRXn01;
    TEdit *edtRX01;
    TLabel *lblRX01;
    TLabel *lblRX02;
    TLabel *lblRXn02;
    TEdit *edtRX02;
    TLabel *lblRX03;
    TLabel *lblRXn03;
    TEdit *edtRX03;
    TLabel *lblRXn04;
    TEdit *edtRX04;
    TLabel *lblRX04;
    TLabel *lblRXn05;
    TEdit *edtRX05;
    TLabel *lblRX05;
    TLabel *lblRX06;
    TLabel *lblRXn06;
    TEdit *edtRX06;
    TLabel *lblRXn07;
    TEdit *edtRX07;
    TLabel *lblRX07;
    TLabel *lblRXn08;
    TEdit *edtRX08;
    TLabel *lblRX08;
    TLabel *lblRX09;
    TLabel *lblRXn09;
    TEdit *edtRX09;
    TLabel *lblRXn10;
    TEdit *edtRX10;
    TLabel *lblRX10;
    TLabel *lblRX11;
    TLabel *lblRXn11;
    TEdit *edtRX11;
    TLabel *lblRXn12;
    TEdit *edtRX12;
    TLabel *lblRX12;
    TCheckBox *cbRX00;
    TCheckBox *cbRX01;
    TCheckBox *cbRX02;
    TCheckBox *cbRX03;
    TCheckBox *cbRX04;
    TCheckBox *cbRX05;
    TCheckBox *cbRX06;
    TCheckBox *cbRX07;
    TCheckBox *cbRX08;
    TCheckBox *cbRX09;
    TCheckBox *cbRX10;
    TCheckBox *cbRX11;
    TCheckBox *cbRX12;
    TPanel *pnlBBPCHeader;
    TPanel *Panel9;
    TCheckBox *cbBBPC004;
    TCheckBox *cbBBPCHeader;
    TCheckBox *cbBBPC005;
    TCheckBox *cbBBPC006;
    TCheckBox *cbBBPC007;
    TLabel *lblRX13;
    TLabel *lblRXn13;
    TEdit *edtRX13;
    TLabel *lblRX14;
    TLabel *lblRXn14;
    TEdit *edtRX14;
    TLabel *lblBBPC000;
    TEdit *edtBBPC000;
    TLabel *lblBBPCn000;
    TLabel *lblBBPC001;
    TLabel *lblBBPCn001;
    TEdit *edtBBPC001;
    TLabel *lblBBPCn002;
    TEdit *edtBBPC002;
    TLabel *lblBBPC002;
    TLabel *lblBBPCn003;
    TEdit *edtBBPC003;
    TLabel *lblBBPC003;
    TLabel *lblBBPCn004;
    TEdit *edtBBPC004;
    TLabel *lblBBPC004;
    TLabel *lblBBPCn005;
    TEdit *edtBBPC005;
    TLabel *lblBBPC005;
    TLabel *lblBBPCn006;
    TEdit *edtBBPC006;
    TLabel *lblBBPC006;
    TLabel *lblBBPCn007;
    TEdit *edtBBPC007;
    TLabel *lblBBPC007;
    TLabel *lblBBPCn008;
    TEdit *edtBBPC008;
    TLabel *lblBBPC008;
    TLabel *lblBBPCn009;
    TEdit *edtBBPC009;
    TLabel *lblBBPC009;
    TLabel *lblBBPCn010;
    TEdit *edtBBPC010;
    TLabel *lblBBPC010;
    TCheckBox *cbBBPC000;
    TCheckBox *cbBBPC001;
    TCheckBox *cbBBPC002;
    TCheckBox *cbBBPC003;
    TCheckBox *cbBBPC010;
    TCheckBox *cbBBPC009;
    TCheckBox *cbBBPC008;
    TLabel *lblBBPC011;
    TEdit *edtBBPC011;
    TLabel *lblBBPCn011;
    TLabel *lblBBPCn012;
    TEdit *edtBBPC012;
    TLabel *lblBBPC012;
    TLabel *lblBBPC013;
    TLabel *lblBBPCn013;
    TEdit *edtBBPC013;
    TLabel *lblBBPC014;
    TEdit *edtBBPC014;
    TLabel *lblBBPCn014;
    TLabel *lblBBPCn015;
    TEdit *edtBBPC015;
    TLabel *lblBBPC015;
    TCheckBox *cbBBPC011;
    TCheckBox *cbBBPC012;
    TCheckBox *cbBBPC013;
    TCheckBox *cbBBPC014;
    TCheckBox *cbBBPC015;
    TLabel *lblBBPC016;
    TLabel *lblBBPCn016;
    TEdit *edtBBPC016;
    TLabel *lblBBPCn017;
    TEdit *edtBBPC017;
    TLabel *lblBBPC017;
    TLabel *lblBBPC018;
    TLabel *lblBBPCn018;
    TEdit *edtBBPC018;
    TCheckBox *cbBBPC016;
    TCheckBox *cbBBPC017;
    TCheckBox *cbBBPC018;
    TLabel *lblBBPC019;
    TLabel *lblBBPCn019;
    TEdit *edtBBPC019;
    TLabel *lblBBPC020;
    TEdit *edtBBPC020;
    TLabel *lblBBPCn020;
    TLabel *lblBBPC021;
    TLabel *lblBBPCn021;
    TEdit *edtBBPC021;
    TLabel *lblBBPCn022;
    TEdit *edtBBPC022;
    TLabel *lblBBPC022;
    TLabel *lblBBPCn023;
    TEdit *edtBBPC023;
    TLabel *lblBBPC023;
    TCheckBox *cbBBPC019;
    TCheckBox *cbBBPC020;
    TCheckBox *cbBBPC021;
    TCheckBox *cbBBPC022;
    TCheckBox *cbBBPC023;
    TLabel *lblBBPC024;
    TLabel *lblBBPCn024;
    TEdit *edtBBPC024;
    TLabel *lblBBPC025;
    TLabel *lblBBPCn025;
    TEdit *edtBBPC025;
    TLabel *lblBBPCn026;
    TEdit *edtBBPC026;
    TLabel *lblBBPC026;
    TLabel *lblBBPCn027;
    TEdit *edtBBPC027;
    TLabel *lblBBPC027;
    TLabel *lblBBPC028;
    TLabel *lblBBPCn028;
    TEdit *edtBBPC028;
    TLabel *lblBBPC029;
    TLabel *lblBBPCn029;
    TEdit *edtBBPC029;
    TLabel *lblBBPCn030;
    TEdit *edtBBPC030;
    TLabel *lblBBPC030;
    TCheckBox *cbBBPC024;
    TCheckBox *cbBBPC025;
    TCheckBox *cbBBPC026;
    TCheckBox *cbBBPC027;
    TCheckBox *cbBBPC028;
    TCheckBox *cbBBPC029;
    TCheckBox *cbBBPC030;
    TLabel *lblBBPC031;
    TLabel *lblBBPCn031;
    TEdit *edtBBPC031;
    TCheckBox *cbBBPC031;
    TLabel *lblBBPC032;
    TLabel *lblBBPCn032;
    TEdit *edtBBPC032;
    TLabel *lblBBPCn033;
    TEdit *edtBBPC033;
    TLabel *lblBBPC033;
    TLabel *lblBBPCn034;
    TEdit *edtBBPC034;
    TLabel *lblBBPC034;
    TLabel *lblBBPCn035;
    TEdit *edtBBPC035;
    TLabel *lblBBPC035;
    TLabel *lblBBPC036;
    TLabel *lblBBPCn036;
    TEdit *edtBBPC036;
    TLabel *lblBBPC037;
    TLabel *lblBBPCn037;
    TEdit *edtBBPC037;
    TLabel *lblBBPC038;
    TEdit *edtBBPC038;
    TLabel *lblBBPCn038;
    TLabel *lblBBPCn039;
    TEdit *edtBBPC039;
    TLabel *lblBBPC039;
    TCheckBox *cbBBPC032;
    TCheckBox *cbBBPC033;
    TCheckBox *cbBBPC034;
    TCheckBox *cbBBPC035;
    TCheckBox *cbBBPC036;
    TCheckBox *cbBBPC037;
    TCheckBox *cbBBPC038;
    TCheckBox *cbBBPC039;
    TLabel *lblBBPC040;
    TEdit *edtBBPC040;
    TLabel *lblBBPCn040;
    TLabel *lblBBPCn041;
    TEdit *edtBBPC041;
    TLabel *lblBBPC041;
    TLabel *lblBBPCn042;
    TEdit *edtBBPC042;
    TLabel *lblBBPC042;
    TLabel *lblBBPCn043;
    TEdit *edtBBPC043;
    TLabel *lblBBPC043;
    TLabel *lblBBPCn044;
    TEdit *edtBBPC044;
    TLabel *lblBBPC044;
    TLabel *lblBBPCn045;
    TEdit *edtBBPC045;
    TLabel *lblBBPC045;
    TLabel *lblBBPCn046;
    TEdit *edtBBPC046;
    TLabel *lblBBPC046;
    TLabel *lblBBPCn047;
    TEdit *edtBBPC047;
    TLabel *lblBBPC047;
    TCheckBox *cbBBPC040;
    TCheckBox *cbBBPC041;
    TCheckBox *cbBBPC042;
    TCheckBox *cbBBPC043;
    TCheckBox *cbBBPC044;
    TCheckBox *cbBBPC045;
    TCheckBox *cbBBPC046;
    TCheckBox *cbBBPC047;
    TLabel *lblBBPC048;
    TEdit *edtBBPC048;
    TLabel *lblBBPCn048;
    TLabel *lblBBPCn049;
    TLabel *lblBBPC049;
    TEdit *edtBBPC049;
    TLabel *lblBBPC050;
    TLabel *lblBBPCn050;
    TEdit *edtBBPC050;
    TLabel *lblBBPC051;
    TLabel *lblBBPCn051;
    TEdit *edtBBPC051;
    TLabel *lblBBPC052;
    TLabel *lblBBPCn052;
    TEdit *edtBBPC052;
    TLabel *lblBBPCn053;
    TEdit *edtBBPC053;
    TLabel *lblBBPC053;
    TEdit *edtBBPC054;
    TLabel *lblBBPCn054;
    TLabel *lblBBPC054;
    TEdit *edtBBPC055;
    TLabel *lblBBPCn055;
    TLabel *lblBBPC055;
    TCheckBox *cbBBPC048;
    TCheckBox *cbBBPC049;
    TCheckBox *cbBBPC050;
    TCheckBox *cbBBPC051;
    TCheckBox *cbBBPC052;
    TCheckBox *cbBBPC053;
    TCheckBox *cbBBPC054;
    TCheckBox *cbBBPC055;
    TLabel *lblBBPC056;
    TLabel *lblBBPCn056;
    TEdit *edtBBPC056;
    TLabel *lblBBPCn057;
    TLabel *lblBBPC057;
    TEdit *edtBBPC057;
    TLabel *lblBBPC058;
    TEdit *edtBBPC058;
    TLabel *lblBBPCn058;
    TLabel *lblBBPCn059;
    TEdit *edtBBPC059;
    TLabel *lblBBPC059;
    TLabel *lblBBPCn060;
    TEdit *edtBBPC060;
    TLabel *lblBBPC060;
    TLabel *lblBBPCn061;
    TLabel *lblBBPC061;
    TEdit *edtBBPC061;
    TLabel *lblBBPCn062;
    TLabel *lblBBPC062;
    TEdit *edtBBPC062;
    TEdit *edtBBPC063;
    TLabel *lblBBPCn063;
    TLabel *lblBBPC063;
    TLabel *lblBBPC064;
    TLabel *lblBBPCn064;
    TEdit *edtBBPC064;
    TLabel *lblBBPC065;
    TLabel *lblBBPCn065;
    TEdit *edtBBPC065;
    TCheckBox *cbBBPC056;
    TCheckBox *cbBBPC057;
    TCheckBox *cbBBPC058;
    TCheckBox *cbBBPC059;
    TCheckBox *cbBBPC060;
    TCheckBox *cbBBPC061;
    TCheckBox *cbBBPC062;
    TCheckBox *cbBBPC063;
    TLabel *lblBBPC066;
    TLabel *lblBBPCn066;
    TEdit *edtBBPC066;
    TLabel *lblBBPCn067;
    TEdit *edtBBPC067;
    TLabel *lblBBPC067;
    TLabel *lblBBPC073;
    TEdit *edtBBPC073;
    TLabel *lblBBPCn073;
    TLabel *lblBBPC072;
    TEdit *edtBBPC072;
    TLabel *lblBBPCn072;
    TEdit *edtBBPC071;
    TLabel *lblBBPCn071;
    TLabel *lblBBPC071;
    TLabel *lblBBPC070;
    TEdit *edtBBPC070;
    TLabel *lblBBPCn070;
    TEdit *edtBBPC069;
    TLabel *lblBBPCn069;
    TLabel *lblBBPC069;
    TLabel *lblBBPC068;
    TEdit *edtBBPC068;
    TLabel *lblBBPCn068;
    TStatusBar *sbWiFiBBCR;
    TCheckBox *cbRX13;
    TCheckBox *cbRX14;
    TCheckBox *cbBBPC064;
    TCheckBox *cbBBPC065;
    TCheckBox *cbBBPC071;
    TCheckBox *cbBBPC070;
    TCheckBox *cbBBPC069;
    TCheckBox *cbBBPC068;
    TCheckBox *cbBBPC067;
    TCheckBox *cbBBPC066;
    TCheckBox *cbBBPC072;
    TCheckBox *cbBBPC073;
    TCheckBox *cbRXHeader;
    TButton *btnReadFromRegister;
    TButton *btnWriteToRegister;
    TButton *btnLoadFromFile;
    TButton *btnSaveToFile;
    TButton *btnIPTRBBCRData;
    TShape *Shape1;
    TLabel *Label40;
    TShape *Shape2;
    TLabel *Label1;
    TButton *btnBBPCBBCRData;
    TShape *Shape3;
    TLabel *Label2;
    TShape *Shape4;
    TLabel *Label3;
    TStaticText *lblHint;
    void __fastcall cbIPCHeaderClick(TObject *Sender);
    void __fastcall cbTXHeaderClick(TObject *Sender);
    void __fastcall cbRXHeaderClick(TObject *Sender);
    void __fastcall cbBBPCHeaderClick(TObject *Sender);
    void __fastcall edtBBPCCheck(TObject *Sender);
    void __fastcall edtIPCCheck(TObject *Sender);
    void __fastcall edtTXCheck(TObject *Sender);
    void __fastcall edtRXCheck(TObject *Sender);
    void __fastcall cbIPCClick(TObject *Sender);
    void __fastcall cbTXClick(TObject *Sender);
    void __fastcall cbRXClick(TObject *Sender);
    void __fastcall cbBBPCClick(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall btnIPTRBBCRDataClick(TObject *Sender);
    void __fastcall btnBBPCBBCRDataClick(TObject *Sender);
    void __fastcall btnWriteToRegisterClick(TObject *Sender);
    void __fastcall btnReadFromRegisterClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
private:	// User declarations
    TCheckBox *cbIPC[WIFI_IPC_NUM];
    TCheckBox *cbTX[WIFI_TX_NUM];
    TCheckBox *cbRX[WIFI_RX_NUM];
    TCheckBox *cbBBPC[WIFI_BBPC_NUM];
    TLabel *lblIPC[WIFI_IPC_NUM];
    TLabel *lblTX[WIFI_TX_NUM];
    TLabel *lblRX[WIFI_RX_NUM];
    TLabel *lblBBPC[WIFI_BBPC_NUM];
    TLabel *lblIPCn[WIFI_IPC_NUM];
    TLabel *lblTXn[WIFI_TX_NUM];
    TLabel *lblRXn[WIFI_RX_NUM];
    TLabel *lblBBPCn[WIFI_BBPC_NUM];
    TEdit *edtIPC[WIFI_IPC_NUM];
    TEdit *edtTX[WIFI_TX_NUM];
    TEdit *edtRX[WIFI_RX_NUM];
    TEdit *edtBBPC[WIFI_BBPC_NUM];

    S_WIFI_BBCR_SETTING  m_sBBCR_Setting[WIFI_BBCR_TYPE_NUM][WIFI_BBCR_MAX_NUM];
    CWIFIBB   m_WIFI_BB_Obj;
    S_WiFi_BBCR m_sBBCR;
public:		// User declarations
    __fastcall TfrmWiFiBBCR(TComponent* Owner);
    // UI
    void  ReDrawFields( void );
    bool  CheckFields( void );
    void  ShowHintLabel( TControl *sender, char* hint );
    void  CurrentPageLock( void );
    void  CurrentPageReset( void );

    // BBCR read/write
    void  Compose_BBCR_Parameter( void );
    void  Compose_BBCR_Data( void );
    void  DeCompose_BBCR_Data( void );

    // call back
    void  ConfirmCallback_ReadReg( void );
    void  ConfirmCallback_WriteReg( void );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWiFiBBCR *frmWiFiBBCR;
//---------------------------------------------------------------------------
#endif
