#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int laDoiXung(char str[], int left, int right) {
    if (left > right) return 1;
    if (str[left] != str[right]) return 0;
    return laDoiXung(str, left + 1, right-1);
}
int main() {
    char str[100];
    printf("Nhap chuoi");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    if (laDoiXung(str, 0, strlen(str)-1)) {
        printf("Palindrome valid\n\n");
    }else {
        printf("Palindrome invalid\n\n");
    }
    return 0;
}