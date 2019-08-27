/*
 *  task2.c
 *
 *  August 27, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    unsigned long long int number, digits;
    int i, j;
    _Bool palindrome;

    digits = 0;

    scanf("%llu", &number);

    for (i = 0; ; i++) {
        if (number % (int)pow(10, i) == number) {
            break;
        } else {
            digits++;
        }
    }

    long long int numberSplit[digits];

    for (i = 0, j = digits - 1; i < digits, j >= 0; i++, j--) {
        numberSplit[j] = (number % (unsigned long long int)pow(10, i + 1) - number % (unsigned long long int)pow(10, i)) / pow(10, i);
    }

    if (digits % 2 == 0) {
        for (i = 0, j = digits - 1; i <= digits / 2, j > digits / 2; i++, j--) {
            if (numberSplit[i] == numberSplit[j]) {
                palindrome = 1;
            } else {
                palindrome = 0;
                break;
            }
        }
    } else if (digits % 2 == 1) {
        for (i = 0, j = digits - 1; i < digits / 2, j > digits / 2; i++, j--) {
            if (numberSplit[i] == numberSplit[j]) {
                palindrome = 1;
            } else {
                palindrome = 0;
                break;
            }
        }
    }

    printf("Number: %d, reverse: ", number);

    for (i = digits - 1; i >= 0; i--) {
        printf("%d", numberSplit[i]);
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
