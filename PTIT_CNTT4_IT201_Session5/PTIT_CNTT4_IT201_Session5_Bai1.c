#include <stdio.h>
#include <stdlib.h>
void inTu1DenN(int n) {
    if (n == 0) return;
    inTu1DenN(n - 1);
    printf("%d", n);
}
int main() {
    int n;
    do {
        printf("Nhap so nguyen duong:");
        scanf("%d", &n);
    }while(n<=0);
    printf("Cac so tu 1 den %d la:\n",n);
    inTu1DenN(n);
    return 0;
}