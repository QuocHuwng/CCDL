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
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("NULL\n");
}
void themTaiViTri(Node** head, int value, int position) {
    if (position == 0) {
        printf("Vi tri khong hop le");
        return;
    }
    Node *newNode = taoNode(value);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main() {
    Node* danhSach = NULL;
    themVao(&danhSach, 1);
    themVao(&danhSach, 2);
    themVao(&danhSach, 3);
    themVao(&danhSach, 4);
    themVao(&danhSach, 5);
    inDanhSach(danhSach);
    int value, pos;
    printf("\nvalue: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &pos);

    themTaiViTri(&danhSach, value, pos);

    printf("\n");
    inDanhSach(danhSach);
    return 0;
}