#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//binary sort

int main() {
    int random = 1000;
    SYSTEMTIME st;
    GetSystemTime(&st);
    srand(st.wMilliseconds);
    int num = rand() % random + 1;
    int guesses = 0;
    int low = 1;
    int high = random;
    while (1) {
        guesses++;
        int guess = (low + high) / 2;
        printf("Guess: %d\n", guess);
        if (guess == num) {
            printf("Number found in %d tries!\nThe number was: %d\n", guesses, num);
            break;
        } else if (guess > num) {
            printf("Too high.\n");
            high = guess - 1;
        } else {
            printf("Too low.\n");
            low = guess + 1;
        }
    }
    return 0;
}
