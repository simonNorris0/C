#include <stdio.h>

/* copy input to output, replace each string of one
   or more blanks with a single blank               */
/* exercise 1-9  */

/* design: think about copying the input char by char
           if we save the state of the previous char,
           we can consider: if this char is a blank and
           the previous char is also a blank then we 
           should not print this one and move on to the next
           char.                                          */
           
#define START 0   /* to safely initialize the var for storing
                     the previously copied character         */
main() {
   int c, prev;
   
   prev = START;
   while ((c = getchar()) != EOF) {
      if (c == ' ')
         if (prev == ' ')
            /* do nothing */
            ;
         else
            /* print a single blank */
            printf("%d", c);
      else
         printf("%d", c);
   /* update state of the previous char to this char
      before moving on                              */
   prev = c;
   }
}