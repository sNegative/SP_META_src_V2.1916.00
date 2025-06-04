object frmNFCTagAccessType3: TfrmNFCTagAccessType3
  Left = 555
  Top = 264
  Width = 418
  Height = 492
  Caption = 'Tag Access'
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
  object sbNFC_TagAccess: TStatusBar
    Left = 0
    Top = 428
    Width = 410
    Height = 30
    Panels = <>
    SimplePanel = False
  end
  object gbNFC_Info: TGroupBox
    Left = 16
    Top = 16
    Width = 377
    Height = 249
    Caption = 'Info'
    TabOrder = 1
    object lblNFC_TD_RdTag_RecFlags: TLabel
      Left = 27
      Top = 24
      Width = 69
      Height = 13
      Caption = 'Record Flags :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 211
      Top = 24
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
    object Label2: TLabel
      Left = 233
      Top = 58
      Width = 30
      Height = 13
      Caption = 'Lang :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_RecId: TLabel
      Left = 41
      Top = 56
      Width = 55
      Height = 13
      Caption = 'Record ID :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_RecTnf: TLabel
      Left = 36
      Top = 88
      Width = 60
      Height = 13
      Caption = 'Record Tnf :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_PayLoadLen: TLabel
      Left = 16
      Top = 120
      Width = 80
      Height = 13
      Caption = 'Payload Length :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_PayLoad: TLabel
      Left = 16
      Top = 168
      Width = 44
      Height = 13
      Caption = 'Payload :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_Hex: TLabel
      Left = 35
      Top = 192
      Width = 25
      Height = 13
      Caption = 'Hex :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblNFC_TD_RdTag_ACSII: TLabel
      Left = 27
      Top = 216
      Width = 33
      Height = 13
      Caption = 'ASCII :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object stNFC_TD_RdTag_RecFlags: TStaticText
      Left = 112
      Top = 22
      Width = 73
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
    object stNFC_TD_RdTag_TagType: TStaticText
      Left = 280
      Top = 22
      Width = 73
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
    object stNFC_TD_RdTag_Lang: TStaticText
      Left = 280
      Top = 56
      Width = 73
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
    object stNFC_TD_RdTag_RecId: TStaticText
      Left = 112
      Top = 54
      Width = 73
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
    object stNFC_TD_RdTag_RecTnf: TStaticText
      Left = 112
      Top = 86
      Width = 73
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
    object stNFC_TD_RdTag_PayLoadLen: TStaticText
      Left = 112
      Top = 118
      Width = 73
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
    object stNFC_TD_RdTag_Hex: TStaticText
      Left = 72
      Top = 190
      Width = 281
      Height = 17
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
    end
    object stNFC_TD_RdTag_ACSII: TStaticText
      Left = 72
      Top = 214
      Width = 281
      Height = 17
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
  object gbNFC_Outpot: TGroupBox
    Left = 16
    Top = 280
    Width = 377
    Height = 137
    Caption = 'Input'
    TabOrder = 2
    object mmNFC_TD_WrTag: TMemo
      Left = 16
      Top = 24
      Width = 345
      Height = 57
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object btnNFC_Write: TButton
      Left = 264
      Top = 96
      Width = 97
      Height = 25
      Caption = 'Write'
      TabOrder = 1
      OnClick = btnNFC_WriteClick
    end
  end
end
