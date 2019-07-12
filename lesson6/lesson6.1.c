/*
 *  lesson6.1.c
 *
 *  Write a for loop that prints out a temperature conversion table
 *  (Celsius to Fahrenheit), for integer values from -50 C to 40 C.
 *  You can use format strings such as %10i to make sure your integers
 *  take up a fixed number of spaces to make the formatting look nice.

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
    int c, f;

    printf("Celcius   Fahrenheit\n");
    printf("--------------------\n");

    for(c = -50; c <= 40; c += 10){
        f = c * 1.8 + 32;
        printf("%-10i%-10i\n", c, f);
    }

    return 0;
}
