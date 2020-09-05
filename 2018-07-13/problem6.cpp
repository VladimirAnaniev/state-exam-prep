#include <iostream>
#include <algorithm>

/**
 * Във всяка от n панички са поставени съответно a1, a2, ..., an жълтици (ai > 0).
 *
 * Задачата Ви е да изберете няколко панички така, че като съберете всички жълтици от тях,
 * полученият брой жълтици да се дели на 3 и да е максимален.
 *
 * Предложете възможно най-ефикасен алгоритъм за тази цел.
 *
 * Упътване 1:
 * Разсъждавайте за паничките, които нямада бъдат включени в оптималното решение.
 * Съобразете, че техният брой е малък.
 * Започнете с въпроса: при какво условие можем да вземем жълтиците от всички панички?
 *
 * Упътване 2:
 * Друг възможна техника за решаване на задачата е динамично програмиране.
 */

int dyn[64][3] = {0};

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

int maxSum(const int *arr, int n) {


    for (int i = 0; i < n; i++) {
        for (int r = 0; r < 3; r++) {
            int reminder = arr[i] % 3;
            int complement = mod(r - reminder, 3);

            int with = dyn[i][complement] + arr[i];
            int without = dyn[i][r];

            if (with % 3 == r && with > without) {
                dyn[i + 1][r] = with;
            } else {
                dyn[i + 1][r] = without;
            }
        }
    }

    return dyn[n][0];
}

int main() {
    int *arr = new int[10]{3, 5, 1, 7, 10, 9, 6, 3, 11, 17};

    std::cout << maxSum(arr, 10);

    return 0;
}