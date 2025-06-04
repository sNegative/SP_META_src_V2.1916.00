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
 *   form_GetVersion.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Get version form header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 25 2005 11:54:24  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Form/form_GetVersion.h-arc  $
 *
 *    Rev 1.11   Oct 25 2005 14:14:26   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.10   Sep 04 2005 11:05:22   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.9   Apr 18 2005 15:48:20   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.8   Jan 30 2005 17:56:06   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.7   Jan 10 2005 11:12:16   mtk00490
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
//---------------------------------------------------------------------------

#ifndef form_GetVersionH
#define form_GetVersionH
//---------------------------------------------------------------------------

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#endif

#ifndef  _MISC_H_
#include "misc.h"
#endif
#include <stdio.h>
#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "get_version.h"
#include "UUIDOp.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmGetVersion : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TStaticText *stSWVersion;
    TLabel *Label2;
    TStaticText *stHWVersion;
    TButton *btnGetTargetVersion;
    TLabel *Label3;
    TStaticText *stMelodyVersion;
    TLabel *Label4;
    TStaticText *stBBChipVersion;
    TLabel *Label5;
    TStaticText *stECOVersion;
    TLabel *Label6;
    TStaticText *stDSPFirmwareVersion;
    TLabel *Label7;
    TStaticText *stDSPPatchVersion;
    TButton *btnLoadFromFile;
    TButton *btnSaveToFile;
    TStatusBar *sbVersion;
    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    TGroupBox *GetVersion;
    TGroupBox *UUID;
    TLabel *Label8;
    TEdit *edUUIDHigh1;
    TLabel *Label9;
    TEdit *edUUIDLow1;
    TButton *bnUUIDRead;
    TButton *bnUUIDWrite;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TLabel *Label10;
    TEdit *edUUIDHigh2;
    TEdit *edUUIDHigh3;
    TEdit *edUUIDHigh4;
    TEdit *edUUIDHigh5;
    TEdit *edUUIDHigh6;
    TEdit *edUUIDHigh7;
    TEdit *edUUIDHigh8;
    TEdit *edUUIDLow2;
    TEdit *edUUIDLow3;
    TEdit *edUUIDLow4;
    TEdit *edUUIDLow5;
    TEdit *edUUIDLow6;
    TEdit *edUUIDLow7;
    TEdit *edUUIDLow8;

    void __fastcall btnGetTargetVersionClick(TObject *Sender);
    void __fastcall btnLoadFromFileClick(TObject *Sender);
    void __fastcall btnSaveToFileClick(TObject *Sender);
    void __fastcall edtUUIDCheck(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall bnUUIDReadClick(TObject *Sender);
    void __fastcall bnUUIDWriteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CGETVERSION    GET_VERSION_Object;
    UUIDOp         UUID_Op_Object;
    VerInfo_Cnf   VerInfo;
    //	char  ECO_version[4];
    // char *BB_CHIP_version, *DSP_FW_version, *DSP_PATCH_version, *SW_version, *HW_version, *Melody_version;
public:		// User declarations
    __fastcall TfrmGetVersion(TComponent* Owner);
    void ReDrawFields(void);
    void GetFields(void);
//rongguo 2011-12-22
//    void ResetFields(void);

    void ShowHintLabel(TControl *sender, char* hint);
    unsigned int GetUUIDHigh(void);
    unsigned int GetUUIDLow(void);
    void ShowUUID(const unsigned int high,const unsigned int low);
    void CurrentPageLock(void);
    void CurrentPageReset(void);
    // call back
    void CNF_GetTargetVersion(void);
    void CNF_ReadUUID(void);
    void CNF_WriteUUID(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGetVersion *frmGetVersion;
//---------------------------------------------------------------------------
#endif
