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
 *  mtk_mcu.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  The definition of MediaTek chip types and external clock arguments.
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
 * $Modtime:   Dec 28 2005 20:07:46  $
 * $Log:   //mtkvs01/vmdata/flash_tool/archives/BootRom/mtk_mcu.h-arc  $
 *
 * Jul 11 2008 mtk01413
 * [STP100001750] [FlashTool] v3.0828.0 release
 *
 *
 * May 16 2008 mtk01413
 * [STP100001708] [FlashTool] v3.0820.0 release
 * New features:
 *  1. MT6238 Download
 *  2. MT6235 Download
 *
 *
 * Dec 3 2007 mtk01413
 * [STP100001568] [FlashTool] v3.0748.0 release
 *
 *
 * Aug 30 2007 mtk01413
 * [STP100001497] [FlashTool] v3.2.0 release
 * New features:
 *  1. [BROM_DLL/DA] Support MT6226D  download.
 *  2. [BROM_DLL/DA] Support MT6223P  download.
 *
 * Jan 2 2007 mtk01413
 * [STP100001195] FlashTool v3.1.02 release
 * New features:
 *  1. [BROM_DLL/DA] Support FOTA(Firmware update Over The Air) download.
 *  2. [BROM_DLL/DA] Support MT6223  download.
 *  3. [BROM_DLL/DA] Support MT6268T download.
 *  4. [DA] Supports new NOR Flash device
 * 		[SPANSION] S29GL128NH
 * 		[SPANSION] S29GL128NL
 * 		[SPANSION] S29GL256NH
 * 		[SPANSION] S29GL256NL
 * 		[SPANSION] S29GL512NH
 * 		[SPANSION] S29GL512NL
 *
 * Enhancements:
 *  1. [DA] Support BBC(Blank Block Check) for NOR Flash Format.
 *  2. [BROM_DLL/DA] Support Retransmit mechanism for NAND Readback operation.
 *  3. [BROM_DLL] Enhance E-NFB Check.
 *
 *
 * Sep 27 2006 mtk00539
 * [STP100001145] FlashTool v3.1.01 release
 *
 *
 * Aug 14 2006 mtk00539
 * [STP100001057] FlashTool v3.1.00 release
 *
 *
 *    Rev 1.13   Dec 29 2005 10:42:02   mtk00539
 *  1. [BROM_DLL] Support new baseband chip MT6226M.
 * Resolution for 156: [FlashTool v2.7.1013][BUG FIX] Fix BootROM start command failure while manually selecting NMT6226 or MT6227 baseband chip.
 *
 *    Rev 1.12   Sep 13 2005 13:23:52   mtk00539
 *  1. [DA][New] New NOR flash device support [Winbond] W19B320ATB, W19B320ATT.
 *  2. [DA][BUG FIX] Fix MT6229 read DSP version failure problem.
 * Resolution for 130: [BROM_DLL v2.4.1016][Enhance] Workaround the 1st time power up failure issue when RTC is empty.
 *
 *    Rev 1.11   Jul 24 2005 21:33:14   mtk00539
 * 1. Write a new Boot_META virtual function for MT6228.
 * 2. Lock power in META mode on MT6228.
 * Resolution for 121: [BROM_DLL v2.4.1014][New] Support MT6227 and MT6228 NFB META mode.
 *
 *    Rev 1.10   Jul 22 2005 20:39:10   mtk00539
 *  1. [BROM_DLL][New] Support MT6227.
 *  2. [BROM_DLL][New] Support MT6228 NFB META mode.
 * Resolution for 121: [BROM_DLL v2.4.1014][New] Support MT6227 and MT6228 NFB META mode.
 *
 *    Rev 1.9   Mar 29 2005 20:41:42   mtk00539
 * Add MT6228 chip id
 * Resolution for 107: [BROM_DLL v2.4.1010][New] Enhance bus test in FlashTest_DA, new INTEL flash support and bug fix.
 *
 *    Rev 1.8   Aug 03 2004 10:42:44   mtk00539
 *  1. [DA][BUG FIX] Invoke Board_Schematic()(old name is HW_Init()) before FUTL_CheckDevice(). Because FUTL_CheckDevice() must know the absolute address for each bank.
 *  2. [DA][New] Add 12 new flash devices support
 * 				[SAMSUNG]K5A3280YT,
 * 				[TOSHIBA]TH50VPF6782AASB,
 * 				[TOSHIBA]TH50VPF6783AASB,
 * 				[TOSHIBA]TV00578002AABD,
 * 				[TOSHIBA]TV00578003AABD,
 * 				[Fujitsu]MB84VP24581HK,
 * 				[INTEL]INTEL_28F640W30_B,
 * 				[SPANSION]AM49PDL127BH,
 * 				[SPANSION]AM49PDL129BH,
 * 				[RENESAS]M6MGD13BW66CDG,
 * 				[Winbond]W19B322TM,
 * 				[Winbond]W19B323TM,
 *  3. [DA][New] Readback check after WORD program is done, so that DA won't have to keep the chksum.
 *  4. [DA][New] Auto-detect baseband chip type.
 *  5. [DA][New] Auto-detect external SRAM size.
 *  6. [DA][New] Merge MT6205B, MT6218B and MT6219 to an all-in-one DA.
 *  7. [DA][New] Merge flash stress test module.
 *  8. [DA][New] Modify makefile to build ARM or THUMB code.
 *  9. [DA][New] Construct a customization kit for customers to add new flash or SOC checking algorithm by themselves.
 * 10. [DA][Enhance] Split out AM29PDL128G function to improve the performance of general AMD callback functions.
 * 11. [DA][Enhance] Enhance RX_BUFF_FULL behavior to prevent always retry two times.
 * Resolution for 83: [BROM_DLL v2.4.1002] Merge all the DAs into all-in-one DA and fix many bugs and enhancement.
 *
 *    Rev 1.7   May 21 2004 15:44:40   mtk00539
 *  1. [brom.dll][New] add J2ME_ROM resource for w04.21 load.
 *  2. [brom.dll][New] add MT6217 BootROM.
 *  3. [brom.dll][New] add Brom_DownloadData API.
 *  4. [brom.dll][New] remove Brom_Verify relative APIs.
 *  5. [brom.dll][Enhance] move region overlap checking from Rom_Load() to IsReady() for more convenience.
 * Resolution for 70: [BROM_DLL v2.3.1003][New] add J2ME_ROM resource for w04.21 load.
 *
 *    Rev 1.6   Mar 02 2004 00:14:42   mtk00539
 * 1. [DA][Enhance] re-assign DA command id.
 * 2. [DA][Enhance] add DSP firmware version command.
 * 3. [DA][BUG FIX] fix unsigned var in while loop that causes infinite loop.
 * Resolution for 53: [BootRom v2.2.1007][Enhance] resource layout error detection.
 *
 *    Rev 1.5   Nov 12 2003 14:14:44   mtk00539
 * Add SOC feature
 * Resolution for 35: [BootRom v2.1.1005][New] Add SOC feature.
 *
 *    Rev 1.4   Sep 25 2003 13:57:54   mtk00539
 * brom.dll v2.1.1001, please see SCR(28) for more details.
 * Resolution for 28: [BootRom v2.1.1001][New] See the reasons below.
 *
 *    Rev 1.3   Jun 30 2003 19:24:50   mtk00539
 * 1. [brom.dll][Add Features] Split flashtool function into brom.dll
 * 2. [brom.dll][Add Features] Add a fake MT6208 bootrom for FlashTool for Pluto version.
 * 3. [DA][Add Features] Check format range.
 * 4. [DA][Add Features] Report format percentage.
 * 5. [DA][Add Features] Support 6208 EVB/CEVB for double flash devices access.
 * 6. [DA][BUG FIXED] Fix DA pre-format sector bug, it shouldn't format beyond the max size of flash.
 * 7. [DA][BUG FIXED] Fix DA FlashTool MEM_CMD end_addr bug, FlashTool should use (begin_addr+length-1) as end_addr.
 * 8. [DA][BUG FIXED] Fix DA AM29DL640D, MB84VD23280FA and TC58FVB64 flash table error.
 * Resolution for 12: [BootRom v2.2.1001][New Version] Split flashtool function into brom.dll
 *
 *    Rev 1.2   Jun 11 2003 21:26:24   mtk00539
 * 1. Modify BootRom library to support MT6218
 * 2. Modify DA to support AM29PDL128G flash
 * Resolution for 9: [FlashTool v2.2.1005][Add Feature] Support MT6218 and new flash AM29PDL128G
 *
 *    Rev 1.1   May 20 2003 18:05:46   mtk00539
 * add copyright
 * Resolution for 6: [FlashTool v2.2][AddFeature] Support 6205/6205B at 13MHz, 26MHz and 52MHz.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef	_MTK_MCU_H_
