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
 *   bt_info_mt6611.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MT6611 BT info NVRAM access source
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
#include <IniFiles.hpp>

#pragma hdrstop

// BT
#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

#ifndef  _BT_HCI_FT_H_
#include "bt_hci_ft.h"
#endif

#ifndef  _BT_INFO_MT6611_H_
#include "bt_info_mt6611.h"
#endif

// man
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

// misc
#ifndef  _MISC_H_
#include "misc.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// NVRAM
#ifndef  _NVRAM_VER_H_
#include "nvram_ver.h"
#endif

#define MT6611_BT_CAP_ID_IDX  0
//===========================================================================
static CBTINFO6611* g_bt_info_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static void __stdcall CNF_Calibrate_Cyrstal_Clock_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    g_bt_info_ptr->CNF_Calibrate_Cyrstal_Clock_HCIEvent(cnf, token, usrData);
}

//-------------------------------------------------------------------------
static void __stdcall CNF_Get_Result_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    g_bt_info_ptr->CNF_Get_Result_HCIEvent(cnf, token, usrData);
}

//-------------------------------------------------------------------------
static void __stdcall CNF_Set_CapId_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    g_bt_info_ptr->CNF_Set_CapId_HCIEvent(cnf, token, usrData);
}

//-------------------------------------------------------------------------
static void CNF_ReadFromNVRAM(void)
{
    g_bt_info_ptr->CNF_ReadFromNVRAM();
}

//-------------------------------------------------------------------------
static void CNF_WriteToNVRAM(void)
{
    g_bt_info_ptr->CNF_WriteToNVRAM();
}

//===========================================================================
CBTINFO6611::CBTINFO6611(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    m_uiBufSize = NULL;
    m_cBuf = NULL;
    
    m_ucCapID = 0;
    m_uiLpoPllCount = 0;
    m_bEventOk = false;
    m_bDownloadTrigger = false;
}

//---------------------------------------------------------------------------
CBTINFO6611::~CBTINFO6611()
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    if(m_cBuf)
    {
        delete [] m_cBuf;
        m_cBuf = NULL;
    }
}

//---------------------------------------------------------------------------
/*void CBTINFO6611::REQ_Stop(void)
{
    if(!g_bIsRunning)
    {
        return;
    }

    NVRAMMan->REQ_Stop();
    Confirm(METAAPP_STOP);
} */

//---------------------------------------------------------------------------
void  CBTINFO6611::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
bool CBTINFO6611::REQ_Enable_PCM_Clock_Sync_Signal(void)
{
    META_RESULT MetaResult = SP_META_BT_EnablePcmClockSyncSignal_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}

//===========================================================================
bool CBTINFO6611::REQ_Start_Calibrate_Crystal_Clock(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning  = true;
    CBTHCIFT HCI_FT_Obj;
    BT_HCI_COMMAND s_hci_cmd;
    HCI_FT_Obj.Reset_HCI_Command(s_hci_cmd);

    // C7 FC 04 02 01 32 00
    s_hci_cmd.m_opcode = 0xFCC7;
    s_hci_cmd.m_len = 0x04;
    s_hci_cmd.m_cmd[0] = 0x02;
    s_hci_cmd.m_cmd[1] = 0x01;
    s_hci_cmd.m_cmd[2] = 0x32;
    s_hci_cmd.m_cmd[3] = 0x00;

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &s_hci_cmd, ::CNF_Calibrate_Cyrstal_Clock_HCIEvent, NULL, HCE_COMMAND_COMPLETE);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------
void CBTINFO6611::CNF_Calibrate_Cyrstal_Clock_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
}

//===========================================================================
bool CBTINFO6611::REQ_Get_Result(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning  = true;
    CBTHCIFT HCI_FT_Obj;
    BT_HCI_COMMAND s_hci_cmd;
    HCI_FT_Obj.Reset_HCI_Command(s_hci_cmd);

    // C8 FC 00
    s_hci_cmd.m_opcode = 0xFCC8;
    s_hci_cmd.m_len = 0x00;

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &s_hci_cmd, ::CNF_Get_Result_HCIEvent, NULL, HCE_COMMAND_COMPLETE);
    if ((MetaResult != META_SUCCESS) || (!m_bEventOk))
    {
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------
void CBTINFO6611::CNF_Get_Result_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    // 0E 0C 01 C8 FC 00 CC CC DD DD DD DD EE EE
    if ((0x01 != cnf->m_parms[0]) ||  // connect not successfully
            (0xC8 != cnf->m_parms[1]) ||
            (0xFC != cnf->m_parms[2]) ||
            (0x00 != cnf->m_parms[3])
       )
    {
        m_bEventOk = false;
        return;
    }
    m_uiLpoPllCount = (cnf->m_parms[9] << 24) |
                      (cnf->m_parms[8] << 16) |
                      (cnf->m_parms[7] << 8)  |
                      cnf->m_parms[6];
    m_bEventOk = true;
}

//===========================================================================
bool CBTINFO6611::REQ_Set_CapId(unsigned char cap_id)
{
    g_bt_info_ptr = this;
    g_bIsRunning  = true;
    CBTHCIFT HCI_FT_Obj;
    BT_HCI_COMMAND s_hci_cmd;
    HCI_FT_Obj.Reset_HCI_Command(s_hci_cmd);

    // 7F FC 01 xx
    s_hci_cmd.m_opcode = 0xFC7F;
    s_hci_cmd.m_len = 0x01;
    s_hci_cmd.m_cmd[0] = cap_id;

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &s_hci_cmd, ::CNF_Set_CapId_HCIEvent, NULL, HCE_COMMAND_COMPLETE);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------
void CBTINFO6611::CNF_Set_CapId_HCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    m_bEventOk = true;
}

