#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
}Node;
Node* addNode(Node* head, int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
int main() {
    int n;
    printf("nhan so dinh:\n");
    scanf("%d",&n);
    if (n <= 0) {
        printf("dinh khong hop le");
        return 1;
    }
    int **matrix = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        matrix[i] = (int*)malloc(n*sizeof(int));
    }
    printf("nhap (%d %d):\n",n,n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    Node** list=(Node**)malloc(n*sizeof(Node*));
    for(int i=0;i<n;i++) {
        list[i] = NULL;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j] == 1) {
                list[i] = addNode(list[i],j);
            }
        }
    }
    printf("\ndanh sach ke:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",i);
        Node *temp = list[i];
        while(temp != NULL) {
            printf("%d-> ",temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    for(int i=0;i<n;i++) {
        free(list[i]);
        Node* temp = list[i];
        while(temp != NULL) {
            Node* a = temp;
            temp = temp->next;
            free(a);
        }
    }
    free(list);
    free(matrix);
    return 0;
}