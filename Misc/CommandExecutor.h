#ifndef _COMMAND_EXECUTOR_H
#define _COMMAND_EXECUTOR_H

#include <iostream>
#include <windows.h>

class CommandExecutor
{
public:
    CommandExecutor(const std::string& command, const std::string& outputFile);
    ~CommandExecutor();
    bool Execute();

    DWORD GetLastErr() const
    {
        return mLastErr;
    }
    DWORD GetExitCode() const
    {
        return mExitCode;
    }
private:
    std::string mCommand;
    std::string mOutFile;
    DWORD mLastErr;
    DWORD mExitCode;
};

#endif