#include <stdio.h>

#define IN  1    /* Inside a word */
#define OUT 0   /* Outside a word */

/* count lines, words, and characters in input */

int main() {

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while((c = getchar()) != EOF) {
        ++nc;   /* increment # of chars */
        if(c == '\n')
            ++nl;   /* increment # of lines based on number of
                       newline chars */
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("number of lines, number of words, number of chars\n");
    printf("%9d %15d %16d\n", nl, nw, nc);
}
