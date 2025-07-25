#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("nhap dinh:");
    scanf("%d", &n);
    if (n<=0||n>=100) {
        printf("so dinh khong hop le\n");
        return 1;
    }
    int **matrix = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Nhap(%d %d):\n",n,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }
    printf("so canh: %d\n", count/2);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}