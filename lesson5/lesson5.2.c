/*
 *  lesson5.2.c
 *
 *  Declare a variable x of type double, whose value is read in from the user,
 *  and use the Taylor series expansion (around 0) to approximate the value of
 *  sin(x) using three terms in the summation
 *
 *  May 15, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long long int factorial(int number) {
    long long int factorial = 1;

    if (number < 0) {
        return 0;
    } else {
        for(int i = 1; i <= number; i++){
            factorial *= i;
        }
        return factorial;
    }
}

int main(void) {
    double x, sinX;

    printf("Enter x: ");
    scanf("%lf", &x);

    sinX = x - (pow(x, 3) / factorial(3)) + (pow(x, 5) / factorial(5));

    printf("sin(%g) = %g\n", x, sinX);

    return 0;
}
