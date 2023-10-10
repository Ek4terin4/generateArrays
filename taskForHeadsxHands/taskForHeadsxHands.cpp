// Copyright 2023 Ek4terin4
#include <iostream>
#include <vector>
#include <algorithm>


// Получаем массив с отсортированными массивами
std::vector<std::vector<int>> generateArrays(int n) {
    std::vector<std::vector<int>> arrays;

    for (int i = 0; i < n; i++) {
        std::vector<int> array;

        int size = rand() % 10 + 1;  // Генерация случайного числа от 1 до 10 для задания размера массива
        while (std::find_if(arrays.begin(), arrays.end(), [size](const std::vector<int>& arr) { return arr.size() == size; }) != arrays.end()) {
            size = rand() % 100 + 1;  // Размеры массивов должны быть уникальными
        }

        for (int j = 0; j < size; j++) {
            int num = rand() % 100 + 1;  // Генерация случайного числа от 0 до 100 для заполнения массивов
            array.push_back(num); // Добавление чисел в массив
        }

        arrays.push_back(array); // Добавление массива в массив массивов
    }

    for (int i = 0; i < arrays.size(); i++) {
        if (i % 2 == 0) {
            std::sort(arrays[i].begin(), arrays[i].end()); // Сортировка по возрастанию для массивов с чётным порядковым номером
        } else {
            std::sort(arrays[i].begin(), arrays[i].end(), std::greater<int>()); // Сортировка по убыванию для массивов с нечётным порядковым номером
        }
    }

    return arrays;
}


// Проверка работы функции generateSortArrays
int main() {
    setlocale(LC_ALL, "Russian"); // Вывод русских символов в консоль
    srand(time(nullptr));

    int n;
    std::cout << "Введите количество массивов: ";
    std::cin >> n;

    if (n > 0) { // Проверка введённого размера массива
        std::vector<std::vector<int>> sortedArrays = generateArrays(n); 

        // Вывод результата
        std::cout << "\nОтсортированные массивы:\n";
        for (const auto& array : sortedArrays) {
            for (const auto& num : array) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "\nРазмер массива должен быть больше 0!\n";
    }

    return 0;
}