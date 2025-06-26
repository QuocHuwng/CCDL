#include <stdio.h>
int tong = 0;
void tinhTong(int n) {
    if (n == 0) return;
    tinhTong(n -1);
    tong += n;
}

int main() {
    int n;
    printf("Nhap vao 1 so nguyen duong bat ky: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le\n");
    } else {
        tinhTong(n);
        printf("Tong la: %d\n", tong);
    }
    return 0;
}