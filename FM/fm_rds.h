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
 *   fm_rds.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   FM RDS header
 *
 * Author:
 * -------
 *  YH Sung (mtk02607)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _FM_RDS_H_
#define  _FM_RDS_H_

// common
#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _TIME_UTILS_H_
#include "time_utils.h"
#endif

/*---------------------------------------------------------------------------*/
class  CFMRDS
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;
    bool m_bFMSupport;
    FM_CHIP_ID_CNF_T m_sFMChipId;
    FM_SetRDS_REQ_T m_sRDSREQ;
    FM_RDS_Good_Block_Counter_CNF_T m_sRDSGoodBlockCounter;
    FM_RDS_Bad_Block_Counter_CNF_T m_sRDSBadBlockCounter;
//rongguo 2011-06-24
//        FM_RDS_Group_Counter_CNF_T m_sRDSGroupCounter;
    FM_RDS_GROUPCOUNTER_T m_sRDSGroupCounter;
    FM_RDS_Info_CNF_T m_sRDSInfo;
    FM_RDS_Status_CNF_T m_sRDSStatus;
//rongguo 2011-06-24
//        FM_RDS_Block_CNF_T m_sRDSLogData;
    FM_RDS_LOGDATA_T m_sRDSLogData;
    unsigned short m_u2RDSBLERRatio;
    HANDLE hPostMsgDestHandle;
    S_TIME RDS_StartTime;
    S_TIME RDS_EventSyncTime;

protected:
public:
    void REQ_FM_RDS_On(void);
    void REQ_FM_RDS_Off(void);
    void REQ_FM_RDS_Reset_BlockCounter(void);
    void REQ_FM_RDS_Reset_GroupCounter(void);
    void REQ_FM_RDS_Get_GoodBlockCounter(void);
    void REQ_FM_RDS_Get_BadBlockCounter(void);
    void REQ_FM_RDS_Get_GroupCounter(void);
    void REQ_FM_RDS_Get_RDSBLERRatio(void);
    void REQ_FM_RDS_Get_RDSLogData(void);
    void __stdcall CNF_RDSInfoUpdate(const FM_RDS_Info_CNF_T *cnf, const short token, void *usrData);
    void __stdcall CNF_RDSStatusUpdate(const FM_RDS_Status_CNF_T *cnf, const short token, void *usrData);


    void REQ_FM_RDS_On_Start(HANDLE handle);
    void REQ_FM_RDS_Off_Start(void);
    void REQ_FM_RDS_Reset_BlockCounter_Start(void);
    void REQ_FM_RDS_Reset_GroupCounter_Start(void);
    void REQ_FM_RDS_Get_GoodBlockCounter_Start(void);
    void REQ_FM_RDS_Get_BadBlockCounter_Start(void);
    void REQ_FM_RDS_Get_GroupCounter_Start(void);
    void REQ_FM_RDS_Get_RDSBLERRatio_Start(void);
    void REQ_FM_RDS_Get_RDSLogData_Start(void);


    void Confirm(META_RESULT confirm_state);

    CFMRDS(void);
    ~CFMRDS();

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void  (*ConfirmCallback)(void);


    //---------------------------------------------------------------------------
    // Public interface

    // query
    bool Query_FMSupport_Start(void);
    bool REQ_Query_FMChipID_Start(FM_CHIP_ID_CNF_T& fm_chip_id);

    // global information
    META_RESULT Get_ConfirmState(void);
    FM_RDS_Good_Block_Counter_CNF_T Get_FM_RDS_GoodBlockCounter(void);
    FM_RDS_Bad_Block_Counter_CNF_T Get_FM_RDS_BadBlockCounter(void);
//rongguo 2011-06-24
//        FM_RDS_Group_Counter_CNF_T Get_FM_RDS_GroupCounter(void);
    FM_RDS_GROUPCOUNTER_T Get_FM_RDS_GroupCounter(void);
    S_TIME* Get_FM_RDS_StartTime();
    S_TIME* Get_FM_RDS_EventSyncTime();
    unsigned short Get_FM_RDS_BLER(void);
//rongguo 2011-06-24
//        FM_RDS_Block_CNF_T* Get_FM_RDS_LogData(void);
    FM_RDS_LOGDATA_T* Get_FM_RDS_LogData(void);
};

/*---------------------------------------------------------------------------*/
#endif
