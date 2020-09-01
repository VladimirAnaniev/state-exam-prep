
#include <cmath>
#include <iostream>
#include <fstream>

/**
 * Нека разгледаме следната структура от данни за бързо търсене,
 * съхраняваща сортирана редица от цели числа: Нека имаме списък с n елемента
 * и нека с k означим горната цяла част на числото √𝑛.
 *
 * Всеки възел на списъка съдържа цяло число и два указателя.
 * Първият указател винаги сочи следващия елемент (ако има такъв).
 * За възлите, намиращи се на индекс, кратен на k, вторият указател сочи възела,
 * намиращ се на k позиции напред (ако има такъв).
 * В горния пример n = 9, k = 3.
 *
 * а) Да се напише функция readList, която по подаден път до текстов файл прочита от
 * файла сортирана редица от цели числа и конструира списък от описания по-горе тип,
 * съдържащ прочетените числа.
 * Числата са записани във файла на един ред и са разделени с интервали.
 *
 * б) Да се напише булева функция member, която по даден списък от описания тип
 * и дадено цяло число проверява дали това число се съдържа в списъка.
 * Функцията да реализира ефективен алгоритъм за търсене, който се възползва от
 * особеностите на структурата, за да минимизира броя на обходените елементи.
 *
 * Пример:ако в списъка от диаграмата по-горе търсим числото 6, при ефективния алгоритъм за
 * търсене ще бъдат последователно обходени следните елементи: 1, 4, 7, 5, 6
 * и функцията member ще върне резултат “истина”.
 *
 * За реализацията на гореописаната структура от данни и за функциите readList и member
 * не епозволено използване на библиотечни структури от данни и алгоритми,
 * но е позволено използването на стандартните функции за работа с файлове.
 */

struct Node {
    int value;
    Node *next;
    Node *skip;

    Node(int value): value(value), next(nullptr), skip(nullptr) {}
};


Node *constructList(int *numbers, int n) {
    int k = (int) sqrt(n);

    Node *first = new Node(numbers[0]);

    Node *previous = first;
    Node *skip = first;

    for (int i = 1; i < n; i++) {
        Node *node = new Node(numbers[i]);
        previous->next = node;
        previous = node;

        if (i % k == 1) {
            skip->skip = node;
            skip = node;
        }
    }

    return first;
}

Node *readList(char *filename) {
    int *numbers = new int[100];
    int n = 0;

    std::ifstream file;
    file.open(filename);
    while (!file.eof()) {
        file >> numbers[n++];
    }
    file.close();

    return constructList(numbers, 9);
}

bool member(Node *list, int n) {
    Node *current = list;

    while(current->skip != nullptr && current->skip->value <= n) {
        current = current->skip;
    }

    while(current->next != nullptr && current->next->value <= n) {
        current = current->next;
    }

    return current->value == n;
}

int main() {

    std::cout << member(readList("test"), 8);
    return 0;
}