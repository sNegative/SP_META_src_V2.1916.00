#include <vcl.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
#pragma hdrstop

#include "METAAPP_common.h"
#include "form_BaseBand.h"
#include "form_main.h"
#include "form_pmicreg.h"
#include "misc.h"
#include "misc_bb.h"
#include "man_fdm.h"

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBaseBand *frmBaseBand;
extern TfrmMainSel *frmMainSel;
extern AnsiString chipVersion;
extern AnsiString softwareVersion;


static void CNF_Clean_Boot(void)
{
    frmBaseBand->CNF_Clean_Boot();
}

static void CNF_PMIC_ReadRegister( void )
{
    frmBaseBand->CNF_PMIC_ReadRegister();
}

static void CNF_PMIC_WriteRegister( void )
{
    frmBaseBand->CNF_PMIC_WriteRegister();
}

static void CNF_LED_KeypadLEDOnOff(void)
{
    frmBaseBand->CNF_LED_KeypadLEDOnOff();
}

static void CNF_LED_LCDLightLevel(void)
{
    frmBaseBand->CNF_LED_LCDLightLevel();
}

static void CNF_VBR_TurnOn(void)
{
    frmBaseBand->CNF_VBR_TurnOn();
}

static void CNF_VBR_TurnOff(void)
{
    frmBaseBand->CNF_VBR_TurnOff();
}

static void CNF_RTC_Query(void)
{
    frmBaseBand->CNF_RTC_Query();
}

static void CNF_SignalIndicator_TurnOn(void)
{
    frmBaseBand->CNF_SignalIndicator_TurnOn();
}

static void CNF_SignalIndicator_TurnOff(void)
{
    frmBaseBand->CNF_SignalIndicator_TurnOff();
}


static void  CNF_ReadRegister( void )
{
    frmBaseBand->CNF_ReadRegister();
}


static void  CNF_ECCIUSBTest( void )
{
    frmBaseBand->CNF_ECCIUSBTest();
}

static void  CNF_ECCIUARTTest( void )
{
    frmBaseBand->CNF_ECCIUARTTest();
}

static void  CNF_WriteRegister( void )
{
    frmBaseBand->CNF_WriteRegister();
}


__fastcall TfrmBaseBand::TfrmBaseBand(TComponent* Owner)
    : TForm(Owner)
{
    ProgressBar1->Min = 0;
    ProgressBar1->Max = 11;
    m_uiPMICRegNumber = 0x1;
    m_usPMICRegValue = 0;
    LBDisplay->Visible = false;
    
    m_bInit = false;
    m_iFinalBBChip = 0;
    m_uiBBRegAddr = 0;
    m_usBBRegValue = 0;
    m_uiBBRegBitCount = 0;
    m_cLCDLEDLevel = 0;
    m_Len = 0;
    m_Type = 0;
    
    memset(m_RowBuf,0,sizeof(char)*96);

}
void __fastcall TfrmBaseBand::FormCreate(TObject *Sender)
{
    WindowProc = SubClassWndProc;
    Init();
}

void __fastcall TfrmBaseBand::FormActivate(TObject *Sender)
{
    if (!m_bInit)
    {
        return;
    }
    m_bInit = false;

    m_iFinalBBChip = frmMainSel->Get_FinalBBChip();

    // PMIC register
    if (! m_cBB_PMIC_REG_Obj.Query_PMIC_ID_Start())
    {
        m_sPmicId.id = FT_MT_UNKNOWN;
    }
    m_sPmicId = *(m_cBB_PMIC_REG_Obj.Get_PMIC_ID());

    if (FT_MT6318 == m_sPmicId.id)
    {
        btnPMICReg->Caption = "MT6318 PMIC register setting ...";
        btnPMICReg->Visible = true;
    }
    else
    {
        btnPMICReg->Visible = false;
    }
    if(chipVersion == "MT6573")
    {
        tsBattery->Visible = false;
        tsBattery->TabVisible = false;
        tsLEDShow(Sender);
    }
}
void TfrmBaseBand::Init( void )
{
    m_bInit = true;
    frmPMICReg->Init();
}

