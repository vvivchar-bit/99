#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <System.Math.hpp>
#include <vector>

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

// ===== буфери для табуляції =====
namespace {
    std::vector<double> xs, ys, dydxs;
    double y_min, y_max;
    int count_between_05_1;
}

// ===== конструктор =====
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {}

// ===== ініціалізація підписів та прив’язок =====
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    // Заголовок форми
    Caption = L"Табулювання функції";

    // Підписи
    Label1->Caption = L"Ліва межа (a)";
    Label2->Caption = L"Права межа (b)";
    Label3->Caption = L"Крок (h)";
    Label4->Caption = L"y = sin(x) + 1";

    // Група/прапорці
    GroupBox1->Caption = L"Виведення";
    CheckBoxScreen->Caption = L"На екран";
    CheckBoxArray->Caption  = L"Виведення";   // якщо треба — зміни на "У масив"
    CheckBoxDerivative->Caption = L"Похідна";

    // Головне меню (без зайвих Visible/Enabled)
    miFile->Caption = L"Файл";
    miExit->Caption = L"Вийти";
    miCalc->Caption = L"Обчислення";
    miCompute->Caption = L"Протабулювати";
    pmClearMemoItem->Caption = L"Очистити поле виведення";
    miChartMenu->Caption = L"Графік";
    miPlot->Caption = L"Нарисувати";

    // Гарантовано підв’язуємо меню
    Menu = MainMenu1;

    // Контекстні меню
    PopupClear->Caption = L"Очистити поле виведення";
    miExitPopup->Caption = L"Вийти";
    miChecksSelectAll->Caption = L"Встановити всі";
    miChecksClearAll->Caption  = L"Зняти всі";
    miChecksInvert->Caption    = L"Інверсивно";

    PopupMenu = PopupMenu1;               // ПКМ по формі
    GroupBox1->PopupMenu = PopupMenu2;    // ПКМ по групі прапорців

    // Заголовок графіка
    Chart1->Title->Text->Clear();
    Chart1->Title->Text->Add(L"Графік y = sin(x) + 1");
    Chart1->Legend->Visible = false;
    Chart1->View3D = false;

    // Шрифти (про всяк)
    Font->Charset = DEFAULT_CHARSET;
    Memo1->Font->Charset = DEFAULT_CHARSET;
}

// ===== утиліти =====
bool TForm2::TryReadInputs(double &a, double &b, double &h) {
    // Приймаємо і кому, і крапку як десятковий роздільник
    auto norm = [](UnicodeString s) -> UnicodeString {
        s = s.Trim();
        s = StringReplace(s, L",", L".", TReplaceFlags() << rfReplaceAll);
        return s;
    };
    TFormatSettings fs;
    fs.DecimalSeparator = '.'; // парсимо під крапку

    try {
        if (!TryStrToFloat(norm(Edit1->Text), a, fs) ||
            !TryStrToFloat(norm(Edit2->Text), b, fs) ||
            !TryStrToFloat(norm(Edit3->Text), h, fs)) {
            throw Exception(L"");
        }
    } catch (...) {
        Application->MessageBox(
            L"Некоректні дані.\nПриклад: 6.28 або 6,28",
            L"Помилка вводу", MB_ICONERROR);
        return false;
    }

    if (h == 0.0 || ((b - a) / h) < 0.0) {
        Application->MessageBox(
            L"Крок має вести від a до b (ненульовий і з правильним знаком).",
            L"Помилка кроку", MB_ICONERROR);
        return false;
    }
    return true;
}

void TForm2::AppendToMemo(const UnicodeString &line) {
    Memo1->Lines->Add(line);
}

void TForm2::ClearResults() {
    xs.clear(); ys.clear(); dydxs.clear();
    count_between_05_1 = 0;
}

// ===== табуляція y = sin(x) + 1 (та похідна за прапорцем) =====
void TForm2::DoTabulate() {
    double a,b,h;
    if (!TryReadInputs(a,b,h)) return;

    Memo1->Lines->Add(L"=== Tabulation start ===");
    ClearResults();

    bool toScreen = CheckBoxScreen->Checked;
    bool toArray  = CheckBoxArray->Checked;
    bool withDer  = CheckBoxDerivative->Checked;

    y_min = HUGE_VAL; y_max = -HUGE_VAL;

    const int maxIters = 2'000'000;
    int safe = 0;
    double x = a;

    while (((h > 0) ? (x <= b + 1e-12) : (x >= b - 1e-12)) && ++safe < maxIters) {
        double y = std::sin(x) + 1.0;
        double d = withDer ? std::cos(x) : 0.0;

        if (y < y_min) y_min = y;
        if (y > y_max) y_max = y;

        if (y > 0.5 && y < 1.0) ++count_between_05_1;

        if (toScreen) {
            if (withDer) {
                AppendToMemo( Format(
                    L"x=%0:.6f   y=%1:.6f   y'=%2:.6f",
                    ARRAYOFCONST((
                        static_cast<Extended>(x),
                        static_cast<Extended>(y),
                        static_cast<Extended>(d)
                    )))
                );
            } else {
                AppendToMemo( Format(
                    L"x=%0:.6f   y=%1:.6f",
                    ARRAYOFCONST((
                        static_cast<Extended>(x),
                        static_cast<Extended>(y)
                    )))
                );
            }
        }

        if (toArray) {
            xs.push_back(x); ys.push_back(y);
            dydxs.push_back(withDer ? d : NAN);
        }

        x += h;
    }

    AppendToMemo(L"--- Summary ---");

    AppendToMemo( Format(
        L"min(y) = %0:.6f   max(y) = %1:.6f",
        ARRAYOFCONST((
            static_cast<Extended>(y_min),
            static_cast<Extended>(y_max)
        )))
    );

    AppendToMemo( Format(
        L"count(0.5 < y < 1) = %0:d",
        ARRAYOFCONST(( static_cast<int>(count_between_05_1) ))
    ));

    AppendToMemo(L"=== Tabulation end ===");
}

// ===== обробники =====
void __fastcall TForm2::miComputeClick(TObject *Sender) { DoTabulate(); }
void __fastcall TForm2::miClearMemoClick(TObject *Sender) { Memo1->Clear(); }
void __fastcall TForm2::miExitClick(TObject *Sender) { Close(); }

void __fastcall TForm2::miPlotClick(TObject *Sender) {
    if (ys.empty()) {            // якщо ще не табульовано — табулюємо без виводу на екран
        bool prev = CheckBoxScreen->Checked;
        CheckBoxScreen->Checked = false;
        DoTabulate();
        CheckBoxScreen->Checked = prev;
    }
    Series1->Clear();
    for (size_t i = 0; i < xs.size(); ++i) Series1->AddXY(xs[i], ys[i]);
}

void __fastcall TForm2::pmChecksSelectAllClick(TObject *Sender) {
    CheckBoxScreen->Checked = true;
    CheckBoxArray->Checked = true;
    CheckBoxDerivative->Checked = true;
}
void __fastcall TForm2::pmChecksClearAllClick(TObject *Sender) {
    CheckBoxScreen->Checked = false;
    CheckBoxArray->Checked = false;
    CheckBoxDerivative->Checked = false;
}
void __fastcall TForm2::pmChecksInvertClick(TObject *Sender) {
    CheckBoxScreen->Checked = !CheckBoxScreen->Checked;
    CheckBoxArray->Checked  = !CheckBoxArray->Checked;
    CheckBoxDerivative->Checked = !CheckBoxDerivative->Checked;
}
