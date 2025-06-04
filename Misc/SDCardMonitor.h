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
 *   SDCardMonitor.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   Detect SD Card for recording or copying.
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
#ifndef SDCARDMONITOR_H_
#define SDCARDMONITOR_H_

#include <iostream>
#include <list>


class SDCardListener
{
public:
    virtual void OnSDCardMounted() = 0;
    virtual void OnSDCardTimeOut() = 0;
};

enum SDCardEvent
{
    Mounted,
    Timeout,
};

class SDDetectThread;

class SDCardMonitor
{
public:
    friend class SDDetectThread;
    SDCardMonitor();
    ~SDCardMonitor();

    void AddObserver(SDCardListener * ob);
    void RemoveObserver(SDCardListener * ob);

    void SetTimeoutInS(int timeout)
    {
        sTimeout = timeout;
    }
    bool Start();
    void Stop();

    bool GetIsRunning()
    {
        return isRunning;
    }

protected:
    void Execute();

private:
    void SetIsRunning(bool running)
    {
        isRunning = running;
    }
    bool CheckSDCardMounted();

    void NotifySDCardEvent(SDCardEvent event);

    std::list<SDCardListener*> observers;
//    std::list<const SDCardListener*> observers;
    int sTimeout;

    volatile bool isRunning;
    std::string m_CWD;

    SDDetectThread *dtThread;

public:
    static SDCardMonitor *Instance()
    {
        if(instance == NULL)
        {
            instance = new SDCardMonitor();
        }
        return instance;
    }

private:
    static SDCardMonitor *instance;
    const static int DEFAULT_TIMEOUT;
};



#endif /* SDCARDMONITOR_H_ */
