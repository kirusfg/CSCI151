/*
Using recursion to convert a number into binary
 */

#include <stdio.h>

void printBinary(int n) {
	if (n < 2) {
		printf("1");
	} else {
		printf("%d", n % 2);
		printBinary(n / 2);
	}
}

int main(void) {
	printBinary(156);

	return 0;
}