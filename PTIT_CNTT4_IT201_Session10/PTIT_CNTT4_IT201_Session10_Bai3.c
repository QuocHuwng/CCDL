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
void themVaoDau(Node** head, int value) {
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
}
void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Node* danhSach = NULL;
    themVaoDau(&danhSach, 1);
    themVaoDau(&danhSach, 2);
    themVaoDau(&danhSach, 3);
    themVaoDau(&danhSach, 4);
    themVaoDau(&danhSach, 5);
    printf("Danh sach ban dau:\n");
    inDanhSach(danhSach);

    int soMoi;
    printf("Nhap so nguyen duong can them: ");
    scanf("%d", &soMoi);

    if (soMoi > 0) {
        themVaoCuoi(&danhSach, soMoi);
        printf("Danh sach sau khi them:\n");
        inDanhSach(danhSach);
    } else {
        printf("Chi chap nhan so nguyen duong.\n");
    }

    return 0;
}