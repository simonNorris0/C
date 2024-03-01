#include <stdio.h>

/* count characters in input; 2nd version */

main() {
   double nc;
   
   for (nc = 0; getchar() != EOF; ++nc)
      /* c requires for statements to have a body,
         even if it does nothing                   */
      /* the line below is called a null statement */
      ;
   printf("%.0f\n", nc);
}