#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;
Stack* taoStack(int max) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(max * sizeof(int));
    s->top = -1;
    s->capacity = max;
    return s;
}
void push(Stack* s, int value) {
    if (s->top == s->capacity - 1) {
        printf("Stack day\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}
void inStack(Stack* s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->arr[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", s->capacity);
    printf("}\n");
}
int main() {
    Stack* stack = taoStack(5);
    int x;

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &x);
        push(stack, x);
    }
    inStack(stack);
    free(stack->arr);
    free(stack);
    return 0;
}
