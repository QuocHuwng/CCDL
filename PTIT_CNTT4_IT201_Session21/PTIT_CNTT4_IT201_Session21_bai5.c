#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* graph[],int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}
void printGraph(Node* graph[], int n) {
    printf("[\n");
    for (int i = 0; i < n; i++) {
        printf(" ");
        Node* temp= graph[i];
        if (temp == NULL) {
            printf("NULL,\n");
            continue;
        }
            while (temp != NULL) {
                printf("%d->", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
}
int main() {
    int n=3;
    Node* graph[3]={NULL};
    int starNode =1;
    int endNode =2;
    addEdge(graph,starNode,endNode);
    printGraph(graph, n);

    starNode=0;
    endNode=1;
    addEdge(graph,starNode,endNode);
    printGraph(graph, n);
    return 0;
}