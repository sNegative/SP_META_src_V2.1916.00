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
 *   MfSetupUtil.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MF_Setup.txt file handler source
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
 * $Modtime:   Oct 25 2005 12:21:22  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/MF_Setup/MfSetupUtil.cpp-arc  $
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
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
 * Aug 14 2006 mtk00490
 * [STP100001065] [META] META ver 3.7.07
 *
 *
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
 *
 *
 * May 17 2006 mtk00490
 * [STP100000868] [META] META ver 3.7.05
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:22   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:06:58   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:20   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:58:08   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:14:42   mtk00490
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
#include <vcl.h>

#pragma hdrstop

#include "MfSetupUtil.h"

//------------------------------------------------------------------------------
///////////////////////////    Main menu     ///////////////////////////////////
//------------------------------------------------------------------------------
//==============================================================================
AnsiString read_field(AnsiString asSetupFile,AnsiString asExeName, AnsiString asSecName, AnsiString asFieldName, AnsiString asDefStr)
{
    AnsiString asPath;
    AnsiString as_str;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile(asSetupFile);
        if (ini != NULL)
        {
            as_str  = ini->ReadString(asSecName, asFieldName, asDefStr);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " read setup file " + asSetupFile + " error: " + asFieldName);
    }
    return as_str;
}

//---------------------------------------------------------------------------
void write_field(AnsiString asSetupFile, AnsiString asExeName, AnsiString asSecName, AnsiString asFieldName, AnsiString asStr)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString(asSecName, asFieldName, asStr );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " write setup file : " + asSetupFile + " error" + asStr);
    }
}

//-----------------------------------------------------------------------------------------
AnsiString read_Menu_selection( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_Menu_selection = read_field(asSetupFile, asExeName, "Main menu","Menu selection", "RF tool");
    return  as_Menu_selection;
}

//---------------------------------------------------------------------------
void write_Menu_selection( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_MenuSel )
{
    write_field(asSetupFile, asExeName, "Main menu","Menu selection", as_MenuSel);

}

//---------------------------------------------------------------------------
/*AnsiString read_GSM850_support(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_GSM850_support;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_GSM850_support  = ini->ReadString("Main menu","GSM850 support", "No");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (GSM850 support)");
    }
    return as_temp_GSM850_support;
}

//---------------------------------------------------------------------------
void write_GSM850_support( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_GSM850_support )
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("Main menu", "GSM850 support", as_GSM850_support);
            delete ini;
        }
    }
    catch (...)
    {
        AnsiString as_error_msg;
        as_error_msg = " META factory : write setup file(GSM850 support) : " + asSetupFile + " error ";
        Application->MessageBox( as_error_msg.c_str() , "Error", MB_OK );
    }
} */

//-----------------------------------------------------------------------------------------
AnsiString read_COM_PORT_SETTING( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    AnsiString as_COM_PORT_SETTING;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_COM_PORT_SETTING  = ini->ReadString("Main menu","COM PORT", "COM1");
            delete ini;
        }
    }
    catch (...)
    {
        AnsiString as_error_msg;
        as_error_msg = " META factory : read setup file : " + asSetupFile + " error ";
        Application->MessageBox( as_error_msg.c_str() , "Error", MB_OK );
    }
    return  as_COM_PORT_SETTING;
}

//---------------------------------------------------------------------------
void write_COM_PORT_SETTING( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Com )
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("Main menu", "COM PORT", as_Com );
            delete ini;
        }
    }
    catch (...)
    {
        AnsiString as_error_msg;
        as_error_msg = " META factory : write setup file : " + asSetupFile + " error ";
        Application->MessageBox( as_error_msg.c_str() , "Error", MB_OK );
    }
}

//------------------------------------------------------------------------------
AnsiString read_Baseband_chip(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Baseband_chip;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Baseband_chip  = ini->ReadString("Main menu","Baseband chip", "6205B");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Baseband_chip)");
    }
    return as_temp_Baseband_chip;
}

//---------------------------------------------------------------------------
void write_Baseband_chip(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Baseband_chip)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Baseband chip", as_Baseband_chip );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Baseband chip)");
    }
}

//==============================================================================
/*AnsiString read_Clock_rate(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Clock_rate;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Clock_rate  = ini->ReadString("Main menu","Clock rate", "26");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Clock rate)");
    }
    return as_temp_Clock_rate;
}

//---------------------------------------------------------------------------
void write_Clock_rate(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Clock_rate)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Clock rate", as_Clock_rate );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Clock rate)");
    }
}

//===============================================================================
AnsiString read_Flow_control(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Flow_control;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Flow_control  = ini->ReadString("Main menu","Flow control", "Software");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Flow_control)");
    }
    return as_temp_Flow_control;
}

//---------------------------------------------------------------------------
void write_Flow_control(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Flow_control)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Flow control", as_Flow_control);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Flow control)");
    }
}   */

//==============================================================================
AnsiString read_Sync_with_target_support(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Syn_with_target_support;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Syn_with_target_support  = ini->ReadString("Main menu","Syn with target support", "Yes");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Syn_with_target)");
    }
    return as_temp_Syn_with_target_support;
}

//---------------------------------------------------------------------------
void write_Sync_with_target_support(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Syn_with_target_support)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Syn with target support", as_Syn_with_target_support);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Syn with target support)");
    }
}

//==============================================================================
AnsiString read_Auto_control_power_supply(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Auto_control_power_supply;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Auto_control_power_supply  = ini->ReadString("Main menu","Auto control power supply", "Yes");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Auto control power supply)");
    }
    return as_temp_Auto_control_power_supply;
}

//---------------------------------------------------------------------------
/*void write_Auto_control_power_supply(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Auto_control_power_supply)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Auto control power supply", as_Auto_control_power_supply);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Auto control power supply)");
    }
}  */

//===============================================================================
AnsiString read_Baudrate(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Baudrate;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Baudrate  = ini->ReadString("Main menu","Baudrate", "115200");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Baudrate)");
    }
    return as_temp_Baudrate;
}

//---------------------------------------------------------------------------
void write_Baudrate(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Baudrate)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Baudrate", as_Baudrate);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " Main menu : write setup file : " + asSetupFile + " error (Baudrate)");
    }
}

