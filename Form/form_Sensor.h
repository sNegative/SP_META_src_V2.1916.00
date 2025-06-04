//---------------------------------------------------------------------------

#ifndef form_SensorH
#define form_SensorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>


#include "GSensor.h"
#include "GYROSensor.h"

//---------------------------------------------------------------------------
class TfrmSensor : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *ENumberSample;
    TEdit *ESampleDelay;
    TEdit *ETolerance;
    TButton *btnPerformCalibration;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TButton *btnWriteNvram;
    TStaticText *stInfo;
    TStaticText *EXaxis;
    TStaticText *EYaxis;
    TStaticText *EZaxis;
    TStaticText *EStatus;
    TStaticText *StaticText1;
    TStaticText *StaticText2;
    TGroupBox *GroupBox3;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TEdit *GYROENumberSample;
    TEdit *GYROESampleDelay;
    TEdit *GYROETolerance;
    TButton *btnbtnPerformCalibrationGYRO;
    TGroupBox *GroupBox4;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TButton *btnWriteNvramGYNO;
    TStaticText *GYROEXaxis;
    TStaticText *GYROEYaxis;
    TStaticText *GYROEZaxis;
    TStaticText *GYROEStatus;
    TStaticText *stGYROInfo;
    void __fastcall btnPerformCalibrationClick(TObject *Sender);
    void __fastcall btnWriteNvramClick(TObject *Sender);
    void __fastcall btnPerformCalibrationGYROClick(TObject *Sender);
    void __fastcall btnWriteNvramGYROClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSensor(TComponent* Owner);
    void CNF_GS_Perform_Calibration(void);
    void CNF_GYRO_Perform_Calibration(void);
    void CNF_GS_Write_NVRAM(void);
    void CNF_GYRO_Write_NVRAM(void);
    void SetStatusBarString(char *strInfo);
    void SetGYROStatusBarString(char *strInfo);

    CGSensor m_cGSensor_Obj;
    CGYROSensor m_cGYROSensor_Obj;
    float GS_InttoFloat(int input);
    float GYRO_InttoFloat(int input);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSensor *frmSensor;
//---------------------------------------------------------------------------

#endif


