#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
//POINTER TO NODE, TYPE NODE POINTER
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

//function that creates new nodes

//return node_t pointer
// creat pointer to the new node
// RETURNS ADDRESS TO NODE
node_t *create_new_node(int value) {
    //create dynamically allocated pointer
    // why second pointer?
    //enough space to put a node_t in that memory
    //transfer owner of memory to the caller, once scope finishes memory is reclaimed for other users
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

//function to add node to the head of the list
// pass a pointer to a pointer, head
//defining the variable that hold the address as a pointer
node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    // point new node's next pointer to head
    //
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

//delete node
node_t *delete_node(node_t *head, int value) {
    // move through the head
    node_t *current = head;
    node_t *prev = NULL;
    while (current != NULL) {
        if (current->value == value) {
            prev->next = current->next;
            printf("This is previous: %d\n", prev->value);
            // do I need this?
            prev =current;
            //free(current);
            return current;
        }
        prev = current;
        current = current->next;
        
    }

}

int get_length(node_t *head) {
    node_t * current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count += 1;
    }
    return count;
}

// bubble sort linked list

// for i from 1 to N
//     for j from 0 to N-1
//         if a[j] > a[j+1]
//             temp = a[j+1]
//             a[j+1] = a[j]
//             a[j] = temp



node_t *bubble_sort(node_t *head) {
    node_t *current = head;
    //node_t *prev = NULL;
    int count = 0;
    node_t *temp;
    //returns length of LL
    int leng = get_length(head);
    while (count != leng) {
        while (current->next != NULL) {
            // needs to be done for every item in the LL
            if (current->value > current->next->value) {
                temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
            }
            current = current->next;
        }
        current = current->next;
    }   
        count+=1;
}



// Check is LL is sorted. Return boolean if sorted or not
// bool exists in the current C - C99, but not in C89/90.
bool is_sorted(node_t *head) {
    node_t *current = head;
    while (current->next != NULL) {
        if (current->value > current->next->value) {
            printf("False\n");
            return false;
        }
        current = current->next;
    }return true;
}

//function that finds a node
//node_t is the type of return: return type
// pointer to head (node_t *head)
node_t *find_node(node_t *head, int value) {
    //temporary node point
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) {
            //why not tmp->value
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

    // CREATING LINKED LIST
    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        // sending the address of the head variable
        //calling by reference
        //SINCE HEAD IS ALREADY A NODE POINTER
        insert_at_head(&head, tmp);
    }

    //link them up
    //tmp = find_node(head, 13);
    printf("Found node with value %d the pointer: %p\n", tmp->value, tmp);

    //insert_after_node(tmp, create_new_node(75));

    //delete_node(head,9);
    printlist(head);
    //is_sorted(head);
    //printf("The length of the LL is %d\n", get_length(head));
    //bubble_sort(head);
    return 0;
}