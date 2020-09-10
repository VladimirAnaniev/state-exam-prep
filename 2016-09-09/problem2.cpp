
// Да се напише функция, която получава като параметри цяло число K и едномерен масив A с елементи различни цели числа.
// Функцията трябва да построи в паметта дърво T, съдържащо данните в масива A,
// като дървото T трябва да удовлетворява следните условия:
// 1. Всеки елемент на A се среща като възел в T точно веднъж.
// 2. Всеки възел в T има най-много K преки наследници (деца).
// 3. T е с възможно най-малка дълбочина.
// 4. Ако i < j, то A[i] да не се намира по-дълбоко от A[j] в T (т.е. да е на същата или по-малкадълбочина).
//
// Като резултат функцията да връща построеното дърво и да извежда на стандартния изход неговата дълбочина.
// Конкретното представяне на дървото в паметта е по Ваш избор.

#include <iostream>
#include <queue>

struct Node {
    Node(int value): value(value), children(nullptr) {}

    int value;
    Node **children;
};

Node *constructTree(int *arr, int n, int k) {
    std::queue<Node *> queue;
    Node *root = new Node(arr[0]);
    queue.push(root);
    // nullptr will denote the start of the next level in the tree
    queue.push(nullptr);

    int i = 1;
    int depth = 1;
    while(i < n || queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        if (node == nullptr) {
            depth++;
            queue.push(nullptr);
            continue;
        }

        Node **children = new Node*[k];
        for(int j = 0; j < k && i < n; j++, i++) {
            Node *child = new Node(arr[i]);
            children[j] = child;
            queue.push(child);
        }
        node->children = children;
    }

    std::cout << depth << std::endl;

    return root;
}



int main() {

    Node * tree = constructTree(new int[17] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, 17, 3);

    return 0;
}
