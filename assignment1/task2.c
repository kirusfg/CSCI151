/*
 *  task2.c
 *
 *  August 28, 2019
 *
 *
*/

#include <stdio.h>

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    long long unsigned int number, cachedNumber, reverse;
    _Bool palindrome;

    //Getting input from user
    scanf("%llu", &number);

    //Storing entered number to a separate variable to display later
    cachedNumber = number;
    reverse = 0;

    /* Reversing the number:
     * Getting a digit from the right of a number and
     * assigning it to the left digit of a reverse number
    */
    while (number != 0) {
        reverse = reverse * 10 + (number % 10);
        number /= 10;
    }

    //Printing out the number and its reverse
    printf("Number: %lld, reverse: %lld", cachedNumber, reverse);

    //Checking if a number is a palindrome
    if (cachedNumber == reverse) {
        palindrome = 1;
    } else {
        palindrome = 0;
    }

    //Printing out whether a number is a palindrome or not
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
