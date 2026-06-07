#include <stdio.h>

/* exercise 1.8: write a program to count blanks, tabs, and newlines */

int main()
{
    int c, nb, nt, nl;

    nb = 0;    /* number of blanks */
    nt = 0;    /* number of tabs */
    nl = 0;    /* number of newlines*/
    
    while((c = getchar()) != EOF) {
        if(c == ' ')
            nb++;
        if(c == '\t')
            nt++;
        if(c == '\n')
            nl++;
    }
    printf("number of blanks: %d\n", nb);
    printf("number of tabs: %d\n", nt);
    printf("number of lines: %d\n", nl);
}
