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
 *   NVRAMEditor.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   Read & Write NVRAM
 *
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
#ifndef _NVRAMEDITOR_H_
#define _NVRAMEDITOR_H_

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include "CONTROLSLib_OCX.h"
#include <vector>

#include "meta_const.h"
#include "CONTROLSLib_OCX.h"
#include "META_error_handler.h"
#include "NVRAM_LID_Parsing.h"
#include "meta_msg.h"
#include "nvram_lock.h"
#include "man_handle.h"
#include <OleServer.hpp>

#ifndef CONTROLLOCKER_H_
#include "ControlLocker.h"
#endif

//#define MAX_LID_NUM_IN_NVRAM 150
#define TOTAL_RID_COUNT 20000
//#define META_MAX_LID_LEN 200
//#define MAX_NVRAM_REC_LEN 1024*4
#define MAX_LID_NAME_LEN  256

typedef struct
{
    // char GroupName[MAX_GROUP_NAME_LEN];
    // char ElementName[MAX_ELEMENT_NAME_LEN];
    char *LIDNAME;//[MAX_LID_NAME_LEN];
    char *StructName;//[MAX_STRUCT_NAME_LEN];
    char *Buf;//[MAX_FDM_REC_LEN];
    int  iDataLen;
    TVariant vTreeItemHandle;  //  Active X Tree Control Item
    void *pNode;           // Tree View Node
    bool bRead;
    //   bool bModified;
    //   bool bSaved;
} TreeStructType;
// end of added

//---------------------------------------------------------------------------
class TfrmNVRAMEditor : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tb_FDM;
    TToolButton *tbReadFromNVRAM;
    TToolButton *tbSaveToNVRAM;
    TToolButton *tbNVRAMTreeProperty;
    TToolButton *tbNVRAMClear;
    TTreeView *tv_NVRAM;
    TStringGrid *sg_NVRAM_editor;
    TImageList *ImageList1;
    TOpenDialog *dlgOpenNVRAMDB;
    TOpenDialog *dlgOpenTreeDB;
    TTimer *TimerMETACheck;
    TStatusBar *sb_NVRAM_editor;
    TToolButton *tbLockNVRAM;
    TTree *NVRAM_RawDataTree;
    TToolButton *tbResetNVRAM;
    TToolButton *tbResetAll;
    TToolButton *tbBackup;
    TToolButton *tbRestore;
    TOpenDialog *RestoreOpenDialog;
    TSaveDialog *BackupSaveDialog;
    // end of added
    void __fastcall tbReadFromNVRAMClick(TObject *Sender);
    void __fastcall tbSaveToNVRAMClick(TObject *Sender);
    void __fastcall tbNVRAMTreePropertyClick(TObject *Sender);
    void __fastcall tbNVRAMClearClick(TObject *Sender);
    void __fastcall OnClick(TObject *Sender);
    void __fastcall tbLockNVRAMClick(TObject *Sender);
    void __fastcall tbResetNVRAMClick(TObject *Sender);
    void __fastcall tbResetAllClick(TObject *Sender);
    void __fastcall tbBackupClick(TObject *Sender);
    void __fastcall rbRestoreClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);

