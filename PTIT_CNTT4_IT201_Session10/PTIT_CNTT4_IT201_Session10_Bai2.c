#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
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
    newNode->next = *head;
    *head = newNode;
}

void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("data: %d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    Node* danhSach = NULL;
    themVao(&danhSach, 1);
    themVao(&danhSach, 2);
    themVao(&danhSach, 3);
    themVao(&danhSach, 4);
    themVao(&danhSach, 5);

    inDanhSach(danhSach);
    return 0;
}