#include "stack"
#include "queue"

bool isSymbol(char c) {
    return (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <='z') ||
            (c >= '0' && c <= '9') ||
            c == '_';
}

void addString(char *start, int len, std::stack<char *> &words, std::queue<char *> &punctuation) {
    char *copy = new char[len + 1] {'\0'};
    for(int i = 0; i < len; i++) {
        copy[i] = start[i];
    }
    if (isSymbol(*start)) {
        words.push(copy);
    } else {
        punctuation.push(copy);
    }
}

void printWord(std::stack<char *> &words, std::queue<char *> &punctuation, bool startsWithWord) {
    if (startsWithWord) {
        std::cout << words.top();
        words.pop();
    }
    while(!words.empty() || !punctuation.empty()) {
        if(!punctuation.empty()) {
            std::cout << punctuation.front();
            punctuation.pop();
        }
        if (!words.empty()) {
            std::cout << words.top();
            words.pop();
        }
    }
}

void reverse(char *string) {
    std::stack<char *> words;
    std::queue<char *> punctuation;
    bool startsWithWord = isSymbol(*string);

    int len = 1;
    char *start = string;
    while(*string != '\0') {
        if (isSymbol(*string) != isSymbol(*(string + 1))) {
            addString(start, len, words, punctuation);
            start = string + 1;
            len = 0;
        }

        len++;
        string++;
    }
    if (!isSymbol(*start)) {
        addString(start, len, words, punctuation);
    }

    printWord(words, punctuation, startsWithWord);
}