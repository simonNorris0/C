#include <stdio.h>

/* count tab characters in input */

main() {
   int c, tb;
   
   tb = 0;
   while ((c = getchar()) != EOF)
      /* '\t' is the tab char constant */
      if (c == '\t')
         ++tb;
   printf("%d\n", tb);

}