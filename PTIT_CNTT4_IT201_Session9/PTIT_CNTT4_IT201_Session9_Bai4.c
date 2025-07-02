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
int demPhanTu(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    Node* danhSach = NULL;
    themVao(&danhSach, 1);
    themVao(&danhSach, 2);
    themVao(&danhSach, 3);
    themVao(&danhSach, 4);
    themVao(&danhSach, 5);
    inDanhSach(danhSach);
    int soLuong=demPhanTu(danhSach);
    printf("Danh sach lien ket co %d phan tu\n", soLuong);
    return 0;
}