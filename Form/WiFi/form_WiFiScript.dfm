object frmWiFiScript: TfrmWiFiScript
  Left = 191
  Top = 167
  Width = 696
  Height = 480
  Caption = 'WiFi script test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 673
    Height = 105
    Caption = '  WiFi script  '
    TabOrder = 0
    object BitBtn1: TBitBtn
      Left = 8
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Script file'
      TabOrder = 0
    end
    object StaticText1: TStaticText
      Left = 112
      Top = 16
      Width = 537
      Height = 17
      AutoSize = False
      BorderStyle = sbsSunken
      Color = clSkyBlue
      ParentColor = False
      TabOrder = 1
    end
    object btnStart: TBitBtn
      Left = 552
      Top = 40
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 2
      Kind = bkRetry
    end
    object btnStop: TBitBtn
      Left = 552
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Stop'
      TabOrder = 3
      Kind = bkNo
    end
  end
  object memResult: TMemo
    Left = 8
    Top = 128
    Width = 673
    Height = 273
    Lines.Strings = (
      '')
    TabOrder = 1
  end
  object stWST: TStatusBar
    Left = 0
    Top = 424
    Width = 688
    Height = 29
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object dlgOpenScriptFile: TOpenDialog
    DefaultExt = 'ws'
    Filter = 'WiFi script file (*.ws)|*.ws|All files (*.*)|*.*'
    InitialDir = '.'
    Title = 'Open WiFi script file'
    Left = 576
  end
end
