#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * @brief Считывание параметра типа double из stdin
 * @return результат считывания
 */
double getValue();

/**
 * @brief точка входа в программу
 * @return 0
 */

 int main() {
  cout << "Введите начальное значение x: ";
  double x_initial_value = getValue();
  cout << "Введите конечное значение x: ";
  double x_final_value = getValue();
  
  if (x_initial_value > x_final_value) {
    cout << "Неверный отрезок" << endl;
    return 1;
  }

  cout << "Введите шаг приращения: ";
  double step = getValue();
  if (step <= 0) {
    cout << "Неверное приращение функции" << endl;
    return 1;
  }

  cout << fixed << setprecision(4);
  cout << setw(20) << "x" << setw(30) << "y" << endl;


  for (double x = x_initial_value; x < x_final_value + step; x += step) {
    if (x > 1) {
      cout << setw(20) << x << setw(30) << " Нет решения" << endl;
    } else {
      double y = sqrt(1 - x) - cos(sqrt(1 - x));
      cout << setw(20) << x << setw(30) << y << endl;
    }
  }

  return 0;
}

double getValue() {
  double value;
  cin >> value;
  if (cin.fail()) {
    cout << "Некорректное значение" << endl;
    abort();
  }
  return value;
}