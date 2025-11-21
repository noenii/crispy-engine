#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int option;
    bool running = true;
    printf("pArrs! DYNAMIC ARRAYS!!!!!\n");

    int count = 0;
    int *pArr = NULL;

    while(running) {
        printf("Select: 1. View | 2. View all | 3. Insert | 4. Append | 5. Remove | 6. Clear | 7. Exit\n");
        scanf("%d", &option);
        getchar();
        printf("\n");
        switch(option) {
            case 1: {
                int o1;
                if(count == 0) {printf("pArr is empty.\n"); break;}
                printf("Enter an index: ");
                scanf("%d", &o1);
                getchar();
                printf("\n");
                if(o1 >= count + 1 || o1 <= -1) {printf("Error: Out of bounds.\n"); break;}
                printf("%d\n", pArr[o1]);
                break;
            }
            case 2: {
                if(count == 0) {printf("pArr is empty.\n"); break;}
                for(int i = 0; i < count; i++) {
                    printf("%d ", pArr[i]);
                }
                printf("End\n");
                break;
            }
            case 3: {
                int num;
                int pos;
                printf("Value: ");
                scanf("%d", &num);
                getchar();
                printf("Index: ");
                scanf("%d", &pos);
                getchar();
                if(pos >= count + 1) {printf("go append instead cus im lazy =P\n"); break;}
                count++;
                int *dummy = realloc(pArr, sizeof(*pArr) * count);
                if(!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                pArr = dummy;
                for(int i = count; i >= 0; i--) {
                    pArr[i] = pArr[i - 1];
                    if(i == pos) {pArr[i] = num; break;}
                }
                break;

            }
            case 4: {
                int num;
                printf("Value: ");
                scanf("%d", &num);
                getchar();
                count++;
                int *dummy = realloc(pArr, sizeof(*pArr) * count);
                if(!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                pArr = dummy;
                pArr[count] = num;
                break;
            }
            case 5: {
                int pos;
                printf("Index: ");
                scanf("%d", &pos);
                getchar();
                for(int i = count; i >= pos; i--) {
                    pArr[i - 1] = pArr[i];
                    if(i-1 == pos) {break;}
                }
                count--;
                int *dummy = realloc(pArr, sizeof(*pArr) * count);
                if(!dummy) {printf("Memory allocation failed.\n"); return EXIT_FAILURE;}
                pArr = dummy;
                break;
            }
            case 6: {
                printf("Deallocating...\n");
                free(pArr);
                pArr = NULL;
                printf("Deallocation successful.\n");
                break;
            }
            case 7: {
                printf("Deallocating...\n");
                free(pArr);
                pArr = NULL;
                printf("Deallocation successful.\n");
                return EXIT_SUCCESS;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}