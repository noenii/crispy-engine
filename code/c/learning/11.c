#include <stdio.h>
#include <string.h>

int main() {
    //strings!
    //i think i can tell c is a low level lang by now

    //there is no easy to use string type blehhh :<
    //create one with an array of characters
    char myName[] = "aki";
    printf("%s\n", myName);

    //they are basically arrays so you can view chars by index
    printf("%c\n", myName[0]);

    //also you can update em by index and loop through them just like regular arrays

    //there are also special characters, which ive alr used
    //the most obvious (\n) = new line
    //(\) is a escape character, means stuff that can screw up the string must be put behind it
    //(\") for example, without (\), you would escape the string. others are: (\'), (\\)

    //honorable mentions: (\t) = tab (spaces), (\0) = null (terminator)

    //<string.h> has some useful string functions
    printf("%zu\n", strlen(myName));    //length of string

    char fname[] = "あかんえ";
    char lname[] = "いちかわ";

    strcat(fname, lname);   //concatenate strings
    //printf("%s\n", fname);  bruh

    char username[] = "noenii";
    char coolName[6];
    strcpy(coolName, username); //copy string

    printf("%s\n", coolName);

    printf("%d\n", strcmp(coolName, myName));   //compare strings, 0 if their equal, anything else means their not
    //also if its negative, the first str is bigger, else the second is bigger


    //user input!
    //printf outputs, scanf inputs

    int num;

    printf("input a num: \n");
    scanf("%d", &num);  //foreshadowing...
    printf("your num is: %d\n", num);

    //you input smth, and the variable stores it
    //prob more complicated than that, maybe some pointer black magic

    //scanf can take multiple inputs (multiple data types aswell)

    //it can also take string input
    char yourName[30];

    printf("your name: \n");
    scanf("%s", yourName);  //& is not needed for strings
    printf("your name is: %s\n", yourName);
    //the string length must be specified tho
    //put an amount higher than you will use and dont go over it

    //also some limitations: you cant use whitespace
    //if you input: jane doe, it will store jane (whitespace is a null terminator or smth)

    return 0;
}