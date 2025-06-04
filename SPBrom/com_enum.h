/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  com_enum.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  Enumerate serial ports.
 *
 * Author:
 * -------
 *  Amos Hsu (mtk00539)
 *
 *==============================================================================
 *           HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: #1 $
 * $Modtime:   Dec 29 2005 10:02:44  $
 * $Log:   //mtkvs01/vmdata/flash_tool/archives/BootRom/com_enum.h-arc  $
 *
 *    Rev 1.3   Dec 29 2005 10:42:30   mtk00539
 *  1. [BROM_DLL] Add UsbComPortEnumerate() function for USB COM port enumeration.
 * Resolution for 156: [FlashTool v2.7.1013][BUG FIX] Fix BootROM start command failure while manually selecting NMT6226 or MT6227 baseband chip.
 *
 *    Rev 1.2   Mar 29 2004 09:25:50   mtk00539
 * [brom.dll][Enhance] enumerate com port from registry
 *
 *    Rev 1.1   Feb 05 2004 14:13:50   mtk00539
 * supposupport multiple concatanated bin files download.
 * Resolution for 46: [BootRom v2.2.1001][New] support multiple concatanated bin files download.
 *
 *    Rev 1.0   Dec 12 2003 18:57:04   admin
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _COM_ENUM_H_
#define _COM_ENUM_H_
//#include "host.h"

#define	COM_ENUM_OK						0
#define	COM_ENUM_INVALID_ARGUMENT		1
#define	COM_ENUM_NO_COM_PORT_FOUND		2
#define	COM_ENUM_COM_ARRAY_TOO_SMALL	3
#define	COM_ENUM_ERROR					4
#define C_MAX_COM_NAME_LEN              260

typedef enum
{
    COM_ENUM_BY_CREATEFILE = 0,
    COM_ENUM_BY_REGISTRY,
} COM_ENUM_METHOD;

typedef struct
{
    char name[C_MAX_COM_NAME_LEN];
} COM_ENUM_PORT;

#define C_MAX_PREFIX_NUM 8
typedef struct
{
    COM_ENUM_METHOD method;
    char *prefix[C_MAX_PREFIX_NUM];
    bool bUSBOnly;
} COM_ENUM_ARG;

#ifdef	__cplusplus
extern "C" {
#endif

    LIBEXPORT int __stdcall ComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
    LIBEXPORT int __stdcall ComPortEnumerateWithPrefix(unsigned short *p_com_port_array, unsigned short *p_com_port_count, const char *registryValuePrefix);
    LIBEXPORT int __stdcall ComPortEnumerateEx(COM_ENUM_METHOD  method, unsigned short *p_com_port_array, unsigned short *p_com_port_count);
    LIBEXPORT int __stdcall UsbComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
    LIBEXPORT int __stdcall ComPortEnumerateByArg(COM_ENUM_ARG *p_arg, COM_ENUM_PORT* p_com_port_array, unsigned short *p_com_port_count);

#ifdef	__cplusplus
}
#endif

#endif
