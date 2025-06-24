#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    int *arr;

    do {
        printf("Nhap phan tu n:");
        scanf("%d", &n);
        if (n < 0 || n > 1000) {
            printf("So luong phan tu khong hop le\n");
        }
    }while (n < 0 || n > 1000);
    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Error");
        return 1;
    }
    printf("Nhap phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang vua nhap la:[");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d, ", arr[i]);
        }else {
            printf("%d] ", arr[i]);
        }
    }
    printf("\nNhap so luong phan tu m:");
    scanf("%d", &m);
    if (m>0) {
        int *arr2 = (int *)realloc(arr,(n+m) * sizeof(int));
        if (arr2 == NULL) {
            printf("Error");
            free(arr);
            return 1;
        }
        arr = arr2;
        printf("Nhap phan tu:\n");
        for (int i = n; i < n+m; i++) {
            printf("arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        n = n + m;
    }
    printf("Mang sau khi them: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(arr);
    return 0;
}