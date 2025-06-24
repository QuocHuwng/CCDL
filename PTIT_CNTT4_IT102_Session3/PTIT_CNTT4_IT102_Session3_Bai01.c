#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i;
    do {
        printf("Nhap vao so luong phan tu cua mang la n voi (0<n<1000)");
        scanf("%d",&n);
        if (n < 0) {
            printf("So luong phan tu khong duoc am\n");
        } if (n == 0){
            printf("So luong phan tu phai lon hon 0\n");
        } if (n > 1000) {
            printf("Vui long nhap lai\n");
        }
    }while(n<=0||n>1000);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap [%d]", i);
        scanf("%d",&arr[i]);
    }
    printf("Mang vua nhap la: [");
    for (i=0;i<n;i++) {
        if (i != n-1) {
            printf("%d,", arr[i]);
        }else {
            printf("%d]", arr[i]);
        }
    }
    free(arr);
    return 0;
}