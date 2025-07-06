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
void themTaiViTri(Node** head, int value, int pos) {
    Node* newNode = taoNode(value);
    if (pos <= 1 || *head == NULL) {
        newNode->next = *head;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    int i = 1;
    while (temp != NULL && i <pos -1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL|| temp->next == NULL) {
        themVaoCuoi(head, value);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
int main() {
    Node* danhSach = NULL;
    themVaoCuoi(&danhSach, 1);
    themVaoCuoi(&danhSach, 2);
    themVaoCuoi(&danhSach, 3);
    themVaoCuoi(&danhSach, 4);
    themVaoCuoi(&danhSach, 5);
    printf("danh sach ban dau:\n");
    inDanhSach(danhSach);
    int value,pos;
    printf("\nvalue: ");
    scanf("%d", &value);
    printf("\npos: ");
    scanf("%d", &pos);
    themTaiViTri(&danhSach, value, pos);
    printf("\ndanh sach sau khi them:\n");
    inDanhSach(danhSach);
    return 0;
}