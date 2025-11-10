#include <stdio.h>
#include <stdbool.h>

int main() {
    bool amIJobless = true;

    if(amIJobless == true) {
        printf("peak unemployment\n");
    }   else {
        printf("impossible...");
    }

    int num = 68;

    if(num == 0) {
        printf("num is 0\n");
    }   else if(num % 2 == 0) {
        printf("num is even\n");
    }   else {
        printf("num is odd\n");
    }

    bool haveIGoonedToday = false;
    (haveIGoonedToday == true) ? printf("gooning on nnn is crazy\n") : printf("stay strong soldier\n");     //its shorter isnt it?
    //you can also nest, the usual
    //logic aswell

    //switch statements

    int day = 2;
    /*
    switch(day) {
        case 1:
            printf("日曜日\n");
            break;
        case 2:
            printf("月曜日\n");
            break;
        case 3:
            printf("火曜日\n");
            break;
        case 4:
            printf("水曜日\n");
            break;
        case 5:
            printf("木曜日\n");
            break;
        case 6:
            printf("金曜日\n");
            break;
        case 7:
            printf("土曜日\n");
            break;
    }
    */
   //なんでこれ日本語出力できないの…(〜￣▽￣)〜

    return 0;
}