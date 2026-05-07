#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

int validator(int cur);

int main() {
    printf("Addition with a twist!\nInput: Integer or N (Adds num to itself). Input 0 to quit.\n\n");
    int num=0;
    while(1){
        printf("Num: %d\n> ",num);
        int n=validator(num);
        if(n==0){break;}
        num+=n;
        printf("\n");
    }
    return 0;
}

int validator(int cur) {
    char buffer[32];
    while(1){
        if(fgets(buffer,sizeof(buffer),stdin)==NULL){printf("Invalid input.\n"); continue;}
        buffer[strcspn(buffer,"\n")]='\0';
        if(buffer[0]=='n'||buffer[0]=='N'){if(buffer[1]=='\0'){return cur;}}
        char *endptr;
        errno=0;
        long value=strtol(buffer,&endptr,10);
        if(buffer==endptr){printf("Invalid input.\n"); continue;}
        if(*endptr!='\0'){printf("Invalid input.\n"); continue;}
        if((errno==ERANGE&&(value==LONG_MAX||value==LONG_MIN))||value>INT_MAX||value<INT_MIN){printf("Int exceeds signed 32-bit limit.\n"); continue;}
        return (int)value;
    }
}