/*
Using fscanf and atoi, Implement some code that reads in the integers from a file,
and outputs their sum to the console window. The file may contain a combination of 
both integers and words separated by whitespace.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file = fopen("data.txt", "r");
	int a[100], sum = 0;
	int counter = 0, i = 0;
	char ch[100];

	if (file == NULL) {
		printf("Error opening data.txt");
		return -1;
	}

	while (!feof(file)) {
		fscanf(file, "%s", ch);
		a[counter] = atoi(ch);
		counter++;
	}

	for (i = 0; i < counter; i++) {
		sum += a[i];
	}

	printf("The sum is equal to %d\n", sum);

	return 0;
}