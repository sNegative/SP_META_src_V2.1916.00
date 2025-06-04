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
 *   form_FM.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  FM radio form source
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

// FM
#ifndef  _FM_COMMON_H_
#include "fm_common.h"
#endif

#ifndef _FORM_FM_H_
#include "form_FM.h"
#endif

// misc
#ifndef  _MISC_FM_H_
#include "misc_fm.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#ifndef  _FILE_UTILS_H_
#include "file_utils.h"
#endif

#ifndef  _FM_RADIO_H_
#include "fm_radio.h"
#endif

#include <assert.h>


//---------------------------------------------------------------------------
typedef enum
{
    FM_MODE_IDX_MONO = 0,
    FM_MODE_IDX_STEREO
} E_FM_MODE_IDX;

bool bFirstDisplayTime[3] = {true, true, true};

//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
TfrmFM *frmFM;

extern TfrmMainSel *frmMainSel;
extern bool g_bHideEnable;
extern bool g_DisconnectFlag;
extern bool g_CloseFlag;
extern HANDLE hForm_MainForm;
extern bool ConnectTargetok; //add 20120514

bool g_isPowerOnPressed = false;

//===========================================================================
static void CNF_FM_PowerOn(void)
{
    frmFM->CNF_FM_PowerOn();
}

static void CNF_FM_TxPowerOn(void)
{
    frmFM->CNF_FM_TxPowerOn();
}

static void CNF_FM_TxPowerOff(void)
{
    frmFM->CNF_FM_TxPowerOff();
}

//---------------------------------------------------------------------------
static void CNF_FM_PowerReset(void)
{
    frmFM->CNF_FM_PowerReset();
}

//---------------------------------------------------------------------------
static void CNF_FM_PowerOff(void)
{
    frmFM->CNF_FM_PowerOff();
}

//---------------------------------------------------------------------------
static void CNF_FM_SetFreq(void)
{
    frmFM->CNF_FM_SetFreq();
}


//---------------------------------------------------------------------------
static void CNF_FM_SearchNextStation(void)
{
    frmFM->CNF_FM_SearchNextStation();
}

//---------------------------------------------------------------------------
static void CNF_FM_SearchPreStation(void)
{
    frmFM->CNF_FM_SearchPreStation();
}

//---------------------------------------------------------------------------
static void CNF_FM_SetAudio(void)
{
    frmFM->CNF_FM_SetAudio();
}

//---------------------------------------------------------------------------
static void CNF_FM_ReadData(void)
{
    frmFM->CNF_FM_ReadData();
}

//---------------------------------------------------------------------------
static void CNF_FM_WriteData(void)
{
    frmFM->CNF_FM_WriteData();
}

//---------------------------------------------------------------------------
static void CNF_FM_GetStatus(void)
{
    frmFM->CNF_FM_GetStatus();
}

// for MT6616 new API
//---------------------------------------------------------------------------
static void CNF_FM_ResetBlockCounter(void)
{
    frmFM->CNF_FM_ResetBlockCounter();
}

//---------------------------------------------------------------------------
static void CNF_FM_ResetGroupCounter(void)
{
    frmFM->CNF_FM_ResetGroupCounter();
}

//---------------------------------------------------------------------------
static void CNF_FM_RDSOn(void)
{
    frmFM->CNF_FM_RDSOn();
}

//---------------------------------------------------------------------------
static void CNF_FM_RDSOff(void)
{
    frmFM->CNF_FM_RDSOff();
}

//---------------------------------------------------------------------------
static void CNF_FM_AutoScan(void)
{
    frmFM->CNF_FM_AutoScan();
}

static void CNF_ParameterSetting(void)
{
    frmFM->ParameterSettingDone();
}

static void CNF_StatusUpdate(void)
{
    frmFM->CNF_StatusUpdate();
}

static void CNF_StatusUpdateMT6620(void)
{
    frmFM->CNF_StatusUpdateMT6620();
}

static void CNF_ParameterSettingMT6620(void)
{
    frmFM->CNF_ParameterSettingMT6620();
}

static void CNF_CounterUpdate(void)
{
    frmFM->CNF_CounterUpdate();
}

//---------------------------------------------------------------------------
static void CNF_FM_SeekStation(void)
{
    frmFM->CNF_FM_SeekStation();
}

static void CNF_FM_Set_Volume(void)
{
    frmFM->CNF_FM_Set_Volume();
}

static void CNF_FM_AudioTest(void)
{
    frmFM->CNF_FM_AudioTest();
}
//===========================================================================
__fastcall TfrmFM::TfrmFM(TComponent* Owner)
    : TForm(Owner)
{
    Init();
    WindowProc = SubClassWndProc;
    left="\0";
    right="\0";
}

//---------------------------------------------------------------------------
void TfrmFM::Init(void)
{
    m_bInit = true;
    version = 0;
    m_sFMStepMode.m_i4Step = FM_STEP_MODE_100KHZ;
    QueryFMInfo();
    //Old FM UI
    m_FMOldUILocker.AddControl(m_btnReset);
    m_FMOldUILocker.AddControl(m_btnSetFreq);
    m_FMOldUILocker.AddControl(m_btnSearchNextStation);
    m_FMOldUILocker.AddControl(m_btnSearchPreStation);
    m_FMOldUILocker.AddControl(m_btnSetAudio);
    m_FMOldUILocker.AddControl(m_btnRead);
    m_FMOldUILocker.AddControl(m_btnWrite);
    m_FMOldUILocker.AddControl(m_btnGet);
    //FM Receiver Main Window
    m_FMReceiverLocker.AddControl(m_tbFMReceiver_Frequency);
    m_FMReceiverLocker.AddControl(m_btnFMRXSetFrequency);
    m_FMReceiverLocker.AddControl(m_btnFMRXTune_Increase);
    m_FMReceiverLocker.AddControl(m_btnFMRXTune_Decrease);
    m_FMReceiverLocker.AddControl(m_edtFMReceiver_CurrentFrequency);
    m_FMReceiverLocker.AddControl(m_btnFMRXSeekLeft);
    m_FMReceiverLocker.AddControl(m_btnFMRXSeekRight);
    m_FMReceiverLocker.AddControl(m_cbFMReceiver_ChannelList);
    m_FMReceiverLocker.AddControl(m_btnFMRXAutoScan);
    m_FMReceiverLocker.AddControl(m_edtFMReceiver_ChannelSelect);
    m_FMReceiverLocker.AddControl(m_btnFMRXGoChannel);

    m_FMReceiverLocker.AddControl(btnAudioTest);

    //RDS Receive Data Page
    m_FMRDSLocker.AddControl(m_btnFMRDS_BlockCounterReset);
    m_FMRDSLocker.AddControl(m_btnFMRDS_GroupCounterReset);
    //FM Transmitter Main Window
    m_FMTxLocker.AddControl(edtFMTxRFFreq);
    m_FMTxLocker.AddControl(edtFMTxRFlevel);
    m_FMTxLocker.AddControl(edtFMTxAudioDeviation);
    m_FMTxLocker.AddControl(cbFMTxPilotOn);
    m_FMTxLocker.AddControl(edtFMTxPilotDeviation);
    m_FMTxLocker.AddControl(cbFMTxRDSOn);
    m_FMTxLocker.AddControl(edtFMTxRDSDeviation);
    m_FMTxLocker.AddControl(edtFMTxPilotFreq);
    m_FMTxLocker.AddControl(cbFMTxModulationOn);
    m_FMTxLocker.AddControl(cbFMTxStereoMonoEnable);
    m_FMTxLocker.AddControl(cbFMTxPreEmphasis);
    m_FMTxLocker.AddControl(chkFMTxDRCOn);
    m_FMTxLocker.AddControl(chkFMTxEL);
    m_FMTxLocker.AddControl(cbI2S);
    m_FMTxLocker.AddControl(cbAnalog);
    m_FMTxLocker.AddControl(cboFrequency);
    m_FMTxLocker.AddControl(btnFMTxPowerOnOff);
    m_FMTxLocker.AddControl(readVaractor);
    m_FMTxLocker.AddControl(btnFMTxADRCSET);
    m_FMTxLocker.AddControl(btnFMTxLimiter);
    m_FMTxLocker.AddControl(btnFMSetType);
    m_FMTxLocker.AddControl(stFMTxVaractorValue);
    m_FMTxLocker.AddControl(stFMTxTotalDeviation);
    m_FMTxLocker.AddControl(udFMTxRFFreq);
    m_FMTxLocker.AddControl(udFMTxRFlevel);
    m_FMTxLocker.AddControl(udFMTxAudioDeviation);
    m_FMTxLocker.AddControl(udFMTxPilotDeviation);
    m_FMTxLocker.AddControl(udFMTxRDSDeviation);
    m_FMTxLocker.AddControl(udFMTxPilotFreq);

}




//===========================================================================
void __fastcall TfrmFM::FormActivate(TObject *Sender)
{
    // for MT6616
    if (m_bInit)
    {
        m_sFMChipId = Get_FMChipID();
        m_sFMStepMode = Get_FMStepMode();
        if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
        {
            m_tbFMReceiver_Frequency->Max = FM_FREQUENCY_TRACKBAR_MAX_50KHZ;
            m_tbFMReceiver_Frequency->Min = FM_FREQUENCY_TRACKBAR_MIN_50KHZ;
            m_tbFMReceiver_Frequency->Frequency = 1;
            m_tbFMReceiver_Frequency->PageSize = 2;
            m_tbFMReceiver_Frequency->LineSize = 20;
            m_tbFMReceiver_Frequency->Position = 907*2;


        }
        else
        {
            m_tbFMReceiver_Frequency->Max = FM_FREQUENCY_TRACKBAR_MAX_100KHZ;
            m_tbFMReceiver_Frequency->Min = FM_FREQUENCY_TRACKBAR_MIN_100KHZ;
            m_tbFMReceiver_Frequency->Frequency = 1;
            m_tbFMReceiver_Frequency->PageSize = 2;
            m_tbFMReceiver_Frequency->LineSize = 10;
            m_tbFMReceiver_Frequency->Position = 907;
        }
        // hide/display UI component if old hardware
        if(m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189AN ||
                m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189BN_CN ||
                m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188A ||
                m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188C ||
                m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188D)
        {
            // step1: hide RDS Receiver Data and FM Transmitter Main Window (old sw load?)
            // m_tsFMReceiver->Visible = false;
            // m_tsFMReceiver->TabVisible = false;
            // m_tsFMRDS->Visible = false;
            // m_tsFMRDS->TabVisible = false;
            m_pgcFMRadio->ActivePage = m_tsOldFMUI;
        }
        // hide/display UI component if new sw load
        else if(m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6616)
        {
            m_lblFMReceiver_Status_IFCounter->Visible = false;
            m_stFMReceiver_Status_IFCounter->Visible = false;
            m_lblFMReceiver_Status_HLSide->Visible = false;
            m_stFMReceiver_Status_HLSide->Visible = false;
            m_lblFMReceiver_Setting_StereoBlendLevel->Visible = false;
            m_cbFMReceiver_Setting_StereoBlendLevel->Visible = false;
            // hide legacy UI
            m_tsOldFMUI->Visible = false;
            m_tsOldFMUI->TabVisible = false;
            m_pgcFMRadio->ActivePage = m_tsFMReceiver;
        }
        else if(m_sFMChipId.m_ucChipId == FM_CHIP_ID_AR1000)
        {
            m_btnFMRXRDSOn->Visible = false;
            m_btnFMRXRDSOff->Visible = false;
            m_btnFMRXAutoScan->Visible = false;
        }
        /*else if(m_sFMChipId.m_ucChipId == FM_CHIP_ID_AR1000)
        {
            m_tsFMReceiver->Visible = true;
            m_tsFMReceiver->TabVisible = true;
            m_tsFMRDS->Visible = true;
            m_tsFMRDS->TabVisible = true;
        }*/
//rongguo 2010-08-25
        if(m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6626 ||
        m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6628 ||
        m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6627 ||
        m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6580)
        {
            tsFMTx->TabVisible = false;
            tsRDSTx->TabVisible = false;
            m_pgcFMRadio->ActivePage = m_tsFMReceiver;
        }
        else
        {
            tsFMTx->TabVisible = true;
            tsRDSTx->TabVisible = true;
        }

        if (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6627 || m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6580)
        {
            Label60->Visible = false;
            stCapArray->Visible = false;
            Label55->Visible = false;
            stCapRegValue->Visible = false;
        }
        else
        {
            Label60->Visible = true;
            stCapArray->Visible = true;
            Label55->Visible = true;
            stCapRegValue->Visible = true;
        }

        if( ConnectTargetok )
        {
            m_bInit = false;
        }
        //CurrentPageLock();
        //m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerOn;
        //m_cFM_RADIO_Obj.REQ_FM_Power_On_Start();
    }
    ApplyHideProperty();
}

//===========================================================================
/*void TfrmFM::CurrentPageReset(void)
{   /*
    // old UI
    m_btnReset->Enabled = true;
    m_btnSetFreq->Enabled = true;
    m_btnSearchNextStation->Enabled = true;
    m_btnSearchPreStation->Enabled = true;
    m_btnSetAudio->Enabled = true;
    m_btnRead->Enabled = true;
    m_btnWrite->Enabled = true;
    m_btnGet->Enabled = true;
    // new UI
    m_btnFMRXPowerOn->Enabled = true;
    m_btnFMRXPowerOff->Enabled = true;
    m_btnFMRXSetFrequency->Enabled = true;
    m_udFMReceiver_Tune->Enabled = true;
    m_btnFMRXSeekLeft->Enabled = true;
    m_btnFMRXSeekRight->Enabled = true;
    m_btnFMRXRegisterRead->Enabled = true;
    m_btnFMRXRegisterWrite->Enabled = true;
    m_btnFMRXAutoScan->Enabled = true;
    if(m_cbFMReceiver_ChannelList->Items->Count > 0)
    {
        m_btnFMRXGoChannel->Enabled = true;
    }
    if(m_btnFMRXPowerOn->Tag == 1)
    {
        m_btnFMRXRDSOn->Enabled = true;
        m_btnFMRDS_RDSOn->Enabled = true;
    }
    if(m_btnFMRXRDSOn->Tag == 1)
    {
        m_btnFMRXRDSOff->Enabled = true;
        m_btnFMRDS_RDSOff->Enabled = true;
    }
    m_btnFMRXStatusUpdate->Enabled = true;
    m_btnFMRXSet->Enabled = true;
    m_btnFMRDS_BlockCounterReset->Enabled = true;
    m_btnFMRDS_GroupCounterReset->Enabled = true;
    m_btnFMRXSetVolume->Enabled = true;       */
/*   gbFMTxRFandModu->Enabled = true;
   gbFMTxAudioControl->Enabled = true;

//rongguo 2011-09-07
    if(m_tsFMReceiver == m_pgcFMRadio->ActivePage)
    {
        m_tsFMReceiver->Enabled = true;
    }
    else if(tsFMTx == m_pgcFMRadio->ActivePage)
    {
        edtFMTxRFFreq->Enabled = true;
        edtFMTxRFlevel->Enabled = true;
        edtFMTxAudioDeviation->Enabled = true;

        cbFMTxPilotOn->Enabled = true;
        edtFMTxPilotDeviation->Enabled = true;

        cbFMTxRDSOn->Enabled = true;
        edtFMTxRDSDeviation->Enabled = true;

        edtFMTxPilotFreq->Enabled = true;

        cbFMTxModulationOn->Enabled = true;
        cbFMTxStereoMonoEnable->Enabled = true;
        cbFMTxPreEmphasis->Enabled = true;
        chkFMTxDRCOn->Enabled = true;
        chkFMTxEL->Enabled = true;
        cbI2S->Enabled = true;
        cbAnalog->Enabled = true;
        cboFrequency->Enabled = true;

        btnFMTxPowerOnOff->Enabled = true;
        readVaractor->Enabled = true;
        btnFMTxADRCSET->Enabled = true;
        btnFMTxLimiter->Enabled = true;
        btnFMSetType->Enabled = true;
 //rongguo 2011-07-22
        stFMTxVaractorValue->Enabled = true;
        stFMTxTotalDeviation->Enabled = true;
        udFMTxRFFreq->Enabled = true;
        udFMTxRFlevel->Enabled = true;
        udFMTxAudioDeviation->Enabled = true;
        udFMTxPilotDeviation->Enabled = true;
        udFMTxRDSDeviation->Enabled = true;
        udFMTxPilotFreq->Enabled = true;
    }
}

//---------------------------------------------------------------------------
void TfrmFM::CurrentPageLock(void)
{
    // old UI
    /*
    m_btnReset->Enabled = false;
    m_btnSetFreq->Enabled = false;
    m_btnSearchNextStation->Enabled = false;
    m_btnSearchPreStation->Enabled = false;
    m_btnSetAudio->Enabled = false;
    m_btnRead->Enabled = false;
    m_btnWrite->Enabled = false;
    m_btnGet->Enabled = false;
    // new UI
    m_btnFMRXPowerOn->Enabled = false;
    m_btnFMRXPowerOff->Enabled = false;
    m_btnFMRXSetFrequency->Enabled = false;
    m_udFMReceiver_Tune->Enabled = false;
    m_btnFMRXSeekLeft->Enabled = false;
    m_btnFMRXSeekRight->Enabled = false;
    m_btnFMRXRegisterRead->Enabled = false;
    m_btnFMRXRegisterWrite->Enabled = false;
    m_btnFMRXAutoScan->Enabled = false;
    m_btnFMRXGoChannel->Enabled = false;
    m_btnFMRXRDSOn->Enabled = false;
    m_btnFMRXRDSOff->Enabled = false;
    m_btnFMRXStatusUpdate->Enabled = false;
    m_btnFMRXSet->Enabled = false;
    m_btnFMRDS_RDSOn->Enabled = false;
    m_btnFMRDS_RDSOff->Enabled = false;
    m_btnFMRDS_BlockCounterReset->Enabled = false;
    m_btnFMRDS_GroupCounterReset->Enabled = false;
    m_btnFMRXSetVolume->Enabled = false;
    */
//rongguo 2011-09-07
/*    if(m_tsFMReceiver == m_pgcFMRadio->ActivePage)
    {
        m_tsFMReceiver->Enabled = true;
    }
 //rongguo 2011-07-22
     else if(tsFMTx == m_pgcFMRadio->ActivePage)
     {
        edtFMTxRFFreq->Enabled = false;
        edtFMTxRFlevel->Enabled = false;
        edtFMTxAudioDeviation->Enabled = false;

        cbFMTxPilotOn->Enabled = false;
        edtFMTxPilotDeviation->Enabled = false;

        cbFMTxRDSOn->Enabled = false;
        edtFMTxRDSDeviation->Enabled = false;

        edtFMTxPilotFreq->Enabled = false;

        cbFMTxModulationOn->Enabled = false;
        cbFMTxStereoMonoEnable->Enabled = false;
        cbFMTxPreEmphasis->Enabled = false;
        chkFMTxDRCOn->Enabled = false;
        chkFMTxEL->Enabled = false;
        cbI2S->Enabled = false;
        cbAnalog->Enabled = false;
        cboFrequency->Enabled = false;

        btnFMTxPowerOnOff->Enabled = false;
        readVaractor->Enabled = false;
        btnFMTxADRCSET->Enabled = false;
        btnFMTxLimiter->Enabled = false;
        btnFMSetType->Enabled = false;
 //rongguo 2011-07-22
        stFMTxVaractorValue->Enabled = false;
        stFMTxTotalDeviation->Enabled = false;
        udFMTxRFFreq->Enabled = false;
        udFMTxRFlevel->Enabled = false;
        udFMTxAudioDeviation->Enabled = false;
        udFMTxPilotDeviation->Enabled = false;
        udFMTxRDSDeviation->Enabled = false;
        udFMTxPilotFreq->Enabled = false;
     }
} */

