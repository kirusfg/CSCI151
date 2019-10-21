/*
Modify the recursive implementation of int addSubarray(int x[], int from, int to)
shown in the video lectures so that it uses “back recursion” instead of “front recursion”.
 */

#include <stdio.h>

int addSubarray(int x[], int from, int to) {
	if (from == to) {
		return x[to];
	} else {
		return addSubarray(x, from + 1, to) + x[from];
	}
}

int main(void) {
	int x[] = {1, 2, 3, 4, 5};

	printf("%d\n", addSubarray(x, 0, 4));

	return 0;
}