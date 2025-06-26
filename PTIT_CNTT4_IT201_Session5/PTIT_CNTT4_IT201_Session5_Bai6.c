#include <stdio.h>
int tong = 0;
void tinhTong(int arr[], int n) {
    if (n==0) return;
    tinhTong(arr, n-1);
    tong += arr[n-1];
}
int main() {
    int n;
    printf("Nhap so luong n: ");
    scanf("%d", &n);
    int arr[n];
    if (n <= 0) {
        printf("Khong hop le");
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    tinhTong(arr,n);
    printf("%d", tong);
    return 0;
}