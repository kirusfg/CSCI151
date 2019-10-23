/*
Implement a function which copies fromStr to toStr.
 */

#include <stdio.h>

void stringCopy(char fromStr[], char toStr[]) {
	int i = 0;

	while (fromStr[i] != '\0') {
		toStr[i] = fromStr[i];
		i++;
	}
	toStr[i] = '\0';
}

int main(void) {
	char a[] = "Hi";
	char b[] = "Welcome";

	stringCopy(a, b);
	printf("%s\n", a);
	printf("%s\n", b);

	return 0;
}