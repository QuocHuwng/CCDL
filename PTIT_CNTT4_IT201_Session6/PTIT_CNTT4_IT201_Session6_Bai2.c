#include <stdio.h>
#include <stdlib.h>
int fibonacci(int k) {
    if(k==1 || k==2) return 1;
    return fibonacci(k-1) + fibonacci(k-2);
}
void inFibonacci(int n) {
    if (n ==0) return;
    printf("%d", fibonacci(n));
    if (n>1) printf(", ");
    inFibonacci(n-1);
}
int main() {
    int n;
    printf("Nhap so nguyen duong bat ky");
    scanf("%d",&n);
    if (n <= 0) {
        printf("Input khong hop le");
    }else {
        inFibonacci(n);
        printf("\n");
    }
    return 0;
}