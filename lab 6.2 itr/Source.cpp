#include <iostream>
#include <iomanip> // для форматованого виведення
#include <cstdlib> // для rand() та srand()
#include <ctime>   // для time()
#include <Windows.h> // для SetConsoleCP і SetConsoleOutputCP

// Функція для генерації випадкових чисел у масиві
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// Функція для виведення масиву
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// Функція для знаходження індексу найменшого непарного елемента
int findMinOddIndex(const int arr[], int size) {
    int minOddValue = INT_MAX; // Початкове значення як максимум int
    int minOddIndex = -1; // Якщо непарного елемента немає, повертаємо -1

    // Проходимо через масив і шукаємо найменший непарний елемент
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0 && arr[i] < minOddValue) { // Непарний та менший за поточний мінімум
            minOddValue = arr[i];
            minOddIndex = i;
        }
    }

    return minOddIndex;
}

// Функція для зміни масиву (заміна найменшого непарного числа на 0)
void modifyArray(int arr[], int size, int index) {
    if (index != -1) {
        arr[index] = 0; // Заміна найменшого непарного елемента на 0
    }
}

int main() {
    // Встановлюємо кодування для роботи з кирилицею
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 10; // Розмір масиву
    int arr[size];

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // Генеруємо масив
    generateArray(arr, size, -10, 35);

    // Виводимо згенерований масив
    std::cout << "Початковий масив:\n";
    printArray(arr, size);

    // Знаходимо індекс найменшого непарного елемента
    int minOddIndex = findMinOddIndex(arr, size);

    // Виводимо індекс і значення найменшого непарного елемента, якщо він знайдений
    if (minOddIndex != -1) {
        std::cout << "Індекс найменшого непарного елемента: " << minOddIndex << std::endl;
        std::cout << "Значення найменшого непарного елемента: " << arr[minOddIndex] << std::endl;
    }
    else {
        std::cout << "Найменший непарний елемент не знайдено.\n";
    }

    // Модифікуємо масив, якщо знайдений непарний елемент
    modifyArray(arr, size, minOddIndex);

    // Виводимо модифікований масив (якщо змінений)
    std::cout << "Змінений масив:\n";
    printArray(arr, size);

    return 0;
}
