/*
 *  task1.c
 *
 *  August 27, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long long int factorial(int number) {
    if (number == 0) {
        return 1;
    } else {
        return (number * factorial(number - 1));
    }
}

int main(void) {
    double e;
    int i, k;

    do {
        e = 0;
        scanf("%d", &k);

        for (i = 0; i <= k; i++) {
            e += 1.0 / (factorial(i));
        }

        printf("%1.10f\n", e);
    } while (k > 0);

    return 0;
}
