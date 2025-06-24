#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, j, x;
    int found = 0;
    do {
        printf("Nhap vao so luong phan tu ");
        scanf("%d", &n);
    }while(n <= 0 || n > 100);
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Error");
        return 1;
    }
    for(i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap vao so nguyen bat ki");
    scanf("%d", &x);
    for(i = 0; i < n-1 && !found; i++) {
        for(j = i + 1; j < n; j++) {
            if (arr[i]+arr[j] == x) {
                printf("%d,%d", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
    }
    if(!found) {
        printf("Khong tim thay\n");
    }
    free(arr);
    return 0;
}