FM_CHIP_ID_CNF_T TfrmFM::Get_FMChipID()
{
    return m_FMChipId;
}
FM_STEP_MODE_CNF_T TfrmFM::Get_FMStepMode()
{
    return m_FMStepMode;
}
//---------------------------------------------------------------------------
void TfrmFM::ReDrawRDSFields(RdsEvent e)
{
    // FIXME
    switch(e)
    {
    case RDS_EVENT_FLAGS:
    {
//rongguo 2011-07-04
        if(true == bFirstDisplayTime[0])
        {
            S_TIME *start_time = m_cFM_RDS_Obj.Get_FM_RDS_StartTime();
            S_TIME *sync_time = m_cFM_RDS_Obj.Get_FM_RDS_EventSyncTime();
            int duration = DifferenceMiniSec(start_time, sync_time);
            m_stRDSData_RDS_RDSSYNC->Caption = IntToStr(duration);
            bFirstDisplayTime[0] = false;
        }
//rongguo 2011-07-04
//            RDSFlag_Struct *prdsflag_data = (RDSFlag_Struct *)m_sRDSInfo.m_buffer;
        RDSFlag_Struct *prdsflag_data = (RDSFlag_Struct *)m_sRDSStatus.m_buffer;
//            char offset;

//            if(prdsflag_data->TA != '\0')
//            {
//rongguo 2011-06-22
//                offset =  prdsflag_data->TA;
        if(m_sRDSStatus.m_eFlag & RDS_FLAG_IS_TA)
        {
//                       right ="," + IntToStr(m_sRDSInfo.m_buffer[offset]);
//                right ="," + IntToStr(prdsflag_data->TA);
            m_stRDSData_RDS_TA->Caption = IntToStr(prdsflag_data->TA);
        }
//            }
//            if(prdsflag_data->TP!='\0')
//            {
//rongguo 2011-06-22
//                offset =  prdsflag_data->TP;
        if(m_sRDSStatus.m_eFlag & RDS_FLAG_IS_TP)
        {
//                        left = IntToStr(m_sRDSInfo.m_buffer[offset]);
//                left = IntToStr(prdsflag_data->TP);
            m_stRDSData_RDS_TP->Caption = IntToStr(prdsflag_data->TP);
        }
//            }
//            m_stRDSData_RDS_TA->Caption = left + right;
    }
    break;
    // PS
    case RDS_EVENT_PROGRAMNAME:
        /*
        RDSData.PS[0] = 0x52; //R
        RDSData.PS[1] = 0X61; //a
        RDSData.PS[2] = 0x64; //d
        RDSData.PS[3] = 0x69; //i
        RDSData.PS[4] = 0x6f; //o
        RDSData.PS[5] = 0x32; //space
        RDSData.PS[6] = 0x63; //c
        RDSData.PS[7] = 0x69; //i
        RDSData.PS[8] = 0xFF;
        */
    {
        //rongguo 2011-07-04
        if(true == bFirstDisplayTime[1])
        {
            S_TIME *start_time = m_cFM_RDS_Obj.Get_FM_RDS_StartTime();
            S_TIME *sync_time = m_cFM_RDS_Obj.Get_FM_RDS_EventSyncTime();
            int duration = DifferenceMiniSec(start_time, sync_time);
            m_stRDSData_RDS_PSDISPLAY->Caption = IntToStr(duration);
            bFirstDisplayTime[1] = false;
        }
        char buf[9];
        for(int i=0; i<8; i++)
        {
            buf[i] = (m_sRDSInfo.m_buffer[i]);
        }
        buf[8] = 0;
        m_stRDSData_RDS_PS->Caption = buf;
        m_stFMReceiver_RDSData_PS->Caption = buf;

    }
    break;
    // PTY
    case RDS_EVENT_PTY_CODE:
        //RDSData.PTY = 0x16; //Public
        m_stRDSData_RDS_PTY->Caption = IntToStr(m_sRDSInfo.m_buffer[0]);
        break;
        // PI
    case RDS_EVENT_PI_CODE:
    {
//rongguo 2011-06-22
//            m_stRDSData_RDS_PI->Caption = IntToHex((int)m_sRDSInfo.m_buffer[1],2) + IntToHex((int)m_sRDSInfo.m_buffer[2],2);
        m_stRDSData_RDS_PI->Caption = IntToHex(*( unsigned short *)m_sRDSInfo.m_buffer, 2);
    }
    break;
    // RT
    case RDS_EVENT_LAST_RADIOTEXT:
    {
//rongguo 2011-07-04
        if(true == bFirstDisplayTime[2])
        {
            S_TIME *start_time = m_cFM_RDS_Obj.Get_FM_RDS_StartTime();
            S_TIME *sync_time = m_cFM_RDS_Obj.Get_FM_RDS_EventSyncTime();
            int duration = DifferenceMiniSec(start_time, sync_time);
            m_stRDSData_RDS_RTDISPLAY->Caption = IntToStr(duration);
            bFirstDisplayTime[2] = false;
        }

        char buf[65];
        for(int i=0; i<64; i++)
        {
            buf[i] = (m_sRDSInfo.m_buffer[i]);
        }
        // 20100210: device driver already converted to char array
        buf[64] = 0;
        m_stRDSData_RDS_RT->Caption = buf;
        m_stFMReceiver_RDSData_RT->Caption = buf;

    }
    break;
    // CT
    case RDS_EVENT_UTCDATETIME:
        /*
        RDSData.CT.Month = 7;
        RDSData.CT.Day = 22;
        RDSData.CT.Year = 109;
        RDSData.CT.Hour = 3;
        RDSData.CT.Minute = 12;
        *(buffer+5) = pstRDSData->CT.Local_Time_offset_signbit;
        *(buffer+6) = pstRDSData->CT.Local_Time_offset_half_hour
        */
    {
        // decode m buffer to time format AnsiString
        AnsiString str;
        //str.sprintf("%4d/%2d/%2d %02d:%02d TimeZone(%c%02d:%02d)", /*1900+*/m_sRDSInfo.m_buffer[2],
        //m_sRDSInfo.m_buffer[0], m_sRDSInfo.m_buffer[1], m_sRDSInfo.m_buffer[3] + (((m_sRDSInfo.m_buffer[5] == 0) ? 1 : -1) * m_sRDSInfo.m_buffer[6]/2) /* hour */,
        // m_sRDSInfo.m_buffer[4] + (((m_sRDSInfo.m_buffer[5] == 0) ? 1 : -1) * (m_sRDSInfo.m_buffer[6]%2)*30)/* minutes */, (m_sRDSInfo.m_buffer[5] == 0) ? '+' : '-', m_sRDSInfo.m_buffer[6]/2, (m_sRDSInfo.m_buffer[6]%2)*30);
        // m_stRDSData_RDS_CT->Caption = str;

        CT_Struct *prdsCT_data = (CT_Struct *)m_sRDSInfo.m_buffer;
        str.sprintf("%2d/%2d/%4d %02d:%02d",prdsCT_data->Month,prdsCT_data->Day,prdsCT_data->Year,
                    prdsCT_data->Hour, prdsCT_data->Minute);
        m_stRDSData_RDS_CT->Caption = str;
    }
    break;
    case RDS_EVENT_AF_LIST:
    {
        m_cbxAFList->Clear();
        // first 2byte is AF number (short)
        unsigned short af_num = (unsigned short)(m_sRDSInfo.m_buffer[0]);
        for(unsigned short i = 0; i < af_num; i++)
        {
            char str[100];
            sprintf(str, "%.1f", (float)(*(unsigned short *)(&m_sRDSInfo.m_buffer[2 * i + 1]) / 10.0));
            m_cbxAFList->Items->Add(str);
        }
    }
    break;
    // other events (just skip)
    default:
        break;
    }
}

void TfrmFM::QueryFMInfo(void)
{
    CFMRADIO FM_RADIO_Obj;

    m_bFMSupport = FM_RADIO_Obj.Query_FMSupport_Start();
    
    m_FMStepMode.m_i4Step = FM_STEP_MODE_100KHZ;
    if (m_bFMSupport)
    {
        FM_RADIO_Obj.REQ_Query_FMChipID_Start(m_FMChipId);
        bool bRet = FM_RADIO_Obj.REQ_Query_FMStepMode_Start(m_FMStepMode);
        if(!bRet)
        {
            m_FMStepMode.m_i4Step = FM_STEP_MODE_100KHZ;
        }
    }
}

//---------------------------------------------------------------------------
void TfrmFM::ReDrawFields(E_DRAW_FM_T draw)
{
    if (draw & DRAW_FM_STATION)
    {
        char str[256];
        if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
        {
            sprintf(str, "%.2f", m_sValidFreq.m_i2ValidFreq / FM_FREQ_SCALE_50KHZ);
        }
        else
        {
            sprintf(str, "%.1f", m_sValidFreq.m_i2ValidFreq / FM_FREQ_SCALE_100KHZ);
        }
        //sprintf(str, "%.1f", m_sValidFreq.m_i2ValidFreq / FM_FREQ_SCALE);
        m_edtStation->Text = (AnsiString) str;
        // new
        //m_edtFMReceiver_CurrentFrequency->Text = (AnsiString) str;
        //rongguo 2011-10-20

        if((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6626 || m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6628))
        {
            if(((m_sFMStepMode.m_i4Step == FM_STEP_MODE_100KHZ)&& 1075 == m_sValidFreq.m_i2ValidFreq ) ||
                    ((m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)&& 10750 == m_sValidFreq.m_i2ValidFreq))
            {
                return;
            }
        }
        if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
        {
            m_tbFMReceiver_Frequency->Position = m_sValidFreq.m_i2ValidFreq/5;
        }
        else
        {
            m_tbFMReceiver_Frequency->Position = m_sValidFreq.m_i2ValidFreq;
        }

    }

    if (draw & DRAW_FM_REGISTER)
    {
        // old
        m_edtWord1->Text = IntToStr((m_usData & 0xFF00) >> 8);
        m_edtWord0->Text = IntToStr(m_usData & 0x00FF);
        // new
        char buf[128];
        sprintf(buf, "%X", m_usData);
        m_edtFMReceiver_Word->Text = buf;
    }

    if(draw & DRAW_FM_STATUS_MT6620)
    {
        m_stFMReceiver_Status_RSSI->Caption = IntToStr(cnf.RSSI);
        m_stFMReceiver_Status_BW->Caption = IntToStr(cnf.STA_BW);
        m_stFMReceiver_Status_PAMD->Caption = IntToStr(cnf.PAMD);
        m_stFMReceiver_Status_MR->Caption = IntToStr(cnf.MR);
        m_stFMReceiver_Status_Stereo_Mono->Caption = IntToStr(cnf.STEREO_MONO);
        stFMRSSIhex->Caption = IntToStr(cnf.RSSI_HEX);
        stFMRSSIdbm->Caption = IntToStr(cnf.RSSI_DBM);
        stFMPAMDhex->Caption = IntToStr(cnf.PAMD_HEX);
        stFMPAMDdb->Caption = IntToStr(cnf.PAMD_DBM);
        stFMRSSIH->Caption = IntToStr(cnf.RSSI_HCC);
        stFMPAMDH->Caption = IntToStr(cnf.PAMD_HCC);
        stFMRSSIoffB->Caption = IntToStr(cnf.RSSI_OFF_B);
        stFMPAMDoffB->Caption = IntToStr(cnf.PAMD_OFF_B);
        stFMRSSIoffH->Caption = IntToStr(cnf.RSSI_OFF_H);
        stFMPAMDoffH->Caption = IntToStr(cnf.PAMD_OFF_H);
        stFMHCCFilter->Caption = IntToStr(cnf.HCC_FILTER);
        stFMSoftmuteStep->Caption = IntToStr(cnf.SOFTMUTE_STEP);
        stFMBlendGain->Caption = IntToStr(cnf.BLEND_GAIN);
        stFMBFN->Caption = IntToStr(cnf.BLEND_FILTER_NUMBER);
        stFMSoftmuteGms->Caption = IntToStr(cnf.SOFTMUTE_GMS);
        stFMSoftmuteGfs->Caption = IntToStr(cnf.SOFTMUTE_GFS);
        stFMDynamicGain->Caption = IntToStr(cnf.DYNAMIC_GAIN);
        stFMPLF->Caption = IntToStr(cnf.PILOT_LOCKED_FLAG);
        stFMSSF->Caption = IntToStr(cnf.SOFTMUTE_SELECTION_FLAG);
        stFMLNAGain2->Caption = IntToStr(cnf.LNA_GAIN);
        stFMLNAGainIdx2->Caption = IntToStr(cnf.LNA_GAIN_INDEX);
        stFMPGAGain2->Caption = IntToStr(cnf.PGA_GAIN);
        stFMPGAGainIdx2->Caption = IntToStr(cnf.PGA_GAIN_INDEX);
        stFMGainCounter2->Caption = IntToStr(cnf.GAIN_COUNTER);
        stFMRfTotalGain2->Caption = IntToStr(cnf.TOTAL_GAIN);
        stFMChipID->Caption = IntToStr(cnf.CHIP_ID);
        stFMPulseRatio->Caption = IntToStr(cnf.PULSE_RATIO);
        stFMFastPAMD->Caption = IntToStr(cnf.FAST_PAMD);
        stFMPowerDetector->Caption = IntToStr(cnf.POWER_DETECTOR);

    }

    if (draw & DRAW_FM_STATUS)
    {
        // old
        m_stRssi->Caption = IntToStr(m_sStatus.s_rssi.m_ucSignalLevel);
        m_stIfCounter->Caption = IntToStr(m_sStatus.s_if_cnt.m_u2IfCnt);
        m_stHLSide->Caption = IntToStr(m_sStatus.s_hl_side.m_ucHighOrLow);
        m_stStereoMono->Caption = IntToStr(m_sStatus.s_stero_mono.m_ucStereoOrMono);
        m_stFMReceiver_Status_RSSI->Caption = IntToStr(m_sStatus.s_rssi.m_ucSignalLevel);
        m_stFMReceiver_Status_IFCounter->Caption = IntToStr(m_sStatus.s_if_cnt.m_u2IfCnt);
        m_stFMReceiver_Status_HLSide->Caption = IntToStr(m_sStatus.s_hl_side.m_ucHighOrLow);
        m_stFMReceiver_Status_Stereo_Mono->Caption = m_sStatus.s_stero_mono.m_ucStereoOrMono == 1 ? "Stereo" : "Mono";
        // new
        // RX Filter BW
        m_stFMReceiver_Status_BW->Caption = IntToStr(m_sStatus.s_rxfilterbw.m_ucRXFilterBW);
        // PAMD Level
        m_stFMReceiver_Status_PAMD->Caption = IntToStr(m_sStatus.s_pamdlevel.m_ucPAMDLevel);
        // MR
        m_stFMReceiver_Status_MR->Caption = IntToStr(m_sStatus.s_mr.m_ucMR);
    }
    if(draw & DRAW_FM_RDS_BLOCK_COUNTER)
    {
        m_stRDSData_BlockCounter_Accepted->Caption = IntToStr(m_sRDSGoodBlockCounter.m_u2GoodBlock);
        m_stRDSData_BlockCounter_Errors->Caption = IntToStr(m_sRDSBadBlockCounter.m_u2BadBlock);
        m_stRDSData_BlockCounter_TotalRecv->Caption = IntToStr(m_sRDSBadBlockCounter.m_u2BadBlock+m_sRDSGoodBlockCounter.m_u2GoodBlock);
        // BLER
        m_stRDSData_BlockCounter_BLER->Caption = IntToStr(m_u2BLER);
        // RDS log
        AnsiString s;
//rongguo 2011-06-24
        /*        s.sprintf("%02X %02X %02X %02X %02X", m_sRDSLogData.m_u2Blocks[0], m_sRDSLogData.m_u2Blocks[1],
                    m_sRDSLogData.m_u2Blocks[2], m_sRDSLogData.m_u2Blocks[3], m_sRDSLogData.m_u2Blocks[4]);*/
        int maxIndex, lastLen;
        maxIndex = (m_sRDSLogData.dataLen + 3) / 4;
        lastLen =  (m_sRDSLogData.dataLen % 4) ? (m_sRDSLogData.dataLen % 4) : 4;

        for(int index = 0; index < maxIndex - 1; index++)
        {
            s.sprintf("%02X %02X %02X %02X", (unsigned char)m_sRDSLogData.data[4 * index],
                      (unsigned char)m_sRDSLogData.data[4 * index + 1],
                      (unsigned char)m_sRDSLogData.data[4 * index + 2],
                      (unsigned char)m_sRDSLogData.data[4 * index + 3]);
            m_richedtRDSLog->Lines->Add(s);
        }
        AnsiString tmp;
        s = (AnsiString)"\0";
        for(int index = 0; index < lastLen; index++)
        {
            tmp.sprintf("%02X ", (unsigned char)m_sRDSLogData.data[4 * (maxIndex - 1) + index]);
            s += tmp;
        }
        m_richedtRDSLog->Lines->Add(s);
    }
    if(draw & DRAW_FM_RDS_GROUP_COUNTER)
    {
//rongguo 2011-06-24
        m_stRDSData_GroupCounter_0A->Caption = IntToStr(m_sRDSGroupCounter.groupA[0]);
        m_stRDSData_GroupCounter_0B->Caption = IntToStr(m_sRDSGroupCounter.groupB[0]);
        m_stRDSData_GroupCounter_1A->Caption = IntToStr(m_sRDSGroupCounter.groupA[1]);
        m_stRDSData_GroupCounter_1B->Caption = IntToStr(m_sRDSGroupCounter.groupB[1]);
        m_stRDSData_GroupCounter_2A->Caption = IntToStr(m_sRDSGroupCounter.groupA[2]);
        m_stRDSData_GroupCounter_2B->Caption = IntToStr(m_sRDSGroupCounter.groupB[2]);
        m_stRDSData_GroupCounter_3A->Caption = IntToStr(m_sRDSGroupCounter.groupA[3]);
        m_stRDSData_GroupCounter_3B->Caption = IntToStr(m_sRDSGroupCounter.groupB[3]);
        m_stRDSData_GroupCounter_4A->Caption = IntToStr(m_sRDSGroupCounter.groupA[4]);
        m_stRDSData_GroupCounter_4B->Caption = IntToStr(m_sRDSGroupCounter.groupB[4]);
        m_stRDSData_GroupCounter_5A->Caption = IntToStr(m_sRDSGroupCounter.groupA[5]);
        m_stRDSData_GroupCounter_5B->Caption = IntToStr(m_sRDSGroupCounter.groupB[5]);
        m_stRDSData_GroupCounter_6A->Caption = IntToStr(m_sRDSGroupCounter.groupA[6]);
        m_stRDSData_GroupCounter_6B->Caption = IntToStr(m_sRDSGroupCounter.groupB[6]);
        m_stRDSData_GroupCounter_7A->Caption = IntToStr(m_sRDSGroupCounter.groupA[7]);
        m_stRDSData_GroupCounter_7B->Caption = IntToStr(m_sRDSGroupCounter.groupB[7]);
        m_stRDSData_GroupCounter_8A->Caption = IntToStr(m_sRDSGroupCounter.groupA[8]);
        m_stRDSData_GroupCounter_8B->Caption = IntToStr(m_sRDSGroupCounter.groupB[8]);
        m_stRDSData_GroupCounter_9A->Caption = IntToStr(m_sRDSGroupCounter.groupA[9]);
        m_stRDSData_GroupCounter_9B->Caption = IntToStr(m_sRDSGroupCounter.groupB[9]);
        m_stRDSData_GroupCounter_10A->Caption = IntToStr(m_sRDSGroupCounter.groupA[10]);
        m_stRDSData_GroupCounter_10B->Caption = IntToStr(m_sRDSGroupCounter.groupB[10]);
        m_stRDSData_GroupCounter_11A->Caption = IntToStr(m_sRDSGroupCounter.groupA[11]);
        m_stRDSData_GroupCounter_11B->Caption = IntToStr(m_sRDSGroupCounter.groupB[11]);
        m_stRDSData_GroupCounter_12A->Caption = IntToStr(m_sRDSGroupCounter.groupA[12]);
        m_stRDSData_GroupCounter_12B->Caption = IntToStr(m_sRDSGroupCounter.groupB[12]);
        m_stRDSData_GroupCounter_13A->Caption = IntToStr(m_sRDSGroupCounter.groupA[13]);
        m_stRDSData_GroupCounter_13B->Caption = IntToStr(m_sRDSGroupCounter.groupB[13]);
        m_stRDSData_GroupCounter_14A->Caption = IntToStr(m_sRDSGroupCounter.groupA[14]);
        m_stRDSData_GroupCounter_14B->Caption = IntToStr(m_sRDSGroupCounter.groupB[14]);
        m_stRDSData_GroupCounter_15A->Caption = IntToStr(m_sRDSGroupCounter.groupA[15]);
        m_stRDSData_GroupCounter_15B->Caption = IntToStr(m_sRDSGroupCounter.groupB[15]);
        /*        int total=0;
                for(int i=0;i<32;i++)
                {
                    total += m_sRDSGroupCounter.m_u2GroupCounter[i];
                }
                m_stRDSData_GroupCounter_Total->Caption = IntToStr(total);*/
        m_stRDSData_GroupCounter_Total->Caption = m_sRDSGroupCounter.total;
    }
}
//===========================================================================
void TfrmFM::ShowHintLabel(TControl *sender, char* hint)
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

