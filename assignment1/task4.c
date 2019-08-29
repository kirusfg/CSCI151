/*
 *  task4.c
 *
 *  August 28, 2019
 *
 *
*/

#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    int i, j, k;

    //Getting input from user
    printf("Enter an integer: ");
    scanf("%d", &k);

    //Checking whether k is a non-zero, positive number
    while (k > 0) {
        //Repeating k times with increasing value of i
        for (i = 1; i <= k; i++) {
            //Printing row values from 1 to k
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }

        //Asking for a new value of k
        scanf("%d", &k);
    }

    return 0;
}
