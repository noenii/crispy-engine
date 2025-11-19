#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//this took a lot of tears and begging (￣、￣)

int main() {
    int counter = 0;
    bool running = true;
    char **pArr = NULL;
    printf("Shopping list program or sum shi\n\n");
    while(running) {
        int option;
        printf("Select: View (1), Add (2), Insert (3), Remove (4), Clear (5), Exit (6)\n");
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1: {
                if(counter == 0) {
                    printf("No items yet.\n");
                }   else {
                    for(int i = 0; i < counter; i++) {
                        printf("%d. %s\n", i + 1, pArr[i]);
                    }
                }
                break;
            }
            case 2: {
                char temp[100];
                printf("Add an item:\n");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = 0;
                size_t len = strlen(temp);
                char *pItem = malloc(len + 1);
                strcpy(pItem, temp);
                char **dummy = realloc(pArr, (counter + 1) * sizeof(*pArr));
                if(dummy == NULL) {
                    exit(EXIT_FAILURE);
                }
                pArr = dummy;
                pArr[counter] = pItem;
                counter++;
                break;
            }
            case 3: {
                char temp[100];
                if (counter == 0) {
                    printf("No elements, inserting at index 0.\n");
                    printf("Add an item:\n");
                    fgets(temp, sizeof(temp), stdin);
                    temp[strcspn(temp, "\n")] = 0;
                    char *pItem = malloc(strlen(temp) + 1);
                    strcpy(pItem, temp);
                    char **dummy = realloc(pArr, (counter + 1) * sizeof(*pArr));
                    if(!dummy) {
                        exit(EXIT_FAILURE);
                    }
                    pArr = dummy;
                    pArr[0] = pItem;
                    counter++;
                    break;
                }
                int insertPoint;
                printf("Choose location to insert at: \n");
                for (int i = 0; i < counter; i++) {
                    printf("%d. %s\n", i + 1, pArr[i]);
                }
                scanf("%d", &insertPoint);
                getchar();
                if(insertPoint <= 0) {
                    printf("Starts at 1.\n");
                    break;
                }
                printf("Add an item:\n");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = 0;
                char *pItem = malloc(strlen(temp) + 1);
                strcpy(pItem, temp);
                insertPoint--;
                if (insertPoint >= counter) {
                    printf("Input is larger than array, inserting at end.\n");
                    char **dummy = realloc(pArr, (counter + 1) * sizeof(*pArr));
                    if (!dummy) {
                        exit(EXIT_FAILURE);
                    }
                    pArr = dummy;
                    pArr[counter] = pItem;
                    counter++;
                    break;
                }
                char **dummy = realloc(pArr, (counter + 1) * sizeof(*pArr));
                if (!dummy) exit(EXIT_FAILURE);
                pArr = dummy;
                for (int i = counter; i > insertPoint; i--) {
                    pArr[i] = pArr[i - 1];
                }
                pArr[insertPoint] = pItem;
                counter++;
                break;
            }
            case 4: {
                int removal;
                if(counter == 0) {
                    printf("Nothing to remove.\n");
                    break;
                }
                printf("Choose item to remove: \n");
                for(int i = 0; i < counter; i++) {
                        printf("%d. %s\n", i + 1, pArr[i]);
                    }
                scanf("%d", &removal);
                getchar();
                if(removal <= 0 || removal > counter) {
                    printf("Bro stop.\n");
                    break;
                }
                if(removal > counter) {
                    printf("Item doesn't exist.\n");
                    break;
                }
                free(pArr[removal - 1]);
                counter--;
                if(counter == 0) {
                    free(pArr);
                    pArr = NULL;
                }   else {
                    for(int i = removal - 1; i < counter; i++) {
                        pArr[i] = pArr[i + 1];
                    }
                    char **dummy3 = realloc(pArr, counter * sizeof(*pArr));
                    if(dummy3 == NULL) {
                        printf("Error reallocating.\n");
                        return -1;
                    }
                    pArr = dummy3;
                }
                break;
            }
            case 5: {
                if(counter == 0) {
                    printf("Nothing to clear.\n");
                    break;
                }
                for(size_t i = 0; i < counter; i++) {
                    free(pArr[i]);
                }
                free(pArr);
                pArr = NULL;
                counter = 0;
                break;
            }
            case 6: {
                printf("Exiting...\n");
                for(size_t i = 0; i < counter; i++) {
                    free(pArr[i]);
                }
                free(pArr);
                pArr = NULL;
                running = false;
                break;
            }
            default: {
                printf("Invalid Input\n");
                continue;
            }
        }
    }
    printf("Exit successful.");
    return EXIT_SUCCESS;
}