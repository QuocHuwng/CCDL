#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int top;
    int size;
} Stack;

Stack* taoStack(int n) {
    Stack* s = malloc(sizeof(Stack));
    s->a = malloc(n * sizeof(int));
    s->top = -1;
    s->size = n;
    return s;
}

void day(Stack* s, int x) {
    if (s->top == s->size - 1) return;
    s->a[++s->top] = x;
}

int lay(Stack* s) {
    if (s->top == -1) return -1;
    return s->a[s->top--];
}

void daoMang(int* a, int n) {
    Stack* s = taoStack(n);
    for (int i = 0; i < n; i++) day(s, a[i]);
    for (int i = 0; i < n; i++) a[i] = lay(s);
    free(s->a);
    free(s);
}

void inMang(int* a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("Mang ban dau:\n");
    inMang(a, n);
    daoMang(a, n);
    printf("Mang sau khi dao:\n");
    inMang(a, n);
    free(a);
    return 0;
}
