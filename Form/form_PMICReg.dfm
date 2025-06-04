object frmPMICReg: TfrmPMICReg
  Left = 364
  Top = 241
  Width = 746
  Height = 489
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object sbPMICReg: TStatusBar
    Left = 0
    Top = 426
    Width = 738
    Height = 29
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object lblHint: TStaticText
    Left = 344
    Top = 32
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 1
    Visible = False
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 384
    Top = 24
  end
end
