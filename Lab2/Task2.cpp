#include <iostream>
#include <cmath>
#include <vector>
#include <locale>

using namespace std;

double calculateSum(int n) {
    if (n == 0) return 0;

    vector<double> a(n + 1, 1.0), b(n + 1, 1.0);
    double sum = a[1] * b[1];

    for (int k = 2; k <= n; ++k) {
        a[k] = 0.5 * (sqrt(b[k - 1] + 0.5) * a[k - 1]);
        b[k] = 2 * pow(a[k - 1], 2) + b[k - 1];
        sum += a[k] * b[k];
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    double result = calculateSum(n);
    cout << "Сумма: " << result << endl;

    return 0;
}
