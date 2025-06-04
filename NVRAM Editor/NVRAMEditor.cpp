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
#include <vcl.h>
#pragma hdrstop

#include "form_main.h"
#include "NVRAMEditor.h"
#include "man_fdm.h"

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#pragma package(smart_init)
#pragma link "CONTROLSLib_OCX"
#pragma resource "*.dfm"

TfrmNVRAMEditor *frmNVRAMEditor;

// added by Andy Ueng
int iNVRAM_TreeItemIndex=0;
// new tree ds.
int iTotalTreeItemCount=0;

extern AnsiString chipVersion;
extern AnsiString softwareVersion;
extern int Determine_LID_Category(char *LID_Name_para);

//============================================================================

static void __stdcall NVRAM_node_read_rec_cnf_cb( const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    frmNVRAMEditor->NVRAM_node_read_rec_cnf_cb(cnf, token, usrData );
}
//----------------------------------------------------------------------------
static void __stdcall NVRAM_node_write_rec_cnf_cb(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    frmNVRAMEditor->NVRAM_node_write_rec_cnf_cb(cnf, token, usrData );
}
//----------------------------------------------------------------------------
static void __stdcall NVRAM_Write_Cnf_cb(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    frmNVRAMEditor->NVRAM_Write_Cnf_cb(cnf, token, usrData );
}
//----------------------------------------------------------------------------
static void __stdcall NVRAM_reset_cnf_cb(const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    frmNVRAMEditor->NVRAM_reset_cnf_cb(cnf, token, usrData );
}
//----------------------------------------------------------------------------
static void CNF_NVRAMLock( void )
{
    frmNVRAMEditor->CNF_NVRAMLock();
}
//------------------------------------------------------------------------------
static void CNF_NVRAMRestore(void)
{
    frmNVRAMEditor->CNF_NVRAMRestore();
}
//------------------------------------------------------------------------------
static void CNF_NVRAMBackup(void)
{
    frmNVRAMEditor->CNF_NVRAMBackup();
}
//============================================================================
//---------------------------------------------------------------------------
__fastcall TfrmNVRAMEditor::TfrmNVRAMEditor(TComponent* Owner)
    : TForm(Owner)
{
    m_NVRAM_ReadReq = NULL;
    m_NVRAM_WriteReq = NULL;
    m_NVRAM_node_read_rec.buf = NULL;
    m_pc_all_LID_name_buf = NULL;
    m_pNVRAM_TreeItem = NULL;
    m_psl_NVRAM_list = NULL;
    m_psl_LID_list = NULL;
    m_ptn_LIDNode  = NULL;
    m_ptn_RIDNode  = NULL;
    m_nModifyItemCount = 0;     //Qin Qin 20120703
    m_nNvramWriteCnfCount = 0;  //Qin Qin 20120703
    m_nModifyItemCount = 0;     //Qin Qin 20120703
    m_nNvramWriteCnfCount = 0;  //Qin Qin 20120703
    m_NVRAMCtlLocker.AddControl(tbBackup);
    m_NVRAMCtlLocker.AddControl(tbLockNVRAM);
    m_NVRAMCtlLocker.AddControl(tbNVRAMClear);
    m_NVRAMCtlLocker.AddControl(tbNVRAMTreeProperty);
    m_NVRAMCtlLocker.AddControl(tbReadFromNVRAM);
    m_NVRAMCtlLocker.AddControl(tbResetAll);
    m_NVRAMCtlLocker.AddControl(tbResetNVRAM);
    m_NVRAMCtlLocker.AddControl(tbRestore);
    m_NVRAMCtlLocker.AddControl(tbSaveToNVRAM);
    m_NVRAMCtlLocker.AddControl(tv_NVRAM);
    m_HandleEventCallBack = NULL;
    m_NVRAM_Reset_Req = NULL;
    m_iMaxRecNum = 0;
    m_iTotalLidNum = 0;
    m_iTotalRecNum  = 0;
    m_ptn_rec = NULL;
    m_ptn_selected = NULL;
    m_sNVRAM_node_read_rec_token = 0;
    m_sNVRAM_node_write_rec_token = 0;
    m_sNVRAM_reset_token = 0;
    isNVRAMWriteFinish = false;
    isNVRAMReadFinish = false;
    isNVRAMStressTest = false;
    
}
//---------------------------------------------------------------------------
__fastcall  TfrmNVRAMEditor::~TfrmNVRAMEditor(void)
{
    FreeDynMem();
}
//---------------------------------------------------------------------------
void  TfrmNVRAMEditor::FreeDynMem(void)
{
    if(m_NVRAM_Reset_Req != NULL)
    {
        delete m_NVRAM_Reset_Req;
        m_NVRAM_Reset_Req = NULL;
    }

    if(m_NVRAM_ReadReq != NULL)
    {
        delete m_NVRAM_ReadReq;
        m_NVRAM_ReadReq = NULL;
    }

    if(m_NVRAM_WriteReq != NULL)
    {
        delete m_NVRAM_WriteReq;
        m_NVRAM_WriteReq = NULL;
    }

    if(m_NVRAM_node_read_rec.buf != NULL)
    {
        delete m_NVRAM_node_read_rec.buf;
        m_NVRAM_node_read_rec.buf = NULL;
    }

    if(m_pc_all_LID_name_buf != NULL)
    {
        delete [] m_pc_all_LID_name_buf;
        m_pc_all_LID_name_buf = NULL;
    }

    if(m_pNVRAM_TreeItem != NULL)
    {
        //delete m_pNVRAM_TreeItem.pNode;
        for(int i = 0; i < m_iTotalRecNum; i++)
        {
            if(m_pNVRAM_TreeItem[i].LIDNAME != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].LIDNAME;
                m_pNVRAM_TreeItem[i].LIDNAME = NULL;
            }

            if(m_pNVRAM_TreeItem[i].StructName != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].StructName;
                m_pNVRAM_TreeItem[i].StructName = NULL;
            }

            if(m_pNVRAM_TreeItem[i].Buf != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].Buf;
                m_pNVRAM_TreeItem[i].Buf = NULL;
            }
        }
        delete []m_pNVRAM_TreeItem;
        m_pNVRAM_TreeItem = NULL;
    }

    if(m_psl_NVRAM_list != NULL)
    {
        delete m_psl_NVRAM_list;
        m_psl_NVRAM_list = NULL;
    }

    if(m_psl_LID_list != NULL)
    {
        delete [] m_psl_LID_list;
        m_psl_LID_list = NULL;
    }

    if(m_ptn_LIDNode != NULL)
    {
        delete [] m_ptn_LIDNode;
        m_ptn_LIDNode = NULL;
    }

    if(m_ptn_RIDNode != NULL) //fix memory leak
    {
        for(int i = 0; i < m_iTotalLidNum; i++)
        {
            if(m_ptn_RIDNode[i] != NULL)
            {
                delete m_ptn_RIDNode[i];
                m_ptn_RIDNode[i] = NULL;
            }
        }
        delete [] m_ptn_RIDNode;
        m_ptn_RIDNode = NULL;
    }
}
/*//===========================================================================
void  TfrmNVRAMEditor::CurrentPageReset( void )
{
#if 1
    tbReadFromNVRAM->Enabled = true;
    tbSaveToNVRAM->Enabled = true;
    tbNVRAMTreeProperty->Enabled = true;
    tbNVRAMClear->Enabled = true;
    tbLockNVRAM->Enabled = true;
#endif
}
//---------------------------------------------------------------------------
void  TfrmNVRAMEditor::CurrentPageLock( void )
{
#if 1
    tbReadFromNVRAM->Enabled = false;
    tbSaveToNVRAM->Enabled = false;
    tbNVRAMTreeProperty->Enabled = false;
    tbNVRAMClear->Enabled = false;
    tbLockNVRAM->Enabled = false;
#endif
}        */
//===========================================================================
//---------------------------------------------------------------------------
bool get_StringList_from_buf( TStringList *psl, char *pc_buf, int buf_len, char c_sep )
{
    int iStart = 0;
    AnsiString as_sub;
    char *pc_sub = (char *) malloc( buf_len );

    if ( pc_sub == NULL )
    {
        ShowMessage(" memory alloc error ");
        return false;
    }

    FillMemory( pc_sub, buf_len, '\0' );

    for ( int i=0; i< buf_len; i++)
    {
        if ( *(pc_buf+i) == c_sep)
        {
            FillMemory( pc_sub, buf_len, '\0' );
            memcpy( pc_sub, pc_buf+iStart, i-iStart);
            psl->Add( AnsiString( pc_sub ));
            iStart = i+1;
        }
    }

    if ( pc_sub != NULL )
    {
        free( pc_sub );
    }
    return true;
}
//---------------------------------------------------------------------------
bool TfrmNVRAMEditor::find_node_index( TreeStructType *tst, void *pNode, int &index)
{
    for ( int i = 0; i < m_iTotalRecNum; i++)
    {
        if ( tst[ i ].pNode == pNode )
        {
            index = i;
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
void  TfrmNVRAMEditor::fill_StringGrid( TStringGrid *sg,  int iStartCol, int iStartRow, int iDisplayColCount, int iDataLen, AnsiString as )
{
    int iTotalRow = iDataLen / iDisplayColCount;
    int I = 0;
    int J = 0;
    for (I = iStartCol; I <= (iDisplayColCount+iStartCol-1); I++)
    {
        for (J = iStartRow; J <= (iTotalRow+iStartRow-1); J++)
        {
            sg->Cells[I][J] = as;
        }
    }

    if (iDataLen % iDisplayColCount > 0)
    {
        for (I = iStartCol; I <= ( (iDataLen%iDisplayColCount) + iStartCol - 1); I++)
        {
            J = iTotalRow+iStartRow;
            sg->Cells[I][J] = as;
        }
    }
}
//------------------------------------------------------------------------------
void TfrmNVRAMEditor::show_Raw_Data_on_StringGrid( TStringGrid *sg, char *buf, int buf_len)
{
    AnsiString as;
    int I = 0;
    int J = 0;

    for (I = 0; I < sg->ColCount; I++)
    {
        for (J = 0; J < sg->RowCount; J++)
        {
            sg->Cells[I][J] = "";
        }
    }

    for ( int index=0; index < buf_len; index++ )
    {
        I = (index % ( RAW_DATA_COL_COUNTS )) + sg->FixedCols;
        J = (index / ( RAW_DATA_COL_COUNTS )) + sg->FixedRows;
        sg->Cells[I][J] = IntToHex( (unsigned char)(*(buf+index)), 2 );
    }
}
//---------------------------------------------------------------------------
void  TfrmNVRAMEditor::InitializeNVRAMEditor( void )
{
    iNVRAM_TreeItemIndex = 0;
    iTotalTreeItemCount = 0;

    FreeDynMem();
    tb_Init_NVRAMClick(NULL);

    NVRAM_RawDataTree->InitDataBase( NVRAMMan->Get_NvramDbVariant() );
    if(this->Visible == false)
    {
        // create UI control, becuase the InitialzeNVRAMEditor could be called in other forms
        this->Show();
        this->Hide();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tb_Init_NVRAMClick(TObject *Sender)
{
    META_RESULT MetaResult;
    tv_NVRAM->Items->Clear();

    int i_LID_name_buf_len = 0;

    if(!m_psl_NVRAM_list)
    {
        m_psl_NVRAM_list = new TStringList();
    }

    MetaResult = SP_META_NVRAM_GetAllLIDNameLength( &i_LID_name_buf_len );
    if ( MetaResult != META_SUCCESS )
    {
        META_result_handler( MetaResult );
    }

    if ( i_LID_name_buf_len <= 0 )
    {
        NVRAMMan->Set_IsInit(false);
        Application->MessageBox( "Execution Failure : LID name length error", "FAILURE", MB_OK );
        return;
    }

    if(  m_pc_all_LID_name_buf == NULL)
    {
        m_pc_all_LID_name_buf = new char[i_LID_name_buf_len];
    }

    MetaResult = SP_META_NVRAM_GetAllLIDName(m_pc_all_LID_name_buf, i_LID_name_buf_len, &m_iTotalLidNum );
    if ( MetaResult !=     META_SUCCESS )
    {
        META_result_handler( MetaResult );
    }

    if( NULL == m_psl_LID_list )
    {
        m_psl_LID_list = new TStringList*[m_iTotalLidNum];
    }

    if( NULL == m_ptn_LIDNode )
    {
        m_ptn_LIDNode = new TTreeNode*[m_iTotalLidNum];
    }

    if (! get_StringList_from_buf( m_psl_NVRAM_list, m_pc_all_LID_name_buf, i_LID_name_buf_len, '\0'))
    {
        NVRAMMan->Set_IsInit(false);
        Application->MessageBox( "Execution Failure : parse NVRAM LID name error", "FAILURE", MB_OK );
        return;
    }

    if(! Get_Max_RecNum( m_psl_NVRAM_list, m_iTotalLidNum, m_iMaxRecNum ) )
    {
        NVRAMMan->Set_IsInit(false);
        Application->MessageBox( "Execution Failure : Get maximum record number fail", "FAILURE", MB_OK );
        return;
    }

    //add 20150419
    // if not init state, clear all dynamic array
    if( NULL != m_pNVRAM_TreeItem )
    {
        for(int i = 0; i < m_iTotalRecNum; i++)
        {
            if(m_pNVRAM_TreeItem[i].LIDNAME != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].LIDNAME;
                m_pNVRAM_TreeItem[i].LIDNAME = NULL;
            }

            if(m_pNVRAM_TreeItem[i].StructName != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].StructName;
                m_pNVRAM_TreeItem[i].StructName = NULL;
            }

            if(m_pNVRAM_TreeItem[i].Buf != NULL)
            {
                delete[] m_pNVRAM_TreeItem[i].Buf;
                m_pNVRAM_TreeItem[i].Buf = NULL;
            }
        }
    }
    //add end

    if(! Get_Total_RecNum( m_psl_NVRAM_list, m_iTotalLidNum, m_iTotalRecNum ) )
    {
        NVRAMMan->Set_IsInit(false);
        Application->MessageBox( "Execution Failure : Get total record number fail", "FAILURE", MB_OK );
        return;
    }

    if(!m_ptn_RIDNode )
    {
        m_ptn_RIDNode = new TTreeNode**[m_iTotalLidNum];
        for( int j = 0; j <m_iTotalLidNum; j++ )
        {
            m_ptn_RIDNode[j] = new TTreeNode*[m_iMaxRecNum];
        }
    }

    if(!m_pNVRAM_TreeItem)
    {
        m_pNVRAM_TreeItem = new TreeStructType[m_iTotalRecNum];
        //add 20150419
        memset(m_pNVRAM_TreeItem, 0x0, m_iTotalRecNum * sizeof(TreeStructType));
        //add end
    }

    TTreeNode *ptn_SysNode, *ptn_L1CalNode, *ptn_OtherNode;
    int rec_num = 0;
    int rec_index = 0;

    char rec_buf[20] = {0};


    ptn_SysNode = tv_NVRAM->Items->Add( NULL , "RDEB LID" );
    ptn_L1CalNode = tv_NVRAM->Items->Add( NULL , "RDCL LID" );
    ptn_OtherNode = tv_NVRAM->Items->Add( NULL , "Other LID" );

    for ( int j=0; j<m_iTotalLidNum; j++)
    {
        int LID_category;
        LID_category = Determine_LID_Category(m_psl_NVRAM_list->Strings[j].c_str());
        switch(LID_category)
        {
        case RDEB_LID_CATEGORY:
        {
            m_ptn_LIDNode[j] = tv_NVRAM->Items->AddChild( ptn_SysNode , m_psl_NVRAM_list->Strings[j] );
            MetaResult = SP_META_NVRAM_GetRecNum(m_psl_NVRAM_list->Strings[j].c_str(), &rec_num);
            if( MetaResult != META_SUCCESS )
            {
                META_result_handler(MetaResult);
            }

            for(rec_index = 0; rec_index < rec_num; rec_index++)
            {
                sprintf(rec_buf, "%d", rec_index+1);
                m_ptn_RIDNode[j][rec_index] = tv_NVRAM->Items->AddChild( m_ptn_LIDNode[j] , rec_buf );
            }
        }
        break;

        case RDCL_LID_CATEGORY:
        {
            m_ptn_LIDNode[j] = tv_NVRAM->Items->AddChild( ptn_L1CalNode , m_psl_NVRAM_list->Strings[j] );
            MetaResult = SP_META_NVRAM_GetRecNum(m_psl_NVRAM_list->Strings[j].c_str(), &rec_num);
            if( MetaResult != META_SUCCESS )
            {
                META_result_handler(MetaResult);
            }

            for(rec_index = 0; rec_index < rec_num; rec_index++)
            {
                sprintf(rec_buf, "%d", rec_index+1);
                m_ptn_RIDNode[j][rec_index] = tv_NVRAM->Items->AddChild( m_ptn_LIDNode[j] , rec_buf );
            }
        }
        break;

        case OTHER_LID_CATEGORY:
        {
            m_ptn_LIDNode[j] = tv_NVRAM->Items->AddChild( ptn_OtherNode , m_psl_NVRAM_list->Strings[j] );
            MetaResult = SP_META_NVRAM_GetRecNum(m_psl_NVRAM_list->Strings[j].c_str(), &rec_num);
            if( MetaResult != META_SUCCESS )
            {
                META_result_handler(MetaResult);
            }

            for(rec_index = 0; rec_index < rec_num; rec_index++)
            {
                sprintf(rec_buf, "%d", rec_index+1);
                m_ptn_RIDNode[j][rec_index] = tv_NVRAM->Items->AddChild( m_ptn_LIDNode[j] , rec_buf );
            }
        }
        break;
        }

        for(rec_index = 0; rec_index < rec_num; rec_index++)
        {
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].pNode = m_ptn_RIDNode[j][rec_index];
            //add 20150419
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].LIDNAME = new char[m_psl_NVRAM_list->Strings[j].Length() + 1];
            //add end
            strcpy( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].LIDNAME, m_psl_NVRAM_list->Strings[j].c_str());
            iNVRAM_TreeItemIndex++;
            iTotalTreeItemCount++;
        }
    }
}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::read_Raw_Data_from_StringGrid( TStringGrid *sg, int iStartCol,
        int iStartRow, int iDisplayColCount, int iDataLen, char *buf )
{
    int I = 0;
    int J = 0;
    for ( int index=0; index < iDataLen; index++ )
    {
        I = (index % ( RAW_DATA_COL_COUNTS )) + sg->FixedCols;
        J = (index / ( RAW_DATA_COL_COUNTS )) + sg->FixedRows;

        (*(buf+index)) = StrToInt ( AnsiString("0x")+ sg->Cells[I][J] );
    }
}
bool TfrmNVRAMEditor::get_index_from_LID( char *LID_para, int *index )
{
    for ( int I=0; I < iTotalTreeItemCount; I++)
    {
        if ( ( strcmp( m_pNVRAM_TreeItem[I].LIDNAME, LID_para ) == 0 ) )
        {
            *index = I;
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbReadFromNVRAMClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
        return;
    }
    if( ! NVRAMMan->Get_IsInit() )
    {
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    if ( NULL == tv_NVRAM->Selected )
    {
        Application->MessageBox( " You need to select a record from left tree view window ", "Notice", MB_OK );
        return;
    }

    m_ptn_selected = tv_NVRAM->Selected ;

    if ( NULL == m_ptn_selected  )
    {
        return;
    }

    if (! find_node_index( m_pNVRAM_TreeItem, tv_NVRAM->Selected, iNVRAM_TreeItemIndex ))
    {
        Application->MessageBox( "Execution Failure : AP editor can't find this node", "FAILURE", MB_OK );
        return;
    }

    if ( Sender != NULL )
    {
        dynamic_cast <TControl *>(Sender)->Enabled = false;
    }

    if (0 != m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle.intVal )
    {
        long lModified = 0;
        NVRAM_RawDataTree->TreeGetModify( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle, &lModified );
        if ( lModified )
        {
            NVRAM_RawDataTree->TreeSetSel( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle );
            int msg_result = Application->MessageBox( " Do you want to save this struct ? ", "AP editor ", MB_YESNOCANCEL) ;
            switch ( msg_result )
            {
            case IDYES :
                tbSaveToNVRAMClick(NULL);
                NVRAM_RawDataTree->TreeDeleteItem( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle ); // added by Andy Ueng
                m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle.intVal = 0;
                break;
            case IDNO :
                NVRAM_RawDataTree->TreeDeleteItem( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle );
                m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle.intVal = 0;
                break;
            case IDCANCEL :
                tbReadFromNVRAM->Enabled = true;
                return;
            }
        }
        else
        {
            NVRAM_RawDataTree->TreeDeleteItem( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle );
            m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle.intVal = 0;
        }
    }

    int i_struct_name_buf_len = 0;
    META_RESULT MetaResult = SP_META_NVRAM_GetRecStructNameLength(m_ptn_selected->Parent->Text.c_str(), &i_struct_name_buf_len );
    if ( MetaResult != META_SUCCESS )
    {
        META_result_handler( MetaResult );
        if ( Sender != NULL )
        {
            dynamic_cast <TControl *>(Sender)->Enabled = true;
        }
        return;
    }


    if ( i_struct_name_buf_len > 0 )  // ==0 RawData
    {
        //add 20150419
        if(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName == NULL)
        {
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName = new char[i_struct_name_buf_len];
        }
        //add end
        MetaResult = SP_META_NVRAM_GetRecStructName(m_ptn_selected->Parent->Text.c_str(),
                     m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName, i_struct_name_buf_len );
        if ( MetaResult != META_SUCCESS )
        {
            META_result_handler( MetaResult );
            if ( Sender != NULL )
            {
                dynamic_cast <TControl *>(Sender)->Enabled = true;
            }
            return;
        }

        MetaResult =  SP_META_NVRAM_GetRecLen( m_ptn_selected->Parent->Text.c_str(),
                                               &(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen) );
        if ( MetaResult != META_SUCCESS )
        {
            META_result_handler( MetaResult );
            if ( Sender != NULL )
            {
                dynamic_cast <TControl *>(Sender)->Enabled = true;
            }
            return;
        }

        if( NULL == m_NVRAM_node_read_rec.buf )
        {
            m_NVRAM_node_read_rec.buf = new char[m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen];
        }
        m_NVRAM_node_read_rec.len = m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen;
    }
    else
    {
        m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen = 0;
        //add 20150419
        if(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName == NULL)
        {
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName = new char[m_ptn_selected->Text.Length() + 1];
        }
        //add end
        strcpy ( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].StructName, m_ptn_selected->Text.c_str());

        if( NULL == m_NVRAM_node_read_rec.buf )
        {
            m_NVRAM_node_read_rec.buf = new char[ RAW_DATA_BUF_LEN ];
        }
        m_NVRAM_node_read_rec.len = RAW_DATA_BUF_LEN ;
    }

    if( NULL == m_NVRAM_ReadReq )
    {
        m_NVRAM_ReadReq = new AP_FT_NVRAM_READ_REQ;
    }

    m_NVRAM_ReadReq->LID = m_ptn_selected->Parent->Text.c_str();
    m_NVRAM_ReadReq->RID = m_ptn_selected->Text.ToInt();

    m_HandleEventCallBack = CreateEvent(NULL, FALSE, FALSE, NULL);

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM read record Processing";
    MetaResult = SP_META_NVRAM_Read_r(  m_META_HANDLE_Obj.Get_MainHandle(),
                                        m_NVRAM_ReadReq, &m_NVRAM_node_read_rec, ::NVRAM_node_read_rec_cnf_cb, &m_sNVRAM_node_read_rec_token, NULL );
    if ( MetaResult != META_SUCCESS )
    {
        META_result_handler(MetaResult);
        if (Sender != NULL)
        {
            dynamic_cast <TControl *>(Sender)->Enabled = true;
        }
        return;
    }
    else
    {
        m_ptn_rec = m_ptn_selected;
    }

    DWORD nResult = WaitForSingleObject(m_HandleEventCallBack, 5000);
    switch(nResult)
    {
    case WAIT_OBJECT_0:
        break;
    case WAIT_TIMEOUT:
        tbReadFromNVRAM->Enabled = true;
        if (( m_NVRAM_node_read_rec.status != FDM_READ_SUCCESS ) ||( m_NVRAM_node_read_rec.read_status != STATUS_OK_DIRVER ))
        {
            Application->MessageBox( "NVRAM read record fail", "FAILURE", MB_OK );
            sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM read record Failed";
        }
        else
            sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM read record TimeOut";
        break;
    default:
        break;
    }
    CloseHandle(m_HandleEventCallBack);
    m_HandleEventCallBack = NULL;
}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::SaveToNVRAM(TObject *Sender)
{
        TVariant vTreeItemHandle;
        int nCount = 0;
        int nModifyCount = 0;
        NVRAM_RawDataTree->TreeGetCount(&nCount);
        m_nModifyItemCount = 0;
        m_nNvramWriteCnfCount = 0;//Qin Qin 20120718
        if(nCount > 0)
        {

            NVRAM_RawDataTree->TreeGetFirstModify( &vTreeItemHandle );
            do
            {
                if ( vTreeItemHandle.intVal == 0 )
                {
                    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) " Please select a tree item to save ";
                    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
                    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
                    Application->MessageBox( "Please select a tree item to save", "WARNING", MB_OK );
                    return;
                }

                int iItemIndex = -1;

                if ( ! get_index_from_handle( m_pNVRAM_TreeItem,  vTreeItemHandle.intVal , iItemIndex ))
                {
                    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  AP editor error: can't get item index ";
                    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
                    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
                    Application->MessageBox( "Execution Failure : AP editor error: can't get item index", "FAILURE", MB_OK );
                }
                else
                {
                    long lModified;
                    NVRAM_RawDataTree->TreeGetModify( m_pNVRAM_TreeItem[ iItemIndex].vTreeItemHandle , &lModified );
                    if ( lModified )
                    {
                        iNVRAM_TreeItemIndex = iItemIndex;
                    }
                }

                if ( Sender != NULL )
                {
                    dynamic_cast <TControl *>(Sender)->Enabled = false;
                }

                if(!m_NVRAM_WriteReq )
                {
                    m_NVRAM_WriteReq = new AP_FT_NVRAM_WRITE_REQ;
                }

                TTreeNode *pCurrentNode = (TTreeNode *)m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].pNode;
                if(pCurrentNode == NULL)
                {
                    return;
                }

                m_NVRAM_WriteReq->LID = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].LIDNAME;//m_ptn_selected->Parent->Text.c_str();
                m_NVRAM_WriteReq->RID = pCurrentNode->Text.ToInt();//m_ptn_selected->Text.ToInt(); // temp set to 1
                m_NVRAM_WriteReq->buf = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].Buf;
                m_NVRAM_WriteReq->len = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].iDataLen;

                //Qin Qin 20120703
                nModifyCount++;
                int* nItemIndexTemp = new int();
                *nItemIndexTemp = iNVRAM_TreeItemIndex;
                //

                META_RESULT mr1 = SP_META_NVRAM_Write_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                  m_NVRAM_WriteReq, ::NVRAM_node_write_rec_cnf_cb, &m_sNVRAM_node_write_rec_token, nItemIndexTemp/*NULL*/ );

                if ( mr1 != META_SUCCESS )
                {
                    META_result_handler(mr1);
                    if (Sender)
                    {
                        dynamic_cast <TControl *>(Sender)->Enabled = true;
                    }
                    return;
                }
                //Qin Qin 20120703
                NVRAM_RawDataTree->TreeGetNextModify( vTreeItemHandle,&vTreeItemHandle);
            }
            while(vTreeItemHandle.intVal != 0);
      m_nModifyItemCount = nModifyCount;
    }
}

