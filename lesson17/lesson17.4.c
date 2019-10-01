/*
Write a function, transpose(int row, int col, double orig[row][col], 
double result[col][row]), which stores the transpose of the 2-dimensional 
array orig into another 2-dimensional array, result. 
(The array result initially has garbage values in it.) 
In order to properly test your implementation, create a second function 
which outputs the values stored in a 2-dimensional array of doubles.
 */

#include <stdio.h>

double transpose(int row, int col, double orig[row][col], double result[col][row]) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			result[j][i] = orig[i][j];
		}
	}

	return result[col][row];
}

void printArray(int row, int col, double array[row][col]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%g ", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	double array[2][2] = {{1, 2}, {3, 4}};
	double result[2][2];

	printArray(2, 2, array);
	transpose(2, 2, array, result);
	printArray(2, 2, result);

	return 0;
}