void __fastcall TfrmBaseBand::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

void  TfrmBaseBand::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

void  TfrmBaseBand::CurrentPageReset( void )
{
#if 0
    switch (pctlToolSel->ActivePageIndex)
    {
    case BB_PAGEIDX_BB_REG:
        btnBBRegRead->Enabled = true;
        btnBBRegWrite->Enabled = true;
        break;
    case BB_PAGEIDX_PMIC_REG:
        btnPMICRegRead->Enabled = true;
        btnPMICRegWrite->Enabled = true;
        break;
    case BB_PAGEIDX_BATTERY:
        btnBGUploadFromFlash->Enabled = true;
        btnBGDownloadToFlash->Enabled = true;
        btnBGChangeDB->Enabled = true;
        break;
    case BB_PAGEIDX_LED:
        btnKeypadLEDOn->Enabled = true;
        btnKeypadLEDOff->Enabled = true;
        btnLCDLEDSet->Enabled = true;
        break;
    case BB_PAGEIDX_VBR:
        btnVBROn->Enabled = true;
        btnVBROff->Enabled = true;
        break;
    case BB_PAGEIDX_RTC:
        btnRTCQuery->Enabled = true;
        break;
    case BB_PAGEIDX_SIGNAL_INDICATOR:
        btnRedLightOff->Enabled = true;
        btnRedLightOff->Enabled = true;
        btnGreenLightOff->Enabled = true;
        btnGreenLightOff->Enabled = true;
        btnBlueLightOff->Enabled = true;
        btnBlueLightOff->Enabled = true;
        break;
    default:
        break;
    }
#endif

}

void  TfrmBaseBand::CurrentPageLock( void )
{
#if 0
    switch (pctlToolSel->ActivePageIndex)
    {
    case BB_PAGEIDX_BB_REG:
        btnBBRegRead->Enabled = false;
        btnBBRegWrite->Enabled = false;
        break;
    case BB_PAGEIDX_PMIC_REG:
        btnPMICRegRead->Enabled = false;
        btnPMICRegWrite->Enabled = false;
        break;
    case BB_PAGEIDX_BATTERY:
        btnBGUploadFromFlash->Enabled = false;
        btnBGDownloadToFlash->Enabled = false;
        btnBGChangeDB->Enabled = false;
        break;
    case BB_PAGEIDX_LED:
        btnKeypadLEDOn->Enabled = false;
        btnKeypadLEDOff->Enabled = false;
        btnLCDLEDSet->Enabled = false;
        break;
    case BB_PAGEIDX_VBR:
        btnVBROn->Enabled = false;
        btnVBROff->Enabled = false;
        break;
    case BB_PAGEIDX_RTC:
        btnRTCQuery->Enabled = false;
        break;
    case BB_PAGEIDX_SIGNAL_INDICATOR:
        btnRedLightOff->Enabled = false;
        btnRedLightOff->Enabled = false;
        btnGreenLightOff->Enabled = false;
        btnGreenLightOff->Enabled = false;
        btnBlueLightOff->Enabled = false;
        btnBlueLightOff->Enabled = false;
        break;
    default:
        break;
    }
#endif
}

void __fastcall TfrmBaseBand::pctlToolSelChange(TObject *Sender)
{
    ReDrawFields( (E_BB_PAGEIDX_T)pctlToolSel->ActivePageIndex );
}