//==============================================================================
AnsiString read_Disable_HW_flow_control(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Disable_HW_flow_control;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Disable_HW_flow_control  = ini->ReadString("Main menu","Disable HW flow control", "yes");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Disable_HW_flow_control)");
    }
    return as_temp_Disable_HW_flow_control;
}

//---------------------------------------------------------------------------
void write_Disable_HW_flow_control(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Disable_HW_flow_control)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("Main menu", "Disable HW flow control", as_Disable_HW_flow_control);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " Main menu : write setup file : " + asSetupFile + " error (Disable_HW_flow_control)");
    }
}

//==============================================================================
/*AnsiString read_TstMessageFormat(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TstMsgFormat = read_field(asSetupFile, asExeName, "Main menu", "TST message format", "2G");
    return  as_TstMsgFormat;
}

//------------------------------------------------------------------------------
void write_TstMessageFormat(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TstMessageFormat)
{
    write_field(asSetupFile, asExeName, "Main menu", "TST message format", as_TstMessageFormat);
} */

//==============================================================================
AnsiString read_Boot_timeout(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_BootTimeout = read_field(asSetupFile, asExeName, "Main menu", "Boot timeout", "infinite");
    return  as_BootTimeout;
}

//------------------------------------------------------------------------------
void write_Boot_timeout(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Boot_timeout)
{
    write_field(asSetupFile, asExeName, "Main menu", "Boot timeout", as_Boot_timeout);
}

//==============================================================================
AnsiString read_META_Connect_timeout(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_METAConnectTimeout = read_field(asSetupFile, asExeName, "Main menu", "META connect timeout", "30000");
    return  as_METAConnectTimeout;
}

//------------------------------------------------------------------------------
void write_META_Connect_timeout(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_METAConnectTimeout)
{
    write_field(asSetupFile, asExeName, "Main menu", "META connect timeout", as_METAConnectTimeout);
}

//==============================================================================
AnsiString read_PowerSupplyOnCount(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PowerSupplyOnCount = read_field(asSetupFile, asExeName, "Main menu", "Power Supply On Count", "5");
    return  as_PowerSupplyOnCount;
}

//-----------------------------------------------------------------------------
AnsiString read_PowerSupplyOffCount(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PowerSupplyOffCount = read_field(asSetupFile, asExeName, "Main menu", "Power Supply Off Count", "3");
    return  as_PowerSupplyOffCount;
}

//-----------------------------------------------------------------------------
AnsiString read_PowerSupplyTriggerTime(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PowerSupplyTriggerTime = read_field(asSetupFile, asExeName, "Main menu", "Power Supply Trigger Time", "1");
    return  as_PowerSupplyTriggerTime;
}

//==============================================================================
AnsiString read_Com_Port_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Main menu", "Com Port Filter", "");
    return  as_ComPortFilter;
}


//==============================================================================
AnsiString read_GUID(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_GUID = read_field(asSetupFile, asExeName, "Connection", "GUID", "");
    return  as_GUID;
}

//==============================================================================
AnsiString read_AuthenticationFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_AuthenticationFile = read_field(asSetupFile, asExeName, "Connection", "Authentication file", "");
    return  as_AuthenticationFile;
}

//------------------------------------------------------------------------------
void write_AuthenticationFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AuthenticationFile)
{
    write_field(asSetupFile, asExeName, "Connection", "Authentication file", as_AuthenticationFile);
}

AnsiString read_CertificateFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_CertificateFile = read_field(asSetupFile, asExeName, "Connection", "Certificate file", "");
    return  as_CertificateFile;
}

//------------------------------------------------------------------------------
void write_CertificateFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CertificateFile)
{
    write_field(asSetupFile, asExeName, "Connection", "Certificate file", as_CertificateFile);
}

//==============================================================================
AnsiString read_BROM_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Connection", "BROM port filter", "VID_0E8D&PID_0003");
    return  as_ComPortFilter;
}

//==============================================================================
AnsiString read_Preloader_Single_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Connection", "Preloader single port filter", "VID_0E8D&PID_2000");
    return  as_ComPortFilter;
}

//==============================================================================
AnsiString read_Kernel_Single_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Connection", "Kernel single port filter", "VID_0E8D&PID_2007");
    return  as_ComPortFilter;
}

//==============================================================================
AnsiString read_Kernel_Composite_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Connection", "Kernel composite port filter", "VID_0BB4&PID_2005");
    return  as_ComPortFilter;
}

//==============================================================================
AnsiString read_FirstStage_Timeout(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_timeout = read_field(asSetupFile, asExeName, "Connection", "First stage timeout(ms)", "20000");
    return  as_timeout;
}

//==============================================================================
AnsiString read_SecondStage_Timeout(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_timeout = read_field(asSetupFile, asExeName, "Connection", "Second stage timout(ms)", "20000");
    return  as_timeout;
}

//==============================================================================
AnsiString read_SecondStage_Delay(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_delay = read_field(asSetupFile, asExeName, "Connection", "Second stage delay(ms)", "1000");
    return  as_delay;
}


//==============================================================================
//Qin Qin 20120711
AnsiString read_Preloader_Composite_COMPort_Filter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComPortFilter = read_field(asSetupFile, asExeName, "Connection", "Preloader composite port filter", "VID_1004&PID_6000");
    return  as_ComPortFilter;
}

AnsiString read_DeviceType(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_DeviceType = read_field(asSetupFile, asExeName, "Connection", "Composite Preloader", "0");
    return  as_DeviceType;
}

AnsiString read_Kernel_Filter_Count(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_KernelFilterCount = read_field(asSetupFile, asExeName, "Connection", "Kernel COM port filter count(0~10)", "0");
    return  as_KernelFilterCount;
}
//==============================================================================
AnsiString read_Kernel_Filter_Type(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_KernelFilterType = read_field(asSetupFile, asExeName, "Connection", "Kernel COM port filter type(BlackList/WhiteList)", "WhiteList");
    return  as_KernelFilterType;
}

//==============================================================================
AnsiString read_Kernel_Filter_PIDVID(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_KernelFilterPIDVID = read_field(asSetupFile, asExeName, "Connection", "Kernel COM port filter PIDVID", "");
    return  as_KernelFilterPIDVID;
}
//

