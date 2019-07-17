/*
 *  lesson14.1.c
 *
 *  Using the time struct that we defined in the video clips above, write some code that will
 *  advance a given time by a specified number of minutes. To do this, declare a variable now
 *  of type time initialized to some particular value, and another integer variable advMins set
 *  to some initial value. Then, update the fields of now to show the time in advMins minutes.
 *  You can check and handle special cases using if-statements, and don’t forget that you can
 *  also use the modulus (%) operator.
 *
 *  July 17, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

typedef struct {
    int hours;
    int minutes;
    char amORpm;
} Time;

int main(void) {
    Time now = {11, 23, 'a'};
    int advMins = 3601;

    now.hours += advMins / 60;
    now.minutes += advMins - (advMins / 60) * 60;

    if (now.minutes >= 60) {
        now.hours += now.minutes / 60;
        now.minutes = now.minutes - (now.minutes / 60) * 60;
    }

    if ((now.hours / 12) % 2 == 0) {
        now.amORpm = 'a';
    } else {
        now.amORpm = 'p';
    }

    now.hours = now.hours % 12;

    printf("It is %d hours %d minutes %cm\n", now.hours, now.minutes, now.amORpm);

    return 0;
}
