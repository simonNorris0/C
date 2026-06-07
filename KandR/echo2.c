#include <stdio.h>

/* exercise 1.9: write a program to copy its input to its output, 
 *               replacing each string of one or more blanks by a 
 *               single blank */

int main()
{
    int c, d;

    while((c = getchar()) != EOF) {
        if(d == ' ' && c == ' ')
            ; /* do nothing */
        else
            putchar(c);
        d = c;
    }
}
