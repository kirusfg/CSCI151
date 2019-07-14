/*
 *  lesson10.2.c
 *
 *  Write a program that prompts the user to enter in some text,
 *  and then outputs the same text, except that all of the lowercase
 *  letters are now in uppercase (uppercase letters and other symbols
 *  should remain the same in the output).
 *
 *  June 22, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    char ch;

    do {
        ch = getchar();

        if ((ch >= 97) && (ch <= 122)) {
            printf("%c", ch - 32);
        } else {
            printf("%c", ch);
        }
    } while (ch != '\n');

    return 0;
}
