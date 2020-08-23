#include <iostream>
#include <cstring>
#include <fstream>

/**
 * Троично дърво от латински букви ще наричаме следната структура:
 * - Празното дърво е троично дърво от латински букви;
 * - Ако Т1, Т2и Т3 са троични дървета от латински букви, а xе латинска буква,
 *   то наредената четворка <x, Т1, Т2, Т3> също е троично дърво от латински букви.
 *
 * а) Да се напише функция readLast, която по дадено троично дърво от латински букви намира думата,
 * която може да се прочете отляво надясно в последното му ниво.
 *
 * Ниво на троично дърво от латински букви наричаме списък от възли в дървото,
 * които са равноотдалечени от корена.
 *
 * Пример:за дървото вдясно функцията readLast трябва да връща думата “cat”.
 *
 * Представянето на дървото е по Ваш избор.
 * Опишете избраното от Вас представяне.
 *
 * б) Да се напише функция serialize, която по дадени:
 *   (1) троично дърво от латински букви и
 *   (2) низ, описващ път до файл, записва дървото в текстов файл.
 *
 * Текстовото представяне на троично дърво да бъде следното:
 * - Текстовото представяне на празното дърво е звездичка (“*”);
 * - Текстовото представяне на троичното дърво <x, Т1, Т2, Т3> е “(x T1 T2 T3)”,
 *   където T1, T2и T3са текстовите представяния съответно на Т1, Т2и Т3.
 *
 *      b
 *    /  |
 *   x   y
 * / | \  \
 * p q r   s
 *    / \  |
 *   c  a  t
 * Пример:Текстовото представянето на дървото горе е:
 * (b (x (p * * *) (q * * *) (r (c * * *) * (a * * *))) (y * * (s * (t * * *) *)) *)
 *
 * За реализацията на функциите readLastи serialize е позволено използването на
 * стандартните за съответния език библиотечни функции.
 */

struct Node {
    Node(char value, Node *left, Node *middle, Node *right) :
            value(value), left(left), middle(middle), right(right) {}

    explicit Node(char value) :
            value(value), left(nullptr), middle(nullptr), right(nullptr) {}

    char value;
    Node *left;
    Node *middle;
    Node *right;
};

void readLastDfs(Node *tree, char *str, int currentDepth, int depth) {
    if (!tree) {
        return;
    }

    readLastDfs(tree->left, str, currentDepth + 1, depth);
    readLastDfs(tree->middle, str, currentDepth + 1, depth);
    readLastDfs(tree->right, str, currentDepth + 1, depth);

    if (currentDepth == depth) {
        size_t len = strlen(str);
        str[len] = tree->value;
    }
}

int maxDepth(Node *tree) {
    if (!tree) {
        return 0;
    }

    int leftDepth = 1 + maxDepth(tree->left);
    int middleDepth = 1 + maxDepth(tree->middle);
    int rightDepth = 1 + maxDepth(tree->right);

    return std::max(std::max(leftDepth, middleDepth), rightDepth);
}

char *readLast(Node *tree) {
    char *str = new char[256]{'\0'};

    readLastDfs(tree, str, 1, maxDepth(tree));

    return str;
}

std::string serialize(Node *tree) {
    if (!tree) {
        return "*";
    }

    std::string str = "(";
    str.push_back(tree->value);
    str.push_back(' ');
    str.append(serialize(tree->left));
    str.push_back(' ');
    str.append(serialize(tree->middle));
    str.push_back(' ');
    str.append(serialize(tree->right));
    str.push_back(')');

    return str;
}

void writeToFile(std::string filename, std::string value) {
    std::ofstream file;
    file.open(filename);
    file << value;
    file.close();
}


int main() {

    Node *tree =
            new Node('b',
                     new Node('x',
                              new Node('p'),
                              new Node('q'),
                              new Node('r',
                                       new Node('c'),
                                       nullptr,
                                       new Node('a'))),
                     new Node('y',
                              nullptr,
                              nullptr,
                              new Node('s',
                                       nullptr,
                                       new Node('t'),
                                       nullptr)),
                     nullptr);

    std::cout << readLast(tree) << std::endl;
    std::cout << serialize(tree) << std::endl;
    writeToFile("test", serialize(tree));

    return 0;
}