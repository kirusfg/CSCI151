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

student* readStudents(char *fileName, int* entry_size, int all_ids[], int* studentSize) {
	int i;

	//Working with the file
	FILE *file = fopen(fileName, "r");

	if (file == NULL) {
		printf("Error opening the file\n");
	}

	//Scanning the number of entries
	fscanf(file, "%d", entry_size);

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
		//printf("Success %d\n", i);
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
	
	return students;
}

int getMaxGrade(student *students, int from, int to) {
	if (from == to) {
		return students[from].grade;	//Base case
	} else {
		return getMaxGrade(students, from + 1, to);
	}
}

int getTopThreeAvgGrade(student* students, int entry_size, int id, int all_ids[]) {
	int topThree[3] = {0, 0, 0};
	int i, average = 0;

	for (i = 0; i < entry_size; i++) {
		if (students[i].ID == id) {
			if (students[i].grade >= topThree[2]) {
				topThree[0] = topThree[1];
				topThree[1] = topThree[2];
				topThree[2] = students[i].grade;
			}
		}
	}

	if (all_ids[id] == 0) {
		return 0;
	} else if (all_ids[id] == 1) {
		return (topThree[0] + topThree[1]+ topThree[2]);
	} else if (all_ids[id] == 2) {
		return (topThree[0] + topThree[1]+ topThree[2]) / 2;
	} else {
		return (topThree[0] + topThree[1]+ topThree[2]) / 3;
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int i, numberOfEntries, numberOfStudents;
	int *all_ids = (int*)malloc(101 * sizeof(int));

	char *fileName;
	fileName = "students3.txt";

	student *studentList;
	studentList = readStudents(fileName, &numberOfEntries, all_ids, &numberOfStudents);

	//Testing the readStudents function
	for (i = 0; i < numberOfEntries; i++) {
		printf("%s ", studentList[i].firstName);
		printf("%s ", studentList[i].secondName);
		printf("%d ", studentList[i].ID);
		printf("%d\n", studentList[i].grade);
	}
	
	i = 1;
	printf("\nID \t Number of grades\n");
	while (all_ids[i] != 0) {
		printf("%d \t %d\n", i, all_ids[i]);
		i++;
	}

	//Testing the getMaxGrade function
	printf("\nMaximum grade is %d", getMaxGrade(studentList, 0, numberOfEntries - 1));
	
	//Testing the getTopThreeAvgGrade function
	i = 1;
	printf("\n");
	while (all_ids[i] != 0) {
		printf("\nThe top three average for student with id %d is %d", i, getTopThreeAvgGrade(studentList, numberOfEntries, i, all_ids));
		i++;
	}
	
	return 0;
}