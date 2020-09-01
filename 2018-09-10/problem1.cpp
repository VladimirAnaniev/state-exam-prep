#include <iostream>
#include <cstring>

/**
 * Професор Х забравя постоянно паролата за своя таен сейф,
 * която представлява последователност от цели числа.
 *
 * За да не е нужно да я помни, той скрива подсказки в кабинета си.
 * На всеки ред от библиотеката му са подредени книги, най-много 20 реда книги,
 * с до 30 книги на ред. Книгите на някои от редовете са подредени по азбучен ред
 * на заглавията си, всяко от които е до 100 символа.
 *
 * Паролата за сейфа на професор X се определя от числата,
 * които задават последователните дължини на думите в заглавията на книгите,
 * разположени точно в средата на редовете, в които книгите са подредени в азбучен ред.
 *
 * Ако на реда има четен брой книги, за паролата се използва книгата,
 * намираща се по-близо до началото на  реда.
 *
 * Думите  в  заглавията  на  книгите  са  разделени  от  точно  един  интервал.
 * Дължините  на  думите формират паролата в реда, в който се срещат,
 * от най-горния към най-долния ред на библиотеката.
 * Библиотеката  на  Х  може  да  се  представи  като  двумерен  масив a
 * от  низове  с m реда  по n низа  всеки, представящи заглавията на книгите.
 *
 * Да се дефинира функция revealPassword, която по подадени a, m и n,
 * извежда на стандартния изход паролата на професор X като последователност от числа,
 * разделени с по един интервал.
 *
 * Да се демонстрира употребата на функцията revealPassword в кратка програма.
 */

//char books[20][30][100];


int middleIndex(int cols) {
    return cols % 2 == 0 ? (cols / 2) - 1 : cols / 2;
}


bool areSorted(char **row, int cols) {
    for (int i = 0; i < cols - 1; i++) {
        char *first = row[i];
        char *second = row[i + 1];
        if (strcmp(first, second) > 0) {
            return false;
        }
    }

    return true;
}

void printNumbers(char *bookName) {
    int count = 0;

    while (*bookName != '\0') {
        if (*bookName == ' ') {
            std::cout << count << ' ';
            count = 0;
        } else {
            count++;
        }

        bookName++;
    }

    std::cout << count << ' ';
}

void revealPassword(char ***books, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (areSorted(books[i], cols)) {
            char *middleBook = books[i][middleIndex(cols)];
            printNumbers(middleBook);
        }
    }
}

int maina() {
    char ***books = new char **[3];
    books[0] = new char *[3];
    books[1] = new char *[3];
    books[2] = new char *[3];

    books[0][0] = "Algebra";
    books[0][1] = "Analytic Geometry"; // 8 8
    books[0][2] = "Mathematical Analysis";
    books[1][0] = "Introduction to Programming";
    books[1][1] = "Object-Oriented Programming";
    books[1][2] = "Data Structures and Alagorithms";
    books[2][0] = "Artificial Intelligence";
    books[2][1] = "Databases"; // 9
    books[2][2] = "Functional Programming";

    revealPassword(books, 3, 3); // 8 8 9
    return 0;
}