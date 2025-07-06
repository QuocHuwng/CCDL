#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* taoNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void themVaoCuoi(Node** head, int value) {
    Node* newNode = taoNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void duyetVaIn(Node* head) {
    int i= 1;
    while (head != NULL) {
        printf("Node %d: %d\n", i, head->data);
        head = head->next;
        i++;
    }
}
int main() {
    Node* danhSach = NULL;
    themVaoCuoi(&danhSach, 1);
    themVaoCuoi(&danhSach, 2);
    themVaoCuoi(&danhSach, 3);
    themVaoCuoi(&danhSach, 4);
    themVaoCuoi(&danhSach, 5);
    duyetVaIn(danhSach);
    return 0;
}