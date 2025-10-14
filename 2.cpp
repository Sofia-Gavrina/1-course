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
 * @brief Вычисляет радиус описанной окружности
 * @param a Длина первой стороны (const)
 * @param b Длина второй стороны (const)
 * @param c Длина третьей стороны (const)
 * @param area Площадь треугольника (const)
 * @return Радиус описанной окружности
 */
double calculateCircumradius(const double a, const double b, const double c, const double area);

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении, 1 при ошибке
 * @note Вычисляет параметры треугольника по двум сторонам и углу между ними
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

    // Вывод результатов
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Третья сторона (c) = " << c << endl;
    cout << "Площадь треугольника = " << area << endl;
    cout << "Радиус описанной окружности = " << radius << endl;

    return 0;
}

double getValidInput(const string& prompt) {
    double value = 0.0;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cerr << "Ошибка: введите положительное число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double calculateThirdSide(const double a, const double b, const double angleRad) {
    return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angleRad));
}

double calculateArea(const double a, const double b, const double angleRad) {
    return 0.5 * a * b * sin(angleRad);
}

double calculateCircumradius(const double a, const double b, const double c, const double area) {
    if (area <= numeric_limits<double>::epsilon()) {
        cerr << "Ошибка: площадь треугольника слишком мала для вычисления радиуса.\n";
        return NAN;
    }
    return (a * b * c) / (4 * area);
}
