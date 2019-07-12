/*
 *  lesson7.2.c
 *
 *  Create a loop that, for a positive integer n, finds the biggest integer k for which n ≥ 2k.
 *  (We are essentially finding the integer log base-2 of n.)  Do not use pow, log2, or any
 *  functions from math.h to implement this!
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
    int n, k, counter;

    scanf("%d", &n);

    counter = 0;
    k = 1;

    while(n >= k){
        k *= 2;
        counter++;
    }

    printf("%d\n", counter - 1);

    return 0;
}
