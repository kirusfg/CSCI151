#include <stdio.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int number, cachedNumber, reverse;

	//Getting a number from user
	printf("Enter an integer: ");
	scanf("%d", &number);

	//Storing entered number to a separate variable to display later
	cachedNumber = number;
	reverse = 0;

	printf("Number: %d, reverse: ", cachedNumber);
	/* Reversing the number:
	 * Getting a digit from the right of a number and
	 * assigning it to the left digit of a reverse number
	*/
	while (number != 0) {
		reverse = reverse * 10 + (number % 10);
		printf("%d", number % 10);	  //Printing each digit of a reverse number
		number /= 10;
	}

	//Special case for 0
	if (cachedNumber == 0) {
		printf("0");
	}

	//Printing out whether a number is a palindrome or not
	if (cachedNumber == reverse) {
		printf(", is a palindrome.");
	} else {
		printf(", is not a palindrome.");
	}

	return 0;
}
