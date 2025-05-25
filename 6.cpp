#include <cstdlib>  // для size_t
#include <iostream>

using namespace std;

/**
 * @brief Считывание параметра типа double из stdin
 * @return результат считывания
 */
int getValue();

/**
 * @brief Функция для заполнения массива случайными числами
 * @param data массив
 * @param size размер массива
 * @param minVal мин число
 * @param maxVal макс число
 */
void populateRandom(int* data, const size_t size, const int minVal, const int maxVal); 

/**
 * @brief Функция для заполнения массива с клавиатуры
 * @param data массив
 * @param size размер массива
 * @param minVal мин число
 * @param maxVal макс число
 */
void populateFromInput(int* data, const size_t size, const int minVal, const int maxVal);  

/**
 * @brief Функция для поиска суммы четных отрицательных элементов
 * @param data массив
 * @param size размер массива
 * @return сумма
 */
int calculateEvenNegativeSum(const int* data, const size_t size); 

/**
 * @brief Функция для вывода индексов элементов, кратных 3 и 6
 * @param data массив
 * @param size размер массива
 */
void displayDivisibleBy3And6(const int* data, const size_t size); 

/**
 * @brief Функция для нахождения минимального и максимального элементов массива
 * @param data массив
 * @param size размер массива
 * @param minIdx ссылка для отслеживания индексов минимального числа
 * @param maxIdx ссылка для отслеживания индексов максимального числа
 */
void findExtremes(const int* data, const size_t size, size_t& minIdx, size_t& maxIdx);  

/**
 * @brief Функция для замены нулями элементов между минимальным и максимальным,
 * кроме самих минимального и максимального
 * @param data массив
 * @param size размер массива
 */
void zeroOutBetweenExtremes(int* data, const size_t size); 

/**
 * @brief Вывод массива в консоль
 * @param data массив
 * @param size размер массива
 */
void printArray(const int* data, const size_t size);  

/**
 * @brief точка входа в программу
 * @return 0
 */
int main() {
  cout << "Введите размер массива: ";
  size_t arraySize = getValue();
  if (arraySize <= 0) {
    cout << "неправильный размер!\n";
    return 1;
  }

  cout << "Выберите режим заполнения массива:\n";
  cout << "1. Случайные числа\n";
  cout << "2. Ввод с клавиатуры\n";
  int mode = getValue();
  int* array = new int[arraySize];

  cout << "min value:\n";
  int minValue = getValue();
  cout << "max value:\n";
  int maxValue = getValue();

  if (minValue > maxValue) {
    cout << "Плохой отрезок\n";
    return 1;
  }

if (mode == 1) {
    populateRandom(array, arraySize, minValue, maxValue);
} else if (mode == 2) {
    populateFromInput(array, arraySize, minValue, maxValue);
} else {
    cerr << "Ошибка: некорректный выбор режима заполнения.\n";
    delete[] array;
    return 1;
}

  cout << "Массив:\n";
  printArray(array, arraySize);
  cout << "\n";


  int evenNegativeSum = calculateEvenNegativeSum(array, arraySize);
  cout << "Сумма четных отрицательных элементов: " << evenNegativeSum << "\n";

  displayDivisibleBy3And6(array, arraySize);


  zeroOutBetweenExtremes(array, arraySize);

  cout << "Измененный массив (элементы между минимальным и максимальным "
          "заменены на нули):\n";
  printArray(array, arraySize);
  cout << "\n";

  delete[] array;
  return 0;
}

void printArray(const int* data, const size_t size) {
  for (size_t i = 0; i < size; ++i) {
    cout << data[i] << " ";
  }
}

int getValue() {
  int value;
  cin >> value;
  if (cin.fail()) {
    cout << "Некорректное значение" << endl;
    abort();
  }
  return value;
}

void populateRandom(int* data, const size_t size, const int minVal, const int maxVal) { 
  srand(time(NULL));  
  for (size_t i = 0; i < size; ++i) {
    data[i] = rand() % (maxVal - minVal + 1) + minVal;
  }
}

void populateFromInput(int* data, const size_t size, const int minVal, const int maxVal) { 
  cout << "Введите " << size << " целых чисел для массива:\n";
  for (size_t i = 0; i < size; ++i) {
    data[i] = getValue();
    if (data[i] > maxVal || data[i] < minVal) {
      cerr << "Ошибка ввода данных.\n";
      delete[] data;
      abort();
    }
  }
}

int calculateEvenNegativeSum(const int* data, const size_t size) { 
  int totalSum = 0;
  for (size_t i = 0; i < size; ++i) {
    if (data[i] < 0 && data[i] % 2 == 0) {
      totalSum += data[i];
    }
  }
  return totalSum;
}

void displayDivisibleBy3And6(const int* data, const size_t size) {
  cout << "Индексы элементов, значения которых кратны 3 и 6:\n";
  for (size_t i = 0; i < size; ++i) {
    if (data[i] != 0 && data[i] % 3 == 0 && data[i] % 6 == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

void findExtremes(const int* data, const size_t size, size_t& minIdx, size_t& maxIdx) {  
  int minValue = data[0], maxValue = data[0];
  minIdx = 0;
  maxIdx = 0;

  for (size_t i = 1; i < size; ++i) {
    if (data[i] < minValue) {
      minValue = data[i];
      minIdx = i;
    }
    if (data[i] > maxValue) {
      maxValue = data[i];
      maxIdx = i;
    }
  }
}

void zeroOutBetweenExtremes(int* data, const size_t size) {
  size_t minIdx, maxIdx;
  findExtremes(data, size, minIdx, maxIdx);

  size_t start = min(minIdx, maxIdx) + 1;
  size_t end = max(minIdx, maxIdx);

  for (size_t i = start; i < end; ++i) {
    data[i] = 0;
  }
}
