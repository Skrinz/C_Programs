#include <stdio.h>

int main() {
    char first_name[20];
    char last_name[20];
    int age;
    int year_level;
    char school_name[50];
    
    printf("Enter your first name: ");
    scanf("%s", first_name);
    
    printf("Enter your last name: ");
    scanf("%s", last_name);
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Enter your year level: ");
    scanf("%d", &year_level);
    
    printf("Enter your school name: ");
    scanf ("%s", school_name);
    
    printf("\nUser Information\n");
    printf("First name: %s\n", first_name);
    printf("Last name: %s\n", last_name);
    printf("Age: %d\n", age);
    printf("Year level: %d\n", year_level);
    printf("School Name: %s\n", school_name);
    
    return 0;
    
}
