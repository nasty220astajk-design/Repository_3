#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * @file ConsoleApplication123.cpp
 * @brief Программа для расчета тригонометрических функций.
 * @author Anastasia
 * @version 1.0
 * @date 2026-06-20
 * @details лабораторная № 5
 */

 /**
  * @brief Главная функция программы.
  * @details Считывает угол в градусах из стандартного ввода,
  * переводит его в радианы и вычисляет sin, cos, tan.
  *
  * @return int Статус завершения программы (0 - успех).
  */
int main() {
	/** @brief Переменная для хранения введенного угла в градусах. */
	double a;

	/** @brief Синус угла. */
	double b;

	/** @brief Косинус угла. */
	double c;

	/** @brief Тангенс угла. */
	double d;

	cin >> a;

	// Перевод градусов в радианы и вычисление
	b = sin(a * (M_PI / 180));
	c = cos(a * (M_PI / 180));
	d = tan(a * (M_PI / 180));

	cout << "sin: " << b << endl <<
		"cos: " << c << endl <<
		"tan: " << d << endl;

	return 0;
}