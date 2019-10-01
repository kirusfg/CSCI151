/*
Write a function that takes an array of doubles and its size as arguments, 
and reverses the order of all of the elements inside of the array.  
In order to properly test your implementation, create a second function 
which outputs the values stored in an array of doubles.
 */

#include <stdio.h>

double reverseArray(int size, double array[size]) {
	double temp;

	for (int i = 0; i < size / 2; i++) {
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}

	return array[size];
}

void printArray(int size, double array[size]) {
	for (int i = 0; i < size; i++) {
		printf("%g ", array[i]);
	}
	printf("\n");
}

int main(void) {
	double array[] = {1.0, 2.0, 3.0, 4.0, 5.0};

	printArray(5, array);
	reverseArray(5, array);
	printArray(5, array);

	return 0;
}