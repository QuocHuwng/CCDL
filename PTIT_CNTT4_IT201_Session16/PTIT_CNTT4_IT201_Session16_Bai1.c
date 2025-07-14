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

int main() {
    Queue* q = createQueue();
    if (q->front == NULL && q->rear == NULL) {
        printf("Queue is empty (front -> NULL, rear -> NULL)\n");
    }
    free(q);
    return 0;
}
