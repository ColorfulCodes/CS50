#include <stdlib.h>
#include <stdio.h>

// *Note: A pointer is a variable whose value is the address of another variable

struct node {
    int value;
    // next pointer, should point to the next node in the list
    //"stuct node*" is type like "int* num"
    // struct node* is  pointer to struct node and is type and next is the name of the variable
    // according to cdec1, "declare next as pointer to struct node"
    struct node* next; // pointer of structure type
};

// set existing type, node, to the alias, node_t
typedef struct node node_t;

// Function to print out the LL
// head pointer tells us where to start
void printlist(node_t *head) {
    node_t *temporary = head;

    while (temporary != NULL) {
        //print out the value of the node that temporary points to

        printf("%d - ", temporary->value);
        // to creep/move along the list
        temporary = temporary->next;
    }
    printf("\n");
}

int main() {
    node_t n1, n2, n3;
    // declaring head pointer
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    //link them up

    //make head point to the address of n3
    head = &n3;
    // set each node's next pointer to the address of the other node
    n3.next = &n2;
    n2.next = &n1;
    // this is how we know when to stop.
    n1.next = NULL;
    head = head->next;
    //call the function to print
    printlist(head);
    return 0;
}