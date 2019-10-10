/*
Power function using recursion
 */

#include <stdio.h>

double power(double num, int pow) {
	if (pow == 0) {
		return 1;
	} else if (pow > 0) {
		return num * power(num, pow - 1);
	} else {
		return num / power(num, pow + 1);
	}
}

int main(void) {
	printf("%d\n", power(2.0, 2));
	printf("%d\n", power(2.0, -2));
	printf("%d\n", power(2.0, 0));

	return 0;
}