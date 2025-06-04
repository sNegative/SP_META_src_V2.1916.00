object frmGetVersion: TfrmGetVersion
  Left = 385
  Top = 324
  Width = 701
  Height = 392
  Caption = 'Get version'
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
  object sbVersion: TStatusBar
    Left = 0
    Top = 305
    Width = 689
    Height = 32
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object GetVersion: TGroupBox
    Left = 8
    Top = 8
    Width = 681
    Height = 177
    Caption = 'Get Version'
    TabOrder = 1
    object Label1: TLabel
      Left = 74
      Top = 68
      Width = 79
      Height = 13
      Caption = 'Software version'
    end
    object Label7: TLabel
      Left = 552
      Top = 16
      Width = 59
      Height = 13
      Caption = 'RSC version'
    end
    object Label6: TLabel
      Left = 380
      Top = 16
      Width = 101
      Height = 13
      Caption = 'DSP firmware version'
    end
    object Label5: TLabel
      Left = 230
      Top = 16
      Width = 59
      Height = 13
      Caption = 'ECO version'
    end
    object Label4: TLabel
      Left = 32
      Top = 16
      Width = 109
      Height = 13
      Caption = 'BaseBand chip version'
    end
    object Label3: TLabel
      Left = 538
      Top = 68
      Width = 71
      Height = 13
      Caption = 'Melody version'
    end
    object Label2: TLabel
      Left = 294
      Top = 68
      Width = 83
      Height = 13
      Caption = 'Hardware version'
    end
    object btnSaveToFile: TButton
      Left = 441
      Top = 136
      Width = 80
      Height = 25
      Caption = 'Save to file'
      TabOrder = 0
      OnClick = btnSaveToFileClick
    end
    object btnLoadFromFile: TButton
      Left = 305
      Top = 136
      Width = 80
      Height = 25
      Caption = 'Load from file'
      TabOrder = 1
      OnClick = btnLoadFromFileClick
    end
    object btnGetTargetVersion: TButton
      Left = 128
      Top = 136
      Width = 113
      Height = 25
      Caption = 'Get target version'
      TabOrder = 2
      OnClick = btnGetTargetVersionClick
    end
    object stBBChipVersion: TStaticText
      Left = 16
      Top = 32
      Width = 153
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 3
    end
    object stSWVersion: TStaticText
      Left = 16
      Top = 88
      Width = 209
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 4
    end
    object stMelodyVersion: TStaticText
      Left = 464
      Top = 88
      Width = 209
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 5
    end
    object stHWVersion: TStaticText
      Left = 240
      Top = 88
      Width = 209
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 6
    end
    object stECOVersion: TStaticText
      Left = 184
      Top = 32
      Width = 153
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 7
    end
    object stDSPPatchVersion: TStaticText
      Left = 520
      Top = 32
      Width = 153
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 8
    end
    object stDSPFirmwareVersion: TStaticText
      Left = 352
      Top = 32
      Width = 153
      Height = 25
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clBtnHighlight
      ParentColor = False
      TabOrder = 9
    end
  end
  object UUID: TGroupBox
    Left = 8
    Top = 200
    Width = 681
    Height = 81
    Caption = 'UUID'
    TabOrder = 2
    object Label8: TLabel
      Left = 104
      Top = 16
      Width = 52
      Height = 13
      Caption = 'UUID High'
    end
    object Label9: TLabel
      Left = 248
      Top = 16
      Width = 50
      Height = 13
      Caption = 'UUID Low'
    end
    object Label10: TLabel
      Left = 48
      Top = 32
      Width = 13
      Height = 16
      Caption = '0x'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object edUUIDLow1: TEdit
      Left = 216
      Top = 32
      Width = 17
      Height = 21
      MaxLength = 10
      TabOrder = 1
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object bnUUIDRead: TButton
      Left = 400
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Read'
      TabOrder = 2
      OnClick = bnUUIDReadClick
    end
    object bnUUIDWrite: TButton
      Left = 520
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Write'
      TabOrder = 3
      OnClick = bnUUIDWriteClick
    end
    object edUUIDHigh1: TEdit
      Left = 64
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh2: TEdit
      Left = 80
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 4
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh3: TEdit
      Left = 96
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 5
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh4: TEdit
      Left = 112
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 6
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh5: TEdit
      Left = 128
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 7
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh6: TEdit
      Left = 144
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 8
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh7: TEdit
      Left = 160
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 9
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDHigh8: TEdit
      Left = 176
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 10
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow2: TEdit
      Left = 232
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 11
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow3: TEdit
      Left = 248
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 12
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow4: TEdit
      Left = 264
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 13
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow5: TEdit
      Left = 280
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 14
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow6: TEdit
      Left = 296
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 15
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow7: TEdit
      Left = 312
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 16
      Text = '0'
      OnExit = edtUUIDCheck
    end
    object edUUIDLow8: TEdit
      Left = 328
      Top = 32
      Width = 17
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      MaxLength = 10
      ParentFont = False
      TabOrder = 17
      Text = '0'
      OnExit = edtUUIDCheck
    end
  end
  object lblHint: TStaticText
    Left = 304
    Top = 184
    Width = 33
    Height = 17
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 3
    Visible = False
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 'Ini file (*.ini)|*.ini|All files (*.*)|*.*'
    Title = 'Open ini file'
    Left = 16
    Top = 152
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 'Ini file (*.ini)|*.ini|All files (*.*)|*.*'
    Title = 'Save ini file'
    Left = 72
    Top = 152
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 208
    Top = 184
  end
end