//add 20150421
AnsiString read_Query_WCNDriver_Ready(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_QueryWCNDriverReady = read_field(asSetupFile, asExeName, "Connection", "Query WCN Driver Ready", "0");
    return  as_QueryWCNDriverReady;
}

//==============================================================================


//==============================================================================
///////////////////////////////////  Audio  ////////////////////////////////////
//==============================================================================
AnsiString read_AcousticFirDirection(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Direction", "Tx");
    return  as_str;
}

//---------------------------------------------------------------------------
void write_AcousticFirDirection( AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str )
{
    write_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Direction", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AcousticFirBoundary(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Boundary", "Spec");
    return  as_str;
}

//---------------------------------------------------------------------------
void write_AcousticFirBoundary(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Boundary", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AcousticFirEquipment(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Equipment", "UPL");
    return  as_str;
}

//-----------------------------------------------------------------------------
void write_AcousticFirEquipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Equipment", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AcousticFirFileFormat(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "File Format", "Linear");
    return  as_str;
}

//-----------------------------------------------------------------------------
void write_AcousticFirFileFormat(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "File Format", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// AEC
AnsiString read_AECNvramDB(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "AEC", "NVRAM DB file", "BPLGUInfoCustom");
    return as_str;
}

//-----------------------------------------------------------------------------
void write_AECNvramDB(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "AEC", "NVRAM DB file", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AECInitialSettingFile(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "AEC", "Initial setting file", "aec_calibrate.ini");
    return as_str;
}

//----------------------------------------------------------------------------
void write_AECInitialSettingFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "AEC", "Initial setting file", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AECAudcoffDefaultH(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "AEC", "audcoff_default_h", "audcoff_default.h");
    return as_str;
}

//----------------------------------------------------------------------------
void write_AECAudcoffDefaultH(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "AEC", "audcoff_default_h", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AECOutputSpeechFirFile(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "AEC", "Output speech FIR file", "output_speech_fir.ini");
    return as_str;
}

//----------------------------------------------------------------------------
void write_AECOutputSpeechFirFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "AEC", "Output speech FIR file", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AECVolumeGainFile(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "AEC", "Volume gain file", "volume_gain.ini");
    return as_str;
}

//----------------------------------------------------------------------------
void write_AECVolumeGainFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "AEC", "Volume gain file", as_str);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_AcousticFirBoundaryFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Boundary File", "");
    return  as_str;
}

void write_AcousticFirBoundaryFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "8k Acoustic FIR Tunning", "Boundary File", as_str);
}


//==============================================================================
// META factory
//==============================================================================
AnsiString read_NVRAM_DATABASE_FILE(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","NVRAM database file", "D:\\Share\\BPLGInfo_W0336");
    return  as_str;
}

//---------------------------------------------------------------------------
void write_NVRAM_DATABASE_FILE(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_NVRAM_DATABASE_FILE)
{
    write_field(asSetupFile, asExeName, "META factory", "NVRAM database file", as_NVRAM_DATABASE_FILE );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_ConfigurationFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Configuration file", "D:\\Share\\abc.cfg");
    return  as_str;
}

//----------------------------------------------------------------------------
void write_ConfigurationFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ConfigurationFile)
{
    write_field(asSetupFile, asExeName, "META factory", "Configuration file", as_ConfigurationFile );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_LoggingFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Logging file", "D:\\Share\\abc.log");
    return  as_str;
}

//----------------------------------------------------------------------------
void write_LoggingFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_LogFile)
{
    write_field(asSetupFile, asExeName, "META factory","Logging file", as_LogFile );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_ResultFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Result file", "D:\\Share\\result.txt");
    return  as_str;
}

//----------------------------------------------------------------------------
void write_ResultFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResFile)
{
    write_field(asSetupFile, asExeName, "META factory","Result file", as_ResFile );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_InitialFile(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Calibration data initial file", "D:\\Share\\abc.ini");
    return  as_str;
}

//----------------------------------------------------------------------------
void write_InitialFile(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResFile)
{
    write_field(asSetupFile, asExeName, "META factory","Calibration data initial file", as_ResFile );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_ResultPath(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Calibration data result path", "D:\\Share\\");
    return  as_str;
}

//----------------------------------------------------------------------------
void write_ResultPath(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ResPath)
{
    write_field(asSetupFile, asExeName, "META factory","Calibration data result path", as_ResPath );
}

//================================================================================
AnsiString read_BARCODE(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_BARCODE;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_BARCODE  = ini->ReadString("META factory","BARCODE", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (BARCODE)");
    }
    return as_temp_BARCODE;
}

//---------------------------------------------------------------------------
void write_Barcode(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_BARCODE)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "BARCODE", as_BARCODE );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (BARCODE)");
    }
}

//------------------------------------------------------------------------------
AnsiString read_DELAY_TIME_BEFORE_ACCESS_NVRAM( AnsiString asSetupFile,
        AnsiString asExeName
                                              )
{
    AnsiString asPath;
    AnsiString as_temp_DELAY_TIME_BEFORE_ACCESS_NVRAM;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_DELAY_TIME_BEFORE_ACCESS_NVRAM  = ini->ReadString("META factory","DELAY_TIME_BEFORE_ACCESS_NVRAM", "10");
            delete ini;
        }
    }
    catch (...)
    {
        AnsiString as_error_msg;
        as_error_msg = " META factory : read setup file : " + asSetupFile + " error (DELAY_TIME_BEFORE_ACCESS_NVRAM)";
        Application->MessageBox( as_error_msg.c_str() , "Error", MB_OK );
    }
    return as_temp_DELAY_TIME_BEFORE_ACCESS_NVRAM;
}


//=========================================================================================
AnsiString read_Initial_value_from(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Initial_value_from;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Initial_value_from  = ini->ReadString("META factory","Initial value from", "INI file");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Initial value from)");
    }
    return as_temp_Initial_value_from;
}

//------------------------------------------------------------------------------
void write_Initial_value_from(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Initial_value_from)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Initial value from", as_Initial_value_from );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Initial value from)");
    }
}

//=========================================================================================
AnsiString read_RF_calibration(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_RF_calibration;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_RF_calibration  = ini->ReadString("META factory","RF calibration", "Yes");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (RF_calibration)");
    }
    return as_temp_RF_calibration;
}

