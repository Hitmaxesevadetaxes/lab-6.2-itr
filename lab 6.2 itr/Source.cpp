#include <iostream>
#include <iomanip> // ��� ������������� ���������
#include <cstdlib> // ��� rand() �� srand()
#include <ctime>   // ��� time()
#include <Windows.h> // ��� SetConsoleCP � SetConsoleOutputCP

// ������� ��� ��������� ���������� ����� � �����
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// ������� ��� ��������� ������
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// ������� ��� ����������� ������� ���������� ��������� ��������
int findMinOddIndex(const int arr[], int size) {
    int minOddValue = INT_MAX; // ��������� �������� �� �������� int
    int minOddIndex = -1; // ���� ��������� �������� ����, ��������� -1

    // ��������� ����� ����� � ������ ��������� �������� �������
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0 && arr[i] < minOddValue) { // �������� �� ������ �� �������� �����
            minOddValue = arr[i];
            minOddIndex = i;
        }
    }

    return minOddIndex;
}

// ������� ��� ���� ������ (����� ���������� ��������� ����� �� 0)
void modifyArray(int arr[], int size, int index) {
    if (index != -1) {
        arr[index] = 0; // ����� ���������� ��������� �������� �� 0
    }
}

int main() {
    // ������������ ��������� ��� ������ � ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 10; // ����� ������
    int arr[size];

    // ����������� ���������� ���������� �����
    srand(static_cast<unsigned>(time(0)));

    // �������� �����
    generateArray(arr, size, -10, 35);

    // �������� ������������ �����
    std::cout << "���������� �����:\n";
    printArray(arr, size);

    // ��������� ������ ���������� ��������� ��������
    int minOddIndex = findMinOddIndex(arr, size);

    // �������� ������ � �������� ���������� ��������� ��������, ���� �� ���������
    if (minOddIndex != -1) {
        std::cout << "������ ���������� ��������� ��������: " << minOddIndex << std::endl;
        std::cout << "�������� ���������� ��������� ��������: " << arr[minOddIndex] << std::endl;
    }
    else {
        std::cout << "��������� �������� ������� �� ��������.\n";
    }

    // ���������� �����, ���� ��������� �������� �������
    modifyArray(arr, size, minOddIndex);

    // �������� ������������� ����� (���� �������)
    std::cout << "������� �����:\n";
    printArray(arr, size);

    return 0;
}