void __fastcall TfrmNVRAMEditor::tbSaveToNVRAMClick(TObject *Sender)
{
    if(!NVRAMMan->Get_IsInit())
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }
    if(!NVRAMMan->Get_IsInit())
    {
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
        }

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    if (NVRAM_RawDataTree->Visible)
    {
        if(isNVRAMStressTest)
            WriteNVRAMStressTest(Sender);
        else
            SaveToNVRAM(Sender);
    }
    else
    {

        read_Raw_Data_from_StringGrid( sg_NVRAM_editor,
                                       RAW_DATA_START_COL, RAW_DATA_START_ROW, RAW_DATA_COL_COUNTS,
                                       m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen,
                                       m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf );


        META_RESULT mr2 = SP_META_NVRAM_Write_r( m_META_HANDLE_Obj.Get_MainHandle(),
                          m_NVRAM_WriteReq, ::NVRAM_node_write_rec_cnf_cb, &m_sNVRAM_node_write_rec_token, NULL );

        if ( mr2 != META_SUCCESS )
        {
            META_result_handler( mr2);
            if (Sender)
            {
                dynamic_cast <TControl *>(Sender)->Enabled = true;
            }
            return;
        }

    }

}
//-----------------------------------------------------------------------------
void __stdcall TfrmNVRAMEditor::NVRAM_node_read_rec_cnf_cb( const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{

        LOG("NVRAM_node_read_rec_cnf_cb: %s", usrData);
    if(m_HandleEventCallBack)
    {
        SetEvent(m_HandleEventCallBack);
    }
    tbReadFromNVRAM->Enabled = true;
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
    LOG("NVRAM_node_read_rec_cnf_cb :1");
    if (( cnf->status != FDM_READ_SUCCESS ) ||( cnf->read_status != STATUS_OK_DIRVER ))
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM read record fail ";
        Application->MessageBox( "NVRAM read record fail", "FAILURE", MB_OK );
        return;
    }
    LOG("NVRAM_node_read_rec_cnf_cb :2");

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM read record successfully ";
    if (0 == m_NVRAM_node_read_rec.len)
    {
        sb_NVRAM_editor->Panels->Items[1]->Text = " buf length: 0 ";
        return;
    }
    LOG("NVRAM_node_read_rec_cnf_cb :3");


    sb_NVRAM_editor->Panels->Items[1]->Text = " buf length: " + IntToStr(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen);
    if (FDM_DATA_VALID != m_NVRAM_node_read_rec.status)
    {
        sb_NVRAM_editor->Panels->Items[2]->Text = " data invalid ";
        return;
    }
    LOG("NVRAM_node_read_rec_cnf_cb :4");

    sb_NVRAM_editor->Panels->Items[2]->Text = " data valid ";
    if ( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen  > 0)
    {
        NVRAM_RawDataTree->Visible = true;
        tbNVRAMTreeProperty->Enabled = true;
        sg_NVRAM_editor->Visible = false;

        //modify 20150419
        #define MAX_PEER_BUFFER_SIZE (1024*60)
        if (m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen > MAX_PEER_BUFFER_SIZE)
        {
            m_vIndex.push_back(iNVRAM_TreeItemIndex);
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen = MAX_PEER_BUFFER_SIZE;
        }
        if(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf == NULL)
        {
             m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf = new char[m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen];
        }
        //modify end
        memcpy( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf,
                m_NVRAM_node_read_rec.buf, m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen);
        if( m_NVRAM_node_read_rec.buf )
        {
            delete []m_NVRAM_node_read_rec.buf;
            m_NVRAM_node_read_rec.buf = NULL;
        }
     LOG("NVRAM_node_read_rec_cnf_cb :5");

     LOG("NVRAM_node_read_rec_cnf_cb :iNVRAM_TreeItemIndex £º%d",iNVRAM_TreeItemIndex
     );
     LOG("NVRAM_node_read_rec_cnf_cb :m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen %d", m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen
     );
        LOG("NVRAM_node_read_rec_cnf_cb :m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf %s", m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf
     );

     LOG("NVRAM_node_read_rec_cnf_cb :m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].LIDNAME %s", m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].LIDNAME
     );

     LOG("NVRAM_node_read_rec_cnf_cb :m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].vTreeItemHandle %s", m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].vTreeItemHandle
     );


     LOG("NVRAM_node_read_rec_cnf_cb :6");


        NVRAM_RawDataTree->EncodeNvramData( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen,
                                            TVariant((long)m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf),
                                            TVariant((char *)m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].LIDNAME) ,
                                            &m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].vTreeItemHandle);
    }
    else
    {
        //add 20150419
        if(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf == NULL)
        {
            m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf = new char[m_NVRAM_node_read_rec.len];
        }
        //add end
        memcpy( m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf,
                m_NVRAM_node_read_rec.buf, m_NVRAM_node_read_rec.len);
        if(m_NVRAM_node_read_rec.buf)
        {
            delete []m_NVRAM_node_read_rec.buf;
            m_NVRAM_node_read_rec.buf = NULL;
        }
        m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen = m_NVRAM_node_read_rec.len;
        NVRAM_RawDataTree->Visible = false;
        tbNVRAMTreeProperty->Enabled = false;
        sg_NVRAM_editor->Visible = true;

    LOG("NVRAM_node_read_rec_cnf_cb :6");
        show_Raw_Data_on_StringGrid( sg_NVRAM_editor,
                                     m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].Buf,
                                     m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen);
    }
    LOG("NVRAM_node_read_rec_cnf_cb :7");
    m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].bRead = true;
    isNVRAMReadFinish = true;

}
//------------------------------------------------------------------------------
void __stdcall TfrmNVRAMEditor::NVRAM_node_write_rec_cnf_cb( const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    //Qin Qin 20120703
    if(cnf == NULL || usrData == NULL)
    {
        return;
    }

    m_nNvramWriteCnfCount++;
    //

    //tbSaveToNVRAM->Enabled = true;
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    if (( cnf->status != FDM_WRITE_SUCCESS ) ||( cnf->write_status != STATUS_OK_DIRVER ))
    {
        tbSaveToNVRAM->Enabled = true;
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM write record fail ";
        Application->MessageBox( "NVRAM write record fail", "FAILURE", MB_OK );
        return;
    }

    //Qin Qin 20120703
    int* iItemIndex = (int*)usrData;

    if( m_nModifyItemCount == m_nNvramWriteCnfCount)
    {
        tbSaveToNVRAM->Enabled = true;
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM write record successfully ";
    }
    //

    //sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM write record successfully ";
    if ( NVRAM_RawDataTree->Visible )
    {
        //NVRAM_RawDataTree->TreeSetModify( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle, false);
        NVRAM_RawDataTree->TreeSetModify( m_pNVRAM_TreeItem[*iItemIndex].vTreeItemHandle, false);
    }
    if( iItemIndex != NULL )
    {
        delete iItemIndex;
        iItemIndex = NULL;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbNVRAMTreePropertyClick(TObject *Sender)
{
    LPUNKNOWN pUnk = NVRAM_RawDataTree->ControlInterface;
    IOleObject* pIOle = NULL;
    if (SUCCEEDED( pUnk->QueryInterface( IID_IOleObject, (void**)&pIOle)))
    {
        IOleClientSite* pCS = NULL;
        pIOle->GetClientSite(&pCS);

        RECT rct;
        pIOle->DoVerb(OLEIVERB_PROPERTIES,NULL,pCS,0, this->Handle ,&rct);

        pIOle->Release();
        pCS->Release();
    }
}
//---------------------------------------------------------------------------
bool TfrmNVRAMEditor::get_index_from_handle( TreeStructType *tst, int i, int &index )
{
    for( int k = 0; k < iTotalTreeItemCount; k++)
    {
        if (tst[ k ].vTreeItemHandle.intVal == i )
        {
            index = k;
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbNVRAMClearClick(TObject *Sender)
{
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }
    if( ! NVRAMMan->Get_IsInit() )
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM database file initialization fail";
        sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
        sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
        Application->MessageBox( "Execution Failure : NVRAM database file initialization fail", "FAILURE", MB_OK );
        return;
    }

    if (  NVRAM_RawDataTree->Visible )
    {
        if (iTotalTreeItemCount == 0)
            return;

        TVariant vTreeItemHandle;

        NVRAM_RawDataTree->TreeGetSel( &vTreeItemHandle );
        if ( vTreeItemHandle.intVal == 0 )
        {
            sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) " Please select a tree item to clear ";
            sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
            sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
            Application->MessageBox( "Please select a tree item to clear", "WARNING", MB_OK );
            return;
        }

        int iItemIndex = -1;

        if ( ! get_index_from_handle( m_pNVRAM_TreeItem,  vTreeItemHandle.intVal , iItemIndex ))
        {
            sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  AP editor error: can't get item index ";
            sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
            sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
            Application->MessageBox( "Execution Failure : AP editor error: can't get item index", "FAILURE", MB_OK );
        }
        else
        {
            long lModified;

            NVRAM_RawDataTree->TreeGetModify( m_pNVRAM_TreeItem[ iItemIndex].vTreeItemHandle , &lModified );
            if ( lModified )
            {
                int msg_result = Application->MessageBox( " Do you want to save this struct ? ",
                                 " AP editor ",
                                 MB_YESNOCANCEL) ;
                switch ( msg_result )
                {
                case IDYES :
                    tbSaveToNVRAMClick( NULL );
                    tbNVRAMClearClick(Sender);
                    return;
                case IDNO :
                    NVRAM_RawDataTree->TreeDeleteItem( m_pNVRAM_TreeItem[ iItemIndex ].vTreeItemHandle );
                    m_pNVRAM_TreeItem[ iItemIndex ].vTreeItemHandle.intVal = 0 ;
                    break;
                case IDCANCEL :
                    return;
                } // switch
            }
            else
            {
                NVRAM_RawDataTree->TreeDeleteItem( m_pNVRAM_TreeItem[ iItemIndex ].vTreeItemHandle );
                m_pNVRAM_TreeItem[ iItemIndex ].vTreeItemHandle.intVal = 0 ;
                sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  Clear NVRAM record successfully";
                sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
                sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
            }
        }
    }
    else
    {
        fill_StringGrid( sg_NVRAM_editor,
                         RAW_DATA_START_COL,
                         RAW_DATA_START_ROW,
                         RAW_DATA_COL_COUNTS,
                         m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].iDataLen,
                         AnsiString("00") );
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::OnClick(TObject *Sender)//no use
{
    if (find_node_index( m_pNVRAM_TreeItem, tv_NVRAM->Selected, iNVRAM_TreeItemIndex ))
    {
        if(m_pNVRAM_TreeItem[ iNVRAM_TreeItemIndex ].vTreeItemHandle.intVal != 0)
        {
            NVRAM_RawDataTree->TreeSetSel( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle );
        }
    }
}
//---------------------------------------------------------------------------
bool TfrmNVRAMEditor::Get_Total_RecNum( TStringList* psl_list, int lid_num, int &total_rec_num)
{
    int rec_num = 0;
    total_rec_num = 0;
    for( int i=0; i<lid_num; i++ )
    {
        if(META_SUCCESS != SP_META_NVRAM_GetRecNum(psl_list->Strings[i].c_str(), &rec_num))
        {
            return false;
        }
        total_rec_num += rec_num;
    }
    return true;
}
//---------------------------------------------------------------------------
bool TfrmNVRAMEditor::Get_Max_RecNum( TStringList* psl_list, int lid_num, int &max_rec_num )
{
    int rec_num = 0;
    max_rec_num = 0;
    for( int i = 0; i < lid_num; i++ )
    {
        if(META_SUCCESS != SP_META_NVRAM_GetRecNum(psl_list->Strings[i].c_str(), &rec_num))
        {
            return false;
        }

        if( max_rec_num < rec_num )
            max_rec_num = rec_num;
    }
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbLockNVRAMClick(TObject *Sender)
{
    m_NVRAMCtlLocker.Lock();
    m_NVRAM_LOCK_Obj.ConfirmCallback = ::CNF_NVRAMLock;
    m_NVRAM_LOCK_Obj.REQ_Start();

//    CurrentPageLock();

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  Locks NVRAM progressing ";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::CNF_NVRAMLock( void )
{
    int state = m_NVRAM_LOCK_Obj.Get_ConfirmState();

    switch( state )
    {
    case STATE_NVRAM_LOCK_OK:
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  Locks NVRAM successfully ";
    }
    break;

    case STATE_NVRAM_LOCK_FAIL:
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString)"  Locks NVRAM  fail";
        Application->MessageBox( "Execution Failure : Locks NVRAM ", "FAILURE", MB_OK );
        //Force_WiFi_Stop();

    }
    break;

    case STATE_NVRAM_LOCK_TIMEOUT:
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString)"  Locks NVRAM timeout";
        Application->MessageBox( "Execution Timeout : Locks NVRAM ", "TIMEOUT", MB_OK );
        // Force_WiFi_Stop();
    }
    break;

    case STATE_NVRAM_LOCK_STOP:
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString)"  Locks NVRAM stop";
    }
    break;
    }

