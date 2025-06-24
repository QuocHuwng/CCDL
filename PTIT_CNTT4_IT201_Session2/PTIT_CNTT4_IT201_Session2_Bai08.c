#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i;
    do {
        printf("Nhap so luong phan tu:");
        scanf("%d",&n);
    }while(n<=0||n>100);
    int *arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL) {
        printf("Error\n");
        return 1;
    }
    for(i=0;i<n;i++) {
        printf("Nhap [%d]",i);
        scanf("%d",&arr[i]);
    }
    printf("Cac phan tu lon hon cac phan tu dung sau no:");
    int max= arr[n-1];
    printf("%d", max);
    for(i=n-2;i>=0;i--) {
        if(arr[i]>max) {
            printf(" %d", arr[i]);
            max=arr[i];
        }
    }
    printf("\n");
    free(arr);
    return 0;
}