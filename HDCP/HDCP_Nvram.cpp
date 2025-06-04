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
 *   HDCP_Nvram.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   HDCP NVRAM read and write class source file.
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
#include <IniFiles.hpp>

#pragma hdrstop

#include <fstream>

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef HDCP_ENCRYPTION_H
#include "HdcpEncryption.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef _HDCP_NVRAM_H_
#include "HDCP_Nvram.h"
#endif

using namespace std;

static HDCP_NVRAM* sp_HDCP_ptr;
static bool g_bIsRunning;
//===========================================================================
static void CNF_ReadFromNVRAM(void)
{
    sp_HDCP_ptr->CNF_ReadFromNVRAM();
}
//---------------------------------------------------------------------------
static void CNF_WriteToNVRAM(void)
{
    sp_HDCP_ptr->CNF_WriteToNVRAM();
}
//===========================================================================
HDCP_NVRAM::HDCP_NVRAM(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_pcHDCPBuf = NULL;
    m_iHDCPBufSize = 0;
}
//---------------------------------------------------------------------------
HDCP_NVRAM::~HDCP_NVRAM()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    if (NULL != m_pcHDCPBuf)
    {
        delete [] m_pcHDCPBuf;
        m_pcHDCPBuf = NULL;
        m_iHDCPBufSize = 0;
    }
}
//===========================================================================
////////////////////////////       Common          //////////////////////////
//===========================================================================
void HDCP_NVRAM::Confirm(META_RESULT confirm_state)
{
    if(!g_bIsRunning)  return;
    g_bIsRunning = false;
    if(ConfirmCallback == 0)  return;
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}
//--------------------------------------------------------------------------
META_RESULT HDCP_NVRAM::Get_ConfirmState(void)
{
    return m_eConfirmState;
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::Get_HDCPValue(FILE_CUSTOM_HDCP_KEY_STRUCT* pHDCPNvramValue)
{
    memcpy(pHDCPNvramValue, &m_sHDCPNvramStruct, sizeof(m_sHDCPNvramStruct));
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::Set_HDCPValue(FILE_CUSTOM_HDCP_KEY_STRUCT hdcpNvramValue)
{
    memcpy(&m_sHDCPNvramStruct, &hdcpNvramValue, sizeof(m_sHDCPNvramStruct));
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::REQ_Read_From_NVRAM()
{
    sp_HDCP_ptr = this;
    g_bIsRunning = true;

    if (NULL == m_pcHDCPBuf)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen( "AP_CFG_RDCL_FILE_HDCP_KEY_LID",&m_iHDCPBufSize );
        if(MetaResult != META_SUCCESS)
        {
            Confirm( META_FAILED );
            return;
        }
        m_pcHDCPBuf = new char[m_iHDCPBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start( "AP_CFG_RDCL_FILE_HDCP_KEY_LID",
                                   1,
                                   m_iHDCPBufSize,
                                   m_pcHDCPBuf );
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::CNF_ReadFromNVRAM( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        FILE_CUSTOM_HDCP_KEY_STRUCT param= {0};
        META_RESULT mr = SP_META_NVRAM_Decompose_HDCP(&param, m_pcHDCPBuf, m_iHDCPBufSize);
        if(mr != META_SUCCESS)
            Confirm(META_FAILED);
        else
        {
            memcpy(&m_sHDCPNvramStruct, &param, sizeof(m_sHDCPNvramStruct));
            Confirm(META_SUCCESS);
        }
    }
    break;

    default:
    {
        Confirm(state);
    }
    break;
    }
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::REQ_Write_To_NVRAM()
{
    sp_HDCP_ptr = this;
    g_bIsRunning = true;
    META_RESULT MetaResult;

    if (NULL == m_pcHDCPBuf)
    {
        MetaResult = SP_META_NVRAM_GetRecLen("AP_CFG_RDCL_FILE_HDCP_KEY_LID", &m_iHDCPBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_pcHDCPBuf = new char[m_iHDCPBufSize];
    }

    MetaResult = SP_META_NVRAM_Compose_HDCP(&m_sHDCPNvramStruct, m_pcHDCPBuf, m_iHDCPBufSize);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    
    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("AP_CFG_RDCL_FILE_HDCP_KEY_LID",
                                   1,
                                   m_iHDCPBufSize,
                                   m_pcHDCPBuf);
}
//---------------------------------------------------------------------------
void HDCP_NVRAM::CNF_WriteToNVRAM( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    Confirm(state);
}
//---------------------------------------------------------------------------
bool HDCP_NVRAM::REQ_Read_HDCP_Key_File(char *filename)
{
	int count = 0;
    char bufNoEncrypt[HDCP_KEY_ARRAY_NUMBER_FILE] = {0};
    char bufEncrypt[HDCP_KEY_ARRAY_NUMBER] = {0};
    ifstream in(filename, ios::binary);
    
    in.seekg(0, ios::beg);
    in.read(bufNoEncrypt, sizeof(bufNoEncrypt));
//    in.read((char*)&m_sHDCPNvramStruct, HDCP_KEY_ARRAY_NUMBER);
    count = in.gcount();
	if(/*!in.eof() ||*/ count != sizeof(bufNoEncrypt))
    {
        LOG("The input file is invalid.");
        return false;
	}

    LOG("HDCP: before HdcpProcess.");
    for(int i = 0; i < HDCP_KEY_ARRAY_NUMBER_FILE; i++)
    {
        LOG("HDCP: HdcpProcess input bufNoEncrypt[%d]: 0x%2.2X.", i, bufNoEncrypt[i] & 0xFF);
    }
    EN_HDCP_RET retHdcp = HdcpProcess((unsigned char *)bufNoEncrypt, (unsigned char *)bufEncrypt);
    LOG("HDCP: after HdcpProcess.");
    for(int i = 0; i < HDCP_KEY_ARRAY_NUMBER; i++)
    {
        LOG("HDCP: HdcpProcess output bufEncrypt[%d]: 0x%2.2X.", i, bufEncrypt[i] & 0xFF);
    }
    
    LOG("retHdcp is: %d.", (int)retHdcp);
    if(R_OK != retHdcp)
    {
        LOG("retHdcp is not ok.");
        return false;
	}

    memcpy((char*)&m_sHDCPNvramStruct, bufEncrypt, sizeof(bufEncrypt));
    return true;
}
//---------------------------------------------------------------------------
