#include <stdio.h>
void quickSort(int arr[], int left, int right) {
    if (left >= right) return ;
    int pivot = arr[(left+right)/2];
    int i = left, j = right, temp;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}
int main() {
    int n,i,arr[100];
    printf("Nhap so luong phan tu");
    scanf("%d", &n);
    if (n <= 0 || n >=1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("before = [");
    for (i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    quickSort(arr, 0, n - 1);
    printf("after = [");
    for (i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    return 0;
}