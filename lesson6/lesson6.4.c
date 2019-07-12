/*
 *  lesson6.4.c
 *
 *  Get an integer value n, and a double value x from the user,
 *  and implement a loop which calculates x^n without using
 *  the pow(x, i) function for this).
 *
 *  May 18, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void){
    int n, i;
    double x, result;
    result = 1;

    printf("x^n\n");
    printf("Enter value for x: ");
    scanf("%lf", &x);
    printf("Enter value for n: ");
    scanf("%i", &n);

    for(i = 1; i <= n; i++){
        result *= x;
    }

    printf("%g^%i is equal to %g\n", x, n, result);

    return 0;
}
