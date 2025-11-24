#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//arrays yo

int main() {
    int option;
    bool running = true;

    int count = 0;
    int *pArr = NULL;

    printf("pArrs! DYNAMIC ARRAYS!!!!!\n");

    while (running) {
        printf("Select: 1. View | 2. View all | 3. Insert | 4. Append | 5. Remove | 6. Clear | 7. Exit\n");
        scanf("%d", &option);
        getchar();
        printf("\n");
        switch(option) {
            case 1: {
                int i;
                if (count == 0) { printf("Empty.\n"); break; }
                printf("Enter an index: ");
                scanf("%d", &i);
                getchar();
                if (i < 0 || i >= count) {
                    printf("Error: Out of bounds.\n");
                    break;
                }
                printf("%d\n", pArr[i]);
                break;
            }
            case 2: {
                if (count == 0) { printf("Empty.\n"); break; }
                for (int i = 0; i < count; i++)
                    printf("%d ", pArr[i]);
                printf("End\n");
                break;
            }
            case 3: {
                int num, pos;
                printf("Value: ");
                scanf("%d", &num);
                printf("Index: ");
                scanf("%d", &pos);
                getchar();
                if (pos < 0 || pos > count) {
                    printf("Invalid index.\n");
                    break;
                }
                int *dummy = realloc(pArr, sizeof(*pArr) * (count + 1));
                if (!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                pArr = dummy;
                for (int i = count; i > pos; i--)
                    pArr[i] = pArr[i - 1];
                pArr[pos] = num;
                count++;
                break;
            }
            case 4: {
                int num;
                printf("Value: ");
                scanf("%d", &num);
                getchar();
                int *dummy = realloc(pArr, sizeof(*pArr) * (count + 1));
                if (!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                pArr = dummy;
                pArr[count] = num;
                count++;
                break;
            }
            case 5: {
                int pos;
                printf("Index: ");
                scanf("%d", &pos);
                getchar();
                if (pos < 0 || pos >= count) {
                    printf("Invalid index.\n");
                    break;
                }
                for (int i = pos; i < count - 1; i++)
                    pArr[i] = pArr[i + 1];
                count--;
                if (count == 0) {
                    free(pArr);
                    pArr = NULL;
                } else {
                    int *dummy = realloc(pArr, sizeof(*pArr) * count);
                    if (!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                    pArr = dummy;
                }
                break;
            }
            case 6: {
                free(pArr);
                pArr = NULL;
                count = 0;
                printf("Cleared.\n");
                break;
            }
            case 7: {
                printf("Exiting...\n");
                free(pArr);
                printf("Exit successfull.\n");
                return 0;
            }
            default:
                printf("Invalid option.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}