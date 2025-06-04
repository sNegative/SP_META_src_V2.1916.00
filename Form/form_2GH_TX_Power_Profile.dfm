object frm2GH_TX_Power_Profile: Tfrm2GH_TX_Power_Profile
  Left = 499
  Top = 145
  Width = 515
  Height = 862
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = '2GHz_TX_Power_Profile'
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 152
    Width = 481
    Height = 169
    Caption = 'TX Power Compensation Over Channels'
    TabOrder = 1
    object m_cb2GH_TX_Power_Compensation: TComboBox
      Left = 8
      Top = 20
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_lv2GH_TX_Power_Compensation: TListView
      Left = 8
      Top = 48
      Width = 465
      Height = 73
      Columns = <
        item
          Caption = 'Channels'
          Width = 150
        end
        item
          Caption = 'TX Power Offset (-4~+4dB, step 0.5)'
          Width = 200
        end>
      Items.Data = {
        770000000300000000000000FFFFFFFFFFFFFFFF010000000000000009436831
        2C322C332C34013000000000FFFFFFFFFFFFFFFF010000000000000009436835
        2C362C372C38013000000000FFFFFFFFFFFFFFFF010000000000000012436839
        2C31302C31312C31322C31332C31340130FFFFFFFFFFFF}
      ReadOnly = True
      RowSelect = True
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lv2GH_TX_Power_CompensationAdvancedCustomDrawSubItem
      OnClick = m_lv2GH_TX_Power_CompensationClick
    end
    object m_cb2GH_TX_Power_Compensation_Edit: TComboBox
      Left = 365
      Top = 92
      Width = 97
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      TabOrder = 2
      Visible = False
      OnExit = m_cb2GH_TX_Power_Compensation_EditChange
      Items.Strings = (
        '-4'
        '-3.5'
        '-3'
        '-2.5'
        '-2'
        '-1.5'
        '-1'
        '-0.5'
        '0'
        '0.5'
        '1'
        '1.5'
        '2'
        '2.5'
        '3'
        '3.5'
        '4')
    end
    object m_tc2GH_TX_Power_Compensation: TTabControl
      Left = 0
      Top = 16
      Width = 473
      Height = 153
      TabOrder = 3
      Tabs.Strings = (
        'WF0'
        'WF1')
      TabIndex = 0
      Visible = False
      OnChange = m_tc2GH_TX_Power_CompensationChange
      object m_lvTXPowerCom: TListView
        Left = 0
        Top = 48
        Width = 473
        Height = 105
        Columns = <
          item
            Caption = 'Channels'
            Width = 100
          end
          item
            Caption = 'TX Power Offset (-3.5~+3.5dB, step 0.5)'
            Width = 250
          end
          item
            Caption = 'Enable(1)Disable(0)'
            Width = 125
          end>
        FlatScrollBars = True
        Items.Data = {
          CD0100000E00000000000000FFFFFFFFFFFFFFFF020000000000000003436831
          0130013000000000FFFFFFFFFFFFFFFF02000000000000000343683201300130
          00000000FFFFFFFFFFFFFFFF0200000000000000034368330130013000000000
          FFFFFFFFFFFFFFFF0200000000000000034368340130013000000000FFFFFFFF
          FFFFFFFF0200000000000000034368350130013000000000FFFFFFFFFFFFFFFF
          0200000000000000034368360130013000000000FFFFFFFFFFFFFFFF02000000
          00000000034368370130013000000000FFFFFFFFFFFFFFFF0200000000000000
          034368380130013000000000FFFFFFFFFFFFFFFF020000000000000003436839
          0130013000000000FFFFFFFFFFFFFFFF02000000000000000443683130013001
          3000000000FFFFFFFFFFFFFFFF02000000000000000443683131013001300000
          0000FFFFFFFFFFFFFFFF020000000000000004436831320130013000000000FF
          FFFFFFFFFFFFFF020000000000000004436831330130013000000000FFFFFFFF
          FFFFFFFF0200000000000000044368313401300130FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        Visible = False
        OnAdvancedCustomDrawSubItem = m_lv2GH_TX_Power_CompensationAdvancedCustomDrawSubItem
        OnClick = m_lvTXPowerComClick
      end
      object m_cbEnable: TComboBox
        Left = 0
        Top = 28
        Width = 90
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 1
        Text = 'Enable'
        Visible = False
        Items.Strings = (
          'Enable'
          'Disable')
      end
      object m_cb_2GHTXPowerCompEdit: TComboBox
        Left = 365
        Top = 84
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 2
        Visible = False
        OnExit = m_cb_2GHTXPowerCompEditChange
        Items.Strings = (
          '-3.5'
          '-3'
          '-2.5'
          '-2'
          '-1.5'
          '-1'
          '-0.5'
          '0'
          '0.5'
          '1'
          '1.5'
          '2'
          '2.5'
          '3'
          '3.5')
      end
      object m_cb_2GH_EnableEdit: TComboBox
        Left = 365
        Top = 108
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 3
        Visible = False
        OnExit = m_cb_2GH_EnableEditChange
        Items.Strings = (
          '0'
          '1')
      end
      object m_btnWriteToNvram_MT6632: TButton
        Left = 128
        Top = 24
        Width = 89
        Height = 25
        Caption = 'Write to Nvram'
        TabOrder = 4
        Visible = False
        OnClick = m_btnWriteToNvram_MT6632Click
      end
    end
  end
  object m_lv2GH_TX_Power_Register: TListView
    Left = 8
    Top = 8
    Width = 481
    Height = 145
    Columns = <
      item
        Caption = 'Register Name'
        Width = 150
      end
      item
        Caption = 'Data Rate '
        Width = 150
      end
      item
        Caption = 'Target Power at Chipout (dBm)'
        Width = 170
      end>
    Items.Data = {
      1C0400001200000000000000FFFFFFFFFFFFFFFF02000000000000000C635478
      50777232473443636B1443434B20314D2C20324D2C352E354D2C2031314D0232
      3000000000FFFFFFFFFFFFFFFF0200000000000000126354585077723247344F
      46444D5F4250534B0B4F46444D20364D2C20394D02313800000000FFFFFFFFFF
      FFFFFF0200000000000000126354585077723247344F46444D5F5150534B0D4F
      46444D2031324D2C2031384D02313800000000FFFFFFFFFFFFFFFF0200000000
      000000136354585077723247344F46444D5F313651414D0D4F46444D2032344D
      2C2033364D02313800000000FFFFFFFFFFFFFFFF020000000000000011635458
      5077723247344F46444D5F34384D084F46444D2034384D02313800000000FFFF
      FFFFFFFFFFFF0200000000000000116354585077723247344F46444D5F35344D
      084F46444D2035344D02313800000000FFFFFFFFFFFFFFFF0200000000000000
      12635458507772324734485432305F4250534B0848543230204D433002313800
      000000FFFFFFFFFFFFFFFF020000000000000012635458507772324734485432
      305F5150534B0F48543230204D4353312C204D43533202313800000000FFFFFF
      FFFFFFFFFF020000000000000013635458507772324734485432305F31365141
      4D0F48543230204D4353332C204D43533402313800000000FFFFFFFFFFFFFFFF
      020000000000000012635458507772324734485432305F4D4353350948543230
      204D43533502313800000000FFFFFFFFFFFFFFFF020000000000000012635458
      507772324734485432305F4D4353360948543230204D43533602313800000000
      FFFFFFFFFFFFFFFF020000000000000012635458507772324734485432305F4D
      4353370948543230204D43533702313800000000FFFFFFFFFFFFFFFF02000000
      0000000012635458507772324734485434305F4250534B0848543430204D4330
      02313600000000FFFFFFFFFFFFFFFF0200000000000000126354585077723247
      34485434305F5150534B0F48543430204D4353312C204D435332023136000000
      00FFFFFFFFFFFFFFFF020000000000000013635458507772324734485434305F
      313651414D0F48543430204D4353332C204D43533402313600000000FFFFFFFF
      FFFFFFFF020000000000000012635458507772324734485434305F4D43533509
      48543430204D43533502313600000000FFFFFFFFFFFFFFFF0200000000000000
      12635458507772324734485434305F4D4353360948543430204D435336023136
      00000000FFFFFFFFFFFFFFFF0200000000000000126354585077723247344854
      34305F4D4353370948543430204D435337023136FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnAdvancedCustomDrawSubItem = m_lv2GH_TX_Power_RegisterAdvancedCustomDrawSubItem
    OnClick = m_lv2GH_TX_Power_RegisterClick
  end
  object GroupBox2: TGroupBox
    Left = 7
    Top = 431
    Width = 483
    Height = 113
    Caption = 'FCC Ch1,Ch11 Band Edge Limit'
    TabOrder = 2
    object m_cb2GH_TX_Power_FCC: TComboBox
      Left = 8
      Top = 20
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_lv2GH_TX_Power_FCC: TListView
      Left = 8
      Top = 48
      Width = 465
      Height = 57
      Columns = <
        item
          Width = 180
        end
        item
        end>
      Items.Data = {
        950000000300000000000000FFFFFFFFFFFFFFFF01000000000000001343434B
        204D415820506F776572202864426D2902323000000000FFFFFFFFFFFFFFFF01
        00000000000000164F46444D3230204D415820506F776572202864426D290231
        3800000000FFFFFFFFFFFFFFFF0100000000000000164F46444D3430204D4158
        20506F776572202864426D29023136FFFFFFFFFFFF}
      ReadOnly = True
      RowSelect = True
      ShowColumnHeaders = False
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lv2GH_TX_Power_FCCAdvancedCustomDrawSubItem
      OnClick = m_lv2GH_TX_Power_FCCClick
    end
    object m_edt2GH_TX_Power_FCC: TEdit
      Left = 282
      Top = 72
      Width = 167
      Height = 17
      AutoSize = False
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 2
      Visible = False
      OnExit = m_edt2GH_TX_Power_FCCExit
    end
  end
  object m_btnReadFromNVRAM: TButton
    Left = 8
    Top = 759
    Width = 105
    Height = 25
    Caption = 'Read from NVRAM'
    TabOrder = 3
    OnClick = m_btnReadFromNVRAMClick
  end
  object m_btnWriteToNVRAM: TButton
    Left = 119
    Top = 759
    Width = 105
    Height = 25
    Caption = 'Write to NVRAM'
    TabOrder = 4
    OnClick = m_btnWriteToNVRAMClick
  end
  object m_sb2GH: TStatusBar
    Left = 0
    Top = 799
    Width = 499
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object m_edt2GH_TX_Power_Register: TEdit
    Left = 308
    Top = 112
    Width = 167
    Height = 17
    AutoSize = False
    ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
    TabOrder = 6
    Visible = False
    OnExit = m_edt2GH_TX_Power_RegisterExit
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 325
    Width = 481
    Height = 101
    Caption = 'TX Power Compensation Over ALL Channels '
    TabOrder = 7
    object m_cb2GH_TX_Power_Compensation_AllChannel: TComboBox
      Left = 8
      Top = 20
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_lv2GH_TX_Power_CompensationAllChannel: TListView
      Left = 8
      Top = 48
      Width = 465
      Height = 46
      Columns = <
        item
          Caption = 'Channels'
          Width = 150
        end
        item
          Caption = 'TX Power Offset (-4~+4dB, step 0.5)'
          Width = 200
        end>
      Items.Data = {
        2D0000000100000000000000FFFFFFFFFFFFFFFF01000000000000000C416C6C
        204368616E6E656C730130FFFF}
      RowSelect = True
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lv2GH_TX_Power_Compensation_AllChannel_AdvancedCustomDrawSubItem
      OnClick = m_lv2GH_TX_Power_Compensation_AllChannel_Click
    end
    object m_cb2GH_TX_Power_Compensation_AllChannel_Edit: TComboBox
      Left = 336
      Top = 72
      Width = 97
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      TabOrder = 2
      Visible = False
      OnExit = m_cb2GH_TX_Power_Compensation_AllChannel_EditChange
    end
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 545
    Width = 481
    Height = 92
    Caption = 'TX Power Back Off'
    TabOrder = 8
    object m_cb2GH_TX_Power_BackOff: TComboBox
      Left = 8
      Top = 16
      Width = 90
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_lv2GH_TX_Power_BackOff: TListView
      Left = 8
      Top = 43
      Width = 465
      Height = 34
      Columns = <
        item
          Width = 180
        end
        item
        end>
      Items.Data = {
        370000000100000000000000FFFFFFFFFFFFFFFF010000000000000013322E34
        47204261636B206F666620506F7765720431392E35FFFF}
      ReadOnly = True
      RowSelect = True
      ShowColumnHeaders = False
      TabOrder = 1
      ViewStyle = vsReport
      OnClick = m_lv2GH_TX_Power_BackOffClick
    end
    object m_edt2GH_TX_Power_BackOff: TEdit
      Left = 295
      Top = 51
      Width = 167
      Height = 17
      AutoSize = False
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 2
      Visible = False
      OnExit = m_edt2GH_TX_Power_BackOffExit
    end
  end
  object GroupBox5: TGroupBox
    Left = 8
    Top = 640
    Width = 481
    Height = 117
    Caption = 'TX power offset per-channel (offset step 0.5)'
    TabOrder = 9
    object m_lv2GH_TX_Power_Offset: TListView
      Left = 8
      Top = 18
      Width = 467
      Height = 93
      Columns = <
        item
          Caption = 'Index'
          Width = 55
        end
        item
          Caption = 'CH'
          Width = 75
        end
        item
          Caption = 'CCK'
          Width = 75
        end
        item
          Caption = 'Ofdm'
          Width = 75
        end
        item
          Caption = 'HT20'
          Width = 75
        end
        item
          Caption = 'HT40'
          Width = 75
        end>
      Items.Data = {
        0D0700002A00000000000000FFFFFFFFFFFFFFFF050000000000000001310130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001320130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001330130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001340130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001350130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001360130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001370130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001380130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000001390130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000002313001
        30013001300130013000000000FFFFFFFFFFFFFFFF0500000000000000023131
        0130013001300130013000000000FFFFFFFFFFFFFFFF05000000000000000231
        320130013001300130013000000000FFFFFFFFFFFFFFFF050000000000000002
        31330130013001300130013000000000FFFFFFFFFFFFFFFF0500000000000000
        0231340130013001300130013000000000FFFFFFFFFFFFFFFF05000000000000
        000231350130013001300130013000000000FFFFFFFFFFFFFFFF050000000000
        00000231360130013001300130013000000000FFFFFFFFFFFFFFFF0500000000
        0000000231360130013001300130013000000000FFFFFFFFFFFFFFFF05000000
        000000000231370130013001300130013000000000FFFFFFFFFFFFFFFF050000
        00000000000231380130013001300130013000000000FFFFFFFFFFFFFFFF0500
        0000000000000231390130013001300130013000000000FFFFFFFFFFFFFFFF05
        000000000000000232300130013001300130013000000000FFFFFFFFFFFFFFFF
        05000000000000000232310130013001300130013000000000FFFFFFFFFFFFFF
        FF05000000000000000232320130013001300130013000000000FFFFFFFFFFFF
        FFFF05000000000000000232330130013001300130013000000000FFFFFFFFFF
        FFFFFF05000000000000000232340130013001300130013000000000FFFFFFFF
        FFFFFFFF05000000000000000232350130013001300130013000000000FFFFFF
        FFFFFFFFFF05000000000000000232360130013001300130013000000000FFFF
        FFFFFFFFFFFF05000000000000000232370130013001300130013000000000FF
        FFFFFFFFFFFFFF05000000000000000232380130013001300130013000000000
        FFFFFFFFFFFFFFFF050000000000000002323901300130013001300130000000
        00FFFFFFFFFFFFFFFF0500000000000000023330013001300130013001300000
        0000FFFFFFFFFFFFFFFF05000000000000000233310130013001300130013000
        000000FFFFFFFFFFFFFFFF050000000000000002333201300130013001300130
        00000000FFFFFFFFFFFFFFFF0500000000000000023333013001300130013001
        3000000000FFFFFFFFFFFFFFFF05000000000000000233340130013001300130
        013000000000FFFFFFFFFFFFFFFF050000000000000002333401300130013001
        30013000000000FFFFFFFFFFFFFFFF0500000000000000023335013001300130
        0130013000000000FFFFFFFFFFFFFFFF05000000000000000233360130013001
        300130013000000000FFFFFFFFFFFFFFFF050000000000000002333701300130
        01300130013000000000FFFFFFFFFFFFFFFF0500000000000000023338013001
        3001300130013000000000FFFFFFFFFFFFFFFF05000000000000000233390130
        013001300130013000000000FFFFFFFFFFFFFFFF050000000000000002343001
        300130013001300130FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFF}
      ReadOnly = True
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
      OnClick = m_lv2GH_TX_Power_OffsetClick
    end
    object m_edt2GHTX_Power_Offset: TEdit
      Left = 367
      Top = 74
      Width = 71
      Height = 17
      AutoSize = False
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 1
      Visible = False
      OnExit = m_edt2GHTX_Power_OffsetExit
    end
  end
end
