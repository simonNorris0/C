#include <stdio.h>

/* exercise 1-10: write a program to copy its input to its output, 
 *                replacing each tab by \t, each backspace by \b, 
 *                and each backslash by \\. This makes tabs and backspaces 
 *                visible in an unambiguous way. */

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            putchar('\\');
            putchar('t');
            continue;
        }
        if(c == '\b') {   /* input CTRL-h to pass backspace char,
                             backspace key doesn't store a char on 
                             modern terminals */
            putchar('\\');
            putchar('b');
            continue;
        }
        if(c == '\\') {
            putchar('\\');
            putchar('\\');
            continue;
        }
        /* if no special case is found, just echo the char */
        putchar(c);
    }
}
