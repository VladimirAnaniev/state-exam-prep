#include <iostream>

/**
 * Горски терен епредставен с помощта на мрежа или двумерен масив с𝑚x𝑛(𝑚,𝑛∈[0;100]) области (елементи).
 *
 * Елементите на двумерния масив са символи, които имат следното значение:
 *   R–река;
 *   S–скала;
 *   цифри от 1 до 4, които означават гъстота на гората.
 *
 * Теренът се променя на всеки 10 години.
 * Реката и скалите остават постоянни, докато гъстотата на горските площи се променя по следните правила:
 *   1 преминава в 2, 2 в 3, a 3 в 4.
 *   4 преминава в 3, ако в съседство има поне 3 области с гъстота 4, в противен случай остава 4.
 *
 * Съседни на дадена област (елемент) от масива са тези области, индексите на които се различават най-много с 1
 * т.е. всяка област има най-много 8 съседни области.
 *
 * Напишете функция, която по подаден терен намира вида му след 100 години.
 * Демонстрирайте използването на функцията в кратка програма.
 *
 * Примерен вид на терен:
 *   R R 1 1 2 2
 *   1 R R R 1 2
 *   S 1 R R 2 3
 *   4 4 S S R R
 */

void print(char** field, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << field[r][c] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool hasAtLeast3Neighbours(char **field, int rows, int cols, int r, int c) {
    int count = 0;

    int rMin = r == 0 ? r : r - 1;
    int rMax = r == rows - 1 ? r : r + 1;
    int cMin = c == 0 ? c : c - 1;
    int cMax = c == cols - 1 ? c : c + 1;

    for (int i = rMin; i <= rMax; i++) {
        for (int j = cMin; j <= cMax; j++) {
            if (i == r && j == c) {
                continue;
            }

            count += (int) (field[i][j] == '4');
        }
    }

    return count >= 3;
}

char **after10Years(char **field, int rows, int cols) {
    char** after = new char*[rows];

    for (int r = 0; r < rows; r++) {
        after[r] = new char[cols];
        for (int c = 0; c < cols; c++) {
            char value = field[r][c];

            if (value >= '1' && value <= '3') {
                after[r][c] = (char) (value + 1);
            } else if (value == '4' && hasAtLeast3Neighbours(field, rows, cols, r, c)) {
                after[r][c] = '3';
            } else {
                after[r][c] = value;
            }
        }
    }

    return after;
}

char** add100Years(char **field, int rows, int cols) {
    for (int i = 0; i < 10; i++) {
        field = after10Years(field, rows, cols);
//        print(field, rows, cols);
    }

    return field;
}

int mainn() {

    char **field = new char *[4]{
            new char[6]{'R', 'R', '1', '1', '2', '2'},
            new char[6]{'1', 'R', 'R', 'R', '1', '2'},
            new char[6]{'S', '1', 'R', 'R', '2', '3'},
            new char[6]{'4', '4', 'S', 'S', 'R', 'R'}
    };

    field = add100Years(field, 4, 6);

    print(field, 4, 6);

    return 0;
}