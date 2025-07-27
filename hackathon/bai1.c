#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[20];
}Task;
//Node cho danh sach lien ket don
typedef struct SingLeNode {
    Task task;
    struct SingLeNode *next;
}SingLeNode;
//Node cho danh sach lien ket doi
typedef struct DoubleNode {
    Task task;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
SingLeNode *head = NULL;
DoubleNode *completedHead = NULL, *completedTail = NULL;
int id() {
    static int id = 1;
    return id++;
}
void addTask() {
    SingLeNode *newTask = (SingLeNode *)malloc(sizeof(SingLeNode));
    newTask->task.id = id();
    fflush(stdin);
    printf("Nhap tieu de:");
    gets(newTask->task.title);
    printf("Nhap muc do uu tien:");
    scanf("%d", &newTask->task.priority);
    fflush(stdin);
    printf("Nhap dealine:");
    gets(newTask->task.deadline);
    newTask->next = NULL;
    if (head == NULL) {
        head = newTask;
    }else {
        SingLeNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
    printf("Them nhiem vu thanh cong\n");
}
void showTask(){
    if (!head) {
        printf("List is empty\n");
        return;
    }
    SingLeNode *temp = head;
    printf("Danh sach nhiem vu\n");
    while (temp) {
        printf("Id: %d | Tieu De: %s | Uu tien: %d | Dealine: %s\n",
            temp->task.id, temp->task.title, temp->task.priority, temp->task.deadline);
        temp = temp->next;
    }
}
void deleteTask() {
    int id;
    printf("Nhap id muon xoa: ");
    scanf("%d", &id);
    SingLeNode *temp = head, *prev = NULL;
    while (temp && temp->task.id != id) {
        prev=temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay nhiem vu");
        return;
    }
    if (!prev) {
        head= temp->next;
    }else {
        prev->next=temp->next;
    }
    free(temp);
    printf("da xoa nhiem vu\n");
}
void updateTask() {
    int id;
    printf("Nhap id muon cap nhat: ");
    scanf("%d", &id);
    SingLeNode *temp = head;
    while (temp&&temp->task.id != id) {
        temp=temp->next;
    }
    if (!temp) {
        printf("khong tim thay nhiem vu");
        return;
    }
    printf("Nhap tieu de moi: ");
    fflush(stdin);
    gets(temp->task.title);
    printf("Nhap muc do uu tien: ");
    scanf("%d", &temp->task.priority);
    printf("Nhap dealine: ");
    fflush(stdin);
    gets(temp->task.deadline);
    printf("Cap nhat thanh cong\n");
}
void markTask() {
    int id;
    printf("Nhap id muon danh dau");
    scanf(("%d", &id));
    SingLeNode *temp = head, *prev = NULL;
    while (temp && temp->task.id != id) {
        prev=temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay nhiem vu");
        return;
    }
    if (!prev) {
        head= temp->next;
    }else {
        prev->next= temp->next;
    }
    DoubleNode *newTask = (DoubleNode *)malloc(sizeof(DoubleNode));
    newTask->task=temp->task;
    newTask->prev=completedTail;
    newTask->prev=NULL;
    if (completedTail) {
        completedTail->next = newTask;
    }else {
        completedTail = newTask;
    }
    completedTail=newTask;
    free(temp);
    printf("Du an da duoc danh dau");
}
void sortTask() {
    if (!head || !head->next) {
        return;
    }
    for (SingLeNode *i = head;i;i=i->next) {
        for (SingLeNode *j=head;j;j=j->next) {
            if (i->task.priority>j->task.priority) {
                Task temp= i->task;
                i->task=j->task;
                j->task=temp;
            }
        }
    }
    printf("Da sap xep\n");
}
void searchTask() {
    char name[100];
    printf("Nhap ten du an can tim: ");
    fflush(stdin);
    scanf("%s", name);
    SingLeNode *temp = head;
    while (temp) {
        if (strcmp(temp->task.title, name) == 0) {
            printf("Tim thay: ID: %d | Tieu de: %s | Uu tien: %d | Deline: %s\n",
                temp->task.id, temp->task.title, temp->task.priority,temp->task.deadline);
            return;
        }
        temp=temp->next;
    }
    printf("Khong tim thay du an\n");
}

int main() {
    int choice;
    do {
        printf("1. add\n");
        printf("2. show\n");
        printf("3. delete\n");
        printf("4. update\n");
        printf("5. mark\n");
        printf("6. sort\n");
        printf("7. search\n");
        printf("8. exit\n");
        printf("Choose: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1: addTask();
                break;
            case 2: showTask();
                break;
            case 3: deleteTask();
                break;
            case 4: updateTask();
                break;
            case 5: markTask();
                break;
            case 6: sortTask();
                break;
            case 7: searchTask();
                break;
            case 8:
                printf("Thoat");
                break;
            default:
                printf("Wrong Choice");
        }
    }while (choice!=8);
    return 0;
}