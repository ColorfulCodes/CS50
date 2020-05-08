#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words and characters in input */
int main()
{
    int c, nl, nw, nc, state;
    /* max 50 characters of space */

    state = OUT;
    nl = nw = nc = 0;
    

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
                nl++;
            }
        } else{
            if(state == OUT){
                state = IN;
                nw++;
                
            }
            putchar(c);
            nc++;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}