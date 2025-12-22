#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//trees yo

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

typedef struct {
    node* root;
} tree;

node* createNode(int val);

tree* createTree(int n);

void insertLeft(node* parent, node* child);
void insertRight(node* parent, node* child);
void traverse(node* root);
void freeNodes(node* root);
void freeTree(tree* t);
void detach(node* parent, node* child);

bool isLeaf(node* n);
int height(node* root);
int size(node* root);
int countLeaves(node* root);
int depth(node* n);

node* findNode(node* root, int value);
bool contains(node* root, int value);
node* findMin(node* root);
node* findMax(node* root);
void cleanup(tree* t, node** temp, int count);

void fillInorder(node *n, int *arr, int *index);
int compare(const void *a, const void *b);
void assignInorder(node *n, int *arr, int *index);
void BSTNator(tree* t);
bool isBSTUtil(node* n, int min, int max);
bool isBST(node* root);

bool BinarySearch(node* n, int val);
node* findMinBST(node* root);
node* findMaxBST(node* root);

int main() {
    bool running = true;
    tree *t = NULL;
    node *n = NULL;
    node **temp = NULL;
    int count = 0;
    bool bst = false;
    while(running) {
        if(!t) {
            printf("Select: Create tree (1) | Exit (2)\n");
            int option;
            if(scanf("%d", &option) != 1) {
                printf("Invalid input, please enter a number.\n");
                while(getchar() != '\n');
                continue;
            }
            switch(option) {
                case 1: {
                    printf("Value: ");
                    int val;
                    if(scanf("%d", &val) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    t = createTree(val);
                    n = t->root;
                    printf("\nTree created successfully.\n\n");
                    break;
                }
                case 2: {
                    if(temp) {
                        for(int i = 0; i < count; i++) {
                            free(temp[i]);
                        }
                        free(temp);
                        temp = NULL;
                    }
                    exit(EXIT_SUCCESS);
                }
                default: {
                    printf("Invalid input.\n\n");
                    break;
                }
            }
        }   else {
            printf("Select: Insert (1) | View (2) | Navigate (3) | Info (4) | Search (5) | Detach (6) | FindMin/Max (7) | BSTNator (8) | Clear (9) | Exit (10)\n");
            int option;
            if(scanf("%d", &option) != 1) {
                printf("Invalid input, please enter a number.\n");
                while(getchar() != '\n');
                continue;
            }
            switch(option) {
                case 1: {
                    if(n->left && n->right) {
                        printf("Node is full.\n\n");
                        break;
                    }
                    printf("Select: Create new node (1) | Insert detached node (2)\n");
                    int option2;
                    if(scanf("%d", &option2) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    node* nodeToInsert = NULL;
                    if(option2 == 1) {
                        printf("Enter value: ");
                        int value;
                        if(scanf("%d", &value) != 1) {
                            printf("Invalid input, please enter a number.\n");
                            while(getchar() != '\n');
                            continue;
                        }
                        nodeToInsert = createNode(value);
                    }   else if(option2 == 2) {
                        if(!temp || count == 0) {
                            printf("No detached nodes available.\n\n");
                            break;
                        }
                        printf("Select a node to insert: ");
                        for(int i = 0; i < count; i++) {
                            printf("(%d) %d  ", i, temp[i]->value);
                        }
                        int sel;
                        if(scanf("%d", &sel) != 1) {
                            printf("Invalid input, please enter a number.\n");
                            while(getchar() != '\n');
                            continue;
                        }
                        if(sel < 0 || sel >= count) {
                            printf("Invalid selection.\n");
                            break;
                        }
                        nodeToInsert = temp[sel];
                        for(int j = sel; j < count - 1; j++) temp[j] = temp[j + 1];
                        count--;
                        if(count > 0) {
                            node **temp2 = realloc(temp, count * sizeof(node*));
                            if(!temp2) {printf("Memory Reallocation failed.\n"); exit(EXIT_FAILURE);}
                            temp = temp2;
                        } else {
                            free(temp);
                            temp = NULL;
                        }
                    }   else {
                        break;
                    }
                    if(!nodeToInsert) {break;}
                    printf("Insert Left (1) | Right (2): ");
                    int side;
                    if(scanf("%d", &side) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    if(side == 1) {
                        if(!n->left) {
                            insertLeft(n, nodeToInsert);
                            if(!isBST(t->root)) {
                                if(bst == true) {printf("Tree is no longer a BST.\n"); bst = false;}
                            }
                        }   else {
                            printf("Parent's left exists.\n\n");
                        }
                    }   else if(side == 2) {
                        if(!n->right) {
                            insertRight(n, nodeToInsert);
                            if(!isBST(t->root)) {
                                if(bst == true) {printf("Tree is no longer a BST.\n"); bst = false;}
                            }
                        }   else {
                            printf("Parent's right exists.\n\n");
                        }
                    }   else {
                        printf("Cancelled.\n");
                    }
                    break;
                }
                case 2: {
                    traverse(n);
                    printf("\n\n");
                    break;
                }
                case 3: {
                    printf("Select: Left (1) | Right (2) | Parent (3) | Root (4) | Menu (5)\n");
                    int anum;
                    if(scanf("%d", &anum) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    switch(anum) {
                        case 1: {
                            if(!n->left) {printf("Error: Node has no left child.\n"); break;}
                            n = n->left;
                            break;
                        }
                        case 2: {
                            if(!n->right) {printf("Error: Node has no right child.\n"); break;}
                            n = n->right;
                            break;
                        }
                        case 3: {
                            if(!n->parent) {printf("Error: Node has no parent.\n"); break;}     //assumes tree exists
                            n = n->parent;
                            break;
                        }
                        case 4: {
                            n = t->root;
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    printf("View: isLeaf (1) | Height (2) | Size (3) | countLeaves (4) | Depth (5) | isBST (6) | Menu (7)\n");
                    int anum;
                    if(scanf("%d", &anum) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    switch(anum) {
                        case 1: {
                            bool yes = isLeaf(n);
                            if(yes) {
                                printf("Node is a leaf.\n\n");
                            }   else {
                                printf("Node is not a leaf.\n\n");
                            }
                            break;
                        }
                        case 2: {
                            printf("Height is %d nodes.\n\n", height(n));
                            break;
                        }
                        case 3: {
                            printf("Tree contains %d nodes.\n\n", size(n));
                            break;
                        }
                        case 4: {
                            printf("There are %d leaf nodes.\n\n", countLeaves(n));
                            break;
                        }
                        case 5: {
                            printf("Tree is %d nodes deep.\n\n", depth(n));
                            break;
                        }
                        case 6: {
                            bool tmp = isBST(t->root);
                            if(tmp) {printf("Tree is a BST.\n");}
                            else {printf("Tree is not a BST>\n");}
                            break;
                        }
                    }
                    break;
                }
                case 5: {
                    printf("Find: ");
                    int anum;
                    if(scanf("%d", &anum) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    if(bst == true) {
                        if(BinarySearch(n, anum)) {
                            printf("Value was found.\n\n");
                        }   else {
                            printf("Value wasn't found.\n\n");
                        }
                    }   else {
                        if(contains(n, anum)) {
                            printf("Value was found.\n\n");
                        }   else {
                            printf("Value wasn't found.\n\n");
                        }
                    }
                    break;
                }
                case 6: {
                    printf("Detaching child of current node...\nDetach: Left (1) | Right (2)\n");
                    int anum;
                    if(scanf("%d", &anum) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    if(anum == 1 && n->left) {
                        count++;
                        node **pTemp = realloc(temp, count * sizeof(node*));
                        if(!pTemp) { printf("Error: Memory Reallocation Failed.\n"); exit(EXIT_FAILURE); }
                        temp = pTemp;
                        temp[count - 1] = n->left;
                        detach(n, n->left);
                        printf("Detached node with value: %d\n", temp[count - 1]->value);
                    }   else if(anum == 2 && n->right) {
                        count++;
                        node **pTemp = realloc(temp, count * sizeof(node*));
                        if(!pTemp) { printf("Error: Memory Reallocation Failed.\n"); exit(EXIT_FAILURE); }
                        temp = pTemp;
                        temp[count - 1] = n->right;
                        detach(n, n->right);
                        printf("Detached node with value: %d\n", temp[count - 1]->value);
                    }   else {
                        printf("No child to detach.\n");
                    }
                    break;
                }
                case 7: {
                    printf("Select: FindMin (1), FindMax (2), Menu (3)\n");
                    int anum;
                    if(scanf("%d", &anum) != 1) {
                        printf("Invalid input, please enter a number.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    switch(anum) {
                        case 1: {
                            node* minNode = NULL;
                            if(bst) {minNode = findMinBST(n);}
                            else {minNode = findMin(n);}
                            if(minNode) {printf("%d\n", minNode->value);}
                            else {printf("Empty Tree.\n");}
                            break;
                        }
                        case 2: {
                            node* maxNode = NULL;
                            if(bst) {maxNode = findMaxBST(n);}
                            else {maxNode = findMax(n);}
                            if(maxNode) {printf("%d\n", maxNode->value);}
                            else {printf("Empty Tree.\n");}
                            break;
                        }
                    }
                    printf("\n\n");
                    break;
                }
                case 8: {
                    BSTNator(t);
                    bst = true;
                    break;
                }
                case 9: {
                    cleanup(t, temp, count);
                    t = NULL;
                    temp = NULL;
                    count = 0;
                    break;
                }
                case 10: {
                    printf("Exiting...\n");
                    cleanup(t, temp, count);
                    t = NULL;
                    temp = NULL;
                    count = 0;
                    running = false;
                    break;
                }
                default: {
                    printf("Invalid input.\n\n");
                    break;
                }
            }
        }
    }
    printf("Exit successful.\n");
    return 0;
}

node* createNode(int val) {
    node* temp = malloc(sizeof(node));
    if(!temp) {printf("Error Allocating.\n"); exit(EXIT_FAILURE);}
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

tree* createTree(int n) {
    tree* t = malloc(sizeof(tree));
    if(!t) {printf("Error Allocating.\n"); exit(EXIT_FAILURE);}
    t->root = createNode(n);
    return t;
}

void insertLeft(node* parent, node* child) {
    if(parent->left) {printf("Error: Parent has a left node.\n"); return;}
    if(child->parent) {printf("Error: Child already has a parent.\n"); return;}
    parent->left = child;
    child->parent = parent;
}

void insertRight(node* parent, node* child) {
    if(parent->right) {printf("Error: Parent has a right node.\n"); return;}
    if(child->parent) {printf("Error: Child already has a parent.\n"); return;}
    parent->right = child;
    child->parent = parent;
}

void traverse(node* root) {
    if(!root) {return;}
    printf("%d ", root->value);
    traverse(root->left);
    traverse(root->right);
}

void freeNodes(node* root) {
    if(!root) {return;}
    freeNodes(root->left);
    freeNodes(root->right);
    free(root);
}

void freeTree(tree* t) {
    if(!t) {return;}
    freeNodes(t->root);
    free(t);
}

void detach(node* parent, node* child) {
    if(parent->left != child && parent->right != child) {printf("Error: Nodes are not connected.\n"); return;}
    if(child->parent != parent) {printf("Error: Nodes are not connected.\n"); return;}
    if(parent->left == child) {
        parent->left = NULL;
    }   else {
        parent->right = NULL;
    }
    child->parent = NULL;
}

bool isLeaf(node* n) {
    if(!n) return false;
    return !n->left && !n->right;
}

int height(node* root) {
    if(!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int size(node* root) {
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int countLeaves(node* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int depth(node* n) {
    int d = 0;
    while(n->parent) {
        d++;
        n = n->parent;
    }
    return d;
}

node* findNode(node* root, int value) {
    if(!root)
        return NULL;
    if(root->value == value)
        return root;
    node* found = findNode(root->left, value);
    if(found)
        return found;
    return findNode(root->right, value);
}

bool contains(node* root, int value) {
    return findNode(root, value) != NULL;
}

node* findMin(node* root) {
    if(!root)
        return NULL;
    node* min = root;
    node* leftMin = findMin(root->left);
    node* rightMin = findMin(root->right);
    if(leftMin && leftMin->value < min->value)
        min = leftMin;
    if(rightMin && rightMin->value < min->value)
        min = rightMin;
    return min;
}

node* findMax(node* root) {
    if(!root)
        return NULL;
    node* max = root;
    node* leftMax = findMax(root->left);
    node* rightMax = findMax(root->right);
    if(leftMax && leftMax->value > max->value)
        max = leftMax;
    if(rightMax && rightMax->value > max->value)
        max = rightMax;
    return max;
}

void cleanup(tree* t, node** temp, int count) {
    freeTree(t);
    if(temp) {
        for(int i = 0; i < count; i++) free(temp[i]);
        free(temp);
    }
}

void fillInorder(node *n, int *arr, int *index) {
    if(n == NULL)
        return;
    fillInorder(n->left, arr, index);
    arr[*index] = n->value;
    (*index)++;
    fillInorder(n->right, arr, index);
}

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;   
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void assignInorder(node *n, int *arr, int *index) {
    if (n == NULL) {return;}
    assignInorder(n->left, arr, index);
    n->value = arr[*index];
    (*index)++;
    assignInorder(n->right, arr, index);
}

void BSTNator(tree* t) {
    if(!t || !t->root) {printf("Tree is empty.\n"); return;}
    int n = size(t->root);
    int *arr = malloc(n * sizeof(int));
    if (!arr) {printf("Error Allocating.\n"); exit(EXIT_FAILURE);}
    int index = 0;
    fillInorder(t->root, arr, &index);
    qsort(arr, n, sizeof(int), compare);
    index = 0;
    assignInorder(t->root, arr, &index);
    free(arr);
}

bool isBSTUtil(node* n, int min, int max) {
    if(n == NULL) {return true;}  // empty tree is BST

    if(n->value < min || n->value > max) {return false;}

    return isBSTUtil(n->left, min, n->value - 1) &&
           isBSTUtil(n->right, n->value + 1, max);
}

bool isBST(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

bool BinarySearch(node* n, int val) {
    node* cur = n;
    while(cur) {
        if(cur->value == val) {return true;}
        if(val < cur->value) {cur = cur->left;}
        else {cur = cur->right;}
    }
    return false;
}

node* findMinBST(node* root) {
    if(!root) {return NULL;}
    node* cur = root;
    while(cur->left)
        cur = cur->left;
    return cur;
}

node* findMaxBST(node* root) {
    if(!root) {return NULL;}
    node* cur = root;
    while(cur->right)
        cur = cur->right;
    return cur;
}