#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

// Функция и ее производные
double f(double x) {
    return cos(x) + x - 2;
}

double df(double x) {
    return -sin(x) + 1;
}

double d2f(double x) {
    return -cos(x);
}

// Метод дихотомии (бисекции)
double bisection(double a, double b, double eps, int& iter) {
    iter = 0;
    double c, fa = f(a), fb = f(b);

    // Если на границах одинаковые знаки, расширяем интервал
    while (fa * fb > 0) {
        a -= 1.0;
        b += 1.0;
        fa = f(a);
        fb = f(b);
    }

    while (fabs(b - a) > eps) {
        c = (a + b) / 2;
        iter++;

        if (f(c) == 0.0) break;
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    return (a + b) / 2;
}

// Метод Ньютона
double newton(double x0, double eps, int& iter) {
    iter = 0;
    double x = x0, delta;

    do {
        delta = f(x) / df(x);
        x -= delta;
        iter++;
    } while (fabs(delta) > eps && iter < 1000);

    return x;
}

// Метод секущих
double secant(double x0, double x1, double eps, int& iter) {
    iter = 0;
    double x2;

    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        iter++;
    } while (fabs(f(x1)) > eps && iter < 1000);

    return x1;
}

// Метод простых итераций
double simple_iteration(double x0, double eps, int& iter) {
    iter = 0;
    double x = x0, prev_x;

    do {
        prev_x = x;
        x = 2 - cos(x);  // x = g(x)
        iter++;
    } while (fabs(x - prev_x) > eps && iter < 1000);

    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double eps, a, b;
    int iter;

    cout << "Решение уравнения cos(x) + x - 2 = 0\n";
    cout << "Введите точность: ";
    cin >> eps;

    // Автоматический поиск начального приближения
    a = -10; b = 10;
    while (f(a) * f(b) > 0) {
        a *= 1.5;
        b *= 1.5;
    }

    cout << "\nРезультаты разными методами:\n";
    cout << fixed << setprecision(10);

    // Метод бисекции
    double root_bisect = bisection(a, b, eps, iter);
    cout << "1. Метод бисекции:\n";
    cout << "   Корень: " << root_bisect << endl;
    cout << "   f(x) = " << f(root_bisect) << endl;
    cout << "   Итераций: " << iter << endl << endl;

    // Метод Ньютона
    double root_newton = newton((a + b) / 2, eps, iter);
    cout << "2. Метод Ньютона:\n";
    cout << "   Корень: " << root_newton << endl;
    cout << "   f(x) = " << f(root_newton) << endl;
    cout << "   Итераций: " << iter << endl << endl;

    // Метод секущих
    double root_secant = secant(a, b, eps, iter);
    cout << "3. Метод секущих:\n";
    cout << "   Корень: " << root_secant << endl;
    cout << "   f(x) = " << f(root_secant) << endl;
    cout << "   Итераций: " << iter << endl << endl;

    // Метод простых итераций
    double root_simple = simple_iteration((a + b) / 2, eps, iter);
    cout << "4. Метод простых итераций:\n";
    cout << "   Корень: " << root_simple << endl;
    cout << "   f(x) = " << f(root_simple) << endl;
    cout << "   Итераций: " << iter << endl;

    return 0;
}
