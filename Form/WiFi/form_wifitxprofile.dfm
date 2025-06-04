object frmWiFiTxProfile: TfrmWiFiTxProfile
  Left = 172
  Top = -8
  Width = 784
  Height = 240
  Caption = 'WiFi TX Power Profile'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pnlPCL: TPanel
    Left = 8
    Top = 8
    Width = 761
    Height = 137
    BevelOuter = bvLowered
    TabOrder = 0
    object Label13: TLabel
      Left = 62
      Top = 42
      Width = 42
      Height = 13
      Caption = '2412000'
    end
    object Label14: TLabel
      Left = 111
      Top = 40
      Width = 42
      Height = 13
      Caption = '2417000'
    end
    object Label15: TLabel
      Left = 160
      Top = 40
      Width = 42
      Height = 13
      Caption = '2422000'
    end
    object Label16: TLabel
      Left = 210
      Top = 40
      Width = 42
      Height = 13
      Caption = '2427000'
    end
    object Label17: TLabel
      Left = 259
      Top = 40
      Width = 42
      Height = 13
      Caption = '2432000'
    end
    object Label18: TLabel
      Left = 358
      Top = 40
      Width = 42
      Height = 13
      Caption = '2442000'
    end
    object Label19: TLabel
      Left = 407
      Top = 40
      Width = 42
      Height = 13
      Caption = '2447000'
    end
    object Label20: TLabel
      Left = 457
      Top = 40
      Width = 42
      Height = 13
      Caption = '2452000'
    end
    object Label21: TLabel
      Left = 506
      Top = 40
      Width = 42
      Height = 13
      Caption = '2457000'
    end
    object Label22: TLabel
      Left = 555
      Top = 40
      Width = 42
      Height = 13
      Caption = '2462000'
    end
    object Label23: TLabel
      Left = 605
      Top = 40
      Width = 42
      Height = 13
      Caption = '2467000'
    end
    object Label24: TLabel
      Left = 654
      Top = 40
      Width = 42
      Height = 13
      Caption = '2472000'
    end
    object Label25: TLabel
      Left = 704
      Top = 40
      Width = 42
      Height = 13
      Caption = '2484000'
    end
    object Label27: TLabel
      Left = 384
      Top = 16
      Width = 117
      Height = 13
      Caption = 'Channel frequency (kHz)'
    end
    object Label28: TLabel
      Left = 308
      Top = 40
      Width = 42
      Height = 13
      Caption = '2437000'
    end
    object Label1: TLabel
      Left = 24
      Top = 56
      Width = 21
      Height = 13
      Caption = 'CCK'
    end
    object Label2: TLabel
      Left = 16
      Top = 96
      Width = 31
      Height = 13
      Caption = 'OFDM'
    end
    object edtCCKCHDAC00: TEdit
      Left = 64
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 0
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC01: TEdit
      Tag = 1
      Left = 113
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 1
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC02: TEdit
      Tag = 2
      Left = 162
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 2
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC03: TEdit
      Tag = 3
      Left = 211
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 3
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC04: TEdit
      Tag = 4
      Left = 260
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 4
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC05: TEdit
      Tag = 5
      Left = 310
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 5
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC06: TEdit
      Tag = 6
      Left = 359
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 6
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC07: TEdit
      Tag = 7
      Left = 408
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 7
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC08: TEdit
      Tag = 8
      Left = 457
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 8
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC09: TEdit
      Tag = 9
      Left = 507
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 9
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC0A: TEdit
      Tag = 10
      Left = 556
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 10
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC0B: TEdit
      Tag = 11
      Left = 605
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 11
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtOFDMCHDAC01: TEdit
      Tag = 1
      Left = 113
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 12
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC02: TEdit
      Tag = 2
      Left = 162
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 13
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC03: TEdit
      Tag = 3
      Left = 211
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 14
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC04: TEdit
      Tag = 4
      Left = 260
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 15
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC05: TEdit
      Tag = 5
      Left = 310
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 16
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC06: TEdit
      Tag = 6
      Left = 359
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 17
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC07: TEdit
      Tag = 7
      Left = 408
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 18
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC08: TEdit
      Tag = 8
      Left = 457
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 19
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC09: TEdit
      Tag = 9
      Left = 507
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 20
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC0A: TEdit
      Tag = 10
      Left = 556
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 21
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC0B: TEdit
      Tag = 11
      Left = 605
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 22
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC00: TEdit
      Left = 64
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 23
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object btnTxPowerDac: TButton
      Tag = 1
      Left = 238
      Top = 10
      Width = 107
      Height = 23
      Caption = 'TX Power DAC (Hex)'
      TabOrder = 24
      OnClick = btnTxPowerDacClick
    end
    object edtCCKCHDAC0C: TEdit
      Tag = 12
      Left = 654
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 25
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtCCKCHDAC0D: TEdit
      Tag = 13
      Left = 704
      Top = 56
      Width = 40
      Height = 21
      TabOrder = 26
      Text = '0'
      OnExit = edtCCKCHDACCheck
    end
    object edtOFDMCHDAC0C: TEdit
      Tag = 12
      Left = 654
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 27
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
    object edtOFDMCHDAC0D: TEdit
      Tag = 13
      Left = 704
      Top = 96
      Width = 40
      Height = 21
      TabOrder = 28
      Text = '0'
      OnExit = edtOFDMCHDACCheck
    end
  end
  object btnUploadFromFlash: TButton
    Left = 13
    Top = 156
    Width = 100
    Height = 25
    Caption = 'Upload from flash'
    TabOrder = 1
    OnClick = btnUploadFromFlashClick
  end
  object btnDownloadToFlash: TButton
    Left = 118
    Top = 156
    Width = 100
    Height = 25
    Caption = 'Download to flash'
    TabOrder = 2
    OnClick = btnDownloadToFlashClick
  end
  object btnChangeDB: TButton
    Left = 224
    Top = 156
    Width = 100
    Height = 25
    Caption = 'Change NVRAM DB'
    TabOrder = 3
    OnClick = btnChangeDBClick
  end
  object btnLoadFromFile: TButton
    Left = 330
    Top = 156
    Width = 80
    Height = 25
    Caption = 'Load fom file'
    TabOrder = 4
    OnClick = btnLoadFromFileClick
  end
  object btnSaveToFile: TButton
    Left = 420
    Top = 156
    Width = 80
    Height = 25
    Caption = 'Save to file'
    TabOrder = 5
    OnClick = btnSaveToFileClick
  end
  object sbWiFiTXP: TStatusBar
    Left = 0
    Top = 181
    Width = 776
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object lblHint: TStaticText
    Left = 384
    Top = 0
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 7
    Visible = False
  end
  object btnLoadFromEEPROM: TButton
    Left = 512
    Top = 156
    Width = 113
    Height = 25
    Caption = 'Load from EEPROM'
    TabOrder = 8
    OnClick = btnLoadFromEEPROMClick
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Open ini file'
    Left = 488
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Save to ini file'
    Left = 440
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 336
  end
end