//------------------------------------------------------------------------------
void write_RF_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RF_calibration)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "RF calibration", as_RF_calibration);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (RF calibration)");
    }
}

//==============================================================================
AnsiString read_AFC_Type(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_AFC_Type = read_field(asSetupFile, asExeName, "META factory", "AFC type", "TCVCXO");
    return  as_AFC_Type;
}

//------------------------------------------------------------------------------
void write_AFC_Type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AFC_Type)
{
    write_field(asSetupFile, asExeName, "META factory", "AFC type", as_AFC_Type);
}

//==============================================================================
AnsiString read_Crystal_CAP_ID(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_Crystal_CAP_ID = read_field(asSetupFile, asExeName, "META factory", "Crystal CAP ID", "run time update");
    return  as_Crystal_CAP_ID;
}

//------------------------------------------------------------------------------
void write_Crystal_CAP_ID(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Crystal_CAP_ID)
{
    write_field(asSetupFile, asExeName, "META factory", "Crystal CAP ID", as_Crystal_CAP_ID);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_CapIdCal(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_CapIdCal = read_field(asSetupFile, asExeName, "META factory", "Crystal CAP ID calibration", "yes");
    return as_CapIdCal;
}

//------------------------------------------------------------------------------
void write_CapIdCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CapIdCal)
{
    write_field(asSetupFile, asExeName, "META factory", "Crystal CAP ID calibration", as_CapIdCal);
}

//==============================================================================
AnsiString read_TxAfcOffsetCal(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TxAfcOffsetCal = read_field(asSetupFile, asExeName, "META factory", "TX AFC offset", "yes");
    return  as_TxAfcOffsetCal;
}

//------------------------------------------------------------------------------
void write_TxAfcOffsetCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxAfcOffsetCal)
{
    write_field(asSetupFile, asExeName, "META factory", "TX AFC offset", as_TxAfcOffsetCal);
}

//==============================================================================
AnsiString read_ResetRfTester(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ResetRfTester = read_field(asSetupFile, asExeName, "META factory", "Reset RF Tester", "yes");
    return  as_ResetRfTester;
}

//------------------------------------------------------------------------------
void write_ResetRfTester(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxAfcOffsetCal)
{
    write_field(asSetupFile, asExeName, "META factory", "Reset RF Tester", as_TxAfcOffsetCal);
}

//==============================================================================
AnsiString read_AFC(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_AFC = read_field(asSetupFile, asExeName, "META factory", "AFC", "yes");
    return  as_AFC;
}

//------------------------------------------------------------------------------
void write_AFC(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_AFC)
{
    write_field(asSetupFile, asExeName, "META factory", "AFC", as_AFC);
}

//==============================================================================
AnsiString read_RxPathLoss(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_RxPathLoss = read_field(asSetupFile, asExeName, "META factory", "RX path loss", "yes");
    return  as_RxPathLoss;
}

//------------------------------------------------------------------------------
void write_RxPathLoss(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RxPathLoss)
{
    write_field(asSetupFile, asExeName, "META factory", "RX path loss", as_RxPathLoss);
}

//==============================================================================
AnsiString read_TxIqCal(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TxIqCal = read_field(asSetupFile, asExeName, "META factory", "TX IQ calibration", "yes");
    return  as_TxIqCal;
}

//------------------------------------------------------------------------------
void write_TxIqCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxIqCal)
{
    write_field(asSetupFile, asExeName, "META factory", "TX IQ calibration", as_TxIqCal);
}

//==============================================================================
AnsiString read_IP2(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_IP2 = read_field(asSetupFile, asExeName, "META factory", "IP2", "yes");
    return  as_IP2;
}

//------------------------------------------------------------------------------
void write_IP2(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IP2)
{
    write_field(asSetupFile, asExeName, "META factory", "IP2", as_IP2);
}

//==============================================================================
AnsiString read_TxDcOffset(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TxDcOffset = read_field(asSetupFile, asExeName, "META factory", "TX DC offset", "yes");
    return  as_TxDcOffset;
}

//------------------------------------------------------------------------------
void write_TxDcOffset(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxDcOffset)
{
    write_field(asSetupFile, asExeName, "META factory", "TX DC offset", as_TxDcOffset);
}

//==============================================================================
AnsiString read_TxFbDac(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as = read_field(asSetupFile, asExeName, "META factory", "TX FB DAC calibraiton", "yes");
    return  as;
}

//------------------------------------------------------------------------------
void write_TxFbDac(AnsiString asSetupFile, AnsiString asExeName, AnsiString as)
{
    write_field(asSetupFile, asExeName, "META factory", "TX FB DAC calibraiton", as);
}

//==============================================================================
AnsiString read_TxPcl(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TxPcl = read_field(asSetupFile, asExeName, "META factory", "TX PCL", "yes");
    return  as_TxPcl;
}

//------------------------------------------------------------------------------
void write_TxPcl(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxPcl)
{
    write_field(asSetupFile, asExeName, "META factory", "TX PCL", as_TxPcl);
}

//==============================================================================
AnsiString read_TxSlowSkewCal(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as = read_field(asSetupFile, asExeName, "META factory", "TX slope skew calibration", "yes");
    return  as;
}

//------------------------------------------------------------------------------
void write_TxSlowSkewCal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as)
{
    write_field(asSetupFile, asExeName, "META factory", "TX slope skew calibration", as);
}
//==============================================================================
AnsiString read_TxPhaseErr(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_TxPhaseErr = read_field(asSetupFile, asExeName, "META factory", "TX phase error", "no");
    return  as_TxPhaseErr;
}

