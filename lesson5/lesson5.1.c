/*
 *  lesson5.1.c
 *
 *  Read in from the user three doubles, a, b, and c, which represent
 *  the coefficients of the quadratic equation, and calculate its two roots.
 *  You can find square roots by using the function call sqrt(x), where at
 *  the top of your .c file you need to #include <math.h>.
 *
 *  May 15, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    double a, b, c, x1, x2;

    printf("Enter a, b, and c coefficients of the quadratic equation: ");

    scanf("%lf %lf %lf", &a, &b, &c);

    x1 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    x2 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    printf("x1 = %g\n", x1);
    printf("x2 = %g\n", x2);

    return 0;
}