//--------------------------------------------------------------------------
void __fastcall TfrmFM::edtFreqCheck(TObject *Sender)
{
    AnsiString  text;
    short freq;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " frequecy shall be 76~108 MHz ";

    text = edit->Text;
    /*    if (!IsValidFMFreq(text, freq))
        {
            ShowHintLabel(edit, hint);
            edit->SetFocus();
            return;
        } */

    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        if (!IsValidFMFreqFor50KHz(text, freq))
        {
            ShowHintLabel(edit, hint);
            edit->SetFocus();
            return;
        }
        else
        {
            if(freq%5 != 0)
            {
                char hint50KHz[] = "Invalid frequency,please reset it ";
                ShowHintLabel(edit, hint50KHz);
                edit->SetFocus();
                return;
            }
        }
    }
    else
    {
        if (!IsValidFMFreq(text, freq))
        {
            ShowHintLabel(edit, hint);
            edit->SetFocus();
            return;
        }
    }
    m_btnFMRXTune_Increase->Tag --;
    m_btnFMRXTune_Decrease->Tag --;

    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        m_tbFMReceiver_Frequency->Position = freq/5;
    }
    else
    {
        m_tbFMReceiver_Frequency->Position = freq;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnSetFreqClick(TObject *Sender)
{
    FM_FREQ_REQ_T req;
    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        AnsiString_To_FM_Freq_50KHz(m_edtFreq->Text, req.m_i2CurFreq);
    }
    else
    {
        AnsiString_To_FM_Freq(m_edtFreq->Text, req.m_i2CurFreq);
    }

    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SetFreq;
    m_cFM_RADIO_Obj.REQ_Set_Freq_Start(req);
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Set frequency progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::edtRssiThresholdCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 1~6";

    text = edit->Text;
    if (!IsValidFMRssiThreshold(text, uidata))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::edtIFCounterDeltaCheck(TObject *Sender)
{
    AnsiString  text;
    unsigned int uidata;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " value shall be 10~30 and multiple of 5";

    text = edit->Text;
    if (!IsValidFMIfCounterDelta(text, uidata))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }
}

//==========================================================================
void __fastcall TfrmFM::m_btnSearchNextStationClick(TObject *Sender)
{
    S_FM_SEARCH_STATION_T search_station;
    short freq;
    search_station.s_if_cnt_delta.m_u4IfCntDelta = m_cbIfCounterDelta->Text.ToInt();
    search_station.s_rssi_thrsh.m_u4RssiThreshold = m_cbRssiThreshold->ItemIndex + 1;

    if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        AnsiString_To_FM_Freq_50KHz(m_edtStation->Text, freq);
        search_station.s_freq_range.m_i2StartFreq = freq + 5;
        search_station.s_freq_range.m_i2StopFreq  = FM_MAX_FREQ * FM_FREQ_SCALE_50KHZ;
    }
    else
    {
        AnsiString_To_FM_Freq(m_edtStation->Text, freq);
        search_station.s_freq_range.m_i2StartFreq = freq + 1;
        search_station.s_freq_range.m_i2StopFreq  = FM_MAX_FREQ * FM_FREQ_SCALE_100KHZ;
    }

    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SearchNextStation;
    m_cFM_RADIO_Obj.REQ_SearchFreq_Start(search_station);
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Search next station progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_SearchNextStation(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        FM_VAILD_FREQ_CNF_T* p_valid_freq;
        p_valid_freq = m_cFM_RADIO_Obj.Get_ValidFreq();
        m_sValidFreq = *p_valid_freq;
        ReDrawFields(DRAW_FM_STATION);
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Search next station successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Search next station", state, m_sbFM);
    }
    break;
    }
    //CurrentPageReset();
    m_FMOldUILocker.Unlock();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmFM::m_btnSearchPreStationClick(TObject *Sender)
{
    S_FM_SEARCH_STATION_T search_station;
    short freq;
    search_station.s_if_cnt_delta.m_u4IfCntDelta = m_cbIfCounterDelta->Text.ToInt();
    search_station.s_rssi_thrsh.m_u4RssiThreshold = m_cbRssiThreshold->ItemIndex + 1;
    if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ )
    {
        AnsiString_To_FM_Freq_50KHz(m_edtStation->Text, freq);
        search_station.s_freq_range.m_i2StartFreq = freq - 5;
        search_station.s_freq_range.m_i2StopFreq  = FM_MIN_FREQ * FM_FREQ_SCALE_50KHZ;
    }
    else
    {
        AnsiString_To_FM_Freq(m_edtStation->Text, freq);
        search_station.s_freq_range.m_i2StartFreq = freq - 1;
        search_station.s_freq_range.m_i2StopFreq  = FM_MIN_FREQ * FM_FREQ_SCALE_100KHZ;
    }

    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SearchNextStation;
    m_cFM_RADIO_Obj.REQ_SearchFreq_Start(search_station);
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Search previous station progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_SearchPreStation(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Search previous station successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Search previous station", state, m_sbFM);
    }
    break;
    }
    //CurrentPageReset();
    m_FMOldUILocker.Unlock();
}

//===========================================================================
void __fastcall TfrmFM::m_btnSetAudioClick(TObject *Sender)
{
    S_FM_AUDIO_T audio;

    audio.s_mono_stereo_blend.m_u2MonoOrStereo = m_cbMode->ItemIndex;  // 0: mono, 1: stereo
    audio.s_mono_stereo_blend.m_u2SblendOnOrOff = m_cbStereoBlend->Checked && m_cbStereoBlend->Enabled;
    audio.s_soft_mute_onoff.m_bOnOff = m_cbSoftMute->Checked;
    //audio.s_soft_mute_level.m_ucStage = m_cbSoftMuteLevel->ItemIndex + 1;
    audio.s_stereo_blend_level.m_ucStage = m_cbStereoBlendLevel->ItemIndex + 1;

    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SetAudio;
    m_cFM_RADIO_Obj.REQ_SetAudio_Start(audio);

    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Set audio parameter progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_SetAudio(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Set audio parameter successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Set audio parameter", state, m_sbFM);
    }
    break;
    }
    //CurrentPageReset();
    m_FMOldUILocker.Unlock();
}

//===========================================================================
void __fastcall TfrmFM::m_btnReadClick(TObject *Sender)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_ReadData;
    m_cFM_RADIO_Obj.REQ_ReadData_Start(m_edtAddr->Text.ToInt());
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Read data progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void __fastcall TfrmFM::m_btnWriteClick(TObject *Sender)
{
    unsigned short data;
    unsigned short word1;
    unsigned short word0;
    word1 = m_edtWord1->Text.ToInt() & 0x00FF;
    word0 = m_edtWord0->Text.ToInt() & 0x00FF;
    data  = (word1 << 8) | word0;
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_WriteData;
    m_cFM_RADIO_Obj.REQ_WriteData_Start(m_edtAddr->Text.ToInt(), data);
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Write data progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnGetClick(TObject *Sender)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_GetStatus;
    m_cFM_RADIO_Obj.REQ_Get_FM_Status_Start();
    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Get FM status progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_GetStatus(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        S_FM_STATUS_T* p_fm_status = m_cFM_RADIO_Obj.Get_FMStatus();
        m_sStatus = *p_fm_status;
        ReDrawFields(DRAW_FM_STATUS);
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Get FM status successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Get FM status", state, m_sbFM);
    }
    break;
    }
    //CurrentPageReset();
    m_FMOldUILocker.Unlock();
}


void __fastcall TfrmFM::m_btnResetClick(TObject *Sender)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerReset;
    m_cFM_RADIO_Obj.REQ_FM_Power_Off_Start();

    m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Reset progressing";
    //CurrentPageLock();
    m_FMOldUILocker.Lock();
}

//-------------------------------------------------------------------------
void TfrmFM::CNF_FM_PowerReset(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerOn;
        m_cFM_RADIO_Obj.REQ_FM_Power_On_Start();
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  FM radio module power reset successfully";
    }
    break;

    default:
        CNF_ErrorHandler("FM radio module power on", state, m_sbFM);
        break;
    }
    //CurrentPageReset();
    m_FMOldUILocker.Unlock();
}

//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_cbModeChange(TObject *Sender)
{
    m_cbStereoBlend->Enabled = (FM_MODE_IDX_STEREO == (E_FM_MODE_IDX) m_cbMode->ItemIndex) ? true : false;
}

// for MT6616 new API
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_tbFMReceiver_FrequencyChange(TObject *Sender)
{
//    m_edtFMReceiver_CurrentFrequency->Text = Double_To_AnsiString((double)m_tbFMReceiver_Frequency->Position/10.0f, 1);
    if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ )
    {
        LOG("Max:%d, Min:%d, m_tbFMReceiver_Frequency->Position:%d",m_tbFMReceiver_Frequency->Max,m_tbFMReceiver_Frequency->Min,m_tbFMReceiver_Frequency->Position);
        m_edtFMReceiver_CurrentFrequency->Text = Double_To_AnsiString((double)(m_tbFMReceiver_Frequency->Position)/20.0f, 2);
    }
    else
    {
        m_edtFMReceiver_CurrentFrequency->Text = Double_To_AnsiString((double)m_tbFMReceiver_Frequency->Position/10.0f, 1);
    }
    /*    m_btnFMRXTune_Increase->Tag = m_tbFMReceiver_Frequency->Position;
        m_btnFMRXTune_Decrease->Tag = m_tbFMReceiver_Frequency->Position; */
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRDS_BlockCounterResetClick(TObject *Sender)
{
    m_cFM_RDS_Obj.ConfirmCallback = ::CNF_FM_ResetBlockCounter;
    m_cFM_RDS_Obj.REQ_FM_RDS_Reset_BlockCounter_Start();

    m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset block counter progressing";
    //CurrentPageLock();
    m_FMRDSLocker.Lock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRDS_GroupCounterResetClick(TObject *Sender)
{
    m_cFM_RDS_Obj.ConfirmCallback = ::CNF_FM_ResetGroupCounter;
    m_cFM_RDS_Obj.REQ_FM_RDS_Reset_GroupCounter_Start();

    m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset group counter progressing";
    //CurrentPageLock();
    m_FMRDSLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_ResetBlockCounter(void)
{
    // update UI
    META_RESULT state = m_cFM_RDS_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // FIXME!!!
        //ReDrawFields(DRAW_FM_RDS_BLOCK_COUNTER);
        //m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset block counter successfully";
        //Use PostMessage to fix hange issue.
        PostMessage(this->Handle,WM_ML_FM_BLOCKCOUNTER_RESET_MSG,0,0);
    }
    break;

    default:
        CNF_ErrorHandler("Reset block counter", state, m_sbFMRDS);
        break;
    }
    //CurrentPageReset();
    m_FMRDSLocker.Unlock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_ResetGroupCounter(void)
{
    // update UI
    META_RESULT state = m_cFM_RDS_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // FIXME!!!
        //ReDrawFields(DRAW_FM_RDS_GROUP_COUNTER);
        //m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset group counter successfully";
        //Use PostMessage to fix hange issue.
        PostMessage(this->Handle,WM_ML_FM_GROUPCOUNTER_RESET_MSG,0,0);
    }
    break;

    default:
        CNF_ErrorHandler("Reset group counter", state, m_sbFMRDS);
        break;
    }
    //CurrentPageReset();
    m_FMRDSLocker.Unlock();
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_btnFMRDS_RDSOffClick(TObject *Sender)
{
    // set block counter timer be false
    ClearRDSUIData();
    CounterTimer->Enabled = false;
    CounterTimer->Tag = 0;
//rongguo 2011-06-22
    /*    m_btnFMRXRDSOn->Tag = 0;
        m_btnFMRDS_RDSOn->Tag = 0; */
    m_cFM_RDS_Obj.ConfirmCallback = ::CNF_FM_RDSOff;
    m_cFM_RDS_Obj.REQ_FM_RDS_Off_Start();
    m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  RDS Off progressing";
    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  RDS Off progressing";
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_RDSOff(void)
{
    // update UI
    META_RESULT state = m_cFM_RDS_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_btnFMRXRDSOn->Tag = 0;
        m_btnFMRDS_RDSOn->Tag = 0;
        m_btnFMRXRDSOff->Enabled = false;
        m_btnFMRDS_RDSOff->Enabled = false;
//rongguo 2011-06-24
        m_btnFMRDS_BlockCounterReset->Enabled = false;
        m_btnFMRDS_GroupCounterReset->Enabled = false;

        TxMainUIControl(~(FM_TX_MAIN_UICONTROL_POWERON | FM_TX_MAIN_UICONTROL_RDSOFF));

        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)" RDS off successful";
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFMRDS->Panels->Items[0]->Text;
//rongguo 2011-07-05
        bFirstDisplayTime[0] = true;
        bFirstDisplayTime[1] = true;
        bFirstDisplayTime[2] = true;
    }
    break;

    default:
        CNF_ErrorHandler("RDS Off", state, m_sbFMRDS);
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFMRDS->Panels->Items[0]->Text;
        break;
    }
    //CurrentPageReset();
    m_FMReceiverLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRDS_RDSOnClick(TObject *Sender)
{
//rongguo 2011-06-22
    if(!m_btnFMRXPowerOn->Tag)
    {
        Application->MessageBox("Please turn on RX first", "WARNING", MB_OK );
        return;
    }
    m_cFM_RDS_Obj.ConfirmCallback = ::CNF_FM_RDSOn;
    m_cFM_RDS_Obj.REQ_FM_RDS_On_Start(this->Handle);
//rongguo 2011-06-22
    /*    m_btnFMRXRDSOn->Tag = 1;
        m_btnFMRDS_RDSOn->Tag = 1; */
    m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  RDS On progressing";
    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  RDS On progressing";
//    CurrentPageLock();
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_RDSOn(void)
{
    // update UI
    META_RESULT state = m_cFM_RDS_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // set block counter timer be true
       /* CounterTimer->Enabled = true;
        CounterTimer->Tag = 1;
        m_btnFMRXRDSOn->Tag = 1;
        m_btnFMRDS_RDSOn->Tag = 1;

        m_btnFMRXRDSOff->Enabled = true;
        m_btnFMRDS_RDSOff->Enabled = true;
//rongguo 2011-06-24
        m_btnFMRDS_BlockCounterReset->Enabled = true;
        m_btnFMRDS_GroupCounterReset->Enabled = true;

        TxMainUIControl(FM_TX_MAIN_UICONTROL_RDSOFF | FM_TX_MAIN_UICONTROL_OTHERS | FM_TX_MAIN_UICONTROL_RESET);
        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  RDS On successful";
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  RDS On successful"; */

        //Use PostMessage to fix hange issue.
        PostMessage(this->Handle,WM_ML_FM_RDSON_SUCCESS_MSG,0,0);
        break;
    }
    case META_FAILED:
    {
        m_btnFMRXRDSOn->Tag = 0;
        m_btnFMRDS_RDSOn->Tag = 0;
        m_btnFMRXRDSOff->Enabled = false;
        m_btnFMRDS_RDSOff->Enabled = false;
        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)" RDS On failed";
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFMRDS->Panels->Items[0]->Text;
        break;
    }
    default:
        CNF_ErrorHandler("RDS On", state, m_sbFMRDS);
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFMRDS->Panels->Items[0]->Text;
        break;
    }
//    CurrentPageReset();
    m_FMReceiverLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXAutoScanClick(TObject *Sender)
{
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }
    // Removing all items
    m_cbFMReceiver_ChannelList->Clear();
    dwStart   =   GetTickCount();
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_AutoScan;
    m_cFM_RADIO_Obj.REQ_FM_AutoScan_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  AutoScan progressing";
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_AutoScan(void)
{
    // update UI
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    TDateTime dt = Now();
    WORD hour,min, sec, msec;
    dt.DecodeTime(&hour, &min,&sec,&msec);

    switch (state)
    {
    case META_SUCCESS:
    {
        // update the channel list!
        int idx = 0;
        m_cFM_RADIO_Obj.Get_AutoScan(m_sAutoScan);
        short base = FM_FREQUENCY_MIN_100KHZ;
        int nSpace = 1;
        int nScanTableSize = 16;
        int nUpperLimit = FM_FREQUENCY_MAX_100KHZ;
        if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ )
        {
            base = FM_FREQUENCY_MIN_50KHZ;
            nSpace = 5;
            nScanTableSize = 26;
            nUpperLimit = FM_FREQUENCY_MAX_50KHZ;
        }
        else
        {
            base = FM_FREQUENCY_MIN_100KHZ;
            nSpace = 1;
            nScanTableSize = 16;
            nUpperLimit = FM_FREQUENCY_MAX_100KHZ;
        }
        for(int i=0; i<nScanTableSize; i++)
        {
            unsigned short mask = 0x0001;
            for(int j=0; j<sizeof(unsigned short)*8; j++)
            {
                bool flag = m_sAutoScan.m_u2Bitmap[i] & (mask << j);
                // if(base > 1080)
                if(base > nUpperLimit)
                {
                    break;
                }
                LOG("base:%d",base);
                //rongguo 2011-10-20
                if((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6626 || m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6628))
                {
                    if(((m_sFMStepMode.m_i4Step == FM_STEP_MODE_100KHZ)&& 1075 == base ) ||
                            ((m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)&& 10750 == base))
                    {
                        base += nSpace;
                        continue;
                    }
                }

                if(flag)
                {
//rongguo 2011-06-09
//                        AnsiString item = Double_To_AnsiString((double)base/10.0f, 1);
                    char buffer[50] = {0};
                    LOG("flag:%d,base:%d",flag,base);
                    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
                    {
                        sprintf(buffer, "Channel %d: %0.2f", idx++, (double)base/100.0f);
                    }
                    else
                    {
                        sprintf(buffer, "Channel %d: %0.1f", idx++, (double)base/10.0f);
                    }

                    m_cbFMReceiver_ChannelList->AddItem(buffer, NULL);
                }

                base += nSpace;
            }

        }
        // Enabled go button
        lbTime->Caption = FloatToStr((GetTickCount()-dwStart)/1000.0);
        m_btnFMRXGoChannel->Enabled = true;
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Auto Scan successfully";
    }
    break;
    default:
        CNF_ErrorHandler("Auto Scan", state, m_sbFMReceiver);
        break;
    }
    //CurrentPageReset();
    m_FMReceiverLocker.Unlock();
}