bool  TfrmBaseBand::CheckFields( void )
{
    AnsiString  text;
    int total_adc_num = 0;

    switch ((E_BB_PAGEIDX_T) pctlToolSel->ActivePageIndex)
    {
    case BB_PAGEIDX_BB_REG:
    {
        unsigned int idata = 0;
        unsigned int sdata = 0;
        unsigned int bcdata = 0;
        text = edtBBAddress->Text;
        if (!IsValidHexRegAddr(text, &idata))
        {
            edtRegAddrCheck(edtBBAddress);
            return false;
        }
        m_cBaseBand_Obj.m_sRegReadReq.addr = idata;
        m_cBaseBand_Obj.m_sRegWriteReq.addr = idata;
        text = edtBBValue->Text;
        if( DEC_FORMAT == btnBBRegValue->Tag )  // Dec
        {
            if (!IsValidDecRegValue(text, &sdata))
            {
                edtRegValueCheck(edtBBValue);
                return false;
            }
        }
        else  // Hex
        {
            if (!IsValidHexRegValue(text, &sdata))
            {
                edtRegValueCheck(edtBBValue);
                return false;
            }
        }
        m_cBaseBand_Obj.m_sRegWriteReq.value = sdata;

        text = edtBBBitCount->Text;
        if (!IsValidDecRegValue(text, &bcdata))
        {
            edtRegValueCheck(edtBBBitCount);
            return false;
        }
        m_cBaseBand_Obj.m_sRegReadReq.bytenum = bcdata;
        m_cBaseBand_Obj.m_sRegWriteReq.bytenum = bcdata;
    }
    break;

    case BB_PAGEIDX_PMIC_REG:
    {
        unsigned int idata;
        unsigned int sdata;
        text = edtPMICAddress->Text;
        if (!IsValidHexRegAddr(text, &idata))
        {
            edtRegAddrCheck(edtPMICAddress);
            return false;
        }
        m_uiPMICRegNumber = idata;
        text = edtPMICValue->Text;
        if( DEC_FORMAT == btnPMICRegValue->Tag )  // Dec
        {
            if (!IsValidDecRegValue(text, &sdata))
            {
                edtPMICValueCheck(edtPMICValue);
                return false;
            }
        }
        else  // Hex
        {
            if (!IsValidHexRegValue(text, &sdata))
            {
                edtPMICValueCheck(edtPMICValue);
                return false;
            }
        }
        m_usPMICRegValue = sdata;
    }
    break;

    default:

        break;
    }

    return true;
}

void __fastcall TfrmBaseBand::edtRegAddrCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned int  data = 0;
    if( !IsValidHexRegAddr( edit->Text, &data ) )
    {
        ShowHintLabel( edit, " character is not valid ");
        edit->SetFocus();
        return;
    }
    m_uiBBRegAddr = data;
}

void __fastcall TfrmBaseBand::edtRegValueCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned int  data = 0;
    if( DEC_FORMAT == btnBBRegValue->Tag )  // Dec
    {
        if( !IsValidDecRegValue( edit->Text, &data ) )
        {
            ShowHintLabel( edit, " character is not valid ");
            edit->SetFocus();
            return;
        }
    }
    else
    {
        if( !IsValidHexRegValue( edit->Text, &data ) )
        {
            ShowHintLabel( edit, " character is not valid ");
            edit->SetFocus();
            return;
        }
    }

    m_usBBRegValue = data;
}

