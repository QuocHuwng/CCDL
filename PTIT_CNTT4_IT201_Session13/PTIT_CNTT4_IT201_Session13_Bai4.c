#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *elements;
    int top;
    int capacity;
} Stack;
Stack* createStack(int max) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->elements = (int*)malloc(max * sizeof(int));
    s->top = -1;
    s->capacity = max;
    return s;
}
void push(Stack* s, int value) {
    if (s->top == s->capacity - 1) return;
    s->top++;
    s->elements[s->top] = value;
}
void printStack(Stack* s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->elements[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", s->capacity);
    printf("}\n");
}
void viewAllElements(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->elements[i]);
    }
}
int main() {
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    printStack(stack);
    viewAllElements(stack);
    free(stack->elements);
    free(stack);
    return 0;
}
