#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int num;
    struct node* next;
} node;

node* create(int num) {
    node* new = malloc(sizeof(node));
    if(!new) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new->num = num;
    new->next = NULL;
    return new;
}

void cycle(node* head) {
    while(head) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("End\n");
}

void clear(node** head) {
    node* temp;
    while(*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Deallocation successful.\n");
}

node* insert(node* head, int num, int pos) {
    node* cur = create(num);
    if(pos == 0 || head == NULL) {
        cur->next = head;
        return cur;
    }
    node* temp = head;
    int count = 0;
    while(temp->next != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    cur->next = temp->next;
    temp->next = cur;
    return head;
}

int main() {
    printf("Linked Lists!\n");
    bool running = true;
    node* anode = NULL;
    while(running) {
        int option;
        printf("Choose option: 1. View | 2. Insert | 3. Remove | 4. Exit    ");
        scanf("%d", &option);
        getchar();
        printf("\n");
        switch(option) {
            case 1:
                if(!anode) {printf("No elements yet.\n"); break;}
                cycle(anode);
                break;
            case 2: {
                int value, pos;
                printf("Value: ");
                scanf("%d", &value);
                printf("Insert position: ");
                scanf("%d", &pos);
                anode = insert(anode, value, pos);
                break;
            }
            case 3:
                if(!anode) {printf("List is empty.\n"); break;}
                printf("Clearing list.\n");
                clear(&anode);
                break;
            case 4:
                if(anode) {clear(&anode);}
                printf("Exiting.\n");
                running = false;
                break;
            default:
                printf("Invalid.\n");
        }
    }
    return 0;
}