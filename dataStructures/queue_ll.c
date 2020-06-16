#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct node {
    int value;
    //declare next as pointer to struct node
    struct node* next;
};

typedef struct node node_t;

void printlist(node_t* head) {
    node_t *temporary = head;

    while (temporary != NULL) {
        //print out the value of the node that temporary points to

        printf("%d - ", temporary->value);
        // to creep/move along the list
        temporary = temporary->next;
    }
    printf("\n");
}

//push, append to front of array
node_t *push(node_t **head, int value) {
    //create an new node and point to head
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = *head;
    *head = result;
    return result;
}

//first in first out
// ->3->2->1
node_t* pop(node_t *head) {
    //Remove new node and point to head
    // Move through end of list, check if next value is NULL
    // If so, current equals previous and previous points to null
    node_t* prev = NULL;
    node_t* current = head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    prev = current;
    free(current);
    return current;

}


// First in first out

int main() {
    node_t *head = NULL;
    push(&head, 12);
    push(&head, 90);
    push(&head, 22);

    printlist(head);
    pop(head);
    printlist(head);
    pop(head);
    printlist(head);


}