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
void themVaoDau(Node** head, int value) {
    Node* newNode = taoNode(value);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
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
    Node* danhSach = NULL;
    themVaoCuoi(&danhSach, 1);
    themVaoCuoi(&danhSach, 2);
    themVaoCuoi(&danhSach, 3);
    themVaoCuoi(&danhSach, 4);
    themVaoCuoi(&danhSach, 5);

    printf("Danh sach ban dau:\n");
    inDanhSach(danhSach);
    int x;
    printf("Nhap so nguyen duong can them vao dau: ");
    scanf("%d", &x);
    if (x>0) {
        themVaoDau(&danhSach, x);
        printf("Danh sach sau khi them:\n");
        inDanhSach(danhSach);
    }else {
        printf("Chi chap nhan so nguyen duong\n");
    }
    return 0;
}