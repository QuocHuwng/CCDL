#include <stdio.h>
int linerSearch(int arr[], int n, int searchValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchValue)
            return i+1;
    }
    return -1;
}
int main() {
    int n, searchValue;
    int arr[100];
    do {
        printf("n = ");
        scanf("%d", &n);
    }  while (n <= 0 || n >= 1000);

    for (int i = 0; i < n; i++) {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }

    printf("search = ");
    scanf("%d", &searchValue);
    int result= linerSearch(arr, n, searchValue);
    if (result != -1) {
        printf("vi tri thu %d\n", result);
    } else {
        printf("Khong ton tai phan tu\n");
    }
    return 0;
}