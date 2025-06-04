object frmNFCTagAccessType1: TfrmNFCTagAccessType1
  Left = 594
  Top = 333
  Width = 198
  Height = 257
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
  object lblNFC_TD_RdTag_Type2_Byte0: TLabel
    Left = 29
    Top = 88
    Width = 6
    Height = 13
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lblNFC_TD_RdTag_Type2_Byte1: TLabel
    Left = 69
    Top = 88
    Width = 6
    Height = 13
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lblNFC_TD_RdTag_Type2_Byte2: TLabel
    Left = 109
    Top = 88
    Width = 6
    Height = 13
    Caption = '2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lblNFC_TD_RdTag_Type2_Byte3: TLabel
    Left = 149
    Top = 88
    Width = 6
    Height = 13
    Caption = '3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object edtNFC_Datas: TLabel
    Left = 16
    Top = 56
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
  object lblNFC_PageAddress: TLabel
    Left = 16
    Top = 20
    Width = 72
    Height = 13
    Caption = 'Page Address :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object btnNFC_Write: TButton
    Left = 96
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Write'
    TabOrder = 0
    OnClick = btnNFC_WriteClick
  end
  object sbNFC_TagAccess: TStatusBar
    Left = 0
    Top = 193
    Width = 190
    Height = 30
    Panels = <>
    SimplePanel = False
  end
  object edtNFC_Byte0: TEdit
    Left = 16
    Top = 104
    Width = 33
    Height = 21
    MaxLength = 2
    TabOrder = 2
    Text = '00'
  end
  object edtNFC_Byte1: TEdit
    Left = 56
    Top = 104
    Width = 33
    Height = 21
    MaxLength = 2
    TabOrder = 3
    Text = '00'
  end
  object edtNFC_Byte2: TEdit
    Left = 96
    Top = 104
    Width = 33
    Height = 21
    MaxLength = 2
    TabOrder = 4
    Text = '00'
  end
  object edtNFC_Byte3: TEdit
    Left = 136
    Top = 104
    Width = 33
    Height = 21
    MaxLength = 2
    TabOrder = 5
    Text = '00'
  end
  object cbNFC_PageAddress: TComboBox
    Left = 104
    Top = 16
    Width = 65
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ItemIndex = 0
    ParentFont = False
    TabOrder = 6
    Text = '0'
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15')
  end
  object btnNFC_Read: TButton
    Left = 16
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Read'
    TabOrder = 7
    OnClick = btnNFC_ReadClick
  end
end
