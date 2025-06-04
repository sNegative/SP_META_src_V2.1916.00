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
 *   bt_info_mt6601.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MT6601 BT info NVRAM access source
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
 * Jun 19 2008 mtk00490
 * [STP100001739] [META] META ver 5.0820.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _BT_INFO_MT6601_H_
#include "bt_info_mt6601.h"
#endif

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

#define MT6601_BT_CAP_ID_IDX  2
//===========================================================================
static CBTINFO6601* g_bt_info_ptr;
static bool g_bIsRunning = false;

//===========================================================================
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
CBTINFO6601::CBTINFO6601(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;

    m_uiBufSize = NULL;
    m_cBuf = NULL;
    m_bDownloadTrigger = false;
    m_ucCapID = 0;
}

//---------------------------------------------------------------------------
CBTINFO6601::~CBTINFO6601()
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
/*void CBTINFO6601::REQ_Stop(void)
{
    if(!g_bIsRunning)
    {
        return;
    }

    NVRAMMan->REQ_Stop();
    Confirm(METAAPP_STOP);
} */

//---------------------------------------------------------------------------
void  CBTINFO6601::Confirm(META_RESULT confirm_state)
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
void CBTINFO6601::REQ_Read_From_NVRAM_Start(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;

    REQ_Read_From_NVRAM();
}

//---------------------------------------------------------------------------
void CBTINFO6601::REQ_Read_From_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == m_cBuf)
    {
        META_RESULT MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_BTRADIO_MT6601_LID", (int *) &m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cBuf = new  char[m_uiBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_BTRADIO_MT6601_LID",
                                  1,
                                  m_uiBufSize,
                                  m_cBuf
                                 );
}

//-------------------------------------
void CBTINFO6601::CNF_ReadFromNVRAM(void)
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
        META_RESULT MetaResult = SP_META_NVRAM_BT_Decompose_MT6601Radio(&m_sBtInfo,
                                 m_cBuf,
                                 m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        if (m_bDownloadTrigger)
        {
            m_sBtInfo.Radio[MT6601_BT_CAP_ID_IDX] = m_ucCapID;
            REQ_Write_To_NVRAM();
        }
        else
        {
            m_ucCapID = m_sBtInfo.Radio[MT6601_BT_CAP_ID_IDX];
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
void CBTINFO6601::REQ_Write_To_NVRAM_Start(void)
{
    g_bt_info_ptr = this;
    g_bIsRunning = true;

    m_bDownloadTrigger = true;

    REQ_Write_To_NVRAM();
}

//---------------------------------------------------------------------------
void CBTINFO6601::REQ_Write_To_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;

    if (NULL == m_cBuf)
    {
        MetaResult = SP_META_NVRAM_GetRecLen("NVRAM_EF_BTRADIO_MT6601_LID", (int *) &m_uiBufSize);
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_cBuf = new char[m_uiBufSize];
    }

    MetaResult = SP_META_NVRAM_BT_Compose_MT6601Radio(&m_sBtInfo,
                 m_cBuf,
                 m_uiBufSize);

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_BTRADIO_MT6601_LID",
                                   1,
                                   m_uiBufSize,
                                   m_cBuf);
}

//-------------------------------------
void CBTINFO6601::CNF_WriteToNVRAM(void)
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
bool CBTINFO6601::BtCapIdSectionExist(char *filename)
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
bool CBTINFO6601::REQ_Read_From_File(char *filename)
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

    m_sBtInfo.Radio[MT6601_BT_CAP_ID_IDX] = m_ucCapID;

    delete  ini_file;
    return true;
}

//---------------------------------------------------------------------------
bool CBTINFO6601::REQ_Write_To_File(char *filename)
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
META_RESULT CBTINFO6601::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTINFO6601::Get_BTInfo(nvram_ef_btradio_mt6601_struct& bt_info)
{
    bt_info = m_sBtInfo;
}

//---------------------------------------------------------------------------
void CBTINFO6601::Set_BTInfo(nvram_ef_btradio_mt6601_struct bt_info)
{
    m_sBtInfo = bt_info;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char CBTINFO6601::Get_BT_CAP_ID(void)
{
    return m_ucCapID;
}

//---------------------------------------------------------------------------
void CBTINFO6601::Set_BT_CAP_ID(unsigned char cap_id)
{
    m_ucCapID = cap_id;
    m_sBtInfo.Radio[MT6601_BT_CAP_ID_IDX] = cap_id;
}

