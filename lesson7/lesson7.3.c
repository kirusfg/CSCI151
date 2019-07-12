/*
 *  lesson7.3.c
 *
 *  Challenge Exercise.  Use a nested for loop to print out something that looks
 *  similar to the following design.  You can use the function sin(x) from math.h'
 *  to calculate the approximate length of your rows. (Hint:  Don’t forget that
 *  for loops can use doubles as their iterators!)
 *
 *  June 1, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void){
    int row;
    double x, number;

    for(row = 1, x = 0; row <= 40; row++, x += M_PI / 20){
        for(number = ((sin(x) * 10) + 10); number >= 0; number--){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
