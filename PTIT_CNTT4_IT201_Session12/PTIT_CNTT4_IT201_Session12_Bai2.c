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

void duyetVaIn(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("data: %d\n", temp->data);
        temp = temp->prev;
    }
}

int main() {
    Node* danhSach = NULL;

    themVaoCuoi(&danhSach, 5);
    themVaoCuoi(&danhSach, 4);
    themVaoCuoi(&danhSach, 3);
    themVaoCuoi(&danhSach, 2);
    themVaoCuoi(&danhSach, 1);

    printf("Danh sach lien ket doi:\n");
    inDanhSach(danhSach);

    printf("\nDuyet va in du lieu cac node:\n");
    duyetVaIn(danhSach);

    return 0;
}
