/*
 *  lesson8.1.c
 *
 *  Create a program that asks the user to input an integer, and then outputs
 *  that number squared, and then asks for another integer, and outputs that
 *  number squared, and continues repeating this process until the input number
 *  is less than or equal to 0.
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
    int n, nSquared;

    do {
        printf("Enter an integer: ");
        scanf("%d", &n);
        nSquared = pow(n, 2);
        printf("The number squared is %d\n", nSquared);
    } while (n > 0);

    printf("Done\n");

    return 0;
}
