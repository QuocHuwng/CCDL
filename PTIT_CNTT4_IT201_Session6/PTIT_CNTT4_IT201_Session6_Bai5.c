#include <stdio.h>
#include <stdlib.h>
int timMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxPhanConLai = timMax(arr, n -1);
    int max;
    if (arr[n-1]> maxPhanConLai) {
        max = arr[n-1];
    }else {
        max = maxPhanConLai;
    }
    return max;
}
int timMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int minPhanConLai = timMin(arr, n-1);
    int min;
    if (arr[n-1] < minPhanConLai) {
        min = arr[n-1];
    }else {
        min = minPhanConLai;
    }
    return min;
}
int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int min = timMin(arr, n);
    int max =timMax(arr, n);
    printf("min:%d, max:%d", min, max);
    return 0;
}