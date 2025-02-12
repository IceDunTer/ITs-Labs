#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	double chisl, znam, sq, ans1, ans2;
	cout << "Введите числитель:\n";
	scanf_s("%lg", &chisl); // 27
	cout << "Введите знаменатель:\n";
	scanf_s("%lg", &znam); // 31
	printf("Частное от деления %lg на %lg даёт %lg\n", chisl, znam, chisl / znam);

	cout << "Введите число, из которого нужно извлечь корень:\n";
	scanf_s("%lg", &sq); // 42
	printf("Корень из %lg равен %lg\n", sq, sqrt(sq));

	cout << "Введите первый полувичшийся Вами ответ:\n";
	scanf_s("%lf", &ans1); // 0.871
	cout << "Введите второй полувичшийся Вами ответ:\n";
	scanf_s("%lf", &ans2); // 6.48
	double temp = chisl / znam;
	printf("Разница в первом: %lf\nРазница во втором: %lf\n", abs(ans1 - temp), abs(ans2 - sqrt(sq)));

	if (abs(ans1 - temp) < abs(ans2 - sqrt(sq))) printf("*** Первое число точнее второго ***\n\n");
	else printf("*** Второе число точнее первого ***\n\n");

	double inter, proz, ans3, round;
	cout << "Введите число:\n";
	scanf_s("%lg", &inter); // 0.088748
	cout << "Введите относительную погрешность (в процентах):\n";
	scanf_s("%lg", &proz); // 0.56

	proz /= 100;
	ans3 = abs(inter - proz);

	printf("Абсолютная погрешность результата равна: %lf\n", inter * ans3);

}
