#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "calc.h"
#include <stdint.h>

#define PI 3.14159265358793

int main() {
    //misc stuff

    //date & time
    time_t currentTime;
    time(&currentTime);

    printf("%s", ctime(&currentTime));

    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Year: %d\n", t->tm_year + 1900);
    printf("Month: %d\n", t->tm_mon + 1);
    printf("Day: %d\n", t->tm_mday);
    printf("Hour: %d\n", t->tm_hour);
    printf("Minute: %d\n", t->tm_min);
    printf("Second: %d\n", t->tm_sec);      //bruh, all this just to split it up?


    //random
    srand(time(NULL));      //using the current time as a seed
    int r = rand();
    int r1 = rand() % 100;      //% to give a range
    printf("%d\n", r1);


    //header files and macros
    //#include <file> is a header, basically inserts that file there
    //dont think about it too much, just pretend it works like import from python

    //you can do "" instead of <> to include your own files, #include "17.c"

    //a macro is like a constant ig
    //it can represent a value, code or even like a function?

    //#ifdef and #ifndef to check if a macro is defined, no need for if statements. just end the statement with #endif

    #ifdef PI
        printf("Yes\n");
    #endif


    //creating your own header files
    //for organization, readability, is efficiency

    //goto calc.h and calc.c;

    printf("5 + 5 = %d\n", add(5, 5));
    printf("6 - 4 = %d\n", subtract(6, 4));

    //now you needa compile multiple files, use --> gcc main.c calc.c -o programName
    printf("%d\n", add(6, 7));
    printf("%d\n", subtract(6, 7));


    //storage classes
    auto int w = 5;     //auto is for local variables, its default for variables used in functions so it rarely used
    static int x = 6;       //static to use variables outside of functions, but not outside their file
    register int y = 7;     //register puts the variable on a cpu register (for faster access), obsolete (modern compilers can do this automatically)
    extern int z;       //extern means variable from another file, should be included when compiling

    //for extern --> gcc thisFile.c fileThatContainsIntZ.c -o program


    //bitwise operators
    //i dont really need em, but they are used to operate on individual bits, for efficiency i assume

    /*

    &   <-- sets both bits to one if both are one
    |   <-- sets both bits to one if either is one
    ^   <-- sets both bits to one if only one if one
    ~   <-- inverts the bits
    <<  <-- shifts the literal binary to the left
    >>  <-- shifts to the right

    */
    
    //confusing ay?


    //fixed width ints
    //the size of ints, float and doubles can vary depending on your machine
    //C solves this with stdint, a header
    //stdint's types always have the same size

    int8_t num1 = 1;    //8 bit
    int16_t  num2 = 2;  //16 bit
    int32_t num3 = 3;   //32 bit
    int64_t num4 = 4;   //64 bit

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%lld\n", num4); //lld for 64 bit

    //all the 8 bit - 64 bit have their unsigned counterpart, unsigned cant be negative (gives double the range)
    //put u infront of the type

    uint16_t num5 = 5;

    /*
    for most purposes, regular int is enough
        but sometimes it is needed, like in:
        - embedded systems
        - working with file formats where exact size matters
        - sending data across networks and need consistent results
    */


    return 0;
}