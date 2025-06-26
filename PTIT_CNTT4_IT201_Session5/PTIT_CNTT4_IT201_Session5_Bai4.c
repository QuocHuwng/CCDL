#include <stdio.h>
int tong=0;
void tinhTong(int a, int b) {
    if (a>b) return;
    tinhTong(a+1,b);
    tong += a;
}
int main() {
    int a,b;
    printf("Nhap so thu nhat:");
    scanf("%d", &a);
    printf("Nhap so thu hai:");
    scanf("%d", &b);
    if (a <0 && b > 0) {
        printf("Khong hop le");
    }else if (a>0 && b<0) {
       printf("Khong hop le");
    }else {
        tinhTong(a,b);
        printf("Tong la: %d", tong);
    }
    return 0;
}