/*
 *  lesson5.3.c
 *
 *  Read in a single integer from the user, which represents
 *  the number of seconds past midnight. From this, calculate
 *  and output the time in the form hh:mm:ss
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
    int x, hours, minutes, seconds;

    printf("Enter number of seconds past midnight: ");

    scanf("%d", &x);

    hours = (x / 3600) % 24;
    minutes = ((x - hours * 3600) / 60) % 60;
    seconds = x % 60;

    printf("Time is %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
