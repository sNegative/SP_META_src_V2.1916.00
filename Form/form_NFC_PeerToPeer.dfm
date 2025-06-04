object frmNFCPeerToPeer: TfrmNFCPeerToPeer
  Left = 450
  Top = 253
  Width = 402
  Height = 470
  Caption = 'Peer To Peer'
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
  object gbNFC_P2P_Info: TGroupBox
    Left = 16
    Top = 16
    Width = 233
    Height = 57
    Caption = 'Protocol Detected'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object lblNFC_P2P_Type: TLabel
      Left = 16
      Top = 24
      Width = 53
      Height = 13
      Caption = 'P2P Type :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object StaticText2: TStaticText
      Left = 80
      Top = 24
      Width = 137
      Height = 17
      Alignment = taCenter
      AutoSize = False
      BorderStyle = sbsSingle
      Caption = 'P2P Target'
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
  end
  object gbNFCP2PText: TGroupBox
    Left = 16
    Top = 88
    Width = 345
    Height = 265
    Caption = 'Data'
    TabOrder = 1
    object mmNFCP2PText: TMemo
      Left = 16
      Top = 24
      Width = 313
      Height = 185
      Enabled = False
      Lines.Strings = (
        '')
      ScrollBars = ssVertical
      TabOrder = 0
    end
    object btnNFC_P2P_Send: TButton
      Left = 34
      Top = 224
      Width = 125
      Height = 25
      Caption = 'Send'
      Enabled = False
      TabOrder = 1
      OnClick = btnNFC_P2P_SendClick
    end
    object btnNFC_P2P_Recieve: TButton
      Left = 178
      Top = 224
      Width = 125
      Height = 25
      Caption = 'Recieve'
      Enabled = False
      TabOrder = 2
      OnClick = btnNFC_P2P_RecieveClick
    end
  end
  object btnNFC_P2P_Disconnect: TButton
    Left = 52
    Top = 368
    Width = 273
    Height = 25
    Caption = 'Disconnect'
    Enabled = False
    TabOrder = 2
    OnClick = btnNFC_P2P_DisconnectClick
  end
  object sbNFC_PeerToPeer: TStatusBar
    Left = 0
    Top = 406
    Width = 394
    Height = 30
    Panels = <>
    SimplePanel = False
  end
end
