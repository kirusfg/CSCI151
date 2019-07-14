/*
 *  lesson6.3.c
 *
 *  Use a nested for loop to print out the following design:
 *
 *  +++++
 *  ++++*
 *  +++**
 *  ++***
 *  +****
 *  *****
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
    int row, plus, star;

    for (row = 0; row <= 5; row++) {
        for (plus = 5 - row; plus > 0; plus--) {
            printf("+");
        }
        for (star = row; star > 0; star--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
