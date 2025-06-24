#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i;
    int *arr;
    do {
        printf("Nhap vao 1 mang so nguyen co n phan tu (0 < n <= 100)");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Vui long nhap lai n!\n");
        }
    }while(n <= 0 || n > 100);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int x, count=0;
    printf("Nhap so can dem trong mang");
    scanf("%d", &x);
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
     printf("So %d xuat hien %d lan trong mang.\n", x, count);
    return 0;
}
