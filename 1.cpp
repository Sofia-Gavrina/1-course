#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Функция для вычисления значения переменной a по заданным константам.
 * @param x значение константы.
 * @param y значение константы.
 * @param z значение константы.
 * @return Результат вычисления переменной a.
 */
double calculateA(const double x, const double y, const double z);

/**
 * @brief Функция для вычисления значения переменной b по заданным константам.
 * @param x значение константы.
 * @param y значение константы.
 * @param z значение константы.
 * @return Результат вычисления переменной b.
 */
double calculateB(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return 0 - если программа выполнена корректно, иначе - 1
 */
int main()
{
    const double x = 0.5;
    const double y = 0.05;
    const double z = 0.7;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "a = " << calculateA(x, y, z) << endl;
    cout << "b = " << calculateB(x, y, z) << endl;

    return 0;
}

double calculateA(const double x, const double y, const double z)
{
    return double(pow(x, 2) * (x + 1)) / (y - pow(sin(x + z), 2));
}

double calculateB(const double x, const double y, const double z)
{
    return (sqrt((x * y) / z)) + (pow(cos(pow(x + y, 2)), 2));
}
