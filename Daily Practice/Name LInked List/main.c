#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "declaration.h"

int main() {
    char choice = -1;
    char fName[20];
    char lName[20];

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    while(1){
         
        printf("\t============Menu============\n\n");
        printf("1) Add & Sort Input by LastName\n2) Insert Input Last\n3) Insert Input at the Start");
        printf("\n4) Delete\n5) Print All\n6) Create a Cycle\n7) Check if there is cycle\n0) End\n\n");
        scanf(" %c", &choice);
        while(getchar() != '\n');

        if((choice == '4' || choice == '5' || choice == '6' || choice == '7') && head->next == NULL){
            printf("The list is empty...!\n\n");
            break;
        }else{
                printf("Enter First Name: ");
                scanf("%s", fName);
                fName[strcspn(fName, "\n")] = '\0';
                
                
                printf("Enter Last Name: ");
                scanf("%s", lName);
                lName[strcspn(lName,"\n")] = '\0';


            switch(choice){
                case '1': 
                    insertSorted(head, fName, lName);
                    printf("\n\n\tThe added data has been Sorted in the Linked List!!\n\n");
                    break;

                case '2':
                    insertEnd(head, fName,lName);
                    printf("\n\n\tNew node has been added at the end!!\n\n");
                    break;

                case '3':
                    insertStart(head, fName, lName);
                    printf("\n\n\tNew node has been addded at the start!!\n\n");
                    break;

                case '4':
                    deleteName(head);
                    break;
                    
                case '5':
                    printThis(head);
                    break;

                case '6':
                    printThis(head);
                    printf("\n");

                    char entry[20];
                    printf("\nEnter the last name of the entry point: ");
                    scanf("%s", entry);
                    entry[strcspn(entry, "\n")] = '\0';

                    createCycle(head, entry);
                    printf("\n\n\tNOTICE YOU'VE CREATED A CYCLE IN THE LINKED LIST!!\n\n");
                    break;

                case '7':
                    bool check = checkCycle(head);
                    
                    if(check){
                        printf("There is a cycle..!!\n\n");
                        break;
                    }else{
                        printf("There is no cycle..!!\n\n");
                        break;
                    }

                case '0':
                    printf("Exiting program....");
                    deleteList(head);
                    return 0;

                default: 
                    printf("Choice Invalid!!\n\n");
                    break;
            }
        }

        printf("\n\n");
    }
}