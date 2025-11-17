#include <stdio.h>
#include <stdlib.h>     //must be included for memory functions
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char discord[20];
}   contact;

int main() {
    //memory management
    //finally, the final boss of C

    //memory management is pretty complicated, but when used right makes programs more efficient

    //there are two types of memory, static and dynamic
    //static is variables assigned before the program runs, dynamic is variables assigned while the program is running
    //as you can tell dynamic is a lot more powerful, but incredibly easy to screw up


    //allocation

    int *pNum = malloc(4);  //allocate four bytes of memory (for an int), malloc returns the memory address for it
    int *pNum2 = calloc(2, 4);      //calloc is like malloc, but it takes an extra arguement first (how many elements), calloc is slightly less efficient tho

    //unlike calloc, malloc is unpredictable. always write to it before reading it
    //a better way to allocate memory is:

    int *pNum3;
    pNum3 = malloc(sizeof(*pNum3));     //dont forget the * cus if you dont, youll measure the size of the pointer and not the type

    //stack memory is a type of dynamic memory reserved for variables defined inside a function, when the function returns, the memory is freed.
    //however if too much stack memory is used (like recursion that goes wrong), its called a stack overflow error... is this a reference (￣、￣)

    //allocated memory acts like an array, pretty confusing right?
    //but look at pNum2, calloc'd 2 ints, so access them just like an array

    *pNum2 = 6;
    pNum2[1] = 7;   //u can jst drop the pointer if ur using an index

    pNum[0] = 9;
    *pNum3 = 10;    //i prefer * tho, that asterisk is job security ong
    
    //btw dynamic memory does not have a data type, its just bytes in memory.
    //like if you allocated 4 bytes, it could be one int or four chars, your choice.


    //reallocation
    //if you alloc'd and need more memory, you can reallocate it to make it larger
    //realloc() tries to resize the memory at the current address, if it cant it will reallocate memory at another address and return the new address
    //if it suceeds it will return the original address, also the original pointer should not be used if so (might throw an error)

    int *pNum4;

    pNum4 = realloc(pNum2, 16);

    if(pNum4 == NULL) {     //theres a small chance realloc might fail, if it does it will return null so check for that
        printf("Reallocation unsuccessful\n");
    }   else {
        printf("Reallocation Successful, new address = %p\n", pNum4);
        pNum2 = pNum4;
    }


    //deallocation
    //once you finish using memory, always deallocate it!
    //with free(pointer)

    free(pNum);
    pNum = NULL;    //you should set the pointer for that memory to NULL after freeing it so it wont be accidentally used

    //a memory leak is when you allocate memory but dont deallocate it, leaks should be avoided yeah
    /*
    how it may happen:    
    1. overwriting the pointer to that memory
    2. not freeing in a function
    3. pointer gets lost when a realloc() fails
    4. or simply to free() memory
    */

    free(pNum2);
    free(pNum3);

    pNum2 = NULL;
    pNum3 = NULL;
    pNum4 = NULL;


    //structs and memory
    //now we dont have just static data structures anymore
    
    //like arrays. we can add elements as we please now

    char *pChar;
    pChar = calloc(4, sizeof(char));
    
    *pChar = 'a';
    pChar[1] = 'k';
    pChar[2] = 'i';
    pChar[3] = '\0';

    printf("%s\n", pChar);

    char *pChar2;

    pChar2 = realloc(pChar, 6);

    if(pChar2 == NULL) {
        printf("Error reallocating\n");
        return -1;
    }
    pChar = pChar2;

    pChar[2] = 'a';
    pChar[3] = 'n';
    pChar[4] = 'e';
    pChar[5] = '\0';

    printf("%s\n", pChar);

    free(pChar);

    pChar = NULL;
    pChar2 = NULL;

    //another example

    int *pArr;

    pArr = calloc(4, sizeof(int));
    *pArr = 6;
    pArr[1] = 7;
    pArr[2] = 9;
    pArr[3] = 10;

    for(int i = 0; i < 4; i++) {
        printf("%d ", pArr[i]);
    }

    int *pArr2;
    pArr2 = realloc(pArr, 5 * (sizeof(int)));

    if(pArr2 == NULL) {
        printf("Error reallocating\n");
        return -1;
    }

    pArr = pArr2;

    pArr[4] = 21;

    for(int i = 0; i < 5; i++) {
        printf("%d ", pArr[i]);
    }

    free(pArr);

    pArr = NULL;
    pArr2 = NULL;

    //also with structs

    contact *pMe = (contact*) malloc(sizeof(contact));
    if (pMe == NULL) {
        printf("allocation failed\n");
        return 1;
    }

    strcpy(pMe->name, "aki =3");
    pMe->age = 15;
    strcpy(pMe->discord, "yun.seoo");

    printf("Hi my name is %s, I am %d years old. My Discord user is %s", pMe->name, pMe->age, pMe->discord);

    free(pMe);
    pMe = NULL;
    
    //possibilities are endless!

    return 0;
}