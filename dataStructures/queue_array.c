#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int QUE[20];
const int EMPTY = -1;
int position = -1;
int retrieve = 0;

//push, append to front of array
bool push(int num) {
    if (position >= 19) return false;
    position += 1;
    QUE[position] = num;
    return true;
}

//pop from top of array
int pop() {
    
    if(QUE[retrieve] == 0) return false;
    int hold = QUE[retrieve];
    retrieve ++;
    return hold;

}

// PEEK

// First in first out

int main() {
    push(12);
    push(90);
    push(22);

    int t;
    //why does pop equal 1
    while ((t = pop()) != 0) {
        printf("t = %d\n",t);

    }

}