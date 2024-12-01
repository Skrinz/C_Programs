#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 4

// insert
// delete
// isfull
// isempty
//return a new set
  // union
  // difference

typedef struct{
    int elem[size];
    int count;//number of elements in the bit vector
}Set;


bool isFull(Set set){
    return set.count >= size;
}

bool isEmpty(Set set){
    return set.count == 0;
}

void insertSet(Set *set){
    if(isFull(*set)){
        printf("The set is full!!\n");
        return;
    }
   
    int num;
    set->count = 0;
   
    for(int i = 0; i < size;i++){
       printf("set[%d] (0 or 1): ", i);
       scanf("%d", &num);
       if(num == 1){
           set->elem[i] = 1;
           set->count++;
       }else{
           set->elem[i] = 0;
       }
    }
}

void displaySet(Set set){
   
    printf("{");
    for(int i = 0; i < size; i++){
        printf("  %d", set.elem[i]);
    }
    printf("  }\n");
    
    for(int i = 0; i < size;i++){
        printf("   %d", i);
    }
    printf("\n");
}

void deleteElem(Set *set, int num){
    if (num >= 0 && num < size) {
        set->elem[num] = 0;
        set->count--;
    } else {
        printf("Invalid element number!\n");
    }
}

Set* unionSet(Set setA, Set setB){
    Set *newSet = (Set*) malloc(sizeof(Set));
    newSet->count = 0;
   
    for(int i = 0; i < size; i++){
        if (setA.elem[i] == 1 || setB.elem[i] == 1) {
            newSet->elem[i] = 1;
            newSet->count++;
        }else{
            newSet->elem[i] = 0;
        }
    }
    
    return newSet;
}

Set* differenceSet(Set setA, Set setB){
    Set *newSet = (Set*) malloc(sizeof(Set));
    
    for(int i = 0;i < size; i++){
        if((setA.elem[i] == 1 && setB.elem[i] == 0) || (setA.elem[i] == 0 && setB.elem[i] == 1)){
            newSet->elem[i] = 1;
        }else{
            newSet->elem[i] = 0;
        }
    }
    return newSet;
}

int main() {
    Set setA;
    Set setB;
    
    setA.count = 0;
    setB.count = 0;
    
    printf("This is a bit vector!!\n");
    printf("You can only enter a number set ranging from 0-14:\n");
    printf("Type 0 or 1 if the number is in the set.\n\n");
   
    printf("For Set A;\n");
    insertSet(&setA);
    
    printf("\n\nFor Set B;\n");
    insertSet(&setB);
    
    //displaying the initial state of the state
    printf("\nInitial:\n");
    displaySet(setA);
    printf("\n");
    displaySet(setB);
   
   //deleting an elem in the set
   printf("\nAfter deleting:\n");
    deleteElem(&setA, 0);
    displaySet(setA);
    printf("\n");
    
    
    deleteElem(&setB, 1);
    displaySet(setB);
    printf("\n");
   
   printf("Union:\n");
   //for union
    Set *setC = unionSet(setA, setB);
    displaySet(*setC);
    printf("\n");
    
    
    printf("Difference:\n");
    //for difference
    Set *setD = differenceSet(setA, setB);
    displaySet(*setD);
    
    free(setC);
    free(setD);
    
    return 0;
}
