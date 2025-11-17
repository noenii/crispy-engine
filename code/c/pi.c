#include <stdio.h>
#include <stdbool.h>

int main() {
    double pi = 3.0;
    bool addd = true;

    for(int i = 1; i < 1000; i++) {
        int dummy = (i * 2) * ((i * 2) + 1) * ((i * 2) + 2);
        if(addd == true) {
            pi += (4/(double) dummy);
            addd = false;
        }   else {
            pi -= (4/(double) dummy);
            addd = true;
        }
    }
    printf("%.15lf\n", pi);
    return 0;
}