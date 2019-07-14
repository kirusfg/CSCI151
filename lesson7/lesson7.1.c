/*
 *  lesson7.1.c
 *
 *  Write a loop that prints out the first 20 Fibonacci numbers.
 *  Hint: use separate variables to keep track of the values
 *  printed out from the previous two iterations.
 *
 *  June 1, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    int a, b, c, counter;

    a = 0;
    b = 1;
    c = a + b;

    counter = 1;

    while (counter <= 20) {
        printf("%d ", a);
        a = b;
        b = c;
        c = a + b;
        counter++;
    }

    return 0;
}
