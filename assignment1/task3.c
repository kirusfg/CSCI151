#include <stdio.h>

#define PI 3.14159265358979

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    int x, k;
    int i, sign;
    double xRad, sinX, numerator, denominator;

    //Getting values from user
    printf("Enter angle value in degrees: ");
    scanf("%d", &x);
    printf("Enter number of terms used for the expansion: ");
    scanf("%d", &k);

    //Converting degrees into radians
    xRad = (x * PI) / 180;

    //Setting first values for numerator, denominator, signX, and sign before starting iterations
    numerator = xRad;
    denominator = 1;
    sign = 1;
    sinX = 0;

    //Evaluating sin(x)
    for (i = 0; i <= k; i++) {
        //Adding term i to the sinX
        sinX += sign * numerator / denominator;

        //Increasing num. and den. to use in the next term
        numerator = numerator * xRad * xRad;    //x -> x^3 -> x^5 -> x^7...
        denominator = denominator * (2 * i + 2) * (2 * i + 3);  //1! -> 3! -> 5! -> 7!...x
        //Changing sign for the next term
        sign *= -1;
    }

    printf("sin(%d) = %.20f", x, sinX);

    return 0;
}
