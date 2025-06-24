#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, position;
    do {
        printf("Nhap so phan tu n (0 < n <= 100): ");
        scanf("%d", &n);
    }while (n <= 0 || n > 100);
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Error");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri muon xoa (0->%d", n-1);
    scanf("%d", &position);
    if (position < 0 || position >= n) {
        printf("Khong hop le\n");
        free(arr);
        return 1;
    }
    for (int i = position; i<n-1;i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf("Mang sau khi xoa:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i != n-1) {
            printf(",");
        }
    }
    printf("\n");
    free(arr);
    return 0;
}