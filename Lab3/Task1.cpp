#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>
#include <locale>

using namespace std;
using namespace std::chrono;

double EPS; // Теперь точность задается пользователем

double f(double x) {
    return cos(x) + x - 2;
}

double df(double x) {
    return -sin(x) + 1;
}

struct Result {
    string method;
    double root;
    double func_value;
    int iters;
    long long ms;
};

Result division(double a, double b) {
    auto start = high_resolution_clock::now();
    int iterations = 0;
    double root;

    while (fabs(b - a) > EPS) {
        root = (a + b) / 2;
        iterations++;

        if (f(a) * f(root) < 0)
            b = root;
        else
            a = root;
    }

    auto stop = high_resolution_clock::now();
    return { "Деление", root, f(root), iterations,
            duration_cast<microseconds>(stop - start).count() };
}

Result chord(double a, double b) {
    auto start = high_resolution_clock::now();
    int iterations = 0;
    double root;

    do {
        root = a - f(a) * (b - a) / (f(b) - f(a));
        iterations++;

        if (f(a) * f(root) < 0)
            b = root;
        else
            a = root;
    } while (fabs(f(root)) > EPS);

    auto stop = high_resolution_clock::now();
    return { "Хорд", root, f(root), iterations,
            duration_cast<microseconds>(stop - start).count() };
}

Result newton(double x0) {
    auto start = high_resolution_clock::now();
    int iterations = 0;
    double root = x0;
    double prev;

    do {
        prev = root;
        root = prev - f(prev) / df(prev);
        iterations++;
    } while (fabs(root - prev) > EPS);

    auto stop = high_resolution_clock::now();
    return { "Ньютона", root, f(root), iterations,
            duration_cast<microseconds>(stop - start).count() };
}

Result secant(double x0, double x1) {
    auto start = high_resolution_clock::now();
    int iterations = 0;
    double root;

    do {
        root = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = root;
        iterations++;
    } while (fabs(f(root)) > EPS);

    auto stop = high_resolution_clock::now();
    return { "Секущих", root, f(root), iterations,
            duration_cast<microseconds>(stop - start).count() };
}

Result combined(double a, double b) {
    auto start = high_resolution_clock::now();
    int iterations = 0;
    double root;

    do {
        double chord_val = a - f(a) * (b - a) / (f(b) - f(a));
        double newton_val = b - f(b) / df(b);

        a = chord_val;
        b = newton_val;
        root = (a + b) / 2;
        iterations++;
    } while (fabs(b - a) > EPS);

    auto stop = high_resolution_clock::now();
    return { "Комбинированный", root, f(root), iterations,
            duration_cast<microseconds>(stop - start).count() };
}

void print_menu() {
    cout << "\nВыберите метод решения:\n";
    cout << "1. Метод деления пополам\n";
    cout << "2. Метод хорд\n";
    cout << "3. Метод Ньютона\n";
    cout << "4. Метод секущих\n";
    cout << "5. Комбинированный метод\n";
    cout << "6. Все методы (сравнение)\n";
    cout << "0. Выход\n";
    cout << "Ваш выбор: ";
}

void print_result(const Result& r) {
    cout << "\nРезультаты метода " << r.method << ":\n";
    cout << "Корень: " << fixed << setprecision(10) << r.root << endl;
    cout << "Значение f(x): " << scientific << setprecision(2) << r.func_value << endl;
    cout << "Количество итераций: " << r.iters << endl;
    cout << "Время выполнения: " << r.ms << " мкс\n";
}

int main() {
    setlocale(LC_ALL, "RUS");
    const double a = 1.0, b = 2.0;
    int choice;

    cout << "Введите желаемую точность (например, 0.000001): ";
    cin >> EPS;

    do {
        print_menu();
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            print_result(division(a, b));
            break;
        case 2:
            print_result(chord(a, b));
            break;
        case 3:
            print_result(newton((a + b) / 2));
            break;
        case 4:
            print_result(secant(a, b));
            break;
        case 5:
            print_result(combined(a, b));
            break;
        case 6: {
            vector<Result> results = {
                division(a, b),
                chord(a, b),
                newton((a + b) / 2),
                secant(a, b),
                combined(a, b)
            };

            sort(results.begin(), results.end(),
                [](const Result& r1, const Result& r2) {
                    return r1.ms < r2.ms;
                });

            cout << "\nСравнение всех методов (точность " << EPS << "):\n";
            cout << "|      Метод       |     Корень       |  Значение f(x)   | Итерации   | Время (мкс)  |\n";

            for (const auto& r : results) {
                cout << "| " << setw(17) << left << r.method << " | "
                    << setw(16) << fixed << setprecision(10) << r.root << " | "
                    << setw(16) << scientific << setprecision(2) << r.func_value << " | "
                    << setw(10) << r.iters << " | "
                    << setw(12) << r.ms << " |\n";
            }

            cout << "\nАнализ результатов:\n";
            cout << "1. Самый быстрый метод: " << results[0].method
                << " (" << results[0].ms << " мкс)\n";
            cout << "2. Наиболее эффективный по итерациям: ";

            auto min_iter = min_element(results.begin(), results.end(),
                [](const Result& r1, const Result& r2) {
                    return r1.iters < r2.iters;
                });
            cout << min_iter->method << " (" << min_iter->iters << " итераций)\n";
            break;
        }
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
