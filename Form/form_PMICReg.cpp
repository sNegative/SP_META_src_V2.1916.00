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
 *   form_PMICReg.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   PMIC register form source
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
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
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

#ifndef  _METAAPP_COMMON_H_
#include "METAAPP_common.h"
#endif

// form
#ifndef _FORM_PMICREG_H_
#include "form_PMICReg.h"
#endif

#ifndef _FORM_BASEBAND_H_
#include "form_BaseBand.h"
#endif

// misc
#ifndef  _FILE_UTILS_H_
#include "file_utils.h"
#endif

#ifndef  _MISC_BB_H_
#include "misc_bb.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPMICReg *frmPMICReg;

//==========================================================================
static void CNF_PMIC_ReadRegister( void )
{
    frmPMICReg->CNF_PMIC_ReadRegister();
}

//--------------------------------------------------------------------------
static void CNF_PMIC_WriteRegister( void )
{
    frmPMICReg->CNF_PMIC_WriteRegister();
}

//---------------------------------------------------------------------------
__fastcall TfrmPMICReg::TfrmPMICReg(TComponent* Owner)
    : TForm(Owner)
{
    m_pvPmicReg   = NULL;
    m_pvPmicRegUI = NULL;
    m_bInit = false;
    m_iTag = 0;
    m_uiPMICRegNumber = 0;
    m_usPMICRegValue = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  TfrmPMICReg::AllocateVector(void)
{
    if (NULL == m_pvPmicRegUI)
    {
        m_pvPmicRegUI = new vector<S_PMIC_REG_UI_T>;
    }
}

//--------------------------------------------------------------------------
void  TfrmPMICReg::DeAllocateVector(void)
{
    if (NULL != m_pvPmicRegUI)
    {
        delete m_pvPmicRegUI;
        m_pvPmicRegUI = NULL;
    }
}

//--------------------------------------------------------------------------
void  TfrmPMICReg::EraseVector(void)
{
    if (NULL != m_pvPmicRegUI)
    {
        if (! m_pvPmicRegUI->empty())
        {
            vector<S_PMIC_REG_UI_T>:: iterator iter;
            for (iter = m_pvPmicRegUI->begin(); iter != m_pvPmicRegUI->end(); iter++)
            {
                //delete iter->lblPMICRegAddr0X;
                if (iter->lblPMICRegAddr)
                {
                    delete iter->lblPMICRegAddr;
                    iter->lblPMICRegAddr = NULL;
                }

                if (iter->stPMICRegAddr)
                {
                    delete iter->stPMICRegAddr;
                    iter->stPMICRegAddr = NULL;
                }

                if (iter->lblPMICRegValue0X)
                {
                    delete iter->lblPMICRegValue0X;
                    iter->lblPMICRegValue0X = NULL;
                }

                if (iter->lblPMICRegValue)
                {
                    delete iter->lblPMICRegValue;
                    iter->lblPMICRegValue = NULL;
                }

                if (iter->edtPMICValue)
                {
                    delete iter->edtPMICValue;
                    iter->edtPMICValue = NULL;
                }

                if (iter->btnPMICRegRead)
                {
                    delete iter->btnPMICRegRead;
                    iter->btnPMICRegRead = NULL;
                }

                if (iter->btnPMICRegWrite)
                {
                    delete iter->btnPMICRegWrite;
                    iter->btnPMICRegWrite = NULL;
                }
            }
            m_pvPmicRegUI->erase(m_pvPmicRegUI->begin(), m_pvPmicRegUI->end());
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmPMICReg::FormCreate(TObject *Sender)
{
    m_bInit = true;
}

//---------------------------------------------------------------------------
void __fastcall TfrmPMICReg::FormActivate(TObject *Sender)
{
    if (m_bInit)
    {
        m_bInit = false;
        PMIC_ID* psPmicId;
        psPmicId = frmBaseBand->Get_PMIC_ID();
        m_sPmicId = *psPmicId;

        if (FT_MT6318 == m_sPmicId.id)
        {
            frmPMICReg->Caption = "MT6318 PMIC Register Setting";
            AnsiString as = ::Get_WorkingDirectory();
            as += "\\MT6318.ini";
            m_cBB_PMIC_REG_Obj.REQ_Read_From_File(as.c_str());
            Display_PMICRegister();
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmPMICReg::FormDestroy(TObject *Sender)
{
    EraseVector();
    DeAllocateVector();
}

//---------------------------------------------------------------------------
void TfrmPMICReg::Init( void )
{
    //m_bInit = true;
}

//===========================================================================
void TfrmPMICReg::Display_PMICRegister(void)
{
    AllocateVector();
    EraseVector();
    m_pvPmicReg = m_cBB_PMIC_REG_Obj.Get_PMICRegVector();


    //int i_lblPMICRegName_top     =  40;
    //int i_lblPMICRegName_left    =   8;
    //int i_stPMICRegName_top      =  60;
    //int i_stPMICRegName_left     =   8;
    int i_lblPMICRegAddr_top     =  40;
    int i_lblPMICRegAddr_left    =  32;
    int i_stPMICAddr_top         =  56;
    int i_stPMICAddr_left        =  24;
    int i_lblPMICRegValue0X_top  =  60;
    int i_lblPMICRegValue0X_left = 114;
    //int i_lblPMICRegValue_top    =  40;
    //int i_lblPMICRegValue_left   = 152;
    int i_edtPMICValue_top       =  56;
    int i_edtPMICValue_left      = 128;
    int i_btnPMICRegRead_top     =  56;
    int i_btnPMICRegRead_left    = 216;
    int i_btnPMICRegWrite_top    =  56;
    int i_btnPMICRegWrite_left   = 288;
    int i_vertical_offset        =  50;
    int i_horizontal_offset      = 360;

    vector<S_BB_PMIC_REG_T>:: iterator iter;
    int i=0;
    for (iter = m_pvPmicReg->begin(); iter != m_pvPmicReg->end(); iter++)
    {
        S_PMIC_REG_UI_T pmic_reg_ui;

        if (0 == i%2)
        {
            //pmic_reg_ui.lblPMICRegName = new TLabel(this);
            //pmic_reg_ui.lblPMICRegName->Parent = frmPMICReg;
            //pmic_reg_ui.lblPMICRegName->Caption = "Name";
            //pmic_reg_ui.lblPMICRegName->Top = i_lblPMICRegName_top + i/2 * i_vertical_offset;
            //pmic_reg_ui.lblPMICRegName->Left = i_lblPMICRegName_left;

            //pmic_reg_ui.stPMICRegName = new TStaticText(this);
            //pmic_reg_ui.stPMICRegName->Parent = frmPMICReg;
            //pmic_reg_ui.stPMICRegName->Caption = iter->as_name;
            //pmic_reg_ui.stPMICRegName->Tag = i;
            //pmic_reg_ui.stPMICRegName->Top = i_stPMICRegName_top + i/2 * i_vertical_offset;
            //pmic_reg_ui.stPMICRegNamer->Left = i_stPMICRegName_left;

            pmic_reg_ui.lblPMICRegAddr = new TLabel(this);
            pmic_reg_ui.lblPMICRegAddr->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegAddr->Caption = "Address (Hex)";
            pmic_reg_ui.lblPMICRegAddr->Top = i_lblPMICRegAddr_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegAddr->Left = i_lblPMICRegAddr_left;

            pmic_reg_ui.stPMICRegAddr = new TStaticText(this);
            pmic_reg_ui.stPMICRegAddr->Parent = frmPMICReg;
            char str[5];
            sprintf(str, "0x%X", iter->us_index);
            pmic_reg_ui.stPMICRegAddr->Caption = (AnsiString) str;
            pmic_reg_ui.stPMICRegAddr->Tag = i;
            pmic_reg_ui.stPMICRegAddr->Top = i_stPMICAddr_top + i/2 * i_vertical_offset;
            pmic_reg_ui.stPMICRegAddr->Left = i_stPMICAddr_left;

            pmic_reg_ui.lblPMICRegValue0X = new TLabel(this);
            pmic_reg_ui.lblPMICRegValue0X->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegValue0X->Caption = "0x";
            pmic_reg_ui.lblPMICRegValue0X->Tag = i;
            pmic_reg_ui.lblPMICRegValue0X->Top = i_lblPMICRegValue0X_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegValue0X->Left = i_lblPMICRegValue0X_left;

            pmic_reg_ui.lblPMICRegValue = new TLabel(this);
            pmic_reg_ui.lblPMICRegValue->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegValue->Caption = "Value(Hex)";
            pmic_reg_ui.lblPMICRegValue->Tag = i;
            pmic_reg_ui.lblPMICRegValue->Top = i_edtPMICValue_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegValue->Left = i_edtPMICValue_left;

            pmic_reg_ui.edtPMICValue = new TEdit(this);
            pmic_reg_ui.edtPMICValue->Parent = frmPMICReg;
            pmic_reg_ui.edtPMICValue->Text = iter->uc_value;
            pmic_reg_ui.edtPMICValue->Tag = i;
            pmic_reg_ui.edtPMICValue->Top = i_edtPMICValue_top + i/2 * i_vertical_offset;
            pmic_reg_ui.edtPMICValue->Left = i_edtPMICValue_left;
            pmic_reg_ui.edtPMICValue->Width = 81;

            pmic_reg_ui.btnPMICRegRead = new TButton(this);
            pmic_reg_ui.btnPMICRegRead->Parent = frmPMICReg;
            pmic_reg_ui.btnPMICRegRead->Caption = "Read";
            pmic_reg_ui.btnPMICRegRead->Tag = i;
            pmic_reg_ui.btnPMICRegRead->Top = i_btnPMICRegRead_top + i/2 * i_vertical_offset;
            pmic_reg_ui.btnPMICRegRead->Left = i_btnPMICRegRead_left;
            pmic_reg_ui.btnPMICRegRead->Width = 65;
            pmic_reg_ui.btnPMICRegRead->OnClick = btnPMICRegReadClick;

            pmic_reg_ui.btnPMICRegWrite = new TButton(this);
            pmic_reg_ui.btnPMICRegWrite->Parent = frmPMICReg;
            pmic_reg_ui.btnPMICRegWrite->Caption = "Write";
            pmic_reg_ui.btnPMICRegWrite->Tag = i;
            pmic_reg_ui.btnPMICRegWrite->Top = i_btnPMICRegWrite_top + i/2 * i_vertical_offset;
            pmic_reg_ui.btnPMICRegWrite->Left = i_btnPMICRegWrite_left;
            pmic_reg_ui.btnPMICRegWrite->Width = 65;
            pmic_reg_ui.btnPMICRegWrite->OnClick = btnPMICRegWriteClick;
        }
        else
        {
            //pmic_reg_ui.lblPMICRegName = new TLabel(this);
            //pmic_reg_ui.lblPMICRegName->Parent = frmPMICReg;
            //pmic_reg_ui.lblPMICRegName->Caption = "Name";
            //pmic_reg_ui.lblPMICRegName->Top = i_lblPMICRegName_top + i/2 * i_vertical_offset;
            //pmic_reg_ui.lblPMICRegName->Left = i_lblPMICRegName_left + i_horizontal_offset;

            //pmic_reg_ui.stPMICRegName = new TStaticText(this);
            //pmic_reg_ui.stPMICRegName->Parent = frmPMICReg;
            //pmic_reg_ui.stPMICRegName->Caption = iter->as_name;
            //pmic_reg_ui.stPMICRegName->Tag = i;
            //pmic_reg_ui.stPMICRegName->Top = i_stPMICRegName_top + i/2 * i_vertical_offset;
            //pmic_reg_ui.stPMICRegNamer->Left = i_stPMICRegName_left + i_horizontal_offset;

            pmic_reg_ui.lblPMICRegAddr = new TLabel(this);
            pmic_reg_ui.lblPMICRegAddr->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegAddr->Caption = "Address (Hex)";
            pmic_reg_ui.lblPMICRegAddr->Top = i_lblPMICRegAddr_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegAddr->Left = i_lblPMICRegAddr_left + i_horizontal_offset;

            pmic_reg_ui.stPMICRegAddr = new TStaticText(this);
            pmic_reg_ui.stPMICRegAddr->Parent = frmPMICReg;
            char str[5];
            sprintf(str, "0x%X", iter->us_index);
            pmic_reg_ui.stPMICRegAddr->Caption = (AnsiString) str;
            pmic_reg_ui.stPMICRegAddr->Tag = i;
            pmic_reg_ui.stPMICRegAddr->Top = i_stPMICAddr_top + i/2 * i_vertical_offset;
            pmic_reg_ui.stPMICRegAddr->Left = i_stPMICAddr_left + i_horizontal_offset;

            pmic_reg_ui.lblPMICRegValue0X = new TLabel(this);
            pmic_reg_ui.lblPMICRegValue0X->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegValue0X->Caption = "0x";
            pmic_reg_ui.lblPMICRegValue0X->Tag = i;
            pmic_reg_ui.lblPMICRegValue0X->Top = i_lblPMICRegValue0X_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegValue0X->Left = i_lblPMICRegValue0X_left + i_horizontal_offset;

            pmic_reg_ui.lblPMICRegValue = new TLabel(this);
            pmic_reg_ui.lblPMICRegValue->Parent = frmPMICReg;
            pmic_reg_ui.lblPMICRegValue->Caption = "Value(Hex)";
            pmic_reg_ui.lblPMICRegValue->Tag = i;
            pmic_reg_ui.lblPMICRegValue->Top = i_edtPMICValue_top + i/2 * i_vertical_offset;
            pmic_reg_ui.lblPMICRegValue->Left = i_edtPMICValue_left + i_horizontal_offset;

            pmic_reg_ui.edtPMICValue = new TEdit(this);
            pmic_reg_ui.edtPMICValue->Parent = frmPMICReg;
            pmic_reg_ui.edtPMICValue->Text = iter->uc_value;
            pmic_reg_ui.edtPMICValue->Tag = i;
            pmic_reg_ui.edtPMICValue->Top = i_edtPMICValue_top + i/2 * i_vertical_offset;
            pmic_reg_ui.edtPMICValue->Left = i_edtPMICValue_left + i_horizontal_offset;
            pmic_reg_ui.edtPMICValue->Width = 81;

            pmic_reg_ui.btnPMICRegRead = new TButton(this);
            pmic_reg_ui.btnPMICRegRead->Parent = frmPMICReg;
            pmic_reg_ui.btnPMICRegRead->Caption = "Read";
            pmic_reg_ui.btnPMICRegRead->Tag = i;
            pmic_reg_ui.btnPMICRegRead->Top = i_btnPMICRegRead_top + i/2 * i_vertical_offset;
            pmic_reg_ui.btnPMICRegRead->Left = i_btnPMICRegRead_left + i_horizontal_offset;
            pmic_reg_ui.btnPMICRegRead->Width = 65;
            pmic_reg_ui.btnPMICRegRead->OnClick = btnPMICRegReadClick;

            pmic_reg_ui.btnPMICRegWrite = new TButton(this);
            pmic_reg_ui.btnPMICRegWrite->Parent = frmPMICReg;
            pmic_reg_ui.btnPMICRegWrite->Caption = "Write";
            pmic_reg_ui.btnPMICRegWrite->Tag = i;
            pmic_reg_ui.btnPMICRegWrite->Top = i_btnPMICRegWrite_top + i/2 * i_vertical_offset;
            pmic_reg_ui.btnPMICRegWrite->Left = i_btnPMICRegWrite_left + i_horizontal_offset;
            pmic_reg_ui.btnPMICRegWrite->Width = 65;
            pmic_reg_ui.btnPMICRegWrite->OnClick = btnPMICRegWriteClick;
        }
        m_pvPmicRegUI->push_back(pmic_reg_ui);
        i++;
    }
}

//---------------------------------------------------------------------------
bool  TfrmPMICReg::CheckFields(int tag)
{
    AnsiString  text;
    unsigned int idata;
    unsigned int sdata;
    vector<S_PMIC_REG_UI_T>:: iterator iter;
    for (iter = m_pvPmicRegUI->begin(); iter != m_pvPmicRegUI->end(); iter++)
    {
        if (iter->stPMICRegAddr->Tag == tag)
        {
            break;
        }
    }
    text = iter->stPMICRegAddr->Caption;
    text = text.SubString(3, text.Length()-2);
    if ( ! IsValidHexRegAddr(text, &idata))
    {
        return false;
    }
    m_uiPMICRegNumber = idata;
    text = iter->edtPMICValue->Text;
    // if (DEC_FORMAT == iter->edtPMICValue->Tag)  // Dec
    // {
    //     if (!IsValidDecRegValue(text, sdata))
    //     {
    //         edtPMICValueCheck(iter->edtPMICValue);
    //         return false;
    //     }
    // }
    // else  // Hex
    {
        if (!IsValidHexRegValue(text, &sdata))
        {
            edtPMICValueCheck(iter->edtPMICValue);
            return false;
        }
    }
    m_usPMICRegValue = sdata;


    return true;
}

//---------------------------------------------------------------------------
void  TfrmPMICReg::ReDrawFields(int tag)
{
    char str[256];
    vector<S_PMIC_REG_UI_T>:: iterator iter;
    for (iter = m_pvPmicRegUI->begin(); iter != m_pvPmicRegUI->end(); iter++)
    {
        if ((int)iter->lblPMICRegValue->Tag == tag)
        {
            break;
        }
    }

    // if (DEC_FORMAT == btnPMICRegValue->Tag)  // Dec
    // {
    //     iter->lblPMICRegValue->Caption = "Value (Dec)";
    //     iter->lblPMICRegValue0X->Visible = false;
    //     iter->edtPMICValue->Text = IntToStr(m_usPMICRegValue);
    // }
    // else  // Hex
    {
        iter->lblPMICRegValue->Caption = "Value (Hex)";
        iter->lblPMICRegValue0X->Visible = true;
        sprintf( str, "%X", (int)m_usPMICRegValue );
        iter->edtPMICValue->Text = str;
    }

}

//---------------------------------------------------------------------------
void __fastcall TfrmPMICReg::edtPMICValueCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " character is not valid ";

    text = edit->Text;

    if (! IsValidHexRegValue(text, &data))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }

    m_usPMICRegValue = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmPMICReg::btnPMICRegReadClick(TObject *Sender)
{
    TButton* btn = (TButton*) Sender;
    m_iTag = btn->Tag;

    if ( ! CheckFields(btn->Tag))
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register fail";
        return;
    }

    m_cBB_PMIC_REG_Obj.ConfirmCallback = ::CNF_PMIC_ReadRegister;
    m_cBB_PMIC_REG_Obj.REQ_ReadRegister_Start( m_uiPMICRegNumber );
    sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register progressing";
}

//-----------------------------------------------
void  TfrmPMICReg::CNF_PMIC_ReadRegister(void)
{
    META_RESULT state = m_cBB_PMIC_REG_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_usPMICRegValue = m_cBB_PMIC_REG_Obj.Get_RegValue();
        ReDrawFields(m_iTag);
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register successfully";
    }
    break;

    case META_FAILED:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register fail";
        Application->MessageBox( "Execution Failure : Read PMIC register", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register timeout";
        Application->MessageBox( "Execution Timeout : Read PMIC register", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Read PMIC register stop";
    }
    break;

    default:

        break;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmPMICReg::btnPMICRegWriteClick(TObject *Sender)
{
    TButton* btn = (TButton*) Sender;
    m_iTag = btn->Tag;

    if (!CheckFields(btn->Tag))
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register fail";
        Application->MessageBox( "Execution Failure : Write PMIC register", "FAILURE", MB_OK );
        return;
    }

    m_cBB_PMIC_REG_Obj.ConfirmCallback = ::CNF_PMIC_WriteRegister;
    m_cBB_PMIC_REG_Obj.REQ_WriteRegister_Start( m_uiPMICRegNumber, m_usPMICRegValue );
    sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write PMIC register progressing";
}

//-----------------------------------------------
void TfrmPMICReg::CNF_PMIC_WriteRegister(void)
{
    META_RESULT state = m_cBB_PMIC_REG_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register successfully";
    }
    break;

    case META_FAILED:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register fail";
        Application->MessageBox( "Execution Failure : Write Baseband register", "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register timeout";
        Application->MessageBox( "Execution Timeout : Write Baseband register", "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        sbPMICReg->Panels->Items[0]->Text = (AnsiString) "  Write baseband register stop";
    }
    break;

    default:
        break;
    }
}



void __fastcall TfrmPMICReg::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void  TfrmPMICReg::ShowHintLabel(TControl *sender, char* hint)
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
void __fastcall TfrmPMICReg::FormShow(TObject *Sender)
{
    LOG("PMICReg form center the form.");
    FormPositionSetting::CenterForm(this);    
}
//---------------------------------------------------------------------------
