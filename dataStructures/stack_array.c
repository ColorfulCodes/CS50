#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
// set stack_empty to lowest possible interger
#define STACK_EMPTY INT_MIN

int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int value) {
    // if greater than actual length
    if (top >= STACK_LENGTH-1) return false;
    //increment moving along
    top ++;
    //fill stack with values
    mystack[top] = value;
    return true;
}

int pop() {
    //return lowest possible integer if empty
    if (top == EMPTY) return STACK_EMPTY;
    // top with be the index of whatever was added
    //to the end of the array
    int result = mystack[top];
    // decrement to move closer to front
    top --;
    return result;
}

// Last in first out
int main() {

    push(59);
    push(78);
    push(13);

    int t;

    while ((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n",t);

    }
}