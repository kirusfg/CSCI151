/*
Write a function, sumOfDigits(int n), that returns the sum 
of digits of the non-negative number n in its decimal representation. 
For n=129, for instance, the function returns the value 12, obtained as 1+2+9.
 */

#include <stdio.h>

int sumOfDigits(int n) {
	if (n <= 0) {
		return 0;
	}

	int i, digits = 1, sum = 0;

	for (i = 10; i <= n; i *= 10) {
		digits++;
	}

	for (i = 1; i <= digits; i++) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main(void) {
	printf("%d", sumOfDigits(187));

	return 0;
}