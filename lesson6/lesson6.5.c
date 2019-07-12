/*
 *  lesson6.5.c
 *
 *  Challenge Problem. Get an integer value n, and a double
 *  value x from the user, and then calculate the value of
 *  the series x^1 + x^2 + x^3 + … + x^n.  Do this without using
 *  nested loops, or the pow(x, i) function from the math.h
 *  library (that’s what makes this challenging!
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
    int n;
    double x, result = 0, xtoN = 1;

    scanf("%lf %i", &x, &n);

    for(int i = 1; i <= n; i++){
        xtoN = 1;
        //Evaluating each x^n
        for(int j = i; j >= 1; j--){
            xtoN *= x;
        }
        //Adding each x^n to the result
        result += xtoN;
    }

    printf("%g\n", result);

    return 0;
}
