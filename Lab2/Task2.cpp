#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

double cube(double a, double epsilon = 1e-6) {
    double x = a / 3.0;
    double x_next;

    do {
        x_next = x;
        x = (2.0 / 3.0) * (x + a / (2.0 * x * x));
    } while (abs(x - x_next) >= epsilon);

    return x;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double a;
    cout << "Введите число a: ";
    cin >> a;

    double result = cube(a);
    cout << "Кубический корень из " << a << " приближенно равен " << fixed << setprecision(6) << result << endl;

    return 0;
}
