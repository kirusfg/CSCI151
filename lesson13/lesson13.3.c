/*
 *  lesson13.3.c
 *
 *  Write some code that finds the maximum element in a two-dimensional matrix,
 *  and then prints out the row and column of its location.
 *
 *  July 14, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

int main(void) {
    int i, j, sizeX, sizeY, min = 100, max = 0;
    int iMin, iMax, jMin, jMax;

    //rand() returns pseudo-random numbers. It generates numbers based on a given algorithm.
    //The starting point of that algorithm is always the same, so you'll see the same sequence
    //generated for each invocation. This is handy when you need to verify the behavior and
    //consistency of your program. In this case, we want to create a unique matrix with unique
    //dimensions each time we run a program. Therefore, we have to set the seed of the rand()
    //function to the current time for those values to be unique. To use a function time(),
    //we have to include a time.h library
    srand(time(NULL));

    sizeX = rand() % 10 + 1;
    sizeY = rand() % 10 + 1;

    int matrix[sizeX][sizeY];

    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            matrix[i][j] = rand() % 100;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                iMin = i;
                jMin = j;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }

    printf("\n");
    printf("Min at [%d][%d] = %d\n", iMin, jMin, min);
    printf("Max at [%d][%d] = %d\n", iMax, jMax, max);

    return 0;
}
