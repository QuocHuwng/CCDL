#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *taoNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("error");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void themVaoCuoi(Node** head, int value) {
    Node *newNode = taoNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Node* danhSach = NULL;
    themVaoCuoi(&danhSach, 10);
    themVaoCuoi(&danhSach, 20);
    themVaoCuoi(&danhSach, 30);
    themVaoCuoi(&danhSach, 40);
    themVaoCuoi(&danhSach, 50);
    printf("Danh sach lien ket doi:\n");
    inDanhSach(danhSach);
    return 0;
}