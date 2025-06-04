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
 *   get_version.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Get version source
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
 * $Modtime:   Oct 25 2005 12:10:14  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Get Version/get_version.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:08   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:06:32   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:00   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:57:28   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:13:56   mtk00490
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
#include <vcl.h>
#include <IniFiles.hpp>

#pragma hdrstop

#include "get_version.h"
#include "man_active.h"

//==============================================================================
static CGETVERSION  *get_version_ptr;
static bool g_bIsRunning;
//---------------------------------------------------------------------------
static void __stdcall CNF_GetTargetVersion(const VerInfo_Cnf  *cnf, const short token, void *usrData)
{
    get_version_ptr->CNF_GetTargetVersion( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    get_version_ptr->REQ_Finish();
}

//=============================================================================
CGETVERSION::CGETVERSION( void )
{
	  m_iConfirmState = 0;
	  GETID_VERSION = 0;
	  ConfirmCallback = NULL;
}

//----------------------------------------------------------------------------
CGETVERSION::~CGETVERSION( )
{

}

//---------------------------------------------------------------------------
void  CGETVERSION::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_GET_VERSION_OK );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CGETVERSION::REQ_Stop( void )
{
    if(!g_bIsRunning)  return;

    SP_META_Cancel_r( m_META_HANDLE_Obj.Get_MainHandle(), GETID_VERSION );
    Confirm( STATE_GET_VERSION_STOP );
    g_bIsRunning = false;
}  */

//------------------------------------------------------------------------------
void  CGETVERSION::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;

    SP_META_Cancel_r( m_META_HANDLE_Obj.Get_MainHandle(), GETID_VERSION );
    Confirm( STATE_GET_VERSION_TIMEOUT );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CGETVERSION::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//==============================================================================
bool CGETVERSION::GetTargetVersion(void)
{
    get_version_ptr = this;
    g_bIsRunning = true;
    MetaResult = SP_META_GetTargetVerInfo_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_GetTargetVersion, &GETID_VERSION, NULL);
    if(MetaResult!=META_SUCCESS)
    {
        Confirm( STATE_GET_VERSION_FAIL );
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
void CGETVERSION::CNF_GetTargetVersion(const VerInfo_Cnf  *cnf, const short token, void *usrData)
{
    if( ! g_bIsRunning )
        return;

    VerInfo = *cnf;

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//---------------------------------------------------------------------------
//===========================================================================
bool  CGETVERSION::REQ_Read_From_File( char *filename )
{
    TIniFile   *ini_file;
    AnsiString  as;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return false;

    as = ini_file->ReadString( "Version",
                               "BaseBand chip version",
                               0 );
    strcpy(VerInfo.BB_CHIP, as.c_str());


    as = ini_file->ReadString( "Version",
                               "ECO version",
                               0 );
    strcpy(VerInfo.ECO_VER, as.c_str());


    as = ini_file->ReadString( "Version",
                               "DSP firmware version",
                               0 );
    strcpy(VerInfo.DSP_FW, as.c_str());


    as = ini_file->ReadString( "Version",
                               "DSP patch version",
                               0 );
    strcpy(VerInfo.DSP_PATCH, as.c_str());


    as = ini_file->ReadString( "Version",
                               "Software version",
                               0 );
    strcpy(VerInfo.SW_VER, as.c_str());


    as = ini_file->ReadString( "Version",
                               "Hardware version",
                               0 );
    strcpy(VerInfo.HW_VER, as.c_str());

    as = ini_file->ReadString( "Version",
                               "Melody version",
                               0 );
    strcpy(VerInfo.MELODY_VER, as.c_str());


    delete  ini_file;
    return true;
}

//===========================================================================
bool  CGETVERSION::REQ_Write_To_File( char *filename )
{
    TIniFile   *ini_file;

    ini_file = new TIniFile( filename );
    if( ini_file == NULL )  return  false;

    ini_file->WriteString( "Version",
                           "BaseBand chip version",
                           VerInfo.BB_CHIP );

    ini_file->WriteString( "Version",
                           "ECO version",
                           VerInfo.ECO_VER );

    ini_file->WriteString( "Version",
                           "DSP firmware version",
                           VerInfo.DSP_FW );

    ini_file->WriteString( "Version",
                           "DSP patch version",
                           VerInfo.DSP_PATCH );

    ini_file->WriteString( "Version",
                           "Software version",
                           VerInfo.SW_VER );

    ini_file->WriteString( "Version",
                           "Hardware version",
                           VerInfo.HW_VER );

    ini_file->WriteString( "Version",
                           "Melody version",
                           VerInfo.MELODY_VER );

    delete  ini_file;
    return  true;
}

//==========================================================================
bool  CGETVERSION::Get_VerInfo( VerInfo_Cnf &verinfo )
{
    verinfo = VerInfo;
    return true;
}

//--------------------------------------------------------------------------
bool  CGETVERSION::Set_VerInfo( VerInfo_Cnf &verinfo )
{
    VerInfo = verinfo;
    return true;
}
//==============================================================================
bool CGETVERSION::GetEncryptSupport(CRYPTFS_QUERYSUPPORT_CNF * pCnf)
{
    get_version_ptr = this;
    g_bIsRunning = true;
    MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, "SP_META_ENCRYPTED_Support_r");
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    MetaResult = SP_META_ENCRYPTED_Support_r(m_META_HANDLE_Obj.Get_MainHandle(), 60000, pCnf);
    if(MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}
//----------------------------------------------------------------------------
bool CGETVERSION::GetEncryptVeritif(CRYPTFS_VERITIF_REQ * pReq, CRYPTFS_VERITIF_CNF * pCnf)
{
    get_version_ptr = this;
    g_bIsRunning = true;
    MetaResult = SP_META_ENCRYPTED_VertifyPwd_r(m_META_HANDLE_Obj.Get_MainHandle(), 60000, pReq, pCnf);
    if(MetaResult != META_SUCCESS)
    {
        return false;
    }
    return true;
}
//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
int  CGETVERSION::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}
//----------------------------------------------------------------------------

