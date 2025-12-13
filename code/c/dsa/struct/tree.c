#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//trees yo

typedef struct node {
    int value;
    struct node *right;
    struct node *left;
}   node;

node *createNode(int val);
node *append(node *parent, node *child, bool left);

int main() {
    return 0;
}

node *createNode(int val) {
    node *root = malloc(sizeof(node));
    if(!root) {printf("Error Allocating.\n"); exit(EXIT_FAILURE);}
    root->left = NULL;
    root->right = NULL;
    root->value = val;
    return root;
}

node *append(node *parent, node *child, bool left) {
    if(left) {
        parent->left = child;
    }   else {
        parent->right = child;
    }
    return parent;
}