
#include <iostream>

// Следната задача да се реши на един от езиците за програмиране C++ или Java.
// Да се обозначи явно на кой от двата езика е решавана задачата.
// При решението на задачата да не се използват библиотеки за работа със структури от данни.
//
// а) Да се дефинира подходяща ​индуктивна (рекурсивна)​ структура от данни,
// позволяваща представянето в паметта на програмата на възел на дърво от цели числа (​int​),
// за което всеки връх може да има произволен брой наследници (0, 1 или повече).

struct Node {
    Node(int x): value(x), children(nullptr), n(0) {}
    Node(int x, Node **children, int n): value(x), children(children), n(n) {}

    int value;
    Node **children;
    int n;
};


// б) Да се дефинира ​рекурсивна​ функция (или статичен метод)
// [булев тип] member ([подходящ тип]root, int x)
// чиято стойност е истина точно тогава, когато в дървото с корен,
// представен от параметъра ​root​,съществува възел със стойност​ x​.
bool member(Node *root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == x) {
        return true;
    }

    for(int i = 0; i < root->n; i++) {
        if (member(root->children[i], x)) {
            return true;
        }
    }

    return false;
}


// в) Да се дефинира рекурсивна функция (или статичен метод)
// void filterOdd ([подходящ тип] root)
// Функцията да премахва (чрез мутация) всяко поддърво ​t’​ на дървото с корен,
// представен отпараметъра ​root​, за което е изпълнено,
// че коренът на​ t’​ е със стойност нечетно число.

void deleteTree(Node *root) {
    // release memory
}

void filterOdd(Node *root) {
    if(root == nullptr) {
        return;
    }
    if (root->value % 2 == 1) {
        deleteTree(root);
        return;
    }

    for (int i = 0; i < root->n; i++) {
        if (root->children[i] != nullptr && root->children[i]->value % 2 == 1) {
            deleteTree(root->children[i]);
            root->children[i] = nullptr;
        }
    }
}


int main() {
    Node *root = new Node(8, new Node *[2]{
            new Node(2),
            new Node(3, new Node *[3]{
                    new Node(4),
                    new Node(5),
                    new Node(6)
            }, 3)
    }, 2);

    std::cout << member(root, 8); //true
    std::cout << member(root, 6); //true
    std::cout << member(root, 9); //false
    std::cout << member(root, 2); //true

    std::cout << std::endl;

    filterOdd(root);
    std::cout << member(root, 2); //true
    std::cout << member(root, 8); //true
    std::cout << member(root, 3); //false
    std::cout << member(root, 6); //false
    return 0;
}