//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXRegisterReadClick(TObject *Sender)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_ReadData;
    m_cFM_RADIO_Obj.REQ_ReadData_Start(m_ucAddr);

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Read data progressing";
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_ReadData(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_usData = m_cFM_RADIO_Obj.Get_Data();
        ReDrawFields(DRAW_FM_REGISTER);
        // old
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Read data successfully";
        // new
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Read data successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Read data", state, m_sbFM);
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
    }
    break;
    }

    //CurrentPageReset();
    if(m_pgcFMRadio->ActivePage == m_tsFMReceiver)
    {
        m_FMReceiverLocker.Unlock();
    }
    else if(m_pgcFMRadio->ActivePage == m_tsOldFMUI)
    {
        m_FMOldUILocker.Unlock();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_btnFMRXRegisterWriteClick(TObject *Sender)
{
    unsigned short us_data;
    // new
    if(!AnsiString_Hex_To_UnsignedShort(m_edtFMReceiver_Word->Text, us_data ))
    {
        return;
    }
    if(!AnsiString_Hex_To_UnsignedChar(m_edtFMRegister_Address->Text, m_ucAddr ))
    {
        return;
    }
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_WriteData;
    m_cFM_RADIO_Obj.REQ_WriteData_Start(m_ucAddr, us_data);

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Write data progressing";
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_WriteData(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // old
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Write data successfully";
        // new
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Write data successfully";
    }
    break;

    default:
    {
        CNF_ErrorHandler("Write data", state, m_sbFM);
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
    }
    break;
    }
    //CurrentPageReset();
    if(m_pgcFMRadio->ActivePage == m_tsFMReceiver)
    {
        m_FMReceiverLocker.Unlock();
    }
    else if(m_pgcFMRadio->ActivePage == m_tsOldFMUI)
    {
        m_FMOldUILocker.Unlock();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnFMRXPowerOnClick(TObject *Sender)
{
    if(bFMTXPowerOn == true)
    {
        Application->MessageBox( "Please turn off TX.", "Fail", MB_OK );
        return;
    }
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerOn;
    m_cFM_RADIO_Obj.REQ_FM_Power_On_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Power On progressing";

}
//===========================================================================
void TfrmFM::CNF_FM_PowerOn(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // 20100320 for form close handling
        frmFM->Tag = 1;
        // old
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  FM radio module power on successfully";
        // new
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  FM radio module power on successfully";

        //version = m_cFM_RADIO_Obj.REQ_FM_Query_Version_Start();
        m_btnFMRXPowerOn->Tag = 1;
        m_btnFMRXRDSOn->Enabled = true;
        m_btnFMRDS_RDSOn->Enabled = true;
        bFMRXPowerOn = true;
        //CurrentPageReset();
        m_FMReceiverLocker.Unlock();
        TxMainUIControl(~(FM_TX_MAIN_UICONTROL_POWERON | FM_TX_MAIN_UICONTROL_RDSOFF));
    }
    break;

    default:
    {
        CNF_ErrorHandler("FM radio module power on", state, m_sbFM);
        //CurrentPageReset();
        m_FMReceiverLocker.Unlock();
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
    }
    break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnFMRXPowerOffClick(TObject *Sender)
{
    // FIXME!!!
//rongguo 2011-06-22
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerOff;
    m_cFM_RADIO_Obj.REQ_FM_Power_Off_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Power Off progressing";
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_PowerOff(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    // 20100320 for form close handling
    if(state != META_SUCCESS)
    {
        if(true == g_DisconnectFlag || true == g_CloseFlag)
        {
            PostMessage(hForm_MainForm, WM_FM_DISCONNECT_CLEAN_DONE, 1, 0);
        }
        CNF_ErrorHandler("FM radio module power off", state, m_sbFMReceiver);
    }
    else
    {
        bFMRXPowerOn = false;
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  FM radio module power off successfully";
//rongguo 2011-06-22
        m_btnFMRXPowerOn->Tag = 0;
        m_btnFMRXRDSOn->Enabled = false;
        m_btnFMRDS_RDSOn->Enabled = false;
        if(true == g_DisconnectFlag || true == g_CloseFlag)
        {
            PostMessage(hForm_MainForm, WM_FM_DISCONNECT_CLEAN_DONE, 0, 0);
        }
    }
    // no matter the power off is successfully or not, the form can close!!
    frmFM->Tag = 0;
    //CurrentPageReset();
    m_FMReceiverLocker.Unlock();
    TxMainUIControl(FM_TX_MAIN_UICONTROL_POWERON);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_btnFMRXSeekLeftClick(TObject *Sender)
{
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }
    if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ )
    {
        m_cFM_RADIO_Obj.Set_HWSeekReq(m_edtFMReceiver_CurrentFrequency->Text.ToDouble()*100, 0);
    }
    else
    {
        m_cFM_RADIO_Obj.Set_HWSeekReq(m_edtFMReceiver_CurrentFrequency->Text.ToDouble()*10, 0);
    }
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SeekStation;
    m_cFM_RADIO_Obj.REQ_FM_HWSeek_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Seek previous station progressing";
    //m_FMReceiverLocker.Lock();

}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_btnFMRXSeekRightClick(TObject *Sender)
{
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }
//    m_cFM_RADIO_Obj.Set_HWSeekReq(m_edtFMReceiver_CurrentFrequency->Text.ToDouble()*10, 1);
    if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ )
    {
        m_cFM_RADIO_Obj.Set_HWSeekReq(m_edtFMReceiver_CurrentFrequency->Text.ToDouble()*100, 1);
    }
    else
    {
        m_cFM_RADIO_Obj.Set_HWSeekReq(m_edtFMReceiver_CurrentFrequency->Text.ToDouble()*10, 1);
    }
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SeekStation;
    m_cFM_RADIO_Obj.REQ_FM_HWSeek_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Seek next station progressing";

    //m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_SeekStation(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        m_cFM_RADIO_Obj.Get_ValidSeekFreq(m_sHWSeek);
        m_sValidFreq.m_i2ValidFreq = m_sHWSeek.m_i2EndFreq;
        ReDrawFields(DRAW_FM_STATION);
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Seek station successfully";
        m_btnFMRXSetFrequencyClick(m_btnFMRXSeekRight);
    }
    break;

    default:
        CNF_ErrorHandler("Seek Station", state, m_sbFMReceiver);
        break;
    }
    //m_FMReceiverLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXSetFrequencyClick(TObject *Sender)
{
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }
    //CurrentPageLock();
    //m_FMReceiverLocker.Lock();
    FM_FREQ_REQ_T req;
//    AnsiString_To_FM_Freq(m_edtFMReceiver_CurrentFrequency->Text, req.m_i2CurFreq);
    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        AnsiString_To_FM_Freq_50KHz(m_edtFMReceiver_CurrentFrequency->Text, req.m_i2CurFreq);
        m_tbFMReceiver_Frequency->Position = req.m_i2CurFreq/5;
    }
    else
    {
        AnsiString_To_FM_Freq(m_edtFMReceiver_CurrentFrequency->Text, req.m_i2CurFreq);
        m_tbFMReceiver_Frequency->Position = req.m_i2CurFreq;
    }

    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_SetFreq;
    m_cFM_RADIO_Obj.REQ_Set_Freq_Start(req);

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Set frequency progressing";
}
//frequency
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_SetFreq(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // old
        m_sbFM->Panels->Items[0]->Text = (AnsiString)"  Set frequency successfully";
        // new
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Set frequency successfully";

        m_sbFMTX->Panels->Items[0]->Text = (AnsiString)"  Set frequency successfully";

        //rongguo 2011-09-01
        if(m_pgcFMRadio->ActivePage == tsFMTx)
        {
            //rongguo 2011-04-20
            if(true == g_isPowerOnPressed)
            {
                TObject *Sender = (TObject *)btnFMTxPowerOnOff;
                char key = VK_RETURN;
                edtFMTxRFlevelKeyPress(Sender, key);
                edtFMTxAudioDeviationKeyPress(Sender, key);
                cbFMTxPilotOnKeyPress(Sender, key);
                edtFMTxPilotDeviationKeyPress(Sender, key);
                cbFMTxRDSOnKeyPress(Sender, key);
                edtFMTxRDSDeviationKeyPress(Sender, key);
                cbFMTxModulationOnKeyPress(Sender, key);
                cbFMTxStereoMonoEnableKeyPress(Sender, key);
                edtFMTxPilotFreqKeyPress(Sender, key);
                cbFMTxPreEmphasisKeyPress(Sender, key);

                m_FMTxLocker.Unlock();
                ResetFMTxUI(true);
                udFMTxPilotDeviation->Enabled = true;
                edtFMTxPilotDeviation->Enabled = true;

                udFMTxRDSDeviation->Enabled = false;
                edtFMTxRDSDeviation->Enabled = false;

                g_isPowerOnPressed = false;
            }
            //rongguo 2011-04-29
            TObject *Sender = (TObject *)edtFMTxRFFreq;
            readVaractorClick(Sender);

        }
        else if(m_pgcFMRadio->ActivePage == m_tsFMReceiver)
        {
            if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
            {
                AnsiString_To_FM_Freq_50KHz(m_edtFMReceiver_CurrentFrequency->Text, m_RXCurrentFrequency);
            }
            else
            {
                AnsiString_To_FM_Freq(m_edtFMReceiver_CurrentFrequency->Text, m_RXCurrentFrequency);
            }
            //m_FMReceiverLocker.Unlock();
        }
        else if(m_pgcFMRadio->ActivePage == m_tsOldFMUI)
        {
            m_FMOldUILocker.Unlock();
        }

    }
    break;

    default:
    {
        CNF_ErrorHandler("Set frequency", state, m_sbFM);
        m_sbFMReceiver->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
        m_sbFMTX->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
        //rongguo 2011-09-01
        if(m_pgcFMRadio->ActivePage == tsFMTx)
        {
            //rongguo 2011-04-29
            m_FMTxLocker.Unlock();
            TObject *Sender = (TObject *)edtFMTxRFFreq;
            readVaractorClick(Sender);
        }
        else if(m_pgcFMRadio->ActivePage == m_tsFMReceiver)
        {
            m_FMReceiverLocker.Unlock();
        }
        else if(m_pgcFMRadio->ActivePage == m_tsOldFMUI)
        {
            m_FMOldUILocker.Unlock();
        }
        // CurrentPageReset();
    }
    break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXSetClick(TObject *Sender)
{

    if(version == 1 || version == 0)
    {
        // check the hardware
        if((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6616))
        {
            m_vParameter.clear();
            parameter_pair parameter;
            // decode mode
            m_cFM_RADIO_Obj.Set_DecodeModeReq(m_cbFMReceiver_Setting_DecodeMode->ItemIndex);
            parameter.first = FM_PARAMETER_DECODE_MODE;
            parameter.second= AnsiString("Set Decode Mode");
            m_vParameter.push_back(parameter);
            // de-emphasis level
            m_cFM_RADIO_Obj.Set_DeemphasisLevelReq(m_cbFMReceiver_Setting_De_emphasisLevel->ItemIndex);
            parameter.first = FM_PARAMETER_DEEMPHASIS_LEVEL;
            parameter.second= AnsiString("Set De-emphasis Level");
            m_vParameter.push_back(parameter);
            // Stereo blend control enable
            if(m_cbFMReceiver_Setting_DecodeMode->ItemIndex == 0)
            {
                m_cFM_RADIO_Obj.Set_StereoBlendControl(m_cbFMReceiver_Setting_StereoBlend->ItemIndex);
                parameter.first = FM_PARAMETER_STEREO_BLEND;
                parameter.second= AnsiString("Set Stereo Blend Control");
                m_vParameter.push_back(parameter);
            }
            // HL side
            m_cFM_RADIO_Obj.Set_HLSideReq(m_cbFMReceiver_Setting_HLSide->ItemIndex);
            parameter.first = FM_PARAMETER_HL_SIDE;
            parameter.second= AnsiString("Set HL Side");
            m_vParameter.push_back(parameter);
            // HCC
            m_cFM_RADIO_Obj.Set_HCCReq(m_cbFMReceiver_Setting_HCC->ItemIndex);
            parameter.first = FM_PARAMETER_HCC;
            parameter.second= AnsiString("Set HCC");
            m_vParameter.push_back(parameter);
            // demod bandwidth
            if(m_cbFMReceiver_Setting_DemodBandwidth->ItemIndex == 0)
                m_cFM_RADIO_Obj.Set_DemodBandwidthReq(0);
            else if(m_cbFMReceiver_Setting_DemodBandwidth->ItemIndex == 1)
                m_cFM_RADIO_Obj.Set_DemodBandwidthReq(1);
            else
                m_cFM_RADIO_Obj.Set_DemodBandwidthReq(2);
            parameter.first = FM_PARAMETER_DEMOD_BW;
            parameter.second= AnsiString("Set Demodulation bandwidth");
            m_vParameter.push_back(parameter);
            // pamd threshold
            m_cFM_RADIO_Obj.Set_PAMDThresholdReq(m_edtFMReceiver_Setting_PAMDThreshold->Text.ToInt());
            parameter.first = FM_PARAMETER_PAMD_THRESHOLD;
            parameter.second= AnsiString("Set PAMD Threshold");
            m_vParameter.push_back(parameter);
            // dynamic limiter
            m_cFM_RADIO_Obj.Set_DynamicLimiterReq(m_cbFMReceiver_Setting_DynamicLimiter->ItemIndex);
            parameter.first = FM_PARAMETER_DYNAMIC_LIMITER;
            parameter.second= AnsiString("Set Dynamic Limiter");
            m_vParameter.push_back(parameter);
            // RSSI threshold
            m_cFM_RADIO_Obj.Set_RSSIThresholdReq(m_edtFMReceiver_Setting_RSSIThreshold->Text.ToInt());
            parameter.first = FM_PARAMETER_RSSI_THRESHOLD;
            parameter.second= AnsiString("Set RSSI Threshold");
            m_vParameter.push_back(parameter);
            // soft mute rate
            m_cFM_RADIO_Obj.Set_SoftmuteRateReq(m_edtFMReceiver_Setting_SoftMuteRate->Text.ToInt());
            parameter.first = FM_PARAMETER_SOFTMUTE_RATE;
            parameter.second= AnsiString("Set Softmute Rate");
            m_vParameter.push_back(parameter);
            // soft mute
            m_cFM_RADIO_Obj.Set_SoftmuteEnableReq(m_cbFMReceiver_Setting_SoftMute->ItemIndex);
            parameter.first = FM_PARAMETER_SOFTMUTE_ENABLE;
            parameter.second= AnsiString("Set Softmute enable");
            m_vParameter.push_back(parameter);
            m_iterParameter = m_vParameter.begin();

            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Setting parameter progressing";
            //CurrentPageLock();
            m_FMReceiverLocker.Lock();
            ParameterSetting();
        }
        else if(((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189AN)    ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189BN_CN) ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188A)     ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188C)     ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188D)))
        {
            m_vParameter.clear();
            parameter_pair parameter;
            // mono or stereo blend
            /*
            audio.s_mono_stereo_blend.m_u2MonoOrStereo = m_cbFMReceiver_Setting_StereoBlend->ItemIndex;  // 0: mono, 1: stereo blend
            audio.s_mono_stereo_blend.m_u2SblendOnOrOff = m_cbFMReceiver_Setting_StereoBlend->ItemIndex;
            */
            m_cFM_RADIO_Obj.Set_MonoOrStereoBlendReq(m_cbFMReceiver_Setting_StereoBlend->ItemIndex);
            parameter.first = FM_PARAMETER_MONO_STEREO_BLEND;
            parameter.second= AnsiString("Set Mono Or Stereo");
            m_vParameter.push_back(parameter);

            // softmute
            /*
            audio.s_soft_mute_onoff.m_bOnOff = m_cbFMReceiver_Setting_SoftMute->ItemIndex;
            */
            m_cFM_RADIO_Obj.Set_SoftmuteReq(m_cbFMReceiver_Setting_SoftMute->ItemIndex);
            parameter.first = FM_PARAMETER_SET_SOFTMUTE;
            parameter.second= AnsiString("Set Softmute");
            m_vParameter.push_back(parameter);

            // stereo blend stage
            /*
            audio.s_stereo_blend_level.m_ucStage = m_cbFMReceiver_Setting_StereoBlendLevel->ItemIndex + 1;
            */
            m_cFM_RADIO_Obj.Set_StereoBlendStageReq(m_cbFMReceiver_Setting_StereoBlendLevel->ItemIndex + 1);
            parameter.first = FM_PARAMETER_STEREO_BLEND_STAGE;
            parameter.second= AnsiString("Set Stereo Blend Stage");
            m_vParameter.push_back(parameter);
            m_iterParameter = m_vParameter.begin();

            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Setting parameter progressing";
            //CurrentPageLock();
            m_FMReceiverLocker.Lock();
            ParameterSetting();
        }
        else if(m_sFMChipId.m_ucChipId ==FM_CHIP_ID_MT6620)
        {
            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Setting parameter progressing";
            //CurrentPageLock();
            m_FMReceiverLocker.Lock();
            ParameterSettingMT6620("MT6620.xml");
        }
    }

}
//---------------------------------------------------------------------------
void TfrmFM::ParameterSettingMT6620(AnsiString xmlFile)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_ParameterSettingMT6620;
    FM_SETStatus_REQ_T req;
    req.DECODE_MODE = m_cbFMReceiver_Setting_DecodeMode->ItemIndex;
    req.STEREO_BLEND = m_cbFMReceiver_Setting_StereoBlend->ItemIndex;
    req.HCC = m_cbFMReceiver_Setting_HCC->ItemIndex;
    req.PAMD_THRESHOLD =  m_edtFMReceiver_Setting_PAMDThreshold->Text.ToInt();
    req.RSSI_THRESHOLD = m_edtFMReceiver_Setting_RSSIThreshold->Text.ToInt();
    req.SOFTMUTE=m_cbFMReceiver_Setting_SoftMute->ItemIndex;
    req.CAP_ARRAY = edtFMCapArray->Text.ToInt();
    req.DE_EMPHASIS_LEV = m_cbFMReceiver_Setting_De_emphasisLevel->ItemIndex;
    req.HL_SIDE = m_cbFMReceiver_Setting_HLSide->ItemIndex;
    req.DEMOD_BANDWIDTH = m_cbFMReceiver_Setting_DemodBandwidth->ItemIndex;
    req.DYNAMIC_LIMITER = m_cbFMReceiver_Setting_DynamicLimiter->ItemIndex;
    req.SOFTMUTE_RATE = m_edtFMReceiver_Setting_SoftMuteRate->Text.ToInt();
    req.DEMOD_TYPE = cbFMDemodType->ItemIndex;
    m_cFM_RADIO_Obj.REQ_FM_SET_PARAMETER_Start(xmlFile,req);

}
void TfrmFM::ParameterSetting(void)
{
    // same mechanism from update parameter
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_ParameterSetting;
    if (m_iterParameter == m_vParameter.end())
    {
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Setting parameter done";
        //CurrentPageReset();
        m_FMReceiverLocker.Unlock();
        return;
    }
    switch(m_iterParameter->first)
    {
    case FM_PARAMETER_DECODE_MODE:
        m_cFM_RADIO_Obj.REQ_FM_Set_DecodeMode_Start();
        break;
    case FM_PARAMETER_DEEMPHASIS_LEVEL:
        m_cFM_RADIO_Obj.REQ_FM_Set_DeemphasisLevel_Start();
        break;
    case FM_PARAMETER_STEREO_BLEND:
        m_cFM_RADIO_Obj.REQ_FM_Set_StereoBlend_Start();
        break;
    case FM_PARAMETER_HL_SIDE:
        m_cFM_RADIO_Obj.REQ_FM_Set_HLSide_Start();
        break;
    case FM_PARAMETER_HCC:
        m_cFM_RADIO_Obj.REQ_FM_Set_HCC_Start();
        break;
    case FM_PARAMETER_DEMOD_BW:
        m_cFM_RADIO_Obj.REQ_FM_Set_DemodBandwidth_Start();
        break;
    case FM_PARAMETER_PAMD_THRESHOLD:
        m_cFM_RADIO_Obj.REQ_FM_Set_PAMDThreshold_Start();
        break;
    case FM_PARAMETER_DYNAMIC_LIMITER:
        m_cFM_RADIO_Obj.REQ_FM_Set_DynamicLimiter_Start();
        break;
    case FM_PARAMETER_RSSI_THRESHOLD:
        m_cFM_RADIO_Obj.REQ_FM_Set_RSSIThreshold_Start();
        break;
    case FM_PARAMETER_SOFTMUTE_RATE:
        m_cFM_RADIO_Obj.REQ_FM_Set_SoftmuteRate_Start();
        break;
    case FM_PARAMETER_SOFTMUTE_ENABLE:
        m_cFM_RADIO_Obj.REQ_FM_Set_SoftmuteEnable_Start();
        break;
    case FM_PARAMETER_SET_SOFTMUTE:
        m_cFM_RADIO_Obj.REQ_FM_Set_Softmute_Start();
        break;
    case FM_PARAMETER_MONO_STEREO_BLEND:
        m_cFM_RADIO_Obj.REQ_FM_Set_MonoOrStereoBlend_Start();
        break;
    case FM_PARAMETER_STEREO_BLEND_STAGE:
        m_cFM_RADIO_Obj.REQ_FM_Set_StereoBlendStage_Start();
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmFM::ParameterSettingDone(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    //AnsiString as_msg = Get_DisplayMessagePrefix();
    switch (state)
    {
    case META_SUCCESS:
        m_iterParameter++;
        ParameterSetting();
        break;

    default:
        CNF_ErrorHandler(m_iterParameter->second, state, m_sbFMReceiver);
        // for the parameter setting test!!
        m_iterParameter++;
        ParameterSetting();
        //CurrentPageReset();
        break;
    }
    m_FMReceiverLocker.Unlock();
}



void __fastcall TfrmFM::m_btnFMRXStatusUpdateClick(TObject *Sender)
{
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
    if(version == 1 || version == 0)
    {
        if((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6616))
        {
            // new chip
            m_vStatus.clear();
            status_pair status;
            status.first = FM_STATUS_PARAMETER_BW;
            status.second= AnsiString("Get RxFilter BW");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_PAMD;
            status.second= AnsiString("Get PAMD");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_MR;
            status.second= AnsiString("Get MR");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_RSSI;
            status.second= AnsiString("Get RSSI");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_STEREO;
            status.second= AnsiString("Get Stereo Or Mono");
            m_vStatus.push_back(status);
            m_iterStatus = m_vStatus.begin();
            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status progressing";
            //CurrentPageLock();
            StatusUpdate();

        }
        else if(((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189AN)    ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6189BN_CN) ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188A)     ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188C)     ||
                 (m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6188D)))
        {
            // old chips
            m_vStatus.clear();
            status_pair status;
            status.first = FM_STATUS_PARAMETER_RSSI;
            status.second= AnsiString("Get RSSI");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_STEREO;
            status.second= AnsiString("Get Stereo Or Mono");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_IF_COUNTER;
            status.second= AnsiString("Get IF counter");
            m_vStatus.push_back(status);
            status.first = FM_STATUS_PARAMETER_HL_SIDE;
            status.second= AnsiString("Get HL Side");
            m_vStatus.push_back(status);
            m_iterStatus = m_vStatus.begin();
            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status progressing";
            //CurrentPageLock();
            StatusUpdate();
        }
        else if((m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6620))
        {
            /*m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status progressing";
            CurrentPageLock();
            FMStatusUpdate("MT6620.xml");
            */
            int RSSI;
            int RSSIdBm;
            char str[256]= {0};
            RSSI = ReadRegister(0xE8,0,0,9);
            if(RSSI == -1)
            {
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }
            m_stFMReceiver_Status_RSSI->Caption = RSSI;
            sprintf(str,"%04lx",RSSI);
            stFMRSSIhex->Caption = str;
            if(RSSI>511)
            {
                RSSIdBm = (RSSI-1024)*6/16;
            }
            else
            {
                RSSIdBm = RSSI*6/16;
            }
            stFMRSSIdbm->Caption = RSSIdBm;

            int STEREO_MONO;
            STEREO_MONO = ReadRegister(0xE8,1,10,10);
            if(STEREO_MONO == 0)
            {
                m_stFMReceiver_Status_Stereo_Mono->Caption = "Stereo";
            }
            else
            {
                m_stFMReceiver_Status_Stereo_Mono->Caption = "Mono";
            }
//rongguo 2011-06-08
            /*            int CAP_ARRAY;
                        CAP_ARRAY = ReadRegister(0x2F,0,5,14);
                        CAP_ARRAY = 0x3FF;
                        memset(str,'\0',256);
                        itoa(CAP_ARRAY, str, 2);
                        int i = CAP_ARRAY;
                        double cap;
                        if(str[0]==1)
                        {
                            cap = 0.166;
                        }
                        if(str[1]==1)
                        {
                            cap += 0.332;
                        }
                        if(str[2]==1)
                        {
                            cap += 0.664;
                        }
                        if(str[3]==1)
                        {
                            cap += 1.33;
                        }
                        if(str[4]==1)
                        {
                            cap += 2.66;
                        }
                        if(str[5]==1)
                        {
                            cap += 5.31;
                        }
                        if(str[6]==1)
                        {
                            cap += 10.6;
                        }
                        if(str[7]==1)
                        {
                            cap += 18.6;
                        } */
//rongguo 2011-07-04
            int CAP_ARRAY;
            CAP_ARRAY = ReadRegister(0x26, 1, 6, 14);
            double cap;
            cap = ((CAP_ARRAY >> 6) & 0x0001) * 0.166 +
                  ((CAP_ARRAY >> 7) & 0x0001) * 0.332 +
                  ((CAP_ARRAY >> 8) & 0x0001) * 0.664 +
                  ((CAP_ARRAY >> 9) & 0x0001) * 1.33 +
                  ((CAP_ARRAY >> 10) & 0x0001) * 2.66 +
                  ((CAP_ARRAY >> 11) & 0x0001) * 5.31 +
                  ((CAP_ARRAY >> 12) & 0x0001) * 10.6 +
                  ((CAP_ARRAY >> 13) & 0x0001) * 18.6;

            stCapArray->Caption = Double_To_AnsiString(cap);
            stCapRegValue->Caption = Double_To_AnsiString(CAP_ARRAY);
        }
        else
        {
            //RSSI
            FM_FREQ_REQ_T fm_freq_req;
            FM_RSSI_CNF_T fm_rssi_cnf;

            memset(&fm_freq_req, 0, sizeof(fm_freq_req));
            //fm_freq_req.m_i2CurFreq = m_RXCurrentFrequency / FM_FREQ_SCALE;
            if( m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
            {
                fm_freq_req.m_i2CurFreq = m_RXCurrentFrequency / FM_FREQ_SCALE_50KHZ;
            }
            else
            {
                fm_freq_req.m_i2CurFreq = m_RXCurrentFrequency / FM_FREQ_SCALE_100KHZ;
            }

            META_RESULT MetaResult = SP_META_FM_GetRSSI_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &fm_freq_req, &fm_rssi_cnf);
            if(META_SUCCESS != MetaResult)
            {
                Output_FM_ErrorHandler("Get RSSI", MetaResult, m_sbFMReceiver);
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }
            stFMRSSIdbm->Caption = fm_rssi_cnf.m_ucSignalLevel;
            m_sbFMReceiver->Panels->Items[0]->Text =(AnsiString)" Get RSSI successful";

            //Stereo / Mono
            FM_Stereo_Mono_CNF_T fm_stereo_mono_cnf;

            MetaResult = SP_META_FM_GetStereoOrMono_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &fm_stereo_mono_cnf);
            if(META_SUCCESS != MetaResult)
            {
                Output_FM_ErrorHandler("Get Stereo/Mono", MetaResult, m_sbFMReceiver);
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }
            if(fm_stereo_mono_cnf.m_ucStereoOrMono == 0)
            {
                m_stFMReceiver_Status_Stereo_Mono->Caption = "Mono";
            }
            else if(fm_stereo_mono_cnf.m_ucStereoOrMono == 1)
            {
                m_stFMReceiver_Status_Stereo_Mono->Caption = "Stereo";
            }
            else
            {
//                Application->MessageBox("Stereo/Mono value wrong!", "ERROR", MB_OK );
//                return;
            }
            m_sbFMReceiver->Panels->Items[0]->Text =(AnsiString)" Get Stereo/Mono successful";

            //CapArray
            FM_CapArray_CNF_T fm_caparray_cnf;

            MetaResult = SP_META_FM_GetCapArray_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &fm_caparray_cnf);
            if(META_SUCCESS != MetaResult)
            {
                Output_FM_ErrorHandler("Get Cap Array", MetaResult, m_sbFMReceiver);
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }
            stCapRegValue->Caption = Double_To_AnsiString(fm_caparray_cnf.m_uCapArray);
            double cap;
            if( m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6626 )
            {
                cap = ((fm_caparray_cnf.m_uCapArray >> 8) & 0x0001) * 0.166 +
                      ((fm_caparray_cnf.m_uCapArray >> 9) & 0x0001) * 0.332 +
                      ((fm_caparray_cnf.m_uCapArray >> 10) & 0x0001) * 0.664 +
                      ((fm_caparray_cnf.m_uCapArray >> 11) & 0x0001) * 1.33 +
                      ((fm_caparray_cnf.m_uCapArray >> 12) & 0x0001) * 2.66 +
                      ((fm_caparray_cnf.m_uCapArray >> 13) & 0x0001) * 5.31 +
                      ((fm_caparray_cnf.m_uCapArray >> 14) & 0x0001) * 10.6 +
                      ((fm_caparray_cnf.m_uCapArray >> 15) & 0x0001) * 21.2;
            }
            if( m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6628 )
            {
                cap = ((fm_caparray_cnf.m_uCapArray >> 6) & 0x0001) * 0.166 +
                      ((fm_caparray_cnf.m_uCapArray >> 7) & 0x0001) * 0.332 +
                      ((fm_caparray_cnf.m_uCapArray >> 8) & 0x0001) * 0.664 +
                      ((fm_caparray_cnf.m_uCapArray >> 9) & 0x0001) * 1.33 +
                      ((fm_caparray_cnf.m_uCapArray >> 10) & 0x0001) * 2.66 +
                      ((fm_caparray_cnf.m_uCapArray >> 11) & 0x0001) * 5.31 +
                      ((fm_caparray_cnf.m_uCapArray >> 12) & 0x0001) * 10.6 +
                      ((fm_caparray_cnf.m_uCapArray >> 13) & 0x0001) * 21.2;
            }

            if( m_sFMChipId.m_ucChipId == FM_CHIP_ID_MT6630 )
            {
                 cap = 8 + 0.0925*(fm_caparray_cnf.m_uCapArray);
            }

            stCapArray->Caption = Double_To_AnsiString(cap);
            m_sbFMReceiver->Panels->Items[0]->Text =(AnsiString)" Get CapArray successful";
        }
    }
    //CurrentPageReset();
    m_FMReceiverLocker.Unlock();
}
int TfrmFM::ReadRegister(unsigned char addr,unsigned short page,int sb,int eb)
{
    META_RESULT MetaResult;
    FM_WRITE_BYTE_REQ_T byte;
    FM_READ_BYTE_ADDR_REQ_T  readByte;
    FM_READ_BYTE_CNF_T confByte;

    //Step1
    byte.m_ucAddr = 0x9f;
    byte.m_u2WriteByte = page;

    MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);

    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Set Page ");
        return -1;
    }

    //Step2
    readByte.m_ucAddr =  addr;
    MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Read Register");
        return -1;
    }

    //Step3
    unsigned short temp=0;

    unsigned short result=0;

    int i=eb-sb+1;

    for (int j=0; j<i; j++)
    {
        temp=(temp<<1)+1;
    }

    temp = temp<<sb;

    result = (confByte.m_u2ReadByte) & temp;

    return result;

}

