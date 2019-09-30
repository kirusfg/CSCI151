/*
Write a function, expApprox(double x, int n), which approximates 
the exponential function by calculating the first n terms of its 
Taylor series expansion about 0
 */

#include <stdio.h>

double expApprox(double x, int n) {
	double numerator = x, value = 1;
	int i, j;
	long long unsigned int factorial = 1;

	for (i = 1; i < n; ++i, numerator *= x, factorial *= i) {
		value += numerator / factorial;
		//printf("%d %g %g %g\n", i, numerator, factorial, value);
	}

	return value;
}

int main(void) {
	printf("%1.16f", expApprox(2, 20));

	return 0;
}