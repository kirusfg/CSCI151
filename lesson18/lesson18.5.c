/*
Using recursion to compute "n choose k"
 */

#include <stdio.h>

long choose(int n, int k) {
	if ((n == k) || (k == 0)) {
		return 1;
	} else {
		return choose(n - 1, k - 1) + choose(n - 1, k);
	}
}

int main(void) {
	printf("%d\n", choose(4, 2));

	return 0;
}