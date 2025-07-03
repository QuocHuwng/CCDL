#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* taoNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void themVaoDau(Node** head, int value) {
    Node* newNode = taoNode(value);
    newNode->next = *head;
    *head = newNode;
}

void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void xoaCuoi(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

int main() {
    Node* danhSach = NULL;
    themVaoDau(&danhSach, 1);
    themVaoDau(&danhSach, 2);
    themVaoDau(&danhSach, 3);
    themVaoDau(&danhSach, 4);
    themVaoDau(&danhSach, 5);
    printf("Truoc khi xoa:\n");
    inDanhSach(danhSach);
    xoaCuoi(&danhSach);
    printf("Sau khi xoa cuoi:\n");
    inDanhSach(danhSach);
    return 0;
}
