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
 *   man_fdm.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   NVRAM access handling source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.10  $
 * $Modtime:   Oct 25 2005 12:18:28  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_fdm.cpp-arc  $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#pragma hdrstop

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include "form_main.h"

extern AnsiString chipVersion;
extern AnsiString softwareVersion;
extern TfrmMainSel *frmMainSel;

//===========================================================================
CNVRAMMan  *NVRAMMan = NULL;
static bool g_bIsRunning = false;
static CNVRAMMan* g_nvram_ptr;
//===========================================================================
static void REQ_Init_NVRAM_DB(void)
{
    g_nvram_ptr->REQ_Init_NVRAM_DB();
}
//---------------------------------------------------------------------------
static void REQ_ReadNVRAM(void)
{
    g_nvram_ptr->REQ_ReadNVRAM();
}
//---------------------------------------------------------------------------
static void  __stdcall CNF_ReadNVRAM( const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    g_nvram_ptr->CNF_ReadNVRAM( cnf, token, usrData);
}
//---------------------------------------------------------------------------
static void  REQ_WriteNVRAM(void)
{
    g_nvram_ptr->REQ_WriteNVRAM();
}
//---------------------------------------------------------------------------
static void  __stdcall CNF_WriteNVRAM(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    g_nvram_ptr->CNF_WriteNVRAM(cnf, token, usrData);
}
//---------------------------------------------------------------------------
static void REQ_ResetNVRAMData(void)
{
    g_nvram_ptr->REQ_ResetNVRAMData();
}
//---------------------------------------------------------------------------
static void  __stdcall CNF_ResetNVRAMData( const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    g_nvram_ptr->CNF_ResetNVRAMData(cnf, token, usrData);
}
//---------------------------------------------------------------------------
static void  __stdcall CNF_ResetNVRAM(const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    g_nvram_ptr->CNF_ResetNVRAM(cnf, token, usrData);
}
//------------------------------------------------------------------------------
static void REQ_NVRAMBackup()
{
    g_nvram_ptr->REQ_NVRAMBackup();
}
//------------------------------------------------------------------------------
static void REQ_NVRAMRestore()
{
    g_nvram_ptr->REQ_NVRAMRestore();
}
//---------------------------------------------------------------------------
static void REQ_Finish(void)
{
    g_nvram_ptr->REQ_Finish();
}

//---------------------------------------------------------------------------
static void REQ_TimeOut(void)
{
    g_nvram_ptr->REQ_TimeOut();
}

//===========================================================================
CNVRAMMan::CNVRAMMan(void)
{
    m_bIsInit = false;
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iResetStatus = true;
    m_psNVRAM_ReadReq  = NULL;
    m_psNVRAM_WriteReq = NULL;
    m_psNVRAM_ResetDataReq = NULL;
    m_psNVRAM_ResetReq = NULL;
    m_ReadFromNVRAMEvent = NULL;
    m_WriteToNVRAMEvent = NULL;
    m_b2ndIMEISupport = false;
    m_bCustVolExSupport = false;
    m_bVbiasSupport = false;
    m_cBuf = NULL;
    m_cLID = NULL;
    m_iBufSize = 0;
    m_iResetCountPtr = NULL;
    m_psNVRAM_ResetCnf = NULL;
    m_psNVRAM_WriteCnf = NULL;
    m_sNVRAM_OPID = NULL;
    m_ucIsResetOk = 0;
    m_ulNvramIdb = 0;
    m_usRID = 0;
}

