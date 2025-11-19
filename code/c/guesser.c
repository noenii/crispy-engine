#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
//binary search would go hard as hell here fr
int main() {
    bool running = true;
    srand(time(NULL));
    int num = rand() % 101;
    int guesses = 0;
    while(running) {
        guesses++;
        int guess = 0;
        char temp[10];
        printf("Guess the number: ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0;
        if (sscanf(temp, "%d", &guess) != 1) {
            printf("Invalid input.\n");
            continue;
        }
        if (guess < 0 || guess > 100) {
            printf("Guess must be between 0 and 100.\n");
            continue;
        }
        if(guess == num) {
            printf("You won!\nThe number was: %d", num);
            break;
        }   else if(guess > num) {
            printf("Too high.\n");
        }   else if(guess < num) {
            printf("Too low.\n");
        }   else {
            printf("WHAT\n");
        }
    }
    return 0;
}