void TfrmFM::FMStatusUpdate(AnsiString xmlFileName)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_StatusUpdateMT6620;
    m_cFM_RADIO_Obj.REQ_FM_GET_STATUS_Start(xmlFileName);
}
//---------------------------------------------------------------------------
void TfrmFM::StatusUpdate(void)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_StatusUpdate;
    if (m_iterStatus == m_vStatus.end())
    {
        S_FM_STATUS_T* p_fm_status = m_cFM_RADIO_Obj.Get_FMStatus();
        m_sStatus = *p_fm_status;
        ReDrawFields(DRAW_FM_STATUS);
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status done";
        //CurrentPageReset();
        m_FMReceiverLocker.Unlock();
    }
    switch(m_iterStatus->first)
    {
    case FM_STATUS_PARAMETER_RSSI:
        m_cFM_RADIO_Obj.REQ_FM_Get_RSSI_Start();
        break;
    case FM_STATUS_PARAMETER_BW:
        m_cFM_RADIO_Obj.REQ_FM_Get_RXFilterBW_Start();
        break;
    case FM_STATUS_PARAMETER_PAMD:
        m_cFM_RADIO_Obj.REQ_FM_Get_PAMDLevel_Start();
        break;
    case FM_STATUS_PARAMETER_MR:
        m_cFM_RADIO_Obj.REQ_FM_Get_MR_Start();
        break;
    case FM_STATUS_PARAMETER_STEREO:
        m_cFM_RADIO_Obj.REQ_FM_Get_Stereo_Start();
        break;
    case FM_STATUS_PARAMETER_IF_COUNTER:
        m_cFM_RADIO_Obj.REQ_FM_Get_IFCounter_Start();
        break;
    case FM_STATUS_PARAMETER_HL_SIDE:
        m_cFM_RADIO_Obj.REQ_FM_Get_HLSide_Start();
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_StatusUpdate(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    //AnsiString as_msg = Get_DisplayMessagePrefix();
    switch (state)
    {
    case META_SUCCESS:
        m_iterStatus++;
        StatusUpdate();
        break;

    default:
        CNF_ErrorHandler(m_iterStatus->second, state, m_sbFMReceiver);
        //CurrentPageReset();
        m_FMReceiverLocker.Unlock();
        break;
    }
}
//---------------------------------------------------------------------------

void TfrmFM::CNF_ParameterSettingMT6620(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status Success";
        //CurrentPageReset();
        break;

    default:
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status Fail";
        //CurrentPageReset();
        break;
    }
    m_FMReceiverLocker.Unlock();
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_StatusUpdateMT6620(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();
    //AnsiString as_msg = Get_DisplayMessagePrefix();
    switch (state)
    {
    case META_SUCCESS:
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status Success";
        cnf = m_cFM_RADIO_Obj.REQ_FM_GetStatusMT6620();
        ReDrawFields(DRAW_FM_STATUS_MT6620);
        //CurrentPageReset();
        break;
    default:
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Update Status Fail";
        //CurrentPageReset();
        break;
    }
    m_FMReceiverLocker.Unlock();
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::CounterTimerTimer(TObject *Sender)
{
    CounterTimer->Enabled = false;
    m_eRdsCounter = FM_RDS_GOOD_BLOCK_COUNTER;
    CounterUpdate();
}
//---------------------------------------------------------------------------

void TfrmFM::CounterUpdate(void)
{
    m_cFM_RDS_Obj.ConfirmCallback = ::CNF_CounterUpdate;
    // 20100320 if the tag is not 1, means the timer stopped but the confirm is back
    // do not process the counter update anymore!!
    if(CounterTimer->Tag == 0)
    {
        return;
    }
    switch(m_eRdsCounter)
    {
    case FM_RDS_GOOD_BLOCK_COUNTER:
        m_cFM_RDS_Obj.REQ_FM_RDS_Get_GoodBlockCounter_Start();
        break;
    case FM_RDS_BAD_BLOCK_COUNTER:
        m_cFM_RDS_Obj.REQ_FM_RDS_Get_BadBlockCounter_Start();
        break;
    case FM_RDS_GROUP_COUNTER:
        m_cFM_RDS_Obj.REQ_FM_RDS_Get_GroupCounter_Start();
        break;
    case FM_RDS_BLER:
        m_cFM_RDS_Obj.REQ_FM_RDS_Get_RDSBLERRatio_Start();
        break;
    case FM_RDS_RDSLOG:
        m_cFM_RDS_Obj.REQ_FM_RDS_Get_RDSLogData_Start();
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_CounterUpdate(void)
{
    META_RESULT state = m_cFM_RDS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        m_eRdsCounter++;
        if (m_eRdsCounter >= FM_RDS_COUNTER_COUNT)
        {
            m_sRDSGoodBlockCounter = m_cFM_RDS_Obj.Get_FM_RDS_GoodBlockCounter();
            m_sRDSBadBlockCounter = m_cFM_RDS_Obj.Get_FM_RDS_BadBlockCounter();
            m_sRDSGroupCounter = m_cFM_RDS_Obj.Get_FM_RDS_GroupCounter();
            m_u2BLER = m_cFM_RDS_Obj.Get_FM_RDS_BLER();
            FM_RDS_LOGDATA_T * rdslog = m_cFM_RDS_Obj.Get_FM_RDS_LogData();

            memcpy(&m_sRDSLogData,rdslog,sizeof(m_sRDSLogData));
            PostMessage(this->Handle,WM_ML_FM_RDS_COUNTER_UPDATE_MSG,0,0);
            CounterTimer->Enabled = true;
        }
        else
        {
            CounterUpdate();
        }
        break;
    default:
        CNF_ErrorHandler("Counter Update", state, m_sbFMReceiver);
        break;
    }
}
//---------------------------------------------------------------------------
void _fastcall TfrmFM::SubClassWndProc( Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
    case WM_ML_FM_RDS_INFO_UPDATE:
    {
        FM_RDS_Info_CNF_T* info = (FM_RDS_Info_CNF_T*) Message.WParam;
        RdsEvent e = (RdsEvent)Message.LParam;
        m_sRDSInfo = *info;
        ReDrawRDSFields(e);
        break;
    }
    case WM_ML_FM_RDS_STATUS_UPDATE:
    {
        FM_RDS_Status_CNF_T* status = (FM_RDS_Status_CNF_T*) Message.WParam;
        RdsEvent e = (RdsEvent)Message.LParam;
        m_sRDSStatus = *status;
        ReDrawRDSFields(e);
        break;
    }
    case WM_ML_FM_RDS_COUNTER_UPDATE:
    {
        DealCounterUpdate();
        break;
    }
    case WM_ML_FM_RDS_COUNTER_UPDATE_MSG:
    {
        ReDrawFields(DRAW_FM_RDS_BLOCK_COUNTER | DRAW_FM_RDS_GROUP_COUNTER);
        break;
    }
    case WM_ML_FM_RDSON_SUCCESS_MSG:
    {
        // set block counter timer be true
        CounterTimer->Enabled = true;
        CounterTimer->Tag = 1;
        m_btnFMRXRDSOn->Tag = 1;
        m_btnFMRDS_RDSOn->Tag = 1;

        m_btnFMRXRDSOff->Enabled = true;
        m_btnFMRDS_RDSOff->Enabled = true;
//rongguo 2011-06-24
        m_btnFMRDS_BlockCounterReset->Enabled = true;
        m_btnFMRDS_GroupCounterReset->Enabled = true;

        TxMainUIControl(FM_TX_MAIN_UICONTROL_RDSOFF | FM_TX_MAIN_UICONTROL_OTHERS | FM_TX_MAIN_UICONTROL_RESET);
        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  RDS On successful";
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  RDS On successful";
        break;
    }
    case WM_ML_FM_BLOCKCOUNTER_RESET_MSG:
    {
        ReDrawFields(DRAW_FM_RDS_BLOCK_COUNTER);
        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset block counter successfully";
        break;
    }
    case WM_ML_FM_GROUPCOUNTER_RESET_MSG:
    {
        ReDrawFields(DRAW_FM_RDS_GROUP_COUNTER);
        m_sbFMRDS->Panels->Items[0]->Text = (AnsiString)"  Reset group counter successfully";
        break;
    }
    default:
        this->WndProc( Message );
        break;
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::m_cbFMReceiver_ChannelListChange(TObject *Sender)
{
    m_edtFMReceiver_ChannelSelect->Text = IntToStr(m_cbFMReceiver_ChannelList->ItemIndex);
    AnsiString str1 = m_cbFMReceiver_ChannelList->Items->Strings[m_cbFMReceiver_ChannelList->ItemIndex];
    char * str = str1.c_str();
    if(NULL == strchr(str, ':'))
    {
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Channel select fail!";
        Application->MessageBox("Execution Failure : Channel select", "FAILURE", MB_OK );
    }
    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        m_tbFMReceiver_Frequency->Position = (atof(strchr(str, ':') + 2) * 100)/5;
    }
    else
    {
        m_tbFMReceiver_Frequency->Position = atof(strchr(str, ':') + 2) * 10;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_edtFMReceiver_ChannelSelectExit(TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    AnsiString hint;
    short channel;
    if(m_cbFMReceiver_ChannelList->Items->Count > 1)
    {
        hint = " Channel No. should between 0 ~ " + IntToStr(m_cbFMReceiver_ChannelList->Items->Count-1);
        if(!IsValidFMChannel(edit->Text, channel))
        {
            ShowHintLabel(edit, hint.c_str());
            edit->SetFocus();
            return;
        }
        if(edit->Text.ToInt() < 0 || edit->Text.ToInt() >= m_cbFMReceiver_ChannelList->Items->Count)
        {
            ShowHintLabel(edit, hint.c_str());
            edit->SetFocus();
        }
    }
    return;
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_btnFMRXSetVolumeClick(TObject *Sender)
{
    // 20100414: digital gain index
    m_cFM_RADIO_Obj.Set_VolumeSettingReq(255 - m_tbFMReceiver_Volume->Position, 0);
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_Set_Volume;
    m_cFM_RADIO_Obj.REQ_FM_Set_Volume_Start();

    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Volume Setting progressing";
    m_FMReceiverLocker.Lock();
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_Set_Volume(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // new
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Volume Setting successfully";
    }
    break;

    default:
        CNF_ErrorHandler("Volume Setting", state, m_sbFMReceiver);
        break;
    }
    //CurrentPageReset();
    m_FMReceiverLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXGoChannelClick(TObject *Sender)
{
    m_cbFMReceiver_ChannelList->ItemIndex = m_edtFMReceiver_ChannelSelect->Text.ToInt();
//rongguo 2011-06-09
    AnsiString str1 = m_cbFMReceiver_ChannelList->Items->Strings[m_cbFMReceiver_ChannelList->ItemIndex];
    char * str = str1.c_str();
    if(NULL == strchr(str, ':'))
    {
        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Channel select fail!";
        Application->MessageBox("Execution Failure : Channel select", "FAILURE", MB_OK );
        return;
    }
    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        m_tbFMReceiver_Frequency->Position = (atof(strchr(str, ':') + 2) * 100)/5;
    }
    else
    {
        m_tbFMReceiver_Frequency->Position = atof(strchr(str, ':') + 2) * 10;
    }
//    m_tbFMReceiver_Frequency->Position = m_cbFMReceiver_ChannelList->Items->Strings[m_cbFMReceiver_ChannelList->ItemIndex].ToDouble()*10;
    m_btnFMRXSetFrequencyClick(Sender);
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb)
{
    switch (state)
    {
    case META_FAILED:
    {
        // new
        sb->Panels->Items[0]->Text = message + " failed";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        // new
        sb->Panels->Items[0]->Text = message+ " timeout";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "TIMEOUT", MB_OK );
    }
    break;

    case METAAPP_STOP:
    {
        // new
        sb->Panels->Items[0]->Text = message + " stop";
    }
    break;

    default:
    {
    }
    break;
    }
}


void TfrmFM::Output_FM_ErrorHandler(AnsiString message, META_RESULT state, TStatusBar* sb)
{
    switch (state)
    {
    case META_FAILED:
    {
        // new
        sb->Panels->Items[0]->Text = message + " failed";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "FAILURE", MB_OK );
    }
    break;

    case META_TIMEOUT:
    {
        // new
        sb->Panels->Items[0]->Text = message+ " timeout";
        Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "TIMEOUT", MB_OK );
    }
    break;
    default:
    {
        // new
        //sb->Panels->Items[0]->Text = message+ " other error";
        //Application->MessageBox(sb->Panels->Items[0]->Text.c_str(), "OTHER ERROR", MB_OK );
    }
    break;
    }
}

void __fastcall TfrmFM::m_tbFMReceiver_FrequencyKeyDown(TObject *Sender,
        WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        m_btnFMRXSetFrequencyClick(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_edtFMRegister_AddressExit(TObject *Sender)
{
    AnsiString  text;
    //short freq;
    TEdit *edit = (TEdit*)Sender;
    char * hint = "input is invalid";
    text = edit->Text;
    if (!AnsiString_Hex_To_UnsignedChar(m_edtFMRegister_Address->Text, m_ucAddr ))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_edtFMReceiver_WordExit(TObject *Sender)
{
    AnsiString  text;
    //short freq;
    TEdit *edit = (TEdit*)Sender;
    char * hint = "input is invalid";
    text = edit->Text;
    if (!AnsiString_Hex_To_UnsignedInt(m_edtFMRegister_Address->Text, &m_u4Data ))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_tbFMReceiver_VolumeKeyDown(TObject *Sender,
        WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        m_btnFMRXSetVolumeClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_edtFMReceiver_CurrentFrequencyKeyDown(
    TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        m_btnFMRXSetFrequencyClick(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::m_edtRDSQueryTimerExit(TObject *Sender)
{
    // limit the range
    AnsiString  text;
    unsigned short interval;
    TEdit *edit = (TEdit*)Sender;
    char * hint = "input is invalid (should be 1000 ~ 60000)";
    text = edit->Text;
    if (!AnsiString_To_UnsignedShort(m_edtRDSQueryTimer->Text, interval, 1000, 60000))
    {
        ShowHintLabel(edit, hint);
        edit->SetFocus();
        m_edtRDSQueryTimer->Text = IntToStr(3000);
        return;
    }
    CounterTimer->Interval = interval;
}
//---------------------------------------------------------------------------
void TfrmFM::ClearRDSUIData(void)
{
    // clear RDS log data
    m_stFMReceiver_RDSData_PS->Caption = "";
    m_stFMReceiver_RDSData_RT->Caption = "";
    m_cbxAFList->Items->Clear();
    m_richedtRDSLog->Lines->Clear();
    m_stRDSData_RDS_PS->Caption = "";
    m_stRDSData_RDS_PTY->Caption = "";
    m_stRDSData_RDS_PI->Caption = "";
    m_stRDSData_RDS_RT->Caption = "";
    m_stRDSData_RDS_CT->Caption = "";
    m_stRDSData_RDS_TA->Caption = "";
    m_stRDSData_RDS_RDSSYNC->Caption = "";
    m_stRDSData_RDS_RTDISPLAY->Caption = "";
    m_stRDSData_RDS_PSDISPLAY->Caption = "";
    m_stRDSData_BlockCounter_Accepted->Caption = "";
    m_stRDSData_BlockCounter_Errors->Caption = "";
    m_stRDSData_BlockCounter_TotalRecv->Caption = "";
    m_stRDSData_BlockCounter_BLER->Caption = "";
    m_stRDSData_GroupCounter_0A->Caption = "";
    m_stRDSData_GroupCounter_0B->Caption = "";
    m_stRDSData_GroupCounter_1A->Caption = "";
    m_stRDSData_GroupCounter_1B->Caption = "";
    m_stRDSData_GroupCounter_2A->Caption = "";
    m_stRDSData_GroupCounter_2B->Caption = "";
    m_stRDSData_GroupCounter_3A->Caption = "";
    m_stRDSData_GroupCounter_3B->Caption = "";
    m_stRDSData_GroupCounter_4A->Caption = "";
    m_stRDSData_GroupCounter_4B->Caption = "";
    m_stRDSData_GroupCounter_5A->Caption = "";
    m_stRDSData_GroupCounter_5B->Caption = "";
    m_stRDSData_GroupCounter_6A->Caption = "";
    m_stRDSData_GroupCounter_6B->Caption = "";
    m_stRDSData_GroupCounter_7A->Caption = "";
    m_stRDSData_GroupCounter_7B->Caption = "";
    m_stRDSData_GroupCounter_8A->Caption = "";
    m_stRDSData_GroupCounter_8B->Caption = "";
    m_stRDSData_GroupCounter_9A->Caption = "";
    m_stRDSData_GroupCounter_9B->Caption = "";
    m_stRDSData_GroupCounter_10A->Caption = "";
    m_stRDSData_GroupCounter_10B->Caption = "";
    m_stRDSData_GroupCounter_11A->Caption = "";
    m_stRDSData_GroupCounter_11B->Caption = "";
    m_stRDSData_GroupCounter_12A->Caption = "";
    m_stRDSData_GroupCounter_12B->Caption = "";
    m_stRDSData_GroupCounter_13A->Caption = "";
    m_stRDSData_GroupCounter_13B->Caption = "";
    m_stRDSData_GroupCounter_14A->Caption = "";
    m_stRDSData_GroupCounter_14B->Caption = "";
    m_stRDSData_GroupCounter_15A->Caption = "";
    m_stRDSData_GroupCounter_15B->Caption = "";
//rongguo 2011-06-22
    m_stRDSData_GroupCounter_Total->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    //20100320
    CounterTimer->Enabled = false;
    CounterTimer->Tag = 0;


    /*
    // not yet powered on, some problem on target side, but the form can close
    if(frmFM->Tag == 0)
    {
        CanClose = true;
        return;
    }
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_PowerOff;
    m_cFM_RADIO_Obj.REQ_FM_Power_Off_Start();
    for(int i=0;i<100;i++)
    {
        if(frmFM->Tag == 0)
        {
            break;
        }
        Sleep(50);
    }
    */
    CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::ToggleHideExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;
    ApplyHideProperty();
}
//---------------------------------------------------------------------------
void TfrmFM::ApplyHideProperty(void)
{
//rongguo 2011-06-09
    /*    m_lblFMReceiver_Status_BW->Visible = !g_bHideEnable;
        m_stFMReceiver_Status_BW->Visible = !g_bHideEnable;
        m_lblFMReceiver_Status_PAMD->Visible = !g_bHideEnable;
        m_stFMReceiver_Status_PAMD->Visible = !g_bHideEnable;
        m_lblFMReceiver_Status_MR->Visible = !g_bHideEnable;
        m_stFMReceiver_Status_MR->Visible = !g_bHideEnable; */
    m_gbFMReceiver_RegisterRW->Visible = !g_bHideEnable;
    m_gbFMRDS_RDSLogData->Visible = !g_bHideEnable;
//rongguo 2011-07-04
//    Label60->Visible = !g_bHideEnable;
//    stCapArray->Visible = !g_bHideEnable;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnFMTxPowerOnOffClick(TObject *Sender)
{
    if(btnFMTxPowerOnOff->Caption == "TX Power On")
    {
        if(bFMRXPowerOn == true)
        {
            Application->MessageBox( "Please turn off RX.", "Fail", MB_OK );
            return;
        }
        //rongguo 2011-04-27
        m_FMTxLocker.Lock();
        ResetFMTransmitter();
        btnFMTxADRCSETClick(Sender);
//            btnFMSetTypeClick(Sender);

        m_cFM_TX_Obj.ConfirmCallback = ::CNF_FM_TxPowerOn;
        m_cFM_TX_Obj.REQ_FM_TxPowerOn_Start();
        m_sbFMTX->Panels->Items[0]->Text = (AnsiString)"FM TX Power On progressing";
        btnFMTxPowerOnOff->Caption = "TX Power Off";
        //rongguo 2011-04-20
        g_isPowerOnPressed = true;
//rongguo 2011-05-15
//            m_pgcFMRadio->Enabled = false;
    }
    else
    {
//rongguo 2011-07-22
        m_FMTxLocker.Lock();

        m_cFM_TX_Obj.ConfirmCallback = ::CNF_FM_TxPowerOff;
        m_cFM_TX_Obj.REQ_FM_TxPowerOff_Start();
        m_sbFMTX->Panels->Items[0]->Text = (AnsiString)"FM TX Power Off progressing";
        btnFMTxPowerOnOff->Caption = "TX Power On";
    }
}
//===========================================================================
void TfrmFM::CNF_FM_TxPowerOn(void)
{
    META_RESULT state = m_cFM_TX_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        // 20100320 for form close handling
        bFMTXPowerOn = true;
        frmFM->Tag = 1;
        m_sbFMTX->Panels->Items[0]->Text = (AnsiString)"  FM TX Power On successfully";
        btnFMTxPowerOnOff->Caption = "TX Power Off";

        //rongguo 2011-04-20
        if(true == g_isPowerOnPressed)
        {
            TObject *Sender = (TObject *)btnFMTxPowerOnOff;
            char key = VK_RETURN;
            edtFMTxRFFreqKeyPress(Sender, key);
        }
        else
        {
            m_FMTxLocker.Unlock();
            ResetFMTxUI(true);
//rongguo 2011-05-15
//                m_pgcFMRadio->Enabled = true;
        }
    }
    break;

    default:
    {
        CNF_ErrorHandler("FM TX Power On", state, m_sbFM);
        m_FMTxLocker.Unlock();
        ResetFMTxUI(true);
//rongguo 2011-05-15
//            m_pgcFMRadio->Enabled = true;
        m_sbFMTX->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
    }
    break;
    }
}

//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_TxPowerOff(void)
{
//rongguo 2011-07-22
    btnFMTxPowerOnOff->Enabled = true;

    META_RESULT state = m_cFM_TX_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
    {
        // 20100320 for form close handling
        bFMTXPowerOn = false;
        m_sbFMTX->Panels->Items[0]->Text = (AnsiString)"  FM TX Power Off successfully";
        btnFMTxPowerOnOff->Caption = "TX Power On";
        if(true == g_DisconnectFlag || true == g_CloseFlag)
        {
            PostMessage(hForm_MainForm, WM_FM_DISCONNECT_CLEAN_DONE, 2, 0);
        }
        //m_FMTxLocker.Unlock();
        ResetFMTxUI(false);

//rongguo 2011-07-22
//            CurrentPageReset();
    }
    break;

    default:
    {
        if(true == g_DisconnectFlag || true == g_CloseFlag)
        {
            PostMessage(hForm_MainForm, WM_FM_DISCONNECT_CLEAN_DONE, 3, 0);
        }
        CNF_ErrorHandler("FM TX Power Off", state, m_sbFM);
//rongguo 2011-07-22
//            CurrentPageReset();
        //m_FMTxLocker.Unlock();
        ResetFMTxUI(false);
        m_sbFMTX->Panels->Items[0]->Text = m_sbFM->Panels->Items[0]->Text;
    }
    break;
    }
    frmFM->Tag = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::edtFMTxRFFreqKeyPress(TObject *Sender, char &Key)
{
    if( Key == VK_RETURN ) // If the user presses the Enter key
    {

        if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
        {
            Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
            return;
        }

        FM_FREQ_REQ_T req;

        if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
        {
            AnsiString_To_FM_Freq_50KHz(edtFMTxRFFreq->Text, req.m_i2CurFreq);
        }
        else
        {
            AnsiString_To_FM_Freq(edtFMTxRFFreq->Text, req.m_i2CurFreq);
        }
        m_cFM_TX_Obj.ConfirmCallback = ::CNF_FM_SetFreq;
        m_cFM_TX_Obj.REQ_Set_Freq_Start(req);

        m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Set frequency progressing";
//        CurrentPageLock();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udFMTxRFFreqChanging(TObject *Sender,
        bool &AllowChange)
{
//rongguo 2011-07-04
//    edtFMTxRFFreq->Text = udFMTxRFFreq->Position/100.0;
    edtFMTxRFFreq->Text = udFMTxRFFreq->Position / 20.0;
    char key = VK_RETURN;
    edtFMTxRFFreqKeyPress(Sender, key);
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udFMTxRFlevelChanging(TObject *Sender,
        bool &AllowChange)
{
    edtFMTxRFlevel->Text = udFMTxRFlevel->Position;
//rongguo 2011-07-04
    char key = VK_RETURN;
    edtFMTxRFlevelKeyPress(Sender, key);
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtFMTxRFlevelKeyPress(TObject *Sender, char &Key)
{
    if( Key == VK_RETURN )
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte1;
        FM_WRITE_BYTE_REQ_T byte2;
        if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
        {
            Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
            return;
        }
        unsigned short addr1;
        unsigned short addr2;
        mt6620_FMTxRfLevel(edtFMTxRFlevel->Text.ToInt(),&addr1,&addr2);
        byte1.m_ucAddr = 0x3c;
        byte1.m_u2WriteByte = addr1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte1);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RF Level");
            return;
        }
        byte2.m_ucAddr = 0x3d;
        byte2.m_u2WriteByte = addr2;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte2);
        CNF_FM_WriteAddr(MetaResult,"Set RF Level");
    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtFMTxAudioDeviationKeyPress(TObject *Sender,
        char &Key)
{
    if( Key == VK_RETURN )
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;

        if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
        {
            Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
            return;
        }
        unsigned short addr1;
        unsigned short addr2;
        unsigned short addr3;
        unsigned short addr4;
        unsigned short addr5;
        unsigned short addr6;
        unsigned short addr7;
        unsigned short addr8;

        if( (StrToFloat(edtFMTxAudioDeviation->Text) < 0) || (StrToFloat(edtFMTxAudioDeviation->Text) > 90))
        {
            Application->MessageBox( "Out of range", "Error",MB_OK);
            return;

        }
        unsigned int temp = StrToFloat(edtFMTxAudioDeviation->Text)*1000;

        mt6620_FMTxAudioDeviation(temp,&addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 0;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }

        byte.m_ucAddr = 0xAB;
        byte.m_u2WriteByte = addr1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xAC;
        byte.m_u2WriteByte = addr2;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xAD;
        byte.m_u2WriteByte = addr3;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xAE;
        byte.m_u2WriteByte = addr4;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xAF;
        byte.m_u2WriteByte = addr5;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xF4;
        byte.m_u2WriteByte = addr6;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xF5;
        byte.m_u2WriteByte = addr7;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }
        byte.m_ucAddr = 0xB1;
        byte.m_u2WriteByte = addr8;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");

        float fTotalValue =  StrToFloat(edtFMTxAudioDeviation->Text) +
                             ((cbFMTxPilotOn->ItemIndex==0)? 0 : StrToFloat(edtFMTxPilotDeviation->Text)) +
                             ((cbFMTxRDSOn->ItemIndex==0)?   0 : StrToFloat(edtFMTxRDSDeviation->Text));
        stFMTxTotalDeviation->Caption = FormatFloat("0.00",fTotalValue);
        if(fTotalValue > 75)
            stFMTxTotalDeviation->Font->Color = clRed;
        else
            stFMTxTotalDeviation->Font->Color = clWindowText;
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udFMTxAudioDeviationChanging(TObject *Sender,
        bool &AllowChange)
{
    edtFMTxAudioDeviation->Text =  udFMTxAudioDeviation->Position/100.0;
//rongguo 2011-07-06
    char key = VK_RETURN;
    edtFMTxAudioDeviationKeyPress(Sender, key);
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::udFMTxPilotDeviationChanging(TObject *Sender,
        bool &AllowChange)
{
    edtFMTxPilotDeviation->Text =  udFMTxPilotDeviation->Position/100.0;
//rongguo 2011-07-04
    char key = VK_RETURN;
    edtFMTxPilotDeviationKeyPress(Sender, key);
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udFMTxRDSDeviationChanging(TObject *Sender,
        bool &AllowChange)
{
    edtFMTxRDSDeviation->Text = udFMTxRDSDeviation->Position/1000.0;
//rongguo 2011-07-04
    char key = VK_RETURN;
    edtFMTxRDSDeviationKeyPress(Sender, key);
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udFMTxPilotFreqChanging(TObject *Sender,
        bool &AllowChange)
{
    edtFMTxPilotFreq->Text = udFMTxPilotFreq->Position/1000.0;
//rongguo 2011-07-04
    char key = VK_RETURN;
    edtFMTxPilotFreqKeyPress(Sender, key);
}
//---------------------------------------------------------------------------

void TfrmFM::CNF_FM_WriteAddr(META_RESULT state ,AnsiString text)
{

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbFMTX->Panels->Items[0]->Text =text + (AnsiString)" successfully";
    }
    break;

    default:
    {
        //CNF_ErrorHandler(text, state, m_sbFMTX);
        Output_FM_ErrorHandler(text, state, m_sbFMTX);
    }
    break;
    }
    //rongguo 2011-05-06
//;    CurrentPageReset();
}


void TfrmFM::CNF_FM_AudioSource(META_RESULT state ,AnsiString text)
{

    switch (state)
    {
    case META_SUCCESS:
    {
        m_sbFMTX->Panels->Items[0]->Text =text + (AnsiString)" successfully";
    }
    break;

    default:
    {
        //CNF_ErrorHandler(text, state, m_sbFMTX);
        Output_FM_ErrorHandler(text, state, m_sbFMTX);
    }
    break;
    }
    //CurrentPageReset();
    m_FMTxLocker.Unlock();
}

void __fastcall TfrmFM::edtFMTxPilotDeviationKeyPress(TObject *Sender,
        char &Key)
{
    if(Key == VK_RETURN)
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        if( (StrToFloat(edtFMTxPilotDeviation->Text) < 0) || (StrToFloat(edtFMTxPilotDeviation->Text) > 90))
        {
            Application->MessageBox( "Out of range", "Error",MB_OK);
            return;
        }
        unsigned short addr1;
        unsigned short addr2;
        unsigned short addr3;
        unsigned short addr4;
        unsigned short addr5;
        unsigned short addr6;
        unsigned short addr7;
        unsigned short addr8;
        if(cbFMTxPilotOn->ItemIndex==0)
        {
            mt6620_FMTxPilotDeviation(0 * 1000,&addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);
        }
        else
        {
            mt6620_FMTxPilotDeviation(StrToFloat(edtFMTxPilotDeviation->Text)*1000,&addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);
        }

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 0;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }

        byte.m_ucAddr = 0xAB;
        byte.m_u2WriteByte = addr1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xAC;
        byte.m_u2WriteByte = addr2;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xAD;
        byte.m_u2WriteByte = addr3;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xAE;
        byte.m_u2WriteByte = addr4;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xAF;
        byte.m_u2WriteByte = addr5;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xF4;
        byte.m_u2WriteByte = addr6;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xF5;
        byte.m_u2WriteByte = addr7;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");
            return;
        }

        byte.m_ucAddr = 0xB1;
        byte.m_u2WriteByte = addr8;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Pilot deviation");

        float fTotalValue =  StrToFloat(edtFMTxAudioDeviation->Text) +
                             ((cbFMTxPilotOn->ItemIndex==0)? 0 : StrToFloat(edtFMTxPilotDeviation->Text)) +
                             ((cbFMTxRDSOn->ItemIndex==0)? 0 : StrToFloat(edtFMTxRDSDeviation->Text));
        stFMTxTotalDeviation->Caption = FormatFloat("0.00",fTotalValue);
        if(fTotalValue > 75)
            stFMTxTotalDeviation->Font->Color = clRed;
        else
            stFMTxTotalDeviation->Font->Color = clWindowText;
    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtFMTxRDSDeviationKeyPress(TObject *Sender,
        char &Key)
{
    if( Key == VK_RETURN)
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        if( (StrToFloat(edtFMTxRDSDeviation->Text) < 0) || (StrToFloat(edtFMTxRDSDeviation->Text) > 7.5))
        {
            Application->MessageBox( "Out of range", "Error",MB_OK);
            return;
        }
        unsigned short addr1;
        unsigned short addr2;
        unsigned short addr3;
        unsigned short addr4;
        unsigned short addr5;
        unsigned short addr6;
        unsigned short addr7;
        unsigned short addr8;

        if(cbFMTxRDSOn->ItemIndex==0)
        {
            mt6620_FMTxRDSDeviation(0 * 1000,&addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);
        }
        else
        {
            mt6620_FMTxRDSDeviation(StrToFloat(edtFMTxRDSDeviation->Text)*1000,&addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);
        }

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 0;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }

        byte.m_ucAddr = 0xAB;
        byte.m_u2WriteByte = addr1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xAC;
        byte.m_u2WriteByte = addr2;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xAD;
        byte.m_u2WriteByte = addr3;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xAE;
        byte.m_u2WriteByte = addr4;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xAF;
        byte.m_u2WriteByte = addr5;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xF4;
        byte.m_u2WriteByte = addr6;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xF5;
        byte.m_u2WriteByte = addr7;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");
            return;
        }
        byte.m_ucAddr = 0xB1;
        byte.m_u2WriteByte = addr8;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set RDS deviation");

        float fTotalValue =  StrToFloat(edtFMTxAudioDeviation->Text) +
                             ((cbFMTxPilotOn->ItemIndex==0)? 0 : StrToFloat(edtFMTxPilotDeviation->Text)) +
                             ((cbFMTxRDSOn->ItemIndex==0)?   0 : StrToFloat(edtFMTxRDSDeviation->Text));
        stFMTxTotalDeviation->Caption = FormatFloat("0.00",fTotalValue);
        if(fTotalValue > 75)
            stFMTxTotalDeviation->Font->Color = clRed;
        else
            stFMTxTotalDeviation->Font->Color = clWindowText;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::cbFMTxStereoMonoEnableKeyPress(TObject *Sender,
        char &Key)
{
    if( Key == VK_RETURN)
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        unsigned short addr1;
        unsigned short addr2;
        unsigned short addr3;
        unsigned short addr4;
        unsigned short addr5;
        unsigned short addr6;
        unsigned short addr7;
        unsigned short addr8;
        mt6620_FMTxStereo( cbFMTxStereoMonoEnable->ItemIndex , &addr1,&addr2,&addr3,&addr4,&addr5,&addr6,&addr7,&addr8);

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 0;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Audio deviation");
            return;
        }

        byte.m_ucAddr = 0xAB;
        byte.m_u2WriteByte = addr1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xAC;
        byte.m_u2WriteByte = addr2;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xAD;
        byte.m_u2WriteByte = addr3;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xAE;
        byte.m_u2WriteByte = addr4;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xAF;
        byte.m_u2WriteByte = addr5;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xF4;
        byte.m_u2WriteByte = addr6;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xF5;
        byte.m_u2WriteByte = addr7;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
            return;
        }

        byte.m_ucAddr = 0xB1;
        byte.m_u2WriteByte = addr8;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Stereo/Mono deviation");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::cbFMTxModulationOnKeyPress(TObject *Sender,
        char &Key)
{
    if(Key == VK_RETURN)
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        FM_READ_BYTE_ADDR_REQ_T  readByte;
        FM_READ_BYTE_CNF_T confByte;
        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 0;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Modulation on/off");
            return;
        }

        readByte.m_ucAddr =  0xB8;
        MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Modulation on/off");
            return;
        }

        if(cbFMTxModulationOn->ItemIndex == 0)
        {
            confByte.m_u2ReadByte |= 0x10;
        }
        else
        {
            confByte.m_u2ReadByte  &= ~(0x10);
        }

        byte.m_ucAddr = 0xB8;
        byte.m_u2WriteByte = confByte.m_u2ReadByte;
        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Modulation on/off");

    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::cbFMTxPreEmphasisKeyPress(TObject *Sender,
        char &Key)
{
    if(Key == VK_RETURN)
    {
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        FM_READ_BYTE_ADDR_REQ_T  readByte;
        FM_READ_BYTE_CNF_T confByte;

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pre-emphasis");
            return;
        }


        readByte.m_ucAddr =  0xD4;
        MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pre-emphasis");
            return;
        }
        if(cbFMTxPreEmphasis -> ItemIndex == 0)
        {
            confByte.m_u2ReadByte  &= ~(0x1000);   //[12] = 0
            confByte.m_u2ReadByte  &= ~(0x2000);   //[13] =0
        }
        else if(cbFMTxPreEmphasis -> ItemIndex == 1)
        {
            confByte.m_u2ReadByte  |= 0x1000;;   //[12] = 1
            confByte.m_u2ReadByte  &= ~(0x2000);   //[13] =0
        }
        else
        {
            confByte.m_u2ReadByte  &= ~(0x1000);   //[12] = 0
            confByte.m_u2ReadByte  |= 0x2000;   //[13] =1
        }

        byte.m_ucAddr = 0xD4;
        byte.m_u2WriteByte = confByte.m_u2ReadByte;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Pre-emphasis");
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnFMTxADRCSETClick(TObject *Sender)
{
    META_RESULT MetaResult;
    FM_WRITE_BYTE_REQ_T byte;
    FM_READ_BYTE_ADDR_REQ_T  readByte;
    FM_READ_BYTE_CNF_T confByte;

    byte.m_ucAddr = 0x9f;
    byte.m_u2WriteByte = 1;

    MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Set Audio dynamic range control on/off");
        return;
    }

    readByte.m_ucAddr =  0xFA;
    MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Set Audio dynamic range control on/off");
        return;
    }
    if(chkFMTxDRCOn->Checked == true&&chkFMTxEL->Checked == true)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
    }
    else if(chkFMTxDRCOn->Checked == true&&chkFMTxEL->Checked == false)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
        confByte.m_u2ReadByte  |=0x08;
    }
    else if(chkFMTxDRCOn->Checked == false&&chkFMTxEL->Checked == true)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
        confByte.m_u2ReadByte  |=0x10;
    }
    else
    {
        confByte.m_u2ReadByte  |=0x18;
    }

    byte.m_ucAddr = 0xFA;
    byte.m_u2WriteByte = confByte.m_u2ReadByte;

    MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);

    CNF_FM_WriteAddr(MetaResult,"Set Audio dynamic range control on/off");
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::btnFM(TObject *Sender)
{

    META_RESULT MetaResult;
    FM_WRITE_BYTE_REQ_T byte;
    FM_READ_BYTE_ADDR_REQ_T  readByte;
    FM_READ_BYTE_CNF_T confByte;
    byte.m_ucAddr = 0x9f;
    byte.m_u2WriteByte = 1;

    MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Set Limiter Enable/Disable");
        return;
    }

    readByte.m_ucAddr =  0xFA;
    MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

    if(META_SUCCESS != MetaResult)
    {
        CNF_FM_WriteAddr(MetaResult,"Set Limiter Enable/Disable");
        return;
    }
    if(chkFMTxEL->Checked == true)
    {
        confByte.m_u2ReadByte  &= ~(0x08);   //[3] = 0
    }
    else
    {
        confByte.m_u2ReadByte  |= 0x08;      //[3] = 1
    }

    if(chkFMTxDRCOn->Checked == true&&chkFMTxEL->Checked == true)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
    }
    else if(chkFMTxDRCOn->Checked == true&&chkFMTxEL->Checked == false)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
        confByte.m_u2ReadByte  |=0x08;
    }
    else if(chkFMTxDRCOn->Checked == false&&chkFMTxEL->Checked == true)
    {
        confByte.m_u2ReadByte  &= ~(0x18);
        confByte.m_u2ReadByte  |=0x10;
    }
    else
    {
        confByte.m_u2ReadByte  |=0x18;
    }

    byte.m_ucAddr = 0xFA;
    byte.m_u2WriteByte = confByte.m_u2ReadByte;

    MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);

    CNF_FM_WriteAddr(MetaResult,"Set Limiter Enable/Disable");

}


