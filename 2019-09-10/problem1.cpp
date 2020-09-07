#include <cstring>

/**
 * Да се попълнят празните места в кода на функциите така, че те да отговарят на описанието си.
 */

// А) find използва алгоритъма за двоично търсене (binary search), за да
// провери дали value се съдържа в масива arr, състоящ се от size елемента.
// Функцията връща true ако това е така и false в противен случай.
bool find(int value, int* arr, size_t size) {
    if (size == 0) return false;
    
    size_t mid = size / 2;
    if (value == arr[mid]) return true;
    
    if (value < arr[mid])
        return find(value, arr, mid);
    else
        return find(value, arr + mid, mid);
}

// Б) fold_left изпълнява ляво свиване (left fold) върху масива arr, съдържащ size елемента,
// прилагайки операцията op. Началната стойност е nil.
// Функцията връща стойността op(...op(op(nil, a[0]), a[1]), ..., a[size-1]).
template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil) {
    ReturnType result = nil;
    
    for (size_t i = 0; i < size; ++i)
        result = op(arr[i], result);
        
    return result;
}

int op(char Digit, int Result) {
    return (Result * 10) + (Digit - '0');
}

// Преобразува символен низ от десетични цифри до величина от тип int
int str_to_int(const char * str) {
    return (str == nullptr) ? 0 : fold_left(str, strlen(str), op, 0);
}
