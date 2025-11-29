#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5000
#define KEY_MAX 256
#define VAL_MAX 1024

//hashtables yo
//pretty hard icl

typedef struct item {
    char *key;
    char *value;
} item;

typedef struct lnkdli {
    item *item;
    struct lnkdli *next;
} lnkdli;

typedef struct table {
    item **items;
    lnkdli **overflow;
    int size;
    int count;
} table;

unsigned long hasher(const char *str);
item* create_item(const char *key, const char *value);
void free_item(item *it);
lnkdli* lnkdli_insert_head(lnkdli *head, item *it);
item* lnkdli_remove_head(lnkdli **head);
void free_linkedlist(lnkdli *head);
table* create_table(int n);
void free_table(table *t);
lnkdli** create_buckets(int n);
void free_overflow_buckets(table *t);
void table_insert(table *t, const char *key, const char *value);
char* table_search(table *t, const char *key);
void table_delete(table *t, const char *key);
void print_table(table *t);
void print_search(table *t, const char *key);

int main() {
    table *ht = create_table(SIZE);
    if (!ht) {
        fprintf(stderr, "Failed to create table\n");
        return 1;
    }
    bool running = true;
    while (running) {
        printf("Selection: Insert (1) | View (2) | Search (3) | Remove (4) | Exit (5)\n");
        int option = 0;
        if(scanf("%d", &option) != 1) {
            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Try again.\n\n");
            continue;
        }
        getchar();
        if(option == 1) {
            char key[KEY_MAX];
            char value[VAL_MAX];
            printf("Key: ");
            if (!fgets(key, sizeof(key), stdin)) continue;
            key[strcspn(key, "\n")] = '\0';
            printf("Value: ");
            if (!fgets(value, sizeof(value), stdin)) continue;
            value[strcspn(value, "\n")] = '\0';
            table_insert(ht, key, value);
        }   else if(option == 2) {
            print_table(ht);
        }   else if(option == 3) {
            char key[KEY_MAX];
            printf("Key: ");
            if (!fgets(key, sizeof(key), stdin)) continue;
            key[strcspn(key, "\n")] = '\0';
            print_search(ht, key);
        }   else if(option == 4) {
            char key[KEY_MAX];
            printf("Key: ");
            if (!fgets(key, sizeof(key), stdin)) continue;
            key[strcspn(key, "\n")] = '\0';
            table_delete(ht, key);
        }   else if(option == 5) {
            printf("Exiting...");
            free_table(ht);
            running = false;
        }   else {
            printf("Invalid option.");
        }
        printf("\n");
    }
    printf("Exit successful.\n");
    return 0;
}

unsigned long hasher(const char *str) {
    unsigned long i = 0;
    for (size_t j = 0; str[j]; ++j) i = i * 31 + (unsigned char)str[j];
    return i % SIZE;
}

item* create_item(const char *key, const char *value) {
    item *it = malloc(sizeof(item));
    if (!it) return NULL;
    it->key = strdup(key);
    it->value = strdup(value);
    return it;
}

void free_item(item *it) {
    if (!it) return;
    free(it->key);
    free(it->value);
    free(it);
}

lnkdli* lnkdli_insert_head(lnkdli *head, item *it) {
    lnkdli *node = malloc(sizeof(lnkdli));
    if (!node) return head;
    node->item = it;
    node->next = head;
    return node;
}

item* lnkdli_remove_head(lnkdli **head) {
    if (!head || !*head) return NULL;
    lnkdli *node = *head;
    item *it = node->item;
    *head = node->next;
    free(node);
    return it;
}

void free_linkedlist(lnkdli *head) {
    lnkdli *cur = head;
    while (cur) {
        lnkdli *next = cur->next;
        free_item(cur->item);
        free(cur);
        cur = next;
    }
}

table* create_table(int n) {
    table *t = malloc(sizeof(table));
    if (!t) return NULL;
    t->size = n;
    t->count = 0;
    t->items = calloc(n, sizeof(item*));
    t->overflow = create_buckets(n);
    return t;
}

lnkdli** create_buckets(int n) {
    lnkdli **b = calloc(n, sizeof(lnkdli*));
    if (!b) return NULL;
    for (int i = 0; i < n; ++i) b[i] = NULL;
    return b;
}

void free_overflow_buckets(table *t) {
    if (!t || !t->overflow) return;
    for (int i = 0; i < t->size; ++i) {
        free_linkedlist(t->overflow[i]);
    }
    free(t->overflow);
}

void free_table(table *t) {
    if (!t) return;
    if (t->items) {
        for (int i = 0; i < t->size; ++i) {
            if (t->items[i]) free_item(t->items[i]);
        }
        free(t->items);
    }
    free_overflow_buckets(t);
    free(t);
}

void table_insert(table *t, const char *key, const char *value) {
    if (!t) return;
    unsigned long index = hasher(key);
    item *cur = t->items[index];
    if (!cur) {
        t->items[index] = create_item(key, value);
        if (t->items[index]) t->count++;
        return;
    }
    if (strcmp(cur->key, key) == 0) {
        free(cur->value);
        cur->value = strdup(value);
        return;
    }
    lnkdli *node = t->overflow[index];
    for (lnkdli *it = node; it; it = it->next) {
        if (strcmp(it->item->key, key) == 0) {
            free(it->item->value);
            it->item->value = strdup(value);
            return;
        }
    }
    item *newit = create_item(key, value);
    t->overflow[index] = lnkdli_insert_head(t->overflow[index], newit);
}

char* table_search(table *t, const char *key) {
    if (!t) return NULL;
    unsigned long index = hasher(key);
    item *cur = t->items[index];
    if (cur && strcmp(cur->key, key) == 0) return cur->value;
    for (lnkdli *it = t->overflow[index]; it; it = it->next) {
        if (strcmp(it->item->key, key) == 0) return it->item->value;
    }
    return NULL;
}

void table_delete(table *t, const char *key) {
    if (!t) return;
    unsigned long index = hasher(key);
    item *cur = t->items[index];
    lnkdli *head = t->overflow[index];
    if (!cur) return;
    if (strcmp(cur->key, key) == 0) {
        free_item(cur);
        t->items[index] = NULL;
        t->count--;
        if (head) {
            item *moved = lnkdli_remove_head(&t->overflow[index]);
            t->items[index] = moved;
        }
        return;
    }
    lnkdli *prev = NULL;
    lnkdli *curNode = head;
    while (curNode) {
        if (strcmp(curNode->item->key, key) == 0) {
            if (prev == NULL) {
                t->overflow[index] = curNode->next;
            } else {
                prev->next = curNode->next;
            }
            free_item(curNode->item);
            free(curNode);
            return;
        }
        prev = curNode;
        curNode = curNode->next;
    }
}

void print_table(table *t) {
    if (!t) return;
    printf("\nHash Table (non-empty entries)\n-------------------\n");
    for (int i = 0; i < t->size; ++i) {
        if (t->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, t->items[i]->key, t->items[i]->value);
            for (lnkdli *it = t->overflow[i]; it; it = it->next) {
                printf("  -> Collision Key:%s, Value:%s\n", it->item->key, it->item->value);
            }
        } else {
            for (lnkdli *it = t->overflow[i]; it; it = it->next) {
                printf("Index:%d (primary empty) -> Key:%s, Value:%s\n", i, it->item->key, it->item->value);
            }
        }
    }
    printf("-------------------\n\n");
}

void print_search(table *t, const char *key) {
    char *v = table_search(t, key);
    if (!v) printf("Key: %s does not exist\n", key);
    else printf("Key: %s, Value: %s\n", key, v);
}