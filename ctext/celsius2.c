#include <stdio.h>

/* pfint Fahrenheit-Celisus table from
   celsius.c in reverse (300, 280, ... 0) */
   
#define LOWER 0    /* lower limit of temperature table */
#define UPPER 300  /* upper limit */
#define STEP 20    /* step size */

main() {
   float fahr, celsius;
   
   fahr = UPPER;
   while (fahr >= LOWER) {
      celsius = (5.0/9.0) * (fahr-32.0);
      printf("%3.0f %6.1f\n", fahr, celsius);
      fahr = fahr + STEP;
   }
}