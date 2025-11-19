#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
//yah ts is bugged ash ik

int main() {
    while(true) {
        int num1;
        int num2;
        char temp[10];

        printf("Enter Number: ");
        if(scanf("%d", &num1) != 1) {
            printf("Invalid.\n");
            break;
        }
        getchar();
        printf("Select operation:  +  -  *  /  **  sqrt  : ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0;
        int len = 0;
        while (temp[len] != '\0') {
            len++;
        }
        temp[len] = ' ';
        temp[len + 1] = '\0';
        printf("Enter Number: ");
        if (scanf("%d", &num2) != 1) {
            printf("Invalid.\n");
            break;
        }
        getchar();

        if(temp[0] == '+') {
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
        }   else if(temp[0] == '-') {
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
        }   else if(temp[0] == '*') {
            if(temp[1] == '*') {
                int result = num1;
                for (int i = 0; i < num2; i++) {
                    result *= result;
                }
                printf("%d ** %d = %d", num1, num2, result);
            }   else {
                printf("%d * %d = %d\n", num1, num2, num1 * num2);
            }
        }   else if(temp[0] == '/') {
            if(num1 == 0 || num2 == 0) {
                printf("Cannot divide by Zero.\n");
                continue;
            }
            double result = (double)num1/num2;
            printf("%d / %d = %lf\n", num1, num2, result);
        }   else {}
            char str[] = "sqrt";
            if(temp[0] == 's') {
                bool yes = false;
                for(int i = 1; temp[i] != '\0'; i++) {
                    if(temp[i] != str[i]) {
                        printf("Invalid\n");
                        continue;
                    }   else {
                        yes = false;
                    }
                }
                if(yes = true) {
                    double result = sqrt(num1);
                    printf("square root of %d = %lf\n", num1, result);
                }
            }

    }
    return 0;
}