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
        printf("Loi cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* themVaoCuoi(Node* head, int value) {
    Node* newNode = taoNode(value);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
Node* xoaCuoi(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
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
int main() {
    Node* head = NULL;
    head = themVaoCuoi(head, 5);
    head = themVaoCuoi(head, 4);
    head = themVaoCuoi(head, 3);
    head = themVaoCuoi(head, 2);
    head = themVaoCuoi(head, 1);
    printf("Danh sach ban dau:\n");
    inDanhSach(head);
    head = xoaCuoi(head);
    printf("Danh sach sau khi xoa cuoi:\n");
    inDanhSach(head);
    return 0;
}
