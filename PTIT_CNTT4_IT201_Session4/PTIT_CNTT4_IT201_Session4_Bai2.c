#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Nhap vao so luong: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Chi so phan tu lon nhat dau tien trong mang la: ");
    int maxValue= arr[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
    printf("%d\n", maxIndex);
    free(arr);
    return 0;
}