//----------------------------------------------------------------------------
#ifndef nfc_reader_modeH
#define nfc_reader_modeH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
//----------------------------------------------------------------------------
class TOKRightDlg : public TForm
{
__published:
	TBevel *Bevel1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *tb_AIRM_NTF_Read;
        TButton *tb_AIRM_NTF_Write;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label8;
        TEdit *Edit3;
        TLabel *Label9;
        TEdit *Edit4;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TEdit *Edit5;
        TLabel *Label13;
        TEdit *Edit6;
        TLabel *Label14;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TLabel *Label15;
        TEdit *Edit7;
        TLabel *Label16;
        TLabel *Label18;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TLabel *Label17;
        TEdit *Edit8;
        TButton *Button1;
private:
public:
	virtual __fastcall TOKRightDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKRightDlg *OKRightDlg;
//----------------------------------------------------------------------------
#endif    
