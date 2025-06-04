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
 *  file_utils.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  file utility source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.1  $
 * $Modtime:   Oct 25 2005 12:22:18  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Misc/file_utils.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Nov 7 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.1   Oct 25 2005 14:15:26   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.0   Sep 04 2005 11:24:26   mtk00490
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <fstream.h>
#include <vcl.h>

#pragma hdrstop

#include <io.h>

#ifndef  _FILE_UTILS_H_
#include "file_utils.h"
#endif

#ifndef  _META_UTILS_H_
#include "meta_utils.h"
#endif
//------------------------------------------------------------------------------
bool CheckFileExist( AnsiString as_fullfilename )
{

    ifstream ifs;
    ifs.open( as_fullfilename.c_str(), ios::in );
    if( ! ifs.is_open() )  return false;

    ifs.close();
    return true;

#if 0
    AnsiString as_path;
    AnsiString as_filename;
    AnsiString as_fileext;
    char buf[1024];
    char **filepart;

    getPathFromStr( as_fullfilename, as_path);
    getFilenameFromStr( as_fullfilename, as_filename );
    getFileExtFromStr( as_fullfilename, as_fileext );

    if( SearchPath( as_path.c_str(),
                    as_filename.c_str(),
                    as_fileext.c_str(),
                    sizeof(buf),
                    buf,
                    filepart
                  ) == NULL)
    {
        return false;
    }

    return true;
#endif
}
//---------------------------------------------------------------------------
bool getFileExtFromStr( AnsiString asStr, AnsiString &asFileExt )
{
    int iLD = asStr.LastDelimiter(".");
    if (iLD <= 0)
        return false;

    asFileExt = asStr.SubString( iLD+1, asStr.Length() );
    return true;
}
//---------------------------------------------------------------------------
AnsiString Get_WorkingDirectory(void)
{
    AnsiString asPath;
    getPathFromStr(Application->ExeName, asPath);

    return asPath;
}
//---------------------------------------------------------------------------
bool CheckDirectoryExist( AnsiString as_dirname )
{
    if((access(as_dirname.c_str(), 0)) == -1)
    {
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------
bool CheckOutputDirectoryExist( AnsiString as_filename )
{
    AnsiString path = ExtractFilePath(as_filename);
    if(path.IsEmpty())
    {
        return false;
    }
    if((access(path.c_str(), 0)) == -1)
    {
        return false;
    }
    return true;
}
