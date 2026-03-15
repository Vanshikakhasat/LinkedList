#include <stdio.h>
#include <stdlib.h>

// Structure for the Node
struct Node {
    int info;
    struct Node* link;
};


// Function to delete node from the beginning
void delet_beginning(struct Node** start) 
{
    struct Node* LOC; 

    // Step 1: Check for Underflow (List empty)
    if (*start == NULL) {
        printf("Underflow: List is empty\n");
        return;
    }

    // Step 2: LOC := START (Store first node)
    LOC = *start;

    // Step 3: START := LINK[START] (Move start to next node)
    *start = (*start)->link;

    // Step 4: Return node to AVAIL (free memory in C)
    printf("Deleted item: %d\n", LOC->info);
    free(LOC); 
}


// Function to insert node at end (used to create initial list)
void insertAtEnd(struct Node** start, int item)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* ptr;

    // Step 1: Check for Overflow
    if(newNode == NULL){
        printf("Overflow\n");
        return;
    }

    // Step 2: Assign value
    newNode->info = item;
    newNode->link = NULL;

    // Step 3: If list is empty
    if(*start == NULL){
        *start = newNode;
        return;
    }

    // Step 4: Traverse to last node
    ptr = *start;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    // Step 5: Insert node at end
    ptr->link = newNode;
}


// Function to print the linked list
void printList(struct Node* node) 
{
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->info);
        node = node->link;
    }

    printf("NULL\n");
}


// Main function
int main() 
{
    struct Node* start = NULL;
    int choice, n, item, i;

    // Ask user how many nodes to create
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    // Create linked list using insertAtEnd
    for(i = 0; i < n; i++){
        printf("Enter value: ");
        scanf("%d",&item);
        insertAtEnd(&start,item);
    }

    // Print initial linked list
    printf("Initial List: ");
    printList(start);

    // Menu for deletion
    while (1) {

        printf("\n1. Delete from Beginning\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            // Call delete function
            delet_beginning(&start);

            printf("Current List: ");
            printList(start);
        }
        else {
            break;
        }
    }

    return 0;
}