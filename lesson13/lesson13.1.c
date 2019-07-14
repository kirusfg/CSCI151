/*
 *  lesson13.1.c
 *
 *  Using nested loops, create a 12 x 12 matrix for representing a multiplication table,
 *  where the i, jth element of the matrix stores the value i * j. Use a second pair of
 *  nested loops to print out the contents of your matrix.
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
    int i, j, x, y, sizeX, sizeY;

    sizeX = 12;
    sizeY = 12;

    int array[sizeX][sizeY];

    for (i = 0, x = 1; i < sizeX; i++, x++) {
        for (j = 0, y = 1; j < sizeY; j++, y++) {
            array[i][j] = x * y;
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
