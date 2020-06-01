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

//function that creates new nodes

//return node_t pointer
// creat pointer to the new node
node_t *create_new_node(int value) {
    //create dynamically allocated pointer
    // why second pointer?
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

//function to add node to the head of the list
// pass a pointer to a pointer, head
node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    // point new node's next pointer to head
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

// Insert a node after another node in the list
node_t *insert_after_node(node_t *node_to_insert_after, node_t* newnode) {
    //make the next of new node point to the next of node_to_insert_after
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;

}

//function that finds a node
node_t *find_node(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main() {
    node_t *tmp;
    // declaring head pointer
    node_t *head = NULL;

    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        //de-reference head for value
        insert_at_head(&head, tmp);
    }
    

    //link them up
    tmp = find_node(head, 13);
    printf("Found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(75));


    printlist(head);
    return 0;
}