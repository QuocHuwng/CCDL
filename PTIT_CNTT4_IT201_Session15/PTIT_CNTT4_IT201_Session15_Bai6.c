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

void enqueue(Queue* q, int value) {
    q->rear++;
    q->array[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    int value = q->array[q->front];
    q->front++;
    q->size--;
    return value;
}

int isIncreasingByOne(Queue* q) {
    if (q->size < 2) return 1;
    int prev = dequeue(q);
    while (q->size > 0) {
        int curr = dequeue(q);
        if (curr - prev != 1) return 0;
        prev = curr;
    }
    return 1;
}

int main() {
    int n, x;
    scanf("%d", &n);
    Queue* q = createQueue(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    if (isIncreasingByOne(q)) printf("True\n");
    else printf("False\n");

    free(q->array);
    free(q);
    return 0;
}
