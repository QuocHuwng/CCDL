#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* taoStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Khong the cap phat bo nho cho stack\n");
        exit(1);
    }
    stack->arr = (int*)malloc(maxSize * sizeof(int));
    if (stack->arr == NULL) {
        printf("Khong the cap phat bo nho cho mang\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = maxSize;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack day, khong the them %d\n", value);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

void inStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack rong\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main() {
    Stack* stack = taoStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    inStack(stack);
    free(stack->arr);
    free(stack);
    return 0;
}