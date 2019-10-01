/*
Write a function double maxVal(int len, double arr[len][len]), 
which returns the maximum value stored in the two-dimensional array with dimensions len x len.
 */

#include <stdio.h>

double maxVal(int len, double arr[len][len]) {
	int i, j, iMax = 0, jMax = 0;
	double max = arr[0][0];

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			max = (arr[i][j] > max) ? arr[i][j] : max;
		}
	}

	return max;
}

int main(void) {
	int len = 2;
	double array[2][2] = {{10, 1023}, {123, 1}};

	printf("%g", maxVal(len, array));

	return 0;
}