void  TfrmBaseBand::ReDrawFields(E_BB_PAGEIDX_T e_pageidx)
{
    char  str[256] = {0};
    switch (e_pageidx)
    {
    case BB_PAGEIDX_BB_REG:
    {
        sprintf(str, "%08lx", m_uiBBRegAddr);
        edtBBAddress->Text = str;
        if (DEC_FORMAT == btnBBRegValue->Tag)  // Dec
        {
            btnBBRegValue->Caption = "Value (Dec)";
            lblBBRegValue0X->Visible = false;
            edtBBValue->Text = IntToStr(m_usBBRegValue);
        }
        else  // Hex
        {
            btnBBRegValue->Caption = "Value (Hex)";
            lblBBRegValue0X->Visible = true;
            memset(str, 0, 256);
            sprintf( str, "%X", (int)m_usBBRegValue );
            edtBBValue->Text = str;
        }
    }
    break;

    case BB_PAGEIDX_PMIC_REG:
    {
        sprintf(str, "%08lx", m_uiPMICRegNumber);
        edtPMICAddress->Text = str;
        if (DEC_FORMAT == btnPMICRegValue->Tag)  // Dec
        {
            btnPMICRegValue->Caption = "Value (Dec)";
            lblPMICRegValue0X->Visible = false;
            edtPMICValue->Text = IntToStr(m_usPMICRegValue);
        }
        else  // Hex
        {
            btnPMICRegValue->Caption = "Value (Hex)";
            lblPMICRegValue0X->Visible = true;
            sprintf( str, "%X", (int)m_usPMICRegValue );
            edtPMICValue->Text = str;
        }
    }
    break;

    case BB_PAGEIDX_RTC:
    {
        edtRTCYear->Text  = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_year);
        edtRTCMonth->Text = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_mon);
        edtRTCDay->Text   = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_day);
        edtRTCWDay->Text  = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_wday);
        edtRTCWHour->Text = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_hour);
        edtRTCMinute->Text= IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_min);
        edtRTCSec->Text   = IntToStr(m_cBaseBand_Obj.m_sRTC.rtc_sec);
    }
    break;

    default:

        break;
    }
}

//===========================================================================

void __fastcall TfrmBaseBand::btnBBRegReadClick(TObject *Sender)
{
    if(!CheckFields())
    {
        return;
    }
    //CurrentPageLock();
    sbReg->Panels->Items[0]->Text = (AnsiString) "  Read baseband register progressing";
    m_cBaseBand_Obj.REQ_Start(BB_READ_REGISTER, ::CNF_ReadRegister);
}

void  TfrmBaseBand::CNF_ReadRegister(void)
{
    META_RESULT state = (META_RESULT)m_cBaseBand_Obj.Get_ConfirmState();

    switch( state )
    {
    case META_SUCCESS:
    {
        m_usBBRegValue = m_cBaseBand_Obj.m_usValue;
        ReDrawFields(BB_PAGEIDX_BB_REG);
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Read baseband register successfully";
    }
    break;

    case META_FAILED:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Read baseband register fail";
    }
    break;
    case META_TIMEOUT:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Read baseband register timeout";
    }
    break;

    case METAAPP_STOP:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Read baseband register stop";
    }
    break;
    }
}

void __fastcall TfrmBaseBand::btnBBRegWriteClick(TObject *Sender)
{
    if(!CheckFields())
    {
        return;
    }
    //CurrentPageLock();
    sbReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register progressing";
    m_cBaseBand_Obj.REQ_Start(BB_WRITE_REGISTER, ::CNF_WriteRegister);
}

//-----------------------------------------------
void TfrmBaseBand::CNF_WriteRegister(void)
{
    META_RESULT state = (META_RESULT)m_cBaseBand_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register successfully";
    }
    break;

    case META_FAILED:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register fail";
    }
    break;

    case META_TIMEOUT:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register timeout";
    }
    break;

    case METAAPP_STOP:
    {
        sbReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register stop";
    }
    break;

    default:
        break;
    }
}

void __fastcall TfrmBaseBand::btnBBRegValueClick(TObject *Sender)
{
    btnBBRegValue->Tag = (DEC_FORMAT == (E_VALUE_FORMAT_T) btnBBRegValue->Tag) ? HEX_FORMAT: DEC_FORMAT;

    ReDrawFields(BB_PAGEIDX_BB_REG);
}
//---------------------------------------------------------------------------


void __fastcall TfrmBaseBand::btnPMICRegValueClick(TObject *Sender)
{
    btnPMICRegValue->Tag = (DEC_FORMAT == (E_VALUE_FORMAT_T) btnPMICRegValue->Tag) ? HEX_FORMAT: DEC_FORMAT;
    ReDrawFields(BB_PAGEIDX_PMIC_REG);
}

