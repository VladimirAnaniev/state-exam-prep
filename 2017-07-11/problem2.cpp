#include <iostream>

/**
 * Напишете функция, която получава като аргумент свързан списък с елементи цели числа и го сортира.
 * Списъкът е представен и подаден на функцията по избран от вас начин.
 * Напишете кратка програма, която създава списък, добавя в него няколко елемента, и
 * зползва функцията за сортиране и извежда на екрана резултата.
 *
 * Използвайтеезиците JAVA, C или C++, но безбиблиотечни структури данни и алгоритми.
 */

struct Node {
    Node(int value, Node *next): value(value), next(next) {}
    int value;
    Node *next;
};

Node* getMinNode(Node *list) {
    Node *min = list;

    Node *current = list;
    while(current != nullptr) {
        if (current->value < min->value) {
            min = current;
        }
        current = current->next;
    }

    return min;
}

void sort(Node *list) {
    Node *current = list;
    while(current != nullptr) {
        Node* min = getMinNode(current);

        int minValue = min->value;
        min->value = current->value;
        current->value = minValue;

        current = current->next;
    }
}

void print(Node* list) {
    while (list != nullptr) {
        std::cout << list->value << ' ';
        list = list->next;
    }
    std::cout << '\n';
}

int main() {

    Node *list = new Node(5, new Node(3, new Node(1, new Node(4, nullptr))));

    sort(list);

    print(list);

    return 0;
}