#include <iostream>
#include <cstring>

/**
 * Даден е двумерен масив с размер 6 на 6 от символи —малки и главни латински букви и цифри. 
 * Две клетки в него ще наричаме “съседни”, ако имат обща стена 
 * (т.е. всяка клетка е съседна с най-много четири други, намиращи се под, над, вляво и вдясно от нея).
 * 
 * Път с дължина N ще наричаме редица  a0, a1, ... aN –1 от клетки, за която:
 * 1. за всяко 0 ≤ i < N –1 е изпълнено, че ai и ai+1 са съседни;
 * 2.никоя от клетките не се среща повече от веднъж (т.е. няма цикли).
 * 
 * Да се попълнят празните места в кода на дадените по-долу функция contains и помощната ѝ функция walk.  
 * Функцията contains получава  два  аргумента – масив arr от дадения тип char[6][6] и символен низ str. 
 * Тя трябва да връща истина тогава и само тогава, когато в arr съществува път, 
 * чиито клетки образуват точно съдържанието на низа str (вижте примера по-долу). 
 * 
 * За определеност считаме, че функцията трябва да връща истина за празния низ.
 */


bool contains(char arr[6][6], const char* str) {
    for (int row = 0; row < 6; row++)
        for (int col = 0; col < 6; col++)
            if (walk(arr, row, col, str))
                return true;
    return false;
}

bool walk(char arr[6][6], int row, int col, const char* str) {
    if (*str == '\0') 
        return true;
    
    if (row < 0 || col < 0 || row >= 6 || col >= 6) 
        return false;
        
    if (arr[row][col] != *str)
        return false;
        
    arr[row][col] *= -1;
    
    bool result =
        walk(arr, row + 1, col,       str + 1) ||
        walk(arr, row - 1, col,       str + 1) ||
        walk(arr, row,     col + 1,   str + 1) ||
        walk(arr, row,     col - 1,   str + 1);
        
    arr[row][col] *= -1;
    
    return result;
}
