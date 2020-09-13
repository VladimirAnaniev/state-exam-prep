#include <iostream>
#include "problem3_07.15.cpp"
#include "problem3_09.08.cpp"

int main() {
    char *strings[7] {"string", "ginrts", "ringst", "strong", "spong", "shpong", "pongs"};
    std::cout << maxAnagrams(strings, 7) << std::endl;


    reverse("1;;2;3;4;;5.");
    std::cout << std::endl;
    reverse("Some text, and then --- Surprise!");
    std::cout << std::endl;
    reverse("... this starts with punctioation and ends with_word");
    return 0;
}