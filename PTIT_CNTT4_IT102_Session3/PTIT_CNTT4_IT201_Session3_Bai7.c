#include <stdio.h>
#include <stdlib.h>
int tinhTongHang(int **arr, int cols, int k) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[k][j];
    }
    return sum;
}
int main() {
    int rows, cols, k;
    do {
        printf("Nhap so hang (0 < rows < 1000): ");
        scanf("%d", &rows);
        printf("Nhap so cot (0 < rows < 1000): ");
        scanf("%d", &cols);
        if (rows <= 0 && cols <= 0) {
            printf("So hang va so cot khong hop le. Vui long nhap lai.\n");
        }else if(rows <=0) {
            printf("So hang khong hop le. Vui long nhap lai.\n");
        }else if(cols<=0) {
            printf("So cot khong hop le. Vui long nhap lai.\n");
        }
    }while(rows <= 0 || cols <= 0);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Nhap cac phan tu:\n ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d]", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Nhap chi so hang k:\n ");
    scanf("%d", &k);
    if (k < 0 || k >= cols) {
        printf("Hang can tinh khong ton tai");
    }else {
        int sum= tinhTongHang(arr, cols, k);
        printf("sum = %d", sum);
    }
    free(arr);
    return 0;
}