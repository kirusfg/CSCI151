/*
Implement a function which checks for equality of str1 and str2. 
You may not assume that these strings contain the same number of characters.
 */
#include <stdio.h>

#define true 1
#define false 0

_Bool areEqual(char str1[], char str2[]) {
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return false;
		}
		i++;
	}

	return true;
}

int main(void) {
	char a[] = "Hello";
	char b[] = "Hellofriend";

	printf("%d", areEqual(a, b));

	return 0;
}