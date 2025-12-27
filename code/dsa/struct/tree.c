#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//trees yo

typedef enum {
    MODE_FREE,
    MODE_BST,
    MODE_AVL
}   TreeMode;

typedef struct node {
    int value;
    int height;
    struct node* left;
    struct node* right;
    struct node* parent;
}   node;

typedef struct {
    node* root;
}   tree;

bool readInt(const char *prompt, int *out);

node* createNode(int val);
tree* createTree(int n);
void insertLeft(node* parent, node* child);
void insertRight(node* parent, node* child);
void traverse(node* root);
void freeNodes(node* root);
void freeTree(tree* t);
void detach(node* parent, node* child);

bool isLeaf(node* n);
int size(node* root);
int countLeaves(node* root);
int depth(node* n);

node* findNode(node* root, int value);
bool contains(node* root, int value);
node* findMin(node* root);
node* findMax(node* root);

void fillInorder(node *n, int *arr, int *index);
node* buildBalancedBST(int *arr, int start, int end, node* parent);
void BSTNator(tree* t);
bool isBSTUtil(node* n, long long min, long long max);
bool isBST(node* root);

bool BinarySearch(node* n, int val);
node* findMinBST(node* root);
node* findMaxBST(node* root);

int AVLHeight(node* n);
void updateHeight(node* n);
int AVLBalance(node* n);
node* AVLRotateRight(node* y);
node* AVLRotateLeft(node* y);
bool isAVL(node* root);
void AVLNator(tree* t);
node* AVLInsert(node* root, int value);
void insertAVL(tree* t, int value);

