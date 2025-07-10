#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
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
typedef struct {
    Node* top;
} Stack;
Stack* taoStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Khong the cap phat bo nho Stack!\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}
int main() {
    Stack* myStack = taoStack();
    if (myStack->top == NULL) {
        printf("Ngan xep da duoc khoi tao. Dang rong.\n");
    }
    free(myStack);
    return 0;
}