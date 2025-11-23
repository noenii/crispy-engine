#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//insertion sort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void shiftRight(int arr[], int count, int index);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    int sorted[SIZE];
    int size = 0;
    for (int x = 0; x < SIZE; x++) {
        int inserted = 0;
        for(int y = 0; y < size; y++) {
            if (arr[x] < sorted[y]) {
                shiftRight(sorted, size, y);
                sorted[y] = arr[x];
                size++;
                inserted = 1;
                break;
            }
        }
        if(!inserted) {
            sorted[size++] = arr[x];
        }
    }
    printArray(sorted, size);
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

void shiftRight(int arr[], int count, int index) {
    for (int i = count; i > index; i--) {
        arr[i] = arr[i - 1];
    }
}