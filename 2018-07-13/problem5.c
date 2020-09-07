// В текущия каталог се намира текстов файл f1.txt със следното съдържаниe:
// ```
// xyzabcd
// 0123456789
// ABCD
// ```

// Изпълнимият файл, получен след компилация на зададения по-долу програмен фрагмент, се стартира със следния команден ред:
// ./a.out f1.txt f2.txt

// Напишете какво ще бъде изведено на стандартния изход и какво ще бъде съдържанието на файловете f1.txt и f2.txt след приключване на успешното изпълнение.

#include <stdio.h> 
#include <fcntl.h>

main(int argc, char * argv[]) {
    int des1, des2, k, broi, i = 0, status;
    char buff[40], c;
    if ((des1 = open(argv[1], O_RDWR)) == -1) { // opens f1.txt for read & write
        printf("\n Cannot open  \n");
        exit(1);
    }
    if ((des2 = open(argv[2], O_CREAT |O_TRUNC |O_RDWR, 0666)) == -1) { // Creates file f2.txt if does not exist, truncates content if it does
        printf("\n Cannot open  \n");
        exit(1);
    }
    if (fork() == 0) { // child process
        broi = read(des1, buff, 22); // buff="xyzabcd\n0123456789\nABC", broi=22
        write(1, buff, 10); // print "xyzabcd\n01" to standard output
        k = dup(1); // k = standard output stream descriptor
        close(1); // closes standard output
        dup(des1); // redirects standard output to f1.txt
        c = buff[i++]; // c='x', i=1
        if (c <= '0' || c >= '9') { // true
            while (buff[i++] != '\n' && i < broi) // 6 iterations (for "yzabcd")
                write(1, "x", 1); // writes xxxxxx in f1.txt
            write(1, "\n", 1); // new line in f1.txt
            close(1); // closes f1.txt as standard output
            dup(k); // reverts back to standard output
            write(1, buff, 4); // prints "xyza" to standard output
            write(des2, buff, 12); // writes "xyzabcd\n0123" to f2.txt
        } else { // not executed
            write(1, buff, broi);
            close(1);
            dup(k);
            write(1, "x\n", 2);
        }
        lseek(des2, 0, 0); // Goes to the start of f2.txt
        write(des2, "x\n", 2); // writes x\n -> x\nzabcd\n0123
        close(des1); // closes f1.txt
        close(des2); // closes f2.txt
    } else { // parent process
        wait( &status ); // waits child to finish 
        close(1); // closes standart output
        dup(des1); // redirects standard output to f1.txt
        execlp("head", "head", "-2", argv[2], 0); // write the first 2 lines from f2.txt into f1.txt
        execlp("wc", "wc", "-l", argv[1], 0); // will not be executed
    }
    execlp("grep", "grep", "x", "f1.txt", 0); // prints all lines matching `x` from f1.txt. Only executed by child process (ABCxxxxxx)
}

// Standard output:
// xyzabcd
// 01xyzaxyzabcd
// ABCxxxxx

// f2.txt:
// x
// zabcd
// 0123

// f1.txt:
// xyzabcd
// 0123456789
// ABCxxxxxx
// x
// zabcd
