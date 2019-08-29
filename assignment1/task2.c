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

    int number, cachedNumber, reverse;
    _Bool palindrome;

    //Getting input from user
    printf("Enter an integer: ");
    scanf("%d", &number);

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
    printf("Number: %d, reverse: %d", cachedNumber, reverse);

    //Checking if a number is a palindrome
    if (cachedNumber == reverse) {
        palindrome = 1;
    } else {
        palindrome = 0;
    }

    //Printing out whether a number is a palindrome or not
    if (palindrome == 1) {
        printf(", is a palindrome.");
    } else {
        printf(", is not a palindrome.");
    }

    return 0;
}
