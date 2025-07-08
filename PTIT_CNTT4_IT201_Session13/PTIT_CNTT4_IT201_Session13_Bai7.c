#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

int laCap(char mo, char dong) {
    return (mo == '(' && dong == ')') ||
        (mo == '[' && dong == ']')
    || (mo == '{' && dong == '}');
}

int kiemTra(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' ||
            s[i] == '{') stack[++top] = s[i];
        else if (s[i] == ')' || s[i] == ']' ||
            s[i] == '}') {
            if (top == -1 || !laCap(stack[top--], s[i]))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char s[1000];
    printf("Nhap bieu thuc");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    printf(kiemTra(s) ? "true\n" : "false\n");
    return 0;
}
