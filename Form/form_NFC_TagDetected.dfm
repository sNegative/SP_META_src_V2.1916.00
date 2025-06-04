object frmNFCTagDetected: TfrmNFCTagDetected
  Left = 381
  Top = 179
  Width = 313
  Height = 503
  Caption = 'NFC Tag Detected'
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
  object gbNFC_TD_Info: TGroupBox
    Left = 16
    Top = 16
    Width = 273
    Height = 281
    Caption = 'Tag Informarion'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object lblNFC_TD_MaxDataRate: TLabel
      Left = 16
      Top = 220
      Width = 72
      Height = 13
      Caption = 'MaxDataRate :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_AppData: TLabel
      Left = 40
      Top = 188
      Width = 48
      Height = 13
      Caption = 'AppData :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_AtqA: TLabel
      Left = 59
      Top = 156
      Width = 29
      Height = 13
      Caption = 'AtqA :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_Sak: TLabel
      Left = 63
      Top = 124
      Width = 25
      Height = 13
      Caption = 'Sak :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_Uid: TLabel
      Left = 66
      Top = 92
      Width = 22
      Height = 13
      Caption = 'Uid :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_CardType: TLabel
      Left = 33
      Top = 60
      Width = 55
      Height = 13
      Caption = 'Card Type :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_Protocol: TLabel
      Left = 43
      Top = 244
      Width = 45
      Height = 13
      Caption = 'Protocol :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object lblNFC_TD_TagDetected: TLabel
      Left = 36
      Top = 26
      Width = 52
      Height = 13
      Caption = 'Tag Type :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object stNFC_TD_CardType: TStaticText
      Left = 112
      Top = 56
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 0
    end
    object stNFC_TD_Uid: TStaticText
      Left = 112
      Top = 88
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 1
    end
    object stNFC_TD_AtqA: TStaticText
      Left = 112
      Top = 152
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 2
    end
    object stNFC_TD_AppData: TStaticText
      Left = 112
      Top = 184
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 3
    end
    object stNFC_TD_MaxDataRate: TStaticText
      Left = 112
      Top = 216
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 4
    end
    object stNFC_TD_Sak: TStaticText
      Left = 112
      Top = 120
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 5
    end
    object stNFC_TD_Protocol: TStaticText
      Left = 112
      Top = 240
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 6
      Visible = False
    end
    object stNFC_TD_TagType: TStaticText
      Left = 112
      Top = 24
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Color = clCaptionText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 7
    end
  end
  object sbNFC_TagDetected: TStatusBar
    Left = 0
    Top = 439
    Width = 305
    Height = 30
    Panels = <>
    SimplePanel = False
  end
  object btnNFC_TD_RdWr: TButton
    Left = 16
    Top = 320
    Width = 130
    Height = 25
    Caption = 'Read/Wrte'
    TabOrder = 2
    OnClick = btnNFC_TD_RdWrClick
  end
  object btnNFC_TD_RawCommand: TButton
    Left = 159
    Top = 320
    Width = 130
    Height = 25
    Caption = 'Raw Command'
    TabOrder = 3
    OnClick = btnNFC_TD_RawCommandClick
  end
  object btnNFC_TD_Disconnect: TButton
    Left = 16
    Top = 400
    Width = 273
    Height = 25
    Caption = 'Disconnect'
    TabOrder = 4
    OnClick = btnNFC_TD_DisconnectClick
  end
  object btnNFC_TD_FormatToNDEF: TButton
    Left = 16
    Top = 360
    Width = 273
    Height = 25
    Caption = 'Format To Be NDEF Compliant'
    TabOrder = 5
    OnClick = btnNFC_TD_FormatToNDEFClick
  end
end
