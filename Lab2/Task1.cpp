#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

double taylorSeries(double x, double epsilon, int& termCount) {
    double sum = 0.0;
    double term = 1.0;
    termCount = 0;

    while (fabs(term) >= epsilon) {
        sum += term;
        termCount++;
        term = (termCount + 1) * pow(x, termCount);
    }

    return sum;
}

// Точное значение функции
double exactFunction(double x) {
    return 1.0 / pow(1.0 - x, 2);
}

int main() {
    setlocale(LC_ALL, "RUS");
    double xn, xk, dx;
    cout << "Введите начальное значение x (xn): ";
    cin >> xn;
    cout << "Введите конечное значение x (xk): ";
    cin >> xk;
    cout << "Введите шаг dx: ";
    cin >> dx;

    if (xn >= 1 || xk >= 1 || xn <= -1 || xk <= -1) {
        cout << "Ошибка: x должен быть в интервале (-1, 1)" << endl;
        return 1;
    }

    cout << "\n\n";
    cout << left << setw(10) << "x"
        << setw(15) << "f(x)"
        << setw(10) << "eps1"
        << setw(15) << "f1(x)"
        << setw(5) << "n1"
        << setw(10) << "eps2"
        << setw(15) << "f2(x)"
        << setw(5) << "n2" << endl;

    cout << string(80, '-') << endl;

    cout << fixed << setprecision(6);

    for (double x = xn; x <= xk; x += dx) {
        int n1, n2;
        double eps1 = 0.1;
        double eps2 = 0.000001;

        double exact = exactFunction(x);
        double f1 = taylorSeries(x, eps1, n1);
        double f2 = taylorSeries(x, eps2, n2);

        cout << left << setw(10) << x
            << setw(15) << exact
            << setw(10) << eps1
            << setw(15) << f1
            << setw(5) << n1
            << setw(10) << eps2
            << setw(15) << f2
            << setw(5) << n2 << endl;
    }

    cout << string(80, '-') << endl;

    return 0;
}
