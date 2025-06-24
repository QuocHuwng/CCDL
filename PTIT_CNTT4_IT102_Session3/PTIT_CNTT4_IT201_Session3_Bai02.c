#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    do {
        printf(("Nhap vao so luong phan tu la n voi (0<n<1000)"));
        scanf("%d", &n);
        if( n < 0) {
            printf("So luong phan tu khong hop le\n");
        } if (n == 0){
            printf("So luong phan tu khong hop le\n");
        }if (n > 1000) {
            printf("So luong phan tu khong hop le\n");
        }
    }while(n <= 0 || n > 1000);
    int *arr = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        printf("Nhap [%d]",i);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("max=%d", max);
    free(arr);
    return 0;
}