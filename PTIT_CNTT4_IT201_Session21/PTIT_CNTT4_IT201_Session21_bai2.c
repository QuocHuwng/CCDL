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
void prinMatrix() {
    printf("[\n");
    for (int i = 0; i < 4; i++) {
        printf(" ");
        for (int j = 0; j<4;j++) {
            printf("%d ",matrix[i][j]);
            if (j<3) printf(", ");
        }
        printf("\n");
    }
    printf("]\n");
}
int main() {
    initMatrix();
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(2,3);
    prinMatrix();
    return 0;
}
