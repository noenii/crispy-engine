#include <stdio.h>

int main() {
    //operators!

    int num = 9 + 10;
    printf("%d\n", num);  //NO ITS 21!!!!!!!!!!!!!!

    //anyways + can be used to add variables, they should be the same data type tho
    printf("%d\n", num + 67 + 69);

    
    //arithmetic
    int x = 9;
    int y = 11;

    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);  //prob use a float for this
    
    printf("x %% y = %d\n", x % y); //amateur knows about modulo, crazy right?

    x++;
    y--;

    printf("x ++ = %d\n", x);    //increment (1)
    printf("y -- = %d\n", y);    //decrement (1)


    //assignment
    int z = x += y;

    printf("%d\n", z);
    /*

    x = y   <-- x = y
    x += y  <-- x = x + y
    x -= y  <-- x = x - y
    x *= y  <-- x = x * y
    x /= y  <-- x = x / y
    x %= y  <-- x = x % 5
    x &= y  <-- x = x & y
    x |= y  <-- x = x | y
    x ^= y  <-- x = x ^ y
    x >>= y <-- x = x >> y
    x <<= y <-- x = x << y

    */


    //comparison

    int a = 2, b = 1;
    printf("%d", a < b);    //is b more than a?

    /*

    ==  <-- equal?
    !=  <-- not equal?
    >   <-- greater than?
    <   <-- less than?
    >=  <-- greater than OR equal to?
    <=  <-- less than OR equal to?
    
    */
    //returns 1 if true, and 0 if false


    //logic

    /*
    &&  <-- AND
    ||  <-- OR
    !   <-- NOT
    */


    //order

    /*

    1.  ()
    2.  * , / , %
    3.  + , -
    4.  > , < , >= , =<
    5.  == , !=
    6.  &&
    7.  ||
    8.  =

    */

    return 0;
}