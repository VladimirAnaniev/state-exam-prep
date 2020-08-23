#include <iostream>
#include <cstring>

/**
 * Да се дефинира функция sortLex, която получава като аргументи положителното число n
 * и масив a, съдържащ nна брой цели неотрицателни числа,
 * и ги сортира във възходящ ред относно лексикографската наредба
 * (например, 123 е преди 9 по лексикографската наредба).
 *
 * Да се напише кратка програма, в която да се демонстрира използването на функцията sortLex.
 * За реализацията на функцията sortLex не епозволено използването на стандартни библиотечни функции.
 *
 * Пример:
 * При подаден масив {13,14,7,2018,9,0}, след изпълнение на функцията sortLex
 * масивът ще бъде подреден по следния начин: {0,13,14,2018,7,9}.
 */

int compare(unsigned a, unsigned b) {
    char buffA[32];
    char buffB[32];

    sprintf(buffA, "%d", a);
    sprintf(buffB, "%d", b);

    return strcmp(buffA, buffB);
}

void sortLex(unsigned *arr, int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int j = i; j < n; ++j) {
            if (compare(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }

        unsigned minValue = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
}

int main2() {

    unsigned *arr = new unsigned[6]{13, 14, 7, 2018, 9, 0};

    sortLex(arr, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << ' ';
    }

    return 0;
}