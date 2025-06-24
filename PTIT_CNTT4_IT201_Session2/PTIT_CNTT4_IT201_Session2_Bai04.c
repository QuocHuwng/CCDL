#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, position, newValue;

    do {
        printf("Nhap so phan tu n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri muon sua (0 -> %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        free(arr);
        return 1;
    }

    printf("Nhap gia tri moi tai vi tri %d: ", position);
    scanf("%d", &newValue);

    arr[position] = newValue;

    printf("Mang sau khi cap nhat:\n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(arr);
    return 0;
}
