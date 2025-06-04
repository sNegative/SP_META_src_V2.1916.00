object frmNFCRawCommand: TfrmNFCRawCommand
  Left = 592
  Top = 269
  Width = 400
  Height = 246
  Caption = 'Raw Command'
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
  object lblNFC_TD_RC_Datas: TLabel
    Left = 16
    Top = 16
    Width = 59
    Height = 13
    Caption = 'Datas(Hex) :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object sbNFC_RawCommand: TStatusBar
    Left = 0
    Top = 182
    Width = 392
    Height = 30
    Panels = <>
    SimplePanel = False
  end
  object mmNFC_TD_RC: TMemo
    Left = 16
    Top = 40
    Width = 361
    Height = 89
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object btnNFC_Write: TButton
    Left = 280
    Top = 144
    Width = 97
    Height = 25
    Caption = 'Write'
    TabOrder = 2
    OnClick = btnNFC_WriteClick
  end
end
