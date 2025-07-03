#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* taoNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void themCuoi(Node** head, int value) {
    Node* newNode = taoNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void inDanhSach(Node* head) {
    Node* temp = head;
    printf("Danh sach: ");
    while (temp) {
        printf("%d", temp->data);
        if (temp->next)
            printf("->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

void xoaTaiViTri(Node** head, int position) {
    if (position <= 0 || *head == NULL) {
        printf("Vi tri khong hop le hoac danh sach rong!\n");
        return;
    }

    Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; ++i) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri vuot qua chieu dai danh sach!\n");
        return;
    }

    Node* nodeCanXoa = temp->next;
    temp->next = nodeCanXoa->next;
    free(nodeCanXoa);
}

int main() {
    Node* danhSach = NULL;

    for (int i = 1; i <= 5; ++i)
        themCuoi(&danhSach, i);

    inDanhSach(danhSach);

    int pos;
    printf("\nNhap vi tri can xoa: ");
    scanf("%d", &pos);

    xoaTaiViTri(&danhSach, pos);
    printf("\n");
    inDanhSach(danhSach);

    return 0;
}
