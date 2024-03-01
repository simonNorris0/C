#include <stdio.h>

/* count lines in input 
   an input stream is a sequence of
   lines terminated by a newline char.
   Hence, counting lines is just counting 
   newline chars                            */

main()   {
   int c, nl;
   
   nl = 0;
   while ((c = getchar()) != EOF)
               /* 'character constant' == integer value */
      if (c == '\n')
         ++nl;
   printf("%d\n", nl);
}