//------------------------------------------------------------------------------
void write_TxPhaseErr(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TxPhaseErr)
{
    write_field(asSetupFile, asExeName, "META factory", "TX phase error", as_TxPhaseErr);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_GMSK_TX_PCL_type(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_GMSK_TX_PCL_type = read_field(asSetupFile, asExeName, "META factory", "GMSK TX PCL type", "3 PCL");
    return  as_GMSK_TX_PCL_type;
}

//------------------------------------------------------------------------------
void write_GMSK_TX_PCL_type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TX_PCL_type)
{
    write_field(asSetupFile, asExeName, "META factory", "GMSK TX PCL type", as_TX_PCL_type);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_EPSK_TX_PCL_type(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_EPSK_TX_PCL_type = read_field(asSetupFile, asExeName, "META factory", "EPSK TX PCL type", "3 PCL");
    return  as_EPSK_TX_PCL_type;
}

//------------------------------------------------------------------------------
void write_EPSK_TX_PCL_type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TX_PCL_type)
{
    write_field(asSetupFile, asExeName, "META factory", "EPSK TX PCL type", as_TX_PCL_type);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_APC_GMSK_Modulation(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_APC_GMSK_Modulation = read_field(asSetupFile, asExeName, "META factory", "TX PCL GMSK modulation", "yes");
    return  as_APC_GMSK_Modulation;
}

//-----------------------------------------------------------------------------
void write_APC_GMSK_Modulation(AnsiString asSetupFile,AnsiString asExeName, AnsiString as_APC_GMSK_Mod)
{
    write_field(asSetupFile, asExeName, "META factory", "TX PCL GMSK modulation", as_APC_GMSK_Mod);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_APC_EPSK_Modulation(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_APC_EPSK_Modulation = read_field(asSetupFile, asExeName, "META factory", "TX PCL EPSK modulation", "yes");
    return  as_APC_EPSK_Modulation;
}

//---------------------------------------------------------------------------
void write_APC_EPSK_Modulation(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_APC_EPSK_Mod)
{
    write_field(asSetupFile, asExeName, "META factory", "TX PCL EPSK modulation", as_APC_EPSK_Mod);
}

//===========================================================================
AnsiString read_ADC_calibration(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ADC_cal = read_field(asSetupFile, asExeName, "META factory", "ADC calibration", "yes");
    return  as_ADC_cal;
}

//------------------------------------------------------------------------------
void write_ADC_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_ADC_calibration)
{
    write_field(asSetupFile, asExeName, "META factory", "ADC calibration", as_ADC_calibration);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_CV_calibration(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_CV_cal = read_field(asSetupFile, asExeName, "META factory", "CV calibration", "yes");
    return  as_CV_cal;
}

//----------------------------------------------------------------------------
void write_CV_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_CV_calibration)
{
    write_field(asSetupFile, asExeName, "META factory", "CV calibration", as_CV_calibration);
}

//=============================================================================
AnsiString read_WiFiTxDcOffset_calibration(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_WiFiTxDcOffset_calibration = read_field(asSetupFile, asExeName, "META factory", "WiFi TX DC offset calibration", "yes");
    return  as_WiFiTxDcOffset_calibration;
}

//------------------------------------------------------------------------------
void write_WiFiTxDcOffset_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_WiFiTxDcOffset_calibration)
{
    write_field(asSetupFile, asExeName, "META factory", "WiFi TX DC offset calibration", as_WiFiTxDcOffset_calibration);
}

//=============================================================================
AnsiString read_WiFiTxPower_calibration(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_WiFiTxPower_calibration = read_field(asSetupFile, asExeName, "META factory", "WiFi TX power calibration", "yes");
    return  as_WiFiTxPower_calibration;
}

//------------------------------------------------------------------------------
void write_WiFiTxPower_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_WiFiTxPower_calibration)
{
    write_field(asSetupFile, asExeName, "META factory", "WiFi TX power calibration", as_WiFiTxPower_calibration);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_BTCrystalCAPID_calibration(AnsiString asSetupFile, AnsiString asExeName)
{
    AnsiString as_BTCrystalCAPID_calibration = read_field(asSetupFile, asExeName, "META factory", "BT crystal CAP ID calibration", "yes");
    return  as_BTCrystalCAPID_calibration;
}

//------------------------------------------------------------------------------
void write_BTCrystalCAPID_calibration(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_BTCrystalCAPID_calibration)
{
    write_field(asSetupFile, asExeName, "META factory", "BT crystal CAP ID calibration", as_BTCrystalCAPID_calibration);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_PAType(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PAType = read_field(asSetupFile, asExeName, "META factory", "PA type", "RFMD3140");
    return  as_PAType;
}

//------------------------------------------------------------------------------
void write_PAType(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_PAType)
{
    write_field(asSetupFile, asExeName, "META factory", "PA type", as_PAType);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_PABiasType(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PABiasType = read_field(asSetupFile, asExeName, "META factory", "PA bias type", "Fixed");
    return  as_PABiasType;
}

//------------------------------------------------------------------------------
void write_PABiasType(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_PABiasType)
{
    write_field(asSetupFile, asExeName, "META factory", "PA bias type", as_PABiasType);
}

//=============================================================================
AnsiString read_Sky77328_APC_DC_Offset_cal(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_Sky77328_APC_DC_Offset_cal = read_field(asSetupFile, asExeName, "META factory", "Sky77328 APC DC Offset cal", "no");
    return  as_Sky77328_APC_DC_Offset_cal;
}

//------------------------------------------------------------------------------
void write_Sky77328_APC_DC_Offset_cal(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Sky77328_APC_DC_Offset_cal)
{
    write_field(asSetupFile, asExeName, "META factory", "Sky77328 APC DC Offset cal", as_Sky77328_APC_DC_Offset_cal);
}

//============================================================================
AnsiString read_RF_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_RF_calibration_equipment;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_RF_calibration_equipment  = ini->ReadString("META factory","RF calibration equipment", "Agilent 8960");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (RF calibration equipment)");
    }
    return as_temp_RF_calibration_equipment;
}

//------------------------------------------------------------------------------
void write_RF_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_RF_calibration_equipment)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "RF calibration equipment", as_RF_calibration_equipment );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (RF calibration equipment)");
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_WiFi_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_equipment = read_field(asSetupFile, asExeName, "META factory", "WiFi calibration equipment", "IQView");
    return  as_equipment;
}

//------------------------------------------------------------------------------
void write_WiFi_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_equipment)
{
    write_field(asSetupFile, asExeName, "META factory", "WiFi calibration equipment", as_equipment);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnsiString read_BT_calibration_equipment(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_equipment = read_field(asSetupFile, asExeName, "META factory", "BT calibration equipment", "CBT");
    return  as_equipment;
}

//------------------------------------------------------------------------------
void write_BT_calibration_equipment(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_equipment)
{
    write_field(asSetupFile, asExeName, "META factory", "BT calibration equipment", as_equipment);
}

//=========================================================================================
AnsiString read_Power_Supply_Type(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_Power_Supply_Type = read_field(asSetupFile, asExeName, "META factory","Power Supply Type", "Agilent 663x2");
    return  as_Power_Supply_Type;

#if 0
    AnsiString asPath;
    AnsiString as_temp_Power_Supply_Type;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Power_Supply_Type  = ini->ReadString("META factory","Power Supply Type", "Agilent 663x2");
            delete ini;
            return as_temp_Power_Supply_Type;
        }
        return ("Agilent 663x2");
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Power Supply Type)");
    }
