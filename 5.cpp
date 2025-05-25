#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Функция для вычисления следующего элемента последовательности
 * @param curr текущий член последовательности
 * @param idx номер члена последовательности
 * @return элемент
 */
double calculateNext(const double curr, const int idx);  

/**
 * @brief Функция для вычисления суммы первых n членов последовательности
 * @param count количество членов последовательности
 * @return сумма
 */
double computeSumFirstN(int count);  // изменено с sumFirstN

/**
 * @brief Функция для вычисления суммы всех членов последовательности, по модулю
 * не меньших заданного числа epsilon
 * @param epsilon число е
 * @return сумма
 */
double computeSumWithLimit(double epsilon);  

/**
 * @brief Считывание параметра
 * @return результат считывания
 */
double getValue();

/**
 * @brief точка входа в программу
 * @return 0
 */

int main() {
  const double initial = -0.5;

  cout << "Введите количество первых членов последовательности (n): ";
  int quantity = (int)getValue();
  if (quantity <= 0) {
    cout << "err size" << endl;
    return 1;
  }

  cout << "Введите значение порога (e): ";
  double epsilon = getValue();
  if (fabs(epsilon) < fabs(initial) || epsilon < 0) {
    cout << "Значение не может быть меньше первого элемента последовательности";
  }

  double sum_n_num = computeSumFirstN(quantity);
  cout << "Сумма первых " << quantity << " членов последовательности: " << sum_n_num
       << endl;

  double sum_e = computeSumWithLimit(epsilon);
  cout << "Сумма членов последовательности по модулю не меньших " << epsilon << ": "
       << sum_e << endl;

  return 0;
}

double calculateNext(const double curr, const int idx) {
  return curr * (-1.0) * (idx) / ((double)idx * (double)idx - 1);
}

double computeSumFirstN(int count) { 
  double total = 0.0;
  double curr_value = -0.5;
  total += curr_value;

  for (int i = 2; i <= count; ++i) {
    curr_value = calculateNext(curr_value, i);
    total += curr_value;
    cout << "ind=" << i << " cur=" << curr_value << endl;
  }

  return total;
}

double computeSumWithLimit(double epsilon) { 
  double total = 0.0;
  double current_value = -0.5;
  int idx = 2;
  while (abs(current_value) >= epsilon) {
    total += current_value;
    current_value = calculateNext(current_value, idx);
    idx++;
  }
  return total;
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
