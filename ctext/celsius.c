#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300     */
   
#define LOWER 0    /* lower limit of temperature table */
#define UPPER 300  /* upper limit */
#define STEP 20    /* step size */

main() {
   float fahr, celsius;
   
   fahr = LOWER;
   while (fahr <= UPPER) {
      celsius = (5.0/9.0) * (fahr-32.0);
      printf("%3.0f %6.1f\n", fahr, celsius);
      fahr = fahr + STEP;
   }
}