//---------------------------------------------------------------------------
CNVRAMMan::~CNVRAMMan(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    if (m_psNVRAM_ReadReq)
    {
        delete m_psNVRAM_ReadReq;
        m_psNVRAM_ReadReq = NULL;
    }

    if (m_psNVRAM_WriteReq)
    {
        delete m_psNVRAM_WriteReq;
        m_psNVRAM_WriteReq = NULL;
    }

    if (m_psNVRAM_ResetReq)
    {
        delete m_psNVRAM_ResetReq;
        m_psNVRAM_ResetReq = NULL;
    }
}
//---------------------------------------------------------------------------
void CNVRAMMan::REQ_Finish(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void  CNVRAMMan::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sNVRAM_OPID);
    Confirm(METAAPP_STOP);
}
//---------------------------------------------------------------------------
void  CNVRAMMan::REQ_TimeOut( void )
{
    if (!g_bIsRunning)
    {
        return;
    }
    SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sNVRAM_OPID);
    Confirm( META_TIMEOUT );
}
//---------------------------------------------------------------------------
void  CNVRAMMan::Confirm(META_RESULT confirm_state)
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
void CNVRAMMan::REQ_Init(AnsiString as_file)
{
    g_nvram_ptr = this;
    g_bIsRunning = true;
    m_asNVRAM_DB_File = as_file;
    ActiveMan->SetActiveFunction(::REQ_Init_NVRAM_DB);
}
//---------------------------------------------------------------------------
void CNVRAMMan::Init(char* fdm_database_file)
{
    g_nvram_ptr = this;
    m_bIsInit = false;
    META_RESULT MetaResult = SP_META_NVRAM_Init_r( m_META_HANDLE_Obj.Get_MainHandle(), fdm_database_file, &m_ulNvramIdb );

    if ((META_SUCCESS == MetaResult)              ||
            (META_MAUI_DB_INCONSISTENT == MetaResult)
       )
    {
        if (META_MAUI_DB_INCONSISTENT == MetaResult)
        {
            m_eConfirmState = META_MAUI_DB_INCONSISTENT;
        }
        else
        {
            m_eConfirmState = META_SUCCESS;
        }
        m_bIsInit = true;
        m_asNVRAM_DB_File = fdm_database_file;
        SP_META_NVRAM_SWC_RetrieveChangeList_r(m_META_HANDLE_Obj.Get_MainHandle());
        m_vNVRAM_db_variant = TVariant((long) m_ulNvramIdb);
    }
    else
    {
        m_bIsInit = false;
        m_eConfirmState = META_FAILED;
    }
}
//----------------------------------------------------------------------------
void CNVRAMMan::REQ_Init_NVRAM_DB(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_NVRAM_Init_r(m_META_HANDLE_Obj.Get_MainHandle(), m_asNVRAM_DB_File.c_str(), &m_ulNvramIdb);

    if ((META_SUCCESS == MetaResult)              ||
            (META_MAUI_DB_INCONSISTENT == MetaResult)
       )
    {
        if (META_MAUI_DB_INCONSISTENT == MetaResult)
        {
            m_eConfirmState = META_MAUI_DB_INCONSISTENT;
        }
        else
        {
            m_eConfirmState = META_SUCCESS;
        }
        m_bIsInit = true;

        SP_META_NVRAM_SWC_RetrieveChangeList_r(m_META_HANDLE_Obj.Get_MainHandle());
        m_vNVRAM_db_variant = TVariant((long) m_ulNvramIdb);
    }
    else
    {
        m_bIsInit = false;
        m_eConfirmState = META_FAILED;
    }

    Confirm(m_eConfirmState);
}

