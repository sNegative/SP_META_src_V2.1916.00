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
 *   ControlLocker.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   Lock the controls when time exhausting process is going on.
 *   Unlock them after the process.
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
#ifndef CONTROLLOCKER_H_
#include "ControlLocker.h"
#endif


//---------------------------------------------------------------------------
void ControlLocker::Lock()
{
//    LOG("mControls MAX SIZE: %ld", mControls.max_size());
    //must be the first time to lock.
    LOG("locked start: %d", m_count);
    m_count++;
    if(E_CONTROL_FLAG_LOCKED == m_controlFlag)
    {
        return;
    }
    m_controlFlag = E_CONTROL_FLAG_LOCKED;
    std::map<TControl*,bool>::iterator it;
    for(it = mControls.begin(); it!=mControls.end(); ++it)
    {
        it->second = it->first->Enabled; //store current status
        it->first->Enabled = false; //disable it then
        /*        if(NULL != m_stopPoint && m_stopPoint == (TButton*)(it->first))
                {
                    LOG("locked m_stopPointEnabled: %d", it->second);
                }  */
    }
    LOG("locked end: %d", m_count);
}
//---------------------------------------------------------------------------
void ControlLocker::Unlock(int i)
{
    //must have beeen locked.
    LOG("unlocked start: %d", m_count);
    /*    if(E_CONTROL_FLAG_NONE != m_controlFlag)
        {
            m_count--;
        } */

    if(E_CONTROL_FLAG_NONE == m_controlFlag || 1 > m_count)
    {
        return;
    }

    m_count--;

    if(0 == m_count || 1 == i)
    {
        m_controlFlag = E_CONTROL_FLAG_UNLOCKED;
        std::map<TControl*,bool>::const_iterator it;
        for(it = mControls.begin(); it!=mControls.end(); ++it)
        {
            it->first->Enabled = it->second;
            /*            if(NULL != m_stopPoint && m_stopPoint == (TButton*)(it->first))
                        {
                            LOG("unlocked m_stopPointEnabled: %d", it->second);
                        }      */
        }
    }

    if(0 == m_count)
    {
        m_controlFlag = E_CONTROL_FLAG_NONE;
    }
    /*    if(0 < m_count)
        {
            m_count--;
            Lock();
        }        */
    LOG("unlocked end: %d", m_count);
}
