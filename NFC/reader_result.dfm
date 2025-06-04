object frm_tag_operation: Tfrm_tag_operation
  Left = 370
  Top = 164
  Width = 259
  Height = 303
  Caption = 'tag_operation'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object nfc_reader_uid: TLabel
    Left = 40
    Top = 16
    Width = 26
    Height = 16
    Caption = 'UID:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object read_result_read: TButton
    Left = 40
    Top = 80
    Width = 169
    Height = 33
    Caption = 'Read'
    TabOrder = 0
  end
  object Read_result_write: TButton
    Left = 40
    Top = 144
    Width = 169
    Height = 33
    Caption = 'Write'
    TabOrder = 1
  end
  object read_result_format: TButton
    Left = 40
    Top = 200
    Width = 169
    Height = 33
    Caption = 'Format to NDEF'
    TabOrder = 2
  end
end