void __fastcall TfrmBaseBand::btnPMICRegReadClick(TObject *Sender)
{
    if( !CheckFields() )
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register fail";
        return;
    }
    m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register progressing";
    m_cBB_PMIC_REG_Obj.ConfirmCallback = ::CNF_PMIC_ReadRegister;
    m_cBB_PMIC_REG_Obj.REQ_ReadRegister_Start( m_uiPMICRegNumber );
}

//-----------------------------------------------
void  TfrmBaseBand::CNF_PMIC_ReadRegister(void)
{
    META_RESULT state = m_cBB_PMIC_REG_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_usPMICRegValue = m_cBB_PMIC_REG_Obj.Get_RegValue();
        ReDrawFields(BB_PAGEIDX_PMIC_REG);
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register successfully";
    }
    break;

    case META_FAILED:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register fail";
    }
    break;

    case META_TIMEOUT:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register timeout";
    }
    break;

    case METAAPP_STOP:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register stop";
    }
    break;

    default:

        break;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmBaseBand::btnPMICRegWriteClick(TObject *Sender)
{
    m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register progressing";
    if( !CheckFields() )
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register fail";
        return;
    }

    m_cBB_PMIC_REG_Obj.ConfirmCallback = ::CNF_PMIC_WriteRegister;
    m_cBB_PMIC_REG_Obj.REQ_WriteRegister_Start( m_uiPMICRegNumber, m_usPMICRegValue );

}

//-----------------------------------------------
void  TfrmBaseBand::CNF_PMIC_WriteRegister(void)
{
    META_RESULT state = m_cBB_PMIC_REG_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register successfully";
    }
    break;

    case META_FAILED:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register fail";
    }
    break;

    case META_TIMEOUT:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register timeout";
    }
    break;

    case METAAPP_STOP:
    {
        m_sbPMIC->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register stop";
    }
    break;

    default:
    {
    }
    break;
    }
}



void __fastcall TfrmBaseBand::edtPMICAddressCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned int  data = 0;
    if (! IsValidHexRegAddr(edit->Text, &data))
    {
        ShowHintLabel(edit, " value invalid ");
        edit->SetFocus();
        return;
    }
    m_uiPMICRegNumber = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmBaseBand::edtPMICValueCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned int  data = 0;

    if (DEC_FORMAT == btnPMICRegValue->Tag)  // Dec
    {
        if (! IsValidDecRegValue(edit->Text, &data))
        {
            ShowHintLabel(edit, " value invalid ");
            edit->SetFocus();
            return;
        }
    }
    else  // Hex
    {
        if (! IsValidHexRegValue(edit->Text, &data))
        {
            ShowHintLabel(edit, " value invalid ");
            edit->SetFocus();
            return;
        }
    }
    m_usPMICRegValue = data;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBaseBand::btnPMICRegClick(TObject *Sender)
{
    if ( FT_MT6318 == m_sPmicId.id )
    {
        frmPMICReg->Top  = 104;
        frmPMICReg->Left = 135;
        frmPMICReg->Show();
    }
}
//===========================================================================
void __fastcall TfrmBaseBand::edtKeypadLEDDivCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned char  ucdata = 0;
    if( !IsValidLEDDiv(edit->Text, ucdata))
    {
        ShowHintLabel( edit, " value invalid " );
        edit->SetFocus();
        return;
    }
    m_cBaseBand_Obj.m_sLEDKeypad.DIV = ucdata;
}

void __fastcall TfrmBaseBand::edtKeypadLEDDutyCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned char  ucdata = 0;
    if( !IsValidLEDDuty(edit->Text, ucdata))
    {
        ShowHintLabel( edit, " value invalid " );
        edit->SetFocus();
        return;
    }
    m_cBaseBand_Obj.m_sLEDKeypad.DUTY = ucdata;
}

