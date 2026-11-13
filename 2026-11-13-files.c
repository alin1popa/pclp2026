#include <stdio.h>

int main() {
    int x = 65537;

    // FILE *fp = fopen("myoutput_text", "w");
    FILE *fp = fopen("myoutput_bin", "wb");
    if (!fp) {
        perror("aaaAAA!\n");
    }
    // fprintf(fp, "%d", x);
    fwrite(&x, sizeof(int), 1, fp);

    return 0;
}