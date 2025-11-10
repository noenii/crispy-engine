#include <stdio.h>
#include <stdbool.h>
//must include stdbool.h to use booleans

int main() {
    //booleans
    //everyone knows about em

    bool isCHard = true;
    bool isPythonHard = false;
    //declare with bool

    printf("%d\n", isCHard);
    printf("%d\n", isPythonHard);
    //1 = true, 0 = false

    //now you can do logic
    printf("%d\n", isCHard && isPythonHard);    //is C and python BOTH hard? false
    printf("%d\n", isCHard || isPythonHard);    //is either of them hard?

    return 0;
}