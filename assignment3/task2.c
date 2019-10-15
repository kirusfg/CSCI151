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

void printStations(station line[], int stationNumber, int includeNumber) {
	int i;

	//Deciding whether to include station index or not
	if (includeNumber == 1) {
		printf("[%d] ", stationNumber);
	}
	
	//Printing
	for (i = 0; i < 30; i++) {
		if ((line[stationNumber].name[i] >= 'a' && line[stationNumber].name[i] <= 'z') || (line[stationNumber].name[i] >= 'A' && line[stationNumber].name[i] <= 'Z')) {
			printf("%c", line[stationNumber].name[i]);
		} else if (line[stationNumber].name[i] == '-') {	//Replacing '-' with ' '
			printf(" ");
		} else if (line[stationNumber].name[i] == '*') {	//Abrupting function upon reaching '*' symbol
			break;
		}
	}
}

int main(void) {
	int i = 0, numberOfStationsScanned;
	station railwayLine[100];

	numberOfStationsScanned = readStations("london-cambridge.txt", railwayLine);

	//Testing the implementation
	while (i != numberOfStationsScanned) {
		printStations(railwayLine, i, 1);
		printf("\n");
		i++;
	}

	printf("\n");
	i = 0;

	while (i != numberOfStationsScanned) {
		printStations(railwayLine, i, 0);
		printf("\n");
		i++;
	}

	return 0;
}