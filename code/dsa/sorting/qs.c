#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//quicksort

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    quickSort(arr, 0, SIZE - 1);
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

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recur on partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}