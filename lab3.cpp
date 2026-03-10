#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
	return pow(sin(pow(x / 2.0 + 2.0, 2)), 2) - x / 5.0;
}
double df(double x) {
	double u = x / 2.0 + 2.0;
	double y = pow(u, 2);
	return sin(2.0 * y) * u - 0.2;
}
double d2f(double x) {
	double u = x / 2.0 + 2.0;
	return 0.5 * sin(2.0 * u * u) + 2.0 * u * u * cos(2.0 * u * u);
}
double function_1(double a, double b, double E) {
	int count_iteration = 0;
	double c = 0.0;
	while (b - a > 2 * E) {
		c = (a + b) / 2.0;
		if (f(a) * f(c) < 0) {
			b = c;
		}
		else {
			a = c;
		}
		count_iteration++;
	}
	cout << "Метод половинного деления ---------------------------------------------" << endl;
	cout << "итераций: " << count_iteration << endl;
	return c;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
double function_2(double a, double b, double E) {
	int count_iteration = 0;
	double c = 0.0, d = 0.0;
	while (b - a > 2 * E) {
		if (df(a) * d2f(a) > 0) {
			d = a - (f(a) / df(a));
			c = b - ((f(b) * (a - b)) / (f(a) - f(b)));
		}
		else if (df(b) * d2f(b) > 0){
			d = b - (f(b) / df(b));
			c = a - (f(a) * (b - a)) / (f(b) - f(a));
		}
		a = min(d, c);
		b = max(d, c);
		count_iteration++;
	}
	cout << "Метод хорд и касательных ---------------------------------------------" << endl;
	cout << "итераций: " << count_iteration << endl;
	return (a + b)/2.0;
}
int main() {
	setlocale(LC_ALL, "ru");
	double a, b, E;
	cin >> a >> b >> E;
	double root_1 = function_1(a, b, E);
	cout << "Корень1: " << root_1 << endl;
	cout << "Невязка: " << f(root_1) << endl;
	double root_2 = function_2(a, b, E);
	cout << "Корень2: " << root_2 << endl;
	cout <<"Невязка: " << f(root_2) << endl;
}