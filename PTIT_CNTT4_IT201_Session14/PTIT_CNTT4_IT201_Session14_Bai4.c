#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
} Stack;
Node* taoNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho  Node!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Stack* taoStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Khong the cap phat bo nho  Stack!\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

void push(Stack* s, int value) {
    Node* newNode = taoNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Ngan xep trong\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

void inStack(Stack* s) {
    Node* current = s->top;
    printf("stack = {\n   ");
    if (current == NULL) {
        printf("NULL\n");
        printf("}\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
    printf("}\n");
}
int main() {
    Stack* myStack = taoStack();

    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);

    inStack(myStack);
    int layGiaTri = pop(myStack);
    inStack(myStack);
    Stack* emptyStack = taoStack();
    inStack(emptyStack);
    int giaTri = pop(emptyStack);
    return 0;
}