#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf(" ]\n");
}
int main() {
    int n;
    int arr[100];
    printf("n= ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("arr [%d]", i);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}