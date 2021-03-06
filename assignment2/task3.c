#include <stdio.h>
#include <math.h>

typedef struct {
	int xcoor;
	int ycoor;
	char name[30];
} city;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	
	FILE *infile;
	int a, i, j, n, iMin, jMin;
	double d, dMin;
	char ch[40];

	//Opening file cities.txt
	infile = fopen("cities.txt", "r");

	if (infile == NULL) {
		printf("Error opening cities.txt");
		return -1;
	}

	//Counting number of cities given
	a = 0;
	do {
		fscanf(infile, "%s", &ch);
		a++;
	} while (!feof(infile));

	n = a / 3;

	//If the number of cities given is more than 1, creating an array of type city of length n
	if (n <= 1) {
		printf("Not enough cities data in cities.txt\n");
		return -1;
	}
	city cities[n];

	//Reopening cities.txt
	fclose(infile);
	infile = fopen("cities.txt", "r");

	for (i = 0; i < n; i++) {
		fscanf(infile, "%d", &cities[i].xcoor);
		fscanf(infile, "%d", &cities[i].ycoor);
		fscanf(infile, "%s", cities[i].name);
	}

	//Evaluating distances between all cities and finding minimum distance
	dMin = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			//Euclidian distance
			d = sqrt((cities[i].xcoor - cities[j].xcoor) * (cities[i].xcoor - cities[j].xcoor) + (cities[i].ycoor - cities[j].ycoor) * (cities[i].ycoor - cities[j].ycoor));
			if (dMin == 0) {
				dMin = d;
				iMin = i;
				jMin = j;
			} else if (d < dMin) {
				dMin = d;
				iMin = i;
				jMin = j;
			}
		}
	}

	printf("Minimum distance: %g, between %s and %s", dMin, cities[iMin].name, cities[jMin].name);

	fclose(infile);

	return 0;
}