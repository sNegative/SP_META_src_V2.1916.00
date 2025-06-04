object frmMetaConnectTime: TfrmMetaConnectTime
  Left = 464
  Top = 373
  Width = 817
  Height = 520
  Caption = 'Meta Connect Time'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnLoadBootprof: TButton
    Left = 32
    Top = 48
    Width = 193
    Height = 41
    Caption = 'Save Bootprof to PC'
    TabOrder = 0
    OnClick = btnLoadBootprofClick
  end
  object sdBootprof: TSaveDialog
    Left = 576
    Top = 272
  end
end
