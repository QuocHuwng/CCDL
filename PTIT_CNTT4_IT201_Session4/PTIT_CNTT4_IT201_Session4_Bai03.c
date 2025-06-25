#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap vao so luong phan tu: ");
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
    int minValue = arr[0];
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }
    printf("Chi so cua phan tu nho nhat dau tien trong mang la: %d ", minIndex);
    free(arr);
    return 0;
}
