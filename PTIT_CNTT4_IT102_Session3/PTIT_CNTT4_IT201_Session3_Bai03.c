#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    do {
        printf("Nhap vao so luong phan tu cua mang la n voi (0<n<1000):");
        scanf("%d", &n);
        if (n<0 || n==0) {
            printf("So luong phan tu khong hop le\n");
        }if (n>1000) {
            printf("So luong phan tu khong hop le\n");
        }
    }while (n <= 0 || n > 1000);
    int *arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap [%d]", i);
        scanf("%d", &arr[i]);
    }
    int sum=0;
    int even=0;
    for (int i = 0; i < n; i++) {
        if (arr[i]%2==0) {
            even++;
            sum+=arr[i];
        }
    }
    int average = sum/even;
    printf("average=%d", average);
    return 0;
}