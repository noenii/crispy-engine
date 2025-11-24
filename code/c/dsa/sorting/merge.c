#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]);
void mergeSort(int arr[], int size);
void copyArray(int src[], int dst[], int n);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    mergeSort(arr, SIZE);
    printArray(arr, SIZE);
    return 0;
}

void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = (rand() % 20) + 1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void copyArray(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1) arr3[k++] = arr1[i++];
    while (j < n2) arr3[k++] = arr2[j++];
}

void mergeSort(int arr[], int size) {
    if (size <= 1) return;
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    copyArray(arr, left, mid);
    copyArray(arr + mid, right, size - mid);
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    mergeArrays(left, mid, right, size - mid, arr);
}