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
 *   fm_radio.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   FM radio header
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
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _FM_RADIO_H_
#define  _FM_RADIO_H_

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
typedef enum
{
    FM_DISABLE = 0,
    FM_ENABLE
} E_FM_ENABLE_T;

typedef struct
{
    FM_IF_CNT_DELTA_REQ_T s_if_cnt_delta;
    FM_RSSI_THRESHOLD_REQ_T s_rssi_thrsh;
    FM_FREQ_RANGE_REQ_T s_freq_range;
} S_FM_SEARCH_STATION_T;

typedef struct
{
    FM_RSSI_CNF_T s_rssi;
    FM_IF_CNT_CNF_T s_if_cnt;
    FM_HL_Side_CNF_T s_hl_side;
    FM_Stereo_Mono_CNF_T s_stero_mono;
    FM_MR_CNF_T s_mr;
    FM_PAMD_Level_CNF_T s_pamdlevel;
    FM_RX_FilterBW_CNF_T s_rxfilterbw;
} S_FM_STATUS_T;

typedef struct
{
    //Audio_Set_Volume_Req s_vol;
    FM_MONO_STEREO_BLEND_REQ_T s_mono_stereo_blend;
    FM_SOFT_MUTE_ONOFF_REQ_T s_soft_mute_onoff;
    //FM_STAGE_REQ_T s_soft_mute_level;
    FM_STAGE_REQ_T s_stereo_blend_level;
} S_FM_AUDIO_T;

/*---------------------------------------------------------------------------*/
class  CFMRADIO
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;
    bool m_bFMSupport;
    FM_CHIP_ID_CNF_T m_sFMChipId;

    // frequecny
    FM_FREQ_REQ_T m_sFMFreq;

    // search station
    S_FM_SEARCH_STATION_T m_sSearchStation;
    FM_VAILD_FREQ_CNF_T m_sValidFreq;
    // seek statation (with HW seek capability)
    FM_HWSeek_REQ_T m_sHWSeekReq;
    FM_HWSeek_CNF_T m_sHWSeekCnf;

    // RSSI & IF counter
    S_FM_STATUS_T m_sStatus;

    // volume
    short m_sSETVOLUME;
    S_FM_AUDIO_T m_sAudio;
    HANDLE  m_hEvent;

    // data read/write
    unsigned char m_ucAddr;
    unsigned short m_usData;

    // for MT6616 new API
    // auto scan
    FM_AutoScan_CNF_T m_sAutoScanCnf;
    // setting paramters
    FM_Decode_Mode_REQ_T m_sDecodeModeReq;
    FM_Deemphasis_Level_REQ_T m_sDeemphasisLevelReq;
    FM_HL_Side_REQ_T m_sHLSideReq;
    FM_HCC_REQ_T m_sHCCReq;
    FM_Demod_Bandwidth_REQ_T m_sDemodBandwidthReq;
    FM_PAMD_Threshold_REQ_T m_sPAMDThresholdReq;
    FM_DynamicLimiter_REQ_T m_sDynamicLimiterReq;
    FM_Softmute_Rate_REQ_T m_sSoftmuteRateReq;
    FM_Softmute_Enable_REQ_T m_sSoftmuteEnableReq;
    FM_Volume_Setting_REQ_T m_sVolumeSettingReq;
    FM_RSSI_THRESHOLD_REQ_T m_sRSSIThresholdReq;
    FM_SetStereoBlend_REQ_T m_sStereoBlendControlReq;
    // get status
    AnsiString m_fileName;
    FM_Status_CNF_T cnf;
    FM_SETStatus_REQ_T m_req;
    FM_STEP_MODE_CNF_T m_sFMStepMode;
    //