void __fastcall TfrmBaseBand::edtLCDLEDCheck(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    unsigned char  ucdata = 0;
    if( !IsValidLEDLightLevel(edit->Text, ucdata))
    {
        ShowHintLabel( edit, " value invalid " );
        edit->SetFocus();
        return;
    }
    m_cBaseBand_Obj.m_sLCDLevel.lcd_light_level = ucdata;
}

PMIC_ID* TfrmBaseBand::Get_PMIC_ID(void)
{
    return &m_sPmicId;
}

void __fastcall TfrmBaseBand::btnKeypadLEDOnClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level progressing";
    m_cBaseBand_Obj.m_sLEDKeypad.onoff = 1;

    m_cBaseBand_Obj.m_sVBROnOff.LedNum = 4;
    m_cBaseBand_Obj.m_sVBROnOff.OFFON = 1;

    m_cBaseBand_Obj.REQ_Start(BB_SET_KEYPADLED_ONOFF, ::CNF_LED_KeypadLEDOnOff);
}

void __fastcall TfrmBaseBand::btnKeypadLEDOffClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level progressing";
    m_cBaseBand_Obj.m_sLEDKeypad.onoff = 0;
    m_cBaseBand_Obj.m_sVBROnOff.LedNum = 4;
    m_cBaseBand_Obj.m_sVBROnOff.OFFON = 0;
    m_cBaseBand_Obj.REQ_Start(BB_SET_KEYPADLED_ONOFF, ::CNF_LED_KeypadLEDOnOff);
}

void __fastcall TfrmBaseBand::btnLCDLEDSetClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD progressing";
    m_cBaseBand_Obj.m_sLCDLevel.lcd_light_level = edtLCDLED->Text.ToInt();
    m_cBaseBand_Obj.REQ_Start(BB_SET_LCDLED_LIGHTLEVEL, ::CNF_LED_LCDLightLevel);
}

void __fastcall TfrmBaseBand::btnVBROnClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator progressing";
    m_cBaseBand_Obj.m_sVBROnOff.OFFON= 1;
    m_cBaseBand_Obj.m_sVBROnOff.LedNum= 0;//0 means vbr
    m_cBaseBand_Obj.REQ_Start(BB_SET_VIBRATOR_ONOFF, ::CNF_VBR_TurnOn);
}

void __fastcall TfrmBaseBand::btnVBROffClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator progressing";
    m_cBaseBand_Obj.m_sVBROnOff.OFFON= 0;
    m_cBaseBand_Obj.m_sVBROnOff.LedNum= 0;//0 means vbr
    m_cBaseBand_Obj.REQ_Start(BB_SET_VIBRATOR_ONOFF, ::CNF_VBR_TurnOff);
}

void __fastcall TfrmBaseBand::btnRTCQueryClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time progressing";
    m_cBaseBand_Obj.REQ_Start(BB_QUERY_RTC_TIME, ::CNF_RTC_Query);
}


void __fastcall TfrmBaseBand::btnRedLightOnClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 1;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 1;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOn);
}

void __fastcall TfrmBaseBand::btnRedLightOffClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 1;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 0;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOff);
}

void __fastcall TfrmBaseBand::btnGreenLightOnClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 2;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 1;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOn);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnGreenLightOffClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 2;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 0;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOff);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnBlueLightOnClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 3;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 1;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOn);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnBlueLightOffClick(TObject *Sender)
{
    CurrentPageLock();
    m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator progressing";
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.LedNum= 3;
    m_cBaseBand_Obj.m_sSignalIndicatorOnOff.OFFON= 0;
    m_cBaseBand_Obj.REQ_Start(BB_SET_SIGNAL_INDICATOR_ONOFF, ::CNF_SignalIndicator_TurnOff);
}
//---------------------------------------------------------------------------

void TfrmBaseBand::CNF_SignalIndicator_TurnOff(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator successful";
        break;
    case META_FAILED:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator fail";
        break;
    case META_TIMEOUT:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator timeout";
        break;
    case METAAPP_STOP:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator stop";
        break;
    default:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn off signal indicator other error";
        break;
    }
    CurrentPageReset();
}


