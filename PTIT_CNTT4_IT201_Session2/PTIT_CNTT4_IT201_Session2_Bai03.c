#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    int *arr;
    do {
        printf("Nhap vao 1 mang so nguyen co n phan tu (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Vui long nhap lai n!\n");
        }

    }while(n <= 0 || n > 100);
    arr = (int *)malloc(n * sizeof(int));
    if (n <= 0 || n > 100) {
        printf("Error\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n/2 ; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Mang sau khi dao nguoc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}