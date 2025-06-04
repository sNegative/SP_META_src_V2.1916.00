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
 *   form_PMICReg.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   PMIC register form header
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
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_PMICREG_H_
#define _FORM_PMICREG_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

#ifndef  _BB_PMIC_REG_H_
#include "bb_pmic_reg.h"
#endif

typedef struct
{
    TLabel *lblPMICRegName;
    TStaticText *stPMICRegName;
    TLabel *lblPMICRegAddr;
    TStaticText *stPMICRegAddr;
    TLabel *lblPMICRegValue0X;
    TLabel *lblPMICRegValue;
    TEdit *edtPMICValue;
    TButton *btnPMICRegRead;
    TButton *btnPMICRegWrite;
} S_PMIC_REG_UI_T;


//---------------------------------------------------------------------------
class TfrmPMICReg : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbPMICReg;
    TTimer *HintTimer;
    TStaticText *lblHint;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);

private:	// User declarations
    bool    m_bInit;
    PMIC_ID m_sPmicId;
    int     m_iTag;
    unsigned int   m_uiPMICRegNumber;
    unsigned short  m_usPMICRegValue;
    CBBPMICREG m_cBB_PMIC_REG_Obj;
    vector<S_BB_PMIC_REG_T> *m_pvPmicReg;
    vector<S_PMIC_REG_UI_T> *m_pvPmicRegUI;

public:		// User declarations
    __fastcall TfrmPMICReg(TComponent* Owner);
    void Init(void);
    void Display_PMICRegister(void);
    bool CheckFields(int tag);
    void ReDrawFields(int tag);
    void ShowHintLabel(TControl *sender, char* hint);
    void __fastcall edtPMICValueCheck(TObject *Sender);
    void __fastcall btnPMICRegReadClick(TObject *Sender);
    void CNF_PMIC_ReadRegister(void);
    void __fastcall btnPMICRegWriteClick(TObject *Sender);
    void CNF_PMIC_WriteRegister(void);

    // vector
    void  AllocateVector(void);
    void  DeAllocateVector(void);
    void  EraseVector(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPMICReg *frmPMICReg;
//---------------------------------------------------------------------------
#endif
