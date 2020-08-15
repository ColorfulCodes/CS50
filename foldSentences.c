#include <stdio.h>
#include <ncurses.h>            

#define MAXLINE 10

//From Stackoverflow https://stackoverflow.com/questions/62107312/why-does-getch-output-10-characters-on-first-run-line-but-9-characters-for-a?noredirect=1#comment109845572_62107312

// The first time through the loop i is zero. When you set i to zero inside the loop, 
// when control reaches the end of the for, the statement executed is i++ (making i 1), 
// then (c = getch()) != EOF

// \r (Carriage Return): A carriage return in C programming language is a special code that 
// helps to move the cursor/print head to the beginning of the current line.

// count number of chars, once it reaches certain amount
int main (void) 
{
    
    // to open curses terminal
    initscr();
    cbreak();

    int i, c;

    // first iteration set to 1
    for (i = 0; (c = getch()) != ERR; i++)
    {
         if (i == (MAXLINE-1))
         {
             printf("\r\n");
             
             i = -1;
         }
    }

    // to close curses terminal
    endwin();
}