/*
 *  lesson8.4.c
 *
 *  Challenge Problem. This problem is the same as the previous two,
 *  except now, in addition to getting a value n from the user to be
 *  expanded, the program should also get an integer b > 1 from the user
 *  as well, which is the base for the conversion to be used. In other
 *  words, the program will display the base-b expansion of the number n.
 *
 *  June 2, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {

    int n, f, b;

    scanf("%d", &n);
    scanf("%d", &b);

    while (n >= 0) {
        printf("%d =", n);

        do {
            int counter = 0;

            f = n % b;
            n = n / b;

            printf(" + (%d * %d^%d)", f, b, counter);

            counter++;
        } while (n > 0);
        printf("\n");

        scanf("%d", &n);
        scanf("%d", &b);
    }

    return 0;
}
