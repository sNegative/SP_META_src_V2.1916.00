object OKRightDlg: TOKRightDlg
  Left = 407
  Top = 188
  BorderStyle = bsDialog
  Caption = 'Dialog'
  ClientHeight = 609
  ClientWidth = 722
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 713
    Height = 601
    Shape = bsFrame
  end
  object Label13: TLabel
    Left = 152
    Top = 320
    Width = 73
    Height = 13
    Caption = 'Payload length:'
  end
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 697
    Height = 593
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 24
      Width = 29
      Height = 16
      Caption = 'UID: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 72
      Top = 16
      Width = 3
      Height = 13
    end
    object Label3: TLabel
      Left = 64
      Top = 24
      Width = 70
      Height = 16
      Caption = '0000000000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object tb_AIRM_NTF_Read: TButton
      Left = 32
      Top = 64
      Width = 89
      Height = 33
      Caption = 'Read'
      TabOrder = 0
    end
    object tb_AIRM_NTF_Write: TButton
      Left = 32
      Top = 368
      Width = 89
      Height = 33
      Caption = 'Write'
      TabOrder = 1
    end
    object GroupBox1: TGroupBox
      Left = 128
      Top = 64
      Width = 353
      Height = 297
      TabOrder = 2
      object Label4: TLabel
        Left = 8
        Top = 8
        Width = 80
        Height = 13
        Caption = 'Read NEDF Tag'
      end
      object Label5: TLabel
        Left = 8
        Top = 32
        Width = 80
        Height = 13
        Caption = 'Read NEDF Tag'
      end
      object Label6: TLabel
        Left = 200
        Top = 32
        Width = 46
        Height = 13
        Caption = 'Tag Type'
      end
      object Label7: TLabel
        Left = 8
        Top = 56
        Width = 58
        Height = 13
        Caption = 'Record flag:'
      end
      object Label8: TLabel
        Left = 8
        Top = 88
        Width = 52
        Height = 13
        Caption = 'Record ID:'
      end
      object Label9: TLabel
        Left = 8
        Top = 120
        Width = 59
        Height = 13
        Caption = 'Record Info:'
      end
      object Label10: TLabel
        Left = 8
        Top = 152
        Width = 73
        Height = 13
        Caption = 'Payload length:'
      end
      object Label11: TLabel
        Left = 8
        Top = 184
        Width = 41
        Height = 13
        Caption = 'Payload:'
      end
      object Label12: TLabel
        Left = 8
        Top = 208
        Width = 25
        Height = 13
        Caption = 'HEX:'
      end
      object Label14: TLabel
        Left = 8
        Top = 240
        Width = 30
        Height = 13
        Caption = 'ASCII:'
      end
      object Label15: TLabel
        Left = 256
        Top = 80
        Width = 24
        Height = 14
        Caption = 'Lang'
      end
      object Edit1: TEdit
        Left = 88
        Top = 56
        Width = 97
        Height = 21
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 88
        Top = 88
        Width = 97
        Height = 21
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 88
        Top = 120
        Width = 97
        Height = 21
        TabOrder = 2
      end
      object Edit4: TEdit
        Left = 88
        Top = 152
        Width = 97
        Height = 21
        TabOrder = 3
      end
      object Edit5: TEdit
        Left = 40
        Top = 208
        Width = 297
        Height = 21
        TabOrder = 4
      end
      object CheckBox1: TCheckBox
        Left = 208
        Top = 56
        Width = 89
        Height = 17
        Caption = 'URI'
        TabOrder = 5
      end
      object CheckBox2: TCheckBox
        Left = 208
        Top = 80
        Width = 41
        Height = 17
        Caption = 'Text'
        TabOrder = 6
      end
      object CheckBox3: TCheckBox
        Left = 208
        Top = 104
        Width = 89
        Height = 17
        Caption = 'Smart Poster'
        TabOrder = 7
      end
      object Edit7: TEdit
        Left = 288
        Top = 80
        Width = 57
        Height = 21
        TabOrder = 8
      end
    end
    object GroupBox2: TGroupBox
      Left = 144
      Top = 400
      Width = 337
      Height = 161
      TabOrder = 3
      object Label16: TLabel
        Left = 8
        Top = 8
        Width = 79
        Height = 13
        Caption = 'Write NEDF Tag'
      end
      object Label18: TLabel
        Left = 24
        Top = 32
        Width = 78
        Height = 13
        Caption = 'NEDF Tag Type'
      end
      object Label17: TLabel
        Left = 16
        Top = 116
        Width = 83
        Height = 13
        Caption = 'URL:http://www.'
      end
      object RadioButton1: TRadioButton
        Left = 24
        Top = 56
        Width = 105
        Height = 25
        Caption = 'URI'
        TabOrder = 0
      end
      object RadioButton2: TRadioButton
        Left = 24
        Top = 80
        Width = 105
        Height = 25
        Caption = 'Text'
        TabOrder = 1
      end
      object Edit8: TEdit
        Left = 104
        Top = 116
        Width = 209
        Height = 21
        TabOrder = 2
      end
    end
    object Button1: TButton
      Left = 560
      Top = 336
      Width = 89
      Height = 33
      Caption = 'ok'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
  end
  object Edit6: TEdit
    Left = 184
    Top = 320
    Width = 297
    Height = 21
    TabOrder = 1
  end
end
