#include <stdio.h>

int main() {
    int *v = (int*)malloc(100);
    v[2] = 5;
    return 0;
}