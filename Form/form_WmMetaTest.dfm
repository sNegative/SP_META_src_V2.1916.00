object frmWmMetaTest: TfrmWmMetaTest
  Left = 288
  Top = 233
  Width = 415
  Height = 273
  Caption = 'frmWmMetaTest'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnSum: TButton
    Left = 24
    Top = 24
    Width = 81
    Height = 25
    Caption = 'Sum'
    TabOrder = 0
    OnClick = btnSumClick
  end
  object btnQueryIfTargetSupportDVBH: TButton
    Left = 24
    Top = 56
    Width = 81
    Height = 25
    Caption = 'Query DVBH'
    TabOrder = 1
    OnClick = btnQueryIfTargetSupportDVBHClick
  end
  object btnActiveTimer: TButton
    Left = 24
    Top = 88
    Width = 81
    Height = 25
    Caption = 'Active Timer'
    TabOrder = 2
    OnClick = btnActiveTimerClick
  end
  object btnWriteFile: TButton
    Left = 24
    Top = 120
    Width = 81
    Height = 25
    Caption = 'Write File'
    TabOrder = 3
    OnClick = btnWriteFileClick
  end
  object btnReadFile: TButton
    Left = 24
    Top = 152
    Width = 81
    Height = 25
    Caption = 'Read File'
    TabOrder = 4
    OnClick = btnReadFileClick
  end
  object editSum: TEdit
    Left = 120
    Top = 24
    Width = 257
    Height = 21
    TabOrder = 5
  end
  object editQueryIfTargetSupportDVBH: TEdit
    Left = 120
    Top = 56
    Width = 257
    Height = 21
    TabOrder = 6
  end
  object editActiveTimer: TEdit
    Left = 120
    Top = 88
    Width = 257
    Height = 21
    TabOrder = 7
  end
  object editWriteFile: TEdit
    Left = 120
    Top = 120
    Width = 257
    Height = 21
    TabOrder = 8
  end
  object editReadFile: TEdit
    Left = 120
    Top = 152
    Width = 257
    Height = 21
    TabOrder = 9
  end
  object btnUnitTest: TButton
    Left = 24
    Top = 200
    Width = 81
    Height = 25
    Caption = 'Unit Test'
    TabOrder = 10
    OnClick = btnUnitTestClick
  end
  object tTimerControl: TTimer
    Interval = 200
    OnTimer = ControlChange
    Left = 112
    Top = 8
  end
end
