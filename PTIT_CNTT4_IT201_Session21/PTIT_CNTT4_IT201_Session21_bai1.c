#include <stdio.h>
int matrix[4][4];
void initMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j<4;j++) {
            matrix[i][j]=0;
        }
    }
}
void addEdge(int u, int v) {
    matrix[u][v]=1;
    matrix[v][u]=1;
}
void printMatrix() {
    for (int i = -0;i<4;i++) {
        for (int j = 0;j<4;j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    initMatrix();
    addEdge(0,1);
    addEdge(1,2);
    printMatrix();
    return 0;
}