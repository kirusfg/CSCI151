/*
 *  lesson12.1.c
 *
 *  Recall that the factorial of a non-negative integer n is the product n! = 1 * 2 * 3 * … * n.
 *  (Also, remember that 0! = 1, by definition.) Write some code that stores in an integer array,
 *  the sequence of the first ten factorial numbers, i.e., 1, 1, 2, 6, 24, 120, 720...
 *
 *  July 14, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

unsigned long long factorial(int x){
    if (x >= 1){
        return x * factorial(x - 1);
    } else {
        return 1;
    }
}

int main (void) {
    int arrayLength = 10;

    int array[arrayLength];
    int i;

    for(i = 0; i < arrayLength; i++){
        array[i] = factorial(i);
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}


/*  Second solution without using a distincted factorial() function
int main(void){
    int i, j, factorial;
    int array[10];

    for(i = 0; i < 10; i++){
        factorial = 1;
        for(j = 1; j <= i; j++){
            factorial *= j;
        }
        array[i] = factorial;
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
*/
