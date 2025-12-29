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

// Time Complexity Analysis:
//   1. Bucket initialization: O(k)
//   2. fillRandom: O(n)
//   3. Counting occurrences: O(n)
//   4. Printing sorted output: O(n)
//     Overall time complexity: O(n + k)
//     Space complexity: O(k)
//   NOTE: Counting Sort is limited as it only works on integers and requires all items be in a bounded range.