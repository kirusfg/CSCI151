/*
 *  lesson13.4.c
 *
 *  Write some code that first creates and initializes two 3 x 3 matrices, and then multiplies
 *  them together to get a third 3 x 3 matrix, which you print out at the end.
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
    int xPos1, yPos2, i, j;

    int array1[3][3];
    int array2[3][3];
    int array3[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    srand(time(NULL));

    //Creating and printing out the first matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            array1[i][j] = rand() % 100;
            printf("%3d ", array1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Creating and printing out the second matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            array2[i][j] = rand() % 100;
            printf("%3d ", array2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Finding the third matrix
    for (xPos1 = 0; xPos1 < 3; xPos1++) {
        for (yPos2 = 0; yPos2 < 3; yPos2++) {
            for (i = 0; i < 3; i++) {
                array3[xPos1][yPos2] += array1[xPos1][i] * array2[i][yPos2];
            }
        }
    }

    //Printing out the third matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d ", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
