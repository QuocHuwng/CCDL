#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->array = malloc(capacity * sizeof(int));
    return q;
}

int main() {
    int n;
    scanf("%d", &n);
    Queue* q = createQueue(n);
    free(q->array);
    free(q);
    return 0;
}
