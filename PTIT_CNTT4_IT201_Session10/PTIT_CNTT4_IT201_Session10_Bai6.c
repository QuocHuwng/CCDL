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

int demSoLuong(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void timPhanTuGiua(Node* head) {
    int count = demSoLuong(head);
    int viTri = count / 2 + 1;
    int index = 1;
    while (head != NULL) {
        if (index == viTri) {
            printf("Node %d: %d\n", viTri, head->data);
            return;
        }
        index++;
        head = head->next;
    }
}

int main() {
    Node* danhSach1 = NULL;
    themVaoDau(&danhSach1, 1);
    themVaoDau(&danhSach1, 2);
    themVaoDau(&danhSach1, 3);
    themVaoDau(&danhSach1, 4);
    themVaoDau(&danhSach1, 5);

    printf("Danh sach 1:\n");
    inDanhSach(danhSach1);
    timPhanTuGiua(danhSach1);

    Node* danhSach2 = NULL;
    themVaoDau(&danhSach2, 6);
    themVaoDau(&danhSach2, 1);
    themVaoDau(&danhSach2, 2);
    themVaoDau(&danhSach2, 3);
    themVaoDau(&danhSach2, 4);
    themVaoDau(&danhSach2, 5);

    printf("Danh sach 2:\n");
    inDanhSach(danhSach2);
    timPhanTuGiua(danhSach2);

    return 0;
}
