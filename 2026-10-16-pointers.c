#include <stdio.h>

int dubleaza(int *addr_x) {
    (*addr_x) *= 2;
}

int swap(int *addr_a, int *addr_b) {
    int aux = *addr_a;
    *addr_a = *addr_b;
    *addr_b = aux;
}

int main() {
    int x = 10;
    dubleaza(&x);

    int a = 2, b = 3;
    swap(&a, &b);

    printf("%d\n", x);
    printf("%d %d\n", a, b);
}