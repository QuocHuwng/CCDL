#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, v;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    if (n <= 0 || v <= 0 || n >= 100 || v >= 100) {
        printf("Gia tri khong hop le!\n");
        return 1;
    }
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);
    if (k < 0 || k >= n) {
        printf("Dinh khong hop le!\n");
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (adj[k][i] == 1)
            count++;
    }
    printf("So dinh ke voi %d la: %d\n", k, count);
    return 0;
}
