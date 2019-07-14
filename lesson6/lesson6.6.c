/*
 *  lesson6.6.c
 *
 *  Challenge Problem. Get an integer value n, and a double value x from the user,
 *  and then use a Taylor series expansion (around 0) to approximate the exponential
 *  function e^x using n+1 terms of the following series without using pow() function
 *  or nested loops
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
    int n, i, factor;
    double x, nthValue, xtoN, sum;

    scanf("%lf %i", &x, &n);

    for (i = 0, factor = 1, xtoN = 1; i <= n; i++, factor *= i, xtoN *= x) {
        nthValue = xtoN / factor;
        sum += nthValue;
    }

    printf("%3.10f\n", sum);

    return 0;
}
