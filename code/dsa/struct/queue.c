#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//queues yo

typedef struct node {
    int num;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;
int count = 0;

node* create(int num);
void enqueue(int num);
int dequeue();
int peek();
bool isEmpty();
void clearQueue();
void printQueue();

int main() {
    bool running = true;
    while(running) {
        int option;
        printf("\nSelection: Enqueue (1) | Dequeue (2) | Peek (3) | isEmpty (4) | Size (5) | View (6) | Exit (7)\n");
        scanf("%d", &option);
        getchar();
        switch(option) {
            case 1: {
                int num;
                printf("Value: ");
                scanf("%d", &num);
                getchar();
                enqueue(num);
                break;
            }
            case 2: {
                if(isEmpty()) {
                    printf("Nothing to dequeue.\n");
                } else {
                    int value = dequeue();
                    printf("Dequeued: %d\n", value);
                }
                break;
            }
            case 3: {
                if(isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Front: %d\n", peek());
                }
                break;
            }
            case 4: {
                printf(isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            }
            case 5: {
                printf("Queue size: %d\n", count);
                break;
            }
            case 6: {
                printQueue();
                break;
            }
            case 7: {
                printf("Exiting...\n");
                clearQueue();
                running = false;
                break;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }
    printf("Exit successful.\n");
    return 0;
}

node* create(int num) {
    node* newNode = malloc(sizeof(node));
    if(!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int num) {
    node* newNode = create(num);
    if(front == NULL) {
        front = rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue empty.\n");
        return -1;
    }
    node* temp = front;
    int value = temp->num;
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    count--;
    return value;
}

int peek() {
    if(isEmpty()) {
        printf("Queue empty.\n");
        return -1;
    }
    return front->num;
}

bool isEmpty() {
    return front == NULL;
}

void clearQueue() {
    if(isEmpty())
        return;
    node* cur = front;
    do {
        node* next = cur->next;
        free(cur);
        cur = next;
    } while(cur != front);
    front = rear = NULL;
    count = 0;
}

void printQueue() {
    if(isEmpty()) {
        printf("Queue empty.\n");
        return;
    }
    node* temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->num);
        temp = temp->next;
    } while(temp != front);
    printf("\n");
}