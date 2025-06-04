object frmRatConfig: TfrmRatConfig
  Left = 594
  Top = 101
  Width = 597
  Height = 480
  Caption = 'Radio Access Technology'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBoxRATConfig: TGroupBox
    Left = 16
    Top = 16
    Width = 449
    Height = 321
    Caption = 'RAT Configuration'
    TabOrder = 0
    object LabelCurRAT: TLabel
      Left = 24
      Top = 24
      Width = 40
      Height = 13
      Caption = 'Current: '
      Visible = False
    end
  end
  object BtnUpdate: TButton
    Left = 488
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Update'
    TabOrder = 1
    OnClick = BtnUpdateClick
  end
  object m_sbRATStatus: TStatusBar
    Left = 0
    Top = 417
    Width = 581
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
end
