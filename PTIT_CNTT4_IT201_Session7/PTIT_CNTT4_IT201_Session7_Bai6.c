#include <stdio.h>
void merge(int arr[], int left,int m, int right) {
    int i = left, j = m+1, k=0, temp[100];
    while (i <= m && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left, j = 0; i <= right; i++,j++) arr[i] = temp[j];
}
void mergeSort(int arr[],int left, int right) {
    if (left >= right) return;
    int m = (left + right) / 2;
    mergeSort(arr,left,m);
    mergeSort(arr,m+1,right);
    merge(arr, left, m, right);
}
int main() {
    int n,i,arr[100];
    printf("Nhap so luong phan tu");
    scanf("%d", &n);
    if (n<=0||n>=1000) {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    for (i=0;i<n;i++) {
        printf("arr[%d] = ", i);
        scanf("%d",&arr[i]);
    }
    printf("before =[\n");
    for (i=0;i<n;i++) {
        printf("%d, ", arr[i]);
        if (i < n-1) printf(",");
    }
    printf("]\n");
    mergeSort(arr,0,n-1);
    printf("after =[\n");
    for (i=0;i<n;i++) {
        printf("%d, ", arr[i]);
        if (i < n-1) printf(",");
    }
    printf("]\n");
    return 0;
}
