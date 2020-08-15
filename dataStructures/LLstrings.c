#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//passing in an array is like passing in a pointer

struct node {
    
    struct node* next; // pointer of structure type
    char value[];
    
};

// Is it better to define a size.

// set existing type, node, to the alias, node_t
typedef struct node node_t;


node_t *create_new_node(const char *value) 
{
    // create space for node with malloc
    //length of string plus extra char? \0 and size of node_t?
    node_t *result = malloc(sizeof(node_t) + strlen(value) + 1);
    if(result)
    {
        strcpy(result->value, value);
        result->next = NULL;
    }
    return result;
}
// node_t *create_new_node(char value) {
//     // create space for node with malloc
//     node_t *result = malloc(sizeof(node_t));
//     // set the value of the new node
//     result->value = value;

//     result->next = NULL;
//     return result;
// }

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {

    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}
//Prints linked list
void printlist(node_t* head) {
    node_t *temporary = head;
    int count = 1;

    while (temporary != NULL) {
        //print out the value of the node that temporary points to
        printf("%d. %s\n", count, temporary->value);
        count++;
        // to move along the list
        temporary = temporary->next;
    }
    printf("\n");
}

int main() {
    node_t *tmp;
    // declaring head pointer
    node_t *head = NULL;

    // CREATING LINKED LIST
    // for (int i = 0; i < 25; i++) {
    //     tmp = create_new_node(i);
    //     // sending the address of the head variable
    //     //calling by reference
    //     //SINCE HEAD IS ALREADY A NODE POINTER
    //     insert_at_head(&head, tmp);
    // }
    
    
    tmp = create_new_node("I like food");
    insert_at_head(&head, tmp);
    tmp = create_new_node("sleep is nice");
    insert_at_head(&head, tmp);
    tmp = create_new_node("pink");
    insert_at_head(&head, tmp);
    printlist(head);

}