object frmUnitTest: TfrmUnitTest
  Left = 457
  Top = 357
  Width = 490
  Height = 532
  Caption = 'Unit Test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edtTestCase: TEdit
    Left = 16
    Top = 32
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
    Text = '0'
    OnExit = edtTestCaseCheck
  end
  object btnTest: TButton
    Left = 152
    Top = 32
    Width = 57
    Height = 25
    Caption = 'Test'
    TabOrder = 1
    OnClick = btnTestClick
  end
  object lblHint: TStaticText
    Left = 211
    Top = 471
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 2
    Visible = False
  end
  object btnTestAll: TButton
    Left = 224
    Top = 32
    Width = 57
    Height = 25
    Caption = 'TestAll'
    TabOrder = 3
    Visible = False
    OnClick = btnTestAllClick
  end
  object btnTestDVB: TButton
    Left = 132
    Top = 472
    Width = 81
    Height = 33
    Caption = 'btnTestDVB'
    TabOrder = 4
    Visible = False
    OnClick = btnTestDVBClick
  end
  object btnTestWmWiFi: TButton
    Left = 31
    Top = 472
    Width = 89
    Height = 33
    Caption = 'btnTestWmWiFi'
    TabOrder = 5
    Visible = False
    OnClick = btnTestWmWiFiClick
  end
  object btnTestNVRAM: TButton
    Left = 212
    Top = 472
    Width = 89
    Height = 33
    Caption = 'NVRAM Test'
    TabOrder = 6
    Visible = False
    OnClick = btnTestNVRAMClick
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 80
    Width = 449
    Height = 385
    Caption = 'HW Test Tool API Test'
    TabOrder = 7
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 46
      Height = 13
      Caption = 'Auto Test'
    end
    object Label2: TLabel
      Left = 8
      Top = 152
      Width = 59
      Height = 13
      Caption = 'Manual Test'
    end
    object Label3: TLabel
      Left = 16
      Top = 328
      Width = 79
      Height = 13
      Caption = 'Clear Information'
    end
    object HWTestInfo: TMemo
      Left = 136
      Top = 104
      Width = 305
      Height = 265
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      Lines.Strings = (
        'HWTestInfo')
      ScrollBars = ssVertical
      TabOrder = 0
    end
    object HWTest: TButton
      Left = 24
      Top = 104
      Width = 97
      Height = 25
      Caption = 'Test'
      TabOrder = 1
      OnClick = HWTestClick
    end
    object ClearInfo: TButton
      Left = 24
      Top = 352
      Width = 97
      Height = 25
      Caption = 'Clear'
      TabOrder = 2
      OnClick = ClearInfoClick
    end
    object btnReceiver: TButton
      Left = 40
      Top = 232
      Width = 73
      Height = 25
      Caption = 'Receiver'
      TabOrder = 3
      OnClick = btnReceiverClick
    end
    object btnPass: TButton
      Left = 40
      Top = 264
      Width = 75
      Height = 25
      Caption = 'Pass'
      TabOrder = 4
      OnClick = btnPassClick
    end
    object btnFail: TButton
      Left = 40
      Top = 296
      Width = 75
      Height = 25
      Caption = 'Fail'
      TabOrder = 5
      OnClick = btnFailClick
    end
    object btnSpeakerR: TButton
      Left = 40
      Top = 200
      Width = 73
      Height = 25
      Caption = 'Speaker R'
      TabOrder = 6
      OnClick = btnSpeakerRClick
    end
    object btnSpeakerL: TButton
      Left = 40
      Top = 168
      Width = 73
      Height = 25
      Caption = 'Speaker L'
      TabOrder = 7
      OnClick = btnSpeakerLClick
    end
    object cb_wifi: TCheckBox
      Left = 16
      Top = 48
      Width = 57
      Height = 17
      Caption = 'WIFI'
      TabOrder = 8
    end
    object cb_bt: TCheckBox
      Left = 96
      Top = 48
      Width = 57
      Height = 17
      Caption = 'BT'
      TabOrder = 9
    end
    object cb_fm: TCheckBox
      Left = 176
      Top = 48
      Width = 57
      Height = 17
      Caption = 'FM'
      TabOrder = 10
    end
    object cb_gps: TCheckBox
      Left = 256
      Top = 48
      Width = 57
      Height = 17
      Caption = 'GPS'
      TabOrder = 11
    end
    object cb_gsensor: TCheckBox
      Left = 336
      Top = 48
      Width = 73
      Height = 17
      Caption = 'G-Sensor'
      TabOrder = 12
    end
    object cb_msensor: TCheckBox
      Left = 16
      Top = 64
      Width = 73
      Height = 17
      Caption = 'M-Sensor'
      TabOrder = 13
    end
    object cb_sdcard: TCheckBox
      Left = 96
      Top = 64
      Width = 73
      Height = 17
      Caption = 'SD Card'
      TabOrder = 14
    end
    object cb_ctp: TCheckBox
      Left = 176
      Top = 64
      Width = 57
      Height = 17
      Caption = 'CTP'
      TabOrder = 15
    end
    object cb_gyrosensor: TCheckBox
      Left = 256
      Top = 64
      Width = 81
      Height = 17
      Caption = 'Gyro sensor'
      TabOrder = 16
    end
    object cb_alsps: TCheckBox
      Left = 336
      Top = 64
      Width = 57
      Height = 17
      Caption = 'ALS/PS'
      TabOrder = 17
    end
    object cb_cancelAll: TCheckBox
      Left = 16
      Top = 80
      Width = 81
      Height = 17
      Caption = 'Cancel All'
      TabOrder = 18
    end
  end
  object btnEnATM: TButton
    Left = 344
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Enable ATM'
    TabOrder = 8
    OnClick = btnEnATMClick
  end
  object btnDisATM: TButton
    Left = 344
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Disable ATM'
    TabOrder = 9
    OnClick = btnDisATMClick
  end
  object HintTimer: TTimer
    OnTimer = HintTimerTimer
    Left = 144
    Top = 464
  end
end
