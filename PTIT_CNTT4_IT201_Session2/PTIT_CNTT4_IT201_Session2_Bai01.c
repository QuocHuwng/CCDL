#include <stdio.h>
#include  <stdlib.h>


int main() {
    int n, i;
    int *arr;

    do {
        printf("Nhap vao mang so nguyen n (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Vui long nhap lai n!\n");
        }
    } while (n <= 0 || n > 100);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("So lon nhat trong mang: %d\n", max);
    free(arr);
    return 0;
}
