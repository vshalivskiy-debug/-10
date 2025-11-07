#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>   // для setw() і setprecision()
#include <windows.h> // для кирилиці в консолі

using namespace std;

int main() {
    // Увімкнення української мови у консолі
    system("chcp 65001 > nul");

    int choice;
    double a, b, step;

    cout << "=== ТАБУЛЮВАННЯ ФУНКЦІЙ ===\n\n";
    cout << "Оберіть функцію:\n";
    cout << "1) y = sin(x)\n";
    cout << "2) y = cos(x)\n";
    cout << "3) y = e^x\n";
    cout << "4) y = ln(x)\n";
    cout << "\nВаш вибір: ";
    cin >> choice;

    cout << "\nВведіть початок відрізка a: ";
    cin >> a;
    cout << "Введіть кінець відрізка b: ";
    cin >> b;
    cout << "Введіть крок h: ";
    cin >> step;

    if (step <= 0 || a > b) {
        cerr << "Помилка: неправильні значення a, b або h!\n";
        return 1;
    }

    cout << "\nРезультат табулювання:\n\n";
    cout << setw(10) << "x" << setw(10) << "y" << "\n";
    cout << "--------------------\n";

    for (double x = a; x <= b + step / 2; x += step) {
        double y;
        try {
            switch (choice) {
            case 1:
                y = sin(x);
                break;
            case 2:
                y = cos(x);
                break;
            case 3:
                y = exp(x);
                break;
            case 4:
                if (x <= 0) throw invalid_argument("невизначено");
                y = log(x);
                break;
            default:
                cerr << "Невірний вибір функції!\n";
                return 1;
            }
            cout << fixed << setprecision(4);
            cout << setw(10) << x << setw(10) << y << "\n";
        }
        catch (const invalid_argument& e) {
            cout << fixed << setprecision(4);
            cout << setw(10) << x << setw(10) << e.what() << "\n";
        }
    }

    return 0;
}