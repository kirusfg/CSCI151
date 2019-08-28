/*
 *  task3.c
 *
 *  August 28, 2019
 *
 *
*/

#include <stdio.h>

#define PI 3.14159265358979

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    int xDeg, k;
    int i;
    double xRad, sinX, numerator, denominator;

    //Getting values from user
    printf("Enter angle value in degrees: ");
    scanf("%d", &xDeg);
    printf("Enter number of terms used for the expansion: ");
    scanf("%d", &k);

    //Converting degrees into radians
    xRad = (xDeg * PI) / 180;

    //Setting first values for numerator and denominator
    numerator = xRad;
    denominator = 1;

    //Evaluating sin(x)
    for (i = 0; i <= k; i++) {
        //Checking if (-1)^k is positive or negative
        if (i % 2 == 0) {
            sinX += numerator / denominator;
        } else {
            sinX -= numerator / denominator;
        }

        //Increasing num. and den. to use in the next term
        numerator = numerator * xRad * xRad;    //x -> x^3 -> x^5 -> x^7...
        denominator = denominator * (2 * i + 2) * (2 * i + 3);  //1! -> 3! -> 5! -> 7!...
    }

    printf("sin(%d) = %f", xDeg, sinX);

    return 0;
}
