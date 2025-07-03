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

void sapXepTangDan(Node* head) {
    if (head == NULL) return;
    Node* i = head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main() {
    Node* danhSach = NULL;
    themVaoDau(&danhSach, 3);
    themVaoDau(&danhSach, 7);
    themVaoDau(&danhSach, 5);

    printf("Truoc khi sap xep:\n");
    inDanhSach(danhSach);

    sapXepTangDan(danhSach);

    printf("Sau khi sap xep tang dan:\n");
    inDanhSach(danhSach);

    return 0;
}
