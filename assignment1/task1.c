#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    double e;
    int i, k;
    long long unsigned int factorial;

    do {
        //Asking for the number of terms for expansion k
        printf("Enter number of terms for e number expansion: ");
        scanf("%d", &k);

        e = 0;
        factorial = 1;

        //Evaluating i! and adding 1 / i! to e
        for (i = 0; i <= k; i++) {
            if (i == 0) {
                factorial = 1;
            } else {
                factorial *= i;
            }

            e += 1.0 / factorial;
        }

        //Printing out the result
        printf("%1.16f\n", e);
    } while (k > 0);    //As stated in the task, k should be non-zero positive number: checking

    return 0;
}
