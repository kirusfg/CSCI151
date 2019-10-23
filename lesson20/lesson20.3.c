/*
Implement a function which reverses the string fromStr and saves the result to toStr
*/

#include <stdio.h>

void reverse(char fromStr[], char toStr[]) {
	int i = 0, length = 0;

	while (fromStr[i] != '\0') {
		length++;
		i++;
	}

	i = 0;

	while (fromStr[i] != '\0') {
		toStr[length - 1 - i] = fromStr[i];
		i++;
	}

	toStr[length] = '\0';
}

int main(void) {
	char name[] = "mynameisjacob";
	char reversed[100];

	reverse(name, reversed);

	printf("%s\n", reversed);

	return 0;
}