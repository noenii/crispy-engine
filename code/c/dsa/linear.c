#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//linear search

#define SIZE 100
#define VALUE 17

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
int finder(int arr[], int size, int val);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    printArray(arr, SIZE);
    int x = finder(arr, SIZE, VALUE);
    if(x == -1) {
        printf("(%d) not found.\n");
    }   else {
        printf("(%d) found at index %d.\n", VALUE, x);
    }
    return 0;
}

void fillRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = (rand() % 20) + 1;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int finder(int arr[], int size, int val) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == val) {
            return i;
        }
    }
    return -1;
}