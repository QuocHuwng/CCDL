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
        printf("Khong the cap phat bo nho Node!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Stack* taoStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Khong the cap phat bo nho Stack!\n");
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
void duyetStack(Stack* s) {
    if (s->top == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    Node* current = s->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
int main() {
    Stack* myStack = taoStack();
    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);

    inStack(myStack);
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    duyetStack(myStack);
    Stack* emptyStack = taoStack();
    inStack(emptyStack);
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    duyetStack(emptyStack);
    return 0;
}
