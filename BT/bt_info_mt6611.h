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
 *   bt_info_mt6611.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MT6611 BT info NVRAM access header
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
 * Feb 25 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_INFO_MT6611_H_
#define  _BT_INFO_MT6611_H_

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

/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
class CBTINFO6611
{
private:
    META_RESULT  m_eConfirmState;
    bool  m_bDownloadTrigger;
    CMETAHANDLE m_META_HANDLE_Obj;
    NVRAM_BTRADIO_MT6611_S  m_sBtInfo;
    unsigned char m_ucCapID;
    unsigned int m_uiLpoPllCount;
    unsigned int m_uiBufSize;
    char         *m_cBuf;
    bool m_bEventOk;

protected:
public:
    void Confirm(META_RESULT confirm_state);
    CBTINFO6611(void);
    ~CBTINFO6611();
    void REQ_Read_From_NVRAM(void);
    void REQ_Write_To_NVRAM(void);

    // call back
    void CNF_Calibrate_Cyrstal_Clock_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void CNF_Get_Result_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void CNF_Set_CapId_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void CNF_ReadFromNVRAM(void);
    void CNF_WriteToNVRAM(void);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    // Public member
    void  (*ConfirmCallback)(void);
    void  REQ_Stop(void);

    // calibration
    bool REQ_Enable_PCM_Clock_Sync_Signal(void);
    bool REQ_Start_Calibrate_Crystal_Clock(void);
    bool REQ_Get_Result(void);
    bool REQ_Set_CapId(unsigned char cap_id);

    // NVRAM
    void  REQ_Read_From_NVRAM_Start(void);
    void  REQ_Write_To_NVRAM_Start(void);

    // file
    bool  BtCapIdSectionExist(char *filename);
    bool  REQ_Read_From_File(char *filename);
    bool  REQ_Write_To_File(char *filename);

    // export information
    META_RESULT   Get_ConfirmState(void);
    void Get_BTInfo(NVRAM_BTRADIO_MT6611_S& bt_info);
    void Set_BTInfo(NVRAM_BTRADIO_MT6611_S bt_info);
    unsigned char Get_BT_CAP_ID(void);
    void Set_BT_CAP_ID(unsigned char cap_id);
    unsigned int Get_LpoPllCount(void);
};

/*---------------------------------------------------------------------------*/
#endif

