/*
Write a function, _Bool isPrime(int n), which indicates
whether or not the given integer n is a prime number. 
You may assume that the user will only call the function with value n > 1.
 */

#include <stdio.h>

_Bool isPrime(int n) {
	int i;

	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main(void) {
	printf("%d", isPrime(100));

	return 0;
}