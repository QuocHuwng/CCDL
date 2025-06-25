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
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap mot gia tri bat ky:");
    int x;
    scanf("%d", &x);
    for (int i = n-1; i >= 0; i--) {
        if (arr[i]==x) {
            printf("Chi so phan tu cuoi cung cua mang giong voi gia tri da nhap %d ", i);
            free(arr);
            return 0;
        }
    }
    printf("Khong tim thay phan tu");
    free(arr);
    return 0;
}
