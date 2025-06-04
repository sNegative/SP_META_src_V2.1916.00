/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*****************************************************************************/

#ifndef _COMMAND_LINE_ARGUMENTS_H
#define _COMMAND_LINE_ARGUMENTS_H

#include <stdexcept>
#include <string>
#include <vcl.h>

#include "Logger.h"


namespace ConsoleMode
{
    class CommandLineArguments
    {
    public:
        explicit CommandLineArguments(const std::wstring &commandLine);
        explicit CommandLineArguments();

    public:
        bool CommandLineArguments::GetConnect() const;
        bool CommandLineArguments::GetDisconnect() const;
        bool CommandLineArguments::GetSpecialTest() const;
        bool CommandLineArguments::GetNvramTest() const;
        bool CommandLineArguments::GetUintTest() const;
        bool CommandLineArguments::GetRemoveDriver() const;
        bool CommandLineArguments::GetFlagComPort() const;
        AnsiString CommandLineArguments::GetConfigFile() const;

    private:
        void Parse(const std::wstring &commandLine);

    private:
        bool m_Connect;
        bool m_Disconnect;
        bool m_SpecialTest;
        bool m_FlagComPort;
        bool m_NvramTest;
        bool m_UnitTest;
        bool m_RemoveDriver;
        bool m_FlagPort;
        AnsiString m_ConfigFile;
    };

    class InvalidCommandLineArgument : public std::logic_error
    {
    public:
        InvalidCommandLineArgument(const std::string &what);
    };
}

#endif // _COMMAND_LINE_ARGUMENTS_H
