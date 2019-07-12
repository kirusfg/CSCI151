/*
 *  lesson9.2.c
 *
 *  Write some code that takes an integer value n from the user as input,
 *  and then prints out all of the integers between 2 and n-1 that divide
 *  it evenly.  For example, on input n=100, the output should be 2, 4, 5, 10, 20, 25, 50.
 *
 *  June 2, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main (void) {

    int n, divisor;

    scanf("%d", &n);

    for(divisor = 2; divisor < n; divisor++){
        if(n % divisor == 0){
            printf("%d ", divisor);
        }
    }

    return 0;
}