void TfrmBaseBand::CNF_SignalIndicator_TurnOn(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator successful";
        break;
    case META_FAILED:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator fail";
        break;
    case META_TIMEOUT:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator timeout";
        break;
    case METAAPP_STOP:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator stop";
        break;
    default:
        m_sbSignalIndicator->Panels->Items[0]->Text = (AnsiString) "  Turn on Signal Indicator other error";
        break;
    }
    CurrentPageReset();
}

void TfrmBaseBand::CNF_VBR_TurnOff(void)
{
    switch (m_cBaseBand_Obj.Get_ConfirmState())
    {
    case META_SUCCESS:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator successful";
        break;
    case META_FAILED:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator fail";
        break;
    case META_TIMEOUT:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator timeout";
        break;
    case METAAPP_STOP:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator stop";
        break;
    default:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn off vibrator other error";
        break;
    }
    CurrentPageReset();

}

void TfrmBaseBand::CNF_LED_KeypadLEDOnOff(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level successful";
        break;
    case META_FAILED:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level fail";
        break;
    case META_TIMEOUT:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level timeout";
        break;
    case METAAPP_STOP:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level stop";
        break;
    default:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level other error";
        break;
    }
    CurrentPageReset();
}

void TfrmBaseBand::CNF_LED_LCDLightLevel(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD successful";
        break;
    case META_FAILED:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD fail";
        break;
    case META_TIMEOUT:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD timeout";
        break;
    case METAAPP_STOP:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD stop";
        break;
    default:
        m_sbLED->Panels->Items[0]->Text = (AnsiString) "  Set LED light level of main LCD other error";
        break;
    }
    CurrentPageReset();
}


void TfrmBaseBand::CNF_VBR_TurnOn(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator successful";
        break;
    case META_FAILED:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator fail";
        break;
    case META_TIMEOUT:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator timeout";
        break;
    case METAAPP_STOP:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator stop";
        break;
    default:
        m_sbVBR->Panels->Items[0]->Text = (AnsiString) "  Turn on vibrator other error";
        break;
    }

    CurrentPageReset();
}


//-------------------------------
void TfrmBaseBand::CNF_RTC_Query(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        ReDrawFields(BB_PAGEIDX_RTC);
        m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time successful";
        break;
    case META_FAILED:
        m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time fail";
        break;
    case META_TIMEOUT:
        m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time timeout";
        break;
    case METAAPP_STOP:
        m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time stop";
        break;

    default:
        m_sbRTC->Panels->Items[0]->Text = (AnsiString) "  Query RTC time other error";
        break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmBaseBand::EdtExit(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    if (edit->Text == "")
    {
        ShowHintLabel( edit, " value invalid " );
        edit->SetFocus();
        return;
    }
}


void _fastcall TfrmBaseBand::SubClassWndProc( Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
    case WM_ML_BASEBAND_BATTERY_FWUPDATE_ONGOING_MSG:
        ProgressBar1->Position++;
        break;
    case WM_ML_BASEBAND_BATTERY_FWUPDATE_FAILED_MSG:
        ProgressBar1->Position = 0;
        break;
    case WM_ML_BASEBAND_BATTERY_FWUPDATE_FINISHED_MSG:
        ProgressBar1->Position = 0;
        break;
    default:
        this->WndProc( Message );
        break;
    }
}

//---------------------------------------------------------------------------



void  TfrmBaseBand::CNF_ECCIUSBTest(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    spUSB->Brush->Color = clRed;
    switch (state)
    {
    case META_SUCCESS:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test USB Port successful";
        spUSB->Brush->Color = clGreen;
        break;
    case META_FAILED:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test USB Port fail";
        break;
    case META_TIMEOUT:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test USB Port timeout";
        break;
    case METAAPP_STOP:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test USB Port stop";
        break;
    default:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test USB Port other error";
        break;
    }
    CurrentPageReset();
}

