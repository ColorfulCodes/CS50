#include <stdio.h>

/* Exercise 1-6, 1-7 */
/* copy input to output; 1st version */

// int main()
// {
//     int c;
//     while (c = getchar() != EOF) {
//         printf("%d",EOF);
//         putchar(c);
//     }
// }

/* count characters in input; 1st version */

// int main()

// {
//     long nc;

//     nc =0;
//     while (getchar() != EOF)
//         nc++;
//     printf("%ld\n", nc);

// }

/* count characters in input; 1st version */

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc) 
            printf("%.0f\n",nc);
    printf("%.0f yur\n", nc);
}
