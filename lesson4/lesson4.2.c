/*
 *  lesson4.2.c
 *
 *  int limitations
 *
 *  May 15, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    int a = 2147483647;
    int b = 2147483648;
    int c = 2147483649;

    printf("%d %d %d\n", a, b, c);

    return 0;
}
