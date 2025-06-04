object frm5GHz_TX_Power_Profile: Tfrm5GHz_TX_Power_Profile
  Left = 312
  Top = 0
  Width = 503
  Height = 728
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = '5GHz_TX_Power_Profile'
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
  object m_lv5GHz_TX_Power_Register: TListView
    Left = 8
    Top = 8
    Width = 477
    Height = 265
    Columns = <
      item
        Caption = 'Register Name'
        Width = 160
      end
      item
        Caption = 'Data Rate '
        Width = 140
      end
      item
        Caption = 'Target Power at Chipout (dBm)'
        Width = 170
      end>
    Items.Data = {
      0A0600001B00000000000000FFFFFFFFFFFFFFFF020000000000000011635458
      50777235474F46444D5F4250534B0B4F46444D20364D2C20394D023138000000
      00FFFFFFFFFFFFFFFF02000000000000001163545850777235474F46444D5F51
      50534B0D4F46444D2031324D2C2031384D02313800000000FFFFFFFFFFFFFFFF
      02000000000000001263545850777235474F46444D5F313651414D0D4F46444D
      2032344D2C2033364D02313800000000FFFFFFFFFFFFFFFF0200000000000000
      1063545850777235474F46444D5F34384D084F46444D2034384D023138000000
      00FFFFFFFFFFFFFFFF02000000000000001063545850777235474F46444D5F35
      344D084F46444D2035344D02313800000000FFFFFFFFFFFFFFFF020000000000
      0000116354585077723547485432305F4250534B0848543230204D4330023138
      00000000FFFFFFFFFFFFFFFF0200000000000000116354585077723547485432
      305F5150534B0F48543230204D4353312C204D43533202313800000000FFFFFF
      FFFFFFFFFF0200000000000000126354585077723547485432305F313651414D
      0F48543230204D4353332C204D43533402313800000000FFFFFFFFFFFFFFFF02
      00000000000000116354585077723547485432305F4D4353350948543230204D
      43533502313800000000FFFFFFFFFFFFFFFF0200000000000000116354585077
      723547485432305F4D4353360948543230204D43533602313800000000FFFFFF
      FFFFFFFFFF0200000000000000116354585077723547485432305F4D43533709
      48543230204D43533702313800000000FFFFFFFFFFFFFFFF0200000000000000
      116354585077723547485434305F4250534B0848543430204D43300231360000
      0000FFFFFFFFFFFFFFFF0200000000000000116354585077723547485434305F
      5150534B0F48543430204D4353312C204D43533202313600000000FFFFFFFFFF
      FFFFFF0200000000000000126354585077723547485434305F313651414D0F48
      543430204D4353332C204D43533402313600000000FFFFFFFFFFFFFFFF020000
      0000000000116354585077723547485434305F4D4353350948543430204D4353
      3502313600000000FFFFFFFFFFFFFFFF02000000000000001163545850777235
      47485434305F4D4353360948543430204D43533602313600000000FFFFFFFFFF
      FFFFFF0200000000000000116354585077723547485434305F4D435337094854
      3430204D43533702313600000000FFFFFFFFFFFFFFFF02000000000000000F63
      3131416354585077725F4250534B044D43533002313600000000FFFFFFFFFFFF
      FFFF02000000000000000F633131416354585077725F5150534B064D4353312C
      3202313600000000FFFFFFFFFFFFFFFF02000000000000001063313141635458
      5077725F313651414D064D4353332C3402313600000000FFFFFFFFFFFFFFFF02
      0000000000000010633131416354585077725F363451414D064D4353352C3602
      313600000000FFFFFFFFFFFFFFFF020000000000000010633131416354585077
      725F4D43533720044D43533702313600000000FFFFFFFFFFFFFFFF0200000000
      0000000F633131416354585077725F4D435338044D43533802313600000000FF
      FFFFFFFFFFFFFF020000000000000010633131416354585077725F4D43533920
      044D43533902313600000000FFFFFFFFFFFFFFFF020000000000000016633131
      4163545850777256485434305F4F4646534554175648543430206F6666736574
      207769746820564854323002313600000000FFFFFFFFFFFFFFFF020000000000
      0000176331314163545850777256485438305F4F464653455420175648543830
      206F6666736574207769746820564854323002313600000000FFFFFFFFFFFFFF
      FF020000000000000018633131416354585077725648543136305F4F46465345
      542018564854313630206F66667365742077697468205648543230023136FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF}
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnAdvancedCustomDrawSubItem = m_lv5GHz_TX_Power_RegisterAdvancedCustomDrawSubItem
    OnClick = m_lv5GHz_TX_Power_RegisterClick
  end
  object m_edt5GHz_TX_Power_Register: TEdit
    Left = 300
    Top = 258
    Width = 167
    Height = 17
    AutoSize = False
    ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
    TabOrder = 1
    Visible = False
    OnExit = m_edt5GHz_TX_Power_RegisterExit
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 288
    Width = 481
    Height = 193
    Caption = 'TX Power Compensation Over Channels'
    TabOrder = 2
    object m_cb5GHz_TX_Power_Compensation: TComboBox
      Left = 8
      Top = 20
      Width = 145
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
    object m_lv5GHz_TX_Power_Compensation: TListView
      Left = 8
      Top = 48
      Width = 465
      Height = 137
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
        380100000800000000000000FFFFFFFFFFFFFFFF01000000000000000D313161
        20343931352D34393830013000000000FFFFFFFFFFFFFFFF0100000000000000
        0D31316120353034302D35313030013000000000FFFFFFFFFFFFFFFF01000000
        000000000D31316120353138302D35333230013000000000FFFFFFFFFFFFFFFF
        01000000000000000D31316120353530302D35353430013000000000FFFFFFFF
        FFFFFFFF01000000000000000D31316120353536302D35363230013000000000
        FFFFFFFFFFFFFFFF01000000000000000D31316120353634302D353636300130
        00000000FFFFFFFFFFFFFFFF01000000000000000D31316120353638302D3537
        3835013000000000FFFFFFFFFFFFFFFF01000000000000000D31316120353830
        352D353832350130FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ReadOnly = True
      RowSelect = True
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lv5GHz_TX_Power_CompensationAdvancedCustomDrawSubItem
      OnClick = m_lv5GHz_TX_Power_CompensationClick
    end
    object m_cb5GH_TX_Power_Compensation_Edit: TComboBox
      Left = 301
      Top = 172
      Width = 97
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      TabOrder = 2
      Visible = False
      OnExit = m_cb5GH_TX_Power_Compensation_EditChange
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
    object m_tc5GH_TX_Power_Compensation: TTabControl
      Left = 0
      Top = 16
      Width = 473
      Height = 177
      TabOrder = 3
      Tabs.Strings = (
        'WF0'
        'WF1')
      TabIndex = 0
      Visible = False
      OnChange = m_tc5GH_TX_Power_CompensationChange
      object m_lv5GTXPowerCom: TListView
        Left = 0
        Top = 48
        Width = 473
        Height = 129
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
          680200001000000000000000FFFFFFFFFFFFFFFF020000000000000009343835
          307E343936300130013000000000FFFFFFFFFFFFFFFF02000000000000000934
          3936357E353134350130013000000000FFFFFFFFFFFFFFFF0200000000000000
          09353135307E353230300130013000000000FFFFFFFFFFFFFFFF020000000000
          000009353230357E353235350130013000000000FFFFFFFFFFFFFFFF02000000
          0000000009353236307E353238300130013000000000FFFFFFFFFFFFFFFF0200
          00000000000009353238357E353336350130013000000000FFFFFFFFFFFFFFFF
          02000000000000000852657665727365640130013000000000FFFFFFFFFFFFFF
          FF02000000000000000A35333730207E353437350130013000000000FFFFFFFF
          FFFFFFFF02000000000000000A353438307E35353230200130013000000000FF
          FFFFFFFFFFFFFF020000000000000009353532357E3535383501300130000000
          00FFFFFFFFFFFFFFFF020000000000000009353539307E353632300130013000
          000000FFFFFFFFFFFFFFFF020000000000000009353632357E35363935013001
          3000000000FFFFFFFFFFFFFFFF020000000000000009353730307E3537323001
          30013000000000FFFFFFFFFFFFFFFF020000000000000009353732357E353830
          350130013000000000FFFFFFFFFFFFFFFF020000000000000008526576657273
          65640130013000000000FFFFFFFFFFFFFFFF020000000000000009353831307E
          3539353001300130FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        Visible = False
        OnClick = m_lv5GTXPowerComClick
      end
      object m_cb5GEnable: TComboBox
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
      object m_cb_5GHTXPowerCompEdit: TComboBox
        Left = 365
        Top = 88
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 2
        Visible = False
        OnExit = m_cb_5GHTXPowerCompEditExit
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
      object m_cb_5GH_EnableEdit: TComboBox
        Left = 365
        Top = 108
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 3
        Visible = False
        OnExit = m_cb_5GH_EnableEditExit
        Items.Strings = (
          '0'
          '1')
      end
      object m_btn5GWriteToNvram_MT6632: TButton
        Left = 128
        Top = 24
        Width = 89
        Height = 25
        Caption = 'Write to Nvram'
        TabOrder = 4
        Visible = False
        OnClick = m_btn5GWriteToNvram_MT6632Click
      end
    end
  end
  object m_btnReadFromNVRAM: TButton
    Left = 8
    Top = 699
    Width = 105
    Height = 25
    Caption = 'Read from NVRAM'
    TabOrder = 3
    OnClick = m_btnReadFromNVRAMClick
  end
  object m_btnWriteToNVRAM: TButton
    Left = 120
    Top = 699
    Width = 105
    Height = 25
    Caption = 'Write to NVRAM'
    TabOrder = 4
    OnClick = m_btnWriteToNVRAMClick
  end
  object m_sb5GH: TStatusBar
    Left = 0
    Top = 724
    Width = 490
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object GroupBox5GHzBandEdgeLimit: TGroupBox
    Left = 9
    Top = 489
    Width = 481
    Height = 113
    Caption = 'FCC CH 36/64/100/165 Bandedge Limit'
    TabOrder = 6
    object m_cb5GH_TX_Power_FCC: TComboBox
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
    object m_lv5GH_TX_Power_FCC: TListView
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
        9B0000000300000000000000FFFFFFFFFFFFFFFF0100000000000000164F4644
        4D3230204D415820506F776572202864426D2902313800000000FFFFFFFFFFFF
        FFFF0100000000000000164F46444D3430204D415820506F776572202864426D
        2902313600000000FFFFFFFFFFFFFFFF0100000000000000194F46444D205648
        543830204D415820506F7765722864426D29023136FFFFFFFFFFFF}
      ReadOnly = True
      RowSelect = True
      ShowColumnHeaders = False
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lv5GH_TX_Power_FCCAdvancedCustomDrawSubItem
      OnClick = m_lv5GH_TX_Power_FCCClick
    end
    object m_edt5GH_TX_Power_FCC: TEdit
      Left = 322
      Top = 88
      Width = 167
      Height = 17
      AutoSize = False
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 2
      Visible = False
      OnExit = m_edt5GH_TX_Power_FCCExit
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 607
    Width = 481
    Height = 90
    Caption = 'TX power Back off'
    TabOrder = 7
    object m_lv5GH_TX_Power_BackOff: TListView
      Left = 8
      Top = 43
      Width = 465
      Height = 41
      Columns = <
        item
          Width = 180
        end
        item
        end>
      Items.Data = {
        350000000100000000000000FFFFFFFFFFFFFFFF010000000000000011354720
        4261636B206F666620506F7765720431382E35FFFF}
      ReadOnly = True
      RowSelect = True
      ShowColumnHeaders = False
      TabOrder = 0
      ViewStyle = vsReport
      OnClick = m_lv5GH_TX_Power_BackOffClick
    end
    object m_edt5GH_TX_Power_BackOff: TEdit
      Left = 298
      Top = 65
      Width = 167
      Height = 17
      AutoSize = False
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      TabOrder = 1
      Visible = False
      OnExit = m_edt5GH_TX_Power_BackOffExit
    end
    object m_cb5GH_TX_Power_BackOff: TComboBox
      Left = 8
      Top = 15
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 2
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
  end
end
