#include <stdio.h>
int graph[3][3];
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j<3;j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void prinMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j<4;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrix();
    addEdge(1,0);
    addEdge(1,2);
    addEdge(2,0);
    prinMatrix();
    return 0;
}