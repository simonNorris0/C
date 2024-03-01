#include <stdio.h>

/* count blanks in input */

main() {
   int c, bl;
   
   bl = 0;
   while ((c = getchar()) != EOF)
      /* ' ' is the char constant for whitespace */
      if (c == ' ')
         ++bl;
   printf("%d\n", bl);
}