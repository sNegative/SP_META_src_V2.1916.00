object frmSensor: TfrmSensor
  Left = 394
  Top = 174
  Width = 806
  Height = 592
  Caption = 'Sensor Tool'
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 793
    Height = 553
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'G-Sensor'
      object GroupBox1: TGroupBox
        Left = 32
        Top = 56
        Width = 713
        Height = 209
        Caption = 'Calibration Parameters'
        TabOrder = 0
        object Label1: TLabel
          Left = 40
          Top = 32
          Width = 87
          Height = 13
          Caption = 'Number of Sample'
        end
        object Label2: TLabel
          Left = 40
          Top = 80
          Width = 85
          Height = 13
          Caption = 'Sample delay (ms)'
        end
        object Label3: TLabel
          Left = 40
          Top = 128
          Width = 65
          Height = 13
          Caption = 'Tolerance (%)'
        end
        object ENumberSample: TEdit
          Left = 160
          Top = 32
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '50'
        end
        object ESampleDelay: TEdit
          Left = 160
          Top = 80
          Width = 121
          Height = 21
          TabOrder = 1
          Text = '20'
        end
        object ETolerance: TEdit
          Left = 160
          Top = 128
          Width = 121
          Height = 21
          TabOrder = 2
          Text = '20'
        end
        object btnPerformCalibration: TButton
          Left = 392
          Top = 48
          Width = 105
          Height = 81
          Caption = 'Perform Calibration'
          TabOrder = 3
          OnClick = btnPerformCalibrationClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 32
        Top = 280
        Width = 713
        Height = 193
        Caption = 'Calibration Result'
        TabOrder = 1
        object Label4: TLabel
          Left = 40
          Top = 32
          Width = 28
          Height = 13
          Caption = 'X-axis'
        end
        object Label5: TLabel
          Left = 40
          Top = 72
          Width = 28
          Height = 13
          Caption = 'Y-axis'
        end
        object Label6: TLabel
          Left = 40
          Top = 112
          Width = 28
          Height = 13
          Caption = 'Z-axis'
        end
        object Label7: TLabel
          Left = 40
          Top = 152
          Width = 30
          Height = 13
          Caption = 'Status'
        end
        object btnWriteNvram: TButton
          Left = 392
          Top = 64
          Width = 113
          Height = 81
          Caption = 'Write NVRam'
          TabOrder = 0
          OnClick = btnWriteNvramClick
        end
        object EXaxis: TStaticText
          Left = 160
          Top = 32
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = 
            '                                                                ' +
            '             '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object EYaxis: TStaticText
          Left = 160
          Top = 72
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object EZaxis: TStaticText
          Left = 160
          Top = 112
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object EStatus: TStaticText
          Left = 160
          Top = 152
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
      end
      object stInfo: TStaticText
        Left = 9
        Top = 508
        Width = 688
        Height = 17
        AutoSize = False
        BevelInner = bvNone
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Reference Sans Serif'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 2
      end
      object StaticText1: TStaticText
        Left = 32
        Top = 16
        Width = 721
        Height = 25
        AutoSize = False
        Caption = 
          'Please put the device on a horizontal surface with LCD face to s' +
          'ky. Otherwise, the g-sensor will work abnormally after calibrati' +
          'on.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Gyroscope'
      ImageIndex = 1
      object StaticText2: TStaticText
        Left = 32
        Top = 16
        Width = 721
        Height = 25
        AutoSize = False
        Caption = 
          'Please put the device on a horizontal surface with LCD face to s' +
          'ky. Otherwise, the gyroscope will work abnormally after calibrat' +
          'ion.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object GroupBox3: TGroupBox
        Left = 32
        Top = 56
        Width = 713
        Height = 209
        Caption = 'Calibration Parameters'
        TabOrder = 1
        object Label8: TLabel
          Left = 40
          Top = 32
          Width = 87
          Height = 13
          Caption = 'Number of Sample'
        end
        object Label9: TLabel
          Left = 40
          Top = 80
          Width = 85
          Height = 13
          Caption = 'Sample delay (ms)'
        end
        object Label10: TLabel
          Left = 40
          Top = 128
          Width = 65
          Height = 13
          Caption = 'Tolerance (%)'
        end
        object GYROENumberSample: TEdit
          Left = 160
          Top = 32
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '50'
        end
        object GYROESampleDelay: TEdit
          Left = 160
          Top = 80
          Width = 121
          Height = 21
          TabOrder = 1
          Text = '20'
        end
        object GYROETolerance: TEdit
          Left = 160
          Top = 128
          Width = 121
          Height = 21
          TabOrder = 2
          Text = '40'
        end
        object btnbtnPerformCalibrationGYRO: TButton
          Left = 392
          Top = 48
          Width = 105
          Height = 81
          Caption = 'Perform Calibration'
          TabOrder = 3
          OnClick = btnPerformCalibrationGYROClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 32
        Top = 280
        Width = 713
        Height = 193
        Caption = 'Calibration Result'
        TabOrder = 2
        object Label11: TLabel
          Left = 40
          Top = 32
          Width = 28
          Height = 13
          Caption = 'X-axis'
        end
        object Label12: TLabel
          Left = 40
          Top = 72
          Width = 28
          Height = 13
          Caption = 'Y-axis'
        end
        object Label13: TLabel
          Left = 40
          Top = 112
          Width = 28
          Height = 13
          Caption = 'Z-axis'
        end
        object Label14: TLabel
          Left = 40
          Top = 152
          Width = 30
          Height = 13
          Caption = 'Status'
        end
        object btnWriteNvramGYNO: TButton
          Left = 392
          Top = 64
          Width = 113
          Height = 81
          Caption = 'Write NVRam'
          TabOrder = 0
          OnClick = btnWriteNvramGYROClick
        end
        object GYROEXaxis: TStaticText
          Left = 160
          Top = 32
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = 
            '                                                                ' +
            '             '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object GYROEYaxis: TStaticText
          Left = 160
          Top = 72
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object GYROEZaxis: TStaticText
          Left = 160
          Top = 112
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object GYROEStatus: TStaticText
          Left = 160
          Top = 152
          Width = 121
          Height = 21
          AutoSize = False
          BorderStyle = sbsSingle
          Caption = '                                       '
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
      end
      object stGYROInfo: TStaticText
        Left = 9
        Top = 508
        Width = 688
        Height = 17
        AutoSize = False
        BevelInner = bvNone
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Reference Sans Serif'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 3
      end
    end
  end
end
