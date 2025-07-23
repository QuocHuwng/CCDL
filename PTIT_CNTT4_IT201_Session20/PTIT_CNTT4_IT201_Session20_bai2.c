#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node** items;
    int size;
    int front;
    int rear;
    int capacity;
} Queue;
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->items = (Node**)malloc(q->capacity * sizeof(Node*));
    return q;
}
int isEmpty(Queue* q) {
    return q->size == 0;
}
void enqueue(Queue* q, Node* node) {
    if (q->rear == q->capacity) {
        return;
    }
    q->rear++;
    q->items[q->rear] = node;
    q->size++;
}
Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    Node* node = q->items[q->front];
    q->front++;
    q->size--;
    return node;
}
void addNode(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        }else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        }else {
            enqueue(q, current->right);
        }
    }
    free(q->items);
    free(q);
}
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
    free(q->items);
    free(q);
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    addNode(root, 6);
    addNode(root, 7);
    printf("Preoder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Levelorder: ");
    levelorder(root);
    printf("\n");
    return 0;
}