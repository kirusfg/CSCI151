/*
 *  lesson4.1.c
 *
 *  Integer convertation
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
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;

    a = 010;
    b = 062;
    c = 05712;

    d = 5;
    e = 40;
    f = 125;
    g = 1000000;

    h = 0x23;
    i = 0x2A9;
    j = 0xDECAF;

    k = 38;
    l = 259;
    m = 98765;
    n = 1000000;

    //Part A: Octal to decimal
    printf("\n");
    printf("      Octal\t    Decimal\n");
    printf("---------------------------\n");
    printf("%#11o\t%11d\n", a, a);
    printf("%#11o\t%11d\n", b, b);
    printf("%#11o\t%11d\n", c, c);
    printf("\n");

    //Part B: Decimal to octal
    printf("\n");
    printf("    Decimal\t      Octal\n");
    printf("---------------------------\n");
    printf("%11d\t%#11o\n", d, d);
    printf("%11d\t%#11o\n", e, e);
    printf("%11d\t%#11o\n", f, f);
    printf("%11d\t%#11o\n", g, g);
    printf("\n");

    //Part C: Hexadecimal to decimal
    printf("\n");
    printf("Hexadecimal\t    Decimal\n");
    printf("---------------------------\n");
    printf("%#11x\t%11d\n", h, h);
    printf("%#11x\t%11d\n", i, i);
    printf("%#11x\t%11d\n", j, j);
    printf("\n");

    //Part D: Decimal to hexadecimal
    printf("\n");
    printf("    Decimal\tHexadecimal\n");
    printf("---------------------------\n");
    printf("%11d\t%#11x\n", k, k);
    printf("%11d\t%#11x\n", l, l);
    printf("%11d\t%#11x\n", m, m);
    printf("%11d\t%#11x\n", n, n);
    printf("\n");

    return 0;
}
