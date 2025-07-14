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

void printQueueStruct(Queue* q) {
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

void printAllElements(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Queue* q1 = createQueue();
    printQueueStruct(q1);
    printAllElements(q1);
    printf("\n");

    Queue* q2 = createQueue();
    Node* n1 = malloc(sizeof(Node)); n1->data = 1;
    Node* n2 = malloc(sizeof(Node)); n2->data = 2;
    Node* n3 = malloc(sizeof(Node)); n3->data = 5;
    n1->next = n2; n2->next = n3; n3->next = NULL;
    q2->front = n1;
    q2->rear = n3;

    printQueueStruct(q2);
    printAllElements(q2);

    return 0;
}