//    CurrentPageReset();
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
    m_NVRAMCtlLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbResetNVRAMClick(TObject *Sender)
{
    //initialization of NVRAM
    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
        //        return;
    }
    if( ! NVRAMMan->Get_IsInit() )
    {
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }
    m_NVRAMCtlLocker.Lock();
    //initialize statusbar in UI
    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    //
    if ( NVRAM_RawDataTree->Visible )
    {
        // Active X tree
        if (  tv_NVRAM->Selected == NULL )
        {
            Application->MessageBox( " You must select a element to download to NVRAM ", "Notice", MB_OK );
            m_NVRAMCtlLocker.Unlock();
            return;
        }
        m_ptn_selected = tv_NVRAM->Selected;

        if ( m_ptn_selected->Parent == NULL )
        {
            Application->MessageBox( " You need to select a element to download to NVRAM ", "Notice", MB_OK );
            m_NVRAMCtlLocker.Unlock();
            return;
        }

        if (! get_index_from_LID( m_ptn_selected->Parent->Text.c_str(),
                                  &iNVRAM_TreeItemIndex
                                ))
        {
            Application->MessageBox( " AP editor error: can't find index", "FAILURE", MB_OK );
            m_NVRAMCtlLocker.Unlock();
            return;
        }

        iNVRAM_TreeItemIndex = iNVRAM_TreeItemIndex +  m_ptn_selected->Text.ToInt()-1;

        if ( Sender != NULL )
        {
            dynamic_cast <TControl *>(Sender)->Enabled = false;
        }

        if( NULL == m_NVRAM_Reset_Req )
        {
            m_NVRAM_Reset_Req = new AP_FT_NVRAM_RESET_REQ;
        }

        m_NVRAM_Reset_Req->LID = m_ptn_selected->Parent->Text.c_str();
        m_NVRAM_Reset_Req->category = (ResetCategory)3;

        META_RESULT MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                 m_NVRAM_Reset_Req,
                                 ::NVRAM_reset_cnf_cb,
                                 &m_sNVRAM_reset_token,
                                 NULL );

        if ( MetaResult != META_SUCCESS )
        {
            META_result_handler(MetaResult);
            if ( Sender != NULL )
            {
                dynamic_cast <TControl *>(Sender)->Enabled = true;
            }
            m_NVRAMCtlLocker.Unlock();
            return;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbResetAllClick(TObject *Sender)
{
    META_RESULT MetaResult = META_SUCCESS;

    if( ! NVRAMMan->Get_IsInit() )
    {
        frmMainSel->mnuFDMDatabaseClick(Sender);
    }
    if( ! NVRAMMan->Get_IsInit() )
    {
        Application->MessageBox( "Execution Failure : NVRAM database file initialize fail", "FAILURE", MB_OK );
        return;
    }

    m_NVRAMCtlLocker.Lock();
    //initialize statusbar in UI
    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    //  Application->MessageBox( "Execution Remind : NVRAM Reset All?", "REMIND", MB_OKCANCEL);
    //  DialogResult dres = MessageBox.Show(...);
    //  sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "Cancel Reset ALL Command";
    //    return;
    //   }


    char LID_para[] = "NVRAM_RESET_ALL";

    if( NULL == m_NVRAM_Reset_Req )
    {
        m_NVRAM_Reset_Req = new AP_FT_NVRAM_RESET_REQ;
    }

    m_NVRAM_Reset_Req->category = NVRAM_RESET_ALL;
    m_NVRAM_Reset_Req->LID = LID_para;

    MetaResult = SP_META_NVRAM_Reset_r( m_META_HANDLE_Obj.Get_MainHandle(),
                                        m_NVRAM_Reset_Req,
                                        ::NVRAM_reset_cnf_cb,
                                        &m_sNVRAM_reset_token,
                                        NULL );

    if ( MetaResult != META_SUCCESS )
    {
        META_result_handler(MetaResult);
        if ( Sender != NULL )
        {
            dynamic_cast <TControl *>(Sender)->Enabled = true;
        }
        m_NVRAMCtlLocker.Unlock();
        return;
    }
}
//---------------------------------------------------------------------------
void __stdcall TfrmNVRAMEditor::NVRAM_reset_cnf_cb( const AP_FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData)
{
    tbResetNVRAM->Enabled = true;
    if (( cnf->status == FDM_RESET_SUCCESS ) ||cnf->reset_status == 1)
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM reset successfully ";
        sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
        sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
    }
    else
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM reset fail ";
        sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
        sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
        Application->MessageBox( "NVRAM reset  fail", "FAILURE", MB_OK );
    }
    m_NVRAMCtlLocker.Unlock();
}
//------------------------------------------------------------------------------
bool  TfrmNVRAMEditor::Backup_GetFileNames(const AnsiString& file,AnsiString& bpFile1,AnsiString& bpFile2)
{
    int pos = file.AnsiPos(".");
    if( pos != 0)
    {
        //AnsiString tmp = file.SubString(pos + 1,3);
        if(file.SubString(pos + 1,3) == "map")
        {
            bpFile1 = file;
            bpFile2 = file.SubString(0,pos) + "dat";
            return true;
        }
        else if(file.SubString(pos + 1,3) == "dat")
        {
            bpFile1 = file.SubString(0,pos) + "map";
            bpFile2 = file;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        bpFile1 = file + ".map" ;
        bpFile2 = file + ".dat" ;
        return true;
    }
}
//------------------------------------------------------------------------------
bool  TfrmNVRAMEditor::Restore_GetFileNames(const AnsiString& file,AnsiString& bpFile1,AnsiString& bpFile2)
{
    int pos = file.AnsiPos(".");
    if( pos != 0)
    {
        if(file.SubString(pos + 1,3) == "map")
        {
            bpFile1 = file;
            bpFile2 = file.SubString(0,pos) + "dat";
            return true;
        }
        else if(file.SubString(pos + 1,3) == "dat")
        {
            bpFile1 = file.SubString(0,pos) + "map";
            bpFile2 = file;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        bpFile1 = file + ".map";
        bpFile2 = file + ".dat";
        return true;
    }
}
//------------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::tbBackupClick(TObject *Sender)
{
    m_NVRAMCtlLocker.Lock();
    //initialize statusbar in UI
    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
    tbBackup->Enabled = false;
    tbRestore->Enabled = false;

    if(!BackupSaveDialog->Execute())
    {
        tbBackup->Enabled = true;
        tbRestore->Enabled = true;
        Application->MessageBox( "Execution Failure : NVRAM Backup save file failed !", "FAILURE", MB_OK );
        m_NVRAMCtlLocker.Unlock();
        return;
    }

    if(!Backup_GetFileNames(BackupSaveDialog->FileName,m_file_name1,m_file_name2))
    {
        tbBackup->Enabled = true;
        tbRestore->Enabled = true;
        Application->MessageBox( "Execution Failure : NVRAM Backup save file name wrong !", "FAILURE", MB_OK );
        m_NVRAMCtlLocker.Unlock();
        return;
    }
    sb_NVRAM_editor->Panels->Items[1]->Text = m_file_name1;
    sb_NVRAM_editor->Panels->Items[2]->Text = m_file_name2;
    NVRAMMan->ConfirmCallback = ::CNF_NVRAMBackup;
    NVRAMMan->REQ_NVRAMBackup_Start(m_file_name1,m_file_name2);
}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::CNF_NVRAMBackup(void)
{
    tbBackup->Enabled = true;
    tbRestore->Enabled = true;

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    if(state != META_SUCCESS)
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM Backup file failed !";
    }
    else
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM Backup file OK !";
    }
    m_NVRAMCtlLocker.Unlock();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::rbRestoreClick(TObject *Sender)
{
    m_NVRAMCtlLocker.Lock();
    //initialize statusbar in UI
    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";
    tbBackup->Enabled = false;
    tbRestore->Enabled = false;

    if(!RestoreOpenDialog->Execute())
    {
        tbBackup->Enabled = true;
        tbRestore->Enabled = true;
        Application->MessageBox( "Execution Failure : NVRAM Restore open file1 failed !", "FAILURE", MB_OK );
        m_NVRAMCtlLocker.Unlock();
        return;
    }

    if(!Restore_GetFileNames(RestoreOpenDialog->FileName,m_file_name1,m_file_name2))
    {
        tbBackup->Enabled = true;
        tbRestore->Enabled = true;
        Application->MessageBox( "Execution Failure : NVRAM Restore open file name wrong !", "FAILURE", MB_OK );
        m_NVRAMCtlLocker.Unlock();
        return;
    }
    sb_NVRAM_editor->Panels->Items[1]->Text = m_file_name1;
    sb_NVRAM_editor->Panels->Items[2]->Text = m_file_name2;

    NVRAMMan->ConfirmCallback = ::CNF_NVRAMRestore;
    NVRAMMan->REQ_NVRAMRestore_Start(m_file_name1,m_file_name2);

}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::CNF_NVRAMRestore(void)
{
    tbBackup->Enabled = true;
    tbRestore->Enabled = true;

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    if(state != META_SUCCESS)
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM Restore file failed !";
    }
    else
    {
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM Restore file OK !";
    }
    m_NVRAMCtlLocker.Unlock();
}
//---------------------------------------------------------------------------
/**
*
* @return true: clean up NVRAM tree view items and go for replace database false: do not clean up NVRAM tree view and don't replace database
*/
bool  TfrmNVRAMEditor::ReplaceDatabaseClean( void )
{
    TVariant firstModifiedItem;
    int nCount;
    NVRAM_RawDataTree->TreeGetCount(&nCount);
    if(nCount > 0)
    {
        NVRAM_RawDataTree->TreeGetFirstModify(&firstModifiedItem);
        if( NVRAMMan->Get_IsInit() && (firstModifiedItem.lVal != NULL))
        {
            int ret_code = MessageDlg("There is modified items in NVRAM editor. Are you sure want to change database?" , mtConfirmation, mbOKCancel, 0);
            if(ret_code == mrCancel)
            {
                // do not clean up NVRAM items and cancel the replace database operation
                return false;
            }
            ClearNVRAMEditor();
        }
    }
    return true;
}
/**
* clean up left side tree view
*/
void  TfrmNVRAMEditor::ClearNVRAMEditor( void )
{
    // clean up all NVRAM items shown in treeview
    NVRAM_RawDataTree->TreeDeleteAllItems();
    tv_NVRAM->Items->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNVRAMEditor::FormShow(TObject *Sender)
{
    LOG("NVRAMEditor form center the form.");
    if (m_isFirstOpenNvram) {
        m_isFirstOpenNvram = false;
        if (NVRAM_RawDataTree->Visible) {
            NVRAMMan->Set_IsInit(false);
            ClearNVRAMEditor();
        }
        else
        {
            LOG("NVRAM_RawDataTree->Visible = false.");
        }
    }
    else
    {
        LOG("isFirstOpenNvram = false.");
    }
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------

void TfrmNVRAMEditor::CheckNVRAMReadWriteStatus(bool& isFinish)
{
    while (isFinish == false)
    {
        Application->ProcessMessages();
    }
}

//---------------------------------------------------------------------------
void TfrmNVRAMEditor::ReadWriteStressTest()
{
    char error_msg_str[1024];
    isNVRAMStressTest = true;
    m_vIndex.clear();
    
    for(int i = 0; i < m_iTotalLidNum; i++)
    {
        isNVRAMReadFinish = false;
        tv_NVRAM->Selected = m_ptn_RIDNode[i][0];
        tbReadFromNVRAM->Click();
        CheckNVRAMReadWriteStatus(isNVRAMReadFinish);
        if (NVRAMMan->Get_ConfirmState() != META_SUCCESS)
        {
            sprintf(error_msg_str, "NVRAM Read Stress Test Failed in %s.\nDo you want to keep testing ?", (m_ptn_LIDNode[i]->Text).c_str());
            if ( Application->MessageBox(error_msg_str, "Message", MB_YESNO) == IDNO )
            {
                return;
            }
        }
    }

    if ( Application->MessageBox("Start to NVRAM Write", "Message", MB_YESNO)== IDNO )
    {
        return;
    }

    for(int i = 0; i < m_iTotalLidNum; i++)
    {
        isNVRAMWriteFinish = false;
        tv_NVRAM->Selected = m_ptn_RIDNode[i][0];
        tbSaveToNVRAM->Click();
        CheckNVRAMReadWriteStatus(isNVRAMWriteFinish);
        if (NVRAMMan->Get_ConfirmState() != META_SUCCESS)
        {
            sprintf(error_msg_str, "NVRAM Write Stress Test Failed in %s.\nDo you want to keep testing ?", (m_ptn_LIDNode[i]->Text).c_str());
            if( Application->MessageBox(error_msg_str, "Message", MB_YESNO) == IDNO )
            {
                isNVRAMStressTest = false;
                return;
            }
        }
    }
    isNVRAMStressTest = false;
    Application->MessageBox("Finish the Read and Write Stress Test", "Message", MB_OK);
}

bool TfrmNVRAMEditor::IsValid(int &idx)
{
    for(int i=0; i<m_vIndex.size(); i++)
    {
        if(idx == m_vIndex[i])
            return false;
    }
    return true;
}

void TfrmNVRAMEditor::WriteNVRAMStressTest(TObject *Sender)
{
    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    if ( NVRAM_RawDataTree->Visible )
    {
        // Active X tree
        if (  tv_NVRAM->Selected == NULL )
        {
            Application->MessageBox( " You must select a element to download to NVRAM ", "Notice", MB_OK );
            return;
        }
        m_ptn_selected = tv_NVRAM->Selected;

        if ( m_ptn_selected->Parent == NULL )
        {
            Application->MessageBox( " You need to select a element to download to NVRAM ", "Notice", MB_OK );
            return;
        }

        if (!get_index_from_LID( m_ptn_selected->Parent->Text.c_str(),
                                  &iNVRAM_TreeItemIndex))
        {
            Application->MessageBox( " NVRAM editor error: can't find index", "FAILURE", MB_OK );
            return;
        }

        iNVRAM_TreeItemIndex = iNVRAM_TreeItemIndex +  m_ptn_selected->Text.ToInt() - 1;

        if(! IsValid(iNVRAM_TreeItemIndex))
        {
            isNVRAMWriteFinish = true;
            return;
        }

        if(!m_NVRAM_WriteReq )
        {
            m_NVRAM_WriteReq = new AP_FT_NVRAM_WRITE_REQ;
        }

        m_NVRAM_WriteReq->LID = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].LIDNAME;//m_ptn_selected->Parent->Text.c_str();
        m_NVRAM_WriteReq->RID = m_ptn_selected->Text.ToInt();
        m_NVRAM_WriteReq->buf = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].Buf;
        m_NVRAM_WriteReq->len = m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].iDataLen;

        META_RESULT mr1 = SP_META_NVRAM_Write_r( m_META_HANDLE_Obj.Get_MainHandle(),
                          m_NVRAM_WriteReq, ::NVRAM_Write_Cnf_cb, &m_sNVRAM_node_write_rec_token, NULL);

        if ( mr1 != META_SUCCESS )
        {
            META_result_handler(mr1);
        }
    }
} 

