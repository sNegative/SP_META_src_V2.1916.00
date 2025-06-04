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
 *   Logger.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   SP Meta Tool Log file.
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
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <stdarg.h>
#include <windows.h>

#include "Logger.h"

#pragma warn -8004
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
class LoggerImpl
{
public:
    LoggerImpl(const string& loggerName, Logger::Level baseLevel,
               Logger::Level curLevel);
    ~LoggerImpl();

    void AddLogHandle(const string& fileName, Logger::Level level);
    void AddLogHandle(ostream* stdStream, Logger::Level level);
    void RemoveAllLogHandle();

    void SetCurrentLevel(Logger::Level level)
    {
        m_CurLevel = level;
    }
    void SetBaseLevel(Logger::Level level)
    {
        m_BaseLevel = level;
    }
    bool Suppressed() const
    {
        return (m_CurLevel < m_BaseLevel);
    }
    string ContextInfo() const;
    string GetTimestamp() const;

    template<typename T>
    void Put(T obj);

    static string GetLevelString(Logger::Level level);

private:
    struct LogHandle
    {
        string FileName;
        Logger::Level HandleLevel;
        ostream* OutStream;
    };

    string m_LoggerName;
    Logger::Level m_CurLevel;
    Logger::Level m_BaseLevel;

    vector<LogHandle> m_LogHandles;
};
//---------------------------------------------------------------------------
string LoggerImpl::GetLevelString(Logger::Level level)
{
    switch (level)
    {
    case Logger::Verbose:
        return "V";
    case Logger::Debug:
        return "D";
    case Logger::Info:
        return "I";
    case Logger::Warn:
        return "W";
    case Logger::Error:
        return "E";
    case Logger::Off:
        return "OFF";
    default:
        return "UNKNOWN";
    }
}
//---------------------------------------------------------------------------
LoggerImpl::LoggerImpl(const string &loggerName, Logger::Level baseLevel,
                       Logger::Level curLevel) :
    m_LoggerName(loggerName), m_BaseLevel(baseLevel), m_CurLevel(curLevel)
{
}
//---------------------------------------------------------------------------
LoggerImpl::~LoggerImpl()
{
    RemoveAllLogHandle();
}
//---------------------------------------------------------------------------
string LoggerImpl::ContextInfo() const
{
    char infoBuffer[256] = { 0 };
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();
    SYSTEMTIME timestamp;
    GetLocalTime(&timestamp);
    sprintf(infoBuffer,
            "%02d/%02d/%02d %02d:%02d:%02d.%03d %s[%lu][%lu]:",
            timestamp.wMonth, timestamp.wDay, timestamp.wYear%100, timestamp.wHour,
            timestamp.wMinute, timestamp.wSecond, timestamp.wMilliseconds,
            m_LoggerName.c_str(), pid, tid);
    return string(infoBuffer);
}
//---------------------------------------------------------------------------
string LoggerImpl::GetTimestamp() const
{
    char infoTimestamp[_MAX_FNAME] = { 0 };
    SYSTEMTIME timestamp;
    GetLocalTime(&timestamp);
    sprintf(infoTimestamp,
            "%02d-%02d-%02d-%02d-%02d-%02d",
            timestamp.wMonth, timestamp.wDay, timestamp.wYear, timestamp.wHour,
            timestamp.wMinute, timestamp.wSecond);
    return string(infoTimestamp);
}
//---------------------------------------------------------------------------
void LoggerImpl::AddLogHandle(const string& fileName, Logger::Level level)
{
    assert(fileName != "");
    ofstream *fs = new ofstream(fileName.c_str(), std::ios_base::out
                                /* | std::ios_base::app*/);
    if (fs != NULL && fs->is_open())
    {
        LogHandle handle;
        handle.FileName = fileName;
        handle.HandleLevel = level;
        handle.OutStream = fs;
        m_LogHandles.push_back(handle);
    }
}
//---------------------------------------------------------------------------
void LoggerImpl::AddLogHandle(ostream* stdStream, Logger::Level level)
{
    assert(stdStream != NULL);
    LogHandle handle;
    handle.FileName = "";
    handle.HandleLevel = level;
    handle.OutStream = stdStream;
    m_LogHandles.push_back(handle);
}
//---------------------------------------------------------------------------
void LoggerImpl::RemoveAllLogHandle()
{
    for (vector<LogHandle>::const_iterator it = m_LogHandles.begin(); it
            != m_LogHandles.end(); ++it)
    {
        if (it->FileName != "" && it->OutStream)
        {
            delete it->OutStream;
        }
    }
    m_LogHandles.clear();
}
//---------------------------------------------------------------------------
template<typename T>
void LoggerImpl::Put(T obj)
{
    if (!Suppressed())
    {
        for (vector<LogHandle>::const_iterator it = m_LogHandles.begin(); it
                != m_LogHandles.end(); ++it)
        {
            if (m_CurLevel >= it->HandleLevel)
            {
                if (it->OutStream)
                {
                    *(it->OutStream) << obj;
                    it->OutStream->flush();
                }
            }
        }
    }
}

