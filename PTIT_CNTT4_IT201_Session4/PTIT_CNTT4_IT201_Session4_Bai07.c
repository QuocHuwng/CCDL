#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,j,i;
    printf("Nhap so luong: ");
    scanf("%d", &n);
    if(n<=0) {
        printf("Vui long nhap lai");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int found = 0;
    for (int i = 0; i < n/2; i++) {
        if (arr[i] == arr[n-1-i]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n-1-i]);
            found = 1;
        }
    }
    if (!found) {
        printf("khong co cap doi xung nao");
    }
    free(arr);
    return 0;
}