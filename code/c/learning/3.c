#include <stdio.h>

int main() {
    //this is a single line comment
    /*
    THIS IS A MULTI
    LINE
    COMMENT
    */

    //variables!

    int a = 100; //an integer, no decimals! can be +/-
    int b = -67;

    float c = 3.14159; //a float, decimals yes. can be +/-

    char d = 'a';   //a char, a single character only...

    //you can also declare variables without assigning

    int e;

    printf("%d\n", e);  //e is unassigned so a random value prints out, wouldnt recommend doing this

    e = 69;

    printf("%d\n", e);

    //%d = integer
    //%f = float
    //%c = char

    printf("First letter of the English alphabet: %c\n", d);
    int f = a + b;
    printf("%d + %d = %d\n", a, b, f);
    printf("こんにちは\n");   //DOES NOT SUPPORT NON ENGLISH CHARACTERS LMFAOOAOAOAOAO
    int g = 1, h = 2, i = 3;
    printf("%d", g + h + i);    //can do math in there ig

    /*
    standard variable naming blah blah
    must be unique,
    names are recommended to be descriptive for usability purposes,
    must start with a letter or underscore
    can contain digits, letters & underscores
    case sensitive
    no whitespace or special chars
    cant use keywords
    */
   
    return 0;
}