#endif

}

//------------------------------------------------------------------------------
void write_Power_Supply_Type(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_Type)
{
    write_field(asSetupFile, asExeName, "META factory", "Power Supply Type", as_Power_Supply_Type);

#if 0
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Power Supply Type", as_Power_Supply_Type );
            delete ini;
            ini = NULL;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Power Supply Type)");
    }
#endif
}

//=========================================================================================
AnsiString read_Read_barcode_from_enter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Read_barcode_from_enter;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Read_barcode_from_enter  = ini->ReadString("META factory","Read barcode from enter", "none");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Read barcode from enter)");
    }
    return as_temp_Read_barcode_from_enter;
}

//------------------------------------------------------------------------------
void write_Read_barcode_from_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Read_barcode_from_enter)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Read barcode from enter", as_Read_barcode_from_enter );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Read barcode from enter)");
    }
}

//=========================================================================================
AnsiString read_Auto_start_calibration_enter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Auto_start_calibration_enter;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Auto_start_calibration_enter  = ini->ReadString("META factory","Auto start calibration enter", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Auto start calibration enter)");
    }
    return as_temp_Auto_start_calibration_enter;
}

//------------------------------------------------------------------------------
void write_Auto_start_calibration_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Auto_start_calibration_enter)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Auto start calibration enter", as_Auto_start_calibration_enter );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Auto start calibration enter)");
    }
}

//=========================================================================================
AnsiString read_Barcode_increasement_enter(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Barcode_increasement_enter;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Barcode_increasement_enter  = ini->ReadString("META factory","Barcode increasement enter", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Barcode increasement enter)");
    }
    return as_temp_Barcode_increasement_enter;
}

//------------------------------------------------------------------------------
void write_Barcode_increasement_enter(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_enter)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Barcode increasement enter", as_Barcode_increasement_enter );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Barcode increasement enter)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_NVRAM_exit(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_read_Save_barcode_to_NVRAM_exit;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_read_Save_barcode_to_NVRAM_exit  = ini->ReadString("META factory","Save barcode to NVRAM exit", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to NVRAM exit)");
    }
    return as_temp_read_Save_barcode_to_NVRAM_exit;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_NVRAM_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_NVRAM_exit)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to NVRAM exit", as_Save_barcode_to_NVRAM_exit );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to NVRAM exit)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_file_exit(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Save_barcode_to_file_exit;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Save_barcode_to_file_exit  = ini->ReadString("META factory","Save barcode to file exit", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to file exit)");
    }
    return as_temp_Save_barcode_to_file_exit;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_file_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_file_exit)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to file exit", as_Save_barcode_to_file_exit );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to file exit)");
    }
}

//=========================================================================================
AnsiString read_Barcode_increasement_exit(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Barcode_increasement_exit;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Barcode_increasement_exit  = ini->ReadString("META factory","Barcode increasement exit", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Barcode increasement exit)");
    }
    return as_temp_Barcode_increasement_exit;
}

//------------------------------------------------------------------------------
void write_Barcode_increasement_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_exit)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Barcode increasement exit", as_Barcode_increasement_exit );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Barcode increasement exit)");
    }
}
//=========================================================================================
AnsiString read_Terminate_META_exit(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Terminate_META_exit;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Terminate_META_exit  = ini->ReadString("META factory","Terminate META exit", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Terminate META exit)");
    }
    return as_temp_Terminate_META_exit;
}

//------------------------------------------------------------------------------
void write_Terminate_META_exit(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Terminate_META_exit)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Terminate META exit", as_Terminate_META_exit );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Terminate META exit)");
    }
}

//=========================================================================================
AnsiString read_Barcode_increasement_fail(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Barcode_increasement_fail;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Barcode_increasement_fail  = ini->ReadString("META factory","Barcode increasement when calibration fail", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Barcode increasement)");
    }
    return as_temp_Barcode_increasement_fail;
}

//------------------------------------------------------------------------------
void write_Barcode_increasement_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_fail)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Barcode increasement when calibration fail", as_Barcode_increasement_fail );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Barcode increasement  when calibration fail)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_NVRAM_fail(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Save_barcode_to_NVRAM_fail;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Save_barcode_to_NVRAM_fail  = ini->ReadString("META factory","Save barcode to NVRAM when calibration fail", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to NVRAM when calibration fail)");
    }
    return as_temp_Save_barcode_to_NVRAM_fail;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_NVRAM_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_save_to_NVRAM_fail)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to NVRAM when calibration fail", as_Barcode_save_to_NVRAM_fail );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to NVRAM when calibration fail)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_file_fail(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Save_barcode_to_file_fail;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Save_barcode_to_file_fail  = ini->ReadString("META factory","Save barcode to file when calibration fail", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to file when calibration fail)");
    }
    return as_temp_Save_barcode_to_file_fail;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_file_fail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_file_fail)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to file when calibration fail", as_Save_barcode_to_file_fail );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to file when calibration fail)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_NVRAM_success(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Save_barcode_to_NVRAM_success;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Save_barcode_to_NVRAM_success = ini->ReadString("META factory","Save barcode to NVRAM when calibration success", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to NVRAM when calibration success)");
    }
    return as_temp_Save_barcode_to_NVRAM_success;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_NVRAM_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_NVRAM_success)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to NVRAM when calibration success", as_Save_barcode_to_NVRAM_success );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to NVRAM when calibration success)");
    }
}

//=========================================================================================
AnsiString read_Save_barcode_to_file_success(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Save_barcode_to_file_success;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Save_barcode_to_file_success  = ini->ReadString("META factory","Save barcode to file when calibration success", "0");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Save barcode to NVRAM when calibration success)");
    }
    return as_temp_Save_barcode_to_file_success;
}

