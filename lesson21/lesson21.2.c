/*
Implement the following function which converts a string representation of a floating-point number into a double
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

double strToDouble(char str[]) {
	double x = 0, j = 0.1;
	_Bool decimal = true, e = false, d = true, pos = true;
	int i = 0, degree = 0;

	while (str[i] != '\0') {
		if (i == 0 && str[0] == '-') {
			pos = false;
			i++;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9' && decimal) {
			x = x * 10 + (str[i] - '0');
			i++;
		} else if (str[i] == '.') {
			decimal = false;
			i++;
		} else if (!decimal && str[i] == 'e') {
			e = true;
			i++;
		} else if (!decimal && e) {
			if (str[i] == '-' && d) {
				d = false;
			} else if (str[i] >= '0' && str[i] <= '9') {
				degree = degree * 10 + (str[i] - '0');
			} else {
				break;
			}
			i++;
		} else if (!decimal) {
			x = x + (str[i] - '0') * j;
			j /= 10;
			i++;
		} else {
			return x;
		}
	}

	if (e) {
		if (d) {
			x = x * pow(10, degree);
		} else {
			x = x * pow(10, -degree);
		}
	}

	if (!pos) {
		x *= -1;
	}
	
	return x;
}

int main(void) {
	double x = 0;
	char string[] = "10123.11e-8";

	x = strToDouble(string);

	printf("%f", x);

	return 0;
}