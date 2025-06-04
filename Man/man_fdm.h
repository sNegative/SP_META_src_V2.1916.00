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
 *   man_fdm.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   NVRAM access handling header
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
 * $Modtime:   Oct 25 2005 12:18:48  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_fdm.h-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
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
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:16   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:06:46   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:12   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:57:52   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:14:26   mtk00490
 * 1. Automatic BB chip and external clock rate detection
 * 2. Support baud rate 57600 (for FPGA test)
 * 3. RF tool
 * a.Trim IQ, offset IQ sweep (get phase error, original offset, IQ imbalance information from equipment)
 * 4. Audio
 * a.Acoustic FIR tuning and melody FIR tuning integrate with AFTDLL.dll (provide freqz and firls function, user does not to install MATLAB for FIR tuning)
 * 5. Update parameter
 * a.add barcode and IMEI read/write
 * 6. Factory
 * a.support DCS, PCS, GSM850 AFC calibration
 * b.phase error calibration
 * c.user configurable current limit
 * d.add APC DAC to result file
 * e.add AFC_BAND, AFC_ARFCN to TCVCXO AFC CFG editor
 * f.add CURRENT_LIMIT to ADC CFG editor
 * g.add phase error CFG editor
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _MAN_FDM_H_
#define  _MAN_FDM_H_

#include <vcl.h>

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

// NVRAM
#ifndef _NVRAMEDITOR_H_
#include "NVRAMEditor.h"
#endif

/*---------------------------------------------------------------------------*/
#define NVRAM_STATUS_SUCCESS 0
#define NVRAM_STATUS_FAIL    1



/*---------------------------------------------------------------------------*/
class CNVRAMMan
{
private:
    bool m_bIsInit;
    S_FORM_HANDLE_T m_sHandle;
    Variant m_vNVRAM_db_variant;
    unsigned long m_ulNvramIdb;
    META_RESULT m_eConfirmState;
    AnsiString m_asNVRAM_DB_File;
    CMETAHANDLE m_META_HANDLE_Obj;
    short              m_sNVRAM_OPID;
    AP_FT_NVRAM_READ_REQ *m_psNVRAM_ReadReq;
    AP_FT_NVRAM_READ_CNF m_sNVRAM_ReadCnf;

    AP_FT_NVRAM_WRITE_REQ    *m_psNVRAM_WriteReq;
    const AP_FT_NVRAM_WRITE_CNF    *m_psNVRAM_WriteCnf;

    AP_FT_NVRAM_RESET_REQ    *m_psNVRAM_ResetReq;
    const AP_FT_NVRAM_RESET_CNF    *m_psNVRAM_ResetCnf;

    AP_FT_NVRAM_RESET_REQ    *m_psNVRAM_ResetDataReq;

    int                 m_iBufSize;
    char               *m_cBuf;

    const char		*m_cLID;		// The name of logical data item ID
    unsigned short 	 m_usRID;		// Record ID
    unsigned char     m_ucIsResetOk;
    int *m_iResetCountPtr;
    bool m_iResetStatus;
    HANDLE  m_WriteToNVRAMEvent;
    HANDLE  m_ReadFromNVRAMEvent;

    // APC
    bool m_bVbiasSupport;

    bool     m_bCustVolExSupport;

    // IMEI
    bool m_b2ndIMEISupport;

    //backup and restore
    AnsiString m_file1;
    AnsiString m_file2;

    //AP DB path on target side
    unsigned char m_TargetSideAPDBFolder[128];
    unsigned char m_PCSideAPDBPath[256];

protected:
    void Get_BbTxCfgVer_FromNVDB(void);
    void Confirm(META_RESULT confirm_state);

public:
    // NVRAM
    void  REQ_ReadNVRAM(void);
    void  REQ_WriteNVRAM(void);

    // call back
    void  __stdcall CNF_ReadNVRAM(const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData);
    void  __stdcall CNF_WriteNVRAM(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);
    void  __stdcall CNF_ResetNVRAMData(const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData);
    void  __stdcall CNF_ResetNVRAM(const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData);

    CNVRAMMan(void);
    ~CNVRAMMan();
    void  REQ_Finish(void);
    void  REQ_TimeOut(void);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)(void);

    void  Init(char* fdm_database_file);
    void  Init_NVRAM_DB(char* fdm_database_file);
    void  REQ_Init(AnsiString as_file);
    void  REQ_Init_NVRAM_DB(void);
    void  REQ_Stop(void);

    void  REQ_ReadNVRAM_Start(const char *LID_para, unsigned short RID, int size, char *buf);
    void  REQ_WriteNVRAM_Start(const char *LID_para, unsigned short RID, int size, char *buf);
    void  REQ_ResetNVRAMData_Start(const char *LID_para);
    void  REQ_ResetNVRAMData(void);
    int   REQ_ResetLayer1(int *ResetCountPtrPara);

    void  REQ_NVRAMBackup_Start(const AnsiString& file1,const AnsiString& file2);
    void  REQ_NVRAMBackup(void);
    void  REQ_NVRAMRestore_Start(const AnsiString& file1,const AnsiString& file2);
    void  REQ_NVRAMRestore(void);

    // Global information
    META_RESULT Get_ConfirmState(void);
    bool Get_IsInit(void);
    void Set_IsInit(bool is_init);
    AnsiString Get_NVRAM_DB_File(void);
    Variant Get_NvramDbVariant(void);
    void Set_NvramDbVariant(Variant variant);
    bool Get_VbiasSupport(void);
    bool Get_CustVolExSupport(void);
    void Set_FormHandle(S_FORM_HANDLE_T handle);
    bool Get_2ndIMEISupport(void);
    bool QueryAPDBPath(void);
    bool CopyAPDBToPC(void);
    unsigned char* GetPCSideAPDBPath();
};


extern  CNVRAMMan  *NVRAMMan;
/*---------------------------------------------------------------------------*/
#endif