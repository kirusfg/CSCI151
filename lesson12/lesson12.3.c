/*
 *  lesson12.2.c
 *
 *  Write a program that declares an integer array of size 20, and then with a loop,
 *  initializes all of its values to random numbers between 50 and 100.
 *  You can use the rand() function from stdlib.h to generate an arbitrary int,
 *  and then mod it by m to fall within the range 0 to m-1. Create another loop that
 *  prints out all of its values to the console window.
 *
 *  Extend the program in the previous exercise to find the minimum, maximum,
 *  and average values stored in the array, and print those results to the screen as well.
 *
 *  July 14, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void){
    int array[20];
    int i, min, max, sum, avg;

    min = 100;
    max = 50;
    sum = 0;
    avg = 0;

    for(i = 0; i < 20; i++){
        array[i] = rand() % 50 + 50;
        printf("array[%d] = %d\n", i, array[i]);
    }

    for(i = 0; i < 20; i++){
        if (array[i] <= min){
            min = array[i];
        }
    }

    for(i = 0; i < 20; i++){
        if (array[i] >= max){
            max = array[i];
        }
    }

    for(i = 0; i < 20; i++){
        sum += array[i];
    }

    avg = (int)(sum / 20);

    printf("\n");
    printf("min = %d\n", min);
    printf("max = %d\n", max);
    printf("avg = %d\n", avg);

    return 0;
}
