#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//bubblesort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void swap(int arr[], int i, int j);

int main() {
    int arr[SIZE];
    int option;
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < SIZE; i++) {
            if (arr[i] < arr[i - 1]) {
                swap(arr, i, i - 1);
                swapped = true;
            }
        }
    }
    printArray(arr, SIZE);
    return 0;
}

void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 20) + 1;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}