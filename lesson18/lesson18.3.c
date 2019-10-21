/*
Using recursion to find minimum value in an array
 */

#include <stdio.h>

double minValue(double arr[], int from, int to) {
	if (from == to) {
		return (arr[from] < arr[to]) ? arr[from] : arr[to];
	} else {
		return (minValue(arr, from, to - 1) < arr[to]) ? minValue(arr, from, to - 1) : arr[to];
	}
}

int main(void) {
	double array[] = {0, 0, 0, 0, 0, 1};

	printf("%g\n", minValue(array, 0, 5));

	return 0;
}