#include <stdio.h>

/* count lines, words, and characters in input */

#define IN 1   /* inside a word  */
#define OUT 0  /* outside a word */

main() {
   int c, nl, nc, nw, state;
   
   state = OUT;
   nl = nc = nw = 0;
   while ((c = getchar()) != EOF) {
      ++nc;
      if (c == '\n')
         ++nl;
      /* a word is any sequence of characters that doesnt contain
         a blank ' ', tab '\t', or newline '\n'                  */
      if (c == ' ' || c == '\t' || c == '\n')
         state == OUT;
      else if (state == OUT) {
         state == IN;
         ++nw;
      }        
   }
   printf("%d %d %d\n", nl, nc, nw);
}