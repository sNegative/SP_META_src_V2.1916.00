object frmNFCNew: TfrmNFCNew
  Left = 343
  Top = 164
  Width = 950
  Height = 696
  Caption = 'NFC'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object tabNFC: TPageControl
    Left = 2
    Top = 0
    Width = 935
    Height = 657
    ActivePage = SWT
    MultiLine = True
    TabIndex = 10
    TabOrder = 0
    OnChange = tabNFCChange
    object tsRM: TTabSheet
      Caption = 'Always In Reader Mode'
      object GroupBox1: TGroupBox
        Left = 40
        Top = 32
        Width = 657
        Height = 433
        Caption = 'Reader Mode'
        TabOrder = 0
        object GroupBox12: TGroupBox
          Left = 40
          Top = 176
          Width = 265
          Height = 41
          TabOrder = 9
          object rb_AIRM_TypeF_212kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_AIRM_TypeF_424kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 1
          end
        end
        object GroupBox10: TGroupBox
          Left = 40
          Top = 48
          Width = 521
          Height = 41
          TabOrder = 7
          object rb_AIRM_TypeA_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_AIRM_TypeA_212kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object rb_AIRM_TypeA_424kbps: TRadioButton
            Left = 272
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object rb_AIRM_TypeA_848kbps: TRadioButton
            Left = 408
            Top = 16
            Width = 97
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
        object cb_AIRM_TypeA: TCheckBox
          Left = 24
          Top = 32
          Width = 97
          Height = 17
          Caption = 'Type A'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = cb_AIRM_TypeAClick
        end
        object cb_AIRM_TypeB: TCheckBox
          Left = 24
          Top = 96
          Width = 97
          Height = 17
          Caption = 'Type B'
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = cb_AIRM_TypeBClick
        end
        object cb_AIRM_TypeF: TCheckBox
          Left = 24
          Top = 160
          Width = 97
          Height = 17
          Caption = 'Type F'
          Checked = True
          State = cbChecked
          TabOrder = 2
          OnClick = cb_AIRM_TypeFClick
        end
        object cb_AIRM_TypeV: TCheckBox
          Left = 24
          Top = 224
          Width = 97
          Height = 17
          Caption = 'Type V'
          Checked = True
          State = cbChecked
          TabOrder = 3
          OnClick = cb_AIRM_TypeVClick
        end
        object cb_AIRM_TypeB_plus: TCheckBox
          Left = 24
          Top = 384
          Width = 97
          Height = 17
          Caption = 'Type B'#39
          TabOrder = 4
          Visible = False
        end
        object cb_AIRM_Kovio: TCheckBox
          Left = 24
          Top = 408
          Width = 97
          Height = 17
          Caption = 'Kovio'
          Checked = True
          State = cbChecked
          TabOrder = 5
        end
        object GroupBox2: TGroupBox
          Left = 40
          Top = 240
          Width = 497
          Height = 137
          TabOrder = 6
          object GroupBox45: TGroupBox
            Left = 8
            Top = 48
            Width = 337
            Height = 41
            TabOrder = 1
            object rb_AIRM_TypeV_CodingMode_256: TRadioButton
              Left = 168
              Top = 16
              Width = 161
              Height = 17
              Caption = 'CodingMode(1 out of 256)'
              TabOrder = 0
            end
            object rb_AIRM_TypeV_CodingMode_4: TRadioButton
              Left = 8
              Top = 16
              Width = 145
              Height = 17
              Caption = 'CodingMode(1 out of 4)'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
          end
          object GroupBox44: TGroupBox
            Left = 8
            Top = 8
            Width = 337
            Height = 41
            TabOrder = 0
            object rb_AIRM_TypeV_DualSubcarrie: TRadioButton
              Left = 168
              Top = 16
              Width = 113
              Height = 17
              Caption = 'dual subcarrier'
              TabOrder = 0
            end
            object rb_AIRM_TypeV_Subcarrier: TRadioButton
              Left = 8
              Top = 16
              Width = 113
              Height = 17
              Caption = 'subcarrier'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
          end
          object TGroupBox
            Left = 8
            Top = 88
            Width = 337
            Height = 41
            TabOrder = 2
            object rb_AIRM_TypeV_6_62kbps: TRadioButton
              Left = 8
              Top = 16
              Width = 153
              Height = 17
              Caption = '6.62 kbps'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object rb_AIRM_TypeV_26_48kbps: TRadioButton
              Left = 168
              Top = 16
              Width = 161
              Height = 17
              Caption = '26.48kbps'
              TabOrder = 1
            end
          end
        end
        object GroupBox11: TGroupBox
          Left = 40
          Top = 112
          Width = 521
          Height = 41
          TabOrder = 8
          object rb_AIRM_TypeB_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_AIRM_TypeB_212kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object rb_AIRM_TypeB_424kbps: TRadioButton
            Left = 272
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object rb_AIRM_TypeB_848kbps: TRadioButton
            Left = 408
            Top = 16
            Width = 105
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
      end
      object tb_AIRM_Start: TButton
        Left = 40
        Top = 496
        Width = 97
        Height = 33
        Caption = 'Start'
        TabOrder = 1
        OnClick = tb_AIRM_StartClick
      end
      object tb_AIRM_SelectAll: TButton
        Left = 760
        Top = 64
        Width = 97
        Height = 33
        Caption = 'Select All'
        TabOrder = 2
        OnClick = tb_AIRM_SelectAllClick
      end
      object tb_AIRM_ClearAll: TButton
        Left = 760
        Top = 136
        Width = 97
        Height = 33
        Caption = 'Clear All'
        TabOrder = 3
        OnClick = tb_AIRM_ClearAllClick
      end
    end
    object tsP2P: TTabSheet
      Caption = 'Always In Peer To Peer Mode'
      ImageIndex = 1
      object GroupBox3: TGroupBox
        Left = 32
        Top = 32
        Width = 705
        Height = 465
        Caption = 'P2P Mode'
        TabOrder = 0
        object tl_AIP2PM_Link_Status_up: TLabel
          Left = 24
          Top = 416
          Width = 91
          Height = 20
          Caption = 'p2p link is up'
          Color = clBtnHighlight
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clHighlight
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object tl_AIP2PM_Link_Status_down: TLabel
          Left = 136
          Top = 416
          Width = 111
          Height = 20
          Caption = 'p2p link is down'
          Color = clBtnHighlight
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clHighlight
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object GroupBox14: TGroupBox
          Left = 40
          Top = 120
          Width = 257
          Height = 41
          TabOrder = 4
          object rb_P2PM_TypeF_212kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_P2PM_TypeF_424kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 1
          end
        end
        object GroupBox13: TGroupBox
          Left = 40
          Top = 48
          Width = 521
          Height = 41
          TabOrder = 3
          object rb_P2PM_TypeA_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_P2PM_TypeA_212kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object rb_P2PM_TypeA_424kbps: TRadioButton
            Left = 264
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object rb_P2PM_TypeA_848kbps: TRadioButton
            Left = 400
            Top = 16
            Width = 97
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
        object GroupBox4: TGroupBox
          Left = 24
          Top = 184
          Width = 393
          Height = 209
          TabOrder = 2
          object GroupBox17: TGroupBox
            Left = 16
            Top = 144
            Width = 257
            Height = 41
            TabOrder = 0
            object cb_P2PM_DisableCardEmulation: TCheckBox
              Left = 8
              Top = 16
              Width = 137
              Height = 17
              Caption = 'Disable Card Emulation'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
          end
          object GroupBox9: TGroupBox
            Left = 16
            Top = 32
            Width = 257
            Height = 41
            TabOrder = 1
            object cb_P2PM_PassiveMode: TCheckBox
              Left = 8
              Top = 16
              Width = 89
              Height = 17
              Caption = 'passive mode'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object cb_P2PM_ActiveMode: TCheckBox
              Left = 136
              Top = 16
              Width = 97
              Height = 17
              Caption = 'active mode'
              Checked = True
              State = cbChecked
              TabOrder = 1
            end
          end
          object GroupBox15: TGroupBox
            Left = 16
            Top = 88
            Width = 257
            Height = 41
            TabOrder = 2
            object cb_P2PM_Initator: TCheckBox
              Left = 8
              Top = 8
              Width = 97
              Height = 29
              Caption = 'Initiator'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object cb_P2PM_Target: TCheckBox
              Left = 136
              Top = 16
              Width = 105
              Height = 17
              Caption = 'Target'
              Checked = True
              State = cbChecked
              TabOrder = 1
            end
          end
        end
        object cb_P2PM_TypeA: TCheckBox
          Left = 24
          Top = 32
          Width = 97
          Height = 17
          Caption = 'Type A'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = cb_P2PM_TypeAClick
        end
        object cb_P2PM_TypeF: TCheckBox
          Left = 24
          Top = 104
          Width = 97
          Height = 17
          Caption = 'Type F'
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = cb_P2PM_TypeFClick
        end
      end
      object tb_P2PM_Start: TButton
        Left = 40
        Top = 536
        Width = 97
        Height = 33
        Caption = 'Start'
        TabOrder = 1
        OnClick = tb_P2PM_StartClick
      end
      object tb_P2PM_ClearAll: TButton
        Left = 760
        Top = 136
        Width = 97
        Height = 33
        Caption = 'Clear All'
        TabOrder = 2
        OnClick = tb_P2PM_ClearAllClick
      end
      object tb_P2PM_SelectAll: TButton
        Left = 760
        Top = 64
        Width = 97
        Height = 33
        Caption = 'Select All'
        TabOrder = 3
        OnClick = tb_P2PM_SelectAllClick
      end
    end
    object tsCEM: TTabSheet
      Caption = 'Always In Card Emulation Mode'
      ImageIndex = 2
      object GroupBox5: TGroupBox
        Left = 40
        Top = 32
        Width = 649
        Height = 185
        Caption = 'Card Emulation Mode'
        TabOrder = 0
        object GroupBox6: TGroupBox
          Left = 40
          Top = 32
          Width = 513
          Height = 49
          TabOrder = 0
          object rb_AICEM_SWIO1: TRadioButton
            Left = 16
            Top = 16
            Width = 97
            Height = 25
            Caption = 'SWIO1'
            TabOrder = 0
            Visible = False
          end
          object rb_AICEM_SWIO2: TRadioButton
            Left = 144
            Top = 16
            Width = 97
            Height = 25
            Caption = 'SWIO2'
            TabOrder = 1
            Visible = False
          end
          object rb_AICEM_SWIOSE: TRadioButton
            Left = 264
            Top = 16
            Width = 81
            Height = 25
            Caption = 'SWIO_SE'
            TabOrder = 2
            Visible = False
          end
          object Button2: TButton
            Left = 384
            Top = 16
            Width = 105
            Height = 25
            Caption = 'Get SE'
            TabOrder = 3
            OnClick = tb_AICEM_SetSWIOClick
          end
        end
        object GroupBox7: TGroupBox
          Left = 40
          Top = 112
          Width = 513
          Height = 49
          TabOrder = 1
          object cb_AICEM_TypeA: TCheckBox
            Left = 16
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Type A'
            Checked = True
            State = cbChecked
            TabOrder = 0
          end
          object cb_AICEM_TypeB: TCheckBox
            Left = 144
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Type B'
            Checked = True
            State = cbChecked
            TabOrder = 1
          end
          object cb_AICEM_TypeB_plus: TCheckBox
            Left = 272
            Top = 16
            Width = 97
            Height = 17
            Caption = 'TypeB'#39
            Checked = True
            State = cbChecked
            TabOrder = 2
          end
          object cb_AICEM_TypeF: TCheckBox
            Left = 400
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Type F'
            Checked = True
            State = cbChecked
            TabOrder = 3
          end
        end
      end
      object tb_AICEM_Start: TButton
        Left = 88
        Top = 264
        Width = 97
        Height = 33
        Caption = 'Start'
        Enabled = False
        TabOrder = 1
        OnClick = tb_AICEM_StartClick
      end
      object tb_AICEM_ClearAll: TButton
        Left = 760
        Top = 136
        Width = 97
        Height = 33
        Caption = 'Clear All'
        TabOrder = 2
        OnClick = tb_AICEM_ClearAllClick
      end
      object tb_AICEM_SelectAll: TButton
        Left = 760
        Top = 64
        Width = 97
        Height = 33
        Caption = 'Select All'
        TabOrder = 3
        OnClick = tb_AICEM_SelectAllClick
      end
    end
    object TSPLM: TTabSheet
      Caption = 'Polling Loop Mode'
      ImageIndex = 3
      object Label1: TLabel
        Left = 280
        Top = 32
        Width = 53
        Height = 20
        Caption = 'Period :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 408
        Top = 32
        Width = 21
        Height = 20
        Caption = 'ms'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object rb_PLM_RM_6_62kbps: TGroupBox
        Left = 32
        Top = 112
        Width = 425
        Height = 457
        Caption = 'Reader Mode'
        TabOrder = 0
        object GroupBox18: TGroupBox
          Left = 40
          Top = 176
          Width = 265
          Height = 41
          TabOrder = 9
          object cb_PLM_RM_TypeF_212kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object cb_PLM_RM_TypeF_424kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 1
          end
        end
        object GroupBox19: TGroupBox
          Left = 40
          Top = 48
          Width = 361
          Height = 41
          TabOrder = 7
          object cb_PLM_RM_TypeA_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object cb_PLM_RM_TypeA_212kbps: TRadioButton
            Left = 88
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object cb_PLM_RM_TypeA_424kbps: TRadioButton
            Left = 176
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object cb_PLM_RM_TypeA_848kbps: TRadioButton
            Left = 272
            Top = 16
            Width = 73
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
        object cb_PLM_RM_TypeA: TCheckBox
          Left = 24
          Top = 32
          Width = 97
          Height = 17
          Caption = 'Type A'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = cb_PLM_RM_TypeAClick
        end
        object cb_PLM_RM_TypeB: TCheckBox
          Left = 24
          Top = 96
          Width = 97
          Height = 17
          Caption = 'Type B'
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = cb_PLM_RM_TypeBClick
        end
        object cb_PLM_RM_TypeF: TCheckBox
          Left = 24
          Top = 160
          Width = 97
          Height = 17
          Caption = 'Type F'
          Checked = True
          State = cbChecked
          TabOrder = 2
          OnClick = cb_PLM_RM_TypeFClick
        end
        object cb_PLM_RM_TypeV: TCheckBox
          Left = 24
          Top = 224
          Width = 97
          Height = 17
          Caption = 'Type V'
          Checked = True
          State = cbChecked
          TabOrder = 3
          OnClick = cb_PLM_RM_TypeVClick
        end
        object cb_PLM_RM_TypeB_plus: TCheckBox
          Left = 24
          Top = 384
          Width = 97
          Height = 17
          Caption = 'Type B'#39
          TabOrder = 4
          Visible = False
        end
        object cb_PLM_RM_Kovio: TCheckBox
          Left = 24
          Top = 408
          Width = 97
          Height = 17
          Caption = 'Kovio'
          Checked = True
          State = cbChecked
          TabOrder = 5
        end
        object GroupBox20: TGroupBox
          Left = 40
          Top = 240
          Width = 337
          Height = 137
          TabOrder = 6
          object GroupBox48: TGroupBox
            Left = 8
            Top = 88
            Width = 321
            Height = 41
            TabOrder = 2
            object cb_PLM_RM_6_62kbps: TRadioButton
              Left = 8
              Top = 16
              Width = 137
              Height = 17
              Caption = '6.62 kbps'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object cb_PLM_RM_26_48kbps: TRadioButton
              Left = 168
              Top = 16
              Width = 145
              Height = 17
              Caption = '26.48 kbps'
              TabOrder = 1
            end
          end
          object GroupBox47: TGroupBox
            Left = 8
            Top = 48
            Width = 321
            Height = 41
            TabOrder = 1
            object cb_PLM_RM_TypeV_CodingMode_4: TRadioButton
              Left = 8
              Top = 16
              Width = 145
              Height = 17
              Caption = 'CodingMode(1 out of 4)'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object cb_PLM_RM_TypeV_CodingMode_256: TRadioButton
              Left = 168
              Top = 16
              Width = 145
              Height = 17
              Caption = 'CodingMode(1 out of 256)'
              TabOrder = 1
            end
          end
          object GroupBox46: TGroupBox
            Left = 8
            Top = 8
            Width = 321
            Height = 41
            TabOrder = 0
            object cb_PLM_RM_TypeV_Subcarrier: TRadioButton
              Left = 8
              Top = 16
              Width = 113
              Height = 17
              Caption = 'subcarrier'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object cb_PLM_RM_TypeV_DualSubcarrier: TRadioButton
              Left = 168
              Top = 16
              Width = 113
              Height = 17
              Caption = 'dual subcarrier'
              TabOrder = 1
            end
          end
        end
        object GroupBox21: TGroupBox
          Left = 40
          Top = 112
          Width = 361
          Height = 41
          TabOrder = 8
          object cb_PLM_RM_TypeB_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object cb_PLM_RM_TypeB_212kbps: TRadioButton
            Left = 88
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object cb_PLM_RM_TypeB_424kbps: TRadioButton
            Left = 176
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object cb_PLM_RM_TypeB_848kbps: TRadioButton
            Left = 272
            Top = 16
            Width = 73
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
      end
      object cb_PLM_RM: TCheckBox
        Left = 32
        Top = 80
        Width = 97
        Height = 17
        Caption = 'Read Mode'
        Checked = True
        State = cbChecked
        TabOrder = 1
        OnClick = cb_PLM_RMClick
      end
      object cb_PLM_P2PM: TCheckBox
        Left = 152
        Top = 80
        Width = 97
        Height = 17
        Caption = 'P2P Mode'
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = cb_PLM_P2PMClick
      end
      object GroupBox22: TGroupBox
        Left = 520
        Top = 16
        Width = 401
        Height = 361
        Caption = 'P2P Mode'
        TabOrder = 3
        object cb_PLM_P2PM_LinkStatus_up: TLabel
          Left = 16
          Top = 325
          Width = 91
          Height = 20
          Caption = 'p2p link is up'
          Color = clBtnHighlight
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clHighlight
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object cb_PLM_P2PM_LinkStatus_down: TLabel
          Left = 120
          Top = 325
          Width = 111
          Height = 20
          Caption = 'p2p link is down'
          Color = clBtnHighlight
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clHighlight
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object GroupBox23: TGroupBox
          Left = 24
          Top = 96
          Width = 257
          Height = 41
          TabOrder = 4
          object rb_PLM_P2PM_TypeF_212kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_PLM_P2PM_TypeF_424kbps: TRadioButton
            Left = 136
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 1
          end
        end
        object GroupBox24: TGroupBox
          Left = 24
          Top = 32
          Width = 345
          Height = 41
          TabOrder = 3
          object rb_PLM_P2PM_TypeA_106kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = '106 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_PLM_P2PM_TypeA_212kbps: TRadioButton
            Left = 88
            Top = 16
            Width = 113
            Height = 17
            Caption = '212 kbps'
            TabOrder = 1
          end
          object rb_PLM_P2PM_TypeA_424kbps: TRadioButton
            Left = 176
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 2
          end
          object rb_PLM_P2PM_TypeA_848kbps: TRadioButton
            Left = 264
            Top = 16
            Width = 73
            Height = 17
            Caption = '848 kbps'
            TabOrder = 3
          end
        end
        object GroupBox25: TGroupBox
          Left = 16
          Top = 144
          Width = 297
          Height = 169
          TabOrder = 2
          object GroupBox26: TGroupBox
            Left = 8
            Top = 16
            Width = 257
            Height = 41
            TabOrder = 0
            object cb_PLM_P2PM_PassiveMode: TCheckBox
              Left = 8
              Top = 16
              Width = 97
              Height = 17
              Caption = 'Passive Mode'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object cb_PLM_P2PM_ActiveMode: TCheckBox
              Left = 136
              Top = 16
              Width = 89
              Height = 17
              Caption = 'Active Mode'
              Checked = True
              State = cbChecked
              TabOrder = 1
            end
          end
          object GroupBox27: TGroupBox
            Left = 8
            Top = 64
            Width = 257
            Height = 41
            TabOrder = 1
            object cb_PLM_P2PM_Initiator: TCheckBox
              Left = 8
              Top = 16
              Width = 89
              Height = 17
              Caption = 'Initiator'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object cb_PLM_P2PM_Target: TCheckBox
              Left = 136
              Top = 16
              Width = 97
              Height = 17
              Caption = 'Target'
              Checked = True
              State = cbChecked
              TabOrder = 1
            end
          end
          object GroupBox28: TGroupBox
            Left = 8
            Top = 112
            Width = 257
            Height = 41
            TabOrder = 2
            object cb_PLM_P2PM_DisableCardEmulation: TCheckBox
              Left = 8
              Top = 16
              Width = 137
              Height = 17
              Caption = 'Disable Card Emulation'
              TabOrder = 0
              Visible = False
            end
          end
        end
        object cb_PLM_P2PM_TypeA: TCheckBox
          Left = 16
          Top = 16
          Width = 97
          Height = 17
          Caption = 'Type A'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = cb_PLM_P2PM_TypeAClick
        end
        object cb_PLM_P2PM_TypeF: TCheckBox
          Left = 16
          Top = 80
          Width = 97
          Height = 17
          Caption = 'Type F'
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = cb_PLM_P2PM_TypeFClick
        end
      end
      object cb_PLM_CEM: TCheckBox
        Left = 280
        Top = 80
        Width = 129
        Height = 17
        Caption = 'Card Emulation Mode'
        Checked = True
        State = cbChecked
        TabOrder = 4
        OnClick = cb_PLM_CEMClick
      end
      object GroupBox29: TGroupBox
        Left = 520
        Top = 392
        Width = 401
        Height = 177
        Caption = 'Card Emulation Mode'
        TabOrder = 5
        object GroupBox30: TGroupBox
          Left = 40
          Top = 40
          Width = 297
          Height = 49
          TabOrder = 0
          object rb_PLM_CEM_SWIO1: TRadioButton
            Left = 16
            Top = 16
            Width = 65
            Height = 25
            Caption = 'SWIO1'
            TabOrder = 0
            Visible = False
          end
          object rb_PLM_CEM_SWIO2: TRadioButton
            Left = 88
            Top = 16
            Width = 65
            Height = 25
            Caption = 'SWIO2'
            TabOrder = 1
            Visible = False
          end
          object rb_PLM_CEM_SWIOSE: TRadioButton
            Left = 160
            Top = 16
            Width = 65
            Height = 25
            Caption = 'SWIOSE'
            TabOrder = 2
            Visible = False
          end
          object rb_PLM_CEM_SetSE: TButton
            Left = 232
            Top = 16
            Width = 57
            Height = 25
            Caption = 'Get SE'
            TabOrder = 3
            OnClick = rb_PLM_CEM_SetSEClick
          end
        end
        object GroupBox31: TGroupBox
          Left = 40
          Top = 104
          Width = 297
          Height = 49
          TabOrder = 1
          object cb_PLM_CEM_TypeA: TCheckBox
            Left = 16
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Type A'
            Checked = True
            State = cbChecked
            TabOrder = 0
          end
          object cb_PLM_CEM_TypeB: TCheckBox
            Left = 88
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Type B'
            Checked = True
            State = cbChecked
            TabOrder = 1
          end
          object cb_PLM_CEM_TypeB_plus: TCheckBox
            Left = 160
            Top = 16
            Width = 97
            Height = 17
            Caption = 'TypeB'#39
            Checked = True
            State = cbChecked
            TabOrder = 2
          end
          object cb_PLM_CEM_TypeF: TCheckBox
            Left = 224
            Top = 16
            Width = 65
            Height = 17
            Caption = 'Type F'
            Checked = True
            State = cbChecked
            TabOrder = 3
          end
        end
      end
      object rb_PLM_Listen: TRadioButton
        Left = 32
        Top = 24
        Width = 121
        Height = 33
        Caption = 'Listen'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        TabStop = True
      end
      object rb_PLM_Pause: TRadioButton
        Left = 152
        Top = 24
        Width = 89
        Height = 33
        Caption = 'Pause'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
      end
      object te_PLM_Period: TEdit
        Left = 344
        Top = 32
        Width = 65
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ParentFont = False
        TabOrder = 8
        Text = '500'
      end
      object tb_PLM_Start: TButton
        Left = 32
        Top = 584
        Width = 97
        Height = 25
        Caption = 'Start'
        Enabled = False
        TabOrder = 9
        OnClick = tb_PLM_StartClick
      end
      object tb_PLM_SelectAll: TButton
        Left = 192
        Top = 584
        Width = 97
        Height = 25
        Caption = 'Select All'
        TabOrder = 10
        OnClick = tb_PLM_SelectAllClick
      end
      object tb_PLM_ClearAll: TButton
        Left = 352
        Top = 584
        Width = 89
        Height = 25
        Caption = 'Clear All'
        TabOrder = 11
        OnClick = tb_PLM_ClearAllClick
      end
    end
    object TSTXCSAO: TTabSheet
      Caption = 'TX Carrier Signal Always On'
      ImageIndex = 4
      object tb_TXCSAO_Start: TButton
        Left = 72
        Top = 40
        Width = 113
        Height = 41
        Caption = 'Start'
        TabOrder = 0
        OnClick = tb_TXCSAO_StartClick
      end
    end
    object TSVCF: TTabSheet
      Caption = 'Virtual Card Function'
      ImageIndex = 5
      object GroupBox33: TGroupBox
        Left = 40
        Top = 32
        Width = 441
        Height = 225
        Caption = 'Virtual Card Function'
        TabOrder = 0
        object cb_VCF_TypeA: TCheckBox
          Left = 24
          Top = 24
          Width = 97
          Height = 33
          Caption = 'Type A'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object cb_VCF_TypeB: TCheckBox
          Left = 24
          Top = 80
          Width = 97
          Height = 33
          Caption = 'Type B'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object cb_VCF_TypeF: TCheckBox
          Left = 24
          Top = 136
          Width = 97
          Height = 33
          Caption = 'Type F'
          Checked = True
          State = cbChecked
          TabOrder = 2
          OnClick = cb_VCF_TypeFClick
        end
        object GroupBox34: TGroupBox
          Left = 104
          Top = 128
          Width = 273
          Height = 41
          TabOrder = 3
          object rb_VCF_TypeF_212kbps: TRadioButton
            Left = 8
            Top = 16
            Width = 105
            Height = 17
            Caption = '212 kbps'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rb_VCF_TypeF_424kbps: TRadioButton
            Left = 144
            Top = 16
            Width = 113
            Height = 17
            Caption = '424 kbps'
            TabOrder = 1
          end
        end
        object cb_VCF_TypeB_plus: TCheckBox
          Left = 23
          Top = 189
          Width = 97
          Height = 33
          Caption = 'Type B'#39
          Checked = True
          State = cbChecked
          TabOrder = 4
          OnClick = cb_VCF_TypeFClick
        end
      end
      object tb_VCF_Start: TButton
        Left = 72
        Top = 272
        Width = 97
        Height = 33
        Caption = 'Start'
        TabOrder = 1
        OnClick = tb_VCF_StartClick
      end
      object tb_SelectAll: TButton
        Left = 528
        Top = 64
        Width = 97
        Height = 33
        Caption = 'Select All'
        TabOrder = 2
        OnClick = tb_SelectAllClick
      end
      object tb_ClearAll: TButton
        Left = 528
        Top = 136
        Width = 97
        Height = 33
        Caption = 'Clear All'
        TabOrder = 3
        OnClick = tb_ClearAllClick
      end
    end
    object TSPNFC: TTabSheet
      Caption = 'PNFC Command'
      ImageIndex = 6
      object GroupBox35: TGroupBox
        Left = 64
        Top = 32
        Width = 425
        Height = 297
        Caption = 'PNFC Command'
        TabOrder = 0
        object Label3: TLabel
          Left = 24
          Top = 32
          Width = 34
          Height = 13
          Caption = '$PNFC'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label4: TLabel
          Left = 24
          Top = 64
          Width = 94
          Height = 13
          Caption = 'Receiving Message'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object te_PNFC_Command: TEdit
          Left = 64
          Top = 24
          Width = 201
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ParentFont = False
          TabOrder = 0
        end
        object tre_PNFC_ReceivingMessage: TRichEdit
          Left = 24
          Top = 88
          Width = 369
          Height = 145
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          MaxLength = 2048
          ParentFont = False
          TabOrder = 1
        end
        object tb_PNFC_Start: TButton
          Left = 304
          Top = 24
          Width = 81
          Height = 25
          Caption = 'Send'
          TabOrder = 2
          OnClick = tb_PNFC_StartClick
        end
        object tb_PNFC_Clean: TButton
          Left = 272
          Top = 248
          Width = 105
          Height = 25
          Caption = 'Clean'
          TabOrder = 3
          OnClick = tb_PNFC_CleanClick
        end
      end
    end
    object TSVQ: TTabSheet
      Caption = 'Version Query'
      ImageIndex = 7
      object GroupBox36: TGroupBox
        Left = 80
        Top = 40
        Width = 417
        Height = 241
        Caption = 'Version Query'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object Label5: TLabel
          Left = 24
          Top = 112
          Width = 84
          Height = 13
          BiDiMode = bdRightToLeft
          Caption = 'NFC MW version:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
        end
        object Label6: TLabel
          Left = 24
          Top = 152
          Width = 81
          Height = 13
          BiDiMode = bdRightToLeft
          Caption = 'NFC FW version:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
        end
        object Label7: TLabel
          Left = 24
          Top = 192
          Width = 83
          Height = 13
          BiDiMode = bdRightToLeft
          Caption = 'NFC HW version:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
        end
        object te_VQ_NFC_MW_Version: TEdit
          Left = 120
          Top = 104
          Width = 177
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
        end
        object te_VQ_NFC_FW_Version: TEdit
          Left = 120
          Top = 144
          Width = 177
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object te_VQ_NFC_HW_Version: TEdit
          Left = 120
          Top = 184
          Width = 177
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
        end
        object tb_VQ_Query: TButton
          Left = 40
          Top = 32
          Width = 89
          Height = 33
          Caption = 'Query'
          TabOrder = 3
          OnClick = tb_VQ_QueryClick
        end
      end
    end
    object TSOption: TTabSheet
      Caption = 'Option'
      ImageIndex = 8
      object GroupBox37: TGroupBox
        Left = 48
        Top = 40
        Width = 361
        Height = 129
        Caption = 'Option'
        TabOrder = 0
        object cb_Option_EnableForceDownload: TCheckBox
          Left = 32
          Top = 32
          Width = 153
          Height = 17
          Caption = 'Enable Force Download'
          TabOrder = 0
        end
        object cb_Option_EnableAutoCheckPresence: TCheckBox
          Left = 32
          Top = 72
          Width = 185
          Height = 17
          Caption = 'Enable AutoCheckPresence'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object tb_Option_Set: TButton
          Left = 216
          Top = 48
          Width = 89
          Height = 25
          Caption = 'Set'
          TabOrder = 2
          OnClick = tb_Option_SetClick
        end
      end
    end
    object TSLoopback: TTabSheet
      Caption = 'Loopback'
      ImageIndex = 10
      object tl_Loopback_test: TLabel
        Left = 40
        Top = 24
        Width = 117
        Height = 16
        Caption = 'Loop-Back testing...'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        Visible = False
      end
      object tb_Loopback_Start_Stop: TButton
        Left = 56
        Top = 72
        Width = 113
        Height = 33
        Caption = 'Start'
        TabOrder = 0
        OnClick = tb_Loopback_Start_StopClick
      end
    end
    object SWT: TTabSheet
      Caption = 'SWP Test'
      ImageIndex = 11
      object tb_SWPTest_Start_Stop: TButton
        Left = 24
        Top = 96
        Width = 105
        Height = 33
        Caption = 'Start'
        TabOrder = 0
        OnClick = tb_SWPTest_Start_StopClick
      end
      object TGroupBox
        Left = 24
        Top = 16
        Width = 321
        Height = 49
        TabOrder = 1
        object Label8: TLabel
          Left = 16
          Top = 16
          Width = 63
          Height = 13
          Caption = 'Test All SWP'
        end
        object cb_SWPT_SWIO1: TCheckBox
          Left = 8
          Top = 16
          Width = 73
          Height = 25
          Caption = 'SWIO1'
          Checked = True
          State = cbChecked
          TabOrder = 0
          Visible = False
          OnClick = cb_SWPT_SWIO1Click
        end
        object cb_SWPT_SWIO2: TCheckBox
          Left = 112
          Top = 16
          Width = 89
          Height = 23
          Caption = 'SWIO2'
          Checked = True
          State = cbChecked
          TabOrder = 1
          Visible = False
          OnClick = cb_SWPT_SWIO2Click
        end
        object cb_SWPT_SWIOSE: TCheckBox
          Left = 216
          Top = 16
          Width = 89
          Height = 23
          Caption = 'SWIO_SE'
          Checked = True
          State = cbChecked
          TabOrder = 2
          Visible = False
          OnClick = cb_SWPT_SWIOSEClick
        end
      end
    end
  end
end
