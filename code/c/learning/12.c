#include <stdio.h>

int main() {
    //finally >:D
    //POINTERS!!!
    //are they really that hard tho?

    int myAge = 15;
    printf("%p\n", &myAge);  //%p to read memory addresses

    //a memory address is the physical location the variable is stored at
    //seems simple to me but maybe its just the dunning kruger effect

    //memory addresses and pointers are not the same
    //pointers are variables that STORE an address

    //they can point to any datatype, they are created with the dreaded * operator
    int cornyMeme = 67;
    int* ptr = &cornyMeme;  //stores the address of cornyMeme

    printf("%d\n%p\n%p\n", cornyMeme, &cornyMeme, ptr); //prints the data, the address, and the address stored in the pointer

    //you can also get the variable a pointer is "pointing" at (dereferencing)
    printf("%d\n\n", *ptr);

    //i dont find * to be confused for some reason, maybe im just used to computers ig
    //but ill explain em anyways, you havent mastered something till you can explain it easily!

    //int* ptr;     <-- creates a pointer variable, when its not used in declaration it acts as a dereference operator
    //you can do int* ptr;  or int *ptr;  doesnt really matter

    //pointers must be handled with a lot of care cus u can damage data stored in other memory addresses

    int myNumbers[4] = {25, 50, 75, 100};
    int i;

    for (i = 0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }   //regular array looping with pointers

    printf("\n");

    //pointers and arrays are related tho
    printf("%p\n", myNumbers);  //the variable is actually a pointer to the first element in the array

    //idk why but ig its useful in some cases?
    printf("%d\n\n", *myNumbers); //prints out the first item in the array

    //you can also add to the pointer to access the other items

    for(int y = 0; y < 4; y ++) {
        printf("%d\n", *(myNumbers + y));
    }
    
    //you can also change items with their pointers too
    *(myNumbers +1) = 17;

    return 0;
}