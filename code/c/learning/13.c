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
//goto to line 54

int factorial(int num);

void stacked(void (*func)());

void another();

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

    //theres also functions pointers ヾ(≧へ≦)〃

    int (*pFactorial)(int) = &factorial;    //can be (... = &factorial) OR (... = factorial)
    //a function name is just a pointer that points to the start of the code in memory, so now you can use the function pointer to call the func
    //now you can pass around functions as a parameter
    printf("%d\n", pFactorial(5));

    stacked(another);   //a function called within another function
    
    //now you can also have an array of pointers, pointing to different functions
    //void (*pMyFuncs[7])() = { greatest, addition, myFunc, dummy, factorial, stacked, another };     //the array, should be the same type ig
    //im too lazy to get it to work

    /*
    for(int i = 0; i < 7; i++) {
        printf("%p\n", pMyFuncs[i]());
    }
    */

    //a callback function is a function thats passed in as a parameter to another function
    //they can have parameters and passing different functions can have different behaviors too, but dont mess it up as it will prob throw an error
    
    //note: you cant nest functions in C

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

void stacked(void (*func)()) {
    func();
}

void another() {
    printf("from within\n");
}