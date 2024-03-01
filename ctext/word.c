#include <stdio.h>

/* print input one word per line */
/* exercise 1-12 */

main() {
   int c;
   
   while ((c = getchar()) != EOF) {
      /* a word is any sequence of characters that doesnt contain
         a blank ' ', tab '\t', or newline '\n'                  */
      if (c == ' ' || c == '\t' || c == '\n')
         printf("\n");
      printf("%d", c);
   }
}