/*
 *  lesson11.1.c
 *
 *  Write a program that copies the contents of an input file,
 *  and writes them to another file. The input and output file
 *  names should be provided by the user via the console at the
 *  beginning of the program.
 *
 *  June 23, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    FILE *infile;
    FILE *outfile;

    char infileName[20];
    char outfileName[20];
    char ch;

    printf("Enter the location of an input file: ");
    scanf("%s", infileName);

    printf("Enter the name of an output file: ");
    scanf("%s", outfileName);

    infile = fopen(infileName, "r");
    outfile = fopen(outfileName, "w");

    if (infile == NULL) {
        printf("Error opening input file %s\n", infileName);
    } else if (outfile == NULL) {
        printf("Error opening output file %s\n", outfileName);
    }

    while (!feof(infile)) {
        ch = getc(infile);
        fprintf(outfile, "%c", ch);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
