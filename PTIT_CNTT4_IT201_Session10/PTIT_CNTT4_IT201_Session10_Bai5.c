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

void xoaGiaTri(Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* danhSach = NULL;
    themVaoDau(&danhSach, 5);
    themVaoDau(&danhSach, 1);
    themVaoDau(&danhSach, 2);
    themVaoDau(&danhSach, 5);
    themVaoDau(&danhSach, 3);
    themVaoDau(&danhSach, 4);
    themVaoDau(&danhSach, 5);

    printf("Danh sach ban dau:\n");
    inDanhSach(danhSach);

    int x;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &x);

    xoaGiaTri(&danhSach, x);

    printf("Danh sach sau khi xoa %d:\n", x);
    inDanhSach(danhSach);

    return 0;
}
