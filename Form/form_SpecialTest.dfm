object frmSpecialTest: TfrmSpecialTest
  Left = 421
  Top = 137
  Width = 586
  Height = 535
  Caption = 'Special Test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 24
    Top = 24
    Width = 481
    Height = 137
    Caption = 'Huge Data Test'
    TabOrder = 0
    object Label1: TLabel
      Left = 12
      Top = 31
      Width = 49
      Height = 13
      Caption = 'Data Size:'
    end
    object Label2: TLabel
      Left = 13
      Top = 63
      Width = 50
      Height = 13
      Caption = 'Test Time:'
    end
    object Label3: TLabel
      Left = 192
      Top = 64
      Width = 43
      Height = 13
      Caption = '(1~1000)'
    end
    object btnSpecialTest: TButton
      Left = 16
      Top = 96
      Width = 75
      Height = 25
      Caption = 'Test'
      TabOrder = 0
      OnClick = btnSpecialTestClick
    end
    object cbxDataSize: TComboBox
      Left = 78
      Top = 29
      Width = 105
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      TabOrder = 1
      Items.Strings = (
        '10K'
        '20K'
        '30K'
        '40K'
        '50K')
    end
    object edtTestTime: TEdit
      Left = 78
      Top = 61
      Width = 105
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 2
      Text = '1'
      OnExit = edtTestTimeExit
    end
  end
  object lblHint: TStaticText
    Left = 288
    Top = 128
    Width = 33
    Height = 17
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 1
    Visible = False
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 176
    Width = 481
    Height = 313
    Caption = 'Special Test'
    TabOrder = 2
    object Label4: TLabel
      Left = 16
      Top = 17
      Width = 251
      Height = 13
      Caption = 'Please input the data you want to send to target side.'
    end
    object btnChecksumError: TButton
      Left = 167
      Top = 235
      Width = 129
      Height = 25
      Caption = 'Checksum Error Test'
      TabOrder = 0
      Visible = False
      OnClick = btnChecksumErrorClick
    end
    object btnRightDataTest: TButton
      Left = 332
      Top = 274
      Width = 128
      Height = 25
      Caption = 'Right Data Test'
      TabOrder = 1
      Visible = False
      OnClick = btnRightDataTestClick
    end
    object btnEscapeDataTest: TButton
      Left = 328
      Top = 236
      Width = 129
      Height = 25
      Caption = 'Escaping Data Test'
      TabOrder = 2
      Visible = False
      OnClick = btnEscapeDataTestClick
    end
    object memRFResult: TRichEdit
      Left = -248
      Top = 96
      Width = 30
      Height = 161
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      Lines.Strings = (
        '')
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 3
    end
    object edtRawData: TRichEdit
      Left = 15
      Top = 54
      Width = 441
      Height = 169
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      Lines.Strings = (
        '')
      ParentFont = False
      TabOrder = 4
      OnExit = edtRawDataExit
    end
    object btnChecksumEscapingTest: TButton
      Left = 168
      Top = 272
      Width = 129
      Height = 25
      Caption = 'Checksum Escaping Test'
      TabOrder = 5
      Visible = False
      OnClick = btnChecksumEscapingTestClick
    end
    object btnRawDataTest: TButton
      Left = 16
      Top = 240
      Width = 121
      Height = 25
      Caption = 'Raw Data Test'
      TabOrder = 6
      OnClick = btnRawDataTestClick
    end
    object btnGetChecksum: TButton
      Left = 16
      Top = 280
      Width = 121
      Height = 25
      Caption = 'Get Checksum'
      TabOrder = 7
      Visible = False
      OnClick = btnGetChecksumClick
    end
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 344
    Top = 40
  end
end
