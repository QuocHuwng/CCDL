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
Node* xoaTatCa(Node* head, int x) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        if (temp->data == x) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            free(temp);
        }
        temp = nextNode;
    }
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
    head = themVaoCuoi(head, 5);
    head = themVaoCuoi(head, 2);
    head = themVaoCuoi(head, 1);
    head = themVaoCuoi(head, 5);
    printf("Danh sach ban dau:\n");
    inDanhSach(head);
    int x;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &x);
    head = xoaTatCa(head, x);
    printf("Danh sach sau khi xoa %d:\n", x);
    inDanhSach(head);
    return 0;
}
