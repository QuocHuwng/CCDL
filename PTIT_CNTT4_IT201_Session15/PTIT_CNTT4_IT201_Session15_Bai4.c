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

void printQueueStruct(Queue* q) {
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
    printf("}\n\n");
}

void printQueueElements(Queue* q) {
    if (q->size == 0) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
}

int main() {
    Queue* q1 = createQueue(5);
    printQueueStruct(q1);
    printQueueElements(q1);
    printf("\n");

    Queue* q2 = createQueue(5);
    q2->rear = 2;
    q2->size = 3;
    q2->array[0] = 1;
    q2->array[1] = 2;
    q2->array[2] = 5;
    printQueueStruct(q2);
    printQueueElements(q2);

    free(q1->array);
    free(q1);
    free(q2->array);
    free(q2);
    return 0;
}
