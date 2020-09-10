#include <iostream>
#include <cstring>

// Да се състави функция, която приема като параметър низ с произволна дължина
// и връща като резултат позициите на двойката ​еднакви ​символи, които са максимално отдалечени един от друг.
// Ако в низа съществуват няколко двойки максимално отдалечени символи,
// функцията да връща позициите на най-ляво разположената двойка.
// Счита се, че номерата на позициите започват от 0.
//
// Пример:
// В символния низ​ "this is just a simple example"​ най-ляво и най-дясно разположените символи​ ‘‘(интервали)​,
// са на позиции съответно 4 и 21, намират се на разстояние 17 символа един от друг
// и няма друга двойка еднакви символи, които са на по-голямо разстояние един от друг.

struct Pair {
    Pair(int first, int second): first(first), second(second) {}
    int first;
    int second;
};

Pair getIndexes(char *str) {
    size_t len = strlen(str);

    for(int k = len - 1; k > 0; k--) {
        for(int i = 0; i < len - k; i++) {
            if (str[i] == str[k + i]) {
                return Pair(i, k + i);
            }
        }
    }
    return Pair(-1, -1);
}

int main1() {
    Pair p = getIndexes("this is just a simple example");
    std::cout << p.first << " " << p.second << std::endl;
    return 0;
}