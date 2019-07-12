/*
 *  lesson9.1.c
 *
 *  Write a program that reads in your final course grade percentage,
 *  and outputs your final letter grade.
 *
 *  June 2, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main (void) {

    float p;

    scanf("%f", &p);

    if (p >= 100){
        printf("Invalid percentage\n");
    } else if (p >= 95.0){
        printf("A\n");
    } else if (p >= 90.0){
        printf("A-\n");
    } else if (p >= 85.0){
        printf("B+\n");
    } else if (p >= 80.0){
        printf("B\n");
    } else if (p >= 75.0){
        printf("B-\n");
    } else if (p >= 70.0){
        printf("C+\n");
    } else if (p >= 65.0){
        printf("C\n");
    } else if (p >= 60.0){
        printf("C-\n");
    } else if (p >= 55.0){
        printf("D+\n");
    } else if (p >= 50.0){
        printf("D\n");
    } else if (p >= 45.0){
        printf("D-\n");
    } else if ((p < 45.0) && (p >= 0.0)){
        printf("F\n");
    } else {
        printf("Invalid percentage\n");
    }

    return 0;
}