private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
    // TTreeNode *ptn_element;
    // TTreeNode *ptn_group;
    int m_iTotalLidNum;
    int m_iTotalRecNum;
    int m_iMaxRecNum;
    char *m_pc_all_LID_name_buf;
    // TStringList* psl_LID_list[ MAX_LID_NUM_IN_NVRAM ];
    TStringList** m_psl_LID_list;
    //TTreeNode *ptn_LIDNode[ MAX_LID_NUM_IN_NVRAM ];
    TTreeNode** m_ptn_LIDNode;
    // TTreeNode *m_ptn_RIDNode[ MAX_LID_NUM_IN_NVRAM ][ MAX_RID_NUM_IN_LID ];
    TTreeNode*** m_ptn_RIDNode;
    TStringList* m_psl_NVRAM_list;

    TTreeNode *m_ptn_selected;
    TTreeNode *m_ptn_rec;
    // end of modified
    // modified by Andy Ueng
    // TreeStructType NVRAM_TreeItem[MAX_ELEMENT_IN_NVRAM];
    // TreeStructType m_NVRAM_TreeItem[TOTAL_RID_COUNT];
    TreeStructType* m_pNVRAM_TreeItem;
    // end of modified
    short m_sNVRAM_node_read_rec_token;  // for META_UI AX tree
    short m_sNVRAM_node_write_rec_token;

    AP_FT_NVRAM_READ_CNF		 	m_NVRAM_node_read_rec;  // for META_UI AX tree
    AP_FT_NVRAM_WRITE_CNF		    m_NVRAM_node_write_rec_cnf;
    AP_FT_NVRAM_WRITE_REQ   		*m_NVRAM_WriteReq;
    AP_FT_NVRAM_READ_REQ     		*m_NVRAM_ReadReq;

    //added for reset NVRAM 2008-12-10
    AP_FT_NVRAM_RESET_REQ    		*m_NVRAM_Reset_Req;
    AP_FT_NVRAM_RESET_CNF			m_NVRAM_reset_cnf;
    short m_sNVRAM_reset_token;

    // NVRAM lock
    CNVRAMLOCK  m_NVRAM_LOCK_Obj;

    AnsiString m_file_name1;
    AnsiString m_file_name2;

    //event to reset button
    HANDLE m_HandleEventCallBack;

    ControlLocker m_NVRAMCtlLocker;

    //Qin Qin 20120703
    int m_nModifyItemCount;
    int m_nNvramWriteCnfCount;

    std::vector<int> m_vIndex;
    bool isNVRAMWriteFinish;
    bool isNVRAMReadFinish;
    bool isNVRAMStressTest;
    bool m_isFirstOpenNvram;
    //

public:		// User declarations
    __fastcall TfrmNVRAMEditor(TComponent* Owner);
    __fastcall ~TfrmNVRAMEditor(void); // added by Andy Ueng
    void  FreeDynMem(void);

    // UI
//	void  CurrentPageReset( void );
//	void  CurrentPageLock( void );
    void __fastcall tb_Init_NVRAMClick(TObject *Sender);

    // bool get_index_from_LID( char *LID_para, int &index );
    bool  get_index_from_LID( char *LID_para, int *index );

    void  read_Raw_Data_from_StringGrid( TStringGrid *sg, int iStartCol, int iStartRow, int iDisplayColCount, int iDataLen, char *buf );
    void  fill_StringGrid( TStringGrid *sg, int iStartCol, int iStartRow, int iDisplayColCount, int iDataLen, AnsiString as );
    bool  get_index_from_handle( TreeStructType *tst, int i, int &index );
    bool  find_node_index( TreeStructType *tst, void *pNode, int &index);
    void  show_Raw_Data_on_StringGrid( TStringGrid *sg, char *buf, int buf_len);
    void __stdcall NVRAM_node_write_rec_cnf_cb(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);
    void __stdcall NVRAM_node_read_rec_cnf_cb( const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData);
    void __stdcall NVRAM_reset_cnf_cb( const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData);
    void __stdcall NVRAM_Write_Cnf_cb(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);
    void  InitializeNVRAMEditor( void );
    bool  Get_Total_RecNum( TStringList* psl_list, int lid_num, int &total_rec_num );
    bool  Get_Max_RecNum( TStringList* psl_list, int lid_num, int &max_rec_num );

    //FOR NVRAM backup and restore
    bool  Backup_GetFileNames(const AnsiString& file,AnsiString& bpFile1,AnsiString& bpFile2);
    bool  Restore_GetFileNames(const AnsiString& file,AnsiString& bpFile1,AnsiString& bpFile2);
    void  CNF_NVRAMBackup(void);
    void  CNF_NVRAMRestore(void);

    // callback
    void  CNF_NVRAMLock( void );
    //rongguo 2011-09-27
    bool  ReplaceDatabaseClean( void );
    void  ClearNVRAMEditor(void);
    void  ReadWriteStressTest();
    void  SetFirstOpenNvramEditor(bool isFirstOpenNvram);

private:
    void  CheckNVRAMReadWriteStatus(bool& isFinish);
    void  SaveToNVRAM(TObject *Sender);
    void  WriteNVRAMStressTest(TObject *Sender);
    bool  IsValid(int &idx);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNVRAMEditor *frmNVRAMEditor;
//---------------------------------------------------------------------------
#endif
