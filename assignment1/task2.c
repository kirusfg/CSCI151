/*
 *  task2.c
 *
 *  August 27, 2019
 *
 *
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    long long unsigned int number, cachedNumber, reverse;
    _Bool palindrome;

    scanf("%llu", &number);

    cachedNumber = number;
    reverse = 0;

    while (number != 0) {
        reverse = reverse * 10 + (number % 10);
        number /= 10;
    }

    printf("Number: %lld, reverse: %lld", cachedNumber, reverse);

    if (cachedNumber == reverse) {
        palindrome = 1;
    } else {
        palindrome = 0;
    }

    switch (palindrome) {
        case 1:
            printf(", is a palindrome.");
            break;
        case 0:
            printf(", is not a palindrome.");
            break;
        default:
            printf("Wrong input");
            break;
    }

    return 0;
}
