/*
 *  lesson14.2.c
 *
 *  Define a new structure type called student which has members:
 *
 *   - ID (a six digit student ID)
 *   - gender (the character ‘m’ or ‘f’)
 *   - Three separate members that represent the three different components of your CSCI 151 grade
 *   (doubles between 0.0 and 100.0)
 *   - finalGrade (a double between 0.0 and 100.0)
 *  Then, write some code that declares a single student variable, and prompts the user to enter
 *  in values for the first five fields, and then uses this information to calculate and set the finalGrade.
 *  At the end, use a printf statement that prints out the field contents of the student variable
 *
 *  July 17, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

typedef struct {
    int ID;
    char gender;
    double grade1;
    double grade2;
    double grade3;
    double finalGrade;
} student;

int main(void) {
    student newStudent;

    printf("Enter student ID: ");
    scanf("%d", &newStudent.ID);

    printf("Enter your gender (m/f): ");
    scanf(" %c", &newStudent.gender);

    printf("Enter your first grade: ");
    scanf("%lf", &newStudent.grade1);
    printf("Enter your second grade: ");
    scanf("%lf", &newStudent.grade2);
    printf("Enter your third grade: ");
    scanf("%lf", &newStudent.grade3);

    newStudent.finalGrade = (newStudent.grade1 * 0.3) + (newStudent.grade2 * 0.3) + (newStudent.grade3 * 0.4);

    printf("\n");
    printf("student ID: %06d\n", newStudent.ID);

    if (newStudent.gender == 'f' || newStudent.gender == 'F') {
        printf("Female\n");
    } else if (newStudent.gender == 'm' || newStudent.gender == 'M') {
        printf("Male\n");
    } else {
        printf("Gender unspecified (wrong input)\n");
    }

    printf("First grade: %3.2f\n", newStudent.grade1);
    printf("Second grade: %3.2f\n", newStudent.grade2);
    printf("Third grade: %3.2f\n", newStudent.grade3);
    printf("Final grade: %3.2f\n", newStudent.finalGrade);

    return 0;
}
