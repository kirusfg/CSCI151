/*
 *  lesson6.2.c
 *
 *  Print out the numbers 2, 4, 8, 16, 32, …, 65536, where each number is twice
 *  the value of the previous.  Hint:  use the iterator of the loop to count the
 *  16 iterations, but use a separate variable to keep track of the number to be
 *  printed each iteration.
 *
 *
 *  May 18, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    int i, j, k;

    printf(" n     2^n\n");
    printf("----------\n");

    //Using pow() function
    for (i = 1; i <= 16; i++) {
        printf("%2i   %5.0f\n", i, pow(2, i));
    }

    //Using nested loops
    /*
    printf(" n     2^n\n");
    printf("----------\n");

    for (i = 1; i <= 16; i++) {
        k = 1;
        for (j = i; j >= 1; j--) {
            k *= 2;
        }
        printf("%2i   %5i\n", i, k);
    }
    */

    return 0;
}
