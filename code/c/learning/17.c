#include <stdio.h>
#include <errno.h>      //for errors
#include <string.h>
#include <stdlib.h>     //for custom return values

int main() {
    //extra stuff
    //c is a lot easier to screw up than most languages, so becareful ig
    //debugging in C is the same as any other lang


    //NULL is a special value that represents a pointer that doesnt point to anything
    //helps you avoid using pointers that are empty or invalid
    //lots of functions return NULL if they fail, so you can use an if statement to check for it

    int *pNum = NULL;


    //error handling
    //C doesnt have try/except like python
    //instead it uses return values, status codes and helper functions

    FILE *pFile = fopen("20.c", "r");

    if(pFile == NULL) {     //returns null if it fails
        perror("error opening file");   //perror instead of printf, and reason of error will be printed out along with the text
        //return 1;     <-- returns 1, a non zero return code means error
    }

    fclose(pFile);

    //now with errno

    FILE *pFile2 = fopen("21.c", "r");

    if(pFile2 == NULL) {
        printf("error: %s\n", strerror(errno));
        //return 1;
    }

    fclose(pFile2);

    //in errno, there are error constants
    //you can use conditional statements to check which happened
    /*
    ENOENT  -   no such file or directory
    EACCES  -   permission denied
    ENOMEM  -   not enough memory
    EINVAL  -   invalid arguement
    */

    //with stdlib, you can return EXIT_SUCCESS or EXIT_FAILURE instead of 0 and !0, for readability

    FILE *pFile3 = fopen("22.c", "r");

    if(pFile3 == NULL) {
        printf("error: %s\n", strerror(errno));
        //exit(EXIT_FAILURE);     exit to exit immediately instead of returning
    }

    fclose(pFile3);

    //input validation
    //"never ever ever EVER trust user input" - tom scott

    //validate number range
    int number;

    do {
        printf("input a positive integer below 1000: ");
        scanf("%d", &number);
        while (getchar() != '\n');
    }   while (number < 1 || number > 1000);

    printf("You chose: %d\n", number);

    //validate string
    char name[100];

    do {
        printf("your name: ");
        fgets(name, sizeof(name), stdin); 
        name[strcspn(name, "\n")] = 0;
    } while (strlen(name) == 0);

    printf("Hello, %s\n", name);

    //validate integer

    int num;
    char input[100];

    printf("Enter a number: ");


    while (fgets(input, sizeof(input), stdin)) {
        if (sscanf(input, "%d", &num) == 1) {
            break;
        } else {
            printf("Invalid input. Try again: ");
        }
    }

    printf("You entered: %d\n", num);   //doesnt work on float, ok...

    return EXIT_SUCCESS;
}