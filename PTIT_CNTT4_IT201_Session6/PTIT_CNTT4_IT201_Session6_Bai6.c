#include <stdio.h>
int count(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return count(n-1) + count(n-2);
}
int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
    }else {
        int soCach=count(n);
        printf("%d\n",soCach);
    }
    return 0;
}