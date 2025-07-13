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
    if (q->size == q->capacity) {
        printf("queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
    q->size++;
}

void printQueue(Queue* q) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = 0; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q->front);
    printf("   rear = %d,\n", q->rear);
    printf("   capacity = %d\n", q->capacity);
    printf("},\n");
}

int main() {
    int n = 5;
    Queue* q = createQueue(n);
    printQueue(q);

    for (int i = 0; i < 5; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
        printQueue(q);
    }

    int extra;
    scanf("%d", &extra);
    enqueue(q, extra);

    free(q->array);
    free(q);
    return 0;
}
