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
 *   misc_bb.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband Misc. function source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *
 * Nov 7 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MISC_BB_H_
#define  _MISC_BB_H_

// Baseband
extern bool  IsValidADCMeasureCount(AnsiString ansi_str, unsigned short &measure_count);
extern bool  IsValidBatteryLevelVoltage(AnsiString ansi_str, unsigned int &voltage);
extern bool  IsValidHexRegAddr(AnsiString ansi_str, unsigned int *addr);
extern bool  IsValidHexRegValue(AnsiString ansi_str, unsigned int *value);
extern bool  IsValidDecRegValue(AnsiString ansi_str, unsigned int *value);
extern bool  IsValidLEDLightLevel(AnsiString ansi_str, unsigned char &level);
extern bool  IsValidLEDDiv(AnsiString ansi_str, unsigned char &level);
extern bool  IsValidLEDDuty(AnsiString ansi_str, unsigned char &level);
extern bool  IsValidRTCYear(AnsiString ansi_str, unsigned char &year);
extern bool  IsValidRTCMonth(AnsiString ansi_str, unsigned char &month);
extern bool  IsValidRTCWDay(AnsiString ansi_str, unsigned char &wday);
extern bool  IsValidRTCDay(AnsiString ansi_str, unsigned char &day);
extern bool  IsValidRTCHour(AnsiString ansi_str, unsigned char &hour);
extern bool  IsValidRTCMinute(AnsiString ansi_str, unsigned char &minute);
extern bool  IsValidRTCSec(AnsiString ansi_str, unsigned char &sec);






/*---------------------------------------------------------------------------*/

#endif
