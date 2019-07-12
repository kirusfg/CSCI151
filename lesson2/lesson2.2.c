/*
 *  lesson2.2.c
 *
 *  For a circle with radius r, where you can assign
 *  any value you want to r, compute and output its
 *  circumference and area. Use the type double,
 *  and the format string %f to output them
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
    double r, circumference, area;

    printf("Enter value for the radius of a circle: ");

    scanf("%lf", &r);

    circumference = 2 * M_PI * r;
    area = M_PI * pow(r, 2);

    printf("The circumference of a circle is %g m\n", circumference);
    printf("The area of a circle is %g m2\n", area);

    return 0;
}
