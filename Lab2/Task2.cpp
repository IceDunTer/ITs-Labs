#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

double findMinValue(int n) {
    cout << "k \t|\t k^3 \t| sin(n + k/n) \t| Значение" << endl;
    cout << "---------------------------------" << endl;

    double min_val = pow(1, 3) * sin(n + static_cast<double>(1) / n);
    cout << fixed << setprecision(6);
    cout << 1 << " \t|\t " << setw(4) << 1 << " \t| " << setw(12) << sin(n + 1.0 / n) << " \t| " << min_val << endl;

    for (int k = 2; k <= n; ++k) {
        double sin_val = sin(n + static_cast<double>(k) / n);
        double term = pow(k, 3) * sin_val;
        cout << k << " \t| " << setw(4) << pow(k, 3) << " \t| " << setw(12) << sin_val << " \t| " << term << endl;
        if (term < min_val) {
            min_val = term;
        }
    }

    return min_val;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    double result = findMinValue(n);
    cout << "---------------------------------" << endl;
    cout << "Наименьшее значение: " << result << endl;

    return 0;
}
