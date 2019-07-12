/*
 *  lesson8.2.c
 *
 *  Using a loop (not the output format character %o), create a program that
 *  takes a positive integer n, and then displays the polynomial for the octal
 *  representation of that integer. Use successive division, as demonstrated
 *  in the binary conversion example from the lesson, to do this.
 *
 *  June 2, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main (void) {

    int n;

    scanf("%d", &n);

    while (n >= 0) {
        printf("%d =", n);

        do {
            int counter = 0;

            int f = n % 8;
            n = n / 8;

            printf(" + (%d * 8^%d)", f, counter);

            counter++;
        } while (n > 0);
        printf("\n");

        scanf("%d", &n);
    }

    return 0;
}
