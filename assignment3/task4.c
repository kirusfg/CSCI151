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

double ticketPrice(station line[], int departure, int destination, int ticketClass) {
	double cost, total, distance;
	int size;

	//Assigning one ticket cost dependent on the class of the ticket
	cost = (ticketClass == 1) ? 0.25 : 0.15;

	//Calculating total ticket price, taking absolute value for both directions
	distance = line[departure].km - line[destination].km;
	distance = (distance < 0) ? -distance : distance;

	total = cost * distance;

	return total;
}

int main(void) {
	int i, numberOfStationsScanned;
	int destination, departure, ticketClass;
	station railwayLine[100];
	char nextPurchase;

	numberOfStationsScanned = readStations("london-cambridge.txt", railwayLine);

	while (numberOfStationsScanned != 0) {
		printf("Here is the list of stations:\n\n");

		//Printing out the list of stations
		for (i = 0; i < numberOfStationsScanned; i++) {
			printStations(railwayLine, i, 1);
			printf("\n");
		}

		//Choosing departure station
		printf("\nChoose the index of your departure station: ");
		scanf("%d", &departure);

		printf("Here is the list of stations left:\n");
		for (i = 0; i < numberOfStationsScanned; i++) {
			if (i != departure) {
				printStations(railwayLine, i, 1);
				printf("\n");
			}
		}

		//Choosing destination station
		printf("\nChoose where you would like to arrive: ");
		scanf("%d", &destination);

		//Printing out the ticket prices and asking user for their choice
		printf("\nHere are the ticket prices: \n");
		printf("	First class: %.2f\n", ticketPrice(railwayLine, departure, destination, 1));
		printf("	Second class: %.2f\n", ticketPrice(railwayLine, departure, destination, 2));
		printf("\nChoose desired ticket class: ");
		scanf("%d", &ticketClass);

		//Printing purchase details
		printf("\nYour purchase has been successful: \n");
		printf("\n	Departure station: ");
		printStations(railwayLine, departure, 1);
		printf("\n	Destination station: ");
		printStations(railwayLine, destination, 1);
		printf("\n	Ticket price: %.2f\n", ticketPrice(railwayLine, departure, destination, ticketClass));

		//Asking whether user wants to make another purchase
		do {
			printf("\nWould you like to make another purchase? (y or n): ");
			scanf(" %c", &nextPurchase);

			if ((nextPurchase == 'n') || (nextPurchase == 'N')) {
				return 0;
			} else if ((nextPurchase != 'y') || (nextPurchase != 'Y')) {
				break;
			}
		} while (numberOfStationsScanned != 0);
	}
}