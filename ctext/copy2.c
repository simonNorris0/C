#include <stdio.h>

/* copy input to ouptut; 2nd version */

main() {
   /* see copy1 for note on using int and EOF */
   int c;
   /* in c, any assignment is an expression and has a value */
   /* so an assignment can appear as part of a larger expression */
   /* NOTE~~~ the precedence of != is higher than = 
       making the parenthesis necessary for these expressions */
   while ((c = getchar()) != EOF)
      putchar(c);
}

/* ~~~
   This version centralizes the input - there is now only one reference
   to getchar() - and shrinks the program