//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtFMTxPilotFreqKeyPress(TObject *Sender,
        char &Key)
{
    if( Key == VK_RETURN )
    {
        if( (StrToFloat(edtFMTxPilotFreq->Text) < 0.01) || (StrToFloat(edtFMTxPilotFreq->Text) > 32))
        {
            Application->MessageBox( "Out of range", "Error",MB_OK);
            return;
        }
        META_RESULT MetaResult;
        FM_WRITE_BYTE_REQ_T byte;
        FM_READ_BYTE_ADDR_REQ_T  readByte;
        FM_READ_BYTE_CNF_T confByte;

        byte.m_ucAddr = 0x9f;
        byte.m_u2WriteByte = 1;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot frequency");
            return;
        }

        readByte.m_ucAddr =  0xC0;
        MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );

        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Pilot frequency");
            return;
        }

        confByte.m_u2ReadByte &= 0xc000;
        unsigned short value = StrToFloat(edtFMTxPilotFreq->Text)*100;
        confByte.m_u2ReadByte |= value;


        byte.m_ucAddr = 0xC0;
        byte.m_u2WriteByte = confByte.m_u2ReadByte;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);


        CNF_FM_WriteAddr(MetaResult,"Set Pilot frequency");


    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::rgpRDSTxTypeClick(TObject *Sender)
{
    cbRDSTxPTY->Items->Clear();
    cbRDSTxPTY->Enabled = true;
    switch (rgpRDSTxType->ItemIndex)
    {
    case 0:
        cbRDSTxPTY->Items->Add("No Prgram type or undefined");  // 0
        cbRDSTxPTY->Items->Add("News");                         // 1
        cbRDSTxPTY->Items->Add("Current Affairs");              // 2
        cbRDSTxPTY->Items->Add("Information");                  // 3
        cbRDSTxPTY->Items->Add("Sport");                        // 4
        cbRDSTxPTY->Items->Add("Education");                    // 5
        cbRDSTxPTY->Items->Add("Drama");                        // 6
        cbRDSTxPTY->Items->Add("Culture");                      // 7
        cbRDSTxPTY->Items->Add("Science");                      // 8
        cbRDSTxPTY->Items->Add("Varied");                       // 9
        cbRDSTxPTY->Items->Add("Pop Music");                    // 10
        cbRDSTxPTY->Items->Add("Rock Music");                   // 11
        cbRDSTxPTY->Items->Add("M.O.R. Music");                 // 12
        cbRDSTxPTY->Items->Add("Light classical");              // 13
        cbRDSTxPTY->Items->Add("Serious classical");            // 14
        cbRDSTxPTY->Items->Add("Other Music");                  // 15
        cbRDSTxPTY->Items->Add("Weather");                      // 16
        cbRDSTxPTY->Items->Add("Finance");                      // 17
        cbRDSTxPTY->Items->Add("Children's program");           // 18
        cbRDSTxPTY->Items->Add("Social Affairs");               // 19
        cbRDSTxPTY->Items->Add("Religion");                     // 20
        cbRDSTxPTY->Items->Add("Phone In");                     // 21
        cbRDSTxPTY->Items->Add("Travel");                       // 22
        cbRDSTxPTY->Items->Add("Leisure");                      // 23
        cbRDSTxPTY->Items->Add("Jazz Music");                   // 24
        cbRDSTxPTY->Items->Add("Country Music");                // 25
        cbRDSTxPTY->Items->Add("National Music");               // 26
        cbRDSTxPTY->Items->Add("Oldies Music");                 // 27
        cbRDSTxPTY->Items->Add("Folk Music");                   // 28
        cbRDSTxPTY->Items->Add("Documentary");                  // 29
        cbRDSTxPTY->Items->Add("Alarm Test");                   // 30
        cbRDSTxPTY->Items->Add("Alarm");                        // 31

        break;
    case 1:
        cbRDSTxPTY->Items->Add("No Prgram type or undefined"); // 0
        cbRDSTxPTY->Items->Add("News");                     // 1
        cbRDSTxPTY->Items->Add("Information");              // 2
        cbRDSTxPTY->Items->Add("Sports");                   // 3
        cbRDSTxPTY->Items->Add("Talk");                     // 4
        cbRDSTxPTY->Items->Add("Rock");                     // 5
        cbRDSTxPTY->Items->Add("Classic Rock");             // 6
        cbRDSTxPTY->Items->Add("Adult Hits");               // 7
        cbRDSTxPTY->Items->Add("Soft Rock");                // 8
        cbRDSTxPTY->Items->Add("Top 40");                   // 9
        cbRDSTxPTY->Items->Add("Country");                  // 10
        cbRDSTxPTY->Items->Add("Oldies");                   // 11
        cbRDSTxPTY->Items->Add("Soft");                     // 12
        cbRDSTxPTY->Items->Add("Nostalgia");                // 13
        cbRDSTxPTY->Items->Add("Jazz");                     // 14
        cbRDSTxPTY->Items->Add("Classical");                // 15
        cbRDSTxPTY->Items->Add("Rhythm and Blues");         // 16
        cbRDSTxPTY->Items->Add("Soft Rhythm and Blues");    // 17
        cbRDSTxPTY->Items->Add("Language");                 // 18
        cbRDSTxPTY->Items->Add("Religious Music");          // 19
        cbRDSTxPTY->Items->Add("Religious Talk");           // 20
        cbRDSTxPTY->Items->Add("Personality");              // 21
        cbRDSTxPTY->Items->Add("Public");                   // 22
        cbRDSTxPTY->Items->Add("College");                  // 23
        cbRDSTxPTY->Items->Add("Unassigned");               // 24
        cbRDSTxPTY->Items->Add("Unassigned");               // 25
        cbRDSTxPTY->Items->Add("Unassigned");               // 26
        cbRDSTxPTY->Items->Add("Unassigned");               // 27
        cbRDSTxPTY->Items->Add("Unassigned");               // 28
        cbRDSTxPTY->Items->Add("Weather");                  // 29
        cbRDSTxPTY->Items->Add("Emergency Test");           // 30
        cbRDSTxPTY->Items->Add("Emergency");                // 31
        break;
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::chkRDSTxAFClick(TObject *Sender)
{
    if (chkRDSTxAF->Checked == true)
    {
        //speRDSTxAF->Enabled = true;
        udRDSTxAF->Enabled = true;
        edtRDSTxAF->Enabled = true;
    }
    else
    {
        //speRDSTxAF->Enabled = false;
        udRDSTxAF->Enabled = false;
        edtRDSTxAF->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtRDSTxAFKeyPress(TObject *Sender, char &Key)
{
    if(Key == VK_RETURN)
    {
        u_int8 af = (chkRDSTxAF->Checked)?HandleFloat((edtRDSTxAF->Text.ToDouble()-87.5)*10) : 0;
        Application->MessageBox(IntToStr(af).c_str(),"Warning",MB_OK);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::udRDSTxAFChanging(TObject *Sender,
        bool &AllowChange)
{
    edtRDSTxAF->Text = udRDSTxAF->Position/10.0;
}
//---------------------------------------------------------------------------



void __fastcall TfrmFM::btnRDSTxSendClick(TObject *Sender)
{
    FM_RDS_TX_REQ_T req;
    if(edtRDSTxPI->Text == "")
    {
        Application->MessageBox("Please fill the PI entry", "Error",MB_OK);
        return;
    }
    req.pi_code = AnsiString("0x" + edtRDSTxPI->Text).ToInt();	// 2-byte hex
    req.pty = cbRDSTxPTY->ItemIndex; 		                    // 0~31 integer
    req.dyn_pty = (chkRDSTxDynamic->Checked)?1:0; 	            // 0:static, 1:dynamic
    req.rds_rbds = rgpRDSTxType->ItemIndex;	                    // 0:RDS, 1:RBDS

    AnsiString asFillPS = edtRDSTxPS->Text;

    if(asFillPS.Length() < 8)
    {
        asFillPS = edtRDSTxPS->Text;
        for(int i = (edtRDSTxPS->Text.Length()+1); i <= 8; i++)
        {
            asFillPS.Insert(" ",i);
        }

        strncpy(req.ps_buf , asFillPS.c_str() , 8);
        req.ps_len = 8;
    }
    else if(asFillPS.Length() == 8)
    {
        strncpy(req.ps_buf , asFillPS.c_str() , 8);
        req.ps_len = 8;
    }


    req.tp = (chkRDSTxTP->Checked)?1:0;			// traffic program, 0:no, 1:yes
    req.ta = (chkRDSTxTA->Checked)?1:0;			// traffic announcement, 0:no, 1:yes
    req.speech = (chkRDSTxSpeech->Checked)?1:0;		// 0:music, 1:speech
    req.stereo = (chkRDSTxStereo->Checked)?1:0;		// 0:mono, 1:stereo
    req.ah = (chkRDSTxAH->Checked)?1:0;			// Artificial head, 0:no, 1:yes
    req.compress = (chkRDSTxAudioCompress->Checked)?1:0;	// Audio compress, 0:no, 1:yes
    req.af = (chkRDSTxAF->Checked)?HandleFloat((edtRDSTxAF->Text.ToDouble()-87.5)*10) : 0;			// 0~204, 0:not used, 1~204:(87.5+0.1*af)MHz

    META_RESULT MetaResult;
    MetaResult = SP_META_FM_SetRDSTX_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,req);
//rongguo 2011-05-06
//    CNF_FM_WriteAddr(MetaResult,"Set RDS parameter");
    AnsiString text = "Set RDS parameter";
    switch (MetaResult)
    {
    case META_SUCCESS:
    {
        m_sbRDSTX->Panels->Items[0]->Text =text + (AnsiString)" successfully";
    }
    break;

    default:
    {
        Output_FM_ErrorHandler(text, MetaResult, m_sbRDSTX);
    }
    break;
    }
}
//---------------------------------------------------------------------------

inline double TfrmFM::HandleFloat(double dInput)
{
    if(dInput >= 0.0f)
    {
        return floor(dInput + 0.5f);
    }
    return ceil(dInput - 0.5f);
}
void __fastcall TfrmFM::m_btnSetAntennaTypeClick(TObject *Sender)
{
    //CurrentPageLock();
    m_FMReceiverLocker.Lock();
    if ( (m_sFMChipId.m_ucChipId >= FM_CHIP_ID_MT6189AN) && (m_sFMChipId.m_ucChipId <= FM_CHIP_ID_MT6620) )
    {
        if(rbEarPhone->Checked == true)
        {
            META_RESULT MetaResult;
            FM_WRITE_BYTE_REQ_T byte;
            byte.m_ucAddr = 0x04;
            byte.m_u2WriteByte = 0x0142;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x05;
            byte.m_u2WriteByte = 0x00E7;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x26;
            byte.m_u2WriteByte = 0x0004;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x2E;
            byte.m_u2WriteByte = 0x0008;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);

            CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
            //CurrentPageReset();
            m_FMReceiverLocker.Unlock();
        }
        else if(rbShortAnt->Checked == true)
        {
            META_RESULT MetaResult;
            FM_WRITE_BYTE_REQ_T byte;
            byte.m_ucAddr = 0x04;
            byte.m_u2WriteByte = 0x0145;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x05;
            byte.m_u2WriteByte = 0x00ff;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x26;
            byte.m_u2WriteByte = 0x0024;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
            if(META_SUCCESS != MetaResult)
            {
                CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
                //CurrentPageReset();
                m_FMReceiverLocker.Unlock();
                return;
            }

            byte.m_ucAddr = 0x2E;
            byte.m_u2WriteByte = 0x0000;

            MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);

            CNF_FM_WriteAddr(MetaResult,"Set Antenna Switching");
            //CurrentPageReset();
            m_FMReceiverLocker.Unlock();
        }
    }
    else
    {
        FM_SetAntenna_REQ_T fm_set_antenna_req;
        memset(&fm_set_antenna_req, 0 ,sizeof(fm_set_antenna_req));
        if(rbEarPhone->Checked == true)
        {
            fm_set_antenna_req.ana = 0;
        }
        else if(rbShortAnt->Checked == true)
        {
            fm_set_antenna_req.ana = 1;
        }

        META_RESULT MetaResult = SP_META_FM_SetAntenna_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &fm_set_antenna_req);
        if(META_SUCCESS != MetaResult)
        {
            Output_FM_ErrorHandler("Set Antenna Switching", MetaResult, m_sbFMReceiver);
            //CurrentPageReset();
            m_FMReceiverLocker.Unlock();
            return;
        }
        m_sbFMReceiver->Panels->Items[0]->Text =(AnsiString)" Set Antenna Switching successful";
        m_FMReceiverLocker.Unlock();
    }

}
//---------------------------------------------------------------------------



void __fastcall TfrmFM::readVaractorClick(TObject *Sender)
{
//rongguo 2011-05-03
    /*        FM_READ_BYTE_ADDR_REQ_T  readByte;
            FM_READ_BYTE_CNF_T confByte;
            META_RESULT MetaResult;

            readByte.m_ucAddr =  0x26;

            MetaResult =  SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000 ,&readByte , &confByte );


            if(META_SUCCESS != MetaResult)
            {
                    CNF_FM_WriteAddr(MetaResult,"Read Varactor value");
                    return;
            }
    //rongguo 2011-04-28
    //        unsigned short result = confByte.m_u2ReadByte & 0x7fc0;
            unsigned short result = (confByte.m_u2ReadByte & 0x3fc0) >> 6;
            stFMTxVaractorValue->Caption = IntToStr(result);   */

//rongguo 2011-06-15
    /*            char str[256]= {0};
                int CAP_ARRAY;
                CAP_ARRAY = ReadRegister(0x2F,0,5,14);
                CAP_ARRAY = 0x3FF;
                memset(str,'\0',256);
                itoa(CAP_ARRAY, str, 2);
                int i = CAP_ARRAY;
                double cap;
                if(str[0]==1)
                {
                    cap = 0.166;
                }
                if(str[1]==1)
                {
                    cap += 0.332;
                }
                if(str[2]==1)
                {
                    cap += 0.664;
                }
                if(str[3]==1)
                {
                    cap += 1.33;
                }
                if(str[4]==1)
                {
                    cap += 2.66;
                }
                if(str[5]==1)
                {
                    cap += 5.31;
                }
                if(str[6]==1)
                {
                    cap += 10.6;
                }
                if(str[7]==1)
                {
                    cap += 18.6;
                }
                stFMTxVaractorValue->Caption = Double_To_AnsiString(cap);*/
//rongguo 2011-07-04
    int CAP_ARRAY;
    CAP_ARRAY = ReadRegister(0x26, 1, 6, 14);
    double cap;
    cap = ((CAP_ARRAY >> 6) & 0x0001) * 0.166 +
          ((CAP_ARRAY >> 7) & 0x0001) * 0.332 +
          ((CAP_ARRAY >> 8) & 0x0001) * 0.664 +
          ((CAP_ARRAY >> 9) & 0x0001) * 1.33 +
          ((CAP_ARRAY >> 10) & 0x0001) * 2.66 +
          ((CAP_ARRAY >> 11) & 0x0001) * 5.31 +
          ((CAP_ARRAY >> 12) & 0x0001) * 10.6 +
          ((CAP_ARRAY >> 13) & 0x0001) * 18.6;

    stFMTxVaractorValue->Caption = Double_To_AnsiString(cap);
//            CNF_FM_WriteAddr(META_SUCCESS, "Read Varactor");
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::cbFMTxPilotOnKeyPress(TObject *Sender, char &Key)
{
    if(Key == VK_RETURN)
    {
        edtFMTxPilotDeviationKeyPress(Sender, Key);

        //rongguo 2011-04-28
        if(cbFMTxPilotOn->ItemIndex == 0 || true == g_isPowerOnPressed) //Pilot Off
        {

            udFMTxPilotDeviation->Enabled = false;
            edtFMTxPilotDeviation->Enabled = false;
        }
        else
        {
            udFMTxPilotDeviation->Enabled = true;
            edtFMTxPilotDeviation->Enabled = true;
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmFM::cbFMTxRDSOnKeyPress(TObject *Sender, char &Key)
{
    if(Key == VK_RETURN)
    {

        edtFMTxRDSDeviationKeyPress(Sender, Key);

        //rongguo 2011-04-28
        if(cbFMTxRDSOn->ItemIndex == 0 || true == g_isPowerOnPressed) //RDS Off
        {
            udFMTxRDSDeviation->Enabled = false;
            edtFMTxRDSDeviation->Enabled = false;
        }
        else
        {

            udFMTxRDSDeviation->Enabled = true;
            edtFMTxRDSDeviation->Enabled = true;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnFMSetTypeClick(TObject *Sender)
{
//rongguo 2011-07-06
    META_RESULT MetaResult;
    FM_SetTxAudioPath_REQ_T path;
    FM_SetTxAudioFreq_REQ_T freq;
    if(cbI2S->Checked ==  true)
    {
        path.m_audioPath=FM_TX_AUDIO_I2S;
        MetaResult =  SP_META_FM_SetTxAudioPath_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, path);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_AudioSource(MetaResult,"Set Tx Audio Path");
            return;
        }
        else
        {
            freq.m_audioFreq = (FM_TX_TONE_T)(cboFrequency->ItemIndex+1);
            MetaResult =  SP_META_FM_SetTxAudioFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, freq);
            CNF_FM_AudioSource(MetaResult,"Set Tx Audio Freq");
        }

        /*                //rongguo 2011-04-29
                        FM_WRITE_BYTE_REQ_T byte;
                        byte.m_ucAddr = 0x56;
                        byte.m_u2WriteByte = 0x0001;

                        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
                        if(META_SUCCESS != MetaResult)
                        {
                                CNF_FM_WriteAddr(MetaResult,"Set Tx Audio Path");
                                return;
                        }

                        byte.m_ucAddr = 0x9b;
                        byte.m_u2WriteByte = 0x000b;

                        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
                        if(META_SUCCESS != MetaResult)
                        {
                                CNF_FM_WriteAddr(MetaResult,"Set Tx Audio Path");
                                return;
                        } */
    }
    else if(cbAnalog->Checked ==  true)
    {
        /*                path.m_audioPath=FM_TX_AUDIO_ANALOG;
                        MetaResult =  SP_META_FM_SetTxAudioPath_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, path);
                        if(META_SUCCESS != MetaResult)
                        {
                                CNF_FM_AudioSource(MetaResult,"Set Tx Audio Path");
                                return;
                        }
                        else
                        {
                                 freq.m_audioFreq = cboFrequency->ItemIndex+1;
                                 MetaResult =  SP_META_FM_SetTxAudioFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, freq);
                                 CNF_FM_AudioSource(MetaResult,"Set Tx Audio Freq");
                        } */
        //rongguo 2011-04-29
        FM_WRITE_BYTE_REQ_T byte;
        byte.m_ucAddr = 0x56;
        byte.m_u2WriteByte = 0x0000;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Tx Audio Path");
            return;
        }

        byte.m_ucAddr = 0x9b;
        byte.m_u2WriteByte = 0x0008;

        MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&byte);
        if(META_SUCCESS != MetaResult)
        {
            CNF_FM_WriteAddr(MetaResult,"Set Tx Audio Path");
            return;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::edtFMTxRFFreqChange(TObject *Sender)
{
    readVaractorClick(Sender);
}
//---------------------------------------------------------------------------
void TfrmFM::ResetFMTransmitter()
{
    edtFMTxRFFreq->Text = 94;
    edtFMTxRFlevel->Text = 120;
    edtFMTxAudioDeviation->Text = 68.25;

    cbFMTxPilotOn->ItemIndex = 1;
    edtFMTxPilotDeviation->Text = 6.75;

    cbFMTxRDSOn->ItemIndex = 0;
    edtFMTxRDSDeviation->Text = 0;

    edtFMTxPilotFreq->Text = 19;

    cbFMTxModulationOn->ItemIndex = 1;
    cbFMTxStereoMonoEnable->ItemIndex = 1;
    cbFMTxPreEmphasis->ItemIndex = 2;
    chkFMTxDRCOn->Checked = true;
    chkFMTxEL->Checked = true;
    cbI2S->Checked = true;
    cbAnalog->Checked = false;
    cboFrequency->ItemIndex = 0;

    //rongguo 2011-05-06
    //for RDS transmitter page
    rgpRDSTxType->ItemIndex = 0;
    TObject *Sender = (TObject *)btnFMTxPowerOnOff;
    rgpRDSTxTypeClick(Sender);
    cbRDSTxPTY->ItemIndex = -1;
    chkRDSTxDynamic->Checked = false;
    edtRDSTxPI->Text = '\0';
    edtRDSTxPS->Text = '\0';
    chkRDSTxAF->Checked = false;
    chkRDSTxAFClick(Sender);
    edtRDSTxAF->Text = '\0';
    chkRDSTxAH->Checked = false;
    chkRDSTxStereo->Checked = false;
    chkRDSTxAudioCompress->Checked = false;
    chkRDSTxTP->Checked = false;
    chkRDSTxTA->Checked = false;
    chkRDSTxSpeech->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::FormCreate(TObject *Sender)
{
//rongguo 2011-04-29
    /*        ResetFMTransmitter();
            btnFMTxADRCSETClick(Sender);
            btnFMSetTypeClick(Sender);*/
//rongguo 2011-09-06
    if(m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)
    {
        AnsiString_To_FM_Freq_50KHz(m_edtFMReceiver_CurrentFrequency->Text, m_RXCurrentFrequency);
    }
    else
    {
        AnsiString_To_FM_Freq(m_edtFMReceiver_CurrentFrequency->Text, m_RXCurrentFrequency);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmFM::edtFMTxExit(TObject *Sender)
{
//        ((TControl*)Sender)->Perform(WM_CHAR, VK_RETURN, 0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXTune_IncreaseClick(TObject *Sender)
{
//    if(m_tbFMReceiver_Frequency->Position < 1080)
    if(m_tbFMReceiver_Frequency->Position < ((m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)?FM_FREQUENCY_MAX_50KHZ:FM_FREQUENCY_MAX_100KHZ))
    {
        m_btnFMRXTune_Increase->Tag ++;
        m_btnFMRXTune_Decrease->Tag ++;

        m_tbFMReceiver_Frequency->Position += 1;

        m_btnFMRXSetFrequencyClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::m_btnFMRXTune_DecreaseClick(TObject *Sender)
{
//rongguo 2011-06-15
//    if(m_tbFMReceiver_Frequency->Position > 875)
//    if(m_tbFMReceiver_Frequency->Position > 760)
    if(m_tbFMReceiver_Frequency->Position > ((m_sFMStepMode.m_i4Step == FM_STEP_MODE_50KHZ)?FM_FREQUENCY_TRACKBAR_MIN_50KHZ:FM_FREQUENCY_TRACKBAR_MIN_100KHZ))
    {
        m_btnFMRXTune_Increase->Tag --;
        m_btnFMRXTune_Decrease->Tag --;

        m_tbFMReceiver_Frequency->Position -= 1;

        m_btnFMRXSetFrequencyClick(Sender);
    }
}
//---------------------------------------------------------------------------
void TfrmFM::TxMainUIControl(E_FM_TX_MAIN_UICONTROL_T control)
{
    if(control & FM_TX_MAIN_UICONTROL_POWERON)
    {
        m_btnFMRXPowerOn->Enabled = true;
    }
    else
    {
        m_btnFMRXPowerOn->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_POWEROFF)
    {
        m_btnFMRXPowerOff->Enabled = true;
    }
    else
    {
        m_btnFMRXPowerOff->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_RDSON)
    {
        m_btnFMRXRDSOn->Enabled = true;
        m_btnFMRDS_RDSOn->Enabled = true;
    }
    else
    {
        m_btnFMRXRDSOn->Enabled = false;
        m_btnFMRDS_RDSOn->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_RDSOFF)
    {
        m_btnFMRXRDSOff->Enabled = true;
        m_btnFMRDS_RDSOff->Enabled = true;
    }
    else
    {
        m_btnFMRXRDSOff->Enabled = false;
        m_btnFMRDS_RDSOff->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_FREQUENCY)
    {
        m_tbFMReceiver_Frequency->Enabled = true;
        m_btnFMRXSetFrequency->Enabled = true;
        m_btnFMRXTune_Increase->Enabled = true;
        m_btnFMRXTune_Decrease->Enabled = true;
        m_edtFMReceiver_CurrentFrequency->Enabled = true;
        m_btnFMRXSeekLeft->Enabled = true;
        m_btnFMRXSeekRight->Enabled = true;
        m_cbFMReceiver_ChannelList->Enabled = true;
        m_btnFMRXAutoScan->Enabled = true;
        m_edtFMReceiver_ChannelSelect->Enabled = true;
        m_btnFMRXGoChannel->Enabled = true;
    }
    else
    {
        m_tbFMReceiver_Frequency->Enabled = false;
        m_btnFMRXSetFrequency->Enabled = false;
        m_btnFMRXTune_Increase->Enabled = false;
        m_btnFMRXTune_Decrease->Enabled = false;
        m_edtFMReceiver_CurrentFrequency->Enabled = false;
        m_btnFMRXSeekLeft->Enabled = false;
        m_btnFMRXSeekRight->Enabled = false;
        m_cbFMReceiver_ChannelList->Enabled = false;
        m_btnFMRXAutoScan->Enabled = false;
        m_edtFMReceiver_ChannelSelect->Enabled = false;
        m_btnFMRXGoChannel->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_RESET)
    {
        m_btnFMRDS_BlockCounterReset->Enabled = true;
        m_btnFMRDS_GroupCounterReset->Enabled = true;
    }
    else
    {
        m_btnFMRDS_BlockCounterReset->Enabled = false;
        m_btnFMRDS_GroupCounterReset->Enabled = false;
    }

    if(control & FM_TX_MAIN_UICONTROL_OTHERS)
    {
        m_btnFMRXSetVolume->Enabled = true;
        m_tbFMReceiver_Volume->Enabled = true;
        m_btnFMRXStatusUpdate->Enabled = true;
        rbEarPhone->Enabled = true;
        rbShortAnt->Enabled = true;
        m_btnSetAntennaType->Enabled = true;
        btnAudioTest->Enabled = true;
    }
    else
    {
        m_btnFMRXSetVolume->Enabled = false;
        m_tbFMReceiver_Volume->Enabled = false;
        m_btnFMRXStatusUpdate->Enabled = false;
        rbEarPhone->Enabled = false;
        rbShortAnt->Enabled = false;
        m_btnSetAntennaType->Enabled = false;
        btnAudioTest->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void TfrmFM::DisconnectClean(int cleanFlag)
{
    if(m_btnFMRXRDSOn->Tag || m_btnFMRDS_RDSOn->Tag)
    {
        g_DisconnectFlag = false;
        g_CloseFlag = false;
        Application->MessageBox("Please turn off RDS first", "WARNING", MB_OK );
        return;
    }

    if(0 == cleanFlag && true == bFMRXPowerOn)
    {
        btnFMRXPowerOffClick(NULL);
    }
    else if(true == bFMTXPowerOn)
    {
        btnFMTxPowerOnOffClick(NULL);
    }
    else
    {
        PostMessage(hForm_MainForm, WM_FM_DISCONNECT_CLEAN_DONE, 2, 0);
    }
    return;
}

void TfrmFM::CleanFMStatus(void)
{
    if(true == bFMRXPowerOn)
    {
       bFMRXPowerOn = false;
       m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  FM radio module power off successfully";
       m_btnFMRXPowerOn->Tag = 0;
       m_btnFMRXRDSOn->Enabled = false;
       m_btnFMRDS_RDSOn->Enabled = false;
       frmFM->Tag = 0;
       TxMainUIControl(FM_TX_MAIN_UICONTROL_POWERON);
    }
}


void TfrmFM::DealCounterUpdate(void)
{
    m_eRdsCounter++;
    if (m_eRdsCounter >= FM_RDS_COUNTER_COUNT)
    {
        m_sRDSGoodBlockCounter = m_cFM_RDS_Obj.Get_FM_RDS_GoodBlockCounter();
        m_sRDSBadBlockCounter = m_cFM_RDS_Obj.Get_FM_RDS_BadBlockCounter();
        m_sRDSGroupCounter = m_cFM_RDS_Obj.Get_FM_RDS_GroupCounter();
        m_u2BLER = m_cFM_RDS_Obj.Get_FM_RDS_BLER();
        FM_RDS_LOGDATA_T * rdslog = m_cFM_RDS_Obj.Get_FM_RDS_LogData();

        memcpy(&m_sRDSLogData,rdslog,sizeof(m_sRDSLogData));
        ReDrawFields(DRAW_FM_RDS_BLOCK_COUNTER | DRAW_FM_RDS_GROUP_COUNTER);
        CounterTimer->Enabled = true;
    }
    else
    {
        CounterUpdate();
    }
}

void TfrmFM::ResetFMTxUI(bool bEnable)
{
    edtFMTxRFFreq->Enabled = bEnable;
    edtFMTxRFlevel->Enabled = bEnable;
    edtFMTxAudioDeviation->Enabled = bEnable;

    cbFMTxPilotOn->Enabled = bEnable;
    edtFMTxPilotDeviation->Enabled = bEnable;

    cbFMTxRDSOn->Enabled = bEnable;
    edtFMTxRDSDeviation->Enabled = bEnable;

    edtFMTxPilotFreq->Enabled = bEnable;

    cbFMTxModulationOn->Enabled = bEnable;
    cbFMTxStereoMonoEnable->Enabled = bEnable;
    cbFMTxPreEmphasis->Enabled = bEnable;
    chkFMTxDRCOn->Enabled = bEnable;
    chkFMTxEL->Enabled = bEnable;
    cbI2S->Enabled = bEnable;
    cbAnalog->Enabled = bEnable;
    cboFrequency->Enabled = bEnable;
    readVaractor->Enabled = bEnable;
    btnFMTxADRCSET->Enabled = bEnable;
    btnFMTxLimiter->Enabled = bEnable;
    btnFMSetType->Enabled = bEnable;
    stFMTxVaractorValue->Enabled = bEnable;
    stFMTxTotalDeviation->Enabled = bEnable;
    udFMTxRFFreq->Enabled = bEnable;
    udFMTxRFlevel->Enabled = bEnable;
    udFMTxAudioDeviation->Enabled = bEnable;
    udFMTxPilotDeviation->Enabled = bEnable;
    udFMTxRDSDeviation->Enabled = bEnable;
    udFMTxPilotFreq->Enabled = bEnable;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFM::btnAudioTestClick(TObject *Sender)
{
    m_cFM_RADIO_Obj.ConfirmCallback = ::CNF_FM_AudioTest;
    m_cFM_RADIO_Obj.REQ_FM_Audio_Test_Start();
    m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Audio Test progressing";
}
//---------------------------------------------------------------------------
void TfrmFM::CNF_FM_AudioTest(void)
{
    META_RESULT state = m_cFM_RADIO_Obj.Get_ConfirmState();

    switch (state)
    {
        case META_SUCCESS:
        {
            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"  Audio Test success";
            stAudioTest->Caption = (AnsiString)"Success";
        }
        break;

        default:
        {
            m_sbFMReceiver->Panels->Items[0]->Text = (AnsiString)"Audio Test fail";
            stAudioTest->Caption = (AnsiString)"Fail";
        }
        break;
    }
}
//---------------------------------------------------------------------------

