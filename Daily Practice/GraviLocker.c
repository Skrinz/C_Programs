/* Instructions:
	The University of San Carlos has begun rolling out its newest locker technology: GraviLockers.
	These lockers are capable of fitting any amount of items, for as long as the total weight of all items
	does not exceed the weight limit of 5 KG. However, during shipping, the lockers' disk drives were damaged,
	and the firmware that made them work was lost. Luckily, the documentation for the structures remained intact.
	
	As students of DCIS, USC needs your help. Write the codes for the functions to make the lockers work again.
	Use the structures defined below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 5

typedef struct{
	char studID[9];		
	char studName[65];  
	char course[5];		
}Student;

typedef struct{
	char itemName[33];	
	float weight;	/* Weight of the item to be stored */	
}ItemDets;

typedef struct ItemNode{
	ItemDets item;
	struct ItemNode* nextItem;
}ItemNode, *ItemList;

typedef struct{
	Student owner;/* Details of the student who owns the locker */
	ItemList IL;/* Linked list representation of all the items inside a certain locker */
	int lockerStat; /* 0 if locker is Vacant, 1 if occupied */
	float totWeight;/* Total weight of all items in the locker */
}Locker;

/* Function depositItem(): This function will receive as parameter a Locker, a student ID, and an item to be
stored. The function will insert the item into the Locker's ItemList, which is sorted by weight. Heavier
items are stored at the end of the locker's ItemList. Before insertion, please make sure that the student ID
passed is the same as the student ID of the locker's owner. Also, make sure that the weight of all items,
including the new item to store, does not exceed the weight limit. */

void depositItem(Locker* L, char studID[], ItemDets newItem)
{       
    if(strcmp(L->owner.studID, studID) != 0){
        printf("The student ID passed is not the locker's owner");
        return;
    } 

    if(L->totWeight + newItem.weight > WEIGHTLIMIT){
        printf("The weigth of the item will exceed the weight limit!");
        return;
    }

    ItemNode *newItemNode = (ItemNode*) malloc(sizeof(ItemNode));
    strcpy(newItemNode->item.itemName, newItem.itemName);
    newItemNode->item.weight = newItem.weight;
    newItemNode->nextItem = NULL;
    
    L->totWeight += newItem.weight;

    if(L->IL == NULL){
        L->IL = newItemNode;
    }else{
        ItemList trav = L->IL;
        ItemList prev = NULL;
        //find the space of item in ascending order of weight
        while(trav != NULL && newItemNode->item.weight > trav->item.weight){
            prev = trav;
            trav = trav->nextItem;
        }
        
        if(prev == NULL){
            newItemNode->nextItem = L->IL;
            L->IL = newItemNode;
            return;
        }else{
            newItemNode->nextItem = prev->nextItem;
            prev->nextItem = newItemNode;

            return;
        }
    }
}

/* Function getHeavyItems(): This function will receive as parameter a Locker and a weight threshold/limit.
The function will go through all the items in the passed Locker's ItemList. If any item EXCEEDS the passed
threshold/limit, store that item into a new ItemList using insertFirst, and delete it from the locker's 
ItemList. Return the ItemList o f deleted items to the calling function. */

ItemList getHeavyItems(Locker* L, float limit)
{
    ItemList heavyItems = NULL;
    ItemList prev = NULL;
    ItemList trav = L->IL;

    while(trav != NULL){
        if(trav->item.weight > limit){
            ItemList newNode = (ItemList) malloc(sizeof(ItemNode));
            strcpy(newNode->item.itemName, trav->item.itemName);
            newNode->item.weight = trav->item.weight;
            newNode->nextItem = heavyItems;

            heavyItems = newNode;

            prev->nextItem = trav->nextItem;

            L->totWeight -= trav->item.weight;

            free(trav);
            trav = prev->nextItem;

        }else{
            prev = trav;
            trav = trav->nextItem;
        }
    }

    return heavyItems;
}

void displayItemList(ItemList L)
{
	ItemList trav;
	float totWeight = 0;
	for(trav = L; trav != NULL; trav = trav->nextItem){
		printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);
        totWeight += trav->item.weight;

	}
	printf("\nTotal Weight: %.2fkg\n\n", totWeight);
}

int main(void)
{
	ItemDets item1 = {"Prog 1 Book", 0.35};
	ItemDets item2 = {"Shoes", 0.87};
	ItemDets item3 = {"Laptop", 2.35};
	ItemDets item4 = {"Keyboard", 1.17};
	
	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	ItemList heavyItems;
	
	depositItem(&myLocker, "14101941", item4);
	depositItem(&myLocker, "14101941", item2);
	depositItem(&myLocker, "14101941", item3);
	depositItem(&myLocker, "14101941", item1);
	displayItemList(myLocker.IL);
	
	heavyItems = getHeavyItems(&myLocker, 1.00);
	displayItemList(myLocker.IL);
	displayItemList(heavyItems);
	return 0;
}