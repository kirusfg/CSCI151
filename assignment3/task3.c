#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	fclose(inputFile);

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

double ticketPrice(station line[], int departure, int destination, int ticketClass) {
	double cost, total, distance;

	//Assigning one ticket cost dependent on the class of the ticket
	cost = (ticketClass == 1) ? 0.25 : 0.15;

	//Calculating total ticket price, taking absolute value for both directions
	distance = line[departure].km - line[destination].km;
	distance = (distance < 0) ? -distance : distance;

	total = cost * distance;

	return total;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));

	int i = 0, numberOfStationsScanned;
	int destination, departure, ticketClass;
	station railwayLine[100];

	numberOfStationsScanned = readStations("london-cambridge.txt", railwayLine);

	//Testing the implementation
	for (i = 0; i < 10; i++) {
		//Randomizing values using time seeding on line 72
		destination = rand() % 100 % numberOfStationsScanned;
		departure = rand() % 100 % numberOfStationsScanned;
		ticketClass = rand() % 2;
		//Printing
		printf("Departure: %2d Destination: %2d Ticket class: %d ", departure, destination, ticketClass);
		printf("Total cost: %.2f\n", ticketPrice(railwayLine, destination, departure, ticketClass));
	}

	return 0;
}