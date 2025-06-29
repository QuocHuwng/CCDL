#include <stdio.h>
#include <stdlib.h>
int tinhTong(int n) {
    if (n == 0) return 0;
    int soCuoi = n%10;
    int phanConLai = n/10;
    int tongConLai = tinhTong(phanConLai);
    int tong = soCuoi + tongConLai;
    return tong;
}
int main() {
    int n;
    printf("Please enter a number: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le");
    }else {
        int tong = tinhTong(n);
        printf("%d", tong);
    }
    return 0;
}