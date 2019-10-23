/*
Implement a function which concatenates str1 and str2 and saves the result to resultStr
 */

#include <stdio.h>

void concat(char str1[], char str2[], char resultStr[]) {
	int i = 0, j = 0;

	while (str1[i] != '\0') {
		resultStr[j] = str1[i];
		j++;
		i++;
	}

	i = 0;

	while (str2[i] != '\0') {
		resultStr[j] = str2[i];
		j++;
		i++;
	}

	resultStr[j] = '\0';
}

int main(void) {
	char a[] = "Hi", b[] = "Welcome", c[100];

	concat(a, b, c);
	printf("%s\n", c);

	return 0;
}