int main() {
    tree *t = NULL;
    node *cursor = NULL;
    TreeMode mode = MODE_FREE;
    bool running = true;
    while (running) {
        if(!t) {
            printf("1) Create tree | 2) Exit\n> ");
            int opt;
            if(!readInt("Value: ", &opt)) {
                printf("Invalid input.\n");
                break;
            }
            if(opt == 1) {
                printf("Root value: ");
                int val;
                if(!readInt("Value: ", &val)) {
                    printf("Invalid input.\n");
                    break;
                }
                t = createTree(val);
                cursor = t->root;
                mode = MODE_FREE;
                printf("Tree created (Binary Tree).\n\n");
            }   else {
                break;
            }
            continue;
        }
        printf("\nMode: %s\n", mode == MODE_FREE ? "FREE" : mode == MODE_BST  ? "BST"  : "AVL");
        printf("1) Insert | 2) Navigate | 3) Info | 4) Search | 5) Convert | 6) Clear tree | 7) Exit\n> ");
        int opt;
        if(!readInt("Value: ", &opt)) {
            printf("Invalid input.\n");
            break;
        }
        switch(opt) {
            case 1: {
                int val;
                if(!readInt("Value: ", &val)) {
                    printf("Invalid input. Skipping insertion.\n");
                    break;
                }
                if(mode == MODE_FREE) {
                    if(contains(t->root, val)) {
                        printf("Value already exists in the tree. Skipping insertion.\n");
                        break;
                    }
                    int side;
                    printf("1) Insert Left | 2) Insert Right:\n> ");
                    if(scanf("%d", &side) != 1) {
                        printf("Invalid input.\n");
                        while(getchar() != '\n');
                        break;
                    }
                    node *n = createNode(val);
                    if(side == 1) insertLeft(cursor, n);
                    else if(side == 2) insertRight(cursor, n);
                    else { 
                        printf("Cancelled.\n"); 
                        free(n); 
                    }
                }
                else if(mode == MODE_BST) {
                    node *cur = t->root;
                    node *parent = NULL;
                    bool duplicate = false;
                    while(cur) {
                        parent = cur;
                        if(val < cur->value) cur = cur->left;
                        else if(val > cur->value) cur = cur->right;
                        else { duplicate = true; break; }
                    }
                    if(duplicate) {
                        printf("Value already exists in BST. Skipping insertion.\n");
                    } else {
                        node *n = createNode(val);
                        n->parent = parent;
                        if(val < parent->value) parent->left = n;
                        else parent->right = n;

                        node *p = parent;
                        while(p) { updateHeight(p); p = p->parent; }
                    }
                }
                else {
                    t->root = AVLInsert(t->root, val);
                    t->root->parent = NULL;
                }
                break;
            }
            case 2: {
                printf("1) Left | 2) Right | 3) Parent | 4) Root\n> ");
                int n;
                if(!readInt("Value: ", &n)) {
                    printf("Invalid input.\n");
                    break;
                }
                if(n == 1 && cursor->left) {cursor = cursor->left;}
                else if(n == 2 && cursor->right) {cursor = cursor->right;}
                else if(n == 3 && cursor->parent) {cursor = cursor->parent;}
                else if(n == 4) {cursor = t->root;}
                else {printf("Invalid move.\n");}
                break;
            }
            case 3:
                printf("Value: %d\n", cursor->value);
                printf("Height: %d\n", AVLHeight(cursor));
                printf("Size: %d\n", size(t->root));
                printf("isBST: %s\n", isBST(t->root) ? "yes" : "no");
                printf("isAVL: %s\n", isAVL(t->root) ? "yes" : "no");
                break;
            case 4: {
                printf("Search value: ");
                int v;
                if(!readInt("Value: ", &v)) {
                    printf("Invalid input.\n");
                    break;
                }
                bool found = (mode != MODE_FREE) ? BinarySearch(t->root, v) : contains(t->root, v);
                printf(found ? "Found\n" : "Not found\n");
                break;
            }
            case 5: {
                printf("1) To BST\n2) To AVL\n> ");
                int c;
                if(!readInt("Value: ", &c)) {
                    printf("Invalid input.\n");
                    break;
                }
                if(c == 1) {
                    BSTNator(t);
                    mode = MODE_BST;
                    cursor = t->root;
                }   else if(c == 2) {
                    AVLNator(t);
                    mode = MODE_AVL;
                    cursor = t->root;
                }
                break;
            }
            case 6: {
                freeTree(t);
                t = NULL;
                cursor = NULL;
                mode = MODE_FREE;
                break;
            }
            case 7: {
                running = false;
                break;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }
    freeTree(t);
    return 0;
}

bool readInt(const char *prompt, int *out) {
    int c;
    if(prompt) {printf("%s", prompt);}
    if(scanf("%d", out) != 1) {
        while((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    return true;
}

node* createNode(int val) {
    node* temp = malloc(sizeof(node));
    if(!temp) {printf("Error Allocating.\n"); exit(EXIT_FAILURE);}
    temp->value = val;
    temp->height = 1;
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

void updateHeight(node* n) {
    if(!n) {return;}
    int leftH = n->left ? n->left->height : 0;
    int rightH = n->right ? n->right->height : 0;
    n->height = 1 + (leftH > rightH ? leftH : rightH);
}

void insertLeft(node* parent, node* child) {
    if(!parent || !child) return;
    if(parent->left) {printf("Error: Parent has a left node.\n"); return;}
    if(child->parent) {printf("Error: Child already has a parent.\n"); return;}
    parent->left = child;
    child->parent = parent;
    node* cur = parent;
    while(cur) { updateHeight(cur); cur = cur->parent; }
}

void insertRight(node* parent, node* child) {
    if(!parent || !child) {return;}
    if(parent->right) {printf("Error: Parent has a right node.\n"); return;}
    if(child->parent) {printf("Error: Child already has a parent.\n"); return;}
    parent->right = child;
    child->parent = parent;
    node* cur = parent;
    while(cur) {updateHeight(cur); cur = cur->parent;}
}

void traverse(node* root) {
    if(!root) {return;}
    printf("%d ", root->value);
    traverse(root->left);
    traverse(root->right);
}

bool isLeaf(node* n) {
    if(!n) {return false;}
    return !n->left && !n->right;
}

int size(node* root) {
    if(!root) {return 0;}
    return 1 + size(root->left) + size(root->right);
}

int countLeaves(node* root) {
    if(!root) {return 0;}
    if(isLeaf(root)) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int depth(node* n) {
    int d = 0;
    while(n && n->parent) { d++; n = n->parent; }
    return d;
}

node* findNode(node* root, int value) {
    if(!root) {return NULL;}
    if(root->value == value) {return root;}
    node* found = findNode(root->left, value);
    if(found) {return found;}
    return findNode(root->right, value);
}

bool contains(node* root, int value) {
    return findNode(root, value) != NULL;
}

node* findMin(node* root) {
    if(!root) return NULL;
    node* min = root;
    node* lmin = findMin(root->left);
    node* rmin = findMin(root->right);
    if(lmin && lmin->value < min->value) {min = lmin;}
    if(rmin && rmin->value < min->value) {min = rmin;}
    return min;
}

node* findMax(node* root) {
    if(!root) {return NULL;}
    node* max = root;
    node* lmax = findMax(root->left);
    node* rmax = findMax(root->right);
    if(lmax && lmax->value > max->value) {max = lmax;}
    if(rmax && rmax->value > max->value) {max = rmax;}
    return max;
}

void detach(node* parent, node* child) {
    if(!parent || !child) return;
    if(parent->left == child) parent->left = NULL;
    else if(parent->right == child) parent->right = NULL;
    else {printf("Error: Nodes are not connected.\n"); return;}
    child->parent = NULL;
    node* cur = parent;
    while(cur) { updateHeight(cur); cur = cur->parent; }
}

void freeNodes(node* root) {
    if(!root) return;
    freeNodes(root->left);
    freeNodes(root->right);
    free(root);
}

void freeTree(tree* t) {
    if(!t) return;
    freeNodes(t->root);
    free(t);
}

bool isBSTUtil(node* n, long long min, long long max) {
    if(!n) return true;
    if(n->value <= min || n->value >= max) return false;
    return isBSTUtil(n->left, min, n->value) &&
           isBSTUtil(n->right, n->value, max);
}

bool isBST(node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

void fillInorder(node *n, int *arr, int *index) {
    if(!n) return;
    fillInorder(n->left, arr, index);
    arr[(*index)++] = n->value;
    fillInorder(n->right, arr, index);
}

node* buildBalancedBST(int *arr, int start, int end, node* parent) {
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    node* n = createNode(arr[mid]);
    n->parent = parent;
    n->left = buildBalancedBST(arr, start, mid-1, n);
    n->right = buildBalancedBST(arr, mid+1, end, n);
    updateHeight(n);
    return n;
}

void BSTNator(tree* t) {
    if(!t || !t->root) return;
    int n = size(t->root);
    int* arr = malloc(n * sizeof(int));
    int idx = 0;
    fillInorder(t->root, arr, &idx);
    freeNodes(t->root);
    t->root = buildBalancedBST(arr, 0, n-1, NULL);
    free(arr);
}

bool BinarySearch(node* n, int val) {
    while(n) {
        if(n->value == val) return true;
        if(val < n->value) n = n->left;
        else n = n->right;
    }
    return false;
}

node* findMinBST(node* root) {
    if(!root) return NULL;
    while(root->left) root = root->left;
    return root;
}

node* findMaxBST(node* root) {
    if(!root) return NULL;
    while(root->right) root = root->right;
    return root;
}

node* AVLRotateRight(node* y) {
    node* x = y->left;
    node* T2 = x->right;
    x->right = y;
    y->left = T2;
    x->parent = y->parent;
    y->parent = x;
    if(T2) T2->parent = y;
    if(x->parent) {
        if(x->parent->left == y) x->parent->left = x;
        else x->parent->right = x;
    }
    updateHeight(y);
    updateHeight(x);
    return x;
}

node* AVLRotateLeft(node* y) {
    node* x = y->right;
    node* T2 = x->left;
    x->left = y;
    y->right = T2;
    x->parent = y->parent;
    y->parent = x;
    if(T2) T2->parent = y;
    if(x->parent) {
        if(x->parent->left == y) x->parent->left = x;
        else x->parent->right = x;
    }
    updateHeight(y);
    updateHeight(x);
    return x;
}

int checkAVL(node *n, bool *ok) {
    if(!n) {return 0;}
    int lh = checkAVL(n->left, ok);
    int rh = checkAVL(n->right, ok);
    if(abs(lh - rh) > 1) {*ok = false;}
    if(n->height != 1 + (lh > rh ? lh : rh)) {*ok = false;}
    return 1 + (lh > rh ? lh : rh);
}

bool isAVL(node* root) {
    if(!root) {return true;}
    if(!isBST(root)) {return false;}
    bool ok = true;
    checkAVL(root, &ok);
    return ok;
}

int AVLHeight(node* n) {
    return n ? n->height : 0;
}

int AVLBalance(node* n) {
    if(!n) {return 0;}
    return AVLHeight(n->left) - AVLHeight(n->right);
}

void AVLNator(tree* t) {
    if(!t || !t->root) {return;}
    if(!isBST(t->root)) {BSTNator(t);}
    int n = size(t->root);
    int* arr = malloc(n * sizeof(int));
    if(!arr) {printf("Memory allocation failed.\n"); exit(EXIT_FAILURE);}
    int idx = 0;
    fillInorder(t->root, arr, &idx);
    freeNodes(t->root);
    t->root = buildBalancedBST(arr, 0, n-1, NULL);
    free(arr);
}

node* AVLInsert(node* root, int value) {
    if (!root) {return createNode(value);}
    if(value < root->value) {
        root->left = AVLInsert(root->left, value);
        root->left->parent = root;
    }   else if (value > root->value) {
        root->right = AVLInsert(root->right, value);
        root->right->parent = root;
    }   else {return root;}
    updateHeight(root);
    int balance = AVLBalance(root);
    if(balance > 1 && value < root->left->value) {return AVLRotateRight(root);}
    if(balance < -1 && value > root->right->value) {return AVLRotateLeft(root);}
    if(balance > 1 && value > root->left->value) {
        root->left = AVLRotateLeft(root->left);
        root->left->parent = root;
        return AVLRotateRight(root);
    }
    if (balance < -1 && value < root->right->value) {
        root->right = AVLRotateRight(root->right);
        root->right->parent = root;
        return AVLRotateLeft(root);
    }
    return root;
}

void insertAVL(tree* t, int value) {
    if(!t) {return;}
    t->root = AVLInsert(t->root, value);
    t->root->parent = NULL;
}