//------------------------------------------------------------------------------
void write_Save_barcode_to_file_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Save_barcode_to_file_success)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Save barcode to file when calibration success", as_Save_barcode_to_file_success );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Save barcode to file when calibration success)");
    }
}

//=========================================================================================
AnsiString read_Barcode_increasement_success(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_Barcode_increasement;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_Barcode_increasement  = ini->ReadString("META factory","Barcode increasement when calibration success", "1");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Barcode increasement when calibration success)");
    }
    return as_temp_Barcode_increasement;
}

//------------------------------------------------------------------------------
void write_Barcode_increasement_success(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Barcode_increasement_success)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "Barcode increasement when calibration success", as_Barcode_increasement_success );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Barcode increasement  when calibration success)");
    }
}
//=========================================================================================
AnsiString read_IMEI_read_from(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_IMEI_read_from;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_IMEI_read_from  = ini->ReadString("META factory","IMEI read from", "none");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (IMEI read from)");
    }
    return as_temp_IMEI_read_from;
}

//------------------------------------------------------------------------------
void write_IMEI_read_from(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_read_from)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "IMEI read from", as_IMEI_read_from );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (IMEI read from)");
    }
}


//=========================================================================================
AnsiString read_IMEI_save_to(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_IMEI_save_to;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_IMEI_save_to  = ini->ReadString("META factory","IMEI save to", "none");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (IMEI save to)");
    }
    return as_temp_IMEI_save_to;
}

//------------------------------------------------------------------------------
void write_IMEI_save_to(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_save_to)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "IMEI save to", as_IMEI_save_to );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (IMEI save to)");
    }
}

//=========================================================================================
AnsiString read_IMEI_increasement(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_IMEI_increasement;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_IMEI_increasement  = ini->ReadString("META factory","IMEI increasement", "1");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (IMEI increasement)");
    }
    return as_temp_IMEI_increasement;
}

//------------------------------------------------------------------------------
void write_IMEI_increasement(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_increasement)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            ini->WriteString("META factory", "IMEI increasement", as_IMEI_increasement );
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (IMEI increasement)");
    }
}

//------------------------------------------------------------------------------
///////////////////////////    Power supply table     //////////////////////////
//------------------------------------------------------------------------------
/*int read_NORMAL_VOLTAGE( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;
    int i_temp_NORMAL_VOLTAGE;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            i_temp_NORMAL_VOLTAGE  = ini->ReadInteger("Power supply table","NORMAL_VOLTAGE", 3800);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error ");
    }
    return i_temp_NORMAL_VOLTAGE;
}

//-----------------------------------------------------------------------------
int read_CURRENT_LIMIT( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_CURRENT_LIMIT = read_field(asSetupFile, asExeName, "Power supply table", "CURRENT_LIMIT", "3000");
    return  as_CURRENT_LIMIT.ToInt();
}

//---------------------------------------------------------------------------
int read_OFF_VOLTAGE( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString asPath;
    int i_temp_OFF_VOLTAGE;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            i_temp_OFF_VOLTAGE  = ini->ReadInteger("Power supply table","OFF_VOLTAGE", 0);
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error ");
    }
    return i_temp_OFF_VOLTAGE;
} */

//---------------------------------------------------------------------------
AnsiString read_661x_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_661x_GPIB_Address = read_field(asSetupFile, asExeName, "META factory","661x GPIB Address", "GPIB0::5::INSTR");
    return  as_661x_GPIB_Address;

}

//---------------------------------------------------------------------------
void write_661x_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr)
{
    write_field(asSetupFile, asExeName, "META factory", "661x GPIB Address", as_Power_Supply_GPIB_Addr);

}

//====================================================================================
AnsiString read_663x2_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_661x_GPIB_Address = read_field(asSetupFile, asExeName, "META factory","663x2 GPIB Address", "GPIB0::5::INSTR");
    return  as_661x_GPIB_Address;

}

//---------------------------------------------------------------------------
void write_663x2_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr)
{
    write_field(asSetupFile, asExeName, "META factory", "663x2 GPIB Address", as_Power_Supply_GPIB_Addr);
}

//====================================================================================
AnsiString read_E3631A_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_E3631A_GPIB_Address = read_field(asSetupFile, asExeName, "META factory","E3631A GPIB Address", "GPIB0::5::INSTR");
    return  as_E3631A_GPIB_Address;

}

//---------------------------------------------------------------------------
void write_E3631A_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_Power_Supply_GPIB_Addr)
{
    write_field(asSetupFile, asExeName, "META factory", "E3631A GPIB Address", as_Power_Supply_GPIB_Addr);
}

//====================================================================================
AnsiString read_Keithley2306_GPIB_Address( AnsiString asSetupFile, AnsiString asExeName )
{
    AnsiString as_str = read_field(asSetupFile, asExeName, "META factory","Keithley 2306 GPIB Address", "GPIB0::16::INSTR");
    return  as_str;

}

//---------------------------------------------------------------------------
void write_Keithley2306_GPIB_Address(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_str)
{
    write_field(asSetupFile, asExeName, "META factory", "Keithley 2306 GPIB Address", as_str);
}

//====================================================================================
AnsiString read_IMEI(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_IMEI;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile(asSetupFile);
        if (ini != NULL)
        {
            as_temp_IMEI  = ini->ReadString("META factory","IMEI", "0000");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (IMEI)");
    }
    return as_temp_IMEI;
}

//---------------------------------------------------------------------------
void write_IMEI(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_without_CheckSum)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("META factory", "IMEI", as_IMEI_without_CheckSum );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (IMEI)");
    }
}

//====================================================================================
AnsiString read_TurnOffPowerSupplyFail(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_TurnOffPowerSupplyFail;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_TurnOffPowerSupplyFail  = ini->ReadString("META factory", "Turn off power supply when calibration fail", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Turn off power supply when calibration fail)");
    }
    return as_temp_TurnOffPowerSupplyFail;
}

//---------------------------------------------------------------------------
void write_TurnOffPowerSupplyFail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TurnOffPowerSupplyFail)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("META factory", "Turn off power supply when calibration fail", as_TurnOffPowerSupplyFail );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Terminate META when calibration fail)");
    }
}

