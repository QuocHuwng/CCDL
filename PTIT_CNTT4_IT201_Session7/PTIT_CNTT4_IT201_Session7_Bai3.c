#include <stdio.h>
int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
int printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
}
int main() {
    int n;
    int arr[100];
    printf("Nhap vao so luong phan tu");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d]", i);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("after: ");
    printArray(arr, n);
    return 0;
}