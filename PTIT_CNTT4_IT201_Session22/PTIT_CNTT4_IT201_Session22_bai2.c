#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node *graph[], int u, int v) {
    Node* nodeV=createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;
    Node* nodeU=createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}
void sortList(Node** head) {
    int arr[100], count = 0;
    Node* temp = *head;
    while (temp != NULL) {
        arr[count++] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    Node* sorted = NULL;
    for (int i = count-1; i >= 0; i--) {
        Node* newNode=createNode(arr[i]);
        newNode->next = sorted;
        sorted = newNode;
    }
    *head = sorted;
}
void printGraph(Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        sortList(&graph[i]);
        printf("%d ",i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int n,m;
    printf("Nhap so dinh: ");
    scanf("%d",&n);
    printf("Nhap so canh: ");
    scanf("%d",&m);
    Node* graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    printf("Nhap cac canh (u,v):\n");
    for (int i = 0; i < m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(graph, u, v);
    }
    printf("\nDanh sach ke:\n");
    printGraph(graph, n);
    return 0;
}