#include <stdio.h>

int main() {
    //data types!
    //ik int, float and char alr... anything else?

    double pi = 3.141592653587923;   //yes i wrote that by memory :>
    //double gives double the accuracy of floats
    //6-7 (ayo) digits for floats, 15 digits for double

    //strings in c be a pain

    char u[] = "AAAAAAAAAAAAAAAAA"; //atleast you dont have manually allocate it ;-;
    printf("%s\n", u);

    float sienc = 35e3; //scientific notation
    printf("%f\n", sienc);

    printf("%.15lf\n", pi);  //specify how many decimals you want to display (%. + [number here] + type)

    //display variable size
    printf("%zu", sizeof(pi));  //8 bytes

    /*
    there are more data types but im prob not gonna use em:
    short int, unsigned int, long int, long long int, unsigned long int, unsigned long long int, long double
    WHERE ARE BOOLEANS BRUH
    */
    return 0;
}