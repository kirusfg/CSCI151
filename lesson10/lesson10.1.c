/*
 *  lesson10.1.c
 *
 *  Write a program that prompts the user to enter in some text, and then outputs
 *  the number of occurrences of the letter ‘a’ in the input provided.
 *
 *  June 22, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main (void) {

    int counter = 0;
    char ch;

    do {
        ch = getchar();

        if(ch == 'a'){
            counter++;
        }
    } while (ch != '\n');

    printf("%d\n", counter);

    return 0;
}
