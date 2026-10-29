#include <stdio.h>

void swap(int *addr_a, int *addr_b) {
    int aux = *addr_a;
    *addr_a = *addr_b;
    *addr_b = aux;
}

void f(int a[100][100], int r, int c, int n, int m, int expected, int val) {
    if (r < 0 || r >=n || c < 0 || c >= m) {
        return;
    }

    if (a[r][c] != expected) {
        return;
    }
    a[r][c] = val;
    f(a, r-1, c, n, m, expected, val);
    f(a, r, c-1, n, m, expected, val);
    f(a, r+1, c, n, m, expected, val);
    f(a, r, c+1, n, m, expected, val);
}

int main() {
    int a[100][100]={0};
    int b[100][100]={0};
    int bn, bm;
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // for (int i=0; i<n; i++) {
    //     for (int j=i+1; j<m; j++) {
    //         swap(&a[i][j], &a[j][i]);
    //     }
    // }
    // swap(&n, &m);

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         b[j][n-i-1] = a[i][j];
    //     }
    // }
    // bn = m;
    // bm = n;


    // for (int i=n/2; i<n; i++) {
    //     for (int j=n-i; j<i; j++) {
    //         a[i][j]=8;
    //     }
    // }

    // int r,c, val;
    // scanf("%d%d", &r, &c);
    // // a[r-1][c], a[r+1][c], a[r][c-1], a[r][c+1]
    // if (r-1 >= 0) {
    //     a[r-1][c] = val;
    // }
    // if (r+1 < n) {
    //     a[r+1][c] = val;
    // }
    // if (c-1 >= 0) {
    //     a[r][c-1] = val;
    // }
    // if (c+1 < m) {
    //     a[r][c+1] = val;
    // }

    int r, c, val;
    scanf("%d%d%d", &r, &c, &val);
    f(a, r, c, n, m, a[r][c], val);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("-----\n");

    // for (int i=0; i<bn; i++) {
    //     for (int j=0; j<bm; j++) {
    //         printf("%d ", b[i][j]);
    //     }
    //     printf("\n");
    // }

}