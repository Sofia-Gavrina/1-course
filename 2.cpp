#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

/**
 * @brief Получает корректное положительное числовое значение от пользователя
 * @param prompt Приглашение для ввода
 * @return Введенное положительное число
 * @note Завершает программу при некорректном вводе
 */
double getValidInput(const string& prompt);

/**
 * @brief Вычисляет третью сторону треугольника по теореме косинусов
 * @param a Длина первой стороны (const)
 * @param b Длина второй стороны (const)
 * @param angleRad Угол между сторонами в радианах (const)
 * @return Длина третьей стороны
 */
double calculateThirdSide(const double a, const double b, const double angleRad);

/**
 * @brief Вычисляет площадь треугольника
 * @param a Длина первой стороны (const)
 * @param b Длина второй стороны (const)
 * @param angleRad Угол между сторонами в радианах (const)
 * @return Площадь треугольника
 */
double calculateArea(const double a, const double b, const double angleRad);

/**
 * @brief Вычисляет радиус описанной окружности треугольника
 * @param a Длина первой стороны (const)
 * @param b Длина второй стороны (const)
 * @param c Длина третьей стороны (const)
 * @param area Площадь треугольника (const)
 * @return Радиус описанной окружности или NAN при ошибке вычисления
 */
double calculateCircumradius(const double a, const double b, const double c, const double area);

/**
 * @brief Главная функция программы
 *
 * Эта функция осуществляет взаимодействие с пользователем,
 * собирает входные данные, вызывает вычислительные функции,
 * и выводит результаты. В частности:
 * - запрашивает длины двух сторон и угол между ними в градусах;
 * - преобразует угол в радианы;
 * - вычисляет третью сторону по теореме косинусов;
 * - вычисляет площадь треугольника;
 * - вычисляет радиус описанной окружности.
 *
 * В случае успешного выполнения выводит результаты с точностью 4 знака после запятой.
 *
 * @return 0 при успешном завершении программы.
 */
int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных с проверкой
    cout << "Введите данные треугольника:\n";
    double a = getValidInput("Сторона a = ");
    double b = getValidInput("Сторона b = ");
    double angle = getValidInput("Угол между сторонами (в градусах) = ");

    // Преобразование угла в радианы
    const double angleRad = angle * M_PI / 180.0;

    // Вычисление параметров треугольника
    const double c = calculateThirdSide(a, b, angleRad);
    const double area = calculateArea(a, b, angleRad);
    const double radius = calculateCircumradius(a, b, c, area);

    // Вывод результатов с точностью 4 знака после запятой
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Третья сторона (c) = " << c << endl;
    cout << "Площадь треугольника = " << area << endl;
    cout << "Радиус описанной окружности = " << radius << endl;

    return 0;
}

// Реализация вспомогательных функций остаётся без изменений.
