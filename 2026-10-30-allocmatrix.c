#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int **a;
    a = malloc(n * sizeof(int*));
    if (a == NULL) {
        fprintf(stderr, "Eroare\n");
        exit();
    }

    for (int i=0; i<n; i++) {
        a[i] = malloc(m * sizeof(int));
        if (a[i] == NULL) {
            fprintf(stderr, "Eroare\n");
            for (int j=0; j<i; j++) {
                free(a[j]);
            }
            free(a);
            exit();
        }

    }
}