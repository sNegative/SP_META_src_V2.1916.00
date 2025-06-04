object frmGPSAutoTest: TfrmGPSAutoTest
  Left = 541
  Top = 192
  Width = 425
  Height = 286
  Caption = 'GPS CW Test Mode Auto Test Setting'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 40
    Width = 80
    Height = 13
    Caption = 'Auto test number'
  end
  object Label2: TLabel
    Left = 187
    Top = 42
    Width = 48
    Height = 13
    Caption = '(1'#65374'1000)'
  end
  object EDAutoTestNum: TEdit
    Left = 96
    Top = 38
    Width = 81
    Height = 21
    ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
    TabOrder = 0
    OnExit = EDAutoTestNumExit
  end
  object BtnCWLogPath: TButton
    Left = 8
    Top = 88
    Width = 81
    Height = 25
    Caption = 'Save log file as'
    TabOrder = 1
    OnClick = BtnCWLogPathClick
  end
  object stAutoTestFilePath: TStaticText
    Left = 96
    Top = 88
    Width = 273
    Height = 25
    AutoSize = False
    BorderStyle = sbsSunken
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 2
  end
  object BtnOk: TButton
    Left = 112
    Top = 168
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = BtnOkClick
  end
  object BtnCancel: TButton
    Left = 240
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = BtnCancelClick
  end
  object lblHint: TStaticText
    Left = 288
    Top = 128
    Width = 33
    Height = 17
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 5
    Visible = False
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 344
    Top = 40
  end
  object SaveDialogCWLog: TSaveDialog
    Filter = 'Text file (*.txt)|*.txt|All files (*.*)|*.*'
    Left = 344
    Top = 200
  end
end
