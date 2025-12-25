#include <stdio.h>

int main(){     //idk y goto is so hated
    int i=0;
    start:
    i++;
    printf("%d\n",i);
    if(i<100){goto start;}
    return 0;
}