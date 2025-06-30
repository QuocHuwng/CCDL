#include <stdio.h>
#include <string.h>

void sapXepChuoi(char str[]) {
    int i, j;
    char temp;
    int len = strlen(str);
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j] && str[i] != ' ' && str[j] != ' ') {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    int i;

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    int hopLe = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            hopLe = 1;
            break;
        }
    }

    if (!hopLe) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("Truoc khi sap xep: \"%s\"\n", str);
    sapXepChuoi(str);
    printf("Sau khi sap xep: \"");
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            printf("%c", str[i]);
        }
    }
    printf("\"\n");

    return 0;
}
