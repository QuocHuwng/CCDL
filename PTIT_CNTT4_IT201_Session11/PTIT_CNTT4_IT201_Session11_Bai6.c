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
void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}
void xoaDau(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
int main() {
    Node* danhSach = NULL;
    themVaoCuoi(&danhSach, 1);
    themVaoCuoi(&danhSach, 2);
    themVaoCuoi(&danhSach, 3);
    themVaoCuoi(&danhSach, 4);
    themVaoCuoi(&danhSach, 5);

    printf("Truoc khi xoa dau:\n");
    inDanhSach(danhSach);

    xoaDau(&danhSach);

    printf("Sau khi xoa dau:\n");
    inDanhSach(danhSach);

    return 0;
}