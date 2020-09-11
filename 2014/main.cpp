#include <iostream>
#include "problem4_09.11.cpp"
//#include "problem6_09.11.cpp"
#include "problem6_07.15.cpp"

int main() {

    // 2014-09-11 Problem 4
//    float *x = new float[5] { 1, 5, 0, 22, 7};
//    float *y = new float[5] {1, 2, 3, 4, 5};
//    square(x, y, 5); // Expected result (11, 3) 22

    // 2014-09-11 Problem 6
//    Node *l1 = new Node(1, new Node(3, new Node(5, new Node(7, new Node(9, new Node(6))))));
//    Node *l2 = new Node(3, new Node(4, new Node(8, new Node(5, new Node(7)))));
//
//    std::cout << isJoined(l1) << std::endl; // false
//    std::cout << sum(l1) << std::endl;      // 31
//    std::cout << isJoined(l2) << std::endl; // false
//    std::cout << sum(l2) <<std::endl;       // 27
//    join(l1, l2);
//    std::cout << isJoined(l1) << std::endl; // true
//    std::cout << sum(l1) << std::endl;      // 58

    Node *l1 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6))))));
    Node *l2 = new Node(7, new Node(8, new Node(4, new Node(3, new Node(9)))));
    makeCyclic(l1);
    makeCyclic(l2);
    std::cout << precedes(l1, 3, 9) << std::endl; //false
    std::cout << precedes(l1, 3, 4) << std::endl; //true
    merge(l1, l2);
    std::cout << precedes(l1, 3, 9) << std::endl; //true
    std::cout << precedes(l1, 3, 4) << std::endl; //false
    split(l1, 3, 4);
    std::cout << precedes(l1, 3, 9) << std::endl; //false
    std::cout << precedes(l1, 3, 4) << std::endl; //true
    std::cout << precedes(l1, 3, 5) << std::endl; //true
    std::cout << precedes(l1, 2, 3) << std::endl; //true


    return 0;
}