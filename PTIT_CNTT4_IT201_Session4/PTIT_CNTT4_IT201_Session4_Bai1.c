#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n Nhap gia tri bat ky: ");
    int target;
    scanf("%d", &target);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("%d", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu");
    }
    free(arr);
    return 0;
}