void __stdcall TfrmNVRAMEditor::NVRAM_Write_Cnf_cb(const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    sb_NVRAM_editor->Panels->Items[1]->Text = (AnsiString) "";
    sb_NVRAM_editor->Panels->Items[2]->Text = (AnsiString) "";

    if (( cnf->status != FDM_WRITE_SUCCESS ) ||( cnf->write_status != STATUS_OK_DIRVER ))
    {
        tbSaveToNVRAM->Enabled = true;
        sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM write record fail ";
        Application->MessageBox( "NVRAM write record fail", "FAILURE", MB_OK );
        isNVRAMWriteFinish = true;
        return;
    }

    sb_NVRAM_editor->Panels->Items[0]->Text = (AnsiString) "  NVRAM write record successfully ";
    if ( NVRAM_RawDataTree->Visible )
    {
        NVRAM_RawDataTree->TreeSetModify( m_pNVRAM_TreeItem[iNVRAM_TreeItemIndex].vTreeItemHandle, false);
    }
    isNVRAMWriteFinish = true;
}
//---------------------------------------------------------------------------
void TfrmNVRAMEditor::SetFirstOpenNvramEditor(bool isFirstOpenNvram)
{
    m_isFirstOpenNvram = isFirstOpenNvram;
}
//---------------------------------------------------------------------------
