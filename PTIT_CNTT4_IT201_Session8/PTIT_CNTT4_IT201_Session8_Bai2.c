#include <stdio.h>
int binarySearch(int arr[], int n, int searchValue) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right + left) / 2;
        if (searchValue == arr[mid])
            return mid+1;
        else if (searchValue > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    int n, searchValue;
    int arr[1000];
    do {
        printf("n= ");
        scanf("%d", &n);
    }while (n <= 0 || n >= 1000);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("search = ");
    scanf("%d", &searchValue);

    int result = binarySearch(arr, n, searchValue);
    if (result != -1)
        printf("phan tu vi tri thu %d\n", result);
    else
        printf("Khong ton tai phan tu\n");

    return 0;
}