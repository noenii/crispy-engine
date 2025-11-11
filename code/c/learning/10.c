#include <stdio.h>

int main() {
    //arrays!

    int funnyNumbers[] = {67, 69, 420, 21};
    printf("%d\n", funnyNumbers[2]);

    //the usual

    funnyNumbers[0] = 68;
    printf("%d\n", funnyNumbers[0]);

    //you can also set the array size first, then add elements later
    //tho after that you cant change the array size

    int someNumbers[4];

    someNumbers[0] = 2;
    someNumbers[1] = 99;
    someNumbers[3] = 2903203290;    //doesnt have to be in order too
    someNumbers[2] = 0;

    printf("%d\n", someNumbers[2]);

    //do NOT mix datatypes!
    //array size:
    printf("%zu\n", sizeof(funnyNumbers));  //16 bytes
    
    //to get how many items in an array:
    printf("%zu\n\n", sizeof(someNumbers) / sizeof(someNumbers[0]));

    //you can loop through arrays too!
    for(int i = 0; i < 4; i++) {
        printf("%d\n", funnyNumbers[i]);
    }

    printf("\n");

    //a better way:
    int length = sizeof(someNumbers) / sizeof(someNumbers[0]);

    for(int x = 0; x < length; x++) {
        printf("%d\n", funnyNumbers[x]);
    }   //this is so incredibly tedious...(￣、￣)

    //also there can be multi-dimensional arrays... hell nah
    return 0;
}