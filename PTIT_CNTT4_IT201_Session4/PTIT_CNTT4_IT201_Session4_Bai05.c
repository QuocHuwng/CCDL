#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Nhap so luong ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hop le");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Nhap gia tri bat ky ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Phan tu co trong mang");
            return 0;
        }
    }
    printf("Phan tu khong co trong mang");
    free(arr);
    return 0;
}