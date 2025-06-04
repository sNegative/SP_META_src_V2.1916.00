/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*****************************************************************************/
#ifndef _CONSOLE_EXCUTE_H
#define _CONSOLE_EXCUTE_H

#include <stdexcept>
#include <string>
#include <vcl.h>

#include "Logger.h"
#include "CommandLineArguments.h"
#include "sp_brom.h"
#include "AUTH.h"
#include "SCERT.h"
#include "sla_challenge.h"

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif


extern  CNVRAMMan  *NVRAMMan;

namespace ConsoleMode
{
    typedef enum
    {
        BootROMUSB,
        PreloaderUSB,
        KernalUSB
    } USBType;


    class ConsoleExcute
    {
        public:
            ConsoleExcute();
            ConsoleExcute(CommandLineArguments *commandLineArguments);
        public:
            void ExcuteCommand();
            void CNF_NVRAMInitial( void );
            void DebugOnOff(bool onoff);
            int SearchPreloaderUSB();
            void  CNF_ReadNVRAM(const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData);
            void  CNF_WriteNVRAM( const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);
        private:
            CommandLineArguments * m_commandLineArguments;
            SP_BOOT_ARG_S *m_stArg;
            USBType eType;
            bool m_bMetaDebugOn;
            int BootStop;
            bool m_isUSB;
            bool b_open_NVRAM_database;
            AnsiString m_LID;
            AnsiString as_value;
            AnsiString as_str;
            unsigned char value;
            char  *m_pcCustHwBuf;
            int    m_iCustHwBufSize;
            int m_kernelUSB;
            unsigned int m_pcom;
            unsigned int m_kcom;
            HANDLE p_Nvram_Test_Event;
            int m_count;

        private:

            void SetMETAModeArg();
            void SetCommandLine(CommandLineArguments *commandLineArguments);
            int BootIntoMetaMode();
            void Connect(bool setcomm,bool flagport);
            int SerachKernelComport();
            void Parse_KernelFilterPIDVID(char* pKernelFilterPIDVID,unsigned int nFilterCount,unsigned int& nFilterPIDVIDCount);
            bool FetchFilterPIDVID(char *start, char *result);
            int ConnectInMetaModeByUSB();
            int ConnectInMetaModeByUART();
            int OpenDatabaseCommon(char* str );
            void ModifyNvram(int id);
            void BackupNvram();
            void Disconnect();
            void SetRecFieldValue();
            void WriteNvram();
            void ReadNvram();


    };
}

#endif // _CONSOLE_EXCUTE_H

