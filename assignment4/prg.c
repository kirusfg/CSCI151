#include <stdio.h>
#include <stdlib.h>

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

student* readStudents(char *fileName, int* entry_size, int all_ids[], int* studentSize) {
	int i;
	char ch;

	//Working with the file
	FILE *file = fopen(fileName, "r");

	if (file == NULL) {
		printf("Error opening the file\n");
	}
	
	//Scanning the number of entries
	fscanf(file, "%d", entry_size);

	//Checking that the file is not empty	
	if (*entry_size == 0 || (ch = getc(file)) == EOF) {
		printf("The file is empty");
		exit(-1);
	}

	//Allocating memory in the heap for an array of type student big enough to contain "entry_size" number of elements
	student *students = (student*)malloc(*entry_size * sizeof(student));

	//Allocating 30 bytes of memory for firstName and secondName elements of the student structure
	for (i = 0; i < *entry_size; i++) {
		students[i].firstName = (char*)malloc(30 * sizeof(char));
		students[i].secondName = (char*)malloc(30 * sizeof(char));
	}

	//Reading in the data from the file
	i = 0;
	while (!feof(file)) {
		fscanf(file, "%s", students[i].firstName);
		fscanf(file, "%s", students[i].secondName);
		fscanf(file, "%d", &students[i].ID);
		fscanf(file, "%d", &students[i].grade);
		i++;
	}

	//Setting each element in all_ids to 0
	for (i = 0; i <= 100; i++) {
		all_ids[i] = 0; 
	}

	//Counting how many unique students are there in the file with the number of their grades associated
	for (i = 0; i < *entry_size; i++) {
		all_ids[(int)(students[i].ID)]++;
	}

	//Counting the number of unique student ids
	*studentSize = 0;
	for (i = 1; i <= 100; i++) {
		if (all_ids[i] != 0) {
			(*studentSize)++;
		}
	}

	fclose(file);
	
	return students;
}

int getMaxGrade(student *students, int from, int to) {
	if (from == to) {
		return students[from].grade;	//Base case
	} else {
		return (getMaxGrade(students, from + 1, to) > students[from].grade) ? getMaxGrade(students, from + 1, to) : students[from].grade;
	}
}

int getTopThreeAvgGrade(student* students, int entry_size, int id, int all_ids[]) {
	int topThree[3] = {0, 0, 0};
	int i, average = 0;

	//Fullfilling the topThree array with the student's 3 highest grades
	for (i = 0; i < entry_size; i++) {
		if (students[i].ID == id) {
			if (students[i].grade >= topThree[2]) {
				topThree[0] = topThree[1];
				topThree[1] = topThree[2];
				topThree[2] = students[i].grade;
			} else if (students[i].grade >= topThree[1]) {
				topThree[1] = students[i].grade;
			} else if (students[i].grade >= topThree[0]) {
				topThree[0] = students[i].grade;
			}
		}
	}

	//Returning the average dependent on whether there are less than 3 entries or not
	if (all_ids[id] == 0) {
		return 0;
	} else if (all_ids[id] < 3) {
		return (topThree[0] + topThree[1] + topThree[2]) / all_ids[id];
	} else {
		return (topThree[0] + topThree[1] + topThree[2]) / 3;
	}
}

void fillAllStudentsAvgGrades(topThreeAvg *averages[], student* students, int entry_size, int all_ids[]) {
	int i, idCounter = 0;

	for (i = 1; i <= 100; i++) {
		if (all_ids[i] != 0) {
			averages[idCounter]->ID = i;
			averages[idCounter]->avgGrade = getTopThreeAvgGrade(students, entry_size, i, all_ids);
			idCounter++;
		}
	}
}

void printAllAverages(topThreeAvg* averages[], int studentSize, student* students, int entry_size, int all_ids[]) {
	printf("\nFirst \tLast \tID \tAvg\n");

	int uniqueIDCounter = 0;
	for (int i = 1; i <= 100; i++) {
		if (all_ids[i] != 0) {
			for (int j = 0; j < entry_size; j++) {
				if (students[j].ID == i) {
					printf("%s\t", students[j].firstName);
					break;
				}
			}
			for (int j = 0; j < entry_size; j++) {
				if (students[j].ID == i) {
					printf("%s\t", students[j].secondName);
					break;
				}
			}
			printf("%d\t", i);
			printf("%d\n", averages[uniqueIDCounter]->avgGrade);
			uniqueIDCounter++;
		}
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int i, numberOfEntries, numberOfStudents;
	int *all_ids = (int*)malloc(101 * sizeof(int));

	//Allocating memory of 100 bytes for the file name, receiving input from the user
	char *fileName = (char*)malloc(100 * sizeof(char));
	printf("Enter the file name: ");
	scanf(" %s", fileName);
	printf("\n");

	student *studentList;
	
	//Testing the readStudents() function
	studentList = readStudents(fileName, &numberOfEntries, all_ids, &numberOfStudents);
	for (i = 0; i < numberOfEntries; i++) {
		printf("%s ", studentList[i].firstName);
		printf("%s ", studentList[i].secondName);
		printf("%d ", studentList[i].ID);
		printf("%d\n", studentList[i].grade);
	}

	//Testing the getMaxGrade() function
	printf("\nMaximum grade is %d", getMaxGrade(studentList, 0, numberOfEntries - 1));
	
	//Testing the getTopThreeAvgGrade() function
	printf("\n");
	for (i = 1; i <= 100; i++) {
		if (all_ids[i] != 0) {
			printf("\nThe top three average for student with id %d is %d", i, getTopThreeAvgGrade(studentList, numberOfEntries, i, all_ids));
		}
	}

	//Allocating enough memory for each pointer in the array
	topThreeAvg *averages[numberOfStudents];
	for (i = 0; i < numberOfStudents; i++) {
		averages[i] = (topThreeAvg*)malloc(sizeof(topThreeAvg));
	}

	//Testing the fillAllStudentsAvgGrades() function
	fillAllStudentsAvgGrades(averages, studentList, numberOfEntries, all_ids);
	printf("\n\nContents of topThreeAvg *averages[]:");
	for (i = 0; i < numberOfStudents; i++) {
		printf("\nThe top three average for student with id %d is %d", averages[i]->ID, averages[i]->avgGrade);
	}

	//Testing the printAllAverages() function
	printf("\n");
	printAllAverages(averages, numberOfStudents, studentList, numberOfEntries, all_ids);

	//Freeing up the memory
	free(fileName);
	free(studentList);
	free(all_ids);
	for (i = 0; i < numberOfStudents; i++) {
		free(averages[i]);
	}
	
	return 0;
}