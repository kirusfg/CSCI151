/*
 *  lesson11.2.c
 *
 *  Create a program that substitutes the words found in the file values.txt in for
 *  the ‘$’ characters found in story.txt, and prints the result out to the console window.
 *  Enhance your story generator program so that it outputs the resulting story out to a file.
 *  The filename for the resulting story should be entered in by the user at the beginning
 *  of the program.
 *
 *  June 23, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main (void) {
    FILE *values, *story;
    FILE *outfile;

    char value[10];
    char ch;

    char outfileName[100];

    printf("Enter a name for the output file: ");
    scanf("%s", outfileName);

    values = fopen("values.txt", "r");
    story = fopen("story.txt", "r");
    outfile = fopen(outfileName, "w");

    if(values == NULL){
        printf("Error opening values.txt\n");
    } else if(story == NULL){
        printf("Error opening story.txt\n");
    } else if(outfile == NULL){
        printf("Error opening output.txt\n");
    }

    while(!feof(story)){
        ch = getc(story);

        if((ch != EOF) && (ch != '$')){
            putc(ch, outfile);
        }

        if(ch == '$'){
            fscanf(values, "%s", value);
            printf("%s", value);
            fprintf(outfile, "%s", value);
        } else if(ch == EOF){
            break;
        } else {
            printf("%c", ch);
        }
    }

    fclose(story);
    fclose(values);
    fclose(outfile);

    return 0;
}
