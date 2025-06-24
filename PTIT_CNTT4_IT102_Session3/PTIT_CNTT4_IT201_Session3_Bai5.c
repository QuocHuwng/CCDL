#include <stdio.h>
#include <stdlib.h>
int tinhTongCheoChinh(int ** arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];
    }
    return sum;
}
int tinhTongCheoPhu(int ** arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][n - 1 - i];
    }
    return sum;
}
int main() {
    int row, col;
    do {
        printf("Nhap so hang: ");
        scanf("%d", &row);
        printf("Nhap so cot:");
        scanf("%d", &col);
        if (row <= 0 && col <= 0) {
            printf("So hang va so cot khong hop le): ");
        }else if (row <= 0) {
            printf("So hang khong hop le): ");
        }else if (col <= 0) {
            printf("So cot khong hop le): ");
        }
    }while (row <= 0 || col <= 0);
    int** arr = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(col * sizeof(int));
        }
    printf("Nhap cac phan tu:\n ");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%arr[%d][%d] = ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    if (row == col) {
        int tongChinh = tinhTongCheoChinh(arr, row);
        int tongPhu = tinhTongCheoPhu(arr, row);
        printf("TongChinh: %d\n", tongChinh);
        printf("TongPhu: %d\n", tongPhu);
    }else {
        printf("Khong ton tai duong cheo chinh\n ");
        printf("Khong ton tai duong cheo phu:\n ");
    }
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}