#include <stdio.h>
#include <stdlib.h>

int main() {
    // int n = 10;
    // int *v = malloc(n*sizeof(int));
    // if (v == NULL) {
    //     printf("problema!!!\n");
    //     return -1;
    // }

    // v[2] = 5;
    // v[3] = 7;

    // int *v_temp = malloc(n*2*sizeof(int));
    // if (v_temp == NULL) {
    //     printf("o alta problema !!! mai complexa\n");
    //     free(v);
    //     return -1;
    // }
    // for (int i=0; i<n; i++) {
    //     v_temp[i] = v[i];
    // }
    // free(v);
    // n *= 2;
    // v = v_temp;

    // n *= 2;
    // int *v_temp = realloc(v, n*sizeof(int));
    // if (v_temp == NULL) {
    //     printf("problema\n");
    //     free(v);
    //     return -1;
    // }
    // v = v_temp;

    int elem;
    int capacity = 1;
    int length = 0;
    int *v = malloc(capacity * sizeof(int));
    if (v == NULL) {
        printf("problema\n");
        return -1;
    }
    do {
        scanf("%d", &elem);
        if (elem != 0) {
            if (length >= capacity) {
                // realocare ==>>> dublez capacitatea
                int *v_temp = realloc(v, capacity*2*sizeof(int));
                if (v_temp == NULL) {
                    free(v);
                    printf("problema!!\n");
                    return -1;
                }
                v = v_temp;
                capacity *= 2;
            }

            v[length] = elem;
            length++;
        }
    } while (elem != 0);

    for (int i=0; i<length; i++) {
        printf("%d ", v[i]);
    }
}