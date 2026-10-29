#include <stdio.h>
#include <limits.h>

void swap(int *addr_a, int *addr_b) {
    int aux = *addr_a;
    *addr_a = *addr_b;
    *addr_b = aux;
}

int main() {
    int v[100];
    int n;

    // int v2[100], n2;

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    // int sum = 0;
    // for (int i=0; i<n; i++) {
    //     sum += v[i];
    // }
    // printf("Sum is %d\n", sum);

    // int elem_cautat;
    // int index_gasit = 0;
    // int flag_amgasit = 0;
    // scanf("%d", &elem_cautat);
    // for (int i=0; i<n; i++) {
    //     if (v[i] == elem_cautat) {
    //         // printf("Am gasit pe pozitia %d\n", i);
    //         index_gasit = i;
    //         flag_amgasit = 1;
    //         // goto label;
    //         // break; // prima aparitie
    //     }
    // }
    // // printf("Nu am gasit\n");
    // // label:
    // if (!flag_amgasit) {
    //     printf("Nu am gasit\n");
    // } else {
    //     printf("Am gasit pe pozitia %d\n", index_gasit);
    // }

    // int max = INT_MIN;
    // int index_max = -1;
    // for (int i=0; i<n; i++) {
    //     if (v[i] >= max) {
    //         max = v[i];
    //         index_max = i;
    //     }
    // }
    // if (index_max != -1) {
    //     printf("Am gasit maximul %d pe pozitia %d\n", max, index_max);
    // } else {
    //     printf("Vectorul are 0 elemente\n");
    // }

    // for (int i=0; i<n; i++) {
    //     v[i] = 2*v[i];
    // }

    // scanf("%d", &n2);
    // for (int i=0; i<n2; i++) {
    //     scanf("%d", &v2[i]);
    // }

    // int flag_am_comparat = 0;
    // for (int i=0; i<(n<n2?n:n2); i++) {
    //     if (v[i] < v2[i]) {
    //         printf("v < v2\n");
    //         flag_am_comparat = 1;
    //         break;
    //     } else if (v[i] > v2[i]) {
    //         printf("v > v2\n");
    //         flag_am_comparat = 1;
    //         break;
    //     }
    // }
    // if (!flag_am_comparat) {
    //     if (n==n2) {
    //         printf("v == v2\n");
    //     } else if (n > n2) {
    //         printf("v > v2\n");
    //     } else {
    //         printf("v2 > v\n");
    //     }
    // }

    // int frecv[10] = {0};
    // for (int i=0; i<n; i++) {
    //     if (v[i] >= 0 && v[i] <= 9) {
    //         frecv[v[i]]++;
    //     }
    // }
    // for (int i=0; i<10; i++) {
    //     printf("Frecv %d: %d\n", i, frecv[i]);
    // }

    // for (int i=0; i<n-1; i++) {
    //     for (int j=i+1; j<n; j++) {
    //         if (v[i] > v[j]) {
    //             int aux = v[i];
    //             v[i] = v[j];
    //             v[j] = aux;
    //         }
    //     }
    // }

    // int elem_cautat;
    // scanf("%d", &elem_cautat);
    // int left, right;
    // left = 0;
    // right = n;
    // int flag_amgasit = 0;
    // while (left < right) {
    //     int mid = left+(right-left)/2;
    //     if (v[mid] < elem_cautat) {
    //         left = mid+1;
    //     } else if (v[mid] > elem_cautat) {
    //         right = mid;
    //     } else {
    //         printf("Am gasit pe pozitia %d\n", mid);
    //         flag_amgasit = 1;
    //         break;
    //     }
    // }
    // if (!flag_amgasit) {
    //     printf("n-am gasit\n");
    // }

    // int elem;
    // int poz;
    // scanf("%d%d", &elem, &poz);
    // for (int i=n-1; i>=poz; i--) {
    //     v[i+1] = v[i];
    // }
    // v[poz] = elem;
    // n++;

    // int poz_delete;
    // scanf("%d", &poz_delete);
    // for (int i=poz_delete; i<n; i++) {
    //     v[i] = v[i+1];
    // }
    // n--;

    for (int i=0; i<n/2; i++) {
        swap(&v[i], &v[n-1-i]);
    }

    printf("----\n");
    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}