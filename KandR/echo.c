#include <stdio.h>

/* copy input to output */
/* CTRL-D to send EOF */
int main()
{
    int c;

    while((c = getchar()) != EOF)
        putchar(c);
        /* verify c = getchar() != EOF is either 1 or 0 */
        /* printf("%d\n", c = getchar() != EOF);
    printf("%d\n", c = getchar() != EOF); */
}
