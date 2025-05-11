#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления значения подынтегральной функции
double f(double x) {
    return (x * x + 0.5) / (sqrt(x * x + 1));
}

// Метод левых прямоугольников
double leftRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

// Метод правых прямоугольников
double rightRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

// Метод средних прямоугольников
double midRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return sum * h;
}

// Метод трапеций
double trap(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

// Метод парабол (метод Симпсона)
double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return (h / 3) * sum;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double a = 0.5;
    double b = 1.6;
    int n_values[] = { 4, 40, 140 };
    double exact_value = 1.2299285;

    for (int n : n_values) {
        double left = leftRect(a, b, n);
        double right = rightRect(a, b, n);
        double middle = midRect(a, b, n);
        double trapezoidal = trap(a, b, n);
        double simpson_value = simpson(a, b, n);

        double left_error = abs(left - exact_value);
        double right_error = abs(right - exact_value);
        double middle_error = abs(middle - exact_value);
        double trapezoidal_error = abs(trapezoidal - exact_value);
        double simpson_error = abs(simpson_value - exact_value);

        cout << "n = " << n << endl;
        cout << "Метод левых прямоугольников: " << setprecision(10) << left << ", Абсолютная погрешность: " << setprecision(4) << left_error << endl;
        cout << "Метод правых прямоугольников: " << setprecision(10) << right << ", Абсолютная погрешность: " << setprecision(4) << right_error << endl;
        cout << "Метод средних прямоугольников: " << setprecision(10) << middle << ", Абсолютная погрешность: " << setprecision(4) << middle_error << endl;
        cout << "Метод трапеций: " << setprecision(10) << trapezoidal << ", Абсолютная погрешность: " << setprecision(4) << trapezoidal_error << endl;
        cout << "Метод парабол (Симпсона): " << setprecision(10) << simpson_value << ", Абсолютная погрешность: " << setprecision(4) << simpson_error << endl;
        cout << endl;
    }

    return 0;
}