//====================================================================================
AnsiString read_TerminateMETAFail(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_TerminateMETAFail;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_TerminateMETAFail  = ini->ReadString("META factory", "Terminate META when calibration fail", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Terminate META when calibration fail)");
    }
    return as_temp_TerminateMETAFail;
}

//---------------------------------------------------------------------------
void write_TerminateMETAFail(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TerminateMETAFail)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("META factory", "Terminate META when calibration fail", as_TerminateMETAFail );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Terminate META when calibration fail)");
    }
}

//====================================================================================
AnsiString read_TurnOffPowerSupplySuccess(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_TurnOffPowerSupplySuccess;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_TurnOffPowerSupplySuccess  = ini->ReadString("META factory", "Turn off power supply when calibration success", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Turn off power supply when calibration success)");
    }
    return as_temp_TurnOffPowerSupplySuccess;
}

//---------------------------------------------------------------------------
void write_TurnOffPowerSupplySuccess(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TurnOffPowerSupplySuccess)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("META factory", "Turn off power supply when calibration success", as_TurnOffPowerSupplySuccess );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Terminate META when calibration success)");
    }
}

//====================================================================================
AnsiString read_TerminateMETASuccess(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_TerminateMETASuccess;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_TerminateMETASuccess  = ini->ReadString("META factory", "Terminate META when calibration success", "no");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " META factory : read setup file : " + asSetupFile + " error (Terminate META when calibration success)");
    }
    return as_temp_TerminateMETASuccess;
}

//---------------------------------------------------------------------------
void write_TerminateMETASuccess(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_TerminateMETASuccess)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("META factory", "Terminate META when calibration success", as_TerminateMETASuccess );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " META factory : write setup file : " + asSetupFile + " error (Terminate META when calibration success)");
    }
}

//==========================================================================================
///////////////////////////////////// IMEI download ////////////////////////////////////////
//==========================================================================================
AnsiString read_IMEI_NVRAM_DATABASE_FILE(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asPath;
    AnsiString as_temp_IMEI_NVRAM_DATABASE_FILE;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );
        if(ini != NULL)
        {
            as_temp_IMEI_NVRAM_DATABASE_FILE  = ini->ReadString("IMEI Download","NVRAM database file", "BPLGInfo");
            delete ini;
        }
    }
    catch (...)
    {
        ShowMessage( " IMEI download : read setup file : " + asSetupFile + " error (IMEI_NVRAM_DATABASE_FILE)");
    }
    return as_temp_IMEI_NVRAM_DATABASE_FILE;
}

//---------------------------------------------------------------------------
void write_IMEI_NVRAM_DATABASE_FILE(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_IMEI_NVRAM_DATABASE_FILE)
{
    AnsiString asPath;
    if ( getPathFromStr(asExeName, asPath) &&
            withPath( asPath) &&
            !withPath( asSetupFile)
       )
    {
        asSetupFile = asPath + asSetupFile;
    }

    TIniFile *ini;

    try
    {
        ini = new TIniFile( asSetupFile );

        if(ini != NULL)
        {
            ini->WriteString("IMEI Download", "NVRAM database file", as_IMEI_NVRAM_DATABASE_FILE );
            delete ini;
        }

    }
    catch (...)
    {
        ShowMessage( " IMEI download : write setup file : " + asSetupFile + " error (IMEI_NVRAM_DATABASE_FILE)");
    }
}

//==============================================================================
/////////////////////////////    BT tool  //////////////////////////////////////
//==============================================================================
AnsiString read_HCI_File( AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_str = read_field( asSetupFile, asExeName, "BT Tool","HCI file", "C:\\HCI.txt" );
    return  as_str;
}

//---------------------------------------------------------------------------
void write_HCI_File(AnsiString asSetupFile, AnsiString asExeName, AnsiString as_HCI_file )
{
    write_field( asSetupFile, asExeName, "BT Tool","HCI file", as_HCI_file );
}

AnsiString read_Console_ConnectType(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ConnectType = read_field(asSetupFile, asExeName, "Console Mode Connect", "COM PORT", "USB");
    return  as_ConnectType;
}

AnsiString read_Console_ComFindType(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ComFindType = read_field(asSetupFile, asExeName, "Console Mode Connect", "Find com port by number", "yes");
    return  as_ComFindType;
}
AnsiString read_Console_PreloaderComPort(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PreloaderComPort = read_field(asSetupFile, asExeName, "Console Mode Connect", "Fixed preloader com port number", NULL);
    return  as_PreloaderComPort;
}
AnsiString read_Console_KernelComPort(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_PreloaderComPort = read_field(asSetupFile, asExeName, "Console Mode Connect", "Fixed kernel com port number", NULL);
    return  as_PreloaderComPort;
}
AnsiString read_Console_NvramDBPath(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_NvramPath = read_field(asSetupFile, asExeName, "Console Mode Nvram Test", "Nvram database path", NULL);
    return  as_NvramPath;
}

AnsiString read_Console_ModifyCount(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_ModifyCount = read_field(asSetupFile, asExeName, "Console Mode Nvram Test", "Modify count", 0);
    return  as_ModifyCount;
}

AnsiString read_Console_ModifyLID(int id,AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asSecName = "Nvram Modify Group" + IntToStr(id);
    AnsiString as_ModifyLID = read_field(asSetupFile, asExeName, asSecName, "LID", NULL);
    return  as_ModifyLID;
}
AnsiString read_Console_ModifyVariable(int id,AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asSecName = "Nvram Modify Group" + IntToStr(id);
    AnsiString as_ModifyVariable = read_field(asSetupFile, asExeName, asSecName, "Variable", NULL);
    return  as_ModifyVariable;
}
AnsiString read_Console_ModifyValue(int id,AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString asSecName = "Nvram Modify Group" + IntToStr(id);
    AnsiString as_ModifyValue = read_field(asSetupFile, asExeName, asSecName, "Value", NULL);
    return  as_ModifyValue;
}
AnsiString read_LogPath(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_LogPath = read_field(asSetupFile, asExeName, "Main menu", "META log path",NULL);
    return  as_LogPath;
}

AnsiString read_NVRAMBackupRestoreTimeout(AnsiString asSetupFile,AnsiString asExeName)
{
    AnsiString as_NvramTimeout = read_field(asSetupFile, asExeName, "Connection", "NVRAM backup restore timout(ms)", "40000");
    return  as_NvramTimeout;
}
