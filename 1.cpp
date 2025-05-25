#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Заданные константы
    const double x = 0.5;
    const double y = 0.05;
    const double z = 0.7;

    // Вычисление значения a
    double numerator_a = pow(x, 2) * (x + 1);
    double denominator_a = y - pow(sin(x + z), 2);
    double a = numerator_a / denominator_a;

    // Вычисление значения b
    double sqrt_term = sqrt((x * y) / z);
    double cos_term = pow(cos(pow(x + y, 2)), 2);
    double b = sqrt_term + cos_term;

    // Вывод исходных данных
    cout << "Исходные данные:\n";
    cout << fixed << setprecision(2);
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    cout << "z = " << z << "\n\n";

    // Вывод результатов с повышенной точностью
    cout << "Результаты вычислений:\n";
    cout << fixed << setprecision(6);
    cout << "a = " << a << "\n";
    cout << "b = " << b << endl;

    return 0;
}