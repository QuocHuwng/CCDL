#include <stdio.h>
int nhiPhan(int n) {
    if (n ==0) return ;
    nhiPhan(n/2);
    printf("%d ",n%2);
}
int main() {
    int n;
    do {
        printf("Nhap so nguyen duong bat ky");
        scanf("%d",&n);
    }while(n <= 0);
    printf("Dang nhi phan cua %d la: ",n);
    nhiPhan(n);
    printf("\n");
    return 0;
}