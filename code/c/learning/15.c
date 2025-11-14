#include <stdio.h>
#include <string.h>

struct movements {
    int mvt;
};

struct car {
    int date;
    char brand[15];
};

struct pieces {     //structures are like folders for variables
    char composer[20];
    char name[50];
    int score;
    struct movements mvts;  //nesting
};  //create a blueprint for a struct

union stuff {
    char acr[10];
    int gayNum;
    char todaysCringe[50];
};

int main() {
    //structures
    struct pieces p1 = {"Ravel", "Gaspard De La Nuit", 10};     //and then create an instance of the struct

    printf("%s, %s, %d, ", p1.composer, p1.name, p1.score);     //print out the variables with instanceName.variableName
    p1.score = 11;  //can update variables like this

    struct pieces p2;
    strcpy(p1.composer, "Rachmaninoff");    //strings cannot be assigned this way tho, so use strcpy(variable, string)
    strcpy(p1.name, "Piano Concerto No. 3");
    p2.score = 11;

    struct pieces p3;

    p3 = p2;    //copy

    //you can also nest structures for some reason
    struct movements gaspard = {3};
    p1.mvts = gaspard;

    printf("%d\n", p1.mvts.mvt);

    //and pointers can be used with structures, how fun

    struct car c1 = {2020, "Toyota"};
    struct car *pC1 = &c1;  //point to a structure instance

    printf("%d, %s\n", pC1->date, pC1->brand);  //instead of (.), (->) is used
    //structure pointers are used to make stuff more efficient, esp in functions
    //used for avoiding copying large amounts of data, change values from inside functions, to create structures dynamically (with memory allocation)


    //there smth similar to structs, unions
    //except in unions, you can only use one variable at a time, and its also more unreliable
    union stuff u1;

    strcpy(u1.acr, "sybau");
    u1.gayNum = 67;
    strcpy(u1.todaysCringe, "idk, i havent been on in awhile");
    //same stuff as struct
    //unions are used for max efficiency ig, anyways i dont really need em so imma move on

    //now typedef
    //to rename types, for readability i assume

    typedef float sink;
    sink num = 56;  //sink is just float with a different name

    //it can be used with structs to make ur life slightly easier
    //typedef struct {} name;   <- syntax
    //now you dont have to type struct when making instances

    //padding
    //computers are more efficient when things are alligned in its memory, so structs will add some extra empty bytes to "pad" the data
    //making it all the same size or smth, can be ignored most of the time, but for max efficiency its best not to

    //padding can be reduced by ordering the variables from largest at the top to smallest at the bottom
    //unions dont use padding btw

    return 0;
}