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
 *   bt_id.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT chip ID header
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BT_ID_H_
#define  _BT_ID_H_

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

/*---------------------------------------------------------------------------*/
class CBTID
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    BT_ModuleID_S m_sBTModuleID;
    bool  m_bEventOk;
    META_RESULT m_eConfirmState;
    unsigned char BT_Version_Buf[4];

protected:
public:
    CBTID(void);
    ~CBTID();
    void REQ_Stop(void);
    void REQ_BT_GET_HW_Version_Start(void);
    void REQ_BT_GET_HW_Version(void);
    void REQ_BT_GET_FW_Version_Start(void);
    void REQ_BT_GET_FW_Version(void);
    void CNF_GET_BT_HW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void CNF_GET_BT_FW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void  Compose_GET_HW_Versionl_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_GET_FW_Versionl_HCI_Command( BT_HCI_COMMAND &hci_cmd);
    bool  DeCompose_GET_HW_Versionl_HCI_Event( BT_HCI_EVENT hci_event );
    bool  DeCompose_GET_FW_Versionl_HCI_Event( BT_HCI_EVENT hci_event );
    bool  Compare_Buf(unsigned char *pSourceBuf, unsigned char *pDestBuf,unsigned int bufLen);


    void Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    bool Set_BT_ModuleID();
    void  Confirm(META_RESULT confirm_state);
    void MetaResult_Confirm(META_RESULT MetaResult);

    /*//function
       static void REQ_Stop(void);

       static void  REQ_BT_GET_HW_Vertion( void );
       static void __stdcall CNF_GET_BT_HW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData);

       static void  REQ_BT_GET_FW_Vertion( void );
       static void __stdcall CNF_GET_BT_FW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    */

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    void  (*ConfirmCallback)( void );
    // Public interface
    // query
    bool REQ_Query_MoudleID_Start(void);
    // global information

    void Get_BTMoudleID(BT_ModuleID_S& bt_module_id);

};

/*---------------------------------------------------------------------------*/
#endif
