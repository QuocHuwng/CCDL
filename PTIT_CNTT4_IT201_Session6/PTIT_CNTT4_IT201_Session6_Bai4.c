#include <stdio.h>
int thapHaNoi(int n, char cotNguon, char cotTrungGian, char cotDich) {
    if (n ==1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", cotNguon, cotDich);
            return;
    }
    thapHaNoi(n-1, cotNguon, cotTrungGian, cotDich);
    printf("Dia %d di chuyen tu %c sang %c\n", n, cotNguon, cotDich);
    thapHaNoi(n-1,cotTrungGian, cotNguon, cotDich);
}
int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le");
    }else {
        thapHaNoi(n, 'A', 'B', 'C');
    }
    return 0;
}