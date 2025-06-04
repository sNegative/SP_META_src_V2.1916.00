//---------------------------------------------------------------------------

#ifndef form_SpecialTestH
#define form_SpecialTestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include <string>

#ifndef  _SPECIALTEST_MAN_H_
#include "specialtest_man.h"
#endif

#define RAW_DATA_LEN 4096
//---------------------------------------------------------------------------
class TfrmSpecialTest : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TButton *btnSpecialTest;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *edtTestTime;
    TComboBox *cbxDataSize;
    TLabel *Label3;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TGroupBox *GroupBox2;
    TButton *btnChecksumError;
    TButton *btnRightDataTest;
    TButton *btnEscapeDataTest;
    TLabel *Label4;
    TRichEdit *edtRawData;
    TButton *btnChecksumEscapingTest;
    TButton *btnRawDataTest;
    TButton *btnGetChecksum;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnSpecialTestClick(TObject *Sender);
    void __fastcall edtTestTimeExit(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall btnRightDataTestClick(TObject *Sender);
    void __fastcall btnChecksumErrorClick(TObject *Sender);
    void __fastcall btnEscapeDataTestClick(TObject *Sender);
    void __fastcall btnChecksumEscapingTestClick(TObject *Sender);
    void __fastcall edtRawDataExit(TObject *Sender);
    void __fastcall btnRawDataTestClick(TObject *Sender);
    void __fastcall btnGetChecksumClick(TObject *Sender);
private:	// User declarations
    CSpecialTestMan m_SpecialTest_Man_Obj;
    int m_nHugeDataTestNum;
    unsigned char m_cRawDataBuf[RAW_DATA_LEN];
    int m_nChecksum;
    int m_nRawDataSize;

    void ShowHintLabel( TControl *sender, char* hint );
    void GetRawDataTestBuf(void);
    int GetCheckSum(char *buf, int size);
    bool ParseSendData(unsigned char *buf_ptr, unsigned int input_len);
    int String2Hex(std::string str, char *SendOut);
    char ConvertHexData(char ch);
public:		// User declarations
    __fastcall TfrmSpecialTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSpecialTest *frmSpecialTest;
//---------------------------------------------------------------------------
#endif
