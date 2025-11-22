#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//insertion sort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void swap(int arr[], int i, int j);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);

    int sorted[SIZE];


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

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shiftRight(int arr[], int count, int index) {
    for (int i = count; i > index; i--) {
        arr[i] = arr[i - 1];
    }
}