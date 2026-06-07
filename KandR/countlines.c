#include <stdio.h>

/* counts lines in input */
/* 'the standard library insures that an input text stream appears as 
 *  a sequence of lines, each terminated by a newline character' */

int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if(c == '\n') /* character constant for the escape sequence */
                      /* note ' ' for char constant,
                       *      " " makes a string constant! */
            ++nl;
    printf("%d\n", nl);
}
