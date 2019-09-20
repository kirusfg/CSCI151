#include <stdio.h>

int main(void) {
	int n, i, j, k;

	printf("Enter the dimensions of square matrices: ");
	scanf("%d", &n);

	int a[n][n], b[n][n], c[n][n];

	//Asking user to enter each value of a[n][n] and b[n][n]s arrays
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("b[%d][%d] = ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	printf("\n");

	//Assigning each value of n-dimensional array c to 0
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = 0;
		}
	}

	//Multiplying matrices and printing out the values simultaneously
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}