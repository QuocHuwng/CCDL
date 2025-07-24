#include <stdio.h>
int graph[3][3];
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int u, int v) {
    graph[u][v] = 1;
}
void prinMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    addEdge(1,2);
    prinMatrix();
    return 0;
}