#include <stdio.h>

int main() {
    //type conversion
    //implicit and explicit
    //implicit generally is not a good thing, unless ur a hard core python/js programmer

    //example of implicit
    float afloat = 9;
    printf("%f\n", afloat);   //gets converted to 9.00000...

    int x = 5;
    int y = 2;
    int sum = 5/2;
    printf("%d\n", sum);

    //example of explicit
    float sum1 = (float) 5/2;
    printf("%f\n", sum1);

    //implicit can lead to problems so explicit is better

    //const
    //if a variable doesnt change it should be a constant

    const double PI = 3.14159265358793;
    //trying to reassign it will throw an error
    //constants should be named with ALL CAPS (ifykyk) for readability
    return 0;
}