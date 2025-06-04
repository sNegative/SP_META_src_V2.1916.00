object frmWiFiEEPROM: TfrmWiFiEEPROM
  Left = 180
  Top = -5
  Width = 743
  Height = 398
  Caption = 'WiFi EEPROM Setting'
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
  object Shape1: TShape
    Left = 376
    Top = 12
    Width = 9
    Height = 9
    Brush.Color = clMaroon
  end
  object Label40: TLabel
    Left = 392
    Top = 10
    Width = 48
    Height = 13
    Caption = 'Read only'
  end
  object pnlPCL: TPanel
    Left = 7
    Top = 192
    Width = 722
    Height = 105
    BevelOuter = bvLowered
    TabOrder = 0
    object Label13: TLabel
      Left = 48
      Top = 26
      Width = 42
      Height = 13
      Caption = '2412000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 96
      Top = 24
      Width = 42
      Height = 13
      Caption = '2417000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 144
      Top = 24
      Width = 42
      Height = 13
      Caption = '2422000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 192
      Top = 24
      Width = 42
      Height = 13
      Caption = '2427000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 240
      Top = 24
      Width = 42
      Height = 13
      Caption = '2432000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 336
      Top = 24
      Width = 42
      Height = 13
      Caption = '2442000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 384
      Top = 24
      Width = 42
      Height = 13
      Caption = '2447000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 432
      Top = 24
      Width = 42
      Height = 13
      Caption = '2452000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 480
      Top = 24
      Width = 42
      Height = 13
      Caption = '2457000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 528
      Top = 24
      Width = 42
      Height = 13
      Caption = '2462000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label23: TLabel
      Left = 576
      Top = 24
      Width = 42
      Height = 13
      Caption = '2467000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label24: TLabel
      Left = 624
      Top = 24
      Width = 42
      Height = 13
      Caption = '2472000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label25: TLabel
      Left = 672
      Top = 24
      Width = 42
      Height = 13
      Caption = '2484000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label26: TLabel
      Left = 344
      Top = 8
      Width = 117
      Height = 13
      Caption = 'Channel frequency (kHz)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label28: TLabel
      Left = 288
      Top = 24
      Width = 42
      Height = 13
      Caption = '2437000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 16
      Top = 40
      Width = 21
      Height = 13
      Caption = 'CCK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 76
      Width = 31
      Height = 13
      Caption = 'OFDM'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object edtCCKCHDAC00: TEdit
      Left = 48
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object edtCCKCHDAC01: TEdit
      Tag = 1
      Left = 96
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = '0'
    end
    object edtCCKCHDAC02: TEdit
      Tag = 2
      Left = 144
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 2
      Text = '0'
    end
    object edtCCKCHDAC03: TEdit
      Tag = 3
      Left = 192
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 3
      Text = '0'
    end
    object edtCCKCHDAC04: TEdit
      Tag = 4
      Left = 240
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object edtCCKCHDAC05: TEdit
      Tag = 5
      Left = 288
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 5
      Text = '0'
    end
    object edtCCKCHDAC06: TEdit
      Tag = 6
      Left = 336
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 6
      Text = '0'
    end
    object edtCCKCHDAC07: TEdit
      Tag = 7
      Left = 384
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 7
      Text = '0'
    end
    object edtCCKCHDAC08: TEdit
      Tag = 8
      Left = 432
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object edtCCKCHDAC09: TEdit
      Tag = 9
      Left = 480
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 9
      Text = '0'
    end
    object edtCCKCHDAC0A: TEdit
      Tag = 10
      Left = 528
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 10
      Text = '0'
    end
    object edtCCKCHDAC0B: TEdit
      Tag = 11
      Left = 576
      Top = 40
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 11
      Text = '0'
    end
    object edtOFDMCHDAC01: TEdit
      Tag = 1
      Left = 96
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 12
      Text = '0'
    end
    object edtOFDMCHDAC02: TEdit
      Tag = 2
      Left = 144
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 13
      Text = '0'
    end
    object edtOFDMCHDAC03: TEdit
      Tag = 3
      Left = 192
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 14
      Text = '0'
    end
    object edtOFDMCHDAC04: TEdit
      Tag = 4
      Left = 240
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 15
      Text = '0'
    end
    object edtOFDMCHDAC05: TEdit
      Tag = 5
      Left = 288
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 16
      Text = '0'
    end
    object edtOFDMCHDAC06: TEdit
      Tag = 6
      Left = 336
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 17
      Text = '0'
    end
    object edtOFDMCHDAC07: TEdit
      Tag = 7
      Left = 384
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 18
      Text = '0'
    end
    object edtOFDMCHDAC08: TEdit
      Tag = 8
      Left = 432
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 19
      Text = '0'
    end
    object edtOFDMCHDAC09: TEdit
      Tag = 9
      Left = 480
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 20
      Text = '0'
    end
    object edtOFDMCHDAC0A: TEdit
      Tag = 10
      Left = 528
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 21
      Text = '0'
    end
    object edtOFDMCHDAC0B: TEdit
      Tag = 11
      Left = 576
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 22
      Text = '0'
    end
    object edtOFDMCHDAC00: TEdit
      Left = 48
      Top = 72
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 23
      Text = '0'
    end
    object edtCCKCHDAC0C: TEdit
      Tag = 12
      Left = 624
      Top = 40
      Width = 40
      Height = 21
      TabOrder = 24
      Text = '0'
    end
    object edtCCKCHDAC0D: TEdit
      Tag = 13
      Left = 672
      Top = 40
      Width = 40
      Height = 21
      TabOrder = 25
      Text = '0'
    end
    object edtOFDMCHDAC0C: TEdit
      Tag = 12
      Left = 624
      Top = 72
      Width = 40
      Height = 21
      TabOrder = 26
      Text = '0'
    end
    object edtOFDMCHDAC0D: TEdit
      Tag = 13
      Left = 672
      Top = 72
      Width = 40
      Height = 21
      TabOrder = 27
      Text = '0'
    end
  end
  object pnl2400MTXP: TPanel
    Left = 8
    Top = 168
    Width = 241
    Height = 25
    BevelOuter = bvLowered
    Caption = '2.4G TX Power Table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Panel2: TPanel
    Left = 8
    Top = 32
    Width = 721
    Height = 45
    BevelOuter = bvLowered
    TabOrder = 2
    object lblBBChipID: TLabel
      Left = 48
      Top = 4
      Width = 51
      Height = 13
      Caption = 'BB chip ID'
    end
    object lblRFChipID: TLabel
      Left = 176
      Top = 4
      Width = 51
      Height = 13
      Caption = 'RF chip ID'
    end
    object lblSN: TLabel
      Left = 312
      Top = 4
      Width = 64
      Height = 13
      Caption = 'Serial number'
    end
    object lblMACAddr: TLabel
      Left = 456
      Top = 4
      Width = 63
      Height = 13
      Caption = 'MAC address'
    end
    object lblBBChipID0x: TLabel
      Left = 8
      Top = 26
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object lblRFChipID0x: TLabel
      Left = 148
      Top = 26
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object lblSN0x: TLabel
      Left = 286
      Top = 26
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object lblMACAddr0x: TLabel
      Left = 400
      Top = 26
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object edtBBChipID: TEdit
      Left = 24
      Top = 20
      Width = 89
      Height = 21
      TabOrder = 0
      Text = '0'
      OnExit = edtBBChipIDCheck
    end
    object edtRFChipID: TEdit
      Left = 162
      Top = 20
      Width = 89
      Height = 21
      TabOrder = 1
      Text = '0'
      OnExit = edtRFChipIDCheck
    end
    object edtSN: TEdit
      Left = 300
      Top = 20
      Width = 89
      Height = 21
      TabOrder = 2
      Text = '0'
      OnExit = edtSNCheck
    end
    object edtMACAddr5: TEdit
      Tag = 5
      Left = 416
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 3
      Text = '00'
      OnExit = edtMACAddrCheck
    end
    object edtMACAddr4: TEdit
      Tag = 4
      Left = 440
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 4
      Text = '00'
      OnExit = edtMACAddrCheck
    end
    object edtMACAddr3: TEdit
      Tag = 3
      Left = 464
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 5
      Text = '00'
      OnExit = edtMACAddrCheck
    end
    object edtMACAddr2: TEdit
      Tag = 2
      Left = 488
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 6
      Text = '00'
      OnExit = edtMACAddrCheck
    end
    object edtMACAddr1: TEdit
      Tag = 1
      Left = 512
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 7
      Text = '00'
      OnExit = edtMACAddrCheck
    end
    object edtMACAddr0: TEdit
      Left = 536
      Top = 20
      Width = 25
      Height = 21
      TabOrder = 8
      Text = '00'
      OnExit = edtMACAddrCheck
    end
  end
  object pnlWGI: TPanel
    Left = 8
    Top = 8
    Width = 241
    Height = 25
    BevelOuter = bvLowered
    Caption = 'WiFi General Information'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object pnlTXDC: TPanel
    Left = 8
    Top = 80
    Width = 241
    Height = 25
    BevelOuter = bvLowered
    Caption = 'TX DC Offset'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object Panel3: TPanel
    Left = 8
    Top = 104
    Width = 353
    Height = 57
    BevelOuter = bvLowered
    TabOrder = 5
    object lblTXIDC0x: TLabel
      Left = 8
      Top = 32
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object lblTXQDC0x: TLabel
      Left = 112
      Top = 32
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object Label29: TLabel
      Left = 40
      Top = 8
      Width = 24
      Height = 13
      Caption = 'I_DC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label30: TLabel
      Left = 144
      Top = 8
      Width = 29
      Height = 13
      Caption = 'Q_DC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object edtTXIDC: TEdit
      Left = 24
      Top = 28
      Width = 57
      Height = 21
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object edtTXQDC: TEdit
      Left = 128
      Top = 28
      Width = 57
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = '0'
    end
  end
  object btnWGI: TButton
    Tag = 1
    Left = 256
    Top = 10
    Width = 41
    Height = 20
    Caption = 'Hex'
    TabOrder = 6
    OnClick = btnWGIClick
  end
  object btnTXDC: TButton
    Tag = 1
    Left = 256
    Top = 82
    Width = 41
    Height = 20
    Caption = 'Hex'
    TabOrder = 7
    OnClick = btnTXDCClick
  end
  object btn2400MTXP: TButton
    Tag = 1
    Left = 256
    Top = 170
    Width = 41
    Height = 20
    Caption = 'Hex'
    TabOrder = 8
    OnClick = btn2400MTXPClick
  end
  object btnUploadFromEEPROM: TButton
    Left = 8
    Top = 312
    Width = 115
    Height = 25
    Caption = 'Upload from EEPROM'
    TabOrder = 9
    OnClick = btnUploadFromEEPROMClick
  end
  object btnDownloadToEEPROM: TButton
    Left = 136
    Top = 312
    Width = 115
    Height = 25
    Caption = 'Download to EEPROM'
    TabOrder = 10
    OnClick = btnDownloadToEEPROMClick
  end
  object sbWiFiEEPROM: TStatusBar
    Left = 0
    Top = 337
    Width = 729
    Height = 28
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object btnSaveToFile: TButton
    Left = 352
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Save to file'
    TabOrder = 12
    OnClick = btnSaveToFileClick
  end
  object btnLoadFromFile: TButton
    Left = 264
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Load from file'
    TabOrder = 13
    OnClick = btnLoadFromFileClick
  end
  object lblHint: TStaticText
    Left = 504
    Top = 680
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 14
    Visible = False
  end
  object Panel1: TPanel
    Left = 376
    Top = 104
    Width = 353
    Height = 57
    BevelOuter = bvLowered
    TabOrder = 15
    object lblChecksum: TLabel
      Left = 39
      Top = 12
      Width = 50
      Height = 13
      Caption = 'Checksum'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblChecksum0x: TLabel
      Left = 6
      Top = 32
      Width = 11
      Height = 13
      Caption = '0x'
    end
    object edtChecksum: TEdit
      Left = 24
      Top = 28
      Width = 89
      Height = 21
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
  end
  object Panel4: TPanel
    Left = 376
    Top = 80
    Width = 241
    Height = 25
    BevelOuter = bvLowered
    Caption = 'Checksum'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 16
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 456
    Top = 680
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Left = 560
    Top = 680
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Left = 608
    Top = 680
  end
end
