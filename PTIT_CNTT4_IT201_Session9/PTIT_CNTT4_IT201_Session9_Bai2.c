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
void inNode(Node* head) {
    Node* temp = head;
    int i =1;
    while (temp != NULL) {
        printf("Node %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
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
    inNode(danhSach);
    return 0;
}