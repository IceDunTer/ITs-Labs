#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

void task1() {
    double fact1 = 27.0 / 31.0;
    double fact2 = sqrt(42.0);
    double around1 = 0.871;
    double around2 = 6.48;


    double absError1 = fabs(around1 - fact1);
    double absError2 = fabs(around2 - fact2);
    double relError1 = (absError1 / fact1) * 100;
    double relError2 = (absError2 / fact2) * 100;

    cout << "а) Сравнение точности равенств:" << endl;
    cout << "1. 27/31 = 0.871:" << endl;
    cout << "   Абсолютная погрешность: " << absError1 << endl;
    cout << "   Относительная погрешность: " << fixed << setprecision(4) << relError1 << "%" << endl;

    cout << "2. Корень из 42 = 6.48:" << endl;
    cout << "   Абсолютная погрешность: " << absError2 << endl;
    cout << "   Относительная погрешность: " << fixed << setprecision(4) << relError2 << "%" << endl;

    if (relError1 < relError2) {
        cout << "Вывод: Первое равенство точнее." << endl;
    }
    else {
        cout << "Вывод: Второе равенство точнее." << endl;
    }
    cout << endl;
}

// Функция для округления числа с учетом погрешности
void task2() {
    double num = 0.088748;
    double relError = 0.56; // в процентах

    cout << "б) Округление числа с учетом погрешности:" << endl;
    cout << "Исходное число: " << fixed << setprecision(6) << num << endl;
    cout << "Относительная погрешность: " << relError << "%" << endl;

    // Вычисляем абсолютную погрешность
    double absError = (relError / 100) * num;
    cout << "Абсолютная погрешность: " << absError << endl;

    // Определяем количество верных знаков после запятой
    int decimalPlaces = 0;
    double temp = absError;
    while (temp < 1.0) {
        temp *= 10;
        decimalPlaces++;
    }
    decimalPlaces--; // корректировка

    // Округляем число
    double rounded = round(num * pow(10, decimalPlaces)) / pow(10, decimalPlaces);

    cout << "Число верных знаков после запятой: " << decimalPlaces << endl;
    cout << "Округленное число: " << fixed << setprecision(decimalPlaces) << rounded << endl;
    cout << endl;
}

// Функция для вычисления предельных погрешностей
void task3() {
    double num = 71.385;

    cout << "в) Предельные погрешности для числа " << fixed << setprecision(3) << num << ":" << endl;

    // По умолчанию все цифры верные -> абсолютная погрешность 0.5 единицы последнего разряда
    double absError = 0.0005; // для числа 71.385 последний разряд - тысячные

    // Относительная погрешность
    double relError = (absError / num) * 100;

    cout << "Предельная абсолютная погрешность: ±" << absError << endl;
    cout << "Предельная относительная погрешность: " << setprecision(4) << relError << "%" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    task1();
    task2();
    task3();

    return 0;
}