//===========================================================================
void CBTINFO6611::REQ_Read_From_NVRAM_Start(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;

    REQ_Read_From_NVRAM();
}

//---------------------------------------------------------------------------
void CBTINFO6611::REQ_Read_From_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cBuf)
    {
        // META_RESULT MetaResult = WM_META_NVRAM_GetRecLen("NVRAM_EF_BTRADIO_MT6611_LID", (int *) &m_uiBufSize);
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("AP_CFG_RDEB_FILE_BT_ADDR_LID",(int *) &m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cBuf = new  char[m_uiBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    //NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_BTRADIO_MT6611_LID",
    NVRAMMan->REQ_ReadNVRAM_Start("AP_CFG_RDEB_FILE_BT_ADDR_LID",
                                  1,
                                  m_uiBufSize,
                                  m_cBuf
                                 );
}

//-------------------------------------
void CBTINFO6611::CNF_ReadFromNVRAM(void)
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
        META_RESULT MetaResult = SP_META_NVRAM_BT_Decompose_MT6611Radio(&m_sBtInfo,
                                 m_cBuf,
                                 m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        if (m_bDownloadTrigger)
        {
            //m_sBtInfo.Radio[MT6611_BT_CAP_ID_IDX] = m_ucCapID;
            m_sBtInfo.CapId[0] = m_ucCapID;
            REQ_Write_To_NVRAM();
        }
        else
        {
            //m_ucCapID = m_sBtInfo.Radio[MT6611_BT_CAP_ID_IDX];
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

//===========================================================================
void CBTINFO6611::REQ_Write_To_NVRAM_Start(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning = true;

    m_bDownloadTrigger = true;

    //  REQ_Write_To_NVRAM();
    REQ_Read_From_NVRAM();
}

//---------------------------------------------------------------------------
void CBTINFO6611::REQ_Write_To_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;

    if (NULL == m_cBuf)
    {
        // MetaResult = WM_META_NVRAM_GetRecLen("NVRAM_EF_BTRADIO_MT6611_LID", (int *) &m_uiBufSize);
        MetaResult = SP_META_NVRAM_GetRecLen("AP_CFG_RDEB_FILE_BT_ADDR_LID", (int *) &m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cBuf = new char[m_uiBufSize];
    }

    MetaResult = SP_META_NVRAM_BT_Compose_MT6611Radio(&m_sBtInfo,
                 m_cBuf,
                 m_uiBufSize);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    // NVRAMMan->REQ_WriteNVRAM_Start("AP_CFG_RDCL_FILE_BT_CAPID_LID",
    NVRAMMan->REQ_WriteNVRAM_Start("AP_CFG_RDEB_FILE_BT_ADDR_LID",
                                   1,
                                   m_uiBufSize,
                                   m_cBuf);
}

//-------------------------------------
void CBTINFO6611::CNF_WriteToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    Confirm(state);
}

//===========================================================================
//////////////////////////////////  INI file   //////////////////////////////
//===========================================================================
static const AnsiString as_SECTION_NAME = "BT Info";
static const AnsiString as_KEY_NAME = "Crystal CAP ID";

//---------------------------------------------------------------------------
bool CBTINFO6611::BtCapIdSectionExist(char *filename)
{
    TIniFile *ini_file;

    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return false;
    }

    if (!ini_file->SectionExists(as_SECTION_NAME))
    {
        delete ini_file;
        return false;
    }

    delete ini_file;
    return true;
}

//---------------------------------------------------------------------------
bool CBTINFO6611::REQ_Read_From_File(char *filename)
{
    TIniFile   *ini_file;
    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return false;
    }

    m_ucCapID = ini_file->ReadInteger(as_SECTION_NAME,
                                      as_KEY_NAME,
                                      127);

    //m_sBtInfo.Radio[MT6611_BT_CAP_ID_IDX] = m_ucCapID;

    delete  ini_file;
    return true;
}

//---------------------------------------------------------------------------
bool CBTINFO6611::REQ_Write_To_File(char *filename)
{
    TIniFile *ini_file;
    ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return  false;
    }

    ini_file->WriteString(as_SECTION_NAME,
                          as_KEY_NAME,
                          IntToStr(m_ucCapID));

    delete ini_file;
    return true;

}

//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CBTINFO6611::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CBTINFO6611::Get_BTInfo(NVRAM_BTRADIO_MT6611_S& s_bt_info)
{
    s_bt_info = m_sBtInfo;
}

//---------------------------------------------------------------------------
void CBTINFO6611::Set_BTInfo(NVRAM_BTRADIO_MT6611_S bt_info)
{
    m_sBtInfo = bt_info;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CBTINFO6611::Get_BT_CAP_ID(void)
{
    return m_ucCapID;
}

//---------------------------------------------------------------------------
void CBTINFO6611::Set_BT_CAP_ID(unsigned char cap_id)
{
    m_ucCapID = cap_id;
    //m_sBtInfo.Radio[MT6611_BT_CAP_ID_IDX] = cap_id;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int CBTINFO6611::Get_LpoPllCount(void)
{
    return m_uiLpoPllCount;
}

