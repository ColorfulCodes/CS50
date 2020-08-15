#include <stdio.h>
#include <stdlib.h>


struct node {
    int key_value;
    struct node *left;
    struct node *right;
};


// goes to bottom of tree while there is a non-null node, deletes that leaf
// and then works its way back up. Deletes whole tree.
void delete_tree(struct node *leaf) {
    if (leaf == NULL) {
        return;
    }
    else {
        delete_tree(leaf->left);
        delete_tree(leaf->right);
        free(leaf);
    }
}

// Insert the value and the node
void insert(int key, struct node **leaf) {
    if( *leaf == NULL) {
        *leaf = (struct node*) malloc(sizeof( struct node ));
        (*leaf)->key_value = key;
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
    }
    else if (key < (*leaf)->key_value) {
        insert(key, &(*leaf)->left);
    }
    else if (key > (*leaf)->key_value) {
        insert(key, &(*leaf)->right);
    }
}

//search: Giving the binary search tree a value to search for
// returning a node pointer
struct node* search(int key, struct node* tree_node) {
    //Base Case
    if(tree_node == NULL) {
        // The entire search function returns NULL
        return NULL;
    }

    else if(tree_node->key_value == key) {
        return tree_node;
    }
    else{
        // The Recursion Case
        if (tree_node->key_value < key) {
            return search(key, tree_node->right);
        } else if (tree_node->key_value > key) {
            return search(key, tree_node->left);
        }
    }
    
}

void inorder(struct node*root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->key_value);
    inorder(root->right);
}

int main() {
    // Initialize root to 0 so the other functions are able to
    // recognize that the tree does not yet exist
    struct node *root = 0;
    root = insert(8, root);
    insert(46, &root);
    inorder(*root);
}