#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertAtEnd(struct Node** start, int item)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* ptr;

    if(newNode == NULL){
        printf("Overflow\n");
        return;
    }

    newNode->info = item;
    newNode->link = NULL;

    if(*start == NULL){
        *start = newNode;
        return;
    }

    ptr = *start;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr->link = newNode;
}

void printList(struct Node* node)
{
    printf("Current List: ");

    while(node != NULL){
        printf("%d -> ", node->info);
        node = node->link;
    }

    printf("NULL\n");
}

int main()
{
    struct Node* start = NULL;
    int totalItems, item, i;
    char choice;

    printf("How many nodes do you want to create initially? ");
    scanf("%d", &totalItems);

    // Create initial linked list
    for(i = 0; i < totalItems; i++){
        printf("Enter value: ");
        scanf("%d", &item);

        insertAtEnd(&start, item);
    }

    printList(start);

    // Ask user if they want to insert more nodes
    printf("\nDo you want to insert another node at the end? (y/n): ");
    scanf(" %c", &choice);

    while(choice == 'y' || choice == 'Y'){
        printf("Enter value to insert at end: ");
        scanf("%d", &item);

        insertAtEnd(&start, item);

        printList(start);

        printf("Insert another node? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nFinal Linked List:\n");
    printList(start);

    return 0;
}