#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

union IntAndChars {
    int x;
    char c[4];
};

int main() {
    struct Node *list;
    list = malloc(sizeof(struct Node));

    list->data = 2;
    struct Node *p = list;
    p->next = malloc(sizeof(struct Node));
    p = p->next;
    p->data = 7;
    p->next = malloc(sizeof(struct Node));
    p = p->next;
    p->data = 10;
    p->next = NULL;

    // -------

    p = list;
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    union IntAndChars myUnion;
    myUnion.c[3] = 3;
    myUnion.c[2] = 2;
    myUnion.c[1] = 1;

    printf("My int is %d\n", myUnion.x);
}