void  TfrmBaseBand::CNF_ECCIUARTTest(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    spUART->Brush->Color = clRed;
    switch (state)
    {
    case META_SUCCESS:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test UART Port successful";
        spUART->Brush->Color = clGreen;
        break;
    case META_FAILED:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test UART Port fail";

        break;
    case META_TIMEOUT:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test UART Port timeout";
        break;
    case METAAPP_STOP:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test UART Port stop";
        break;
    default:
        m_sbECCI->Panels->Items[0]->Text = (AnsiString) "  Test UART Port other error";
        break;
    }
    CurrentPageReset();
}

void __fastcall TfrmBaseBand::btnUSBClick(TObject *Sender)
{
    m_cBaseBand_Obj.m_tIndex = 1;
    m_cBaseBand_Obj.REQ_Start(ECCI_TEST, ::CNF_ECCIUSBTest);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnUARTClick(TObject *Sender)
{
    m_cBaseBand_Obj.m_tIndex = 0;
    m_cBaseBand_Obj.REQ_Start(ECCI_TEST, ::CNF_ECCIUARTTest);
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnResetClick(TObject *Sender)
{
    spUSB->Brush->Color = clSilver;
    spUART->Brush->Color = clSilver;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void TfrmBaseBand::CNF_Clean_Boot(void)
{
    int state = m_cBaseBand_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        sbReg->Panels->Items[0]->Text = (AnsiString) "Clean Boot Successfully";
        break;
    case META_FAILED:
        sbReg->Panels->Items[0]->Text = (AnsiString) "Clean Boot Fail";
        break;
    case META_TIMEOUT:
        sbReg->Panels->Items[0]->Text = (AnsiString) "Clean Boot Time out";
        break;
    case METAAPP_STOP:
        sbReg->Panels->Items[0]->Text = (AnsiString) "Clean Boot Stop";
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnCleanBootClick(TObject *Sender)
{
    sbReg->Panels->Items[0]->Text = (AnsiString) "  Clean Boot processing...";
    m_cBaseBand_Obj.REQ_Start(CLEAN_BOOT, ::CNF_Clean_Boot);
    return;
}
//---------------------------------------------------------------------------


void __fastcall TfrmBaseBand::tsLEDShow(TObject *Sender)
{
//        if(chipVersion=="MT6573")
    if(chipVersion!="MT6516")
    {
        Label27->Visible = false;
        edtKeypadLedDIV->Visible = false;
        Label28->Visible = false;
        edtKeypadLedDUTY->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmBaseBand::FormShow(TObject *Sender)
{
    LOG("BaseBand form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBaseBand::btnBatteryVolClick(TObject *Sender)
{
    int nVol = 0;
    META_RESULT mr = m_cBaseBand_Obj.ADC_GetBatVol(&nVol);
    if( mr != META_SUCCESS )
    {
        sbAdc->Panels->Items[0]->Text = (AnsiString) (" Get Battery Voltage fail");
        return;
    }
    char buf[50] = {0};
    sprintf(buf, "%d", nVol);
    stBatteryVol->Caption = buf;
    sbAdc->Panels->Items[0]->Text = (AnsiString) (" Get Battery Voltage success");
}
//---------------------------------------------------------------------------

void __fastcall TfrmBaseBand::btnBatteryCapClick(TObject *Sender)
{
    int nCapacity = 0;
    META_RESULT mr = m_cBaseBand_Obj.ADC_GetBatCapacity(&nCapacity);
    if( mr != META_SUCCESS )
    {
        sbAdc->Panels->Items[0]->Text = (AnsiString) (" Get Battery Capacity fail");
        return;
    }
    char buf[50] = {0};
    sprintf(buf, "%d", nCapacity);
    stBatteryCap->Caption = buf;
    sbAdc->Panels->Items[0]->Text = (AnsiString) (" Get Battery Capacity success");
}
//---------------------------------------------------------------------------

