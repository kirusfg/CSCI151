/*
 *  lesson3.1.c
 *
 *  Declare a variable of type double that stores a length value
 *  in meters, and assign it some value. Declare several other
 *  variables that store this same length converted into
 *  centimeters, myriameters, inches, miles, and furlongs, and output
 *  all variable values with suitable messages to the console window.
 *
 *  May 15, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    double meters, centimeters, myriameters, inches, miles, furlongs;

    printf("Enter value of length in meters: ");

    scanf("%lf", &meters);

    centimeters = meters * 100;
    myriameters = meters / 10000;
    inches = meters / 254;
    miles = meters / 1609.34;
    furlongs = meters / 201.168;

    printf("%g meters is equal to\n", meters);
    printf("%g centimeters\n", centimeters);
    printf("%g myriameters\n", myriameters);
    printf("%g inches\n", inches);
    printf("%g miles\n", miles);
    printf("%g furlongs\n", furlongs);

    return 0;
}
