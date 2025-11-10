#include <stdio.h>

int main() {
    float radius = 67;
    const float pi = 3.141593;

    float circumfrence = 2 * radius * pi;
    float area = radius * radius * pi;
    printf("radius: %f\ncircumfrence: %f\narea: %f\n", radius, circumfrence, area);
    return 0;
}