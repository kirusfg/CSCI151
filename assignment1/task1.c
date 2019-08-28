/*
 *  task1.c
 *
 *  August 28, 2019
 *
 *
*/

#include <stdio.h>

int main(void) {
    double e;
    int i, k, factorial;

    scanf("%d", &k);

    while (k > 0) {
        e = 1;
        factorial = 1;

        for (i = 1; i <= k + 1; i++) {
            factorial = factorial * i;
            e += 1.0 / factorial;
        }

        printf("%1.16f\n", e);
        scanf("%d", &k);
    }

    return 0;
}
