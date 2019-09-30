/*
Write a function, _Bool isIdeal(int n), which indicates if 
the positive number n is an ideal number. A number n is ideal 
if it is the sum over all its divisors (except n itself). 
The number 28, having divisors 1, 2, 4, 7, 14, 28 is ideal because 1+2+4+7+14=28.
 */

#include <stdio.h>

_Bool isIdeal(int n) {
	int i, sum = 0;

	for (i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	return (sum == n) ? 1 : 0;
}

int main(void) {
	printf("%d", isIdeal(28));

	return 0;
}