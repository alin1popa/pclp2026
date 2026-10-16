#include <stdio.h>

int main() {
    float a = 0.1;
    float b = 0.2;

    float sum = a + b;

    printf("%.9f\n", sum);

    if (sum == 0.3) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }
}