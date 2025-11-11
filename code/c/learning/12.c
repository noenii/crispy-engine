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

    
    //pointer arithmetic ffs (￣、￣)
    //just like incrementing through arrays

    //addresses are also kept in order or smth like that, so elements in an array's addresses are next to each other
    int *firstElem = myNumbers;
    int *lastElem = &myNumbers[3];  //C doesnt stop you from accessing stuff outside of the array so be careful as it will lead to some undefined behavior

    printf("%d\n", *lastElem);
    printf("%d\n", lastElem - firstElem);   //3 which is the size of the array - 1
    //only works when both pointers are in the same array, result is the number of items too

    //pointers will also be different depending on the data they point to
    //like a pointer that points to an int is: int *pointer
    //while one for a char will be char *pointer

    //the type of the pointer matters cus the math in pointer arithmetic is different depending on it
    //memory addresses dont hold entire variables, they only store one byte
    //if more than one byte is needed like for an int (4 bytes), sequential addresses are used (p, p + 1, p + 2, p + 3 | 4 bytes)

    //thats why the type is needed, not all types are the same size
    //(int *ptr; ptr + 1 - ptr) != (char *ptr2; ptr2 + 1 - ptr2)

    int birthdays[] = {2007, 2009, 2010, 2012};
    int *p = birthdays;

    for(int i = 0; i < 3; i++) {
        printf("%d\n", *p);
        p++;    //loop through array but adding to the pointer instead of adding i to it
    }

    //pointers can also point to other pointers too for some reason (double pointers)
    int **p2 = &p;
    printf("\n%d\n", **p2); //you can also change the original variable with this too

    //WARNINGS
    //do NOT mix pointer types, it will result in the wrong addresses
    //ALWAYS initialize a pointer (point it at smth), before using it. not doing so can crash your program
    //NEVER go outside an array, you can access data from other programs and damage it

    //and be very careful since you can damage data stored in other memory addresses

    return 0;
}