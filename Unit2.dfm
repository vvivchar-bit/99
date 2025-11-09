object Form2: TForm2
  Left = 200
  Top = 120
  Caption = #1058#1072#1073#1091#1083#1102#1074#1072#1085#1085#1103' '#1092#1091#1085#1082#1094#1110#1111
  ClientHeight = 827
  ClientWidth = 1073
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  TextHeight = 17
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 81
    Height = 17
    Caption = #1051#1110#1074#1072' '#1084#1077#1078#1072' (a)'
  end
  object Label2: TLabel
    Left = 16
    Top = 56
    Width = 94
    Height = 17
    Caption = #1055#1088#1072#1074#1072' '#1084#1077#1078#1072' (b)'
  end
  object Label3: TLabel
    Left = 16
    Top = 88
    Width = 49
    Height = 17
    Caption = #1050#1088#1086#1082' (h)'
  end
  object Label4: TLabel
    Left = 480
    Top = 1
    Width = 83
    Height = 17
    Caption = 'y = sin(x) + 1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 136
    Top = 22
    Width = 120
    Height = 25
    TabOrder = 0
    Text = '0'
  end
  object Edit2: TEdit
    Left = 136
    Top = 53
    Width = 120
    Height = 25
    TabOrder = 1
    Text = '6.28'
  end
  object Edit3: TEdit
    Left = 136
    Top = 84
    Width = 120
    Height = 25
    TabOrder = 2
    Text = '0.1'
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 128
    Width = 224
    Height = 120
    Caption = #1042#1080#1074#1077#1076#1077#1085#1085#1103
    PopupMenu = PopupMenu2
    TabOrder = 3
    object CheckBoxScreen: TCheckBox
      Left = 16
      Top = 24
      Width = 150
      Height = 21
      Caption = #1053#1072' '#1077#1082#1088#1072#1085
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object CheckBoxArray: TCheckBox
      Left = 16
      Top = 48
      Width = 150
      Height = 21
      Caption = #1042#1080#1074#1077#1076#1077#1085#1085#1103
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object CheckBoxDerivative: TCheckBox
      Left = 16
      Top = 72
      Width = 150
      Height = 21
      Caption = #1055#1086#1093#1110#1076#1085#1072
      TabOrder = 2
    end
  end
  object Memo1: TMemo
    Left = 16
    Top = 488
    Width = 424
    Height = 312
    Lines.Strings = (
      '')
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Chart1: TChart
    Left = 480
    Top = 32
    Width = 585
    Height = 601
    Legend.Visible = False
    Title.Text.Strings = (
      #1043#1088#1072#1092#1110#1082' y = sin(x) + 1')
    View3D = False
    TabOrder = 5
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TLineSeries
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loNone
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 296
    object miFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object miExit: TMenuItem
        Caption = #1042#1080#1081#1090#1080
        OnClick = miExitClick
      end
    end
    object miCalc: TMenuItem
      Caption = #1054#1073#1095#1080#1089#1083#1077#1085#1085#1103
      object miCompute: TMenuItem
        Caption = #1055#1088#1086#1090#1072#1073#1091#1083#1102#1074#1072#1090#1080
        OnClick = miComputeClick
      end
      object pmClearMemoItem: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1080' '#1087#1086#1083#1077' '#1074#1080#1074#1077#1076#1077#1085#1085#1103
        OnClick = miClearMemoClick
      end
    end
    object miChartMenu: TMenuItem
      Caption = #1043#1088#1072#1092#1110#1082
      object miPlot: TMenuItem
        Caption = #1053#1072#1088#1080#1089#1091#1074#1072#1090#1080
        OnClick = miPlotClick
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 112
    Top = 296
    object PopupClear: TMenuItem
      Caption = #1054#1095#1080#1089#1090#1080#1090#1080' '#1087#1086#1083#1077' '#1074#1080#1074#1077#1076#1077#1085#1085#1103
      OnClick = miClearMemoClick
    end
    object miExitPopup: TMenuItem
      Caption = #1042#1080#1081#1090#1080
      OnClick = miExitClick
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 192
    Top = 296
    object miChecksSelectAll: TMenuItem
      Caption = #1042#1089#1090#1072#1085#1086#1074#1080#1090#1080' '#1074#1089#1110
      OnClick = pmChecksSelectAllClick
    end
    object miChecksClearAll: TMenuItem
      Caption = #1047#1085#1103#1090#1080' '#1074#1089#1110
      OnClick = pmChecksClearAllClick
    end
    object miChecksInvert: TMenuItem
      Caption = #1030#1085#1074#1077#1088#1089#1080#1074#1085#1086
      OnClick = pmChecksInvertClick
    end
  end
end
