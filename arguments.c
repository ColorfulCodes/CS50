#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */

int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /*longest line saved here */

    max = 0;
    //printf("%d %s %s",len, line, longest);
    while ((len = getlines(line, MAXLINE)) > 0) {
        // printf("This is the line length %d %s %d.", len);
        if (len > max){
            max = len;
            // Saving line as longest
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("%s\n", longest);
    return 0;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
// This stores the longest line
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}

// If copying from C programming book change getline function to something else or it will not
// compile because it is already defined in the standard library

/* getline: read a line into s, return length */
int getlines(char s[], int lim)
{
    int c, i;
    // limit - 1 is making space for '\0' to make sure not over index
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    // if (c == '\n') {
    //     s[i] = c;
    //     i++;
    // }
    s[i] = '\0';
    printf("%d\n",i);
    printf("%s\n",s);
    return i;
}