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
    struct Node* start = NULL;
    int totalItems, item, i, newItem;

    printf("How many elements do you want to create? ");
    scanf("%d", &totalItems);

    // Creating initial list
    for(i = 0; i < totalItems; i++) {
        printf("Enter value: ");
        scanf("%d", &item);
        insertAtBeginning(&start, item);
    }

    printf("\nInitial List:\n");
    printList(start);

    // Asking which element to insert at beginning
    printf("\nEnter the element you want to insert at the beginning: ");
    scanf("%d", &newItem);

    insertAtBeginning(&start, newItem);

    printf("\nList after inserting at beginning:\n");
    printList(start);

    return 0;
}