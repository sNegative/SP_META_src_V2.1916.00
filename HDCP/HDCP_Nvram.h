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
 *   HDCP_Nvram.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   HDCP NVRAM read and write class header file.
 *
 * Author:
 * -------
 *  Rongguo Zhang (mtk80761)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 16 2012 11:45:30  $
 * $Log:    $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------
#ifndef _HDCP_NVRAM_H_
#define _HDCP_NVRAM_H_

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

#define HDCP_KEY_ARRAY_NUMBER_FILE 305 

/*struct FILE_CUSTOM_HDCP_KEY_STRUCT
{
    unsigned char HdcpKeyArray[287];
};

META_RESULT  SP_META_NVRAM_Compose_HDCP(const FILE_CUSTOM_HDCP_KEY_STRUCT *param, char *buf, const int buf_len)
{
    return META_SUCCESS;
}
META_RESULT  SP_META_NVRAM_Decompose_HDCP(FILE_CUSTOM_HDCP_KEY_STRUCT *param, const char *buf, const int buf_len)
{
    return META_SUCCESS;
}   */


class HDCP_NVRAM
{
private:
    FILE_CUSTOM_HDCP_KEY_STRUCT m_sHDCPNvramStruct;
    META_RESULT m_eConfirmState;

    int  m_iHDCPBufSize;
    char *m_pcHDCPBuf;

protected:
    void Confirm(META_RESULT confirm_state);

public:
    // Public member
    HDCP_NVRAM( void );
    ~HDCP_NVRAM( );

    // Public interface
    void (*ConfirmCallback)( void );
    META_RESULT Get_ConfirmState(void);

    void Get_HDCPValue(FILE_CUSTOM_HDCP_KEY_STRUCT* pHDCPNvramValue);
    void Set_HDCPValue(FILE_CUSTOM_HDCP_KEY_STRUCT hdcpNvramValue);
    void REQ_Read_From_NVRAM();
    void CNF_ReadFromNVRAM( void );
    void REQ_Write_To_NVRAM();
    void CNF_WriteToNVRAM( void );
    bool REQ_Read_HDCP_Key_File(char *filename);
};
#endif
