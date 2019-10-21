/*
Power function using recursion
 */

#include <stdio.h>

double power(double num, int pow) {
	if (pow == 0) {
		return 1;
	} else if (pow > 0) {
		return num * power(num, pow - 1);
	} else if (pow < 0) {
		return 1 / (num * power(num, -pow - 1));
	}
}

int main(void) {
	printf("%g\n", power(2.0, 2));
	printf("%g\n", power(2.0, -3));
	printf("%g\n", power(2.0, 0));

	return 0;
}