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
 *   Logger.h
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
#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>

class LoggerImpl;

class Logger
{
public:
    enum Level
    {
        Verbose = 0,
        Debug,
        Info,  //default for console mode
        Warn,
        Error,
        Off
    };

    void SetBaseLevel(Level baselevel);
    void AddLogHandle(const std::string& fileName, Logger::Level level);
    void AddLogHandle(std::ostream* stdStream, Logger::Level level);
    void RemoveAllLogHandle();

    std::string ContextInfo() const; //get time,logger name, pid, tid
    void Log(Level level,const char *pattern, ...);

    Logger& operator<<(Level curlevel);

    Logger& operator<< (bool val );
    Logger& operator<< (short val );
    Logger& operator<< (unsigned short val );
    Logger& operator<< (int val );
    Logger& operator<< (unsigned int val );
    Logger& operator<< (long val );
    Logger& operator<< (unsigned long val );
    Logger& operator<< (float val );
    Logger& operator<< (double val );
    Logger& operator<< (long double val );
    Logger& operator<< (const void* val );
    Logger& operator<< (char val);
    Logger& operator<< (const char* val);
    Logger& operator<< (const wchar_t* val);
    Logger& operator<< (std::streambuf* sb );
    Logger& operator<< (const std::string& sb );

    Logger& operator<<(std::ostream& (*pf)(std::ostream&));
    Logger& operator<< (std::ios& ( *pf )(std::ios&));
    Logger& operator<<(std::ios_base& (*pf)(std::ios_base&));

    ~Logger();
private:
    LoggerImpl *pimpl;
    Logger(const std::string& loggerName, Level baseLevel = Warn);

public:
    static Logger& GetLogger();
    static void DebugOn();
    static void DebugOnPath(const char *);
    static void DebugOff();
};

class LogFunc
{
public:
    Logger::Level m_level;
    char * m_func;
    char * m_file;
    int m_line;

    LogFunc(Logger::Level level, char * func, char * file,int line)
    {
        m_level = level;
        m_func = func;
        m_file = file;
        m_line = line;
    }
    void operator ()(const char * format,...);
};

#define LOG (LogFunc(Logger::Debug, __FUNC__, __FILE__, __LINE__))

#define TAG_CONSOLE "[CONSOLE MODE]"
#endif // _LOGGER_H
