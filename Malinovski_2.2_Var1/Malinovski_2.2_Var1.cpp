#include <iostream>
#include <cmath>
#include <iomanip> // для fixed и setprecision

using namespace std;

// Функция для вычисления ln(1 + x) с использованием ряда Тейлора
double taylor_ln(double x, double epsilon, int& terms) {
    double sum = 0.0;
    double term = x;
    int n = 1;
    terms = 0;

    while (fabs(term) > epsilon) { // однажды term будет 0.0000000000000001 из-за бесконечного деления
        sum += term;
        terms++; // кол-во слагаемых
        n++;
        term = pow(-1, n - 1) * pow(x, n) / n;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "RU");
    double x0 = -0.8, xn = 1.0, delta_x = 0.1;
    double epsilon = 0.000001;

    cout << fixed << setprecision(6);  // fixed - вывод чисел в десятичном формате (не в 1e-835y285) // setprecision - точек после запятой

    cout << " x\t\tТейлор\t\t Слог.\t Встроенная\t Разность\n";

    for (double x = x0; x <= xn; x += delta_x) {
        int terms = 0;
        double taylor_result = taylor_ln(x, epsilon, terms) - x;
        double builtin_result = log(1 + x) - x;
        double difference = fabs(taylor_result - builtin_result);

        cout << x << "\t " << taylor_result << "\t " << terms << "\t " << builtin_result << "\t " << difference << "\n";
    }

    return 0;
}