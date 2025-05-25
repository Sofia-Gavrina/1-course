#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
 * @brief Функция выделения памяти под матрицу
 * @param rows строки
 * @param cols столбцы
 * @return результат выделения
 */
int** allocateMatrix(const size_t rows, const size_t cols);

/**
 * @brief Функция для ввода числа с проверкой на валидность
 * @return результат считывания
 */
int getValue();

/**
 * @brief проверка на положительную размерность
 * @param rows строки
 * @param cols столбцы
 * @return результат проверки
 */
bool validatePositiveDimensions(const int rows, const int cols);

/**
 * @brief Функция для заполнения матрицы случайными числами в заданном диапазоне
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 * @param minRange диапазон от
 * @param maxRange диапазон до
 */
void populateRandom(int** mat, const size_t rows, const size_t cols, const int minRange, const int maxRange);

/**
 * @brief Функция для заполнения матрицы с клавиатуры в заданном диапазоне
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 * @param minRange диапазон от
 * @param maxRange диапазон до
 */
void populateFromInput(int** mat, const size_t rows, const size_t cols, const int minRange, const int maxRange);

/**
 * @brief Функция для вывода матрицы на экран
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 */
void displayMatrix(int** mat, const size_t rows, const size_t cols);

/**
 * @brief Функция для замены минимального элемента каждой строки на ноль
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 */
void swapMinWithZero(int** mat, const size_t rows, const size_t cols);

/**
 * @brief Функция для копирования матрицы
 * @param matrix массив
 * @param n строки
 * @param m столбцы
 */
int** copyMatrix(int** matrix, const size_t n, const size_t m);
/**
 * @brief Функция для освобождения памяти, выделенной под матрицу
 * @param mat массив
 * @param rows строки
 */
void freeMatrix(int** mat, const size_t rows);

/**
 * @brief Функция для удаления столбцов с нечетным положительным элементом
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 * @param newMatrix новый массив
 * @param updatedCols новое количество столбцов
 */
void removeOddPositiveColumns(int** mat, const size_t rows, const size_t cols, int** newMatrix, const size_t updatedCols);

/**
 * @brief Функция для подсчета количества новых столбцов с нечетным положительным элементом
 * @param mat массив
 * @param rows строки
 * @param cols столбцы
 */
size_t countUpdatedColumns(int** mat, const size_t rows, const size_t cols);

int main() {
  cout << "Введите количество строк (n): ";
  int rows = getValue();
  cout << "Введите количество столбцов (m): ";
  int cols = getValue();

  if (!validatePositiveDimensions(rows, cols)) {
    cerr << "Ошибка: количество строк и столбцов должно быть положительным числом.\n";
    return 1;
  }

  int** matrix = allocateMatrix(rows, cols);

  cout << "Введите диапазон значений для заполнения матрицы (минимальное и максимальное значение): ";
  int minRange = getValue();
  int maxRange = getValue();

  cout << "Выберите режим заполнения матрицы:\n";
  cout << "1. Случайные числа\n";
  cout << "2. Ввод с клавиатуры\n";
  int mode = getValue();

  switch (mode) {
    case 1:
      populateRandom(matrix, rows, cols, minRange, maxRange);
      break;
    case 2:
      populateFromInput(matrix, rows, cols, minRange, maxRange);
      break;
    default:
      cerr << "Ошибка: некорректный выбор режима заполнения.\n";
      return 1;
  }

  displayMatrix(matrix, rows, cols);

  int** matrixTask1 = copyMatrix(matrix, rows, cols);
  swapMinWithZero(matrixTask1, rows, cols);
  cout << "Матрица после замены минимальных элементов каждой строки на ноль:\n";
  displayMatrix(matrixTask1, rows, cols);
  freeMatrix(matrixTask1, rows);

  size_t updatedCols = countUpdatedColumns(matrix, rows, cols);
  int** matrixTask2 = allocateMatrix(rows, updatedCols);
  removeOddPositiveColumns(matrix, rows, cols, matrixTask2, updatedCols);
  cout << "Матрица после удаления столбцов с нечетным положительным элементом:\n";
  displayMatrix(matrixTask2, rows, updatedCols);
  freeMatrix(matrixTask2, rows);

  freeMatrix(matrix, rows);

  return 0;
}

int** allocateMatrix(const size_t rows, const size_t cols) {
  int** mat = new int*[rows];
  for (size_t i = 0; i < rows; ++i) {
    mat[i] = new int[cols]();
  }
  return mat;
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

bool validatePositiveDimensions(int rows, int cols) { return (rows > 0 && cols > 0); }

void populateRandom(int** mat, size_t rows, size_t cols, int minRange, int maxRange) {
  srand(time(NULL));
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      mat[i][j] = rand() % (maxRange - minRange + 1) + minRange;
    }
  }
}

void populateFromInput(int** mat, const size_t rows, const size_t cols, const int minRange, const int maxRange) {
  cout << "Введите " << rows * cols << " целых чисел для заполнения матрицы построчно:\n";
  for (size_t i = 0; i < rows; ++i) {
    cout << "Строка " << i + 1 << ":\n";
    for (size_t j = 0; j < cols; ++j) {
      cout << "Элемент [" << i << "][" << j << "]: ";
      mat[i][j] = getValue();
      if (mat[i][j] > maxRange || mat[i][j] < minRange) {
        cout << "не входит в диапазон!" << endl;
        --j;
      }
    }
  }
}

void displayMatrix(int** mat, size_t rows, size_t cols) {
  cout << "Матрица " << rows << "x" << cols << ":\n";
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      cout << mat[i][j] << "\t";
    }
    cout << "\n";
  }
}

void swapMinWithZero(int** mat, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    int min_val = mat[i][0];
    size_t min_idx = 0;
    for (size_t j = 1; j < cols; ++j) {
      if (mat[i][j] < min_val) {
        min_val = mat[i][j];
        min_idx = j;
      }
    }
    mat[i][min_idx] = 0;
  }
}

int** copyMatrix(int** matrix, const size_t n, const size_t m) {
  int** newMatrix = allocateMatrix(n, m);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      newMatrix[i][j] = matrix[i][j];
    }
  }
  return newMatrix;
}

void freeMatrix(int** mat, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] mat[i];
  }
  delete[] mat;
}

void removeOddPositiveColumns(int** mat, size_t rows, size_t cols, int** newMatrix, const size_t updatedCols) {
  bool* toDelete = new bool[cols];
  for (size_t j = 0; j < cols; ++j) {
    toDelete[j] = false;
    for (size_t i = 0; i < rows; ++i) {
      if (mat[i][j] > 0 && mat[i][j] % 2 == 1) {
        toDelete[j] = true;
        break;
      }
    }
  }

  size_t colIndex = 0;
  for (size_t j = 0; j < cols; ++j) {
    if (!toDelete[j]) {
      for (size_t i = 0; i < rows; ++i) {
        newMatrix[i][colIndex] = mat[i][j];
      }
      ++colIndex;
    }
  }

  delete[] toDelete;
}

size_t countUpdatedColumns(int** mat, const size_t rows, const size_t cols) {
  size_t validCols = cols;
  for (size_t j = 0; j < cols; ++j) {
    for (size_t i = 0; i < rows; ++i) {
      if (mat[i][j] > 0 && mat[i][j] % 2 == 1) {
        --validCols;
        break;
      }
    }
  }
  return validCols;
}
