#include <stdio.h>

/* copy input to output; 1st version */

main() {
   /* getchar returns a distinctive value when there
      is no more input - EOF for 'end of file'
      EOF is defined in the std lib as an int - 
      therefore, in order to use EOF as our
      termination flag we must make the variable
      for our 'character stream' big enough to
      hold the EOF value - therefore, we use an int  */
   int c;
   
   c = getchar();
   /* using the symbolic constant (EOF) ensures nothing
      in our program depends on a specific numeric value
      here - making it more robust                      */
   while (c != EOF) {
      putchar(c);
      c = getchar();
   }
}