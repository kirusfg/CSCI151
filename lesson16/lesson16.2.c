/*
Write a function, sinApprox(double x, int n), which approximates
the trigonometric sine function by calculating the first n terms
of its Taylor series expansion about 0
 */

#include <stdio.h>

double sinApprox(double x, int n) {
	double numerator = x, value = 0;
	int i, j = 1;
	long long unsigned int factorial = 1;

	for (i = 1; i < n; ++i, numerator *= -1 * x * x, factorial *= (j + 1) * (j + 2), j += 2) {
		value += numerator / factorial;
		//printf("%d %g %g %g\n", i, numerator, factorial, value);
	}

	return value;
}

int main(void) {
	printf("%1.16f", sinApprox(2, 20));

	return 0;
}