#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>   // для setw() і setprecision()
#include <windows.h> // для кирилиці в консолі

using namespace std;

// Функція для вибору елементарної функції
double f(double x, int choice) {
    switch (choice) {
    case 1: return sin(x);
    case 2: return cos(x);
    case 3: return exp(x);
    case 4:
        if (x <= 0) throw invalid_argument("невизначено (x ≤ 0)");
        return log(x);
    default: throw invalid_argument("невірний вибір функції");
    }
}

// Метод Сімпсона
double simpson(double a, double b, int n, int choice) {
    if (n % 2 != 0) n++; // метод Сімпсона потребує парне n

    double h = (b - a) / n;
    double sum = 0.0;

    try {
        sum = f(a, choice) + f(b, choice);

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 2 == 0)
                sum += 2 * f(x, choice);
            else
                sum += 4 * f(x, choice);
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Помилка під час обчислення: " << e.what() << endl;
        exit(1);
    }

    return (h / 3.0) * sum;
}

int main() {
    system("chcp 65001 > nul"); // підтримка української мови

    int choice, n;
    double a, b;

    cout << "=== ОБЧИСЛЕННЯ ІНТЕГРАЛІВ ===\n\n";
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
    cout << "Введіть кількість підінтервалів n (парне): ";
    cin >> n;

    if (a >= b || n <= 0) {
        cerr << "Помилка: некоректні межі або кількість підінтервалів!\n";
        return 1;
    }

    double result = simpson(a, b, n, choice);

    cout << fixed << setprecision(6);
    cout << "\nРезультат обчислення інтеграла:\n";
    cout << "--------------------------------------\n";
    cout << " ∫ f(x) dx від " << a << " до " << b << " = " << result << endl;
    cout << "--------------------------------------\n";

    return 0;
}