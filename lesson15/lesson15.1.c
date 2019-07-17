/*
 *  lesson15.1.c
 *
 *  Starting with the Color and Coords struct definitions given in the first video clip,
 *  define another struct called Square, which has an upper-left corner, a side length,
 *  an outline color, and a fill color. (Assume that a square’s sides are parallel to
 *  the x and y-axes.) Declare a Square variable in main, and initialize all of its member values.
 *  Similarly, define another struct for Rectangle, and declare and initialize a variable of that type.
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
    Coords point;
    int sideLength;
    Color fillColor;
    Color outsideColor;
} Square;

typedef struct {
    Coords point;
    int height, width;
    Color fillColor;
    Color outsideColor;
} Rectangle;

int main(void) {
    Square newSquare =
        {
            {12, 54},
            5,
            {255, 255, 255},
            {0, 0, 0}
        };

    Rectangle newRectangle =
        {
            {66, 10},
            10, 5,
            {255, 0, 255},
            {0, 0, 0}
        };

    return 0;
}
