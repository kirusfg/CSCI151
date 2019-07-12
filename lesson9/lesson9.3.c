/*
 *  lesson9.3.c
 *
 *
 *  Write a program that gets an integer d between 1 and 366 from the user,
 *  which represents the d-th day of the year (2016).  If the input value
 *  falls outside of this range, print an error message and quit the program.
 *  Otherwise, print a message containing the day of the week, the name of
 *  the month, and the day (as a number) represented by d to the console window.
 *  For example, if d is 100, then the output should be “It is Saturday, April 9”.
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

    int d;

    scanf("%d", &d);

    printf("It is ");

    //Day of the week
    switch(d % 7){
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        default:
            printf("Sunday");
            break;
    }

    printf(", ");

    //Month and day
    if((d > 0) && (d <= 31)){
        printf("January %d\n", d);
    } else if((d > 31) && (d <= 60)){
        printf("January %d\n", d - 31);
    } else if((d > 60) && (d <= 91)){
        printf("March %d\n", d - 60);
    } else if((d > 91) && (d <= 121)){
        printf("April %d\n", d - 91);
    } else if((d > 121) && (d <= 152)){
        printf("May %d\n", d - 121);
    } else if((d > 152) && (d <= 182)){
        printf("June %d\n", d - 152);
    } else if((d > 182) && (d <= 213)){
        printf("July %d\n", d - 182);
    } else if((d > 213) && (d <= 244)){
        printf("August %d\n", d - 213);
    } else if((d > 244) && (d <= 274)){
        printf("September %d\n", d - 244);
    } else if((d > 274) && (d <= 305)){
        printf("October %d\n", d - 274);
    } else if((d > 305) && (d <= 335)){
        printf("November %d\n", d - 305);
    } else if((d > 335) && (d <= 366)){
        printf("December %d\n", d - 335);
    }

    return 0;
}
