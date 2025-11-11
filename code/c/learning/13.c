#include <stdio.h>
#include <math.h>   //has some cool math functions

void greatest() {   //returnType funcName() {}      void means the function wont return anything
    printf("KENDRICK!!!!!!!!!!!!!!!\n");
}

//you can also put parameters in the parantheses
int addition(int x, int y) {    //returnType = int      means the function returns an...
    return x + y;       //...int!
}

//c has the same local/global variable scope as every other lang
//structure of functions

void myFunc() {     //declaration
    //code to be run here (definition)
}

void dummy(int x);

//functions can also call other functions obviously

//inline is a keyword that tells the compiler to insert the function at where it is called, its used to make code slightly faster
//only use it for small functions, bigger ones make it slower
//dont use it for recursive and rarely called functions

//functions can call themselves too, recursion ;-;
//skip to line 54

int factorial(int num);

int main() {
    //functions!
    //int main() {} is a function btw
    greatest();
    printf("%d\n", addition(9, 10));    //when using parameters the function call must have the same number of arguements and in the right order

    float sqrtTwo = sqrt(2);    //sqrt()    for square roots
    printf("%f\n", ceil(sqrtTwo));  //ceil()    for ceiling rounding
    printf("%f\n", floor(sqrtTwo)); //floor()   for floor rounding
    printf("%f\n", pow(sqrtTwo, sqrtTwo));  //pow(num, power)   for exponents
    
    printf("%d\n", factorial(4));

    return 0;
}

void dummy(int x) {
    //do nothing =P
}

int factorial(int num) {
    if(num > 1) {
        return num * factorial(num - 1);    //calls itself
    }   else {
        return 1;
    }
}