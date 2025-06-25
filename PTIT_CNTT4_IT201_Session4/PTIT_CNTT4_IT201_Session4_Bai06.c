#include <stdio.h>
#include <stdlib.h>
struct Student {
    int id;
    char name[50];
    int age;
};
int main() {
    int n;
    printf("Nhap so luong sinh vien:");
    scanf("%d", &n);
    if (n<=0) {
        printf("So luong khong hop le");
        return 1;
    }
    struct Student *students = (struct Student *) malloc(n*sizeof(struct Student));
    if (students == NULL) {
        printf("Error");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        students[i].id = i+1;
        printf("\nID:%d\n", i+1);
        printf("Name:");
        scanf(" %[^\n]",&students[i].name);
        printf("Age:");
        scanf("%d",&students[i].age);
    }
    printf("Nhap id muon tim:");
    int target;
    scanf("%d", &target);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id==target) {
            printf("{ id: %d, name: \"%s\", age: %d }\n",
                   students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sinh vien khong hop le");
    }
    free(students);
    return 0;
}
