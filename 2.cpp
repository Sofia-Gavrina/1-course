#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Прототипы функций
/**
 * @brief Получает корректное числовое значение от пользователя
 * @param prompt Приглашение для ввода
 * @return Введенное положительное число
 * @note Завершает программу при некорректном вводе
 */
double getValidInput(const string& prompt);

/**
 * @brief Вычисляет третью сторону треугольника по теореме косинусов
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param angleRad Угол между сторонами в радианах
 * @return Длина третьей стороны
 */
double calculateThirdSide(double a, double b, double angleRad);

/**
 * @brief Вычисляет площадь треугольника
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param angleRad Угол между сторонами в радианах
 * @return Площадь треугольника
 */
double calculateArea(double a, double b, double angleRad);

/**
 * @brief Вычисляет радиус описанной окружности
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @param c Длина третьей стороны
 * @param area Площадь треугольника
 * @return Радиус описанной окружности
 */
double calculateCircumradius(double a, double b, double c, double area);

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных с проверкой
    cout << "Введите данные треугольника:\n";
    double a = getValidInput("Сторона a = ");
    double b = getValidInput("Сторона b = ");
    double angle = getValidInput("Угол между сторонами (в градусах) = ");

    // Преобразование угла в радианы
    double angleRad = angle * M_PI / 180.0;

    // Вычисление параметров треугольника
    double c = calculateThirdSide(a, b, angleRad);
    double area = calculateArea(a, b, angleRad);
    double radius = calculateCircumradius(a, b, c, area);

    // Вывод результатов
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Третья сторона (c) = " << c << endl;
    cout << "Площадь треугольника = " << area << endl;
    cout << "Радиус описанной окружности = " << radius << endl;

    return 0;
}

// Реализация функций

double getValidInput(const string& prompt) {
    double value;
    cout << prompt;
    if (!(cin >> value) || value <= 0) {
        cerr << "Ошибка: введено некорректное значение. Завершение программы.\n";
        exit(EXIT_FAILURE);
    }
    return value;
}

double calculateThirdSide(double a, double b, double angleRad) {
    // Теорема косинусов: c² = a² + b² - 2ab·cos(γ)
    return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angleRad));
}

double calculateArea(double a, double b, double angleRad) {
    // Формула площади через две стороны и угол между ними: S = (1/2)ab·sin(γ)
    return 0.5 * a * b * sin(angleRad);
}

double calculateCircumradius(double a, double b, double c, double area) {
    // Формула радиуса описанной окружности: R = abc/(4S)
    return (a * b * c) / (4 * area);
}