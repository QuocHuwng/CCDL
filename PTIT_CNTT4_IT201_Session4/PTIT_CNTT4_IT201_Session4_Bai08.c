#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, value;
    printf("Nhap so luong phan tu");
    scanf("%d", &n);
    if(n<=0) {
        printf("Vui long nhap lai");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d]", i );
        scanf("%d", &arr[i]);
    }
    int found = 0;
    printf("Nhap gia tri can tim");
    scanf("%d", &value);
    printf("Vi tri xuat hien cua %d trong mang: ", value);
    for (int i = 0; i < n; i++) {
        if(arr[i] == value) {
            printf("%d ", i);
            found = 1;
        }
    }
    if(!found) {
        printf("Phan tu khong co trong mang");
    }
    free(arr);
    return 0;
}