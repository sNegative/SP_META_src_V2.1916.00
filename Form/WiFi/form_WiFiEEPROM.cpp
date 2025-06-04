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
 *   form_WiFiEEPROM.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi EEPROM form source
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
//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>

#pragma hdrstop

// form
#ifndef _FORM_WIFIEEPROM_H_
#include "form_WiFiEEPROM.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

// misc
#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFiEEPROM *frmWiFiEEPROM;

#define    PNLIDX_WGI       0x01
#define    PNLIDX_TXDC      0x02
#define    PNLIDX_2400MTXP  0x04

//---------------------------------------------------------------------------
void ConfirmCallback_ReadEE( void )
{
    frmWiFiEEPROM->ConfirmCallback_ReadEE();
}

//---------------------------------------------------------------------------
void ConfirmCallback_WriteEE( void )
{
    frmWiFiEEPROM->ConfirmCallback_WriteEE();
}

//---------------------------------------------------------------------------
__fastcall TfrmWiFiEEPROM::TfrmWiFiEEPROM(TComponent* Owner)
    : TForm(Owner)
{
    edtCCKCHDAC[ 0] = edtCCKCHDAC00;
    edtCCKCHDAC[ 1] = edtCCKCHDAC01;
    edtCCKCHDAC[ 2] = edtCCKCHDAC02;
    edtCCKCHDAC[ 3] = edtCCKCHDAC03;
    edtCCKCHDAC[ 4] = edtCCKCHDAC04;
    edtCCKCHDAC[ 5] = edtCCKCHDAC05;
    edtCCKCHDAC[ 6] = edtCCKCHDAC06;
    edtCCKCHDAC[ 7] = edtCCKCHDAC07;
    edtCCKCHDAC[ 8] = edtCCKCHDAC08;
    edtCCKCHDAC[ 9] = edtCCKCHDAC09;
    edtCCKCHDAC[10] = edtCCKCHDAC0A;
    edtCCKCHDAC[11] = edtCCKCHDAC0B;
    edtCCKCHDAC[12] = edtCCKCHDAC0C;
    edtCCKCHDAC[13] = edtCCKCHDAC0D;

    edtOFDMCHDAC[ 0] = edtOFDMCHDAC00;
    edtOFDMCHDAC[ 1] = edtOFDMCHDAC01;
    edtOFDMCHDAC[ 2] = edtOFDMCHDAC02;
    edtOFDMCHDAC[ 3] = edtOFDMCHDAC03;
    edtOFDMCHDAC[ 4] = edtOFDMCHDAC04;
    edtOFDMCHDAC[ 5] = edtOFDMCHDAC05;
    edtOFDMCHDAC[ 6] = edtOFDMCHDAC06;
    edtOFDMCHDAC[ 7] = edtOFDMCHDAC07;
    edtOFDMCHDAC[ 8] = edtOFDMCHDAC08;
    edtOFDMCHDAC[ 9] = edtOFDMCHDAC09;
    edtOFDMCHDAC[10] = edtOFDMCHDAC0A;
    edtOFDMCHDAC[11] = edtOFDMCHDAC0B;
    edtOFDMCHDAC[12] = edtOFDMCHDAC0C;
    edtOFDMCHDAC[13] = edtOFDMCHDAC0D;

    Init();
    
    for(int i=0; i<6; i++)
    {
    	   edtMACAddr[i] = NULL;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFiEEPROM::Init( void )
{
    m_bInit          = true;
    m_sEEGeneral.usReserved0 = 0x0000;
    m_sEEGeneral.usReserved1 = 0x0000;
    m_sEEGeneral.ucReserved2 = 0x00;
    m_usReserved3 = 0x0000;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::FormShow(TObject *Sender)
{
    if( m_bInit )
    {
        m_bInit = false;
        m_sWiFiCap = frmMainSel->Get_FinalWiFiCap();
    }
}
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
void  TfrmWiFiEEPROM::ReDrawFields( int idx )
{
    int i;
    char str[256];

    if( idx & PNLIDX_WGI )
    {
        if( 0 == btnWGI->Tag ) // Dec
        {
            btnWGI->Caption = "Dec";

            lblBBChipID0x->Visible = false;
            lblRFChipID0x->Visible = false;
            lblSN0x->Visible = false;
            lblMACAddr0x->Visible = false;
            lblChecksum0x->Visible = false;

            edtBBChipID->Text = IntToStr( m_sEEGeneral.usBBChipID );
            edtRFChipID->Text = IntToStr( m_sEEGeneral.usRFChipID );
            edtSN->Text       = IntToStr( m_sEEGeneral.uiSN );
            for( i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
            {
                edtMACAddr[i]->Text  = IntToStr( m_sEEGeneral.sMACAddr.mac_addr[i] );
            }
            edtChecksum->Text = IntToStr( m_sEEGeneral.ucChecksum );
        }
        else
        {

            btnWGI->Caption = "Hex";

            lblBBChipID0x->Visible = true;
            lblRFChipID0x->Visible = true;
            lblSN0x->Visible = true;
            lblMACAddr0x->Visible = true;
            lblChecksum0x->Visible = true;

            sprintf( str, "%X", m_sEEGeneral.usBBChipID );
            edtBBChipID->Text = str;
            sprintf( str, "%X", m_sEEGeneral.usRFChipID );
            edtRFChipID->Text = str;
            sprintf( str, "%X", m_sEEGeneral.uiSN );
            edtSN->Text = str;
            for( i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
            {
                sprintf( str, "%X", m_sEEGeneral.sMACAddr.mac_addr[i] );
                edtMACAddr[i]->Text = str;
            }
            sprintf( str, "%X", m_sEEGeneral.ucChecksum );
            edtChecksum->Text = str;
        }
    }

    if( idx & PNLIDX_TXDC )
    {
        if( 0 == btnTXDC->Tag ) // Dec
        {
            btnTXDC->Caption = "Dec";

            lblTXIDC0x->Visible = false;
            lblTXQDC0x->Visible = false;

            edtTXIDC->Text = IntToStr( m_sEEGeneral.sTxDcOffset.i_ch_offset );
            edtTXQDC->Text = IntToStr( m_sEEGeneral.sTxDcOffset.q_ch_offset );
        }
        else // Hex
        {
            btnTXDC->Caption = "Hex";

            lblTXIDC0x->Visible = true;
            lblTXQDC0x->Visible = true;

            sprintf( str, "%X", m_sEEGeneral.sTxDcOffset.i_ch_offset );
            edtTXIDC->Text = str;
            sprintf( str, "%X", m_sEEGeneral.sTxDcOffset.q_ch_offset );
            edtTXQDC->Text = str;

        }
    }

    if( idx & PNLIDX_2400MTXP )
    {
        if( 0 == btn2400MTXP->Tag ) // Dec
        {
            btn2400MTXP->Caption = "Dec";

            for(i=0; i<NUM_TX_POWER_2400M_CH; i++)
            {
                edtCCKCHDAC[i]->Text = IntToStr( m_sTxPwr2400M.CCKTxPWR[i] );
                edtOFDMCHDAC[i]->Text = IntToStr( m_sTxPwr2400M.OFDMTxPWR[i] );
            }
        }
        else
        {
            btn2400MTXP->Caption = "Hex";

            for(i=0; i<NUM_TX_POWER_2400M_CH; i++)
            {
                sprintf( str, "%X", m_sTxPwr2400M.CCKTxPWR[i] );
                edtCCKCHDAC[i]->Text = str;
                sprintf( str, "%X", m_sTxPwr2400M.OFDMTxPWR[i] );
                edtOFDMCHDAC[i]->Text = str;

            }
        }
    }
}

//---------------------------------------------------------------------------
bool  TfrmWiFiEEPROM::CheckFields( void )
{
    AnsiString text;
    unsigned char ucdata;
    unsigned short usdata;
    unsigned int uidata;
    int i;
    if( 0 == btnWGI->Tag ) // Dec
    {
        // General information
        text = edtBBChipID->Text;
        if( !IsValidDecWiFiBBChipID( text, usdata ) )
        {
            edtBBChipIDCheck(edtBBChipID);
            return false;
        }
        m_sEEGeneral.usBBChipID = usdata;

        text = edtRFChipID->Text;
        if( !IsValidDecWiFiRFChipID( text, usdata ) )
        {
            edtRFChipIDCheck(edtRFChipID);
            return false;
        }
        m_sEEGeneral.usRFChipID = usdata;

        text = edtSN->Text;
        if( !IsValidDecWiFiSN( text, uidata ) )
        {
            edtSNCheck(edtSN);
            return false;
        }
        m_sEEGeneral.uiSN = uidata;

        for( i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
        {
            text = edtMACAddr[i]->Text;
            if( !IsValidDecWiFiMACAddress( text, ucdata ) )
            {
                edtMACAddrCheck(edtMACAddr[i]);
                return false;
            }
            m_sEEGeneral.sMACAddr.mac_addr[i] = ucdata;
        }
    }
    else  // Hex
    {
        // General information
        text = edtBBChipID->Text;
        if( !IsValidHexWiFiBBChipID( text, usdata ) )
        {
            edtBBChipIDCheck(edtBBChipID);
            return false;
        }
        m_sEEGeneral.usBBChipID = usdata;

        text = edtRFChipID->Text;
        if( !IsValidHexWiFiRFChipID( text, usdata ) )
        {
            edtRFChipIDCheck(edtRFChipID);
            return false;
        }
        m_sEEGeneral.usRFChipID = usdata;

        text = edtSN->Text;
        if( !IsValidHexWiFiSN( text, &uidata ) )
        {
            edtSNCheck(edtSN);
            return false;
        }
        m_sEEGeneral.uiSN = uidata;

        for( i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
        {
            text = edtMACAddr[i]->Text;
            if( !IsValidHexWiFiMACAddress( text, ucdata ) )
            {
                edtMACAddrCheck(edtMACAddr[i]);
                return false;
            }
            m_sEEGeneral.sMACAddr.mac_addr[i] = ucdata;
        }
    }
    return true;
}

//---------------------------------------------------------------------------
void  TfrmWiFiEEPROM::CurrentPageReset( void )
{
    // WiFi general information
    btnWGI->Enabled = true;
    edtBBChipID->Enabled = true;
    edtRFChipID->Enabled = true;
    edtSN->Enabled = true;
    for(int i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
    {
        edtMACAddr[i]->Enabled = true;
    }

    // TX DC offset
    btnTXDC->Enabled = true;

    // 2.4G TX power table
    btn2400MTXP->Enabled = true;

    btnUploadFromEEPROM->Enabled = true;
    btnDownloadToEEPROM->Enabled = true;
    btnLoadFromFile->Enabled = true;
    btnSaveToFile->Enabled = true;
}

//---------------------------------------------------------------------------
void  TfrmWiFiEEPROM::CurrentPageLock( void )
{
    // WiFi general information
    btnWGI->Enabled = false;
    edtBBChipID->Enabled = false;
    edtRFChipID->Enabled = false;
    edtSN->Enabled = false;
    for(int i=0; i<sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
    {
        edtMACAddr[i]->Enabled = false;
    }

    // TX DC offset
    btnTXDC->Enabled = false;

    // 2.4G TX power table
    btn2400MTXP->Enabled = false;

    btnUploadFromEEPROM->Enabled = false;
    btnDownloadToEEPROM->Enabled = false;
    btnLoadFromFile->Enabled = false;
    btnSaveToFile->Enabled = false;
}

//--------------------------------------------------------------------------
void  TfrmWiFiEEPROM::ShowHintLabel( TControl *sender, char* hint )
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
void __fastcall TfrmWiFiEEPROM::btnWGIClick(TObject *Sender)
{
    if( 0 == btnWGI->Tag )  // Dec-->Hex
    {
        btnWGI->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnWGI->Tag = 0;
    }
    ReDrawFields( PNLIDX_WGI );
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::btnTXDCClick(TObject *Sender)
{
    if( 0 == btnTXDC->Tag )  // Dec-->Hex
    {
        btnTXDC->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btnTXDC->Tag = 0;
    }
    ReDrawFields( PNLIDX_TXDC );
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::btn2400MTXPClick(TObject *Sender)
{
    if( 0 == btn2400MTXP->Tag )  // Dec-->Hex
    {
        btn2400MTXP->Tag = 1;
    }
    else  //Hex-->Dec
    {
        btn2400MTXP->Tag = 0;
    }
    ReDrawFields( PNLIDX_2400MTXP );
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFiEEPROM::edtBBChipIDCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned short  usdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~65535 ";

    text = edit->Text;

    if( 0 == btnWGI->Tag ) // Dec
    {
        if( !IsValidDecWiFiBBChipID( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiBBChipID( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sEEGeneral.usBBChipID = usdata;
}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFiEEPROM::edtRFChipIDCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned short  usdata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~65535 ";

    text = edit->Text;

    if( 0 == btnWGI->Tag ) // Dec
    {
        if( !IsValidDecWiFiRFChipID( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiRFChipID( text, usdata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sEEGeneral.usRFChipID = usdata;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiEEPROM::edtSNCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~0xFFFFFFFF ";

    text = edit->Text;

    if( 0 == btnWGI->Tag ) // Dec
    {
        if( !IsValidDecWiFiSN( text, uidata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiSN( text, &uidata ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sEEGeneral.uiSN = uidata;
}
//---------------------------------------------------------------------------



void __fastcall TfrmWiFiEEPROM::edtMACAddrCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned char  mac_addr_char;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0x00~0xFF ";

    text = edit->Text;


    if( 0 == btnWGI->Tag ) // Dec
    {
        if( !IsValidDecWiFiMACAddress( text, mac_addr_char ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexWiFiMACAddress( text, mac_addr_char ) )
        {
            ShowHintLabel( edit, hint );
            edit->SetFocus();
            return;
        }
    }

    m_sEEGeneral.sMACAddr.mac_addr[edit->Tag] = mac_addr_char;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::btnUploadFromEEPROMClick(TObject *Sender)
{

    m_sEE.count          = WIFI_EE_LEN_BB_CHIP_ID   +
                           WIFI_EE_LEN_RF_CHIP_ID   +
                           WIFI_EE_LEN_SN           +
                           WIFI_EE_LEN_MAC_ADDR     +
                           WIFI_EE_LEN_RESERVED0    +
                           WIFI_EE_LEN_TX_IQ        +
                           WIFI_EE_LEN_RESERVED1    +
                           WIFI_EE_LEN_RESERVED2    +
                           WIFI_EE_LEN_CHECKSUM     +
                           WIFI_EE_LEN_TXP_2_4_G;

    for (unsigned int i=0; i<m_sEE.count; i++ )
    {
        m_sEE.eeprom[i].index = 2*i;
    }

    m_WIFI_EE_Obj.ConfirmCallback = ::ConfirmCallback_ReadEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start( m_sEE );

    sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM progressing";

}

//---------------------------------------------------------------------------
void TfrmWiFiEEPROM::ConfirmCallback_ReadEE( void )
{

    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        ReDrawFields( PNLIDX_WGI | PNLIDX_TXDC | PNLIDX_2400MTXP );
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM fail";
        Application->MessageBox( "Execution Fail : Read EEPROM", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Read EEPROM", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Read EEPROM stop";
    }
    break;
    }
    CurrentPageReset();

}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::btnDownloadToEEPROMClick(TObject *Sender)
{

    // m_sEE.eeprom_index = WIFI_EE_ADDR_BB_CHIP_ID;
    m_sEE.count          = WIFI_EE_LEN_BB_CHIP_ID   +
                           WIFI_EE_LEN_RF_CHIP_ID   +
                           WIFI_EE_LEN_SN           +
                           WIFI_EE_LEN_MAC_ADDR     +
                           WIFI_EE_LEN_RESERVED0    +
                           WIFI_EE_LEN_TX_IQ        +
                           WIFI_EE_LEN_RESERVED1    +
                           WIFI_EE_LEN_RESERVED2    +
                           WIFI_EE_LEN_CHECKSUM     +
                           WIFI_EE_LEN_TXP_2_4_G;





    for (unsigned int i=0; i<m_sEE.count; i++)
    {
        m_sEE.eeprom[i].index = 2*i;
    }

    m_sEEGeneral.ucChecksum = m_WIFI_EE_Obj.Calculate_Checksum( m_sEEGeneral );
    Compose_EEPROM_Data();

    m_WIFI_EE_Obj.ConfirmCallback = ::ConfirmCallback_WriteEE;
    m_WIFI_EE_Obj.REQ_Write_To_EE_Start( m_sEE );

    sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM progressing";

}

//---------------------------------------------------------------------------
void TfrmWiFiEEPROM::ConfirmCallback_WriteEE( void )
{

    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM fail";
        Application->MessageBox( "Execution Timeout : Write EEPROM", "FAIL", MB_OK );

    }
    break;

    case META_TIMEOUT:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Write EEPROM", "TIMEOUT", MB_OK );

    }
    break;

    case METAAPP_STOP:
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString)"  Write EEPROM stop";
    }
    break;
    }
    CurrentPageReset();

}

//---------------------------------------------------------------------------

void __fastcall TfrmWiFiEEPROM::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;
    //float  fdata;

    ok = OpenDialog->Execute();
    if( !ok )
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Load WiFi EEPROM setting from file fail";
        return;
    }
    strcpy( str, OpenDialog->FileName.c_str() );

    // General information
    //if( cbWGIHeader->Checked )
    {
        ok = m_WIFI_EE_Obj.REQ_Read_General_Info_From_File( str );
        if( !ok )
        {
            sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Load WiFi EEPROM setting from file fail";
            Application->MessageBox( "Execution Failure : Load WiFi EEPROM setting from file", "FAILURE", MB_OK );
            return;
        }
        m_sEEGeneral = m_WIFI_EE_Obj.Get_EEGeneral();
    }

    ReDrawFields( PNLIDX_WGI | PNLIDX_TXDC | PNLIDX_2400MTXP );
    sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Load WiFi TX setting from file successfully";
}
//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if( !ok )
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file fail";
        return;
    }

    if( ! CheckFields() )
    {
        sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file fail";
        return;
    }

    strcpy( str, SaveDialog->FileName.c_str() );

    /// General information
    // if( cbWGIHeader->Checked )
    {
        m_WIFI_EE_Obj.Set_EEGeneral( m_sEEGeneral );
        ok = m_WIFI_EE_Obj.REQ_Write_General_Info_To_File( str );
        if( !ok )
        {
            sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file fail";
            Application->MessageBox( "Execution Failure : Save WiFi EEPROM setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    // TX DC offset
    // if( cbTXDCHeader->Checked )
    {
        m_WIFI_EE_Obj.Set_TxDcOffset( m_sEEGeneral.sTxDcOffset );
        ok = m_WIFI_EE_Obj.REQ_Write_TX_DC_Offset_To_File( str );
        if( !ok )
        {
            sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file fail";
            Application->MessageBox( "Execution Failure : Save WiFi EEPROM setting to file", "FAILURE", MB_OK );
            return;
        }
    }

    // 2.4G TX power table
    // if( cb2400MTXPHeader->Checked )
    {
        if( m_sWiFiCap.support_802_11g || m_sWiFiCap.support_802_11b )
        {
            m_WIFI_EE_Obj.Set_TxChannelDac2400M( m_sTxPwr2400M );
            ok = m_WIFI_EE_Obj.REQ_Write_TxPower2400M_To_File( str );
            if( !ok )
            {
                sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file fail";
                Application->MessageBox( "Execution Failure : Save WiFi EEPROM setting to file", "FAILURE", MB_OK );
                return;
            }
        }
    }



    sbWiFiEEPROM->Panels->Items[0]->Text = (AnsiString) "  Save WiFi EEPROM setting to file successfully";
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiEEPROM::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}


//---------------------------------------------------------------------------
void TfrmWiFiEEPROM::Compose_EEPROM_Data( void )
{
    // BB chip ID
    m_sEE.eeprom[WIFI_EE_ADDR_BB_CHIP_ID].eeprom_data16   = m_sEEGeneral.usBBChipID;
    // RF chip ID
    m_sEE.eeprom[WIFI_EE_ADDR_RF_CHIP_ID].eeprom_data16   = m_sEEGeneral.usRFChipID;
    // SN
    m_sEE.eeprom[WIFI_EE_ADDR_SN].eeprom_data16           = m_sEEGeneral.uiSN       & 0x0000FFFF;
    m_sEE.eeprom[WIFI_EE_ADDR_SN+1].eeprom_data16         = m_sEEGeneral.uiSN       & 0xFFFF0000 >> 16;
    // MAC address
    for( int i=0; i< sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i=i+2 )
    {
        m_sEE.eeprom[WIFI_EE_ADDR_MAC_ADDR+i/2].eeprom_data16     = m_sEEGeneral.sMACAddr.mac_addr[i] | (m_sEEGeneral.sMACAddr.mac_addr[i+1]<<8);
    }

    // reserved 0
    m_sEE.eeprom[WIFI_EE_ADDR_RESERVED0].eeprom_data16   = m_sEEGeneral.usReserved0;

    // TX DC offset
    m_sEE.eeprom[WIFI_EE_ADDR_TX_IQ].eeprom_data16       = m_sEEGeneral.sTxDcOffset.q_ch_offset;
    m_sEE.eeprom[WIFI_EE_ADDR_TX_IQ].eeprom_data16       = (m_sEE.eeprom[WIFI_EE_ADDR_TX_IQ].eeprom_data16 << 8) |
            m_sEEGeneral.sTxDcOffset.i_ch_offset;

    // reserved 1
    m_sEE.eeprom[WIFI_EE_ADDR_RESERVED1].eeprom_data16   = m_sEEGeneral.usReserved1;

    // checksum
    m_sEE.eeprom[WIFI_EE_ADDR_CHECKSUM].eeprom_data16    = m_sEEGeneral.ucChecksum;
    m_sEE.eeprom[WIFI_EE_ADDR_CHECKSUM].eeprom_data16    = (m_sEE.eeprom[WIFI_EE_ADDR_CHECKSUM].eeprom_data16 << 8) |
            m_sEEGeneral.ucReserved2;
    // reserved 3
    m_sEE.eeprom[WIFI_EE_ADDR_RESERVED3].eeprom_data16   = m_usReserved3;

}

//---------------------------------------------------------------------------
void TfrmWiFiEEPROM::DeCompose_EEPROM_Data( void )
{

    int i;
    //int j;

    // WiFi general information
    // BB chip ID
    m_sEEGeneral.usBBChipID = m_sEE.eeprom[WIFI_EE_ADDR_BB_CHIP_ID].eeprom_data16;

    // RF chip ID
    m_sEEGeneral.usRFChipID = m_sEE.eeprom[WIFI_EE_ADDR_RF_CHIP_ID].eeprom_data16;

    // SN
    m_sEEGeneral.uiSN       = (m_sEE.eeprom[WIFI_EE_ADDR_SN+1].eeprom_data16<<16)  |
                              m_sEE.eeprom[WIFI_EE_ADDR_SN].eeprom_data16;

    // MAC address
    for( i=0; i< sizeof(m_sEEGeneral.sMACAddr.mac_addr)/sizeof(m_sEEGeneral.sMACAddr.mac_addr[0]); i++ )
    {
        if( 0 == i % 2 )
        {
            m_sEEGeneral.sMACAddr.mac_addr[i] = m_sEE.eeprom[WIFI_EE_ADDR_MAC_ADDR+i/2].eeprom_data16 & 0x00FF;
        }
        else
        {
            m_sEEGeneral.sMACAddr.mac_addr[i] = (m_sEE.eeprom[WIFI_EE_ADDR_MAC_ADDR+i/2].eeprom_data16 & 0xFF00) >> 8;
        }
    }

    // reserve 0
    m_sEEGeneral.usReserved0 = m_sEE.eeprom[WIFI_EE_ADDR_RESERVED0].eeprom_data16;

    // TX IQ offset
    m_sEEGeneral.sTxDcOffset.q_ch_offset = (m_sEE.eeprom[WIFI_EE_ADDR_TX_IQ].eeprom_data16&0xFF00)>>8;
    m_sEEGeneral.sTxDcOffset.i_ch_offset = m_sEE.eeprom[WIFI_EE_ADDR_TX_IQ].eeprom_data16&0x00FF;

    // reserved 1
    m_sEEGeneral.usReserved1 = m_sEE.eeprom[WIFI_EE_ADDR_RESERVED1].eeprom_data16;

    // reserved 2
    m_sEEGeneral.ucReserved2    = m_sEE.eeprom[WIFI_EE_ADDR_CHECKSUM].eeprom_data16 & 0xFF00;

    // checksum
    m_sEEGeneral.ucChecksum = (m_sEE.eeprom[WIFI_EE_ADDR_CHECKSUM].eeprom_data16>>8) & 0x00FF;

    // reserved 3
    m_usReserved3 = m_sEE.eeprom[WIFI_EE_ADDR_RESERVED3].eeprom_data16;

    // 2.4G TX power table
    for( i=0; i<NUM_TX_POWER_2400M_CH; i++ )
    {
        m_sTxPwr2400M.CCKTxPWR[i] = m_sEE.eeprom[i].eeprom_data16;
    }

}

