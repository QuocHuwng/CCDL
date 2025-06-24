#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, position, newValue;

    do {
        printf("Nhap so phan tu n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri muon chen (0 -> %d): ", n);
    scanf("%d", &position);
    printf("Nhap gia tri muon them: ");
    scanf("%d", &newValue);

    if (position < 0 || position > n) {
        printf("Khong hop le\n");
        free(arr);
        return 1;
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = newValue;
    n++;

    printf("Mang sau khi them:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(",");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
