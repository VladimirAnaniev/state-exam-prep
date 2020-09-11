#include <cmath>
#include <iostream>

// Дадени са координатите на N-точки, които са записани в масивите floatx[N],y[N] по следния начин:
// координатите на i-тата точка са (x[i],y[i]).
// Напишете функция square, която получава като аргументи броя на точките N и два масива X и Y
// съдържащи координатите им и извежда на екрана координатите на центъра
// и страната на най-малкия квадрат със страни успоредни на координатните оси,
// който обхваща всички дадени точки (всички дадени точки са във вътрешността му или на страните му).


float findMin(float *arr, int n) {
    float min = INFINITY;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

float findMax(float *arr, int n) {
    float max = -INFINITY;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void square(float *x, float *y, int n) {
    float minX = findMin(x, n);
    float maxX = findMax(x, n);
    float minY = findMin(y, n);
    float maxY = findMax(y, n);

    float middleX = (maxX + minX) / 2;
    float middleY = (maxY + minY) / 2;

    std::cout << "(" << middleX << ", " << middleY << ")\n";

    float sizeX = maxX - minX;
    float sizeY = maxY - minY;

    std::cout << (sizeX > sizeY ? sizeX : sizeY);
}