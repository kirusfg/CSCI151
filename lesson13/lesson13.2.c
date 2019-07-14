/*
 *  lesson13.2.c
 *
 *  Starting with the code shown above in “Multi-dimensional Arrays”, write a looping
 *  structure that will transpose the matrix a and store it in a new matrix b of dimensions C x R,
 *  and add 25 to each of its elements, and then finally print out b’s contents.
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
    //Code given
    int R = 3, C = 4;
    int a[R][C];

    int i, j, val = 100;

    /* set matrix elements */
    for (i = 0; i < R; i++) {
    	for (j = 0; j < C; j++) {
    		a[i][j] = val;
    		val++;
    	}
    }

    /* print matrix elements */
    for (i = 0; i < R; i++) {
    	for (j = 0; j < C; j++) {
    		printf("%5d", a[i][j]);
    	}
    	printf("\n");
    }

    //Code added
    int b[C][R];

    printf("\n");
    
    for (i = 0; i < C; i++) {
    	for (j = 0; j < R; j++) {
    		b[i][j] = a[j][i];
            printf("%5d ", b[i][j]);
    	}
        printf("\n");
    }

    return 0;
}
