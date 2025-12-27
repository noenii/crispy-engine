#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//radix sort

#define SIZE 100

int getMax(int array[], int n);
void fillRandom(int arr[], int size);
void printArray(int arr[], int size);
void sort(int arr[], int n);
void countingSort(int array[], int n, int place);

int main() {
    int arr[SIZE];
    srand((unsigned)time(NULL));
    fillRandom(arr, SIZE);
    sort(arr, SIZE);
    printArray(arr, SIZE);
    return 0;
}

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void fillRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) + 1;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int array[], int n, int place) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void sort(int arr[], int n) {
    int maxElement = getMax(arr, n);
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}