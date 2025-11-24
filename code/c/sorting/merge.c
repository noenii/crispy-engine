#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merge sort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);

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