protected:
public:

    void  Confirm(META_RESULT confirm_state);



    CFMRADIO(void);
    ~CFMRADIO();
    void REQ_FM_Power_On(void);
    void REQ_FM_Power_Off(void);
    void REQ_Set_Freq(void);
    void REQ_SetRssiThreold(void);
    void REQ_SetAudio(void);
    void REQ_FM_Set_Softmute(void);
    void REQ_FM_Set_MonoOrStereoBlend(void);
    void REQ_FM_Set_StereoBlendStage(void);
    void REQ_Get_FM_Status(void);
    void REQ_SearchFreq(void);
    void REQ_ReadData(void);
    void REQ_WriteData(void);
    void __stdcall CNF_AudioSetVolume(const AUDIO_RESULT status, const short token, void *usrData);

    // for MT6616 new API
    void REQ_FM_AutoScan(void);
    void REQ_FM_Set_DecodeMode(void);
    void REQ_FM_Set_DeemphasisLevel(void);
    void REQ_FM_Set_StereoBlend(void);
    void REQ_FM_Set_HLSide(void);
    void REQ_FM_Set_HCC(void);
    void REQ_FM_Set_DemodBandwidth(void);
    void REQ_FM_Set_PAMDThreshold(void);
    void REQ_FM_Set_DynamicLimiter(void);
    void REQ_FM_Set_RSSIThreshold(void);
    void REQ_FM_Set_SoftmuteRate(void);
    void REQ_FM_Set_SoftmuteEnable(void);
    void REQ_FM_Get_RSSI(void);
    void REQ_FM_Get_RXFilterBW(void);
    void REQ_FM_Get_PAMDLevel(void);
    void REQ_FM_Get_MR(void);
    void REQ_FM_Get_Stereo(void);
    void REQ_FM_Get_IFCounter(void);
    void REQ_FM_Get_HLSide(void);
    void REQ_FM_HWSeek(void);
    void REQ_FM_Set_Volume(void);
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



    void  (*ConfirmCallback)(void);


    //---------------------------------------------------------------------------
    // Public interface
    void REQ_FM_Power_On_Start(void);
    void REQ_FM_Power_Off_Start(void);
    void REQ_Set_Freq_Start(FM_FREQ_REQ_T freq);
    //void REQ_SetRssiThreold_Start(FM_RSSI_THRESHOLD_REQ_T rssi_threshold);
    void REQ_Get_FM_Status_Start(void);
    void REQ_SearchFreq_Start(S_FM_SEARCH_STATION_T search_station);
    void REQ_SetAudio_Start(S_FM_AUDIO_T audio);
    // SetAudio_Start divided into 3 APIs
    void REQ_FM_Set_Softmute_Start(void);
    void REQ_FM_Set_MonoOrStereoBlend_Start(void);
    void REQ_FM_Set_StereoBlendStage_Start(void);
    void REQ_ReadData_Start(unsigned char addr);
    void REQ_WriteData_Start(unsigned char addr, unsigned short data);
    // for MT6616 new API (parameters are stored in the object)
    void REQ_FM_AutoScan_Start(void);
    void REQ_FM_Set_DecodeMode_Start(void);
    void REQ_FM_Set_DeemphasisLevel_Start(void);
    void REQ_FM_Set_StereoBlend_Start(void);
    void REQ_FM_Set_HLSide_Start(void);
    void REQ_FM_Set_HCC_Start(void);
    void REQ_FM_Set_DemodBandwidth_Start(void);
    void REQ_FM_Set_PAMDThreshold_Start(void);
    void REQ_FM_Set_DynamicLimiter_Start(void);
    void REQ_FM_Set_RSSIThreshold_Start(void);
    void REQ_FM_Set_SoftmuteRate_Start(void);
    void REQ_FM_Set_SoftmuteEnable_Start(void);
    void REQ_FM_Get_RSSI_Start(void);
    void REQ_FM_Get_RXFilterBW_Start(void);
    void REQ_FM_Get_PAMDLevel_Start(void);
    void REQ_FM_Get_MR_Start(void);
    void REQ_FM_Get_Stereo_Start(void);
    void REQ_FM_Get_IFCounter_Start(void);
    void REQ_FM_Get_HLSide_Start(void);
    void REQ_FM_HWSeek_Start(void);
    void REQ_FM_Set_Volume_Start(void);

    // query
    bool Query_FMSupport_Start(void);
    bool REQ_Query_FMChipID_Start(FM_CHIP_ID_CNF_T& fm_chip_id);
    unsigned int REQ_FM_Query_Version_Start(void);
    bool REQ_Query_FMStepMode_Start(FM_STEP_MODE_CNF_T& fm_step_mode);
    //


    // global information
    META_RESULT   Get_ConfirmState(void);
    bool Get_FMSupport(void);
    FM_CHIP_ID_CNF_T* Get_FMChipID(void);
    S_FM_STATUS_T* Get_FMStatus(void);
    FM_VAILD_FREQ_CNF_T* Get_ValidFreq(void);
    unsigned short Get_Data(void);
    void Get_ValidSeekFreq(FM_HWSeek_CNF_T& cnf);
    void Get_AutoScan(FM_AutoScan_CNF_T& cnf);
    // new load with old chips
    void Set_MonoOrStereoBlendReq(unsigned short stereo);
    void Set_StereoBlendStageReq(unsigned char stage);
    void Set_SoftmuteReq(unsigned char enable);
    // new in MT6616 input setting parameter
    void Set_DecodeModeReq(unsigned int decode_mode);
    void Set_DeemphasisLevelReq(unsigned int deemphasis_level);
    void Set_HLSideReq(unsigned int hl_side);
    void Set_HCCReq(unsigned int hcc);
    void Set_DemodBandwidthReq(unsigned int demod_bandwidth);
    void Set_PAMDThresholdReq(unsigned int pamd_threshold);
    void Set_DynamicLimiterReq(unsigned int dynamic_limiter);
    void Set_SoftmuteRateReq(unsigned int softmute_rate);
    void Set_SoftmuteEnableReq(unsigned int softmute_enable);
    void Set_VolumeSettingReq(unsigned char volume, char digital_gain_index);
    void Set_RSSIThresholdReq(unsigned int rssi_threshold);
    void Set_HWSeekReq(short start_freq, unsigned char seek_direction);
    void Set_StereoBlendControl(unsigned short stereoblend_enable);

    void REQ_FM_GET_STATUS(void);
    void REQ_FM_GET_STATUS_Start(AnsiString filename);
    FM_Status_CNF_T REQ_FM_GetStatusMT6620();
    void REQ_FM_SET_PARAMETER_Start(AnsiString xmlFile,FM_SETStatus_REQ_T req);
    void REQ_FM_SET_PARAMETER(void);

    void REQ_FM_Audio_Test_Start(void);
    void REQ_FM_Audio_Test(void);

};

/*---------------------------------------------------------------------------*/
#endif
