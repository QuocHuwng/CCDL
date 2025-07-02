#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* taoNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("error");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void themVao(Node** head, int value) {
    Node* newNode = taoNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL ) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void inDanhSach(Node* head) {
    Node* temp = head;
    printf("Danh sach");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int timKiem(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) return 1;
        temp = temp->next;
    }
    return 0;
}
int main() {
    Node* danhSach = NULL;
    themVao(&danhSach, 1);
    themVao(&danhSach, 2);
    themVao(&danhSach, 3);
    themVao(&danhSach, 4);
    themVao(&danhSach, 5);
    inDanhSach(danhSach);
    int x;
    printf("Nhap so can tim");
    scanf("%d", &x);
    if (timKiem(danhSach, x)) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}