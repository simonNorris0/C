#include <stdio.h>

#define LOWER 0     /* lower limit of temperature table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

int main()
{
    float fahr, celsius;

    celsius = LOWER;

    printf("%3s\t%6s\n", "Celsius", "Fahr");
    while(celsius <= UPPER) {
        fahr = (9.0/5.0) * (celsius) + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
}
