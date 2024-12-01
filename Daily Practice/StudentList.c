// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_students 40

struct studrec{
  int studID;
  char* name;
  int age;
  char gender;
  float GPA;
};

struct studrec list[max_students];
int num_students = 0;


void addRecord();
void searchByStudID();
void searchByAge();
void displayList();
void removeByStudID();
void displayNumStud();

int main() {
    int count = 1;
    int choice;
    while(count == 1){
       printf("What do you want to do?\n");
       printf("1) Add student record\n2) Search student by ID\n3) Search student by age\n4) Display list\n5) Remove student record by ID\n6) Display total number of student records\n7) Exit\n");
       scanf("%i", &choice);
        switch(choice){
            case 1:
                addRecord();
                printf("Student Added\n\n");
                break;
            case 2: 
                if(num_students == 0){
                    printf("Student list is empty\n\n");
                    break;
                }else{
                    searchByStudID();
                    break;
                }
                
            case 3:
                if(num_students == 0){
                    printf("Student list is empty\n\n");
                    break;
                }else{
                    searchByAge();
                    break;
                }
            case 4: 
                if(num_students == 0){
                    printf("Student list is empty\n\n");
                    break;
                }else{
                    displayList();
                    break;
                }
            case 5:
                if(num_students == 0){
                    printf("Student list is empty\n\n");
                    break;
                }else{
                    removeByStudID();
                    printf("Student removed successfully\n\n");
                    break;
                }
            case 6:
                displayNumStud();
                break;
            case 7:
                return 0;
            default:
                printf("Choice invalid\n");
                break;
        }
    }
    
}


void addRecord(){
    struct studrec student;
    
    printf("Student ID: ");
    scanf("%i", &student.studID);
    getchar();
    
    printf("Name: ");
    student.name = malloc (100*sizeof(char));
    fgets(student.name, 100, stdin);
    
    printf("Age: ");
    scanf("%i", &student.age);
    getchar();
    
    printf("Gender(F = Female; M = Male): ");
    scanf(" %c", &student.gender);
    getchar();
    
    printf("GPA: ");
    scanf("%f", &student.GPA);
    getchar();

    list[num_students++] = student;
    
}

void searchByStudID(){
    int searchID;
    printf("What is the student's ID? ");
    scanf("%i", &searchID);
    
    for(int i = 0; i < num_students;i++){
        if(searchID == list[i].studID){
            printf("Student found!\n\n");
            
            printf("Name: %s", list[i].name);
            
            printf("Age: %i\n", list[i].age);
            
            printf("Gender: %c\n", list[i].gender);
            
            printf("GPA: %.2f", list[i].GPA);
            return;
        }
        printf("Student not found.\n\n");
    }
    
}

void searchByAge(){
    int searchAge;
    printf("What is the student's age? ");
    scanf("%i", &searchAge);
    
    for(int i = 0; i < num_students;i++){
        if(searchAge == list[i].age){
            printf("Student found!\n");
            
            printf("Student ID: %i\n", list[i].studID);
            
            printf("Name: %s", list[i].name);
            
            printf("Gender: %c\n", list[i].gender);
            
            printf("GPA: %.2f\n\n", list[i].GPA);
        }
    }
    printf("\n\n");
}

void displayList(){
    printf("List of Students: \n");
     for(int i = 0; i < num_students;i++){
        
        printf("Student ID: %i\n", list[i].studID);
            
        printf("Name: %s", list[i].name);
        
        printf("Student ID: %i\n", list[i].age);
            
        printf("Gender: %c\n", list[i].gender);
            
        printf("GPA: %.2f\n\n", list[i].GPA);
        
    }
    printf("\n\n");
}

void removeByStudID(){
    int removeID;
    printf("Student ID to remove: \n");
    scanf("%i", &removeID);
    
    for(int i=0;i < num_students; i++){
        if(list[i].studID == removeID){
            for(int j=i; j < num_students - 1; j++){
                list[j] = list[j+1];
            }
            free(list[i].name);
            num_students--;
            return;
        }
    }
    
    
}
void displayNumStud(){
    printf("Number of students in the list: %i\n\n", num_students);
    return;
}