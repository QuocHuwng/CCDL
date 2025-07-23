#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int findLevel(Node *root, int x, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == x) {
        return level;
    }
    int left = findLevel(root->left, x, level + 1);
    if (left != -1) {
        return left;
    }
    return findLevel(root->right, x, level + 1);
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int x = 3;
    int level = findLevel(root, x, 0);
    if (level != -1) {
        printf("level = %d\n", level);
    }else {
        printf("error\n");
    }
    return 0;
}
