/*
 *  exerciseA.c
 *
 *  Aug 7, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <string.h>

typedef struct {
	_Bool hasRobot;
	int robHeading;
	_Bool robAlive;
} gridSquare;

int main(void) {
	srand(time(NULL));

    gridSquare grid[10][10];
    int i, j, k, l;
    int row, column;
	int robotsAlive;
	_Bool gameEnded = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            grid[i][j].hasRobot = 0;
        }
    }

	for (i = 0; i < 10; i++) {
		j = rand() % 10;
		k = rand() % 10;
		l = rand() % 4;

		if (grid[j][k].hasRobot == 0) {
			grid[j][k].hasRobot = 1;
			grid[j][k].robHeading = l;	//0 - west, 1 - north, 2 - east, 3 - south
			grid[j][k].robAlive = 1;
		}
	}

	robotsAlive = 10;

	do {
		char command;

		//Displaying the game field
		printf("\n");
		printf("  ");

		for (i = 0; i < 10; i++) {
			printf("%d", i);
		}

		printf("\n");

		for (i = 0; i < 10; i++) {
			printf("%d ", i);
	        for (j = 0; j < 10; j++) {
	            if (grid[i][j].hasRobot == 1 && grid[i][j].robAlive == 1) {
					printf("R");
				} else if (grid[i][j].hasRobot == 1 && grid[i][j].robAlive == 0) {
					printf("@");
				} else {
					printf(".");
				}
	        }
			printf("\n");
	    }

		printf("\nEnter the command and coordinates: ");
		scanf(" %c %i %i", &command, &row, &column);

		//Command execution
		if (grid[row][column].hasRobot && grid[row][column].robAlive) {
			if (command == 'F') {
				switch (grid[row][column].robHeading) {
					case 0:
						if (column >= 1) {
							if (grid[row][column - 1].hasRobot && grid[row][column - 1].robAlive) {
								grid[row][column].robAlive = 0;
								grid[row][column - 1].robAlive = 0;
								robotsAlive -= 2;
							} else if (grid[row][column - 1].hasRobot && !grid[row][column - 1].robAlive) {
								grid[row][column].robAlive = 0;
								robotsAlive -= 1;
							} else {
								grid[row][column].hasRobot = 0;
								grid[row][column - 1].hasRobot = 1;
								grid[row][column - 1].robHeading = 0;
								grid[row][column - 1].robAlive = 1;
							}
						}
						break;
					case 1:
						if (row >= 1) {
							if (grid[row - 1][column].hasRobot && grid[row - 1][column].robAlive) {
								grid[row][column].robAlive = 0;
								grid[row - 1][column].robAlive = 0;
								robotsAlive -= 2;
							} else if (grid[row - 1][column].hasRobot && !grid[row - 1][column].robAlive) {
								grid[row][column].robAlive = 0;
								robotsAlive -= 1;
							} else {
								grid[row][column].hasRobot = 0;
								grid[row - 1][column].hasRobot = 1;
								grid[row - 1][column].robHeading = 1;
								grid[row - 1][column].robAlive = 1;
							}
						}
						break;
					case 2:
						if (column <= 8) {
							if (grid[row][column + 1].hasRobot && grid[row][column + 1].robAlive) {
								grid[row][column].robAlive = 0;
								grid[row][column + 1].robAlive = 0;
								robotsAlive -= 2;
							} else if (grid[row][column + 1].hasRobot && !grid[row][column + 1].robAlive) {
								grid[row][column].robAlive = 0;
								robotsAlive -= 1;
							} else {
								grid[row][column].hasRobot = 0;
								grid[row][column + 1].hasRobot = 1;
								grid[row][column + 1].robHeading = 2;
								grid[row][column + 1].robAlive = 1;
							}
						}
						break;
					case 3:
						if (row <= 8) {
							if (grid[row + 1][column].hasRobot && grid[row + 1][column].robAlive) {
								grid[row][column].robAlive = 0;
								grid[row + 1][column].robAlive = 0;
								robotsAlive -= 2;
							} else if (grid[row + 1][column].hasRobot && !grid[row + 1][column].robAlive) {
								grid[row][column].robAlive = 0;
								robotsAlive -= 1;
							} else {
								grid[row][column].hasRobot = 0;
								grid[row + 1][column].hasRobot = 1;
								grid[row + 1][column].robHeading = 3;
								grid[row + 1][column].robAlive = 1;
							}
						}
						break;
					default:
						printf("\nError: (F) robHeading does not exist\n");
						return 1;
						break;
				}
			} else if (command == 'L') {
				switch (grid[row][column].robHeading) {
					case 0:
						grid[row][column].robHeading = 3;
						break;
					case 1:
						grid[row][column].robHeading = 0;
						break;
					case 2:
						grid[row][column].robHeading = 1;
						break;
					case 3:
						grid[row][column].robHeading = 2;
						break;
					default:
						printf("\nError: (L) robHeading does not exist\n");
						return 1;
						break;
				}
			} else if (command == 'R') {
				switch (grid[row][column].robHeading) {
					case 0:
						grid[row][column].robHeading = 1;
						break;
					case 1:
						grid[row][column].robHeading = 2;
						break;
					case 2:
						grid[row][column].robHeading = 3;
						break;
					case 3:
						grid[row][column].robHeading = 0;
						break;
					default:
						printf("\nError: (R) robHeading does not exist\n");
						return 1;
						break;
				}
			} else {
				printf("Wrong input!\n");
			}
		} else if (grid[row][column].hasRobot == 1 && grid[row][column].robAlive == 0) {
			printf("\nRobot is not alive, please, choose another one!\n");
		} else {
			printf("\nYou haven't chosen any robots, please, choose one!\n");
		}

		if (robotsAlive == 0) {
			gameEnded = 1;
		}
	} while (!gameEnded);

	printf("\nYay! You have won!\n");

    return 0;
}
