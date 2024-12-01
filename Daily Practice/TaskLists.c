// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100

typedef struct{
    char *desc;
    bool completed;
}todo;

void addTask(todo *list[], int *tasks);
void upStatus(todo *list[], int tasks);
void removeTask(todo *list[], int *tasks);
void displayTask(todo *list[], int tasks);

int main() {
    todo **list = malloc(max*sizeof(todo*));
    int tasks = 0;
    
    int choice;
    
    while(1){
        printf("1) Add a Task\n2) Update Task Status\n3) Remove Task\n4) Display All Task\n5) End\n");
        scanf("%i", &choice);
        
        switch (choice){
            case 1:
                addTask(list, &tasks);
                printf("Task Added\n\n");
                break;
            case 2:
                if(tasks == 0){
                    printf("Task List is Empty!!\n\n");
                    break;
                }else{
                    upStatus(list, tasks);
                    printf("\n\n");
                    break;
                }
            case 3:
                if(tasks == 0){
                    printf("Task List is Empty!!\n\n");
                    break;
                }else{
                    displayTask(list, tasks);
                    printf("\n\n");
                    removeTask(list, &tasks);
                    printf("\n\n");
                    break;
                }
            case 4:
                if(tasks == 0){
                    printf("Task List is Empty!!\n\n");
                    break;
                }else{
                    displayTask(list, tasks);
                    printf("\n\n");
                    break;
                }
            case 5:
                free(list);
                return 0;
            default:
                printf("Choice Invalid\n\n");
                break;
        }
        
    }
}

void addTask(todo *list[], int *tasks){
     list[*tasks] = malloc(sizeof(todo));
     if(list[*tasks]  == NULL){
        printf("Memory Allocation Failed!!\n\n");
        return;
    }
    
    list[*tasks]->desc = malloc(max*sizeof(char));
    if(list[*tasks]->desc  == NULL){
        printf("Memory Allocation Failed!!\n\n");
        free(list[*tasks]);
        return;
    }
    
    printf("Enter the Task Description: ");
    while(getchar() != '\n');
    fgets(list[*tasks]->desc , max, stdin);
    list[*tasks]->desc[strcspn(list[*tasks]->desc, "\n")] = '\0';
    
    list[*tasks]->completed = false;
    
    (*tasks)++;
    
}

void upStatus(todo *list[], int tasks){
    displayTask(list, tasks);
    printf("\n\n");
    
    char *tempTask = malloc(max*sizeof(char));
    if(tempTask == NULL){
        printf("Memory Allocation Failed!!\n\n");
        free(tempTask);
        return;
    }
    
    printf("Enter the task you want mark as completed: ");
    while(getchar() != '\n');
    fgets(tempTask, max, stdin);
    tempTask[strcspn(tempTask, "\n")] = '\0';
    
    for(int i = 0; i < tasks; i++){
        if(strcmp(tempTask,list[i]->desc) == 0){
            list[i]->completed = true;
            free(tempTask);
            printf("Task Updated\n\n");
            return;
        }
    }
    
    printf("Task not found!");
    free(tempTask);
    
}

void removeTask(todo *list[], int *tasks){
    
    char *remTask = malloc(max*sizeof(char));
    if(remTask == NULL){
        printf("Memory Allocation Failed!!");
        free(remTask);
        return;
    }
    
    printf("Enter the task you want to remove: ");
    while(getchar() != '\n');
    fgets(remTask, max, stdin);
    remTask[strcspn(remTask, "\n")] = '\0';
    
    for(int i = 0; i < (*tasks); i++){
        if(strcmp(remTask, list[i]->desc) == 0){
            free(list[i]->desc);
            free(list[i]);
            for(int j = i; j < (*tasks); j++){
                list[j] = list[j+1];
            }
            
            (*tasks)--;
            printf("Task Removed\n\n");
            free(remTask);
            return;
        }
    }
    
    printf("Task not in the list\n\n");
    free(remTask);
    
}

void displayTask(todo *list[], int tasks){
    printf("To-Do Lists: \n");
    for(int i = 0; i < tasks; i++){
        if(list[i]->completed == true){
            printf("%i. [x] ", i+1);
        }else{
            printf("%i. [ ] ", i+1);
        }
        
        printf("%s\n", list[i]->desc);
    }
}
