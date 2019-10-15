#include <stdio.h>

typedef struct {
	char name[30];
	double km;
} station;

int readStations(char fileName[20], station line[]) {
	FILE *inputFile = fopen(fileName, "r");
	char ch[30];
	int i = 0;

	if (inputFile == NULL) {
		printf("Error opening input file %s\n", fileName);
	}

	do {
		fscanf(inputFile, "%lf", &line[i].km);
		fscanf(inputFile, " %s", line[i].name);
		i++;
	} while (!feof(inputFile));

	return i;
}

int main(void) {
	int i = 0, numberOfStationsScanned;
	station railwayLine[100];

	numberOfStationsScanned = readStations("london-cambridge.txt", railwayLine);

	while (i != numberOfStationsScanned) {
		printf("%.1f %s\n", railwayLine[i].km, railwayLine[i].name);
		i++;
	}

	return 0;
}