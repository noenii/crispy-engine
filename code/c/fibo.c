#include <stdio.h>

int main() {
    unsigned long long y = 0;
    unsigned long long x = 1;

    for(long long i = 0; i < 101; i++) {
        unsigned long long new = x + y;
        printf("%llu\n", new);
        y = x;
        x = new;
    }
}