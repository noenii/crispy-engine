#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//counting sort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE];
    int buckets[10] = {0};
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    for(int i = 0; i < SIZE; i++) {
        int x = arr[i];
        buckets[x]++; 
    }
    for (int i = 0; i < 10; i++) {
        for(int c = 0; c < buckets[i]; c++) {
            printf("%d ", i);
        }
    }
    return 0;
}

void fillRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}