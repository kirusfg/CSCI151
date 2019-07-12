/*
 *  lesson3.2.c
 *
 *  Declare variables of type double that store the height and radius
 *  of the circular base of a cone, and assign them some values.  Calculate
 *  the surface area, area of the circular base, and volume of the given cone,
 *  and store these in separate variables.   You can find square roots by
 *  using the function call sqrt(x), where at the top of your .c file you
 *  need to #include <math.h>.  Output all of the variable values with
 *  suitable messages to the console window.
 *
 *  May 15, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void){
    double radius, height, surfaceArea, baseArea, volume;

    printf("Enter value of radius and height of a cone: ");

    scanf("%lf %lf", &radius, &height);

    baseArea = M_PI * pow(radius, 2);
    surfaceArea = baseArea + (M_PI * radius * sqrt(pow(radius, 2) + pow(height, 2)));
    volume = (baseArea * height) / 3;

    printf("Base area of a cone is %g m2\n", baseArea);
    printf("Surface area of a cone is %g m2\n", surfaceArea);
    printf("Volume of a cone is %g m3\n", volume);

    return 0;
}
