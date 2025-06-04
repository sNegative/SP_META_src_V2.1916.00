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
 *   bb_pmic_reg.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  PMIC register read/write header
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
 * Nov 8 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BB_PMIC_REG_H_
#define  _BB_PMIC_REG_H_

#include <vector.h>
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

#define  MAX_PMIC_REG_NUM   50

/*---------------------------------------------------------------------------*/
typedef struct
{
    unsigned short us_index;
    AnsiString as_name;
    unsigned char uc_value;
} S_BB_PMIC_REG_T;

/*---------------------------------------------------------------------------*/
class  CBBPMICREG
{
private:
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    short  m_sBBID_REG;
    unsigned int  m_uiRegNumber;
    unsigned short m_usValue;
    PMIC_ID m_sPmicId;
    vector<S_BB_PMIC_REG_T> *m_pvPmicReg;

protected:

    void  Confirm(META_RESULT confirm_state);

public:

    CBBPMICREG(void);
    ~CBBPMICREG();

    void  REQ_Finish(void);
    void  REQ_TimeOut(void);
//   void  REQ_Stop(void);

    // vector
    void  AllocateVector(void);
    void  DeAllocateVector(void);
    void  EraseVector(void);

    void  REQ_ReadRegister(void);
    void  REQ_WriteRegister(void);
    void  REQ_SetRegister_HWT(void);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)(void);

    //-------------------------------------------------------------------------
    // Public interface
    // register read/write
    void  REQ_ReadRegister_Start(unsigned int addr);
    void  REQ_WriteRegister_Start(unsigned int addr, unsigned short value);

    // INI file
    bool  PMICRegisterSectionExist(char *filename);
    bool  REQ_Read_From_File(char *filename);
    bool  REQ_Write_To_File(char *filename);


    // query
    bool  Query_PMIC_ID_Start(void);

    // export information
    META_RESULT Get_ConfirmState(void);
    unsigned short Get_RegValue(void);
    PMIC_ID* Get_PMIC_ID(void);
    vector<S_BB_PMIC_REG_T> *Get_PMICRegVector(void);

};

/*---------------------------------------------------------------------------*/
#endif