//---------------------------------------------------------------------------
//Logger
Logger::Logger(const string& loggerName, Level baseLevel)
{
    pimpl = new LoggerImpl(loggerName, baseLevel, Logger::Verbose);
}
//---------------------------------------------------------------------------
Logger::~Logger()
{
    if (pimpl)
    {
        pimpl->Put("\nLogger deinited.");
        delete pimpl;
    }
}
//---------------------------------------------------------------------------
string Logger::ContextInfo() const
{
    return pimpl->ContextInfo();
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(Level level)
{
    pimpl->SetCurrentLevel(level);
    return *this;
}
//---------------------------------------------------------------------------
void Logger::SetBaseLevel(Logger::Level level)
{
    pimpl->SetBaseLevel(level);
}
//---------------------------------------------------------------------------
void Logger::AddLogHandle(const string& fileName, Logger::Level level)
{
    pimpl->AddLogHandle(fileName, level);
}
//---------------------------------------------------------------------------
void Logger::AddLogHandle(ostream* stdStream, Logger::Level level)
{
    pimpl->AddLogHandle(stdStream, level);
}
//---------------------------------------------------------------------------
void Logger::RemoveAllLogHandle()
{
    pimpl->RemoveAllLogHandle();
}
//---------------------------------------------------------------------------
void Logger::Log(Level level, const char *pattern, ...)
{
    static char buffer[2048];
    va_list params;
    va_start(params, pattern);
    vsnprintf(buffer, 2048, pattern, params);
    va_end(params);
    *this << level;
    *this << ContextInfo();
    *this << buffer << std::endl;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(ostream& (*pf)(ostream&))
{
    pimpl->Put(pf);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(ios_base& (*pf)(ios_base&))
{
    pimpl->Put(pf);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(ios& (*pf)(ios&))
{
    pimpl->Put(pf);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(bool val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(short val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(unsigned short val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(int val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(unsigned int val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(long val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(unsigned long val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(float val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(double val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(long double val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(const void* val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(streambuf* sb)
{
    pimpl->Put(sb);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(const string& sb)
{
    pimpl->Put(sb);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(char val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator<<(const char* val)
{
    pimpl->Put(val);
    return *this;
}
//---------------------------------------------------------------------------
Logger& Logger::operator <<(const wchar_t* val)
{
    pimpl->Put(val);
    return *this;
}


//---------------------------------------------------------------------------
Logger& Logger::GetLogger()
{
    static Logger mLogger("SP_META");
    return mLogger;
}

//---------------------------------------------------------------------------
void Logger::DebugOnPath(const char * path)
{
    if(path==NULL)
    {
        path = "C:\\";
    }

    string logPath = path;
    logPath = logPath + "SP_META_TOOL.log";
    Logger::GetLogger().SetBaseLevel(Logger::Verbose);
    Logger::GetLogger().AddLogHandle(logPath, Logger::Verbose);
    Logger::GetLogger() << Logger::Verbose<<std::endl;
    Logger::GetLogger()<<Logger::Debug<<
                       "================================================================="
                       "================================================================="
                       <<std::endl<<"Smart Phone META Tool runtime trace is ON"<<std::endl<<
                       "================================================================="
                       "================================================================="
                       <<std::endl;
}
void Logger::DebugOn()
{
    DebugOnPath(NULL);
}

//---------------------------------------------------------------------------
void Logger::DebugOff()
{
    Logger::GetLogger()<<Logger::Debug<<
                       "================================================================="
                       "================================================================="
                       <<std::endl<<"Smart Phone META Tool runtime trace is OFF"<<std::endl<<
                       "================================================================="
                       "================================================================="
                       <<std::endl;
    Logger::GetLogger().SetBaseLevel(Logger::Off);
    Logger::GetLogger().RemoveAllLogHandle();
}

//---------------------------------------------------------------------------
void LogFunc::operator ()(const char * format,...)
{
    va_list params;
    static char msg[1024];

    va_start( params, format );
    _vsnprintf( msg, 1020, format, params );
    va_end( params );

    Logger::GetLogger()<<m_level;
    Logger::GetLogger()<<Logger::GetLogger().ContextInfo()
                       <<m_func<<"(): "
                       <<msg<<"("<<m_file<<","<<m_line<<")"<<std::endl;
}



