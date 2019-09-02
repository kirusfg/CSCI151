/*
 *  task1.c
 *
 *  August 28, 2019
 *
 *
*/

#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    double e;
    int i, k;
    long long unsigned int factorial;

    printf("Enter number of terms for e number expansion: ");
    scanf("%d", &k);

    //As stated in the task, k should be non-zero positive number: checking
    while (k > 0) {
        /*
         * The first term in the expansion, i.e. 1 / 0! is equal to 1
         * Assigning this as initial value of e makes the problem a lot easier
         * as we don't have to evaluate 0!
        */
        e = 1;
        factorial = 1;

        //Evaluating i! and adding 1 / i! to e
        for (i = 1; i <= k; i++) {
            factorial *= i;
            e += 1.0 / factorial;
        }

        //Printing out the result
        printf("%1.16f\n", e);
        //Asking for a new k value
        printf("Enter number of terms for e number expansion: ");
        scanf("%d", &k);
    }

    return 0;
}
