#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *firstName;
	char *secondName;
	int ID;
	int grade;
} student;

typedef struct {
	int ID;
	int avgGrade;
} topThreeAvg;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	student *studentList;
	
	return 0;
}