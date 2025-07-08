#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int max) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (char*)malloc(max * sizeof(char));
    s->top = -1;
    s->capacity = max;
    return s;
}

void push(Stack* s, char c) {
    if (s->top == s->capacity - 1) return;
    s->data[++s->top] = c;
}

char pop(Stack* s) {
    if (s->top == -1) return '\0';
    return s->data[s->top--];
}

int isPalindrome(char* str) {
    int len = strlen(str);
    Stack* s = createStack(len);
    for (int i = 0; i < len; i++) {
        push(s, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(s)) {
            free(s->data);
            free(s);
            return 0;
        }
    }
    free(s->data);
    free(s);
    return 1;
}

int main() {
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';
    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
