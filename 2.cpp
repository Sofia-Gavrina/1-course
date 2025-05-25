#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Функция для безопасного ввода чисел
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cout << "Ошибка: введите положительное число!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных с проверкой
    cout << "Введите данные треугольника:\n";
    double a = getValidInput("Сторона a = ");
    double b = getValidInput("Сторона b = ");
    double angle = getValidInput("Угол между сторонами (в градусах) = ");

    // Преобразование угла в радианы
    double angleRad = angle * M_PI / 180.0;

    // Вычисление третьей стороны по теореме косинусов: c² = a² + b² - 2ab*cos(γ)
    double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angleRad));

    // Вычисление площади по формуле: S = (1/2)*a*b*sin(γ)
    double area = 0.5 * a * b * sin(angleRad);

    // Вычисление радиуса описанной окружности по формуле: R = (a*b*c)/(4*S)
    double radius = (a * b * c) / (4 * area);

    // Вывод результатов
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Третья сторона (c) = " << c << endl;
    cout << "Площадь треугольника = " << area << endl;
    cout << "Радиус описанной окружности = " << radius << endl;

    return 0;
}