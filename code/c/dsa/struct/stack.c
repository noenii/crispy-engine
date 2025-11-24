#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//stacks yo

int main() {
    int count = 0;
    bool running = true;
    int *pArr = NULL;
    while (running) {
        int option;
        printf("Selection: Push (1) | Pop (2) | Peek (3) | isEmpty (4) | size (5) | exit (6)\n");
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1: {
                int x;
                printf("Value: ");
                scanf("%d", &x);
                getchar();
                int *pTemp = realloc(pArr, (count + 1) * sizeof(int));
                if (pTemp == NULL) {
                    printf("Error allocating memory.\n");
                    free(pArr);
                    return EXIT_FAILURE;
                }
                pArr = pTemp;
                pArr[count] = x;
                count++;
                printf("\n");
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("Nothing to pop.\n\n");
                    break;
                }
                count--;
                int *pTemp = realloc(pArr, count * sizeof(int));
                if (pTemp != NULL) {
                    pArr = pTemp;
                }
                printf("\n");
                break;
            }
            case 3: {
                if (count == 0) {
                    printf("Stack is empty.\n\n");
                    break;
                }
                printf("Top: %d\n\n", pArr[count - 1]);
                break;
            }
            case 4: {
                printf(count == 0 ? "Stack is empty.\n\n" : "Stack is not empty.\n\n");
                break;
            }
            case 5: {
                printf("Size: %d\n\n", count);
                break;
            }
            case 6: {
                printf("Exiting...\n");
                free(pArr);
                running = false;
                break;
            }
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    printf("Exit successful.\n");
    return 0;
}