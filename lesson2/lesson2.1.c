/*
 *  lesson2.1.c
 *
 *  For a box with dimensions l, w, and h, where you
 *  can assign any values you want to these three,
 *  compute and output the volume and surface area
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
    double l, w, h, volume, surfaceArea;

    printf("Enter values for the length, width, and height of a container: ");

    scanf("%lf %lf %lf", &l, &w, &h);

    volume = l * w * h;
    surfaceArea = 2 * ((l * w) + (l * h) + (w * h));

    printf("The volume of a container is %g m3\n", volume);
    printf("The surface area of a container is %g m2\n", surfaceArea);

    return 0;
}
