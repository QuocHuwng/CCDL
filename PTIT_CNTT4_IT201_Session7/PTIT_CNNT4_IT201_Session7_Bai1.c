#include <stdio.h>
int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i < n-1) printf(" ");
    }
    printf("\n");
}
int main() {
    int n;
    int arr[100];
    printf("Nhap vao so luong phan tu n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nafter: ");
    printArray(arr, n);
    return 0;
}