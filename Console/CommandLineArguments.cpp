/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*****************************************************************************/

#include <atlbase.h>
#include <iostream>
#include <stdexcept>

#include "CommandLineArguments.h"
#include "argcargv.h"
#include "XGetopt.h"

#ifndef  _MAN_METADLL_H_
#include "man_metadll.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

using ConsoleMode::CommandLineArguments;
using ConsoleMode::InvalidCommandLineArgument;
using std::string;
using std::wstring;

const string CONSOLE_MODE_USAGE(
    "\nUsage: Meta2.exe OPTION...\n"
    "Run Sp Meta Tool in console mode.\n"
    "Example:  Meta2.exe -i config_file\n"
    "\nMandatory:\n"
    "  -i    console mode configuration file\n"
    "\nOverwriting settings specified in the configuration file:\n"
    "  -p    COM port\n"
    "  -d    download agent file path\n"
    "\nMiscellaneous:\n"
    "  -o    specify a BROM DLL log file path (default: C:\\BROM_DLL.log)\n"
    "  -q    suppress console mode messages\n"
    "  -v    show all console mode messages\n"
    "  -h    display this help and exit\n"
);


CommandLineArguments::CommandLineArguments()
{
    m_Connect=false;
    m_Disconnect=false;
    m_SpecialTest=false;
    m_NvramTest=false;
    m_UnitTest=false;
    m_RemoveDriver=false;
    m_FlagPort=false;
}

CommandLineArguments::CommandLineArguments(const wstring &commandLine)
{
    CommandLineArguments();
    Parse(commandLine);
}

bool CommandLineArguments::GetConnect() const
{
    return m_Connect;
}

bool CommandLineArguments::GetDisconnect() const
{
    return m_Disconnect;
}

bool CommandLineArguments::GetSpecialTest() const
{
    return m_SpecialTest;
}

bool CommandLineArguments::GetNvramTest() const
{
    return m_NvramTest;
}

bool CommandLineArguments::GetUintTest() const
{
    return m_UnitTest;
}

bool CommandLineArguments::GetRemoveDriver() const
{
    return m_RemoveDriver;
}

bool CommandLineArguments::GetFlagComPort() const
{
    return m_FlagPort;
}

AnsiString CommandLineArguments::GetConfigFile() const
{
    if(m_ConfigFile!="")
        return m_ConfigFile;
    else
        return "MF_setup.txt";
}
void CommandLineArguments::Parse(const wstring &commandLine)
{
    USES_CONVERSION;
    static bool firstTime = true;
    bool bConnected = false;
    const int argc = _ConvertCommandLineToArgcArgv(commandLine.c_str());

    while (1)
    {
        int c = getopt(argc, _ppszArgv, L"cfnd:");
        if (c == EOF)
        {
            break;
        }
        m_ConfigFile = optarg;
        LOG(TAG_CONSOLE "ConfigFile=\"%s\"",m_ConfigFile);
        switch (c)
        {
            case L'c':
                LOG(TAG_CONSOLE "case c");
                m_Connect = true;
                break;
            case L'n':
                LOG(TAG_CONSOLE "case n");
                m_NvramTest = true;
                break;
            case L'f':
                LOG(TAG_CONSOLE "case f");
                m_FlagPort = true;
                break;
            case L'd':
                LOG(TAG_CONSOLE "case d");
                m_Disconnect = true;
                break;

           /* case L'i':
                LOG(TAG_CONSOLE "case u");
                m_UnitTest = true;
                break;
            case L's':
                LOG(TAG_CONSOLE "case s");
                m_SpecialTest = true;
                break;
            case L'r':
                LOG(TAG_CONSOLE "case r");
                m_RemoveDriver = true;
                break;
            case L'h':
                LOG(TAG_CONSOLE "case h");
                std::cout << CONSOLE_MODE_USAGE;
                exit(0);
                break;
            case L'q':
                LOG(TAG_CONSOLE "case q");
                exit(0);
            */
            default:
                LOG(TAG_CONSOLE "case default");
                std::cout << CONSOLE_MODE_USAGE;
        
        }
    }
}

InvalidCommandLineArgument::InvalidCommandLineArgument(const string &what)
    : std::logic_error(what)
{
}













