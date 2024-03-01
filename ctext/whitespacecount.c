#include <stdio.h>

/* counts blanks, tabs, and newlines in input */
/* exercise 1-8 */

main() {
   int c, ws;
   
   ws = 0;
   while ((c = getchar()) != EOF) 
      if (c == ' ' || c == '\t' || c == '\n')
         ++ws;
   printf("%d\n", ws);
}