#ifndef Unit2H
#define Unit2H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VclTee.TeEngine.hpp>
#include <VclTee.Series.hpp>
#include <VclTee.TeeProcs.hpp>
#include <VclTee.Chart.hpp>

class TForm2 : public TForm
{
__published:    // IDE-managed Components
    // Labels
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;

    // Inputs
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;

    // Output group
    TGroupBox *GroupBox1;
    TCheckBox *CheckBoxScreen;
    TCheckBox *CheckBoxArray;
    TCheckBox *CheckBoxDerivative;
    TMemo *Memo1;

    // Menus
    TMainMenu *MainMenu1;
    TMenuItem *miFile;
    TMenuItem *miExit;
    TMenuItem *miCalc;
    TMenuItem *miCompute;
    TMenuItem *pmClearMemoItem;
    TMenuItem *miChartMenu;
    TMenuItem *miPlot;

    // Popup menus
    TPopupMenu *PopupMenu1;
    TMenuItem *PopupClear;
    TMenuItem *miExitPopup;

    TPopupMenu *PopupMenu2;
    TMenuItem *miChecksSelectAll;
    TMenuItem *miChecksClearAll;
    TMenuItem *miChecksInvert;

    // Chart
    TChart *Chart1;
    TLineSeries *Series1;

    // Events
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall miComputeClick(TObject *Sender);
    void __fastcall miClearMemoClick(TObject *Sender);
    void __fastcall miExitClick(TObject *Sender);
    void __fastcall miPlotClick(TObject *Sender);
    void __fastcall pmChecksSelectAllClick(TObject *Sender);
    void __fastcall pmChecksClearAllClick(TObject *Sender);
    void __fastcall pmChecksInvertClick(TObject *Sender);

private:
    bool TryReadInputs(double &a, double &b, double &h);
    void DoTabulate();
    void AppendToMemo(const UnicodeString &line);
    void ClearResults();

public:
    __fastcall TForm2(TComponent* Owner);
};

extern PACKAGE TForm2 *Form2;

#endif
