#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int age;

    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("What is your age? ");
    scanf("%d", &age);

    printf("Hi %s! You will turn %d years old.", name, age + 1);

    return 0;
}