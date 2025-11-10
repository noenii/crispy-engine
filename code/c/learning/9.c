#include <stdio.h>
#include <stdbool.h>

int main() {
    //loops

    //while loop
    while(true) {
        //printf("hi =D\n");
        break;
    }   //infinite loops huh???
    int i = 0;

    while(i < 10) {
        i++;
    }

    int x = 0;  //do/while does the action before checking the condition
    do {
        x++;
    }
    while(x != 5);

    //for loop
    for(int i = 1; i < 101; i++) {  //100 numbers?
        if(i % 15 == 0) {
            printf("fizzbuzz\n");
        }   else if(i % 3 == 0) {
            printf("fizz\n");
        }   else if(i % 5 == 0) {
            printf("buzz\n");
        }   else {
            printf("%d\n", i);  
        }
    }   //lmao not me writing fizzbuzz in every lang that has every existed
    //nest loops too, the usual

    //control
    //break; to exit a loop
    //continue; to skip an iteration
    return 0;
}