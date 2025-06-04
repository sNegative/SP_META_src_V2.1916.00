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
 *   LogicalControlBase.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   .
 * Author:
 * -------
 *  Rongguo Zhang (mtk80761)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 25 2005 11:45:30  $
 * $Log:    $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------
#ifndef  _LOGICAL_CONTROL_H_
#define  _LOGICAL_CONTROL_H_

#include "meta.h"
#include "man_handle.h"

typedef enum
{
//BASEBAND
    BB_SET_VIBRATOR_ONOFF,
    BB_QUERY_RTC_TIME,
    BB_SET_KEYPADLED_ONOFF,
    BB_SET_LCDLED_LIGHTLEVEL,
    BB_SET_SIGNAL_INDICATOR_ONOFF,
    BB_READ_REGISTER,
    BB_WRITE_REGISTER,
    BB_BATTERY_DOWNLOADIMAGE,
    BB_BATTERY_UPLOADIMAGE,
//DVB
    DVB_CONNECT,
    DVB_DISCONNECT,
    DVB_MIDDLEWARE_UPDATE,
    DVB_PARAMETER_CALIBRATION,
    DVB_GET_SIGNALQUALITY,
    DVB_DEMODULATOR_ISALIVE,
    DVB_SET_TS_PACKET_BATCH,
    DVB_SET_TX_PACKET_TIMEOUT,
    DVB_ADD_TS_PID,
    DVB_REMOVE_TS_PID,
    DVB_DISABLE_ALL_TS_PIDS_FILTERING,
    DVB_DUMP_TS_PACKETS_TO_SDCARD,
    DVB_GET_RECPTION_MODE,
    DVB_GET_LOCK_INDICATOR,
    DVB_GET_PERFORMANCE_INFO,
    DVB_GET_VERSION,
    DVB_GET_DEBUG_COUNTER,
//Battery
    Battery_READINFO,
    Battery_READSOC,
    Battery_WRITESOC,
    Battery_UPDATEFW,

    Battery_ENABLEBQ,
//GPS
    GPS_Open,
    GPS_Close,
    GPS_SendCommand_PMTK810,
    GPS_SendCommand_PMTK811,
    GPS_SendStartCommand_PMTK817,
    GPS_SendStopCommand_PMTK817,
    GPS_SendCNRStartCommand_PMTK810,
    GPS_SendCNRStopCommand_PMTK811,
//HW Test
    HW_AUTO_TEST_BEGIN,
    HW_MANUAL_TEST_BEGIN,
    HW_MANUAL_TEST_CONTINUE,
    HW_MANUAL_TEST_RETRY,
    HW_MANUAL_TEST_END,
// ECCI Test
    ECCI_TEST,
//Clean Boot
    CLEAN_BOOT,
//GSensor
    GS_Perform_Calibration,
    GS_Write_NVRAM,

    GYRO_Perform_Calibration,
    GYRO_Write_NVRAM


} REQ_CMDTYPE;


class  CLogicalControlBase
{
public:
    CLogicalControlBase(void);
    ~CLogicalControlBase(void);

    void  REQ_Finish(void);
    void  REQ_TimeOut(void);
    void  REQ_Stop(void);
    int  Get_ConfirmState( void );

    void  (*ConfirmCallback)( void );

protected:
    CMETAHANDLE m_META_HANDLE_Obj;
    int   m_iConfirmState;
    bool m_bIsRunning;

    void  Confirm(int confirm_state);
    void DoMetaResult(META_RESULT mr);

};
#endif