#define	_MTK_MCU_H_

typedef enum
{
    EXT_13M = 1,
    EXT_26M = 2,
    EXT_39M = 3,
    EXT_52M = 4,
    EXT_CLOCK_END,
    AUTO_DETECT_EXT_CLOCK = 254,
    UNKNOWN_EXT_CLOCK = 255
} EXT_CLOCK;

typedef	enum
{
    MT6205	= 0,
    MT6205B	= 1,
    MT6218	= 2,
    MT6218B	= 4,
    MT6219  = 5,
    MT6217  = 6,
    MT6228  = 7,
    MT6227  = 8,
    MT6229  = 9,
    MT6226  = 10,
    MT6226M  = 11,
    MT6230  = 12,
    MT6225  = 13,
    MT6268T  = 14,
    MT6223  = 15,
    MT6227D  = 16,
    MT6226D  = 17,
    MT6223P  = 18,
    MT6238	= 19,
    MT6235	= 20,
    MT6235B	= 21,
    TK6516_MD  = 22,
    TK6516_AP  = 23,
    MT6268A	= 24,
    MT6516_MD  = 25,
    MT6516_AP  = 26,
    MT6239	= 27,
    MT6251T	= 28,
    MT6253T  = 29,
    MT6268B  = 30,
    MT6253  = 32,
    MT6253D  = 33,
    MT6236  = 34,
    MT6270A  = 35,

    MT6276  = 128,
    MT6251  = 129,
    MT6255  = 130,
    MT6573  = 131,
    MT6575  = 132,
    BBCHIP_TYPE_END,
    AUTO_DETECT_BBCHIP = 254,
    UNKNOWN_BBCHIP_TYPE = 255
} BBCHIP_TYPE;


// FIXME
typedef BBCHIP_TYPE ChipName;


#endif
