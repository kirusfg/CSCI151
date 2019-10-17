#include <stdio.h>

typedef struct {
	char name[30];
	double km;
} station;

int readStations(char fileName[20], station line[]) {
	char ch;
	int i = 0;

	//Opening the file, checking whether it has been opened successfully
	FILE *inputFile = fopen(fileName, "r");
	if (inputFile == NULL) {
		printf("Error opening input file %s\n", fileName);
	}

	//Returning zero if the file is empty
	if ((ch = getc(inputFile)) == EOF) {
		return 0;
	}

	//Scanning the file
	while (!feof(inputFile)) {
		fscanf(inputFile, "%lf", &line[i].km);
		fscanf(inputFile, " %s", line[i].name);
		i++;
	}

	return i;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	
	int i = 0, numberOfStationsScanned;
	station railwayLine[100];

	numberOfStationsScanned = readStations("london-cambridge.txt", railwayLine);

	//Testing the implementation
	while (i != numberOfStationsScanned) {
		printf("%.1f %s\n", railwayLine[i].km, railwayLine[i].name);
		i++;
	}

	return 0;
}