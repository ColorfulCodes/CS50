#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0,20,..... 300 */

// int main() 

// {
//     float fahr, celsius;
//     int lower, upper, step;

//     lower = 0; /* lower limit of temperature*/
//     upper = 300; /* upper limit of temperature */
//     step = 20; /* step size */

//     fahr = lower;
//     printf("Fahrenheit - Celcius\n");
//     printf("---------------------\n");
//     while (fahr <= upper) {
//         celsius = (5.0/9.0) * (fahr -32.0);
//         printf("%5.0f %10.1f\n", fahr, celsius);
//         fahr = fahr + step;
        
//     }
// }


/* print Celsius-Fahrenheit table
for fahr = 0,20,..... 300 */

// int main() 

// {
//     float fahr, celsius;
//     int lower, upper, step;

//     lower = 0; /* lower limit of temperature*/
//     upper = 300; /* upper limit of temperature */
//     step = 20; /* step size */

//     fahr = lower;
//     printf("Celcius - Fahrenheit\n");
//     printf("---------------------\n");
//     while (fahr <= upper) {
//         celsius = (5.0/9.0) * (fahr -32.0);
//         printf("%6.1f %9.0f\n", celsius, fahr);
//         fahr = fahr + step;
        
//     }
// }

// Excercise 1-5: For loop in reverse order 

int main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf( "%3d %6.1f\n",  fahr, (5.0/9.0) * (fahr -32.0));
}