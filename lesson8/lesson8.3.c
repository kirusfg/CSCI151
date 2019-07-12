/*
 *  lesson8.3.c
 *
 *  Create a modified version of the above program so that it displays
 *  the hexadecimal expansion of the number n, instead of the octal.
 *  (In your output, all the displayed numbers should still be in decimal format.)
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

            int f = n % 16;
            n = n / 16;

            printf(" + (%d * 16^%d)", f, counter);

            counter++;
        } while (n > 0);
        printf("\n");

        scanf("%d", &n);
    }

    return 0;
}
