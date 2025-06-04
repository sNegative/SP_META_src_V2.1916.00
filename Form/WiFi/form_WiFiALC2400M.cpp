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
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
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
 *   form_WiFiALC2400M.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi ALC 2.4G form source
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
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#include <vcl.h>
#pragma hdrstop

#ifndef  _METAAPP_COMMON_H_
#include "METAAPP_common.h"
#endif

#ifndef _FORM_WIFIALC2400M_H_
#include "form_WiFiALC2400M.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#ifndef  _MISC_WIFI_H_
#include "misc_wifi.h"
#endif



#ifndef  _MT5911_COMMON_H_
#include "mt5911_common.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWiFiALC2400M *frmWiFiALC2400M;
//===========================================================================
static void CNF_ReadAlc2400MFromNVRAM(void)
{
    frmWiFiALC2400M->UploadAlc2400MFromFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_WriteAlc2400MToNVRAM(void)
{
    frmWiFiALC2400M->DownloadAlc2400MToFlashDone();
}

//---------------------------------------------------------------------------
static void CNF_ReadAlcCCKFromEE(void)
{
    frmWiFiALC2400M->CNF_ReadAlcCCKFromEE();
}

//---------------------------------------------------------------------------
static void CNF_ReadAlcOFDMFromEE(void)
{
    frmWiFiALC2400M->CNF_ReadAlcOFDMFromEE();
}

//---------------------------------------------------------------------------
static void CNF_ReadAlcSlopeFromEE(void)
{
    frmWiFiALC2400M->CNF_ReadAlcSlopeFromEE();
}
//===========================================================================
__fastcall TfrmWiFiALC2400M::TfrmWiFiALC2400M(TComponent* Owner)
    : TForm(Owner)
{
    m_edtTxAlcCCK[ 0] = m_edtTxAlcCCK00;
    m_edtTxAlcCCK[ 1] = m_edtTxAlcCCK01;
    m_edtTxAlcCCK[ 2] = m_edtTxAlcCCK02;
    m_edtTxAlcCCK[ 3] = m_edtTxAlcCCK03;
    m_edtTxAlcCCK[ 4] = m_edtTxAlcCCK04;
    m_edtTxAlcCCK[ 5] = m_edtTxAlcCCK05;
    m_edtTxAlcCCK[ 6] = m_edtTxAlcCCK06;
    m_edtTxAlcCCK[ 7] = m_edtTxAlcCCK07;
    m_edtTxAlcCCK[ 8] = m_edtTxAlcCCK08;
    m_edtTxAlcCCK[ 9] = m_edtTxAlcCCK09;
    m_edtTxAlcCCK[10] = m_edtTxAlcCCK10;
    m_edtTxAlcCCK[11] = m_edtTxAlcCCK11;
    m_edtTxAlcCCK[12] = m_edtTxAlcCCK12;
    m_edtTxAlcCCK[13] = m_edtTxAlcCCK13;

    m_edtTxOutputPowerDbCCK[ 0] = m_edtTxOutputPowerDbCCK00;
    m_edtTxOutputPowerDbCCK[ 1] = m_edtTxOutputPowerDbCCK01;
    m_edtTxOutputPowerDbCCK[ 2] = m_edtTxOutputPowerDbCCK02;
    m_edtTxOutputPowerDbCCK[ 3] = m_edtTxOutputPowerDbCCK03;
    m_edtTxOutputPowerDbCCK[ 4] = m_edtTxOutputPowerDbCCK04;
    m_edtTxOutputPowerDbCCK[ 5] = m_edtTxOutputPowerDbCCK05;
    m_edtTxOutputPowerDbCCK[ 6] = m_edtTxOutputPowerDbCCK06;
    m_edtTxOutputPowerDbCCK[ 7] = m_edtTxOutputPowerDbCCK07;
    m_edtTxOutputPowerDbCCK[ 8] = m_edtTxOutputPowerDbCCK08;
    m_edtTxOutputPowerDbCCK[ 9] = m_edtTxOutputPowerDbCCK09;
    m_edtTxOutputPowerDbCCK[10] = m_edtTxOutputPowerDbCCK10;
    m_edtTxOutputPowerDbCCK[11] = m_edtTxOutputPowerDbCCK11;
    m_edtTxOutputPowerDbCCK[12] = m_edtTxOutputPowerDbCCK12;
    m_edtTxOutputPowerDbCCK[13] = m_edtTxOutputPowerDbCCK13;

    m_btnOFDMTxRate[0] = m_btnOFDMTxRate0;
    m_btnOFDMTxRate[1] = m_btnOFDMTxRate1;
    m_btnOFDMTxRate[2] = m_btnOFDMTxRate2;
    m_btnOFDMTxRate[3] = m_btnOFDMTxRate3;
    m_btnOFDMTxRate[4] = m_btnOFDMTxRate4;
    m_btnOFDMTxRate[5] = m_btnOFDMTxRate5;
    m_btnOFDMTxRate[6] = m_btnOFDMTxRate6;
    m_btnOFDMTxRate[7] = m_btnOFDMTxRate7;

    m_edtOFDMTxAlcOffset[0] = m_edtOFDMTxAlcOffset0;
    m_edtOFDMTxAlcOffset[1] = m_edtOFDMTxAlcOffset1;
    m_edtOFDMTxAlcOffset[2] = m_edtOFDMTxAlcOffset2;
    m_edtOFDMTxAlcOffset[3] = m_edtOFDMTxAlcOffset3;
    m_edtOFDMTxAlcOffset[4] = m_edtOFDMTxAlcOffset4;
    m_edtOFDMTxAlcOffset[5] = m_edtOFDMTxAlcOffset5;
    m_edtOFDMTxAlcOffset[6] = m_edtOFDMTxAlcOffset6;
    m_edtOFDMTxAlcOffset[7] = m_edtOFDMTxAlcOffset7;

    m_edtOFDMTxOutputPowerOffset[0] = m_edtOFDMTxOutputPowerOffset0;
    m_edtOFDMTxOutputPowerOffset[1] = m_edtOFDMTxOutputPowerOffset1;
    m_edtOFDMTxOutputPowerOffset[2] = m_edtOFDMTxOutputPowerOffset2;
    m_edtOFDMTxOutputPowerOffset[3] = m_edtOFDMTxOutputPowerOffset3;
    m_edtOFDMTxOutputPowerOffset[4] = m_edtOFDMTxOutputPowerOffset4;
    m_edtOFDMTxOutputPowerOffset[5] = m_edtOFDMTxOutputPowerOffset5;
    m_edtOFDMTxOutputPowerOffset[6] = m_edtOFDMTxOutputPowerOffset6;
    m_edtOFDMTxOutputPowerOffset[7] = m_edtOFDMTxOutputPowerOffset7;

    m_edtTxAlcOFDM[ 0] = m_edtTxAlcOFDM00;
    m_edtTxAlcOFDM[ 1] = m_edtTxAlcOFDM01;
    m_edtTxAlcOFDM[ 2] = m_edtTxAlcOFDM02;
    m_edtTxAlcOFDM[ 3] = m_edtTxAlcOFDM03;
    m_edtTxAlcOFDM[ 4] = m_edtTxAlcOFDM04;
    m_edtTxAlcOFDM[ 5] = m_edtTxAlcOFDM05;
    m_edtTxAlcOFDM[ 6] = m_edtTxAlcOFDM06;
    m_edtTxAlcOFDM[ 7] = m_edtTxAlcOFDM07;
    m_edtTxAlcOFDM[ 8] = m_edtTxAlcOFDM08;
    m_edtTxAlcOFDM[ 9] = m_edtTxAlcOFDM09;
    m_edtTxAlcOFDM[10] = m_edtTxAlcOFDM10;
    m_edtTxAlcOFDM[11] = m_edtTxAlcOFDM11;
    m_edtTxAlcOFDM[12] = m_edtTxAlcOFDM12;
    m_edtTxAlcOFDM[13] = m_edtTxAlcOFDM13;

    m_edtTxOutputPowerDbOFDM[ 0] = m_edtTxOutputPowerDbOFDM00;
    m_edtTxOutputPowerDbOFDM[ 1] = m_edtTxOutputPowerDbOFDM01;
    m_edtTxOutputPowerDbOFDM[ 2] = m_edtTxOutputPowerDbOFDM02;
    m_edtTxOutputPowerDbOFDM[ 3] = m_edtTxOutputPowerDbOFDM03;
    m_edtTxOutputPowerDbOFDM[ 4] = m_edtTxOutputPowerDbOFDM04;
    m_edtTxOutputPowerDbOFDM[ 5] = m_edtTxOutputPowerDbOFDM05;
    m_edtTxOutputPowerDbOFDM[ 6] = m_edtTxOutputPowerDbOFDM06;
    m_edtTxOutputPowerDbOFDM[ 7] = m_edtTxOutputPowerDbOFDM07;
    m_edtTxOutputPowerDbOFDM[ 8] = m_edtTxOutputPowerDbOFDM08;
    m_edtTxOutputPowerDbOFDM[ 9] = m_edtTxOutputPowerDbOFDM09;
    m_edtTxOutputPowerDbOFDM[10] = m_edtTxOutputPowerDbOFDM10;
    m_edtTxOutputPowerDbOFDM[11] = m_edtTxOutputPowerDbOFDM11;
    m_edtTxOutputPowerDbOFDM[12] = m_edtTxOutputPowerDbOFDM12;
    m_edtTxOutputPowerDbOFDM[13] = m_edtTxOutputPowerDbOFDM13;
    
    memset(m_cOFDMTxAlcOffset,0,sizeof(char)*WIFI_ALC_2400M_TX_RATE_NUM);
    memset(m_cOFDMTxOutputPowerOffset,0,sizeof(char)*WIFI_ALC_2400M_TX_RATE_NUM);

}

//------------------------------------------------------------------------------
void TfrmWiFiALC2400M::ReDrawFields(E_DRAW_MASK_WIFI_ALC2400M mask)
{
    if (mask & DRAW_MASK_WIFI_ALC2400M_CCK_ALC)
    {
        for (int i=0; i<WIFI_ALC_2400M_CH_NUM; i++)
        {
            m_edtTxAlcCCK[i]->Text           = IntToStr(m_sWiFiAlcPower2400M.txAlcCCK[i]);
        }
    }

    if (mask & DRAW_MASK_WIFI_ALC2400M_CCK_POWER)
    {
        for (int i=0; i<WIFI_ALC_2400M_CH_NUM; i++)
        {
            m_edtTxOutputPowerDbCCK[i]->Text = IntToStr(m_sWiFiAlcPower2400M.txOutputPowerDBCCK[i]);
        }
    }

    if (mask & DRAW_MASK_WIFI_ALC2400M_OFDM_OFFSET)
    {
        for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
        {
            m_edtOFDMTxAlcOffset[i]->Text         = IntToStr(m_cOFDMTxAlcOffset[i]);
            m_edtOFDMTxOutputPowerOffset[i]->Text = IntToStr(m_cOFDMTxOutputPowerOffset[i]);
        }
    }

    if (mask & DRAW_MASK_WIFI_ALC2400M_OFDM_ALC)
    {
        for (int i=0; i<WIFI_ALC_2400M_CH_NUM; i++)
        {
            m_edtTxAlcOFDM[i]->Text = IntToStr(m_sWiFiAlcPower2400M.txAlcOFDM[m_pnlOFDMTxRate->Tag][i]);
        }
    }

    if (mask & DRAW_MASK_WIFI_ALC2400M_OFDM_POWER)
    {
        for (int i=0; i<WIFI_ALC_2400M_CH_NUM; i++)
        {
            m_edtTxOutputPowerDbOFDM[i]->Text = IntToStr(m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[m_pnlOFDMTxRate->Tag][i]);
        }
    }

    if (mask & DRAW_MASK_WIFI_ALC2400M_SLOPE)
    {
        m_edtALCSlop1Divider->Text  = IntToStr(m_sWiFiAlcSlope2400M.alcSlop1Divider);
        m_edtALCSlop1Dividend->Text = IntToStr(m_sWiFiAlcSlope2400M.alcSlop1Dividend);
        m_edtALCSlop2Divider->Text  = IntToStr(m_sWiFiAlcSlope2400M.alcSlop2Divider);
        m_edtALCSlop2Dividend->Text = IntToStr(m_sWiFiAlcSlope2400M.alcSlop2Dividend);
    }
}

//---------------------------------------------------------------------------
bool TfrmWiFiALC2400M::CheckFields(E_CHECK_MASK_WIFI_ALC2400M mask)
{
    unsigned char ucdata;

    AnsiString  text;

    if (mask & CHECK_MASK_WIFI_ALC2400M_CCK_ALC)
    {
        for (int i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            text = m_edtTxAlcCCK[i]->Text;
            if (!IsValidWiFiTxAlcCCK(text, ucdata))
            {
                edtTxAlcCCKCheck(m_edtTxAlcCCK[i]);
                return false;
            }
            m_sWiFiAlcPower2400M.txAlcCCK[i] = ucdata;
        }
    }

    if (mask & CHECK_MASK_WIFI_ALC2400M_CCK_POWER)
    {
        for (int i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            text = m_edtTxOutputPowerDbCCK[i]->Text;
            if (!IsValidWiFiTxOutputPowerDbCCK(text, ucdata))
            {
                edtTxOutputPowerDbCCKCheck(m_edtTxOutputPowerDbCCK[i]);
                return false;
            }
            m_sWiFiAlcPower2400M.txOutputPowerDBCCK[i] = ucdata;
        }
    }

    if (mask & CHECK_MASK_WIFI_ALC2400M_OFDM_ALC)
    {
        for (int i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            text = m_edtTxAlcOFDM[i]->Text;
            if (!IsValidWiFiTxOutputPowerDbCCK(text, ucdata))
            {
                edtTxAlcOFDMCheck(m_edtTxAlcOFDM[i]);
                return false;
            }
            m_sWiFiAlcPower2400M.txAlcOFDM[m_pnlOFDMTxRate->Tag][i] = ucdata;
        }
    }

    if (mask & CHECK_MASK_WIFI_ALC2400M_OFDM_POWER)
    {
        for (int i=0; i<NUM_TX_POWER_2400M_CH; i++)
        {
            text = m_edtTxOutputPowerDbOFDM[i]->Text;
            if (!IsValidWiFiTxOutputPowerDbOFDM(text, ucdata))
            {
                edtTxOutputPowerDbOFDMCheck(m_edtTxOutputPowerDbOFDM[i]);
                return false;
            }
            m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[m_pnlOFDMTxRate->Tag][i] = ucdata;
        }
    }

    if (mask & CHECK_MASK_WIFI_ALC2400M_SLOPE)
    {
        // alcSlop1Divider
        text = m_edtALCSlop1Divider->Text;
        if (!IsValidWiFiAlcSlopeDivider(text, ucdata))
        {
            m_edtALCSlopDividerCheck(m_edtALCSlop1Divider);
            return false;
        }
        m_sWiFiAlcSlope2400M.alcSlop1Divider = ucdata;

        // alcSlop1Dividend
        text = m_edtALCSlop1Dividend->Text;
        if (!IsValidWiFiAlcSlopeDividend(text, ucdata))
        {
            m_edtALCSlopDividerCheck(m_edtALCSlop1Dividend);
            return false;
        }
        m_sWiFiAlcSlope2400M.alcSlop1Dividend = ucdata;

        // alcSlop2Divider
        text = m_edtALCSlop2Divider->Text;
        if (!IsValidWiFiAlcSlopeDivider(text, ucdata))
        {
            m_edtALCSlopDividerCheck(m_edtALCSlop2Divider);
            return false;
        }
        m_sWiFiAlcSlope2400M.alcSlop2Divider = ucdata;

        // alcSlop2Dividend
        text = m_edtALCSlop2Dividend->Text;
        if (!IsValidWiFiAlcSlopeDividend(text, ucdata))
        {
            m_edtALCSlopDividerCheck(m_edtALCSlop2Dividend);
            return false;
        }
        m_sWiFiAlcSlope2400M.alcSlop2Dividend = ucdata;
    }

    return true;
}

//---------------------------------------------------------------------------
void TfrmWiFiALC2400M::CurrentPageReset(void)
{
    btnUploadFromFlash->Enabled = true;
    btnDownloadToFlash->Enabled = true;
    btnChangeDB->Enabled = true;
}

//---------------------------------------------------------------------------
void TfrmWiFiALC2400M::CurrentPageLock(void)
{
    btnUploadFromFlash->Enabled = false;
    btnDownloadToFlash->Enabled = false;
    btnChangeDB->Enabled = false;
}

//--------------------------------------------------------------------------
void TfrmWiFiALC2400M::ShowHintLabel(TControl *sender, char* hint)
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
void __fastcall TfrmWiFiALC2400M::edtTxAlcCCKCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if (!IsValidWiFiTxAlcCCK(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_sWiFiAlcPower2400M.txAlcCCK[edit->Tag] = uc_data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::edtTxOutputPowerDbCCKCheck(
    TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if (!IsValidWiFiTxOutputPowerDbCCK(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_sWiFiAlcPower2400M.txOutputPowerDBCCK[edit->Tag] = uc_data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::edtTxAlcOFDMCheck(TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if (!IsValidWiFiTxAlcOFDM(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_sWiFiAlcPower2400M.txAlcOFDM[m_pnlOFDMTxRate->Tag][edit->Tag] = uc_data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::edtTxOutputPowerDbOFDMCheck(
    TObject *Sender)
{
    unsigned char  uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 0~255 ";

    text = edit->Text;
    if (!IsValidWiFiTxOutputPowerDbOFDM(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[m_pnlOFDMTxRate->Tag][edit->Tag] = uc_data;
}


//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::btnOFDMTxRateClick(TObject *Sender)
{
    TButton *btn = (TButton *) Sender;
    m_pnlOFDMTxRate->Tag = btn->Tag;
    m_pnlOFDMTxRate->Caption = "TX Rate " + IntToStr(btn->Tag);
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        if (i != btn->Tag )
        {
            m_edtOFDMTxAlcOffset[i]->Visible = true;
            m_edtOFDMTxOutputPowerOffset[i]->Visible = true;
        }
        else
        {
            m_edtOFDMTxAlcOffset[i]->Visible = false;
            m_edtOFDMTxOutputPowerOffset[i]->Visible = false;
        }
    }
    ReDrawFields(DRAW_MASK_WIFI_ALC2400M_OFDM_ALC | DRAW_MASK_WIFI_ALC2400M_OFDM_POWER);
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::btnUploadFromFlashClick(TObject *Sender)
{
    if (!NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
        if (!NVRAMMan->Get_IsInit())
        {
            m_sbALC->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
            Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
            return;
        }
    }

    m_cWIFI_ALC_Obj.ConfirmCallback = ::CNF_ReadAlc2400MFromNVRAM;
    m_cWIFI_ALC_Obj.REQ_Read_From_NVRAM_Start( );

    CurrentPageLock();
    m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi TX power setting from flash progressing";
}

//-----------------------------------------
void TfrmWiFiALC2400M::UploadAlc2400MFromFlashDone(void)
{
    META_RESULT state = m_cWIFI_ALC_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        WiFi_ALC_2400M_S* p_alc_power = m_cWIFI_ALC_Obj.Get_AlcPower2400M();
        m_sWiFiAlcPower2400M = *p_alc_power;
        WiFi_TxALC_2400M_S* p_alc_slope = m_cWIFI_ALC_Obj.Get_AlcSlope2400M();
        m_sWiFiAlcSlope2400M = *p_alc_slope;

        ReDrawFields(DRAW_MASK_WIFI_ALC2400M_CCK_ALC     |
                     DRAW_MASK_WIFI_ALC2400M_CCK_POWER   |
                     DRAW_MASK_WIFI_ALC2400M_OFDM_ALC    |
                     DRAW_MASK_WIFI_ALC2400M_OFDM_POWER  |
                     DRAW_MASK_WIFI_ALC2400M_SLOPE);
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi ALC setting from flash successfully";
    }
    break;

    case META_FAILED:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi WiFi ALC setting from flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Upload WiFi ALC setting from flash, please check 1. GSM850 support. 2. The version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi ALC setting setting from flash timeout";
        Application->MessageBox( "Execution Timeout : Upload WiFi ALC setting from flash", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Upload WiFi ALC setting setting from flash stop";
        Application->MessageBox( "Execution Timeout : Upload WiFi ALC setting from flash", "STOP", MB_OK );
    }
    break;

    default:
    {
    }
    break;
    }
    CurrentPageReset();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmWiFiALC2400M::btnDownloadToFlashClick(TObject *Sender)
{
    if (!CheckFields(CHECK_MASK_WIFI_ALC2400M_CCK_ALC    |
                     CHECK_MASK_WIFI_ALC2400M_CCK_POWER  |
                     CHECK_MASK_WIFI_ALC2400M_OFDM_ALC   |
                     CHECK_MASK_WIFI_ALC2400M_OFDM_POWER |
                     CHECK_MASK_WIFI_ALC2400M_SLOPE
                    )
       )
    {
        return;
    }

    if (!NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }

    if (!NVRAMMan->Get_IsInit())
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialize fail";
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }


    m_cWIFI_ALC_Obj.Set_AlcPower2400M(m_sWiFiAlcPower2400M);
    m_cWIFI_ALC_Obj.Set_AlcSlope2400M(m_sWiFiAlcSlope2400M);

    m_cWIFI_ALC_Obj.ConfirmCallback = ::CNF_WriteAlc2400MToNVRAM;
    m_cWIFI_ALC_Obj.REQ_Write_To_NVRAM_Start();

    CurrentPageLock();
    m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Download WiFi ALC setting to flash progressing";
}

//---------------------------------------------------------------------------
void TfrmWiFiALC2400M::DownloadAlc2400MToFlashDone(void)
{
    META_RESULT state = m_cWIFI_ALC_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Download WiFi ALC setting to flash successfully";
    }
    break;

    case META_FAILED:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Download WiFi ALC setting to flash fail, please check the version of load and NVRAM database are same.";
        Application->MessageBox( "Execution Failure : Download WiFi ALC setting to flash, please check the version of load and NVRAM database are same.", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Download WiFi ALC setting to flash timeout";
        Application->MessageBox( "Execution Timeout : Download WiFi ALC setting to flash", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Download WiFi ALC setting to flash stop";
    }
    break;

    default:
    {
    }
    break;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::btnLoadFromFileClick(TObject *Sender)
{
    char str[512];
    bool ok;
    //float  fdata;

    ok = OpenDialog->Execute();
    if (!ok)
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Load WiFi ALC setting from file fail";
        return;
    }
    strcpy(str, OpenDialog->FileName.c_str());

    ok = m_cWIFI_ALC_Obj.REQ_Read_From_File(str);
    if (!ok)
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Load WiFi ALC setting from file fail";
        Application->MessageBox( "Execution Failure : Load WiFi ALC setting from file", "FAILURE", MB_OK );
        return;
    }

    WiFi_ALC_2400M_S* p_alc_power = m_cWIFI_ALC_Obj.Get_AlcPower2400M();
    m_sWiFiAlcPower2400M = *p_alc_power;
    WiFi_TxALC_2400M_S* p_alc_slope = m_cWIFI_ALC_Obj.Get_AlcSlope2400M();
    m_sWiFiAlcSlope2400M = *p_alc_slope;

    ReDrawFields(DRAW_MASK_WIFI_ALC2400M_CCK_ALC     |
                 DRAW_MASK_WIFI_ALC2400M_CCK_POWER   |
                 DRAW_MASK_WIFI_ALC2400M_OFDM_ALC    |
                 DRAW_MASK_WIFI_ALC2400M_OFDM_POWER  |
                 DRAW_MASK_WIFI_ALC2400M_SLOPE);

    m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Load WiFi ALC setting from file successfully";
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::btnSaveToFileClick(TObject *Sender)
{
    char str[512];
    bool ok;

    ok = SaveDialog->Execute();
    if (!ok)
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Save WiFi ALC setting to file fail";
        return;
    }

    strcpy(str, SaveDialog->FileName.c_str());

    m_cWIFI_ALC_Obj.Set_AlcPower2400M(m_sWiFiAlcPower2400M);
    m_cWIFI_ALC_Obj.Set_AlcSlope2400M(m_sWiFiAlcSlope2400M);

    ok = m_cWIFI_ALC_Obj.REQ_Write_To_File(str);
    if (!ok)
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Save WiFi ALC setting to file fail";
        Application->MessageBox( "Execution Failure : Save WiFi ALC setting to file", "FAILURE", MB_OK );
        return;
    }

    m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Save WiFi ALC setting to file successfully";
}



void __fastcall TfrmWiFiALC2400M::m_btnApplyClick(TObject *Sender)
{
    // CCK
    for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
    {
        if (i != m_pnlOFDMTxRate->Tag)
        {
            for (int j=0; j<WIFI_ALC_2400M_CH_NUM; j++)
            {
                m_sWiFiAlcPower2400M.txAlcOFDM[i][j] = m_sWiFiAlcPower2400M.txAlcOFDM[m_pnlOFDMTxRate->Tag][j] + m_cOFDMTxAlcOffset[i];
                m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[i][j] = m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[m_pnlOFDMTxRate->Tag][j] + m_cOFDMTxOutputPowerOffset[i];
            }
        }
    }


}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiALC2400M::edtOFDMTxAlcOffsetCheck(TObject *Sender)
{
    char  c_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be -128~127 ";

    text = edit->Text;
    if (!IsValidWiFiAlcOffset(text, c_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_cOFDMTxAlcOffset[edit->Tag] = c_data;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiALC2400M::edtOFDMTxOutputPowerOffsetCheck(
    TObject *Sender)
{
    char  c_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be -128~127 ";

    text = edit->Text;
    if (!IsValidWiFiAlcOffset(text, c_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_cOFDMTxOutputPowerOffset[edit->Tag] = c_data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::m_edtALCSlopDividerCheck(TObject *Sender)
{
    unsigned char uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 1~100 ";

    text = edit->Text;
    if (!IsValidWiFiAlcSlopeDivider(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    if (0 == edit->Tag)
    {
        m_sWiFiAlcSlope2400M.alcSlop1Divider = uc_data;
    }
    else
    {
        m_sWiFiAlcSlope2400M.alcSlop2Divider = uc_data;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWiFiALC2400M::m_edtALCSlopDividendCheck(
    TObject *Sender)
{
    unsigned char uc_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 1~100 ";

    text = edit->Text;
    if (!IsValidWiFiAlcSlopeDividend(text, uc_data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    if (0 == edit->Tag)
    {
        m_sWiFiAlcSlope2400M.alcSlop1Dividend = uc_data;
    }
    else
    {
        m_sWiFiAlcSlope2400M.alcSlop2Dividend = uc_data;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmWiFiALC2400M::btnChangeDBClick(TObject *Sender)
{
    frmMainSel->mnuFDMDatabaseClick(Sender);
    if (!NVRAMMan->Get_IsInit())
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        Application->MessageBox("Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK);
        return;
    }
    m_sbALC->Panels->Items[0]->Text = (AnsiString) "  Change NVRAM database file successfully";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TfrmWiFiALC2400M::Compose_EEPROM_Parameter(E_WIFI_EE_ALC_TYPE_T type)
{
    switch (type)
    {
    case WIFI_EE_ALC_TYPE_2_4_G_CCK:
    {
        m_sEE.count = 14;
        for (unsigned int i=0; i<m_sEE.count; i++)
        {
            m_sEE.eeprom[i].index = ADDR_MT5911_EEPROM_2_4G_CCK_ALC + i;
        }
    }
    break;

    case WIFI_EE_ALC_TYPE_2_4_G_OFDM:
    {
        m_sEE.count = 14;
        for (unsigned int i=0; i<m_sEE.count; i++)
        {
            m_sEE.eeprom[i].index = ADDR_MT5911_EEPROM_2_4G_OFDM_ALC + i;
        }
    }
    break;

    case WIFI_EE_ALC_TYPE_SLOPE:
    {
        m_sEE.count = 2;
        for (unsigned int i=0; i<m_sEE.count; i++)
        {
            m_sEE.eeprom[i].index = ADDR_MT5911_EEPROM_ALC_SLOPE + i;
        }
    }
    break;
    }
}

//---------------------------------------------------------------------------
void TfrmWiFiALC2400M::WiFiAlcEEToNVRAMFormat(E_WIFI_EE_ALC_TYPE_T type)
{
    switch (type)
    {
    case WIFI_EE_ALC_TYPE_2_4_G_CCK:
    {
        for (int i=0; i<WIFI_ALC_2400M_CH_NUM; i++)
        {
            m_sWiFiAlcPower2400M.txAlcCCK[i]           = m_sEE.eeprom[i].eeprom_data16 & 0x00FF;
            m_sWiFiAlcPower2400M.txOutputPowerDBCCK[i] = (m_sEE.eeprom[i].eeprom_data16 & 0xFF00) >> 8;
        }
    }
    break;

    case WIFI_EE_ALC_TYPE_2_4_G_OFDM:
    {
        for (int i=0; i<WIFI_ALC_2400M_TX_RATE_NUM; i++)
        {
            for (int j=0; j<WIFI_ALC_2400M_CH_NUM; j++)
            {
                m_sWiFiAlcPower2400M.txAlcOFDM[i][j]        = m_sEE.eeprom[i].eeprom_data16 & 0x00FF;
                m_sWiFiAlcPower2400M.txOutputPowerDBOFDM[i][j] = (m_sEE.eeprom[i].eeprom_data16 & 0xFF00) >> 8;
            }
        }
    }
    break;

    case WIFI_EE_ALC_TYPE_SLOPE:
    {
        m_sWiFiAlcSlope2400M.alcSlop1Divider  = m_sEE.eeprom[0].eeprom_data16 & 0x00FF;
        m_sWiFiAlcSlope2400M.alcSlop1Dividend = (m_sEE.eeprom[0].eeprom_data16 & 0xFF00) >> 8;
        m_sWiFiAlcSlope2400M.alcSlop2Divider  = m_sEE.eeprom[1].eeprom_data16 & 0x00FF;
        m_sWiFiAlcSlope2400M.alcSlop2Dividend = (m_sEE.eeprom[1].eeprom_data16 & 0xFF00) >> 8;
    }
    break;
    }
}

//===========================================================================
void __fastcall TfrmWiFiALC2400M::m_btnLoadFromEEPROMClick(TObject *Sender)
{
    CurrentPageLock();

    Compose_EEPROM_Parameter(WIFI_EE_ALC_TYPE_2_4_G_CCK);

    m_WIFI_EE_Obj.ConfirmCallback  = ::CNF_ReadAlcCCKFromEE;
    m_WIFI_EE_Obj.REQ_Read_From_EE_Start(m_sEE);

    m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM progressing";
}


//-------------------------------------------
void TfrmWiFiALC2400M::CNF_ReadAlcCCKFromEE(void)
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiAlcEEToNVRAMFormat(WIFI_EE_ALC_TYPE_2_4_G_CCK);
        Compose_EEPROM_Parameter(WIFI_EE_ALC_TYPE_2_4_G_OFDM);
        m_WIFI_EE_Obj.ConfirmCallback  = ::CNF_ReadAlcOFDMFromEE;
        m_WIFI_EE_Obj.REQ_Read_From_EE_Start(m_sEE);
    }
    break;

    case META_FAILED:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM fail";
        Application->MessageBox("Execution Timeout : Load WiFi ALC setting from EEPROM", "FAIL", MB_OK);
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Load WiFi ALC setting from EEPROM", "TIMEOUT", MB_OK );
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM stop";
        CurrentPageReset();
    }
    break;
    }
}

//----------------------------------------
void TfrmWiFiALC2400M::CNF_ReadAlcOFDMFromEE(void)
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiAlcEEToNVRAMFormat(WIFI_EE_ALC_TYPE_2_4_G_OFDM);
        Compose_EEPROM_Parameter(WIFI_EE_ALC_TYPE_SLOPE);
        m_WIFI_EE_Obj.ConfirmCallback  = ::CNF_ReadAlcSlopeFromEE;
        m_WIFI_EE_Obj.REQ_Read_From_EE_Start(m_sEE);
    }
    break;

    case META_FAILED:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting power from EEPROM fail";
        Application->MessageBox("Execution Timeout : Load WiFi ALC setting from EEPROM", "FAIL", MB_OK);
        CurrentPageReset();
    }
    break;

    case META_TIMEOUT:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM timeout";
        Application->MessageBox("Execution Timeout : Load WiFi ALC setting from EEPROM", "TIMEOUT", MB_OK);
        CurrentPageReset();
    }
    break;

    case METAAPP_STOP:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM stop";
        CurrentPageReset();
    }
    break;
    }

}

//----------------------------------------
void TfrmWiFiALC2400M::CNF_ReadAlcSlopeFromEE(void)
{
    META_RESULT state = m_WIFI_EE_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sEE = m_WIFI_EE_Obj.Get_EE();
        WiFiAlcEEToNVRAMFormat(WIFI_EE_ALC_TYPE_SLOPE);
        ReDrawFields(DRAW_MASK_WIFI_ALC2400M_CCK_ALC    |
                     DRAW_MASK_WIFI_ALC2400M_CCK_POWER  |
                     DRAW_MASK_WIFI_ALC2400M_OFDM_ALC   |
                     DRAW_MASK_WIFI_ALC2400M_OFDM_POWER |
                     DRAW_MASK_WIFI_ALC2400M_SLOPE);
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM successfully";
    }
    break;

    case META_FAILED:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM fail";
        Application->MessageBox( "Execution Timeout : Load WiFi ALC setting from EEPROM", "FAIL", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM timeout";
        Application->MessageBox( "Execution Timeout : Load WiFi ALC setting from EEPROM", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        m_sbALC->Panels->Items[0]->Text = (AnsiString)"  Load WiFi ALC setting from EEPROM stop";
    }
    break;
    }
    CurrentPageReset();
}

