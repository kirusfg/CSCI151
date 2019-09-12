#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    int i, j, k;

    do {
        //Asking for a new value of k
        scanf("%d", &k);

        //Repeating k times with increasing value of i
        for (i = 1; i <= k; i++) {
            //Printing row values from 1 to k
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } while (k > 0);    //Checking whether k is a non-zero, positive number

    return 0;
}
