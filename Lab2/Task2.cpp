#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

void checkFirstLimit(double epsilon) {
    cout << "\n--- Проверка первого замечательного предела ---\n";
    cout << "lim(sin(x)/x) при x->0 = 1\n\n";

    double x = 1.0;
    int step = 1;
    double diff;

    cout << "Шаг |      x      |  sin(x)/x  |  Разница  " << endl;
    cout << "------------------------------------------" << endl;

    do {
        double ratio = sin(x) / x;
        diff = abs(ratio - 1.0);
        cout << setw(3) << step++ << " | " << scientific << setw(11) << x
            << " | " << fixed << setw(9) << ratio << " | " << diff << endl;
        x /= 2.0;
    } while (diff >= epsilon);
}

void checkSecondLimit(double epsilon) {
    cout << "\n--- Проверка второго замечательного предела ---\n";
    cout << "lim(1+1/n)^n при n->∞ = e\n\n";

    int n = 1;
    int step = 1;
    double e = exp(1.0);
    double diff;

    cout << "Шаг |    (1+1/n)^n    |  Разница  " << endl;
    cout << "------------------------------------------" << endl;

    do {
        double term = pow(1.0 + 1.0 / n, n);
        diff = abs(term - e);
        cout << setw(3) << step++
            << " | " << setw(15) << term << " | " << diff << endl;
        n++;
    } while (diff >= epsilon);
}

int main() {
    setlocale(LC_ALL, "RUS");
    double epsilon;
    cout << "Введите точность epsilon: ";
    cin >> epsilon;

    checkFirstLimit(epsilon);
    checkSecondLimit(epsilon);

    return 0;
}
