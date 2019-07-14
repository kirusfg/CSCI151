/*
 *  lesson12.2.c
 *
 *  Write a program that declares an integer array of size 20, and then with a loop,
 *  initializes all of its values to random numbers between 50 and 100.
 *  You can use the rand() function from stdlib.h to generate an arbitrary int,
 *  and then mod it by m to fall within the range 0 to m-1. Create another loop that
 *  prints out all of its values to the console window.
 *
 *  July 14, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    int array[20];
    int i;

    for (i = 0; i < 20; i++) {
        array[i] = rand() % 50 + 50;
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
