//---------------------------------------------------------------------------

#include <vcl.h>   
#include <dir.h>
#include <stdio.h>
#pragma hdrstop

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include "NFCMain.h"

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TfrmNFCNew *frmNFCNew;
static bool is_stop = true;
//---------------------------------------------------------------------------
__fastcall TfrmNFCNew::TfrmNFCNew(TComponent* Owner)
        : TForm(Owner)
{
        WindowProc = SubClassWndProc;
}
static void ConfirmCallback_Reader( void )
{
    frmNFCNew->ConfirmCallback_Reader();
}

static void ConfirmCallback_Polling( void )
{
    frmNFCNew->ConfirmCallback_Polling();
}


static void ConfirmCallback_P2P( void )
{
    frmNFCNew->ConfirmCallback_P2P();
}

void _fastcall TfrmNFCNew::SubClassWndProc(Messages::TMessage &Message)
{
        int link_status;
        NFC_EM_ALS_READERM_NTF_S *readerNtf;
        NFC_EM_POLLING_NTF_S *pollingNtf;
        char Uid[100] = {0};


    switch ( Message.Msg )
    {
        case WM_ML_NFC_AIRM:

                readerNtf = (NFC_EM_ALS_READERM_NTF_S *)Message.WParam;

                for(unsigned int i = 0,j = 0; i < readerNtf->UidLen; i++)
                {

                        sprintf(Uid+j, "%02x", readerNtf->Uid[i]);
                        j += 2;
                }

                if(0 == readerNtf->result)
                {
                        form_AIRM_Reader->tl_AIRM_Reader_UID->Caption = Uid;
                        LOG("NFC_NOTIFY_CNF:0==result\n");
                        if(form_AIRM_Reader->Visible == false)
                        {
                             if(0 == readerNtf->isNDEF)
                             {
                                 LOG("NFC_NOTIFY_CNF:0==result:0==isNDEF,\n");
                                 form_AIRM_Reader->displayReadModule(false);
                                 form_AIRM_Reader->displayWriteModule(false);
                                 form_AIRM_Reader->displayFormatToNDEF(true);
                             }
                             else if(1 == readerNtf->isNDEF)
                             {
                                 LOG("NFC_NOTIFY_CNF:1==result:0==isNDEF,\n");
                                 form_AIRM_Reader->displayReadModule(true);
                                 form_AIRM_Reader->displayWriteModule(true);
                                 form_AIRM_Reader->displayFormatToNDEF(false);
                             }
                             else if(2 == readerNtf->isNDEF)
                             {
                                 LOG("NFC_NOTIFY_CNF:2==result:0==isNDEF,\n");
                                 form_AIRM_Reader->displayReadModule(true);
                                 form_AIRM_Reader->displayWriteModule(false);
                                 form_AIRM_Reader->displayFormatToNDEF(false);
                             }
                             form_AIRM_Reader->resetUI();
                             form_AIRM_Reader->ShowModal();
                        }
                }
                else if(2 == readerNtf->result)
                {
                        LOG("NFC_NOTIFY_CNF:2==result\n");
                        if(form_AIRM_Reader->Visible == true){
                                form_AIRM_Reader->Close();
                        }
                }
                else
                {
                    if(form_AIRM_Reader->Visible == false)
                    {
                        form_AIRM_Reader->tl_AIRM_Reader_UID->Caption = Uid;
                        form_AIRM_Reader->displayReadModule(false);
                        form_AIRM_Reader->displayWriteModule(false);
                        form_AIRM_Reader->displayFormatToNDEF(false);
                                                           
                        form_AIRM_Reader->resetUI();
                        form_AIRM_Reader->ShowModal();
                    }
                }



                break;
        case WM_ML_NFC_P2P:
                LOG("WM_ML_NFC_P2P\n");
                link_status = (int)Message.WParam;
                if(0 == link_status)
                {          
                        LOG("0 == link_status\n");
                        tl_AIP2PM_Link_Status_up->Visible = false;
                        tl_AIP2PM_Link_Status_down->Visible = true;
                }
                else if(1 == link_status)
                {
                        LOG("1 == link_status\n");
                        tl_AIP2PM_Link_Status_up->Visible = true;
                        tl_AIP2PM_Link_Status_down->Visible = false;
                }
                break;
        case WN_ML_NFC_POLLING_LOOP:

                pollingNtf = (NFC_EM_POLLING_NTF_S *)Message.WParam;
                if(1 == pollingNtf->detecttype)
                {
                        LOG("1 == pollingNtf->detecttype\n");

                        for(unsigned int i = 0,j = 0; i < pollingNtf->ntf.reader.UidLen; i++)
                        {

                                sprintf(Uid+j, "%02x", pollingNtf->ntf.reader.Uid[i]);
                                j += 2;
                        }

                        LOG("After for loop\n");


                        if(0 == pollingNtf->ntf.reader.result)
                        {
                                form_AIRM_Reader->tl_AIRM_Reader_UID->Caption = Uid;
                                LOG("NFC_NOTIFY_CNF:0==result\n");
                                if(form_AIRM_Reader->Visible == false)
                                {
                                     if(0 == pollingNtf->ntf.reader.isNDEF)
                                     {
                                         LOG("NFC_NOTIFY_CNF:0==result:0==isNDEF,\n");
                                         form_AIRM_Reader->displayReadModule(false);
                                         form_AIRM_Reader->displayWriteModule(false);
                                         form_AIRM_Reader->displayFormatToNDEF(true);
                                     }
                                     else if(1 == pollingNtf->ntf.reader.isNDEF)
                                     {
                                         LOG("NFC_NOTIFY_CNF:1==result:0==isNDEF,\n");
                                         form_AIRM_Reader->displayReadModule(true);
                                         form_AIRM_Reader->displayWriteModule(true);
                                         form_AIRM_Reader->displayFormatToNDEF(false);
                                     }
                                     else if(2 == pollingNtf->ntf.reader.isNDEF)
                                     {
                                         LOG("NFC_NOTIFY_CNF:2==result:0==isNDEF,\n");
                                         form_AIRM_Reader->displayReadModule(true);
                                         form_AIRM_Reader->displayWriteModule(false);
                                         form_AIRM_Reader->displayFormatToNDEF(false);
                                     }
                                     form_AIRM_Reader->resetUI();
                                     form_AIRM_Reader->ShowModal();
                                }
                        }
                        else if(2 == pollingNtf->ntf.reader.result)
                        {
                                LOG("NFC_NOTIFY_CNF:2==result\n");
                                if(form_AIRM_Reader->Visible == true){
                                        form_AIRM_Reader->Close();
                                }
                        }
                        else
                        {
                             if(form_AIRM_Reader->Visible == false)
                             {
                                form_AIRM_Reader->tl_AIRM_Reader_UID->Caption = Uid;
                                form_AIRM_Reader->displayReadModule(false);
                                form_AIRM_Reader->displayWriteModule(false);
                                form_AIRM_Reader->displayFormatToNDEF(false);
                                form_AIRM_Reader->resetUI();
                                form_AIRM_Reader->ShowModal();
                             }


                        }    
                }
                else if(2 == pollingNtf->detecttype)
                {
                        Application->MessageBox( "Card Emulation Mode", "SUCCESS", MB_OK );
                }
                else if(4 == pollingNtf->detecttype)
                {
                        link_status = pollingNtf->ntf.p2p.link_status;
                        if(0 == link_status)
                        {
                                cb_PLM_P2PM_LinkStatus_up->Visible = false;
                                cb_PLM_P2PM_LinkStatus_down->Visible = true;
                        }
                        else if(1 == link_status)
                        {
                                cb_PLM_P2PM_LinkStatus_up->Visible = true;
                                cb_PLM_P2PM_LinkStatus_down->Visible = false;
                        }
                }
                break;
        case WM_CLOSE:
                if(!is_stop)
                {
                        Application->MessageBoxA("Please stop first!", "Info", MB_OK);
                        break;
                }

        default:
                this->WndProc( Message );
                break;
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_AIRM_TypeAClick(TObject *Sender)
{
        if(cb_AIRM_TypeA->Checked == true)
        {
                rb_AIRM_TypeA_106kbps->Enabled = true;
                rb_AIRM_TypeA_212kbps->Enabled = true;
                rb_AIRM_TypeA_424kbps->Enabled = true;
                rb_AIRM_TypeA_848kbps->Enabled = true;
        }
        else
        {
               
                rb_AIRM_TypeA_106kbps->Enabled = false;
                rb_AIRM_TypeA_212kbps->Enabled = false;
                rb_AIRM_TypeA_424kbps->Enabled = false;
                rb_AIRM_TypeA_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_AIRM_TypeBClick(TObject *Sender)
{
        if(cb_AIRM_TypeB->Checked == true)
        {
                rb_AIRM_TypeB_106kbps->Enabled = true;
                rb_AIRM_TypeB_212kbps->Enabled = true;
                rb_AIRM_TypeB_424kbps->Enabled = true;
                rb_AIRM_TypeB_848kbps->Enabled = true;
        }
        else
        {
                rb_AIRM_TypeB_106kbps->Enabled = false;
                rb_AIRM_TypeB_212kbps->Enabled = false;
                rb_AIRM_TypeB_424kbps->Enabled = false;
                rb_AIRM_TypeB_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_AIRM_TypeFClick(TObject *Sender)
{
        if(cb_AIRM_TypeF->Checked == true)
        {
                rb_AIRM_TypeF_212kbps->Enabled = true;
                rb_AIRM_TypeF_424kbps->Enabled = true;
        }
        else
        { 
                rb_AIRM_TypeF_212kbps->Enabled = false;
                rb_AIRM_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_AIRM_TypeVClick(TObject *Sender)
{
        if(cb_AIRM_TypeV->Checked == true)
        {
              rb_AIRM_TypeV_Subcarrier->Enabled = true;
//              rb_AIRM_TypeV_DualSubcarrie->Enabled = true;
              rb_AIRM_TypeV_CodingMode_4->Enabled = true;
//              rb_AIRM_TypeV_CodingMode_256->Enabled = true;
              rb_AIRM_TypeV_6_62kbps->Enabled = true;
//              cb_AIRM_TypeV_26_48kbps->Enabled = true;
        }
        else
        {
              rb_AIRM_TypeV_Subcarrier->Enabled = false;
              rb_AIRM_TypeV_DualSubcarrie->Enabled = false;
              rb_AIRM_TypeV_CodingMode_4->Enabled = false;
              rb_AIRM_TypeV_CodingMode_256->Enabled = false;
              rb_AIRM_TypeV_6_62kbps->Enabled = false;
              rb_AIRM_TypeV_26_48kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_AIRM_SelectAllClick(TObject *Sender)
{
        cb_AIRM_TypeA->Checked = true;
        cb_AIRM_TypeB->Checked = true;
        cb_AIRM_TypeF->Checked = true;
        cb_AIRM_TypeV->Checked = true;
        //cb_AIRM_TypeB_plus->Checked = true;
        cb_AIRM_Kovio->Checked = true;

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_AIRM_ClearAllClick(TObject *Sender)
{
        cb_AIRM_TypeA->Checked = false;
        cb_AIRM_TypeB->Checked = false;
        cb_AIRM_TypeF->Checked = false;
        cb_AIRM_TypeV->Checked = false;
        //cb_AIRM_TypeB_plus->Checked = false;
        cb_AIRM_Kovio->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_P2PM_TypeAClick(TObject *Sender)
{
        if(cb_P2PM_TypeA->Checked == true)
        {
               rb_P2PM_TypeA_106kbps->Enabled = true;
               rb_P2PM_TypeA_212kbps->Enabled = true;
               rb_P2PM_TypeA_424kbps->Enabled = true;
               rb_P2PM_TypeA_848kbps->Enabled = true;
        }
        else
        {
               rb_P2PM_TypeA_106kbps->Enabled = false;
               rb_P2PM_TypeA_212kbps->Enabled = false;
               rb_P2PM_TypeA_424kbps->Enabled = false;
               rb_P2PM_TypeA_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::cb_P2PM_TypeFClick(TObject *Sender)
{
        if(cb_P2PM_TypeF->Checked == true)
        {
               rb_P2PM_TypeF_212kbps->Enabled = true;
               rb_P2PM_TypeF_424kbps->Enabled = true;
        }
        else
        {                                            
               rb_P2PM_TypeF_212kbps->Enabled = false;
               rb_P2PM_TypeF_424kbps->Enabled = false;

        }        
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_P2PM_SelectAllClick(TObject *Sender)
{
        cb_P2PM_TypeA->Checked = true;
        cb_P2PM_TypeF->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_P2PM_ClearAllClick(TObject *Sender)
{
        cb_P2PM_TypeA->Checked = false;
        cb_P2PM_TypeF->Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_AICEM_SelectAllClick(TObject *Sender)
{
//        cb_AICEM_SWIO1->Checked = true;
//        cb_AICEM_SWIO2->Checked = true;
//        cb_AICEM_SWIO_SE->Checked = true;
        cb_AICEM_TypeA->Checked = true;
        cb_AICEM_TypeB->Checked = true;
        cb_AICEM_TypeB_plus->Checked = true;
        cb_AICEM_TypeF->Checked = true;
//        cb_AICEM_VirtualCardFunction->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_AICEM_ClearAllClick(TObject *Sender)
{
//        cb_AICEM_SWIO1->Checked = false;
//        cb_AICEM_SWIO2->Checked = false;
//        cb_AICEM_SWIO_SE->Checked = false;
        cb_AICEM_TypeA->Checked = false;
        cb_AICEM_TypeB->Checked = false;
        cb_AICEM_TypeB_plus->Checked = false;
        cb_AICEM_TypeF->Checked = false;
//        cb_AICEM_VirtualCardFunction->Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_PLM_SelectAllClick(TObject *Sender)
{
      cb_PLM_RM->Checked = true;
      cb_PLM_P2PM->Checked = true;
      cb_PLM_CEM->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_PLM_ClearAllClick(TObject *Sender)
{
      cb_PLM_RM->Checked = false;
      cb_PLM_P2PM->Checked = false;
      cb_PLM_CEM->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_RMClick(TObject *Sender)
{
        if(cb_PLM_RM->Checked == true){
                cb_PLM_RM_TypeA->Enabled = true;
                cb_PLM_RM_TypeB->Enabled = true;
                cb_PLM_RM_TypeF->Enabled = true;
                cb_PLM_RM_TypeV->Enabled = true;
                //cb_PLM_RM_TypeB_plus->Enabled = true;
                cb_PLM_RM_Kovio->Enabled = true;

                cb_PLM_RM_TypeA_106kbps->Enabled = true;
                cb_PLM_RM_TypeA_212kbps->Enabled = true;
                cb_PLM_RM_TypeA_424kbps->Enabled = true;
                cb_PLM_RM_TypeA_848kbps->Enabled = true;

                cb_PLM_RM_TypeB_106kbps->Enabled = true;
                cb_PLM_RM_TypeB_212kbps->Enabled = true;
                cb_PLM_RM_TypeB_424kbps->Enabled = true;
                cb_PLM_RM_TypeB_848kbps->Enabled = true;

                cb_PLM_RM_TypeF_212kbps->Enabled = true;
                cb_PLM_RM_TypeF_424kbps->Enabled = true;

                cb_PLM_RM_TypeV_Subcarrier->Enabled = true;
                cb_PLM_RM_TypeV_DualSubcarrier->Enabled = true;
                cb_PLM_RM_TypeV_CodingMode_4->Enabled = true;
                cb_PLM_RM_TypeV_CodingMode_256->Enabled = true;
                cb_PLM_RM_6_62kbps->Enabled = true;
                cb_PLM_RM_26_48kbps->Enabled = true;
        }
        else
        {
                cb_PLM_RM_TypeA->Enabled = false;
                cb_PLM_RM_TypeB->Enabled = false;
                cb_PLM_RM_TypeF->Enabled = false;
                cb_PLM_RM_TypeV->Enabled = false;
                //cb_PLM_RM_TypeB_plus->Enabled = false;
                cb_PLM_RM_Kovio->Enabled = false;

                cb_PLM_RM_TypeA_106kbps->Enabled = false;
                cb_PLM_RM_TypeA_212kbps->Enabled = false;
                cb_PLM_RM_TypeA_424kbps->Enabled = false;
                cb_PLM_RM_TypeA_848kbps->Enabled = false;

                cb_PLM_RM_TypeB_106kbps->Enabled = false;
                cb_PLM_RM_TypeB_212kbps->Enabled = false;
                cb_PLM_RM_TypeB_424kbps->Enabled = false;
                cb_PLM_RM_TypeB_848kbps->Enabled = false;

                cb_PLM_RM_TypeF_212kbps->Enabled = false;
                cb_PLM_RM_TypeF_424kbps->Enabled = false;

                cb_PLM_RM_TypeV_Subcarrier->Enabled = false;
                cb_PLM_RM_TypeV_DualSubcarrier->Enabled = false;
                cb_PLM_RM_TypeV_CodingMode_4->Enabled = false;
                cb_PLM_RM_TypeV_CodingMode_256->Enabled = false;
                cb_PLM_RM_6_62kbps->Enabled = false;
                cb_PLM_RM_26_48kbps->Enabled = false;
        }

}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::cb_PLM_RM_TypeAClick(TObject *Sender)
{
        if(cb_PLM_RM_TypeA->Checked == true)
        {
                cb_PLM_RM_TypeA_106kbps->Enabled = true;
                cb_PLM_RM_TypeA_212kbps->Enabled = true;
                cb_PLM_RM_TypeA_424kbps->Enabled = true;
                cb_PLM_RM_TypeA_848kbps->Enabled = true;
        }
        else
        {
                cb_PLM_RM_TypeA_106kbps->Enabled = false;
                cb_PLM_RM_TypeA_212kbps->Enabled = false;
                cb_PLM_RM_TypeA_424kbps->Enabled = false;
                cb_PLM_RM_TypeA_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_RM_TypeBClick(TObject *Sender)
{
        if(cb_PLM_RM_TypeB->Checked == true)
        {
                cb_PLM_RM_TypeB_106kbps->Enabled = true;
                cb_PLM_RM_TypeB_212kbps->Enabled = true;
                cb_PLM_RM_TypeB_424kbps->Enabled = true;
                cb_PLM_RM_TypeB_848kbps->Enabled = true;
        }
        else
        {
                cb_PLM_RM_TypeB_106kbps->Enabled = false;
                cb_PLM_RM_TypeB_212kbps->Enabled = false;
                cb_PLM_RM_TypeB_424kbps->Enabled = false;
                cb_PLM_RM_TypeB_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_RM_TypeFClick(TObject *Sender)
{
        if(cb_PLM_RM_TypeF->Checked == true)
        {
                cb_PLM_RM_TypeF_212kbps->Enabled = true;
                cb_PLM_RM_TypeF_424kbps->Enabled = true;
        }
        else
        {
                cb_PLM_RM_TypeF_212kbps->Enabled = false;
                cb_PLM_RM_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_RM_TypeVClick(TObject *Sender)
{
        if(cb_PLM_RM_TypeV->Checked == true){
                cb_PLM_RM_TypeV_Subcarrier->Enabled = true;
                cb_PLM_RM_TypeV_DualSubcarrier->Enabled = true;
                cb_PLM_RM_TypeV_CodingMode_4->Enabled = true;
                cb_PLM_RM_TypeV_CodingMode_256->Enabled = true;
                cb_PLM_RM_6_62kbps->Enabled = true;
                cb_PLM_RM_26_48kbps->Enabled = true;
        }
        else
        {
                cb_PLM_RM_TypeV_Subcarrier->Enabled = false;
                cb_PLM_RM_TypeV_DualSubcarrier->Enabled = false;
                cb_PLM_RM_TypeV_CodingMode_4->Enabled = false;
                cb_PLM_RM_TypeV_CodingMode_256->Enabled = false;
                cb_PLM_RM_6_62kbps->Enabled = false;
                cb_PLM_RM_26_48kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_P2PMClick(TObject *Sender)
{
        if(cb_PLM_P2PM->Checked == true)
        {
               cb_PLM_P2PM_TypeA->Enabled = true;
               cb_PLM_P2PM_TypeF->Enabled = true;
               cb_PLM_P2PM_PassiveMode->Enabled = true;
               cb_PLM_P2PM_ActiveMode->Enabled = true;
               cb_PLM_P2PM_Initiator->Enabled = true;
               cb_PLM_P2PM_Target->Enabled = true;
               cb_PLM_P2PM_DisableCardEmulation->Enabled = true;

               rb_PLM_P2PM_TypeA_106kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_212kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_424kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_848kbps->Enabled = true;

               rb_PLM_P2PM_TypeF_212kbps->Enabled = true;
               rb_PLM_P2PM_TypeF_424kbps->Enabled = true;
        }
        else
        {
               cb_PLM_P2PM_TypeA->Enabled = false;
               cb_PLM_P2PM_TypeF->Enabled = false;
               cb_PLM_P2PM_PassiveMode->Enabled = false;
               cb_PLM_P2PM_ActiveMode->Enabled = false;
               cb_PLM_P2PM_Initiator->Enabled = false;
               cb_PLM_P2PM_Target->Enabled = false;
               cb_PLM_P2PM_DisableCardEmulation->Enabled = false;

               rb_PLM_P2PM_TypeA_106kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_212kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_424kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_848kbps->Enabled = false;
               
               rb_PLM_P2PM_TypeF_212kbps->Enabled = false;
               rb_PLM_P2PM_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_CEMClick(TObject *Sender)
{
        if(cb_PLM_CEM->Checked == true)
        {
                rb_PLM_CEM_SWIO1->Enabled = true;
                rb_PLM_CEM_SWIO2->Enabled = true;
                rb_PLM_CEM_SWIOSE->Enabled = true;
                cb_PLM_CEM_TypeA->Enabled = true;
                cb_PLM_CEM_TypeB->Enabled = true;
                cb_PLM_CEM_TypeB_plus->Enabled = true;
                cb_PLM_CEM_TypeF->Enabled = true;
                tb_PLM_Start->Enabled = false;
        }
        else
        {
                rb_PLM_CEM_SWIO1->Enabled = false;
                rb_PLM_CEM_SWIO2->Enabled = false;
                rb_PLM_CEM_SWIOSE->Enabled = false;
                cb_PLM_CEM_TypeA->Enabled = false;
                cb_PLM_CEM_TypeB->Enabled = false;
                cb_PLM_CEM_TypeB_plus->Enabled = false;
                cb_PLM_CEM_TypeF->Enabled = false;  
                tb_PLM_Start->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_P2PM_TypeAClick(TObject *Sender)
{
        if(cb_PLM_P2PM_TypeA->Checked == true)
        {
               rb_PLM_P2PM_TypeA_106kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_212kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_424kbps->Enabled = true;
               rb_PLM_P2PM_TypeA_848kbps->Enabled = true;
        }
        else
        {
               
               rb_PLM_P2PM_TypeA_106kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_212kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_424kbps->Enabled = false;
               rb_PLM_P2PM_TypeA_848kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_PLM_P2PM_TypeFClick(TObject *Sender)
{
        if(cb_PLM_P2PM_TypeF->Checked == true)
        {
               rb_PLM_P2PM_TypeF_212kbps->Enabled = true;
               rb_PLM_P2PM_TypeF_424kbps->Enabled = true;
        }
        else
        {
               rb_PLM_P2PM_TypeF_212kbps->Enabled = false;
               rb_PLM_P2PM_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_SelectAllClick(TObject *Sender)
{
       cb_VCF_TypeA->Checked = true;
       cb_VCF_TypeB->Checked = true;
       cb_VCF_TypeF->Checked = true;
       cb_VCF_TypeB_plus->Checked = true;

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_ClearAllClick(TObject *Sender)
{
       cb_VCF_TypeA->Checked = false;
       cb_VCF_TypeB->Checked = false;
       cb_VCF_TypeF->Checked = false;
       cb_VCF_TypeB_plus->Checked = false;

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_VCF_TypeFClick(TObject *Sender)
{
        if(cb_VCF_TypeF->Checked == true)
        {
                rb_VCF_TypeF_212kbps->Enabled = true;
                rb_VCF_TypeF_424kbps->Enabled = true;
        }
        else
        {
                rb_VCF_TypeF_212kbps->Enabled = false;
                rb_VCF_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------
/*
void __fastcall TfrmNFCNew::cb_Others_VCF_SelectAllClick(TObject *Sender)
{
        cb_Others_VCF_TypeA->Checked = true;
        cb_Others_VCF_TypeB->Checked = true;
        cb_Others_VCF_TypeF->Checked = true;
        cb_Others_VCF_TypeB_plus->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_Others_VCF_ClearAllClick(TObject *Sender)
{
        cb_Others_VCF_TypeA->Checked = false;
        cb_Others_VCF_TypeB->Checked = false;
        cb_Others_VCF_TypeF->Checked = false;
        cb_Others_VCF_TypeB_plus->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_Others_VCF_TypeFClick(TObject *Sender)
{
        if(cb_Others_VCF_TypeF->Checked == true)
        {
                cb_Others_VCF_TypeF_212kbps->Enabled = true;
                cb_Others_VCF_TypeF_424kbps->Enabled = true;
        }
        else
        {
                cb_Others_VCF_TypeF_212kbps->Enabled = false;
                cb_Others_VCF_TypeF_424kbps->Enabled = false;
        }
}
//---------------------------------------------------------------------------

*/

void TfrmNFCNew::ConfirmCallback_Reader(void)
{
    META_RESULT state = m_NfcReaderObj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
         Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
         if(!CompareStr(tb_AIRM_Start->Caption, EM_ALS_READER_START))
         {
                is_stop = false;
                tb_AIRM_Start->Caption = EM_ALS_READER_STOP;
         }
         else
         {
                is_stop = true;
                tb_AIRM_Start->Caption = EM_ALS_READER_START;
         }
    }
    break;

    case META_FAILED:
    case META_TIMEOUT:
    case META_CANCEL:
    case METAAPP_STOP:
    {
         Application->MessageBoxA("Failed!", "FAIL", MB_OK);
    }
    break;
    }
}

void TfrmNFCNew::ConfirmCallback_Polling(void)
{
    META_RESULT state = m_NfcPOLLINGObj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
         Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
         if(!CompareStr(tb_PLM_Start->Caption, EM_ALS_READER_START))
         {
                is_stop = false;
                tb_PLM_Start->Caption = EM_ALS_READER_STOP;
         }
         else
         {
                is_stop = true;
                tb_PLM_Start->Caption = EM_ALS_READER_START;
         }
    }
    break;

    case META_FAILED:
    case META_TIMEOUT:
    case META_CANCEL:
    case METAAPP_STOP:
    {
         Application->MessageBoxA("Failed!", "FAIL", MB_OK);
    }
    break;
    }
}

void TfrmNFCNew::ConfirmCallback_P2P(void)
{
    META_RESULT state = m_NfcP2PObj.Get_ConfirmState();

    switch (state)
    {
        case META_SUCCESS:
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_P2PM_Start->Caption, EM_ALS_READER_START))
                {
                        is_stop = false;
                        tb_P2PM_Start->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        is_stop = true;
                        tb_P2PM_Start->Caption = EM_ALS_READER_START;
                }
        }
        break;

        case META_FAILED:
        case META_TIMEOUT:
        case META_CANCEL:
        case METAAPP_STOP:
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
        break;
    }
}

void __fastcall TfrmNFCNew::tb_AIRM_StartClick(TObject *Sender)
{
        LOG("AIRM Start\n");
        
        nfc_rsp.hPostMsgDestHandle = this->Handle;
        composeReaderReq();
        LOG("m_AIRM_reader_req.action=%d\n", m_AIRM_reader_req.action); 
        LOG("m_AIRM_reader_req.supporttype=%d\n", m_AIRM_reader_req.supporttype);
        LOG("m_AIRM_reader_req.typeA_datarate=%d\n", m_AIRM_reader_req.typeA_datarate);
        LOG("m_AIRM_reader_req.typeB_datarate=%d\n", m_AIRM_reader_req.typeB_datarate);
        LOG("m_AIRM_reader_req.typeF_datarate=%d\n", m_AIRM_reader_req.typeF_datarate);

        m_NfcReaderObj.ConfirmCallback  = ::ConfirmCallback_Reader;
        m_NfcReaderObj.REQ_ALS_READER_MODE_Start(nfc_rsp, &m_AIRM_reader_req);
/*
        if(true == result)
        {
        LOG("true == result\n");
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_AIRM_Start->Caption, EM_ALS_READER_START))
                {
                       tb_AIRM_Start->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                       tb_AIRM_Start->Caption = EM_ALS_READER_START;
                }
        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }   */
}

//---------------------------------------------------------------------------
void TfrmNFCNew::composeReaderReq(void)
{
        LOG("%s\n", tb_AIRM_Start->Caption);
        memset(&m_AIRM_reader_req,0,sizeof(m_AIRM_reader_req));

        if(!CompareStr(tb_AIRM_Start->Caption, EM_ALS_READER_START))
        {
                m_AIRM_reader_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_AIRM_Start->Caption, EM_ALS_READER_STOP))
        {
                m_AIRM_reader_req.action = NFC_EM_ACT_STOP;
        }

        if(true == cb_AIRM_TypeA->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_A;
                if(true == rb_AIRM_TypeA_106kbps->Checked)
                {
                        m_AIRM_reader_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_106;
                }
                else if(true == rb_AIRM_TypeA_212kbps->Checked)
                {
                        m_AIRM_reader_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_AIRM_TypeA_424kbps->Checked)
                {
                        m_AIRM_reader_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
                else if(true == rb_AIRM_TypeA_848kbps->Checked)
                {
                        m_AIRM_reader_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_848;
                }
        }

        if(true == cb_AIRM_TypeB->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_B;
                if(true == rb_AIRM_TypeB_106kbps->Checked)
                {
                        m_AIRM_reader_req.typeB_datarate = EM_ALS_READER_M_SPDRATE_106;
                }
                else if(true == rb_AIRM_TypeB_212kbps->Checked)
                {
                        m_AIRM_reader_req.typeB_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_AIRM_TypeB_424kbps->Checked)
                {
                        m_AIRM_reader_req.typeB_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
                else if(true == rb_AIRM_TypeB_848kbps->Checked)
                {
                        m_AIRM_reader_req.typeB_datarate = EM_ALS_READER_M_SPDRATE_848;
                }
        }

        if(true == cb_AIRM_TypeF->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_F;
                if(true == rb_AIRM_TypeF_212kbps->Checked)
                {
                        m_AIRM_reader_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_AIRM_TypeF_424kbps->Checked)
                {
                        m_AIRM_reader_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
        }

        if(true == cb_AIRM_TypeV->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_V;
                if(true == rb_AIRM_TypeV_Subcarrier->Checked)
                {
                        m_AIRM_reader_req.typeV_subcarrier = 0;
                }
                else if(true == rb_AIRM_TypeV_DualSubcarrie->Checked)
                {
                        m_AIRM_reader_req.typeV_subcarrier = 1;
                }

                if(true == rb_AIRM_TypeV_CodingMode_4->Checked)
                {
//                        m_AIRM_reader_req.typeV_codingmode = 0;
                }
                else if(true == rb_AIRM_TypeV_CodingMode_256->Checked)
                {
//                        m_AIRM_reader_req.typeV_codingmode = 1;
                }
                
                if(true == rb_AIRM_TypeV_6_62kbps->Checked)
                {
                        m_AIRM_reader_req.typeV_datarate = EM_ALS_READER_M_SPDRATE_662;
                }

                if(true == rb_AIRM_TypeV_26_48kbps->Checked)
                {
                        m_AIRM_reader_req.typeV_datarate = EM_ALS_READER_M_SPDRATE_2648;
                }
        }


        if(true == cb_AIRM_TypeB_plus->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_BPrime;
        }

        if(true == cb_AIRM_Kovio->Checked)
        {
                m_AIRM_reader_req.supporttype += EM_ALS_READER_M_TYPE_KOVIO;
        }
}

void TfrmNFCNew::composeP2PReq(void)
{
        memset(&m_P2PM_req, 0, sizeof(m_P2PM_req));
        if(!CompareStr(tb_P2PM_Start->Caption, EM_ALS_READER_START))
        {
                m_P2PM_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_P2PM_Start->Caption, EM_ALS_READER_STOP))
        {
                m_P2PM_req.action = NFC_EM_ACT_STOP;
        }
        if(true == cb_P2PM_TypeA->Checked)
        {
                m_P2PM_req.supporttype += EM_ALS_READER_M_TYPE_A;
                if(true == rb_P2PM_TypeA_106kbps->Checked)
                {
                        m_P2PM_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_106;
                }
                else if(true == rb_P2PM_TypeA_212kbps->Checked)
                {
                        m_P2PM_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_P2PM_TypeA_424kbps->Checked)
                {
                        m_P2PM_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
                else if(true == rb_P2PM_TypeA_848kbps->Checked)
                {
                        m_P2PM_req.typeA_datarate = EM_ALS_READER_M_SPDRATE_848;
                }
        }

        if(true == cb_P2PM_TypeF->Checked)
        {
                m_P2PM_req.supporttype += EM_ALS_READER_M_TYPE_F;
                if(true == rb_P2PM_TypeF_212kbps->Checked)
                {
                        m_P2PM_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_P2PM_TypeF_424kbps->Checked)
                {
                        m_P2PM_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
        }

        if(true == cb_P2PM_PassiveMode->Checked)
        {
                m_P2PM_req.mode += EM_P2P_MODE_PASSIVE_MODE;
        }

        if(true == cb_P2PM_ActiveMode->Checked)
        {
                m_P2PM_req.mode += EM_P2P_MODE_ACTIVE_MODE;
        }

        if(true == cb_P2PM_Initator->Checked)
        {
                m_P2PM_req.role += EM_P2P_ROLE_INITIATOR_MODE;
        }

        if(true == cb_P2PM_Target->Checked)
        {
                m_P2PM_req.role += EM_P2P_ROLE_TARGET_MODE;
        }

        if(true == cb_P2PM_DisableCardEmulation->Checked)
        {
                m_P2PM_req.isDisableCardM = 1;
        }
        else
        {
                m_P2PM_req.isDisableCardM = 0;
        }
}
void __fastcall TfrmNFCNew::tb_P2PM_StartClick(TObject *Sender)
{
        composeP2PReq();
        NFC_P2P_RSP_S nfc_rsp;
        nfc_rsp.hPostMsgDestHandle = this->Handle;
        LOG("m_P2PM_req.action=%d\n", m_P2PM_req.action);
        m_NfcP2PObj.ConfirmCallback  = ::ConfirmCallback_P2P;
        m_NfcP2PObj.REQ_ALS_P2P_MODE_Start(nfc_rsp, &m_P2PM_req);
        /*
        if(true == result)
        {                       
                LOG("P2P Start:true == result");

                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_P2PM_Start->Caption, EM_ALS_READER_START))
                {                                                     
                       tb_P2PM_Start->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        
                       tb_P2PM_Start->Caption = EM_ALS_READER_START;
                }
        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
        */
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_AICEM_StartClick(TObject *Sender)
{
        memset(&m_CardMode_req, 0, sizeof(m_CardMode_req));
        compositeAICEMReq();
         bool result = m_NfcCardMObj.REQ_ALS_CARD_MODE_Start(&m_CardMode_req);

        if(true == result)
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_AICEM_Start->Caption, EM_ALS_READER_START))
                {
                        is_stop = false;
                       tb_AICEM_Start->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        is_stop = true;
                       tb_AICEM_Start->Caption = EM_ALS_READER_START;
                }
        }
        else
        {
               Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}

void TfrmNFCNew::compositeAICEMReq(void)
{
        memset(&m_CardMode_req, 0, sizeof(m_CardMode_req));
        if(!CompareStr(tb_AICEM_Start->Caption, EM_ALS_READER_START))
        {
                m_CardMode_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_AICEM_Start->Caption, EM_ALS_READER_STOP))
        {
                m_CardMode_req.action = NFC_EM_ACT_STOP;
        }

        if(true == rb_AICEM_SWIO1->Checked)
        {
                m_CardMode_req.SWNum = EM_ALS_CARD_M_SW_NUM_SWIO1;
        }
        else if(true == rb_AICEM_SWIO2->Checked)
        {
                m_CardMode_req.SWNum = EM_ALS_CARD_M_SW_NUM_SWIO2;
        }
        else if(true == rb_AICEM_SWIOSE->Checked)
        {
                m_CardMode_req.SWNum = EM_ALS_CARD_M_SW_NUM_SWIOSE;
        }
        if(true == cb_AICEM_TypeA->Checked)
        {
                m_CardMode_req.supporttype += EM_ALS_READER_M_TYPE_A;
        }
        if(true == cb_AICEM_TypeB->Checked)
        {
                m_CardMode_req.supporttype += EM_ALS_READER_M_TYPE_B;
        }
        if(true == cb_AICEM_TypeB_plus->Checked)
        {
                m_CardMode_req.supporttype += EM_ALS_READER_M_TYPE_BPrime;
        }
        if(true == cb_AICEM_TypeF->Checked)
        {
                m_CardMode_req.supporttype += EM_ALS_READER_M_TYPE_F;
        }

        m_CardMode_req.fgvirtualcard = 0;
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_TXCSAO_StartClick(TObject *Sender)
{
        LOG("TX action %s.\n", tb_TXCSAO_Start->Caption);
        if(!CompareStr(tb_TXCSAO_Start->Caption, EM_ALS_READER_START))
        {
                m_tx_carr_als_on_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_TXCSAO_Start->Caption, EM_ALS_READER_STOP))
        {
                m_tx_carr_als_on_req.action = NFC_EM_ACT_STOP;
        }
        bool result = m_NfcTxCarrAlsOnObj.REQ_ALS_TX_CARRIER_Start(&m_tx_carr_als_on_req);

        if(true == result)
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_TXCSAO_Start->Caption, EM_ALS_READER_START))
                {
                        is_stop = false;
                       tb_TXCSAO_Start->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        is_stop = true;
                       tb_TXCSAO_Start->Caption = EM_ALS_READER_START;
                }
        }
        else
        {
        
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_VCF_StartClick(TObject *Sender)
{
        NFC_EM_VIRTUAL_CARD_CNF_S nfc_virtual_card_cnf;
        memset(&nfc_virtual_card_cnf, 0, sizeof(nfc_virtual_card_cnf));
        compositeVirtualCardReq();
        bool result = m_NfcVirtualCardFuncObj.REQ_VIRTUAL_CARD_FUNC_Start(&m_Virtual_Card_req, &nfc_virtual_card_cnf);

        if(true == result)
        {
                LOG("nfc_virtual_card_cnf.result=%d\n", nfc_virtual_card_cnf.result);
                if(nfc_virtual_card_cnf.result == 0)
                {
                        Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                        if(!CompareStr(tb_VCF_Start->Caption, EM_ALS_READER_START))
                        {
                                is_stop = false;
                                tb_VCF_Start->Caption = EM_ALS_READER_STOP;
                        }
                        else
                        {
                                is_stop = true;
                                tb_VCF_Start->Caption = EM_ALS_READER_START;
                        }
                }
                else
                {
                        Application->MessageBoxA("Please remove SIM/uSD!", "INFO", MB_OK);
                }
        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}

void TfrmNFCNew::compositeVirtualCardReq()
{
        memset(&m_Virtual_Card_req, 0, sizeof(m_Virtual_Card_req));
        if(!CompareStr(tb_VCF_Start->Caption, EM_ALS_READER_START))
        {
                m_Virtual_Card_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_VCF_Start->Caption, EM_ALS_READER_STOP))
        {
                m_Virtual_Card_req.action = NFC_EM_ACT_STOP;
        }

        if(true == cb_VCF_TypeA->Checked)
        {
                m_Virtual_Card_req.supporttype += EM_ALS_READER_M_TYPE_A;
        }
        if(true == cb_VCF_TypeB->Checked)
        {
                m_Virtual_Card_req.supporttype += EM_ALS_READER_M_TYPE_B;
        }
        if(true == cb_VCF_TypeF->Checked)
        {
                m_Virtual_Card_req.supporttype += EM_ALS_READER_M_TYPE_F;
                if(true == rb_VCF_TypeF_212kbps->Checked)
                {
                        m_Virtual_Card_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_212;
                }
                else if(true == rb_VCF_TypeF_424kbps->Checked)
                {
                        m_Virtual_Card_req.typeF_datarate = EM_ALS_READER_M_SPDRATE_424;
                }
        }
        if(true == cb_VCF_TypeB_plus->Checked)
        {
                m_Virtual_Card_req.supporttype += EM_ALS_READER_M_TYPE_BPrime;
        }

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_PNFC_StartClick(TObject *Sender)
{
        NFC_EM_PNFC_CNF_S pnfc_command_Cnf;
        memset(&pnfc_command_Cnf, 0, sizeof(pnfc_command_Cnf));
        memset(&m_pnfc_command_req, 0, sizeof(m_pnfc_command_req));
        m_pnfc_command_req.pnfc_req.action = NFC_EM_ACT_START;
        if(te_PNFC_Command->Text != "")
        {
                sprintf(m_pnfc_command_req.pnfc_req.data, "%s%s%s", "$PNFC", te_PNFC_Command->Text.c_str(), "*");
                //memcpy(m_pnfc_command_req.pnfc_req.data, te_PNFC_Command->Text.c_str(), 256);
        }
        m_pnfc_command_req.pnfc_req.datalen = strlen(m_pnfc_command_req.pnfc_req.data);
        tre_PNFC_ReceivingMessage->Lines->Add(te_PNFC_Command->Text.c_str());
        bool result = m_NfcPNFCCommandObj.REQ_PNFC_Command_Start(&m_pnfc_command_req, &pnfc_command_Cnf);
        if(true == result)
        {
                char strInfo[256] = {0};
                sprintf(strInfo, "%s%d", "result=", pnfc_command_Cnf.result);
                tre_PNFC_ReceivingMessage->Lines->Add(strInfo);
                memset(strInfo, 0, sizeof(strInfo));
                sprintf(strInfo, "%s%d", "DataLen=", pnfc_command_Cnf.datalen);
                tre_PNFC_ReceivingMessage->Lines->Add(strInfo);
                memset(strInfo, 0, sizeof(strInfo));
                memcpy(strInfo, "Data=", sizeof("Data="));
                for(unsigned int i = 0; i < pnfc_command_Cnf.datalen; i++)
                {
                        strInfo[i + strlen("Data=")] = pnfc_command_Cnf.data[i];
                }
                //strcat(strInfo, pnfc_command_Cnf.data);
                tre_PNFC_ReceivingMessage->Lines->Add(strInfo);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_VQ_QueryClick(TObject *Sender)
{
        NFC_SW_VERSION_CNF_S version_query_cnf;
        memset(&version_query_cnf, 0, sizeof(version_query_cnf));
        bool result = m_NfcVersionQueryObj.REQ_Version_Query_Start(&version_query_cnf);
        if(true == result)
        {
                te_VQ_NFC_MW_Version->Text = version_query_cnf.mw_ver;
                LOG("%d\n",version_query_cnf.fw_ver);       
                LOG("%d\n",version_query_cnf.hw_ver);
                te_VQ_NFC_FW_Version->Text = "0x" + IntToHex(version_query_cnf.fw_ver, 1);
                te_VQ_NFC_HW_Version->Text = "0x" + IntToHex(version_query_cnf.hw_ver, 1);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_Option_SetClick(TObject *Sender)
{
        if(true == cb_Option_EnableForceDownload->Checked)
        {
                m_option_setting_req.forceDownLoad = 1;
        }
        else
        {
                m_option_setting_req.forceDownLoad = 0;
        }
        if(true == cb_Option_EnableAutoCheckPresence->Checked)
        {
                m_option_setting_req.TagAutoPresenceChk = 1;
        }
        else
        {
                m_option_setting_req.TagAutoPresenceChk = 0;
        }

        bool result = m_NfcOptionSettingObj.REQ_Option_Setting_Start(&m_option_setting_req);
        if(META_SUCCESS == result)
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_Loopback_Start_StopClick(TObject *Sender)
{
        if(!CompareStr(tb_Loopback_Start_Stop->Caption, EM_ALS_READER_START))
        {
                m_loopback_test_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_Loopback_Start_Stop->Caption, EM_ALS_READER_STOP))
        {
                m_loopback_test_req.action = NFC_EM_ACT_STOP;
        }

        bool result = m_NfcLoopbackTestObj.REQ_Loopback_Test_Start(&m_loopback_test_req);
        if(true == result)
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                if(!CompareStr(tb_Loopback_Start_Stop->Caption, EM_ALS_READER_START))
                {
                        is_stop = false;
                        tl_Loopback_test->Visible = true;
                        tb_Loopback_Start_Stop->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        is_stop = true;
                        tl_Loopback_test->Visible = false;
                        tb_Loopback_Start_Stop->Caption = EM_ALS_READER_START;
                }
        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}
//---------------------------------------------------------------------------
void TfrmNFCNew::composeSWPTestUI(void)
{
        memset(&m_swp_test_req, 0, sizeof(m_swp_test_req));
        if(cb_SWPT_SWIO1->Checked == true)
        {
                m_swp_test_req.SEmap += 1;
        }
        if(cb_SWPT_SWIO2->Checked == true)
        {
                m_swp_test_req.SEmap += 2;
        }
        if(cb_SWPT_SWIOSE->Checked == true)
        {
                m_swp_test_req.SEmap += 4;
        }
}

void __fastcall TfrmNFCNew::tb_SWPTest_Start_StopClick(TObject *Sender)
{              
        composeSWPTestUI();
        if(!CompareStr(tb_SWPTest_Start_Stop->Caption, EM_ALS_READER_START))
        {
                m_swp_test_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_SWPTest_Start_Stop->Caption, EM_ALS_READER_STOP))
        {
                m_swp_test_req.action = NFC_EM_ACT_STOP;
        }
        bool result = m_NfcSWPTestObj.REQ_SWP_Test_Start(&m_swp_test_req);
        if(true == result)
        {
                Application->MessageBoxA("Successfully!", "SUCCESS", MB_OK);
                LOG("SWP Test result == true\n");

                if(!CompareStr(tb_SWPTest_Start_Stop->Caption, EM_ALS_READER_START))
                {
                        is_stop = false;
                        tb_SWPTest_Start_Stop->Caption = EM_ALS_READER_STOP;
                }
                else
                {
                        is_stop = true;
                        tb_SWPTest_Start_Stop->Caption = EM_ALS_READER_START;
                }

        }
        else
        {
                Application->MessageBoxA("Failed!", "FAIL", MB_OK);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_AICEM_SetSWIOClick(TObject *Sender)
{
        NFC_EM_SE_GET_LIST se_list;
        memset(&se_list, 0, sizeof(se_list));
        bool result = m_NfcCardMObj.REQ_ALS_CARD_MODE_SET_SE(&se_list);
        if(true == result)
        {
                LOG("se_list.seCount=%d\n", se_list.SeCount);
                for(int i = 0; i < se_list.SeCount; i++)
                {
                        switch(se_list.SeInfor[i].seid)
                        {
                                case 1:
                                      rb_AICEM_SWIO1->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIO1->Checked = true;
                                      }
                                break;

                                case 2:
                                      rb_AICEM_SWIO2->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIO2->Checked = true;
                                      }
                                break;

                                case 3:
                                      rb_AICEM_SWIOSE->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIOSE->Checked = true;
                                      }
                                break;

                                default:
                                break;
                        }
                }
                if(se_list.SeCount > 0)
                {
                        tb_AICEM_Start->Enabled = true;
                }
                else
                {
                        Application->MessageBoxA("NO SIM, please check!", "Info", MB_OK);
                }

        }
        else
        {
                tb_AICEM_Start->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_PLM_StartClick(TObject *Sender)
{
        m_nfc_polling_rsp.hPostMsgDestHandle = this->Handle;
        memset(&m_polling_loop_req, 0, sizeof(m_polling_loop_req));
        composePollingLoopReq();

        m_NfcPOLLINGObj.ConfirmCallback  = ::ConfirmCallback_Polling;
        m_NfcPOLLINGObj.REQ_ALS_POLLING_MODE_Start(m_nfc_polling_rsp, &m_polling_loop_req);
}

void TfrmNFCNew::composePollingLoopReq()
{
        memset(&m_polling_loop_req, 0, sizeof(m_polling_loop_req));
        if(!CompareStr(tb_PLM_Start->Caption, EM_ALS_READER_START))
        {
                m_polling_loop_req.action = NFC_EM_ACT_START;
        }
        else if(!CompareStr(tb_PLM_Start->Caption, EM_ALS_READER_STOP))
        {
                m_polling_loop_req.action = NFC_EM_ACT_STOP;
        }
        if(true == rb_PLM_Listen->Checked)
        {
                m_polling_loop_req.phase = 0;
        }
        else
        {
                m_polling_loop_req.phase = 1;
        }

        m_polling_loop_req.Period = StrToInt(te_PLM_Period->Text);
        if(true == cb_PLM_RM->Checked)
        {
                m_polling_loop_req.enablefunc += EM_ENABLE_FUNC_READER_MODE;

                if(true == cb_PLM_RM_TypeA->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_A;
                        if(true == cb_PLM_RM_TypeA_106kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeA_datarate = EM_ALS_READER_M_SPDRATE_106;
                        }
                        else if(true == cb_PLM_RM_TypeA_212kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeA_datarate = EM_ALS_READER_M_SPDRATE_212;
                        }
                        else if(true == cb_PLM_RM_TypeA_424kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeA_datarate = EM_ALS_READER_M_SPDRATE_424;
                        }
                        else if(true == cb_PLM_RM_TypeA_848kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeA_datarate = EM_ALS_READER_M_SPDRATE_848;
                        }
                }

                if(true == cb_PLM_RM_TypeB->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_B;
                        if(true == cb_PLM_RM_TypeB_106kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeB_datarate = EM_ALS_READER_M_SPDRATE_106;
                        }
                        else if(true == cb_PLM_RM_TypeB_212kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeB_datarate = EM_ALS_READER_M_SPDRATE_212;
                        }
                        else if(true == cb_PLM_RM_TypeB_424kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeB_datarate = EM_ALS_READER_M_SPDRATE_424;
                        }
                        else if(true == cb_PLM_RM_TypeB_848kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeB_datarate = EM_ALS_READER_M_SPDRATE_848;
                        }
                }

                if(true == cb_PLM_RM_TypeF->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_F;
                        if(true == cb_PLM_RM_TypeF_212kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeF_datarate = EM_ALS_READER_M_SPDRATE_212;
                        }
                        else if(true == cb_PLM_RM_TypeF_424kbps->Checked)
                        {
                                m_polling_loop_req.readerM.typeF_datarate = EM_ALS_READER_M_SPDRATE_424;
                        }
                }

                if(true == cb_PLM_RM_TypeV->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_V;
                        if(true == cb_PLM_RM_TypeV_Subcarrier->Checked)
                        {
                                m_polling_loop_req.readerM.typeV_subcarrier = 0;
                        }
                        else if(true == cb_PLM_RM_TypeV_DualSubcarrier->Checked)
                        {
                                m_polling_loop_req.readerM.typeV_subcarrier = 1;
                        }

                        if(true == cb_PLM_RM_TypeV_CodingMode_4->Checked)
                        {
//                                m_polling_loop_req.readerM.typeV_codingmode = 0;
                        }
                        else if(true == cb_PLM_RM_TypeV_CodingMode_256->Checked)
                        {
//                                m_polling_loop_req.readerM.typeV_codingmode = 1;
                        }

                        if(true == cb_PLM_RM_6_62kbps->Checked)
                        {
                            m_polling_loop_req.readerM.typeV_datarate = EM_ALS_READER_M_SPDRATE_662;
                        }

                        if(true == cb_PLM_RM_26_48kbps->Checked)
                        {
                            m_polling_loop_req.readerM.typeV_datarate = EM_ALS_READER_M_SPDRATE_2648;
                        }
                }

                if(true == cb_PLM_RM_TypeB_plus->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_BPrime;
                }

                if(true == cb_PLM_RM_Kovio->Checked)
                {
                        m_polling_loop_req.readerM.supporttype += EM_ALS_READER_M_TYPE_KOVIO;
                }
        }
        if(true == cb_PLM_P2PM->Checked)
        {
                m_polling_loop_req.enablefunc += EM_ENABLE_FUNC_P2P_MODE;

                if(true == cb_PLM_P2PM_TypeA->Checked)
                {
                        m_polling_loop_req.p2pM.supporttype += EM_ALS_READER_M_TYPE_A;
                        if(true == rb_PLM_P2PM_TypeA_106kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeA_datarate = EM_ALS_READER_M_SPDRATE_106;
                        }
                        else if(true == rb_PLM_P2PM_TypeA_212kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeA_datarate = EM_ALS_READER_M_SPDRATE_212;
                        }
                        else if(true == rb_PLM_P2PM_TypeA_424kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeA_datarate = EM_ALS_READER_M_SPDRATE_424;
                        }
                        else if(true == rb_PLM_P2PM_TypeA_848kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeA_datarate = EM_ALS_READER_M_SPDRATE_848;
                        }
                }

                if(true == cb_PLM_P2PM_TypeF->Checked)
                {
                        m_polling_loop_req.p2pM.supporttype += EM_ALS_READER_M_TYPE_F;
                        if(true == rb_PLM_P2PM_TypeF_212kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeF_datarate = EM_ALS_READER_M_SPDRATE_212;
                        }
                        else if(true == rb_PLM_P2PM_TypeF_424kbps->Checked)
                        {
                                m_polling_loop_req.p2pM.typeF_datarate = EM_ALS_READER_M_SPDRATE_424;
                        }
                }

                if(true == cb_PLM_P2PM_PassiveMode->Checked)
                {
                        m_polling_loop_req.p2pM.mode += EM_P2P_MODE_PASSIVE_MODE;
                }

                if(true == cb_PLM_P2PM_ActiveMode->Checked)
                {
                        m_polling_loop_req.p2pM.mode += EM_P2P_MODE_ACTIVE_MODE;
                }

                if(true == cb_PLM_P2PM_Initiator->Checked)
                {
                        m_polling_loop_req.p2pM.role += EM_P2P_ROLE_INITIATOR_MODE;
                }

                if(true == cb_PLM_P2PM_Target->Checked)
                {
                        m_polling_loop_req.p2pM.role += EM_P2P_ROLE_TARGET_MODE;
                }

                if(true == cb_PLM_P2PM_DisableCardEmulation->Checked)
                {
                        m_polling_loop_req.p2pM.isDisableCardM = 1;
                }
                else
                {
                        m_polling_loop_req.p2pM.isDisableCardM = 0;
                }
        }
        if(true == cb_PLM_CEM->Checked)
        {
                m_polling_loop_req.enablefunc += EM_ENABLE_FUNC_CARD_MODE;
                if(true == rb_PLM_CEM_SWIO1->Checked)
                {
                        m_polling_loop_req.cardM.SWNum = EM_ALS_CARD_M_SW_NUM_SWIO1;
                }
                else if(true == rb_PLM_CEM_SWIO2->Checked)
                {
                        m_polling_loop_req.cardM.SWNum = EM_ALS_CARD_M_SW_NUM_SWIO2;
                }
                else if(true == rb_PLM_CEM_SWIOSE->Checked)
                {
                        m_polling_loop_req.cardM.SWNum = EM_ALS_CARD_M_SW_NUM_SWIOSE;
                }
                if(true == cb_PLM_CEM_TypeA->Checked)
                {
                        m_polling_loop_req.cardM.supporttype += EM_ALS_READER_M_TYPE_A;
                }
                if(true == cb_PLM_CEM_TypeB->Checked)
                {
                        m_polling_loop_req.cardM.supporttype += EM_ALS_READER_M_TYPE_B;
                }
                if(true == cb_PLM_CEM_TypeB_plus->Checked)
                {
                        m_polling_loop_req.cardM.supporttype += EM_ALS_READER_M_TYPE_BPrime;
                }
                if(true == cb_PLM_CEM_TypeF->Checked)
                {
                        m_polling_loop_req.cardM.supporttype += EM_ALS_READER_M_TYPE_F;
                }

                m_polling_loop_req.cardM.fgvirtualcard = 0;
        }

}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::rb_PLM_CEM_SetSEClick(TObject *Sender)
{
        NFC_EM_SE_GET_LIST se_list;
        memset(&se_list, 0, sizeof(se_list));
        bool result = m_NfcCardMObj.REQ_ALS_CARD_MODE_SET_SE(&se_list);
        if(true == result)
        {
                for(int i = 0; i < se_list.SeCount; i++)
                {
                        switch(se_list.SeInfor[i].seid)
                        {
                                case 1:
                                      rb_PLM_CEM_SWIO1->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_PLM_CEM_SWIO1->Checked = true;
                                      }
                                break;

                                case 2:
                                      rb_PLM_CEM_SWIO2->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_PLM_CEM_SWIO2->Checked = true;
                                      }
                                break;

                                case 3:
                                      rb_PLM_CEM_SWIOSE->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_PLM_CEM_SWIOSE->Checked = true;
                                      }
                                break;

                                default:
                                break;
                        }
                }
                if(se_list.SeCount > 0)
                {
                        tb_PLM_Start->Enabled = true;
                }

        }
        else
        {
                tb_PLM_Start->Enabled = false;
        }
}
//---------------------------------------------------------------------------


void  TfrmNFCNew::resetAIRMUI()
{
        cb_AIRM_TypeA->Checked = true;
        rb_AIRM_TypeA_106kbps->Checked = true;
        cb_AIRM_TypeB->Checked = true;
        rb_AIRM_TypeB_106kbps->Checked = true;
        cb_AIRM_TypeF->Checked = true;
        rb_AIRM_TypeF_212kbps->Checked = true;
        cb_AIRM_TypeV->Checked = true;
        rb_AIRM_TypeV_Subcarrier->Checked = true;
        rb_AIRM_TypeV_CodingMode_4->Checked = true;
        rb_AIRM_TypeV_6_62kbps->Checked = true;
        //cb_AIRM_TypeB_plus->Checked = true;
        cb_AIRM_Kovio->Checked = true;
}

void  TfrmNFCNew::resetP2PMUI()
{
       cb_P2PM_TypeA->Checked = true;
       rb_P2PM_TypeA_106kbps->Checked = true;
       cb_P2PM_TypeF->Checked = true;
       rb_P2PM_TypeF_212kbps->Checked = true;
       cb_P2PM_PassiveMode->Checked = true;
       cb_P2PM_ActiveMode->Checked = true;
       cb_P2PM_Initator->Checked = true;
       cb_P2PM_Target->Checked = true;
       cb_P2PM_DisableCardEmulation->Checked = true;
}

void  TfrmNFCNew::resetAICEMUI()
{
       rb_AICEM_SWIO1->Visible = false;
       rb_AICEM_SWIO2->Visible = false;
       rb_AICEM_SWIOSE->Visible = false;
       cb_AICEM_TypeA->Checked = true;
       cb_AICEM_TypeB->Checked = true;
       cb_AICEM_TypeB_plus->Checked = true;
       cb_AICEM_TypeF->Checked = true;
}

void  TfrmNFCNew::resetPLMUI()
{
      rb_PLM_Listen->Checked = true;
      te_PLM_Period->Text = "500";
      cb_PLM_RM->Checked = true;
      cb_PLM_RM_TypeA->Checked = true;
      cb_PLM_RM_TypeA_106kbps->Checked = true;
      cb_PLM_RM_TypeB->Checked = true;
      cb_PLM_RM_TypeB_106kbps->Checked = true;
      cb_PLM_RM_TypeF->Checked = true;
      cb_PLM_RM_TypeF_212kbps->Checked = true;
      cb_PLM_RM_TypeV->Checked = true;
      cb_PLM_RM_TypeV_Subcarrier->Checked = true;
      cb_PLM_RM_TypeV_CodingMode_4->Checked = true;
      cb_PLM_RM_6_62kbps->Checked = true;
      //cb_PLM_RM_TypeB_plus->Checked = true;
      cb_PLM_RM_Kovio->Checked = true;
      cb_PLM_P2PM_TypeA->Checked = true;
      rb_PLM_P2PM_TypeA_106kbps->Checked = true;
      cb_PLM_P2PM_TypeF->Checked = true;
      rb_PLM_P2PM_TypeF_212kbps->Checked = true;
      cb_PLM_P2PM_PassiveMode->Checked = true;
      cb_PLM_P2PM_ActiveMode->Checked = true;
      cb_PLM_P2PM_Initiator->Checked = true;
      cb_PLM_P2PM_Target->Checked = true;
      cb_PLM_P2PM_DisableCardEmulation->Checked = true;
      rb_PLM_CEM_SWIO1->Visible = false;
      rb_PLM_CEM_SWIO2->Visible = false;
      rb_PLM_CEM_SWIOSE->Visible = false;
      cb_PLM_CEM_TypeA->Checked = true;  
      cb_PLM_CEM_TypeB->Checked = true;
      cb_PLM_CEM_TypeB_plus->Checked = true;
      cb_PLM_CEM_TypeF->Checked = true;
}

void  TfrmNFCNew::resetVCFUI()
{
        cb_VCF_TypeA->Checked = true;
        cb_VCF_TypeB->Checked = true;
        cb_VCF_TypeF->Checked = true;
        rb_VCF_TypeF_212kbps->Checked = true;
        cb_VCF_TypeB_plus->Checked = true;
}

void  TfrmNFCNew::resetPNFCUI()
{
        te_PNFC_Command->Text = "";
        tre_PNFC_ReceivingMessage->Text = "";
}

void  TfrmNFCNew::resetVQUI()
{
        te_VQ_NFC_MW_Version->Text = "";
        te_VQ_NFC_FW_Version->Text = "";
        te_VQ_NFC_HW_Version->Text = "";
}

void  TfrmNFCNew::resetOptionUI()
{
        cb_Option_EnableForceDownload->Checked = false;
        cb_Option_EnableAutoCheckPresence->Checked = true;
}

void __fastcall TfrmNFCNew::tabNFCChange(TObject *Sender)
{
        if(!CompareStr(tb_AIRM_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = tsRM;
        }
        else if(!CompareStr(tb_P2PM_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = tsP2P;
        }
        else if(!CompareStr(tb_AICEM_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = tsCEM;
        }
        else if(!CompareStr(tb_PLM_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = TSPLM;
        }
        else if(!CompareStr(tb_AICEM_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = TSTXCSAO;
        }
        else if(!CompareStr(tb_VCF_Start->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = TSVCF;
        }
        else if(!CompareStr(tb_Loopback_Start_Stop->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = TSLoopback;
        }
        else if(!CompareStr(tb_SWPTest_Start_Stop->Caption, EM_ALS_READER_STOP))
        {
                tabNFC->ActivePage = SWT;
        }
        resetAIRMUI();
        resetP2PMUI();
        resetAICEMUI();
        resetPLMUI();
        resetVCFUI();
        resetPNFCUI();
        resetVQUI();
        resetOptionUI();
}
//---------------------------------------------------------------------------


void __fastcall TfrmNFCNew::tb_PNFC_CleanClick(TObject *Sender)
{
        tre_PNFC_ReceivingMessage->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::Button1Click(TObject *Sender)
{
     form_AIRM_Reader->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::tb_SWPT_SetSEClick(TObject *Sender)
{
        NFC_EM_SE_GET_LIST se_list;
        memset(&se_list, 0, sizeof(se_list));
        bool result = m_NfcCardMObj.REQ_ALS_CARD_MODE_SET_SE(&se_list);
        if(true == result)
        {
                for(int i = 0; i < se_list.SeCount; i++)
                {
                        switch(se_list.SeInfor[i].seid)
                        {
                                case 1:
                                      rb_AICEM_SWIO1->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIO1->Checked = true;
                                      }
                                break;

                                case 2:
                                      rb_AICEM_SWIO2->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIO2->Checked = true;
                                      }
                                break;

                                case 3:
                                      rb_AICEM_SWIOSE->Visible = true;
                                      if(se_list.SeCount == 1)
                                      {
                                        rb_AICEM_SWIOSE->Checked = true;
                                      }
                                break;

                                default:
                                break;
                        }
                }
                if(se_list.SeCount > 0)
                {
                        tb_SWPTest_Start_Stop->Enabled = true;
                }
                else
                {
                        Application->MessageBoxA("NO SIM, please check!", "Info", MB_OK);
                }

        }
        else
        {
                tb_AICEM_Start->Enabled = false;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_SWPT_SWIO1Click(TObject *Sender)
{
        if(cb_SWPT_SWIO1->Checked == true)
        {
                m_swp_test_req.SEmap += 1;
                if(tb_SWPTest_Start_Stop->Enabled == false)
                {
                        tb_SWPTest_Start_Stop->Enabled = true;
                }
        }
        else
        {
                m_swp_test_req.SEmap -= 1;
                if(m_swp_test_req.SEmap == 0)
                {
                        tb_SWPTest_Start_Stop->Enabled = false;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_SWPT_SWIO2Click(TObject *Sender)
{
        if(cb_SWPT_SWIO2->Checked == true)
        {
                m_swp_test_req.SEmap += 2;
                if(tb_SWPTest_Start_Stop->Enabled == false)
                {
                        tb_SWPTest_Start_Stop->Enabled = true;
                }
        }
        else
        {
                m_swp_test_req.SEmap -= 2;
                if(m_swp_test_req.SEmap == 0)
                {
                        tb_SWPTest_Start_Stop->Enabled = false;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmNFCNew::cb_SWPT_SWIOSEClick(TObject *Sender)
{
        if(cb_SWPT_SWIOSE->Checked == true)
        {
                m_swp_test_req.SEmap += 4;
                if(tb_SWPTest_Start_Stop->Enabled == false)
                {
                        tb_SWPTest_Start_Stop->Enabled = true;
                }
        }
        else
        {
                m_swp_test_req.SEmap -= 4;
                if(m_swp_test_req.SEmap == 0)
                {
                        tb_SWPTest_Start_Stop->Enabled = false;
                }
        }
}
//---------------------------------------------------------------------------


