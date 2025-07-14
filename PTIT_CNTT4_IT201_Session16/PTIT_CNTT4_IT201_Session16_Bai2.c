#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node* createNode() {
    int x;
    scanf("%d", &x);
    Node* newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (q->front == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void printQueue(Queue* q) {
    printf("queue = {\n  front->");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (q->rear != NULL)
        printf("  rear->%d->NULL\n", q->rear->data);
    else
        printf("  rear->NULL\n");

    printf("}\n\n");
}

int main() {
    Queue* q = createQueue();
    printQueue(q);

    enqueue(q);
    printQueue(q);

    Queue* q2 = createQueue();
    Node* n1 = malloc(sizeof(Node)); n1->data = 1;
    Node* n2 = malloc(sizeof(Node)); n2->data = 2;
    Node* n3 = malloc(sizeof(Node)); n3->data = 5;
    n1->next = n2; n2->next = n3; n3->next = NULL;
    q2->front = n1;
    q2->rear = n3;
    printQueue(q2);

    enqueue(q2);
    printQueue(q2);

    return 0;
}
