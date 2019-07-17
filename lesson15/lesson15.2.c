/*
 *  lesson15.1.c
 *
 *  In the video clip “Structs Containing Arrays” above, we defined a new struct for pentagons.
 *  Instead of hard coding the initialization, write some code that will read in the necessary
 *  information from a file, and use it to initialize the Pentagon variable shape.
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
    int r, g, b;
} Color;

typedef struct {
    int x, y;
} Coords;

typedef struct {
    Color color;
    Coords point[5];
} Pentagon;

int main(void) {
    FILE *file;
    char ch;
    int i, values[13];
    Pentagon newPentagon = {};

    file = fopen("pentagon.txt", "r");

    if (file == NULL) {
        printf("Error opening pentagon.txt\n");
    }

    for (i = 0; i < 13; i++) {
        fscanf(file, "%d", &values[i]);
    }

    newPentagon.color = (Color){values[0], values[1], values[2]};
    newPentagon.point[0] = (Coords){values[3], values[4]};
    newPentagon.point[1] = (Coords){values[5], values[6]};
    newPentagon.point[2] = (Coords){values[7], values[8]};
    newPentagon.point[3] = (Coords){values[9], values[10]};
    newPentagon.point[4] = (Coords){values[11], values[12]};

    printf("%d %d %d\n", newPentagon.color.r, newPentagon.color.g, newPentagon.color.b);
    printf("%d %d\n", newPentagon.point[0].x, newPentagon.point[0].y);
    printf("%d %d\n", newPentagon.point[1].x, newPentagon.point[1].y);
    printf("%d %d\n", newPentagon.point[2].x, newPentagon.point[2].y);
    printf("%d %d\n", newPentagon.point[3].x, newPentagon.point[3].y);
    printf("%d %d\n", newPentagon.point[4].x, newPentagon.point[4].y);

    return 0;
}
