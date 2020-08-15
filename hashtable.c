#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

//COLLISION: WHEN TWO NAMES MAP TO THE SAME LOCATION

typedef struct {
    char name[MAX_NAME];
    int age;
    // .....other things can go here later
} person;

// Array of pointers to people structs
// Makes it easy to tell when space is empty by setting to NULL

//question
//a pointer of type person. Like inheritance?
person * hash_table[TABLE_SIZE];

//Create random hash
// unsigned integers return 0 or positive
// for different names to map to different locations
unsigned int hash(char *name) {
    // GET LENGTH OF THE STRING
    int length = strnlen(name, MAX_NAME);
    printf("this is the stringlen: %d\n", length);
    unsigned int hash_value = 0;
    //go through string one character at a time and add up the ascii values
    for (int i = 0; i < length; i++) {
        //printf("this is the ascii %d\n",name[i]);
        hash_value += name[i];
        // to spread values out more and add randomness
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;

}

//Initially set all pointer equal to null
//Null pointer means that that's an empty location
void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        // Each time through the loop add the next character value to the sum
        hash_table[i] = NULL;
    }
}

//function to print out the status of the table
void print_table() {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

// funciton to insert a person into the table; will return a boolean
bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    // should return hash number location
    int index = hash(p->name);
    // if that space is taken, return false
    if (hash_table[index] != NULL) {
        return false;
    }
    // insert person struct
    hash_table[index] = p;
    return true;
}

//return point of person if they are in the table
//look them up by name
person *hash_table_lookup(char *name) {
    //get the index location
    int index = hash(name);
    //if location is not empty
    //strncmp compares two strings and maximum number of characters to be compared
    // if return value is 0 it means they are equal
    if(hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            return hash_table[index];
        } else {
            return NULL;
        }
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    if(hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            //if allocated to free the value
            return tmp;
        } else {
            return NULL;
        }
}

int main() {
    init_hash_table();
    print_table();

    // add people to the hash table
    person jacob = {.name="Jacob", .age=56};
    person kate = {.name="Kate", .age=22};
    person jazzy = {.name="Jazzy", .age=12};

    // add their addresses to the hash table
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&jazzy);
    print_table();

    person *tmp = hash_table_lookup("Kate");

    if (tmp == NULL) {
        printf("Not found\n");
    } else {
        printf("Found %s. \n", tmp->name);
    }

    tmp = hash_table_lookup("Pikachu");

    if (tmp == NULL) {
        printf("Not found\n");
    } else {
        printf("Found %s. \n", tmp->name);
    }

    hash_table_delete("Jazzy");
    print_table();

    return 0;
}