//---------------------------------------------------------------------------
void CNVRAMMan::Get_BbTxCfgVer_FromNVDB(void)
{
    bool b_dccoarse_support;
    bool b_phaselsel_support;
    bool b_TxCalbias_support = false;
    META_RESULT MetaResult = SP_META_NVRAM_CheckFieldNameExist("NVRAM_EF_L1_TXIQ_LID", "BBTXParameters.bbtx_dccoarseI", &b_dccoarse_support);
    if (MetaResult != META_SUCCESS)
    {
        b_dccoarse_support = false;
    }

    MetaResult = SP_META_NVRAM_CheckFieldNameExist("NVRAM_EF_L1_TXIQ_LID", "BBTXParameters.bbtx_phsel", &b_phaselsel_support);
    if (MetaResult != META_SUCCESS)
    {
        b_phaselsel_support = false;
    }

    MetaResult = SP_META_NVRAM_CheckFieldNameExist("NVRAM_EF_L1_TXIQ_LID", "BBTXParameters.bbtx_calrcsel", &b_phaselsel_support);
    if (MetaResult != META_SUCCESS)
    {
        b_phaselsel_support = false;
    }
}
//===========================================================================
void  CNVRAMMan::REQ_ReadNVRAM_Start(const char *LID_para, unsigned short RID_para, int size, char *buf)
{
    g_nvram_ptr = this;
    g_bIsRunning = true;
    if( m_psNVRAM_ReadReq == NULL)
    {
        m_psNVRAM_ReadReq = new AP_FT_NVRAM_READ_REQ;
    }

    m_iBufSize = size; // set to m_sNVRAM_ReadCnf.len in function CNVRAMMan::REQ_ReadNVRAM()
    m_cBuf     = buf;
    m_psNVRAM_ReadReq->LID = LID_para;
    m_psNVRAM_ReadReq->RID = RID_para; // temp set to 0

    ActiveMan->SetActiveFunction( ::REQ_ReadNVRAM );
}
//-----------------------------------------------
void CNVRAMMan::REQ_ReadNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    DWORD wait_result;
    m_ReadFromNVRAMEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    ResetEvent(m_ReadFromNVRAMEvent);

    m_sNVRAM_ReadCnf.len = m_iBufSize;
    m_sNVRAM_ReadCnf.buf = m_cBuf;
    META_RESULT MetaResult = SP_META_NVRAM_Read_r(m_META_HANDLE_Obj.Get_MainHandle(),
                             m_psNVRAM_ReadReq,
                             &m_sNVRAM_ReadCnf,
                             ::CNF_ReadNVRAM,
                             &m_sNVRAM_OPID,
                             NULL);
    wait_result = WaitForSingleObject(m_ReadFromNVRAMEvent, 5000);
    if (WAIT_TIMEOUT == wait_result)
    {
        Confirm(META_TIMEOUT);
        return;
    }

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    ActiveMan->SetActiveFunction(::REQ_Finish);
}
//-----------------------------------------------
void __stdcall CNVRAMMan::CNF_ReadNVRAM(const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }
    m_sNVRAM_ReadCnf = *cnf;

    if (cnf->status != NVRAM_STATUS_SUCCESS || cnf->read_status != 1)
    {
        Confirm(META_FAILED);
        return;
    }
    SetEvent(m_ReadFromNVRAMEvent);
}
//===========================================================================
void  CNVRAMMan::REQ_WriteNVRAM_Start( const char *LID_para, unsigned short RID_para, int size, char *buf )
{
    g_nvram_ptr = this;
    g_bIsRunning = true;

    if(m_psNVRAM_WriteReq == NULL)
    {
        m_psNVRAM_WriteReq = new AP_FT_NVRAM_WRITE_REQ;
    }
    m_psNVRAM_WriteReq->LID = LID_para;
    m_psNVRAM_WriteReq->RID = RID_para;
    m_psNVRAM_WriteReq->len = size;
    m_psNVRAM_WriteReq->buf = buf;

    ActiveMan->SetActiveFunction(::REQ_WriteNVRAM);
}
//-----------------------------------------------
void CNVRAMMan::REQ_WriteNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    DWORD wait_result;
    m_WriteToNVRAMEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    ResetEvent(m_WriteToNVRAMEvent);
    META_RESULT MetaResult = SP_META_NVRAM_Write_r(m_META_HANDLE_Obj.Get_MainHandle(),
                             m_psNVRAM_WriteReq,
                             ::CNF_WriteNVRAM,
                             &m_sNVRAM_OPID,
                             NULL);
    wait_result = WaitForSingleObject(m_WriteToNVRAMEvent, 5000);
    if (WAIT_TIMEOUT == wait_result)
    {
        Confirm(META_TIMEOUT);
        return;
    }

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    ActiveMan->SetActiveFunction(::REQ_Finish);
}
//-----------------------------------------------
void __stdcall CNVRAMMan::CNF_WriteNVRAM( const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    m_psNVRAM_WriteCnf = cnf;

    if(cnf->status != NVRAM_STATUS_SUCCESS || cnf->write_status != 1)
    {
        Confirm(META_FAILED);
        return;
    }
    SetEvent( m_WriteToNVRAMEvent );
}
//===========================================================================
void  CNVRAMMan::REQ_ResetNVRAMData_Start( const char *LID_para )
{
    g_nvram_ptr = this;
    g_bIsRunning = true;

    if(m_psNVRAM_ResetDataReq == NULL)
    {
        m_psNVRAM_ResetDataReq = new AP_FT_NVRAM_RESET_REQ;
    }

    m_psNVRAM_ResetDataReq->category = NVRAM_RESET_CERTAIN;
    m_psNVRAM_ResetDataReq->LID      = LID_para;

//    TimerMan->CounterStart( 5000, ::REQ_TimeOut );
    ActiveMan->SetActiveFunction( ::REQ_ResetNVRAMData );
}
//-----------------------------------------------
void  CNVRAMMan::REQ_ResetNVRAMData( void )
{
    if(!g_bIsRunning)  return;

    META_RESULT MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                             m_psNVRAM_ResetDataReq,
                             ::CNF_ResetNVRAMData,
                             &m_sNVRAM_OPID,
                             NULL );

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
}
//-----------------------------------------------
void  __stdcall CNVRAMMan::CNF_ResetNVRAMData( const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    m_psNVRAM_ResetCnf = cnf;

    if(cnf->status != NVRAM_STATUS_SUCCESS || cnf->reset_status != 1)
    {
        Confirm(META_FAILED);
        return;
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}
//-----------------------------------------------
void  __stdcall CNVRAMMan::CNF_ResetNVRAM( const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    m_psNVRAM_ResetCnf = cnf;

    if(cnf->status != NVRAM_STATUS_SUCCESS || cnf->reset_status != 1)
    {
        Confirm(META_FAILED);
        return;
    }
    else
    {
        m_iResetStatus = true;
        *m_iResetCountPtr = *m_iResetCountPtr + 1;
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}
//===========================================================================
int  CNVRAMMan::REQ_ResetLayer1( int *ResetCountPtrPara )
{
    //   if(m_bIsInit==false)
    //   {  Confirm( STATE_FDM_INIT_FAIL );  return;  }
    m_iResetCountPtr =  ResetCountPtrPara;
    //  fdm_ptr = this;
    g_nvram_ptr = this;
    g_bIsRunning = true;
    META_RESULT  MetaResult;

    if(m_bIsInit == true && m_iResetStatus == true)
    {
        if(m_psNVRAM_ResetReq == NULL)
        {
            m_psNVRAM_ResetReq = new AP_FT_NVRAM_RESET_REQ;
        }
        switch(*m_iResetCountPtr)
        {
            //------------- agc path loss --------------------
        case 0:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_AGCPATHLOSS_LID";
            MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                                m_psNVRAM_ResetReq,
                                                ::CNF_ResetNVRAM,
                                                &m_sNVRAM_OPID,
                                                NULL         );
            if(MetaResult!=META_SUCCESS)
                //    {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;

            //------------- ramp table (gsm) --------------------
        case 1:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_RAMPTABLE_GSM900_LID";
            MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                                m_psNVRAM_ResetReq,
                                                ::CNF_ResetNVRAM,
                                                &m_sNVRAM_OPID,
                                                NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;

            //------------- ramp table (dcs) --------------------

        case 2:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_RAMPTABLE_DCS1800_LID";
            MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                                m_psNVRAM_ResetReq,
                                                ::CNF_ResetNVRAM,
                                                &m_sNVRAM_OPID,
                                                NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;
            //------------- ramp table (pcs) --------------------
        case 3:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_RAMPTABLE_PCS1900_LID";
            MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                                m_psNVRAM_ResetReq,
                                                ::CNF_ResetNVRAM,
                                                &m_sNVRAM_OPID,
                                                NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;
            //------------- afc data -----------------------------
        case 4:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_AFCDATA_LID";
            MetaResult = SP_META_NVRAM_Reset_r(  m_META_HANDLE_Obj.Get_MainHandle(),
                                                 m_psNVRAM_ResetReq,
                                                 ::CNF_ResetNVRAM,
                                                 &m_sNVRAM_OPID,
                                                 NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;
            //------------- L1Sp data -----------------------------
        case 5:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_L1SPFC_LID";
            MetaResult = SP_META_NVRAM_Reset_r(m_META_HANDLE_Obj.Get_MainHandle(),
                                               m_psNVRAM_ResetReq,
                                               ::CNF_ResetNVRAM,
                                               &m_sNVRAM_OPID,
                                               NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;
            //------------- L1TXIQ data -----------------------------
        case 6:
            m_psNVRAM_ResetReq->category = NVRAM_RESET_CERTAIN;
            m_psNVRAM_ResetReq->LID = "NVRAM_EF_L1_TXIQ_LID";
            MetaResult = SP_META_NVRAM_Reset_r(m_META_HANDLE_Obj.Get_MainHandle(),
                                               m_psNVRAM_ResetReq,
                                               ::CNF_ResetNVRAM,
                                               &m_sNVRAM_OPID,
                                               NULL         );

            if(MetaResult!=META_SUCCESS)
                //   {  Confirm( STATE_FDM_FAIL );  return;  }
            {
                Confirm( META_FAILED );
                return false;
            }
            break;
        } // switch
        m_iResetStatus = false;
        return true; // continure to reset L1 calibarion parameter
    }//if
    else if(m_bIsInit == false)
    {
        Application->MessageBox( " Please initialize NVRAM database first" , "Warning", MB_OK );
        return false; // stop to reset L1 calibarion parameter
    }
    else
    {
        return false;// stop to reset L1 calibarion parameter
    }
}
//------------------------------------------------------------------------------
void  CNVRAMMan::REQ_NVRAMBackup_Start(const AnsiString& file1,const AnsiString& file2)
{
    g_nvram_ptr = this;
    g_bIsRunning = true;
    m_file1 = file1;
    m_file2 = file2;
    ActiveMan->SetActiveFunction( ::REQ_NVRAMBackup );
}
//------------------------------------------------------------------------------
void CNVRAMMan::REQ_NVRAMBackup(void)
{
    if(!g_bIsRunning)  return;

    META_RESULT MetaResult =  SP_META_Nvram_Backup_r(m_META_HANDLE_Obj.Get_MainHandle(),
                              frmMainSel->m_nNVRAMBackupRestoreTimeout,
                              m_file1.c_str(),
                              m_file2.c_str());

    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
    }
    else
    {
        Confirm(META_SUCCESS);
    }
}
//------------------------------------------------------------------------------
void  CNVRAMMan::REQ_NVRAMRestore_Start(const AnsiString& file1,const AnsiString& file2)
{
    g_nvram_ptr = this;
    g_bIsRunning = true;
    m_file1 = file1;
    m_file2 = file2;
    ActiveMan->SetActiveFunction( ::REQ_NVRAMRestore );
}
//------------------------------------------------------------------------------
void CNVRAMMan::REQ_NVRAMRestore(void)
{
    if(!g_bIsRunning)  return;

    if(softwareVersion == "DUMA")
    {
        META_RESULT MetaResult =  SP_META_Nvram_Restore_r(m_META_HANDLE_Obj.Get_MainHandle(),
                                  frmMainSel->m_nNVRAMBackupRestoreTimeout,
                                  m_file1.c_str(),m_file2.c_str());
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
        }
        else
        {
            MetaResult = SP_META_Nvram2Bin_r(m_META_HANDLE_Obj.Get_MainHandle(), 6000);
            if(MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
            }
            else
            {
                Confirm(META_SUCCESS);
            }
        }
    }
    else
    {
        META_RESULT MetaResult =  SP_META_Nvram_Restore_r(m_META_HANDLE_Obj.Get_MainHandle(),
                                  frmMainSel->m_nNVRAMBackupRestoreTimeout,
                                  m_file1.c_str(),m_file2.c_str());
        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
        }
        else
        {
            Confirm(META_SUCCESS);
        }
    }
}
//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
META_RESULT  CNVRAMMan::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CNVRAMMan::Get_IsInit(void)
{
    return m_bIsInit;
}
//---------------------------------------------------------------------------
void CNVRAMMan::Set_IsInit(bool is_init)
{
    m_bIsInit = is_init;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString CNVRAMMan::Get_NVRAM_DB_File(void)
{
    return  m_asNVRAM_DB_File;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Variant CNVRAMMan::Get_NvramDbVariant(void)
{
    return m_vNVRAM_db_variant;
}
//---------------------------------------------------------------------------
void CNVRAMMan::Set_NvramDbVariant(Variant variant)
{
    m_vNVRAM_db_variant = variant;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CNVRAMMan::Get_VbiasSupport(void)
{
    return m_bVbiasSupport;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CNVRAMMan::Get_CustVolExSupport(void)
{
    return m_bCustVolExSupport;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CNVRAMMan::Set_FormHandle(S_FORM_HANDLE_T handle)
{
    m_sHandle = handle;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CNVRAMMan::Get_2ndIMEISupport(void)
{
    return m_b2ndIMEISupport;
}

bool CNVRAMMan::QueryAPDBPath(void)
{
    META_RESULT mr = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, "SP_META_Query_APDBPath_r");
    if (mr != META_SUCCESS)
    {
        return false;
    }
    QUERY_APDBPATH_REQ Req;
    QUERY_APDBPATH_CNF Cnf;
    memset(&Req, 0, sizeof(Req));
    memset(&Cnf, 0, sizeof(Cnf));
    mr = SP_META_Query_APDBPath_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000, &Req, &Cnf);
    if(mr != META_SUCCESS)
    {
        return false;
    }
    memset(m_TargetSideAPDBFolder, 0, sizeof(m_TargetSideAPDBFolder));
    memcpy(m_TargetSideAPDBFolder, Cnf.apdb_path, strlen(Cnf.apdb_path));
    return true;
}

bool CNVRAMMan::CopyAPDBToPC(void)
{
    FILE_OPERATION_PARSE_REQ parseReq;
    FILE_OPERATION_PARSE_CNF parseCnf;
    memset(&parseReq, 0, sizeof(parseReq));
    memset(&parseCnf, 0, sizeof(parseCnf));
    memcpy(parseReq.path_name, m_TargetSideAPDBFolder, strlen(m_TargetSideAPDBFolder));
    memcpy(parseReq.filename_substr, "APDB_", strlen("APDB_"));
    META_RESULT mr = META_FAILED;
    mr = SP_META_File_Operation_Parse_r(m_META_HANDLE_Obj.Get_MainHandle(), 20000, &parseReq, &parseCnf);
    if (mr != META_SUCCESS)
    {
        return false;
    }
    unsigned int fileCount = parseCnf.file_count;
    FILE_OPERATION_GETFILEINFO_REQ getFileInfoReq;
    FILE_OPERATION_GETFILEINFO_CNF getFileInfoCnf;
    for (unsigned int i = 0; i< fileCount; i++)
    {
        memset(&getFileInfoReq, 0, sizeof(getFileInfoReq));
        memset(&getFileInfoCnf, 0, sizeof(getFileInfoCnf));
        getFileInfoReq.index = i;
        mr = SP_META_File_Operation_GetFileInfo_r(m_META_HANDLE_Obj.Get_MainHandle(), 8000, &getFileInfoReq, &getFileInfoCnf);
        if (mr != META_SUCCESS)
        {
            return false;
        }
        if (getFileInfoCnf.file_info.file_type == FT_FILE_TYPE_FILE)
        {
           AnsiString asFileName = AnsiString((char*)getFileInfoCnf.file_info.file_name);
           if ( (asFileName.Pos("_ENUM") == 0) && (asFileName.Pos(".check") == 0))
           {
               //This is the right AP NVRAM database we need.
               AnsiString asPath;
               getPathFromStr(Application->ExeName, asPath);
               AnsiString asDestFileNamePath = asPath + asFileName;
               AnsiString asSrcFileFolder = AnsiString((char*)m_TargetSideAPDBFolder);
               AnsiString asSrcFilePath = asSrcFileFolder + "/" + asFileName;
               LOG("asDestFileNamePath:%s, asSrcFilePath:%s", asDestFileNamePath.c_str(),asSrcFilePath.c_str());
               mr = SP_META_File_Operation_ReceiveFile_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, asSrcFilePath.c_str(),
                   asDestFileNamePath.c_str());
               if (mr == META_SUCCESS)
               {
                   memset(m_PCSideAPDBPath, 0, sizeof(m_PCSideAPDBPath));
                   memcpy(m_PCSideAPDBPath, asDestFileNamePath.c_str(), asDestFileNamePath.Length());
                   return true;
               }
           }
        }
    }
    return false;
}



unsigned char* CNVRAMMan::GetPCSideAPDBPath()
{
    return m_PCSideAPDBPath;
}
