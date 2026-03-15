#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;           
    struct Node* link;  
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** start, int item) {
    
    // Step 2 (Part A): NEW := AVAIL
    // malloc handles the 'AVAIL' list for us
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 1: Check if AVAIL == NULL (Overflow)
    if (newNode == NULL) {
        printf("Overflow: No memory available.\n");
        return;
    }

    /* Note: The Step 2 line "AVAIL := LINK[AVAIL]" happens 
       automatically inside the malloc() function.
    */

    // Step 3: Set INFO and LINK
    newNode->info = item;      // INFO[NEW] := ITEM
    newNode->link = *start;    // LINK[NEW] := START

    // Step 4: START := NEW
    *start = newNode;   

    // Step 5: Exit
    printf(" %d\n", item);
}

// Helper function to print the list
void printList(struct Node* node) {
   printf("Current List:");
   while (node!=NULL){
printf("%d -> ", node->info);
node=node->link;
   }
   printf("NULL\n");
}

int main() {
    struct Node* start = NULL; // Initially, the list is empty
int totalItems,item,i;
printf("How many Elements do you want to insert?");
scanf("%d", &totalItems);
for(i=0;i<totalItems;i++){
    printf("Enter the values");
    scanf("%d",&item);
    insertAtBeginning(&start, item);
    
    printList(start);
}
printf("\nFinal Result:");
printList(start);

    return 0;
}
