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
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    bool swapped = true;
    int temp = SIZE;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < temp; i++) {
            if (arr[i] < arr[i - 1]) {
                swap(arr, i, i - 1);
                swapped = true;
            }
        }
        temp--;
    }
    printArray(arr, SIZE);
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

// Time Complexity Analysis:
//   1. fillRandom: fills array of size N with random values = O(n)
//   2. swap: constant-time element exchange = O(1)
//   3. bubbleSort:
//        - best case (already sorted): O(n)
//        - average case: O(n^2)
//        - worst case: O(n^2)
//   4. printArray: prints N elements = O(n)