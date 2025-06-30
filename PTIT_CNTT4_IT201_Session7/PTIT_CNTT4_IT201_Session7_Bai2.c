#include <stdio.h>
int selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    printf("Nhan vao so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("after: ");
    printArray(arr, n);
    return 0;
}