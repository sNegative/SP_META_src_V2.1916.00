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
 *   SDCardMonitor.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   Detect SD Card for recording or copying.
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
#include "SDCardMonitor.h"

#include <Classes.hpp>

#include <fstream>
#include <time.h>

#include "CommandExecutor.h"
#include "meta_utils.h"
#include "Logger.h"
#include <tlhelp32.h>
#include <io.h>

//***************SD card detect thread ****************//
class SDDetectThread : public TThread
{
public:
    __fastcall SDDetectThread(SDCardMonitor *monitor);

protected:
    void _fastcall Execute();

private:
    SDCardMonitor* monitor;
};
//---------------------------------------------------------------------------
__fastcall SDDetectThread::SDDetectThread(SDCardMonitor *sdmonitor) : TThread(true)
{
    this->monitor = sdmonitor;
}
//---------------------------------------------------------------------------
void __fastcall SDDetectThread::Execute()
{
    this->monitor->Execute();
}


//***********SD card Monitor implementations**************//
SDCardMonitor* SDCardMonitor::instance = NULL;
//---------------------------------------------------------------------------
const int SDCardMonitor::DEFAULT_TIMEOUT = 60;  //in seconds
//---------------------------------------------------------------------------
SDCardMonitor::SDCardMonitor()
    : observers()
{
    SetIsRunning(false);
    sTimeout = DEFAULT_TIMEOUT;

    AnsiString path;
    getPathFromStr(Application->ExeName, path);
    m_CWD = path.c_str();

    dtThread = NULL;
}
//---------------------------------------------------------------------------
void SDCardMonitor::AddObserver(SDCardListener * ob)
{
    if(ob != NULL)
    {
        observers.push_back(ob);
    }
}
//---------------------------------------------------------------------------
void SDCardMonitor::RemoveObserver(SDCardListener * ob)
{
    if(ob != NULL)
    {
        observers.remove(ob);
    }
}
//---------------------------------------------------------------------------
void SDCardMonitor::NotifySDCardEvent(SDCardEvent event)
{
//    for(std::list<const SDCardListener*>::const_iterator it = observers.begin();
    for(std::list< SDCardListener*>::iterator it = observers.begin();
            it!= observers.end(); ++it)
    {
        if(event == Mounted)
        {
            (*it)->OnSDCardMounted();
        }
        else
        {
            (*it)->OnSDCardTimeOut();
        }
    }
}
//---------------------------------------------------------------------------
void SDCardMonitor::Execute()
{
    SetIsRunning(true);

    time_t begin = time(NULL);
    SDCardEvent event;

    do
    {
        if(!GetIsRunning())
        {
            return;
        }
        if(!CheckSDCardMounted())
        {
            int delta = time(NULL)-begin;

            if(delta > sTimeout)
            {
                event = Timeout;
                break;
            }
            if(!GetIsRunning())
            {
                return;
            }
            Sleep(2000);

        }
        else
        {
            event = Mounted;
            break;
        }
    }
    while(1);

    NotifySDCardEvent(event);

    SetIsRunning(false);
}
//---------------------------------------------------------------------------
bool SDCardMonitor::Start()
{
    if(!GetIsRunning())
    {
        if(dtThread == NULL)
        {
            dtThread = new SDDetectThread(this);
        }
        dtThread->Resume();
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------
void SDCardMonitor::Stop()
{
    SetIsRunning(false);

    if(NULL != dtThread)
    {
//        delete dtThread;
        dtThread = NULL;
    }

// Kill adb.exe when disconnected.
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(NULL == snapshot) return;
    SHFILEINFO shSmall;
    PROCESSENTRY32 processinfo;
    processinfo.dwSize=sizeof(processinfo);

    BOOL status=Process32First(snapshot,&processinfo);
    AnsiString StrInfo;
    while(status)
    {
        ZeroMemory(&shSmall, sizeof(shSmall));
        SHGetFileInfo(processinfo.szExeFile, 0, &shSmall, sizeof(shSmall), SHGFI_ICON|SHGFI_SMALLICON);
        StrInfo = processinfo.szExeFile;
        AnsiString StrAdb="adb.exe";
        if(StrInfo == StrAdb)
        {
            DWORD dwProcessID = processinfo.th32ProcessID;
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, dwProcessID);
            ::TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            LOG("SDCardMonitor:: Close adb.exe succeeded");
        }
        status=Process32Next(snapshot, &processinfo);
    }

    std::string asPath(m_CWD);
    asPath.append("sdcard_info.log");

    if(0 == _access(asPath.c_str(), 0))
    {
        if(-1 == remove(asPath.c_str()))
        {
            LOG("SDCardMonitor:: Remove file %s failed", asPath.c_str());
        }
        else
        {
            LOG("SDCardMonitor:: Remove file %s succeeded", asPath.c_str());
        }
    }

    std::string asPath2(m_CWD);
    asPath2.append("adb_output.log");

    if(0 == _access(asPath2.c_str(), 0))
    {
        if(-1 == remove(asPath2.c_str()))
        {
            LOG("SDCardMonitor:: Remove file %s failed", asPath2.c_str());
        }
        else
        {
            LOG("SDCardMonitor:: Remove file %s succeeded", asPath2.c_str());
        }
    }
}
//---------------------------------------------------------------------------
bool SDCardMonitor::CheckSDCardMounted()
{
    if(!GetIsRunning())
    {
        return false;
    }
    std::string command("\"");
    command.append(m_CWD).append("adb.exe\" shell ls /sdcard/");

    std::string asPath(m_CWD);
    asPath.append("sdcard_info.log");
    CommandExecutor exec(command, asPath);
    std::string content;

    LOG(command.c_str());
    LOG(asPath.c_str());
    if(exec.Execute())
    {
        //parse file
        std::ifstream fs(asPath.c_str(), std::ios::binary);
        if(fs.is_open())
        {
            // get length of file:
            fs.seekg(0, std::ios::end);
            int length = fs.tellg();
            fs.seekg(0, std::ios::beg);

            // allocate memory:
            char *buffer = new char[length];

            // read data as a block:
            fs.read(buffer, length);
            fs.close();

            content = buffer;
            delete[] buffer;
            LOG("SDCardMonitor:: the buffer length is %d", length);
            if(content.find("LOST.DIR") != std::string::npos)
            {
                /*                if(-1 == remove(asPath.c_str()))
                                {
                                    LOG("SDCardMonitor:: Remove file %s failed", asPath.c_str());
                                }
                                else
                                {
                                    LOG("SDCardMonitor:: Remove file %s succeeded", asPath.c_str());
                                }    */
                return true;
            }
        }
    }

    return false;
}
//---------------------------------------------------------------------------
SDCardMonitor::~SDCardMonitor()
{
// Delete instance
    /*    if(NULL != dtThread)
        {
            delete dtThread;
            dtThread = NULL;
        }  */
// Delete instance
    /*    if(NULL != instance)
        {
            delete instance;
            instance = NULL;
        }   */
}
