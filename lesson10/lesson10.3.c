/*
 *  lesson10.3.c
 *
 *  Write a program that first prompts the user to enter in some words,
 *  and then outputs the length of each of the words. Note that words
 *  can have more than one whitespace character between them.
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
    int counter = 0, longestWord = 0;
    char ch;

    do {
        ch = getchar();

        if (ch != ' ') {
            counter++;
        } else {
            if (counter != 0) {
                printf("%d\n", counter);
            }
            if (counter > longestWord) {
                longestWord = counter;
            }
            counter = 0;
        }
    } while (ch != '\n');

    printf("%d\n", counter - 1);

    printf("The longest word was %d symbols long\n", longestWord);

    return 0;
}
