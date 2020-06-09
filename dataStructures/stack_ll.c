#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
// set stack_empty to lowest possible interger
#define STACK_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node * next;
}node;

node* head = NULL;

bool push(int value) {
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    
    newnode->value = value;
    newnode->next = head;
    head = newnode;
    return true;
}

int pop() {
    if (head == NULL) return STACK_EMPTY;

    int result = head->value;
    //save head
    node *tmp = head;
    // new head is next
    head = head->next;
    // free the node
    free(tmp);
    return result;
}


int main() {

    push(59);
    push(78);
    push(13);

    int t;

    while ((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n",t);

    }
}