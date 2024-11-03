#include <iostream>
#include <vector>

// Шаблонная функция для числовых типов
template <typename T>
T square(const T& value) {
    return value * value;
}

// Перегрузка шаблонной функции для вектора
template <typename T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const T& element : vec) {
        result.push_back(square(element));
    }
    return result;
}

// Функция для вывода числового значения в формате [IN] и [OUT]
template <typename T>
void printSquareResult(const T& value) {
    std::cout << "[IN]: " << value << std::endl;
    std::cout << "[OUT]: " << square(value) << std::endl;
}

// Функция для вывода вектора в формате [IN] и [OUT]
template <typename T>
void printSquareResult(const std::vector<T>& vec) {
    std::cout << "[IN]: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    std::vector<T> squaredVec = square(vec);
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < squaredVec.size(); ++i) {
        std::cout << squaredVec[i];
        if (i < squaredVec.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // Тест для числового значения
    int num = 4;
    printSquareResult(num);

    // Тест для вектора чисел
    std::vector<int> vec = {-1, 4, 8};
    printSquareResult(vec);

    return 0;
}
