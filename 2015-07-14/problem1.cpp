// Следната задача да се реши на един от езиците за програмиране C++ или Java.
// Дадена е ​float матрица ​img с размери ​М≤10 реда и ​N≤10 стълба.
// Напишете функция subsample​, която получава като аргументи ​M​, ​N и ​img 
// и извежда на екрана матрица ​s с размери (М+1)/2 и ​(N+1)/2 ​(при целочислено деление),
// всеки елемент ​s[i][j] на която е равен на средно­аритметичното от всички елементи ​
// img[y][x]​, такива че​ i*2 ≤ y ≤ i*2+1​ и ​j*2 ≤ x ≤ j*2+1​.
// Например, при матрица ​img​, представена таблично по следния начин:
// 1.0  2.0  3.0
// 4.5  6.5  7.5
// функцията да извежда на екрана:
// 3.5  5.25

#include <iostream>


void subsample(float img[10][10], int m, int n) {
    for (int i = 0; i < (m + 1) / 2; i++) {
        for(int j = 0; j < (n + 1) / 2; j++) {
            float sum = 0;
            int c = 0;
            for(int y = i * 2; y <= i * 2 + 1 && y < n; y++) {
                for (int x = j * 2; x <= j * 2 + 1 && x < n; x++) {
                    sum += img[y][x];
                    c++;
                }
            }
            std::cout << sum / c << " ";
        }
        std::cout << std::endl;
    }
}


int mains() {
    float img[10][10] {0};
    img[0][0] = 1;   img[0][1] = 2;   img[0][2] = 3;
    img[1][0] = 4.5; img[1][1] = 6.5; img[1][2] = 7.5;

    subsample(img, 2, 3);

    return 0;
}
