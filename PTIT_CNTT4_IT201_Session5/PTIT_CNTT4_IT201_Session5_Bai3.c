#include <stdio.h>
int giaiThua=1;
void tinhGiaiThua(int n) {
    if (n == 0) return;
    tinhGiaiThua(n-1);
    giaiThua *=n;
}
int main() {
    int n;
    printf("Nhap n phai la so nguyen duong: ");
    scanf("%d", &n);
    if (n<0) {
        printf("Khong hop le");
    }else if (n==0){
        printf("Giai thua cua 0 la: 1\n");
    }else {
        tinhGiaiThua(n);
        printf("Giai thua la: %d  ", giaiThua);
    }
    return 0;
}