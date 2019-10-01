/*
Write a function that takes an array of doubles and its 
size as arguments, and returns the index of the smallest element.
 */

#include <stdio.h>

int smallest(int size, double array[]) {
	int i, index = 0;
	double min = array[0];

	for (i = 0; i < size; i++) {
		index = (array[i] < min) ? i : index;
		min = (array[i] < min) ? array[i] : min;
	}

	return index;
}

int main(void) {
	double array[] = {10, 1023, 123, 1, -12, 5};

	printf("%d", smallest(6, array));

	return 0;
}